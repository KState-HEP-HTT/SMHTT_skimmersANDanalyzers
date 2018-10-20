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
#include "TFile.h"
// my includes
#include "../include/myHelper.h"
#include "../include/tt_Tree.h"
#include "../include/scenario_info.h"
#include "../include/TMVAClassification_TMlpANN.cxx"

int main(int argc, char** argv) {    
    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string name = *(argv + 3);
    std::string shape = *(argv + 4);

    TFile *f_Double = new TFile(input.c_str());
    std::cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<std::endl;
    TTree* arbre = (TTree*) f_Double->Get("tt_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);
    std::cout.precision(11);

    arbre->SetBranchAddress("evtwt",&evtwt);

    arbre->SetBranchAddress("t1_pt",&t1_pt);
    arbre->SetBranchAddress("t1_eta", &t1_eta);
    arbre->SetBranchAddress("t1_phi", &t1_phi);
    arbre->SetBranchAddress("t1_mass", &t1_mass);
    arbre->SetBranchAddress("t1_charge", &t1_charge);
    arbre->SetBranchAddress("t1_decaymode", &t1_decaymode);
    arbre->SetBranchAddress("t2_pt", &t2_pt);
    arbre->SetBranchAddress("t2_eta", &t2_eta);
    arbre->SetBranchAddress("t2_phi", &t2_phi);
    arbre->SetBranchAddress("t2_mass", &t2_mass);
    arbre->SetBranchAddress("t2_charge", &t2_charge);
    arbre->SetBranchAddress("t2_decaymode", &t2_decaymode);

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
    arbre->SetBranchAddress("nbtag", &nbtag);

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

    arbre->SetBranchAddress("is_signal", &is_signal);

    //Binning for 0jet cat. 1D: Msv. In AN it was 10GeV binning / official data card combined 0~50 as one bin
    float bins0[] = {0,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
    //Binning for 1jet cat, x-axis: HpT
    float bins1X[] = {0,100,170,300,10000};
    //Binning for 1jet cat, y-axis: Msv
    float bins1Y[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};
    //Binning for 2jet cat, x-axis: Mjj
    float bins2X[] = {0,300,500,800,10000};
    //Binning for 2jet cat, y-axis: Msv
    float bins2Y[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};

    int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
    int  binnum1X = sizeof(bins1X)/sizeof(Float_t) - 1;
    int  binnum1Y = sizeof(bins1Y)/sizeof(Float_t) - 1;
    int  binnum2X = sizeof(bins2X)/sizeof(Float_t) - 1;
    int  binnum2Y = sizeof(bins2Y)/sizeof(Float_t) - 1;

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

    TString postfix = postfixMaps(shape);
    std::cout << postfix << std::endl;
    //binnum2X,bins2X,binnum2Y,bins2Y
    int nbhist=1;
    for (int k=0; k<nbhist; ++k){
      std::ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
      std::ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
      std::ostringstream HNS2OS; HNS2OS << "h2_OS" << k;
      h0_OS.push_back(new TH1F (HNS0OS.str().c_str(),"",binnum0,bins0)); h0_OS[k]->Sumw2();
      h1_OS.push_back(new TH2F (HNS1OS.str().c_str(),"",binnum1X,bins1X,binnum1Y,bins1Y)); h1_OS[k]->Sumw2();
      h2_OS.push_back(new TH2F (HNS2OS.str().c_str(),"",binnum2X,bins2X,binnum2Y,bins2Y)); h2_OS[k]->Sumw2();
      
      std::ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
      std::ostringstream HNS1SS; HNS1OS << "h1_SS" << k;
      std::ostringstream HNS2SS; HNS2OS << "h2_SS" << k;
      h0_SS.push_back(new TH1F (HNS0SS.str().c_str(),"",binnum0,bins0)); h0_SS[k]->Sumw2();
      h1_SS.push_back(new TH2F (HNS1SS.str().c_str(),"",binnum1X,bins1X,binnum1Y,bins1Y)); h1_SS[k]->Sumw2();
      h2_SS.push_back(new TH2F (HNS2SS.str().c_str(),"",binnum2X,bins2X,binnum2Y,bins2Y)); h2_SS[k]->Sumw2();
      
      std::ostringstream HNS0AIOS; HNS0AIOS << "h0_AIOS" << k;
      std::ostringstream HNS1AIOS; HNS1AIOS << "h1_AIOS" << k;
      std::ostringstream HNS2AIOS; HNS2AIOS << "h2_AIOS" << k;
      h0_AIOS.push_back(new TH1F (HNS0AIOS.str().c_str(),"",binnum0,bins0)); h0_AIOS[k]->Sumw2();
      h1_AIOS.push_back(new TH2F (HNS1AIOS.str().c_str(),"",binnum1X,bins1X,binnum1Y,bins1Y)); h1_AIOS[k]->Sumw2();
      h2_AIOS.push_back(new TH2F (HNS2AIOS.str().c_str(),"",binnum2X,bins2X,binnum2Y,bins2Y)); h2_AIOS[k]->Sumw2();
        
      std::ostringstream HNS0AISS; HNS0AISS << "h0_AISS" << k;
      std::ostringstream HNS1AISS; HNS1AISS << "h1_AISS" << k;
      std::ostringstream HNS2AISS; HNS2AISS << "h2_AISS" << k;
      h0_AISS.push_back(new TH1F (HNS0AISS.str().c_str(),"",binnum0,bins0)); h0_AISS[k]->Sumw2();
      h1_AISS.push_back(new TH2F (HNS1AISS.str().c_str(),"",binnum1X,bins1X,binnum1Y,bins1Y)); h1_AISS[k]->Sumw2();
      h2_AISS.push_back(new TH2F (HNS2AISS.str().c_str(),"",binnum2X,bins2X,binnum2Y,bins2Y)); h2_AISS[k]->Sumw2();
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
      if (njets==1 || (njets>=2 && (!(higgs_pT>100 && dEtajj>2.5)))) is_boosted=true;
      if (njets>=2 && higgs_pT>100 && dEtajj>2.5) is_VBF=true;

      ////////////////////////     
      // KSU study category //     
      ////////////////////////     
      //if (njets==0) is_0jet=true;
      //else if (njets>=2 && mjj>300) is_VBF=true; 
      //else is_boosted=true;   

      float var_0jet = m_sv;
      float var_boostedX = higgs_pT;
      float var_boostedY = m_sv;
      float var_vbfX = mjj;
      float var_vbfY = m_sv;

      for (int k=0; k<nbhist; ++k){
	// ################### signalRegion && OS ####################
	if (is_0jet && is_signal && t1_charge*t2_charge<0)	    h0_OS[k]->Fill(var_0jet,evtwt);
	if (is_boosted && is_signal && t1_charge*t2_charge<0)	    h1_OS[k]->Fill(var_boostedX,var_boostedY,evtwt);
	if (is_VBF && is_signal && t1_charge*t2_charge<0) 	    h2_OS[k]->Fill(var_vbfX,var_vbfY,evtwt);
	// ################### signalRegion && SS ####################
	if (is_0jet && is_signal && t1_charge*t2_charge>0)          h0_SS[k]->Fill(var_0jet,evtwt);
	if (is_boosted && is_signal && t1_charge*t2_charge>0)	    h1_SS[k]->Fill(var_boostedX,var_boostedY,evtwt);
	if (is_VBF && is_signal && t1_charge*t2_charge>0) 	    h2_SS[k]->Fill(var_vbfX,var_vbfY,evtwt);
	// ################### ai-Region && OS ####################
	if (is_0jet && t1_charge*t2_charge<0 && !is_signal)         	    h0_AIOS[k]->Fill(var_0jet,evtwt);
	if (is_boosted && t1_charge*t2_charge<0 && !is_signal)	    h1_AIOS[k]->Fill(var_boostedX,var_boostedY,evtwt);
	if (is_VBF && t1_charge*t2_charge<0 && !is_signal)         	    h2_AIOS[k]->Fill(var_vbfX,var_vbfY,evtwt);
	// ################### ai-Region && SS ####################
	if (is_0jet && t1_charge*t2_charge>0 && !is_signal)              h0_AISS[k]->Fill(var_0jet,evtwt);
	if (is_boosted && t1_charge*t2_charge>0 && !is_signal)	    h1_AISS[k]->Fill(var_boostedX,var_boostedY,evtwt);
	if (is_VBF && t1_charge*t2_charge>0 && !is_signal)         	    h2_AISS[k]->Fill(var_vbfX,var_vbfY,evtwt);
      }
    } // end of loop over events
    
    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    TDirectory *OS0jet_tt =fout->mkdir("tt_0jet");
    TDirectory *OSboosted_tt =fout->mkdir("tt_boosted");
    TDirectory *OSvbf_tt =fout->mkdir("tt_vbf");

    TDirectory *SS0jet =fout->mkdir("ttSS_0jet");
    TDirectory *SSboosted =fout->mkdir("ttSS_boosted");
    TDirectory *SSvbf =fout->mkdir("ttSS_vbf");
    
    TDirectory *AIOS0jet =fout->mkdir("AIOS_0jet");
    TDirectory *AIOSboosted =fout->mkdir("AIOS_boosted");
    TDirectory *AIOSvbf =fout->mkdir("AIOS_vbf");
    
    TDirectory *AISS0jet =fout->mkdir("AISS_0jet");
    TDirectory *AISSboosted =fout->mkdir("AISS_boosted");
    TDirectory *AISSvbf =fout->mkdir("AISS_vbf");

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
      
      AIOS0jet->cd();
      h0_AIOS[k]->SetName(name.c_str()+postfix);
      h0_AIOS[k]->Write();
      AIOSboosted->cd();
      h1_AIOS[k]->SetName(name.c_str()+postfix);
      h1_AIOS[k]->Write();
      AIOSvbf->cd();
      h2_AIOS[k]->SetName(name.c_str()+postfix);
      h2_AIOS[k]->Write();
      
      AISS0jet->cd();
      h0_AISS[k]->SetName(name.c_str()+postfix);
      h0_AISS[k]->Write();
      AISSboosted->cd();
      h1_AISS[k]->SetName(name.c_str()+postfix);
      h1_AISS[k]->Write();
      AISSvbf->cd();
      h2_AISS[k]->SetName(name.c_str()+postfix);
      h2_AISS[k]->Write();
      
    }
    fout->Close();
} 


