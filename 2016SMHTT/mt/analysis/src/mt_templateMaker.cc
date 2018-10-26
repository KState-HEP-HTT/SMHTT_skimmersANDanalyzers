#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <typeinfo>
// ROOT
#include <TH2.h>
#include <TF1.h>
#include <TDirectoryFile.h>
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
// my includes
#include "../include/myHelper.h"
#include "../include/tr_Tree.h"
#include "../include/TMVAClassification_TMlpANN.cxx"

int main(int argc, char** argv) {    
    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string name = *(argv + 3);
    std::string shape = *(argv + 4);

    TFile *f_Double = new TFile(input.c_str());
    std::cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<std::endl;
    TTree* arbre = (TTree*) f_Double->Get("mutau_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);

    arbre->SetBranchAddress("evtwt",&evtwt);

    arbre->SetBranchAddress("t1_pt",&t1_pt);
    arbre->SetBranchAddress("t1_eta", &t1_eta);
    arbre->SetBranchAddress("t1_phi", &t1_phi);
    arbre->SetBranchAddress("t1_mass", &t1_mass);
    arbre->SetBranchAddress("t1_charge", &t1_charge);
    arbre->SetBranchAddress("t1_decayMode", &t1_decayMode);
    arbre->SetBranchAddress("mu_pt", &mu_pt);
    arbre->SetBranchAddress("mu_eta", &mu_eta);
    arbre->SetBranchAddress("mu_phi", &mu_phi);
    arbre->SetBranchAddress("mu_mass", &mu_mass);
    arbre->SetBranchAddress("mu_charge", &mu_charge);

    arbre->SetBranchAddress("j1_pt",&j1_pt);
    arbre->SetBranchAddress("j1_eta", &j1_eta);
    arbre->SetBranchAddress("j1_phi", &j1_phi);
    arbre->SetBranchAddress("j2_pt", &j2_pt);
    arbre->SetBranchAddress("j2_eta", &j2_eta);
    arbre->SetBranchAddress("j2_phi", &j2_phi);

    arbre->SetBranchAddress("b1_pt",&b1_pt);
    arbre->SetBranchAddress("b1_eta", &b1_eta);
    arbre->SetBranchAddress("b1_phi", &b1_phi);
    arbre->SetBranchAddress("b2_pt", &b2_pt);
    arbre->SetBranchAddress("b2_eta", &b2_eta);
    arbre->SetBranchAddress("b2_phi", &b2_phi);
    arbre->SetBranchAddress("nbjets", &nbjets);

    arbre->SetBranchAddress("met",&met);
    arbre->SetBranchAddress("metphi",&metphi);
    arbre->SetBranchAddress("mjj",&mjj);
    
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("numGenJets",&numGenJets);

    arbre->SetBranchAddress("pt_sv", &pt_sv);
    arbre->SetBranchAddress("m_sv",&m_sv);
    arbre->SetBranchAddress("Dbkg_VBF",&Dbkg_VBF);
    arbre->SetBranchAddress("Dbkg_ggH",&Dbkg_ggH);
    
    arbre->SetBranchAddress("Phi"         , &Phi);
    arbre->SetBranchAddress("Phi1"        , &Phi1);
    arbre->SetBranchAddress("costheta1"   , &costheta1);
    arbre->SetBranchAddress("costheta2"   , &costheta2);
    arbre->SetBranchAddress("costhetastar", &costhetastar);
    arbre->SetBranchAddress("Q2V1"        , &Q2V1);
    arbre->SetBranchAddress("Q2V2"        , &Q2V2);

    arbre->SetBranchAddress("ME_sm_VBF"   , &ME_sm_VBF);
    arbre->SetBranchAddress("ME_sm_ggH"   , &ME_sm_ggH);
    arbre->SetBranchAddress("ME_bkg"   , &ME_bkg);

    arbre->SetBranchAddress("higgs_pT",      &higgs_pT);
    arbre->SetBranchAddress("higgs_m",       &higgs_m);
    arbre->SetBranchAddress("hjj_pT",        &hjj_pT);
    arbre->SetBranchAddress("hjj_m",         &hjj_m);
    arbre->SetBranchAddress("dEtajj",        &dEtajj);
    arbre->SetBranchAddress("dPhijj",        &dPhijj);
    arbre->SetBranchAddress("cat_0jet",      &cat_0jet);
    arbre->SetBranchAddress("cat_boosted",   &cat_boosted);
    arbre->SetBranchAddress("cat_vbf",       &cat_vbf);
    arbre->SetBranchAddress("cat_inclusive", &cat_inclusive);

    arbre->SetBranchAddress("is_signal",     &is_signal);
    arbre->SetBranchAddress("is_qcd",        &is_qcd);
    arbre->SetBranchAddress("mt",            &mt);

    //Binning for 0jet cat, x-axis
    float bins0X[] = {0,1,10,11};
    //Binning for 0jet cat, y-axis
    float bins0Y[] = {0,60,65,70,75,80,85,90,95,100,105,110,400};
    //Binning for 1jet cat, x-axis
    float bins1X[] = {0,100,150,200,250,300,5000};
    //Binning for 1jet cat, y-axis
    float bins1Y[] = {0,80,90,100,110,120,130,140,150,160,300};
    //Binning for 2jet cat, x-axis
    float bins2X[] = {300,700,1100,1500,10000};
    //Binning for 2jet cat, y-axis
    float bins2Y[] = {0,95,115,135,155,400};

    int  binnum0X = sizeof(bins0X)/sizeof(Float_t) - 1;
    int  binnum0Y = sizeof(bins0Y)/sizeof(Float_t) - 1;
    int  binnum1X = sizeof(bins1X)/sizeof(Float_t) - 1;
    int  binnum1Y = sizeof(bins1Y)/sizeof(Float_t) - 1;
    int  binnum2X = sizeof(bins2X)/sizeof(Float_t) - 1;
    int  binnum2Y = sizeof(bins2Y)/sizeof(Float_t) - 1;

    std::vector<TH2F*> h0_OS;
    std::vector<TH2F*> h0_SS;
    std::vector<TH2F*> h0_QCD;
    std::vector<TH2F*> h1_OS;
    std::vector<TH2F*> h1_SS;
    std::vector<TH2F*> h1_QCD;
    std::vector<TH2F*> h2_OS;
    std::vector<TH2F*> h2_SS;
    std::vector<TH2F*> h2_QCD;

    TString postfix = "";//postfixMaps(shape);

    //binnum2X,bins2X,binnum2Y,bins2Y
    int nbhist=1;
    for (int k=0; k<nbhist; ++k){
      std::ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
      std::ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
      std::ostringstream HNS2OS; HNS2OS << "h2_OS" << k;
      h0_OS.push_back(new TH2F (HNS0OS.str().c_str(),"",binnum0X,bins0X,binnum0Y,bins0Y)); h0_OS[k]->Sumw2();
      h1_OS.push_back(new TH2F (HNS1OS.str().c_str(),"",binnum1X,bins1X,binnum1Y,bins1Y)); h1_OS[k]->Sumw2();
      h2_OS.push_back(new TH2F (HNS2OS.str().c_str(),"",binnum2X,bins2X,binnum2Y,bins2Y)); h2_OS[k]->Sumw2();
      
      std::ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
      std::ostringstream HNS1SS; HNS1OS << "h1_SS" << k;
      std::ostringstream HNS2SS; HNS2OS << "h2_SS" << k;
      h0_SS.push_back(new TH2F (HNS0SS.str().c_str(),"",binnum0X,bins0X,binnum0Y,bins0Y)); h0_SS[k]->Sumw2();
      h1_SS.push_back(new TH2F (HNS1SS.str().c_str(),"",binnum1X,bins1X,binnum1Y,bins1Y)); h1_SS[k]->Sumw2();
      h2_SS.push_back(new TH2F (HNS2SS.str().c_str(),"",binnum2X,bins2X,binnum2Y,bins2Y)); h2_SS[k]->Sumw2();
      
      std::ostringstream HNS0QCD; HNS0QCD << "h0_QCD" << k;
      std::ostringstream HNS1QCD; HNS1QCD << "h1_QCD" << k;
      std::ostringstream HNS2QCD; HNS2QCD << "h2_QCD" << k;
      h0_QCD.push_back(new TH2F (HNS0QCD.str().c_str(),"",binnum0X,bins0X,binnum0Y,bins0Y)); h0_QCD[k]->Sumw2();
      h1_QCD.push_back(new TH2F (HNS1QCD.str().c_str(),"",binnum1X,bins1X,binnum1Y,bins1Y)); h1_QCD[k]->Sumw2();
      h2_QCD.push_back(new TH2F (HNS2QCD.str().c_str(),"",binnum2X,bins2X,binnum2Y,bins2Y)); h2_QCD[k]->Sumw2();
    }
    
    // Loop over all events
    Int_t nentries_wtn = (Int_t) arbre->GetEntries();
    for (Int_t i = 0; i < nentries_wtn; i++) {
      arbre->GetEntry(i);
      if (i % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
      fflush(stdout);
      // book the NN                                                                                                        
      TMVAClassification_TMlpANN* t = new TMVAClassification_TMlpANN();
      double my_NN = t->Value(0, Phi, Phi1, costheta1, costheta2, costhetastar, Q2V1, Q2V2);      
      float normMELAvbf = ME_sm_VBF/(ME_sm_VBF+45*ME_bkg);

      // Categories                                                                                                                                                                                       
      bool is_0jet = false;
      bool is_boosted = false;
      bool is_VBF = false;
      //////////////////////////// 
      // 2016 analysis category //
      ////////////////////////////
      if (njets==0) is_0jet=true;
      if (njets==1 || (njets>=2 && (mjj<=300 || pt_sv<=50 || t1_pt<=40))) is_boosted=true;
      if (njets>=2 && mjj>300 && pt_sv>50 && t1_pt>40) is_VBF=true;

      ////////////////////////
      // KSU study category //
      ////////////////////////
      //if (njets==0) is_0jet=true;
      //else if (njets>=2) is_VBF=true; 
      //else is_boosted=true;   

      float var_0jetX = t1_decayMode;
      float var_0jetY = m_sv;
      float var_boostedX = pt_sv;
      float var_boostedY = m_sv;
      float var_vbfX = mjj;
      float var_vbfY = m_sv;

      for (int k=0; k<nbhist; ++k){
	if (mt<50 && t1_charge*mu_charge<0) {
	  // ################### signalRegion && OS ####################
	  if (is_0jet && is_signal)         h0_OS[k]->Fill(var_0jetX,var_0jetY,evtwt);
	  if (is_boosted && is_signal)	    h1_OS[k]->Fill(var_boostedX,var_boostedY,evtwt);
	  if (is_VBF && is_signal) 	    h2_OS[k]->Fill(var_vbfX,var_vbfY,evtwt);	  
	}

	if (mt<50 && t1_charge*mu_charge>0) {
	  // ################### signalRegion && SS ####################
	  if (is_0jet && is_signal)         h0_SS[k]->Fill(var_0jetX,var_0jetY,evtwt);
	  if (is_boosted && is_signal)	    h1_SS[k]->Fill(var_boostedX,var_boostedY,evtwt);
	  if (is_VBF && is_signal) 	    h2_SS[k]->Fill(var_vbfX,var_vbfY,evtwt);	  
	  // ################### QCDRegion && SS ####################
	  if (is_0jet && is_qcd)            h0_QCD[k]->Fill(var_0jetX,var_0jetY,evtwt);
	  if (is_boosted && is_qcd)	    h1_QCD[k]->Fill(var_boostedX,var_boostedY,evtwt);
	  if (is_VBF && is_qcd) 	    h2_QCD[k]->Fill(var_vbfX,var_vbfY,evtwt);	  
	}
      }
    } // end of loop over events
    
    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    TDirectory *OS0jet_tt =fout->mkdir("mt_0jet");
    TDirectory *OSboosted_tt =fout->mkdir("mt_boosted");
    TDirectory *OSvbf_tt =fout->mkdir("mt_vbf");

    TDirectory *SS0jet =fout->mkdir("SS0jet");
    TDirectory *SSboosted =fout->mkdir("SS1jet");
    TDirectory *SSvbf =fout->mkdir("SSvbf");
    
    TDirectory *QCD0jet =fout->mkdir("QCD0jet");
    TDirectory *QCDboosted =fout->mkdir("QCD1jet");
    TDirectory *QCDvbf =fout->mkdir("QCDvbf");

    for (int k=0; k<nbhist; ++k){
      OS0jet_tt->cd();
      h0_OS[k]->SetName(name.c_str()+postfix);
      h0_OS[k]->Write();
      OSboosted_tt->cd();
      h1_OS[k]->SetName(name.c_str()+postfix);
      h1_OS[k]->Write();
      OSvbf_tt->cd();
      h2_OS[k]->SetName(name.c_str()+postfix);
      h2_OS[k]->Write();        
      
      SS0jet->cd();
      h0_SS[k]->SetName(name.c_str()+postfix);
      h0_SS[k]->Write();
      SSboosted->cd();
      h1_SS[k]->SetName(name.c_str()+postfix);
      h1_SS[k]->Write();
      SSvbf->cd();
      h2_SS[k]->SetName(name.c_str()+postfix);
      h2_SS[k]->Write();
      
      QCD0jet->cd();
      h0_QCD[k]->SetName(name.c_str()+postfix);
      h0_QCD[k]->Write();
      QCDboosted->cd();
      h1_QCD[k]->SetName(name.c_str()+postfix);
      h1_QCD[k]->Write();
      QCDvbf->cd();
      h2_QCD[k]->SetName(name.c_str()+postfix);
      h2_QCD[k]->Write();
    }
    fout->Close();
} 


