if __name__ == "__main__":

    import ROOT
    import argparse

    fcentral=ROOT.TFile("files_nominal/ZL.root","r")
    fshifted=ROOT.TFile("files_nominal/ZL_dm.root","r")
    fnormalized=ROOT.TFile("files_nominal/ZL_dm_norm.root","recreate")

    h0=fcentral.Get("mt_0jet/ZL")
    h0_1=fshifted.Get("mt_0jet/ZL_CMS_mFakeTau_0jet_tauDMReco_13TeVUp")
    h0_1.Scale(h0.Integral()/h0_1.Integral())
    h0_2=fshifted.Get("mt_0jet/ZL_CMS_mFakeTau_0jet_tauDMReco_13TeVDown")
    h0_2.Scale(h0.Integral()/h0_2.Integral())

    fnormalized.cd()
    dir0OS=fnormalized.mkdir("mt_0jet")
    dir0OS.cd()
    h0_1.Write()
    h0_2.Write()

