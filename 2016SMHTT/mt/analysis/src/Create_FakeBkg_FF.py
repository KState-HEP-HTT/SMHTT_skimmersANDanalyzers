if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="_nominal", choices=['nominal', 'up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allJES'], help="Which TES?")


    # This is folder where all the process root files are stored
    fileName='files_nominal_FF'

    options = parser.parse_args()

#    if options.scale=="nominal":
#        nbhist=31

##########################################
# Note that we do not need to subtract the non-data processes from data anymore !
##########################################
#    fzj=ROOT.TFile(fileName+"/ZJ.root","r")
#    fzl=ROOT.TFile(fileName+"/ZL.root","r")
#    fDY=ROOT.TFile(fileName+"/ZTT.root","r")
#    fW=ROOT.TFile(fileName+"/W.root","r")
#    fTTj=ROOT.TFile(fileName+"/TTJ.root","r")
#    fTT=ROOT.TFile(fileName+"/TTT.root","r")
#    fVV=ROOT.TFile(fileName+"/VV.root","r")

    fData=ROOT.TFile(fileName+"/Data.root","r")

    # Output file
    fout=ROOT.TFile(fileName+"/Fake.root","recreate")





    postfixFF=["","_norm_ff_qcd_mt_systUp","_norm_ff_qcd_mt_systDown","_norm_ff_qcd_dm0_njet0_mt_statUp","_norm_ff_qcd_dm0_njet0_mt_statDown","_norm_ff_qcd_dm0_njet1_mt_statUp","_norm_ff_qcd_dm0_njet1_mt_statDown","_norm_ff_qcd_dm1_njet0_mt_statUp","_norm_ff_qcd_dm1_njet0_mt_statDown","_norm_ff_qcd_dm1_njet1_mt_statUp","_norm_ff_qcd_dm1_njet1_mt_statDown","_norm_ff_w_mt_systUp","_norm_ff_w_mt_systDown","_norm_ff_w_dm0_njet0_mt_statUp","_norm_ff_w_dm0_njet0_mt_statDown","_norm_ff_w_dm0_njet1_mt_statUp","_norm_ff_w_dm0_njet1_mt_statDown","_norm_ff_w_dm1_njet0_mt_statUp","_norm_ff_w_dm1_njet0_mt_statDown","_norm_ff_w_dm1_njet1_mt_statUp","_norm_ff_w_dm1_njet1_mt_statDown","_norm_ff_tt_mt_systUp","_norm_ff_tt_mt_systDown","_norm_ff_tt_dm0_njet0_mt_statUp","_norm_ff_tt_dm0_njet0_mt_statDown","_norm_ff_tt_dm0_njet1_mt_statUp","_norm_ff_tt_dm0_njet1_mt_statDown","_norm_ff_tt_dm1_njet0_mt_statUp","_norm_ff_tt_dm1_njet0_mt_statDown","_norm_ff_tt_dm1_njet1_mt_statUp","_norm_ff_tt_dm1_njet1_mt_statDown"]


    dir0jet=fout.mkdir("mt_0jet")
    dirboosted=fout.mkdir("mt_boosted")
    dirvbf=fout.mkdir("mt_vbf")



    nbhist=1

    for k in range(0,nbhist):
#	if options.scale=="nominal":

        postfix=postfixFF[k]

        h_0jet=fData.Get("AI0jet_FF/data_obs"+postfix)
        h_boosted=fData.Get("AIboosted_FF/data_obs"+postfix)
        h_vbf=fData.Get("AIvbf_FF/data_obs"+postfix)
    
        fout.cd()
        
        dir0jet.cd()
        h_0jet.SetName("jetFakes"+postfix)
        h_0jet.Write()
        print "h_0jet= ", h_0jet.Integral()


        dirboosted.cd()
        h_boosted.SetName("jetFakes"+postfix)
        h_boosted.Write()
        print "h_boosted= ", h_boosted.Integral()

        dirvbf.cd()
        h_vbf.SetName("jetFakes"+postfix)
        h_vbf.Write()
        print "h_vbf= ", h_vbf.Integral()


