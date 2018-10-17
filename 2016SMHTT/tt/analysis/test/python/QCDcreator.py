if __name__ == "__main__":

    import ROOT
    import argparse
    
    samples = ["data","embedded", "ZJ", "ZL", "TTJ", "VVJ", "W", "EWKZ"]
    #samples = ["data","ZTT", "ZJ", "ZL", "TTT", "TTJ", "VVT", "VVJ", "W", "EWKZ"]
    regions = ["AIOS","AISS","ttSS"]
    cates = ["0jet","boosted","vbf"]
    files = []
    histos = [[],[],[]] # [[hAIOS_0jet,hAISS_0jet,hSS_0jet],[same for boosted],[same for vbf]]

    

    # Open root files
    '''
    for sample in samples:
        files.append(ROOT.TFile("outputs_nominal/"+sample+".root","r"))
    fout=ROOT.TFile("outputs_nominal/QCD.root","recreate")
    '''
    for sample in samples:
        files.append(ROOT.TFile("outputs_forPlots/"+sample+".root","r"))
    fout=ROOT.TFile("outputs_forPlots/QCD.root","recreate")
        

    # Get all histograms
    for region in regions:
        print ""
        for cate in cates:
            for sample in samples:
                # subtract all bkgs from data
                if sample is "data":
                    print "-----   Data   -----"
                    print files[samples.index(sample)].Get(region+"_"+cate+"/data_obs").Integral()
                    histos[cates.index(cate)].append(files[samples.index(sample)].Get(region+"_"+cate+"/data_obs"))
                    print "----- Subtract -----"
                else:
                    print files[samples.index(sample)].Get(region+"_"+cate+"/"+sample).Integral()
                    histos[cates.index(cate)][-1].Add(files[samples.index(sample)].Get(region+"_"+cate+"/"+sample),-1)
                    print region+"_"+cate+"/"+sample

    # Set negative yield bin to 0
    for i in range(0,len(histos)):
        for histo in histos[i]:
            for j in range(0,histo.GetSize()-2):
                if histo.GetBinContent(j)<0:
                    print histo
                    print histo.GetBinContent(j)
                    histo.SetBinError(j,max(0,histo.GetBinContent(j)+histo.GetBinContent(j)))
                    histo.SetBinContent(j,0)
                    
                    

    #######################################
    #                                     #
    #  Estimate QCD - AN eq (14)          #
    #  QCD = AIOS * (SS_signallike/AISS)  #
    #                                     #
    #######################################
    for k in range(0,len(histos)):  # loop over categories
        fout.cd()
        dir = fout.mkdir("tt_"+cates[k])
        dir.cd()
        # Save control region histograms for checking.
        histos[k][regions.index("ttSS")].SetName("QCD_ttSS")
        histos[k][regions.index("ttSS")].Write()
        histos[k][regions.index("AISS")].SetName("QCD_AISS")
        histos[k][regions.index("AISS")].Write()
        histos[k][regions.index("AIOS")].SetName("QCD_AIOS")
        histos[k][regions.index("AIOS")].Write()
        # Compute SF and QCD
        hSF = histos[k][0].Clone()
        hSF.Divide(histos[k][regions.index("ttSS")],histos[k][regions.index("AISS")],1,1,"B")
        hSF.SetName("QCD_sf")
        hSF.Write()
        hQCD = hSF.Clone()
        hQCD.Multiply(histos[k][regions.index("AIOS")],hSF,1,1,"B")
        hQCD = histos[k][regions.index("AIOS")]
        hQCD.Multiply(histos[k][regions.index("AIOS")],hSF,1,1,"B")
        '''
        # Discard obvious wrong value
        for l in range(0,histos[k][regions.index("AISS")].GetSize()-2):
            #if histos[k][regions.index("AISS")].GetBinContent(l)<=0:
            print "--"
            print k,l
            print histos[k][regions.index("AISS")].GetBinContent(l)
            print histos[k][regions.index("ttSS")].GetBinContent(l)
            print hQCD.GetBinContent(l)
            hQCD.SetBinContent(l,0)        
            '''
        hQCD.SetName("QCD")
        hQCD.Write()

    
