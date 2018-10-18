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
    (options, args) = parser.parse_args()

    samplefolder = "outputs_forPlots"
    if options.is_zttMC: 
        samplefolder = "outputs_nominal"
        
    fVBF125=ROOT.TFile(samplefolder+"/VBF125.root","r")
    fggH125=ROOT.TFile(samplefolder+"/ggH125.root","r")
    fWH125=ROOT.TFile(samplefolder+"/WH125.root","r")
    fZH125=ROOT.TFile(samplefolder+"/ZH125.root","r")
    fout=ROOT.TFile(samplefolder+"/SMH.root","recreate")


    dirOS_0jet=fout.mkdir("tt_0jet")
    dirSS_0jet=fout.mkdir("ttSS_0jet")
    dirAIOS_0jet=fout.mkdir("AIOS_0jet")
    dirAISS_0jet=fout.mkdir("AISS_0jet")
    dirOS_boosted=fout.mkdir("tt_boosted")
    dirSS_boosted=fout.mkdir("ttSS_boosted")
    dirAIOS_boosted=fout.mkdir("AIOS_boosted")
    dirAISS_boosted=fout.mkdir("AISS_boosted")
    dirOS_vbf=fout.mkdir("tt_vbf")
    dirSS_vbf=fout.mkdir("ttSS_vbf")
    dirAIOS_vbf=fout.mkdir("AIOS_vbf")
    dirAISS_vbf=fout.mkdir("AISS_vbf")

    cats=['0jet','boosted','vbf'] #do not have jobs
    regions=['OS','SS','AIOS','AISS']

    #for cat in cats:
    #    for region in regions:
    hOS_0jet=fVBF125.Get("tt_0jet/VBF125")
    hOS_0jet.Add(fggH125.Get("tt_0jet/ggH125"))
    hOS_0jet.Add(fWH125.Get("tt_0jet/WH125"))
    hOS_0jet.Add(fZH125.Get("tt_0jet/ZH125"))
    for i in range(0,hOS_0jet.GetSize()-2):
        if hOS_0jet.GetBinContent(i)<0:
            hOS_0jet.SetBinError(i,max(0,hOS_0jet.GetBinError(i)+hOS_0jet.GetBinError(i)))
            hOS_0jet.SetBinContent(i,0)

    hSS_0jet=fVBF125.Get("ttSS_0jet/VBF125")
    hSS_0jet.Add(fggH125.Get("ttSS_0jet/ggH125"))
    hSS_0jet.Add(fWH125.Get("ttSS_0jet/WH125"))
    hSS_0jet.Add(fZH125.Get("ttSS_0jet/ZH125"))
    for i in range(0,hSS_0jet.GetSize()-2):
        if hSS_0jet.GetBinContent(i)<0:
            hSS_0jet.SetBinError(i,max(0,hSS_0jet.GetBinError(i)+hSS_0jet.GetBinError(i)))
            hSS_0jet.SetBinContent(i,0)

    hAIOS_0jet=fVBF125.Get("AIOS_0jet/VBF125")
    hAIOS_0jet.Add(fggH125.Get("AIOS_0jet/ggH125"))
    hAIOS_0jet.Add(fWH125.Get("AIOS_0jet/WH125"))
    hAIOS_0jet.Add(fZH125.Get("AIOS_0jet/ZH125"))
    for i in range(0,hAIOS_0jet.GetSize()-2):
        if hAIOS_0jet.GetBinContent(i)<0:
            hAIOS_0jet.SetBinError(i,max(0,hAIOS_0jet.GetBinError(i)+hAIOS_0jet.GetBinError(i)))
            hAIOS_0jet.SetBinContent(i,0)

    hAISS_0jet=fVBF125.Get("AISS_0jet/VBF125")
    hAISS_0jet.Add(fggH125.Get("AISS_0jet/ggH125"))
    hAISS_0jet.Add(fWH125.Get("AISS_0jet/WH125"))
    hAISS_0jet.Add(fZH125.Get("AISS_0jet/ZH125"))
    for i in range(0,hAISS_0jet.GetSize()-2):
        if hAISS_0jet.GetBinContent(i)<0:
            hAISS_0jet.SetBinError(i,max(0,hAISS_0jet.GetBinError(i)+hAISS_0jet.GetBinError(i)))
            hAISS_0jet.SetBinContent(i,0)


    fout.cd()
    dirOS_0jet.cd()
    hOS_0jet.SetName("SMH")
    hOS_0jet.Write()

    dirSS_0jet.cd()
    hSS_0jet.SetName("SMH")
    hSS_0jet.Write()

    dirAIOS_0jet.cd()
    hAIOS_0jet.SetName("SMH")
    hAIOS_0jet.Write()

    dirAISS_0jet.cd()
    hAISS_0jet.SetName("SMH")
    hAISS_0jet.Write()



    hOS_boosted=fVBF125.Get("tt_boosted/VBF125")
    hOS_boosted.Add(fggH125.Get("tt_boosted/ggH125"))
    hOS_boosted.Add(fWH125.Get("tt_boosted/WH125"))
    hOS_boosted.Add(fZH125.Get("tt_boosted/ZH125"))
    for i in range(0,hOS_boosted.GetSize()-2):
        if hOS_boosted.GetBinContent(i)<0:
            hOS_boosted.SetBinError(i,max(0,hOS_boosted.GetBinError(i)+hOS_boosted.GetBinError(i)))
            hOS_boosted.SetBinContent(i,0)

    hSS_boosted=fVBF125.Get("ttSS_boosted/VBF125")
    hSS_boosted.Add(fggH125.Get("ttSS_boosted/ggH125"))
    hSS_boosted.Add(fWH125.Get("ttSS_boosted/WH125"))
    hSS_boosted.Add(fZH125.Get("ttSS_boosted/ZH125"))
    for i in range(0,hSS_boosted.GetSize()-2):
        if hSS_boosted.GetBinContent(i)<0:
            hSS_boosted.SetBinError(i,max(0,hSS_boosted.GetBinError(i)+hSS_boosted.GetBinError(i)))
            hSS_boosted.SetBinContent(i,0)


    hAIOS_boosted=fVBF125.Get("AIOS_boosted/VBF125")
    hAIOS_boosted.Add(fggH125.Get("AIOS_boosted/ggH125"))
    hAIOS_boosted.Add(fWH125.Get("AIOS_boosted/WH125"))
    hAIOS_boosted.Add(fZH125.Get("AIOS_boosted/ZH125"))
    for i in range(0,hAIOS_boosted.GetSize()-2):
        if hAIOS_boosted.GetBinContent(i)<0:
            hAIOS_boosted.SetBinError(i,max(0,hAIOS_boosted.GetBinError(i)+hAIOS_boosted.GetBinError(i)))
            hAIOS_boosted.SetBinContent(i,0)

    hAISS_boosted=fVBF125.Get("AISS_boosted/VBF125")
    hAISS_boosted.Add(fggH125.Get("AISS_boosted/ggH125"))
    hAISS_boosted.Add(fWH125.Get("AISS_boosted/WH125"))
    hAISS_boosted.Add(fZH125.Get("AISS_boosted/ZH125"))
    for i in range(0,hAISS_boosted.GetSize()-2):
        if hAISS_boosted.GetBinContent(i)<0:
            hAISS_boosted.SetBinError(i,max(0,hAISS_boosted.GetBinError(i)+hAISS_boosted.GetBinError(i)))
            hAISS_boosted.SetBinContent(i,0)


    fout.cd()
    dirOS_boosted.cd()
    hOS_boosted.SetName("SMH")
    hOS_boosted.Write()

    dirSS_boosted.cd()
    hSS_boosted.SetName("SMH")
    hSS_boosted.Write()

    dirAIOS_boosted.cd()
    hAIOS_boosted.SetName("SMH")
    hAIOS_boosted.Write()

    dirAISS_boosted.cd()
    hAISS_boosted.SetName("SMH")
    hAISS_boosted.Write()





    hOS_vbf=fVBF125.Get("tt_vbf/VBF125")
    hOS_vbf.Add(fggH125.Get("tt_vbf/ggH125"))
    hOS_vbf.Add(fWH125.Get("tt_vbf/WH125"))
    hOS_vbf.Add(fZH125.Get("tt_vbf/ZH125"))
    for i in range(0,hOS_vbf.GetSize()-2):
        if hOS_vbf.GetBinContent(i)<0:
            hOS_vbf.SetBinError(i,max(0,hOS_vbf.GetBinError(i)+hOS_vbf.GetBinError(i)))
            hOS_vbf.SetBinContent(i,0)

    hSS_vbf=fVBF125.Get("ttSS_vbf/VBF125")
    hSS_vbf.Add(fggH125.Get("ttSS_vbf/ggH125"))
    hSS_vbf.Add(fWH125.Get("ttSS_vbf/WH125"))
    hSS_vbf.Add(fZH125.Get("ttSS_vbf/ZH125"))
    for i in range(0,hSS_vbf.GetSize()-2):
        if hSS_vbf.GetBinContent(i)<0:
            hSS_vbf.SetBinError(i,max(0,hSS_vbf.GetBinError(i)+hSS_vbf.GetBinError(i)))
            hSS_vbf.SetBinContent(i,0)

    hAIOS_vbf=fVBF125.Get("AIOS_vbf/VBF125")
    hAIOS_vbf.Add(fggH125.Get("AIOS_vbf/ggH125"))
    hAIOS_vbf.Add(fWH125.Get("AIOS_vbf/WH125"))
    hAIOS_vbf.Add(fZH125.Get("AIOS_vbf/ZH125"))
    for i in range(0,hAIOS_vbf.GetSize()-2):
        if hAIOS_vbf.GetBinContent(i)<0:
            hAIOS_vbf.SetBinError(i,max(0,hAIOS_vbf.GetBinError(i)+hAIOS_vbf.GetBinError(i)))
            hAIOS_vbf.SetBinContent(i,0)

    hAISS_vbf=fVBF125.Get("AISS_vbf/VBF125")
    hAISS_vbf.Add(fggH125.Get("AISS_vbf/ggH125"))
    hAISS_vbf.Add(fWH125.Get("AISS_vbf/WH125"))
    hAISS_vbf.Add(fZH125.Get("AISS_vbf/ZH125"))
    for i in range(0,hAISS_vbf.GetSize()-2):
        if hAISS_vbf.GetBinContent(i)<0:
            hAISS_vbf.SetBinError(i,max(0,hAISS_vbf.GetBinError(i)+hAISS_vbf.GetBinError(i)))
            hAISS_vbf.SetBinContent(i,0)

    fout.cd()
    dirOS_vbf.cd()
    hOS_vbf.SetName("SMH")
    hOS_vbf.Write()

    dirSS_vbf.cd()
    hSS_vbf.SetName("SMH")
    hSS_vbf.Write()

    dirAIOS_vbf.cd()
    hAIOS_vbf.SetName("SMH")
    hAIOS_vbf.Write()

    dirAISS_vbf.cd()
    hAISS_vbf.SetName("SMH")
    hAISS_vbf.Write()
