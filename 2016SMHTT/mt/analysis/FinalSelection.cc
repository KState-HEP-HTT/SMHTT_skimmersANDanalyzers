#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "TMultiGraph.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
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
#include "myHelper.h"
#include "tr_Tree.h"
#include "ScaleFactor.h"
#include "LumiReweightingStandAlone.h"

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

    TFile *f_Trk=new TFile("ratios.root");
    TGraph *h_Trk=(TGraph*) f_Trk->Get("ratio_eta");

    reweight::LumiReWeighting* LumiWeights_12;
    LumiWeights_12 = new reweight::LumiReWeighting("MC_Spring16_PU25ns_V1.root", "MyDataPileupHistogram.root", "pileup", "pileup");

    float xs=1.0; float weight=1.0; float luminosity=20100.0;
    if (sample=="ZTT" or sample=="ZL" or sample=="ZJ" or sample=="ZLL"){ xs=5765.4; weight=luminosity*xs/ngen;}
    else if (sample=="TT") {xs=831.76; weight=luminosity*xs/ngen;}
    else if (sample=="W") {xs=61526.7; weight=luminosity*xs/ngen;}
    else if (sample=="QCD") {xs=720648000*0.00042; weight=luminosity*xs/ngen;}
    else if (sample=="data_obs"){weight=1.0;}
    else if (sample=="WZ1L1Nu2Q") {xs=10.71; weight=luminosity*xs/ngen;}
    else if (sample=="WZ1L3Nu") {xs=3.05; weight=luminosity*xs/ngen;}
    else if (sample=="WZJets") {xs=5.26; weight=luminosity*xs/ngen;}
    else if (sample=="WZ2L2Q") {xs=5.595; weight=luminosity*xs/ngen;}
    else if (sample=="WW1L1Nu2Q") {xs=49.997; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L") {xs=1.212; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
    else if (sample=="VV2L2Nu") {xs=11.95; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_antitop") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_top") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_antitop") {xs=80.95; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_top") {xs=136.02; weight=luminosity*xs/ngen;}
    else if (sample=="ggh") {xs=44.14*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH125") {xs=44.14*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF125") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH120") {xs=47.38*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="VBF120") {xs=3.935*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ggH130") {xs=41.23*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="VBF130") {xs=3.637*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ") {xs=16.523; weight=luminosity*xs/ngen;}
    else if (sample=="WZ") {xs=47.13; weight=luminosity*xs/ngen;}
    else if (sample=="WW") {xs=118.7; weight=luminosity*xs/ngen;}

    if (sample=="ZTT" or sample=="ggH125" or sample=="VBF125" or sample=="ggH120" or sample=="VBF120" or sample=="ggH130" or sample=="VBF130") weight=weight*0.95;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    arbre->SetBranchAddress("run", &run);
    arbre->SetBranchAddress("lumi", &lumi);
    arbre->SetBranchAddress("evt", &evt);
    arbre->SetBranchAddress("NUP", &NUP);
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
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("q_2", &q_2);
    arbre->SetBranchAddress("trackpt_2", &trackpt_2);
    arbre->SetBranchAddress("px_2", &px_2);
    arbre->SetBranchAddress("py_2", &py_2);
    arbre->SetBranchAddress("pz_2", &pz_2);
    arbre->SetBranchAddress("pt_2", &pt_2);
    arbre->SetBranchAddress("eta_2", &eta_2);
    arbre->SetBranchAddress("m_2", &m_2);
    arbre->SetBranchAddress("mt_2", &mt_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("gen_match_2", &gen_match_2);
    arbre->SetBranchAddress("gen_match_1", &gen_match_1);
    arbre->SetBranchAddress("mvamet", &mvamet);
    arbre->SetBranchAddress("mvametphi", &mvametphi);
    arbre->SetBranchAddress("met", &met);
    arbre->SetBranchAddress("metphi", &metphi);
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("pt_tt", &pt_tt);
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("jpt_2", &jpt_2);
    arbre->SetBranchAddress("jdeta", &jdeta);
    arbre->SetBranchAddress("mjj", &mjj);
    arbre->SetBranchAddress("m_sv", &m_sv);
    arbre->SetBranchAddress("m_pfsv", &m_pfsv);
    arbre->SetBranchAddress("m_sv_UP", &m_sv_UP);
    arbre->SetBranchAddress("m_pfsv_DOWN", &m_pfsv_DOWN);
    arbre->SetBranchAddress("m_sv_DOWN", &m_sv_DOWN);
    arbre->SetBranchAddress("m_pfsv_UP", &m_pfsv_UP);
    arbre->SetBranchAddress("pt_sv", &pt_sv);
    arbre->SetBranchAddress("pt_sv_UP", &pt_sv_UP);
    arbre->SetBranchAddress("pt_sv_DOWN", &pt_sv_DOWN);
    //arbre->SetBranchAddress("met_px", &met_px);
    //arbre->SetBranchAddress("met_py", &met_py);
    arbre->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3Hits_2",&byLooseCombinedIsolationDeltaBetaCorr3Hits_2);
    arbre->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3Hits_2",&byMediumCombinedIsolationDeltaBetaCorr3Hits_2);
    arbre->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3Hits_2",&byTightCombinedIsolationDeltaBetaCorr3Hits_2);
    arbre->SetBranchAddress("byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_2);
    arbre->SetBranchAddress("byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_2);
    arbre->SetBranchAddress("byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2",&byTightCombinedIsolationDeltaBetaCorr3HitsdR03_2);
    arbre->SetBranchAddress("byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2",&byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2);
    arbre->SetBranchAddress("byVLooseIsolationMVArun2v1DBoldDMwLT_2",&byVLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVLooseIsolationMVArun2v1DBnewDMwLT_2",&byVLooseIsolationMVArun2v1DBnewDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationMVArun2v1DBdR03oldDMwLT_2",&byLooseIsolationMVArun2v1DBdR03oldDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationMVArun2v1DBoldDMwLT_2",&byLooseIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byLooseIsolationMVArun2v1DBnewDMwLT_2",&byLooseIsolationMVArun2v1DBnewDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationMVArun2v1DBdR03oldDMwLT_2",&byMediumIsolationMVArun2v1DBdR03oldDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationMVArun2v1DBoldDMwLT_2",&byMediumIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byMediumIsolationMVArun2v1DBnewDMwLT_2",&byMediumIsolationMVArun2v1DBnewDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationMVArun2v1DBdR03oldDMwLT_2",&byTightIsolationMVArun2v1DBdR03oldDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationMVArun2v1DBoldDMwLT_2",&byTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byTightIsolationMVArun2v1DBnewDMwLT_2",&byTightIsolationMVArun2v1DBnewDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationMVArun2v1DBdR03oldDMwLT_2",&byVTightIsolationMVArun2v1DBdR03oldDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationMVArun2v1DBoldDMwLT_2",&byVTightIsolationMVArun2v1DBoldDMwLT_2);
    arbre->SetBranchAddress("byVTightIsolationMVArun2v1DBnewDMwLT_2",&byVTightIsolationMVArun2v1DBnewDMwLT_2);
    arbre->SetBranchAddress("byIsolationMVA3oldDMwLTraw_2",&byIsolationMVA3oldDMwLTraw_2);
    arbre->SetBranchAddress("byCombinedIsolationDeltaBetaCorrRaw3Hits_2", &byCombinedIsolationDeltaBetaCorrRaw3Hits_2);
    //arbre->SetBranchAddress("e_2",&e_2);
    arbre->SetBranchAddress("decayModeFindingNewDMs_2",&decayModeFindingNewDMs_2);
    arbre->SetBranchAddress("decayModeFinding_2",&decayModeFinding_2);
    arbre->SetBranchAddress("numChargedSignalCone_2",&numChargedSignalCone_2);
    arbre->SetBranchAddress("numChargedIsoCone_2",&numChargedIsoCone_2);
    arbre->SetBranchAddress("l2_decayMode",&l2_decayMode);
    arbre->SetBranchAddress("againstElectronVLooseMVA6_2",&againstElectronVLooseMVA6_2);
    arbre->SetBranchAddress("againstElectronLooseMVA6_2",&againstElectronLooseMVA6_2);
    arbre->SetBranchAddress("againstElectronMediumMVA6_2",&againstElectronMediumMVA6_2);
    arbre->SetBranchAddress("againstElectronTightMVA6_2",&againstElectronTightMVA6_2);
    arbre->SetBranchAddress("againstElectronVTightMVA6_2",&againstElectronVTightMVA6_2);
    arbre->SetBranchAddress("againstMuonLoose3_2",&againstMuonLoose3_2);
    arbre->SetBranchAddress("againstMuonTight3_2",&againstMuonTight3_2);
    //arbre->SetBranchAddress("dilepton_veto",&dilepton_veto);
    //arbre->SetBranchAddress("extramuon_veto",&extramuon_veto);
    //arbre->SetBranchAddress("extraelec_veto",&extraelec_veto);
    arbre->SetBranchAddress("isZmt",&isZmt);
    //arbre->SetBranchAddress("aMCatNLO_weight",&aMCatNLO_weight);
    //arbre->SetBranchAddress("puweight",&puweight);
    //arbre->SetBranchAddress("trg_weight",&trg_weight);
    arbre->SetBranchAddress("m_vis",&m_vis);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("neutralIso_2",&neutralIso_2);
    arbre->SetBranchAddress("chargedIso_2",&chargedIso_2);
    arbre->SetBranchAddress("puIso_2",&puIso_2);
    arbre->SetBranchAddress("photonIso_2",&photonIso_2);
    arbre->SetBranchAddress("metcor", &metcor);
    arbre->SetBranchAddress("metcorphi", &metcorphi);

   float bins0_cat1[] = {30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180};
   float bins0_cat2[] = {40,50,60,70,80,90,100,110,120,130,140,150,160,180,190,200,210,220};
   //float bins0_cat1[] = {50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,200,205,210,215,220,225};
   //float bins0_cat2[] = {70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,350};
   float bins1_cat1[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,280};
   float bins1_cat2[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,320};
   float bins2_cat1[] = {0,20,40,60,80,100,120,140,160,180,200,220,270,350};
   float bins2_cat2[] = {0,20,40,60,80,100,120,140,160,180,200,220,270,350};

   /*float bins0_cat1[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180};
   float bins0_cat2[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180};
   float bins1_cat1[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180};
   float bins1_cat2[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180};
   float bins2_cat1[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180};
   float bins2_cat2[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180};*/


   /*float bins0_cat1[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,200};
   float bins0_cat2[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,200};
   float bins1_cat1[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};
   float bins1_cat2[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};
   float bins2_cat1[] = {0,20,40,60,80,100,120,140,160,180,200,220,240};
   float bins2_cat2[] = {0,20,40,60,80,100,120,140,160,180,200,220,240};*/
/*
   //float bins0_cat2[] = {0,30,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};//,260,270,280,290,300,310,320,330,340,350};
   float bins0_cat1[] = {50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126};//
   float bins0_cat2[] = {50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140};//
   float bins1_cat1[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};//,260,270,280,290,300,310,320,330,340,350};
   float bins1_cat2[] = {0,30,45,60,75,90,105,120,135,150,165,180,195,210,225,240,255,270,285};//50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};//,260,270,280,290,300,310,320,330,340,350};
   float bins2_cat1[] = {0,30,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250};//,260,270,280,290,300,310,320,330,340,350};
   float bins2_cat2[] = {0,20,40,60,80,100,120,140,160,180,200,220,240};//,280,300,320,340,360};
*/
   int  binnum1_cat1 = sizeof(bins1_cat1)/sizeof(Float_t) - 1;
   int  binnum2_cat1 = sizeof(bins2_cat1)/sizeof(Float_t) - 1;
   int  binnum0_cat1 = sizeof(bins0_cat1)/sizeof(Float_t) - 1;
   int  binnum1_cat2 = sizeof(bins1_cat2)/sizeof(Float_t) - 1;
   int  binnum2_cat2 = sizeof(bins2_cat2)/sizeof(Float_t) - 1;
   int  binnum0_cat2 = sizeof(bins0_cat2)/sizeof(Float_t) - 1;

   TH1F *n70=new TH1F ("n70", "n70", 6,0,6);
   TH1F *h0_1OS=new TH1F ("h0_1OS","Invariant mass",binnum0_cat1,bins0_cat1);h0_1OS->Sumw2();
   TH1F *h0_2OS=new TH1F ("h0_2OS","Invariant mass",binnum0_cat2,bins0_cat2);h0_2OS->Sumw2();
   TH1F *h1_1OS=new TH1F ("h1_1OS","Invariant mass",binnum1_cat1,bins1_cat1);h1_1OS->Sumw2();
   TH1F *h1_2OS=new TH1F ("h1_2OS","Invariant mass",binnum1_cat2,bins1_cat2);h1_2OS->Sumw2();
   TH1F *h2_1OS=new TH1F ("h2_1OS","Invariant mass",binnum2_cat1,bins2_cat1);h2_1OS->Sumw2();
   TH1F *h2_2OS=new TH1F ("h2_2OS","Invariant mass",binnum2_cat2,bins2_cat2);h2_2OS->Sumw2();
   TH1F *h0_1SS=new TH1F ("h0_1SS","Invariant mass",binnum0_cat1,bins0_cat1);h0_1SS->Sumw2();
   TH1F *h0_2SS=new TH1F ("h0_2SS","Invariant mass",binnum0_cat2,bins0_cat2);h0_2SS->Sumw2();
   TH1F *h1_1SS=new TH1F ("h1_1SS","Invariant mass",binnum1_cat1,bins1_cat1);h1_1SS->Sumw2();
   TH1F *h1_2SS=new TH1F ("h1_2SS","Invariant mass",binnum1_cat2,bins1_cat2);h1_2SS->Sumw2();
   TH1F *h2_1SS=new TH1F ("h2_1SS","Invariant mass",binnum2_cat1,bins2_cat1);h2_1SS->Sumw2();
   TH1F *h2_2SS=new TH1F ("h2_2SS","Invariant mass",binnum2_cat2,bins2_cat2);h2_2SS->Sumw2();

   TH1F *h2_1OS_looseW=new TH1F ("h2_1OS_looseW","Invariant mass",binnum2_cat1,bins2_cat1);h2_1OS_looseW->Sumw2();
   TH1F *h2_2OS_looseW=new TH1F ("h2_2OS_looseW","Invariant mass",binnum2_cat2,bins2_cat2);h2_2OS_looseW->Sumw2();
   TH1F *h2_1SS_looseW=new TH1F ("h2_1SS_looseW","Invariant mass",binnum2_cat1,bins2_cat1);h2_1SS_looseW->Sumw2();
   TH1F *h2_2SS_looseW=new TH1F ("h2_2SS_looseW","Invariant mass",binnum2_cat2,bins2_cat2);h2_2SS_looseW->Sumw2();

   ScaleFactor * myScaleFactor_trg = new ScaleFactor();
   myScaleFactor_trg->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BCD/Muon_IsoMu22_OR_TkIsoMu22_eff.root");
   ScaleFactor * myScaleFactor_id = new ScaleFactor();
   myScaleFactor_id->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BCD/Muon_IdIso0p15_eff.root");

   float n70passOS=0; 
   Int_t nentries_wtn = (Int_t) arbre->GetEntries();
   for (Int_t i = 0; i < nentries_wtn; i++) {
        arbre->GetEntry(i);
        if (i % 20000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);
	//if (nbtag>0) continue;
	if (pt_1<24) continue;
	//if (fabs(eta_1)>2.1) continue;
        bool tauIsolation=byTightIsolationMVArun2v1DBoldDMwLT_2;

        float sf_trg=1.0;
        float sf_id=1.0;

        if (sample!="data_obs"){
           sf_trg=myScaleFactor_trg->get_EfficiencyData(pt_1,eta_1);
           sf_id=myScaleFactor_id->get_ScaleFactor(pt_1,eta_1);
        }

	if (iso_1>0.15) continue;
	if (!againstElectronVLooseMVA6_2) continue;
	if (!againstMuonTight3_2) continue;
	if (!decayModeFinding_2) continue;
	if (fabs(eta_2)>2.3) continue;
	if (!tauIsolation) continue;

	TLorentzVector mytau; 
	mytau.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
        TLorentzVector mymu;
        mymu.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);

	//****************** Tau energy scale corrections ************************
	if (tes==1 && gen_match_2==5){
	   mytau*=1.03;
	}
	if (tes==-1 && gen_match_2==5){
           mytau*=0.97;
        }

        if (sample=="W"){
            if (NUP==5) weight=12.43;
            else if (NUP==6) weight=4.019;
            else if (NUP==7) weight=2.133;
            else if (NUP==8) weight=1.077;
            else if (NUP==9) weight=1.176;
        }

        if (sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
            if (NUP==5)
                weight=1.283;
            if (NUP==6)
                weight=0.2825;
            if (NUP==7)
                weight=0.3022;
            if (NUP==8)
                weight=0.3128;
            if (NUP==9)
                weight=0.2512;
        }

        float correction=sf_trg*sf_id*h_Trk->Eval(eta_1)*LumiWeights_12->weight(npu);
        float aweight=weight*correction;
        if (gen_match_2==5 && l2_decayMode==0) aweight=aweight*0.97;
        if (gen_match_2==5 && l2_decayMode==1) aweight=aweight*0.92;
        if (gen_match_2==5 && l2_decayMode<2) aweight=aweight*0.94;
        if (gen_match_2==5 && l2_decayMode==10) aweight=aweight*0.80;
        if (sample=="data_obs") aweight=1.0;


	float poidsW=1.0;

        if (sample=="ZL" && gen_match_2>4) continue;
        if (sample=="ZTT" && gen_match_2!=5) continue;
        if (sample=="ZLL" && gen_match_2==5) continue;
        if (sample=="ZJ" && gen_match_2!=6) continue;
        if (sample=="ZL" or (sample=="ZLL" && gen_match_2<5)){
            if (fabs(eta_2)<0.4) aweight=aweight*1.470;
            else if (fabs(eta_2)<0.8) aweight=aweight*1.367;
            else if (fabs(eta_2)<1.2) aweight=aweight*1.251;
            else if (fabs(eta_2)<1.7) aweight=aweight*1.770;
            else if (fabs(eta_2)<2.3) aweight=aweight*1.713;
        }

        //********************** MT between muon and MET ***********************************
        float mt=0;
	float mex=metcor*cos(metcorphi); float mey=metcor*sin(metcorphi);
	//float mex=mvamet*cos(mvametphi); float mey=mvamet*sin(mvametphi);
	if (tes==-1 && gen_match_2==5){
	   mex=mex+0.03*(mytau.Px()/0.97);
           mey=mey+0.03*(mytau.Py()/0.97);
	}
        if (tes==1 && gen_match_2==5){
           mex=mex-0.03*(mytau.Px()/1.03);
           mey=mey-0.03*(mytau.Py()/1.03);
        }
	float met_pt2=sqrt(mex*mex+mey*mey);
	mt=TMass_F(pt_1,met_pt2,px_1,mex,py_1,mey);

	//******************** W reweighting in high MT sideband ****************************
        if (q_1*q_2<0 && mt>80 && tauIsolation) n70passOS+=poidsW*aweight;

	//************************* Pzeta variable ***********************
	float norm_zeta=norm_F(mytau.Px()/mytau.Pt()+px_1/pt_1,mytau.Py()/mytau.Pt()+py_1/pt_1);
	float x_zeta= (mytau.Px()/mytau.Pt()+px_1/pt_1)/norm_zeta;
	float y_zeta= (mytau.Py()/mytau.Pt()+py_1/pt_1)/norm_zeta;
	float p_zeta_mis=mex*x_zeta+mey*y_zeta;
	float pzeta_vis=(mytau.Px()+px_1)*x_zeta+(mytau.Py()+py_1)*y_zeta;
	bool cut_zeta=p_zeta_mis-0.85*pzeta_vis>-30;

	//************************* Fill histograms **********************
	float var=(mytau+mymu).M();//m_vis;//
	var=m_sv;
	if (tes==-1)
	   var=m_sv_DOWN;
        if (tes==1)
           var=m_sv_UP;
	if (njets==0) var=(mytau+mymu).M();
        float pth=pt_sv;
        if (tes==1 && gen_match_2==5)
           pth=pt_sv_UP;
        if (tes==-1 && gen_match_2==5)
           pth=pt_sv_DOWN;

        /*var=m_pfsv;
        if (tes==-1)
           var=m_pfsv_DOWN;
        if (tes==1)
           var=m_pfsv_UP;
	var=(mytau+mymu).M();*/

        /*float alpha = (mex * mymu.Py() - mymu.Px()*mey)/(mytau.Px()*mymu.Py() + mymu.Px()*mytau.Py());
	float beta = (mex * mytau.Py() - mytau.Px() * mey)/(mytau.Px()*mymu.Py() + mymu.Px()*mytau.Py());
        var =  (mytau+mymu).M() * (1 + alpha) * (1 + beta);
	cout<<(mytau+mymu).M()<<" "<<alpha<<" "<<beta<<" "<<var<<endl;*/
	/*float pmis1=(mex*mymu.Pt()*mytau.Py()-mey*mytau.Px()*mymu.Pt())/(mymu.Px()*mytau.Py()-mytau.Px()*mymu.Py());
	float pmis2=(mex*mytau.Pt()*mymu.Py()-mey*mymu.Px()*mytau.Pt())/(mymu.Px()*mytau.Py()-mytau.Px()*mymu.Py());
	if (pmis1<0) pmis1=0;
        if (pmis2<0) pmis2=0;
	float alpha=(mymu.Pt())/(mymu.Pt()+pmis1);
        float beta=(mytau.Pt())/(mytau.Pt()+pmis2);
	float mcoll=(mytau+mymu).M();
	if (alpha > 0) mcoll=mcoll/sqrt(alpha);
        if (beta > 0) mcoll=mcoll/sqrt(beta);
	var=mcoll;*/

	/*if (mt>50) continue;
	if (mytau.Pt()<30) continue;
	if (njets==0){
            if (q_1*q_2<0 && mytau.Pt()<50)
		h0_1OS->Fill(var,aweight*poidsW);
            if (q_1*q_2<0 && mytau.Pt()>50)
                h0_2OS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mytau.Pt()<50)
                h0_1SS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mytau.Pt()>50)
                h0_2SS->Fill(var,aweight*poidsW);
	}
        if (njets==1){
            if (q_1*q_2<0 && (mytau.Pt()<50))
                h1_1OS->Fill(var,aweight*poidsW);
            if (q_1*q_2<0 && mytau.Pt()>50)
                h1_2OS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && (mytau.Pt()<50))
                h1_1SS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mytau.Pt()>50)
                h1_2SS->Fill(var,aweight*poidsW);
        }
        if (njets==2){
            if (q_1*q_2<0 && mjj < 900 && mjj>600)
                h2_1OS->Fill(var,aweight*poidsW);
            if (q_1*q_2<0 &&  mjj>900)
                h2_2OS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mjj < 900 && mjj>600)
                h2_1SS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mjj>900)
                h2_2SS->Fill(var,aweight*poidsW);
        }*/

        if (njets==0 && mt<50 && mytau.Pt()>20){
            if (q_1*q_2<0 && mytau.Pt()<50)
                h0_1OS->Fill(var,aweight*poidsW);
            if (q_1*q_2<0 && mytau.Pt()>50)
                h0_2OS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mytau.Pt()<50)
                h0_1SS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mytau.Pt()>50)
                h0_2SS->Fill(var,aweight*poidsW);
        }
        if ((njets==1 or (njets>=2 && mjj<500)) && mt<50 && mytau.Pt()>30){
            if (q_1*q_2<0 && (mytau.Pt()<40 or pth<140))
                h1_1OS->Fill(var,aweight*poidsW);
            if (q_1*q_2<0 && (mytau.Pt()>40 && pth>140))
                h1_2OS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && (mytau.Pt()<40 or pth<140))
                h1_1SS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && (mytau.Pt()>40 && pth>140))
                h1_2SS->Fill(var,aweight*poidsW);
        }
        if (njets==2 && mt<50 && mytau.Pt()>20){
            if (q_1*q_2<0 && ((mjj>500 && mjj<800) or (mjj>500 && pth<100)))
                h2_1OS->Fill(var,aweight*poidsW);
            if (q_1*q_2<0 && mjj>800 && pth>100)
                h2_2OS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && ((mjj>500 && mjj<800) or (mjj>500 && pth<100)))
                h2_1SS->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mjj>800 && pth>100)
                h2_2SS->Fill(var,aweight*poidsW);
            if (q_1*q_2<0 && mjj>200)
                h2_1OS_looseW->Fill(var,aweight*poidsW);
            if (q_1*q_2<0 && mjj>200 && pth>100)
                h2_2OS_looseW->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mjj>200)
                h2_1SS_looseW->Fill(var,aweight*poidsW);
            if (q_1*q_2>0 && mjj>200 && pth>100)
                h2_2SS_looseW->Fill(var,aweight*poidsW);
        }

				
    } // end of loop over events

    cout<<h2_2OS_looseW->GetEntries()<<" "<<h2_2OS->GetEntries()<<endl;
    h2_1OS_looseW->Scale(h2_1OS->Integral()/h2_1OS_looseW->Integral());
    h2_1SS_looseW->Scale(h2_1SS->Integral()/h2_1SS_looseW->Integral());
    h2_2OS_looseW->Scale(h2_2OS->Integral()/h2_2OS_looseW->Integral());
    h2_2SS_looseW->Scale(h2_2SS->Integral()/h2_2SS_looseW->Integral());

    cout<<"n70: "<<n70passOS<<endl;
    n70->SetBinContent(1,n70passOS);
    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    n70->Write();

    TString postfix="";
    if (tes==1)
	postfix="_TESUp";
    if (tes==-1)
        postfix="_TESDown";
    TDirectory *OS0jet_cat1 =fout->mkdir("mt_0jet_low");
    OS0jet_cat1->cd();
    h0_1OS->SetName(name.c_str()+postfix);
    h0_1OS->Write();
    TDirectory *SS0jet_cat1 =fout->mkdir("SS0jet_cat1");
    SS0jet_cat1->cd();
    h0_1SS->SetName(name.c_str()+postfix);
    h0_1SS->Write();
    TDirectory *OS0jet_cat2 =fout->mkdir("mt_0jet_high");
    OS0jet_cat2->cd();
    h0_2OS->SetName(name.c_str()+postfix);
    h0_2OS->Write();
    TDirectory *SS0jet_cat2 =fout->mkdir("SS0jet_cat2");
    SS0jet_cat2->cd();
    h0_2SS->SetName(name.c_str()+postfix);
    h0_2SS->Write();
    TDirectory *OS1jet_cat1 =fout->mkdir("mt_1jet_low");
    OS1jet_cat1->cd();
    h1_1OS->SetName(name.c_str()+postfix);
    h1_1OS->Write();
    TDirectory *SS1jet_cat1 =fout->mkdir("SS1jet_cat1");
    SS1jet_cat1->cd();
    h1_1SS->SetName(name.c_str()+postfix);
    h1_1SS->Write();
    TDirectory *OS1jet_cat2 =fout->mkdir("mt_1jet_high");
    OS1jet_cat2->cd();
    h1_2OS->SetName(name.c_str()+postfix);
    h1_2OS->Write();
    TDirectory *SS1jet_cat2 =fout->mkdir("SS1jet_cat2");
    SS1jet_cat2->cd();
    h1_2SS->SetName(name.c_str()+postfix);
    h1_2SS->Write();
    TDirectory *OS2jet_cat1 =fout->mkdir("mt_vbf_low");
    OS2jet_cat1->cd();
    if (sample!="W"){
       h2_1OS->SetName(name.c_str()+postfix);
       h2_1OS->Write();
    }
    else{
       h2_1OS_looseW->SetName(name.c_str()+postfix);
       h2_1OS_looseW->Write();
    }
    TDirectory *SS2jet_cat1 =fout->mkdir("SS2jet_cat1");
    SS2jet_cat1->cd();
    if (sample!="W"){
       h2_1SS->SetName(name.c_str()+postfix);
       h2_1SS->Write();
    }
    else{
       h2_1SS_looseW->SetName(name.c_str()+postfix);
       h2_1SS_looseW->Write();
    }
    TDirectory *OS2jet_cat2 =fout->mkdir("mt_vbf_high");
    OS2jet_cat2->cd();
    if (sample!="W"){
       h2_2OS->SetName(name.c_str()+postfix);
       h2_2OS->Write();
    }
    else{
       h2_2OS_looseW->SetName(name.c_str()+postfix);
       h2_2OS_looseW->Write();
    }
    TDirectory *SS2jet_cat2 =fout->mkdir("SS2jet_cat2");
    SS2jet_cat2->cd();
    if (sample!="W"){
       h2_2SS->SetName(name.c_str()+postfix);
       h2_2SS->Write();
    }
    else{
       h2_2SS_looseW->SetName(name.c_str()+postfix);
       h2_2SS_looseW->Write();
    }
    fout->Close();
} 


