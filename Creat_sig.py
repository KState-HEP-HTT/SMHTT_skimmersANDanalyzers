if __name__ == "__main__":

    import ROOT
    import argparse

    nbhist=1

    fVBF125=ROOT.TFile("files_nominal/VBF125.root","r")
    fggH125=ROOT.TFile("files_nominal/ggH125.root","r")
    fout=ROOT.TFile("files_nominal/SMH.root","recreate")


    dirOS=fout.mkdir("ttOS")
    dirSS=fout.mkdir("ttSS")
    dirAIOS=fout.mkdir("AIOS")
    dirAISS=fout.mkdir("AISS")

    hOS=fVBF125.Get("ttOS/VBF125")
    hOS.Add(fggH125.Get("ttOS/ggH125"))
    for i in range(0,hOS.GetSize()-2):
        if hOS.GetBinContent(i)<0:
            hOS.SetBinError(i,max(0,hAIOS.GetBinError(i)+hAIOS.GetBinError(i)))
            hOS.SetBinContent(i,0)

    hSS=fVBF125.Get("ttSS/VBF125")
    hSS.Add(fggH125.Get("ttSS/ggH125"))
    for i in range(0,hSS.GetSize()-2):
        if hSS.GetBinContent(i)<0:
            hSS.SetBinError(i,max(0,hAISS.GetBinError(i)+hAISS.GetBinError(i)))
            hSS.SetBinContent(i,0)


    hAIOS=fVBF125.Get("AIOS/VBF125")
    hAIOS.Add(fggH125.Get("AIOS/ggH125"))
    for i in range(0,hAIOS.GetSize()-2):
        if hAIOS.GetBinContent(i)<0:
            hAIOS.SetBinError(i,max(0,hAIAIOS.GetBinError(i)+hAIAIOS.GetBinError(i)))
            hAIOS.SetBinContent(i,0)

    hAISS=fVBF125.Get("AISS/VBF125")
    hAISS.Add(fggH125.Get("AISS/ggH125"))
    for i in range(0,hAISS.GetSize()-2):
        if hAISS.GetBinContent(i)<0:
            hAISS.SetBinError(i,max(0,hAIAISS.GetBinError(i)+hAIAISS.GetBinError(i)))
            hAISS.SetBinContent(i,0)


    fout.cd()
    dirOS.cd()
    hOS.SetName("SMH")
    hOS.Write()

    dirSS.cd()
    hSS.SetName("SMH")
    hSS.Write()

    dirAIOS.cd()
    hAIOS.SetName("SMH")
    hAIOS.Write()

    dirAISS.cd()
    hAISS.SetName("SMH")
    hAISS.Write()






