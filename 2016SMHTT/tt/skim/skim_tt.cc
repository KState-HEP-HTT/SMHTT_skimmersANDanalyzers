#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TTree.h"
#include "TChain.h"
#include "TFile.h"
#include "TMath.h"
#include "TSystem.h"
#include "TRandom.h"
#include "TLorentzVector.h"
#include "TRandom3.h"
#include "makeHisto.h"
#include "tt_Tree.h"

int main(int argc, char** argv) { 

    using namespace std;
    myMap1 = new map<string, TH1F*>();
    myMap2 = new map<string, TH2F*>();
    string status_sample = *(argv + 1);
    bool isMC = false;
    bool isData = false;

    if (status_sample.compare("mc") == 0) isMC = true;
    if (status_sample.compare("data") == 0) isData = true;
    string out = *(argv + 2);
    string outname= out;
    TFile *fout = TFile::Open(outname.c_str(), "RECREATE");

    string in = *(argv + 3);
    string inname= in;
    TFile *fIn = TFile::Open(inname.c_str());

    int recoil(0);
    std::string recoilType("None");
    if (*(argv + 4) != NULL) {
      recoilType = *(argv + 4);
    }

    if (recoilType.find("W") != std::string::npos) {
      recoil = 1;
    } else if (recoilType.find("Z") != std::string::npos) {
      recoil = 2;
    }
    // Get tree and couple of other histograms
    TTree* treePtr = (TTree*) fIn->Get("tt/final/Ntuple");
    TH1F *evCounter = (TH1F*) fIn->Get("tt/eventCount");
    TH1F *evCounterW = (TH1F*) fIn->Get("tt/summedWeights");
    HTauTauTree_tt* tree = new HTauTauTree_tt (treePtr);  

    //Define new output tree and its variables
    TTree *Run_Tree = new TTree("tt_tree", "tt_tree");
    Run_Tree->SetDirectory(0);
    Run_Tree->Branch("run", &run);
    Run_Tree->Branch("lumi", &lumi);
    Run_Tree->Branch("evt", &evt);

    Run_Tree->Branch("npv", &npv);
    Run_Tree->Branch("npu", &npu);
    Run_Tree->Branch("NUP", &NUP);
    Run_Tree->Branch("amcatNLO_weight", &aMCatNLO_weight);
    Run_Tree->Branch("jetPt_1", &jetPt_1);
    Run_Tree->Branch("jetPt_2", &jetPt_2);
    Run_Tree->Branch("pt_1", &pt_1);
    Run_Tree->Branch("px_1", &px_1);
    Run_Tree->Branch("py_1", &py_1);
    Run_Tree->Branch("pz_1", &pz_1);
    Run_Tree->Branch("phi_1", &phi_1);
    Run_Tree->Branch("eta_1", &eta_1);
    Run_Tree->Branch("m_1", &m_1);
    Run_Tree->Branch("e_1", &e_1);
    Run_Tree->Branch("q_1", &q_1);
    Run_Tree->Branch("mt_1", &mt_1);
    Run_Tree->Branch("iso_1", &iso_1);
    Run_Tree->Branch("t1_decayMode", &t1_decayMode);
    Run_Tree->Branch("trackpt_1", &trackpt_1);

    Run_Tree->Branch("t1GenCharge",       &t1GenCharge);
    Run_Tree->Branch("t1GenDecayMode",    &t1GenDecayMode);
    Run_Tree->Branch("t1GenEnergy",       &t1GenEnergy);
    Run_Tree->Branch("t1GenEta",          &t1GenEta);
    Run_Tree->Branch("t1GenIsPrompt",     &t1GenIsPrompt);
    Run_Tree->Branch("t1GenJetEta",       &t1GenJetEta);
    Run_Tree->Branch("t1GenJetPt",        &t1GenJetPt);
    Run_Tree->Branch("t1GenMotherEnergy", &t1GenMotherEnergy);
    Run_Tree->Branch("t1GenMotherEta",    &t1GenMotherEta);
    Run_Tree->Branch("t1GenMotherPdgId",  &t1GenMotherPdgId);
    Run_Tree->Branch("t1GenMotherPhi",    &t1GenMotherPhi);
    Run_Tree->Branch("t1GenMotherPt",     &t1GenMotherPt);
    Run_Tree->Branch("t1GenPdgId",        &t1GenPdgId);
    Run_Tree->Branch("t1GenPhi",          &t1GenPhi);
    Run_Tree->Branch("t1GenPt",           &t1GenPt);
    Run_Tree->Branch("t1GenStatus",       &t1GenStatus);
    Run_Tree->Branch("t1ZTTGenDR",        &t1ZTTGenDR);
    Run_Tree->Branch("t1ZTTGenEta",       &t1ZTTGenEta);
    Run_Tree->Branch("t1ZTTGenPhi",       &t1ZTTGenPhi);
    Run_Tree->Branch("t1ZTTGenPt",        &t1ZTTGenPt);

    Run_Tree->Branch("t2GenCharge",       &t2GenCharge);
    Run_Tree->Branch("t2GenDecayMode",    &t2GenDecayMode);
    Run_Tree->Branch("t2GenEnergy",       &t2GenEnergy);
    Run_Tree->Branch("t2GenEta",          &t2GenEta);
    Run_Tree->Branch("t2GenIsPrompt",     &t2GenIsPrompt);
    Run_Tree->Branch("t2GenJetEta",       &t2GenJetEta);
    Run_Tree->Branch("t2GenJetPt",        &t2GenJetPt);
    Run_Tree->Branch("t2GenMotherEnergy", &t2GenMotherEnergy);
    Run_Tree->Branch("t2GenMotherEta",    &t2GenMotherEta);
    Run_Tree->Branch("t2GenMotherPdgId",  &t2GenMotherPdgId);
    Run_Tree->Branch("t2GenMotherPhi",    &t2GenMotherPhi);
    Run_Tree->Branch("t2GenMotherPt",     &t2GenMotherPt);
    Run_Tree->Branch("t2GenPdgId",        &t2GenPdgId);
    Run_Tree->Branch("t2GenPhi",          &t2GenPhi);
    Run_Tree->Branch("t2GenPt",           &t2GenPt);
    Run_Tree->Branch("t2GenStatus",       &t2GenStatus);
    Run_Tree->Branch("t2ZTTGenDR",        &t2ZTTGenDR);
    Run_Tree->Branch("t2ZTTGenEta",       &t2ZTTGenEta);
    Run_Tree->Branch("t2ZTTGenPhi",       &t2ZTTGenPhi);
    Run_Tree->Branch("t2ZTTGenPt",        &t2ZTTGenPt);

    Run_Tree->Branch("againstElectronLooseMVA6_1",  &againstElectronLooseMVA6_1);
    Run_Tree->Branch("againstElectronMediumMVA6_1", &againstElectronMediumMVA6_1);
    Run_Tree->Branch("againstElectronTightMVA6_1",  &againstElectronTightMVA6_1 );
    Run_Tree->Branch("againstElectronVLooseMVA6_1", &againstElectronVLooseMVA6_1);
    Run_Tree->Branch("againstElectronVTightMVA6_1", &againstElectronVTightMVA6_1);
    Run_Tree->Branch("againstMuonLoose3_1", &againstMuonLoose3_1);
    Run_Tree->Branch("againstMuonTight3_1", &againstMuonTight3_1);
    Run_Tree->Branch("byVLooseIsolationMVArun2v1DBoldDMwLT_1", &byVLooseIsolationMVArun2v1DBoldDMwLT_1);
    Run_Tree->Branch("byLooseIsolationMVArun2v1DBoldDMwLT_1" , &byLooseIsolationMVArun2v1DBoldDMwLT_1 );
    Run_Tree->Branch("byMediumIsolationMVArun2v1DBoldDMwLT_1", &byMediumIsolationMVArun2v1DBoldDMwLT_1);
    Run_Tree->Branch("byTightIsolationMVArun2v1DBoldDMwLT_1", &byTightIsolationMVArun2v1DBoldDMwLT_1);
    Run_Tree->Branch("byVTightIsolationMVArun2v1DBoldDMwLT_1", &byVTightIsolationMVArun2v1DBoldDMwLT_1);
    Run_Tree->Branch("byVVTightIsolationMVArun2v1DBoldDMwLT_1", &byVVTightIsolationMVArun2v1DBoldDMwLT_1);
    Run_Tree->Branch("byCombinedIsolationDeltaBetaCorrRaw3Hits_1", &byCombinedIsolationDeltaBetaCorrRaw3Hits_1);
    Run_Tree->Branch("byCombinedIsolationDeltaBetaCorrRaw3Hits_2", &byCombinedIsolationDeltaBetaCorrRaw3Hits_2);
    Run_Tree->Branch("byIsolationMVA3oldDMwoLTraw_1", &byIsolationMVA3oldDMwoLTraw_1);
    Run_Tree->Branch("byIsolationMVA3oldDMwoLTraw_2", &byIsolationMVA3oldDMwoLTraw_2);
    Run_Tree->Branch("pt_2", &pt_2);
    Run_Tree->Branch("px_2", &px_2);
    Run_Tree->Branch("py_2", &py_2);
    Run_Tree->Branch("pz_2", &pz_2);
    Run_Tree->Branch("phi_2", &phi_2);
    Run_Tree->Branch("eta_2", &eta_2);
    Run_Tree->Branch("m_2", &m_2);
    Run_Tree->Branch("e_2", &e_2);
    Run_Tree->Branch("q_2", &q_2);
    Run_Tree->Branch("iso_2", &iso_2);
    Run_Tree->Branch("t2_decayMode", &t2_decayMode);
    Run_Tree->Branch("trackpt_2", &trackpt_2);
    Run_Tree->Branch("againstElectronLooseMVA6_2", &againstElectronLooseMVA6_2  );
    Run_Tree->Branch("againstElectronMediumMVA6_2", &againstElectronMediumMVA6_2);
    Run_Tree->Branch("againstElectronTightMVA6_2", &againstElectronTightMVA6_2);
    Run_Tree->Branch("againstElectronVLooseMVA6_2", &againstElectronVLooseMVA6_2);
    Run_Tree->Branch("againstElectronVTightMVA6_2", &againstElectronVTightMVA6_2);
    Run_Tree->Branch("againstMuonLoose3_2", &againstMuonLoose3_2);
    Run_Tree->Branch("againstMuonTight3_2", &againstMuonTight3_2);
    Run_Tree->Branch("byVLooseIsolationMVArun2v1DBoldDMwLT_2", &byVLooseIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byLooseIsolationMVArun2v1DBoldDMwLT_2", &byLooseIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byMediumIsolationMVArun2v1DBoldDMwLT_2", &byMediumIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byTightIsolationMVArun2v1DBoldDMwLT_2", &byTightIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byVTightIsolationMVArun2v1DBoldDMwLT_2", &byVTightIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byVVTightIsolationMVArun2v1DBoldDMwLT_2", &byVVTightIsolationMVArun2v1DBoldDMwLT_2);

    Run_Tree->Branch("genpX", &genpX);
    Run_Tree->Branch("genpY", &genpY);
    Run_Tree->Branch("genpT", &genpT);
    Run_Tree->Branch("genM",  &genM);
    Run_Tree->Branch("vispX", &vispX);
    Run_Tree->Branch("vispY", &vispY);

    Run_Tree->Branch("genEta", &genEta);
    Run_Tree->Branch("genPhi", &genPhi);
    Run_Tree->Branch("genHTT", &genHTT);
    Run_Tree->Branch("genMass", &genMass);

    Run_Tree->Branch("numGenJets", &numGenJets);
    Run_Tree->Branch("pt_top1", &pt_top1);
    Run_Tree->Branch("pt_top2", &pt_top2);
    Run_Tree->Branch("genweight", &genweight);

    Run_Tree->Branch("met_JESDown", &met_JESDown);
    Run_Tree->Branch("met_UESDown", &met_UESDown);
    Run_Tree->Branch("met_JESUp", &met_JESUp);
    Run_Tree->Branch("met_UESUp", &met_UESUp);
    Run_Tree->Branch("metphi_JESDown", &metphi_JESDown);
    Run_Tree->Branch("metphi_TESDown", &metphi_TESDown);
    Run_Tree->Branch("metphi_UESDown", &metphi_UESDown);
    Run_Tree->Branch("metphi_JESUp", &metphi_JESUp);
    Run_Tree->Branch("metphi_UESUp", &metphi_UESUp);

    Run_Tree->Branch("met", &met);
    Run_Tree->Branch("metSig", &metSig);
    Run_Tree->Branch("metcov00", &metcov00);   
    Run_Tree->Branch("metcov10", &metcov10);
    Run_Tree->Branch("metcov11", &metcov11);
    Run_Tree->Branch("metcov01", &metcov01);
    Run_Tree->Branch("metcov00_v2", &metcov00_v2);
    Run_Tree->Branch("metcov10_v2", &metcov10_v2);
    Run_Tree->Branch("metcov11_v2", &metcov11_v2);
    Run_Tree->Branch("metcov01_v2", &metcov01_v2);
    Run_Tree->Branch("metphi", &metphi);
    Run_Tree->Branch("met_px", &met_px);
    Run_Tree->Branch("met_py", &met_py);
    Run_Tree->Branch("met_norecoil", &met_norecoil);


    Run_Tree->Branch("gen_match_1", &gen_match_1);
    Run_Tree->Branch("gen_match_2", &gen_match_2);

    Run_Tree->Branch("nbtag",  &nbtag);
    Run_Tree->Branch("nbtagL", &nbtagL);
    Run_Tree->Branch("extraelec_veto",    &extraelec_veto);
    Run_Tree->Branch("extramuon_veto",    &extramuon_veto);
    Run_Tree->Branch("njets",             &njets);
    Run_Tree->Branch("njetspt20",         &njetspt20);
    Run_Tree->Branch("njets_JESDown",     &njets_JESDown);
    Run_Tree->Branch("njetspt20_JESDown", &njetspt20_JESDown);
    Run_Tree->Branch("njets_JESUp",       &njets_JESUp);
    Run_Tree->Branch("njetspt20_JESUp",   &njetspt20_JESUp);
    Run_Tree->Branch("jpt_1",  &jpt_1);
    Run_Tree->Branch("jeta_1", &jeta_1);
    Run_Tree->Branch("jphi_1", &jphi_1);
    Run_Tree->Branch("jcsv_1", &jcsv_1);
    Run_Tree->Branch("jpt_1_JESUp",  &jpt_1_JESUp);
    Run_Tree->Branch("jpt_1_JESDown",  &jpt_1_JESDown);

    Run_Tree->Branch("jpt_2",  &jpt_2 );
    Run_Tree->Branch("jeta_2", &jeta_2);
    Run_Tree->Branch("jphi_2", &jphi_2);
    Run_Tree->Branch("jcsv_2", &jcsv_2);
    Run_Tree->Branch("jpt_2_JESUp",  &jpt_2_JESUp);
    Run_Tree->Branch("jpt_2_JESDown",  &jpt_2_JESDown);

    Run_Tree->Branch("bpt_1",  &bpt_1 );
    Run_Tree->Branch("beta_1", &beta_1);
    Run_Tree->Branch("bphi_1", &bphi_1);
    Run_Tree->Branch("bcsv_1", &bcsv_1);
    Run_Tree->Branch("bflavor_1", &bflavor_1);

    Run_Tree->Branch("bpt_2",  &bpt_2);
    Run_Tree->Branch("beta_2", &beta_2);
    Run_Tree->Branch("bphi_2", &bphi_2);
    Run_Tree->Branch("bcsv_2", &bcsv_2);
    Run_Tree->Branch("bflavor_2", &bflavor_2);

    Run_Tree->Branch("passDoubleTau35", &passDoubleTau35);
    Run_Tree->Branch("matchDoubleTau35_1", &matchDoubleTau35_1);
    Run_Tree->Branch("matchDoubleTau35_2", &matchDoubleTau35_2);
    Run_Tree->Branch("filterDoubleTau35_1", &filterDoubleTau35_1);
    Run_Tree->Branch("filterDoubleTau35_2", &filterDoubleTau35_2);
    Run_Tree->Branch("passDoubleTauCmbIso35", &passDoubleTauCmbIso35);
    Run_Tree->Branch("matchDoubleTauCmbIso35_1", &matchDoubleTauCmbIso35_1);
    Run_Tree->Branch("matchDoubleTauCmbIso35_2", &matchDoubleTauCmbIso35_2);
    Run_Tree->Branch("filterDoubleTauCmbIso35_1", &filterDoubleTauCmbIso35_1);
    Run_Tree->Branch("filterDoubleTauCmbIso35_2", &filterDoubleTauCmbIso35_2);

    Run_Tree->Branch("met_UESUp", &met_UESUp);
    Run_Tree->Branch("met_UESDown", &met_UESDown);
    Run_Tree->Branch("metphi_UESUp", &metphi_UESUp);
    Run_Tree->Branch("metphi_UESDown", &metphi_UESDown);
    Run_Tree->Branch("met_JESUp", &met_JESUp);
    Run_Tree->Branch("met_JESDown", &met_JESDown);
    Run_Tree->Branch("metphi_JESUp", &metphi_JESUp);
    Run_Tree->Branch("metphi_JESDown", &metphi_JESDown);

    Run_Tree->Branch("mjj", &mjj);
    Run_Tree->Branch("mjj_JESUp", &mjj_JESUp);
    Run_Tree->Branch("mjj_JESDown", &mjj_JESDown);
  
    if (isMC){
      Run_Tree->Branch("njets_JetAbsoluteFlavMapDown", &njets_JetAbsoluteFlavMapDown, "njets_JetAbsoluteFlavMapDown/I");
      Run_Tree->Branch("mjj_JetAbsoluteFlavMapDown", &mjj_JetAbsoluteFlavMapDown, "mjj_JetAbsoluteFlavMapDown/F");
      Run_Tree->Branch("njets_JetAbsoluteMPFBiasDown", &njets_JetAbsoluteMPFBiasDown, "njets_JetAbsoluteMPFBiasDown/I");
      Run_Tree->Branch("mjj_JetAbsoluteMPFBiasDown", &mjj_JetAbsoluteMPFBiasDown, "mjj_JetAbsoluteMPFBiasDown/F");
      Run_Tree->Branch("njets_JetAbsoluteScaleDown", &njets_JetAbsoluteScaleDown, "njets_JetAbsoluteScaleDown/I");
      Run_Tree->Branch("mjj_JetAbsoluteScaleDown", &mjj_JetAbsoluteScaleDown, "mjj_JetAbsoluteScaleDown/F");
      Run_Tree->Branch("njets_JetAbsoluteStatDown", &njets_JetAbsoluteStatDown, "njets_JetAbsoluteStatDown/I");
      Run_Tree->Branch("mjj_JetAbsoluteStatDown", &mjj_JetAbsoluteStatDown, "mjj_JetAbsoluteStatDown/F");
      Run_Tree->Branch("njets_JetEnDown", &njets_JetEnDown, "njets_JetEnDown/I");
      Run_Tree->Branch("mjj_JetEnDown", &mjj_JetEnDown, "mjj_JetEnDown/F");
      Run_Tree->Branch("njets_JetFlavorQCDDown", &njets_JetFlavorQCDDown, "njets_JetFlavorQCDDown/I");
      Run_Tree->Branch("mjj_JetFlavorQCDDown", &mjj_JetFlavorQCDDown, "mjj_JetFlavorQCDDown/F");
      Run_Tree->Branch("njets_JetFragmentationDown", &njets_JetFragmentationDown, "njets_JetFragmentationDown/I");
      Run_Tree->Branch("mjj_JetFragmentationDown", &mjj_JetFragmentationDown, "mjj_JetFragmentationDown/F");
      Run_Tree->Branch("njets_JetPileUpDataMCDown", &njets_JetPileUpDataMCDown, "njets_JetPileUpDataMCDown/I");
      Run_Tree->Branch("mjj_JetPileUpDataMCDown", &mjj_JetPileUpDataMCDown, "mjj_JetPileUpDataMCDown/F");
      Run_Tree->Branch("njets_JetPileUpPtBBDown", &njets_JetPileUpPtBBDown, "njets_JetPileUpPtBBDown/I");
      Run_Tree->Branch("mjj_JetPileUpPtBBDown", &mjj_JetPileUpPtBBDown, "mjj_JetPileUpPtBBDown/F");
      Run_Tree->Branch("njets_JetPileUpPtEC1Down", &njets_JetPileUpPtEC1Down, "njets_JetPileUpPtEC1Down/I");
      Run_Tree->Branch("mjj_JetPileUpPtEC1Down", &mjj_JetPileUpPtEC1Down, "mjj_JetPileUpPtEC1Down/F");
      Run_Tree->Branch("njets_JetPileUpPtEC2Down", &njets_JetPileUpPtEC2Down, "njets_JetPileUpPtEC2Down/I");
      Run_Tree->Branch("mjj_JetPileUpPtEC2Down", &mjj_JetPileUpPtEC2Down, "mjj_JetPileUpPtEC2Down/F");
      Run_Tree->Branch("njets_JetPileUpPtHFDown", &njets_JetPileUpPtHFDown, "njets_JetPileUpPtHFDown/I");
      Run_Tree->Branch("mjj_JetPileUpPtHFDown", &mjj_JetPileUpPtHFDown, "mjj_JetPileUpPtHFDown/F");
      Run_Tree->Branch("njets_JetPileUpPtRefDown", &njets_JetPileUpPtRefDown, "njets_JetPileUpPtRefDown/I");
      Run_Tree->Branch("mjj_JetPileUpPtRefDown", &mjj_JetPileUpPtRefDown, "mjj_JetPileUpPtRefDown/F");
      Run_Tree->Branch("njets_JetRelativeBalDown", &njets_JetRelativeBalDown, "njets_JetRelativeBalDown/I");
      Run_Tree->Branch("mjj_JetRelativeBalDown", &mjj_JetRelativeBalDown, "mjj_JetRelativeBalDown/F");
      Run_Tree->Branch("njets_JetRelativeFSRDown", &njets_JetRelativeFSRDown, "njets_JetRelativeFSRDown/I");
      Run_Tree->Branch("mjj_JetRelativeFSRDown", &mjj_JetRelativeFSRDown, "mjj_JetRelativeFSRDown/F");
      Run_Tree->Branch("njets_JetRelativeJEREC1Down", &njets_JetRelativeJEREC1Down, "njets_JetRelativeJEREC1Down/I");
      Run_Tree->Branch("mjj_JetRelativeJEREC1Down", &mjj_JetRelativeJEREC1Down, "mjj_JetRelativeJEREC1Down/F");
      Run_Tree->Branch("njets_JetRelativeJEREC2Down", &njets_JetRelativeJEREC2Down, "njets_JetRelativeJEREC2Down/I");
      Run_Tree->Branch("mjj_JetRelativeJEREC2Down", &mjj_JetRelativeJEREC2Down, "mjj_JetRelativeJEREC2Down/F");
      Run_Tree->Branch("njets_JetRelativeJERHFDown", &njets_JetRelativeJERHFDown, "njets_JetRelativeJERHFDown/I");
      Run_Tree->Branch("mjj_JetRelativeJERHFDown", &mjj_JetRelativeJERHFDown, "mjj_JetRelativeJERHFDown/F");
      Run_Tree->Branch("njets_JetRelativePtBBDown", &njets_JetRelativePtBBDown, "njets_JetRelativePtBBDown/I");
      Run_Tree->Branch("mjj_JetRelativePtBBDown", &mjj_JetRelativePtBBDown, "mjj_JetRelativePtBBDown/F");
      Run_Tree->Branch("njets_JetRelativePtEC1Down", &njets_JetRelativePtEC1Down, "njets_JetRelativePtEC1Down/I");
      Run_Tree->Branch("mjj_JetRelativePtEC1Down", &mjj_JetRelativePtEC1Down, "mjj_JetRelativePtEC1Down/F");
      Run_Tree->Branch("njets_JetRelativePtEC2Down", &njets_JetRelativePtEC2Down, "njets_JetRelativePtEC2Down/I");
      Run_Tree->Branch("mjj_JetRelativePtEC2Down", &mjj_JetRelativePtEC2Down, "mjj_JetRelativePtEC2Down/F");
      Run_Tree->Branch("njets_JetRelativePtHFDown", &njets_JetRelativePtHFDown, "njets_JetRelativePtHFDown/I");
      Run_Tree->Branch("mjj_JetRelativePtHFDown", &mjj_JetRelativePtHFDown, "mjj_JetRelativePtHFDown/F");
      Run_Tree->Branch("njets_JetRelativeStatECDown", &njets_JetRelativeStatECDown, "njets_JetRelativeStatECDown/I");
      Run_Tree->Branch("mjj_JetRelativeStatECDown", &mjj_JetRelativeStatECDown, "mjj_JetRelativeStatECDown/F");
      Run_Tree->Branch("njets_JetRelativeStatFSRDown", &njets_JetRelativeStatFSRDown, "njets_JetRelativeStatFSRDown/I");
      Run_Tree->Branch("mjj_JetRelativeStatFSRDown", &mjj_JetRelativeStatFSRDown, "mjj_JetRelativeStatFSRDown/F");
      Run_Tree->Branch("njets_JetRelativeStatHFDown", &njets_JetRelativeStatHFDown, "njets_JetRelativeStatHFDown/I");
      Run_Tree->Branch("mjj_JetRelativeStatHFDown", &mjj_JetRelativeStatHFDown, "mjj_JetRelativeStatHFDown/F");
      Run_Tree->Branch("njets_JetSinglePionECALDown", &njets_JetSinglePionECALDown, "njets_JetSinglePionECALDown/I");
      Run_Tree->Branch("mjj_JetSinglePionECALDown", &mjj_JetSinglePionECALDown, "mjj_JetSinglePionECALDown/F");
      Run_Tree->Branch("njets_JetSinglePionHCALDown", &njets_JetSinglePionHCALDown, "njets_JetSinglePionHCALDown/I");
      Run_Tree->Branch("mjj_JetSinglePionHCALDown", &mjj_JetSinglePionHCALDown, "mjj_JetSinglePionHCALDown/F");
      Run_Tree->Branch("njets_JetTimePtEtaDown", &njets_JetTimePtEtaDown, "njets_JetTimePtEtaDown/I");
      Run_Tree->Branch("mjj_JetTimePtEtaDown", &mjj_JetTimePtEtaDown, "mjj_JetTimePtEtaDown/F");

      Run_Tree->Branch("njets_JetAbsoluteFlavMapUp", &njets_JetAbsoluteFlavMapUp, "njets_JetAbsoluteFlavMapUp/I");
      Run_Tree->Branch("mjj_JetAbsoluteFlavMapUp", &mjj_JetAbsoluteFlavMapUp, "mjj_JetAbsoluteFlavMapUp/F");
      Run_Tree->Branch("njets_JetAbsoluteMPFBiasUp", &njets_JetAbsoluteMPFBiasUp, "njets_JetAbsoluteMPFBiasUp/I");
      Run_Tree->Branch("mjj_JetAbsoluteMPFBiasUp", &mjj_JetAbsoluteMPFBiasUp, "mjj_JetAbsoluteMPFBiasUp/F");
      Run_Tree->Branch("njets_JetAbsoluteScaleUp", &njets_JetAbsoluteScaleUp, "njets_JetAbsoluteScaleUp/I");
      Run_Tree->Branch("mjj_JetAbsoluteScaleUp", &mjj_JetAbsoluteScaleUp, "mjj_JetAbsoluteScaleUp/F");
      Run_Tree->Branch("njets_JetAbsoluteStatUp", &njets_JetAbsoluteStatUp, "njets_JetAbsoluteStatUp/I");
      Run_Tree->Branch("mjj_JetAbsoluteStatUp", &mjj_JetAbsoluteStatUp, "mjj_JetAbsoluteStatUp/F");
      Run_Tree->Branch("njets_JetEnUp", &njets_JetEnUp, "njets_JetEnUp/I");
      Run_Tree->Branch("mjj_JetEnUp", &mjj_JetEnUp, "mjj_JetEnUp/F");
      Run_Tree->Branch("njets_JetFlavorQCDUp", &njets_JetFlavorQCDUp, "njets_JetFlavorQCDUp/I");
      Run_Tree->Branch("mjj_JetFlavorQCDUp", &mjj_JetFlavorQCDUp, "mjj_JetFlavorQCDUp/F");
      Run_Tree->Branch("njets_JetFragmentationUp", &njets_JetFragmentationUp, "njets_JetFragmentationUp/I");
      Run_Tree->Branch("mjj_JetFragmentationUp", &mjj_JetFragmentationUp, "mjj_JetFragmentationUp/F");
      Run_Tree->Branch("njets_JetPileUpDataMCUp", &njets_JetPileUpDataMCUp, "njets_JetPileUpDataMCUp/I");
      Run_Tree->Branch("mjj_JetPileUpDataMCUp", &mjj_JetPileUpDataMCUp, "mjj_JetPileUpDataMCUp/F");
      Run_Tree->Branch("njets_JetPileUpPtBBUp", &njets_JetPileUpPtBBUp, "njets_JetPileUpPtBBUp/I");
      Run_Tree->Branch("mjj_JetPileUpPtBBUp", &mjj_JetPileUpPtBBUp, "mjj_JetPileUpPtBBUp/F");
      Run_Tree->Branch("njets_JetPileUpPtEC1Up", &njets_JetPileUpPtEC1Up, "njets_JetPileUpPtEC1Up/I");
      Run_Tree->Branch("mjj_JetPileUpPtEC1Up", &mjj_JetPileUpPtEC1Up, "mjj_JetPileUpPtEC1Up/F");
      Run_Tree->Branch("njets_JetPileUpPtEC2Up", &njets_JetPileUpPtEC2Up, "njets_JetPileUpPtEC2Up/I");
      Run_Tree->Branch("mjj_JetPileUpPtEC2Up", &mjj_JetPileUpPtEC2Up, "mjj_JetPileUpPtEC2Up/F");
      Run_Tree->Branch("njets_JetPileUpPtHFUp", &njets_JetPileUpPtHFUp, "njets_JetPileUpPtHFUp/I");
      Run_Tree->Branch("mjj_JetPileUpPtHFUp", &mjj_JetPileUpPtHFUp, "mjj_JetPileUpPtHFUp/F");
      Run_Tree->Branch("njets_JetPileUpPtRefUp", &njets_JetPileUpPtRefUp, "njets_JetPileUpPtRefUp/I");
      Run_Tree->Branch("mjj_JetPileUpPtRefUp", &mjj_JetPileUpPtRefUp, "mjj_JetPileUpPtRefUp/F");
      Run_Tree->Branch("njets_JetRelativeBalUp", &njets_JetRelativeBalUp, "njets_JetRelativeBalUp/I");
      Run_Tree->Branch("mjj_JetRelativeBalUp", &mjj_JetRelativeBalUp, "mjj_JetRelativeBalUp/F");
      Run_Tree->Branch("njets_JetRelativeFSRUp", &njets_JetRelativeFSRUp, "njets_JetRelativeFSRUp/I");

      Run_Tree->Branch("mjj_JetRelativeFSRUp", &mjj_JetRelativeFSRUp, "mjj_JetRelativeFSRUp/F");
      Run_Tree->Branch("njets_JetRelativeJEREC1Up", &njets_JetRelativeJEREC1Up, "njets_JetRelativeJEREC1Up/I");
      Run_Tree->Branch("mjj_JetRelativeJEREC1Up", &mjj_JetRelativeJEREC1Up, "mjj_JetRelativeJEREC1Up/F");
      Run_Tree->Branch("njets_JetRelativeJEREC2Up", &njets_JetRelativeJEREC2Up, "njets_JetRelativeJEREC2Up/I");
      Run_Tree->Branch("mjj_JetRelativeJEREC2Up", &mjj_JetRelativeJEREC2Up, "mjj_JetRelativeJEREC2Up/F");
      Run_Tree->Branch("njets_JetRelativeJERHFUp", &njets_JetRelativeJERHFUp, "njets_JetRelativeJERHFUp/I");
      Run_Tree->Branch("mjj_JetRelativeJERHFUp", &mjj_JetRelativeJERHFUp, "mjj_JetRelativeJERHFUp/F");
      Run_Tree->Branch("njets_JetRelativePtBBUp", &njets_JetRelativePtBBUp, "njets_JetRelativePtBBUp/I");
      Run_Tree->Branch("mjj_JetRelativePtBBUp", &mjj_JetRelativePtBBUp, "mjj_JetRelativePtBBUp/F");
      Run_Tree->Branch("njets_JetRelativePtEC1Up", &njets_JetRelativePtEC1Up, "njets_JetRelativePtEC1Up/I");
      Run_Tree->Branch("mjj_JetRelativePtEC1Up", &mjj_JetRelativePtEC1Up, "mjj_JetRelativePtEC1Up/F");
      Run_Tree->Branch("njets_JetRelativePtEC2Up", &njets_JetRelativePtEC2Up, "njets_JetRelativePtEC2Up/I");
      Run_Tree->Branch("mjj_JetRelativePtEC2Up", &mjj_JetRelativePtEC2Up, "mjj_JetRelativePtEC2Up/F");
      Run_Tree->Branch("njets_JetRelativePtHFUp", &njets_JetRelativePtHFUp, "njets_JetRelativePtHFUp/I");
      Run_Tree->Branch("mjj_JetRelativePtHFUp", &mjj_JetRelativePtHFUp, "mjj_JetRelativePtHFUp/F");
      Run_Tree->Branch("njets_JetRelativeStatECUp", &njets_JetRelativeStatECUp, "njets_JetRelativeStatECUp/I");
      Run_Tree->Branch("mjj_JetRelativeStatECUp", &mjj_JetRelativeStatECUp, "mjj_JetRelativeStatECUp/F");
      Run_Tree->Branch("njets_JetRelativeStatFSRUp", &njets_JetRelativeStatFSRUp, "njets_JetRelativeStatFSRUp/I");
      Run_Tree->Branch("mjj_JetRelativeStatFSRUp", &mjj_JetRelativeStatFSRUp, "mjj_JetRelativeStatFSRUp/F");
      Run_Tree->Branch("njets_JetRelativeStatHFUp", &njets_JetRelativeStatHFUp, "njets_JetRelativeStatHFUp/I");
      Run_Tree->Branch("mjj_JetRelativeStatHFUp", &mjj_JetRelativeStatHFUp, "mjj_JetRelativeStatHFUp/F");
      Run_Tree->Branch("njets_JetSinglePionECALUp", &njets_JetSinglePionECALUp, "njets_JetSinglePionECALUp/I");
      Run_Tree->Branch("mjj_JetSinglePionECALUp", &mjj_JetSinglePionECALUp, "mjj_JetSinglePionECALUp/F");
      Run_Tree->Branch("njets_JetSinglePionHCALUp", &njets_JetSinglePionHCALUp, "njets_JetSinglePionHCALUp/I");
      Run_Tree->Branch("mjj_JetSinglePionHCALUp", &mjj_JetSinglePionHCALUp, "mjj_JetSinglePionHCALUp/F");
      Run_Tree->Branch("njets_JetTimePtEtaUp", &njets_JetTimePtEtaUp, "njets_JetTimePtEtaUp/I");
      Run_Tree->Branch("mjj_JetTimePtEtaUp", &mjj_JetTimePtEtaUp, "mjj_JetTimePtEtaUp/F");
    }


     

    float lt_before=0;
    int bestEntry=-1;
    ULong64_t evt_now=0;
    ULong64_t evt_before=-1;
    bool print=false;
    plotFill("nevents",0,9,0,9,evCounter->GetBinContent(1)); //**
    plotFill("nevents",1,9,0,9,evCounterW->GetBinContent(1)); //**

    pair<float, float> tau1Candidate, tau2Candidate;

    for (int iEntry = 0; iEntry < tree->GetEntries() ; iEntry++)
    {
      // For tau pair forming algorithm
      pair<float, float> currentTau1Candidate, currentTau2Candidate;

      float pu=1.0;
      tree->GetEntry(iEntry);
      
      bool print=false;
      if (iEntry % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d ", iEntry);
      fflush(stdout);

      //DY : 4-momentums of final state objects, tt
      TLorentzVector tau1;
      TLorentzVector tau2;
      tau1.SetPtEtaPhiM(tree->t1Pt,tree->t1Eta,tree->t1Phi,tree->t1Mass);
      tau2.SetPtEtaPhiM(tree->t2Pt,tree->t2Eta,tree->t2Phi,tree->t2Mass);

      // Baseline selection https://www.dropbox.com/s/mb6e26affiodpn3/AN2016_355_v10.pdf?dl=0 page 44
      // line 769. No requirement on OS/SS @ skimming level
      if (tau1.DeltaR(tau2) < 0.5) continue;
      
      // loosen requirements  on  pT a bit for energy scale systematics  (by 5%)
      if (tau1.Pt() < 40./1.05 || fabs(tau1.Eta()) > 2.1 ) continue;
      if (tau2.Pt() < 40./1.05 || fabs(tau2.Eta()) > 2.1 ) continue;
      
      // require the highest pT tau to have pT > 50 (loosen requirements by 5%)
      if (tau1.Pt() < 50./1.05 && tau2.Pt() < 50./1.5 ) continue;

      // line 771
      if (!tree->t1DecayModeFinding) continue;
      if (!tree->t2DecayModeFinding) continue;

      if ( abs(tree->t1Charge) != 1 || abs(tree->t2Charge) != 1) continue;
      //  line 772
      if (fabs( tree->t1PVDZ ) > 0.2 || fabs( tree->t2PVDZ ) > 0.2) continue;
      //  lines 773-774
      
      if (tree->t1AgainstElectronVLooseMVA6 < 0.5 || tree->t1AgainstMuonLoose3 < 0.5) continue;
      if (tree->t2AgainstElectronVLooseMVA6 < 0.5 || tree->t2AgainstMuonLoose3 < 0.5) continue;
      
      bool isoAll =
	tree->t1ByVLooseIsolationMVArun2v1DBoldDMwLT > 0.5 &&
	tree->t2ByVLooseIsolationMVArun2v1DBoldDMwLT > 0.5;
      if (!isoAll ) continue;
      
      // Trigger follow https://github.com/truggles/Z_to_TauTau_13TeV/blob/MELA_test/analysisCuts.py#L23
      // tt35    = '((doubleTau35Pass > 0 && t1MatchesDoubleTau35Path > 0 && t2MatchesDoubleTau35Path > 0 && t1MatchesDoubleTau35Filter > 0 && t2MatchesDoubleTau35Filter > 0) || 
      //             (doubleTauCmbIso35RegPass > 0 && t1MatchesDoubleTauCmbIso35RegPath > 0 && t2MatchesDoubleTauCmbIso35RegPath > 0 && t1MatchesDoubleTauCmbIso35RegFilter > 0 && t2MatchesDoubleTauCmbIso35RegFilter > 0))'
      // Doyeong, this trigger requirement looks different in  your original code, do you  understand why?
      // MC & data_B, C, D, all the way to G (Table 14 page 44)
      bool tt35      = tree->doubleTau35Pass
	&& tree->t1MatchesDoubleTau35Filter && tree->t2MatchesDoubleTau35Filter
	&& tree->t1MatchesDoubleTau35Path   && tree->t2MatchesDoubleTau35Path;
      
      // only data_H
      bool tt35Combo = tree->doubleTauCmbIso35RegPass
	&&  tree->t1MatchesDoubleTauCmbIso35RegFilter  && tree->t2MatchesDoubleTauCmbIso35RegFilter
	&&  tree->t1MatchesDoubleTauCmbIso35RegPath    && tree->t2MatchesDoubleTauCmbIso35RegPath;

      // require either tt35 or tt35Combo to fire
      if ( !tt35 && !tt35Combo) continue;
      
      //  reject event if it has either an electron or a muon
      if ( tree->eVetoZTTp001dxyzR0>0 || tree->muVetoZTTp001dxyzR0>0 ) continue;

      evt_now=tree->evt;
      // implement new sorting per 
      // https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiggsToTauTauWorking2017#Baseline_Selection
      if ( evt_now!=evt_before) { // new event, save the tau candidates

      //   since it is new event, do we have the best entry to save? If yes, save it!
	if ( bestEntry > -1 )
	  // this is the code that actually saves branches etc.
	  fillTree(Run_Tree,tree,bestEntry,recoil,isMC);
	
	//  this is a new event, so the first tau pair is the best! :)
	bestEntry=iEntry;
	tau1Candidate  = make_pair(tree->t1Pt,  tree->t1ByIsolationMVArun2v1DBoldDMwLTraw);
	tau2Candidate  = make_pair(tree->t2Pt,  tree->t2ByIsolationMVArun2v1DBoldDMwLTraw);
	// check if currentTau1 is most isolated
	if ( tree->t1ByIsolationMVArun2v1DBoldDMwLTraw < tree->t2ByIsolationMVArun2v1DBoldDMwLTraw ) {
	  tau1Candidate  = make_pair(tree->t2Pt,  tree->t2ByIsolationMVArun2v1DBoldDMwLTraw);
	  tau2Candidate  = make_pair(tree->t1Pt,  tree->t1ByIsolationMVArun2v1DBoldDMwLTraw);
	}
      } else { // not a new event
	// comparison between previous tau pair and the new one takes place here!
	currentTau1Candidate = make_pair(tree->t1Pt,  tree->t1ByIsolationMVArun2v1DBoldDMwLTraw);
	currentTau2Candidate = make_pair(tree->t2Pt,  tree->t2ByIsolationMVArun2v1DBoldDMwLTraw);
	if ( tree->t1ByIsolationMVArun2v1DBoldDMwLTraw < tree->t2ByIsolationMVArun2v1DBoldDMwLTraw ) {
	  currentTau1Candidate  = make_pair(tree->t2Pt,  tree->t2ByIsolationMVArun2v1DBoldDMwLTraw);
	  currentTau2Candidate  = make_pair(tree->t1Pt,  tree->t1ByIsolationMVArun2v1DBoldDMwLTraw);
	}
	
	// clause 1, select the pair that has most isolated tau lepton 1
	if (currentTau1Candidate.second - tau1Candidate.second  > 0.0001 ) bestEntry=iEntry;
	// check if the first tau is the same, and if so - move to clause 2
	if ( fabs(currentTau1Candidate.second - tau1Candidate.second)  <  0.0001 ) {
	  // pick up  the pair with the highest pT of the first candidate
	  if (currentTau1Candidate.first - tau1Candidate.first > 0.0001 ) bestEntry=iEntry;
	  if ( fabs(currentTau1Candidate.first -tau1Candidate.first) < 0.0001 ) { 
	    // same pT, same iso, move to clause 3
	    if (currentTau2Candidate.second - tau2Candidate.second > 0.0001 ) bestEntry=iEntry;
	    if ( fabs(currentTau2Candidate.second - tau2Candidate.second) < 0.0001 ) {
	      // same iso - pick the pair with the highest pT
	      if ( currentTau2Candidate.first - tau2Candidate.first  > 0.0001 ) bestEntry=iEntry;
	    } // tau2 has the same isolation
	    
	  } // tau1 has the same pT
	  
	} // tau1 has the same isolation
	
      } // not a new event
      evt_before=evt_now;
    }
    
    // save the best pair from the last event
    if (bestEntry>-1)
      fillTree(Run_Tree,tree,bestEntry,recoil,isMC);
    
    // done!
    fout->cd();
    Run_Tree->Write();
    map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
    map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
    for (; iMap1 != jMap1; ++iMap1)
      nplot1(iMap1->first)->Write();
    map<string, TH2F*>::const_iterator iMap2 = myMap2->begin();
    map<string, TH2F*>::const_iterator jMap2 = myMap2->end();
    for (; iMap2 != jMap2; ++iMap2)
      nplot2(iMap2->first)->Write();
    
    fout->Close();
    return 0;
}
