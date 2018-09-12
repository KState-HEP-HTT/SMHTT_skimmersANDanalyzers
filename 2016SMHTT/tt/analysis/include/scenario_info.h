class scenario_info {
 private:
  Float_t tau1_pt, tau1_eta, tau1_phi, tau1_m; 
  Float_t tau2_pt, tau2_eta, tau2_phi, tau2_m;
  Float_t jpt_1, jpt_2;
  Float_t mjj, njets;
  Float_t met, metphi;
  Float_t m_sv, pt_sv;
  
 public:
  scenario_info (TTree*, std::string);
  virtual ~scenario_info () {};

  Float_t get_tau1_pt()  { return tau1_pt;  };
  Float_t get_tau1_eta() { return tau1_eta; };
  Float_t get_tau1_phi() { return tau1_phi; };
  Float_t get_tau1_m()   { return tau1_m;   };
  Float_t get_tau2_pt()  { return tau2_pt;  };
  Float_t get_tau2_eta() { return tau2_eta; };
  Float_t get_tau2_phi() { return tau2_phi; };
  Float_t get_tau2_m()   { return tau2_m;   };
  Float_t get_jpt_1()    { return jpt_1;    };
  Float_t get_jpt_2()    { return jpt_2;    };
  Float_t get_mjj()      { return mjj;      };
  Float_t get_njets()    { return njets;    };
  Float_t get_met()      { return met;      };
  Float_t get_metphi()   { return metphi;   };
  Float_t get_m_sv()     { return m_sv;     };
  Float_t get_pt_sv()    { return pt_sv;    };  
};


// read branches from arbre
scenario_info::scenario_info(TTree* arbre, std::string unc) {
  // set nominal as a defalt
  std::string tau1_pt_unc = "tau1_pt";
  std::string tau1_eta_unc = "tau1_eta";
  std::string tau1_phi_unc = "tau1_phi";
  std::string tau1_m_unc = "tau1_m";
  std::string tau2_pt_unc = "tau2_pt";
  std::string tau2_eta_unc = "tau2_eta";
  std::string tau2_phi_unc = "tau2_phi";
  std::string tau2_m_unc = "tau2_m";
  std::string jpt_1_unc = "jpt_1";
  std::string jpt_2_unc = "jpt_2";
  std::string mjj_unc = "mjj";
  std::string njets_unc = "njets";
  std::string met_unc = "met";
  std::string metphi_unc = "metphi";
  std::string m_sv_unc = "m_sv";
  std::string pt_sv_unc = "pt_sv";

  std::cout << "-------------- " << unc << " --------------" << std::endl;

  // if branches for unc is availble, replace to them
  if (unc=="nominal") unc = "";
  else unc = "_"+unc;
  TIter next(arbre->GetListOfBranches());
  TBranch *branch;
  while ((branch = (TBranch*)next())) {
    if ((tau1_pt_unc+unc)==branch->GetName())             tau1_pt_unc=branch->GetName();
    else if ((tau1_eta_unc+unc)==branch->GetName())       tau1_eta_unc=branch->GetName();
    else if ((tau1_phi_unc+unc)==branch->GetName())       tau1_phi_unc=branch->GetName();
    else if ((tau1_m_unc+unc)==branch->GetName())         tau1_m_unc=branch->GetName();
    else if ((tau2_pt_unc+unc)==branch->GetName())        tau2_pt_unc=branch->GetName();
    else if ((tau2_eta_unc+unc)==branch->GetName())       tau2_eta_unc=branch->GetName();
    else if ((tau2_phi_unc+unc)==branch->GetName())       tau2_phi_unc=branch->GetName();
    else if ((tau2_m_unc+unc)==branch->GetName())         tau2_m_unc=branch->GetName();
    else if ((jpt_1_unc+unc)==branch->GetName())          jpt_1_unc=branch->GetName();
    else if ((jpt_2_unc+unc)==branch->GetName())          jpt_2_unc=branch->GetName();
    else if ((mjj_unc+unc)==branch->GetName())            mjj_unc=branch->GetName();
    else if ((njets_unc+unc)==branch->GetName())          njets_unc=branch->GetName();
    else if ((met_unc+unc)==branch->GetName())            met_unc=branch->GetName();
    else if ((metphi_unc+unc)==branch->GetName())         metphi_unc=branch->GetName();
    else if ((m_sv_unc+unc)==branch->GetName())           m_sv_unc=branch->GetName();
    else if ((pt_sv_unc+unc)==branch->GetName())          pt_sv_unc=branch->GetName();
  }
  // print used tau and jet kinematics
  std::cout << tau1_pt_unc << std::endl;
  std::cout << tau1_eta_unc << std::endl;
  std::cout << tau1_phi_unc << std::endl;
  std::cout << tau1_m_unc << std::endl;
  std::cout << tau2_pt_unc << std::endl;
  std::cout << tau2_eta_unc << std::endl;
  std::cout << tau2_phi_unc << std::endl;
  std::cout << tau2_m_unc << std::endl;
  std::cout << jpt_1_unc << std::endl;
  std::cout << jpt_2_unc << std::endl;
  std::cout << mjj_unc << std::endl;
  std::cout << njets_unc << std::endl;
  std::cout << met_unc << std::endl;
  std::cout << metphi_unc << std::endl;
  std::cout << m_sv_unc << std::endl;
  std::cout << pt_sv_unc << std::endl;

  std::cout << "-------------- used branches --------------" << std::endl << std::endl;

  // pick up printed branches
  arbre -> SetBranchAddress( tau1_pt_unc.c_str()  , &tau1_pt  );
  arbre -> SetBranchAddress( tau1_eta_unc.c_str() , &tau1_eta );
  arbre -> SetBranchAddress( tau1_phi_unc.c_str() , &tau1_phi );
  arbre -> SetBranchAddress( tau1_m_unc.c_str()   , &tau1_m   );
  arbre -> SetBranchAddress( tau2_pt_unc.c_str()  , &tau2_pt  );
  arbre -> SetBranchAddress( tau2_eta_unc.c_str() , &tau2_eta );
  arbre -> SetBranchAddress( tau2_phi_unc.c_str() , &tau2_phi );
  arbre -> SetBranchAddress( tau2_m_unc.c_str()   , &tau2_m   );
  arbre -> SetBranchAddress( jpt_1_unc.c_str()    , &jpt_1    );
  arbre -> SetBranchAddress( jpt_2_unc.c_str()    , &jpt_2    );
  arbre -> SetBranchAddress( mjj_unc.c_str()      , &mjj      );
  arbre -> SetBranchAddress( njets_unc.c_str()    , &njets    );
  arbre -> SetBranchAddress( met_unc.c_str()      , &met      );
  arbre -> SetBranchAddress( metphi_unc.c_str()   , &metphi   );
  arbre -> SetBranchAddress( m_sv_unc.c_str()     , &m_sv     );
  arbre -> SetBranchAddress( pt_sv_unc.c_str()    , &pt_sv    );

}
