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
    float num = atof(argv[4]);
    float min = atof(argv[5]);
    float max = atof(argv[6]);
    std::string tvar = *(argv + 7);

    TFile *f_Double = new TFile(input.c_str());
    std::cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<std::endl;
    TTree* namu = (TTree*) f_Double->Get("mutau_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);
    Float_t var;
    namu->SetBranchAddress("evtwt",&evtwt);
    namu->SetBranchAddress("t1_pt",&t1_pt);
    namu->SetBranchAddress("t1_eta", &t1_eta);
    namu->SetBranchAddress("t1_phi", &t1_phi);
    namu->SetBranchAddress("t1_mass", &t1_mass);
    namu->SetBranchAddress("t1_charge", &t1_charge);
    namu->SetBranchAddress("t1_decayMode", &t1_decayMode);
    namu->SetBranchAddress("mu_pt", &mu_pt);
    namu->SetBranchAddress("mu_eta", &mu_eta);
    namu->SetBranchAddress("mu_phi", &mu_phi);
    namu->SetBranchAddress("mu_mass", &mu_mass);
    namu->SetBranchAddress("mu_charge", &mu_charge);

    namu->SetBranchAddress("j1_pt",&j1_pt);
    namu->SetBranchAddress("j1_eta", &j1_eta);
    namu->SetBranchAddress("j1_phi", &j1_phi);
    namu->SetBranchAddress("j2_pt", &j2_pt);
    namu->SetBranchAddress("j2_eta", &j2_eta);
    namu->SetBranchAddress("j2_phi", &j2_phi);

    namu->SetBranchAddress("b1_pt",&b1_pt);
    namu->SetBranchAddress("b1_eta", &b1_eta);
    namu->SetBranchAddress("b1_phi", &b1_phi);
    namu->SetBranchAddress("b2_pt", &b2_pt);
    namu->SetBranchAddress("b2_eta", &b2_eta);
    namu->SetBranchAddress("b2_phi", &b2_phi);
    namu->SetBranchAddress("nbjets", &nbjets);

    namu->SetBranchAddress("met",&met);
    namu->SetBranchAddress("metphi",&metphi);
    namu->SetBranchAddress("mjj",&mjj);
    
    namu->SetBranchAddress("njets", &njets);
    namu->SetBranchAddress("numGenJets",&numGenJets);

    namu->SetBranchAddress("pt_sv", &pt_sv);
    namu->SetBranchAddress("m_sv",&m_sv);
    namu->SetBranchAddress("Dbkg_VBF",&Dbkg_VBF);
    namu->SetBranchAddress("Dbkg_ggH",&Dbkg_ggH);
    
    namu->SetBranchAddress("Phi"         , &Phi);
    namu->SetBranchAddress("Phi1"        , &Phi1);
    namu->SetBranchAddress("costheta1"   , &costheta1);
    namu->SetBranchAddress("costheta2"   , &costheta2);
    namu->SetBranchAddress("costhetastar", &costhetastar);
    namu->SetBranchAddress("Q2V1"        , &Q2V1);
    namu->SetBranchAddress("Q2V2"        , &Q2V2);

    namu->SetBranchAddress("ME_sm_VBF"   , &ME_sm_VBF);
    namu->SetBranchAddress("ME_sm_ggH"   , &ME_sm_ggH);
    namu->SetBranchAddress("ME_bkg"   , &ME_bkg);

    namu->SetBranchAddress("higgs_pT",      &higgs_pT);
    namu->SetBranchAddress("higgs_m",       &higgs_m);
    namu->SetBranchAddress("hjj_pT",        &hjj_pT);
    namu->SetBranchAddress("hjj_m",         &hjj_m);
    namu->SetBranchAddress("dEtajj",        &dEtajj);
    namu->SetBranchAddress("dPhijj",        &dPhijj);
    namu->SetBranchAddress("cat_0jet",      &cat_0jet);
    namu->SetBranchAddress("cat_boosted",   &cat_boosted);
    namu->SetBranchAddress("cat_vbf",       &cat_vbf);
    namu->SetBranchAddress("cat_inclusive", &cat_inclusive);
    namu->SetBranchAddress("is_signal",     &is_signal);
    namu->SetBranchAddress("is_qcd",        &is_qcd);
    namu->SetBranchAddress("mt",            &mt);

    // Reset branch address if it is exist branch
    TBranch* br = namu->GetBranch(tvar.c_str());
    if (br) namu->SetBranchAddress(tvar.c_str(), &var);

    TH1F *h_sig = new TH1F("","",num,min,max);
    TH1F *h_ss = new TH1F("","",num,min,max);
    TH1F *h_qcd = new TH1F("","",num,min,max);
    
    // Loop over all events
    Int_t nentries_wtn = (Int_t) namu->GetEntries();
    for (Int_t i = 0; i < nentries_wtn; i++) {
      namu->GetEntry(i);
      if (i % 1000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
      fflush(stdout);
      // book the NN                                                                                                        
      TMVAClassification_TMlpANN* t = new TMVAClassification_TMlpANN();
      double my_NN = t->Value(0, Phi, Phi1, costheta1, costheta2, costhetastar, Q2V1, Q2V2);      

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
      //else if (cat_vbf) is_VBF=true; 
      //else is_boosted=true;   
      if(tvar == "MELA") {
	//float normMELAvbf = ME_sm_VBF/(ME_sm_VBF+45*ME_bkg); 
	var = ME_sm_VBF/(ME_sm_VBF+45*ME_bkg);   
      }
      if (mt<50 && t1_charge*mu_charge<0) {
	// ################### signalRegion && OS ####################
	if (is_VBF && is_signal) 	    h_sig->Fill(var,evtwt); 
      }
      
      if (mt<50 && t1_charge*mu_charge>0) {
	// ################### signalRegion && SS ####################
	if (is_VBF && is_signal) 	    h_ss->Fill(var,evtwt);
	// ################### QCDRegion && SS ####################
	if (is_VBF && is_qcd) 	    h_qcd->Fill(var,evtwt);
      }
    }
    
    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();
    TDirectory *OSvbf_tt =fout->mkdir("mt_vbf");
    TDirectory *SSvbf =fout->mkdir("SSvbf");
    TDirectory *QCDvbf =fout->mkdir("QCDvbf");

    OSvbf_tt->cd();
    h_sig->SetName(name.c_str());
    h_sig->Write();
    
    SSvbf->cd();
    h_ss->SetName(name.c_str());
    h_ss->Write();
    
    QCDvbf->cd();
    h_qcd->SetName(name.c_str());
    h_qcd->Write();

    fout->Close();
} 


