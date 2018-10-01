#include <map>

class scenario_info {
 private:
  Float_t jpt_1, jpt_2, mjj;
  Int_t njets;
  Float_t met, metphi;
  Float_t m_sv, pt_sv;
  Float_t ME_sm_VBF, ME_sm_ggH, ME_bkg;
 public:
  scenario_info (TTree*, std::string);
  virtual ~scenario_info () {};

  Float_t get_jpt_1()      { return jpt_1;     };
  Float_t get_jpt_2()      { return jpt_2;     };
  Float_t get_mjj()        { return mjj;       };
  Int_t   get_njets()      { return njets;     };
  Float_t get_met()        { return met;       };
  Float_t get_metphi()     { return metphi;    };
  Float_t get_m_sv()       { return m_sv;      };
  Float_t get_pt_sv()      { return pt_sv;     };  
  Float_t get_ME_sm_VBF()  { return ME_sm_VBF; }; 
  Float_t get_ME_sm_ggH()  { return ME_sm_ggH; }; 
  Float_t get_ME_bkg()     { return ME_bkg;    }; 
};


// read branches from arbre
scenario_info::scenario_info(TTree* arbre, std::string unc) {
  // set nominal as a defalt
  std::string jpt_1_unc = "jpt_1";
  std::string jpt_2_unc = "jpt_2";
  std::string mjj_unc = "mjj";
  std::string njets_unc = "njets";
  std::string met_unc = "met";
  std::string metphi_unc = "metphi";
  std::string m_sv_unc = "m_sv";
  std::string pt_sv_unc = "pt_sv";
  std::string ME_sm_VBF_unc = "ME_sm_VBF";
  std::string ME_sm_ggH_unc = "ME_sm_ggH";
  std::string ME_bkg_unc = "ME_bkg";

  std::cout << "-------------- " << unc << " --------------" << std::endl;

  // if branches for unc is availble, replace to them
  if (unc=="nominal") unc = "";
  else unc = "_"+unc;
  TIter next(arbre->GetListOfBranches());
  TBranch *branch;
  while ((branch = (TBranch*)next())) {
    if ((jpt_1_unc+unc)==branch->GetName())              jpt_1_unc=branch->GetName();
    else if ((jpt_2_unc+unc)==branch->GetName())              jpt_2_unc=branch->GetName();
    else if ((mjj_unc+unc)==branch->GetName())                mjj_unc=branch->GetName();
    else if ((njets_unc+unc)==branch->GetName())              njets_unc=branch->GetName();
    else if ((met_unc+unc)==branch->GetName())                met_unc=branch->GetName();
    else if ((metphi_unc+unc)==branch->GetName())             metphi_unc=branch->GetName();
    else if ((m_sv_unc+unc)==branch->GetName())               m_sv_unc=branch->GetName();
    else if ((pt_sv_unc+unc)==branch->GetName())              pt_sv_unc=branch->GetName();
    else if ((ME_sm_VBF_unc+unc)==branch->GetName())          ME_sm_VBF_unc=branch->GetName();
    else if ((ME_sm_ggH_unc+unc)==branch->GetName())          ME_sm_ggH_unc=branch->GetName();
    else if ((ME_bkg_unc+unc)==branch->GetName())             ME_bkg_unc=branch->GetName();
    
    // This is tmporary fixing. Need to be fixed at skimming level.
    if (unc == "_JESUp" || unc == "_JESDown") {
      met_unc = "met";
      metphi_unc = "metphi";
    }
  }

  // print used tau and jet kinematics
  std::cout << jpt_1_unc << std::endl;
  std::cout << jpt_2_unc << std::endl;
  std::cout << mjj_unc << std::endl;
  std::cout << njets_unc << std::endl;
  std::cout << met_unc << std::endl;
  std::cout << metphi_unc << std::endl;
  std::cout << m_sv_unc << std::endl;
  std::cout << pt_sv_unc << std::endl;
  std::cout << ME_sm_VBF_unc << std::endl;
  std::cout << ME_sm_ggH_unc << std::endl;
  std::cout << ME_bkg_unc << std::endl;

  std::cout << "-------------- used branches --------------" << std::endl << std::endl;

  // pick up printed branches
  arbre -> SetBranchAddress( jpt_1_unc.c_str()        , &jpt_1      );
  arbre -> SetBranchAddress( jpt_2_unc.c_str()        , &jpt_2      );
  arbre -> SetBranchAddress( mjj_unc.c_str()          , &mjj        );
  arbre -> SetBranchAddress( njets_unc.c_str()        , &njets      );
  arbre -> SetBranchAddress( met_unc.c_str()          , &met        );
  arbre -> SetBranchAddress( metphi_unc.c_str()       , &metphi     );
  arbre -> SetBranchAddress( m_sv_unc.c_str()         , &m_sv       );
  arbre -> SetBranchAddress( pt_sv_unc.c_str()        , &pt_sv      );
  arbre -> SetBranchAddress( ME_sm_VBF_unc.c_str()    , &ME_sm_VBF  );
  arbre -> SetBranchAddress( ME_sm_ggH_unc.c_str()    , &ME_sm_ggH  );
  arbre -> SetBranchAddress( ME_bkg_unc.c_str()       , &ME_bkg     );
}

static std::map<std::string, TString> syst {
  {"dyShape_Up", "_CMS_htt_dyShape_13TeVUp"},
  {"dyShape_Down", "_CMS_htt_dyShape_13TeVDown"},
  {"jetToTauFake_Up", "_CMS_htt_jetToTauFake_13TeVUp"},
  {"jetToTauFake_Down", "_CMS_htt_jetToTauFake_13TeVDown"},
  {"ttbarShape_Up", "_CMS_htt_ttbarShape_13TeVUp"},
  {"ttbarShape_Down", "_CMS_htt_ttbarShape_13TeVDown"},
  {"ClusteredMet_Up", "_CMS_scale_met_clustered_13TeVUp"},
  {"ClusteredMet_Down", "_CMS_scale_met_clustered_13TeVDown"},
  {"UncMet_Up", "_CMS_scale_met_unclustered_13TeVUp"},
  {"UncMet_Down", "_CMS_scale_met_unclustered_13TeVDown"},
  {"DM0_Up", "_CMS_scale_t_1prong_13TeVUp"},
  {"DM0_Down", "_CMS_scale_t_1prong_13TeVDown"},
  {"DM1_Up", "_CMS_scale_t_1prong1pizero_13TeVUp"},
  {"DM1_Down", "_CMS_scale_t_1prong1pizero_13TeVDown"},
  {"DM10_Up", "_CMS_scale_t_3prong_13TeVUp"},
  {"DM10_Down", "_CMS_scale_t_3prong_13TeVDown"},
  {"JESUp", "_CMS_scale_j_13TeVUp"},
  {"JESDown", "_CMS_scale_j_13TeVDown"},
  {"zmumuShape_Up", "_CMS_htt_zmumuShape_VBF_13TeVUp"},
  {"zmumuShape_Down", "_CMS_htt_zmumuShape_VBF_13TeVDown"}
};

TString postfixMaps(std::string shape) { return syst[shape]; }
