if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allJES'], help="Which TES?")

    nbhist=1

    options = parser.parse_args()
    postfix=""

    fDY=ROOT.TFile("files_nominal/DY.root","r")
    fTT=ROOT.TFile("files_"+options.scale+"/TT.root","r")
    fVV=ROOT.TFile("files_"+options.scale+"/VV.root","r")
    fW=ROOT.TFile("files_"+options.scale+"/W.root","r")
    fData=ROOT.TFile("files_nominal/data.root","r")
    fout=ROOT.TFile("files_"+options.scale+"/QCD.root","recreate")


    dirQCD=fout.mkdir("ttOS")

    postfixData=""
    hAIOS=fData.Get("AIOS/data_obs"+postfixData)
    for i in range(0,hAIOS.GetSize()-2):
        if hAIOS.GetBinContent(i)<0:
            hAIOS.SetBinError(i,max(0,hAIOS.GetBinError(i)+hAIOS.GetBinError(i)))
            hAIOS.SetBinContent(i,0)

    hAISS=fData.Get("AISS/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.
    hAISS.Add(fDY.Get("AISS/DY"+postfix),-1)
    hAISS.Add(fTT.Get("AISS/TT"+postfix),-1)
    hAISS.Add(fVV.Get("AISS/VV"+postfix),-1)
    hAISS.Add(fW.Get("AISS/W"+postfix),-1)
    for i in range(0,hAISS.GetSize()-2):
        if hAISS.GetBinContent(i)<0:
            hAISS.SetBinError(i,max(0,hAISS.GetBinError(i)+hAISS.GetBinError(i)))
            hAISS.SetBinContent(i,0)

    hSS=fData.Get("ttSS/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.
    hSS.Add(fDY.Get("ttSS/DY"+postfix),-1)
    hSS.Add(fTT.Get("ttSS/TT"+postfix),-1)
    hSS.Add(fVV.Get("ttSS/VV"+postfix),-1)
    hSS.Add(fW.Get("ttSS/W"+postfix),-1)
    for i in range(0,hSS.GetSize()-2):
        if hSS.GetBinContent(i)<0:
            hSS.SetBinError(i,max(0,hSS.GetBinError(i)+hSS.GetBinError(i)))
            hSS.SetBinContent(i,0)

    # AN eq(14)
    hSF = hSS.Clone()
    hSF.Divide(hSS,hAISS,1,1,"B")
    hQCD = hSF.Clone()
    hQCD.Multiply(hAIOS,hSF,1,1,"B")

    fout.cd()
    dirQCD.cd()
    hAIOS.SetName("OSLooseIso"+postfix)
    hAISS.SetName("SSLooseIso"+postfix)
    hSS.SetName("SignalLike"+postfix)
    hSF.SetName("ScaleFactor"+postfix)
    hQCD.SetName("QCD"+postfix)
    hAIOS.Write()
    hAISS.Write()
    hSS.Write()
    hSF.Write()
    hQCD.Write()





