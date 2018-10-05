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

    fDYB=ROOT.TFile("files_"+options.scale+"/DYll.root","r")
    fDYS=ROOT.TFile("files_"+options.scale+"/DYtt.root","r")
    fW=ROOT.TFile("files_"+options.scale+"/Wunscaled.root","r")
    fTT=ROOT.TFile("files_"+options.scale+"/TT.root","r")
    fVV=ROOT.TFile("files_"+options.scale+"/VV.root","r")
    fData=ROOT.TFile("files_nominal/Data.root","r")
    fout=ROOT.TFile("files_"+anti+options.scale+"/W.root","recreate")

    fW_=ROOT.TFile("files_"+anti+options.scale+"/Wunscaled.root","r")

    SFpassOS=(fData.Get("n70").GetBinContent(1)-fDYB.Get("n70").GetBinContent(1)-fDYS.Get("n70").GetBinContent(1)-fTT.Get("n70").GetBinContent(1))/fW.Get("n70").GetBinContent(1)
    print SFpassOS
    hW0jet_1=fW_.Get("mt_0jet_low/W"+postfix)
    hW0jet_1.Scale(SFpassOS)
    hW0jet_2=fW_.Get("mt_0jet_high/W"+postfix)
    hW0jet_2.Scale(SFpassOS)
    hW1jet_1=fW_.Get("mt_1jet_low/W"+postfix)
    hW1jet_1.Scale(SFpassOS)
    hW1jet_2=fW_.Get("mt_1jet_high/W"+postfix)
    hW1jet_2.Scale(SFpassOS)
    hW2jet_1=fW_.Get("mt_vbf_low/W"+postfix)
    hW2jet_1.Scale(SFpassOS)
    hW2jet_2=fW_.Get("mt_vbf_high/W"+postfix)
    hW2jet_2.Scale(SFpassOS)
    hW0jet_1SS=fW_.Get("SS0jet_cat1/W"+postfix)
    hW0jet_1SS.Scale(SFpassOS)
    hW0jet_2SS=fW_.Get("SS0jet_cat2/W"+postfix)
    hW0jet_2SS.Scale(SFpassOS)
    hW1jet_1SS=fW_.Get("SS1jet_cat1/W"+postfix)
    hW1jet_1SS.Scale(SFpassOS)
    hW1jet_2SS=fW_.Get("SS1jet_cat2/W"+postfix)
    hW1jet_2SS.Scale(SFpassOS)
    hW2jet_1SS=fW_.Get("SS2jet_cat1/W"+postfix)
    hW2jet_1SS.Scale(SFpassOS)
    hW2jet_2SS=fW_.Get("SS2jet_cat2/W"+postfix)
    hW2jet_2SS.Scale(SFpassOS)

    fout.cd()
    dir0OS1=fout.mkdir("mt_0jet_low")
    dir0OS1.cd()
    hW0jet_1.SetName("W"+postfix)
    hW0jet_1.Write()
    dir0OS2=fout.mkdir("mt_0jet_high")
    dir0OS2.cd()
    hW0jet_2.SetName("W"+postfix)
    hW0jet_2.Write()
    dir1OS1=fout.mkdir("mt_1jet_low")
    dir1OS1.cd()
    hW1jet_1.SetName("W"+postfix)
    hW1jet_1.Write()
    dir1OS2=fout.mkdir("mt_1jet_high")
    dir1OS2.cd()
    hW1jet_2.SetName("W"+postfix)
    hW1jet_2.Write()
    dir2OS1=fout.mkdir("mt_vbf_low")
    dir2OS1.cd()
    hW2jet_1.SetName("W"+postfix)
    hW2jet_1.Write()
    dir2OS2=fout.mkdir("mt_vbf_high")
    dir2OS2.cd()
    hW2jet_2.SetName("W"+postfix)
    hW2jet_2.Write()

    dir0SS1=fout.mkdir("SS0jet_cat1")
    dir0SS1.cd()
    hW0jet_1SS.SetName("W"+postfix)
    hW0jet_1SS.Write()
    dir0SS2=fout.mkdir("SS0jet_cat2")
    dir0SS2.cd()
    hW0jet_2SS.SetName("W"+postfix)
    hW0jet_2SS.Write()
    dir1SS1=fout.mkdir("SS1jet_cat1")
    dir1SS1.cd()
    hW1jet_1SS.SetName("W"+postfix)
    hW1jet_1SS.Write()
    dir1SS2=fout.mkdir("SS1jet_cat2")
    dir1SS2.cd()
    hW1jet_2SS.SetName("W"+postfix)
    hW1jet_2SS.Write()
    dir2SS1=fout.mkdir("SS2jet_cat1")
    dir2SS1.cd()
    hW2jet_1SS.SetName("W"+postfix)
    hW2jet_1SS.Write()
    dir2SS2=fout.mkdir("SS2jet_cat2")
    dir2SS2.cd()
    hW2jet_2SS.SetName("W"+postfix)
    hW2jet_2SS.Write()

