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

    // Get tree and couple of other histograms
    TTree* treePtr = (TTree*) fIn->Get("tt/final/Ntuple");
    TH1F *evCounter = (TH1F*) fIn->Get("tt/eventCount");
    TH1F *evCounterW = (TH1F*) fIn->Get("tt/summedWeights");
    HTauTauTree_tt* tree = new HTauTauTree_tt (treePtr);  
    //Define new output tree and its variables
    TTree *Run_Tree = new TTree("tt_tree", "tt_tree");
    Run_Tree->SetDirectory(0);
    Run_Tree->Branch("run", &run, "run/I");
    Run_Tree->Branch("lumi", &lumi, "lumi/I");
    Run_Tree->Branch("evt", &evt, "evt/I");

    Run_Tree->Branch("npv", &npv, "npv/F");
    Run_Tree->Branch("npu", &npu, "npu/F");
    Run_Tree->Branch("amcatNLO_weight", &aMCatNLO_weight, "aMCatNLO_weight/F");

    Run_Tree->Branch("jetpt_1", &jetpt_1, "jetpt_1/F");
    Run_Tree->Branch("jetpt_2", &jetpt_2, "jetpt_2/F");
    Run_Tree->Branch("pt_1", &pt_1, "pt_1/F");
    Run_Tree->Branch("px_1", &px_1, "px_1/F");
    Run_Tree->Branch("py_1", &py_1, "py_1/F");
    Run_Tree->Branch("pz_1", &pz_1, "pz_1/F");
    Run_Tree->Branch("phi_1", &phi_1, "phi_1/F");
    Run_Tree->Branch("eta_1", &eta_1, "eta_1/F");
    Run_Tree->Branch("m_1", &m_1, "m_1/F");
    Run_Tree->Branch("e_1", &e_1, "e_1/F");
    Run_Tree->Branch("q_1", &q_1, "q_1/F");
    Run_Tree->Branch("mt_1", &mt_1, "mt_1/F");
    Run_Tree->Branch("iso_1", &iso_1, "iso_1/F");
    Run_Tree->Branch("t1_decayMode", &t1_decayMode, "t1_decayMode/F");

    Run_Tree->Branch("t1GenCharge",&t1GenCharge,"t1GenCharge/F");
    Run_Tree->Branch("t1GenDecayMode",&t1GenDecayMode,"t1GenDecayMode/F");
    Run_Tree->Branch("t1GenEnergy",&t1GenEnergy,"t1GenEnergy/F");
    Run_Tree->Branch("t1GenEta",&t1GenEta,"t1GenEta/F");
    Run_Tree->Branch("t1GenIsPrompt",&t1GenIsPrompt,"t1GenIsPrompt/F");
    Run_Tree->Branch("t1GenJetEta",&t1GenJetEta,"t1GenJetEta/F");
    Run_Tree->Branch("t1GenJetPt",&t1GenJetPt,"t1GenJetPt/F");
    Run_Tree->Branch("t1GenMotherEnergy",&t1GenMotherEnergy,"t1GenMotherEnergy/F");
    Run_Tree->Branch("t1GenMotherEta",&t1GenMotherEta,"t1GenMotherEta/F");
    Run_Tree->Branch("t1GenMotherPdgId",&t1GenMotherPdgId,"t1GenMotherPdgId/F");
    Run_Tree->Branch("t1GenMotherPhi",&t1GenMotherPhi,"t1GenMotherPhi/F");
    Run_Tree->Branch("t1GenMotherPt",&t1GenMotherPt,"t1GenMotherPt/F");
    Run_Tree->Branch("t1GenPdgId",&t1GenPdgId,"t1GenPdgId/F");
    Run_Tree->Branch("t1GenPhi",&t1GenPhi,"t1GenPhi/F");
    Run_Tree->Branch("t1GenPt",&t1GenPt,"t1GenPt/F");
    Run_Tree->Branch("t1GenStatus",&t1GenStatus,"t1GenStatus/F");
    Run_Tree->Branch("t1ZTTGenDR",&t1ZTTGenDR,"t1ZTTGenDR/F");
    Run_Tree->Branch("t1ZTTGenEta",&t1ZTTGenEta,"t1ZTTGenEta/F");
    //Run_Tree->Branch("t1ZTTGenMatching",&t1ZTTGenMatching,"t1ZTTGenMatching/F");
    Run_Tree->Branch("t1ZTTGenPhi",&t1ZTTGenPhi,"t1ZTTGenPhi/F");
    Run_Tree->Branch("t1ZTTGenPt",&t1ZTTGenPt,"t1ZTTGenPt/F");

    Run_Tree->Branch("t2GenCharge",&t2GenCharge,"t2GenCharge/F");
    Run_Tree->Branch("t2GenDecayMode",&t2GenDecayMode,"t2GenDecayMode/F");
    Run_Tree->Branch("t2GenEnergy",&t2GenEnergy,"t2GenEnergy/F");
    Run_Tree->Branch("t2GenEta",&t2GenEta,"t2GenEta/F");
    Run_Tree->Branch("t2GenIsPrompt",&t2GenIsPrompt,"t2GenIsPrompt/F");
    Run_Tree->Branch("t2GenJetEta",&t2GenJetEta,"t2GenJetEta/F");
    Run_Tree->Branch("t2GenJetPt",&t2GenJetPt,"t2GenJetPt/F");
    Run_Tree->Branch("t2GenMotherEnergy",&t2GenMotherEnergy,"t2GenMotherEnergy/F");
    Run_Tree->Branch("t2GenMotherEta",&t2GenMotherEta,"t2GenMotherEta/F");
    Run_Tree->Branch("t2GenMotherPdgId",&t2GenMotherPdgId,"t2GenMotherPdgId/F");
    Run_Tree->Branch("t2GenMotherPhi",&t2GenMotherPhi,"t2GenMotherPhi/F");
    Run_Tree->Branch("t2GenMotherPt",&t2GenMotherPt,"t2GenMotherPt/F");
    Run_Tree->Branch("t2GenPdgId",&t2GenPdgId,"t2GenPdgId/F");
    Run_Tree->Branch("t2GenPhi",&t2GenPhi,"t2GenPhi/F");
    Run_Tree->Branch("t2GenPt",&t2GenPt,"t2GenPt/F");
    Run_Tree->Branch("t2GenStatus",&t2GenStatus,"t2GenStatus/F");
    Run_Tree->Branch("t2ZTTGenDR",&t2ZTTGenDR,"t2ZTTGenDR/F");
    Run_Tree->Branch("t2ZTTGenEta",&t2ZTTGenEta,"t2ZTTGenEta/F");
    //Run_Tree->Branch("t2ZTTGenMatching",&t2ZTTGenMatching,"t2ZTTGenMatching/F");
    Run_Tree->Branch("t2ZTTGenPhi",&t2ZTTGenPhi,"t2ZTTGenPhi/F");
    Run_Tree->Branch("t2ZTTGenPt",&t2ZTTGenPt,"t2ZTTGenPt/F");

    Run_Tree->Branch("againstElectronLooseMVA6_1", &againstElectronLooseMVA6_1, "againstElectronLooseMVA6_1/F");
    Run_Tree->Branch("againstElectronMediumMVA6_1", &againstElectronMediumMVA6_1, "againstElectronMediumMVA6_1/F");
    Run_Tree->Branch("againstElectronTightMVA6_1", &againstElectronTightMVA6_1, "againstElectronTightMVA6_1/F");
    Run_Tree->Branch("againstElectronVLooseMVA6_1", &againstElectronVLooseMVA6_1, "againstElectronVLooseMVA6_1/F");
    Run_Tree->Branch("againstElectronVTightMVA6_1", &againstElectronVTightMVA6_1, "againstElectronVTightMVA6_1/F");
    Run_Tree->Branch("againstMuonLoose3_1", &againstMuonLoose3_1, "againstMuonLoose3_1/F");
    Run_Tree->Branch("againstMuonTight3_1", &againstMuonTight3_1, "againstMuonTight3_1/F");
    Run_Tree->Branch("byVLooseIsolationMVArun2v1DBoldDMwLT_1", &byVLooseIsolationMVArun2v1DBoldDMwLT_1, "byVLooseIsolationMVArun2v1DBoldDMwLT_1/F");
    Run_Tree->Branch("byLooseIsolationMVArun2v1DBoldDMwLT_1", &byLooseIsolationMVArun2v1DBoldDMwLT_1, "byLooseIsolationMVArun2v1DBoldDMwLT_1/F");
    Run_Tree->Branch("byMediumIsolationMVArun2v1DBoldDMwLT_1", &byMediumIsolationMVArun2v1DBoldDMwLT_1, "byMediumIsolationMVArun2v1DBoldDMwLT_1/F");
    Run_Tree->Branch("byTightIsolationMVArun2v1DBoldDMwLT_1", &byTightIsolationMVArun2v1DBoldDMwLT_1, "byTightIsolationMVArun2v1DBoldDMwLT_1/F");
    Run_Tree->Branch("byVTightIsolationMVArun2v1DBoldDMwLT_1", &byVTightIsolationMVArun2v1DBoldDMwLT_1, "byVTightIsolationMVArun2v1DBoldDMwLT_1/F");
    Run_Tree->Branch("byVVTightIsolationMVArun2v1DBoldDMwLT_1", &byVVTightIsolationMVArun2v1DBoldDMwLT_1, "byVVTightIsolationMVArun2v1DBoldDMwLT_1/F");
    Run_Tree->Branch("byCombinedIsolationDeltaBetaCorrRaw3Hits_1", &byCombinedIsolationDeltaBetaCorrRaw3Hits_1, "byCombinedIsolationDeltaBetaCorrRaw3Hits_1/F");
    Run_Tree->Branch("byCombinedIsolationDeltaBetaCorrRaw3Hits_2", &byCombinedIsolationDeltaBetaCorrRaw3Hits_2, "byCombinedIsolationDeltaBetaCorrRaw3Hits_2/F");
    Run_Tree->Branch("byIsolationMVA3oldDMwoLTraw_1", &byIsolationMVA3oldDMwoLTraw_1, "byIsolationMVA3oldDMwoLTraw_1/F");
    Run_Tree->Branch("byIsolationMVA3oldDMwoLTraw_2", &byIsolationMVA3oldDMwoLTraw_2, "byIsolationMVA3oldDMwoLTraw_2/F");
    Run_Tree->Branch("pt_2", &pt_2, "pt_2/F");
    Run_Tree->Branch("px_2", &px_2, "px_2/F");
    Run_Tree->Branch("py_2", &py_2, "py_2/F");
    Run_Tree->Branch("pz_2", &pz_2, "pz_2/F");
    Run_Tree->Branch("phi_2", &phi_2, "phi_2/F");
    Run_Tree->Branch("eta_2", &eta_2, "eta_2/F");
    Run_Tree->Branch("m_2", &m_2, "m_2/F");
    Run_Tree->Branch("e_2", &e_2, "e_2/F");
    Run_Tree->Branch("q_2", &q_2, "q_2/F");
    Run_Tree->Branch("iso_2", &iso_2, "iso_2/F");
    Run_Tree->Branch("t2_decayMode", &t2_decayMode, "t2_decayMode/F");
    Run_Tree->Branch("againstElectronLooseMVA6_2", &againstElectronLooseMVA6_2, "againstElectronLooseMVA6_2/F");
    Run_Tree->Branch("againstElectronMediumMVA6_2", &againstElectronMediumMVA6_2, "againstElectronMediumMVA6_2/F");
    Run_Tree->Branch("againstElectronTightMVA6_2", &againstElectronTightMVA6_2, "againstElectronTightMVA6_2/F");
    Run_Tree->Branch("againstElectronVLooseMVA6_2", &againstElectronVLooseMVA6_2, "againstElectronVLooseMVA6_2/F");
    Run_Tree->Branch("againstElectronVTightMVA6_2", &againstElectronVTightMVA6_2, "againstElectronVTightMVA6_2/F");
    Run_Tree->Branch("againstMuonLoose3_2", &againstMuonLoose3_2, "againstMuonLoose3_2/F");
    Run_Tree->Branch("againstMuonTight3_2", &againstMuonTight3_2, "againstMuonTight3_2/F");
    Run_Tree->Branch("byVLooseIsolationMVArun2v1DBoldDMwLT_2", &byVLooseIsolationMVArun2v1DBoldDMwLT_2, "byVLooseIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byLooseIsolationMVArun2v1DBoldDMwLT_2", &byLooseIsolationMVArun2v1DBoldDMwLT_2, "byLooseIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byMediumIsolationMVArun2v1DBoldDMwLT_2", &byMediumIsolationMVArun2v1DBoldDMwLT_2, "byMediumIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byTightIsolationMVArun2v1DBoldDMwLT_2", &byTightIsolationMVArun2v1DBoldDMwLT_2, "byTightIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byVTightIsolationMVArun2v1DBoldDMwLT_2", &byVTightIsolationMVArun2v1DBoldDMwLT_2, "byVTightIsolationMVArun2v1DBoldDMwLT_2/F");
    Run_Tree->Branch("byVVTightIsolationMVArun2v1DBoldDMwLT_2", &byVVTightIsolationMVArun2v1DBoldDMwLT_2, "byVVTightIsolationMVArun2v1DBoldDMwLT_2/F");

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

    Run_Tree->Branch("met", &met, "met/F");
    Run_Tree->Branch("metSig", &metSig, "metSig/F");
    Run_Tree->Branch("metcov00", &metcov00, "metcov00/F");   
    Run_Tree->Branch("metcov10", &metcov10, "metcov10/F");
    Run_Tree->Branch("metcov11", &metcov11, "metcov11/F");
    Run_Tree->Branch("metcov01", &metcov01, "metcov01/F");
    Run_Tree->Branch("metphi", &metphi, "metphi/F");
    Run_Tree->Branch("met_px", &met_px, "met_px/F");
    Run_Tree->Branch("met_py", &met_py, "met_py/F");

    Run_Tree->Branch("gen_match_1", &gen_match_1, "gen_match_1/I");
    Run_Tree->Branch("gen_match_2", &gen_match_2, "gen_match_2/I");

    Run_Tree->Branch("nbtag", &nbtag, "nbtag/I");
    Run_Tree->Branch("nbtagL", &nbtagL, "nbtagL/I");
    Run_Tree->Branch("extraelec_veto", &extraelec_veto, "extraelec_veto/F");
    Run_Tree->Branch("extramuon_veto", &extramuon_veto, "extramuon_veto/F");
    Run_Tree->Branch("njets", &njets, "njets/I");
    Run_Tree->Branch("njetspt20", &njetspt20, "njetspt20/I");
    Run_Tree->Branch("njets_JESDown", &njets_JESDown, "njets_JESDown/I");
    Run_Tree->Branch("njetspt20_JESDown", &njetspt20_JESDown, "njetspt20_JESDown/I");
    Run_Tree->Branch("njets_JESUp", &njets_JESUp, "njets_JESUp/I");
    Run_Tree->Branch("njetspt20_JESUp", &njetspt20_JESUp, "njetspt20_JESUp/I");
    Run_Tree->Branch("jpt_1", &jpt_1, "jpt_1/F");
    Run_Tree->Branch("jeta_1", &jeta_1, "jeta_1/F");
    Run_Tree->Branch("jphi_1", &jphi_1, "jphi_1/F");
    Run_Tree->Branch("jcsv_1", &jcsv_1, "jcsv_1/F");

    Run_Tree->Branch("jpt_2", &jpt_2, "jpt_2/F");
    Run_Tree->Branch("jeta_2", &jeta_2, "jeta_2/F");
    Run_Tree->Branch("jphi_2", &jphi_2, "jphi_2/F");
    Run_Tree->Branch("jcsv_2", &jcsv_2, "jcsv_2/F");

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

    Run_Tree->Branch("type1_pfMet_shiftedPt_UnclusteredEnUp", &type1_pfMet_shiftedPt_UnclusteredEnUp, "type1_pfMet_shiftedPt_UnclusteredEnUp/F");
    Run_Tree->Branch("type1_pfMet_shiftedPt_UnclusteredEnDown", &type1_pfMet_shiftedPt_UnclusteredEnDown, "type1_pfMet_shiftedPt_UnclusteredEnDown/F");
    Run_Tree->Branch("type1_pfMet_shiftedPhi_UnclusteredEnUp", &type1_pfMet_shiftedPhi_UnclusteredEnUp, "type1_pfMet_shiftedPhi_UnclusteredEnUp/F");
    Run_Tree->Branch("type1_pfMet_shiftedPhi_UnclusteredEnDown", &type1_pfMet_shiftedPhi_UnclusteredEnDown, "type1_pfMet_shiftedPhi_UnclusteredEnDown/F");
    Run_Tree->Branch("type1_pfMet_shiftedPt_JetEnUp", &type1_pfMet_shiftedPt_JetEnUp, "type1_pfMet_shiftedPt_JetEnUp/F");
    Run_Tree->Branch("type1_pfMet_shiftedPt_JetEnDown", &type1_pfMet_shiftedPt_JetEnDown, "type1_pfMet_shiftedPt_JetEnDown/F");
    Run_Tree->Branch("type1_pfMet_shiftedPhi_JetEnUp", &type1_pfMet_shiftedPhi_JetEnUp, "type1_pfMet_shiftedPhi_JetEnUp/F");
    Run_Tree->Branch("type1_pfMet_shiftedPhi_JetEnDown", &type1_pfMet_shiftedPhi_JetEnDown, "type1_pfMet_shiftedPhi_JetEnDown/F");

    float lt_before=0;
    int bestEntry=-1;
    ULong64_t evt_now=0;
    ULong64_t evt_before=-1;
    bool print=false;
    plotFill("nevents",0,9,0,9,evCounter->GetBinContent(1)); //**
    plotFill("nevents",1,9,0,9,evCounterW->GetBinContent(1)); //**

    // Starts loop over events 
    for (int iEntry = 0; iEntry < tree->GetEntries() ; iEntry++)
    {
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
        // Tau energy scale (AN L1271 : -1.8%, +1.0%, +0.4%)
	if (isMC && tree->t1DecayMode==0) tau1=tau1*0.982;
        else if (isMC && tree->t1DecayMode==1) tau1=tau1*1.010;
        else if (isMC && tree->t1DecayMode==10) tau1=tau1*1.004;
        if (isMC && tree->t2DecayMode==0) tau2=tau2*0.982;
        else if (isMC && tree->t2DecayMode==1) tau2=tau2*1.010;
        else if (isMC && tree->t2DecayMode==10) tau2=tau2*1.004;
	
	bool ttKin40 = false; // OK
	bool ttCharge = false; // OK
	bool ttOS = false; // OK but not for skimming
	bool ttDR = false; // OK
	bool ttVtx = false; // OK
	//bool tt35 = false;// need to understand the meaning of variables... this is not for skimming
	bool ttIsoVLoose = false;// OK
	bool ttDisc = false;// not for skimming
	bool extraVetoTT = false; // not for skimming, muVetoZTTp001dxyzR0 has 0, 1, and 2 << need to understand
	bool DecayMode = false; // it's not a boolean

	if (tau1.Pt() > 40 && fabs(tau1.Eta()) < 2.1 && tau2.Pt() > 40 && fabs(tau2.Eta()) < 2.1) ttKin40 = true;
	if (abs(tree->t1Charge) == 1.0 && abs(tree->t2Charge) == 1.0) ttCharge = true;
	if (tree->t1_t2_DR > 0.5) ttDR = true;
	if (tree->t1_t2_SS == 0) ttOS = true;
	if (abs( tree->t1PVDZ ) < 0.2 && abs( tree->t2PVDZ ) < 0.2) ttVtx = true;
	if (tree->t1ByVLooseIsolationMVArun2v1DBoldDMwLT > 0.5 && tree->t2ByVLooseIsolationMVArun2v1DBoldDMwLT > 0.5 ) ttIsoVLoose = true;
	if (tree->t1AgainstElectronVLooseMVA6>0.5 && tree->t2AgainstElectronVLooseMVA6>0.5 && tree->t1AgainstMuonLoose3>0.5 && tree->t2AgainstMuonLoose3>0.5) ttDisc = true;
	if (tree->eVetoZTTp001dxyzR0 == 0 && tree->muVetoZTTp001dxyzR0 == 0) extraVetoTT = true;
	if (tree->t1DecayMode==1 && tree->t2DecayMode==1) DecayMode = true;
	//if ((tree->doubleTau35Pass > 0 && tree->t1MatchesDoubleTau35Path > 0 && tree->t2MatchesDoubleTau35Path > 0 && tree->t1MatchesDoubleTau35Filter > 0 && tree->t2MatchesDoubleTau35Filter > 0) || (tree->doubleTauCmbIso35RegPass > 0&& tree->t1MatchesDoubleTauCmbIso35RegPath > 0 && tree->t2MatchesDoubleTauCmbIso35RegPath > 0 && tree->t1MatchesDoubleTauCmbIso35RegFilter > 0 && tree->t2MatchesDoubleTauCmbIso35RegFilter > 0)) tt35 = true;
	
	
	
	if (!ttKin40 || !ttDR || !ttVtx || !ttCharge || !ttIsoVLoose ) continue;
	if (!tree->t1DecayModeFinding) continue;
	if (!tree->t2DecayModeFinding) continue;

     	evt_now=tree->evt;

	if (evt_now!=evt_before){
	  lt_before=tree->t1Pt + tree->t2Pt;
        }
        if (evt_now!=evt_before){
          if (bestEntry>-1) 
	    fillTree(Run_Tree,tree,bestEntry,isMC);
	  bestEntry=iEntry;
        }
        if (evt_now==evt_before){
	  if (tree->t1Pt + tree->t2Pt >lt_before+0.0001){
	    bestEntry=iEntry;
	    lt_before=tree->t1Pt + tree->t2Pt;
	  }
        }
        evt_before=evt_now;
    }
    if (bestEntry>-1)
      fillTree(Run_Tree,tree,bestEntry,isMC); 
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

