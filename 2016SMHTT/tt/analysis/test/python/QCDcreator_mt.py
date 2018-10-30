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

    factor0jet_u=1.11
    factor1jet_u=1.12
    factor2jet_u=1.20

    factor0jet_d=1.03
    factor1jet_d=1.00
    factor2jet_d=0.80


    regions = ["SS","QCD"]
    cates = ["0jet","1jet","vbf"]
    catesout = ["0jet","boosted","vbf"]
    files = []
    histos = [[],[],[]] # [[hAIOS_0jet,hAISS_0jet,hSS_0jet],[same for boosted],[same for vbf]]
    samples = ["data_obs","embedded", "ZJ", "ZL", "TTJ","TTT", "VV", "W", "EWKZ"]
    if options.is_zttMC:
        del samples[:]
        samples = ["data_obs","ZTT", "ZJ", "ZL", "TTT", "TTJ", "VV", "W", "EWKZ"]
    if options.is_quickPlot:
        cates.remove("0jet")
        cates.remove("1jet")
        catesout.remove("0jet")
        catesout.remove("boosted")

    QCDfactor = [1.07,1.06,1.00]
    # Open root files
    for sample in samples:
        files.append(ROOT.TFile(options.outputs_xxx+"/"+sample+".root","r"))
    fout=ROOT.TFile(options.outputs_xxx+"/QCD.root","recreate")
    print options.outputs_xxx+"/QCD.root"
    # Get all histograms
    for region in regions:
        print ""
        for cate in cates:
            for sample in samples:
                # subtract all bkgs from data
                if sample is "data_obs":
                    print "-----   Data   -----"
                    print files[samples.index(sample)].Get(region+cate+"/"+sample).Integral()
                    histos[cates.index(cate)].append(files[samples.index(sample)].Get(region+cate+"/"+sample))
                    print "----- Subtract -----"
                else:
                    print region+cate+"/"+sample
                    print files[samples.index(sample)].Get(region+cate+"/"+sample).Integral()
                    histos[cates.index(cate)][-1].Add(files[samples.index(sample)].Get(region+cate+"/"+sample),-1)


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
    #  Estimate QCD - AN eq (13)          #
    #  QCD = (hQCD*flatfactor)*QCDCR      #
    #                                     #
    #######################################                     

    for k in range(0,len(catesout)):  # loop over categories
        fout.cd()
        dir = fout.mkdir("mt_"+catesout[k])
        dir.cd()
        # Compute SF and QCD
        hQCDCR = histos[k][regions.index("SS")]
        hQCDCR.Scale(QCDfactor[k])
        hQCD = histos[k][regions.index("QCD")]
        hQCD.Scale(QCDfactor[k])
        hQCD.Scale(hQCDCR.Integral()/hQCD.Integral())

        hQCD.SetName("QCD")
        hQCD.Write()
