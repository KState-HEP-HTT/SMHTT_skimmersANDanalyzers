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
    arbre->SetBranchAddress("njets", &njets);
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
    arbre->SetBranchAddress("met", &met);
    arbre->SetBranchAddress("metphi", &metphi);
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
    arbre->SetBranchAddress("m_sv",&m_sv);
    arbre->SetBranchAddress("m_sv_DOWN", &m_sv_DOWN);
    arbre->SetBranchAddress("m_sv_UP", &m_sv_UP);
    arbre->SetBranchAddress("pt_sv", &pt_sv);
    arbre->SetBranchAddress("pt_sv_DOWN", &pt_sv_DOWN);
    arbre->SetBranchAddress("pt_sv_UP", &pt_sv_UP);
    arbre->SetBranchAddress("m_sv_UncMet_DOWN", &m_sv_UncMet_DOWN);
    arbre->SetBranchAddress("m_sv_UncMet_UP", &m_sv_UncMet_UP);
    arbre->SetBranchAddress("m_sv_ClusteredMet_DOWN", &m_sv_ClusteredMet_DOWN);
    arbre->SetBranchAddress("m_sv_ClusteredMet_UP", &m_sv_ClusteredMet_UP);
    arbre->SetBranchAddress("pt_sv_UncMet_DOWN", &pt_sv_UncMet_DOWN);
    arbre->SetBranchAddress("pt_sv_UncMet_UP", &pt_sv_UncMet_UP);
    arbre->SetBranchAddress("pt_sv_ClusteredMet_DOWN", &pt_sv_ClusteredMet_DOWN);
    arbre->SetBranchAddress("pt_sv_ClusteredMet_UP", &pt_sv_ClusteredMet_UP);
    // MELA
    arbre->SetBranchAddress("ME_sm_VBF",&ME_sm_VBF); // What we actually use.
    arbre->SetBranchAddress("ME_sm_ggH",&ME_sm_ggH);
    arbre->SetBranchAddress("ME_bkg",&ME_bkg); // What we actually use.
    arbre->SetBranchAddress("Dbkg_VBF",&Dbkg_VBF);
    arbre->SetBranchAddress("Dbkg_ggH",&Dbkg_ggH);  
    arbre->SetBranchAddress("ME_sm_VBF_DOWN",&ME_sm_VBF_DOWN); 
    arbre->SetBranchAddress("ME_sm_VBF_UP",&ME_sm_VBF_UP); 
    arbre->SetBranchAddress("ME_sm_VBF_UncMet_DOWN",&ME_sm_VBF_UncMet_DOWN); 
    arbre->SetBranchAddress("ME_sm_VBF_UncMet_UP",&ME_sm_VBF_UncMet_UP); 
    arbre->SetBranchAddress("ME_sm_VBF_ClusteredMet_DOWN",&ME_sm_VBF_ClusteredMet_DOWN); 
    arbre->SetBranchAddress("ME_sm_VBF_ClusteredMet_UP",&ME_sm_VBF_ClusteredMet_UP); 
    arbre->SetBranchAddress("ME_bkg_DOWN",&ME_bkg_DOWN); 
    arbre->SetBranchAddress("ME_bkg_UP",&ME_bkg_UP); 
    arbre->SetBranchAddress("ME_bkg_UncMet_DOWN",&ME_bkg_UncMet_DOWN); 
    arbre->SetBranchAddress("ME_bkg_UncMet_UP",&ME_bkg_UncMet_UP); 
    arbre->SetBranchAddress("ME_bkg_ClusteredMet_DOWN",&ME_bkg_ClusteredMet_DOWN); 
    arbre->SetBranchAddress("ME_bkg_ClusteredMet_UP",&ME_bkg_ClusteredMet_UP); 


    
    //float bins0[] = {0, 40, 60, 70, 80, 90, 100, 110, 120, 130, 150, 200, 250}; //VBF
    //float bins1[] = {0, 40, 60, 70, 80, 90, 100, 110, 120, 130, 150, 200, 250}; //VBF
    //float bins0[] = {0,10,20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300}; //VBF
    //float bins1[] = {0,10,20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300}; //VBF
    //    float bins0[] = {0,50,100,150,200,250,300,350,400,450,500}; //fig50 H pT
    //    float bins1[] = {0,50,100,150,200,250,300,350,400,450,500}; //fig50 H pT

    
    // D.Kim : AN line 791~795
    //Binning for 0jet cat. 1D: Msv. In AN it was 10GeV binning / official data card combined 0~50 as one bin
    float bins0[] = {0,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
    float bins1[] = {0,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
    //float bins0[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
    //float bins1[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
    //float bins0[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300};
    //float bins1[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300};
    //Binning for 1jet cat, x-axis: HpT
    float bins11[] = {0,100,170,300,10000};
    //Binning for 1jet cat, y-axis: Msv
    float bins12[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};

    //Binning for 2jet cat, x-axis: Mjj
    float bins21[] = {0,300,500,800,10000};
    //binning for 2jet cat, x-axis: Dbkg_VBF
    //float bins21[] = {0.0,0.3,0.6,0.9,1.0};
    //Binning for 2jet cat, x-axis: NN_disc
    //float bins21[] = {0.0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
    //float bins21[] = {0.0,0.5,0.7,0.8,1.0};
    //Binning for 2jet cat, y-axis: Msv
    float bins22[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};

    //float bins1[] = {0,50,100,150,200,250,300,350,400,450,500};//,550,600,650,700,750,800,850,900,950,1000,1050}; //fig50 H pT
    //float bins0[] = {0,80,160,240,320,400,480,560,640,720,800,880,960,1040,1120,1200,1280,1360};
    //float bins1[] = {0,80,160,240,320,400,480,560,640,720,800,880,960,1040,1120,1200,1280,1360};
    //float bins0[] = {0,25,50,75,100,120,140,160,180,200,225,250,275,300,324,350,375,400,425,450,475,500,550};//,600,650,700,750,800};//,850,900,950,1000,1050,1100,1150,1200,1250,1300}; // mjj 800
    //float bins1[] = {0,25,50,75,100,120,140,160,180,200,225,250,275,300,324,350,375,400,425,450,475,500,550};//,600,650,700,750,800};//,850,900,950,1000,1050,1100,1150,1200,1250,1300}; // mjj 800
    
    //float bins0[] = {-5.0,-4.5,-4.0,-3.5,-3.0,-2.5,-2.0,-1.5,-1.0,-0.5,0.0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0};
    //float bins1[] = {-5.0,-4.5,-4.0,-3.5,-3.0,-2.5,-2.0,-1.5,-1.0,-0.5,0.0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0};
    //float bins0[] = {0,30,60,90,120,150,180,210,240,270,300,330,360,390};
    //float bins1[] = {0,30,60,90,120,150,180,210,240,270,300,330,360,390};

    int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
    int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;

    int  binnum11 = sizeof(bins11)/sizeof(Float_t) - 1;
    int  binnum12 = sizeof(bins12)/sizeof(Float_t) - 1;
    int  binnum21 = sizeof(bins21)/sizeof(Float_t) - 1;
    int  binnum22 = sizeof(bins22)/sizeof(Float_t) - 1;

    // Categories
    TH1F* h_0jet = new TH1F ("h_0jet", "h_0jet", binnum0, bins0); h_0jet->Sumw2();
    TH1F* hx_boosted = new TH1F ("hx_boosted", "hx_boosted", binnum11, bins11); hx_boosted->Sumw2();
    TH1F* hy_boosted = new TH1F ("hy_boosted", "hy_boosted", binnum12, bins12); hy_boosted->Sumw2();
    TH1F* hx_vbf = new TH1F ("hx_vbf", "hx_vbf", binnum21, bins21); hx_vbf->Sumw2();
    TH1F* hy_vbf = new TH1F ("hy_vbf", "hy_vbf", binnum22, bins22); hy_vbf->Sumw2();

    // Categories
    //TH1F* ojet = new TH1F ("ojet", "ojet", 100, -0.10, 0.10); ojet->Sumw2();
    //TH1F* boosted = new TH1F ("boosted", "boosted", 100, -0.10, 0.10); boosted->Sumw2();
    //TH1F* vbf = new TH1F ("vbf", "vbf", 100, -0.10, 0.10); vbf->Sumw2();

    //KK Change to 2D histograms

    /*
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
    */

    // h0_ : 0jet, h1_ : boosted, h2_ : vbf, h3_ : vh, h2M*_ : vbf with MELA, h4M_ : 2jets with MEAL  h_ : inclusive
    std::vector<TH1F*> h0_OS;
    std::vector<TH1F*> h0_SS;
    std::vector<TH1F*> h0_AIOS;
    std::vector<TH1F*> h0_AISS;
    std::vector<TH2F*> h1_OS;
    std::vector<TH2F*> h1_SS;
    std::vector<TH2F*> h1_AIOS;
    std::vector<TH2F*> h1_AISS;
    std::vector<TH2F*> h2_OS;
    std::vector<TH2F*> h2_SS;
    std::vector<TH2F*> h2_AIOS;
    std::vector<TH2F*> h2_AISS;

    /*
    std::vector<TH2F*> h2M1_OS;
    std::vector<TH2F*> h2M1_SS;
    std::vector<TH2F*> h2M1_AIOS;
    std::vector<TH2F*> h2M1_AISS;
    std::vector<TH2F*> h2M2_OS;
    std::vector<TH2F*> h2M2_SS;
    std::vector<TH2F*> h2M2_AIOS;
    std::vector<TH2F*> h2M2_AISS;
    std::vector<TH2F*> h2M3_OS;
    std::vector<TH2F*> h2M3_SS;
    std::vector<TH2F*> h2M3_AIOS;
    std::vector<TH2F*> h2M3_AISS;
    std::vector<TH2F*> h4M1_OS; // in test cate - ex) 2jets
    std::vector<TH2F*> h4M1_SS;
    std::vector<TH2F*> h4M1_AIOS;
    std::vector<TH2F*> h4M1_AISS;
    std::vector<TH2F*> h4M2_OS;
    std::vector<TH2F*> h4M2_SS;
    std::vector<TH2F*> h4M2_AIOS;
    std::vector<TH2F*> h4M2_AISS;
    */

    std::vector<TH2F*> h3_OS;
    std::vector<TH2F*> h3_SS;
    std::vector<TH2F*> h3_AIOS;
    std::vector<TH2F*> h3_AISS;
    std::vector<TH1F*> h_OS;
    std::vector<TH1F*> h_SS;
    std::vector<TH1F*> h_AIOS;
    std::vector<TH1F*> h_AISS;
    // D.Kim : trg SF histo
    std::vector<TH1F*> h_trgSF1;
    std::vector<TH1F*> h_trgSF2;
    std::vector<TH1F*> h_trgSF_RR;
    std::vector<TH1F*> h_trgSF_FR;
    std::vector<TH1F*> h_trgSF_RF;
    std::vector<TH1F*> h_trgSF_FF;

    /*
    // D.Kim : MELA 1D
    std::vector<TH1F*> h_MELA_VBF;
    std::vector<TH1F*> h_MELA_ggH;
    */

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
      h1_OS.push_back(new TH2F (HNS1OS.str().c_str(),"diTauMa",binnum11,bins11,binnum12,bins12)); h1_OS[k]->Sumw2();
      h2_OS.push_back(new TH2F (HNS2OS.str().c_str(),"diTauMa",binnum21,bins21,binnum22,bins22)); h2_OS[k]->Sumw2();
      
      h3_OS.push_back(new TH2F (HNS3OS.str().c_str(),"diTauMa",binnum21,bins21,binnum22,bins22)); h3_OS[k]->Sumw2();
      h_OS.push_back(new TH1F (HNSOS.str().c_str(),"diTauMa",binnum0,bins0)); h_OS[k]->Sumw2();
      
      std::ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
      std::ostringstream HNS1SS; HNS1OS << "h1_SS" << k;
      std::ostringstream HNS2SS; HNS2OS << "h2_SS" << k;
      std::ostringstream HNS3SS; HNS2OS << "h3_SS" << k;
      std::ostringstream HNSSS; HNSOS << "h_SS" << k;

      h0_SS.push_back(new TH1F (HNS0SS.str().c_str(),"diTauMa",binnum1,bins1)); h0_SS[k]->Sumw2();
      h1_SS.push_back(new TH2F (HNS1SS.str().c_str(),"diTauMa",binnum11,bins11,binnum12,bins12)); h1_SS[k]->Sumw2();
      h2_SS.push_back(new TH2F (HNS2SS.str().c_str(),"diTauMa",binnum21,bins21,binnum22,bins22)); h2_SS[k]->Sumw2();
      h3_SS.push_back(new TH2F (HNS3SS.str().c_str(),"diTauMa",binnum21,bins21,binnum22,bins22)); h3_SS[k]->Sumw2();
      h_SS.push_back(new TH1F (HNSSS.str().c_str(),"diTauMa",binnum1,bins1)); h_SS[k]->Sumw2();
      
      std::ostringstream HNS0AIOS; HNS0AIOS << "h0_AIOS" << k;
      std::ostringstream HNS1AIOS; HNS1AIOS << "h1_AIOS" << k;
      std::ostringstream HNS2AIOS; HNS2AIOS << "h2_AIOS" << k;
      std::ostringstream HNS3AIOS; HNS3AIOS << "h3_AIOS" << k;
      std::ostringstream HNSAIOS; HNSAIOS << "h_AIOS" << k;

      h0_AIOS.push_back(new TH1F (HNS0AIOS.str().c_str(),"diTauMa",binnum0,bins0)); h0_AIOS[k]->Sumw2();
      h1_AIOS.push_back(new TH2F (HNS1AIOS.str().c_str(),"diTauMa",binnum11,bins11,binnum12,bins12)); h1_AIOS[k]->Sumw2();
      h2_AIOS.push_back(new TH2F (HNS2AIOS.str().c_str(),"diTauMa",binnum21,bins21,binnum22,bins22)); h2_AIOS[k]->Sumw2();
      h3_AIOS.push_back(new TH2F (HNS3AIOS.str().c_str(),"diTauMa",binnum21,bins21,binnum22,bins22)); h3_AIOS[k]->Sumw2();
      h_AIOS.push_back(new TH1F (HNSAIOS.str().c_str(),"diTauMa",binnum0,bins0)); h_AIOS[k]->Sumw2();
        
      std::ostringstream HNS0AISS; HNS0AISS << "h0_AISS" << k;
      std::ostringstream HNS1AISS; HNS1AISS << "h1_AISS" << k;
      std::ostringstream HNS2AISS; HNS2AISS << "h2_AISS" << k;
      std::ostringstream HNS3AISS; HNS3AISS << "h3_AISS" << k;
      std::ostringstream HNSAISS; HNSAISS << "h_AISS" << k;

      h0_AISS.push_back(new TH1F (HNS0AISS.str().c_str(),"diTauMa",binnum1,bins1)); h0_AISS[k]->Sumw2();
      h1_AISS.push_back(new TH2F (HNS1AISS.str().c_str(),"diTauMa",binnum11,bins11,binnum12,bins12)); h1_AISS[k]->Sumw2();
      h2_AISS.push_back(new TH2F (HNS2AISS.str().c_str(),"diTauMa",binnum21,bins21,binnum22,bins22)); h2_AISS[k]->Sumw2();
      h3_AISS.push_back(new TH2F (HNS3AISS.str().c_str(),"diTauMa",binnum21,bins21,binnum22,bins22)); h3_AISS[k]->Sumw2();
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
      
    }
    
    TString postfixTES[12]={"_CMS_scale_t_13TeVDown","_CMS_scale_t_13TeVUp","_CMS_scale_t_1prong_13TeVDown","_CMS_scale_t_1prong_13TeVUp","_CMS_scale_t_1prong1pizero_13TeVDown","_CMS_scale_t_1prong1pizero_13TeVUp","_CMS_scale_t_3prong_13TeVDown","_CMS_scale_t_3prong_13TeVUp","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_met_clustered_13TeVDown","_CMS_scale_met_clustered_13TeVUp"};
    TString postfixDM[6]={"_CMS_tauDMReco_1prong_13TeVUp","_CMS_tauDMReco_1prong_13TeVDown","_CMS_tauDMReco_1prong1pizero_13TeVUp","_CMS_tauDMReco_1prong1pizero_13TeVDown","_CMS_tauDMReco_3prong_13TeVUp","_CMS_tauDMReco_3prong_13TeVDown"};
    TString postfixFakeDM[6]={"_CMS_jetToTauDMReco_1prong_13TeVUp","_CMS_jetToTauDMReco_1prong_13TeVDown","_CMS_jetToTauDMReco_1prong1pizero_13TeVUp","_CMS_jetToTauDMReco_1prong1pizero_13TeVDown","_CMS_jetToTauDMReco_3prong_13TeVUp","_CMS_jetToTauDMReco_3prong_13TeVDown"};
    TString postfixZLshape[12]={"_CMS_htt_ZLShape_mt_13TeVUp","_CMS_htt_ZLShape_mt_13TeVDown","_CMS_ZLShape_mt_0jet_1prong_13TeVUp","_CMS_ZLShape_mt_0jet_1prong_13TeVDown","_CMS_ZLShape_mt_0jet_1prong1pizero_13TeVUp","_CMS_ZLShape_mt_0jet_1prong1pizero_13TeVDown","_CMS_ZLShape_mt_1prong_13TeVUp","_CMS_ZLShape_mt_1prong_13TeVDown", "_CMS_ZLShape_mt_1prong1pizero_13TeVUp","_CMS_ZLShape_mt_1prong1pizero_13TeVDown","_CMS_ZLShape_mt_3prong_13TeVUp","_CMS_ZLShape_mt_3prong_13TeVDown"};
    TString postfixZLnorm[4]={"_CMS_mFakeTau_1prong_13TeVUp","_CMS_mFakeTau_1prong_13TeVDown","_CMS_mFakeTau_1prong1pizero_13TeVUp","_CMS_mFakeTau_1prong1pizero_13TeVDown"};
    TString postfixJES[56]={"_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"};
    TString postfixWG1[18]={"_THU_ggH_Mu_13TeVUp","_THU_ggH_Mu_13TeVDown","_THU_ggH_Res_13TeVUp","_THU_ggH_Res_13TeVDown","_THU_ggH_Mig01_13TeVUp","_THU_ggH_Mig01_13TeVDown","_THU_ggH_Mig12_13TeVUp","_THU_ggH_Mig12_13TeVDown","_THU_ggH_VBF2j_13TeVUp","_THU_ggH_VBF2j_13TeVDown","_THU_ggH_VBF3j_13TeVUp","_THU_ggH_VBF3j_13TeVDown","_THU_ggH_PT60_13TeVUp","_THU_ggH_PT60_13TeVDown","_THU_ggH_PT120_13TeVUp","_THU_ggH_PT120_13TeVDown","_THU_ggH_qmtop_13TeVUp","_THU_ggH_qmtop_13TeVDown"};
    
    bool text=true;    
    std::cout << "2" << std::endl;    
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
      if (gen_match_1==5 || gen_match_2==5) isZTT=true;
      if (gen_match_1<6&&gen_match_2<6&&!(gen_match_1==5&&gen_match_2==5)) isZL=true;
      if (gen_match_2==6 || gen_match_1==6) isZJ=true;
      if ((name=="ZTT") && !isZTT) continue;
      if ((name=="ZL") && !isZL) continue;
      if ((name=="ZJ") && !isZJ) continue;

      // TT & VV : line 895~897
      if (!(gen_match_1==5 && gen_match_2==5) && (name=="VVT"|| name=="TTT")) continue;
      if ((gen_match_1==5 && gen_match_2==5) && (name=="VVJ" || name=="TTJ")) continue;

      //KK Added for future. For now we need only first two variables
      int nombrejets[56]={njets_JESDown,njets_JESUp,njets_JetAbsoluteFlavMapDown,njets_JetAbsoluteFlavMapUp,njets_JetAbsoluteMPFBiasDown,njets_JetAbsoluteMPFBiasUp,njets_JetAbsoluteScaleDown,njets_JetAbsoluteScaleUp,njets_JetAbsoluteStatDown,njets_JetAbsoluteStatUp,njets_JetFlavorQCDDown,njets_JetFlavorQCDUp,njets_JetFragmentationDown,njets_JetFragmentationUp,njets_JetPileUpDataMCDown,njets_JetPileUpDataMCUp,njets_JetPileUpPtBBDown,njets_JetPileUpPtBBUp,njets_JetPileUpPtEC1Down,njets_JetPileUpPtEC1Up,njets_JetPileUpPtEC2Down,njets_JetPileUpPtEC2Up,njets_JetPileUpPtHFDown,njets_JetPileUpPtHFUp,njets_JetPileUpPtRefDown,njets_JetPileUpPtRefUp,njets_JetRelativeBalDown,njets_JetRelativeBalUp,njets_JetRelativeFSRDown,njets_JetRelativeFSRUp,njets_JetRelativeJEREC1Down,njets_JetRelativeJEREC1Up,njets_JetRelativeJEREC2Down,njets_JetRelativeJEREC2Up,njets_JetRelativeJERHFDown,njets_JetRelativeJERHFUp,njets_JetRelativePtBBDown,njets_JetRelativePtBBUp,njets_JetRelativePtEC1Down,njets_JetRelativePtEC1Up,njets_JetRelativePtEC2Down,njets_JetRelativePtEC2Up,njets_JetRelativePtHFDown,njets_JetRelativePtHFUp,njets_JetRelativeStatECDown,njets_JetRelativeStatECUp,njets_JetRelativeStatFSRDown,njets_JetRelativeStatFSRUp,njets_JetRelativeStatHFDown,njets_JetRelativeStatHFUp,njets_JetSinglePionECALDown,njets_JetSinglePionECALUp,njets_JetSinglePionHCALDown,njets_JetSinglePionHCALUp,njets_JetTimePtEtaDown,njets_JetTimePtEtaUp};
      
      float massejets[56]={mjj_JESDown,mjj_JESUp,mjj_JetAbsoluteFlavMapDown,mjj_JetAbsoluteFlavMapUp,mjj_JetAbsoluteMPFBiasDown,mjj_JetAbsoluteMPFBiasUp,mjj_JetAbsoluteScaleDown,mjj_JetAbsoluteScaleUp,mjj_JetAbsoluteStatDown,mjj_JetAbsoluteStatUp,mjj_JetFlavorQCDDown,mjj_JetFlavorQCDUp,mjj_JetFragmentationDown,mjj_JetFragmentationUp,mjj_JetPileUpDataMCDown,mjj_JetPileUpDataMCUp,mjj_JetPileUpPtBBDown,mjj_JetPileUpPtBBUp,mjj_JetPileUpPtEC1Down,mjj_JetPileUpPtEC1Up,mjj_JetPileUpPtEC2Down,mjj_JetPileUpPtEC2Up,mjj_JetPileUpPtHFDown,mjj_JetPileUpPtHFUp,mjj_JetPileUpPtRefDown,mjj_JetPileUpPtRefUp,mjj_JetRelativeBalDown,mjj_JetRelativeBalUp,mjj_JetRelativeFSRDown,mjj_JetRelativeFSRUp,mjj_JetRelativeJEREC1Down,mjj_JetRelativeJEREC1Up,mjj_JetRelativeJEREC2Down,mjj_JetRelativeJEREC2Up,mjj_JetRelativeJERHFDown,mjj_JetRelativeJERHFUp,mjj_JetRelativePtBBDown,mjj_JetRelativePtBBUp,mjj_JetRelativePtEC1Down,mjj_JetRelativePtEC1Up,mjj_JetRelativePtEC2Down,mjj_JetRelativePtEC2Up,mjj_JetRelativePtHFDown,mjj_JetRelativePtHFUp,mjj_JetRelativeStatECDown,mjj_JetRelativeStatECUp,mjj_JetRelativeStatFSRDown,mjj_JetRelativeStatFSRUp,mjj_JetRelativeStatHFDown,mjj_JetRelativeStatHFUp,mjj_JetSinglePionECALDown,mjj_JetSinglePionECALUp,mjj_JetSinglePionHCALDown,mjj_JetSinglePionHCALUp,mjj_JetTimePtEtaDown,mjj_JetTimePtEtaUp};
      
      for (int k=0; k<nbhist; ++k){
	
	float var2=m_sv; 
	float var1_1=pt_sv;

	TLorentzVector myjet1;
	myjet1.SetPtEtaPhiM(jpt_1,jeta_1,jphi_1,0);
	TLorentzVector myjet2;
	myjet2.SetPtEtaPhiM(jpt_2,jeta_2,jphi_2,0);
	TLorentzVector jets=myjet2+myjet1;
	mjj = jets.M();
	float normMELA = ME_sm_VBF/(ME_sm_VBF+45*ME_bkg);

	float var1_2=mjj;//normMELA;  //Dbkg_VBF;//mjj; 
	TLorentzVector myrawmet;
	myrawmet.SetPtEtaPhiM(met,0,metphi,0);
	TLorentzVector mymet=myrawmet;
	
	//KK: added "&& gen_match_1==5"
	if (tes==1 && gen_match_2==5 && gen_match_1==5){	    
	  
	  if (k==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau1*=0.988; mytau2*=0.988;  mymet=mymet+(0.012/0.988)*mytau1+(0.012/0.988)*mytau2;}
	  if (k==1){ var1_1=pt_sv_UP;   var2=m_sv_UP;   mytau1*=1.012; mytau2*=1.012;  mymet=mymet-(0.012/1.012)*mytau1-(0.012/1.012)*mytau2;}
                   
	  if (k==2 && t2_decayMode==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau2*=0.988; mymet=mymet+(0.012/0.988)*mytau2;}
	  if (k==3 && t2_decayMode==0){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau2*=1.012; mymet=mymet-(0.012/1.012)*mytau2;}
	  if (k==4 && t2_decayMode==1){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau2*=0.988; mymet=mymet+(0.012/0.988)*mytau2;}
	  if (k==5 && t2_decayMode==1){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau2*=1.012; mymet=mymet-(0.012/1.012)*mytau2;}
	  if (k==6 && t2_decayMode==10){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau2*=0.988; mymet=mymet+(0.012/0.988)*mytau2;}
	  if (k==7 && t2_decayMode==10){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau2*=1.012; mymet=mymet-(0.012/1.012)*mytau2;}
          
	  if (k==2 && t1_decayMode==0){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau1*=0.988; mymet=mymet+(0.012/0.988)*mytau1;}
	  if (k==3 && t1_decayMode==0){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau1*=1.012; mymet=mymet-(0.012/1.012)*mytau1;}
	  if (k==4 && t1_decayMode==1){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau1*=0.988; mymet=mymet+(0.012/0.988)*mytau1;}
	  if (k==5 && t1_decayMode==1){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau1*=1.012; mymet=mymet-(0.012/1.012)*mytau1;}
	  if (k==6 && t1_decayMode==10){ var1_1=pt_sv_DOWN; var2=m_sv_DOWN; mytau1*=0.988; mymet=mymet+(0.012/0.988)*mytau1;}
	  if (k==7 && t1_decayMode==10){ var1_1=pt_sv_UP; var2=m_sv_UP; mytau1*=1.012; mymet=mymet-(0.012/1.012)*mytau1;}
          
	}
	
	if (tes==1){
	  //KK: Modified lines below from
	  //	    if (k==8){ var2=m_sv_UESDown; var1_1=pt_sv_UESDown; mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
	  //	    else if (k==9){ var2=m_sv_UESUp; var1_1=pt_sv_UESUp; mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
	  //	    else if (k==10){ var2=m_sv_JESDown; var1_1=pt_sv_JESDown; mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
	  //	    else if (k==11){ var2=m_sv_JESUp; var1_1=pt_sv_JESUp; mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
	  //KK: to
	  if (k==8){ var2=m_sv_UncMet_DOWN; var1_1=pt_sv_UncMet_DOWN; mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
	  else if (k==9){ var2=m_sv_UncMet_UP; var1_1=pt_sv_UncMet_UP; mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
	  else if (k==10){ var2=m_sv_ClusteredMet_DOWN; var1_1=pt_sv_ClusteredMet_DOWN; mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
	  else if (k==11){ var2=m_sv_ClusteredMet_UP; var1_1=pt_sv_ClusteredMet_UP; mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
	}
	
	//KK: Added njet and mjj variables affected by JES
	if (tes==100 && var1_2==mjj){
	  njets = nombrejets[k];
	  var1_2 = massejets[k]; //KK for now not available in trees
	}

	if (tes==1 && var1_2==normMELA){ 
	  if (text) {std::cout << "------------------------------ var1_2 is replaced to MELA ------------------------------" << std::endl;text=false;}
	  if (k==8) var1_2=ME_sm_VBF_UncMet_DOWN/(ME_sm_VBF_UncMet_DOWN+45*ME_bkg_UncMet_DOWN);
	  if (k==9) var1_2=ME_sm_VBF_UncMet_UP/(ME_sm_VBF_UncMet_UP+45*ME_bkg_UncMet_UP);
	  if (k==10) var1_2=ME_sm_VBF_ClusteredMet_DOWN/(ME_sm_VBF_ClusteredMet_DOWN+45*ME_bkg_ClusteredMet_DOWN);
	  if (k==11) var1_2=ME_sm_VBF_ClusteredMet_UP/(ME_sm_VBF_ClusteredMet_UP+45*ME_bkg_ClusteredMet_UP);
	}

	if (mytau1.Pt() < 40 || mytau2.Pt() < 40 ) continue;
	if (mytau1.Pt() < 50) continue;
	
	if ((fabs(mytau1.Eta()))>2.1 || (fabs(mytau2.Eta())>2.1)) continue; // L770

	float weight2=1.0;	  
	// D.Kim
	weight2=weight2*sf_trg1*sf_trg2;
	if (sample=="data_obs") {aweight=1.0; weight2=1.0;}
        
	// Additional selections
	bool selection =true;
	TLorentzVector Higgs = mytau1+mytau2+mymet;
	
	// Categories
	bool is_0jet = false;
	bool is_boosted = false;
	bool is_VBF = false;
	bool is_VH = false;
	bool is_2jets = false;

	if (njets==0) is_0jet=true;
	if (njets==1 || (njets>=2 && (!(Higgs.Pt()>100 && std::abs(myjet1.Eta()-myjet2.Eta())>2.5)))) is_boosted=true; 
	if (njets>=2 && Higgs.Pt()>100 && std::abs(myjet1.Eta()-myjet2.Eta())>2.5) is_VBF=true;
	if (njets==2) is_2jets=true;
	//if (!is_0jet && !is_boosted) std::cout << "NN is survived! " << NN_disc << std::endl;

	// Z mumu SF 
	// https://github.com/truggles/Z_to_TauTau_13TeV/blob/SM-HTT-2016/analysis2IsoJetsAndDups.py#L1193-L1211
	// https://github.com/truggles/Z_to_TauTau_13TeV/blob/SM-HTT-2016/analysisPlots.py#L293-L312
	if (is_boosted && (sample=="DY" || sample=="ZTT" || sample=="ZLL" || sample=="ZL" || sample=="ZJ" || sample=="EWKZLL" || sample=="EWKZNuNu")) {
	  float zmumusf = 1.00;
	  if (pt_sv<=100) zmumusf = 0.973;
	  else if (pt_sv<=170) zmumusf = 0.959;
	  else if (pt_sv<=300) zmumusf = 0.934;
	  else zmumusf = 0.993;
	  if (std::abs(tes)!=13) //nominal 
	    aweight*=zmumusf;
	  zmumusf-=1.0;
	  if (tes==13) // up 
	    aweight*=((1.0+2*zmumusf)/(1.0+zmumusf));
	  else if (tes==-13) // down  
	    aweight*=(1.0/(1.0+zmumusf));
	}
	if (is_VBF && (sample=="DY" || sample=="ZTT" || sample=="ZLL" || sample=="ZL" || sample=="ZJ" || sample=="EWKZLL" || sample=="EWKZNuNu")) {
	  float zmumusf = 1.00;
	  if (mjj<=300) zmumusf = (0.010/2.0)+1.0;
	  else if (mjj<=500) zmumusf = (0.064/2.0)+1.0;
	  else if (mjj<=800) zmumusf = (0.088/2.0)+1.0;
	  else zmumusf = (0.003/2.0)+1.0;
	  if (std::abs(tes)!=13) //nominal 
	    aweight*=zmumusf;
	  zmumusf-=1.0;//((-1.0+zmumusf)/2.0);
	  if (tes==13) // up 
	    aweight*=((1.0+2*zmumusf)/(1.0+zmumusf));
	  else if (tes==-13) // down  
	    aweight*=(1.0/(1.0+zmumusf));
	}


	//KK: For some studies, definitions of categories
	//	if(njets>=2 && Higgs.Pt()>100 && mjj > 300) is_VBF=true;
	//	if(njets>=2 && mjj < 300) is_VH=true;
	//	if(njets==1 || (njets>=2 && mjj > 300 && Higgs.Pt()<100)) is_boosted=true;
        
	//std::cout << "-------" << is_0jet << is_boosted << is_VBF << is_VH << std::endl;
        
	//************************* Fill histograms **********************
	
        //            float var = Higgs.Pt(); //Variable to plot
        //	float var = (mytau2+mytau1).M(); //Variable to plot

	/*
	   - Variable info - 
	   var : 0jet -> mtautau svFit (m_sv) 
	   var1_1 : boosted -> Higgs pT svFit 
	   var1_2 : vbf -> mjj
	   var2 = boosted,vbf -> mtautau svFit (m_sv)
	   var1_M* : vbf -> MELA obs
	*/
	float var = var2; 
	/*
	float var1_2 = ME_sm_VBF;//mjj;
	float var1_M1 = Dbkg_VBF;//ME_sm_VBF;
	float var1_M2 = Dbkg_ggH;//ME_sm_ggH;
	float var1_M3 = ME_bkg;
	*/
	if (selection){
	  // ################### signalRegion && OS ####################
	  if (is_0jet && signalRegion && charge1*charge2<0){
	    h0_OS[k]->Fill(var,weight2*aweight);
	    if (tes==0)
	      h_0jet->Fill(var,weight2*aweight);
	  }
	  if (is_boosted && signalRegion && charge1*charge2<0){
	    h1_OS[k]->Fill(var1_1,var2,weight2*aweight);
	    if (tes==0){
	      hx_boosted->Fill(var1_1,weight2*aweight);
	      hy_boosted->Fill(var2,weight2*aweight);
	    }
	  }
	  if (is_VBF && signalRegion && charge1*charge2<0) {
	    h2_OS[k]->Fill(var1_2,var2,weight2*aweight);
	    if (tes==0){
	      hx_vbf->Fill(var1_2,weight2*aweight);
	      hy_vbf->Fill(var2,weight2*aweight);
	      //std::cout << "var1_2 is " << var1_2 << std::endl;
	    }
	  }
	  if (is_VH && signalRegion && charge1*charge2<0)
	    h3_OS[k]->Fill(var1_2,var2,weight2*aweight);
	  if (signalRegion && charge1*charge2<0)
	    h_OS[k]->Fill(var,weight2*aweight);
	  
	  
	  // ################### signalRegion && SS ####################
	  if (is_0jet && signalRegion && charge1*charge2>0)
	    h0_SS[k]->Fill(var,weight2*aweight);
	  if (is_boosted && signalRegion && charge1*charge2>0)
	    h1_SS[k]->Fill(var1_1,var2,weight2*aweight);
	  if (is_VBF && signalRegion && charge1*charge2>0) {
	    h2_SS[k]->Fill(var1_2,var2,weight2*aweight);
	  }
	  if (is_VH && signalRegion && charge1*charge2>0)
	    h3_SS[k]->Fill(var1_2,var2,weight2*aweight); 
	  if (signalRegion && charge1*charge2>0)
	    h_SS[k]->Fill(var,weight2*aweight);


	  // ################### ai-Region && OS ####################
	  if (is_0jet && charge1*charge2<0 && aiRegion)
	    h0_AIOS[k]->Fill(var,weight2*aweight);
	  if (is_boosted && charge1*charge2<0 && aiRegion)
	    h1_AIOS[k]->Fill(var1_1,var2,weight2*aweight);
	  if (is_VBF && charge1*charge2<0 && aiRegion) {
	    h2_AIOS[k]->Fill(var1_2,var2,weight2*aweight);
	  }
	  if (is_VH && charge1*charge2<0 && aiRegion)
	    h3_AIOS[k]->Fill(var1_2,var2,weight2*aweight);
	  if (charge1*charge2<0 && aiRegion)
	    h_AIOS[k]->Fill(var,weight2*aweight);

	  
	  // ################### ai-Region && SS ####################
	  if (is_0jet && charge1*charge2>0 && aiRegion)
	    h0_AISS[k]->Fill(var,weight2*aweight);
	  if (is_boosted && charge1*charge2>0 && aiRegion)
	    h1_AISS[k]->Fill(var1_1,var2,weight2*aweight);
	  if (is_VBF && charge1*charge2>0 && aiRegion) {
	    h2_AISS[k]->Fill(var1_2,var2,weight2*aweight);
	  }
	  if (is_VH && charge1*charge2>0 && aiRegion)
	    h3_AISS[k]->Fill(var1_2,var2,weight2*aweight);
	  if (charge1*charge2>0 && aiRegion)
	    h_AISS[k]->Fill(var,weight2*aweight);	  


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
    //TDirectory *OS2jets_tt =fout->mkdir("tt_2jets");
    
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
      std::cout << "\nnbhist = " << nbhist << ", tes = " << tes << ", postfix = " << postfix  << std::endl;
      
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

      OS0jet_tt->cd();
      h0_OS[k]->SetName(name.c_str()+postfix);
      h0_OS[k]->Write();
      OSboosted_tt->cd();
      h1_OS[k]->SetName(name.c_str()+postfix);
      h1_OS[k]->Write();
      OSvbf_tt->cd();
      h2_OS[k]->SetName(name.c_str()+postfix);
      h2_OS[k]->Write();        
      
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
    }
    fout->Close();
    // D.Kim
    Py_Finalize();
} 


