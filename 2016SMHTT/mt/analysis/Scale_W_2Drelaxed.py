if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down'], help="Which TES?")
    parser.add_argument('--anti', default="iso", choices=['iso', 'anti'], help="Which TES?")
    options = parser.parse_args()

    anti=""
    if (options.anti=="anti"):
        anti="anti_"

    postfix=""
    if (options.scale=="up"):
        postfix="_TESUp"
    if (options.scale=="down"):
        postfix="_TESDown"

    fDYB=ROOT.TFile("files_"+options.scale+"/ZTT.root","r")
    fDYS=ROOT.TFile("files_"+options.scale+"/ZLL.root","r")
    fW=ROOT.TFile("files_"+options.scale+"/Wunscaled.root","r")
    fTT=ROOT.TFile("files_"+options.scale+"/TT.root","r")
    fVV=ROOT.TFile("files_"+options.scale+"/VV.root","r")
    fData=ROOT.TFile("files_nominal/Data.root","r")
    fout=ROOT.TFile("files_"+anti+options.scale+"/W.root","recreate")

    fW_=ROOT.TFile("files_"+anti+options.scale+"/Wunscaled.root","r")

    SFpassOS=(fData.Get("n70").GetBinContent(1)-fDYB.Get("n70").GetBinContent(1)-fDYS.Get("n70").GetBinContent(1)-fTT.Get("n70").GetBinContent(1))/fW.Get("n70").GetBinContent(1)
    print SFpassOS
    hW0jet=fW_.Get("mt_0jet/W"+postfix)
    hW0jet.Scale(SFpassOS)
    hW1jet=fW_.Get("mt_1jet/W"+postfix)
    hW1jet.Scale(SFpassOS)
    hW2jet=fW_.Get("mt_vbf/W"+postfix)
    hW2jet.Scale(SFpassOS)
    hW0jet_SS=fW_.Get("SS0jet/W"+postfix)
    hW0jet_SS.Scale(SFpassOS)
    hW1jet_SS=fW_.Get("SS1jet/W"+postfix)
    hW1jet_SS.Scale(SFpassOS)
    hW2jet_SS=fW_.Get("SSvbf/W"+postfix)
    hW2jet_SS.Scale(SFpassOS)
    hW0jet_QCD=fW_.Get("QCD0jet/W"+postfix)
    hW0jet_QCD.Scale(SFpassOS)
    hW1jet_QCD=fW_.Get("QCD1jet/W"+postfix)
    hW1jet_QCD.Scale(SFpassOS)
    hW2jet_QCD=fW_.Get("QCDvbf/W"+postfix)
    hW2jet_QCD.Scale(SFpassOS)

    fout.cd()
    dir0OS=fout.mkdir("mt_0jet")
    dir0OS.cd()
    hW0jet.SetName("W"+postfix)
    hW0jet.Write()
    dir1OS=fout.mkdir("mt_1jet")
    dir1OS.cd()
    hW1jet.SetName("W"+postfix)
    hW1jet.Write()
    dir2OS=fout.mkdir("mt_vbf")
    dir2OS.cd()
    hW2jet.SetName("W"+postfix)
    hW2jet.Write()

    dir0SS=fout.mkdir("SS0jet")
    dir0SS.cd()
    hW0jet_SS.SetName("W"+postfix)
    hW0jet_SS.Write()
    dir1SS=fout.mkdir("SS1jet")
    dir1SS.cd()
    hW1jet_SS.SetName("W"+postfix)
    hW1jet_SS.Write()
    dir2SS=fout.mkdir("SSvbf")
    dir2SS.cd()
    hW2jet_SS.SetName("W"+postfix)
    hW2jet_SS.Write()

    dir0QCD=fout.mkdir("QCD0jet")
    dir0QCD.cd()
    hW0jet_QCD.SetName("W"+postfix)
    hW0jet_QCD.Write()
    dir1QCD=fout.mkdir("QCD1jet")
    dir1QCD.cd()
    hW1jet_QCD.SetName("W"+postfix)
    hW1jet_QCD.Write()
    dir2QCD=fout.mkdir("QCDvbf")
    dir2QCD.cd()
    hW2jet_QCD.SetName("W"+postfix)
    hW2jet_QCD.Write()

