
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

//FF
#include "../../../../../HTTutilities/Jet2TauFakes/interface/FakeFactor.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/WrapperTGraph.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/WrapperTH2F.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/WrapperTH3D.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/WrapperTFormula.h"
#include "../../../../../HTTutilities/Jet2TauFakes/interface/IFunctionWrapper.h"


    ////////////////////////////////////////////////////////////////////////////////
    // The "FakeFraction_mutau_3D.root" file will be the output of the _Get_Fake_Fraction.py
    // Thus, this part is not neccessary to derive the fake fraction.
    // This part is only needed when we want to run the code, estimate jet fake background and produce final results.
    //FF
    ////////////////////////////////////////////////////////////////////////////////
    bool computeFakeFraction = true;
    TFile *FakeFraction=new TFile("FakeFraction_mutau_3D.root");
    TH3F *fakefrac_0jet=(TH3F*) FakeFraction->Get("0jet/0jet");
    TH3F *fakefrac_boosted=(TH3F*) FakeFraction->Get("boosted/boosted");
    TH3F *fakefrac_vbf=(TH3F*) FakeFraction->Get("vbf/vbf");
    
    ////////////////////////////////////////////////////////////////////////////////
    


    
    float bins_mvis_FF[] ={0,50,80,100,110,120,130,150,170,200,250,1000};
    float bins_njet_FF[] = {-0.5,0.5,1.5,15};
    

    
    int  binnum_mvis_FF = sizeof(bins_mvis_FF)/sizeof(Float_t) - 1;
    int  binnum_njet_FF = sizeof(bins_njet_FF)/sizeof(Float_t) - 1;
    

    
    //FakeFactor 0 jet  FF
    std::vector<TH1F*> h0_AI_FF;
    std::vector<TH2F*> h0_AI_FakeFraction_2D;

    //FakeFactor boosted FF
    std::vector<TH1F*> h1_AI_FF;
    std::vector<TH2F*> h1_AI_FakeFraction_2D;
    
    //FakeFactor vbf FF
    std::vector<TH1F*> h2_AI_FF;
    std::vector<TH2F*> h2_AI_FakeFraction_2D;
    
    

        //////////////////////////////////////////////////////
        // Defining the histogram for Fake fraction computation
        //////////////////////////////////////////////////////
                
        
        
        //FakeFactor  0jet FF
        ostringstream HNSh0_AI_FakeFraction_2D; HNSh0_AI_FakeFraction_2D << "h0_AI_FakeFraction_2D" << k;
        h0_AI_FakeFraction_2D.push_back(new TH2F (HNSh0_AI_FakeFraction_2D.str().c_str(),"FakeJet_0jet",binnum_mvis_FF,bins_mvis_FF,binnum_njet_FF,bins_njet_FF)); h0_AI_FakeFraction_2D[k]->Sumw2();
        
        //FakeFactor  boosted FF
        ostringstream HNSh1_AI_FakeFraction_2D; HNSh1_AI_FakeFraction_2D << "h1_AI_FakeFraction_2D" << k;
        h1_AI_FakeFraction_2D.push_back(new TH2F (HNSh1_AI_FakeFraction_2D.str().c_str(),"FakeJet_boosted",binnum_mvis_FF,bins_mvis_FF,binnum_njet_FF,bins_njet_FF)); h1_AI_FakeFraction_2D[k]->Sumw2();
        
        //FakeFactor  vbf FF
        ostringstream HNSh2_AI_FakeFraction_2D; HNSh2_AI_FakeFraction_2D << "h2_AI_FakeFraction_2D" << k;
        h2_AI_FakeFraction_2D.push_back(new TH2F (HNSh2_AI_FakeFraction_2D.str().c_str(),"FakeJet_vbf",binnum_mvis_FF,bins_mvis_FF,binnum_njet_FF,bins_njet_FF)); h2_AI_FakeFraction_2D[k]->Sumw2();


        //////////////////////////////////////////////////////
        // Defining the histogram for Fake background estimation
        //////////////////////////////////////////////////////
        
        
        //FakeFactor  0jet FF
        ostringstream HNSh0_AI_FF; HNSh0_AI_FF << "h0_AI_FF" << k;
        h0_AI_FF.push_back(new TH1F (HNSh0_AI_FF.str().c_str(),"FakeJet_0jet",binnum_mjj,bins_mjj)); h0_AI_FF[k]->Sumw2();
    
        //FakeFactor  boosted FF
        ostringstream HNSh1_AI_FF; HNSh1_AI_FF << "h1_AI_FF" << k;
        h1_AI_FF.push_back(new TH1F (HNSh1_AI_FF.str().c_str(),"FakeJet_boosted",binnum_mjj,bins_mjj)); h1_AI_FF[k]->Sumw2();
        
        //FakeFactor  vbf FF
        ostringstream HNSh2_AI_FF; HNSh2_AI_FF << "h2_AI_FF" << k;
        h2_AI_FF.push_back(new TH1F (HNSh2_AI_FF.str().c_str(),"FakeJet_vbf",binnum_mjj,bins_mjj)); h2_AI_FF[k]->Sumw2();

    }
    


    
    //###############################################################
    // Adding the Fake Factor
    //###############################################################


   TFile* ff_file_0jet = TFile::Open("../../../../../HTTutilities/Jet2TauFakes/data/mt/0Jet/fakeFactors_20180831_tight.root");
   FakeFactor* fakeFactorCmb = (FakeFactor*)ff_file_0jet->Get("ff_comb");
    
   std::vector<double> inputs(9);
    
   std::string FFsys[31]={"","ff_qcd_syst_up","ff_qcd_syst_down","ff_qcd_dm0_njet0_stat_up","ff_qcd_dm0_njet0_stat_down","ff_qcd_dm0_njet1_stat_up","ff_qcd_dm0_njet1_stat_down","ff_qcd_dm1_njet0_stat_up","ff_qcd_dm1_njet0_stat_down","ff_qcd_dm1_njet1_stat_up","ff_qcd_dm1_njet1_stat_down","ff_w_syst_up","ff_w_syst_down","ff_w_dm0_njet0_stat_up","ff_w_dm0_njet0_stat_down","ff_w_dm0_njet1_stat_up","ff_w_dm0_njet1_stat_down","ff_w_dm1_njet0_stat_up","ff_w_dm1_njet0_stat_down","ff_w_dm1_njet1_stat_up","ff_w_dm1_njet1_stat_down","ff_tt_syst_up","ff_tt_syst_down","ff_tt_dm0_njet0_stat_up","ff_tt_dm0_njet0_stat_down","ff_tt_dm0_njet1_stat_up","ff_tt_dm0_njet1_stat_down","ff_tt_dm1_njet0_stat_up","ff_tt_dm1_njet0_stat_down","ff_tt_dm1_njet1_stat_up","ff_tt_dm1_njet1_stat_down"};
  TString postfixFF[31]={"","_norm_ff_qcd_mt_systUp","_norm_ff_qcd_mt_systDown","_norm_ff_qcd_dm0_njet0_mt_statUp","_norm_ff_qcd_dm0_njet0_mt_statDown","_norm_ff_qcd_dm0_njet1_mt_statUp","_norm_ff_qcd_dm0_njet1_mt_statDown","_norm_ff_qcd_dm1_njet0_mt_statUp","_norm_ff_qcd_dm1_njet0_mt_statDown","_norm_ff_qcd_dm1_njet1_mt_statUp","_norm_ff_qcd_dm1_njet1_mt_statDown","_norm_ff_w_mt_systUp","_norm_ff_w_mt_systDown","_norm_ff_w_dm0_njet0_mt_statUp","_norm_ff_w_dm0_njet0_mt_statDown","_norm_ff_w_dm0_njet1_mt_statUp","_norm_ff_w_dm0_njet1_mt_statDown","_norm_ff_w_dm1_njet0_mt_statUp","_norm_ff_w_dm1_njet0_mt_statDown","_norm_ff_w_dm1_njet1_mt_statUp","_norm_ff_w_dm1_njet1_mt_statDown","_norm_ff_tt_mt_systUp","_norm_ff_tt_mt_systDown","_norm_ff_tt_dm0_njet0_mt_statUp","_norm_ff_tt_dm0_njet0_mt_statDown","_norm_ff_tt_dm0_njet1_mt_statUp","_norm_ff_tt_dm0_njet1_mt_statDown","_norm_ff_tt_dm1_njet0_mt_statUp","_norm_ff_tt_dm1_njet0_mt_statDown","_norm_ff_tt_dm1_njet1_mt_statUp","_norm_ff_tt_dm1_njet1_mt_statDown"};

    //###############################################################

    Int_t nentries_wtn = (Int_t) arbre->GetEntries();
    for (Int_t i = 0; i < nentries_wtn; i++) {
      arbre->GetEntry(i);
      if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
      fflush(stdout);

 
        
        float antiisoRegion=(byVLooseIsolationMVArun2v1DBoldDMwLT_2 && !byTightIsolationMVArun2v1DBoldDMwLT_2 && iso_1<0.15 && againstElectronVLooseMVA6_2 && againstMuonTight3_2);
        
 
        
//############################################################################################################
//  Variables to be used for fake fraction methods and fake factor application
//############################################################################################################

        
        // Per convention the x axis of the FakeFraction_mutau_3D.root is m_vis, the yaxis is the jetnumber and the z axis is frac_qcd, frac_w and frac_tt.
        float x_axis_var =(mymu+mytau).M();
        float y_axis_var =numberJets;
        
        // The final observable is now set to be m_sv. YOu can change it to any other 1D variable or 2D variables
        float FinalObservable=m_sv;

        
//############################################################################################################
//############################################################################################################
//  This portion is for filling a 2D histogram to estimate the fake fraction
//############################################################################################################
//############################################################################################################
//############################################################################################################

        
        
        if (computeFakeFraction){
            
            //************************* Fill histograms Fake Factor 0 jet **********************
            
            if (numberJets==0 && mt<50 && q_1*q_2<0){
                
                if (antiisoRegion ){ //anti-isolated data, and MC without jets to subtract later
                    h0_AI_FakeFraction_2D[k]->Fill(x_axis_var,y_axis_var,aweight*weight2);
                }
            }
            //************************* Fill histograms Fake Factor boosted **********************
            
            if (is_boosted && mt<50 && q_1*q_2<0){
                
                if (antiisoRegion ){ //anti-isolated data, and MC without jets to subtract later
                    h1_AI_FakeFraction_2D[k]->Fill(x_axis_var,y_axis_var,aweight*weight2);
                }
            }
            //************************* Fill histograms Fake Factor VBF **********************
            
            if (is_VBF && mt<50 && q_1*q_2<0){
                
                if (antiisoRegion ){ //anti-isolated data, and MC without jets to subtract later
                    h2_AI_FakeFraction_2D[k]->Fill(x_axis_var,y_axis_var,aweight*weight2);
                }
            }
            //***********************************************
            
        }
        
        
        //############################################################################################################
        //############################################################################################################
        //  THis portion is for filling the histograms whill help us to estimate the Jet Fake background.
        //############################################################################################################
        //############################################################################################################
        //############################################################################################################
        //********************* Compute fake factors *********************
        
        if ( ! computeFakeFraction){
            
            inputs[0] = mytau.Pt();
            inputs[1] = l2_decayMode;
            inputs[2] = numberJets;
            inputs[3] = (mymu+mytau).M();
            inputs[4] = mt;
            inputs[5] = iso_1;
            // Just dommy numbers
            //        inputs[6] = frac_qcd;
            //        inputs[7] = frac_w;
            //        inputs[8] = frac_tt;
            inputs[6] = 0.30;
            inputs[7] = 0.50;
            inputs[8] = 0.05;
            
            
            if (is_0jet){
                inputs[6] = fakefrac_0jet->GetBinContent(fakefrac_0jet->GetXaxis()->FindBin(x_axis_var), fakefrac_0jet->GetYaxis()->FindBin(y_axis_var),1);
                inputs[7] = fakefrac_0jet->GetBinContent(fakefrac_0jet->GetXaxis()->FindBin(x_axis_var), fakefrac_0jet->GetYaxis()->FindBin(y_axis_var),2);
                inputs[8] = fakefrac_0jet->GetBinContent(fakefrac_0jet->GetXaxis()->FindBin(x_axis_var), fakefrac_0jet->GetYaxis()->FindBin(y_axis_var),3);
            }
            
            if (is_boosted){
                inputs[6] = fakefrac_boosted->GetBinContent(fakefrac_boosted->GetXaxis()->FindBin(x_axis_var), fakefrac_boosted->GetYaxis()->FindBin(y_axis_var),1);
                inputs[7] = fakefrac_boosted->GetBinContent(fakefrac_boosted->GetXaxis()->FindBin(x_axis_var), fakefrac_boosted->GetYaxis()->FindBin(y_axis_var),2);
                inputs[8] = fakefrac_boosted->GetBinContent(fakefrac_boosted->GetXaxis()->FindBin(x_axis_var), fakefrac_boosted->GetYaxis()->FindBin(y_axis_var),3);
            }
            
            
            if (is_VBF){
                inputs[6] = fakefrac_vbf->GetBinContent(fakefrac_vbf->GetXaxis()->FindBin(x_axis_var), fakefrac_vbf->GetYaxis()->FindBin(y_axis_var),1);
                inputs[7] = fakefrac_vbf->GetBinContent(fakefrac_vbf->GetXaxis()->FindBin(x_axis_var), fakefrac_vbf->GetYaxis()->FindBin(y_axis_var),2);
                inputs[8] = fakefrac_vbf->GetBinContent(fakefrac_vbf->GetXaxis()->FindBin(x_axis_var), fakefrac_vbf->GetYaxis()->FindBin(y_axis_var),3);
            }
            
            
            //*********************  fake factors weight *********************
            double FF_weight=fakeFactorCmb->value(inputs);
            
            //************************* Fill histograms Fake Factor 0 jet **********************
            
            if (numberJets==0 && mt<50 && q_1*q_2<0){
                
                if (antiisoRegion ){ //anti-isolated data, and MC without jets to subtract later
                    //                for (int k=l;k<l+nbhistFF;++k){ // To get also the systematics
                    h0_AI_FF[k]->Fill(FinalObservable,aweight*weight2*FF_weight);
                    //            }
                }
            }
            //************************* Fill histograms Fake Factor boosted **********************
            
            if (is_boosted && mt<50 && q_1*q_2<0){
                
                if (antiisoRegion ){ //anti-isolated data, and MC without jets to subtract later
                    //                for (int k=l;k<l+nbhistFF;++k){ // To get also the systematics
                    h1_AI_FF[k]->Fill(FinalObservable,aweight*weight2*FF_weight);
                    //                }
                }
            }
            //************************* Fill histograms Fake Factor VBF **********************
            
            if (is_VBF && mt<50 && q_1*q_2<0){
                
                if (antiisoRegion ){ //anti-isolated data, and MC without jets to subtract later
                    //                for (int k=l;k<l+nbhistFF;++k){ // To get also the systematics
                    h2_AI_FF[k]->Fill(FinalObservable,aweight*weight2*FF_weight);
                    //                }
                }
            }
        }
        
//############################################################################################################
//############################################################################################################
//############################################################################################################
//############################################################################################################
//############################################################################################################
 
    
    //TDirectories for Fake Factor method
    TDirectory *AI0jet_FF =fout->mkdir("AI0jet_FF");
    TDirectory *AIboosted_FF =fout->mkdir("AIboosted_FF");
    TDirectory *AIvbf_FF =fout->mkdir("AIvbf_FF");
    
 
        
        
        //################  FF  0jet
        AI0jet_FF->cd();
        
        if (computeFakeFraction){
            h0_AI_FakeFraction_2D[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
            h0_AI_FakeFraction_2D[k]->Write();
        }
        else{
            //        for (int l=k; l<k+nbhistFF;++l){
            h0_AI_FF[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
            h0_AI_FF[k]->Write();
            //        }
        }
        //################  FF  boosted
        AIboosted_FF->cd();
        
        if (computeFakeFraction){
            h1_AI_FakeFraction_2D[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
            h1_AI_FakeFraction_2D[k]->Write();
        }
        else{
            //        for (int l=k; l<k+nbhistFF;++l){
            h1_AI_FF[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
            h1_AI_FF[k]->Write();
            //        }
        }
        //################  FF  vbf
        AIvbf_FF->cd();
        
        if (computeFakeFraction){
            h2_AI_FakeFraction_2D[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
            h2_AI_FakeFraction_2D[k]->Write();
        }
        else{
            //        for (int l=k; l<k+nbhistFF;++l){
            h2_AI_FF[k]->SetName(name.c_str()+postfixJES[k]+postfixFF[k]);
            h2_AI_FF[k]->Write();
            //        }
        }
        
    }
    cout<<h0_OS[0]->Integral()<<" "<<h1_OS[0]->Integral()<<" "<<h2_OS[0]->Integral()<<" "<<h3_OS[0]->Integral()<<endl;
    fout->Close();
} 


