if __name__ == "__main__":

    import ROOT
    import argparse
    from optparse import OptionParser
    import sys

    parser = OptionParser()
    parser.add_option('--ztt', '-z', action='store_true',
                      default=False, dest='is_zttMC',
                      help='run on embedded or MC ZTT'
                      )
    parser.add_option('--inputfolder', '-i', action='store',
                      default='outputs_forPlots', dest='outputs_xxx',
                      help='run on output dof analyzer or template'
                      )
    parser.add_option('--quick', '-q', action='store_true',
                      default=False, dest='is_quickPlot',
                      help='forQuickPlot use vbf region only'
                      )
    (options, args) = parser.parse_args()

    regions = ["AIOS","AISS","ttSS"]
    cates = ["0jet","boosted","vbf"]
    files = []
    histos = [[],[],[]] # [[hAIOS_0jet,hAISS_0jet,hSS_0jet],[same for boosted],[same for vbf]]
    samples = ["data_obs","embedded", "ZJ", "ZL", "TTJ", "VVJ", "W", "EWKZ"]
    if options.is_zttMC:
        del files[:]
        samples = ["data_obs","ZTT", "ZJ", "ZL", "TTT", "TTJ", "VVT", "VVJ", "W", "EWKZ"]
    if options.is_quickPlot:
        cates.remove("0jet")
        cates.remove("boosted")
    print options.outputs_xxx
    # Open root files
    for sample in samples:
        files.append(ROOT.TFile(options.outputs_xxx+"/"+sample+".root","r"))
    fout=ROOT.TFile(options.outputs_xxx+"/QCD.root","recreate")

    # Get all histograms
    for region in regions:
        print ""
        for cate in cates:
            for sample in samples:
                # subtract all bkgs from data
                if sample is "data_obs":
                    print "-----   Data   -----"
                    print files[samples.index(sample)].Get(region+"_"+cate+"/"+sample).Integral()
                    histos[cates.index(cate)].append(files[samples.index(sample)].Get(region+"_"+cate+"/"+sample))
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
                    #print histo
                    #print histo.GetBinContent(j)
                    histo.SetBinError(j,max(0,histo.GetBinError(j)+histo.GetBinError(j)))
                    histo.SetBinContent(j,0)
                    
                    

    #######################################
    #                                     #
    #  Estimate QCD - AN eq (14)          #
    #  QCD = AIOS * (SS_signallike/AISS)  #
    #                                     #
    #######################################
    for k in range(0,len(cates)):  # loop over categories
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

        hQCD.SetName("QCD")
        hQCD.Write()

    
