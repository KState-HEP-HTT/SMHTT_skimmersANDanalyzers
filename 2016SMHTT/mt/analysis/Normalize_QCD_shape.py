if __name__ == "__main__":

    import ROOT
    import argparse

    fW=ROOT.TFile("files_nominal/QCD.root","r")
    fW_jfru=ROOT.TFile("files_nominal/QCD_wup.root","r")
    fW_jfrd=ROOT.TFile("files_nominal/QCD_wdown.root","r")
    fout_jfru=ROOT.TFile("files_nominal/QCD_wup_norm.root","recreate")
    fout_jfrd=ROOT.TFile("files_nominal/QCD_wdown_norm.root","recreate")

    hW0jet=fW.Get("mt_0jet/QCD")
    hW0jet_u=fW_jfru.Get("mt_0jet/QCD_WSFUncert_mt_0jet_13TeVUp")
    hW0jet_d=fW_jfrd.Get("mt_0jet/QCD_WSFUncert_mt_0jet_13TeVDown")
    hW0jet_u.Scale(hW0jet.Integral()/hW0jet_u.Integral())
    hW0jet_d.Scale(hW0jet.Integral()/hW0jet_d.Integral())

    hW1jet=fW.Get("mt_boosted/QCD")
    hW1jet_u=fW_jfru.Get("mt_boosted/QCD_WSFUncert_mt_boosted_13TeVUp")
    hW1jet_d=fW_jfrd.Get("mt_boosted/QCD_WSFUncert_mt_boosted_13TeVDown")
    hW1jet_u.Scale(hW1jet.Integral()/hW1jet_u.Integral())
    hW1jet_d.Scale(hW1jet.Integral()/hW1jet_d.Integral())

    hW2jet=fW.Get("mt_vbf/QCD")
    hW2jet_u=fW_jfru.Get("mt_vbf/QCD_WSFUncert_mt_vbf_13TeVUp")
    hW2jet_d=fW_jfrd.Get("mt_vbf/QCD_WSFUncert_mt_vbf_13TeVDown")
    hW2jet_u.Scale(hW2jet.Integral()/hW2jet_u.Integral())
    hW2jet_d.Scale(hW2jet.Integral()/hW2jet_d.Integral())

    fout_jfru.cd()
    dir0OS=fout_jfru.mkdir("mt_0jet")
    dir0OS.cd()
    hW0jet_u.SetName("QCD_WSFUncert_mt_0jet_13TeVUp")
    hW0jet_u.Write()
    hW0jet_d.SetName("QCD_WSFUncert_mt_0jet_13TeVDown")
    hW0jet_d.Write()
    dir1OS=fout_jfru.mkdir("mt_boosted")
    dir1OS.cd()
    hW1jet_u.SetName("QCD_WSFUncert_mt_boosted_13TeVUp")
    hW1jet_u.Write()
    hW1jet_d.SetName("QCD_WSFUncert_mt_boosted_13TeVDown")
    hW1jet_d.Write()
    dir2OS=fout_jfru.mkdir("mt_vbf")
    dir2OS.cd()
    hW2jet_u.SetName("QCD_WSFUncert_mt_vbf_13TeVUp")
    hW2jet_u.Write()
    hW2jet_d.SetName("QCD_WSFUncert_mt_vbf_13TeVDown")
    hW2jet_d.Write()

