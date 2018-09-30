if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal','allJES','qcdup','qcddown','wup','wdown','up', 'down','JESup','JESdown','allTES'], help="Which TES?")
    parser.add_argument('--anti', default="iso", choices=['iso', 'anti'], help="Which TES?")
    options = parser.parse_args()

    nbhist=1
    if options.scale=="allJES":
      nbhist=56
    if options.scale=="allTES":
      nbhist=12

    factorw0jet=1.0
    factorw1jet=1.0
    factorw2jet=1.0

    factorw0jet_u=1.10
    factorw1jet_u=1.10
    factorw2jet_u=1.30

    factorw0jet_d=0.90
    factorw1jet_d=0.90
    factorw2jet_d=0.70

    if (options.scale=="wup"):
        factorw0jet=factorw0jet_u
        factorw1jet=factorw1jet_u
        factorw2jet=factorw2jet_u
    if (options.scale=="wdown"):
        factorw0jet=factorw0jet_d
        factorw1jet=factorw1jet_d
        factorw2jet=factorw2jet_d

    factor0jet=1.07
    factor1jet=1.06
    factor2jet=1.00

    factor0jet_u=1.11
    factor1jet_u=1.12
    factor2jet_u=1.20

    factor0jet_d=1.03
    factor1jet_d=1.00
    factor2jet_d=0.80

    if (options.scale=="qcdup"):
        factor0jet=factor0jet_u
        factor1jet=factor1jet_u
        factor2jet=factor2jet_u
    if (options.scale=="qcddown"):
        factor0jet=factor0jet_d
        factor1jet=factor1jet_d
        factor2jet=factor2jet_d

    postfix=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix0=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix1=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfixTES=["_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"]
    if (options.scale!="allJES"):
        postfix[0]=""
        postfix0[0]=""
        postfix1[0]=""
        postfix2[0]=""
    if (options.scale=="up"):
        postfix[0]="_CMS_scale_t_mt_13TeVUp"
        postfix0[0]="_CMS_scale_t_mt_13TeVUp"
        postfix1[0]="_CMS_scale_t_mt_13TeVUp"
        postfix2[0]="_CMS_scale_t_mt_13TeVUp"
    if (options.scale=="down"):
        postfix[0]="_CMS_scale_t_mt_13TeVDown"
        postfix0[0]="_CMS_scale_t_mt_13TeVDown"
        postfix1[0]="_CMS_scale_t_mt_13TeVDown"
        postfix2[0]="_CMS_scale_t_mt_13TeVDown"
    if (options.scale=="JESup"):
        postfix[0]="_CMS_scale_j_13TeVUp"
        postfix0[0]="_CMS_scale_j_13TeVUp"
        postfix1[0]="_CMS_scale_j_13TeVUp"
        postfix2[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
        postfix[0]="_CMS_scale_j_13TeVDown"
        postfix0[0]="_CMS_scale_j_13TeVDown"
        postfix1[0]="_CMS_scale_j_13TeVDown"
        postfix2[0]="_CMS_scale_j_13TeVDown"
    if (options.scale=="qcdup"):
        postfix0[0]="_QCDSFUncert_mt_0jet_13TeVUp"
        postfix1[0]="_QCDSFUncert_mt_boosted_13TeVUp"
        postfix2[0]="_QCDSFUncert_mt_vbf_13TeVUp"
    if (options.scale=="qcddown"):
        postfix0[0]="_QCDSFUncert_mt_0jet_13TeVDown"
        postfix1[0]="_QCDSFUncert_mt_boosted_13TeVDown"
        postfix2[0]="_QCDSFUncert_mt_vbf_13TeVDown"
    if (options.scale=="wup"):
        postfix0[0]="_WSFUncert_mt_0jet_13TeVUp"
        postfix1[0]="_WSFUncert_mt_boosted_13TeVUp"
        postfix2[0]="_WSFUncert_mt_vbf_13TeVUp"
    if (options.scale=="wdown"):
        postfix0[0]="_WSFUncert_mt_0jet_13TeVDown"
        postfix1[0]="_WSFUncert_mt_boosted_13TeVDown"
        postfix2[0]="_WSFUncert_mt_vbf_13TeVDown"

    post2=postfix
    if (options.scale=="qcdup"):
        post2[0]=""
    if (options.scale=="qcddown"):
        post2[0]=""
    if (options.scale=="wup"):
        post2[0]=""
    if (options.scale=="wdown"):
        post2[0]=""
    if (options.scale=="nominal"):
        post2[0]=""

    if options.scale=="allTES":
      for j in range(0,nbhist):
	 post2[j]=postfixTES[j]
         postfix0[j]=postfixTES[j]
         postfix1[j]=postfixTES[j]
         postfix2[j]=postfixTES[j]

    fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
    fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
    fDYL=ROOT.TFile("files_nominal/ZL.root","r")
    fW=ROOT.TFile("files_nominal/Wunscaled.root","r")
    fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
    fTTT=ROOT.TFile("files_nominal/TTT.root","r")
    fVV=ROOT.TFile("files_nominal/VV.root","r")
    fData=ROOT.TFile("files_nominal/Data.root","r")
    #fout=ROOT.TFile("files_"+options.scale+"/W.root","recreate")

    mydir=options.scale
    if (options.scale=="allJES"):
         mydir="JESup"

    if (options.scale=="wdown"):
       fout=ROOT.TFile("files_nominal/W_wdown.root","recreate")
    elif (options.scale=="wup"):
       fout=ROOT.TFile("files_nominal/W_wup.root","recreate")
    elif (options.scale=="qcddown"):
       fout=ROOT.TFile("files_nominal/W_qcddown.root","recreate")
    elif (options.scale=="qcdup"):
       fout=ROOT.TFile("files_nominal/W_qcdup.root","recreate")
    elif (options.scale=="up" or options.scale=="down" or options.scale=="JESdown" or options.scale=="JESup" or options.scale=="nominal" or options.scale=="allJES" or options.scale=="allTES"):
       fDYS=ROOT.TFile("files_"+mydir+"/ZTT.root","r")
       fDYJ=ROOT.TFile("files_"+mydir+"/ZJ.root","r")
       fDYL=ROOT.TFile("files_"+mydir+"/ZL.root","r")
       fW=ROOT.TFile("files_"+mydir+"/Wunscaled.root","r")
       fTTT=ROOT.TFile("files_"+mydir+"/TTT.root","r")
       fTTJ=ROOT.TFile("files_"+mydir+"/TTJ.root","r")
       fVV=ROOT.TFile("files_"+mydir+"/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_"+mydir+"/W.root","recreate")

    fout.cd()
    dir0OS=fout.mkdir("mt_0jet")
    dir1OS=fout.mkdir("mt_boosted")
    dir2OS=fout.mkdir("mt_vbf")
    dir0QCDCROS=fout.mkdir("mt_antiiso_0jet_cr")
    dir1QCDCROS=fout.mkdir("mt_antiiso_boosted_cr")
    dir2QCDCROS=fout.mkdir("mt_antiiso_vbf_cr")
    dir0WCROS=fout.mkdir("mt_wjets_0jet_cr")
    dir1WCROS=fout.mkdir("mt_wjets_boosted_cr")
    dir2WCROS=fout.mkdir("mt_wjets_vbf_cr")
    dir0QCDCRSSOS=fout.mkdir("mt_antiiso_0jet_crSS")
    dir1QCDCRSSOS=fout.mkdir("mt_antiiso_boosted_crSS")
    dir2QCDCRSSOS=fout.mkdir("mt_antiiso_vbf_crSS")
    dir0WCRSSOS=fout.mkdir("mt_wjets_0jet_crSS")
    dir1WCRSSOS=fout.mkdir("mt_wjets_boosted_crSS")
    dir2WCRSSOS=fout.mkdir("mt_wjets_vbf_crSS")
    dir0SS=fout.mkdir("SS0jet")
    dir1SS=fout.mkdir("SS1jet")
    dir2SS=fout.mkdir("SSvbf")
    dir0QCD=fout.mkdir("QCD0jet")
    dir1QCD=fout.mkdir("QCD1jet")
    dir2QCD=fout.mkdir("QCDvbf")

    nbhist=1
    if options.scale=="allJES":
      nbhist=56
    if options.scale=="allTES":
      nbhist=12
    for k in range(0,nbhist):
        print fDYS.Get("n70"+post2[k]).GetBinContent(4)
        QCDpassSS0=(fData.Get("n70SS").GetBinContent(2)-fDYJ.Get("n70SS"+post2[k]).GetBinContent(2)-fDYL.Get("n70SS"+post2[k]).GetBinContent(2)-fDYS.Get("n70SS"+post2[k]).GetBinContent(2)-fTTJ.Get("n70SS"+post2[k]).GetBinContent(2)-fTTT.Get("n70SS"+post2[k]).GetBinContent(2)-fW.Get("n70SS"+post2[k]).GetBinContent(2)-fVV.Get("n70SS"+post2[k]).GetBinContent(2))
        SFpassOS0=((fData.Get("n70").GetBinContent(2)-fDYJ.Get("n70"+post2[k]).GetBinContent(2)-fDYL.Get("n70"+post2[k]).GetBinContent(2)-fDYS.Get("n70"+post2[k]).GetBinContent(2)-fTTJ.Get("n70"+post2[k]).GetBinContent(2)-fTTT.Get("n70"+post2[k]).GetBinContent(2)-fVV.Get("n70"+post2[k]).GetBinContent(2)-factor0jet*QCDpassSS0)/fW.Get("n70"+post2[k]).GetBinContent(2))
        QCDpassSS1=(fData.Get("n70SS").GetBinContent(3)-fDYJ.Get("n70SS"+post2[k]).GetBinContent(3)-fDYL.Get("n70SS"+post2[k]).GetBinContent(3)-fDYS.Get("n70SS"+post2[k]).GetBinContent(3)-fTTJ.Get("n70SS"+post2[k]).GetBinContent(3)-fTTT.Get("n70SS"+post2[k]).GetBinContent(3)-fW.Get("n70SS"+post2[k]).GetBinContent(3)-fVV.Get("n70SS"+post2[k]).GetBinContent(3))
        SFpassOS1=((fData.Get("n70").GetBinContent(3)-fDYJ.Get("n70"+post2[k]).GetBinContent(3)-fDYL.Get("n70"+post2[k]).GetBinContent(3)-fDYS.Get("n70"+post2[k]).GetBinContent(3)-fTTJ.Get("n70"+post2[k]).GetBinContent(3)-fTTT.Get("n70"+post2[k]).GetBinContent(3)-fVV.Get("n70"+post2[k]).GetBinContent(3)-factor1jet*QCDpassSS1)/fW.Get("n70"+post2[k]).GetBinContent(3))
        QCDpassSS2=(fData.Get("n70SS").GetBinContent(4)-fDYJ.Get("n70SS"+post2[k]).GetBinContent(4)-fDYL.Get("n70SS"+post2[k]).GetBinContent(4)-fDYS.Get("n70SS"+post2[k]).GetBinContent(4)-fTTJ.Get("n70SS"+post2[k]).GetBinContent(4)-fTTT.Get("n70SS"+post2[k]).GetBinContent(4)-fW.Get("n70SS"+post2[k]).GetBinContent(4)-fVV.Get("n70SS"+post2[k]).GetBinContent(4))
        SFpassOS2=((fData.Get("n70").GetBinContent(4)-fDYJ.Get("n70"+post2[k]).GetBinContent(4)-fDYL.Get("n70"+post2[k]).GetBinContent(4)-fDYS.Get("n70"+post2[k]).GetBinContent(4)-fTTJ.Get("n70"+post2[k]).GetBinContent(4)-fTTT.Get("n70"+post2[k]).GetBinContent(4)-fVV.Get("n70"+post2[k]).GetBinContent(4)-factor2jet*QCDpassSS2)/fW.Get("n70"+post2[k]).GetBinContent(4))

        #print "Data high mT, 0 jet: ",fData.Get("n70").GetBinContent(2)
        #print "TTT high mT, 0 jet: ",fTTT.Get("n70").GetBinContent(2)
        #print "TTJ high mT, 0 jet: ",fTTJ.Get("n70").GetBinContent(2)
        #print "VV high mT, 0 jet: ",fVV.Get("n70").GetBinContent(2)
        #print "ZTT high mT, 0 jet: ",fDYS.Get("n70").GetBinContent(2)
        #print "ZJ high mT, 0 jet: ",fDYJ.Get("n70").GetBinContent(2)
        #print "ZL high mT, 0 jet: ",fDYL.Get("n70").GetBinContent(2)
	#print "QCD 0 jet: ",factor0jet*QCDpassSS0
        #print "W unscaled high mT, 0 jet: ",fW.Get("n70").GetBinContent(2)
	#print "0 jet SF: ",SFpassOS0

	#print "Data high mT, boosted: ",fData.Get("n70").GetBinContent(3)
        #print "TTT high mT, boosted: ",fTTT.Get("n70").GetBinContent(3)
        #print "TTJ high mT, boosted: ",fTTJ.Get("n70").GetBinContent(3)
        #print "VV high mT, boosted: ",fVV.Get("n70").GetBinContent(3)
        #print "ZTT high mT, boosted: ",fDYS.Get("n70").GetBinContent(3)
        #print "ZJ high mT, boosted: ",fDYJ.Get("n70").GetBinContent(3)
        #print "ZL high mT, boosted: ",fDYL.Get("n70").GetBinContent(3)
        #print "QCD boosted: ",factor1jet*QCDpassSS1
        #print "W unscaled high mT, boosted: ",fW.Get("n70").GetBinContent(3)
        #print "boosted SF: ",SFpassOS1

        #print "Data high mT, VBF: ",fData.Get("n70").GetBinContent(4)
        #print "TTT high mT, VBF: ",fTTT.Get("n70").GetBinContent(4)
        #print "TTJ high mT, VBF: ",fTTJ.Get("n70").GetBinContent(4)
        #print "VV high mT, VBF: ",fVV.Get("n70").GetBinContent(4)
        #print "ZTT high mT, VBF: ",fDYS.Get("n70").GetBinContent(4)
        #print "ZJ high mT, VBF: ",fDYJ.Get("n70").GetBinContent(4)
        #print "ZL high mT, VBF: ",fDYL.Get("n70").GetBinContent(4)
        #print "QCD VBF: ",factor2jet*QCDpassSS2
        #print "W unscaled high mT, VBF: ",fW.Get("n70").GetBinContent(4)
        #print "VBF SF: ",SFpassOS2

	print post2[k],SFpassOS0,SFpassOS1,SFpassOS2
        SFpassOS2=SFpassOS1
        hW0jet=fW.Get("mt_0jet/W"+post2[k])
        hW0jet.Scale(SFpassOS0*factorw0jet)
        hW1jet=fW.Get("mt_boosted/W"+post2[k])
        hW1jet.Scale(SFpassOS1*factorw1jet)
        hW2jet=fW.Get("mt_vbf/W"+post2[k])
        hW2jet.Scale(SFpassOS2*factorw2jet)
        hW0jet_SS=fW.Get("SS0jet/W"+post2[k])
        hW0jet_SS.Scale(SFpassOS0*factorw0jet)
        hW1jet_SS=fW.Get("SS1jet/W"+post2[k])
        hW1jet_SS.Scale(SFpassOS1*factorw1jet)
        hW2jet_SS=fW.Get("SSvbf/W"+post2[k])
        hW2jet_SS.Scale(SFpassOS2*factorw2jet)
        hW0jet_QCD=fW.Get("QCD0jet/W"+post2[k])
        hW0jet_QCD.Scale(SFpassOS0*factorw0jet)
        hW1jet_QCD=fW.Get("QCD1jet/W"+post2[k])
        hW1jet_QCD.Scale(SFpassOS1*factorw1jet)
        hW2jet_QCD=fW.Get("QCDvbf/W"+post2[k])
        hW2jet_QCD.Scale(SFpassOS2*factorw2jet)

        hWCR0jet=fW.Get("mt_wjets_0jet_cr/W"+post2[k])
        hWCR0jet.Scale(SFpassOS0*factorw0jet)
        hWCR1jet=fW.Get("mt_wjets_boosted_cr/W"+post2[k])
        hWCR1jet.Scale(SFpassOS1*factorw1jet)
        hWCR2jet=fW.Get("mt_wjets_vbf_cr/W"+post2[k])
        hWCR2jet.Scale(SFpassOS2*factorw2jet)

        hQCDCR0jet=fW.Get("mt_antiiso_0jet_cr/W"+post2[k])
        hQCDCR0jet.Scale(SFpassOS0*factorw0jet)
        hQCDCR1jet=fW.Get("mt_antiiso_boosted_cr/W"+post2[k])
        hQCDCR1jet.Scale(SFpassOS1*factorw1jet)
        hQCDCR2jet=fW.Get("mt_antiiso_vbf_cr/W"+post2[k])
        hQCDCR2jet.Scale(SFpassOS2*factorw2jet)

        hWCRSS0jet=fW.Get("mt_wjets_0jet_crSS/W"+post2[k])
        hWCRSS0jet.Scale(SFpassOS0*factorw0jet)
        hWCRSS1jet=fW.Get("mt_wjets_boosted_crSS/W"+post2[k])
        hWCRSS1jet.Scale(SFpassOS1*factorw1jet)
        hWCRSS2jet=fW.Get("mt_wjets_vbf_crSS/W"+post2[k])
        hWCRSS2jet.Scale(SFpassOS2*factorw2jet)

        hQCDCRSS0jet=fW.Get("mt_antiiso_0jet_crSS/W"+post2[k])
        hQCDCRSS0jet.Scale(SFpassOS0*factorw0jet)
        hQCDCRSS1jet=fW.Get("mt_antiiso_boosted_crSS/W"+post2[k])
        hQCDCRSS1jet.Scale(SFpassOS1*factorw1jet)
        hQCDCRSS2jet=fW.Get("mt_antiiso_vbf_crSS/W"+post2[k])
        hQCDCRSS2jet.Scale(SFpassOS2*factorw2jet)

        fout.cd()
        dir0OS.cd()
        hW0jet.SetName("W"+postfix0[k])
        hW0jet.Write()
        dir1OS.cd()
        hW1jet.SetName("W"+postfix1[k])
        hW1jet.Write()
        dir2OS.cd()
        hW2jet.SetName("W"+postfix2[k])
        hW2jet.Write()

        dir0QCDCROS.cd()
        hQCDCR0jet.SetName("W"+postfix0[k])
        hQCDCR0jet.Write()
        dir1QCDCROS.cd()
        hQCDCR1jet.SetName("W"+postfix1[k])
        hQCDCR1jet.Write()
        dir2QCDCROS.cd()
        hQCDCR2jet.SetName("W"+postfix2[k])
        hQCDCR2jet.Write()

        dir0WCROS.cd()
        hWCR0jet.SetName("W"+postfix0[k])
        hWCR0jet.Write()
        dir1WCROS.cd()
        hWCR1jet.SetName("W"+postfix1[k])
        hWCR1jet.Write()
        dir2WCROS.cd()
        hWCR2jet.SetName("W"+postfix2[k])
        hWCR2jet.Write()

        dir0QCDCRSSOS.cd()
        hQCDCRSS0jet.SetName("W"+postfix0[k])
        hQCDCRSS0jet.Write()
        dir1QCDCRSSOS.cd()
        hQCDCRSS1jet.SetName("W"+postfix1[k])
        hQCDCRSS1jet.Write()
        dir2QCDCRSSOS.cd()
        hQCDCRSS2jet.SetName("W"+postfix2[k])
        hQCDCRSS2jet.Write()

        dir0WCRSSOS.cd()
        hWCRSS0jet.SetName("W"+postfix0[k])
        hWCRSS0jet.Write()
        dir1WCRSSOS.cd()
        hWCRSS1jet.SetName("W"+postfix1[k])
        hWCRSS1jet.Write()
        dir2WCRSSOS.cd()
        hWCRSS2jet.SetName("W"+postfix2[k])
        hWCRSS2jet.Write()

        dir0SS.cd()
        hW0jet_SS.SetName("W"+postfix0[k])
        hW0jet_SS.Write()
        dir1SS.cd()
        hW1jet_SS.SetName("W"+postfix1[k])
        hW1jet_SS.Write()
        dir2SS.cd()
        hW2jet_SS.SetName("W"+postfix2[k])
        hW2jet_SS.Write()

        dir0QCD.cd()
        hW0jet_QCD.SetName("W"+postfix0[k])
        hW0jet_QCD.Write()
        dir1QCD.cd()
        hW1jet_QCD.SetName("W"+postfix1[k])
        hW1jet_QCD.Write()
        dir2QCD.cd()
        hW2jet_QCD.SetName("W"+postfix2[k])
        hW2jet_QCD.Write()
        print postfix0[k],postfix1[k],postfix2[k]

