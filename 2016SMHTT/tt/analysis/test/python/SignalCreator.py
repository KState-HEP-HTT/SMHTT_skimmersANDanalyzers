if __name__ == "__main__":

    import ROOT
    import argparse

    nbhist=1

    fVBF125=ROOT.TFile("outputs_nominal/VBF125.root","r")
    fggH125=ROOT.TFile("outputs_nominal/ggH125.root","r")
    fWH125=ROOT.TFile("outputs_nominal/WH125.root","r")
    fZH125=ROOT.TFile("outputs_nominal/ZH125.root","r")
    fout=ROOT.TFile("outputs_nominal/SMH.root","recreate")


    dirOS_0jet=fout.mkdir("ttOS_0jetR")
    dirSS_0jet=fout.mkdir("ttSS_0jetR")
    dirAIOS_0jet=fout.mkdir("AIOS_0jetR")
    dirAISS_0jet=fout.mkdir("AISS_0jetR")
    dirOS_boosted=fout.mkdir("ttOS_boostedR")
    dirSS_boosted=fout.mkdir("ttSS_boostedR")
    dirAIOS_boosted=fout.mkdir("AIOS_boostedR")
    dirAISS_boosted=fout.mkdir("AISS_boostedR")
    dirOS_vbf=fout.mkdir("ttOS_vbfR")
    dirSS_vbf=fout.mkdir("ttSS_vbfR")
    dirAIOS_vbf=fout.mkdir("AIOS_vbfR")
    dirAISS_vbf=fout.mkdir("AISS_vbfR")

    cats=['0jet','boosted','vbf'] #do not have jobs
    regions=['OS','SS','AIOS','AISS']

    #for cat in cats:
    #    for region in regions:
    hOS_0jet=fVBF125.Get("ttOS_0jetR/VBF125")
    hOS_0jet.Add(fggH125.Get("ttOS_0jetR/ggH125"))
    hOS_0jet.Add(fWH125.Get("ttOS_0jetR/WH125"))
    hOS_0jet.Add(fZH125.Get("ttOS_0jetR/ZH125"))
    for i in range(0,hOS_0jet.GetSize()-2):
        if hOS_0jet.GetBinContent(i)<0:
            hOS_0jet.SetBinError(i,max(0,hOS_0jet.GetBinError(i)+hOS_0jet.GetBinError(i)))
            hOS_0jet.SetBinContent(i,0)

    hSS_0jet=fVBF125.Get("ttSS_0jetR/VBF125")
    hSS_0jet.Add(fggH125.Get("ttSS_0jetR/ggH125"))
    hSS_0jet.Add(fWH125.Get("ttSS_0jetR/WH125"))
    hSS_0jet.Add(fZH125.Get("ttSS_0jetR/ZH125"))
    for i in range(0,hSS_0jet.GetSize()-2):
        if hSS_0jet.GetBinContent(i)<0:
            hSS_0jet.SetBinError(i,max(0,hSS_0jet.GetBinError(i)+hSS_0jet.GetBinError(i)))
            hSS_0jet.SetBinContent(i,0)

    hAIOS_0jet=fVBF125.Get("AIOS_0jetR/VBF125")
    hAIOS_0jet.Add(fggH125.Get("AIOS_0jetR/ggH125"))
    hAIOS_0jet.Add(fWH125.Get("AIOS_0jetR/WH125"))
    hAIOS_0jet.Add(fZH125.Get("AIOS_0jetR/ZH125"))
    for i in range(0,hAIOS_0jet.GetSize()-2):
        if hAIOS_0jet.GetBinContent(i)<0:
            hAIOS_0jet.SetBinError(i,max(0,hAIOS_0jet.GetBinError(i)+hAIOS_0jet.GetBinError(i)))
            hAIOS_0jet.SetBinContent(i,0)

    hAISS_0jet=fVBF125.Get("AISS_0jetR/VBF125")
    hAISS_0jet.Add(fggH125.Get("AISS_0jetR/ggH125"))
    hAISS_0jet.Add(fWH125.Get("AISS_0jetR/WH125"))
    hAISS_0jet.Add(fZH125.Get("AISS_0jetR/ZH125"))
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



    hOS_boosted=fVBF125.Get("ttOS_boostedR/VBF125")
    hOS_boosted.Add(fggH125.Get("ttOS_boostedR/ggH125"))
    hOS_boosted.Add(fWH125.Get("ttOS_boostedR/WH125"))
    hOS_boosted.Add(fZH125.Get("ttOS_boostedR/ZH125"))
    for i in range(0,hOS_boosted.GetSize()-2):
        if hOS_boosted.GetBinContent(i)<0:
            hOS_boosted.SetBinError(i,max(0,hOS_boosted.GetBinError(i)+hOS_boosted.GetBinError(i)))
            hOS_boosted.SetBinContent(i,0)

    hSS_boosted=fVBF125.Get("ttSS_boostedR/VBF125")
    hSS_boosted.Add(fggH125.Get("ttSS_boostedR/ggH125"))
    hSS_boosted.Add(fWH125.Get("ttSS_boostedR/WH125"))
    hSS_boosted.Add(fZH125.Get("ttSS_boostedR/ZH125"))
    for i in range(0,hSS_boosted.GetSize()-2):
        if hSS_boosted.GetBinContent(i)<0:
            hSS_boosted.SetBinError(i,max(0,hSS_boosted.GetBinError(i)+hSS_boosted.GetBinError(i)))
            hSS_boosted.SetBinContent(i,0)


    hAIOS_boosted=fVBF125.Get("AIOS_boostedR/VBF125")
    hAIOS_boosted.Add(fggH125.Get("AIOS_boostedR/ggH125"))
    hAIOS_boosted.Add(fWH125.Get("AIOS_boostedR/WH125"))
    hAIOS_boosted.Add(fZH125.Get("AIOS_boostedR/ZH125"))
    for i in range(0,hAIOS_boosted.GetSize()-2):
        if hAIOS_boosted.GetBinContent(i)<0:
            hAIOS_boosted.SetBinError(i,max(0,hAIOS_boosted.GetBinError(i)+hAIOS_boosted.GetBinError(i)))
            hAIOS_boosted.SetBinContent(i,0)

    hAISS_boosted=fVBF125.Get("AISS_boostedR/VBF125")
    hAISS_boosted.Add(fggH125.Get("AISS_boostedR/ggH125"))
    hAISS_boosted.Add(fWH125.Get("AISS_boostedR/WH125"))
    hAISS_boosted.Add(fZH125.Get("AISS_boostedR/ZH125"))
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





    hOS_vbf=fVBF125.Get("ttOS_vbfR/VBF125")
    hOS_vbf.Add(fggH125.Get("ttOS_vbfR/ggH125"))
    hOS_vbf.Add(fWH125.Get("ttOS_vbfR/WH125"))
    hOS_vbf.Add(fZH125.Get("ttOS_vbfR/ZH125"))
    for i in range(0,hOS_vbf.GetSize()-2):
        if hOS_vbf.GetBinContent(i)<0:
            hOS_vbf.SetBinError(i,max(0,hOS_vbf.GetBinError(i)+hOS_vbf.GetBinError(i)))
            hOS_vbf.SetBinContent(i,0)

    hSS_vbf=fVBF125.Get("ttSS_vbfR/VBF125")
    hSS_vbf.Add(fggH125.Get("ttSS_vbfR/ggH125"))
    hSS_vbf.Add(fWH125.Get("ttSS_vbfR/WH125"))
    hSS_vbf.Add(fZH125.Get("ttSS_vbfR/ZH125"))
    for i in range(0,hSS_vbf.GetSize()-2):
        if hSS_vbf.GetBinContent(i)<0:
            hSS_vbf.SetBinError(i,max(0,hSS_vbf.GetBinError(i)+hSS_vbf.GetBinError(i)))
            hSS_vbf.SetBinContent(i,0)

    hAIOS_vbf=fVBF125.Get("AIOS_vbfR/VBF125")
    hAIOS_vbf.Add(fggH125.Get("AIOS_vbfR/ggH125"))
    hAIOS_vbf.Add(fWH125.Get("AIOS_vbfR/WH125"))
    hAIOS_vbf.Add(fZH125.Get("AIOS_vbfR/ZH125"))
    for i in range(0,hAIOS_vbf.GetSize()-2):
        if hAIOS_vbf.GetBinContent(i)<0:
            hAIOS_vbf.SetBinError(i,max(0,hAIOS_vbf.GetBinError(i)+hAIOS_vbf.GetBinError(i)))
            hAIOS_vbf.SetBinContent(i,0)

    hAISS_vbf=fVBF125.Get("AISS_vbfR/VBF125")
    hAISS_vbf.Add(fggH125.Get("AISS_vbfR/ggH125"))
    hAISS_vbf.Add(fWH125.Get("AISS_vbfR/WH125"))
    hAISS_vbf.Add(fZH125.Get("AISS_vbfR/ZH125"))
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
