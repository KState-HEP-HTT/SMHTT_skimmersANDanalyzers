////////////////////////////////////////////////////////////////////////////////////////////////
//  https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiggsToTauTauWorking2017#tautau%20checklist  //
////////////////////////////////////////////////////////////////////////////////////////////////
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
//#include "HTT-utilities/RecoilCorrections/interface/RecoilCorrector.h"
#include "json.hpp"

int main(int argc, char** argv) { 
    using namespace std;
    myMap1 = new map<string, TH1F*>();
    myMap2 = new map<string, TH2F*>();
    string status_sample = *(argv + 1);
    bool isMC = false;
    bool isData = false;
    bool isEmbed = false;
    if (status_sample.compare("mc") == 0) isMC = true;
    if (status_sample.compare("data") == 0) isData = true;
    if (status_sample.compare("embed") == 0) isEmbed = true;
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

    bool seventeen = false;
    if (17 == atof(argv[5])) seventeen = true;

    // open the JSON file
    using json = nlohmann::json;
    std::ifstream ntupleMap("fileMap.json");
    json j;

    // Get tree and couple of other histograms
    TTree* treePtr = (TTree*) fIn->Get("tt/final/Ntuple");
    TH1F *evCounter = (TH1F*) fIn->Get("tt/eventCount");
    TH1F *evCounterW = (TH1F*) fIn->Get("tt/summedWeights");
    HTauTauTree_tt* tree = new HTauTauTree_tt (treePtr);  

    //Define new output tree and its variables
    TTree *Run_Tree = new TTree("tt_tree", "tt_tree");
    Run_Tree->SetDirectory(0);
    // Event ID variables
    Run_Tree->Branch("run", &run);
    Run_Tree->Branch("lumi", &lumi);
    Run_Tree->Branch("evt", &evt);
    // Extra lepton vetos
    Run_Tree->Branch("extraelec_veto",    &extraelec_veto);
    Run_Tree->Branch("extramuon_veto",    &extramuon_veto);
    Run_Tree->Branch("dilepton_veto",     &dilepton_veto);
    // Trigger flags
    Run_Tree->Branch("trg_doubletau",     &trg_doubletau);
    // Filter flags
    Run_Tree->Branch("Flag_goodVertices", &Flag_goodVertices );
    Run_Tree->Branch("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter );
    Run_Tree->Branch("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter );
    Run_Tree->Branch("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter );
    Run_Tree->Branch("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter );
    Run_Tree->Branch("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter );
    Run_Tree->Branch("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter );
    Run_Tree->Branch("Flag_eeBadScFilter", &Flag_eeBadScFilter );
    Run_Tree->Branch("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter );
    // Leg 1
    Run_Tree->Branch("pt_1", &pt_1);
    Run_Tree->Branch("phi_1", &phi_1);
    Run_Tree->Branch("eta_1", &eta_1);
    Run_Tree->Branch("m_1", &m_1);
    Run_Tree->Branch("q_1", &q_1);
    Run_Tree->Branch("d0_1", &d0_1);
    Run_Tree->Branch("dZ_1", &dZ_1);
    Run_Tree->Branch("mt_1", &mt_1);
    Run_Tree->Branch("pfmt_1", &pfmt_1);
    Run_Tree->Branch("puppimt_1", &puppimt_1);
    Run_Tree->Branch("iso_1", &iso_1);
    Run_Tree->Branch("gen_match_1", &gen_match_1);
    Run_Tree->Branch("againstElectronLooseMVA6_1",  &againstElectronLooseMVA6_1);
    Run_Tree->Branch("againstElectronMediumMVA6_1", &againstElectronMediumMVA6_1);
    Run_Tree->Branch("againstElectronTightMVA6_1",  &againstElectronTightMVA6_1 );
    Run_Tree->Branch("againstElectronVLooseMVA6_1", &againstElectronVLooseMVA6_1);
    Run_Tree->Branch("againstElectronVTightMVA6_1", &againstElectronVTightMVA6_1);
    Run_Tree->Branch("againstMuonLoose3_1", &againstMuonLoose3_1);
    Run_Tree->Branch("againstMuonTight3_1", &againstMuonTight3_1);
    Run_Tree->Branch("trigweight_1", &trigweight_1);
    Run_Tree->Branch("idisoweight_1", &idisoweight_1);
    // Leg 2
    Run_Tree->Branch("pt_2", &pt_2);
    Run_Tree->Branch("phi_2", &phi_2);
    Run_Tree->Branch("eta_2", &eta_2);
    Run_Tree->Branch("m_2", &m_2);
    Run_Tree->Branch("q_2", &q_2);
    Run_Tree->Branch("d0_2", &d0_2);
    Run_Tree->Branch("dZ_2", &dZ_2);
    Run_Tree->Branch("mt_2", &mt_2);
    Run_Tree->Branch("pfmt_2", &pfmt_2);
    Run_Tree->Branch("puppimt_2", &puppimt_2);
    Run_Tree->Branch("iso_2", &iso_2);
    Run_Tree->Branch("gen_match_2", &gen_match_2);
    Run_Tree->Branch("againstElectronLooseMVA6_2",  &againstElectronLooseMVA6_2);
    Run_Tree->Branch("againstElectronMediumMVA6_2", &againstElectronMediumMVA6_2);
    Run_Tree->Branch("againstElectronTightMVA6_2",  &againstElectronTightMVA6_2);
    Run_Tree->Branch("againstElectronVLooseMVA6_2", &againstElectronVLooseMVA6_2);
    Run_Tree->Branch("againstElectronVTightMVA6_2", &againstElectronVTightMVA6_2);
    Run_Tree->Branch("againstMuonLoose3_2", &againstMuonLoose3_2);
    Run_Tree->Branch("againstMuonTight3_2", &againstMuonTight3_2);
    Run_Tree->Branch("trigweight_2", &trigweight_2);
    Run_Tree->Branch("idisoweight_2", &idisoweight_2);
    // di-tau system
    Run_Tree->Branch("pt_tt", &pt_tt);
    Run_Tree->Branch("m_vis", &m_vis);
    Run_Tree->Branch("m_sv",&m_sv);
    Run_Tree->Branch("mt_sv",&mt_sv);
    // MET
    Run_Tree->Branch("met", &met);
    Run_Tree->Branch("metphi", &metphi);
    Run_Tree->Branch("puppimet",&puppimet);
    Run_Tree->Branch("puppimetphi",&puppimetphi);
    Run_Tree->Branch("pzetavis",&pzetavis);
    Run_Tree->Branch("pzetamiss",&pzetamiss);
    Run_Tree->Branch("pfpzetamiss",&pfpzetamiss);
    Run_Tree->Branch("puppipzetamiss",&puppipzetamiss);
    Run_Tree->Branch("metcov00", &metcov00);   
    Run_Tree->Branch("metcov10", &metcov10);
    Run_Tree->Branch("metcov11", &metcov11);
    Run_Tree->Branch("metcov01", &metcov01);
    Run_Tree->Branch("metcov00_v2", &metcov00_v2);
    Run_Tree->Branch("metcov10_v2", &metcov10_v2);
    Run_Tree->Branch("metcov11_v2", &metcov11_v2);
    Run_Tree->Branch("metcov01_v2", &metcov01_v2);
    // VBF system
    Run_Tree->Branch("mjj", &mjj);
    Run_Tree->Branch("jdeta",&jdeta);
    Run_Tree->Branch("njetingap",&njetingap);
    Run_Tree->Branch("njetingap",&njetingap20);
    Run_Tree->Branch("jdphi",&jdphi);
    Run_Tree->Branch("dijetpt",&dijetpt);
    Run_Tree->Branch("dijetphi",&dijetphi);
    Run_Tree->Branch("ptvis",&ptvis);
    // additional jets
    Run_Tree->Branch("nbtag",  &nbtag);
    Run_Tree->Branch("njets",             &njets);
    Run_Tree->Branch("njetspt20",         &njetspt20);
    Run_Tree->Branch("jpt_1",  &jpt_1);
    Run_Tree->Branch("jeta_1", &jeta_1);
    Run_Tree->Branch("jphi_1", &jphi_1);
    Run_Tree->Branch("jcsv_1", &jcsv_1);
    Run_Tree->Branch("jpt_2",  &jpt_2 );
    Run_Tree->Branch("jeta_2", &jeta_2);
    Run_Tree->Branch("jphi_2", &jphi_2);
    Run_Tree->Branch("jcsv_2", &jcsv_2);

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
    Run_Tree->Branch("puweight",&puweight);
    /*
    // Leave the following out for now
    Run_Tree->Branch("NUP", &NUP);
    Run_Tree->Branch("",&);

    Run_Tree->Branch("npv", &npv);
    Run_Tree->Branch("npu", &npu);

    //Run_Tree->Branch("amcatNLO_weight", &aMCatNLO_weight);
    Run_Tree->Branch("genweight", &genweight);
    Run_Tree->Branch("jetPt_1", &jetPt_1);
    Run_Tree->Branch("jetPt_2", &jetPt_2);


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



    Run_Tree->Branch("pt_2", &pt_2);
    Run_Tree->Branch("phi_2", &phi_2);
    Run_Tree->Branch("eta_2", &eta_2);
    Run_Tree->Branch("m_2", &m_2);
    Run_Tree->Branch("e_2", &e_2);
    Run_Tree->Branch("q_2", &q_2);
    Run_Tree->Branch("iso_2_old", &iso_2_old);
    Run_Tree->Branch("iso_2_new", &iso_2_new);
    Run_Tree->Branch("t2_decayMode", &t2_decayMode);
    Run_Tree->Branch("trackpt_2", &trackpt_2);
    Run_Tree->Branch("againstElectronLooseMVA6_2", &againstElectronLooseMVA6_2  );
    Run_Tree->Branch("againstElectronMediumMVA6_2", &againstElectronMediumMVA6_2);
    Run_Tree->Branch("againstElectronTightMVA6_2", &againstElectronTightMVA6_2);
    Run_Tree->Branch("againstElectronVLooseMVA6_2", &againstElectronVLooseMVA6_2);
    Run_Tree->Branch("againstElectronVTightMVA6_2", &againstElectronVTightMVA6_2);
    Run_Tree->Branch("againstMuonLoose3_2", &againstMuonLoose3_2);
    Run_Tree->Branch("againstMuonTight3_2", &againstMuonTight3_2);
    ////////////////////////////    
    /// Rerun run2 v2 (2017) ///
    ////////////////////////////
    Run_Tree->Branch("t1RerunMVArun2v2DBoldDMwLTVLoose", &t1RerunMVArun2v2DBoldDMwLTVLoose);
    Run_Tree->Branch("t1RerunMVArun2v2DBoldDMwLTVLoose", &t1RerunMVArun2v2DBoldDMwLTLoose);
    Run_Tree->Branch("t1RerunMVArun2v2DBoldDMwLTMedium", &t1RerunMVArun2v2DBoldDMwLTMedium);
    Run_Tree->Branch("t1RerunMVArun2v2DBoldDMwLTTight", &t1RerunMVArun2v2DBoldDMwLTTight);
    Run_Tree->Branch("t1RerunMVArun2v2DBoldDMwLTVTight", &t1RerunMVArun2v2DBoldDMwLTVTight);
    Run_Tree->Branch("t1RerunMVArun2v2DBoldDMwLTVVTight", &t1RerunMVArun2v2DBoldDMwLTVVTight);
    Run_Tree->Branch("t1RerunMVArun2v2DBoldDMwLTraw", &t1RerunMVArun2v2DBoldDMwLTraw);

    Run_Tree->Branch("t2RerunMVArun2v2DBoldDMwLTVLoose", &t2RerunMVArun2v2DBoldDMwLTVLoose);
    Run_Tree->Branch("t2RerunMVArun2v2DBoldDMwLTVLoose", &t2RerunMVArun2v2DBoldDMwLTLoose);
    Run_Tree->Branch("t2RerunMVArun2v2DBoldDMwLTVMedium", &t2RerunMVArun2v2DBoldDMwLTMedium);
    Run_Tree->Branch("t2RerunMVArun2v2DBoldDMwLTTight", &t2RerunMVArun2v2DBoldDMwLTTight);
    Run_Tree->Branch("t2RerunMVArun2v2DBoldDMwLTVTight", &t2RerunMVArun2v2DBoldDMwLTVTight);
    Run_Tree->Branch("t2RerunMVArun2v2DBoldDMwLTVVTight", &t2RerunMVArun2v2DBoldDMwLTVVTight);
    Run_Tree->Branch("t2RerunMVArun2v2DBoldDMwLTraw", &t2RerunMVArun2v2DBoldDMwLTraw);

    Run_Tree->Branch("genpX", &genpX);
    Run_Tree->Branch("genpY", &genpY);
    Run_Tree->Branch("genpT", &genpT);
    Run_Tree->Branch("genM",  &genM);
    Run_Tree->Branch("vispX", &vispX);
    Run_Tree->Branch("vispY", &vispY);

    Run_Tree->Branch("numGenJets", &numGenJets);
    Run_Tree->Branch("pt_top1", &pt_top1);
    Run_Tree->Branch("pt_top2", &pt_top2);


    Run_Tree->Branch("metSig", &metSig);

    Run_Tree->Branch("met_px", &met_px);
    Run_Tree->Branch("met_py", &met_py);
    Run_Tree->Branch("met_norecoil", &met_norecoil);

    */



    if (seventeen) {
      // https://github.com/truggles/TauTriggerSFs2017/tree/tauTriggers2017_reMiniaod_test
      Run_Tree->Branch("t1MatchesDoubleTightTau35Path", &t1MatchesDoubleTightTau35Path);
      Run_Tree->Branch("t1MatchesDoubleTightTau35Filter", &t1MatchesDoubleTightTau35Filter);
      Run_Tree->Branch("t1MatchesDoubleMediumTau40Path", &t1MatchesDoubleMediumTau40Path);
      Run_Tree->Branch("t1MatchesDoubleMediumTau40Filter", &t1MatchesDoubleMediumTau40Filter );
      Run_Tree->Branch("t1MatchesDoubleTightTau40Path", &t1MatchesDoubleTightTau40Path);
      Run_Tree->Branch("t1MatchesDoubleTightTau40Filter", &t1MatchesDoubleTightTau40Filter);

      Run_Tree->Branch("t2MatchesDoubleTightTau35Path", &t2MatchesDoubleTightTau35Path);
      Run_Tree->Branch("t2MatchesDoubleTightTau35Filter", &t2MatchesDoubleTightTau35Filter);
      Run_Tree->Branch("t2MatchesDoubleMediumTau40Path", &t2MatchesDoubleMediumTau40Path);
      Run_Tree->Branch("t2MatchesDoubleMediumTau40Filter", &t2MatchesDoubleMediumTau40Filter );
      Run_Tree->Branch("t2MatchesDoubleTightTau40Path", &t2MatchesDoubleTightTau40Path);
      Run_Tree->Branch("t2MatchesDoubleTightTau40Filter", &t2MatchesDoubleTightTau40Filter);
      
      Run_Tree->Branch("DoubleTightTau35Pass", &DoubleTightTau35Pass);
      Run_Tree->Branch("DoubleMediumTau40Pass", &DoubleMediumTau40Pass);
      Run_Tree->Branch("DoubleTightTau40Pass", &DoubleTightTau40Pass);
    }
    else {
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
    }





    Run_Tree->Branch("met_JESDown", &met_JESDown);
    Run_Tree->Branch("met_UESDown", &met_UESDown);
    Run_Tree->Branch("met_JESUp", &met_JESUp);
    Run_Tree->Branch("met_UESUp", &met_UESUp);
    Run_Tree->Branch("metphi_JESDown", &metphi_JESDown);
    Run_Tree->Branch("metphi_TESDown", &metphi_TESDown);
    Run_Tree->Branch("metphi_UESDown", &metphi_UESDown);
    Run_Tree->Branch("metphi_JESUp", &metphi_JESUp);
    Run_Tree->Branch("metphi_UESUp", &metphi_UESUp);     

    TH1F *h_cutflow = new TH1F("","",15,0,15);

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
      h_cutflow->Fill(0.0,1.0);
      // line 769. No requirement on OS/SS @ skimming level
      if (tau1.DeltaR(tau2) < 0.5) continue;
      h_cutflow->Fill(1.0,1.0);
      // loosen requirements  on  pT a bit for energy scale systematics  (by 5%)
      if (tau1.Pt() < 40 || fabs(tau1.Eta()) > 2.1 ) continue;
      if (tau2.Pt() < 40 || fabs(tau2.Eta()) > 2.1 ) continue;
      h_cutflow->Fill(2.0,1.0);
      // line 771
      if (!tree->t1DecayModeFinding) continue;
      if (!tree->t2DecayModeFinding) continue;
      //if (!tree->t1DecayModeFindingNewDMs) continue; // For QCD control region study Doyeong tDecayModeFinding replaced to 
      //if (!tree->t2DecayModeFindingNewDMs) continue; // For QCD control region study Doyeong tDecayModeFinding replaced to 
      h_cutflow->Fill(3.0,1.0);
      if ( abs(tree->t1Charge) != 1 || abs(tree->t2Charge) != 1) continue;
      if (fabs( tree->t1PVDZ ) > 0.2 || fabs( tree->t2PVDZ ) > 0.2) continue;
      h_cutflow->Fill(4.0,1.0);
      // MET and muon filters
      //Flag_goodVertices, Flag_globalSuperTightHalo2016Filter, Flag_HBHENoiseFilter, Flag_HBHENoiseIsoFilter, Flag_EcalDeadCellTriggerPrimitiveFilter, Flag_BadPFMuonFilter, Flag_BadChargedCandidateFilter, Flag_eeBadScFilter (only in data), Flag_ecalBadCalibFilter

      //  lines 773-774
      h_cutflow->Fill(5.0,1.0);      
      //if (tree->t1AgainstElectronVLooseMVA6 < 0.5 || tree->t1AgainstMuonLoose3 < 0.5) continue;
      //if (tree->t2AgainstElectronVLooseMVA6 < 0.5 || tree->t2AgainstMuonLoose3 < 0.5) continue;
      h_cutflow->Fill(6.0,1.0);
      bool isoAll = tree->t1RerunMVArun2v2DBoldDMwLTVVLoose > 0.5 && tree->t2RerunMVArun2v2DBoldDMwLTVVLoose > 0.5;
	//tree->t1ByVLooseIsolationMVArun2v1DBoldDMwLT > 0.5 &&
	//tree->t2ByVLooseIsolationMVArun2v1DBoldDMwLT > 0.5;
      if (!isoAll ) continue; // For QCD control region study Doyeong commented out this.
      
      h_cutflow->Fill(7.0,1.0);
      h_cutflow->Fill(11.0,1.0);
      //  reject event if it has either an electron or a muon
      //if ( tree->eVetoZTTp001dxyzR0>0 || tree->muVetoZTTp001dxyzR0>0 ) continue;
      h_cutflow->Fill(12.0,1.0);
      evt_now=tree->evt;
      // implement new sorting per 
      // https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiggsToTauTauWorking2017#Baseline_Selection
      if ( evt_now!=evt_before) { // new event, save the tau candidates

      //   since it is new event, do we have the best entry to save? If yes, save it!
	if ( bestEntry > -1 )
	  // this is the code that actually saves branches etc.
	  fillTree(Run_Tree,tree,bestEntry,recoil,isMC,isEmbed,seventeen);
	
	//  this is a new event, so the first tau pair is the best! :)
	bestEntry=iEntry;
	tau1Candidate  = make_pair(tree->t1Pt,  tree->t1RerunMVArun2v2DBoldDMwLTraw);//t1ByIsolationMVArun2v1DBoldDMwLTraw);
	tau2Candidate  = make_pair(tree->t2Pt,  tree->t2RerunMVArun2v2DBoldDMwLTraw);//t2ByIsolationMVArun2v1DBoldDMwLTraw);
	// check if currentTau1 is most isolated
	//if ( tree->t1ByIsolationMVArun2v1DBoldDMwLTraw < tree->t2ByIsolationMVArun2v1DBoldDMwLTraw ) {
	if ( tree->t1RerunMVArun2v2DBoldDMwLTraw < tree->t2RerunMVArun2v2DBoldDMwLTraw) {
	  tau1Candidate  = make_pair(tree->t2Pt,  tree->t2RerunMVArun2v2DBoldDMwLTraw);//t2ByIsolationMVArun2v1DBoldDMwLTraw);
	  tau2Candidate  = make_pair(tree->t1Pt,  tree->t1RerunMVArun2v2DBoldDMwLTraw);//t1ByIsolationMVArun2v1DBoldDMwLTraw);
	}
      } else { // not a new event
	// comparison between previous tau pair and the new one takes place here!
	currentTau1Candidate = make_pair(tree->t1Pt,  tree->t1RerunMVArun2v2DBoldDMwLTraw);//t1ByIsolationMVArun2v1DBoldDMwLTraw);
	currentTau2Candidate = make_pair(tree->t2Pt,  tree->t2RerunMVArun2v2DBoldDMwLTraw);//t2ByIsolationMVArun2v1DBoldDMwLTraw);
	//if ( tree->t1ByIsolationMVArun2v1DBoldDMwLTraw < tree->t2ByIsolationMVArun2v1DBoldDMwLTraw ) {
	if ( tree->t1RerunMVArun2v2DBoldDMwLTraw < tree->t2RerunMVArun2v2DBoldDMwLTraw) {
	  currentTau1Candidate  = make_pair(tree->t2Pt,  tree->t2RerunMVArun2v2DBoldDMwLTraw);//tree->t2ByIsolationMVArun2v1DBoldDMwLTraw);
	  currentTau2Candidate  = make_pair(tree->t1Pt,  tree->t1RerunMVArun2v2DBoldDMwLTraw);//tree->t1ByIsolationMVArun2v1DBoldDMwLTraw);
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
      fillTree(Run_Tree,tree,bestEntry,recoil,isMC,isEmbed,seventeen);
    
    // done!
    fout->cd();
    h_cutflow->SetName("CutFlow");
    h_cutflow->Write();
    Run_Tree->Write();
    map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
    map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
    for (; iMap1 != jMap1; ++iMap1)
      nplot1(iMap1->first)->Write();
    map<string, TH2F*>::const_iterator iMap2 = myMap2->begin();
    map<string, TH2F*>::const_iterator jMap2 = myMap2->end();
    for (; iMap2 != jMap2; ++iMap2)
      nplot2(iMap2->first)->Write();
    
    // read the file stream into our json object
    ntupleMap >> j;
    std::string originalName = "Not Found";
    std::string tmpName = fIn->GetName();
    auto searchName = tmpName.substr(10);
    for (json::iterator it = j.begin(); it != j.end(); ++it) {
      for (auto ntuple : it.value()) {
	if (std::string(ntuple).find(searchName) != std::string::npos) {
	  originalName = it.key();
	}
      }
    }
    TNamed dbName("MiniAOD_name", originalName.c_str());
    dbName.Write();

    fout->Close();
    return 0;
}
