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
#include "HTauTauTree_mt.h"
#include "RecoilCorrector.h"
//#include "myHelper.h"

using namespace std;

unsigned int run, lumi, evt, NUP = -10;
bool secondMuon=false;
int gen_match_1, gen_match_2=0;
float met_norecoil;
float npu, rho, npv=-1, puweight, weight;
bool isZtt, isZmt, isZet, isZee, isZmm, isZem, isZEE, isZMM, isZLL, isFake;
float e_1, px_1, py_1, pz_1, pt_1, phi_1, eta_1, m_1, q_1, d0_1, dZ_1, mt_1, iso_1, l1_decayMode, iso_1_v2;
float id_m_highpt_1, id_m_loose_1, id_m_medium_1, id_m_tight_1, id_m_tightnovtx_1, id_m_hihghpt_1, id_e_mva_nt_loose_1, id_e_mva_nt_tight_1, id_e_cut_veto_1, id_e_cut_loose_1, id_e_cut_medium_1, id_e_cut_tight_1, againstElectronLooseMVA6_1, againstElectronMediumMVA6_1, againstElectronTightMVA6_1, againstElectronVLooseMVA6_1, againstElectronVTightMVA6_1, againstMuonLoose3_1, againstMuonTight3_1, decayModeFinding_1, decayModeFindingNewDMs_1,id_m_medium2016_1;
float trigweight_1, byCombinedIsolationDeltaBetaCorrRaw3Hits_1, byIsolationMVA3oldDMwoLTraw_1, byIsolationMVA3oldDMwLTraw_1, byIsolationMVA3newDMwoLTraw_1, byIsolationMVA3newDMwLTraw_1, chargedIsoPtSum_1, neutralIsoPtSum_1, puCorrPtSum_1;
float e_2, px_2, py_2, pz_2, pt_2, phi_2, eta_2, m_2, q_2, d0_2, dZ_2, mt_2, iso_2, l2_decayMode;
float id_m_highpt_2, id_m_loose_2, id_m_medium_2, id_m_tight_2, id_m_tightnovtx_2, id_m_hihghpt_2, id_e_mva_nt_loose_2, id_e_mva_nt_tight_2, id_e_cut_veto_2, id_e_cut_loose_2, id_e_cut_medium_2, id_e_cut_tight_2, againstElectronLooseMVA6_2, againstElectronMediumMVA6_2, againstElectronTightMVA6_2, againstElectronVLooseMVA6_2, againstElectronVTightMVA6_2, againstMuonLoose3_2, againstMuonTight3_2, decayModeFinding_2, decayModeFindingNewDMs_2;
float trigweight_2, byCombinedIsolationDeltaBetaCorrRaw3Hits_2, byIsolationMVA3oldDMwoLTraw_2, byIsolationMVA3oldDMwLTraw_2, byIsolationMVA3newDMwoLTraw_2, byIsolationMVA3newDMwLTraw_2, chargedIsoPtSum_2, neutralIsoPtSum_2, puCorrPtSum_2;
float sigmaIetaIeta_1, deltaPhiSuperCluster_1, deltaEtaSuperCluster_1, depositR03tracker_1, depositR03ecal_1, depositR03hcal_1, trackIso_1, ecalIso_1, hcalIso_1; 
float sigmaIetaIeta_2, deltaPhiSuperCluster_2, deltaEtaSuperCluster_2, depositR03tracker_2, depositR03ecal_2, depositR03hcal_2, trackIso_2, ecalIso_2, hcalIso_2;
float pt_tt, m_vis, m_sv, pt_sv, eta_sv, phi_sv, met_sv, mjj, jdeta, jdphi, dijetpt, dijetphi, hdijetphi, visjeteta, ptvis, m_coll, m_coll_uesU, m_coll_uesD, m_coll_jesU, m_coll_jesD, m_coll_tesU, m_coll_tesD;
float mjj_JESDown, jdeta_JESDown,mjj_JESUp,jdeta_JESUp;
int njetingap, njetingap20, nbtag, njets, njetspt20;
int njetingap_JESDown, njetingap20_JESDown, njets_JESDown, njetspt20_JESDown;
int njetingap_JESUp, njetingap20_JESUp, njets_JESUp, njetspt20_JESUp;
float je_1, jmass_1, jpt_1, jpx_1, jpy_1, jpz_1, jeta_1, jphi_1, jrawf_1, jmva_1, jpfid_1, jpuid_1, jcsv_1, jpt_1_JESUp, jpt_1_JESDown;
float je_2, jmass_2, jpx_2, jpy_2, jpz_2, jpt_2, jeta_2, jphi_2, jrawf_2, jmva_2, jpfid_2, jpuid_2, jcsv_2, jpt_2_JESUp, jpt_2_JESDown;
float bpt_1, beta_1, bphi_1, brawf_1, bmva_1, bpfid_1, bpuid_1, bcsv_1, bflavor_1;
float bpt_2, beta_2, bphi_2, brawf_2, bmva_2, bpfid_2, bpuid_2, bcsv_2, bflavor_2;
float met, metphi, mvaMet, mvaMetphi, pzetavis, pzetamiss, mvacov00, mvacov01, mvacov11, mvacov10;
int nb_extra_electrons, nb_extra_muons=0;
float top_reweighting, gen_Higgs_pt, gen_Higgs_mass=1.0;
float extraelec_veto, extramuon_veto, dilepton_veto=false;
float byLooseCombinedIsolationDeltaBetaCorr3Hits_2, byMediumCombinedIsolationDeltaBetaCorr3Hits_2, byTightCombinedIsolationDeltaBetaCorr3Hits_2;
float byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2, byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2, byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2;
float charged_signalCone_2, charged_isoCone_2, trackpt_2;
float chargedIso_2, puIso_2, neutralIso_2, photonIso_2;
float extratau_veto, pt_top1, pt_top2, genweight, dphi_12, dphi_mumet, dphi_taumet;
float aMCatNLO_weight, numGenJets,jetPt_2;
float met_px, met_py;
float byVLooseIsolationMVArun2v1DBnewDMwLT_2,  byVLooseIsolationMVArun2v1DBoldDMwLT_2,  byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2;
float byLooseIsolationMVArun2v1DBnewDMwLT_2,  byLooseIsolationMVArun2v1DBoldDMwLT_2,  byLooseIsolationMVArun2v1DBdR03oldDMwLT_2;
float byMediumIsolationMVArun2v1DBnewDMwLT_2,  byMediumIsolationMVArun2v1DBoldDMwLT_2,  byMediumIsolationMVArun2v1DBdR03oldDMwLT_2;
float byTightIsolationMVArun2v1DBnewDMwLT_2,  byTightIsolationMVArun2v1DBoldDMwLT_2,  byTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float byVTightIsolationMVArun2v1DBnewDMwLT_2,  byVTightIsolationMVArun2v1DBoldDMwLT_2,  byVTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float byVVTightIsolationMVArun2v1DBnewDMwLT_2,  byVVTightIsolationMVArun2v1DBoldDMwLT_2,  byVVTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float metSig, metcov00, metcov01, metcov10,metcov11, mvaMetcov00, mvaMetcov01,mvaMetcov10,mvaMetcov11, metcov00_v2, metcov01_v2, metcov10_v2,metcov11_v2;
float genM,genpT,genpX,genpY,vispX,vispY;
float met_JERDown,met_JESDown,met_UESDown,met_MESDown,met_EESDown,met_TESDown,met_PESDown;
float met_JERUp,met_JESUp,met_UESUp,met_MESUp,met_EESUp,met_TESUp,met_PESUp;
float metphi_JERDown,metphi_JESDown,metphi_UESDown,metphi_MESDown,metphi_EESDown,metphi_TESDown,metphi_PESDown;
float metphi_JERUp,metphi_JESUp,metphi_UESUp,metphi_MESUp,metphi_EESUp,metphi_TESUp,metphi_PESUp;
float genDR_2;
float byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2, byVTightIsolationRerunMVArun2v1DBoldDMwLT_2, byLooseIsolationRerunMVArun2v1DBoldDMwLT_2, byMediumIsolationRerunMVArun2v1DBoldDMwLT_2, byTightIsolationRerunMVArun2v1DBoldDMwLT_2, byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2,byIsolationRerunMVA3oldDMwLTraw_2;
float matchIsoMu22eta2p1_1,matchIsoTkMu22eta2p1_1,matchIsoMu22_1,matchIsoTkMu22_1,matchIsoMu24_1,matchIsoTkMu24_1,matchIsoMu19Tau20_1,matchIsoMu21Tau20_1,filterIsoMu22eta2p1_1,filterIsoTkMu22eta2p1_1,filterIsoMu22_1,filterIsoTkMu22_1,filterIsoMu24_1,filterIsoTkMu24_1,filterIsoMu19Tau20_1,filterIsoMu21Tau20_1,passIsoMu22eta2p1,passIsoTkMu22eta2p1,passIsoMu22,passIsoTkMu22,passIsoMu24,passIsoTkMu24,passIsoMu19Tau20,passIsoMu21Tau20,matchIsoMu19Tau20_2,matchIsoMu21Tau20_2,filterIsoMu19Tau20_2,filterIsoMu21Tau20_2;
int njets_JetAbsoluteFlavMapDown,njets_JetAbsoluteMPFBiasDown,njets_JetAbsoluteScaleDown,njets_JetAbsoluteStatDown,njets_JetEnDown,njets_JetFlavorQCDDown,njets_JetFragmentationDown,njets_JetPileUpDataMCDown,njets_JetPileUpPtBBDown,njets_JetPileUpPtEC1Down,njets_JetPileUpPtEC2Down,njets_JetPileUpPtHFDown,njets_JetPileUpPtRefDown,njets_JetRelativeBalDown,njets_JetRelativeFSRDown,njets_JetRelativeJEREC1Down,njets_JetRelativeJEREC2Down,njets_JetRelativeJERHFDown,njets_JetRelativePtBBDown,njets_JetRelativePtEC1Down,njets_JetRelativePtEC2Down,njets_JetRelativePtHFDown,njets_JetRelativeStatECDown,njets_JetRelativeStatFSRDown,njets_JetRelativeStatHFDown,njets_JetSinglePionECALDown,njets_JetSinglePionHCALDown,njets_JetTimePtEtaDown;
int njets_JetAbsoluteFlavMapUp,njets_JetAbsoluteMPFBiasUp,njets_JetAbsoluteScaleUp,njets_JetAbsoluteStatUp,njets_JetEnUp,njets_JetFlavorQCDUp,njets_JetFragmentationUp,njets_JetPileUpDataMCUp,njets_JetPileUpPtBBUp,njets_JetPileUpPtEC1Up,njets_JetPileUpPtEC2Up,njets_JetPileUpPtHFUp,njets_JetPileUpPtRefUp,njets_JetRelativeBalUp,njets_JetRelativeFSRUp,njets_JetRelativeJEREC1Up,njets_JetRelativeJEREC2Up,njets_JetRelativeJERHFUp,njets_JetRelativePtBBUp,njets_JetRelativePtEC1Up,njets_JetRelativePtEC2Up,njets_JetRelativePtHFUp,njets_JetRelativeStatECUp,njets_JetRelativeStatFSRUp,njets_JetRelativeStatHFUp,njets_JetSinglePionECALUp,njets_JetSinglePionHCALUp,njets_JetTimePtEtaUp;
float mjj_JetAbsoluteFlavMapDown,mjj_JetAbsoluteMPFBiasDown,mjj_JetAbsoluteScaleDown,mjj_JetAbsoluteStatDown,mjj_JetEnDown,mjj_JetFlavorQCDDown,mjj_JetFragmentationDown,mjj_JetPileUpDataMCDown,mjj_JetPileUpPtBBDown,mjj_JetPileUpPtEC1Down,mjj_JetPileUpPtEC2Down,mjj_JetPileUpPtHFDown,mjj_JetPileUpPtRefDown,mjj_JetRelativeBalDown,mjj_JetRelativeFSRDown,mjj_JetRelativeJEREC1Down,mjj_JetRelativeJEREC2Down,mjj_JetRelativeJERHFDown,mjj_JetRelativePtBBDown,mjj_JetRelativePtEC1Down,mjj_JetRelativePtEC2Down,mjj_JetRelativePtHFDown,mjj_JetRelativeStatECDown,mjj_JetRelativeStatFSRDown,mjj_JetRelativeStatHFDown,mjj_JetSinglePionECALDown,mjj_JetSinglePionHCALDown,mjj_JetTimePtEtaDown;
float mjj_JetAbsoluteFlavMapUp,mjj_JetAbsoluteMPFBiasUp,mjj_JetAbsoluteScaleUp,mjj_JetAbsoluteStatUp,mjj_JetEnUp,mjj_JetFlavorQCDUp,mjj_JetFragmentationUp,mjj_JetPileUpDataMCUp,mjj_JetPileUpPtBBUp,mjj_JetPileUpPtEC1Up,mjj_JetPileUpPtEC2Up,mjj_JetPileUpPtHFUp,mjj_JetPileUpPtRefUp,mjj_JetRelativeBalUp,mjj_JetRelativeFSRUp,mjj_JetRelativeJEREC1Up,mjj_JetRelativeJEREC2Up,mjj_JetRelativeJERHFUp,mjj_JetRelativePtBBUp,mjj_JetRelativePtEC1Up,mjj_JetRelativePtEC2Up,mjj_JetRelativePtHFUp,mjj_JetRelativeStatECUp,mjj_JetRelativeStatFSRUp,mjj_JetRelativeStatHFUp,mjj_JetSinglePionECALUp,mjj_JetSinglePionHCALUp,mjj_JetTimePtEtaUp;
float flag_BadChargedCandidate, flag_BadPFMuon, flag_EcalDeadCellTriggerPrimitive, flag_HBHENoise, flag_HBHENoiseIso, flag_badCloneMuon, flag_badGlobalMuon, flag_eeBadSc, flag_globalTightHalo2016, flag_goodVertices;
float tZTTGenDR;


RecoilCorrector recoilPFMetCorrector("TypeI-PFMet_Run2016BtoH.root");

void fillTree(TTree *Run_Tree, HTauTauTree_mt *tree, int entry_tree, int recoil, bool ismc) {
    tree->GetEntry(entry_tree);
    run = tree->run;
    lumi = tree->lumi;
    evt =tree->evt;
    //aMCatNLO_weight = tree->GenWeight;
    genweight = tree->GenWeight; 
    //cout<<aMCatNLO_weight<<endl;
    tZTTGenDR=tree->tZTTGenDR;

    flag_BadChargedCandidate = tree->Flag_BadChargedCandidateFilter;
    flag_BadPFMuon = tree->Flag_BadPFMuonFilter;
    flag_EcalDeadCellTriggerPrimitive = tree->Flag_EcalDeadCellTriggerPrimitiveFilter;
    flag_HBHENoise = tree->Flag_HBHENoiseFilter;
    flag_HBHENoiseIso = tree->Flag_HBHENoiseIsoFilter;
    flag_badCloneMuon = tree->Flag_badCloneMuonFilter;
    flag_badGlobalMuon = tree->Flag_badGlobalMuonFilter;
    flag_eeBadSc = tree->Flag_eeBadScFilter;
    flag_globalTightHalo2016 = tree->Flag_globalTightHalo2016Filter;
    flag_goodVertices = tree->Flag_goodVertices;

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

    matchIsoMu22eta2p1_1=tree->mMatchesIsoMu22eta2p1Path;
    matchIsoTkMu22eta2p1_1=tree->mMatchesIsoTkMu22eta2p1Path;
    matchIsoMu22_1=tree->mMatchesIsoMu22Path;
    matchIsoTkMu22_1=tree->mMatchesIsoTkMu22Path;
    matchIsoMu24_1=tree->mMatchesIsoMu24Path;
    matchIsoTkMu24_1=tree->mMatchesIsoTkMu24Path;
    matchIsoMu19Tau20_1=tree->mMatchesMu19Tau20sL1Path;
    matchIsoMu21Tau20_1=tree->mMatchesMu21Tau20sL1Path;

    filterIsoMu22eta2p1_1=tree->mIsoMu22eta2p1Filter;
    filterIsoTkMu22eta2p1_1=tree->mIsoTkMu22eta2p1Filter;
    filterIsoMu22_1=tree->mIsoMu22Filter;
    filterIsoTkMu22_1=tree->mIsoTkMu22Filter;
    filterIsoMu24_1=tree->mIsoMu24Filter;
    filterIsoTkMu24_1=tree->mIsoTkMu24Filter;
    filterIsoMu19Tau20_1=tree->mMatchesMu19Tau20sL1Filter;
    filterIsoMu21Tau20_1=tree->mMatchesMu21Tau20sL1Filter;

    passIsoMu22eta2p1=tree->singleIsoMu22eta2p1Pass;
    passIsoTkMu22eta2p1=tree->singleIsoTkMu22eta2p1Pass;
    passIsoMu22=tree->singleIsoMu22Pass;
    passIsoTkMu22=tree->singleIsoTkMu22Pass;
    passIsoMu24=tree->singleIsoMu24Pass;
    passIsoTkMu24=tree->singleIsoTkMu24Pass;
    passIsoMu19Tau20=tree->singleMu19eta2p1LooseTau20singleL1Pass;
    passIsoMu21Tau20=tree->singleMu21eta2p1LooseTau20singleL1Pass;
   
    matchIsoMu19Tau20_2=tree->tMatchesMu19Tau20sL1Path;
    matchIsoMu21Tau20_2=tree->tMatchesMu21Tau20sL1Path;
    filterIsoMu19Tau20_2=tree->tMatchesMu19Tau20sL1Filter;
    filterIsoMu21Tau20_2=tree->tMatchesMu21Tau20sL1Filter;

    genpX=tree->genpX;
    genpY=tree->genpY;
    genpT=tree->genpT;
    genM=tree->genM;
    vispX=tree->vispX;
    vispY=tree->vispY;

    /*dphi_12=tree->m_t_DPhi;
    dphi_mumet=tree->mDPhiToPfMet_type1;
    dphi_taumet=tree->tDPhiToPfMet_type1;*/

    m_coll=tree->m_t_collinearmass;
    m_coll_uesU=tree->m_t_collinearmass_UnclusteredEnUp;
    m_coll_uesD=tree->m_t_collinearmass_UnclusteredEnDown;
    m_coll_jesU=tree->m_t_collinearmass_JetEnUp;
    m_coll_jesD=tree->m_t_collinearmass_JetEnDown;
    m_coll_tesU=tree->m_t_collinearmass_TauEnUp;
    m_coll_tesD=tree->m_t_collinearmass_TauEnDown;

    pt_top1=tree->topQuarkPt1;
    pt_top2=tree->topQuarkPt2;

    TLorentzVector tau1;
    TLorentzVector tau2;
    tau1.SetPtEtaPhiM(tree->mPt,tree->mEta,tree->mPhi,tree->mMass);
    tau2.SetPtEtaPhiM(tree->tPt,tree->tEta,tree->tPhi,tree->tMass);

    TLorentzVector mymet;
    mymet.SetPtEtaPhiM(tree->type1_pfMetEt,0,tree->type1_pfMetPhi,0);
    float pfmetcorr_ex=mymet.Px();
    float pfmetcorr_ey=mymet.Py();

    TLorentzVector mymet_UESUp;
    mymet_UESUp.SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_UnclusteredEnUp,0,tree->type1_pfMet_shiftedPhi_UnclusteredEnUp,0);
    float pfmetcorr_ex_UESUp=mymet_UESUp.Px();
    float pfmetcorr_ey_UESUp=mymet_UESUp.Py();

    TLorentzVector mymet_UESDown;
    mymet_UESDown.SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_UnclusteredEnDown,0,tree->type1_pfMet_shiftedPhi_UnclusteredEnDown,0);
    float pfmetcorr_ex_UESDown=mymet_UESDown.Px();
    float pfmetcorr_ey_UESDown=mymet_UESDown.Py();

    TLorentzVector mymet_JESDown;
    mymet_JESDown.SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetEnDown,0,tree->type1_pfMet_shiftedPhi_JetEnDown,0);
    float pfmetcorr_ex_JESDown=mymet_JESDown.Px();
    float pfmetcorr_ey_JESDown=mymet_JESDown.Py();

    TLorentzVector mymet_JESUp;
    mymet_JESUp.SetPtEtaPhiM(tree->type1_pfMet_shiftedPt_JetEnUp,0,tree->type1_pfMet_shiftedPhi_JetEnUp,0);
    float pfmetcorr_ex_JESUp=mymet_JESUp.Px();
    float pfmetcorr_ey_JESUp=mymet_JESUp.Py();
   
    if (recoil==1){
         recoilPFMetCorrector.CorrectByMeanResolution(
         mymet.Px(), // uncorrected type I pf met px (float)
         mymet.Py(), // uncorrected type I pf met py (float)
         tree->genpX, // generator Z/W/Higgs px (float)
         tree->genpY, // generator Z/W/Higgs py (float)
         tree->vispX, // generator visible Z/W/Higgs px (float)
         tree->vispY, // generator visible Z/W/Higgs py (float)
         tree->jetVeto30+1,  // number of jets (hadronic jet multiplicity) (int)
         pfmetcorr_ex, // corrected type I pf met px (float)
         pfmetcorr_ey  // corrected type I pf met py (float)
        );
    }
    if (recoil==2){
        recoilPFMetCorrector.CorrectByMeanResolution(
        mymet.Px(), // uncorrected type I pf met px (float)
        mymet.Py(), // uncorrected type I pf met py (float)
        tree->genpX, // generator Z/W/Higgs px (float)
        tree->genpY, // generator Z/W/Higgs py (float)
        tree->vispX, // generator visible Z/W/Higgs px (float)
        tree->vispY, // generator visible Z/W/Higgs py (float)
        tree->jetVeto30,  // number of jets (hadronic jet multiplicity) (int)
        pfmetcorr_ex, // corrected type I pf met px (float)
        pfmetcorr_ey  // corrected type I pf met py (float)
        );
    }

    if (recoil==1){
         recoilPFMetCorrector.CorrectByMeanResolution(
         mymet_JESUp.Px(), // uncorrected type I pf met px (float)
         mymet_JESUp.Py(), // uncorrected type I pf met py (float)
         tree->genpX, // generator Z/W/Higgs px (float)
         tree->genpY, // generator Z/W/Higgs py (float)
         tree->vispX, // generator visible Z/W/Higgs px (float)
         tree->vispY, // generator visible Z/W/Higgs py (float)
         tree->jetVeto30+1,  // number of jets (hadronic jet multiplicity) (int)
         pfmetcorr_ex_JESUp, // corrected type I pf met px (float)
         pfmetcorr_ey_JESUp  // corrected type I pf met py (float)
        );
    }
    if (recoil==2){
        recoilPFMetCorrector.CorrectByMeanResolution(
        mymet_JESUp.Px(), // uncorrected type I pf met px (float)
        mymet_JESUp.Py(), // uncorrected type I pf met py (float)
        tree->genpX, // generator Z/W/Higgs px (float)
        tree->genpY, // generator Z/W/Higgs py (float)
        tree->vispX, // generator visible Z/W/Higgs px (float)
        tree->vispY, // generator visible Z/W/Higgs py (float)
        tree->jetVeto30,  // number of jets (hadronic jet multiplicity) (int)
        pfmetcorr_ex_JESUp, // corrected type I pf met px (float)
        pfmetcorr_ey_JESUp  // corrected type I pf met py (float)
        );
    }

    if (recoil==1){
         recoilPFMetCorrector.CorrectByMeanResolution(
         mymet_UESUp.Px(), // uncorrected type I pf met px (float)
         mymet_UESUp.Py(), // uncorrected type I pf met py (float)
         tree->genpX, // generator Z/W/Higgs px (float)
         tree->genpY, // generator Z/W/Higgs py (float)
         tree->vispX, // generator visible Z/W/Higgs px (float)
         tree->vispY, // generator visible Z/W/Higgs py (float)
         tree->jetVeto30+1,  // number of jets (hadronic jet multiplicity) (int)
         pfmetcorr_ex_UESUp, // corrected type I pf met px (float)
         pfmetcorr_ey_UESUp  // corrected type I pf met py (float)
        );
    }
    if (recoil==2){
        recoilPFMetCorrector.CorrectByMeanResolution(
        mymet_UESUp.Px(), // uncorrected type I pf met px (float)
        mymet_UESUp.Py(), // uncorrected type I pf met py (float)
        tree->genpX, // generator Z/W/Higgs px (float)
        tree->genpY, // generator Z/W/Higgs py (float)
        tree->vispX, // generator visible Z/W/Higgs px (float)
        tree->vispY, // generator visible Z/W/Higgs py (float)
        tree->jetVeto30,  // number of jets (hadronic jet multiplicity) (int)
        pfmetcorr_ex_UESUp, // corrected type I pf met px (float)
        pfmetcorr_ey_UESUp  // corrected type I pf met py (float)
        );
    }

    if (recoil==1){
         recoilPFMetCorrector.CorrectByMeanResolution(
         mymet_JESDown.Px(), // uncorrected type I pf met px (float)
         mymet_JESDown.Py(), // uncorrected type I pf met py (float)
         tree->genpX, // generator Z/W/Higgs px (float)
         tree->genpY, // generator Z/W/Higgs py (float)
         tree->vispX, // generator visible Z/W/Higgs px (float)
         tree->vispY, // generator visible Z/W/Higgs py (float)
         tree->jetVeto30+1,  // number of jets (hadronic jet multiplicity) (int)
         pfmetcorr_ex_JESDown, // corrected type I pf met px (float)
         pfmetcorr_ey_JESDown  // corrected type I pf met py (float)
        );
    }
    if (recoil==2){
        recoilPFMetCorrector.CorrectByMeanResolution(
        mymet_JESDown.Px(), // uncorrected type I pf met px (float)
        mymet_JESDown.Py(), // uncorrected type I pf met py (float)
        tree->genpX, // generator Z/W/Higgs px (float)
        tree->genpY, // generator Z/W/Higgs py (float)
        tree->vispX, // generator visible Z/W/Higgs px (float)
        tree->vispY, // generator visible Z/W/Higgs py (float)
        tree->jetVeto30,  // number of jets (hadronic jet multiplicity) (int)
        pfmetcorr_ex_JESDown, // corrected type I pf met px (float)
        pfmetcorr_ey_JESDown  // corrected type I pf met py (float)
        );
    }

    if (recoil==1){
         recoilPFMetCorrector.CorrectByMeanResolution(
         mymet_UESDown.Px(), // uncorrected type I pf met px (float)
         mymet_UESDown.Py(), // uncorrected type I pf met py (float)
         tree->genpX, // generator Z/W/Higgs px (float)
         tree->genpY, // generator Z/W/Higgs py (float)
         tree->vispX, // generator visible Z/W/Higgs px (float)
         tree->vispY, // generator visible Z/W/Higgs py (float)
         tree->jetVeto30+1,  // number of jets (hadronic jet multiplicity) (int)
         pfmetcorr_ex_UESDown, // corrected type I pf met px (float)
         pfmetcorr_ey_UESDown  // corrected type I pf met py (float)
        );
    }
    if (recoil==2){
        recoilPFMetCorrector.CorrectByMeanResolution(
        mymet_UESDown.Px(), // uncorrected type I pf met px (float)
        mymet_UESDown.Py(), // uncorrected type I pf met py (float)
        tree->genpX, // generator Z/W/Higgs px (float)
        tree->genpY, // generator Z/W/Higgs py (float)
        tree->vispX, // generator visible Z/W/Higgs px (float)
        tree->vispY, // generator visible Z/W/Higgs py (float)
        tree->jetVeto30,  // number of jets (hadronic jet multiplicity) (int)
        pfmetcorr_ex_UESDown, // corrected type I pf met px (float)
        pfmetcorr_ey_UESDown  // corrected type I pf met py (float)
        );
    }

    mymet.SetPxPyPzE(pfmetcorr_ex,pfmetcorr_ey,0,sqrt(pfmetcorr_ex*pfmetcorr_ex+pfmetcorr_ey*pfmetcorr_ey));
    mymet_UESUp.SetPxPyPzE(pfmetcorr_ex_UESUp,pfmetcorr_ey_UESUp,0,sqrt(pfmetcorr_ex_UESUp*pfmetcorr_ex_UESUp+pfmetcorr_ey_UESUp*pfmetcorr_ey_UESUp));
    mymet_UESDown.SetPxPyPzE(pfmetcorr_ex_UESDown,pfmetcorr_ey_UESDown,0,sqrt(pfmetcorr_ex_UESDown*pfmetcorr_ex_UESDown+pfmetcorr_ey_UESDown*pfmetcorr_ey_UESDown));
    mymet_JESUp.SetPxPyPzE(pfmetcorr_ex_JESUp,pfmetcorr_ey_JESUp,0,sqrt(pfmetcorr_ex_JESUp*pfmetcorr_ex_JESUp+pfmetcorr_ey_JESUp*pfmetcorr_ey_JESUp));
    mymet_JESDown.SetPxPyPzE(pfmetcorr_ex_JESDown,pfmetcorr_ey_JESDown,0,sqrt(pfmetcorr_ex_JESDown*pfmetcorr_ex_JESDown+pfmetcorr_ey_JESDown*pfmetcorr_ey_JESDown));


    if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==0){
	mymet=mymet+tau2-0.982*tau2;
        mymet_JESUp=mymet_JESUp+tau2-0.982*tau2;
        mymet_JESDown=mymet_JESDown+tau2-0.982*tau2;
        mymet_UESUp=mymet_UESUp+tau2-0.982*tau2;
        mymet_UESDown=mymet_UESDown+tau2-0.982*tau2;
    }
    else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==1){
	mymet=mymet+tau2-1.010*tau2;
        mymet_JESUp=mymet_JESUp+tau2-1.010*tau2;
        mymet_JESDown=mymet_JESDown+tau2-1.010*tau2;
        mymet_UESUp=mymet_UESUp+tau2-1.010*tau2;
        mymet_UESDown=mymet_UESDown+tau2-1.010*tau2;
    }
    else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==10){ 
	mymet=mymet+tau2-1.004*tau2;
        mymet_JESUp=mymet_JESUp+tau2-1.004*tau2;
        mymet_JESDown=mymet_JESDown+tau2-1.004*tau2;
        mymet_UESUp=mymet_UESUp+tau2-1.004*tau2;
        mymet_UESDown=mymet_UESDown+tau2-1.004*tau2;
    }
    if (ismc && (tree->tZTTGenMatching==2 or tree->tZTTGenMatching==4) && tree->tDecayMode==0){ 
	mymet=mymet+tau2-0.998*tau2;
        mymet_JESUp=mymet_JESUp+tau2-0.998*tau2;
        mymet_JESDown=mymet_JESDown+tau2-0.998*tau2;
        mymet_UESUp=mymet_UESUp+tau2-0.998*tau2;
        mymet_UESDown=mymet_UESDown+tau2-0.998*tau2;
    }
    else if (ismc && (tree->tZTTGenMatching==2 or tree->tZTTGenMatching==4) && tree->tDecayMode==1){ 
	mymet=mymet+tau2-1.015*tau2;
        mymet_JESUp=mymet_JESUp+tau2-1.015*tau2;
        mymet_JESDown=mymet_JESDown+tau2-1.015*tau2;
        mymet_UESUp=mymet_UESUp+tau2-1.015*tau2;
        mymet_UESDown=mymet_UESDown+tau2-1.015*tau2;
    }
    if (ismc && (tree->tZTTGenMatching==1 or tree->tZTTGenMatching==3) && tree->tDecayMode==1){ 
	mymet=mymet+tau2-1.095*tau2;
        mymet_JESUp=mymet_JESUp+tau2-1.095*tau2;
        mymet_JESDown=mymet_JESDown+tau2-1.095*tau2;
        mymet_UESUp=mymet_UESUp+tau2-1.095*tau2;
        mymet_UESDown=mymet_UESDown+tau2-1.095*tau2;
    }

    met=mymet.Pt();
    metphi=mymet.Phi();
    met_px=mymet.Px();
    met_py=mymet.Py();

    if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==0) tau2=tau2*0.982;
    else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==1) tau2=tau2*1.010;
    else if (ismc && tree->tZTTGenMatching==5 && tree->tDecayMode==10) tau2=tau2*1.004;
    if (ismc && (tree->tZTTGenMatching==2 or tree->tZTTGenMatching==4) && tree->tDecayMode==0) tau2=tau2*0.998;
    else if (ismc && (tree->tZTTGenMatching==2 or tree->tZTTGenMatching==4) && tree->tDecayMode==1) tau2=tau2*1.015;
    if (ismc && (tree->tZTTGenMatching==1 or tree->tZTTGenMatching==3) && tree->tDecayMode==1) tau2=tau2*1.095;


    met_EESDown=tree->type1_pfMet_shiftedPt_ElectronEnDown;
    met_EESUp=tree->type1_pfMet_shiftedPt_ElectronEnUp;
    met_JESUp=mymet_JESUp.Pt();
    met_JESDown=mymet_JESDown.Pt();
    met_MESDown=tree->type1_pfMet_shiftedPt_MuonEnDown;
    met_MESUp=tree->type1_pfMet_shiftedPt_MuonEnUp;
    met_PESUp=tree->type1_pfMet_shiftedPt_PhotonEnUp;
    met_PESDown=tree->type1_pfMet_shiftedPt_PhotonEnDown;
    met_TESUp=tree->type1_pfMet_shiftedPt_TauEnUp;
    met_TESDown=tree->type1_pfMet_shiftedPt_TauEnDown;
    met_UESUp=mymet_UESUp.Pt();
    met_UESDown=mymet_UESDown.Pt();
    met_JERDown=tree->type1_pfMet_shiftedPt_JetResDown;
    met_JERUp=tree->type1_pfMet_shiftedPt_JetResUp;

    metphi_EESDown=tree->type1_pfMet_shiftedPhi_ElectronEnDown;
    metphi_EESUp=tree->type1_pfMet_shiftedPhi_ElectronEnUp;
    metphi_JESUp=mymet_JESUp.Phi();
    metphi_JESDown=mymet_JESDown.Phi();
    metphi_MESDown=tree->type1_pfMet_shiftedPhi_MuonEnDown;
    metphi_MESUp=tree->type1_pfMet_shiftedPhi_MuonEnUp;
    metphi_PESUp=tree->type1_pfMet_shiftedPhi_PhotonEnUp;
    metphi_PESDown=tree->type1_pfMet_shiftedPhi_PhotonEnDown;
    metphi_TESUp=tree->type1_pfMet_shiftedPhi_TauEnUp;
    metphi_TESDown=tree->type1_pfMet_shiftedPhi_TauEnDown;
    metphi_UESUp=mymet_UESUp.Phi();
    metphi_UESDown=mymet_UESDown.Phi();
    metphi_JERDown=tree->type1_pfMet_shiftedPhi_JetResDown;
    metphi_JERUp=tree->type1_pfMet_shiftedPhi_JetResUp;

    metSig=tree->metSig;
    metcov00=tree->metcov00;
    metcov01=tree->metcov01;
    metcov10=tree->metcov10;
    metcov11=tree->metcov11;

    metcov00_v2=tree->metcov00_DESYlike; 
    metcov01_v2=tree->metcov01_DESYlike; 
    metcov10_v2=tree->metcov10_DESYlike; 
    metcov11_v2=tree->metcov11_DESYlike; 

    /*mvaMet=tree->m_t_MvaMet;
    mvaMetcov00=tree->m_t_MvaMetCovMatrix00;
    mvaMetcov11=tree->m_t_MvaMetCovMatrix11;
    mvaMetcov10=tree->m_t_MvaMetCovMatrix10;
    mvaMetcov01=tree->m_t_MvaMetCovMatrix01;
    mvaMetphi=tree->m_t_MvaMetPhi;*/

    njets = tree->jetVeto30;
    nbtag = tree->bjetCISVVeto20Medium;
    njetspt20=tree->jetVeto20;

    njets_JESDown = tree->jetVeto30_JetEnDown;
    njetspt20_JESDown=tree->jetVeto20_JetEnDown;
    njets_JESUp = tree->jetVeto30_JetEnUp;
    njetspt20_JESUp=tree->jetVeto20_JetEnUp;

    gen_match_1=tree->mZTTGenMatching;
    gen_match_2=tree->tZTTGenMatching;
    pt_tt=tree->m_t_pt_tt;
    pzetavis=tree->m_t_PZetaVis;
    pzetamiss=tree->m_t_PZeta;

    extraelec_veto=(tree->eVetoZTTp001dxyzR0>0);
    extramuon_veto=(tree->muVetoZTTp001dxyzR0>1);
    dilepton_veto=(tree->dimuonVeto>0);
 
    m_vis=tree->m_t_Mass;

    l2_decayMode=tree->tDecayMode;

    m_1 = tau1.M();
    px_1 = tau1.Px();
    py_1 = tau1.Py();
    pz_1 = tau1.Pz();
    e_1 = tau1.E();
    pt_1 = tau1.Pt();
    phi_1 = tau1.Phi();
    eta_1 = tau1.Eta();
    mt_1 = tree->mMtToPfMet_type1;
    d0_1 = tree->mPVDXY;
    dZ_1 = tree->mPVDZ;
    id_m_loose_1 = tree->mPFIDLoose;
    id_m_medium_1 = tree->mPFIDMedium;
    bool goodglob=tree->mIsGlobal && tree->mNormalizedChi2 < 3 && tree->mChi2LocalPosition < 12 && tree->mTrkKink < 20;
    bool isMedium = tree->mPFIDLoose && tree->mValidFraction> 0.49 && tree->mSegmentCompatibility > (goodglob ? 0.303 : 0.451);
    id_m_medium2016_1=isMedium;
    id_m_tight_1 = tree->mPFIDTight;
    iso_1 = tree->mRelPFIsoDBDefaultR04;
    iso_1_v2 = tree->mRelPFIsoDBDefault;
    q_1 = tree->mCharge;
    matchIsoMu24_1 = tree->mIsoMu24Filter;
    matchIsoTkMu24_1 = tree->mIsoTkMu24Filter;

    m_2 = tau2.M();
    if (tree->tDecayMode==0) m_2=tree->tMass;

    px_2 = tau2.Px();
    py_2 = tau2.Py();
    pz_2 = tau2.Pz();
    e_2 = tau2.E();
    pt_2 = tau2.Pt();
    phi_2 = tau2.Phi();
    eta_2 = tau2.Eta();
    mt_2 = tree->tMtToPfMet_type1;
    dZ_2 = tree->tPVDZ;
    d0_2=tree->tPVDXY;
    iso_2=tree->tByIsolationMVArun2v1DBoldDMwLTraw;
    q_2 = tree->tCharge;
    trackpt_2=tree->tLeadTrackPt;
    charged_signalCone_2=tree->tNChrgHadrSignalCands;
    charged_isoCone_2=tree->tNChrgHadrIsolationCands;
    chargedIso_2=tree->tChargedIsoPtSum;
    neutralIso_2=tree->tNeutralIsoPtSum;
    puIso_2=tree->tPuCorrPtSum;
    photonIso_2=tree->tPhotonPtSumOutsideSignalCone;
    numGenJets=tree->numGenJets;
    jetPt_2=tree->tJetPt;


    againstMuonTight3_2 = tree->tAgainstMuonTight3;
    //againstMuonLoose3_2 = tree->tAgainstMuonLoose3;
    againstElectronVLooseMVA6_2 = tree->tAgainstElectronVLooseMVA6;
    //againstElectronLooseMVA6_2 = tree->tAgainstElectronLooseMVA6;
    //againstElectronMediumMVA6_2 = tree->tAgainstElectronMediumMVA6;
    //againstElectronTightMVA6_2 = tree->tAgainstElectronTightMVA6;
    //againstElectronVTightMVA6_2 = tree->tAgainstElectronVTightMVA6;
    //byLooseCombinedIsolationDeltaBetaCorr3Hits_2 = tree->tByLooseCombinedIsolationDeltaBetaCorr3Hits;
    //byMediumCombinedIsolationDeltaBetaCorr3Hits_2 = tree->tByMediumCombinedIsolationDeltaBetaCorr3Hits;
    //byTightCombinedIsolationDeltaBetaCorr3Hits_2 = tree->tByTightCombinedIsolationDeltaBetaCorr3Hits;
    //byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2 = tree->tByLooseCombinedIsolationDeltaBetaCorr3HitsdR03;
    //byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2 = tree->tByMediumCombinedIsolationDeltaBetaCorr3HitsdR03;
    //byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2 = tree->tByTightCombinedIsolationDeltaBetaCorr3HitsdR03;
    byVLooseIsolationMVArun2v1DBoldDMwLT_2 = tree->tByVLooseIsolationMVArun2v1DBoldDMwLT;
    byLooseIsolationMVArun2v1DBoldDMwLT_2 = tree->tByLooseIsolationMVArun2v1DBoldDMwLT;
    byMediumIsolationMVArun2v1DBoldDMwLT_2 = tree->tByMediumIsolationMVArun2v1DBoldDMwLT;
    byTightIsolationMVArun2v1DBoldDMwLT_2 = tree->tByTightIsolationMVArun2v1DBoldDMwLT;
    byVTightIsolationMVArun2v1DBoldDMwLT_2 = tree->tByVTightIsolationMVArun2v1DBoldDMwLT;
    byVVTightIsolationMVArun2v1DBoldDMwLT_2 = tree->tByVVTightIsolationMVArun2v1DBoldDMwLT;
    byCombinedIsolationDeltaBetaCorrRaw3Hits_2=tree->tByCombinedIsolationDeltaBetaCorrRaw3Hits;
    byIsolationMVA3oldDMwoLTraw_2=tree->tByIsolationMVArun2v1DBoldDMwLTraw;
    byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2 = tree->tRerunMVArun2v1DBoldDMwLTVLoose;
    byLooseIsolationRerunMVArun2v1DBoldDMwLT_2 = tree->tRerunMVArun2v1DBoldDMwLTLoose;
    byMediumIsolationRerunMVArun2v1DBoldDMwLT_2 = tree->tRerunMVArun2v1DBoldDMwLTMedium;
    byTightIsolationRerunMVArun2v1DBoldDMwLT_2 = tree->tRerunMVArun2v1DBoldDMwLTTight;
    byVTightIsolationRerunMVArun2v1DBoldDMwLT_2 = tree->tRerunMVArun2v1DBoldDMwLTVTight;
    byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2 = tree->tRerunMVArun2v1DBoldDMwLTVVTight;
    byIsolationRerunMVA3oldDMwLTraw_2=tree->tRerunMVArun2v1DBoldDMwLTraw;
    neutralIsoPtSum_2=tree->tNeutralIsoPtSum;
    chargedIsoPtSum_2=tree->tChargedIsoPtSum;
    puCorrPtSum_2=tree->tPuCorrPtSum;
    decayModeFinding_2=tree->tDecayModeFinding;
    decayModeFindingNewDMs_2=tree->tDecayModeFindingNewDMs;
    
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
   
  /*ptvis=h.Pt();

  float norm_zeta=norm_F(tau1.Px()/tau1.Pt()+tau2.Px()/tau2.Pt(),tau1.Py()/tau1.Pt()+tau2.Py()/tau2.Pt());
  float x_zeta= (tau1.Px()/tau1.Pt()+tau2.Px()/tau2.Pt())/norm_zeta;
  float y_zeta= (tau1.Py()/tau1.Pt()+tau2.Py()/tau2.Pt())/norm_zeta;
  pzetamiss=ETM.Px()*x_zeta+ETM.Py()*y_zeta;
  pzetavis=(tau1.Px()+tau2.Px())*x_zeta+(tau1.Py()+tau2.Py())*y_zeta;*/

   TLorentzVector h=tau1+tau2;
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
      hdijetphi=h.DeltaPhi(dijet);
      visjeteta=h.Eta()-dijet.Eta();
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
  //pt_tt=(tau1+tau2+ETM).Pt();
  npu=tree->nTruePU;
  npv=tree->nvtx;
  rho=tree->rho;

  extratau_veto=tree->tauVetoPt20Loose3HitsVtx;
  Run_Tree->Fill();
}

#endif


