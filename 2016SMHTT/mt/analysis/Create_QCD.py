if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down', 'wup', 'wdown'], help="Which TES?")
    options = parser.parse_args()

    postfix=""
    if (options.scale=="up"):
        postfix="_TESUp"
    if (options.scale=="down"):
        postfix="_TESDown"

    postfixP=""
    if (options.scale=="up"):
        postfixP="_TESUp"
    if (options.scale=="down"):
        postfixP="_TESDown"
    if (options.scale=="wup"):
        postfixP="_WnormPassUp"
    if (options.scale=="wdown"):
        postfixP="_WnormPassDown"

    postfixF=""
    if (options.scale=="up"):
        postfixF="_TESUp"
    if (options.scale=="down"):
        postfixF="_TESDown"
    if (options.scale=="wup"):
        postfixF="_WnormFailUp"
    if (options.scale=="wdown"):
        postfixF="_WnormFailDown"

    facteur=1.0
    if (options.scale=="wup"):
        facteur=1.10
    if (options.scale=="wdown"):
        facteur=0.90

    if options.scale=="up" or options.scale=="down":
       fDYB=ROOT.TFile("files_"+options.scale+"/ZLL.root","r")
       fDYS=ROOT.TFile("files_"+options.scale+"/ZTT.root","r")
       fW=ROOT.TFile("files_"+options.scale+"/W.root","r")
       fTT=ROOT.TFile("files_"+options.scale+"/TT.root","r")
       fVV=ROOT.TFile("files_"+options.scale+"/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
    else:
       fDYB=ROOT.TFile("files_nominal/ZLL.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W.root","r")
       fTT=ROOT.TFile("files_nominal/TT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
    fout=ROOT.TFile("files_"+options.scale+"/QCD.root","recreate")

    hSS_0jet1=fData.Get("SS0jet_cat1/data_obs")
    hSS_0jet1.Add(fDYB.Get("SS0jet_cat1/ZLL"+postfix),-1)
    hSS_0jet1.Add(fTT.Get("SS0jet_cat1/TT"+postfix),-1)
    hSS_0jet1.Add(fW.Get("SS0jet_cat1/W"+postfix),-1*facteur)
    hSS_0jet1.Add(fVV.Get("SS0jet_cat1/VV"+postfix),-1)
    hSS_0jet1.Add(fDYS.Get("SS0jet_cat1/ZTT"+postfix),-1)
    hSS_0jet1.SetName("QCD"+postfixP)
    hSS_0jet1.Scale(1.06)
    for i in range(0,hSS_0jet1.GetSize()-2):
	if hSS_0jet1.GetBinContent(i)<0:
	    hSS_0jet1.SetBinContent(i,0)

    hSS_1jet1=fData.Get("SS1jet_cat1/data_obs")
    hSS_1jet1.Add(fDYB.Get("SS1jet_cat1/ZLL"+postfix),-1)
    hSS_1jet1.Add(fTT.Get("SS1jet_cat1/TT"+postfix),-1)
    hSS_1jet1.Add(fW.Get("SS1jet_cat1/W"+postfix),-1*facteur)
    hSS_1jet1.Add(fVV.Get("SS1jet_cat1/VV"+postfix),-1)
    hSS_1jet1.Add(fDYS.Get("SS1jet_cat1/ZTT"+postfix),-1)
    hSS_1jet1.SetName("QCD"+postfixP)
    hSS_1jet1.Scale(1.06)
    for i in range(0,hSS_1jet1.GetSize()-2):
        if hSS_1jet1.GetBinContent(i)<0:
            hSS_1jet1.SetBinContent(i,0)

    hSS_0jet2=fData.Get("SS0jet_cat2/data_obs")
    hSS_0jet2.Add(fDYB.Get("SS0jet_cat2/ZLL"+postfix),-1)
    hSS_0jet2.Add(fTT.Get("SS0jet_cat2/TT"+postfix),-1)
    hSS_0jet2.Add(fW.Get("SS0jet_cat2/W"+postfix),-1*facteur)
    hSS_0jet2.Add(fVV.Get("SS0jet_cat2/VV"+postfix),-1)
    hSS_0jet2.Add(fDYS.Get("SS0jet_cat2/ZTT"+postfix),-1)
    hSS_0jet2.SetName("QCD"+postfixP)
    hSS_0jet2.Scale(1.06)
    for i in range(0,hSS_0jet2.GetSize()-2):
        if hSS_0jet2.GetBinContent(i)<0:
            hSS_0jet2.SetBinContent(i,0)

    hSS_1jet2=fData.Get("SS1jet_cat2/data_obs")
    hSS_1jet2.Add(fDYB.Get("SS1jet_cat2/ZLL"+postfix),-1)
    hSS_1jet2.Add(fTT.Get("SS1jet_cat2/TT"+postfix),-1)
    hSS_1jet2.Add(fW.Get("SS1jet_cat2/W"+postfix),-1*facteur)
    hSS_1jet2.Add(fVV.Get("SS1jet_cat2/VV"+postfix),-1)
    hSS_1jet2.Add(fDYS.Get("SS1jet_cat2/ZTT"+postfix),-1)
    hSS_1jet2.SetName("QCD"+postfixP)
    hSS_1jet2.Scale(1.06)
    for i in range(0,hSS_1jet2.GetSize()-2):
        if hSS_1jet2.GetBinContent(i)<0:
            hSS_1jet2.SetBinContent(i,0)

    hSS_2jet1=fData.Get("SS2jet_cat1/data_obs")
    hSS_2jet1.Add(fDYB.Get("SS2jet_cat1/ZLL"+postfix),-1)
    hSS_2jet1.Add(fTT.Get("SS2jet_cat1/TT"+postfix),-1)
    hSS_2jet1.Add(fW.Get("SS2jet_cat1/W"+postfix),-1*facteur)
    hSS_2jet1.Add(fVV.Get("SS2jet_cat1/VV"+postfix),-1)
    hSS_2jet1.Add(fDYS.Get("SS2jet_cat1/ZTT"+postfix),-1)
    hSS_2jet1.SetName("QCD"+postfixP)
    hSS_2jet1.Scale(1.06)
    for i in range(0,hSS_2jet1.GetSize()-2):
        if hSS_2jet1.GetBinContent(i)<0:
            hSS_2jet1.SetBinContent(i,0)

    hSS_2jet2=fData.Get("SS2jet_cat2/data_obs")
    hSS_2jet2.Add(fDYB.Get("SS2jet_cat2/ZLL"+postfix),-1)
    hSS_2jet2.Add(fTT.Get("SS2jet_cat2/TT"+postfix),-1)
    hSS_2jet2.Add(fW.Get("SS2jet_cat2/W"+postfix),-1*facteur)
    hSS_2jet2.Add(fVV.Get("SS2jet_cat2/VV"+postfix),-1)
    hSS_2jet2.Add(fDYS.Get("SS2jet_cat2/ZTT"+postfix),-1)
    hSS_2jet2.SetName("QCD"+postfixP)
    hSS_2jet2.Scale(1.06)
    for i in range(0,hSS_2jet2.GetSize()-2):
        if hSS_2jet2.GetBinContent(i)<0:
            hSS_2jet2.SetBinContent(i,0)

    fout.cd()
    dir0jet1=fout.mkdir("mt_0jet_low")
    dir0jet1.cd()
    hSS_0jet1.Write()

    dir0jet2=fout.mkdir("mt_0jet_high")
    dir0jet2.cd()
    hSS_0jet2.Write()

    dir1jet1=fout.mkdir("mt_1jet_low")
    dir1jet1.cd()
    hSS_1jet1.Write()

    dir1jet2=fout.mkdir("mt_1jet_high")
    dir1jet2.cd()
    hSS_1jet2.Write()

    dir2jet1=fout.mkdir("mt_vbf_low")
    dir2jet1.cd()
    hSS_2jet1.Write()

    dir2jet2=fout.mkdir("mt_vbf_high")
    dir2jet2.cd()
    hSS_2jet2.Write()

