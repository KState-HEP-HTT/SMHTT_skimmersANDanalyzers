#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>

// ROOT
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "TMultiGraph.h"
#include <TF1.h>
#include <TDirectoryFile.h>
#include <TRandom3.h>
#include "TLorentzVector.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TKey.h"
#include "THashList.h"
#include "THStack.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"

// User
#include "../include/ComputeWG1Unc.h"
#include "../include/myHelper.h"
#include "../include/tr_Tree.h"
#include "../include/ScaleFactor.h"
#include "../include/ZmmSF.h"
#include "../include/LumiReweightingStandAlone.h"
#include "../include/btagSF.h"
#include "../include/TMVAClassification_TMlpANN.cxx"
//#include "include/scenario_info.h"

typedef std::vector<double> NumV;

using namespace std;

int main(int argc, char** argv) {

    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string sample = *(argv + 3);
    std::string name = *(argv + 4);

    float tes=0;
    if (argc > 1) {
        tes = atof(argv[5]);
    }

    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    TTree *arbre = (TTree*) f_Double->Get("mutau_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);
    TTree* namu = new TTree("mutau_tree", "mutau_tree");
    namu->SetDirectory(0);

    namu->Branch("evtwt",&evtwt);

    namu->Branch("t1_pt",&t1_pt);
    namu->Branch("t1_eta", &t1_eta);
    namu->Branch("t1_phi", &t1_phi);
    namu->Branch("t1_mass", &t1_mass);
    namu->Branch("t1_charge", &t1_charge);
    namu->Branch("t1_decaymode", &t1_decaymode);

    namu->Branch("mu_pt", &mu_pt);
    namu->Branch("mu_eta", &mu_eta);
    namu->Branch("mu_phi", &mu_phi);
    namu->Branch("mu_mass", &mu_mass);
    namu->Branch("mu_charge", &mu_charge);

    namu->Branch("j1_pt",&j1_pt);
    namu->Branch("j1_eta", &j1_eta);
    namu->Branch("j1_phi", &j1_phi);
    namu->Branch("j2_pt", &j2_pt);
    namu->Branch("j2_eta", &j2_eta);
    namu->Branch("j2_phi", &j2_phi);

    namu->Branch("b1_pt",&b1_pt);
    namu->Branch("b1_eta", &b1_eta);
    namu->Branch("b1_phi", &b1_phi);
    namu->Branch("b2_pt", &b2_pt);
    namu->Branch("b2_eta", &b2_eta);
    namu->Branch("b2_phi", &b2_phi);
    namu->Branch("nbtag", &nbtag);

    namu->Branch("met",&met);
    namu->Branch("metphi",&metphi);
    namu->Branch("mjj",&mjj);
    
    namu->Branch("njets", &njets);
    namu->Branch("numGenJets",&numGenJets);

    namu->Branch("pt_sv", &pt_sv);
    namu->Branch("m_sv",&m_sv);
    namu->Branch("Dbkg_VBF",&Dbkg_VBF);
    namu->Branch("Dbkg_ggH",&Dbkg_ggH);
    
    namu->Branch("Phi"         , &Phi);
    namu->Branch("Phi1"        , &Phi1);
    namu->Branch("costheta1"   , &costheta1);
    namu->Branch("costheta2"   , &costheta2);
    namu->Branch("costhetastar", &costhetastar);
    namu->Branch("Q2V1"        , &Q2V1);
    namu->Branch("Q2V2"        , &Q2V2);

    namu->Branch("ME_sm_VBF"   , &ME_sm_VBF);
    namu->Branch("ME_sm_ggH"   , &ME_sm_ggH);
    namu->Branch("ME_bkg"   , &ME_bkg);

    namu->Branch("higgs_pT",      &higgs_pT);
    namu->Branch("higgs_m",       &higgs_m);
    namu->Branch("hjj_pT",        &hjj_pT);
    namu->Branch("hjj_m",         &hjj_m);
    namu->Branch("dEtajj",        &dEtajj);
    namu->Branch("dPhijj",        &dPhijj);
    namu->Branch("cat_0jet",      &cat_0jet);
    namu->Branch("cat_boosted",   &cat_boosted);
    namu->Branch("cat_vbf",       &cat_vbf);
    namu->Branch("cat_inclusive", &cat_inclusive);

    namu->Branch("is_signal", &is_signal);
    namu->Branch("is_qcd", &is_qcd);
    namu->Branch("mt", &mt);

    TFile *f_Trk=new TFile("../../../CommonAN/weightROOTs/Tracking_EfficienciesAndSF_BCDEFGH.root");
    TGraph *h_Trk=(TGraph*) f_Trk->Get("ratio_eff_eta3_dr030e030_corr");

    reweight::LumiReWeighting* LumiWeights_12;
    LumiWeights_12 = new reweight::LumiReWeighting("../../../CommonAN/weightROOTs/MC_Moriond17_PU25ns_V1.root", "../../../CommonAN/weightROOTs/Data_Pileup_2016_271036-284044_80bins.root", "pileup", "pileup");

    TFile *fZ=new TFile("../../../CommonAN/weightROOTs/zpt_weights_2016_BtoH.root");
    TH2F *histZ=(TH2F*) fZ->Get("zptmass_histo");

    TFile fw2("../../../CommonAN/weightROOTs/htt_scalefactors_sm_moriond_v1.root");
    RooWorkspace *w2 = (RooWorkspace*)fw2.Get("w");
    fw2.Close();

    float xs=1.0; float weight=1.0; float luminosity=35870.0;
    if (sample=="ZL" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL"){ xs=5765.4; weight=luminosity*xs/ngen;}
    else if (sample=="TT" or sample=="TTT" or sample=="TTJ") {xs=831.76; weight=luminosity*xs/ngen;}
    else if (sample=="W") {xs=61526.7; weight=luminosity*xs/ngen;}
    else if (sample=="QCD") {xs=720648000*0.00042; weight=luminosity*xs/ngen;}
    else if (sample=="data_obs"){weight=1.0;}
    else if (sample=="WZ1L1Nu2Q") {xs=10.71; weight=luminosity*xs/ngen;}
    else if (sample=="WZ1L3Nu") {xs=3.05; weight=luminosity*xs/ngen;}
    else if (sample=="WZJets") {xs=5.26; weight=luminosity*xs/ngen;}
    else if (sample=="WZLLLNu") {xs=4.708; weight=luminosity*xs/ngen;}
    else if (sample=="WZ2L2Q") {xs=5.595; weight=luminosity*xs/ngen;}
    else if (sample=="WW1L1Nu2Q") {xs=49.997; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L") {xs=1.212; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
    else if (sample=="VV2L2Nu") {xs=11.95; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_antitop") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_top") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_antitop") {xs=26.23; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_top") {xs=44.07; weight=luminosity*xs/ngen;}
    else if (sample=="ggh") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH125") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF125") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH120") {xs=52.22*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="VBF120") {xs=3.935*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ggH130") {xs=45.31*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="VBF130") {xs=3.637*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ggH110") {xs=57.90*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="VBF110") {xs=4.434*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ggH140") {xs=36.0*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="VBF140") {xs=3.492*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ggH_WW125") {xs=48.58*0.2137*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBF_WW125") {xs=3.782*0.2137*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH120") {xs=0.9558*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH125") {xs=0.840*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH130") {xs=0.7414*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH110") {xs=1.335*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH140") {xs=0.6308*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH120") {xs=0.6092*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH125") {xs=0.5328*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH130") {xs=0.4676*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH110") {xs=0.8587*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH140") {xs=0.394*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ZH120") {xs=0.9939*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ZH125") {xs=0.8839*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ZH130") {xs=0.7899*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ZH110") {xs=1.309*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ZH140") {xs=0.6514*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WGLNu") {xs=489.0; weight=luminosity*xs/ngen;}
    else if (sample=="WGstarMuMu") {xs=2.793; weight=luminosity*xs/ngen;}
    else if (sample=="WGstarEE") {xs=3.526; weight=luminosity*xs/ngen;}
    else if (sample=="EWKWminus") {xs=20.25; weight=luminosity*xs/ngen;}
    else if (sample=="EWKWplus") {xs=25.62; weight=luminosity*xs/ngen;}
    else if (sample=="EWKZLL" or sample=="EWKZLL_TT" or sample=="EWKZLL_J" or sample=="EWKZLL_L" or sample=="EWKZLL_LL") {xs=3.987; weight=luminosity*xs/ngen;}
    else if (sample=="EWKZNuNu" or sample=="EWKZNuNu_TT" or sample=="EWKZNuNu_J" or sample=="EWKZNuNu_L" or sample=="EWKZNuNu_LL") {xs=10.01; weight=luminosity*xs/ngen;}
    else cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    arbre->SetBranchAddress("Rivet_higgsPt", &Rivet_higgsPt);
    arbre->SetBranchAddress("Rivet_nJets30", &Rivet_nJets30);
    arbre->SetBranchAddress("Rivet_stage0_cat", &Rivet_stage0_cat);
    arbre->SetBranchAddress("Rivet_stage1_cat_pTjet30GeV", &Rivet_stage1_cat_pTjet30GeV);
    arbre->SetBranchAddress("run", &run);
    arbre->SetBranchAddress("lumi", &lumi);
    arbre->SetBranchAddress("evt", &evt);
    arbre->SetBranchAddress("npv", &npv);
    arbre->SetBranchAddress("px_1", &px_1);
    arbre->SetBranchAddress("py_1", &py_1);
    arbre->SetBranchAddress("pz_1", &pz_1);
    arbre->SetBranchAddress("pt_1", &pt_1);
    arbre->SetBranchAddress("phi_1", &phi_1);
    arbre->SetBranchAddress("eta_1", &eta_1);
    arbre->SetBranchAddress("iso_1", &iso_1);
    arbre->SetBranchAddress("m_1", &m_1);
    arbre->SetBranchAddress("q_1", &q_1);
    arbre->SetBranchAddress("id_m_medium_1", &id_m_medium_1);
    arbre->SetBranchAddress("id_m_medium2016_1", &id_m_medium2016_1);
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("q_2", &q_2);
    arbre->SetBranchAddress("px_2", &px_2);
    arbre->SetBranchAddress("py_2", &py_2);
    arbre->SetBranchAddress("pz_2", &pz_2);
    arbre->SetBranchAddress("pt_2", &pt_2);
    arbre->SetBranchAddress("eta_2", &eta_2);
    arbre->SetBranchAddress("m_2", &m_2);
    //arbre->SetBranchAddress("mt_2", &mt_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("met", &met);
    arbre->SetBranchAddress("metphi", &metphi);
    arbre->SetBranchAddress("m_sv", &m_sv);
    arbre->SetBranchAddress("m_sv_DOWN", &m_sv_DOWN);
    arbre->SetBranchAddress("m_sv_UP", &m_sv_UP);
    arbre->SetBranchAddress("pt_sv", &pt_sv);
    arbre->SetBranchAddress("pt_sv_DOWN", &pt_sv_DOWN);
    arbre->SetBranchAddress("pt_sv_UP", &pt_sv_UP);
    /*
    arbre->SetBranchAddress("m_sv_UncMet_DOWN", &m_sv_UncMet_DOWN);
    arbre->SetBranchAddress("m_sv_UncMet_UP", &m_sv_UncMet_UP);
    arbre->SetBranchAddress("m_sv_ClusteredMet_DOWN", &m_sv_ClusteredMet_DOWN);
    arbre->SetBranchAddress("m_sv_ClusteredMet_UP", &m_sv_ClusteredMet_UP);
    arbre->SetBranchAddress("pt_sv_UncMet_DOWN", &pt_sv_UncMet_DOWN);
    arbre->SetBranchAddress("pt_sv_UncMet_UP", &pt_sv_UncMet_UP);
    arbre->SetBranchAddress("pt_sv_ClusteredMet_DOWN", &pt_sv_ClusteredMet_DOWN);
    arbre->SetBranchAddress("pt_sv_ClusteredMet_UP", &pt_sv_ClusteredMet_UP);
    */
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("mjj", &mjj);
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("jeta_1", &jeta_1);
    arbre->SetBranchAddress("jphi_1", &jphi_1);
    arbre->SetBranchAddress("jpt_2", &jpt_2);
    arbre->SetBranchAddress("jeta_2", &jeta_2);
    arbre->SetBranchAddress("jphi_2", &jphi_2);

    arbre->SetBranchAddress("amcatNLO_weight", &amcatNLO_weight);
    arbre->SetBranchAddress("genweight", &genweight);
    /*
    arbre->SetBranchAddress("mjj_JESDown", &mjj_JESDown);
    arbre->SetBranchAddress("mjj_JESUp", &mjj_JESUp);
    arbre->SetBranchAddress("metphi_JESDown", &metphi_JESDown);
    arbre->SetBranchAddress("metphi_JESUp", &metphi_JESUp);
    arbre->SetBranchAddress("met_JESDown", &met_JESDown);
    arbre->SetBranchAddress("met_JESUp", &met_JESUp);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);
    arbre->SetBranchAddress("njets_JESDown", &njets_JESDown);
    arbre->SetBranchAddress("njets_JESUp", &njets_JESUp);
    */
    arbre->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_2",&byVLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationMVArun2v1DBoldDMwLT_2",&byLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationMVArun2v1DBoldDMwLT_2",&byMediumIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_2",&byTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationMVArun2v1DBoldDMwLT_2",&byVTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byIsolationMVA3oldDMwLTraw_2",&byIsolationMVA3oldDMwLTraw_2);

    arbre->SetBranchAddress("byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2", &byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationRerunMVArun2v1DBoldDMwLT_2", &byLooseIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationRerunMVArun2v1DBoldDMwLT_2", &byMediumIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationRerunMVArun2v1DBoldDMwLT_2", &byTightIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationRerunMVArun2v1DBoldDMwLT_2", &byVTightIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2", &byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byIsolationRerunMVA3oldDMwLTraw_2", &byIsolationRerunMVA3oldDMwLTraw_2);


    arbre->SetBranchAddress("matchIsoMu22eta2p1_1", &matchIsoMu22eta2p1_1);
    arbre->SetBranchAddress("matchIsoTkMu22eta2p1_1", &matchIsoTkMu22eta2p1_1);
    arbre->SetBranchAddress("matchIsoMu22_1", &matchIsoMu22_1);
    arbre->SetBranchAddress("matchIsoTkMu22_1", &matchIsoTkMu22_1);
    arbre->SetBranchAddress("matchIsoMu24_1", &matchIsoMu24_1);
    arbre->SetBranchAddress("matchIsoTkMu24_1", &matchIsoTkMu24_1);
    arbre->SetBranchAddress("matchIsoMu19Tau20_1", &matchIsoMu19Tau20_1);
    arbre->SetBranchAddress("matchIsoMu21Tau20_1", &matchIsoMu21Tau20_1);
    arbre->SetBranchAddress("filterIsoMu22eta2p1_1", &filterIsoMu22eta2p1_1);
    arbre->SetBranchAddress("filterIsoTkMu22eta2p1_1", &filterIsoTkMu22eta2p1_1);
    arbre->SetBranchAddress("filterIsoMu22_1", &filterIsoMu22_1);
    arbre->SetBranchAddress("filterIsoTkMu22_1", &filterIsoTkMu22_1);
    arbre->SetBranchAddress("filterIsoMu24_1", &filterIsoMu24_1);
    arbre->SetBranchAddress("filterIsoTkMu24_1", &filterIsoTkMu24_1);
    arbre->SetBranchAddress("filterIsoMu19Tau20_1", &filterIsoMu19Tau20_1);
    arbre->SetBranchAddress("filterIsoMu21Tau20_1", &filterIsoMu21Tau20_1);
    arbre->SetBranchAddress("passIsoMu22eta2p1", &passIsoMu22eta2p1);
    arbre->SetBranchAddress("passIsoTkMu22eta2p1", &passIsoTkMu22eta2p1);
    arbre->SetBranchAddress("passIsoMu22", &passIsoMu22);
    arbre->SetBranchAddress("passIsoTkMu22", &passIsoTkMu22);
    arbre->SetBranchAddress("passIsoMu24", &passIsoMu24);
    arbre->SetBranchAddress("passIsoTkMu24", &passIsoTkMu24);
    arbre->SetBranchAddress("passIsoMu19Tau20", &passIsoMu19Tau20);
    arbre->SetBranchAddress("passIsoMu21Tau20", &passIsoMu21Tau20);
    arbre->SetBranchAddress("matchIsoMu19Tau20_2", &matchIsoMu19Tau20_2);
    arbre->SetBranchAddress("matchIsoMu21Tau20_2", &matchIsoMu21Tau20_2);
    arbre->SetBranchAddress("filterIsoMu19Tau20_2", &filterIsoMu19Tau20_2);
    arbre->SetBranchAddress("filterIsoMu21Tau20_2", &filterIsoMu21Tau20_2);

    arbre->SetBranchAddress("l2_decayMode",&l2_decayMode);
    arbre->SetBranchAddress("againstElectronVLooseMVA6_2",&againstElectronVLooseMVA6_2);
    arbre->SetBranchAddress("againstMuonTight3_2",&againstMuonTight3_2);
    arbre->SetBranchAddress("gen_match_1",&gen_match_1);
    arbre->SetBranchAddress("gen_match_2",&gen_match_2);
    //arbre->SetBranchAddress("m_vis",&m_vis);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("genpT",&genpT);
    arbre->SetBranchAddress("genM",&genM);
    arbre->SetBranchAddress("pt_top1",&pt_top1);
    arbre->SetBranchAddress("pt_top2",&pt_top2);
    arbre->SetBranchAddress("tZTTGenDR",&tZTTGenDR);
    arbre->SetBranchAddress("numGenJets",&numGenJets);
    arbre->SetBranchAddress("bpt_1",&bpt_1);
    arbre->SetBranchAddress("beta_1",&beta_1);
    arbre->SetBranchAddress("bphi_1",&bphi_1);
    arbre->SetBranchAddress("bpt_2",&bpt_2);
    arbre->SetBranchAddress("beta_2",&beta_2);
    arbre->SetBranchAddress("bphi_2",&bphi_2);
    arbre->SetBranchAddress("bflavor_1",&bflavor_1);
    arbre->SetBranchAddress("bflavor_2",&bflavor_2);

    arbre->SetBranchAddress("njets_JetAbsoluteFlavMapDown",&njets_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("njets_JetAbsoluteFlavMapUp",&njets_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("njets_JetAbsoluteMPFBiasDown",&njets_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("njets_JetAbsoluteMPFBiasUp",&njets_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("njets_JetAbsoluteScaleDown",&njets_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("njets_JetAbsoluteScaleUp",&njets_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("njets_JetAbsoluteStatDown",&njets_JetAbsoluteStatDown);
    arbre->SetBranchAddress("njets_JetAbsoluteStatUp",&njets_JetAbsoluteStatUp);
    arbre->SetBranchAddress("njets_JetFlavorQCDDown",&njets_JetFlavorQCDDown);
    arbre->SetBranchAddress("njets_JetFlavorQCDUp",&njets_JetFlavorQCDUp);
    arbre->SetBranchAddress("njets_JetFragmentationDown",&njets_JetFragmentationDown);
    arbre->SetBranchAddress("njets_JetFragmentationUp",&njets_JetFragmentationUp);
    arbre->SetBranchAddress("njets_JetPileUpDataMCDown",&njets_JetPileUpDataMCDown);
    arbre->SetBranchAddress("njets_JetPileUpDataMCUp",&njets_JetPileUpDataMCUp);
    arbre->SetBranchAddress("njets_JetPileUpPtBBDown",&njets_JetPileUpPtBBDown);
    arbre->SetBranchAddress("njets_JetPileUpPtBBUp",&njets_JetPileUpPtBBUp);
    arbre->SetBranchAddress("njets_JetPileUpPtEC1Down",&njets_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("njets_JetPileUpPtEC1Up",&njets_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("njets_JetPileUpPtEC2Down",&njets_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("njets_JetPileUpPtEC2Up",&njets_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("njets_JetPileUpPtHFDown",&njets_JetPileUpPtHFDown);
    arbre->SetBranchAddress("njets_JetPileUpPtHFUp",&njets_JetPileUpPtHFUp);
    arbre->SetBranchAddress("njets_JetPileUpPtRefDown",&njets_JetPileUpPtRefDown);
    arbre->SetBranchAddress("njets_JetPileUpPtRefUp",&njets_JetPileUpPtRefUp);
    arbre->SetBranchAddress("njets_JetRelativeBalDown",&njets_JetRelativeBalDown);
    arbre->SetBranchAddress("njets_JetRelativeBalUp",&njets_JetRelativeBalUp);
    arbre->SetBranchAddress("njets_JetRelativeFSRDown",&njets_JetRelativeFSRDown);
    arbre->SetBranchAddress("njets_JetRelativeFSRUp",&njets_JetRelativeFSRUp);
    arbre->SetBranchAddress("njets_JetRelativeJEREC1Down",&njets_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("njets_JetRelativeJEREC1Up",&njets_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("njets_JetRelativeJEREC2Down",&njets_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("njets_JetRelativeJEREC2Up",&njets_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("njets_JetRelativeJERHFDown",&njets_JetRelativeJERHFDown);
    arbre->SetBranchAddress("njets_JetRelativeJERHFUp",&njets_JetRelativeJERHFUp);
    arbre->SetBranchAddress("njets_JetRelativePtBBDown",&njets_JetRelativePtBBDown);
    arbre->SetBranchAddress("njets_JetRelativePtBBUp",&njets_JetRelativePtBBUp);
    arbre->SetBranchAddress("njets_JetRelativePtEC1Down",&njets_JetRelativePtEC1Down);
    arbre->SetBranchAddress("njets_JetRelativePtEC1Up",&njets_JetRelativePtEC1Up);
    arbre->SetBranchAddress("njets_JetRelativePtEC2Down",&njets_JetRelativePtEC2Down);
    arbre->SetBranchAddress("njets_JetRelativePtEC2Up",&njets_JetRelativePtEC2Up);
    arbre->SetBranchAddress("njets_JetRelativePtHFDown",&njets_JetRelativePtHFDown);
    arbre->SetBranchAddress("njets_JetRelativePtHFUp",&njets_JetRelativePtHFUp);
    arbre->SetBranchAddress("njets_JetRelativeStatECDown",&njets_JetRelativeStatECDown);
    arbre->SetBranchAddress("njets_JetRelativeStatECUp",&njets_JetRelativeStatECUp);
    arbre->SetBranchAddress("njets_JetRelativeStatFSRDown",&njets_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("njets_JetRelativeStatFSRUp",&njets_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("njets_JetRelativeStatHFDown",&njets_JetRelativeStatHFDown);
    arbre->SetBranchAddress("njets_JetRelativeStatHFUp",&njets_JetRelativeStatHFUp);
    arbre->SetBranchAddress("njets_JetSinglePionECALDown",&njets_JetSinglePionECALDown);
    arbre->SetBranchAddress("njets_JetSinglePionECALUp",&njets_JetSinglePionECALUp);
    arbre->SetBranchAddress("njets_JetSinglePionHCALDown",&njets_JetSinglePionHCALDown);
    arbre->SetBranchAddress("njets_JetSinglePionHCALUp",&njets_JetSinglePionHCALUp);
    arbre->SetBranchAddress("njets_JetTimePtEtaDown",&njets_JetTimePtEtaDown);
    arbre->SetBranchAddress("njets_JetTimePtEtaUp",&njets_JetTimePtEtaUp);

    arbre->SetBranchAddress("mjj_JetAbsoluteFlavMapDown",&mjj_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteFlavMapUp",&mjj_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteMPFBiasDown",&mjj_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteMPFBiasUp",&mjj_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteScaleDown",&mjj_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteScaleUp",&mjj_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("mjj_JetAbsoluteStatDown",&mjj_JetAbsoluteStatDown);
    arbre->SetBranchAddress("mjj_JetAbsoluteStatUp",&mjj_JetAbsoluteStatUp);
    arbre->SetBranchAddress("mjj_JetFlavorQCDDown",&mjj_JetFlavorQCDDown);
    arbre->SetBranchAddress("mjj_JetFlavorQCDUp",&mjj_JetFlavorQCDUp);
    arbre->SetBranchAddress("mjj_JetFragmentationDown",&mjj_JetFragmentationDown);
    arbre->SetBranchAddress("mjj_JetFragmentationUp",&mjj_JetFragmentationUp);
    arbre->SetBranchAddress("mjj_JetPileUpDataMCDown",&mjj_JetPileUpDataMCDown);
    arbre->SetBranchAddress("mjj_JetPileUpDataMCUp",&mjj_JetPileUpDataMCUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtBBDown",&mjj_JetPileUpPtBBDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtBBUp",&mjj_JetPileUpPtBBUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC1Down",&mjj_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC1Up",&mjj_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC2Down",&mjj_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("mjj_JetPileUpPtEC2Up",&mjj_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("mjj_JetPileUpPtHFDown",&mjj_JetPileUpPtHFDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtHFUp",&mjj_JetPileUpPtHFUp);
    arbre->SetBranchAddress("mjj_JetPileUpPtRefDown",&mjj_JetPileUpPtRefDown);
    arbre->SetBranchAddress("mjj_JetPileUpPtRefUp",&mjj_JetPileUpPtRefUp);
    arbre->SetBranchAddress("mjj_JetRelativeBalDown",&mjj_JetRelativeBalDown);
    arbre->SetBranchAddress("mjj_JetRelativeBalUp",&mjj_JetRelativeBalUp);
    arbre->SetBranchAddress("mjj_JetRelativeFSRDown",&mjj_JetRelativeFSRDown);
    arbre->SetBranchAddress("mjj_JetRelativeFSRUp",&mjj_JetRelativeFSRUp);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC1Down",&mjj_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC1Up",&mjj_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC2Down",&mjj_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("mjj_JetRelativeJEREC2Up",&mjj_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("mjj_JetRelativeJERHFDown",&mjj_JetRelativeJERHFDown);
    arbre->SetBranchAddress("mjj_JetRelativeJERHFUp",&mjj_JetRelativeJERHFUp);
    arbre->SetBranchAddress("mjj_JetRelativePtBBDown",&mjj_JetRelativePtBBDown);
    arbre->SetBranchAddress("mjj_JetRelativePtBBUp",&mjj_JetRelativePtBBUp);
    arbre->SetBranchAddress("mjj_JetRelativePtEC1Down",&mjj_JetRelativePtEC1Down);
    arbre->SetBranchAddress("mjj_JetRelativePtEC1Up",&mjj_JetRelativePtEC1Up);
    arbre->SetBranchAddress("mjj_JetRelativePtEC2Down",&mjj_JetRelativePtEC2Down);
    arbre->SetBranchAddress("mjj_JetRelativePtEC2Up",&mjj_JetRelativePtEC2Up);
    arbre->SetBranchAddress("mjj_JetRelativePtHFDown",&mjj_JetRelativePtHFDown);
    arbre->SetBranchAddress("mjj_JetRelativePtHFUp",&mjj_JetRelativePtHFUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatECDown",&mjj_JetRelativeStatECDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatECUp",&mjj_JetRelativeStatECUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatFSRDown",&mjj_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatFSRUp",&mjj_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("mjj_JetRelativeStatHFDown",&mjj_JetRelativeStatHFDown);
    arbre->SetBranchAddress("mjj_JetRelativeStatHFUp",&mjj_JetRelativeStatHFUp);
    arbre->SetBranchAddress("mjj_JetSinglePionECALDown",&mjj_JetSinglePionECALDown);
    arbre->SetBranchAddress("mjj_JetSinglePionECALUp",&mjj_JetSinglePionECALUp);
    arbre->SetBranchAddress("mjj_JetSinglePionHCALDown",&mjj_JetSinglePionHCALDown);
    arbre->SetBranchAddress("mjj_JetSinglePionHCALUp",&mjj_JetSinglePionHCALUp);
    arbre->SetBranchAddress("mjj_JetTimePtEtaDown",&mjj_JetTimePtEtaDown);
    arbre->SetBranchAddress("mjj_JetTimePtEtaUp",&mjj_JetTimePtEtaUp);

    arbre->SetBranchAddress("extraelec_veto", &extraelec_veto);
    arbre->SetBranchAddress("extramuon_veto", &extramuon_veto);
    arbre->SetBranchAddress("dilepton_veto", &dilepton_veto);

    arbre->SetBranchAddress("ME_sm_VBF",&ME_sm_VBF);
    arbre->SetBranchAddress("ME_sm_ggH",&ME_sm_ggH);
    arbre->SetBranchAddress("ME_bkg",&ME_bkg);
    
    arbre->SetBranchAddress("Dbkg_ggH", &Dbkg_ggH);
    arbre->SetBranchAddress("Dbkg_VBF", &Dbkg_VBF);

    arbre->SetBranchAddress("Phi"         , &Phi);
    arbre->SetBranchAddress("Phi1"        , &Phi1);
    arbre->SetBranchAddress("costheta1"   , &costheta1);
    arbre->SetBranchAddress("costheta2"   , &costheta2);
    arbre->SetBranchAddress("costhetastar", &costhetastar);
    arbre->SetBranchAddress("Q2V1"        , &Q2V1);
    arbre->SetBranchAddress("Q2V2"        , &Q2V2);


    // Construct scenario
    //scenario_info scenario(arbre, unc);

    float bins0[] = {0,60,65,70,75,80,85,90,95,100,105,110,400};
    //float bins0[] = {50,55,60,65,70,75,80,85,90,95,100,105,110,115,120}; // for 2D plot
    //float bins0[] = {0,60,70,80,90,100,110,400};
    float bins1[] = {0,80,90,100,110,120,130,140,150,160,300};
    //float bins1[] = {40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200}; // for 2D p
    float bins2[] = {0,95,115,135,155,400};
    
    float bins_pth[] = {0,100,150,200,250,300,5000};
    //float bins_pth[] = {0,25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400}; //for 2D
    float bins_mjj[] = {300,700,1100,1500,10000};
    //float bins_mjj[] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
    //float bins_taupt[] = {30,35,40,45,50,55,300};
    //float bins_taupt[] = {30,35,40,300};
    float bins_taupt[] = {0,1,10,11};
    
    int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;
    int  binnum2 = sizeof(bins2)/sizeof(Float_t) - 1;
    int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
    int  binnum_pth = sizeof(bins_pth)/sizeof(Float_t) - 1;
    int  binnum_taupt = sizeof(bins_taupt)/sizeof(Float_t) - 1;
    int  binnum_mjj = sizeof(bins_mjj)/sizeof(Float_t) - 1;
    
    TH1F *hincl=new TH1F ("hincl", "hincl", 16,0,160); hincl->Sumw2();
    TH1F *nlowhigh=new TH1F ("nlowhigh", "nlowhigh", 6,0,6);nlowhigh->Sumw2();
    
    TH1F *mUESUp_0jet=new TH1F ("mUESUp_0jet", "mUESUp_0jet", 100,-0.10,0.10);mUESUp_0jet->Sumw2();
    TH1F *mUESDown_0jet=new TH1F ("mUESDown_0jet", "mUESDown_0jet", 100,-0.10,0.10);mUESDown_0jet->Sumw2();
    TH1F *mCESUp_0jet=new TH1F ("mCESUp_0jet", "mCESUp_0jet", 100,-0.10,0.10);mCESUp_0jet->Sumw2();
    TH1F *mCESDown_0jet=new TH1F ("mCESDown_0jet", "mCESDown_0jet", 100,-0.10,0.10);mCESDown_0jet->Sumw2();
    TH1F *mTESUp_0jet=new TH1F ("mTESUp_0jet", "mTESUp_0jet", 100,-0.10,0.10);mTESUp_0jet->Sumw2();
    TH1F *mTESDown_0jet=new TH1F ("mTESDown_0jet", "mTESDown_0jet", 100,-0.10,0.10);mTESDown_0jet->Sumw2();
    
    TH1F *mUESUp_boosted=new TH1F ("mUESUp_boosted", "mUESUp_boosted", 100,-0.10,0.10);mUESUp_boosted->Sumw2();
    TH1F *mUESDown_boosted=new TH1F ("mUESDown_boosted", "mUESDown_boosted", 100,-0.10,0.10);mUESDown_boosted->Sumw2();
    TH1F *mCESUp_boosted=new TH1F ("mCESUp_boosted", "mCESUp_boosted", 100,-0.10,0.10);mCESUp_boosted->Sumw2();
    TH1F *mCESDown_boosted=new TH1F ("mCESDown_boosted", "mCESDown_boosted", 100,-0.10,0.10);mCESDown_boosted->Sumw2();
    TH1F *mTESUp_boosted=new TH1F ("mTESUp_boosted", "mTESUp_boosted", 100,-0.10,0.10);mTESUp_boosted->Sumw2();
    TH1F *mTESDown_boosted=new TH1F ("mTESDown_boosted", "mTESDown_boosted", 100,-0.10,0.10);mTESDown_boosted->Sumw2();
    
    TH1F *mUESUp_vbf=new TH1F ("mUESUp_vbf", "mUESUp_vbf", 100,-0.10,0.10);mUESUp_vbf->Sumw2();
    TH1F *mUESDown_vbf=new TH1F ("mUESDown_vbf", "mUESDown_vbf", 100,-0.10,0.10);mUESDown_vbf->Sumw2();
    TH1F *mCESUp_vbf=new TH1F ("mCESUp_vbf", "mCESUp_vbf", 100,-0.10,0.10);mCESUp_vbf->Sumw2();
    TH1F *mCESDown_vbf=new TH1F ("mCESDown_vbf", "mCESDown_vbf", 100,-0.10,0.10);mCESDown_vbf->Sumw2();
    TH1F *mTESUp_vbf=new TH1F ("mTESUp_vbf", "mTESUp_vbf", 100,-0.10,0.10);mTESUp_vbf->Sumw2();
    TH1F *mTESDown_vbf=new TH1F ("mTESDown_vbf", "mTESDown_vbf", 100,-0.10,0.10);mTESDown_vbf->Sumw2();
    
    //TH2F* HiggspT=new TH2F ("HiggspT","HiggspT",25,0,500,25,0,500);
    TH2F* HiggspT=new TH2F ("HiggspT","HiggspT",40,0,200,40,0,200);
    
    TH2F* pteta_0jet=new TH2F ("pteta_0jet","pteta_0jet",30,30,180,5,0,2.3);
    TH2F* pteta_boosted_1=new TH2F ("pteta_boosted_1","pteta_boosted_1",30,30,180,5,0,2.3);
    TH2F* pteta_boosted_2=new TH2F ("pteta_boosted_2","pteta_boosted_2",30,30,180,5,0,2.3);
    TH2F* pteta_boosted_3=new TH2F ("pteta_boosted_3","pteta_boosted_3",30,30,180,5,0,2.3);
    TH2F* pteta_boosted_4=new TH2F ("pteta_boosted_4","pteta_boosted_4",30,30,280,5,0,2.3);
    TH2F* pteta_boosted_5=new TH2F ("pteta_boosted_5","pteta_boosted_5",30,30,180,5,0,2.3);
    TH2F* pteta_boosted_6=new TH2F ("pteta_boosted_6","pteta_boosted_6",30,30,180,5,0,2.3);
    TH2F* pteta_vbf_1=new TH2F ("pteta_vbf_1","pteta_vbf_1",30,30,180,5,0,2.3);
    TH2F* pteta_vbf_2=new TH2F ("pteta_vbf_2","pteta_vbf_2",30,30,180,5,0,2.3);
    TH2F* pteta_vbf_3=new TH2F ("pteta_vbf_3","pteta_vbf_3",30,30,180,5,0,2.3);
    TH2F* pteta_vbf_4=new TH2F ("pteta_vbf_4","pteta_vbf_4",30,30,180,5,0,2.3);
    
    TH2F* h2D_0jet=new TH2F ("h2D_0jet","h2D_0jet",14,50,120,3,0,3);
    TH2F* h2D_boosted=new TH2F ("h2D_boosted","h2D_boosted",18,20,200,16,0,400);
    TH2F* h2D_vbf=new TH2F ("h2D_vbf","h2D_vbf",14,18,200,10,300,1800);
    
    std::vector<TH1F*> n70;
    std::vector<TH1F*> n70SS;
    
    std::vector<TH1F*> h0_CR_W;
    std::vector<TH1F*> h0_CR_QCD;
    std::vector<TH1F*> h0_CRSS_W;
    std::vector<TH1F*> h0_CRSS_QCD;
    std::vector<TH1F*> h1_CR_W;
    std::vector<TH1F*> h1_CR_QCD;
    std::vector<TH1F*> h1_CRSS_W;
    std::vector<TH1F*> h1_CRSS_QCD;
    std::vector<TH1F*> h2_CR_W;
    std::vector<TH1F*> h2_CR_QCD;
    std::vector<TH1F*> h2_CRSS_W;
    std::vector<TH1F*> h2_CRSS_QCD;
    
    std::vector<TH2F*> h0_OS;
    std::vector<TH2F*> h1_OS;
    std::vector<TH2F*> h2_OS;
    std::vector<TH2F*> h0_SS;
    std::vector<TH2F*> h1_SS;
    std::vector<TH2F*> h2_SS;
    std::vector<TH2F*> h0_QCD;
    std::vector<TH2F*> h1_QCD;
    std::vector<TH2F*> h2_QCD;
    std::vector<TH2F*> h0_WOS;
    std::vector<TH2F*> h1_WOS;
    std::vector<TH2F*> h2_WOS;
    std::vector<TH2F*> h0_WSS;
    std::vector<TH2F*> h1_WSS;
    std::vector<TH2F*> h2_WSS;
    
    
    
    int nbhist=1;
    if (tes==1000) nbhist=18;
    if (tes==100) nbhist=56;
    if (tes==1) nbhist=12;
    if (tes==16) nbhist=6;
    if (tes==17) nbhist=12;
    if (tes==18) nbhist=4;
    if (tes==19) nbhist=6;
    
    for (int k=0; k<nbhist; ++k){
      ostringstream HNn70; HNn70 << "n70" << k;
      ostringstream HNn70SS; HNn70SS << "n70SS" << k;
      n70.push_back(new TH1F (HNn70.str().c_str(),"",18,0,18)); n70[k]->Sumw2();
      n70SS.push_back(new TH1F (HNn70SS.str().c_str(),"",18,0,18)); n70SS[k]->Sumw2();

      ostringstream HNS0CRQCD; HNS0CRQCD << "h0_CR_QCD" << k;
      ostringstream HNS1CRQCD; HNS1CRQCD << "h1_CR_QCD" << k;
      ostringstream HNS2CRQCD; HNS2CRQCD << "h2_CR_QCD" << k;
      h0_CR_QCD.push_back(new TH1F (HNS0CRQCD.str().c_str(),"I",4,40,200)); h0_CR_QCD[k]->Sumw2();
      h1_CR_QCD.push_back(new TH1F (HNS1CRQCD.str().c_str(),"I",4,40,200)); h1_CR_QCD[k]->Sumw2();
      h2_CR_QCD.push_back(new TH1F (HNS2CRQCD.str().c_str(),"I",4,40,200)); h2_CR_QCD[k]->Sumw2();
      
      ostringstream HNS0CRW; HNS0CRW << "h0_CR_W" << k;
      ostringstream HNS1CRW; HNS1CRW << "h1_CR_W" << k;
      ostringstream HNS2CRW; HNS2CRW << "h2_CR_W" << k;
      h0_CR_W.push_back(new TH1F (HNS0CRW.str().c_str(),"I",1,80,200)); h0_CR_W[k]->Sumw2();
      h1_CR_W.push_back(new TH1F (HNS1CRW.str().c_str(),"I",1,80,200)); h1_CR_W[k]->Sumw2();
      h2_CR_W.push_back(new TH1F (HNS2CRW.str().c_str(),"I",1,80,200)); h2_CR_W[k]->Sumw2();
      
      ostringstream HNS0CRSSQCD; HNS0CRSSQCD << "h0_CRSS_QCD" << k;
      ostringstream HNS1CRSSQCD; HNS1CRSSQCD << "h1_CRSS_QCD" << k;
      ostringstream HNS2CRSSQCD; HNS2CRSSQCD << "h2_CRSS_QCD" << k;
      h0_CRSS_QCD.push_back(new TH1F (HNS0CRSSQCD.str().c_str(),"I",4,40,200)); h0_CRSS_QCD[k]->Sumw2();
      h1_CRSS_QCD.push_back(new TH1F (HNS1CRSSQCD.str().c_str(),"I",4,40,200)); h1_CRSS_QCD[k]->Sumw2();
      h2_CRSS_QCD.push_back(new TH1F (HNS2CRSSQCD.str().c_str(),"I",4,40,200)); h2_CRSS_QCD[k]->Sumw2();
      
      ostringstream HNS0CRSSW; HNS0CRSSW << "h0_CRSS_W" << k;
      ostringstream HNS1CRSSW; HNS1CRSSW << "h1_CRSS_W" << k;
      ostringstream HNS2CRSSW; HNS2CRSSW << "h2_CRSS_W" << k;
      h0_CRSS_W.push_back(new TH1F (HNS0CRSSW.str().c_str(),"I",1,80,200)); h0_CRSS_W[k]->Sumw2();
      h1_CRSS_W.push_back(new TH1F (HNS1CRSSW.str().c_str(),"I",1,80,200)); h1_CRSS_W[k]->Sumw2();
      h2_CRSS_W.push_back(new TH1F (HNS2CRSSW.str().c_str(),"I",1,80,200)); h2_CRSS_W[k]->Sumw2();
    }
    // binnum_mjj,bins_mjj,binnum2,bins2
    for (int k=0; k<nbhist; ++k){
      ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
      ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
      ostringstream HNS2OS; HNS2OS << "h2_OS" << k;
      h0_OS.push_back(new TH2F (HNS0OS.str().c_str(),"",binnum_taupt,bins_taupt,binnum0,bins0)); h0_OS[k]->Sumw2();
      h1_OS.push_back(new TH2F (HNS1OS.str().c_str(),"",binnum_pth,bins_pth,binnum1,bins1)); h1_OS[k]->Sumw2();
      h2_OS.push_back(new TH2F (HNS2OS.str().c_str(),"",binnum_mjj,bins_mjj,binnum2,bins2)); h2_OS[k]->Sumw2();
      
      ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
      ostringstream HNS1SS; HNS1OS << "h1_SS" << k;
      ostringstream HNS2SS; HNS2OS << "h2_SS" << k;
      h0_SS.push_back(new TH2F (HNS0SS.str().c_str(),"",binnum_taupt,bins_taupt,binnum0,bins0)); h0_SS[k]->Sumw2();
      h1_SS.push_back(new TH2F (HNS1SS.str().c_str(),"",binnum_pth,bins_pth,binnum1,bins1)); h1_SS[k]->Sumw2();
      h2_SS.push_back(new TH2F (HNS2SS.str().c_str(),"",binnum_mjj,bins_mjj,binnum2,bins2)); h2_SS[k]->Sumw2();

      ostringstream HNS0QCD; HNS0QCD << "h0_QCD" << k;
      ostringstream HNS1QCD; HNS1QCD << "h1_QCD" << k;
      ostringstream HNS2QCD; HNS2QCD << "h2_QCD" << k;
      h0_QCD.push_back(new TH2F (HNS0QCD.str().c_str(),"",binnum_taupt,bins_taupt,binnum0,bins0)); h0_QCD[k]->Sumw2();
      h1_QCD.push_back(new TH2F (HNS1QCD.str().c_str(),"",binnum_pth,bins_pth,binnum1,bins1)); h1_QCD[k]->Sumw2();
      h2_QCD.push_back(new TH2F (HNS2QCD.str().c_str(),"",binnum_mjj,bins_mjj,binnum2,bins2)); h2_QCD[k]->Sumw2();

      ostringstream HNS0WSS; HNS0WSS << "h0_WSS" << k;
      ostringstream HNS1WSS; HNS1WSS << "h1_WSS" << k;
      ostringstream HNS2WSS; HNS2WSS << "h2_WSS" << k;
      h0_WSS.push_back(new TH2F (HNS0WSS.str().c_str(),"",binnum_taupt,bins_taupt,binnum0,bins0)); h0_WSS[k]->Sumw2();
      h1_WSS.push_back(new TH2F (HNS1WSS.str().c_str(),"",binnum_pth,bins_pth,binnum1,bins1));h1_WSS[k]->Sumw2();
      h2_WSS.push_back(new TH2F (HNS2WSS.str().c_str(),"",binnum_mjj,bins_mjj,binnum2,bins2));h2_WSS[k]->Sumw2();

      ostringstream HNS0WOS; HNS0WOS << "h0_WOS" << k;
      ostringstream HNS1WOS; HNS1WOS << "h1_WOS" << k;
      ostringstream HNS2WOS; HNS2WOS << "h2_WOS" << k;
      h0_WOS.push_back(new TH2F (HNS0WOS.str().c_str(),"",binnum_taupt,bins_taupt,binnum0,bins0)); h0_WOS[k]->Sumw2();
      h1_WOS.push_back(new TH2F (HNS1WOS.str().c_str(),"",binnum_pth,bins_pth,binnum1,bins1)); h1_WOS[k]->Sumw2();
      h2_WOS.push_back(new TH2F (HNS2WOS.str().c_str(),"",binnum_mjj,bins_mjj,binnum2,bins2)); h2_WOS[k]->Sumw2();
    }
    
    
    ScaleFactor * myScaleFactor_trgMu24 = new ScaleFactor();
    myScaleFactor_trgMu24->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_IsoMu24_OR_TkIsoMu24_2016BtoH_eff.root");
    ScaleFactor * myScaleFactor_trgMu19Leg = new ScaleFactor();
    myScaleFactor_trgMu19Leg->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu19leg_2016BtoH_eff.root");
    ScaleFactor * myScaleFactor_trgMu22 = new ScaleFactor();
    myScaleFactor_trgMu22->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu22OR_eta2p1_eff.root");
    ScaleFactor * myScaleFactor_trgMu19LegAnti = new ScaleFactor();
    myScaleFactor_trgMu19LegAnti->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu19leg_eta2p1_antiisolated_Iso0p15to0p3_eff_rb.root");
    ScaleFactor * myScaleFactor_trgMu22Anti = new ScaleFactor();
    myScaleFactor_trgMu22Anti->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu22OR_eta2p1_antiisolated_Iso0p15to0p3_eff_rb.root");
    ScaleFactor * myScaleFactor_id = new ScaleFactor();
    myScaleFactor_id->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_IdIso_IsoLt0p15_2016BtoH_eff.root");
    ScaleFactor * myScaleFactor_idAnti = new ScaleFactor();
    myScaleFactor_idAnti->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_IdIso_antiisolated_Iso0p15to0p3_eff_rb.root");
    
    TString postfixTES[12]={"_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"};
    TString postfixDM[6]={"_CMS_tauDMReco_1prong_13TeVUp","_CMS_tauDMReco_1prong_13TeVDown","_CMS_tauDMReco_1prong1pizero_13TeVUp","_CMS_tauDMReco_1prong1pizero_13TeVDown","_CMS_tauDMReco_3prong_13TeVUp","_CMS_tauDMReco_3prong_13TeVDown"};
    TString postfixFakeDM[6]={"_CMS_jetToTauDMReco_1prong_13TeVUp","_CMS_jetToTauDMReco_1prong_13TeVDown","_CMS_jetToTauDMReco_1prong1pizero_13TeVUp","_CMS_jetToTauDMReco_1prong1pizero_13TeVDown","_CMS_jetToTauDMReco_3prong_13TeVUp","_CMS_jetToTauDMReco_3prong_13TeVDown"};
    TString postfixZLshape[12]={"_CMS_htt_ZLShape_mt_13TeVUp","_CMS_htt_ZLShape_mt_13TeVDown","_CMS_ZLShape_mt_0jet_1prong_13TeVUp","_CMS_ZLShape_mt_0jet_1prong_13TeVDown","_CMS_ZLShape_mt_0jet_1prong1pizero_13TeVUp","_CMS_ZLShape_mt_0jet_1prong1pizero_13TeVDown","_CMS_ZLShape_mt_1prong_13TeVUp","_CMS_ZLShape_mt_1prong_13TeVDown", "_CMS_ZLShape_mt_1prong1pizero_13TeVUp","_CMS_ZLShape_mt_1prong1pizero_13TeVDown","_CMS_ZLShape_mt_3prong_13TeVUp","_CMS_ZLShape_mt_3prong_13TeVDown"};
    TString postfixZLnorm[4]={"_CMS_mFakeTau_1prong_13TeVUp","_CMS_mFakeTau_1prong_13TeVDown","_CMS_mFakeTau_1prong1pizero_13TeVUp","_CMS_mFakeTau_1prong1pizero_13TeVDown"};
    TString postfixJES[56]={"_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"};
    TString postfixWG1[18]={"_THU_ggH_Mu_13TeVUp","_THU_ggH_Mu_13TeVDown","_THU_ggH_Res_13TeVUp","_THU_ggH_Res_13TeVDown","_THU_ggH_Mig01_13TeVUp","_THU_ggH_Mig01_13TeVDown","_THU_ggH_Mig12_13TeVUp","_THU_ggH_Mig12_13TeVDown","_THU_ggH_VBF2j_13TeVUp","_THU_ggH_VBF2j_13TeVDown","_THU_ggH_VBF3j_13TeVUp","_THU_ggH_VBF3j_13TeVDown","_THU_ggH_PT60_13TeVUp","_THU_ggH_PT60_13TeVDown","_THU_ggH_PT120_13TeVUp","_THU_ggH_PT120_13TeVDown","_THU_ggH_qmtop_13TeVUp","_THU_ggH_qmtop_13TeVDown"};
    TFile * f_NNLOPS = new TFile("../../../CommonAN/weightROOTs/NNLOPS_reweight.root");
    TGraph * g_NNLOPS_0jet = (TGraph*) f_NNLOPS-> Get("gr_NNLOPSratio_pt_powheg_0jet");
    TGraph * g_NNLOPS_1jet = (TGraph*) f_NNLOPS-> Get("gr_NNLOPSratio_pt_powheg_1jet");
    TGraph * g_NNLOPS_2jet = (TGraph*) f_NNLOPS-> Get("gr_NNLOPSratio_pt_powheg_2jet");
    TGraph * g_NNLOPS_3jet = (TGraph*) f_NNLOPS-> Get("gr_NNLOPSratio_pt_powheg_3jet");
    
    Int_t nentries_wtn = (Int_t) arbre->GetEntries();
    for (Int_t i = 0; i < nentries_wtn; i++) {
      arbre->GetEntry(i);
      if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
      fflush(stdout);

      if (name.find("ggH_fwd_htt1") < 140 && Rivet_stage0_cat!=10) continue;
      if (name.find("ggH_stage0_htt1") < 140 && Rivet_stage0_cat!=11) continue;//FIXME
      if (name.find("qqH_fwd_htt1") < 140 && Rivet_stage0_cat!=20) continue;
      if (name.find("qqH_stage0_htt1") < 140 && Rivet_stage0_cat!=21) continue;
      if ((name.find("VH_had_htt1") < 140 or name.find("WH_had_htt1") < 140 or name.find("ZH_had_htt1") < 140) && Rivet_stage0_cat!=23) continue;
      if (name.find("WH_lep_fwd_htt1") < 140 && Rivet_stage0_cat!=30) continue;
      if (name.find("WH_lep_htt1") < 140 && Rivet_stage0_cat!=31) continue;
      if ((name.find("VH_had_fwd_htt1") < 140 or name.find("WH_had_fwd_htt1") < 140 or name.find("ZH_had_fwd_htt1") < 140) && Rivet_stage0_cat!=22) continue;
      if (name.find("ZH_lep_fwd_htt1") < 140 && Rivet_stage0_cat!=40) continue;
      if (name.find("ZH_lep_htt1") < 140 && Rivet_stage0_cat!=41) continue;
      
      if (name.find("ggH_VBFTOPO_JET3VETO_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=101) continue;
      if (name.find("ggH_VBFTOPO_JET3_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=102) continue;
      if (name.find("ggH_0J_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=103) continue;
      if (name.find("ggH_1J_PTH_0_60_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=104) continue;
      if (name.find("ggH_1J_PTH_60_120_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=105) continue;
      if (name.find("ggH_1J_PTH_120_200_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=106) continue;
      if (name.find("ggH_1J_PTH_GT200_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=107) continue;
      if (name.find("ggH_GE2J_PTH_0_60_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=108) continue;
      if (name.find("ggH_GE2J_PTH_60_120_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=109) continue;
      if (name.find("ggH_GE2J_PTH_120_200_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=110) continue;
      if (name.find("ggH_GE2J_PTH_GT200_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=111) continue;
      if (name.find("qqH_FWDH_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=200) continue;
      if (name.find("qqH_VBFTOPO_JET3VETO_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=201) continue;
      if (name.find("qqH_VBFTOPO_JET3_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=202) continue;
      if (name.find("qqH_VH2JET_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=203) continue;
      if (name.find("qqH_REST_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=204) continue;
      if (name.find("qqH_PTJET1_GT200_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=205) continue;
      if ((name.find("VH_had_VBFTOPO_JET3VETO_htt1") < 140 or name.find("WH_had_VBFTOPO_JET3VETO_htt1") < 140 or name.find("ZH_had_VBFTOPO_JET3VETO_htt1") < 140) && Rivet_stage1_cat_pTjet30GeV!=201) continue;
      if ((name.find("VH_had_VBFTOPO_JET3_htt1") < 140 or name.find("WH_had_VBFTOPO_JET3_htt1") < 140 or name.find("ZH_had_VBFTOPO_JET3_htt1") < 140) && Rivet_stage1_cat_pTjet30GeV!=202) continue;
      if ((name.find("VH_had_VH2JET_htt1") < 140 or name.find("WH_had_VH2JET_htt1") < 140 or name.find("ZH_had_VH2JET_htt1") < 140) && Rivet_stage1_cat_pTjet30GeV!=203) continue;
      if ((name.find("VH_had_REST_htt1") < 140 or name.find("WH_had_REST_htt1") < 140 or name.find("ZH_had_REST_htt1") < 140) && Rivet_stage1_cat_pTjet30GeV!=204) continue;
      if ((name.find("VH_had_PTJET1_GT200_htt1") < 140 or name.find("WH_had_PTJET1_GT200_htt1") < 140 or name.find("ZH_had_PTJET1_GT200_htt1") < 140) && Rivet_stage1_cat_pTjet30GeV!=205) continue;
      if (name.find("WH_lep_FWDH_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=300) continue;
      if (name.find("WH_lep_PTV_0_150_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=301) continue;
      if (name.find("WH_lep_PTV_150_250_0J_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=302) continue;
      if (name.find("WH_lep_PTV_150_250_GE1J_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=303) continue;
      if (name.find("WH_lep_PTV_GT250_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=304) continue;
      if ((name.find("VH_had_FWDH_htt1") < 140 or name.find("WH_had_FWDH_htt1") < 140 or name.find("ZH_had_FWDH_htt1") < 140) && Rivet_stage1_cat_pTjet30GeV!=200) continue;
      if (name.find("ZH_lep_FWDH_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=400) continue;
      if (name.find("ZH_lep_PTV_0_150_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=401) continue;
      if (name.find("ZH_lep_PTV_150_250_0J_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=402) continue;
      if (name.find("ZH_lep_PTV_150_250_Ge1J_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=403) continue;
      if (name.find("ZH_lep_PTV_GT250_htt1") < 140 && Rivet_stage1_cat_pTjet30GeV!=404) continue;
      
      bool isSingleLep = (passIsoMu22 && matchIsoMu22_1 && filterIsoMu22_1) or (passIsoTkMu22 && matchIsoTkMu22_1 && filterIsoTkMu22_1) or (passIsoMu22eta2p1 && matchIsoMu22eta2p1_1 && filterIsoMu22eta2p1_1) or (passIsoTkMu22eta2p1 && matchIsoTkMu22eta2p1_1 && filterIsoTkMu22eta2p1_1);
      bool isCrossTrigger = (passIsoMu19Tau20 && matchIsoMu19Tau20_1 && filterIsoMu19Tau20_1 && matchIsoMu19Tau20_2 && filterIsoMu19Tau20_2);

      if (sample=="data_obs" && run<278820 && !id_m_medium2016_1) continue;
      if (sample=="data_obs" && run>=278820 && !id_m_medium_1) continue;

      if (sample=="embedded" && tZTTGenDR>0.2) continue;

      if (pt_1<20) continue;
      if (fabs(eta_1)>2.1) continue;
      if (sample!="embedded" && !isSingleLep && !isCrossTrigger) continue;
      if (sample!="embedded" && (!((isSingleLep && pt_1>23) or (isCrossTrigger && pt_1<=23)))) continue;
      
      if (!againstElectronVLooseMVA6_2 or !againstMuonTight3_2) continue;

      // D.Kim - for consistency with tautau channel
      if (extraelec_veto!=0) continue;
      if (extramuon_veto!=0) continue;
      if (dilepton_veto!=0) continue;
      
      float sf_trg=1.0;
      float sf_id=1.0;
      float sf_id_anti=1.0;
      float sf_trg_anti=1.0;
      float eff_tau=1.0;
      float eff_tau_anti=1.0;
      
      if (sample!="data_obs"){
	sf_id=myScaleFactor_id->get_ScaleFactor(pt_1,eta_1);
	sf_id_anti=myScaleFactor_idAnti->get_ScaleFactor(pt_1,eta_1);
      }

      float ratioanti=(sf_id_anti)/(sf_id);
      
      float signalRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.15);
      float qcdRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30);
      float wRegion=(byMediumIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30);
      float wsfRegion=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.15);
      float qcdCR=(byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.30 && iso_1>0.15);
      
      TLorentzVector mytau; 
      mytau.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
      TLorentzVector mymu;
      mymu.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
      TLorentzVector myjet1;
      myjet1.SetPtEtaPhiM(jpt_1,jeta_1,jphi_1,0);
      TLorentzVector myjet2;
      myjet2.SetPtEtaPhiM(jpt_2,jeta_2,jphi_2,0);

      //***************** Weights **************
      
      if (sample=="W"){
	weight=25.446;
	if (numGenJets==1) weight=6.8176;
	else if (numGenJets==2) weight=2.1038;
	else if (numGenJets==3) weight=0.6889;
	else if (numGenJets==4) weight=0.6900;
      }

      /*if (sample=="W"){//Laura stat
	weight=25.446;
	if (numGenJets==1) weight=6.8176;
	else if (numGenJets==2) weight=3.90313;
	else if (numGenJets==3) weight=1.95115;
	else if (numGenJets==4) weight=0.68997;
        }*/
      
      if (sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
	weight=1.4184;
	if (numGenJets==1) weight=0.45729;
	else if (numGenJets==2) weight=0.4668;
	else if (numGenJets==3)	weight=0.47995;
	else if (numGenJets==4) weight=0.39349;
      }
      
      float correction=sf_id;
	if (sample!="embedded" && sample!="data_obs") correction=correction*LumiWeights_12->weight(npu);
        if (sample=="embedded" && amcatNLO_weight>1) amcatNLO_weight=0.10;
	float aweight = 1.0;
	if (name.find("ggH")) aweight = amcatNLO_weight*weight*correction;
	else aweight=genweight*weight*correction;
	
        if (sample!="data_obs"){
	  if (gen_match_2==5) aweight=aweight*0.95;
	  if (gen_match_2==2 or gen_match_2==4){//Yiwen reminiaod
	    if (fabs(eta_2)<0.4) aweight=aweight*1.263;
	    else if (fabs(eta_2)<0.8) aweight=aweight*1.364;
	    else if (fabs(eta_2)<1.2) aweight=aweight*0.854;
	    else if (fabs(eta_2)<1.7) aweight=aweight*1.712;
	    else if (fabs(eta_2)<2.3) aweight=aweight*2.324;
	    if (sample=="ZL" && l2_decayMode==0) aweight=aweight*0.74; //ZL corrections Laura
	    else if (sample=="ZL" && l2_decayMode==1) aweight=aweight*1.0;
	  }
	  if (gen_match_2==1 or gen_match_2==3){//Yiwen
	    if (fabs(eta_2)<1.460) aweight=aweight*1.213;
	    else if (fabs(eta_2)>1.558) aweight=aweight*1.375;
	  }
	  //w->var("m_pt")->setVal(mymu.Pt());
	  //w->var("m_eta")->setVal(mymu.Eta());
	  //aweight=aweight*w->function("m_trk_ratio")->getVal();
	  aweight=aweight*h_Trk->Eval(eta_1);
        }

	if (name.find("ggH")<100 && name.find("NNLOPS")>100 && name.find("hww")>100){
	  if (Rivet_nJets30==0) aweight = aweight * g_NNLOPS_0jet->Eval(min(Rivet_higgsPt,float(125.0)));
	  if (Rivet_nJets30==1) aweight = aweight * g_NNLOPS_1jet->Eval(min(Rivet_higgsPt,float(625.0)));
	  if (Rivet_nJets30==2) aweight = aweight * g_NNLOPS_2jet->Eval(min(Rivet_higgsPt,float(800.0)));
	  if (Rivet_nJets30>=3) aweight = aweight * g_NNLOPS_3jet->Eval(min(Rivet_higgsPt,float(925.0)));
	}

	//cout<<Rivet_nJets30<<" "<<Rivet_higgsPt<<" "<<Rivet_stage1_cat_pTjet30GeV<<endl;
        NumV WG1unc = qcd_ggF_uncert_2017(Rivet_nJets30, Rivet_higgsPt, Rivet_stage1_cat_pTjet30GeV);
//if (evt==40 or evt==42 or evt==129 or evt==360) cout<<evt<<" "<<WG1unc[0]<<" "<<WG1unc[1]<<endl;
	//if (name.find("ggH")<100 && name.find("NNLOPS")>100) cout<<WG1unc[0]<<" "<<WG1unc[1]<<" "<<WG1unc[2]<<" "<<WG1unc[3]<<" "<<WG1unc[4]<<" "<<WG1unc[5]<<" "<<WG1unc[6]<<" "<<WG1unc[7]<<" "<<WG1unc[8]<<endl;

        //if (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ") aweight=aweight*1.02; //Zmumu correction

	if (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
	  float zpt_corr=histZ->GetBinContent(histZ->GetXaxis()->FindBin(genM),histZ->GetYaxis()->FindBin(genpT));
	  if (fabs(tes)!=10) //nominal
	    aweight=aweight*zpt_corr;
	  else if (tes==10) // up
	    aweight=aweight*(1+1.10*(zpt_corr-1));
	  else if (tes==-10) // down
	    aweight=aweight*(1+0.90*(zpt_corr-1));
	}

	//************************ Jet to tau FR shape **************************
	if (tes==14 && (sample=="TTJ" or sample=="ZJ" or sample=="W") && gen_match_2==6){
	  float jtotau=1-(0.2*mytau.Pt()/100);
	  if (mytau.Pt()>200) jtotau=1-(0.2*200.0/100);
	  aweight=aweight*jtotau;
	}
        if (tes==-14 && (sample=="TTJ" or sample=="ZJ" or sample=="W") && gen_match_2==6){
	  float jtotau=1+(0.2*mytau.Pt()/100);
	  if (mytau.Pt()>200) jtotau=1+(0.2*200.0/100);
	  aweight=aweight*jtotau;
        }

	//*********************** Definition of fit variables *******************
        float var2=m_sv;
        float var1_1=pt_sv;
        float var1_0=mytau.Pt();

	// ###########################################################
	// ######## Separation between L, T and J ####################
	// ###########################################################
	
        if (sample=="ZL" && gen_match_2>4) continue;
        if ((sample=="TTT" or sample=="ZTT") && gen_match_2!=5) continue;
        if ((sample=="TTJ" or sample=="ZLL") && gen_match_2==5) continue;
        if (sample=="ZJ" && gen_match_2!=6) continue;

	// #############################################################
     	// ################### Top pT reweighting ######################
     	// #############################################################
	float pttop1=pt_top1;
        if (pttop1>400) pttop1=400;
        float pttop2=pt_top2;
        if (pttop2>400) pttop2=400;
        if ((sample=="TTJ" or sample=="TTT" or sample=="TT") && fabs(tes)!=11) aweight*=sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2));
        if ((sample=="TTJ" or sample=="TTT" or sample=="TT") && tes==11) aweight*=(1+2*(sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2))-1));

	if (sample=="data_obs") aweight=1.0;

	float weight_btag=1.0;
        if (sample!="data_obs"){
	  int nbtagged=nbtag;
	  if (nbtagged>2) nbtagged=2;
	  weight_btag=bTagEventWeight(nbtagged,bpt_1,bflavor_1,bpt_2,bflavor_2,1,0,0);
	  if (nbtagged>2) weight_btag=0;
        }
	bool is_bveto=(sample!="data_obs" or nbtag==0);
	

	// ############################################################
	// ############### Loop over JES sources ######################
	// ############################################################
	//
	int nombrejets[56]={njets_JESDown,njets_JESUp,njets_JetAbsoluteFlavMapDown,njets_JetAbsoluteFlavMapUp,njets_JetAbsoluteMPFBiasDown,njets_JetAbsoluteMPFBiasUp,njets_JetAbsoluteScaleDown,njets_JetAbsoluteScaleUp,njets_JetAbsoluteStatDown,njets_JetAbsoluteStatUp,njets_JetFlavorQCDDown,njets_JetFlavorQCDUp,njets_JetFragmentationDown,njets_JetFragmentationUp,njets_JetPileUpDataMCDown,njets_JetPileUpDataMCUp,njets_JetPileUpPtBBDown,njets_JetPileUpPtBBUp,njets_JetPileUpPtEC1Down,njets_JetPileUpPtEC1Up,njets_JetPileUpPtEC2Down,njets_JetPileUpPtEC2Up,njets_JetPileUpPtHFDown,njets_JetPileUpPtHFUp,njets_JetPileUpPtRefDown,njets_JetPileUpPtRefUp,njets_JetRelativeBalDown,njets_JetRelativeBalUp,njets_JetRelativeFSRDown,njets_JetRelativeFSRUp,njets_JetRelativeJEREC1Down,njets_JetRelativeJEREC1Up,njets_JetRelativeJEREC2Down,njets_JetRelativeJEREC2Up,njets_JetRelativeJERHFDown,njets_JetRelativeJERHFUp,njets_JetRelativePtBBDown,njets_JetRelativePtBBUp,njets_JetRelativePtEC1Down,njets_JetRelativePtEC1Up,njets_JetRelativePtEC2Down,njets_JetRelativePtEC2Up,njets_JetRelativePtHFDown,njets_JetRelativePtHFUp,njets_JetRelativeStatECDown,njets_JetRelativeStatECUp,njets_JetRelativeStatFSRDown,njets_JetRelativeStatFSRUp,njets_JetRelativeStatHFDown,njets_JetRelativeStatHFUp,njets_JetSinglePionECALDown,njets_JetSinglePionECALUp,njets_JetSinglePionHCALDown,njets_JetSinglePionHCALUp,njets_JetTimePtEtaDown,njets_JetTimePtEtaUp};

	float massejets[56]={mjj_JESDown,mjj_JESUp,mjj_JetAbsoluteFlavMapDown,mjj_JetAbsoluteFlavMapUp,mjj_JetAbsoluteMPFBiasDown,mjj_JetAbsoluteMPFBiasUp,mjj_JetAbsoluteScaleDown,mjj_JetAbsoluteScaleUp,mjj_JetAbsoluteStatDown,mjj_JetAbsoluteStatUp,mjj_JetFlavorQCDDown,mjj_JetFlavorQCDUp,mjj_JetFragmentationDown,mjj_JetFragmentationUp,mjj_JetPileUpDataMCDown,mjj_JetPileUpDataMCUp,mjj_JetPileUpPtBBDown,mjj_JetPileUpPtBBUp,mjj_JetPileUpPtEC1Down,mjj_JetPileUpPtEC1Up,mjj_JetPileUpPtEC2Down,mjj_JetPileUpPtEC2Up,mjj_JetPileUpPtHFDown,mjj_JetPileUpPtHFUp,mjj_JetPileUpPtRefDown,mjj_JetPileUpPtRefUp,mjj_JetRelativeBalDown,mjj_JetRelativeBalUp,mjj_JetRelativeFSRDown,mjj_JetRelativeFSRUp,mjj_JetRelativeJEREC1Down,mjj_JetRelativeJEREC1Up,mjj_JetRelativeJEREC2Down,mjj_JetRelativeJEREC2Up,mjj_JetRelativeJERHFDown,mjj_JetRelativeJERHFUp,mjj_JetRelativePtBBDown,mjj_JetRelativePtBBUp,mjj_JetRelativePtEC1Down,mjj_JetRelativePtEC1Up,mjj_JetRelativePtEC2Down,mjj_JetRelativePtEC2Up,mjj_JetRelativePtHFDown,mjj_JetRelativePtHFUp,mjj_JetRelativeStatECDown,mjj_JetRelativeStatECUp,mjj_JetRelativeStatFSRDown,mjj_JetRelativeStatFSRUp,mjj_JetRelativeStatHFDown,mjj_JetRelativeStatHFUp,mjj_JetSinglePionECALDown,mjj_JetSinglePionECALUp,mjj_JetSinglePionHCALDown,mjj_JetSinglePionHCALUp,mjj_JetTimePtEtaDown,mjj_JetTimePtEtaUp};
        TLorentzVector myrawmet;
        myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	TLorentzVector myrawtau=mytau;
	float ratioantiraw=ratioanti;

	for (int k=0; k<nbhist; ++k){
	  
	  int numberJets=nombrejets[k];
	  float massJets=massejets[k];
	  if (tes!=100) numberJets=njets;
	  if (tes!=100) massJets=mjj;
	  float weight2=1.0;
	  if (tes==1000){
	    if (k==0) weight2=1+WG1unc[0];
	    else if (k==1) weight2=1-WG1unc[0];
	    else if (k==2) weight2=1+WG1unc[1];
	    else if (k==3) weight2=1-WG1unc[1];
	    else if (k==4) weight2=1+WG1unc[2];
	    else if (k==5) weight2=1-WG1unc[2];
	    else if (k==6) weight2=1+WG1unc[3];
	    else if (k==7) weight2=1-WG1unc[3];
	    else if (k==8) weight2=1+WG1unc[4];
	    else if (k==9) weight2=1-WG1unc[4];
	    else if (k==10) weight2=1+WG1unc[5];
	    else if (k==11) weight2=1-WG1unc[5];
	    else if (k==12) weight2=1+WG1unc[6];
	    else if (k==13) weight2=1-WG1unc[6];
	    else if (k==14) weight2=1+WG1unc[7];
	    else if (k==15) weight2=1-WG1unc[7];
	    else if (k==16) weight2=1+WG1unc[8];
	    else if (k==17) weight2=1-WG1unc[8];
	  }

	  TLorentzVector mymet=myrawmet;
	  mytau=myrawtau;
	  var1_1=pt_sv;
	  var2=m_sv;
	  float var1_2=massJets;
	  
	  if (tes==1 && gen_match_2==5){
	    if (k==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
	    if (k==1){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
	    if (k==2 && l2_decayMode==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
	    if (k==3 && l2_decayMode==0){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
	    if (k==4 && l2_decayMode==1){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
	    if (k==5 && l2_decayMode==1){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
	    if (k==6 && l2_decayMode==10){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.988; mymet=mymet+(0.012/0.988)*mytau;}
	    if (k==7 && l2_decayMode==10){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.012; mymet=mymet-(0.012/1.012)*mytau;}
	  }
	  
	  if (tes==1){
	    if (k==8){ var2=m_sv_UncMet_DOWN; var1_1=pt_sv_UncMet_DOWN; mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
	    else if (k==9){ var2=m_sv_UncMet_UP; var1_1=pt_sv_UncMet_UP; mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
	    else if (k==10){ var2=m_sv_ClusteredMet_DOWN; var1_1=pt_sv_ClusteredMet_DOWN; mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
	    else if (k==11){ var2=m_sv_ClusteredMet_UP; var1_1=pt_sv_ClusteredMet_UP; mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
	  }
	  
	  if (tes==15 && sample=="ZL"){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau*=1.015; mymet=mymet-(0.015/1.015)*mytau;}
	  if (tes==-15 && sample=="ZL"){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau*=0.985; mymet=mymet+(0.015/0.985)*mytau;}
	  float dm_weight=1.0;
	  if (tes==16 && gen_match_2==5){
	    if (k==0 && l2_decayMode==0) dm_weight=1.03;
	    else if (k==1 && l2_decayMode==0) dm_weight=0.97;
	    else if (k==2 && l2_decayMode==1) dm_weight=1.03;
	    else if (k==3 && l2_decayMode==1) dm_weight=0.97;
	    else if (k==4 && l2_decayMode==10) dm_weight=1.03;
	    else if (k==5 && l2_decayMode==10) dm_weight=0.97;
	  }
	  if (tes==19 && gen_match_2==6){
	    if (k==0 && l2_decayMode==0) dm_weight=1.20;
	    else if (k==1 && l2_decayMode==0) dm_weight=0.80;
	    else if (k==2 && l2_decayMode==1) dm_weight=1.20;
	    else if (k==3 && l2_decayMode==1) dm_weight=0.80;
	    else if (k==4 && l2_decayMode==10) dm_weight=1.20;
	    else if (k==5 && l2_decayMode==10) dm_weight=0.80;
	  }
	  
	  if (tes==18 && sample=="ZL"){
	    if (k==0 && l2_decayMode==0) dm_weight=1.25;
	    else if (k==1 && l2_decayMode==0) dm_weight=0.75;
	    else if (k==2 && l2_decayMode==1) dm_weight=1.25;
	    else if (k==3 && l2_decayMode==1) dm_weight=0.75;
	  }
	  
	  if (numberJets==0) var2=(mymu+mytau).M();
	  
	  if (tes==17 && sample=="ZL"){
	    if (k==0){ 
	      var2=m_sv_UP; 
	      var1_1=pt_sv_UP; 
	      mytau*=1.015; 
	      mymet=mymet-(0.015/1.015)*mytau;
	      if (numberJets==0) var2=(mymu+mytau).M();
	    }
	    else if (k==1) { 
	      var2=m_sv_DOWN; 
	      var1_1=pt_sv_DOWN; 
	      mytau*=0.985; 
	      mymet=mymet+(0.015/0.985)*mytau;
	      if (numberJets==0) var2=(mymu+mytau).M();
	    }
	    else if (k==2 && l2_decayMode==0 && numberJets==0) var2=var2*1.003;
	    else if (k==3 && l2_decayMode==0 && numberJets==0) var2=var2*0.997;
	    else if (k==4 && l2_decayMode==1 && numberJets==0) var2=var2*1.004;
	    else if (k==5 && l2_decayMode==1 && numberJets==0) var2=var2*0.996;
	    if (k==6 && l2_decayMode==0){ 
	      var2=m_sv_UP; 
	      var1_1=pt_sv_UP;
	      mytau*=1.015; 
	      mymet=mymet-(0.015/1.015)*mytau;
	      if (numberJets==0) var2=(mymu+mytau).M();
	    }
	    else if (k==7 && l2_decayMode==0) { 
	      var2=m_sv_DOWN; 
	      var1_1=pt_sv_DOWN;
	      mytau*=0.985; 
	      mymet=mymet+(0.015/0.985)*mytau;
	      if (numberJets==0) var2=(mymu+mytau).M();
	    }
	    if (k==8 && l2_decayMode==1){ 
	      var2=m_sv_UP; 
	      var1_1=pt_sv_UP;
	      mytau*=1.015; 
	      mymet=mymet-(0.015/1.015)*mytau;
	      if (numberJets==0) var2=(mymu+mytau).M();
	    }
	    else if (k==9 && l2_decayMode==1) { 
	      var2=m_sv_DOWN; 
	      var1_1=pt_sv_DOWN;
	      mytau*=0.985; 
	      mymet=mymet+(0.015/0.985)*mytau;
	      if (numberJets==0) var2=(mymu+mytau).M();
	    }
	    if (k==10 && l2_decayMode==10){ 
	      var2=m_sv_UP; 
	      var1_1=pt_sv_UP;
	      mytau*=1.015; 
	      mymet=mymet-(0.015/1.015)*mytau;
	      if (numberJets==0) var2=(mymu+mytau).M();
	    }
	    else if (k==11 && l2_decayMode==10) { 
	      var2=m_sv_DOWN; 
	      var1_1=pt_sv_DOWN;
	      mytau*=0.985; 
	      mymet=mymet+(0.015/0.985)*mytau;
	      if (numberJets==0) var2=(mymu+mytau).M();
	    }
	  }
	  
	  if (mytau.Pt()<30) continue;
	  //var1_0=mytau.Pt();
	  var1_0=l2_decayMode;//FIXME
	  var1_1=(mymu+mytau+mymet).Pt();//FIXME
	  
	  float mt=TMass_F(mymu.Pt(),mymet.Pt(),mymu.Px(),mymet.Px(),mymu.Py(),mymet.Py());
	  
	  if (sample!="embedded" && sample!="data_obs"){
	    if (mymu.Pt()<23){ 
	      w2->var("t_pt")->setVal(mytau.Pt());
	      w2->var("t_eta")->setVal(mytau.Eta());
	      w2->var("t_dm")->setVal(l2_decayMode);
	      float eff_tau_ratio = w2->function("t_genuine_TightIso_mt_ratio")->getVal();
	      sf_trg=myScaleFactor_trgMu19Leg->get_ScaleFactor(pt_1,eta_1)*eff_tau_ratio;
	      sf_trg_anti=myScaleFactor_trgMu19LegAnti->get_ScaleFactor(pt_1,eta_1)*eff_tau_ratio;
	    }
	    else{
	      sf_trg=myScaleFactor_trgMu22->get_ScaleFactor(pt_1,eta_1);
	      sf_trg_anti=myScaleFactor_trgMu22Anti->get_ScaleFactor(pt_1,eta_1);
	    }
	  }
	  if (sample=="embedded"){
	    if (mymu.Pt()<23){ 
	      float eff_tau_ratio = w2->function("t_genuine_TightIso_mt_data")->getVal();
	      sf_trg=myScaleFactor_trgMu19Leg->get_EfficiencyData(pt_1,eta_1)*eff_tau_ratio;
	      sf_trg_anti=myScaleFactor_trgMu19LegAnti->get_EfficiencyData(pt_1,eta_1)*eff_tau_ratio;
	    }
	    else{
	      sf_trg=myScaleFactor_trgMu22->get_EfficiencyData(pt_1,eta_1);
	      sf_trg_anti=myScaleFactor_trgMu22Anti->get_EfficiencyData(pt_1,eta_1);
	    }
	  }
            
	  //************************ Z mumu scale factors **************************
	  if (fabs(tes)!=13 && (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),0);
	  if (tes==13 && (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),1);
	  if (tes==-13 && (sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL" or sample=="ZL")) weight2=GetZmmSF(numberJets,var1_2,var1_1,mytau.Pt(),-1);
	  
	  if (sample=="data_obs") {aweight=1.0; weight2=1.0;}
	  weight2=weight2*sf_trg*dm_weight;
	  ratioanti=ratioantiraw*sf_trg_anti/(sf_trg+0.000000001);
	  
	  bool is_0jet=(numberJets==0);
	  bool is_boosted=(numberJets==1 or (numberJets>=2 && (massJets<=300 or var1_1<=50 or mytau.Pt()<=40)));
	  bool is_VBF=(massJets > 300 && numberJets>=2 && var1_1>50 && mytau.Pt()>40);
	  //bool is_VBF=(massJets > 300 && numberJets>=2);// && var1_1>50 && mytau.Pt()>40);
	  float normMELAvbf = ME_sm_VBF/(ME_sm_VBF+45*ME_bkg);
	  TLorentzVector Higgs;// = mymet+mymu+mytau;
	  Higgs.SetPtEtaPhiM(var1_1,(mymet+mymu+mytau).Eta(),(mymet+mymu+mytau).Phi(),(mymet+mymu+mytau).M());
	  // book the NN                                                                                                       
	  TMVAClassification_TMlpANN* t = new TMVAClassification_TMlpANN();
	  double my_NN = t->Value(0, Phi, Phi1,
				  costheta1, costheta2, costhetastar,
				  Q2V1, Q2V2);      
	  
	  //var1_2 = my_NN;
	  fillNNTree(namu,mytau,q_1,l2_decayMode,
		     mymu,q_2,
		     myjet1,myjet2,
		     mymet,massJets,
		     var1_1,var2,mt, //pt_sv, m_sv, mt
		     numberJets,
		     bpt_1,beta_1,bphi_1,
		     bpt_2,beta_2,bphi_2,nbtag,
		     Higgs,
		     is_0jet,is_boosted,is_VBF,
		     signalRegion,qcdRegion,wRegion,wsfRegion,qcdCR,
		     weight2*aweight,
		     ME_sm_VBF,ME_sm_ggH,ME_bkg);
	  //################ W+jets reweighting in high mT ###############
	  //if(is_VBF) std::cout << var1_2 << std::endl;
	  if (q_1*q_2<0 && mt>80 && mt<200 && wsfRegion){
	    n70[k]->Fill(0.1,aweight*weight2);
	    if (is_bveto && is_0jet && var2<400) n70[k]->Fill(1.1,aweight*weight2*weight_btag);
	    if (is_bveto && is_boosted && var2<300) n70[k]->Fill(2.1,aweight*weight2*weight_btag);
	    if (is_bveto && is_VBF && var2<400) n70[k]->Fill(3.1,aweight*weight2*weight_btag);
	  }

	  if (q_1*q_2>0 && mt>80 && mt<200 && wsfRegion){
	    n70SS[k]->Fill(0.1,aweight*weight2);
	    if (is_bveto && is_0jet && var2<400) n70SS[k]->Fill(1.1,aweight*weight2*weight_btag);
	    if (is_bveto && is_boosted && var2<300) n70SS[k]->Fill(2.1,aweight*weight2*weight_btag);
	    if (is_bveto && is_VBF && var2<400) n70SS[k]->Fill(3.1,aweight*weight2*weight_btag);
	  }
	  
	  
	  //************************* Fill histograms **********************
	  
	  if (qcdCR && q_1*q_2<0 && mt<50){
	    if (is_0jet)
	      h0_CR_QCD[k]->Fill(var2,aweight*weight2*ratioanti);
	    if (is_boosted)
	      h1_CR_QCD[k]->Fill(var2,aweight*weight2*ratioanti);
	    if (is_VBF)
	      h2_CR_QCD[k]->Fill(var2,aweight*weight2*ratioanti);
	  }
	  if (signalRegion && q_1*q_2<0){
	    if (is_0jet && is_bveto && var2<400)
	      h0_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
	    if (is_boosted && is_bveto && var2<300)
	      h1_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
	    if (is_VBF && is_bveto && var2<400)
	      h2_CR_W[k]->Fill(mt,weight2*aweight*weight_btag);
	  }
	  
	  if (qcdCR && q_1*q_2>0 && mt<50){
	    if (is_0jet)
	      h0_CRSS_QCD[k]->Fill(var2,weight2*aweight*ratioanti);
	    if (is_boosted)
	      h1_CRSS_QCD[k]->Fill(var2,weight2*aweight*ratioanti);
	    if (is_VBF)
	      h2_CRSS_QCD[k]->Fill(var2,weight2*aweight*ratioanti);
	  }
	  
	  if (signalRegion && q_1*q_2>0){
	    if (is_0jet && is_bveto && var2<400)
	      h0_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
	    if (is_boosted && is_bveto && var2<300)
	      h1_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
	    if (is_VBF && is_bveto && var2<400)
	      h2_CRSS_W[k]->Fill(mt,weight2*aweight*weight_btag);
	  }
	  
	  if (is_0jet && mt<50){
	    if (tes==12) weight2=weight2*(0.9289 + 0.00017022*mytau.Pt());
	    if (tes==-12) weight2=weight2*(2-(0.9289 + 0.00017022*mytau.Pt()));
	    if (genpT>150 and tes==22) weight2=weight2*(1+0.01*(0.114*genpT -17.14));
	    if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
	    if (signalRegion && q_1*q_2<0){
	      pteta_0jet->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      mUESUp_0jet->Fill((m_sv_UncMet_UP-m_sv)/m_sv_UncMet_UP,weight2*aweight);
	      mUESDown_0jet->Fill((m_sv_UncMet_DOWN-m_sv)/m_sv_UncMet_DOWN,weight2*aweight);
	      mCESUp_0jet->Fill((m_sv_ClusteredMet_UP-m_sv)/m_sv_ClusteredMet_UP,weight2*aweight);
	      mCESDown_0jet->Fill((m_sv_ClusteredMet_DOWN-m_sv)/m_sv_ClusteredMet_DOWN,weight2*aweight);
	      mTESUp_0jet->Fill((m_sv_UP-m_sv)/m_sv_UP,weight2*aweight);
	      mTESDown_0jet->Fill((m_sv_DOWN-m_sv)/m_sv_DOWN,weight2*aweight);
	      h0_OS[k]->Fill(var1_0,var2,weight2*aweight);
	      if (l2_decayMode==0) h2D_0jet->Fill(var2,0.0,weight2*aweight);
	      if (l2_decayMode==1) h2D_0jet->Fill(var2,1.0,weight2*aweight);
	      if (l2_decayMode==10) h2D_0jet->Fill(var2,2.0,weight2*aweight);
	    }
	    if (signalRegion && q_1*q_2>0)
	      h0_SS[k]->Fill(var1_0,var2,weight2*aweight);
	    if (wRegion && q_1*q_2<0)
	      h0_WOS[k]->Fill(var1_0,var2,weight2*aweight);
	    if (wRegion && q_1*q_2>0)
	      h0_WSS[k]->Fill(var1_0,var2,weight2*aweight);
	    if (qcdRegion && q_1*q_2>0)
	      h0_QCD[k]->Fill(var1_0,var2,weight2*aweight);
	  }
	  
	  if (is_boosted && mt<50){
	    HiggspT->Fill(pt_sv,(mymu+mytau+mymet).Pt());
	    if (tes==12) weight2=weight2*(0.9195 + 0.0010055*var1_1);
	    if (tes==-12) weight2=weight2*(2-(0.9195 + 0.0010055*var1_1));
	    if (genpT>150 and tes==22) {weight2=weight2*(1+0.01*(0.114*genpT -17.14));}
	    if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
	    if (signalRegion && q_1*q_2<0){
	      h1_OS[k]->Fill(var1_1,var2,weight2*aweight);
	      h2D_boosted->Fill(var2,var1_2,weight2*aweight);
	      if (var1_1>150) {
		mUESUp_boosted->Fill((m_sv_UncMet_UP-m_sv)/m_sv_UncMet_UP,weight2*aweight);
		mUESDown_boosted->Fill((m_sv_UncMet_DOWN-m_sv)/m_sv_UncMet_DOWN,weight2*aweight);
		mCESUp_boosted->Fill((m_sv_ClusteredMet_UP-m_sv)/m_sv_ClusteredMet_UP,weight2*aweight);
		mCESDown_boosted->Fill((m_sv_ClusteredMet_DOWN-m_sv)/m_sv_ClusteredMet_DOWN,weight2*aweight);
		mTESUp_boosted->Fill((m_sv_UP-m_sv)/m_sv_UP,weight2*aweight);
		mTESDown_boosted->Fill((m_sv_DOWN-m_sv)/m_sv_DOWN,weight2*aweight);
	      }
	      if (var1_1<100) pteta_boosted_1->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      else if (var1_1<150) pteta_boosted_2->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      else if (var1_1<200) pteta_boosted_3->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      else if (var1_1<250) pteta_boosted_4->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      else if (var1_1<300) pteta_boosted_5->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      else pteta_boosted_6->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	    }
	    if (signalRegion && q_1*q_2>0)
	      h1_SS[k]->Fill(var1_1,var2,weight2*aweight);
	    if (wRegion && q_1*q_2<0)
	      h1_WOS[k]->Fill(var1_1,var2,weight2*aweight);
	    if (wRegion && q_1*q_2>0)
	      h1_WSS[k]->Fill(var1_1,var2,weight2*aweight);
	    if (qcdRegion && q_1*q_2>0)
	      h1_QCD[k]->Fill(var1_1,var2,weight2*aweight);
	  }
	  
	  if (is_VBF && mt<50){
	    if (tes==12) weight2=weight2*(1.0258 + 0.00006596*var1_2);
	    if (tes==-12) weight2=weight2*(2-(1.0258 + 0.00006596*var1_2));
	    if (genpT>150 and tes==22) weight2=weight2*(1+0.01*(0.114*genpT -17.14));
	    if (genpT>150 and tes==-22) weight2=weight2*(2-(1+0.01*(0.114*genpT -17.14)));
	    if (signalRegion && q_1*q_2<0){
	      //if (mjj>1500) cout<<run<<" "<<lumi<<" "<<evt<<" "<<m_sv<<" "<<pt_1<<" "<<pt_2<<" "<<mjj<<endl;
	      h2_OS[k]->Fill(var1_2,var2,weight2*aweight);
	      //std::cout << " --------------------- here --------------------- " << std::endl;
	      h2D_vbf->Fill(var2,var1_2,weight2*aweight);
	      if (var1_2<700) pteta_vbf_1->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      else if (var1_2<1100) pteta_vbf_2->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      else if (var1_2<1500) pteta_vbf_3->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      else pteta_vbf_4->Fill(mytau.Pt(),mytau.Eta(),weight2*aweight);
	      mUESUp_vbf->Fill((m_sv_UncMet_UP-m_sv)/m_sv_UncMet_UP,weight2*aweight);
	      mUESDown_vbf->Fill((m_sv_UncMet_DOWN-m_sv)/m_sv_UncMet_DOWN,weight2*aweight);
	      mCESUp_vbf->Fill((m_sv_ClusteredMet_UP-m_sv)/m_sv_ClusteredMet_UP,weight2*aweight);
	      mCESDown_vbf->Fill((m_sv_ClusteredMet_DOWN-m_sv)/m_sv_ClusteredMet_DOWN,weight2*aweight);
	      mTESUp_vbf->Fill((m_sv_UP-m_sv)/m_sv_UP,weight2*aweight);
	      mTESDown_vbf->Fill((m_sv_DOWN-m_sv)/m_sv_DOWN,weight2*aweight);
	    }
	    if (signalRegion && q_1*q_2>0)
	      h2_SS[k]->Fill(var1_2,var2,weight2*aweight);
	    if (wRegion && q_1*q_2<0)
	      h2_WOS[k]->Fill(var1_2,var2,weight2*aweight);
	    if (wRegion && q_1*q_2>0)
	      h2_WSS[k]->Fill(var1_2,var2,weight2*aweight);
	    if (qcdRegion && q_1*q_2>0)
	      h2_QCD[k]->Fill(var1_2,var2,weight2*aweight);
	  }
	}
	
    } // end of loop over events
    
    for (int k=0; k<nbhist; ++k){
      cout<<h0_WOS[k]->Integral()<<endl;
      h0_WOS[k]->Scale(h0_OS[k]->Integral()/h0_WOS[k]->Integral());
      h1_WOS[k]->Scale(h1_OS[k]->Integral()/h1_WOS[k]->Integral());
      h2_WOS[k]->Scale(h2_OS[k]->Integral()/h2_WOS[k]->Integral());
      h0_WSS[k]->Scale(h0_SS[k]->Integral()/h0_WSS[k]->Integral());
      h1_WSS[k]->Scale(h1_SS[k]->Integral()/h1_WSS[k]->Integral());
      h2_WSS[k]->Scale(h2_SS[k]->Integral()/h2_WSS[k]->Integral());
    }
    
    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    nbevt->Write();
    namu->Write();
    hincl->Write();
    nlowhigh->Write();
    mUESUp_0jet->Write();
    mUESDown_0jet->Write();
    mTESUp_0jet->Write();
    mTESDown_0jet->Write();
    mCESUp_0jet->Write();
    mCESDown_0jet->Write();
    
    mUESUp_boosted->Write();
    mUESDown_boosted->Write();
    mTESUp_boosted->Write();
    mTESDown_boosted->Write();
    mCESUp_boosted->Write();
    mCESDown_boosted->Write();
    
    mUESUp_vbf->Write();
    mUESDown_vbf->Write();
    mTESUp_vbf->Write();
    mTESDown_vbf->Write();
    mCESUp_vbf->Write();
    mCESDown_vbf->Write();
    
    HiggspT->Write();
    pteta_0jet->Write();
    pteta_boosted_1->Write();
    pteta_boosted_2->Write();
    pteta_boosted_3->Write();
    pteta_boosted_4->Write();
    pteta_boosted_5->Write();
    pteta_boosted_6->Write();
    pteta_vbf_1->Write();
    pteta_vbf_2->Write();
    pteta_vbf_3->Write();
    pteta_vbf_4->Write();
    
    h2D_0jet->Write();
    h2D_boosted->Write();
    h2D_vbf->Write();
    
    TString postfix="";
    if (tes==1)
      postfix="_CMS_scale_t_mt_13TeVUp";
    if (tes==-1)
      postfix="_CMS_scale_t_mt_13TeVDown";
    if (tes==15)
      postfix="_CMS_htt_ZLShape_mt_13TeVUp";
    if (tes==-15)
      postfix="_CMS_htt_ZLShape_mt_13TeVDown";
    if (tes==3)
      postfix="_CMS_scale_met_13TeVUp";
    if (tes==-3)
      postfix="_CMS_scale_met_13TeVDown";
    if (tes==100)
      postfix="_CMS_scale_j_13TeVUp";
    if (tes==-100)
      postfix="_CMS_scale_j_13TeVDown";
    if (tes==12)
      postfix="_CMS_scale_gg_13TeVUp";
    if (tes==-12)
      postfix="_CMS_scale_gg_13TeVDown";
    if (tes==22)
      postfix="_TopMassTreatment_13TeVUp";
    if (tes==-22)
      postfix="_TopMassTreatment_13TeVDown";
    if (tes==11)
      postfix="_CMS_htt_ttbarShape_13TeVUp";
    if (tes==-11)
      postfix="_CMS_htt_ttbarShape_13TeVDown";
    if (tes==-13)
      postfix="_CMS_htt_zmumuShape_VBF_13TeVDown";
    if (tes==13)
      postfix="_CMS_htt_zmumuShape_VBF_13TeVUp";
    if (tes==10)
      postfix="_CMS_htt_dyShape_13TeVUp";
    if (tes==-10)
      postfix="_CMS_htt_dyShape_13TeVDown";
    if (tes==-14)
      postfix="_CMS_htt_jetToTauFake_13TeVDown";
    if (tes==14)
      postfix="_CMS_htt_jetToTauFake_13TeVUp";
    
    TDirectory *CRQCD0jet =fout->mkdir("mt_antiiso_0jet_cr");
    TDirectory *CRQCD1jet =fout->mkdir("mt_antiiso_boosted_cr");
    TDirectory *CRQCD2jet =fout->mkdir("mt_antiiso_vbf_cr");
    TDirectory *CRW0jet =fout->mkdir("mt_wjets_0jet_cr");
    TDirectory *CRW1jet =fout->mkdir("mt_wjets_boosted_cr");
    TDirectory *CRW2jet =fout->mkdir("mt_wjets_vbf_cr");
    TDirectory *CRSSQCD0jet =fout->mkdir("mt_antiiso_0jet_crSS");
    TDirectory *CRSSQCD1jet =fout->mkdir("mt_antiiso_boosted_crSS");
    TDirectory *CRSSQCD2jet =fout->mkdir("mt_antiiso_vbf_crSS");
    TDirectory *CRSSW0jet =fout->mkdir("mt_wjets_0jet_crSS");
    TDirectory *CRSSW1jet =fout->mkdir("mt_wjets_boosted_crSS");
    TDirectory *CRSSW2jet =fout->mkdir("mt_wjets_vbf_crSS");
    TDirectory *OS0jet =fout->mkdir("mt_0jet");
    TDirectory *SS0jet =fout->mkdir("SS0jet");
    TDirectory *QCD0jet =fout->mkdir("QCD0jet");
    TDirectory *OS1jet =fout->mkdir("mt_boosted");
    TDirectory *SS1jet =fout->mkdir("SS1jet");
    TDirectory *QCD1jet =fout->mkdir("QCD1jet");
    TDirectory *OS2jet =fout->mkdir("mt_vbf");
    TDirectory *SS2jet =fout->mkdir("SSvbf");
    TDirectory *QCD2jet =fout->mkdir("QCDvbf");

    if (nbhist==1) postfixJES[0]=postfix;

    for (int k=0; k<nbhist; ++k){
      
      if (tes==100) postfix=postfixJES[k];
      if (tes==1) postfix=postfixTES[k];
      if (tes==16) postfix=postfixDM[k];
      if (tes==17) postfix=postfixZLshape[k];
      if (tes==18) postfix=postfixZLnorm[k];
      if (tes==19) postfix=postfixFakeDM[k];
      if (tes==1000) postfix=postfixWG1[k];
      
      fout->cd();
      n70[k]->SetName("n70"+postfix);
      n70[k]->Write();
      n70SS[k]->SetName("n70SS"+postfix);
      n70SS[k]->Write();
    }
    
    for (int k=0; k<nbhist; ++k){
      
      if (tes==100) postfix=postfixJES[k];
      if (tes==1) postfix=postfixTES[k];
      if (tes==16) postfix=postfixDM[k];
      if (tes==17) postfix=postfixZLshape[k];
      if (tes==18) postfix=postfixZLnorm[k];
      if (tes==19) postfix=postfixFakeDM[k];
      if (tes==1000) postfix=postfixWG1[k];
      
      for (int nn=1; nn<h0_OS[k]->GetSize()-1; ++nn){
	if (h0_OS[k]->GetBinContent(nn)<0) h0_OS[k]->SetBinContent(nn,0.00001);
	if (h0_SS[k]->GetBinContent(nn)<0) h0_SS[k]->SetBinContent(nn,0.00001);
	if (h0_QCD[k]->GetBinContent(nn)<0) h0_QCD[k]->SetBinContent(nn,0.00001);
	if (h0_WOS[k]->GetBinContent(nn)<0) h0_WOS[k]->SetBinContent(nn,0.00001);
	if (h0_WSS[k]->GetBinContent(nn)<0) h0_WSS[k]->SetBinContent(nn,0.00001);
	if (h1_OS[k]->GetBinContent(nn)<0) h1_OS[k]->SetBinContent(nn,0.00001);
	if (h1_SS[k]->GetBinContent(nn)<0) h1_SS[k]->SetBinContent(nn,0.00001);
	if (h1_QCD[k]->GetBinContent(nn)<0) h1_QCD[k]->SetBinContent(nn,0.00001);
	if (h1_WOS[k]->GetBinContent(nn)<0) h1_WOS[k]->SetBinContent(nn,0.00001);
	if (h1_WSS[k]->GetBinContent(nn)<0) h1_WSS[k]->SetBinContent(nn,0.00001);
	if (h2_OS[k]->GetBinContent(nn)<0) h2_OS[k]->SetBinContent(nn,0.00001);
	if (h2_SS[k]->GetBinContent(nn)<0) h2_SS[k]->SetBinContent(nn,0.00001);
	if (h2_QCD[k]->GetBinContent(nn)<0) h2_QCD[k]->SetBinContent(nn,0.00001);
	if (h2_WOS[k]->GetBinContent(nn)<0) h2_WOS[k]->SetBinContent(nn,0.00001);
	if (h2_WSS[k]->GetBinContent(nn)<0) h2_WSS[k]->SetBinContent(nn,0.00001);
      }
      
      CRQCD0jet->cd();
      h0_CR_QCD[k]->SetName(name.c_str()+postfix);
      h0_CR_QCD[k]->Write();
      
      CRQCD1jet->cd();
      h1_CR_QCD[k]->SetName(name.c_str()+postfix);
      h1_CR_QCD[k]->Write();
      
      CRQCD2jet->cd();
      h2_CR_QCD[k]->SetName(name.c_str()+postfix);
      h2_CR_QCD[k]->Write();
      
      CRW0jet->cd();
      h0_CR_W[k]->SetName(name.c_str()+postfix);
      h0_CR_W[k]->Write();
      
      CRW1jet->cd();
      h1_CR_W[k]->SetName(name.c_str()+postfix);
      h1_CR_W[k]->Write();
      
      CRW2jet->cd();
      h2_CR_W[k]->SetName(name.c_str()+postfix);
      h2_CR_W[k]->Write();
      
      CRSSQCD0jet->cd();
      h0_CRSS_QCD[k]->SetName(name.c_str()+postfix);
      h0_CRSS_QCD[k]->Write();
      
      CRSSQCD1jet->cd();
      h1_CRSS_QCD[k]->SetName(name.c_str()+postfix);
      h1_CRSS_QCD[k]->Write();
      
      CRSSQCD2jet->cd();
      h2_CRSS_QCD[k]->SetName(name.c_str()+postfix);
      h2_CRSS_QCD[k]->Write();
      
      CRSSW0jet->cd();
      h0_CRSS_W[k]->SetName(name.c_str()+postfix);
      h0_CRSS_W[k]->Write();
      
      CRSSW1jet->cd();
      h1_CRSS_W[k]->SetName(name.c_str()+postfix);
      h1_CRSS_W[k]->Write();
      
      CRSSW2jet->cd();
      h2_CRSS_W[k]->SetName(name.c_str()+postfix);
      h2_CRSS_W[k]->Write();
      
      OS0jet->cd();
      h0_OS[k]->SetName(name.c_str()+postfix);
      h0_WOS[k]->SetName(name.c_str()+postfix);
      h0_OS[k]->Write();
      
      SS0jet->cd();
      h0_SS[k]->SetName(name.c_str()+postfix);
      h0_WSS[k]->SetName(name.c_str()+postfix);
      h0_SS[k]->Write();
      
      QCD0jet->cd();
      h0_QCD[k]->SetName(name.c_str()+postfix);
      h0_QCD[k]->Write();
      
      OS1jet->cd();
      h1_OS[k]->SetName(name.c_str()+postfix);
      h1_WOS[k]->SetName(name.c_str()+postfix);
      if (sample=="W")
	h1_WOS[k]->Write();
      else
	h1_OS[k]->Write();
      
      SS1jet->cd();
      h1_SS[k]->SetName(name.c_str()+postfix);
      h1_WSS[k]->SetName(name.c_str()+postfix);
      if (sample=="W")
	h1_WSS[k]->Write();
      else
	h1_SS[k]->Write();
      
      QCD1jet->cd();
      h1_QCD[k]->SetName(name.c_str()+postfix);
      h1_QCD[k]->Write();
      
      OS2jet->cd();
      h2_OS[k]->SetName(name.c_str()+postfix);
      h2_WOS[k]->SetName(name.c_str()+postfix);
      if (sample=="W")
	h2_WOS[k]->Write();
      else
	h2_OS[k]->Write();
      
      SS2jet->cd();
      h2_SS[k]->SetName(name.c_str()+postfix);
      h2_WSS[k]->SetName(name.c_str()+postfix);
      if (sample=="W")
	h2_WSS[k]->Write();
      else
	h2_SS[k]->Write();
      
      QCD2jet->cd();
      h2_QCD[k]->SetName(name.c_str()+postfix);
      h2_QCD[k]->Write();
    }
    cout<<h0_OS[0]->Integral()<<" "<<h1_OS[0]->Integral()<<" "<<h2_OS[0]->Integral()<<endl;
    fout->Close();
} 


