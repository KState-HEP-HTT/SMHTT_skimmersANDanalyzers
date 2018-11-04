if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal_FF_tautau", choices=['nominal', 'up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allJES'], help="Which TES?")

    nbhist=1

    options = parser.parse_args()
    if options.scale=="nominal_FF_tautau":
        nbhist=31

    postfix=""

    fzj=ROOT.TFile("outputs_"+options.scale+"/ZJ.root","r")
    fzl=ROOT.TFile("outputs_"+options.scale+"/ZL.root","r")
    fDY=ROOT.TFile("outputs_"+options.scale+"/ZTT.root","r")
    fW=ROOT.TFile("outputs_"+options.scale+"/W.root","r")
    fTTj=ROOT.TFile("outputs_"+options.scale+"/TTJ.root","r")
    fTT=ROOT.TFile("outputs_"+options.scale+"/TTT.root","r")
    fVV=ROOT.TFile("outputs_"+options.scale+"/VVT.root","r")
    fData=ROOT.TFile("outputs_nominal_FF_tautau/data.root","r")

    fout=ROOT.TFile("outputs_"+options.scale+"/Fake.root","recreate")

    postfixFF=["","_norm_ff_qcd_mt_systUp","_norm_ff_qcd_mt_systDown","_norm_ff_qcd_dm0_njet0_mt_statUp","_norm_ff_qcd_dm0_njet0_mt_statDown","_norm_ff_qcd_dm0_njet1_mt_statUp","_norm_ff_qcd_dm0_njet1_mt_statDown","_norm_ff_qcd_dm1_njet0_mt_statUp","_norm_ff_qcd_dm1_njet0_mt_statDown","_norm_ff_qcd_dm1_njet1_mt_statUp","_norm_ff_qcd_dm1_njet1_mt_statDown","_norm_ff_w_mt_systUp","_norm_ff_w_mt_systDown","_norm_ff_w_dm0_njet0_mt_statUp","_norm_ff_w_dm0_njet0_mt_statDown","_norm_ff_w_dm0_njet1_mt_statUp","_norm_ff_w_dm0_njet1_mt_statDown","_norm_ff_w_dm1_njet0_mt_statUp","_norm_ff_w_dm1_njet0_mt_statDown","_norm_ff_w_dm1_njet1_mt_statUp","_norm_ff_w_dm1_njet1_mt_statDown","_norm_ff_tt_mt_systUp","_norm_ff_tt_mt_systDown","_norm_ff_tt_dm0_njet0_mt_statUp","_norm_ff_tt_dm0_njet0_mt_statDown","_norm_ff_tt_dm0_njet1_mt_statUp","_norm_ff_tt_dm0_njet1_mt_statDown","_norm_ff_tt_dm1_njet0_mt_statUp","_norm_ff_tt_dm1_njet0_mt_statDown","_norm_ff_tt_dm1_njet1_mt_statUp","_norm_ff_tt_dm1_njet1_mt_statDown"];


    dir0jet=fout.mkdir("tt_0jet")
    dirboosted=fout.mkdir("tt_boosted")
    dirvbf=fout.mkdir("tt_vbf")




    postfixData=""
    for k in range(0,nbhist):
	if options.scale=="nominal":
	   postfix=postfixFF[k]
	   postfixData=postfixFF[k]

        h_0jet=fData.Get("AI0jet_FF/data_obs"+postfixData)

        h_0jet.Add(fDY.Get("AI0jet_FF/ZTT"+postfix),-1)
        h_0jet.Add(fzl.Get("AI0jet_FF/ZL"+postfix),-1)
#        h_0jet.Add(fzj.Get("AI0jet_FF/ZJ"+postfix),-1)
        h_0jet.Add(fW.Get("AI0jet_FF/W"+postfix),-1)
        h_0jet.Add(fTT.Get("AI0jet_FF/TTT"+postfix),-1)
#        h_0jet.Add(fTTj.Get("AI0jet_FF/TTJ"+postfix),-1)
        h_0jet.Add(fVV.Get("AI0jet_FF/VVT"+postfix),-1)

        for i in range(0,h_0jet.GetSize()-2):
            if h_0jet.GetBinContent(i)<0:
                h_0jet.SetBinError(i,max(0,h_0jet.GetBinError(i)+h_0jet.GetBinError(i)))
                h_0jet.SetBinContent(i,0)



        h_boosted=fData.Get("AIboosted_FF/data_obs"+postfixData)
    
        h_boosted.Add(fDY.Get("AIboosted_FF/ZTT"+postfix),-1)
        h_boosted.Add(fzl.Get("AIboosted_FF/ZL"+postfix),-1)
#        h_boosted.Add(fzj.Get("AIboosted_FF/ZJ"+postfix),-1)
        h_boosted.Add(fW.Get("AIboosted_FF/W"+postfix),-1)
        h_boosted.Add(fTT.Get("AIboosted_FF/TTT"+postfix),-1)
#        h_boosted.Add(fTTj.Get("AIboosted_FF/TTJ"+postfix),-1)
        h_boosted.Add(fVV.Get("AIboosted_FF/VVT"+postfix),-1)
        
        for i in range(0,h_boosted.GetSize()-2):
            if h_boosted.GetBinContent(i)<0:
                h_boosted.SetBinError(i,max(0,h_boosted.GetBinError(i)+h_boosted.GetBinError(i)))
                h_boosted.SetBinContent(i,0)
    

        h_vbf=fData.Get("AIvbf_FF/data_obs"+postfixData)
    
        h_boosted.Add(fDY.Get("AIvbf_FF/ZTT"+postfix),-1)
        h_vbf.Add(fzl.Get("AIvbf_FF/ZL"+postfix),-1)
#        h_vbf.Add(fzj.Get("AIvbf_FF/ZJ"+postfix),-1)
        h_vbf.Add(fW.Get("AIvbf_FF/W"+postfix),-1)
        h_vbf.Add(fTT.Get("AIvbf_FF/TTT"+postfix),-1)
#        h_vbf.Add(fTTj.Get("AIvbf_FF/TTJ"+postfix),-1)
        h_vbf.Add(fVV.Get("AIvbf_FF/VVT"+postfix),-1)
        
        for i in range(0,h_vbf.GetSize()-2):
            if h_vbf.GetBinContent(i)<0:
                h_vbf.SetBinError(i,max(0,h_vbf.GetBinError(i)+h_vbf.GetBinError(i)))
                h_vbf.SetBinContent(i,0)
    
    

        fout.cd()
        dir0jet.cd()
        h_0jet.SetName("jetFakes"+postfix)
        h_0jet.Write()


        dirboosted.cd()
        h_boosted.SetName("jetFakes"+postfix)
        h_boosted.Write()

        dirvbf.cd()
        h_vbf.SetName("jetFakes"+postfix)
        h_vbf.Write()


