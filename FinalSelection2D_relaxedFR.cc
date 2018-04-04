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
#include "tt_Tree.h"
#include "ScaleFactor.h"
#include "LumiReweightingStandAlone.h"
#include "btagSF.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"

using namespace std;

int main(int argc, char** argv) {
  
  std::string input = *(argv + 1);
  std::string output = *(argv + 2);
  std::string sample = *(argv + 3);
  std::string name = *(argv + 4);
  
  cout << "argc : " << argc << endl;
  float tes=0;
  if (argc > 1) {
    tes = atof(argv[5]);
  }
  
  TFile *f_Double = new TFile(input.c_str());
  cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
  TTree *arbre = (TTree*) f_Double->Get("tt_tree");
  TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
  float ngen = nbevt->GetBinContent(2);
  cout.precision(11);
  cout << "############## " << input.c_str() << "nevents 2nd bin - " << ngen << endl; 

  //Declaration of files with scale factors 
  TFile *f_Trk=new TFile("Tracking_EfficienciesAndSF_BCDEFGH.root");
  TGraph *h_Trk=(TGraph*) f_Trk->Get("ratio_eff_eta3_dr030e030_corr");
  
  reweight::LumiReWeighting* LumiWeights_12;
  LumiWeights_12 = new reweight::LumiReWeighting("MC_Moriond17_PU25ns_V1.root", "Data_Pileup_2016_271036-284044_80bins.root", "pileup", "pileup");
  
  TFile *fZ=new TFile("zpt_weights_2016_BtoH.root");
  TH2F *histZ=(TH2F*) fZ->Get("zptmass_histo");
  
  TFile fw("htt_scalefactors_v16_3.root");
  RooWorkspace *w = (RooWorkspace*)fw.Get("w");
  fw.Close();
  
  TFile fw2("htt_scalefactors_sm_moriond_v1.root");
  RooWorkspace *w2 = (RooWorkspace*)fw2.Get("w");
  fw2.Close();
  
  //Normalization os MC samples
  float xs=1.0; float weight=1.0; float luminosity=35870.0;
  if (sample=="DY" or sample=="ZL" or sample=="ZTT" or sample=="ZJ" or sample=="ZLL"){ xs=5765.4; weight=luminosity*xs/ngen;}//std::cout << "DY weight = " << weight << std::endl;}
  else if (sample=="TTL" or sample=="TT" or sample=="TTT" or sample=="TTJ") {xs=831.76; weight=luminosity*xs/ngen;}
  else if (sample=="W") {xs=61526.7; weight=luminosity*xs/ngen;}// std::cout << "W weight = " << weight << std::endl;}
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
  else if (sample=="ggH125") {xs=48.58; weight=luminosity*xs/ngen;}
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
  else if (sample=="ZZ4L_powheg") {xs=1.256; weight=luminosity*xs/ngen;}
  else if (sample=="WZ3LNu_powheg") {xs=4.430; weight=luminosity*xs/ngen;}
  else if (sample=="ttZ") {xs=0.2529; weight=luminosity*xs/ngen;}
  else if (sample=="ttW") {xs=0.2043; weight=luminosity*xs/ngen;}
  else if (sample=="ZG") {xs=117.864; weight=luminosity*xs/ngen;}
  else if (sample=="GGZZ2e2mu") {xs=0.00319; weight=luminosity*xs/ngen;}
  else if (sample=="GGZZ2e2tau") {xs=0.00319; weight=luminosity*xs/ngen;}
  else if (sample=="GGZZ2mu2tau") {xs=0.00319; weight=luminosity*xs/ngen;}
  else if (sample=="GGZZ4e") {xs=0.00159; weight=luminosity*xs/ngen;}
  else if (sample=="GGZZ4mu") {xs=0.00159; weight=luminosity*xs/ngen;}
  else if (sample=="GGZZ4tau") {xs=0.00159; weight=luminosity*xs/ngen;}
  else if (sample=="WWZ") {xs=0.1651; weight=luminosity*xs/ngen;}
  else if (sample=="WZZ") {xs=0.05565; weight=luminosity*xs/ngen;}
  else if (sample=="ZZZ") {xs=0.01398; weight=luminosity*xs/ngen;}
  else if (sample=="WplusHWW125") {xs=0.840*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
  else if (sample=="WminusHWW125") {xs=0.5328*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
  else if (sample=="ZHWW125") {xs=0.8839*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
  else cout<<"Attention!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
  
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(10);
  arbre->SetBranchAddress("jetpt_1", &jetpt_1);
  arbre->SetBranchAddress("jetpt_2", &jetpt_2);
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
  arbre->SetBranchAddress("q_2", &q_2);
  arbre->SetBranchAddress("px_2", &px_2);
  arbre->SetBranchAddress("py_2", &py_2);
  arbre->SetBranchAddress("pz_2", &pz_2);
  arbre->SetBranchAddress("pt_2", &pt_2);
  arbre->SetBranchAddress("eta_2", &eta_2);
  arbre->SetBranchAddress("iso_2", &iso_2);
  arbre->SetBranchAddress("m_2", &m_2);
  arbre->SetBranchAddress("phi_2", &phi_2);
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
  
  
  arbre->SetBranchAddress("met", &met);
  arbre->SetBranchAddress("metphi", &metphi);
  arbre->SetBranchAddress("njets", &njets);
  arbre->SetBranchAddress("nbtag", &nbtag);
  arbre->SetBranchAddress("nbtagL", &nbtagL);
  arbre->SetBranchAddress("jpt_1", &jpt_1);
  arbre->SetBranchAddress("amcatNLO_weight", &amcatNLO_weight);
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
    
  arbre->SetBranchAddress("t1_decayMode",&t1_decayMode);
  arbre->SetBranchAddress("t2_decayMode",&t2_decayMode);
  arbre->SetBranchAddress("gen_match_1",&gen_match_1);
  arbre->SetBranchAddress("gen_match_2",&gen_match_2);
  arbre->SetBranchAddress("npu",&npu);
  arbre->SetBranchAddress("genpT",&genpT);
  arbre->SetBranchAddress("genM",&genM);
  arbre->SetBranchAddress("pt_top1",&pt_top1);
  arbre->SetBranchAddress("pt_top2",&pt_top2);
  arbre->SetBranchAddress("numGenJets",&numGenJets);
  arbre->SetBranchAddress("bpt_1",&bpt_1);
  arbre->SetBranchAddress("bpt_2",&bpt_2);
  arbre->SetBranchAddress("bflavor_1",&bflavor_1);
  arbre->SetBranchAddress("bflavor_2",&bflavor_2);
  
  //float bins0[] = {0, 40, 60, 70, 80, 90, 100, 110, 120, 130, 150, 200, 250}; //VBF
  //float bins1[] = {0, 40, 60, 70, 80, 90, 100, 110, 120, 130, 150, 200, 250}; //VBF
  //float bins0[] = {0, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300}; //VBF
  //float bins1[] = {0, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300}; //VBF
  float bins0[] = {0,50,100,150,200,250,300,350,400,450,500}; //fig50 H pT
  float bins1[] = {0,50,100,150,200,250,300,350,400,450,500}; //fig50 H pT

  cout<<"bins0 : "<<bins0<<endl;
  cout<<"size of bins0 : "<<sizeof(bins0)<<endl;
  cout<<"size of Float_t : "<<sizeof(Float_t)<<endl;
  
  int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
  int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;
  
  
  std::vector<TH1F*> h0_OS; // Signal region, opposite-sign taus, T,T
  std::vector<TH1F*> h0_SS; // Signal-like region, same-sign taus, T,T
  std::vector<TH1F*> h0_AIOS; // Region with opposite-sign anti-isolated taus, M,!T&&L || !T&&L,M
  std::vector<TH1F*> h0_AISS; // Region with same-sign anti-isolated taus, M,!T&&L || !T&&L,M

  //For shape systematics
  int nbhist=1;
  if (tes==100) nbhist=56;
  if (tes==1) nbhist=12;
  if (tes==16) nbhist=6;
  if (tes==17) nbhist=12;
  if (tes==18) nbhist=4;
  if (tes==19) nbhist=6;
  
  for (int k=0; k<nbhist; ++k){
    ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
    h0_OS.push_back(new TH1F (HNS0OS.str().c_str(),"diTauMa",binnum0,bins0)); h0_OS[k]->Sumw2();
    
    ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
    h0_SS.push_back(new TH1F (HNS0SS.str().c_str(),"diTauMa",binnum1,bins1)); h0_SS[k]->Sumw2();
    
    ostringstream HNS0AIOS; HNS0AIOS << "h0_AIOS" << k;
    h0_AIOS.push_back(new TH1F (HNS0AIOS.str().c_str(),"diTauMa",binnum0,bins0)); h0_AIOS[k]->Sumw2();
    
    ostringstream HNS0AISS; HNS0AISS << "h0_AISS" << k;
    h0_AISS.push_back(new TH1F (HNS0AISS.str().c_str(),"diTauMa",binnum1,bins1)); h0_AISS[k]->Sumw2();
  }
  /*
  ScaleFactor * myScaleFactor_trgMu23 = new ScaleFactor();
  myScaleFactor_trgMu23->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu23leg_2016BtoH_eff.root");
  ScaleFactor * myScaleFactor_trgMu8 = new ScaleFactor();
  myScaleFactor_trgMu8->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu8leg_2016BtoH_eff.root");
  ScaleFactor * myScaleFactor_trgEle12 = new ScaleFactor();
  myScaleFactor_trgEle12->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele12leg_eff.root");
  ScaleFactor * myScaleFactor_trgEle23 = new ScaleFactor();
  myScaleFactor_trgEle23->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele23leg_eff.root");

   ScaleFactor * myScaleFactor_trg = new ScaleFactor();
   myScaleFactor_trg->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele25_eta2p1_WPTight_eff.root");
   ScaleFactor * myScaleFactor_idEle = new ScaleFactor();
   myScaleFactor_idEle->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_IdIso_IsoLt0p15_eff.root");
   ScaleFactor * myScaleFactor_idMu = new ScaleFactor();
   myScaleFactor_idMu->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_IdIso_IsoLt0p15_2016BtoH_eff.root");
  */
   Int_t nentries_wtn = (Int_t) arbre->GetEntries();
   for (Int_t i = 0; i < nentries_wtn; i++) {
        arbre->GetEntry(i);
        if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);

	// DoubleTau trigger
	if (sample=="data_obs" && ((input=="myntuples/data_H_v2.root") || (input=="myntuples/data_H_v3.root"))) {
	  if(!passDoubleTauCmbIso35) continue; 
	}
	if (sample=="data_obs" && !(input=="myntuples/data_H_v2.root") && !(input=="myntuples/data_H_v3.root")) { 
	  if (!passDoubleTau35) continue; 
	}
	if (sample!="data_obs") { 
	  if(!passDoubleTauCmbIso35 || !passDoubleTau35) continue; 
	  if(passDoubleTauCmbIso35 && (filterDoubleTauCmbIso35_1<0.5 || filterDoubleTauCmbIso35_2<0.5)) continue;
	  if(passDoubleTau35 && (filterDoubleTau35_1<0.5 || filterDoubleTau35_2<0.5)) continue;
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

	if (againstElectronVLooseMVA6_1 < 0.5) continue; // L773
	if (againstElectronVLooseMVA6_2 < 0.5) continue; 
	if (againstMuonLoose3_1 < 0.5) continue; //774
	if (againstMuonLoose3_2 < 0.5) continue;
	if (byLooseIsolationMVArun2v1DBoldDMwLT_1 < 0.5 && byLooseIsolationMVArun2v1DBoldDMwLT_2 < 0.5) continue; // Fig 43(a)
	if (extramuon_veto) continue;
	if (extraelec_veto) continue;
        float sf_trg=1.0;
        float sf_id=1.0;
	float eff_tau=1.0;

	/*
        if (sample!="data_obs"){
	  //sf_id=myScaleFactor_idMu->get_ScaleFactor(mytau1.Pt(),mytau1.Eta())*myScaleFactor_idMu->get_ScaleFactor(mytau2.Pt(),mytau2.Eta());
	  w->var("m_pt")->setVal(mytau1.Pt());
	  w->var("m_eta")->setVal(mytau1.Eta());
	  sf_id=sf_id*w->function("m_trk_ratio")->getVal();
	  w->var("m_pt")->setVal(mytau2.Pt());
	  w->var("m_eta")->setVal(mytau2.Eta());
	  sf_id=sf_id*w->function("m_trk_ratio")->getVal();
	  }*/

	// Regions
	float signalRegion = byTightIsolationMVArun2v1DBoldDMwLT_1 && byTightIsolationMVArun2v1DBoldDMwLT_2;
        float aiRegion = ((byMediumIsolationMVArun2v1DBoldDMwLT_1 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && byLooseIsolationMVArun2v1DBoldDMwLT_2) || (byMediumIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_1 && byLooseIsolationMVArun2v1DBoldDMwLT_1));
	
	// GenMap
	//if (sample=="DY"

	
	// Weights depending in the generated jet multiplicity
        if (sample=="W"){
	  weight=38.73334813;
	  if (numGenJets==1) weight=7.512695043;
	  else if (numGenJets==2) weight=4.06934263;
	  else if (numGenJets==3) weight=1.037445761;
	  else if (numGenJets==4) weight=1.103079447;
        }

        if (sample=="DY" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
	  weight=0.697701634;
	  if (numGenJets==1)
	    weight=0.343195232;
	  else if (numGenJets==2)
	    weight=0.348500407;
	  else if (numGenJets==3)
	    weight=0.355788884;
	  else if (numGenJets==4)
	    weight=0.305990056;
	  /*weight=1.4184;
            if (numGenJets==1)
                weight=0.45729;
            else if (numGenJets==2)
                weight=0.4668;
            else if (numGenJets==3)
                weight=0.47995;
            else if (numGenJets==4)
	    weight=0.39349;*/
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
              if (fabs(mytau1.Eta())<1.460) aweight=aweight*1.213;
              else if (fabs(mytau1.Eta())>1.558) aweight=aweight*1.375;
           }
           if (gen_match_2==1 or gen_match_2==3){
              if (fabs(mytau2.Eta())<1.460) aweight=aweight*1.213;
              else if (fabs(mytau2.Eta())>1.558) aweight=aweight*1.375;
           }
	   // mu->tau fakes Loose
           else if (gen_match_1==2 or gen_match_1==4){
              if (fabs(mytau1.Eta())<0.4) aweight=aweight*1.010;
              else if (fabs(mytau1.Eta())<0.8) aweight=aweight*1.007;
              else if (fabs(mytau1.Eta())<1.2) aweight=aweight*0.870;
              else if (fabs(mytau1.Eta())<1.7) aweight=aweight*1.154;
              else aweight=aweight*2.281;
           }
           else if (gen_match_2==2 or gen_match_2==4){
              if (fabs(mytau2.Eta())<0.4) aweight=aweight*1.010;
              else if (fabs(mytau2.Eta())<0.8) aweight=aweight*1.007;
              else if (fabs(mytau2.Eta())<1.2) aweight=aweight*0.870;
              else if (fabs(mytau2.Eta())<1.7) aweight=aweight*1.154;
              else aweight=aweight*2.281;
           }
	   //aweight=aweight*h_Trk->Eval(eta_1);
	}

	// Z pt reweighting for DY events
	if (sample=="DY" or sample=="EWKZLL" or sample=="EWKZNuNu" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
	    float zpt_corr=histZ->GetBinContent(histZ->GetXaxis()->FindBin(genM),histZ->GetYaxis()->FindBin(genpT));
	    if (fabs(tes)!=10) //nominal
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
        if ((sample=="TTL" or sample=="TTJ" or sample=="TTT" or sample=="TT") && fabs(tes)!=11) aweight*=sqrt(exp(0.156-0.00137*pttop1)*exp(0.156-0.00137*pttop2));
        if ((sample=="TTL" or sample=="TTJ" or sample=="TTT" or sample=="TT") && tes==11) aweight*=(1+2*(sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2))-1));

	if (sample=="data_obs") aweight=1.0;

	// #################################
	// # Loop over uncertainty sources #
	// #################################
        TLorentzVector myrawmet;
        myrawmet.SetPtEtaPhiM(met,0,metphi,0);

	for (int k=0; k<nbhist; ++k){
	    // for each iteration start from the nominal objets
	    float weight2=1.0;
	    TLorentzVector mymet=myrawmet;
	    
	    // Apply uncertainty shifts ( NOT ADDED YET )
	    
	    // pT, Eta cuts for the leptons
            if (mytau1.Pt()<50 || mytau2.Pt()<40) continue; // L770
            if (mytau1.Pt()<40 && mytau2.Pt()<40) continue;//if (mytau1.Pt()<20 and mytau2.Pt()<20) continue;
	    if (fabs(mytau1.Eta())>2.1 || fabs(mytau2.Eta()>2.1)) continue; // L770

            weight2=weight2*sf_trg;
            if (sample=="data_obs") {aweight=1.0; weight2=1.0;}
	    
	    // Additional selections
	    bool selection =true;

	    //************************* Fill histograms **********************
	    
            TLorentzVector Higgs = mytau1+mytau2+mymet;
	    float HpT = mytau1.Pt()+mytau2.Pt()+mymet.Pt();
	    /*if (sample!="data_obs") {
	      cout << endl << input.c_str() << endl;
	      cout << "amcatNLO_weight : " << amcatNLO_weight << endl;	
	      cout << "aweight         : " << aweight << endl;
	      cout << "correction      : " << correction << endl;
	      }*/
	    
	    float var = Higgs.Pt(); //Variable to plot
	    if (selection){
	      if (signalRegion && charge1*charge2<0) 
		h0_OS[k]->Fill(var,weight2*aweight);
	      if (signalRegion && charge1*charge2>0)
		h0_SS[k]->Fill(var,weight2*aweight);
	      if (charge1*charge2<0 && aiRegion)
		h0_AIOS[k]->Fill(var,weight2*aweight);
	      if (charge1*charge2>0 && aiRegion)
		h0_AISS[k]->Fill(var,weight2*aweight);
	    }
	}
				
    } // end of loop over events


    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();

    TString postfix="";

    TDirectory *OS =fout->mkdir("ttOS");
    TDirectory *SS =fout->mkdir("ttSS");
    TDirectory *AIOS =fout->mkdir("AIOS");
    TDirectory *AISS =fout->mkdir("AISS");

    for (int k=0; k<nbhist; ++k){

       OS->cd();
       h0_OS[k]->SetName(name.c_str()+postfix);
       h0_OS[k]->Write();
       SS->cd();
       h0_SS[k]->SetName(name.c_str()+postfix);
       h0_SS[k]->Write();
       AIOS->cd();
       h0_AIOS[k]->SetName(name.c_str()+postfix);
       h0_AIOS[k]->Write();
       AISS->cd();
       h0_AISS[k]->SetName(name.c_str()+postfix);
       h0_AISS[k]->Write();
    }
    fout->Close();
} 


