#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include "Python.h"
#include <typeinfo>
// ROOT
#include <TH2.h>
#include <TH3.h>
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
// my includes
#include "../include/myHelper.h"
#include "../include/tt_Tree.h"
#include "../include/ScaleFactor.h"
#include "../include/LumiReweightingStandAlone.h"
#include "../include/lumiMap.h"
#include "../include/btagSF.h"
#include "../include/scenario_info.h"
#include "../include/zmumuSF.h"

//FF
#include "../../../../../HTTutilities/Jet2TauFakes/interface/FakeFactor.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/WrapperTGraph.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/WrapperTH2F.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/WrapperTH3D.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/WrapperTFormula.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/IFunctionWrapper.h"


using namespace std;
int main(int argc, char** argv) {
    
    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string sample = *(argv + 3);
    std::string name = *(argv + 4);
    std::string shape = *(argv + 5);

    float tes=0;
    if (argc > 1) {
        tes = atof(argv[6]);
    }
    
    TFile *f_Double = new TFile(input.c_str());
    std::cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<std::endl;
    TTree *arbre = (TTree*) f_Double->Get("tt_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);
    std::cout.precision(11);
    
    //Declaration of files with scale factors
    TFile *f_Trk=new TFile("weightROOTs/Tracking_EfficienciesAndSF_BCDEFGH.root");
    TGraph *h_Trk=(TGraph*) f_Trk->Get("weightROOTs/ratio_eff_eta3_dr030e030_corr");
    
    reweight::LumiReWeighting* LumiWeights_12;
    LumiWeights_12 = new reweight::LumiReWeighting("weightROOTs/MC_Moriond17_PU25ns_V1.root", "weightROOTs/Data_Pileup_2016_271036-284044_80bins.root", "pileup", "pileup");
    
    TFile *fZ=new TFile("weightROOTs/zpt_weights_2016_BtoH.root");
    TH2F *histZ=(TH2F*) fZ->Get("zptmass_histo");
    
    TFile fw("weightROOTs/htt_scalefactors_v16_3.root");
    RooWorkspace *w = (RooWorkspace*)fw.Get("w");
    fw.Close();
    
    TFile fw2("weightROOTs/htt_scalefactors_sm_moriond_v1.root");
    RooWorkspace *w2 = (RooWorkspace*)fw2.Get("w");
    fw2.Close();

    
    
    TFile *FakeFraction=new TFile("FakeFraction_tautau_3D.root");
    TH3F *fakefrac_0jet=(TH3F*) FakeFraction->Get("0jet/0jet");
    TH3F *fakefrac_boosted=(TH3F*) FakeFraction->Get("boosted/boosted");
    TH3F *fakefrac_vbf=(TH3F*) FakeFraction->Get("vbf/vbf");

    
    
    
    // D.Kim
    const char *scriptDirectoryName = "./../python/";
    Py_Initialize();
    PyObject *sysPath = PySys_GetObject((char *)"path");
    PyObject *path = PyString_FromString(scriptDirectoryName);
    PyList_Insert(sysPath, 0, path);
    PyObject* fitFunctions =  PyImport_ImportModule((char *)"FitFunctions");
    // The line below breaks the code
    PyObject* compute_sf = PyObject_GetAttrString(fitFunctions,"compute_SF");

    float weight = 1.0;
    // Lumi weight  
    float w_lumi = lumiWeight(sample, ngen);
    if (w_lumi==0) std::cout << std::endl << "!!!!!!!!!!!!!!!!!!!!!!!! ATTENTION - can't find lumi weight. Check the sample. !!!!!!!!!!!!!!!!!!!!!!!!" << std::endl << std::endl;
    weight = w_lumi;

    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(10);

    // event
    arbre->SetBranchAddress("run", &run);
    arbre->SetBranchAddress("lumi", &lumi);
    arbre->SetBranchAddress("evt", &evt);
    arbre->SetBranchAddress("npv", &npv);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("genpT",&genpT);
    arbre->SetBranchAddress("genM",&genM);
    arbre->SetBranchAddress("numGenJets",&numGenJets);
    arbre->SetBranchAddress("amcatNLO_weight", &amcatNLO_weight);
    // triggers
    arbre->SetBranchAddress("passDoubleTau35", &passDoubleTau35);
    arbre->SetBranchAddress("matchDoubleTau35_1", &matchDoubleTau35_1);
    arbre->SetBranchAddress("matchDoubleTau35_2", &matchDoubleTau35_2);
    arbre->SetBranchAddress("filterDoubleTau35_1", &filterDoubleTau35_1);
    arbre->SetBranchAddress("filterDoubleTau35_2", &filterDoubleTau35_2);
    arbre->SetBranchAddress("passDoubleTauCmbIso35", &passDoubleTauCmbIso35);
    arbre->SetBranchAddress("matchDoubleTauCmbIso35_1", &matchDoubleTauCmbIso35_1);
    arbre->SetBranchAddress("matchDoubleTauCmbIso35_2", &matchDoubleTauCmbIso35_2);
    arbre->SetBranchAddress("filterDoubleTauCmbIso35_1", &filterDoubleTauCmbIso35_1);
    arbre->SetBranchAddress("filterDoubleTauCmbIso35_2", &filterDoubleTauCmbIso35_2);
    // taus
    arbre->SetBranchAddress("px_1", &px_1);
    arbre->SetBranchAddress("py_1", &py_1);
    arbre->SetBranchAddress("pz_1", &pz_1);
    arbre->SetBranchAddress("pt_1", &pt_1);
    arbre->SetBranchAddress("phi_1", &phi_1);
    arbre->SetBranchAddress("eta_1", &eta_1);
    arbre->SetBranchAddress("iso_1", &iso_1);
    arbre->SetBranchAddress("m_1", &m_1);
    arbre->SetBranchAddress("q_1", &q_1);
    arbre->SetBranchAddress("q_2", &q_2);
    arbre->SetBranchAddress("px_2", &px_2);
    arbre->SetBranchAddress("py_2", &py_2);
    arbre->SetBranchAddress("pz_2", &pz_2);
    arbre->SetBranchAddress("pt_2", &pt_2);
    arbre->SetBranchAddress("eta_2", &eta_2);
    arbre->SetBranchAddress("iso_2", &iso_2);
    arbre->SetBranchAddress("m_2", &m_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("t1_decayMode",&t1_decayMode);
    arbre->SetBranchAddress("t2_decayMode",&t2_decayMode);
    arbre->SetBranchAddress("gen_match_1",&gen_match_1);
    arbre->SetBranchAddress("gen_match_2",&gen_match_2);
    arbre->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_1",&byVLooseIsolationMVArun2v1DBoldDMwLT_1);
    arbre->SetBranchAddress("byLooseIsolationMVArun2v1DBoldDMwLT_1",&byLooseIsolationMVArun2v1DBoldDMwLT_1);
    arbre->SetBranchAddress("byMediumIsolationMVArun2v1DBoldDMwLT_1",&byMediumIsolationMVArun2v1DBoldDMwLT_1);
    arbre->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_1",&byTightIsolationMVArun2v1DBoldDMwLT_1);
    arbre->SetBranchAddress("byVTightIsolationMVArun2v1DBoldDMwLT_1",&byVTightIsolationMVArun2v1DBoldDMwLT_1);
    arbre->SetBranchAddress("againstElectronVLooseMVA6_1",&againstElectronVLooseMVA6_1);
    arbre->SetBranchAddress("againstElectronLooseMVA6_1",&againstElectronLooseMVA6_1);
    arbre->SetBranchAddress("againstElectronMediumMVA6_1",&againstElectronMediumMVA6_1);
    arbre->SetBranchAddress("againstElectronTightMVA6_1",&againstElectronTightMVA6_1);
    arbre->SetBranchAddress("againstElectronVTightMVA6_1",&againstElectronVTightMVA6_1);
    arbre->SetBranchAddress("againstMuonLoose3_1",&againstMuonLoose3_1);
    arbre->SetBranchAddress("againstMuonTight3_1",&againstMuonTight3_1);
    arbre->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_2",&byVLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationMVArun2v1DBoldDMwLT_2",&byLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationMVArun2v1DBoldDMwLT_2",&byMediumIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_2",&byTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationMVArun2v1DBoldDMwLT_2",&byVTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("againstElectronVLooseMVA6_2",&againstElectronVLooseMVA6_2);
    arbre->SetBranchAddress("againstElectronLooseMVA6_2",&againstElectronLooseMVA6_2);
    arbre->SetBranchAddress("againstElectronMediumMVA6_2",&againstElectronMediumMVA6_2);
    arbre->SetBranchAddress("againstElectronTightMVA6_2",&againstElectronTightMVA6_2);
    arbre->SetBranchAddress("againstElectronVTightMVA6_2",&againstElectronVTightMVA6_2);
    arbre->SetBranchAddress("againstMuonLoose3_2",&againstMuonLoose3_2);
    arbre->SetBranchAddress("againstMuonTight3_2",&againstMuonTight3_2);
    // jets
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("jeta_1", &jeta_1);
    arbre->SetBranchAddress("jphi_1", &jphi_1);
    arbre->SetBranchAddress("jcsv_1", &jcsv_1);
    arbre->SetBranchAddress("jpt_2", &jpt_2);
    arbre->SetBranchAddress("jeta_2", &jeta_2);
    arbre->SetBranchAddress("jphi_2", &jphi_2);
    arbre->SetBranchAddress("jcsv_2", &jcsv_2);
    //arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("njets_JESDown", &njets_JESDown);
    arbre->SetBranchAddress("njets_JESUp", &njets_JESUp);
    // bjets
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("nbtagL", &nbtagL);
    arbre->SetBranchAddress("bpt_1",&bpt_1);
    arbre->SetBranchAddress("bpt_2",&bpt_2);
    arbre->SetBranchAddress("bflavor_1",&bflavor_1);
    arbre->SetBranchAddress("bflavor_2",&bflavor_2);
    // met
    //arbre->SetBranchAddress("met", &met);
    //arbre->SetBranchAddress("metphi", &metphi);
    arbre->SetBranchAddress("metphi_JESDown", &metphi_JESDown);
    arbre->SetBranchAddress("metphi_JESUp", &metphi_JESUp);
    arbre->SetBranchAddress("met_JESDown", &met_JESDown);
    arbre->SetBranchAddress("met_JESUp", &met_JESUp);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);
    // top
    arbre->SetBranchAddress("pt_top1",&pt_top1);
    arbre->SetBranchAddress("pt_top2",&pt_top2);
    // svFit
    //arbre->SetBranchAddress("m_sv",&m_sv);
    //arbre->SetBranchAddress("pt_sv", &pt_sv);
    // MELA
    //arbre->SetBranchAddress("ME_sm_VBF",&ME_sm_VBF); // What we actually use.
    //arbre->SetBranchAddress("ME_sm_ggH",&ME_sm_ggH);
    //arbre->SetBranchAddress("ME_bkg",&ME_bkg); // What we actually use.

    scenario_info scenario(arbre, shape);
    
    // D.Kim : AN line 791~795
    //Binning for 0jet cat. 1D: Msv. In AN it was 10GeV binning / official data card combined 0~50 as one bin
    float bins0[] = {0,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
    float bins1[] = {0,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
    float bins11[] = {0,100,170,300,10000};
    //Binning for 1jet cat, y-axis: Msv
    float bins12[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};
    //Binning for 2jet cat, x-axis: Mjj
    float bins21[] = {0,300,500,800,10000};
    //binning for 2jet cat, x-axis: Dbkg_VBF
    //float bins21[] = {0.0,0.3,0.6,0.9,1.0};
    //Binning for 2jet cat, y-axis: Msv
    float bins22[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};

    float binsRND0[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};
    float binsRND1[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};
    float binsRND2[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};


    int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
    int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;

    int  binnum11 = sizeof(bins11)/sizeof(Float_t) - 1;
    int  binnum12 = sizeof(bins12)/sizeof(Float_t) - 1;
    int  binnum21 = sizeof(bins21)/sizeof(Float_t) - 1;
    int  binnum22 = sizeof(bins22)/sizeof(Float_t) - 1;

    int  binnumRND0 = sizeof(binsRND0)/sizeof(Float_t) - 1;
    int  binnumRND1 = sizeof(binsRND1)/sizeof(Float_t) - 1;
    int  binnumRND2 = sizeof(binsRND2)/sizeof(Float_t) - 1;

    // Categories
    TH1F* h_0jet = new TH1F ("h_0jet", "h_0jet", binnum0, bins0); h_0jet->Sumw2();
    TH1F* h_boosted = new TH1F ("h_boosted", "h_boosted", binnum0, bins0); h_boosted->Sumw2();
    TH1F* h_vbf = new TH1F ("h_vbf", "h_vbf", binnum0, bins0); h_vbf->Sumw2();
    TH1F* h_inc = new TH1F ("h_inc", "h_inc", binnum0, bins0); h_inc->Sumw2();
    TH1F* hx_boosted = new TH1F ("hx_boosted", "hx_boosted", binnum11, bins11); hx_boosted->Sumw2();
    TH1F* hy_boosted = new TH1F ("hy_boosted", "hy_boosted", binnum12, bins12); hy_boosted->Sumw2();
    TH1F* hx_vbf = new TH1F ("hx_vbf", "hx_vbf", binnum21, bins21); hx_vbf->Sumw2();
    TH1F* hy_vbf = new TH1F ("hy_vbf", "hy_vbf", binnum22, bins22); hy_vbf->Sumw2();

    // h0_ : 0jet, h1_ : boosted, h2_ : vbf, h3_ : vh, h2M*_ : vbf with MELA, h4M_ : 2jets with MEAL  h_ : inclusive
    std::vector<TH1F*> h0_OS;
    std::vector<TH1F*> h0_SS;
    std::vector<TH1F*> h0_AIOS;
    std::vector<TH1F*> h0_AISS;
    std::vector<TH1F*> h1_OS;
    std::vector<TH1F*> h1_SS;
    std::vector<TH1F*> h1_AIOS;
    std::vector<TH1F*> h1_AISS;
    std::vector<TH1F*> h2_OS;
    std::vector<TH1F*> h2_SS;
    std::vector<TH1F*> h2_AIOS;
    std::vector<TH1F*> h2_AISS;
    std::vector<TH1F*> h3_OS;
    std::vector<TH1F*> h3_SS;
    std::vector<TH1F*> h3_AIOS;
    std::vector<TH1F*> h3_AISS;
    std::vector<TH1F*> h_OS;
    std::vector<TH1F*> h_SS;
    std::vector<TH1F*> h_AIOS;
    std::vector<TH1F*> h_AISS;

    std::vector<TH1F*> h_trgSF1;
    std::vector<TH1F*> h_trgSF2;
    std::vector<TH1F*> h_trgSF_RR;
    std::vector<TH1F*> h_trgSF_FR;
    std::vector<TH1F*> h_trgSF_RF;
    std::vector<TH1F*> h_trgSF_FF;
    // tmp histogram for R&D
    std::vector<TH1F*> h0_rndOS;
    std::vector<TH1F*> h1_rndOS;
    std::vector<TH1F*> h2_rndOS;
    std::vector<TH1F*> h0_rndSS;
    std::vector<TH1F*> h1_rndSS;
    std::vector<TH1F*> h2_rndSS;
    std::vector<TH1F*> h0_rndAIOS;
    std::vector<TH1F*> h1_rndAIOS;
    std::vector<TH1F*> h2_rndAIOS;
    std::vector<TH1F*> h0_rndAISS;
    std::vector<TH1F*> h1_rndAISS;
    std::vector<TH1F*> h2_rndAISS;

    
    
    
    //FakeFactor 0 jet
    std::vector<TH1F*> h0tau_OS;
    std::vector<TH1F*> h0ell_OS;
    std::vector<TH1F*> h0_AI;
    
    //FakeFactor boosted
    std::vector<TH1F*> h1tau_OS;
    std::vector<TH1F*> h1ell_OS;
    std::vector<TH1F*> h1_AI;
    
    //FakeFactor vbf
    std::vector<TH1F*> h2tau_OS;
    std::vector<TH1F*> h2ell_OS;
    std::vector<TH1F*> h2_AI;
    
    
    //###############################################################
    // Adding the Fake Factor
    //###############################################################
    
    
    TFile* ff_file_0jet = TFile::Open("HTTutilities/Jet2TauFakes/data/SM2016_ML/tight/tt/fakeFactors_tt_inclusive.root");
    FakeFactor* ff_0jet = (FakeFactor*)ff_file_0jet->Get("ff_comb");

    std::vector<double> input_1(8);
    std::vector<double> input_2(8);
    std::string FFsys[31]={"","ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};
    TString postfixFF[31]={"","_norm_ff_qcd_mt_systUp","_norm_ff_qcd_mt_systDown","_norm_ff_qcd_dm0_njet0_mt_statUp","_norm_ff_qcd_dm0_njet0_mt_statDown","_norm_ff_qcd_dm0_njet1_mt_statUp","_norm_ff_qcd_dm0_njet1_mt_statDown","_norm_ff_qcd_dm1_njet0_mt_statUp","_norm_ff_qcd_dm1_njet0_mt_statDown","_norm_ff_qcd_dm1_njet1_mt_statUp","_norm_ff_qcd_dm1_njet1_mt_statDown","_norm_ff_w_mt_systUp","_norm_ff_w_mt_systDown","_norm_ff_w_dm0_njet0_mt_statUp","_norm_ff_w_dm0_njet0_mt_statDown","_norm_ff_w_dm0_njet1_mt_statUp","_norm_ff_w_dm0_njet1_mt_statDown","_norm_ff_w_dm1_njet0_mt_statUp","_norm_ff_w_dm1_njet0_mt_statDown","_norm_ff_w_dm1_njet1_mt_statUp","_norm_ff_w_dm1_njet1_mt_statDown","_norm_ff_tt_mt_systUp","_norm_ff_tt_mt_systDown","_norm_ff_tt_dm0_njet0_mt_statUp","_norm_ff_tt_dm0_njet0_mt_statDown","_norm_ff_tt_dm0_njet1_mt_statUp","_norm_ff_tt_dm0_njet1_mt_statDown","_norm_ff_tt_dm1_njet0_mt_statUp","_norm_ff_tt_dm1_njet0_mt_statDown","_norm_ff_tt_dm1_njet1_mt_statUp","_norm_ff_tt_dm1_njet1_mt_statDown"};
    
    //###############################################################
    
    

    

    TString postfix="";
    //For shape systematics
    int nbhist=1;
    if (tes==100) {
      //KK For now use combined JES
      nbhist=2;
      //nbhist=56;
    }
    if (tes==1) nbhist=12;
    if (tes==16) nbhist=6;
    if (tes==17) nbhist=12;
    if (tes==18) nbhist=4;
    if (tes==19) nbhist=6;
    if (tes==1000) nbhist=18;

    for (int k=0; k<nbhist; ++k){
      std::ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
      std::ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
      std::ostringstream HNS2OS; HNS2OS << "h2_OS" << k;
      std::ostringstream HNS2M1OS; HNS2M1OS << "h2M1_OS" << k;
      std::ostringstream HNS2M2OS; HNS2M2OS << "h2M2_OS" << k;
      std::ostringstream HNS2M3OS; HNS2M3OS << "h2M3_OS" << k;
      std::ostringstream HNS4M1OS; HNS4M1OS << "h4M1_OS" << k;
      std::ostringstream HNS4M2OS; HNS4M2OS << "h4M2_OS" << k;
      std::ostringstream HNS3OS; HNS3OS << "h3_OS" << k;
      std::ostringstream HNSOS; HNS2OS << "h_OS" << k;
      
      h0_OS.push_back(new TH1F (HNS0OS.str().c_str(),"diTauMa",binnum0,bins0)); h0_OS[k]->Sumw2();
      h1_OS.push_back(new TH1F (HNS1OS.str().c_str(),"diTauMa",binnum0,bins0)); h1_OS[k]->Sumw2();
      h2_OS.push_back(new TH1F (HNS2OS.str().c_str(),"diTauMa",binnum0,bins0)); h2_OS[k]->Sumw2();
      
      h3_OS.push_back(new TH1F (HNS3OS.str().c_str(),"diTauMa",binnum0,bins0)); h3_OS[k]->Sumw2();
      h_OS.push_back(new TH1F (HNSOS.str().c_str(),"diTauMa",binnum0,bins0)); h_OS[k]->Sumw2();
      
      std::ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
      std::ostringstream HNS1SS; HNS1OS << "h1_SS" << k;
      std::ostringstream HNS2SS; HNS2OS << "h2_SS" << k;
      std::ostringstream HNS3SS; HNS2OS << "h3_SS" << k;
      std::ostringstream HNSSS; HNSOS << "h_SS" << k;

      h0_SS.push_back(new TH1F (HNS0SS.str().c_str(),"diTauMa",binnum1,bins1)); h0_SS[k]->Sumw2();
      h1_SS.push_back(new TH1F (HNS1SS.str().c_str(),"diTauMa",binnum1,bins1)); h1_SS[k]->Sumw2();
      h2_SS.push_back(new TH1F (HNS2SS.str().c_str(),"diTauMa",binnum1,bins1)); h2_SS[k]->Sumw2();
      h3_SS.push_back(new TH1F (HNS3SS.str().c_str(),"diTauMa",binnum1,bins1)); h3_SS[k]->Sumw2();
      h_SS.push_back(new TH1F (HNSSS.str().c_str(),"diTauMa",binnum1,bins1)); h_SS[k]->Sumw2();
      
      std::ostringstream HNS0AIOS; HNS0AIOS << "h0_AIOS" << k;
      std::ostringstream HNS1AIOS; HNS1AIOS << "h1_AIOS" << k;
      std::ostringstream HNS2AIOS; HNS2AIOS << "h2_AIOS" << k;
      std::ostringstream HNS3AIOS; HNS3AIOS << "h3_AIOS" << k;
      std::ostringstream HNSAIOS; HNSAIOS << "h_AIOS" << k;

      h0_AIOS.push_back(new TH1F (HNS0AIOS.str().c_str(),"diTauMa",binnum0,bins0)); h0_AIOS[k]->Sumw2();
      h1_AIOS.push_back(new TH1F (HNS1AIOS.str().c_str(),"diTauMa",binnum1,bins1)); h1_AIOS[k]->Sumw2();
      h2_AIOS.push_back(new TH1F (HNS2AIOS.str().c_str(),"diTauMa",binnum1,bins1)); h2_AIOS[k]->Sumw2();
      h3_AIOS.push_back(new TH1F (HNS3AIOS.str().c_str(),"diTauMa",binnum1,bins1)); h3_AIOS[k]->Sumw2();
      h_AIOS.push_back(new TH1F (HNSAIOS.str().c_str(),"diTauMa",binnum0,bins0)); h_AIOS[k]->Sumw2();
        
      std::ostringstream HNS0AISS; HNS0AISS << "h0_AISS" << k;
      std::ostringstream HNS1AISS; HNS1AISS << "h1_AISS" << k;
      std::ostringstream HNS2AISS; HNS2AISS << "h2_AISS" << k;
      std::ostringstream HNS3AISS; HNS3AISS << "h3_AISS" << k;
      std::ostringstream HNSAISS; HNSAISS << "h_AISS" << k;

      h0_AISS.push_back(new TH1F (HNS0AISS.str().c_str(),"diTauMa",binnum1,bins1)); h0_AISS[k]->Sumw2();
      h1_AISS.push_back(new TH1F (HNS1AISS.str().c_str(),"diTauMa",binnum1,bins1)); h1_AISS[k]->Sumw2();
      h2_AISS.push_back(new TH1F (HNS2AISS.str().c_str(),"diTauMa",binnum1,bins1)); h2_AISS[k]->Sumw2();
      h3_AISS.push_back(new TH1F (HNS3AISS.str().c_str(),"diTauMa",binnum1,bins1)); h3_AISS[k]->Sumw2();
      h_AISS.push_back(new TH1F (HNSAISS.str().c_str(),"diTauMa",binnum1,bins1)); h_AISS[k]->Sumw2();
      
      // D.Kim trgSF
      std::ostringstream HTRGSF1; HTRGSF1 << "h_trgSF1" << k;
      std::ostringstream HTRGSF2; HTRGSF2 << "h_trgSF2" << k;
      std::ostringstream HTRGSFRR; HTRGSFRR << "h_trgSF_RR" << k;
      std::ostringstream HTRGSFFR; HTRGSFFR << "h_trgSF_FR" << k;
      std::ostringstream HTRGSFRF; HTRGSFRF << "h_trgSF_RF" << k;
      std::ostringstream HTRGSFFF; HTRGSFFF << "h_trgSF_FF" << k;
      h_trgSF1.push_back(new TH1F (HTRGSF1.str().c_str(),"trgSF1", 80,1.00,1.10)); h_trgSF1[k]->Sumw2();
      h_trgSF2.push_back(new TH1F (HTRGSF2.str().c_str(),"trgSF2", 80,0.97,1.15)); h_trgSF2[k]->Sumw2();
      h_trgSF_RR.push_back(new TH1F (HTRGSFRR.str().c_str(),"trgSF_RR", 100,0.9,1.5)); h_trgSF_RR[k]->Sumw2();
      h_trgSF_FR.push_back(new TH1F (HTRGSFFR.str().c_str(),"trgSF_FR", 100,0.9,1.5)); h_trgSF_FR[k]->Sumw2();
      h_trgSF_RF.push_back(new TH1F (HTRGSFRF.str().c_str(),"trgSF_RF", 100,0.9,1.5)); h_trgSF_RF[k]->Sumw2();
      h_trgSF_FF.push_back(new TH1F (HTRGSFFF.str().c_str(),"trgSF_FF", 100,0.9,1.5)); h_trgSF_FF[k]->Sumw2();
      // tmp histogram for R&D
      std::string rndobs = "m_sv";
      std::ostringstream H0RNDOS; H0RNDOS << "h0_rndOS" << k;
      std::ostringstream H1RNDOS; H1RNDOS << "h1_rndOS" << k;
      std::ostringstream H2RNDOS; H2RNDOS << "h2_rndOS" << k;
      h0_rndOS.push_back(new TH1F (H0RNDOS.str().c_str(), rndobs.c_str(), binnumRND0, binsRND0)); h0_rndOS[k]->Sumw2();
      h1_rndOS.push_back(new TH1F (H1RNDOS.str().c_str(), rndobs.c_str(), binnumRND1, binsRND1)); h1_rndOS[k]->Sumw2();
      h2_rndOS.push_back(new TH1F (H2RNDOS.str().c_str(), rndobs.c_str(), binnumRND2, binsRND2)); h2_rndOS[k]->Sumw2();
      std::ostringstream H0RNDSS; H0RNDSS << "h0_rndSS" << k;
      std::ostringstream H1RNDSS; H1RNDSS << "h1_rndSS" << k;
      std::ostringstream H2RNDSS; H2RNDSS << "h2_rndSS" << k;
      h0_rndSS.push_back(new TH1F (H0RNDSS.str().c_str(), rndobs.c_str(), binnumRND0, binsRND0)); h0_rndSS[k]->Sumw2();
      h1_rndSS.push_back(new TH1F (H1RNDSS.str().c_str(), rndobs.c_str(), binnumRND1, binsRND1)); h1_rndSS[k]->Sumw2();
      h2_rndSS.push_back(new TH1F (H2RNDSS.str().c_str(), rndobs.c_str(), binnumRND2, binsRND2)); h2_rndSS[k]->Sumw2();
      std::ostringstream H0RNDAIOS; H0RNDAIOS << "h0_rndAIOS" << k;
      std::ostringstream H1RNDAIOS; H1RNDAIOS << "h1_rndAIOS" << k;
      std::ostringstream H2RNDAIOS; H2RNDAIOS << "h2_rndAIOS" << k;
      h0_rndAIOS.push_back(new TH1F (H0RNDAIOS.str().c_str(), rndobs.c_str(), binnumRND0, binsRND0)); h0_rndAIOS[k]->Sumw2();
      h1_rndAIOS.push_back(new TH1F (H1RNDAIOS.str().c_str(), rndobs.c_str(), binnumRND1, binsRND1)); h1_rndAIOS[k]->Sumw2();
      h2_rndAIOS.push_back(new TH1F (H2RNDAIOS.str().c_str(), rndobs.c_str(), binnumRND2, binsRND2)); h2_rndAIOS[k]->Sumw2();
      std::ostringstream H0RNDAISS; H0RNDAISS << "h0_rndAISS" << k;
      std::ostringstream H1RNDAISS; H1RNDAISS << "h1_rndAISS" << k;
      std::ostringstream H2RNDAISS; H2RNDAISS << "h2_rndAISS" << k;
      h0_rndAISS.push_back(new TH1F (H0RNDAISS.str().c_str(), rndobs.c_str(), binnumRND0, binsRND0)); h0_rndAISS[k]->Sumw2();
      h1_rndAISS.push_back(new TH1F (H1RNDAISS.str().c_str(), rndobs.c_str(), binnumRND1, binsRND1)); h1_rndAISS[k]->Sumw2();
      h2_rndAISS.push_back(new TH1F (H2RNDAISS.str().c_str(), rndobs.c_str(), binnumRND2, binsRND2)); h2_rndAISS[k]->Sumw2();
     
        //FakeFactor  0jet
        
        ostringstream HNSh0tau_OS; HNSh0tau_OS << "h0tau_OS" << k;
        ostringstream HNSh0ell_OS; HNSh0ell_OS << "h0ell_OS" << k;
        ostringstream HNSh0_AI; HNSh0_AI << "h0_AI" << k;
        
        h0tau_OS.push_back(new TH1F (HNSh0tau_OS.str().c_str(),"InvMa",binnum0,bins0)); h0tau_OS[k]->Sumw2();
        h0ell_OS.push_back(new TH1F (HNSh0ell_OS.str().c_str(),"InvMa",binnum0,bins0)); h0ell_OS[k]->Sumw2();
        h0_AI.push_back(new TH1F (HNSh0_AI.str().c_str(),"InvMa",binnum0,bins0)); h0_AI[k]->Sumw2();
        
        //FakeFactor  boosted
        
        ostringstream HNSh1tau_OS; HNSh1tau_OS << "h1tau_OS" << k;
        ostringstream HNSh1ell_OS; HNSh1ell_OS << "h1ell_OS" << k;
        ostringstream HNSh1_AI; HNSh1_AI << "h1_AI" << k;
        
        h1tau_OS.push_back(new TH1F (HNSh1tau_OS.str().c_str(),"InvMa",binnum0,bins0)); h1tau_OS[k]->Sumw2();
        h1ell_OS.push_back(new TH1F (HNSh1ell_OS.str().c_str(),"InvMa",binnum0,bins0)); h1ell_OS[k]->Sumw2();
        h1_AI.push_back(new TH1F (HNSh1_AI.str().c_str(),"InvMa",binnum0,bins0)); h1_AI[k]->Sumw2();
        
        
        //FakeFactor  vbf
        
        ostringstream HNSh2tau_OS; HNSh2tau_OS << "h2tau_OS" << k;
        ostringstream HNSh2ell_OS; HNSh2ell_OS << "h2ell_OS" << k;
        ostringstream HNSh2_AI; HNSh2_AI << "h2_AI" << k;
        
        h2tau_OS.push_back(new TH1F (HNSh2tau_OS.str().c_str(),"InvMa",binnum0,bins0)); h2tau_OS[k]->Sumw2();
        h2ell_OS.push_back(new TH1F (HNSh2ell_OS.str().c_str(),"InvMa",binnum0,bins0)); h2ell_OS[k]->Sumw2();
        h2_AI.push_back(new TH1F (HNSh2_AI.str().c_str(),"InvMa",binnum0,bins0)); h2_AI[k]->Sumw2();
        
        
        
        
        
        
        
    }
    
    TString postfixTES[12]={"_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"};
    TString postfixDM[6]={"_CMS_tauDMReco_1prong_13TeVUp","_CMS_tauDMReco_1prong_13TeVDown","_CMS_tauDMReco_1prong1pizero_13TeVUp","_CMS_tauDMReco_1prong1pizero_13TeVDown","_CMS_tauDMReco_3prong_13TeVUp","_CMS_tauDMReco_3prong_13TeVDown"};
    TString postfixFakeDM[6]={"_CMS_jetToTauDMReco_1prong_13TeVUp","_CMS_jetToTauDMReco_1prong_13TeVDown","_CMS_jetToTauDMReco_1prong1pizero_13TeVUp","_CMS_jetToTauDMReco_1prong1pizero_13TeVDown","_CMS_jetToTauDMReco_3prong_13TeVUp","_CMS_jetToTauDMReco_3prong_13TeVDown"};
    TString postfixZLshape[12]={"_CMS_htt_ZLShape_mt_13TeVUp","_CMS_htt_ZLShape_mt_13TeVDown","_CMS_ZLShape_mt_0jet_1prong_13TeVUp","_CMS_ZLShape_mt_0jet_1prong_13TeVDown","_CMS_ZLShape_mt_0jet_1prong1pizero_13TeVUp","_CMS_ZLShape_mt_0jet_1prong1pizero_13TeVDown","_CMS_ZLShape_mt_1prong_13TeVUp","_CMS_ZLShape_mt_1prong_13TeVDown", "_CMS_ZLShape_mt_1prong1pizero_13TeVUp","_CMS_ZLShape_mt_1prong1pizero_13TeVDown","_CMS_ZLShape_mt_3prong_13TeVUp","_CMS_ZLShape_mt_3prong_13TeVDown"};
    TString postfixZLnorm[4]={"_CMS_mFakeTau_1prong_13TeVUp","_CMS_mFakeTau_1prong_13TeVDown","_CMS_mFakeTau_1prong1pizero_13TeVUp","_CMS_mFakeTau_1prong1pizero_13TeVDown"};
    TString postfixJES[56]={"_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"};
    TString postfixWG1[18]={"_THU_ggH_Mu_13TeVUp","_THU_ggH_Mu_13TeVDown","_THU_ggH_Res_13TeVUp","_THU_ggH_Res_13TeVDown","_THU_ggH_Mig01_13TeVUp","_THU_ggH_Mig01_13TeVDown","_THU_ggH_Mig12_13TeVUp","_THU_ggH_Mig12_13TeVDown","_THU_ggH_VBF2j_13TeVUp","_THU_ggH_VBF2j_13TeVDown","_THU_ggH_VBF3j_13TeVUp","_THU_ggH_VBF3j_13TeVDown","_THU_ggH_PT60_13TeVUp","_THU_ggH_PT60_13TeVDown","_THU_ggH_PT120_13TeVUp","_THU_ggH_PT120_13TeVDown","_THU_ggH_qmtop_13TeVUp","_THU_ggH_qmtop_13TeVDown"};
    
    
    

    
    bool text=true;
    Int_t nentries_wtn = (Int_t) arbre->GetEntries();
    for (Int_t i = 0; i < nentries_wtn; i++) {
      arbre->GetEntry(i);
      if (i % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
      fflush(stdout);
      // DoubleTau trigger
      if (sample=="data_obs" && input=="myntuples/data_H.root") {
	if(!passDoubleTauCmbIso35) continue;
	if(!matchDoubleTauCmbIso35_1  || !matchDoubleTauCmbIso35_2) continue;
	if(!filterDoubleTauCmbIso35_1 || !filterDoubleTauCmbIso35_2) continue;
      }
      if (sample=="data_obs" && input=="myntuples/data_H.root") {
	if (!passDoubleTau35) continue;
	if (!matchDoubleTau35_1  || !matchDoubleTau35_2) continue;
	if (!filterDoubleTau35_1 || !filterDoubleTau35_2) continue;
      }

      if (sample!="data_obs") {
	bool t35     =  passDoubleTau35 && filterDoubleTau35_1 && filterDoubleTau35_2 && matchDoubleTau35_1 && matchDoubleTau35_2;
	bool tcomb35 =  passDoubleTauCmbIso35 && filterDoubleTauCmbIso35_1 && filterDoubleTauCmbIso35_2 && matchDoubleTauCmbIso35_1 && matchDoubleTauCmbIso35_2;
	if (  !t35 && !tcomb35 ) continue;
      }


      float jpt_1 = scenario.get_jpt_1();
      float jpt_2 = scenario.get_jpt_2();
      float njets = scenario.get_njets();
      float met = scenario.get_met();
      float metphi = scenario.get_metphi();
      float m_sv = scenario.get_m_sv();
      float pt_sv = scenario.get_pt_sv();
      float mjj = scenario.get_mjj();

      // mytau1 is the highest pT tau
      float charge1=q_1;
      float charge2=q_2;
      TLorentzVector mytau1;
      mytau1.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
      TLorentzVector mytau2;
      mytau2.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
      if (pt_1<pt_2){
	charge2=q_1;
	charge1=q_2;
	mytau2.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
	mytau1.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
      }
      
      if (mytau1.DeltaR(mytau2) < 0.5) continue;
      if (againstElectronVLooseMVA6_1 < 0.5) continue; // L773
      if (againstElectronVLooseMVA6_2 < 0.5) continue;
      if (againstMuonLoose3_1 < 0.5) continue; //774
      if (againstMuonLoose3_2 < 0.5) continue;
      // Change && -> ||
      if (byLooseIsolationMVArun2v1DBoldDMwLT_1 < 0.5 || byLooseIsolationMVArun2v1DBoldDMwLT_2 < 0.5) continue; // Fig 43(a)
      if (extramuon_veto) continue;
      if (extraelec_veto) continue;
      //float sf_trg=1.0;
      float sf_id=1.0;
      //float eff_tau=1.0;

      // D.Kim : Trigger SF
      float sf_trg1 = 1.0;
      float sf_trg2 = 1.0;
      float sf_trg_RR = 1.0;
      float sf_trg_FR = 1.0;
      float sf_trg_RF = 1.0;
      float sf_trg_FF = 1.0;
      PyObject* trgSF = PyObject_CallFunction(compute_sf,(char*)"[f,i]",0.0,0);
      if (sample!="data_obs"){
	if (t1_decayMode==0) trgSF = PyObject_CallFunction(compute_sf,(char*)"[f,i]",mytau1.Pt(),0);
	else if (t1_decayMode==1) trgSF = PyObject_CallFunction(compute_sf,(char*)"[f,i]",mytau1.Pt(),1);
	else if (t1_decayMode==10) trgSF = PyObject_CallFunction(compute_sf,(char*)"[f,i]",mytau1.Pt(),10);
	sf_trg1 = PyFloat_AsDouble(trgSF);
	if (gen_match_1==5)  {
	  sf_trg_RR = PyFloat_AsDouble(trgSF);
	  sf_trg_RF = PyFloat_AsDouble(trgSF);
	}
	if (gen_match_1==6) {
	  sf_trg_FR = PyFloat_AsDouble(trgSF);
	  sf_trg_FF = PyFloat_AsDouble(trgSF);
	}
	if (t2_decayMode==0) trgSF = PyObject_CallFunction(compute_sf,(char*)"[f,i]",mytau2.Pt(),0);
	else if (t2_decayMode==1) trgSF = PyObject_CallFunction(compute_sf,(char*)"[f,i]",mytau2.Pt(),1);
	else if (t2_decayMode==10) trgSF = PyObject_CallFunction(compute_sf,(char*)"[f,i]",mytau2.Pt(),10);
	sf_trg2 = PyFloat_AsDouble(trgSF);
	if (gen_match_2==5)  {
	  sf_trg_RR = sf_trg_RR*PyFloat_AsDouble(trgSF);
          sf_trg_FR = sf_trg_FR*PyFloat_AsDouble(trgSF);
        }
        if (gen_match_2==6) {
          sf_trg_RF = sf_trg_RF*PyFloat_AsDouble(trgSF);
          sf_trg_FF = sf_trg_FF*PyFloat_AsDouble(trgSF);
	}

      }
          
      // Regions
      float signalRegion = byTightIsolationMVArun2v1DBoldDMwLT_1 && byTightIsolationMVArun2v1DBoldDMwLT_2;
      float aiRegion = ((byMediumIsolationMVArun2v1DBoldDMwLT_1 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && byLooseIsolationMVArun2v1DBoldDMwLT_2) || (byMediumIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_1 && byLooseIsolationMVArun2v1DBoldDMwLT_1));
      
        
        
        //FF
        float AI_Region = ((byTightIsolationMVArun2v1DBoldDMwLT_1 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && byVLooseIsolationMVArun2v1DBoldDMwLT_2) || (byTightIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_1 && byVLooseIsolationMVArun2v1DBoldDMwLT_1));
        

        
        
      // Weights depending in the generated jet multiplicity
      if (sample=="W"){
	weight=25.446;
	if (numGenJets==1) weight=6.8176;
	else if (numGenJets==2) weight=2.1038;
	else if (numGenJets==3) weight=0.6889;
	else if (numGenJets==4) weight=0.6900;
	//std::cout << weight << std::endl;
      }
      
      if (sample=="DY" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
	weight=1.41957039;
	if (numGenJets==1 || input=="myntuples/DY1.root")
	  weight=0.457675455;
	else if (numGenJets==2 || input=="myntuples/DY2.root")
	  weight=0.467159142;
	else if (numGenJets==3 || input=="myntuples/DY3.root")
	  weight=0.480349711;
	else if (numGenJets==4 || input=="myntuples/DY4.root")
	  weight=0.3938184351;
      }
      
      // Multiply some weights and scale factors together
      // ID and iso corrections
      float correction=sf_id;
      if (sample!="data_obs") correction=correction*LumiWeights_12->weight(npu);
      float aweight=amcatNLO_weight*weight*correction;
      if (sample!="data_obs"){
	//Tau ID SF (Tight WP)
	if (gen_match_1==5) aweight=aweight*0.95;
	if (gen_match_2==5) aweight=aweight*0.95;
	//e->tau fakes VLoose
	if (gen_match_1==1 or gen_match_1==3){
	  if (std::abs(mytau1.Eta())<1.460) aweight=aweight*1.213;
	  else if (std::abs(mytau1.Eta())>1.558) aweight=aweight*1.375;
	}
	if (gen_match_2==1 or gen_match_2==3){
	  if (std::abs(mytau2.Eta())<1.460) aweight=aweight*1.213;
	  else if (std::abs(mytau2.Eta())>1.558) aweight=aweight*1.375;
	}
	// mu->tau fakes Loose
	else if (gen_match_1==2 or gen_match_1==4){
	  if (std::abs(mytau1.Eta())<0.4) aweight=aweight*1.010;
	  else if (std::abs(mytau1.Eta())<0.8) aweight=aweight*1.007;
	  else if (std::abs(mytau1.Eta())<1.2) aweight=aweight*0.870;
	  else if (std::abs(mytau1.Eta())<1.7) aweight=aweight*1.154;
	  else aweight=aweight*2.281;
	}
	else if (gen_match_2==2 or gen_match_2==4){
	  if (std::abs(mytau2.Eta())<0.4) aweight=aweight*1.010;
	  else if (std::abs(mytau2.Eta())<0.8) aweight=aweight*1.007;
	  else if (std::abs(mytau2.Eta())<1.2) aweight=aweight*0.870;
	  else if (std::abs(mytau2.Eta())<1.7) aweight=aweight*1.154;
	  else aweight=aweight*2.281;
	}
	//aweight=aweight*h_Trk->Eval(eta_1);
      }
      
      // Z pt reweighting for DY events
      if (sample=="DY" || sample=="EWKZLL" || sample=="EWKZNuNu" || sample=="ZTT" || sample=="ZLL" || sample=="ZL" || sample=="ZJ"){
	float zpt_corr=histZ->GetBinContent(histZ->GetXaxis()->FindBin(genM),histZ->GetYaxis()->FindBin(genpT));
	if (std::abs(tes)!=10) //nominal
	  aweight=aweight*zpt_corr;
	else if (tes==10) // up
	  aweight=aweight*(1+1.10*(zpt_corr-1));
	else if (tes==-10) // down
	  aweight=aweight*(1+0.90*(zpt_corr-1));
      }
      
      //  Top pT reweighting for ttbar events
      float pttop1=pt_top1;
      if (pttop1>400) pttop1=400;
      float pttop2=pt_top2;
      if (pttop2>400) pttop2=400;
      if ((sample=="TTL" or sample=="TTJ" or sample=="TTT" or sample=="TT") && std::abs(tes)!=11) aweight*=sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2));
      //aweight*=sqrt(exp(0.156-0.00137*pttop1)*exp(0.156-0.00137*pttop2));
      if ((sample=="TTL" or sample=="TTJ" or sample=="TTT" or sample=="TT") && tes==11) aweight*=(1+2*(sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2))-1));
      
      if (sample=="data_obs") aweight=1.0;
      
      // D.Kim : https://github.com/cecilecaillol/SMHTT2016/blob/master/mt/Analyze/FinalSelection2D_relaxed.cc#L744-L754
      //************************ Jet to tau FR shape **************************
      if (tes==14 && (sample=="TTJ" or sample=="ZJ" or sample=="W")) {
	  float jtotau1=1.0;
	  if (gen_match_1==6) {
	    jtotau1=1-(0.2*mytau1.Pt()/100);
	    if (mytau1.Pt()>200) jtotau1=1-(0.2*200.0/100);
	  }
	  float jtotau2=1.0;
	  if (gen_match_2==6) {
	    jtotau2=1-(0.2*mytau2.Pt()/100);
	    if (mytau2.Pt()>200) jtotau2=1-(0.2*200.0/100);
	  }
	  aweight=aweight*jtotau1*jtotau2;
      }

	if (tes==-14 && (sample=="TTJ" or sample=="ZJ" or sample=="W")) {
	  float jtotau1=1.0;
	  if (gen_match_1==6) {
	    jtotau1=1+(0.2*mytau1.Pt()/100);
	    if (mytau1.Pt()>200) jtotau1=1+(0.2*200.0/100);
	  }
	  float jtotau2=1.0;
	  if (gen_match_2==6) {
	    jtotau2=1+(0.2*mytau2.Pt()/100);
	    if (mytau2.Pt()>200) jtotau2=1+(0.2*200.0/100);
	  }
	  aweight=aweight*jtotau1*jtotau2;
      }


      // D.Kim : Separation between L, T and J (for DY, TT, and VV)
      // https://github.com/truggles/Z_to_TauTau_13TeV/blob/SM-HTT-2016/analysis1BaselineCuts.py#L444-L457
      bool isZTT=false;
      bool isZL=false;
      bool isZJ=false;
        //      if (gen_match_1==5 || gen_match_2==5) isZTT=true;
        if (gen_match_1==5 && gen_match_2==5) isZTT=true;

      if (gen_match_1<6&&gen_match_2<6&&!(gen_match_1==5&&gen_match_2==5)) isZL=true;
      if (gen_match_2==6 || gen_match_1==6) isZJ=true;

       
      if ((name=="ZTT") && !isZTT) continue;
      if ((name=="ZL") && !isZL) continue;
      if ((name=="ZJ") && !isZJ) continue;

//AM

        if (((gen_match_1>2 && gen_match_1<6) &&  (gen_match_2>2 && gen_match_2<6)) && name=="TTT_excluding_digentau") continue;
        if (!((gen_match_1>2 && gen_match_1<6) &&  (gen_match_2>2 && gen_match_2<6)) && name=="TTT_only_digentau") continue;

        if (((gen_match_1>2 && gen_match_1<6) &&  (gen_match_2>2 && gen_match_2<6)) && name=="VVT_excluding_digentau") continue;
        if (!((gen_match_1>2 && gen_match_1<6) &&  (gen_match_2>2 && gen_match_2<6)) && name=="VVT_only_digentau") continue;


      // TT & VV : line 895~897
      if (!(gen_match_1==5 && gen_match_2==5) && (name=="VVT"|| name=="TTT")) continue;
      if ((gen_match_1==5 && gen_match_2==5) && (name=="VVJ" || name=="TTJ")) continue;

      
//if (gen_match_1 < 5 && gen_match_2 < 2) std::cout << "gen_match_1 = "<<gen_match_1<<  "   gen_match_2="<<gen_match_2<<"\n";

      //KK Added for future. For now we need only first two variables
      int nombrejets[56]={njets_JESDown,njets_JESUp,njets_JetAbsoluteFlavMapDown,njets_JetAbsoluteFlavMapUp,njets_JetAbsoluteMPFBiasDown,njets_JetAbsoluteMPFBiasUp,njets_JetAbsoluteScaleDown,njets_JetAbsoluteScaleUp,njets_JetAbsoluteStatDown,njets_JetAbsoluteStatUp,njets_JetFlavorQCDDown,njets_JetFlavorQCDUp,njets_JetFragmentationDown,njets_JetFragmentationUp,njets_JetPileUpDataMCDown,njets_JetPileUpDataMCUp,njets_JetPileUpPtBBDown,njets_JetPileUpPtBBUp,njets_JetPileUpPtEC1Down,njets_JetPileUpPtEC1Up,njets_JetPileUpPtEC2Down,njets_JetPileUpPtEC2Up,njets_JetPileUpPtHFDown,njets_JetPileUpPtHFUp,njets_JetPileUpPtRefDown,njets_JetPileUpPtRefUp,njets_JetRelativeBalDown,njets_JetRelativeBalUp,njets_JetRelativeFSRDown,njets_JetRelativeFSRUp,njets_JetRelativeJEREC1Down,njets_JetRelativeJEREC1Up,njets_JetRelativeJEREC2Down,njets_JetRelativeJEREC2Up,njets_JetRelativeJERHFDown,njets_JetRelativeJERHFUp,njets_JetRelativePtBBDown,njets_JetRelativePtBBUp,njets_JetRelativePtEC1Down,njets_JetRelativePtEC1Up,njets_JetRelativePtEC2Down,njets_JetRelativePtEC2Up,njets_JetRelativePtHFDown,njets_JetRelativePtHFUp,njets_JetRelativeStatECDown,njets_JetRelativeStatECUp,njets_JetRelativeStatFSRDown,njets_JetRelativeStatFSRUp,njets_JetRelativeStatHFDown,njets_JetRelativeStatHFUp,njets_JetSinglePionECALDown,njets_JetSinglePionECALUp,njets_JetSinglePionHCALDown,njets_JetSinglePionHCALUp,njets_JetTimePtEtaDown,njets_JetTimePtEtaUp};
      
      float massejets[56]={mjj_JESDown,mjj_JESUp,mjj_JetAbsoluteFlavMapDown,mjj_JetAbsoluteFlavMapUp,mjj_JetAbsoluteMPFBiasDown,mjj_JetAbsoluteMPFBiasUp,mjj_JetAbsoluteScaleDown,mjj_JetAbsoluteScaleUp,mjj_JetAbsoluteStatDown,mjj_JetAbsoluteStatUp,mjj_JetFlavorQCDDown,mjj_JetFlavorQCDUp,mjj_JetFragmentationDown,mjj_JetFragmentationUp,mjj_JetPileUpDataMCDown,mjj_JetPileUpDataMCUp,mjj_JetPileUpPtBBDown,mjj_JetPileUpPtBBUp,mjj_JetPileUpPtEC1Down,mjj_JetPileUpPtEC1Up,mjj_JetPileUpPtEC2Down,mjj_JetPileUpPtEC2Up,mjj_JetPileUpPtHFDown,mjj_JetPileUpPtHFUp,mjj_JetPileUpPtRefDown,mjj_JetPileUpPtRefUp,mjj_JetRelativeBalDown,mjj_JetRelativeBalUp,mjj_JetRelativeFSRDown,mjj_JetRelativeFSRUp,mjj_JetRelativeJEREC1Down,mjj_JetRelativeJEREC1Up,mjj_JetRelativeJEREC2Down,mjj_JetRelativeJEREC2Up,mjj_JetRelativeJERHFDown,mjj_JetRelativeJERHFUp,mjj_JetRelativePtBBDown,mjj_JetRelativePtBBUp,mjj_JetRelativePtEC1Down,mjj_JetRelativePtEC1Up,mjj_JetRelativePtEC2Down,mjj_JetRelativePtEC2Up,mjj_JetRelativePtHFDown,mjj_JetRelativePtHFUp,mjj_JetRelativeStatECDown,mjj_JetRelativeStatECUp,mjj_JetRelativeStatFSRDown,mjj_JetRelativeStatFSRUp,mjj_JetRelativeStatHFDown,mjj_JetRelativeStatHFUp,mjj_JetSinglePionECALDown,mjj_JetSinglePionECALUp,mjj_JetSinglePionHCALDown,mjj_JetSinglePionHCALUp,mjj_JetTimePtEtaDown,mjj_JetTimePtEtaUp};
      
      for (int k=0; k<nbhist; ++k){
	
	float var2=m_sv; 
	float var1_1=pt_sv;

	TLorentzVector myjet1;
	myjet1.SetPtEtaPhiM(jpt_1,jeta_1,jphi_1,0);
	//myjet1.SetPtEtaPhiM(scenario.get_jpt_1(),jeta_1,jphi_1,0);
	TLorentzVector myjet2;
	myjet2.SetPtEtaPhiM(jpt_2,jeta_2,jphi_2,0);
	//myjet2.SetPtEtaPhiM(scenario.get_jpt_2(),jeta_2,jphi_2,0);
	TLorentzVector jets=myjet2+myjet1;
	//mjj = jets.M();
	float normMELA = ME_sm_VBF/(ME_sm_VBF+45*ME_bkg);
	
	//std::cout << mjj << "\t" << jets.M() << "\t" << mjj/jets.M() << std::endl;
	float var1_2=mjj;//normMELA;  //Dbkg_VBF;//mjj; 
	TLorentzVector myrawmet;
	myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	//myrawmet.SetPtEtaPhiM(scenario.get_met(),0,scenario.get_metphi(),0);
	TLorentzVector mymet=myrawmet;
	
//	//KK: added "&& gen_match_1==5"
//	if (tes==1 && gen_match_2==5 && gen_match_1==5){	    
//	  
//	  if (k==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau1*=0.988; mytau2*=0.988;  mymet=mymet+(0.012/0.988)*mytau1+(0.012/0.988)*mytau2;}
//	  if (k==1){ var1_1=pt_sv_UP;   var2=m_sv_UP;   mytau1*=1.012; mytau2*=1.012;  mymet=mymet-(0.012/1.012)*mytau1-(0.012/1.012)*mytau2;}
//                   
//	  if (k==2 && t2_decayMode==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau2*=0.988; mymet=mymet+(0.012/0.988)*mytau2;}
//	  if (k==3 && t2_decayMode==0){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau2*=1.012; mymet=mymet-(0.012/1.012)*mytau2;}
//	  if (k==4 && t2_decayMode==1){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau2*=0.988; mymet=mymet+(0.012/0.988)*mytau2;}
//	  if (k==5 && t2_decayMode==1){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau2*=1.012; mymet=mymet-(0.012/1.012)*mytau2;}
//	  if (k==6 && t2_decayMode==10){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau2*=0.988; mymet=mymet+(0.012/0.988)*mytau2;}
//	  if (k==7 && t2_decayMode==10){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau2*=1.012; mymet=mymet-(0.012/1.012)*mytau2;}
//          
//	  if (k==2 && t1_decayMode==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau1*=0.988; mymet=mymet+(0.012/0.988)*mytau1;}
//	  if (k==3 && t1_decayMode==0){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau1*=1.012; mymet=mymet-(0.012/1.012)*mytau1;}
//	  if (k==4 && t1_decayMode==1){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau1*=0.988; mymet=mymet+(0.012/0.988)*mytau1;}
//	  if (k==5 && t1_decayMode==1){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau1*=1.012; mymet=mymet-(0.012/1.012)*mytau1;}
//	  if (k==6 && t1_decayMode==10){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau1*=0.988; mymet=mymet+(0.012/0.988)*mytau1;}
//	  if (k==7 && t1_decayMode==10){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau1*=1.012; mymet=mymet-(0.012/1.012)*mytau1;}
//          
//	}
	
//	if (tes==1){
//	  //KK: Modified lines below from
//	  //	    if (k==8){ var2=m_sv_UESDown; var1_1=pt_sv_UESDown; mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
//	  //	    else if (k==9){ var2=m_sv_UESUp; var1_1=pt_sv_UESUp; mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
//	  //	    else if (k==10){ var2=m_sv_JESDown; var1_1=pt_sv_JESDown; mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
//	  //	    else if (k==11){ var2=m_sv_JESUp; var1_1=pt_sv_JESUp; mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
//	  //KK: to
//	  if (k==8){ var2=m_sv_UncMet_DOWN; var1_1=pt_sv_UncMet_DOWN; mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
//	  else if (k==9){ var2=m_sv_UncMet_UP; var1_1=pt_sv_UncMet_UP; mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
//	  else if (k==10){ var2=m_sv_ClusteredMet_DOWN; var1_1=pt_sv_ClusteredMet_DOWN; mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
//	  else if (k==11){ var2=m_sv_ClusteredMet_UP; var1_1=pt_sv_ClusteredMet_UP; mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
//	}
	
//	//KK: Added njet and mjj variables affected by JES
//	if (tes==100 && var1_2==mjj){
//	  njets = nombrejets[k];
//	  var1_2 = massejets[k]; //KK for now not available in trees
//	}
//
//	if (tes==1 && var1_2==normMELA){ 
//	  if (text) {std::cout << "------------------------------ var1_2 is replaced to MELA ------------------------------" << std::endl;text=false;}
//	  if (k==8) var1_2=ME_sm_VBF_UncMet_DOWN/(ME_sm_VBF_UncMet_DOWN+45*ME_bkg_UncMet_DOWN);
//	  if (k==9) var1_2=ME_sm_VBF_UncMet_UP/(ME_sm_VBF_UncMet_UP+45*ME_bkg_UncMet_UP);
//	  if (k==10) var1_2=ME_sm_VBF_ClusteredMet_DOWN/(ME_sm_VBF_ClusteredMet_DOWN+45*ME_bkg_ClusteredMet_DOWN);
//	  if (k==11) var1_2=ME_sm_VBF_ClusteredMet_UP/(ME_sm_VBF_ClusteredMet_UP+45*ME_bkg_ClusteredMet_UP);
//	}

	if (mytau1.Pt() < 40 || mytau2.Pt() < 40 ) continue;
	if (mytau1.Pt() < 50) continue;
	
	if ((fabs(mytau1.Eta()))>2.1 || (fabs(mytau2.Eta())>2.1)) continue; // L770

	float weight2=1.0;	  
	weight2=weight2*sf_trg1*sf_trg2;
        
	// Additional selections
	bool selection =true;
	TLorentzVector Higgs = mytau1+mytau2+mymet;
	
	// Categories
	bool is_0jet = false;
	bool is_boosted = false;
	bool is_VBF = false;
	bool is_VH = false;
	bool is_1jet = false;
	bool is_2jets = false;
	
	if (njets==0) is_0jet=true;
	if (njets==1 || (njets>=2 && (!(Higgs.Pt()>100 && std::abs(myjet1.Eta()-myjet2.Eta())>2.5)))) is_boosted=true; 
	if (njets>=2 && Higgs.Pt()>100 && std::abs(myjet1.Eta()-myjet2.Eta())>2.5) is_VBF=true;
	if (njets==1) is_1jet=true;
	if (njets>=2) is_2jets=true;

	// Z mumu SF 
	if (is_boosted && (sample=="DY" || sample=="ZTT" || sample=="ZLL" || sample=="ZL" || sample=="ZJ" || sample=="EWKZLL" || sample=="EWKZNuNu")) 
	  aweight*=zmumuSF_boosted(pt_sv,shape);
	if (is_VBF && (sample=="DY" || sample=="ZTT" || sample=="ZLL" || sample=="ZL" || sample=="ZJ" || sample=="EWKZLL" || sample=="EWKZNuNu")) 
	  aweight*=zmumuSF_vbf(mjj,shape);

	if (sample=="data_obs") {aweight=1.0; weight2=1.0;}

          
          
          
          
          
          //############################################################################################################
          //############################################################################################################
          //##################################   Fake Factor   #########################################################
          //############################################################################################################
          //############################################################################################################
          
          
          
          
          //          //Fill input_1 for tt channel
          //          inputs[0] = tau_pt;
          //          inputs[1] = tau2_pt; //pt of non-fake tau candidate
          //          inputs[2] = tau_decayMode;
          //          inputs[3] = njets;
          //          inputs[4] = mvis;
          //          inputs[5] = frac_qcd;
          //          inputs[6] = frac_w;
          //          inputs[7] = frac_tt;
          //
          //
          //********************* Compute fake factors *********************
          
          
          float Frac_var= m_sv;
          
          input_1[0] = mytau1.Pt();
          input_1[1] = mytau2.Pt();//pt of non-fake tau candidate
          input_1[2] = t1_decayMode;
          input_1[3] = njets;
          input_1[4] = (mytau1+mytau2).M();
          // Just dommy numbers
          input_1[5] = 0.75;
          input_1[6] = 0.15;
          input_1[7] = 0.05;
          
          
          
          
          input_2[0] = mytau2.Pt();
          input_2[1] = mytau1.Pt();//pt of non-fake tau candidate
          input_2[2] = t2_decayMode;
          input_2[3] = njets;
          input_2[4] = (mytau1+mytau2).M();
          // Just dommy numbers
          input_2[5] = 0.75;
          input_2[6] = 0.15;
          input_2[7] = 0.05;
          
          float vis_mass=(mytau1+mytau2).M();
          float numberJets=njets;
          

          
          
          if (is_0jet){
              input_1[5] =input_2[5] = fakefrac_0jet->GetBinContent(fakefrac_0jet->GetXaxis()->FindBin(vis_mass), fakefrac_0jet->GetYaxis()->FindBin(numberJets),1);
              input_1[6] =input_2[6] = fakefrac_0jet->GetBinContent(fakefrac_0jet->GetXaxis()->FindBin(vis_mass), fakefrac_0jet->GetYaxis()->FindBin(numberJets),2);
              input_1[7] =input_2[7] = fakefrac_0jet->GetBinContent(fakefrac_0jet->GetXaxis()->FindBin(vis_mass), fakefrac_0jet->GetYaxis()->FindBin(numberJets),3);
          }
          
          if (is_boosted){
              input_1[5] =input_2[5] = fakefrac_boosted->GetBinContent(fakefrac_boosted->GetXaxis()->FindBin(vis_mass), fakefrac_boosted->GetYaxis()->FindBin(numberJets),1);
              input_1[6] =input_2[6] = fakefrac_boosted->GetBinContent(fakefrac_boosted->GetXaxis()->FindBin(vis_mass), fakefrac_boosted->GetYaxis()->FindBin(numberJets),2);
              input_1[7] =input_2[7] = fakefrac_boosted->GetBinContent(fakefrac_boosted->GetXaxis()->FindBin(vis_mass), fakefrac_boosted->GetYaxis()->FindBin(numberJets),3);
          }
          
          
          if (is_VBF){
              input_1[5] =input_2[5] = fakefrac_vbf->GetBinContent(fakefrac_vbf->GetXaxis()->FindBin(vis_mass), fakefrac_vbf->GetYaxis()->FindBin(numberJets),1);
              input_1[6] =input_2[6] = fakefrac_vbf->GetBinContent(fakefrac_vbf->GetXaxis()->FindBin(vis_mass), fakefrac_vbf->GetYaxis()->FindBin(numberJets),2);
              input_1[7] =input_2[7] = fakefrac_vbf->GetBinContent(fakefrac_vbf->GetXaxis()->FindBin(vis_mass), fakefrac_vbf->GetYaxis()->FindBin(numberJets),3);
          }
          
          
          
          //*********************  fake factors weight *********************
          double FF_weight_1=ff_0jet->value(input_1);
          double FF_weight_2=ff_0jet->value(input_2);
          
          //************************* Fill histograms Fake Factor 0 jet **********************
          
          if (is_0jet ){
              
              if (AI_Region && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<=5)){ //anti-isolated data, and MC without jets to subtract later
                  //                for (int k=l;k<l+nbhistFF;++k){ // To get also the systematics
                  h0_AI[k]->Fill(m_sv,aweight*FF_weight_1*weight2*0.5);
                  h0_AI[k]->Fill(m_sv,aweight*FF_weight_2*weight2*0.5);
                  //                }
              }
          }
          
          
          //************************* Fill histograms Fake Factor boosted **********************
          
          if (is_boosted ){
              
              if (AI_Region && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<=5)){ //anti-isolated data, and MC without jets to subtract later
                  //                for (int k=l;k<l+nbhistFF;++k){ // To get also the systematics
                  h1_AI[k]->Fill(m_sv,aweight*FF_weight_1*weight2*0.5);
                  h1_AI[k]->Fill(m_sv,aweight*FF_weight_2*weight2*0.5);
                  //                }
              }
          }
          
          //************************* Fill histograms Fake Factor VBF **********************
          
          if (is_VBF ){
              
              if (AI_Region && q_1*q_2<0 && (sample=="data_obs" or gen_match_2<=5)){ //anti-isolated data, and MC without jets to subtract later
                  //                for (int k=l;k<l+nbhistFF;++k){ // To get also the systematics
                  h2_AI[k]->Fill(m_sv,aweight*FF_weight_1*weight2*0.5);
                  h2_AI[k]->Fill(m_sv,aweight*FF_weight_2*weight2*0.5);
                  //                }
              }
          }
          
          //############################################################################################################
          //############################################################################################################
          //############################################################################################################
          //############################################################################################################
          //############################################################################################################
        
          
          
          
          
	//************************* Fill histograms **********************
	//////////////////////////////////////////////////////////////////
	//                                                              //
	//  - Variable info -                                           //
	//   var : 0jet -> mtautau svFit (m_sv)                         //
	//   var1_1 : boosted -> Higgs pT svFit                         // 
	//   var1_2 : vbf -> mjj                                        //
	//   var2 = boosted,vbf -> mtautau svFit (m_sv)                 //
	//   var1_M* : vbf -> MELA obs                                  //
	//                                                              //
	//////////////////////////////////////////////////////////////////
	float var = var2;
//          var=(mytau1+mytau2).M();//AM
//          var=(mytau1+mytau2).M();//AM
//          var=mytau1.Pt();//AM
          var=m_sv;
	float varRND = m_sv;

	if (selection){
        // ################### signalRegion && OS ####################
        if (is_0jet && signalRegion && charge1*charge2<0){
            h0_OS[k]->Fill(var,weight2*aweight);
            //	    if (tes==0)
            //	      h_0jet->Fill(var,Total_Embed_Weight);
        }
        if (is_boosted && signalRegion && charge1*charge2<0){
            h1_OS[k]->Fill(var,weight2*aweight);
            //	    if (tes==0){
            //          h_boosted->Fill(var,Total_Embed_Weight);
            //	      hx_boosted->Fill(var1_1,Total_Embed_Weight);
            //	      hy_boosted->Fill(var2,Total_Embed_Weight);
            //	    }
        }
        if (is_VBF && signalRegion && charge1*charge2<0) {
            h2_OS[k]->Fill(var,weight2*aweight);
            //	    if (tes==0){
            //          h_vbf->Fill(var,Total_Embed_Weight);
            //	      hx_vbf->Fill(var1_2,Total_Embed_Weight);
            //	      hy_vbf->Fill(var2,Total_Embed_Weight);
            //std::cout << "var1_2 is " << var1_2 << std::endl;
            //	    }
        }
        if (is_VH && signalRegion && charge1*charge2<0)
            h3_OS[k]->Fill(var,weight2*aweight);
        
        if (signalRegion && charge1*charge2<0){
            h_OS[k]->Fill(var,weight2*aweight);
            //         h_inc->Fill(var,Total_Embed_Weight);
        }


	  // tmp histograms for R&D
	  if (is_0jet && signalRegion && charge1*charge2<0) h0_rndOS[k]->Fill(varRND,weight2*aweight);
	  if (is_1jet && signalRegion && charge1*charge2<0) h1_rndOS[k]->Fill(varRND,weight2*aweight);
	  if (is_2jets && signalRegion && charge1*charge2<0) h2_rndOS[k]->Fill(varRND,weight2*aweight);
	  
	  
	  // ################### signalRegion && SS ####################
	  if (is_0jet && signalRegion && charge1*charge2>0)
	    h0_SS[k]->Fill(var,weight2*aweight);
	  if (is_boosted && signalRegion && charge1*charge2>0)
	    h1_SS[k]->Fill(var,weight2*aweight);
	  if (is_VBF && signalRegion && charge1*charge2>0) {
	    h2_SS[k]->Fill(var,weight2*aweight);
	  }
	  if (is_VH && signalRegion && charge1*charge2>0)
	    h3_SS[k]->Fill(var,weight2*aweight); 
	  if (signalRegion && charge1*charge2>0)
	    h_SS[k]->Fill(var,weight2*aweight);

	  // tmp histograms for R&D
	  if (is_0jet && signalRegion && charge1*charge2>0) h0_rndSS[k]->Fill(varRND,weight2*aweight);
	  if (is_1jet && signalRegion && charge1*charge2>0) h1_rndSS[k]->Fill(varRND,weight2*aweight);
	  if (is_2jets && signalRegion && charge1*charge2>0) h2_rndSS[k]->Fill(varRND,weight2*aweight);

	  // ################### ai-Region && OS ####################
	  if (is_0jet && charge1*charge2<0 && aiRegion)
	    h0_AIOS[k]->Fill(var,weight2*aweight);
	  if (is_boosted && charge1*charge2<0 && aiRegion)
	    h1_AIOS[k]->Fill(var,weight2*aweight);
	  if (is_VBF && charge1*charge2<0 && aiRegion) {
	    h2_AIOS[k]->Fill(var,weight2*aweight);
	  }
	  if (is_VH && charge1*charge2<0 && aiRegion)
	    h3_AIOS[k]->Fill(var,weight2*aweight);
	  if (charge1*charge2<0 && aiRegion)
	    h_AIOS[k]->Fill(var,weight2*aweight);

	  // tmp histograms for R&D
	  if (is_0jet && aiRegion && charge1*charge2<0) h0_rndAIOS[k]->Fill(varRND,weight2*aweight);
	  if (is_1jet && aiRegion && charge1*charge2<0) h1_rndAIOS[k]->Fill(varRND,weight2*aweight);
	  if (is_2jets && aiRegion && charge1*charge2<0) h2_rndAIOS[k]->Fill(varRND,weight2*aweight);

	  
	  // ################### ai-Region && SS ####################
	  if (is_0jet && charge1*charge2>0 && aiRegion)
	    h0_AISS[k]->Fill(var,weight2*aweight);
	  if (is_boosted && charge1*charge2>0 && aiRegion)
	    h1_AISS[k]->Fill(var,weight2*aweight);
	  if (is_VBF && charge1*charge2>0 && aiRegion) {
	    h2_AISS[k]->Fill(var,weight2*aweight);
	  }
	  if (is_VH && charge1*charge2>0 && aiRegion)
	    h3_AISS[k]->Fill(var,weight2*aweight);
	  if (charge1*charge2>0 && aiRegion)
	    h_AISS[k]->Fill(var,weight2*aweight);	  

	  // tmp histograms for R&D
	  if (is_0jet && aiRegion && charge1*charge2>0) h0_rndAISS[k]->Fill(varRND,weight2*aweight);
	  if (is_1jet && aiRegion && charge1*charge2>0) h1_rndAISS[k]->Fill(varRND,weight2*aweight);
	  if (is_2jets && aiRegion && charge1*charge2>0) h2_rndAISS[k]->Fill(varRND,weight2*aweight);

	  // ################### trg SF ####################
	  h_trgSF1[k]->Fill(sf_trg1);
	  h_trgSF2[k]->Fill(sf_trg2);
	  if (gen_match_1==5 && gen_match_2==5) h_trgSF_RR[k]->Fill(sf_trg_RR);
	  if (gen_match_1==6 && gen_match_2==5) h_trgSF_FR[k]->Fill(sf_trg_FR);
	  if (gen_match_1==5 && gen_match_2==6) h_trgSF_RF[k]->Fill(sf_trg_RF);
	  if (gen_match_1==6 && gen_match_2==6) h_trgSF_FF[k]->Fill(sf_trg_FF);

	}
      }
    } // end of loop over events
    
    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    
    //    TString postfix="";
    /*
    TString postfix="";
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
    */
    TDirectory *OS0jet_tt =fout->mkdir("tt_0jet");
    TDirectory *OSboosted_tt =fout->mkdir("tt_boosted");
    TDirectory *OSvbf_tt =fout->mkdir("tt_vbf");
    TDirectory *OSinclusive_tt =fout->mkdir("tt_inclusive");
    
    TDirectory *OS0jet =fout->mkdir("ttOS_0jet");
    TDirectory *OSboosted =fout->mkdir("ttOS_boosted");
    TDirectory *OSvbf =fout->mkdir("ttOS_vbf");
    TDirectory *OSvh =fout->mkdir("ttOS_vh");
    //TDirectory *OS2jets =fout->mkdir("ttOS_2jets");
    TDirectory *OS =fout->mkdir("ttOS_inclusive");
    // KK
    TDirectory*  OScat = fout->mkdir("tt_categories");

    TDirectory *SS0jet =fout->mkdir("ttSS_0jet");
    TDirectory *SSboosted =fout->mkdir("ttSS_boosted");
    TDirectory *SSvbf =fout->mkdir("ttSS_vbf");
    TDirectory *SSvh =fout->mkdir("ttSS_vh");
    //TDirectory *SS2jets =fout->mkdir("ttSS_2jets");
    TDirectory *SS =fout->mkdir("ttSS_inclusive");
    
    TDirectory *AIOS0jet =fout->mkdir("AIOS_0jet");
    TDirectory *AIOSboosted =fout->mkdir("AIOS_boosted");
    TDirectory *AIOSvbf =fout->mkdir("AIOS_vbf");
    TDirectory *AIOSvh =fout->mkdir("AIOS_vh");
    //TDirectory *AIOS2jets =fout->mkdir("AIOS_2jets");
    TDirectory *AIOS =fout->mkdir("AIOS_inclusive");
    
    TDirectory *AISS0jet =fout->mkdir("AISS_0jet");
    TDirectory *AISSboosted =fout->mkdir("AISS_boosted");
    TDirectory *AISSvbf =fout->mkdir("AISS_vbf");
    TDirectory *AISSvh =fout->mkdir("AISS_vh");
    //TDirectory *AISS2jets =fout->mkdir("AISS_2jets");
    TDirectory *AISS =fout->mkdir("AISS_inclusive");
    // D.Kim
    TDirectory *TRG_SF = fout->mkdir("trgSF");
    TDirectory *RND0jetOS = fout->mkdir("ttOS_0jetR");
    TDirectory *RND1jetOS = fout->mkdir("ttOS_boostedR");
    TDirectory *RND2jetOS = fout->mkdir("ttOS_vbfR");
    TDirectory *RND0jetSS = fout->mkdir("ttSS_0jetR");
    TDirectory *RND1jetSS = fout->mkdir("ttSS_boostedR");
    TDirectory *RND2jetSS = fout->mkdir("ttSS_vbfR");
    TDirectory *RND0jetAIOS = fout->mkdir("AIOS_0jetR");
    TDirectory *RND1jetAIOS = fout->mkdir("AIOS_boostedR");
    TDirectory *RND2jetAIOS = fout->mkdir("AIOS_vbfR");
    TDirectory *RND0jetAISS = fout->mkdir("AISS_0jetR");
    TDirectory *RND1jetAISS = fout->mkdir("AISS_boostedR");
    TDirectory *RND2jetAISS = fout->mkdir("AISS_vbfR");

    
    
    //FF
    TDirectory *OS0jet_FF =fout->mkdir("tt_0jet_FF");
    TDirectory *AI0jet_FF =fout->mkdir("AI0jet_FF");
    
    TDirectory *OSboosted_FF =fout->mkdir("tt_boosted_FF");
    TDirectory *AIboosted_FF =fout->mkdir("AIboosted_FF");
    
    TDirectory *OSvbf_FF =fout->mkdir("tt_vbf_FF");
    TDirectory *AIvbf_FF =fout->mkdir("AIvbf_FF");
    
    

    if (nbhist==1) postfixJES[0]=postfix;
    
    for (int k=0; k<nbhist; ++k){
      if (tes==10) postfix="_CMS_htt_dyShape_13TeVUp";
      if (tes==-10) postfix="_CMS_htt_dyShape_13TeVDown";
      if (tes==14) postfix="_CMS_htt_jetToTauFake_13TeVUp";
      if (tes==-14) postfix="_CMS_htt_jetToTauFake_13TeVDown";
      if (tes==11) postfix="_CMS_htt_ttbarShape_13TeVUp";
      if (tes==-11) postfix="_CMS_htt_ttbarShape_13TeVDown";        
      if (tes==100) postfix=postfixJES[k];
      if (tes==1) postfix=postfixTES[k];
      if (tes==16) postfix=postfixDM[k];
      if (tes==17) postfix=postfixZLshape[k];
      if (tes==18) postfix=postfixZLnorm[k];
      if (tes==19) postfix=postfixFakeDM[k];
      if (tes==1000) postfix=postfixWG1[k];
      if (tes==13)  postfix="_CMS_htt_zmumuShape_VBF_13TeVUp";        
      if (tes==-13) postfix="_CMS_htt_zmumuShape_VBF_13TeVDown";
//      std::cout << "\nnbhist = " << nbhist << ", tes = " << tes << ", postfix = " << postfix  << std::endl;
      
      // These will be the final root files
      // D.Kim
      TRG_SF->cd();
      h_trgSF1[k]->SetName("trgSF1");
      h_trgSF1[k]->Write();
      h_trgSF2[k]->SetName("trgSF2");
      h_trgSF2[k]->Write();
      h_trgSF_RR[k]->SetName("trgSF_RR");
      h_trgSF_RR[k]->Write();
      h_trgSF_FR[k]->SetName("trgSF_FR");
      h_trgSF_FR[k]->Write();
      h_trgSF_RF[k]->SetName("trgSF_RF");
      h_trgSF_RF[k]->Write();
      h_trgSF_FF[k]->SetName("trgSF_FF");
      h_trgSF_FF[k]->Write();

      RND0jetOS->cd();
      h0_rndOS[k]->SetName(name.c_str());
      h0_rndOS[k]->Write();
      RND1jetOS->cd();
      h1_rndOS[k]->SetName(name.c_str());
      h1_rndOS[k]->Write();
      RND2jetOS->cd();
      h2_rndOS[k]->SetName(name.c_str());
      h2_rndOS[k]->Write();

      RND0jetSS->cd();
      h0_rndSS[k]->SetName(name.c_str());
      h0_rndSS[k]->Write();
      RND1jetSS->cd();
      h1_rndSS[k]->SetName(name.c_str());
      h1_rndSS[k]->Write();
      RND2jetSS->cd();
      h2_rndSS[k]->SetName(name.c_str());
      h2_rndSS[k]->Write();

      RND0jetAIOS->cd();
      h0_rndAIOS[k]->SetName(name.c_str());
      h0_rndAIOS[k]->Write();
      RND1jetAIOS->cd();
      h1_rndAIOS[k]->SetName(name.c_str());
      h1_rndAIOS[k]->Write();
      RND2jetAIOS->cd();
      h2_rndAIOS[k]->SetName(name.c_str());
      h2_rndAIOS[k]->Write();

      RND0jetAISS->cd();
      h0_rndAISS[k]->SetName(name.c_str());
      h0_rndAISS[k]->Write();
      RND1jetAISS->cd();
      h1_rndAISS[k]->SetName(name.c_str());
      h1_rndAISS[k]->Write();
      RND2jetAISS->cd();
      h2_rndAISS[k]->SetName(name.c_str());
      h2_rndAISS[k]->Write();

      OS0jet_tt->cd();
      h0_OS[k]->SetName(name.c_str()+postfix);
      h0_OS[k]->Write();
      OSboosted_tt->cd();
      h1_OS[k]->SetName(name.c_str()+postfix);
      h1_OS[k]->Write();
      OSvbf_tt->cd();
      h2_OS[k]->SetName(name.c_str()+postfix);
      h2_OS[k]->Write();
        //AM
    OSinclusive_tt->cd();
    h_OS[k]->SetName(name.c_str()+postfix);
    h_OS[k]->Write();
        
        
      OS0jet->cd();
      h0_OS[k]->SetName(name.c_str()+postfix);
      h0_OS[k]->Write();
      OSboosted->cd();
      h1_OS[k]->SetName(name.c_str()+postfix);
      h1_OS[k]->Write();
      OSvbf->cd();
      h2_OS[k]->SetName(name.c_str()+postfix);
      h2_OS[k]->Write();

      OSvh->cd();
      h3_OS[k]->SetName(name.c_str()+postfix);
      h3_OS[k]->Write();
      OS->cd();
      h_OS[k]->SetName(name.c_str()+postfix);
      h_OS[k]->Write();
      
      //KK
      OScat->cd();
      h_0jet->Write();
      hx_boosted->Write();
      hy_boosted->Write();
      hx_vbf->Write();
      hy_vbf->Write();
      h_inc->Write();
        
      SS0jet->cd();
      h0_SS[k]->SetName(name.c_str()+postfix);
      h0_SS[k]->Write();
      SSboosted->cd();
      h1_SS[k]->SetName(name.c_str()+postfix);
      h1_SS[k]->Write();
      SSvbf->cd();
      h2_SS[k]->SetName(name.c_str()+postfix);
      h2_SS[k]->Write();

      SSvh->cd();
      h3_SS[k]->SetName(name.c_str()+postfix);
      h3_SS[k]->Write();
      SS->cd();
      h_SS[k]->SetName(name.c_str()+postfix);
      h_SS[k]->Write();
      
      AIOS0jet->cd();
      h0_AIOS[k]->SetName(name.c_str()+postfix);
      h0_AIOS[k]->Write();
      AIOSboosted->cd();
      h1_AIOS[k]->SetName(name.c_str()+postfix);
      h1_AIOS[k]->Write();
      AIOSvbf->cd();
      h2_AIOS[k]->SetName(name.c_str()+postfix);
      h2_AIOS[k]->Write();

      AIOSvh->cd();
      h3_AIOS[k]->SetName(name.c_str()+postfix);
      h3_AIOS[k]->Write();
      AIOS->cd();
      h_AIOS[k]->SetName(name.c_str()+postfix);
      h_AIOS[k]->Write();
      
      AISS0jet->cd();
      h0_AISS[k]->SetName(name.c_str()+postfix);
      h0_AISS[k]->Write();
      AISSboosted->cd();
      h1_AISS[k]->SetName(name.c_str()+postfix);
      h1_AISS[k]->Write();
      AISSvbf->cd();
      h2_AISS[k]->SetName(name.c_str()+postfix);
      h2_AISS[k]->Write();

      AISSvh->cd();
      h3_AISS[k]->SetName(name.c_str()+postfix);
      h3_AISS[k]->Write();
      AISS->cd();
      h_AISS[k]->SetName(name.c_str()+postfix);
      h_AISS[k]->Write();
    
    
        
        //################  FF  0jet
        OS0jet_FF->cd();
        if (name=="DY"){
            h0tau_OS[k]->SetName("ZTT"+postfixJES[k]);
            h0ell_OS[k]->SetName("ZL"+postfixJES[k]);
            h0tau_OS[k]->Write();
            h0ell_OS[k]->Write();
        }
        else if (name=="TT"){
            h0tau_OS[k]->SetName("TTT"+postfixJES[k]);
            h0tau_OS[k]->Add(h0ell_OS[k]);
            h0tau_OS[k]->Write();
        }
        else{
            h0tau_OS[k]->SetName(name.c_str()+postfixJES[k]);
            h0tau_OS[k]->Add(h0ell_OS[k]);
            h0tau_OS[k]->Write();
        }
        AI0jet_FF->cd();
        //        for (int l=k; l<k+nbhistFF;++l){
        h0_AI[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
        h0_AI[k]->Write();
        //        }
        
        
        //################  FF  boosted
        OSboosted_FF->cd();
        if (name=="DY"){
            h1tau_OS[k]->SetName("ZTT"+postfixJES[k]);
            h1ell_OS[k]->SetName("ZL"+postfixJES[k]);
            h1tau_OS[k]->Write();
            h1ell_OS[k]->Write();
        }
        else if (name=="TT"){
            h1tau_OS[k]->SetName("TTT"+postfixJES[k]);
            h1tau_OS[k]->Add(h1ell_OS[k]);
            h1tau_OS[k]->Write();
        }
        else{
            h1tau_OS[k]->SetName(name.c_str()+postfixJES[k]);
            h1tau_OS[k]->Add(h1ell_OS[k]);
            h1tau_OS[k]->Write();
        }
        AIboosted_FF->cd();
        //        for (int l=k; l<k+nbhistFF;++l){
        h1_AI[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
        h1_AI[k]->Write();
        //        }
 
        
        
        //################  FF  boosted
        OSvbf_FF->cd();
        if (name=="DY"){
            h2tau_OS[k]->SetName("ZTT"+postfixJES[k]);
            h2ell_OS[k]->SetName("ZL"+postfixJES[k]);
            h2tau_OS[k]->Write();
            h2ell_OS[k]->Write();
        }
        else if (name=="TT"){
            h2tau_OS[k]->SetName("TTT"+postfixJES[k]);
            h2tau_OS[k]->Add(h1ell_OS[k]);
            h2tau_OS[k]->Write();
        }
        else{
            h2tau_OS[k]->SetName(name.c_str()+postfixJES[k]);
            h2tau_OS[k]->Add(h1ell_OS[k]);
            h2tau_OS[k]->Write();
        }
        AIvbf_FF->cd();
        //        for (int l=k; l<k+nbhistFF;++l){
        h2_AI[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
        h2_AI[k]->Write();
        //        }
        
    
    }
    fout->Close();
    // D.Kim
    Py_Finalize();
} 


