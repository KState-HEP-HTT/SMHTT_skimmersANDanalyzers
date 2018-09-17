if __name__ == "__main__":

    import ROOT
    import argparse
    
    samples = ["data","ZTT", "ZJ", "ZL", "TTT", "TTJ", "VVT", "VVJ", "W", "EWKZ"]
    regions = ["AIOS","AISS","ttSS"]
    cates = ["0jet","boosted","vbf"]
    files = []
    histos = [[],[],[]] # [[hAIOS_0jet,hAISS_0jet,hSS_0jet],[same for boosted],[same for vbf]]

    

    # Open root files
    for sample in samples:
        files.append(ROOT.TFile("outputs_nominal/"+sample+".root","r"))
    fout=ROOT.TFile("outputs_nominal/QCD.root","recreate")


    # Get all histograms
    for region in regions:
        print ""
        for cate in cates:
            for sample in samples:
                # subtract all bkgs from data
                if sample is "data":
                    histos[cates.index(cate)].append(files[samples.index(sample)].Get(region+"_"+cate+"/data_obs"))
                    print "----- Subtract -----"
                else:
                    histos[cates.index(cate)][-1].Add(files[samples.index(sample)].Get(region+"_"+cate+"/"+sample),-1)
                    print region+"_"+cate+"/"+sample

    # Set negative yield bin to 0
    for i in range(0,len(histos)):
        for histo in histos[i]:
            for j in range(0,histo.GetSize()-2):
                if histo.GetBinContent(j)<0:
                    histo.SetBinContent(j,0)



    #######################################
    #                                     #
    #  Estimate QCD - AN eq (14)          #
    #  QCD = AIOS * (SS_signallike/AISS)  #
    #                                     #
    #######################################
    for k in range(0,len(histos)):
        hSF = histos[k][0].Clone()
        hSF.Divide(histos[k][regions.index("ttSS")],histos[k][regions.index("AISS")],1,1,"B")
        hQCD = hSF.Clone()
        hQCD.Multiply(histos[k][regions.index("AIOS")],hSF,1,1,"B")
        fout.cd()
        dir = fout.mkdir("tt_"+cates[k])
        dir.cd()
        hQCD.SetName("QCD")
        hQCD.Write()
        
