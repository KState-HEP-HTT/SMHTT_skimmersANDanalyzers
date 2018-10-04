if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'allJES','up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allTES'], help="Which TES?")
    options = parser.parse_args()

    factor0jet=1.07
    factor1jet=1.06
    factor2jet=1.00

    factor0jet_u=1.11
    factor1jet_u=1.12
    factor2jet_u=1.20

    factor0jet_d=1.03
    factor1jet_d=1.00
    factor2jet_d=0.80

    postfix=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_JetAbsoluteFlavMap_13TeVDown","_CMS_scale_j_JetAbsoluteFlavMap_13TeVUp","_CMS_scale_j_JetAbsoluteMPFBias_13TeVDown","_CMS_scale_j_JetAbsoluteMPFBias_13TeVUp","_CMS_scale_j_JetAbsoluteScale_13TeVDown","_CMS_scale_j_JetAbsoluteScale_13TeVUp","_CMS_scale_j_JetAbsoluteStat_13TeVDown","_CMS_scale_j_JetAbsoluteStat_13TeVUp","_CMS_scale_j_JetFlavorQCD_13TeVDown","_CMS_scale_j_JetFlavorQCD_13TeVUp","_CMS_scale_j_JetFragmentation_13TeVDown","_CMS_scale_j_JetFragmentation_13TeVUp","_CMS_scale_j_JetPileUpDataMC_13TeVDown","_CMS_scale_j_JetPileUpDataMC_13TeVUp","_CMS_scale_j_JetPileUpPtBB_13TeVDown","_CMS_scale_j_JetPileUpPtBB_13TeVUp","_CMS_scale_j_JetPileUpPtEC1_13TeVDown","_CMS_scale_j_JetPileUpPtEC1_13TeVUp","_CMS_scale_j_JetPileUpPtEC2_13TeVDown","_CMS_scale_j_JetPileUpPtEC2_13TeVUp","_CMS_scale_j_JetPileUpPtHF_13TeVDown","_CMS_scale_j_JetPileUpPtHF_13TeVUp","_CMS_scale_j_JetPileUpPtRef_13TeVDown","_CMS_scale_j_JetPileUpPtRef_13TeVUp","_CMS_scale_j_JetRelativeBal_13TeVDown","_CMS_scale_j_JetRelativeBal_13TeVUp","_CMS_scale_j_JetRelativeFSR_13TeVDown","_CMS_scale_j_JetRelativeFSR_13TeVUp","_CMS_scale_j_JetRelativeJEREC1_13TeVDown","_CMS_scale_j_JetRelativeJEREC1_13TeVUp","_CMS_scale_j_JetRelativeJEREC2_13TeVDown","_CMS_scale_j_JetRelativeJEREC2_13TeVUp","_CMS_scale_j_JetRelativeJERHF_13TeVDown","_CMS_scale_j_JetRelativeJERHF_13TeVUp","_CMS_scale_j_JetRelativePtBB_13TeVDown","_CMS_scale_j_JetRelativePtBB_13TeVUp","_CMS_scale_j_JetRelativePtEC1_13TeVDown","_CMS_scale_j_JetRelativePtEC1_13TeVUp","_CMS_scale_j_JetRelativePtEC2_13TeVDown","_CMS_scale_j_JetRelativePtEC2_13TeVUp","_CMS_scale_j_JetRelativePtHF_13TeVDown","_CMS_scale_j_JetRelativePtHF_13TeVUp","_CMS_scale_j_JetRelativeStatEC_13TeVDown","_CMS_scale_j_JetRelativeStatEC_13TeVUp","_CMS_scale_j_JetRelativeStatFSR_13TeVDown","_CMS_scale_j_JetRelativeStatFSR_13TeVUp","_CMS_scale_j_JetRelativeStatHF_13TeVDown","_CMS_scale_j_JetRelativeStatHF_13TeVUp","_CMS_scale_j_JetSinglePionECAL_13TeVDown","_CMS_scale_j_JetSinglePionECAL_13TeVUp","_CMS_scale_j_JetSinglePionHCAL_13TeVDown","_CMS_scale_j_JetSinglePionHCAL_13TeVUp","_CMS_scale_j_JetTimePtEta_13TeVDown","_CMS_scale_j_JetTimePtEta_13TeVUp"]
    post2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix0=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix1=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfix2=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]
    postfixTES=["_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"]

    if options.scale!="allJES":
        postfix[0]=""

    if (options.scale!='allJES'):
       postfix0[0]=""
       postfix1[0]=""
       postfix2[0]=""
    if (options.scale=="up"):
        postfix0[0]="_CMS_scale_t_mt_13TeVUp"
        postfix1[0]="_CMS_scale_t_mt_13TeVUp"
        postfix2[0]="_CMS_scale_t_mt_13TeVUp"
    if (options.scale=="down"):
        postfix0[0]="_CMS_scale_t_mt_13TeVDown"
        postfix1[0]="_CMS_scale_t_mt_13TeVDown"
        postfix2[0]="_CMS_scale_t_mt_13TeVDown"
    if (options.scale=="JESup"):
        postfix0[0]="_CMS_scale_j_13TeVUp"
        postfix1[0]="_CMS_scale_j_13TeVUp"
        postfix2[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
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

    if (options.scale=="JESup"):
        post2[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
        post2[0]="_CMS_scale_j_13TeVDown"
    if (options.scale=="up"):
        post2[0]="_CMS_scale_t_mt_13TeVUp"
    if (options.scale=="down"):
        post2[0]="_CMS_scale_t_mt_13TeVDown"
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
        postfix0[0]=""
        postfix1[0]=""
        postfix2[0]=""

    facteur=1.0
    if (options.scale=="qcdup"):
        factor0jet=factor0jet_u
        factor1jet=factor1jet_u
        factor2jet=factor2jet_u
    if (options.scale=="qcddown"):
        factor0jet=factor0jet_d
        factor1jet=factor1jet_d
        factor2jet=factor2jet_d

    if options.scale=="allTES":
      for j in range(0,12):
         post2[j]=postfixTES[j]
         postfix0[j]=postfixTES[j]
         postfix1[j]=postfixTES[j]
         postfix2[j]=postfixTES[j]

    mydir=options.scale
    if options.scale=="allJES":
       mydir="JESup"
    if options.scale=="nominal":
       mydir="nominal"

    if options.scale=="up" or options.scale=="down" or options.scale=="JESup" or options.scale=="JESdown" or options.scale=="allJES" or options.scale=="allTES":
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYS=ROOT.TFile("files_"+mydir+"/ZTT.root","r")
       fW=ROOT.TFile("files_"+mydir+"/W.root","r")
       fTTJ=ROOT.TFile("files_"+mydir+"/TTJ.root","r")
       fTTT=ROOT.TFile("files_"+mydir+"/TTT.root","r")
       fVV=ROOT.TFile("files_"+mydir+"/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_"+mydir+"/QCD.root","recreate")
    elif options.scale=="wup":
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W_wup.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD_wup.root","recreate")
    elif options.scale=="wdown":
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W_wdown.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD_wdown.root","recreate")
    elif options.scale=="qcdup":
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W_qcdup.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD_qcdup.root","recreate")
    elif options.scale=="qcddown":
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W_qcddown.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD_qcddown.root","recreate")
    else:
       fDYJ=ROOT.TFile("files_nominal/ZJ.root","r")
       fDYL=ROOT.TFile("files_nominal/ZL.root","r")
       fDYS=ROOT.TFile("files_nominal/ZTT.root","r")
       fW=ROOT.TFile("files_nominal/W.root","r")
       fTTJ=ROOT.TFile("files_nominal/TTJ.root","r")
       fTTT=ROOT.TFile("files_nominal/TTT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
       fout=ROOT.TFile("files_nominal/QCD.root","recreate")

    fout.cd()
    dir0jet=fout.mkdir("mt_0jet")
    dir1jet=fout.mkdir("mt_boosted")
    dir2jet=fout.mkdir("mt_vbf")
    dirWCR0jet=fout.mkdir("mt_wjets_0jet_cr")
    dirWCR1jet=fout.mkdir("mt_wjets_boosted_cr")
    dirWCR2jet=fout.mkdir("mt_wjets_vbf_cr")
    dirQCDCR0jet=fout.mkdir("mt_antiiso_0jet_cr")
    dirQCDCR1jet=fout.mkdir("mt_antiiso_boosted_cr")
    dirQCDCR2jet=fout.mkdir("mt_antiiso_vbf_cr")

    nbhist=1
    if options.scale=="allJES":
       nbhist=56
    if options.scale=="allTES":
       nbhist=12

    for k in range(0,nbhist):
        hSS_0jet=fData.Get("SS0jet/data_obs")
        hSS_0jet.Add(fDYJ.Get("SS0jet/ZJ"),-1)
        hSS_0jet.Add(fDYL.Get("SS0jet/ZL"),-1)
	print "SS0jet/TTJ"+post2[k]
        hSS_0jet.Add(fTTJ.Get("SS0jet/TTJ"+post2[k]),-1)
        hSS_0jet.Add(fTTT.Get("SS0jet/TTT"+post2[k]),-1)
	print "SS0jet/W"+postfix0[k]
        hSS_0jet.Add(fW.Get("SS0jet/W"+postfix0[k]),-1)
        hSS_0jet.Add(fVV.Get("SS0jet/VV"+post2[k]),-1)
        hSS_0jet.Add(fDYS.Get("SS0jet/ZTT"+post2[k]),-1)
        hSS_0jet.SetName("QCD"+postfix0[k])
        hSS_0jet.Scale(factor0jet)
        for i in range(0,hSS_0jet.GetSize()-2):
            if hSS_0jet.GetBinContent(i)<0:
                hSS_0jet.SetBinError(i,max(0,hSS_0jet.GetBinError(i)+hSS_0jet.GetBinError(i)))
                hSS_0jet.SetBinContent(i,0)

        hQCD_0jet=fData.Get("QCD0jet/data_obs")
        hQCD_0jet.Add(fDYJ.Get("QCD0jet/ZJ"),-1)
        hQCD_0jet.Add(fDYL.Get("QCD0jet/ZL"),-1)
        hQCD_0jet.Add(fTTJ.Get("QCD0jet/TTJ"+post2[k]),-1)
        hQCD_0jet.Add(fTTT.Get("QCD0jet/TTT"+post2[k]),-1)
        hQCD_0jet.Add(fW.Get("QCD0jet/W"+postfix0[k]),-1)
        hQCD_0jet.Add(fVV.Get("QCD0jet/VV"+post2[k]),-1)
        hQCD_0jet.Add(fDYS.Get("QCD0jet/ZTT"+post2[k]),-1)
        hQCD_0jet.SetName("QCD"+postfix0[k])
        hQCD_0jet.Scale(factor0jet)
        for i in range(0,hQCD_0jet.GetSize()-2):
            if hQCD_0jet.GetBinContent(i)<0:
                hQCD_0jet.SetBinError(i,max(0,hQCD_0jet.GetBinError(i)+hQCD_0jet.GetBinError(i)))
                hQCD_0jet.SetBinContent(i,0)

        hSS_1jet=fData.Get("SS1jet/data_obs")
        hSS_1jet.Add(fDYJ.Get("SS1jet/ZJ"),-1)
        hSS_1jet.Add(fDYL.Get("SS1jet/ZL"),-1)
        hSS_1jet.Add(fTTJ.Get("SS1jet/TTJ"+post2[k]),-1)
        hSS_1jet.Add(fTTT.Get("SS1jet/TTT"+post2[k]),-1)
        hSS_1jet.Add(fW.Get("SS1jet/W"+postfix1[k]),-1)
        hSS_1jet.Add(fVV.Get("SS1jet/VV"+post2[k]),-1)
        hSS_1jet.Add(fDYS.Get("SS1jet/ZTT"+post2[k]),-1)
        hSS_1jet.SetName("QCD"+postfix1[k])
        hSS_1jet.Scale(factor1jet)
        for i in range(0,hSS_1jet.GetSize()-2):
            if hSS_1jet.GetBinContent(i)<0:
                hSS_1jet.SetBinError(i,max(0,hSS_1jet.GetBinError(i)+hSS_1jet.GetBinError(i)))
                hSS_1jet.SetBinContent(i,0)

        hQCD_1jet=fData.Get("QCD1jet/data_obs")
        hQCD_1jet.Add(fDYJ.Get("QCD1jet/ZJ"),-1)
        hQCD_1jet.Add(fDYL.Get("QCD1jet/ZL"),-1)
        hQCD_1jet.Add(fTTJ.Get("QCD1jet/TTJ"+post2[k]),-1)
        hQCD_1jet.Add(fTTT.Get("QCD1jet/TTT"+post2[k]),-1)
        hQCD_1jet.Add(fW.Get("QCD1jet/W"+postfix1[k]),-1)
        hQCD_1jet.Add(fVV.Get("QCD1jet/VV"+post2[k]),-1)
        hQCD_1jet.Add(fDYS.Get("QCD1jet/ZTT"+post2[k]),-1)
        hQCD_1jet.SetName("QCD"+postfix1[k])
        hQCD_1jet.Scale(factor1jet)
        for i in range(0,hQCD_1jet.GetSize()-2):
            if hQCD_1jet.GetBinContent(i)<0:
                hQCD_1jet.SetBinError(i,max(0,hQCD_1jet.GetBinError(i)+hQCD_1jet.GetBinError(i)))
                hQCD_1jet.SetBinContent(i,0)

        hSS_2jet=fData.Get("SSvbf/data_obs")
        hSS_2jet.Add(fDYJ.Get("SSvbf/ZJ"),-1)
        hSS_2jet.Add(fDYL.Get("SSvbf/ZL"),-1)
        hSS_2jet.Add(fTTJ.Get("SSvbf/TTJ"+post2[k]),-1)
        hSS_2jet.Add(fTTT.Get("SSvbf/TTT"+post2[k]),-1)
        hSS_2jet.Add(fW.Get("SSvbf/W"+postfix2[k]),-1)
        hSS_2jet.Add(fVV.Get("SSvbf/VV"+post2[k]),-1)
        hSS_2jet.Add(fDYS.Get("SSvbf/ZTT"+post2[k]),-1)
        hSS_2jet.SetName("QCD"+postfix2[k])
        hSS_2jet.Scale(factor2jet)
        for i in range(0,hSS_2jet.GetSize()-2):
            if hSS_2jet.GetBinContent(i)<0:
                hSS_2jet.SetBinError(i,max(0,hSS_2jet.GetBinError(i)+hSS_2jet.GetBinError(i)))
                hSS_2jet.SetBinContent(i,0)

        hQCD_2jet=fData.Get("QCDvbf/data_obs")
        hQCD_2jet.Add(fDYJ.Get("QCDvbf/ZJ"),-1)
        hQCD_2jet.Add(fDYL.Get("QCDvbf/ZL"),-1)
        hQCD_2jet.Add(fTTJ.Get("QCDvbf/TTJ"+post2[k]),-1)
        hQCD_2jet.Add(fTTT.Get("QCDvbf/TTT"+post2[k]),-1)
        hQCD_2jet.Add(fW.Get("QCDvbf/W"+postfix2[k]),-1)
        hQCD_2jet.Add(fVV.Get("QCDvbf/VV"+post2[k]),-1)
        hQCD_2jet.Add(fDYS.Get("QCDvbf/ZTT"+post2[k]),-1)
        hQCD_2jet.SetName("QCD"+postfix2[k])
        hQCD_2jet.Scale(factor2jet)
        for i in range(0,hQCD_2jet.GetSize()-2):
            if hQCD_2jet.GetBinContent(i)<0:
                hQCD_2jet.SetBinError(i,max(0,hQCD_2jet.GetBinError(i)+hQCD_2jet.GetBinError(i)))
                hQCD_2jet.SetBinContent(i,0)

        hantiCR_0jet=fData.Get("mt_antiiso_0jet_crSS/data_obs")
        hantiCR_0jet.Add(fDYJ.Get("mt_antiiso_0jet_crSS/ZJ"),-1)
        hantiCR_0jet.Add(fDYL.Get("mt_antiiso_0jet_crSS/ZL"),-1)
        hantiCR_0jet.Add(fTTJ.Get("mt_antiiso_0jet_crSS/TTJ"+post2[k]),-1)
        hantiCR_0jet.Add(fTTT.Get("mt_antiiso_0jet_crSS/TTT"+post2[k]),-1)
	print "mt_antiiso_0jet_crSS/W"+postfix0[k]
        hantiCR_0jet.Add(fW.Get("mt_antiiso_0jet_crSS/W"+postfix0[k]),-1)
        hantiCR_0jet.Add(fVV.Get("mt_antiiso_0jet_crSS/VV"+post2[k]),-1)
        hantiCR_0jet.Add(fDYS.Get("mt_antiiso_0jet_crSS/ZTT"+post2[k]),-1)
        hantiCR_0jet.SetName("QCD"+postfix2[k])
        hantiCR_0jet.Scale(factor0jet)
        for i in range(0,hantiCR_0jet.GetSize()-2):
            if hantiCR_0jet.GetBinContent(i)<0:
                hantiCR_0jet.SetBinError(i,max(0,hantiCR_0jet.GetBinError(i)+hantiCR_0jet.GetBinError(i)))
                hantiCR_0jet.SetBinContent(i,0)

        hantiCR_1jet=fData.Get("mt_antiiso_boosted_crSS/data_obs")
        hantiCR_1jet.Add(fDYJ.Get("mt_antiiso_boosted_crSS/ZJ"),-1)
        hantiCR_1jet.Add(fDYL.Get("mt_antiiso_boosted_crSS/ZL"),-1)
        hantiCR_1jet.Add(fTTJ.Get("mt_antiiso_boosted_crSS/TTJ"+post2[k]),-1)
        hantiCR_1jet.Add(fTTT.Get("mt_antiiso_boosted_crSS/TTT"+post2[k]),-1)
        hantiCR_1jet.Add(fW.Get("mt_antiiso_boosted_crSS/W"+postfix1[k]),-1)
        hantiCR_1jet.Add(fVV.Get("mt_antiiso_boosted_crSS/VV"+post2[k]),-1)
        hantiCR_1jet.Add(fDYS.Get("mt_antiiso_boosted_crSS/ZTT"+post2[k]),-1)
        hantiCR_1jet.SetName("QCD"+postfix2[k])
        hantiCR_1jet.Scale(factor1jet)
        for i in range(0,hantiCR_1jet.GetSize()-2):
            if hantiCR_1jet.GetBinContent(i)<0:
                hantiCR_1jet.SetBinError(i,max(0,hantiCR_1jet.GetBinError(i)+hantiCR_1jet.GetBinError(i)))
                hantiCR_1jet.SetBinContent(i,0)

        hantiCR_2jet=fData.Get("mt_antiiso_vbf_crSS/data_obs")
        hantiCR_2jet.Add(fDYJ.Get("mt_antiiso_vbf_crSS/ZJ"),-1)
        hantiCR_2jet.Add(fDYL.Get("mt_antiiso_vbf_crSS/ZL"),-1)
        hantiCR_2jet.Add(fTTJ.Get("mt_antiiso_vbf_crSS/TTJ"+post2[k]),-1)
        hantiCR_2jet.Add(fTTT.Get("mt_antiiso_vbf_crSS/TTT"+post2[k]),-1)
        hantiCR_2jet.Add(fW.Get("mt_antiiso_vbf_crSS/W"+postfix2[k]),-1)
        hantiCR_2jet.Add(fVV.Get("mt_antiiso_vbf_crSS/VV"+post2[k]),-1)
        hantiCR_2jet.Add(fDYS.Get("mt_antiiso_vbf_crSS/ZTT"+post2[k]),-1)
        hantiCR_2jet.SetName("QCD"+postfix2[k])
        hantiCR_2jet.Scale(factor2jet)
        for i in range(0,hantiCR_2jet.GetSize()-2):
            if hantiCR_2jet.GetBinContent(i)<0:
                hantiCR_2jet.SetBinError(i,max(0,hantiCR_2jet.GetBinError(i)+hantiCR_2jet.GetBinError(i)))
                hantiCR_2jet.SetBinContent(i,0)

        hwjetsCR_0jet=fData.Get("mt_wjets_0jet_crSS/data_obs")
        hwjetsCR_0jet.Add(fDYJ.Get("mt_wjets_0jet_crSS/ZJ"),-1)
        hwjetsCR_0jet.Add(fDYL.Get("mt_wjets_0jet_crSS/ZL"),-1)
        hwjetsCR_0jet.Add(fTTJ.Get("mt_wjets_0jet_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_0jet.Add(fTTT.Get("mt_wjets_0jet_crSS/TTT"+post2[k]),-1)
        hwjetsCR_0jet.Add(fW.Get("mt_wjets_0jet_crSS/W"+postfix0[k]),-1)
        hwjetsCR_0jet.Add(fVV.Get("mt_wjets_0jet_crSS/VV"+post2[k]),-1)
        hwjetsCR_0jet.Add(fDYS.Get("mt_wjets_0jet_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_0jet.SetName("QCD"+postfix2[k])
        hwjetsCR_0jet.Scale(factor0jet)
        for i in range(0,hwjetsCR_0jet.GetSize()-2):
            if hwjetsCR_0jet.GetBinContent(i)<0:
                hwjetsCR_0jet.SetBinError(i,max(0,hwjetsCR_0jet.GetBinError(i)+hwjetsCR_0jet.GetBinError(i)))
                hwjetsCR_0jet.SetBinContent(i,0)

        hwjetsCR_1jet=fData.Get("mt_wjets_boosted_crSS/data_obs")
        hwjetsCR_1jet.Add(fDYJ.Get("mt_wjets_boosted_crSS/ZJ"),-1)
        hwjetsCR_1jet.Add(fDYL.Get("mt_wjets_boosted_crSS/ZL"),-1)
        hwjetsCR_1jet.Add(fTTJ.Get("mt_wjets_boosted_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_1jet.Add(fTTT.Get("mt_wjets_boosted_crSS/TTT"+post2[k]),-1)
        hwjetsCR_1jet.Add(fW.Get("mt_wjets_boosted_crSS/W"+postfix1[k]),-1)
        hwjetsCR_1jet.Add(fVV.Get("mt_wjets_boosted_crSS/VV"+post2[k]),-1)
        hwjetsCR_1jet.Add(fDYS.Get("mt_wjets_boosted_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_1jet.SetName("QCD"+postfix2[k])
        hwjetsCR_1jet.Scale(factor1jet)
        for i in range(0,hwjetsCR_1jet.GetSize()-2):
            if hwjetsCR_1jet.GetBinContent(i)<0:
                hwjetsCR_1jet.SetBinError(i,max(0,hwjetsCR_1jet.GetBinError(i)+hwjetsCR_1jet.GetBinError(i)))
                hwjetsCR_1jet.SetBinContent(i,0)

        hwjetsCR_2jet=fData.Get("mt_wjets_vbf_crSS/data_obs")
        hwjetsCR_2jet.Add(fDYJ.Get("mt_wjets_vbf_crSS/ZJ"),-1)
        hwjetsCR_2jet.Add(fDYL.Get("mt_wjets_vbf_crSS/ZL"),-1)
        hwjetsCR_2jet.Add(fTTJ.Get("mt_wjets_vbf_crSS/TTJ"+post2[k]),-1)
        hwjetsCR_2jet.Add(fTTT.Get("mt_wjets_vbf_crSS/TTT"+post2[k]),-1)
        hwjetsCR_2jet.Add(fW.Get("mt_wjets_vbf_crSS/W"+postfix2[k]),-1)
        hwjetsCR_2jet.Add(fVV.Get("mt_wjets_vbf_crSS/VV"+post2[k]),-1)
        hwjetsCR_2jet.Add(fDYS.Get("mt_wjets_vbf_crSS/ZTT"+post2[k]),-1)
        hwjetsCR_2jet.SetName("QCD"+postfix2[k])
        hwjetsCR_2jet.Scale(factor2jet)
        for i in range(0,hwjetsCR_2jet.GetSize()-2):
            if hwjetsCR_2jet.GetBinContent(i)<0:
                hwjetsCR_2jet.SetBinError(i,max(0,hwjetsCR_2jet.GetBinError(i)+hwjetsCR_2jet.GetBinError(i)))
                hwjetsCR_2jet.SetBinContent(i,0)

        fout.cd()
        dir0jet.cd()
        hQCD_0jet.Scale(hSS_0jet.Integral()/hQCD_0jet.Integral())
        hQCD_0jet.Write()

        dir1jet.cd()
        hQCD_1jet.Scale(hSS_1jet.Integral()/hQCD_1jet.Integral())
        hQCD_1jet.Write()

        dir2jet.cd()
        hQCD_2jet.Scale(hSS_2jet.Integral()/hQCD_2jet.Integral())
        hQCD_2jet.Write()

        dirWCR0jet.cd()
        hwjetsCR_0jet.Write()

        dirWCR1jet.cd()
        hwjetsCR_1jet.Write()

        dirWCR2jet.cd()
        hwjetsCR_2jet.Write()

        dirQCDCR0jet.cd()
        hantiCR_0jet.Write()

        dirQCDCR1jet.cd()
        hantiCR_1jet.Write()

        dirQCDCR2jet.cd()
        hantiCR_2jet.Write()

