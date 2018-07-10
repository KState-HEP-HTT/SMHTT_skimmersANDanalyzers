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
#include "et_Tree.h"

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

    // Get tree and couple of other histograms
    TTree* treePtr = (TTree*) fIn->Get("et/final/Ntuple");
    TH1F *evCounter = (TH1F*) fIn->Get("et/eventCount");
    TH1F *evCounterW = (TH1F*) fIn->Get("et/summedWeights");
    HTauTauTree_et* tree = new HTauTauTree_et (treePtr);  

    //Define new output tree and its variables
    TTree *Run_Tree = new TTree("et_tree", "et_tree");
    Run_Tree->SetDirectory(0);
    // Event ID variables
    Run_Tree->Branch("run", &run, "run/I");
    Run_Tree->Branch("lumi", &lumi, "lumi/I");
    Run_Tree->Branch("evt", &evt);
    // Extra lepton vetos
    Run_Tree->Branch("dilepton_veto", &dilepton_veto, "dilepton_veto/F");
    Run_Tree->Branch("extraelec_veto", &extraelec_veto, "extraelec_veto/F");
    Run_Tree->Branch("extramuon_veto", &extramuon_veto, "extramuon_veto/F");
    // Trigger flags
    Run_Tree->Branch("trg_doubletau", &trg_doubletau, "trg_doubletau/F"); // FIXME
    // Leg 1
    Run_Tree->Branch("pt_1", &pt_1, "pt_1/F");
    Run_Tree->Branch("px_1", &px_1, "px_1/F");
    Run_Tree->Branch("py_1", &py_1, "py_1/F");
    Run_Tree->Branch("pz_1", &pz_1, "pz_1/F");
    Run_Tree->Branch("phi_1", &phi_1, "phi_1/F");
    Run_Tree->Branch("eta_1", &eta_1, "eta_1/F");
    Run_Tree->Branch("m_1", &m_1, "m_1/F");
    Run_Tree->Branch("e_1", &e_1, "e_1/F");
    Run_Tree->Branch("q_1", &q_1, "q_1/F");
    Run_Tree->Branch("d0_1", &d0_1, "d0_1/F");
    Run_Tree->Branch("dZ_1", &dZ_1, "dZ_1/F");
    //Run_Tree->Branch("mt_1", &mt_1, "mt_1/F"); // FIXME
    //Run_Tree->Branch("pfmt_1", &mt_1, "pfmt_1/F"); // FIXME
    Run_Tree->Branch("iso_1", &iso_1, "iso_1/F");    
    Run_Tree->Branch("gen_match_1", &gen_match_1, "gen_match_1/I");
    Run_Tree->Branch("id_e_mva_iso_wp80_1", &id_e_mva_iso_wp80_1, "id_e_mva_iso_wp80_1/F");
    Run_Tree->Branch("id_e_mva_iso_wp90_1", &id_e_mva_iso_wp90_1, "id_e_mva_iso_wp90_1/F");
    Run_Tree->Branch("id_e_mva_iso_loose_1", &id_e_mva_iso_loose_1, "id_e_mva_iso_loose_1/F");
    Run_Tree->Branch("id_e_mva_wp80_1", &id_e_mva_wp80_1, "id_e_mva_wp80_1/F");
    Run_Tree->Branch("id_e_mva_wp90_1", &id_e_mva_wp90_1, "id_e_mva_wp90_1/F");
    Run_Tree->Branch("id_e_mva_loose_1", &id_e_mva_loose_1, "id_e_mva_loose_1/F");
    // Leg 2
    Run_Tree->Branch("pt_2", &pt_2, "pt_2/F");
    Run_Tree->Branch("px_2", &px_2, "px_2/F");
    Run_Tree->Branch("py_2", &py_2, "py_2/F");
    Run_Tree->Branch("pz_2", &pz_2, "pz_2/F");
    Run_Tree->Branch("phi_2", &phi_2, "phi_2/F");
    Run_Tree->Branch("eta_2", &eta_2, "eta_2/F");
    Run_Tree->Branch("m_2", &m_2, "m_2/F");
    Run_Tree->Branch("e_2", &e_2, "e_2/F");
    Run_Tree->Branch("q_2", &q_2, "q_2/F");
    Run_Tree->Branch("d0_2", &d0_2, "d0_2/F");
    Run_Tree->Branch("dZ_2", &dZ_2, "dZ_2/F");
    Run_Tree->Branch("mt_2", &mt_2, "mt_2/F"); // FIXME
    //Run_Tree->Branch("pfmt_2", &mt_2, "pfmt_2/F"); // FIXME
    Run_Tree->Branch("iso_2", &iso_2, "iso_2/F");
    Run_Tree->Branch("gen_match_2", &gen_match_2, "gen_match_2/I");
    Run_Tree->Branch("againstElectronLooseMVA6_2", &againstElectronLooseMVA6_2, "againstElectronLooseMVA6_2/F");
    Run_Tree->Branch("againstElectronMediumMVA6_2", &againstElectronMediumMVA6_2, "againstElectronMediumMVA6_2/F");
    Run_Tree->Branch("againstElectronTightMVA6_2", &againstElectronTightMVA6_2, "againstElectronTightMVA6_2/F");
    Run_Tree->Branch("againstElectronVLooseMVA6_2", &againstElectronVLooseMVA6_2, "againstElectronVLooseMVA6_2/F");
    Run_Tree->Branch("againstElectronVTightMVA6_2", &againstElectronVTightMVA6_2, "againstElectronVTightMVA6_2/F");
    Run_Tree->Branch("againstMuonLoose3_2", &againstMuonLoose3_2, "againstMuonLoose3_2/F");
    Run_Tree->Branch("againstMuonTight3_2", &againstMuonTight3_2, "againstMuonTight3_2/F");
    Run_Tree->Branch("byCombinedIsolationDeltaBetaCorrRaw3Hits_2", &byCombinedIsolationDeltaBetaCorrRaw3Hits_2, "byCombinedIsolationDeltaBetaCorrRaw3Hits_2/F");
    Run_Tree->Branch("byIsolationMVA3newDMwLTraw_2", &byIsolationMVA3newDMwLTraw_2, "byIsolationMVA3newDMwLTraw_2/F");
    Run_Tree->Branch("byIsolationMVA3oldDMwLTraw_2", &byIsolationMVA3oldDMwLTraw_2, "byIsolationMVA3oldDMwLTraw_2/F");
    Run_Tree->Branch("chargedIsoPtSum_2", &chargedIsoPtSum_2, "chargedIsoPtSum_2/F");
    Run_Tree->Branch("neutralIsoPtSum_2", &neutralIsoPtSum_2, "neutralIsoPtSum_2/F");
    Run_Tree->Branch("decayModeFinding_2", &decayModeFinding_2, "decayModeFinding_2/F");
    Run_Tree->Branch("t_decayMode", &t_decayMode, "t_decayMode/F");
    // MET
    Run_Tree->Branch("met", &met, "met/F");    
    Run_Tree->Branch("metphi", &metphi, "metphi/F");
    Run_Tree->Branch("metSig", &metSig, "metSig/F");
    Run_Tree->Branch("metcov00", &metcov00, "metcov00/F");   
    Run_Tree->Branch("metcov10", &metcov10, "metcov10/F");
    Run_Tree->Branch("metcov11", &metcov11, "metcov11/F");
    Run_Tree->Branch("metcov01", &metcov01, "metcov01/F");
    Run_Tree->Branch("met_px", &met_px, "met_px/F");
    Run_Tree->Branch("met_py", &met_py, "met_py/F");
    // VBF system
    Run_Tree->Branch("mjj", &mjj, "mjj/F");
    Run_Tree->Branch("jdeta", &jdeta, "jdeta/F");
    Run_Tree->Branch("njetingap", &njetingap, "njetingap/F");
    Run_Tree->Branch("njetingap20", &njetingap20, "njetingap20/F");
    Run_Tree->Branch("dijetpt", &dijetpt, "dijetpt/F");
    //Run_Tree->Branch("dijetphi", &dijetphi, "dijetphi/F");
    Run_Tree->Branch("ptvis", &ptvis, "ptvis/F");
    // additional jets
    Run_Tree->Branch("nbtag", &nbtag, "nbtag/I");
    Run_Tree->Branch("nbtagL", &nbtagL, "nbtagL/I");
    Run_Tree->Branch("njets", &njets, "njets/I");
    Run_Tree->Branch("njetspt0", &njetspt0, "njetspt0/I");
    Run_Tree->Branch("njets_JESDown", &njets_JESDown, "njets_JESDown/I");
    Run_Tree->Branch("njetspt0_JESDown", &njetspt0_JESDown, "njetspt0_JESDown/I");
    Run_Tree->Branch("njets_JESUp", &njets_JESUp, "njets_JESUp/I");
    Run_Tree->Branch("njetspt0_JESUp", &njetspt0_JESUp, "njetspt0_JESUp/I");
    Run_Tree->Branch("jpt_1", &jpt_1, "jpt_1/F");
    Run_Tree->Branch("jeta_1", &jeta_1, "jeta_1/F");
    Run_Tree->Branch("jphi_1", &jphi_1, "jphi_1/F");
    Run_Tree->Branch("jcsv_1", &jcsv_1, "jcsv_1/F");
    Run_Tree->Branch("jetpt_1", &jetpt_1, "jetpt_1/F");
    Run_Tree->Branch("jpt_2", &jpt_2, "jpt_2/F");
    Run_Tree->Branch("jeta_2", &jeta_2, "jeta_2/F");
    Run_Tree->Branch("jphi_2", &jphi_2, "jphi_2/F");
    Run_Tree->Branch("jcsv_2", &jcsv_2, "jcsv_2/F");
    Run_Tree->Branch("jetpt_2", &jetpt_2, "jetpt_2/F");
    Run_Tree->Branch("bpt_1", &bpt_1, "bpt_1/F");
    Run_Tree->Branch("beta_1", &beta_1, "beta_1/F");
    Run_Tree->Branch("bphi_1", &bphi_1, "bphi_1/F");
    Run_Tree->Branch("bcsv_1", &bcsv_1, "bcsv_1/F");
    Run_Tree->Branch("bflavor_1", &bflavor_1, "bflavor_1/F");
    Run_Tree->Branch("bpt_2", &bpt_2, "bpt_2/F");
    Run_Tree->Branch("beta_2", &beta_2, "beta_2/F");
    Run_Tree->Branch("bphi_2", &bphi_2, "bphi_2/F");
    Run_Tree->Branch("bcsv_2", &bcsv_2, "bcsv_2/F");
    Run_Tree->Branch("bflavor_2", &bflavor_2, "bflavor_2/F");
    // Generator Variables
    Run_Tree->Branch("NPU", &NUP, "NUP/I");
    // Pile Up
    Run_Tree->Branch("npv", &npv, "npv/F");
    Run_Tree->Branch("npu", &npu, "npu/F");
    Run_Tree->Branch("rho", &rho, "rho/F");
    Run_Tree->Branch("amcatNLO_weight", &aMCatNLO_weight, "aMCatNLO_weight/F");

    // Miscellaneous
    Run_Tree->Branch("mGenCharge",&mGenCharge,"mGenCharge/F");
    Run_Tree->Branch("mGenDecayMode",&mGenDecayMode,"mGenDecayMode/F");
    Run_Tree->Branch("mGenEnergy",&mGenEnergy,"mGenEnergy/F");
    Run_Tree->Branch("mGenEta",&mGenEta,"mGenEta/F");
    Run_Tree->Branch("mGenIsPrompt",&mGenIsPrompt,"mGenIsPrompt/F");
    Run_Tree->Branch("mGenJetEta",&mGenJetEta,"mGenJetEta/F");
    Run_Tree->Branch("mGenJetPt",&mGenJetPt,"mGenJetPt/F");
    Run_Tree->Branch("mGenMotherEnergy",&mGenMotherEnergy,"mGenMotherEnergy/F");
    Run_Tree->Branch("mGenMotherEta",&mGenMotherEta,"mGenMotherEta/F");
    Run_Tree->Branch("mGenMotherPdgId",&mGenMotherPdgId,"mGenMotherPdgId/F");
    Run_Tree->Branch("mGenMotherPhi",&mGenMotherPhi,"mGenMotherPhi/F");
    Run_Tree->Branch("mGenMotherPt",&mGenMotherPt,"mGenMotherPt/F");
    Run_Tree->Branch("mGenPdgId",&mGenPdgId,"mGenPdgId/F");
    Run_Tree->Branch("mGenPhi",&mGenPhi,"mGenPhi/F");
    Run_Tree->Branch("mGenPt",&mGenPt,"mGenPt/F");
    Run_Tree->Branch("mGenStatus",&mGenStatus,"mGenStatus/F");
    Run_Tree->Branch("mZTTGenDR",&mZTTGenDR,"mZTTGenDR/F");
    Run_Tree->Branch("mZTTGenEta",&mZTTGenEta,"mZTTGenEta/F");
    Run_Tree->Branch("mZTTGenPhi",&mZTTGenPhi,"mZTTGenPhi/F");
    Run_Tree->Branch("mZTTGenPt",&mZTTGenPt,"mZTTGenPt/F");

    Run_Tree->Branch("tGenCharge",&tGenCharge,"tGenCharge/F");
    Run_Tree->Branch("tGenDecayMode",&tGenDecayMode,"tGenDecayMode/F");
    Run_Tree->Branch("tGenEnergy",&tGenEnergy,"tGenEnergy/F");
    Run_Tree->Branch("tGenEta",&tGenEta,"tGenEta/F");
    Run_Tree->Branch("tGenIsPrompt",&tGenIsPrompt,"tGenIsPrompt/F");
    Run_Tree->Branch("tGenJetEta",&tGenJetEta,"tGenJetEta/F");
    Run_Tree->Branch("tGenJetPt",&tGenJetPt,"tGenJetPt/F");
    Run_Tree->Branch("tGenMotherEnergy",&tGenMotherEnergy,"tGenMotherEnergy/F");
    Run_Tree->Branch("tGenMotherEta",&tGenMotherEta,"tGenMotherEta/F");
    Run_Tree->Branch("tGenMotherPdgId",&tGenMotherPdgId,"tGenMotherPdgId/F");
    Run_Tree->Branch("tGenMotherPhi",&tGenMotherPhi,"tGenMotherPhi/F");
    Run_Tree->Branch("tGenMotherPt",&tGenMotherPt,"tGenMotherPt/F");
    Run_Tree->Branch("tGenPdgId",&tGenPdgId,"tGenPdgId/F");
    Run_Tree->Branch("tGenPhi",&tGenPhi,"tGenPhi/F");
    Run_Tree->Branch("tGenPt",&tGenPt,"tGenPt/F");
    Run_Tree->Branch("tGenStatus",&tGenStatus,"tGenStatus/F");
    Run_Tree->Branch("tZTTGenDR",&tZTTGenDR,"tZTTGenDR/F");
    Run_Tree->Branch("tZTTGenEta",&tZTTGenEta,"tZTTGenEta/F");
    Run_Tree->Branch("tZTTGenPhi",&tZTTGenPhi,"tZTTGenPhi/F");
    Run_Tree->Branch("tZTTGenPt",&tZTTGenPt,"tZTTGenPt/F");

    // FIXME h file
    Run_Tree->Branch("byVLooseIsolationMVArun2v1DBoldDMwLT_2", &byVLooseIsolationMVArun2v1DBoldDMwLT_2, "byVLooseIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byLooseIsolationMVArun2v1DBoldDMwLT_2", &byLooseIsolationMVArun2v1DBoldDMwLT_2, "byLooseIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byMediumIsolationMVArun2v1DBoldDMwLT_2", &byMediumIsolationMVArun2v1DBoldDMwLT_2, "byMediumIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byTightIsolationMVArun2v1DBoldDMwLT_2", &byTightIsolationMVArun2v1DBoldDMwLT_2, "byTightIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byVTightIsolationMVArun2v1DBoldDMwLT_2", &byVTightIsolationMVArun2v1DBoldDMwLT_2, "byVTightIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byVVTightIsolationMVArun2v1DBoldDMwLT_2", &byVVTightIsolationMVArun2v1DBoldDMwLT_2, "byVVTightIsolationMVArun2v1DBoldDMwLT_2/F");

    Run_Tree->Branch("tRerunMVArun2v2DBoldDMwLTVVLoose", &tRerunMVArun2v2DBoldDMwLTVVLoose, "tRerunMVArun2v2DBoldDMwLTVVLoose/F");
    Run_Tree->Branch("tRerunMVArun2v2DBoldDMwLTVLoose", &tRerunMVArun2v2DBoldDMwLTVLoose, "tRerunMVArun2v2DBoldDMwLTVLoose/F");
    Run_Tree->Branch("tRerunMVArun2v2DBoldDMwLTLoose", &tRerunMVArun2v2DBoldDMwLTLoose, "tRerunMVArun2v2DBoldDMwLTLoose/F");
    Run_Tree->Branch("tRerunMVArun2v2DBoldDMwLTMedium", &tRerunMVArun2v2DBoldDMwLTMedium, "tRerunMVArun2v2DBoldDMwLTMedium/F");
    Run_Tree->Branch("tRerunMVArun2v2DBoldDMwLTTight", &tRerunMVArun2v2DBoldDMwLTTight, "tRerunMVArun2v2DBoldDMwLTTight/F");
    Run_Tree->Branch("tRerunMVArun2v2DBoldDMwLTVTight", &tRerunMVArun2v2DBoldDMwLTVTight, "tRerunMVArun2v2DBoldDMwLTVTight/F");
    Run_Tree->Branch("tRerunMVArun2v2DBoldDMwLTVVTight", &tRerunMVArun2v2DBoldDMwLTVVTight, "tRerunMVArun2v2DBoldDMwLTVVTight/F");

    Run_Tree->Branch("genpX", &genpX, "genpX/F");
    Run_Tree->Branch("genpY", &genpY, "genpY/F");
    Run_Tree->Branch("genpT", &genpT, "genpT/F");
    Run_Tree->Branch("genM", &genM, "genM/F");
    Run_Tree->Branch("vispX", &vispX, "vispX/F");
    Run_Tree->Branch("vispY", &vispY, "vispY/F");

    Run_Tree->Branch("genEta", &genEta, "genEta/F");
    Run_Tree->Branch("genPhi", &genPhi, "genPhi/F");
    Run_Tree->Branch("genHTT", &genHTT, "genHTT/F");
    Run_Tree->Branch("genMass", &genMass, "genMass/F");

    Run_Tree->Branch("numGenJets", &numGenJets, "numGenJets/F");
    Run_Tree->Branch("pt_top1", &pt_top1, "pt_top1/F");
    Run_Tree->Branch("pt_top2", &pt_top2, "pt_top2/F");
    Run_Tree->Branch("genweight", &genweight, "genweight/F");

    Run_Tree->Branch("met_JESDown", &met_JESDown, "met_JESDown/F");
    Run_Tree->Branch("met_UESDown", &met_UESDown, "met_UESDown/F");
    Run_Tree->Branch("met_JESUp", &met_JESUp, "met_JESUp/F");
    Run_Tree->Branch("met_UESUp", &met_UESUp, "met_UESUp/F");
    Run_Tree->Branch("metphi_JESDown", &metphi_JESDown, "metphi_JESDown/F");
    Run_Tree->Branch("metphi_TESDown", &metphi_TESDown, "metphi_TESDown/F");
    Run_Tree->Branch("metphi_UESDown", &metphi_UESDown, "metphi_UESDown/F");
    Run_Tree->Branch("metphi_JESUp", &metphi_JESUp, "metphi_JESUp/F");
    Run_Tree->Branch("metphi_UESUp", &metphi_UESUp, "metphi_UESUp/F");


    Run_Tree->Branch("passDoubleTau35", &passDoubleTau35, "passDoubleTau35/F");
    Run_Tree->Branch("matchDoubleTau35_1", &matchDoubleTau35_1, "matchDoubleTau35_1/F");
    Run_Tree->Branch("matchDoubleTau35_2", &matchDoubleTau35_2, "matchDoubleTau35_2/F");
    Run_Tree->Branch("filterDoubleTau35_1", &filterDoubleTau35_1, "filterDoubleTau35_1/F");
    Run_Tree->Branch("filterDoubleTau35_2", &filterDoubleTau35_2, "filterDoubleTau35_2/F");
    Run_Tree->Branch("passDoubleTauCmbIso35", &passDoubleTauCmbIso35, "passDoubleTauCmbIso35/F");
    Run_Tree->Branch("matchDoubleTauCmbIso35_1", &matchDoubleTauCmbIso35_1, "matchDoubleTauCmbIso35_1/F");
    Run_Tree->Branch("matchDoubleTauCmbIso35_2", &matchDoubleTauCmbIso35_2, "matchDoubleTauCmbIso35_2/F");
    Run_Tree->Branch("filterDoubleTauCmbIso35_1", &filterDoubleTauCmbIso35_1, "filterDoubleTauCmbIso35_1/F");
    Run_Tree->Branch("filterDoubleTauCmbIso35_2", &filterDoubleTauCmbIso35_2, "filterDoubleTauCmbIso35_2/F");

    Run_Tree->Branch("mMatchesDoubleTightTau35Path", &mMatchesDoubleTightTau35Path, "mMatchesDoubleTightTau35Path/F");
    Run_Tree->Branch("tMatchesDoubleTightTau35Path", &tMatchesDoubleTightTau35Path, "tMatchesDoubleTightTau35Path/F");
    Run_Tree->Branch("mMatchesDoubleMediumTau40Path", &mMatchesDoubleMediumTau40Path, "mMatchesDoubleMediumTau40Path/F");
    Run_Tree->Branch("tMatchesDoubleMediumTau40Path", &tMatchesDoubleMediumTau40Path, "tMatchesDoubleMediumTau40Path/F");
    Run_Tree->Branch("mMatchesDoubleTightTau40Path", &mMatchesDoubleTightTau40Path, "mMatchesDoubleTightTau40Path/F");
    Run_Tree->Branch("tMatchesDoubleTightTau40Path", &tMatchesDoubleTightTau40Path, "tMatchesDoubleTightTau40Path/F");
    

    float lt_before=0;
    int bestEntry=-1;
    ULong64_t evt_now=0;
    ULong64_t evt_before=-1;
    bool print=false;
    plotFill("nevents",0,9,0,9,evCounter->GetBinContent(1)); //**
    plotFill("nevents",1,9,0,9,evCounterW->GetBinContent(1)); //**

    pair<float, float> eleCandidate, tauCandidate;

    // Starts loop over events 
    for (int iEntry = 0; iEntry < tree->GetEntries() ; iEntry++)
    {
      // For tau pair forming algorithm
      pair<float, float> currentEleCandidate, currentTauCandidate;

      float pu=1.0;
      tree->GetEntry(iEntry);
      bool print=false;
      if (iEntry % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d ", iEntry);
      fflush(stdout);
      //DY : 4-momentums of final state objects, tt
      TLorentzVector ele;
      TLorentzVector tau;
      ele.SetPtEtaPhiM(tree->ePt,tree->eEta,tree->ePhi,tree->eMass);
      tau.SetPtEtaPhiM(tree->tPt,tree->tEta,tree->tPhi,tree->tMass);
      // Tau energy scale (AN L1271 : -1.8%, +1.0%, +0.4%)
      /*
      if (isMC && tree->mDecayMode==0) ele=ele*0.982;
      else if (isMC && tree->mDecayMode==1) ele=ele*1.010;
      else if (isMC && tree->mDecayMode==10) ele=ele*1.004;
      if (isMC && tree->tDecayMode==0) tau=tau*0.982;
      else if (isMC && tree->tDecayMode==1) tau=tau*1.010;
      else if (isMC && tree->tDecayMode==10) tau=tau*1.004;
      */

      // Baseline selection : https://twiki.cern.ch/twiki/bin/view/CMS/HiggsToTauTauWorking2017#Baseline_tau_h_tau_h
      // Electron
      if (ele.Pt() < 25 || fabs(ele.Eta()) > 2.1 ) continue;
      if (fabs(tree->ePVDZ) > 0.2) continue;
      if (fabs(tree->ePVDXY) > 0.045) continue;
      //if (!tree->eMVANoisoWP80)  continue;
      if (!tree->eMVAIsoWP80)  continue;
      // Tau
      if (tau.Pt() < 20 || fabs(tau.Eta()) > 2.3 ) continue;
      if (tree->tRerunMVArun2v2DBoldDMwLTVVLoose<0.5) continue; // FIXME
      if (!tree->tDecayModeFinding) continue;
      if (fabs( tree->tPVDZ ) > 0.2) continue;
      if (fabs(tree->tCharge)!=1) {
	cout << "DOYEONG" << endl;
	continue;
      }
      // Pair
      if (ele.DeltaR(tau) < 0.5) continue;

      evt_now=tree->evt;
      
      // Old sorting Algorithm as from Cecile
      if ( false ) {
	  if (evt_now!=evt_before){
	    lt_before=tree->ePt + tree->tPt;
	  }
	  if (evt_now!=evt_before){
	    if (bestEntry>-1) 
	      fillTree(Run_Tree,tree,bestEntry,isMC);
	    bestEntry=iEntry;
	  }
	  if (evt_now==evt_before){
	    if (tree->ePt + tree->tPt >lt_before+0.0001){
	      bestEntry=iEntry;
	      lt_before=tree->ePt + tree->tPt;
	    }
	  }
	  evt_before=evt_now;
      } else {
	  // implement new sorting per 
	  // https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiggsToTauTauWorking2017#Baseline_Selection
	  if ( evt_now!=evt_before) { // new event, save the tau candidates

	    //   since it is new event, do we have the best entry to save? If yes, save it!
	    if ( bestEntry > -1  )
	      fillTree(Run_Tree,tree,bestEntry,isMC);
	   
	    //  this is a new event, so the first tau pair is the best! :)
	    bestEntry=iEntry;
	    eleCandidate  = make_pair(tree->ePt,  tree->eIsoDB03);
	    tauCandidate  = make_pair(tree->tPt,  tree->tRerunMVArun2v2DBoldDMwLTraw);
	  } else { // not a new event
	    // comparison between previous tau pair and the new one takes place here!
	    currentEleCandidate = make_pair(tree->ePt,  tree->eIsoDB03);
	    currentTauCandidate = make_pair(tree->tPt,  tree->tRerunMVArun2v2DBoldDMwLTraw);

	    // clause 1, select the pair that has most isolated eleon 
	    if (currentEleCandidate.second - eleCandidate.second  < 0.0001 ) bestEntry=iEntry;
	    // check if the first eleon is the same, and if so - move to clause 2
	    if ( fabs(currentEleCandidate.second - eleCandidate.second)  <  0.0001 ) {
	      // pick up  the pair with the highest pT of the first candidate
	      if (currentEleCandidate.first - eleCandidate.first > 0.0001 ) bestEntry=iEntry;
	      if ( fabs(currentEleCandidate.first -eleCandidate.first) < 0.0001 ) { 
		// same pT, same iso, move to clause 3
		if (currentTauCandidate.second - tauCandidate.second > 0.0001 ) bestEntry=iEntry;
		if ( fabs(currentTauCandidate.second - tauCandidate.second) < 0.0001 ) {
		  // same iso - pick the pair with the highest pT
		  if ( currentTauCandidate.first - tauCandidate.first  > 0.0001 ) bestEntry=iEntry;
		} // tau has the same isolation

	      } // ele has the same pT

	    } // ele has the same isolation

	  } // not a new event
	  evt_before=evt_now;
	} // new way to sort (by isolation)

    } // loop over entries in the ntuple (tau pairs)
    
    // save the best pair from the last event
    if (bestEntry>-1)
      fillTree(Run_Tree,tree,bestEntry,isMC);

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
