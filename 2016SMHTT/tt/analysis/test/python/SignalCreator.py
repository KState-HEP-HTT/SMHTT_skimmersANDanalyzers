if __name__ == "__main__":

    import ROOT
    import argparse

    nbhist=1

    fVBF125=ROOT.TFile("files_nominal/VBF125.root","r")
    fggH125=ROOT.TFile("files_nominal/ggH125.root","r")
    fWplusH125=ROOT.TFile("files_nominal/WplusH125.root","r")
    fWminusH125=ROOT.TFile("files_nominal/WminusH125.root","r")
    fZH125=ROOT.TFile("files_nominal/ZH125.root","r")
    fout=ROOT.TFile("files_nominal/SMH.root","recreate")


    dirOS_0jet=fout.mkdir("ttOS_0jet")
    dirSS_0jet=fout.mkdir("ttSS_0jet")
    dirAIOS_0jet=fout.mkdir("AIOS_0jet")
    dirAISS_0jet=fout.mkdir("AISS_0jet")
    dirOS_boosted=fout.mkdir("ttOS_boosted")
    dirSS_boosted=fout.mkdir("ttSS_boosted")
    dirAIOS_boosted=fout.mkdir("AIOS_boosted")
    dirAISS_boosted=fout.mkdir("AISS_boosted")
    dirOS_vbf=fout.mkdir("ttOS_vbf")
    dirSS_vbf=fout.mkdir("ttSS_vbf")
    dirAIOS_vbf=fout.mkdir("AIOS_vbf")
    dirAISS_vbf=fout.mkdir("AISS_vbf")
    dirOS_vh=fout.mkdir("ttOS_vh")
    dirSS_vh=fout.mkdir("ttSS_vh")
    dirAIOS_vh=fout.mkdir("AIOS_vh")
    dirAISS_vh=fout.mkdir("AISS_vh")
    dirOS_inclusive=fout.mkdir("ttOS_inclusive")
    dirSS_inclusive=fout.mkdir("ttSS_inclusive")
    dirAIOS_inclusive=fout.mkdir("AIOS_inclusive")
    dirAISS_inclusive=fout.mkdir("AISS_inclusive")
    
    
    
    dirOStt_0jet=fout.mkdir("tt_0jet")
    dirOStt_boosted=fout.mkdir("tt_boosted")
    dirOStt_vbf=fout.mkdir("tt_vbf")
    
    

    cats=['0jet','boosted','vbf'] #do not have jobs
    regions=['OS','SS','AIOS','AISS']

    #for cat in cats:
    #    for region in regions:
    hOS_0jet=fVBF125.Get("ttOS_0jet/VBF125")
    hOS_0jet.Add(fggH125.Get("ttOS_0jet/ggH125"))
    hOS_0jet.Add(fWplusH125.Get("ttOS_0jet/WplusH125"))
    hOS_0jet.Add(fWminusH125.Get("ttOS_0jet/WminusH125"))
    hOS_0jet.Add(fZH125.Get("ttOS_0jet/ZH125"))
    for i in range(0,hOS_0jet.GetSize()-2):
        if hOS_0jet.GetBinContent(i)<0:
            hOS_0jet.SetBinError(i,max(0,hOS_0jet.GetBinError(i)+hOS_0jet.GetBinError(i)))
            hOS_0jet.SetBinContent(i,0)

    hSS_0jet=fVBF125.Get("ttSS_0jet/VBF125")
    hSS_0jet.Add(fggH125.Get("ttSS_0jet/ggH125"))
    hSS_0jet.Add(fWplusH125.Get("ttSS_0jet/WplusH125"))
    hSS_0jet.Add(fWminusH125.Get("ttSS_0jet/WminusH125"))
    hSS_0jet.Add(fZH125.Get("ttSS_0jet/ZH125"))
    for i in range(0,hSS_0jet.GetSize()-2):
        if hSS_0jet.GetBinContent(i)<0:
            hSS_0jet.SetBinError(i,max(0,hSS_0jet.GetBinError(i)+hSS_0jet.GetBinError(i)))
            hSS_0jet.SetBinContent(i,0)

    hAIOS_0jet=fVBF125.Get("AIOS_0jet/VBF125")
    hAIOS_0jet.Add(fggH125.Get("AIOS_0jet/ggH125"))
    hAIOS_0jet.Add(fWplusH125.Get("AIOS_0jet/WplusH125"))
    hAIOS_0jet.Add(fWminusH125.Get("AIOS_0jet/WminusH125"))
    hAIOS_0jet.Add(fZH125.Get("AIOS_0jet/ZH125"))
    for i in range(0,hAIOS_0jet.GetSize()-2):
        if hAIOS_0jet.GetBinContent(i)<0:
            hAIOS_0jet.SetBinError(i,max(0,hAIOS_0jet.GetBinError(i)+hAIOS_0jet.GetBinError(i)))
            hAIOS_0jet.SetBinContent(i,0)

    hAISS_0jet=fVBF125.Get("AISS_0jet/VBF125")
    hAISS_0jet.Add(fggH125.Get("AISS_0jet/ggH125"))
    hAISS_0jet.Add(fWplusH125.Get("AISS_0jet/WplusH125"))
    hAISS_0jet.Add(fWminusH125.Get("AISS_0jet/WminusH125"))
    hAISS_0jet.Add(fZH125.Get("AISS_0jet/ZH125"))
    for i in range(0,hAISS_0jet.GetSize()-2):
        if hAISS_0jet.GetBinContent(i)<0:
            hAISS_0jet.SetBinError(i,max(0,hAISS_0jet.GetBinError(i)+hAISS_0jet.GetBinError(i)))
            hAISS_0jet.SetBinContent(i,0)


    fout.cd()
    dirOS_0jet.cd()
    hOS_0jet.SetName("SMH")
    hOS_0jet.Write()

    dirOStt_0jet.cd()
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



    hOS_boosted=fVBF125.Get("ttOS_boosted/VBF125")
    hOS_boosted.Add(fggH125.Get("ttOS_boosted/ggH125"))
    hOS_boosted.Add(fWplusH125.Get("ttOS_boosted/WplusH125"))
    hOS_boosted.Add(fWminusH125.Get("ttOS_boosted/WminusH125"))
    hOS_boosted.Add(fZH125.Get("ttOS_boosted/ZH125"))
    for i in range(0,hOS_boosted.GetSize()-2):
        if hOS_boosted.GetBinContent(i)<0:
            hOS_boosted.SetBinError(i,max(0,hOS_boosted.GetBinError(i)+hOS_boosted.GetBinError(i)))
            hOS_boosted.SetBinContent(i,0)

    hSS_boosted=fVBF125.Get("ttSS_boosted/VBF125")
    hSS_boosted.Add(fggH125.Get("ttSS_boosted/ggH125"))
    hSS_boosted.Add(fWplusH125.Get("ttSS_boosted/WplusH125"))
    hSS_boosted.Add(fWminusH125.Get("ttSS_boosted/WminusH125"))
    hSS_boosted.Add(fZH125.Get("ttSS_boosted/ZH125"))
    for i in range(0,hSS_boosted.GetSize()-2):
        if hSS_boosted.GetBinContent(i)<0:
            hSS_boosted.SetBinError(i,max(0,hSS_boosted.GetBinError(i)+hSS_boosted.GetBinError(i)))
            hSS_boosted.SetBinContent(i,0)


    hAIOS_boosted=fVBF125.Get("AIOS_boosted/VBF125")
    hAIOS_boosted.Add(fggH125.Get("AIOS_boosted/ggH125"))
    hAIOS_boosted.Add(fWplusH125.Get("AIOS_boosted/WplusH125"))
    hAIOS_boosted.Add(fWminusH125.Get("AIOS_boosted/WminusH125"))
    hAIOS_boosted.Add(fZH125.Get("AIOS_boosted/ZH125"))
    for i in range(0,hAIOS_boosted.GetSize()-2):
        if hAIOS_boosted.GetBinContent(i)<0:
            hAIOS_boosted.SetBinError(i,max(0,hAIOS_boosted.GetBinError(i)+hAIOS_boosted.GetBinError(i)))
            hAIOS_boosted.SetBinContent(i,0)

    hAISS_boosted=fVBF125.Get("AISS_boosted/VBF125")
    hAISS_boosted.Add(fggH125.Get("AISS_boosted/ggH125"))
    hAISS_boosted.Add(fWplusH125.Get("AISS_boosted/WplusH125"))
    hAISS_boosted.Add(fWminusH125.Get("AISS_boosted/WminusH125"))
    hAISS_boosted.Add(fZH125.Get("AISS_boosted/ZH125"))
    for i in range(0,hAISS_boosted.GetSize()-2):
        if hAISS_boosted.GetBinContent(i)<0:
            hAISS_boosted.SetBinError(i,max(0,hAISS_boosted.GetBinError(i)+hAISS_boosted.GetBinError(i)))
            hAISS_boosted.SetBinContent(i,0)


    fout.cd()
    dirOS_boosted.cd()
    hOS_boosted.SetName("SMH")
    hOS_boosted.Write()

    dirOStt_boosted.cd()
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





    hOS_vbf=fVBF125.Get("ttOS_vbf/VBF125")
    hOS_vbf.Add(fggH125.Get("ttOS_vbf/ggH125"))
    hOS_vbf.Add(fWplusH125.Get("ttOS_vbf/WplusH125"))
    hOS_vbf.Add(fWminusH125.Get("ttOS_vbf/WminusH125"))
    hOS_vbf.Add(fZH125.Get("ttOS_vbf/ZH125"))
    for i in range(0,hOS_vbf.GetSize()-2):
        if hOS_vbf.GetBinContent(i)<0:
            hOS_vbf.SetBinError(i,max(0,hOS_vbf.GetBinError(i)+hOS_vbf.GetBinError(i)))
            hOS_vbf.SetBinContent(i,0)

    hSS_vbf=fVBF125.Get("ttSS_vbf/VBF125")
    hSS_vbf.Add(fggH125.Get("ttSS_vbf/ggH125"))
    hSS_vbf.Add(fWplusH125.Get("ttSS_vbf/WplusH125"))
    hSS_vbf.Add(fWminusH125.Get("ttSS_vbf/WminusH125"))
    hSS_vbf.Add(fZH125.Get("ttSS_vbf/ZH125"))
    for i in range(0,hSS_vbf.GetSize()-2):
        if hSS_vbf.GetBinContent(i)<0:
            hSS_vbf.SetBinError(i,max(0,hSS_vbf.GetBinError(i)+hSS_vbf.GetBinError(i)))
            hSS_vbf.SetBinContent(i,0)

    hAIOS_vbf=fVBF125.Get("AIOS_vbf/VBF125")
    hAIOS_vbf.Add(fggH125.Get("AIOS_vbf/ggH125"))
    hAIOS_vbf.Add(fWplusH125.Get("AIOS_vbf/WplusH125"))
    hAIOS_vbf.Add(fWminusH125.Get("AIOS_vbf/WminusH125"))
    hAIOS_vbf.Add(fZH125.Get("AIOS_vbf/ZH125"))
    for i in range(0,hAIOS_vbf.GetSize()-2):
        if hAIOS_vbf.GetBinContent(i)<0:
            hAIOS_vbf.SetBinError(i,max(0,hAIOS_vbf.GetBinError(i)+hAIOS_vbf.GetBinError(i)))
            hAIOS_vbf.SetBinContent(i,0)

    hAISS_vbf=fVBF125.Get("AISS_vbf/VBF125")
    hAISS_vbf.Add(fggH125.Get("AISS_vbf/ggH125"))
    hAISS_vbf.Add(fWplusH125.Get("AISS_vbf/WplusH125"))
    hAISS_vbf.Add(fWminusH125.Get("AISS_vbf/WminusH125"))
    hAISS_vbf.Add(fZH125.Get("AISS_vbf/ZH125"))
    for i in range(0,hAISS_vbf.GetSize()-2):
        if hAISS_vbf.GetBinContent(i)<0:
            hAISS_vbf.SetBinError(i,max(0,hAISS_vbf.GetBinError(i)+hAISS_vbf.GetBinError(i)))
            hAISS_vbf.SetBinContent(i,0)

    fout.cd()
    dirOS_vbf.cd()
    hOS_vbf.SetName("SMH")
    hOS_vbf.Write()


    dirOStt_vbf.cd()
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


    hOS_inclusive=fVBF125.Get("ttOS_inclusive/VBF125")
    hOS_inclusive.Add(fggH125.Get("ttOS_inclusive/ggH125"))
    hOS_inclusive.Add(fWplusH125.Get("ttOS_inclusive/WplusH125"))
    hOS_inclusive.Add(fWminusH125.Get("ttOS_inclusive/WminusH125"))
    hOS_inclusive.Add(fZH125.Get("ttOS_inclusive/ZH125"))
    for i in range(0,hOS_inclusive.GetSize()-2):
        if hOS_inclusive.GetBinContent(i)<0:
            hOS_inclusive.SetBinError(i,max(0,hOS_inclusive.GetBinError(i)+hOS_inclusive.GetBinError(i)))
            hOS_inclusive.SetBinContent(i,0)

    hSS_inclusive=fVBF125.Get("ttSS_inclusive/VBF125")
    hSS_inclusive.Add(fggH125.Get("ttSS_inclusive/ggH125"))
    hSS_inclusive.Add(fWplusH125.Get("ttSS_inclusive/WplusH125"))
    hSS_inclusive.Add(fWminusH125.Get("ttSS_inclusive/WminusH125"))
    hSS_inclusive.Add(fZH125.Get("ttSS_inclusive/ZH125"))
    for i in range(0,hSS_inclusive.GetSize()-2):
        if hSS_inclusive.GetBinContent(i)<0:
            hSS_inclusive.SetBinError(i,max(0,hSS_inclusive.GetBinError(i)+hSS_inclusive.GetBinError(i)))
            hSS_inclusive.SetBinContent(i,0)

    hAIOS_inclusive=fVBF125.Get("AIOS_inclusive/VBF125")
    hAIOS_inclusive.Add(fggH125.Get("AIOS_inclusive/ggH125"))
    hAIOS_inclusive.Add(fWplusH125.Get("AIOS_inclusive/WplusH125"))
    hAIOS_inclusive.Add(fWminusH125.Get("AIOS_inclusive/WminusH125"))
    hAIOS_inclusive.Add(fZH125.Get("AIOS_inclusive/ZH125"))
    for i in range(0,hAIOS_inclusive.GetSize()-2):
        if hAIOS_inclusive.GetBinContent(i)<0:
            hAIOS_inclusive.SetBinError(i,max(0,hAIOS_inclusive.GetBinError(i)+hAIOS_inclusive.GetBinError(i)))
            hAIOS_inclusive.SetBinContent(i,0)

    hAISS_inclusive=fVBF125.Get("AISS_inclusive/VBF125")
    hAISS_inclusive.Add(fggH125.Get("AISS_inclusive/ggH125"))
    hAISS_inclusive.Add(fWplusH125.Get("AISS_inclusive/WplusH125"))
    hAISS_inclusive.Add(fWminusH125.Get("AISS_inclusive/WminusH125"))
    hAISS_inclusive.Add(fZH125.Get("AISS_inclusive/ZH125"))
    for i in range(0,hAISS_inclusive.GetSize()-2):
        if hAISS_inclusive.GetBinContent(i)<0:
            hAISS_inclusive.SetBinError(i,max(0,hAISS_inclusive.GetBinError(i)+hAISS_inclusive.GetBinError(i)))
            hAISS_inclusive.SetBinContent(i,0)

    fout.cd()
    dirOS_inclusive.cd()
    hOS_inclusive.SetName("SMH")
    hOS_inclusive.Write()

    dirSS_inclusive.cd()
    hSS_inclusive.SetName("SMH")
    hSS_inclusive.Write()

    dirAIOS_inclusive.cd()
    hAIOS_inclusive.SetName("SMH")
    hAIOS_inclusive.Write()

    dirAISS_inclusive.cd()
    hAISS_inclusive.SetName("SMH")
    hAISS_inclusive.Write()

    hOS_vh=fVBF125.Get("ttOS_vh/VBF125")
    hOS_vh.Add(fggH125.Get("ttOS_vh/ggH125"))
    hOS_vh.Add(fWplusH125.Get("ttOS_vh/WplusH125"))
    hOS_vh.Add(fWminusH125.Get("ttOS_vh/WminusH125"))
    hOS_vh.Add(fZH125.Get("ttOS_vh/ZH125"))
    for i in range(0,hOS_vh.GetSize()-2):
        if hOS_vh.GetBinContent(i)<0:
            hOS_vh.SetBinError(i,max(0,hAIOS_vh.GetBinError(i)+hAIOS_vh.GetBinError(i)))
            hOS_vh.SetBinContent(i,0)

    hSS_vh=fVBF125.Get("ttSS_vh/VBF125")
    hSS_vh.Add(fggH125.Get("ttSS_vh/ggH125"))
    hSS_vh.Add(fWplusH125.Get("ttSS_vh/WplusH125"))
    hSS_vh.Add(fWminusH125.Get("ttSS_vh/WminusH125"))
    hSS_vh.Add(fZH125.Get("ttSS_vh/ZH125"))
    for i in range(0,hSS_vh.GetSize()-2):
        if hSS_vh.GetBinContent(i)<0:
            hSS_vh.SetBinError(i,max(0,hSS_vh.GetBinError(i)+hSS_vh.GetBinError(i)))
            hSS_vh.SetBinContent(i,0)

    hAIOS_vh=fVBF125.Get("AIOS_vh/VBF125")
    hAIOS_vh.Add(fggH125.Get("AIOS_vh/ggH125"))
    hAIOS_vh.Add(fWplusH125.Get("AIOS_vh/WplusH125"))
    hAIOS_vh.Add(fWminusH125.Get("AIOS_vh/WminusH125"))
    hAIOS_vh.Add(fZH125.Get("AIOS_vh/ZH125"))
    for i in range(0,hAIOS_vh.GetSize()-2):
        if hAIOS_vh.GetBinContent(i)<0:
            hAIOS_vh.SetBinError(i,max(0,hAIOS_vh.GetBinError(i)+hAIOS_vh.GetBinError(i)))
            hAIOS_vh.SetBinContent(i,0)

    hAISS_vh=fVBF125.Get("AISS_vh/VBF125")
    hAISS_vh.Add(fggH125.Get("AISS_vh/ggH125"))
    hAISS_vh.Add(fWplusH125.Get("AISS_vh/WplusH125"))
    hAISS_vh.Add(fWminusH125.Get("AISS_vh/WminusH125"))
    hAISS_vh.Add(fZH125.Get("AISS_vh/ZH125"))
    for i in range(0,hAISS_vh.GetSize()-2):
        if hAISS_vh.GetBinContent(i)<0:
            hAISS_vh.SetBinError(i,max(0,hAISS_vh.GetBinError(i)+hAISS_vh.GetBinError(i)))
            hAISS_vh.SetBinContent(i,0)
            

    fout.cd()
    dirOS_vh.cd()
    hOS_vh.SetName("SMH")
    hOS_vh.Write()

    dirSS_vh.cd()
    hSS_vh.SetName("SMH")
    hSS_vh.Write()

    dirAIOS_vh.cd()
    hAIOS_vh.SetName("SMH")
    hAIOS_vh.Write()

    dirAISS_vh.cd()
    hAISS_vh.SetName("SMH")
    hAISS_vh.Write()


