#ifndef THTH_TREE_H
#define	THTH_TREE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include "TTree.h"
#include "TFile.h"
#include "TSystem.h"
#include "HTauTauTree_tt.h"
#include "RecoilCorrector.h"
//#include "myHelper.h"

using namespace std;


float trackpt_1,trackpt_2, jetPt_1, jetPt_2;
unsigned int run, lumi, evt, NUP = -10;
int gen_match_1, gen_match_2=0;
float met_norecoil;
float npu, rho, npv=-1;//, puweight, weight;
float againstElectronLooseMVA6_1, againstElectronMediumMVA6_1, againstElectronTightMVA6_1, againstElectronVLooseMVA6_1, againstElectronVTightMVA6_1, againstMuonLoose3_1, againstMuonTight3_1, decayModeFinding_1;
float againstElectronLooseMVA6_2, againstElectronMediumMVA6_2, againstElectronTightMVA6_2, againstElectronVLooseMVA6_2, againstElectronVTightMVA6_2, againstMuonLoose3_2, againstMuonTight3_2, decayModeFinding_2;
float e_1, px_1, py_1, pz_1, pt_1, phi_1, eta_1, m_1, q_1, d0_1, dZ_1, mt_1, iso_1, t1_decayMode;
float e_2, px_2, py_2, pz_2, pt_2, phi_2, eta_2, m_2, q_2, d0_2, dZ_2, mt_2, iso_2, t2_decayMode;
//
float byCombinedIsolationDeltaBetaCorrRaw3Hits_1, byIsolationMVA3oldDMwoLTraw_1;//byIsolationMVA3oldDMwoLTraw_1;
float byCombinedIsolationDeltaBetaCorrRaw3Hits_2, byIsolationMVA3oldDMwoLTraw_2;
float byVLooseIsolationMVArun2v1DBnewDMwLT_1,  byVLooseIsolationMVArun2v1DBoldDMwLT_1,  byVLooseIsolationMVArun2v1DBdR03oldDMwLT_1;
float byLooseIsolationMVArun2v1DBnewDMwLT_1,  byLooseIsolationMVArun2v1DBoldDMwLT_1,  byLooseIsolationMVArun2v1DBdR03oldDMwLT_1;
float byMediumIsolationMVArun2v1DBnewDMwLT_1,  byMediumIsolationMVArun2v1DBoldDMwLT_1,  byMediumIsolationMVArun2v1DBdR03oldDMwLT_1;
float byTightIsolationMVArun2v1DBnewDMwLT_1,  byTightIsolationMVArun2v1DBoldDMwLT_1,  byTightIsolationMVArun2v1DBdR03oldDMwLT_1;
float byVTightIsolationMVArun2v1DBnewDMwLT_1,  byVTightIsolationMVArun2v1DBoldDMwLT_1,  byVTightIsolationMVArun2v1DBdR03oldDMwLT_1;
float byVVTightIsolationMVArun2v1DBnewDMwLT_1,  byVVTightIsolationMVArun2v1DBoldDMwLT_1,  byVVTightIsolationMVArun2v1DBdR03oldDMwLT_1;
float byVLooseIsolationMVArun2v1DBnewDMwLT_2,  byVLooseIsolationMVArun2v1DBoldDMwLT_2,  byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2;
float byLooseIsolationMVArun2v1DBnewDMwLT_2,  byLooseIsolationMVArun2v1DBoldDMwLT_2,  byLooseIsolationMVArun2v1DBdR03oldDMwLT_2;
float byMediumIsolationMVArun2v1DBnewDMwLT_2,  byMediumIsolationMVArun2v1DBoldDMwLT_2,  byMediumIsolationMVArun2v1DBdR03oldDMwLT_2;
float byTightIsolationMVArun2v1DBnewDMwLT_2,  byTightIsolationMVArun2v1DBoldDMwLT_2,  byTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float byVTightIsolationMVArun2v1DBnewDMwLT_2,  byVTightIsolationMVArun2v1DBoldDMwLT_2,  byVTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float byVVTightIsolationMVArun2v1DBnewDMwLT_2,  byVVTightIsolationMVArun2v1DBoldDMwLT_2,  byVVTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float mjj, jdeta, jdphi, dijetpt, dijetphi, hdijetphi, visjeteta, ptvis;
float mjj_JESDown, jdeta_JESDown,mjj_JESUp,jdeta_JESUp;
int njetingap, njetingap20, nbtag, njets, njetspt20, nbtagL;
int njetingap_JESDown, njetingap20_JESDown, njets_JESDown, njetspt20_JESDown;
int njetingap_JESUp, njetingap20_JESUp, njets_JESUp, njetspt20_JESUp;
float jmass_1, jpt_1, jpx_1, jpy_1, jpz_1, jeta_1, jphi_1, jrawf_1, jmva_1, jpfid_1, jpuid_1, jcsv_1, jpt_1_JESUp, jpt_1_JESDown;
float jmass_2, jpx_2, jpy_2, jpz_2, jpt_2, jeta_2, jphi_2, jrawf_2, jmva_2, jpfid_2, jpuid_2, jcsv_2, jpt_2_JESUp, jpt_2_JESDown;
float bpt_1, beta_1, bphi_1, bpfid_1, bpuid_1, bcsv_1, bflavor_1;
float bpt_2, beta_2, bphi_2, bpfid_2, bpuid_2, bcsv_2, bflavor_2;
float met, metphi, mvaMet, mvaMetphi, pzetavis, pzetamiss, mvacov00, mvacov01, mvacov11, mvacov10;
float top_reweighting, gen_Higgs_pt, gen_Higgs_mass=1.0;
float extraelec_veto, extramuon_veto, dilepton_veto=false;
float byLooseCombinedIsolationDeltaBetaCorr3Hits_3, byMediumCombinedIsolationDeltaBetaCorr3Hits_3, byTightCombinedIsolationDeltaBetaCorr3Hits_3;
float byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_3, byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_3, byTightCombinedIsolationDeltaBetaCorr3HitsdR03_3;
float extratau_veto, pt_top1, pt_top2, genweight, dphi_12, dphi_mumet, dphi_taumet;
float aMCatNLO_weight, numGenJets;
float met_px, met_py;
float metSig, metcov00, metcov01, metcov10,metcov11, metcov00_v2, metcov01_v2, metcov10_v2,metcov11_v2;
float genDR_2;
float byVLooseIsolationRerunMVArun2v1DBoldDMwLT_1, byVTightIsolationRerunMVArun2v1DBoldDMwLT_1, byLooseIsolationRerunMVArun2v1DBoldDMwLT_1, byMediumIsolationRerunMVArun2v1DBoldDMwLT_1, byTightIsolationRerunMVArun2v1DBoldDMwLT_1, byVVTightIsolationRerunMVArun2v1DBoldDMwLT_1,byIsolationRerunMVA3oldDMwLTraw_1;
float byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2, byVTightIsolationRerunMVArun2v1DBoldDMwLT_2, byLooseIsolationRerunMVArun2v1DBoldDMwLT_2, byMediumIsolationRerunMVArun2v1DBoldDMwLT_2, byTightIsolationRerunMVArun2v1DBoldDMwLT_2, byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2,byIsolationRerunMVA3oldDMwLTraw_2;
float matchIsoMu22eta2p1_2,matchIsoTkMu22eta2p1_2,matchIsoMu22_2,matchIsoTkMu22_2,matchIsoMu24_2,matchIsoTkMu24_2,filterIsoMu22eta2p1_2,filterIsoTkMu22eta2p1_2,filterIsoMu22_2,filterIsoTkMu22_2,filterIsoMu24_2,filterIsoTkMu24_2,filterIsoMu19Tau20_3,filterIsoMu21Tau20_3;
int njets_JetAbsoluteFlavMapDown,njets_JetAbsoluteMPFBiasDown,njets_JetAbsoluteScaleDown,njets_JetAbsoluteStatDown,njets_JetEnDown,njets_JetFlavorQCDDown,njets_JetFragmentationDown,njets_JetPileUpDataMCDown,njets_JetPileUpPtBBDown,njets_JetPileUpPtEC1Down,njets_JetPileUpPtEC2Down,njets_JetPileUpPtHFDown,njets_JetPileUpPtRefDown,njets_JetRelativeBalDown,njets_JetRelativeFSRDown,njets_JetRelativeJEREC1Down,njets_JetRelativeJEREC2Down,njets_JetRelativeJERHFDown,njets_JetRelativePtBBDown,njets_JetRelativePtEC1Down,njets_JetRelativePtEC2Down,njets_JetRelativePtHFDown,njets_JetRelativeStatECDown,njets_JetRelativeStatFSRDown,njets_JetRelativeStatHFDown,njets_JetSinglePionECALDown,njets_JetSinglePionHCALDown,njets_JetTimePtEtaDown;
int njets_JetAbsoluteFlavMapUp,njets_JetAbsoluteMPFBiasUp,njets_JetAbsoluteScaleUp,njets_JetAbsoluteStatUp,njets_JetEnUp,njets_JetFlavorQCDUp,njets_JetFragmentationUp,njets_JetPileUpDataMCUp,njets_JetPileUpPtBBUp,njets_JetPileUpPtEC1Up,njets_JetPileUpPtEC2Up,njets_JetPileUpPtHFUp,njets_JetPileUpPtRefUp,njets_JetRelativeBalUp,njets_JetRelativeFSRUp,njets_JetRelativeJEREC1Up,njets_JetRelativeJEREC2Up,njets_JetRelativeJERHFUp,njets_JetRelativePtBBUp,njets_JetRelativePtEC1Up,njets_JetRelativePtEC2Up,njets_JetRelativePtHFUp,njets_JetRelativeStatECUp,njets_JetRelativeStatFSRUp,njets_JetRelativeStatHFUp,njets_JetSinglePionECALUp,njets_JetSinglePionHCALUp,njets_JetTimePtEtaUp;
float mjj_JetAbsoluteFlavMapDown,mjj_JetAbsoluteMPFBiasDown,mjj_JetAbsoluteScaleDown,mjj_JetAbsoluteStatDown,mjj_JetEnDown,mjj_JetFlavorQCDDown,mjj_JetFragmentationDown,mjj_JetPileUpDataMCDown,mjj_JetPileUpPtBBDown,mjj_JetPileUpPtEC1Down,mjj_JetPileUpPtEC2Down,mjj_JetPileUpPtHFDown,mjj_JetPileUpPtRefDown,mjj_JetRelativeBalDown,mjj_JetRelativeFSRDown,mjj_JetRelativeJEREC1Down,mjj_JetRelativeJEREC2Down,mjj_JetRelativeJERHFDown,mjj_JetRelativePtBBDown,mjj_JetRelativePtEC1Down,mjj_JetRelativePtEC2Down,mjj_JetRelativePtHFDown,mjj_JetRelativeStatECDown,mjj_JetRelativeStatFSRDown,mjj_JetRelativeStatHFDown,mjjJetSinglePionECALDown,mjj_JetSinglePionHCALDown,mjj_JetTimePtEtaDown, mjj_JetSinglePionECALDown;
float mjj_JetAbsoluteFlavMapUp,mjj_JetAbsoluteMPFBiasUp,mjj_JetAbsoluteScaleUp,mjj_JetAbsoluteStatUp,mjj_JetEnUp,mjj_JetFlavorQCDUp,mjj_JetFragmentationUp,mjj_JetPileUpDataMCUp,mjj_JetPileUpPtBBUp,mjj_JetPileUpPtEC1Up,mjj_JetPileUpPtEC2Up,mjj_JetPileUpPtHFUp,mjj_JetPileUpPtRefUp,mjj_JetRelativeBalUp,mjj_JetRelativeFSRUp,mjj_JetRelativeJEREC1Up,mjj_JetRelativeJEREC2Up,mjj_JetRelativeJERHFUp,mjj_JetRelativePtBBUp,mjj_JetRelativePtEC1Up,mjj_JetRelativePtEC2Up,mjj_JetRelativePtHFUp,mjj_JetRelativeStatECUp,mjj_JetRelativeStatFSRUp,mjj_JetRelativeStatHFUp,mjj_JetSinglePionECALUp,mjj_JetSinglePionHCALUp,mjj_JetTimePtEtaUp;
float passDoubleMu;
float passDoubleTau35, matchDoubleTau35_1, matchDoubleTau35_2,filterDoubleTau35_1,filterDoubleTau35_2,passDoubleTauCmbIso35,matchDoubleTauCmbIso35_1,matchDoubleTauCmbIso35_2,filterDoubleTauCmbIso35_1,filterDoubleTauCmbIso35_2;
float genM,genpT,genpX,genpY,vispX,vispY, b_vispX;
float genEta, genPhi, genHTT, genMass;
float met_UESUp, met_UESDown, metphi_UESUp, metphi_UESDown, met_JESUp,met_JESDown, metphi_JESUp, metphi_JESDown, met_TESUp,met_TESDown, metphi_TESUp, metphi_TESDown;
float t1GenCharge,t1GenDecayMode,t1GenEnergy,t1GenEta,t1GenIsPrompt,t1GenJetEta,t1GenJetPt,t1GenMotherEnergy,t1GenMotherEta,t1GenMotherPdgId,t1GenMotherPhi,t1GenMotherPt,t1GenPdgId,t1GenPhi,t1GenPt,t1GenStatus,t1ZTTGenDR,t1ZTTGenEta,t1ZTTGenMatching,t1ZTTGenPhi,t1ZTTGenPt;
float t2GenCharge,t2GenDecayMode,t2GenEnergy,t2GenEta,t2GenIsPrompt,t2GenJetEta,t2GenJetPt,t2GenMotherEnergy,t2GenMotherEta,t2GenMotherPdgId,t2GenMotherPhi,t2GenMotherPt,t2GenPdgId,t2GenPhi,t2GenPt,t2GenStatus,t2ZTTGenDR,t2ZTTGenEta,t2ZTTGenMatching,t2ZTTGenPhi,t2ZTTGenPt;

RecoilCorrector recoilPFMetCorrector("TypeI-PFMet_Run2016BtoH.root");

void fillTree(TTree *Run_Tree, HTauTauTree_tt *tree, int entry_tree, int recoil, bool ismc){
    tree->GetEntry(entry_tree);
    run = tree->run;
    lumi = tree->lumi;
    evt =tree->evt;
    aMCatNLO_weight = tree->GenWeight;
    
    njets_JetAbsoluteFlavMapUp=tree->jetVeto30_JetAbsoluteFlavMapUp;
    njets_JetAbsoluteMPFBiasUp=tree->jetVeto30_JetAbsoluteMPFBiasUp;
    njets_JetAbsoluteScaleUp=tree->jetVeto30_JetAbsoluteScaleUp;
    njets_JetAbsoluteStatUp=tree->jetVeto30_JetAbsoluteStatUp;
    njets_JetEnUp=tree->jetVeto30_JetEnUp;
    njets_JetFlavorQCDUp=tree->jetVeto30_JetFlavorQCDUp;
    njets_JetFragmentationUp=tree->jetVeto30_JetFragmentationUp;
    njets_JetPileUpDataMCUp=tree->jetVeto30_JetPileUpDataMCUp;
    njets_JetPileUpPtBBUp=tree->jetVeto30_JetPileUpPtBBUp;
    njets_JetPileUpPtEC1Up=tree->jetVeto30_JetPileUpPtEC1Up;
    njets_JetPileUpPtEC2Up=tree->jetVeto30_JetPileUpPtEC2Up;
    njets_JetPileUpPtHFUp=tree->jetVeto30_JetPileUpPtHFUp;
    njets_JetPileUpPtRefUp=tree->jetVeto30_JetPileUpPtRefUp;
    njets_JetRelativeBalUp=tree->jetVeto30_JetRelativeBalUp;
    njets_JetRelativeFSRUp=tree->jetVeto30_JetRelativeFSRUp;
    njets_JetRelativeJEREC1Up=tree->jetVeto30_JetRelativeJEREC1Up;
    njets_JetRelativeJEREC2Up=tree->jetVeto30_JetRelativeJEREC2Up;
    njets_JetRelativeJERHFUp=tree->jetVeto30_JetRelativeJERHFUp;
    njets_JetRelativePtBBUp=tree->jetVeto30_JetRelativePtBBUp;
    njets_JetRelativePtEC1Up=tree->jetVeto30_JetRelativePtEC1Up;
    njets_JetRelativePtEC2Up=tree->jetVeto30_JetRelativePtEC2Up;
    njets_JetRelativePtHFUp=tree->jetVeto30_JetRelativePtHFUp;
    njets_JetRelativeStatECUp=tree->jetVeto30_JetRelativeStatECUp;
    njets_JetRelativeStatFSRUp=tree->jetVeto30_JetRelativeStatFSRUp;
    njets_JetRelativeStatHFUp=tree->jetVeto30_JetRelativeStatHFUp;
    njets_JetSinglePionECALUp=tree->jetVeto30_JetSinglePionECALUp;
    njets_JetSinglePionHCALUp=tree->jetVeto30_JetSinglePionHCALUp;
    njets_JetTimePtEtaUp=tree->jetVeto30_JetTimePtEtaUp;
    
    njets_JetAbsoluteFlavMapDown=tree->jetVeto30_JetAbsoluteFlavMapDown;
    njets_JetAbsoluteMPFBiasDown=tree->jetVeto30_JetAbsoluteMPFBiasDown;
    njets_JetAbsoluteScaleDown=tree->jetVeto30_JetAbsoluteScaleDown;
    njets_JetAbsoluteStatDown=tree->jetVeto30_JetAbsoluteStatDown;
    njets_JetEnDown=tree->jetVeto30_JetEnDown;
    njets_JetFlavorQCDDown=tree->jetVeto30_JetFlavorQCDDown;
    njets_JetFragmentationDown=tree->jetVeto30_JetFragmentationDown;
    njets_JetPileUpDataMCDown=tree->jetVeto30_JetPileUpDataMCDown;
    njets_JetPileUpPtBBDown=tree->jetVeto30_JetPileUpPtBBDown;
    njets_JetPileUpPtEC1Down=tree->jetVeto30_JetPileUpPtEC1Down;
    njets_JetPileUpPtEC2Down=tree->jetVeto30_JetPileUpPtEC2Down;
    njets_JetPileUpPtHFDown=tree->jetVeto30_JetPileUpPtHFDown;
    njets_JetPileUpPtRefDown=tree->jetVeto30_JetPileUpPtRefDown;
    njets_JetRelativeBalDown=tree->jetVeto30_JetRelativeBalDown;
    njets_JetRelativeFSRDown=tree->jetVeto30_JetRelativeFSRDown;
    njets_JetRelativeJEREC1Down=tree->jetVeto30_JetRelativeJEREC1Down;
    njets_JetRelativeJEREC2Down=tree->jetVeto30_JetRelativeJEREC2Down;
    njets_JetRelativeJERHFDown=tree->jetVeto30_JetRelativeJERHFDown;
    njets_JetRelativePtBBDown=tree->jetVeto30_JetRelativePtBBDown;
    njets_JetRelativePtEC1Down=tree->jetVeto30_JetRelativePtEC1Down;
    njets_JetRelativePtEC2Down=tree->jetVeto30_JetRelativePtEC2Down;
    njets_JetRelativePtHFDown=tree->jetVeto30_JetRelativePtHFDown;
    njets_JetRelativeStatECDown=tree->jetVeto30_JetRelativeStatECDown;
    njets_JetRelativeStatFSRDown=tree->jetVeto30_JetRelativeStatFSRDown;
    njets_JetRelativeStatHFDown=tree->jetVeto30_JetRelativeStatHFDown;
    njets_JetSinglePionECALDown=tree->jetVeto30_JetSinglePionECALDown;
    njets_JetSinglePionHCALDown=tree->jetVeto30_JetSinglePionHCALDown;
    njets_JetTimePtEtaDown=tree->jetVeto30_JetTimePtEtaDown;
    
    mjj_JetAbsoluteFlavMapUp=tree->vbfMass_JetAbsoluteFlavMapUp;
    mjj_JetAbsoluteMPFBiasUp=tree->vbfMass_JetAbsoluteMPFBiasUp;
    mjj_JetAbsoluteScaleUp=tree->vbfMass_JetAbsoluteScaleUp;
    mjj_JetAbsoluteStatUp=tree->vbfMass_JetAbsoluteStatUp;
    mjj_JetEnUp=tree->vbfMass_JetEnUp;
    mjj_JetFlavorQCDUp=tree->vbfMass_JetFlavorQCDUp;
    mjj_JetFragmentationUp=tree->vbfMass_JetFragmentationUp;
    mjj_JetPileUpDataMCUp=tree->vbfMass_JetPileUpDataMCUp;
    mjj_JetPileUpPtBBUp=tree->vbfMass_JetPileUpPtBBUp;
    mjj_JetPileUpPtEC1Up=tree->vbfMass_JetPileUpPtEC1Up;
    mjj_JetPileUpPtEC2Up=tree->vbfMass_JetPileUpPtEC2Up;
    mjj_JetPileUpPtHFUp=tree->vbfMass_JetPileUpPtHFUp;
    mjj_JetPileUpPtRefUp=tree->vbfMass_JetPileUpPtRefUp;
    mjj_JetRelativeBalUp=tree->vbfMass_JetRelativeBalUp;
    mjj_JetRelativeFSRUp=tree->vbfMass_JetRelativeFSRUp;
    mjj_JetRelativeJEREC1Up=tree->vbfMass_JetRelativeJEREC1Up;
    mjj_JetRelativeJEREC2Up=tree->vbfMass_JetRelativeJEREC2Up;
    mjj_JetRelativeJERHFUp=tree->vbfMass_JetRelativeJERHFUp;
    mjj_JetRelativePtBBUp=tree->vbfMass_JetRelativePtBBUp;
    mjj_JetRelativePtEC1Up=tree->vbfMass_JetRelativePtEC1Up;
    mjj_JetRelativePtEC2Up=tree->vbfMass_JetRelativePtEC2Up;
    mjj_JetRelativePtHFUp=tree->vbfMass_JetRelativePtHFUp;
    mjj_JetRelativeStatECUp=tree->vbfMass_JetRelativeStatECUp;
    mjj_JetRelativeStatFSRUp=tree->vbfMass_JetRelativeStatFSRUp;
    mjj_JetRelativeStatHFUp=tree->vbfMass_JetRelativeStatHFUp;
    mjj_JetSinglePionECALUp=tree->vbfMass_JetSinglePionECALUp;
    mjj_JetSinglePionHCALUp=tree->vbfMass_JetSinglePionHCALUp;
    mjj_JetTimePtEtaUp=tree->vbfMass_JetTimePtEtaUp;
    
    mjj_JetAbsoluteFlavMapDown=tree->vbfMass_JetAbsoluteFlavMapDown;
    mjj_JetAbsoluteMPFBiasDown=tree->vbfMass_JetAbsoluteMPFBiasDown;
    mjj_JetAbsoluteScaleDown=tree->vbfMass_JetAbsoluteScaleDown;
    mjj_JetAbsoluteStatDown=tree->vbfMass_JetAbsoluteStatDown;
    mjj_JetEnDown=tree->vbfMass_JetEnDown;
    mjj_JetFlavorQCDDown=tree->vbfMass_JetFlavorQCDDown;
    mjj_JetFragmentationDown=tree->vbfMass_JetFragmentationDown;
    mjj_JetPileUpDataMCDown=tree->vbfMass_JetPileUpDataMCDown;
    mjj_JetPileUpPtBBDown=tree->vbfMass_JetPileUpPtBBDown;
    mjj_JetPileUpPtEC1Down=tree->vbfMass_JetPileUpPtEC1Down;
    mjj_JetPileUpPtEC2Down=tree->vbfMass_JetPileUpPtEC2Down;
    mjj_JetPileUpPtHFDown=tree->vbfMass_JetPileUpPtHFDown;
    mjj_JetPileUpPtRefDown=tree->vbfMass_JetPileUpPtRefDown;
    mjj_JetRelativeBalDown=tree->vbfMass_JetRelativeBalDown;
    mjj_JetRelativeFSRDown=tree->vbfMass_JetRelativeFSRDown;
    mjj_JetRelativeJEREC1Down=tree->vbfMass_JetRelativeJEREC1Down;
    mjj_JetRelativeJEREC2Down=tree->vbfMass_JetRelativeJEREC2Down;
    mjj_JetRelativeJERHFDown=tree->vbfMass_JetRelativeJERHFDown;
    mjj_JetRelativePtBBDown=tree->vbfMass_JetRelativePtBBDown;
    mjj_JetRelativePtEC1Down=tree->vbfMass_JetRelativePtEC1Down;
    mjj_JetRelativePtEC2Down=tree->vbfMass_JetRelativePtEC2Down;
    mjj_JetRelativePtHFDown=tree->vbfMass_JetRelativePtHFDown;
    mjj_JetRelativeStatECDown=tree->vbfMass_JetRelativeStatECDown;
    mjj_JetRelativeStatFSRDown=tree->vbfMass_JetRelativeStatFSRDown;
    mjj_JetRelativeStatHFDown=tree->vbfMass_JetRelativeStatHFDown;
    mjj_JetSinglePionECALDown=tree->vbfMass_JetSinglePionECALDown;
    mjj_JetSinglePionHCALDown=tree->vbfMass_JetSinglePionHCALDown;
    mjj_JetTimePtEtaDown=tree->vbfMass_JetTimePtEtaDown;


    passDoubleTau35 = tree->doubleTau35Pass;
    matchDoubleTau35_1 = tree->t1MatchesDoubleTau35Path; // data    - path
    matchDoubleTau35_2 = tree->t2MatchesDoubleTau35Path;
    filterDoubleTau35_1 = tree->t1MatchesDoubleTau35Filter; // MC   - filter
    filterDoubleTau35_2 = tree->t2MatchesDoubleTau35Filter;
    passDoubleTauCmbIso35 = tree->doubleTauCmbIso35RegPass;
    matchDoubleTauCmbIso35_1 = tree->t1MatchesDoubleTauCmbIso35RegPath;
    matchDoubleTauCmbIso35_2 = tree->t2MatchesDoubleTauCmbIso35RegPath;
    filterDoubleTauCmbIso35_1 = tree->t1MatchesDoubleTauCmbIso35RegFilter;
    filterDoubleTauCmbIso35_2 = tree->t2MatchesDoubleTauCmbIso35RegFilter;

    genpX=tree->genpX;
    genpY=tree->genpY;
    genpT=tree->genpT;
    genM=tree->genM;
    vispX=tree->vispX;
    vispY=tree->vispY;

    genEta=tree->genEta;
    genPhi=tree->genPhi;
    genHTT=tree->genHTT;
    genMass=tree->genMass;

    t1GenCharge=tree->t1GenCharge;
    t1GenDecayMode=tree->t1GenDecayMode;
    t1GenEnergy=tree->t1GenEnergy;
    t1GenEta=tree->t1GenEta;
    t1GenIsPrompt=tree->t1GenIsPrompt;
    t1GenJetEta=tree->t1GenJetEta;
    t1GenJetPt=tree->t1GenJetPt;
    t1GenMotherEnergy=tree->t1GenMotherEnergy;
    t1GenMotherEta=tree->t1GenMotherEta;
    t1GenMotherPdgId=tree->t1GenMotherPdgId;
    t1GenMotherPhi=tree->t1GenMotherPhi;
    t1GenMotherPt=tree->t1GenMotherPt;
    t1GenPdgId=tree->t1GenPdgId;
    t1GenPhi=tree->t1GenPhi;
    t1GenPt=tree->t1GenPt;
    t1GenStatus=tree->t1GenStatus;
    t1ZTTGenDR=tree->t1ZTTGenDR;
    t1ZTTGenEta=tree->t1ZTTGenEta;
    t1ZTTGenMatching=tree->t1ZTTGenMatching;
    t1ZTTGenPhi=tree->t1ZTTGenPhi;
    t1ZTTGenPt=tree->t1ZTTGenPt;

    t2GenCharge=tree->t2GenCharge;
    t2GenDecayMode=tree->t2GenDecayMode;
    t2GenEnergy=tree->t2GenEnergy;
    t2GenEta=tree->t2GenEta;
    t2GenIsPrompt=tree->t2GenIsPrompt;
    t2GenJetEta=tree->t2GenJetEta;
    t2GenJetPt=tree->t2GenJetPt;
    t2GenMotherEnergy=tree->t2GenMotherEnergy;
    t2GenMotherEta=tree->t2GenMotherEta;
    t2GenMotherPdgId=tree->t2GenMotherPdgId;
    t2GenMotherPhi=tree->t2GenMotherPhi;
    t2GenMotherPt=tree->t2GenMotherPt;
    t2GenPdgId=tree->t2GenPdgId;
    t2GenPhi=tree->t2GenPhi;
    t2GenPt=tree->t2GenPt;
    t2GenStatus=tree->t2GenStatus;
    t2ZTTGenDR=tree->t2ZTTGenDR;
    t2ZTTGenEta=tree->t2ZTTGenEta;
    t2ZTTGenMatching=tree->t2ZTTGenMatching;
    t2ZTTGenPhi=tree->t2ZTTGenPhi;
    t2ZTTGenPt=tree->t2ZTTGenPt;


    pt_top1=tree->topQuarkPt1;
    pt_top2=tree->topQuarkPt2;
    numGenJets=tree->numGenJets;

    TLorentzVector tau1;
    TLorentzVector tau2;
    tau1.SetPtEtaPhiM(tree->t1Pt,tree->t1Eta,tree->t1Phi,tree->t1Mass);
    tau2.SetPtEtaPhiM(tree->t2Pt,tree->t2Eta,tree->t2Phi,tree->t2Mass);
    if (ismc && tree->t1DecayMode==0) tau1=tau1*0.982;
    else if (ismc && tree->t1DecayMode==1) tau1=tau1*1.010;
    else if (ismc && tree->t1DecayMode==10) tau1=tau1*1.004;
    if (ismc && tree->t2DecayMode==0) tau2=tau2*0.982;
    else if (ismc && tree->t2DecayMode==1) tau2=tau2*1.010;
    else if (ismc && tree->t2DecayMode==10) tau2=tau2*1.004;

    // configure nominal met
    TLorentzVector mymet;
    mymet.SetPtEtaPhiM(tree->type1_pfMetEt,0,tree->type1_pfMetPhi,0);
    met_norecoil=tree->type1_pfMetEt;
    float pfmetcorr_ex=mymet.Px();
    float pfmetcorr_ey=mymet.Py();

    mymet.SetPxPyPzE(pfmetcorr_ex,pfmetcorr_ey,0,sqrt(pfmetcorr_ex*pfmetcorr_ex+pfmetcorr_ey*pfmetcorr_ey));

    if (recoil == 1) {
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet.Px(),          // uncorrected type I pf met px (float)
          mymet.Py(),          // uncorrected type I pf met py (float)
          tree->genpX,         // generator Z/W/Higgs px (float)
          tree->genpY,         // generator Z/W/Higgs py (float)
          tree->vispX,         // generator visible Z/W/Higgs px (float)
          tree->vispY,         // generator visible Z/W/Higgs py (float)
          tree->jetVeto30 + 1, // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex,        // corrected type I pf met px (float)
          pfmetcorr_ey         // corrected type I pf met py (float)
      );
    } else if (recoil == 2) {
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet.Px(),      // uncorrected type I pf met px (float)
          mymet.Py(),      // uncorrected type I pf met py (float)
          tree->genpX,     // generator Z/W/Higgs px (float)
          tree->genpY,     // generator Z/W/Higgs py (float)
          tree->vispX,     // generator visible Z/W/Higgs px (float)
          tree->vispY,     // generator visible Z/W/Higgs py (float)
          tree->jetVeto30, // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex,    // corrected type I pf met px (float)
          pfmetcorr_ey     // corrected type I pf met py (float)
      );
    }

    // configure met systematics
    /*
    type1_pfMet_shiftedPt_UnclusteredEnUp = tree->type1_pfMet_shiftedPt_UnclusteredEnUp;
    type1_pfMet_shiftedPt_UnclusteredEnDown = tree->type1_pfMet_shiftedPt_UnclusteredEnDown;
    type1_pfMet_shiftedPhi_UnclusteredEnUp = tree->type1_pfMet_shiftedPhi_UnclusteredEnUp;
    type1_pfMet_shiftedPhi_UnclusteredEnDown = tree->type1_pfMet_shiftedPhi_UnclusteredEnDown;
    type1_pfMet_shiftedPt_JetEnUp = tree->type1_pfMet_shiftedPt_JetEnUp;
    type1_pfMet_shiftedPt_JetEnDown = tree->type1_pfMet_shiftedPt_JetEnDown;
    type1_pfMet_shiftedPhi_JetEnUp = tree->type1_pfMet_shiftedPhi_JetEnUp;
    type1_pfMet_shiftedPhi_JetEnDown = tree->type1_pfMet_shiftedPhi_JetEnDown;
    */
    met_UESUp =  tree->type1_pfMet_shiftedPt_UnclusteredEnUp; 
    met_UESDown = tree->type1_pfMet_shiftedPt_UnclusteredEnDown;  
    metphi_UESUp = tree->type1_pfMet_shiftedPhi_UnclusteredEnUp;
    metphi_UESDown = tree->type1_pfMet_shiftedPhi_UnclusteredEnDown; 
    met_JESUp = tree->type1_pfMet_shiftedPt_JetEnUp; 
    met_JESDown = tree->type1_pfMet_shiftedPt_JetEnDown;  
    metphi_JESUp = tree->type1_pfMet_shiftedPhi_JetEnUp;
    metphi_JESDown = tree->type1_pfMet_shiftedPhi_JetEnDown;  

    TLorentzVector mymet_UESUp, mymet_UESDown, mymet_JESUp, mymet_JESDown;
    /*
    mymet_UESUp   .SetPtEtaPhiM(type1_pfMet_shiftedPt_UnclusteredEnUp  , 0, type1_pfMet_shiftedPhi_UnclusteredEnUp  , 0);
    mymet_UESDown .SetPtEtaPhiM(type1_pfMet_shiftedPt_UnclusteredEnDown, 0, type1_pfMet_shiftedPhi_UnclusteredEnDown, 0);
    mymet_JESUp   .SetPtEtaPhiM(type1_pfMet_shiftedPt_JetEnDown        , 0, type1_pfMet_shiftedPhi_JetEnUp          , 0);
    mymet_JESDown .SetPtEtaPhiM(type1_pfMet_shiftedPt_JetEnUp          , 0, type1_pfMet_shiftedPhi_JetEnDown        , 0);
    */
    mymet_UESUp   .SetPtEtaPhiM(met_UESUp  , 0, metphi_UESUp  , 0);
    mymet_UESDown .SetPtEtaPhiM(met_UESDown, 0, metphi_UESDown, 0);
    mymet_JESUp   .SetPtEtaPhiM(met_JESUp  , 0, metphi_JESUp  , 0);
    mymet_JESDown .SetPtEtaPhiM(met_JESDown, 0, metphi_JESDown, 0);

    float pfmetcorr_ex_UESUp(mymet_UESUp.Px())    , pfmetcorr_ey_UESUp(mymet_UESUp.Py()),
          pfmetcorr_ex_UESDown(mymet_UESDown.Px()), pfmetcorr_ey_UESDown(mymet_UESDown.Py()),
          pfmetcorr_ex_JESUp(mymet_JESUp.Px())    , pfmetcorr_ey_JESUp(mymet_JESUp.Py()),
          pfmetcorr_ex_JESDown(mymet_JESDown.Px()), pfmetcorr_ey_JESDown(mymet_JESDown.Py())
          ;

    if (recoil == 1) {  // W
      // unclustered enery up
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet_UESUp.Px(),       // uncorrected type I pf met px (float)
          mymet_UESUp.Py(),       // uncorrected type I pf met py (float)
          tree->genpX,            // generator Z/W/Higgs px (float)
          tree->genpY,            // generator Z/W/Higgs py (float)
          tree->vispX,            // generator visible Z/W/Higgs px (float)
          tree->vispY,            // generator visible Z/W/Higgs py (float)
          tree->jetVeto30 + 1,    // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex_UESUp,     // corrected type I pf met px (float)
          pfmetcorr_ey_UESUp      // corrected type I pf met py (float)
      );

      // unclustered enery down
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet_UESDown.Px(),     // uncorrected type I pf met px (float)
          mymet_UESDown.Py(),     // uncorrected type I pf met py (float)
          tree->genpX,            // generator Z/W/Higgs px (float)
          tree->genpY,            // generator Z/W/Higgs py (float)
          tree->vispX,            // generator visible Z/W/Higgs px (float)
          tree->vispY,            // generator visible Z/W/Higgs py (float)
          tree->jetVeto30 + 1,    // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex_UESDown,   // corrected type I pf met px (float)
          pfmetcorr_ey_UESDown    // corrected type I pf met py (float)
      );

      // jet enery up
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet_JESUp.Px(),    // uncorrected type I pf met px (float)
          mymet_JESUp.Py(),    // uncorrected type I pf met py (float)
          tree->genpX,         // generator Z/W/Higgs px (float)
          tree->genpY,         // generator Z/W/Higgs py (float)
          tree->vispX,         // generator visible Z/W/Higgs px (float)
          tree->vispY,         // generator visible Z/W/Higgs py (float)
          tree->jetVeto30 + 1, // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex_JESUp,  // corrected type I pf met px (float)
          pfmetcorr_ey_JESUp   // corrected type I pf met py (float)
      );

      // jet enery down
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet_JESDown.Px(),   // uncorrected type I pf met px (float)
          mymet_JESDown.Py(),   // uncorrected type I pf met py (float)
          tree->genpX,          // generator Z/W/Higgs px (float)
          tree->genpY,          // generator Z/W/Higgs py (float)
          tree->vispX,          // generator visible Z/W/Higgs px (float)
          tree->vispY,          // generator visible Z/W/Higgs py (float)
          tree->jetVeto30 + 1,  // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex_JESDown, // corrected type I pf met px (float)
          pfmetcorr_ey_JESDown  // corrected type I pf met py (float)
      );
    } else if (recoil == 2) {  // Z
      // unclustered enery up
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet_UESUp.Px(),    // uncorrected type I pf met px (float)
          mymet_UESUp.Py(),    // uncorrected type I pf met py (float)
          tree->genpX,         // generator Z/W/Higgs px (float)
          tree->genpY,         // generator Z/W/Higgs py (float)
          tree->vispX,         // generator visible Z/W/Higgs px (float)
          tree->vispY,         // generator visible Z/W/Higgs py (float)
          tree->jetVeto30,     // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex_UESUp,  // corrected type I pf met px (float)
          pfmetcorr_ey_UESUp   // corrected type I pf met py (float)
      );

      // unclustered enery down
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet_UESDown.Px(),   // uncorrected type I pf met px (float)
          mymet_UESDown.Py(),   // uncorrected type I pf met py (float)
          tree->genpX,          // generator Z/W/Higgs px (float)
          tree->genpY,          // generator Z/W/Higgs py (float)
          tree->vispX,          // generator visible Z/W/Higgs px (float)
          tree->vispY,          // generator visible Z/W/Higgs py (float)
          tree->jetVeto30,      // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex_UESDown, // corrected type I pf met px (float)
          pfmetcorr_ey_UESDown  // corrected type I pf met py (float)
      );

      // jet enery up
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet_JESUp.Px(),    // uncorrected type I pf met px (float)
          mymet_JESUp.Py(),    // uncorrected type I pf met py (float)
          tree->genpX,         // generator Z/W/Higgs px (float)
          tree->genpY,         // generator Z/W/Higgs py (float)
          tree->vispX,         // generator visible Z/W/Higgs px (float)
          tree->vispY,         // generator visible Z/W/Higgs py (float)
          tree->jetVeto30,     // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex_JESUp,  // corrected type I pf met px (float)
          pfmetcorr_ey_JESUp   // corrected type I pf met py (float)
      );

      // jet enery down
      recoilPFMetCorrector.CorrectByMeanResolution(
          mymet_JESDown.Px(),   // uncorrected type I pf met px (float)
          mymet_JESDown.Py(),   // uncorrected type I pf met py (float)
          tree->genpX,          // generator Z/W/Higgs px (float)
          tree->genpY,          // generator Z/W/Higgs py (float)
          tree->vispX,          // generator visible Z/W/Higgs px (float)
          tree->vispY,          // generator visible Z/W/Higgs py (float)
          tree->jetVeto30,      // number of jets (hadronic jet multiplicity) (int)
          pfmetcorr_ex_JESDown, // corrected type I pf met px (float)
          pfmetcorr_ey_JESDown  // corrected type I pf met py (float)
      );
    }

    // correct met systematics
    mymet_UESUp  .SetPxPyPzE(pfmetcorr_ex_UESUp  , pfmetcorr_ey_UESUp  , 0, sqrt(pfmetcorr_ex_UESUp * pfmetcorr_ex_UESUp + pfmetcorr_ey_UESUp * pfmetcorr_ey_UESUp));
    mymet_UESDown.SetPxPyPzE(pfmetcorr_ex_UESDown, pfmetcorr_ey_UESDown, 0, sqrt(pfmetcorr_ex_UESDown * pfmetcorr_ex_UESDown + pfmetcorr_ey_UESDown * pfmetcorr_ey_UESDown));
    mymet_JESUp  .SetPxPyPzE(pfmetcorr_ex_JESUp  , pfmetcorr_ey_JESUp  , 0, sqrt(pfmetcorr_ex_JESUp * pfmetcorr_ex_JESUp + pfmetcorr_ey_JESUp * pfmetcorr_ey_JESUp));
    mymet_JESDown.SetPxPyPzE(pfmetcorr_ex_JESDown, pfmetcorr_ey_JESDown, 0, sqrt(pfmetcorr_ex_JESDown * pfmetcorr_ex_JESDown + pfmetcorr_ey_JESDown * pfmetcorr_ey_JESDown));

    if (ismc && tree->t1DecayMode == 0 && tree->t2DecayMode == 0) mymet = mymet + (tau1 + tau2) - 0.982 * (tau1 + tau2);
    else if (ismc && tree->t1DecayMode==0 && tree->t2DecayMode==1) mymet=mymet+(tau1+tau2)-0.982*tau1-1.010*tau2;
    else if (ismc && tree->t1DecayMode==0 && tree->t2DecayMode==10) mymet=mymet+(tau1+tau2)-0.982*tau1-1.004*tau2;
    else if (ismc && tree->t1DecayMode==1 && tree->t2DecayMode==0) mymet=mymet+(tau1+tau2)-1.010*tau1-1.010*tau2;
    else if (ismc && tree->t1DecayMode==1 && tree->t2DecayMode==1) mymet=mymet+(tau1+tau2)-1.010*(tau1+tau2);
    else if (ismc && tree->t1DecayMode==1 && tree->t2DecayMode==10) mymet=mymet+(tau1+tau2)-1.010*tau1-1.004*tau2;
    else if (ismc && tree->t1DecayMode==10 && tree->t2DecayMode==1) mymet=mymet+(tau1+tau2)-1.004*tau1-1.010*tau2;
    else if (ismc && tree->t1DecayMode==10 && tree->t2DecayMode==0) mymet=mymet+(tau1+tau2)-1.004*tau1-1.004*tau2;
    else if (ismc && tree->t1DecayMode==10 && tree->t2DecayMode==10) mymet=mymet+(tau1+tau2)-1.004*(tau1+tau2);

    met=mymet.Pt();
    metphi=mymet.Phi();
    met_px=mymet.Px();
    met_py=mymet.Py();

    metSig=tree->metSig;
    metcov00=tree->metcov00;
    metcov01=tree->metcov01;
    metcov10=tree->metcov10;
    metcov11=tree->metcov11;

    metcov00_v2=tree->metcov00_DESYlike;  
    metcov01_v2=tree->metcov01_DESYlike; 
    metcov10_v2=tree->metcov10_DESYlike; 
    metcov11_v2=tree->metcov11_DESYlike; 

    njets = tree->jetVeto30;
    nbtag = tree->bjetCISVVeto20Medium;
    nbtagL = tree->bjetCISVVeto20Loose;
    njetspt20=tree->jetVeto20;

    njets_JESDown = tree->jetVeto30_JetEnDown;
    njetspt20_JESDown=tree->jetVeto20_JetEnDown;
    njets_JESUp = tree->jetVeto30_JetEnUp;
    njetspt20_JESUp=tree->jetVeto20_JetEnUp;

    gen_match_1=tree->t1ZTTGenMatching;
    gen_match_2=tree->t2ZTTGenMatching;

    extraelec_veto=(tree->eVetoZTTp001dxyzR0>0);
    extramuon_veto=(tree->muVetoZTTp001dxyzR0>0);
    dilepton_veto=(tree->dimuonVeto>0);
 
    t1_decayMode=tree->t1DecayMode;
    t2_decayMode=tree->t2DecayMode;

    m_1 = tau1.M();
    if (tree->t1DecayMode==0) m_1=tree->t1Mass;
    px_1 = tau1.Px();
    py_1 = tau1.Py();
    pz_1 = tau1.Pz();
    e_1 = tau1.E();
    pt_1 = tau1.Pt();
    phi_1 = tau1.Phi();
    eta_1 = tau1.Eta();
    mt_1 = tree->t1MtToPfMet_type1;
    d0_1 = tree->t1PVDXY;
    dZ_1 = tree->t1PVDZ;
    iso_1 = tree->t1ByVLooseIsolationMVArun2v1DBoldDMwLT;
    q_1 = tree->t1Charge;
    trackpt_1 = tree->t1LeadTrackPt;
    jetPt_1 = tree->t1JetPt;
    
    againstMuonTight3_1 = tree->t1AgainstMuonTight3;
    againstMuonLoose3_1 = tree->t1AgainstMuonLoose3;
    againstElectronVLooseMVA6_1 = tree->t1AgainstElectronVLooseMVA6;
    againstElectronLooseMVA6_1 = tree->t1AgainstElectronLooseMVA6;
    againstElectronMediumMVA6_1 = tree->t1AgainstElectronMediumMVA6;
    againstElectronTightMVA6_1 = tree->t1AgainstElectronTightMVA6;
    againstElectronVTightMVA6_1 = tree->t1AgainstElectronVTightMVA6;
    byVLooseIsolationMVArun2v1DBoldDMwLT_1 = tree->t1ByVLooseIsolationMVArun2v1DBoldDMwLT;
    byLooseIsolationMVArun2v1DBoldDMwLT_1 = tree->t1ByLooseIsolationMVArun2v1DBoldDMwLT;
    byMediumIsolationMVArun2v1DBoldDMwLT_1 = tree->t1ByMediumIsolationMVArun2v1DBoldDMwLT;
    byTightIsolationMVArun2v1DBoldDMwLT_1 = tree->t1ByTightIsolationMVArun2v1DBoldDMwLT;
    byVTightIsolationMVArun2v1DBoldDMwLT_1 = tree->t1ByVTightIsolationMVArun2v1DBoldDMwLT;
    byVVTightIsolationMVArun2v1DBoldDMwLT_1 = tree->t1ByVVTightIsolationMVArun2v1DBoldDMwLT;
    byCombinedIsolationDeltaBetaCorrRaw3Hits_1=tree->t1ByCombinedIsolationDeltaBetaCorrRaw3Hits;
    byIsolationMVA3oldDMwoLTraw_1=tree->t1ByIsolationMVArun2v1DBoldDMwLTraw;
    decayModeFinding_1=tree->t1DecayModeFinding;

    m_2 = tau2.M();
    if (tree->t2DecayMode==0) m_2=tree->t2Mass;
    px_2 = tau2.Px();
    py_2 = tau2.Py();
    pz_2 = tau2.Pz();
    e_2 = tau2.E();
    pt_2 = tau2.Pt();
    phi_2 = tau2.Phi();
    eta_2 = tau2.Eta();
    mt_2 = tree->t2MtToPfMet_type1;
    d0_2 = tree->t2PVDXY;
    dZ_2 = tree->t2PVDZ;
    iso_2 = tree->t2ByVLooseIsolationMVArun2v1DBoldDMwLT;
    q_2 = tree->t2Charge;
    trackpt_2 = tree->t2LeadTrackPt;
    jetPt_2 = tree->t2JetPt;

    againstMuonTight3_2 = tree->t2AgainstMuonTight3;
    againstMuonLoose3_2 = tree->t2AgainstMuonLoose3;
    againstElectronVLooseMVA6_2 = tree->t2AgainstElectronVLooseMVA6;
    againstElectronLooseMVA6_2 = tree->t2AgainstElectronLooseMVA6;
    againstElectronMediumMVA6_2 = tree->t2AgainstElectronMediumMVA6;
    againstElectronTightMVA6_2 = tree->t2AgainstElectronTightMVA6;
    againstElectronVTightMVA6_2 = tree->t2AgainstElectronVTightMVA6;
    byVLooseIsolationMVArun2v1DBoldDMwLT_2 = tree->t2ByVLooseIsolationMVArun2v1DBoldDMwLT;
    byLooseIsolationMVArun2v1DBoldDMwLT_2 = tree->t2ByLooseIsolationMVArun2v1DBoldDMwLT;
    byMediumIsolationMVArun2v1DBoldDMwLT_2 = tree->t2ByMediumIsolationMVArun2v1DBoldDMwLT;
    byTightIsolationMVArun2v1DBoldDMwLT_2 = tree->t2ByTightIsolationMVArun2v1DBoldDMwLT;
    byVTightIsolationMVArun2v1DBoldDMwLT_2 = tree->t2ByVTightIsolationMVArun2v1DBoldDMwLT;
    byVVTightIsolationMVArun2v1DBoldDMwLT_2 = tree->t2ByVVTightIsolationMVArun2v1DBoldDMwLT;
    byCombinedIsolationDeltaBetaCorrRaw3Hits_2=tree->t2ByCombinedIsolationDeltaBetaCorrRaw3Hits;
    byIsolationMVA3oldDMwoLTraw_2=tree->t2ByIsolationMVArun2v1DBoldDMwLTraw;
    decayModeFinding_2=tree->t2DecayModeFinding;


    jpt_1=tree->j1pt;
    jpt_2=tree->j2pt;
    jeta_1=tree->j1eta;
    jeta_2=tree->j2eta;
    jphi_1=tree->j1phi;
    jphi_2=tree->j2phi;
    jcsv_1=tree->j1csv;
    jcsv_2=tree->j2csv;
    jpt_1_JESUp=tree->j1ptUp;
    jpt_1_JESDown=tree->j1ptDown;
    jpt_2_JESUp=tree->j2ptUp;
    jpt_2_JESDown=tree->j2ptDown;

    bpt_1=tree->jb1pt;
    bpt_2=tree->jb2pt;
    beta_1=tree->jb1eta;
    beta_2=tree->jb2eta;
    bphi_1=tree->jb1phi;
    bphi_2=tree->jb2phi;
    bcsv_1=tree->jb1csv;
    bcsv_2=tree->jb2csv;
    bflavor_1=tree->jb1hadronflavor;
    bflavor_2=tree->jb2hadronflavor;

   TLorentzVector jet1;
   if (njetspt20 > 0 && jpt_1>0)
      jet1.SetPtEtaPhiM(jpt_1,jeta_1,jphi_1,0);
   TLorentzVector jet2;
   if (njetspt20 > 1 && jpt_2>0)
      jet2.SetPtEtaPhiM(jpt_2,jeta_2,jphi_2,0);
   TLorentzVector dijet=jet1+jet2;
   if (njetspt20 > 1){
      jdeta=tree->vbfDeta;
      jdphi=tree->vbfDphi;
      dijetphi=dijet.Phi();
      mjj=tree->vbfMass;
      njetingap20=tree->vbfJetVeto20;
      njetingap=tree->vbfJetVeto30;
   }
   else{
      jdphi=-10000;
      jdeta=-10000;
      dijetpt=-10000;
      dijetphi=-10000;
      hdijetphi=-10000;
      visjeteta=-10000;
      mjj=-10000;
      njetingap20=-10000;
      njetingap=-100000;
   }
   if (njetspt20_JESUp > 1){
      njetingap20_JESUp=tree->vbfJetVeto20_JetEnUp;
      njetingap_JESUp=tree->vbfJetVeto30_JetEnUp;
      mjj_JESUp=tree->vbfMass_JetEnUp;
      jdeta_JESUp=tree->vbfDeta_JetEnUp;
   }
   else{
      jdeta_JESUp=-10000;
      mjj_JESUp=-10000;
      njetingap20_JESUp=-10000;
      njetingap_JESUp=-100000;
   }
   if (njetspt20_JESDown > 1){
      njetingap20_JESDown=tree->vbfJetVeto20_JetEnDown;
      njetingap_JESDown=tree->vbfJetVeto30_JetEnDown;
      mjj_JESDown=tree->vbfMass_JetEnDown;
      jdeta_JESDown=tree->vbfDeta_JetEnDown;
   }
   else{
      jdeta_JESDown=-10000;
      mjj_JESDown=-10000;
      njetingap20_JESDown=-10000;
      njetingap_JESDown=-100000;
   }

  NUP=tree->NUP;
  npu=tree->nTruePU;
  npv=tree->nvtx;
  rho=tree->rho;

  extratau_veto=tree->tauVetoPt20Loose3HitsVtx;
  Run_Tree->Fill();
}

#endif


