///////////////////////////////////////////////////////////////////////////////////////////////
//  https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiggsToTauTauWorking2017#mutau%20checklist  //
///////////////////////////////////////////////////////////////////////////////////////////////
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
#include "mutau_Tree_mt.h"
//#include "LumiReweightingStandAlone.h"

int main(int argc, char** argv) {

    using namespace std;
    myMap1 = new map<string, TH1F*>();
    myMap2 = new map<string, TH2F*>();
    string status_sample = *(argv + 1);
    bool isMC = false;
    bool isData = false;
    bool isEmbedded=false;
    if (status_sample.compare("mc") == 0) isMC = true;
    if (status_sample.compare("data") == 0) isData = true;
    if (status_sample.compare("embedded") == 0) isEmbedded = true;
    string out = *(argv + 2);
    string outname= out;
    TFile *fout = TFile::Open(outname.c_str(), "RECREATE");

    string in = *(argv + 3);
    string inname= in;
    TFile *fIn = TFile::Open(inname.c_str());

    int recoil=0;
    string recoilType = *(argv + 4);
    if (recoilType.compare("W") == 0)  recoil=1;
    if (recoilType.compare("Z") == 0)  recoil=2;

    bool seventeen = false;
    if (17 == atof(argv[5])) seventeen = true;

    TTree* treePtr = (TTree*) fIn->Get("mt/final/Ntuple");
    TH1F *evCounter = (TH1F*) fIn->Get("mt/eventCount");
    TH1F *evCounterW = (TH1F*) fIn->Get("mt/summedWeights");
    HTauTauTree_mt* tree = new HTauTauTree_mt (treePtr);

    TTree *Run_Tree = new TTree("mutau_tree", "mutau_tree");
    Run_Tree->SetDirectory(0);
    Run_Tree->Branch("run", &run);
    Run_Tree->Branch("lumi", &lumi);
    Run_Tree->Branch("evt", &evt);

    Run_Tree->Branch("tZTTGenDR", &tZTTGenDR);
    Run_Tree->Branch("npv", &npv);
    Run_Tree->Branch("npu", &npu);
    //Run_Tree->Branch("amcatNLO_weight", &aMCatNLO_weight);
    Run_Tree->Branch("genweight", &genweight);

    Run_Tree->Branch("Rivet_stage1_cat_pTjet30GeV", &Rivet_stage1_cat_pTjet30GeV);
    Run_Tree->Branch("Rivet_stage0_cat", &Rivet_stage0_cat);
    Run_Tree->Branch("Rivet_higgsPt", &Rivet_higgsPt);
    Run_Tree->Branch("Rivet_nJets30", &Rivet_nJets30);

    Run_Tree->Branch("pt_1", &pt_1);
    Run_Tree->Branch("phi_1", &phi_1);
    Run_Tree->Branch("eta_1", &eta_1);
    Run_Tree->Branch("m_1", &m_1);
    Run_Tree->Branch("e_1", &e_1);
    Run_Tree->Branch("q_1", &q_1);
    Run_Tree->Branch("mt_1", &mt_1);
    Run_Tree->Branch("iso_1", &iso_1);
    Run_Tree->Branch("iso_1_v2", &iso_1_v2);
    Run_Tree->Branch("id_m_medium_1", &id_m_medium_1);
    if (seventeen) {
      // Cross trigger
      Run_Tree->Branch("mMatchesIsoMu20Tau27Path", &mMatchesIsoMu20Tau27Path); 
      Run_Tree->Branch("mMatchesIsoMu20Tau27Filter", &mMatchesIsoMu20Tau27Filter); 
      Run_Tree->Branch("tMatchesIsoMu20Tau27Path", &tMatchesIsoMu20Tau27Path); 
      Run_Tree->Branch("tMatchesIsoMu20Tau27Filter", &tMatchesIsoMu20Tau27Filter); 
      Run_Tree->Branch("Mu20Tau27Pass", &Mu20Tau27Pass); 
      // Single Mu trigger 24
      Run_Tree->Branch("mMatchesIsoMu24Path", &mMatchesIsoMu24Path); 
      Run_Tree->Branch("mMatchesIsoMu24Filter", &mMatchesIsoMu24Filter); 
      Run_Tree->Branch("IsoMu24Pass", &IsoMu24Pass); 
      // Single Mu trigger 27
      Run_Tree->Branch("mMatchesIsoMu27Path", &mMatchesIsoMu27Path); 
      Run_Tree->Branch("mMatchesIsoMu27Filter", &mMatchesIsoMu27Filter); 
      Run_Tree->Branch("IsoMu27Pass", &IsoMu27Pass); 
    }
    else {
      Run_Tree->Branch("matchIsoMu22eta2p1_1", &matchIsoMu22eta2p1_1);
      Run_Tree->Branch("matchIsoTkMu22eta2p1_1", &matchIsoTkMu22eta2p1_1);
      Run_Tree->Branch("matchIsoMu22_1", &matchIsoMu22_1);
      Run_Tree->Branch("matchIsoTkMu22_1", &matchIsoTkMu22_1);
      Run_Tree->Branch("matchIsoMu24_1", &matchIsoMu24_1);
      Run_Tree->Branch("matchIsoTkMu24_1", &matchIsoTkMu24_1);
      Run_Tree->Branch("matchIsoMu19Tau20_1", &matchIsoMu19Tau20_1);
      Run_Tree->Branch("matchIsoMu21Tau20_1", &matchIsoMu21Tau20_1);
      Run_Tree->Branch("filterIsoMu22eta2p1_1", &filterIsoMu22eta2p1_1);
      Run_Tree->Branch("filterIsoTkMu22eta2p1_1", &filterIsoTkMu22eta2p1_1);
      Run_Tree->Branch("filterIsoMu22_1", &filterIsoMu22_1);
      Run_Tree->Branch("filterIsoTkMu22_1", &filterIsoTkMu22_1);
      Run_Tree->Branch("filterIsoMu24_1", &filterIsoMu24_1);
      Run_Tree->Branch("filterIsoTkMu24_1", &filterIsoTkMu24_1);
      Run_Tree->Branch("filterIsoMu19Tau20_1", &filterIsoMu19Tau20_1);
      Run_Tree->Branch("filterIsoMu21Tau20_1", &filterIsoMu21Tau20_1);
      Run_Tree->Branch("passIsoMu22eta2p1", &passIsoMu22eta2p1);
      Run_Tree->Branch("passIsoTkMu22eta2p1", &passIsoTkMu22eta2p1);
      Run_Tree->Branch("passIsoMu22", &passIsoMu22);
      Run_Tree->Branch("passIsoTkMu22", &passIsoTkMu22);
      Run_Tree->Branch("passIsoMu24", &passIsoMu24);
      Run_Tree->Branch("passIsoTkMu24", &passIsoTkMu24);
      Run_Tree->Branch("passIsoMu19Tau20", &passIsoMu19Tau20);
      Run_Tree->Branch("passIsoMu21Tau20", &passIsoMu21Tau20);
      Run_Tree->Branch("matchIsoMu19Tau20_2", &matchIsoMu19Tau20_2);
      Run_Tree->Branch("matchIsoMu21Tau20_2", &matchIsoMu21Tau20_2);
      Run_Tree->Branch("filterIsoMu19Tau20_2", &filterIsoMu19Tau20_2);
      Run_Tree->Branch("filterIsoMu21Tau20_2", &filterIsoMu21Tau20_2);
    }
    Run_Tree->Branch("pt_2", &pt_2);
    Run_Tree->Branch("phi_2", &phi_2);
    Run_Tree->Branch("eta_2", &eta_2);
    Run_Tree->Branch("m_2", &m_2);
    Run_Tree->Branch("e_2", &e_2);
    Run_Tree->Branch("q_2", &q_2);
    Run_Tree->Branch("l2_decayMode", &l2_decayMode);
    Run_Tree->Branch("againstElectronVLooseMVA6_2", &againstElectronVLooseMVA6_2);
    Run_Tree->Branch("againstMuonTight3_2", &againstMuonTight3_2);

    /////////////////////////    
    /// ISO Old DecayMode ///
    /////////////////////////        
    Run_Tree->Branch("byVLooseIsolationMVArun2v1DBoldDMwLT_2", &byVLooseIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byLooseIsolationMVArun2v1DBoldDMwLT_2", &byLooseIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byMediumIsolationMVArun2v1DBoldDMwLT_2", &byMediumIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byTightIsolationMVArun2v1DBoldDMwLT_2", &byTightIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byVTightIsolationMVArun2v1DBoldDMwLT_2", &byVTightIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("byVVTightIsolationMVArun2v1DBoldDMwLT_2", &byVVTightIsolationMVArun2v1DBoldDMwLT_2);
    Run_Tree->Branch("iso_2_old", &iso_2_old);
    //Run_Tree->Branch("byIsolationMVA3oldDMwLTraw_2", &byIsolationMVA3oldDMwLTraw_2);
    Run_Tree->Branch("decayModeFinding_2", &decayModeFinding_2);
    /////////////////////////    
    /// ISO New DecayMode ///
    /////////////////////////
    /*
    Run_Tree->Branch("byVLooseIsolationMVArun2v1DBnewDMwLT_2", &byVLooseIsolationMVArun2v1DBnewDMwLT_2);
    Run_Tree->Branch("byLooseIsolationMVArun2v1DBnewDMwLT_2", &byLooseIsolationMVArun2v1DBnewDMwLT_2);
    Run_Tree->Branch("byMediumIsolationMVArun2v1DBnewDMwLT_2", &byMediumIsolationMVArun2v1DBnewDMwLT_2);
    Run_Tree->Branch("byTightIsolationMVArun2v1DBnewDMwLT_2", &byTightIsolationMVArun2v1DBnewDMwLT_2);
    Run_Tree->Branch("byVTightIsolationMVArun2v1DBnewDMwLT_2", &byVTightIsolationMVArun2v1DBnewDMwLT_2);
    Run_Tree->Branch("byVVTightIsolationMVArun2v1DBnewDMwLT_2", &byVVTightIsolationMVArun2v1DBnewDMwLT_2);
    Run_Tree->Branch("iso_2_new", &iso_2_new);
    Run_Tree->Branch("decayModeFindingNewDMs_2", &decayModeFindingNewDMs_2);
    */
    //Run_Tree->Branch("byIsolationMVA3newDMwLTraw_2", &byIsolationMVA3newDMwLTraw_2);

    Run_Tree->Branch("numGenJets", &numGenJets);
    Run_Tree->Branch("jetPt_2", &jetPt_2);

    Run_Tree->Branch("pt_tt", &pt_tt);
    Run_Tree->Branch("m_vis", &m_vis);

    Run_Tree->Branch("pt_top1", &pt_top1);
    Run_Tree->Branch("pt_top2", &pt_top2);

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

    Run_Tree->Branch("mjj", &mjj);
    Run_Tree->Branch("jdeta", &jdeta);//, "jdeta/F");
    Run_Tree->Branch("mjj_JESUp", &mjj_JESUp);
    Run_Tree->Branch("mjj_JESDown", &mjj_JESDown);
    Run_Tree->Branch("gen_match_1", &gen_match_1);//, "gen_match_1/I");
    Run_Tree->Branch("gen_match_2", &gen_match_2);//, "gen_match_2/I");

    if (isMC){
      Run_Tree->Branch("njets_JetAbsoluteFlavMapDown", &njets_JetAbsoluteFlavMapDown);
      Run_Tree->Branch("mjj_JetAbsoluteFlavMapDown", &mjj_JetAbsoluteFlavMapDown);
      Run_Tree->Branch("njets_JetAbsoluteMPFBiasDown", &njets_JetAbsoluteMPFBiasDown);
      Run_Tree->Branch("mjj_JetAbsoluteMPFBiasDown", &mjj_JetAbsoluteMPFBiasDown);
      Run_Tree->Branch("njets_JetAbsoluteScaleDown", &njets_JetAbsoluteScaleDown);
      Run_Tree->Branch("mjj_JetAbsoluteScaleDown", &mjj_JetAbsoluteScaleDown);
      Run_Tree->Branch("njets_JetAbsoluteStatDown", &njets_JetAbsoluteStatDown);
      Run_Tree->Branch("mjj_JetAbsoluteStatDown", &mjj_JetAbsoluteStatDown);
      Run_Tree->Branch("njets_JetEnDown", &njets_JetEnDown);
      Run_Tree->Branch("mjj_JetEnDown", &mjj_JetEnDown);
      Run_Tree->Branch("njets_JetFlavorQCDDown", &njets_JetFlavorQCDDown);
      Run_Tree->Branch("mjj_JetFlavorQCDDown", &mjj_JetFlavorQCDDown);
      Run_Tree->Branch("njets_JetFragmentationDown", &njets_JetFragmentationDown);
      Run_Tree->Branch("mjj_JetFragmentationDown", &mjj_JetFragmentationDown);
      Run_Tree->Branch("njets_JetPileUpDataMCDown", &njets_JetPileUpDataMCDown);
      Run_Tree->Branch("mjj_JetPileUpDataMCDown", &mjj_JetPileUpDataMCDown);
      Run_Tree->Branch("njets_JetPileUpPtBBDown", &njets_JetPileUpPtBBDown);
      Run_Tree->Branch("mjj_JetPileUpPtBBDown", &mjj_JetPileUpPtBBDown);
      Run_Tree->Branch("njets_JetPileUpPtEC1Down", &njets_JetPileUpPtEC1Down);
      Run_Tree->Branch("mjj_JetPileUpPtEC1Down", &mjj_JetPileUpPtEC1Down);
      Run_Tree->Branch("njets_JetPileUpPtEC2Down", &njets_JetPileUpPtEC2Down);
      Run_Tree->Branch("mjj_JetPileUpPtEC2Down", &mjj_JetPileUpPtEC2Down);
      Run_Tree->Branch("njets_JetPileUpPtHFDown", &njets_JetPileUpPtHFDown);
      Run_Tree->Branch("mjj_JetPileUpPtHFDown", &mjj_JetPileUpPtHFDown);
      Run_Tree->Branch("njets_JetPileUpPtRefDown", &njets_JetPileUpPtRefDown);
      Run_Tree->Branch("mjj_JetPileUpPtRefDown", &mjj_JetPileUpPtRefDown);
      Run_Tree->Branch("njets_JetRelativeBalDown", &njets_JetRelativeBalDown);
      Run_Tree->Branch("mjj_JetRelativeBalDown", &mjj_JetRelativeBalDown);
      Run_Tree->Branch("njets_JetRelativeFSRDown", &njets_JetRelativeFSRDown);
      Run_Tree->Branch("mjj_JetRelativeFSRDown", &mjj_JetRelativeFSRDown);
      Run_Tree->Branch("njets_JetRelativeJEREC1Down", &njets_JetRelativeJEREC1Down);
      Run_Tree->Branch("mjj_JetRelativeJEREC1Down", &mjj_JetRelativeJEREC1Down);
      Run_Tree->Branch("njets_JetRelativeJEREC2Down", &njets_JetRelativeJEREC2Down);
      Run_Tree->Branch("mjj_JetRelativeJEREC2Down", &mjj_JetRelativeJEREC2Down);
      Run_Tree->Branch("njets_JetRelativeJERHFDown", &njets_JetRelativeJERHFDown);
      Run_Tree->Branch("mjj_JetRelativeJERHFDown", &mjj_JetRelativeJERHFDown);
      Run_Tree->Branch("njets_JetRelativePtBBDown", &njets_JetRelativePtBBDown);
      Run_Tree->Branch("mjj_JetRelativePtBBDown", &mjj_JetRelativePtBBDown);
      Run_Tree->Branch("njets_JetRelativePtEC1Down", &njets_JetRelativePtEC1Down);
      Run_Tree->Branch("mjj_JetRelativePtEC1Down", &mjj_JetRelativePtEC1Down);
      Run_Tree->Branch("njets_JetRelativePtEC2Down", &njets_JetRelativePtEC2Down);
      Run_Tree->Branch("mjj_JetRelativePtEC2Down", &mjj_JetRelativePtEC2Down);
      Run_Tree->Branch("njets_JetRelativePtHFDown", &njets_JetRelativePtHFDown);
      Run_Tree->Branch("mjj_JetRelativePtHFDown", &mjj_JetRelativePtHFDown);
      Run_Tree->Branch("njets_JetRelativeStatECDown", &njets_JetRelativeStatECDown);
      Run_Tree->Branch("mjj_JetRelativeStatECDown", &mjj_JetRelativeStatECDown);
      Run_Tree->Branch("njets_JetRelativeStatFSRDown", &njets_JetRelativeStatFSRDown);
      Run_Tree->Branch("mjj_JetRelativeStatFSRDown", &mjj_JetRelativeStatFSRDown);
      Run_Tree->Branch("njets_JetRelativeStatHFDown", &njets_JetRelativeStatHFDown);
      Run_Tree->Branch("mjj_JetRelativeStatHFDown", &mjj_JetRelativeStatHFDown);
      Run_Tree->Branch("njets_JetSinglePionECALDown", &njets_JetSinglePionECALDown);
      Run_Tree->Branch("mjj_JetSinglePionECALDown", &mjj_JetSinglePionECALDown);
      Run_Tree->Branch("njets_JetSinglePionHCALDown", &njets_JetSinglePionHCALDown);
      Run_Tree->Branch("mjj_JetSinglePionHCALDown", &mjj_JetSinglePionHCALDown);
      Run_Tree->Branch("njets_JetTimePtEtaDown", &njets_JetTimePtEtaDown);
      Run_Tree->Branch("mjj_JetTimePtEtaDown", &mjj_JetTimePtEtaDown);

      Run_Tree->Branch("njets_JetAbsoluteFlavMapUp", &njets_JetAbsoluteFlavMapUp);
      Run_Tree->Branch("mjj_JetAbsoluteFlavMapUp", &mjj_JetAbsoluteFlavMapUp);
      Run_Tree->Branch("njets_JetAbsoluteMPFBiasUp", &njets_JetAbsoluteMPFBiasUp);
      Run_Tree->Branch("mjj_JetAbsoluteMPFBiasUp", &mjj_JetAbsoluteMPFBiasUp);
      Run_Tree->Branch("njets_JetAbsoluteScaleUp", &njets_JetAbsoluteScaleUp);
      Run_Tree->Branch("mjj_JetAbsoluteScaleUp", &mjj_JetAbsoluteScaleUp);
      Run_Tree->Branch("njets_JetAbsoluteStatUp", &njets_JetAbsoluteStatUp);
      Run_Tree->Branch("mjj_JetAbsoluteStatUp", &mjj_JetAbsoluteStatUp);
      Run_Tree->Branch("njets_JetEnUp", &njets_JetEnUp);
      Run_Tree->Branch("mjj_JetEnUp", &mjj_JetEnUp);
      Run_Tree->Branch("njets_JetFlavorQCDUp", &njets_JetFlavorQCDUp);
      Run_Tree->Branch("mjj_JetFlavorQCDUp", &mjj_JetFlavorQCDUp);
      Run_Tree->Branch("njets_JetFragmentationUp", &njets_JetFragmentationUp);
      Run_Tree->Branch("mjj_JetFragmentationUp", &mjj_JetFragmentationUp);
      Run_Tree->Branch("njets_JetPileUpDataMCUp", &njets_JetPileUpDataMCUp);
      Run_Tree->Branch("mjj_JetPileUpDataMCUp", &mjj_JetPileUpDataMCUp);
      Run_Tree->Branch("njets_JetPileUpPtBBUp", &njets_JetPileUpPtBBUp);
      Run_Tree->Branch("mjj_JetPileUpPtBBUp", &mjj_JetPileUpPtBBUp);
      Run_Tree->Branch("njets_JetPileUpPtEC1Up", &njets_JetPileUpPtEC1Up);
      Run_Tree->Branch("mjj_JetPileUpPtEC1Up", &mjj_JetPileUpPtEC1Up);
      Run_Tree->Branch("njets_JetPileUpPtEC2Up", &njets_JetPileUpPtEC2Up);
      Run_Tree->Branch("mjj_JetPileUpPtEC2Up", &mjj_JetPileUpPtEC2Up);
      Run_Tree->Branch("njets_JetPileUpPtHFUp", &njets_JetPileUpPtHFUp);
      Run_Tree->Branch("mjj_JetPileUpPtHFUp", &mjj_JetPileUpPtHFUp);
      Run_Tree->Branch("njets_JetPileUpPtRefUp", &njets_JetPileUpPtRefUp);
      Run_Tree->Branch("mjj_JetPileUpPtRefUp", &mjj_JetPileUpPtRefUp);
      Run_Tree->Branch("njets_JetRelativeBalUp", &njets_JetRelativeBalUp);
      Run_Tree->Branch("mjj_JetRelativeBalUp", &mjj_JetRelativeBalUp);
      Run_Tree->Branch("njets_JetRelativeFSRUp", &njets_JetRelativeFSRUp);
      Run_Tree->Branch("mjj_JetRelativeFSRUp", &mjj_JetRelativeFSRUp);
      Run_Tree->Branch("njets_JetRelativeJEREC1Up", &njets_JetRelativeJEREC1Up);
      Run_Tree->Branch("mjj_JetRelativeJEREC1Up", &mjj_JetRelativeJEREC1Up);
      Run_Tree->Branch("njets_JetRelativeJEREC2Up", &njets_JetRelativeJEREC2Up);
      Run_Tree->Branch("mjj_JetRelativeJEREC2Up", &mjj_JetRelativeJEREC2Up);
      Run_Tree->Branch("njets_JetRelativeJERHFUp", &njets_JetRelativeJERHFUp);
      Run_Tree->Branch("mjj_JetRelativeJERHFUp", &mjj_JetRelativeJERHFUp);
      Run_Tree->Branch("njets_JetRelativePtBBUp", &njets_JetRelativePtBBUp);
      Run_Tree->Branch("mjj_JetRelativePtBBUp", &mjj_JetRelativePtBBUp);
      Run_Tree->Branch("njets_JetRelativePtEC1Up", &njets_JetRelativePtEC1Up);
      Run_Tree->Branch("mjj_JetRelativePtEC1Up", &mjj_JetRelativePtEC1Up);
      Run_Tree->Branch("njets_JetRelativePtEC2Up", &njets_JetRelativePtEC2Up);
      Run_Tree->Branch("mjj_JetRelativePtEC2Up", &mjj_JetRelativePtEC2Up);
      Run_Tree->Branch("njets_JetRelativePtHFUp", &njets_JetRelativePtHFUp);
      Run_Tree->Branch("mjj_JetRelativePtHFUp", &mjj_JetRelativePtHFUp);
      Run_Tree->Branch("njets_JetRelativeStatECUp", &njets_JetRelativeStatECUp);
      Run_Tree->Branch("mjj_JetRelativeStatECUp", &mjj_JetRelativeStatECUp);
      Run_Tree->Branch("njets_JetRelativeStatFSRUp", &njets_JetRelativeStatFSRUp);
      Run_Tree->Branch("mjj_JetRelativeStatFSRUp", &mjj_JetRelativeStatFSRUp);
      Run_Tree->Branch("njets_JetRelativeStatHFUp", &njets_JetRelativeStatHFUp);
      Run_Tree->Branch("mjj_JetRelativeStatHFUp", &mjj_JetRelativeStatHFUp);
      Run_Tree->Branch("njets_JetSinglePionECALUp", &njets_JetSinglePionECALUp);
      Run_Tree->Branch("mjj_JetSinglePionECALUp", &mjj_JetSinglePionECALUp);
      Run_Tree->Branch("njets_JetSinglePionHCALUp", &njets_JetSinglePionHCALUp);
      Run_Tree->Branch("mjj_JetSinglePionHCALUp", &mjj_JetSinglePionHCALUp);
      Run_Tree->Branch("njets_JetTimePtEtaUp", &njets_JetTimePtEtaUp);
      Run_Tree->Branch("mjj_JetTimePtEtaUp", &mjj_JetTimePtEtaUp);
    }

    Run_Tree->Branch("nbtag", &nbtag);
    Run_Tree->Branch("njets", &njets);
    Run_Tree->Branch("njetspt20", &njetspt20);
    //Run_Tree->Branch("njets_JESDown", &njets_JESDown);
    //Run_Tree->Branch("njetspt20_JESDown", &njetspt20_JESDown, "njetspt20_JESDown/I");
    //Run_Tree->Branch("njets_JESUp", &njets_JESUp);
    //Run_Tree->Branch("njetspt20_JESUp", &njetspt20_JESUp, "njetspt20_JESUp/I");
    Run_Tree->Branch("jpt_1", &jpt_1);
    Run_Tree->Branch("jeta_1", &jeta_1);
    Run_Tree->Branch("jphi_1", &jphi_1);
    Run_Tree->Branch("jcsv_1", &jcsv_1);

    Run_Tree->Branch("jpt_2", &jpt_2);
    Run_Tree->Branch("jeta_2", &jeta_2);
    Run_Tree->Branch("jphi_2", &jphi_2);
    Run_Tree->Branch("jcsv_2", &jcsv_2);

    Run_Tree->Branch("bpt_1", &bpt_1);
    Run_Tree->Branch("beta_1", &beta_1);
    Run_Tree->Branch("bphi_1", &bphi_1);
    Run_Tree->Branch("bcsv_1", &bcsv_1);
    Run_Tree->Branch("bflavor_1", &bflavor_1);

    Run_Tree->Branch("bpt_2", &bpt_2);
    Run_Tree->Branch("beta_2", &beta_2);
    Run_Tree->Branch("bphi_2", &bphi_2);
    Run_Tree->Branch("bcsv_2", &bcsv_2);
    Run_Tree->Branch("bflavor_2", &bflavor_2);

    Run_Tree->Branch("extraelec_veto", &extraelec_veto);
    Run_Tree->Branch("extramuon_veto", &extramuon_veto);
    Run_Tree->Branch("dilepton_veto", &dilepton_veto);
    
    Run_Tree->Branch("Flag_goodVertices", &Flag_goodVertices );
    Run_Tree->Branch("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter );
    Run_Tree->Branch("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter );
    Run_Tree->Branch("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter );
    Run_Tree->Branch("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter );
    Run_Tree->Branch("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter );
    Run_Tree->Branch("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter );
    Run_Tree->Branch("Flag_eeBadScFilter", &Flag_eeBadScFilter );
    Run_Tree->Branch("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter );

    int bestEntry=-1;
    float bestPT=-1;
    ULong64_t evt_now=0;
    ULong64_t evt_before=-1;
    float muiso_before=100;
    float tauiso_before=-1000;
    float mupt_before=0;
    float taupt_before=0;
    bool print=false;
    plotFill("nevents",0,9,0,9,evCounter->GetBinContent(1));
    plotFill("nevents",1,9,0,9,evCounterW->GetBinContent(1));
    for (int iEntry = 0; iEntry < tree->GetEntries() ; iEntry++)
    {
        float pu=1.0;
        tree->GetEntry(iEntry);
        bool print=false;
        if (iEntry % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d ", iEntry);
        fflush(stdout);
        //if (!isEmbedded && !tree->singleIsoTkMu24Pass && !tree->singleIsoMu24Pass) continue;
        TLorentzVector dau1;
        TLorentzVector dau2;
        dau1.SetPtEtaPhiM(tree->mPt,tree->mEta,tree->mPhi,tree->mMass);
        dau2.SetPtEtaPhiM(tree->tPt,tree->tEta,tree->tPhi,tree->tMass);
        if (isMC && tree->tDecayMode==0) dau2=dau2*0.982; //
        else if (isMC && tree->tDecayMode==1) dau2=dau2*1.010; //
        else if (isMC && tree->tDecayMode==10) dau2=dau2*1.004; //

	// Baseline selection https://www.dropbox.com/s/mb6e26affiodpn3/AN2016_355_v10.pdf?dl=0 page 22
	// line 443. No requirement on OS/SS @ skimming level
	if (seventeen && dau1.DeltaR(dau2) < 0.5) continue;
        if (!seventeen && tree->m_t_DR<0.5) continue;

	// loosen requirement on muon pT a bit for energy scale systematics  (by 5%) 
	// loosen tau pT and muon eta keeping Cécile's cut
	if (dau1.Pt() < 20./1.05 || fabs(dau1.Eta())>2.1) continue;
	if (dau2.Pt() < 20 || fabs(dau2.Eta())>2.3) continue;

	// line 460
	if (!tree->tDecayModeFinding) continue; // For QCD control region study Doyeong commented out this.
	//if (!tree->tDecayModeFindingNewDMs) continue; // For QCD control region study Doyeong tDecayModeFinding replaced to 
	
 	if (fabs(tree->tCharge)>1) continue;

	// line 456 && 464
	if (fabs(tree->mPVDXY)>0.045) continue;
        if (fabs(tree->mPVDZ)>0.2) continue;
        if (fabs(tree->tPVDZ)>0.2) continue;

	// line 465
	if (!tree->tAgainstMuonTight3) continue;//FIXME
        if (!tree->tAgainstElectronVLooseMVA6) continue;//FIXME
        
	//if (tree->mRelPFIsoDBDefaultR04>0.5) continue;//FIXME
	bool goodglob=tree->mIsGlobal && tree->mNormalizedChi2 < 3 && tree->mChi2LocalPosition < 12 && tree->mTrkKink < 20; 
	bool isMedium = tree->mPFIDLoose && tree->mValidFraction> 0.49 && tree->mSegmentCompatibility > (goodglob ? 0.303 : 0.451); 
        if (isMC && !tree->mPFIDMedium) continue;//FIXME
        if (isData && !tree->mPFIDMedium && !isMedium) continue;//FIXME
	if (!tree->tByVLooseIsolationMVArun2v1DBnewDMwLT) continue;

	evt_now=tree->evt;
	if (evt_now!=evt_before){
	   mupt_before=tree->mPt;
	   muiso_before=tree->mRelPFIsoDBDefaultR04;
	   taupt_before=tree->tPt;
	   tauiso_before=tree->tByIsolationMVArun2v1DBoldDMwLTraw;
	}
        if (evt_now!=evt_before){
           if (bestEntry>-1 && bestPT>29)
	     fillTree(Run_Tree,tree,bestEntry,recoil, isMC, seventeen);
           bestEntry=iEntry;
	   bestPT=dau2.Pt();
	}
	if (evt_now==evt_before){
	   if (tree->mRelPFIsoDBDefaultR04<muiso_before or (tree->mRelPFIsoDBDefaultR04==muiso_before && tree->mPt>mupt_before) or (tree->mRelPFIsoDBDefaultR04==muiso_before && tree->mPt==mupt_before && tree->tByIsolationMVArun2v1DBoldDMwLTraw>tauiso_before) or (tree->mRelPFIsoDBDefaultR04==muiso_before && tree->mPt==mupt_before && tree->tByIsolationMVArun2v1DBoldDMwLTraw==tauiso_before && tree->tPt>taupt_before) ){
		bestEntry=iEntry;
		bestPT=dau2.Pt();
	        muiso_before=tree->mRelPFIsoDBDefaultR04;
		mupt_before=tree->mPt;
		tauiso_before=tree->tByIsolationMVArun2v1DBoldDMwLTraw;
		taupt_before=tree->tPt;
	   }
	}
	evt_before=evt_now;
    }
    if (bestPT>29)
      fillTree(Run_Tree,tree,bestEntry,recoil,isMC,seventeen);
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

