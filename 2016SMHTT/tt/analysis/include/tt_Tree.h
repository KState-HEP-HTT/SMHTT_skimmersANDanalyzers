float trackpt_1,trackpt_2, jetPt_1, jetPt_2;
unsigned int run, lumi, evt, NUP = -10;
int gen_match_1, gen_match_2=0;

float jetpt_1, jetpt_2, jetpt_3;
float met_norecoil;
float npu, rho, npv=-1, puweight, weight;
//float againstMuonLoose3_1, againstElectronVLooseMVA6_1, againstMuonLoose3_2, againstElectronVLooseMVA6_2;
float againstElectronLooseMVA6_1, againstElectronMediumMVA6_1, againstElectronTightMVA6_1, againstElectronVLooseMVA6_1, againstElectronVTightMVA6_1, againstMuonLoose3_1, againstMuonTight3_1, decayModeFinding_1;
float againstElectronLooseMVA6_2, againstElectronMediumMVA6_2, againstElectronTightMVA6_2, againstElectronVLooseMVA6_2, againstElectronVTightMVA6_2, againstMuonLoose3_2, againstMuonTight3_2, decayModeFinding_2;
float e_1, px_1, py_1, pz_1, pt_1, phi_1, eta_1, m_1, q_1, d0_1, dZ_1, mt_1, iso_1, t1_decayMode;
float eid90_1, eid80_1;
float e_2, px_2, py_2, pz_2, pt_2, phi_2, eta_2, m_2, q_2, d0_2, dZ_2, mt_2, iso_2, t2_decayMode;
//float e_3, px_3, py_3, pz_3, pt_3, phi_3, eta_3, m_3, q_3, d0_3, dZ_3, mt_3, iso_3, t2_decayMode;
float id_m_medium_2,id_m_medium2016_2, id_m_tight_2;
float id_m_medium_1,id_m_medium2016_1, id_m_tight_1;
float byCombinedIsolationDeltaBetaCorrRaw3Hits_1, byIsolationMVA3oldDMwoLTraw_1;//byIsolationMVA3oldDMwoLTraw_1;
float byCombinedIsolationDeltaBetaCorrRaw3Hits_2, byIsolationMVA3oldDMwoLTraw_2;
float byVLooseIsolationMVArun2v1DBnewDMwLT_1,  byVLooseIsolationMVArun2v1DBoldDMwLT_1,  byVLooseIsolationMVArun2v1DBdR03oldDMwLT_1;
float byLooseIsolationMVArun2v1DBnewDMwLT_1,  byLooseIsolationMVArun2v1DBoldDMwLT_1,  byLooseIsolationMVArun2v1DBdR03oldDMwLT_1;
float byMediumIsolationMVArun2v1DBnewDMwLT_1,  byMediumIsolationMVArun2v1DBoldDMwLT_1,  byMediumIsolationMVArun2v1DBdR03oldDMwLT_1;
float byTightIsolationMVArun2v1DBnewDMwLT_1,  byTightIsolationMVArun2v1DBoldDMwLT_1,  byTightIsolationMVArun2v1DBdR03oldDMwLT_1;
float byVTightIsolationMVArun2v1DBnewDMwLT_1,  byVTightIsolationMVArun2v1DBoldDMwLT_1,  byVTightIsolationMVArun2v1DBdR03oldDMwLT_1;
float byVVTightIsolationMVArun2v1DBnewDMwLT_1,  byVVTightIsolationMVArun2v1DBoldDMwLT_1,  byVVTightIsolationMVArun2v1DBdR03oldDMwLT_1;
float byVLooseIsolationMVArun2v1DBnewDMwLT_2,  byVLooseIsolationMVArun2v1DBoldDMwLT_2,  byVLooseIsolationMVArun2v1DBdR03oldDMwLT_2;
float byLooseIsolationMVArun2v1DBnewDMwLT_2,  byLooseIsolationMVArun2v1DBoldDMwLT_2,  byLooseIsolationMVArun2v1DBdR03oldDMwLT_2;
float byMediumIsolationMVArun2v1DBnewDMwLT_2,  byMediumIsolationMVArun2v1DBoldDMwLT_2,  byMediumIsolationMVArun2v1DBdR03oldDMwLT_2;
float byTightIsolationMVArun2v1DBnewDMwLT_2,  byTightIsolationMVArun2v1DBoldDMwLT_2,  byTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float byVTightIsolationMVArun2v1DBnewDMwLT_2,  byVTightIsolationMVArun2v1DBoldDMwLT_2,  byVTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float byVVTightIsolationMVArun2v1DBnewDMwLT_2,  byVVTightIsolationMVArun2v1DBoldDMwLT_2,  byVVTightIsolationMVArun2v1DBdR03oldDMwLT_2;
float mjj, jdeta, jdphi, dijetpt, dijetphi, hdijetphi, visjeteta, ptvis;
float mjj_JESDown, jdeta_JESDown, mjj_JESUp,jdeta_JESUp;
int njetingap, njetingap20, nbtag, njets, njetspt20, nbtagL;
int njetingap_JESDown, njetingap20_JESDown, njets_JESDown, njetspt20_JESDown;
int njetingap_JESUp, njetingap20_JESUp, njets_JESUp, njetspt20_JESUp;
float jmass_1, jpt_1, jpx_1, jpy_1, jpz_1, jeta_1, jphi_1, jrawf_1, jmva_1, jpfid_1, jpuid_1, jcsv_1;
float jmass_2, jpx_2, jpy_2, jpz_2, jpt_2, jeta_2, jphi_2, jrawf_2, jmva_2, jpfid_2, jpuid_2, jcsv_2;
float bpt_1, beta_1, bphi_1, bpfid_1, bpuid_1, bcsv_1, bflavor_1;
float bpt_2, beta_2, bphi_2, bpfid_2, bpuid_2, bcsv_2, bflavor_2;
float met, metphi, mvaMet, mvaMetphi, pzetavis, pzetamiss, mvacov00, mvacov01, mvacov11, mvacov10;
float top_reweighting, gen_Higgs_pt, gen_Higgs_mass=1.0;
float extraelec_veto, extramuon_veto, dilepton_veto=false;
float byLooseCombinedIsolationDeltaBetaCorr3Hits_3, byMediumCombinedIsolationDeltaBetaCorr3Hits_3, byTightCombinedIsolationDeltaBetaCorr3Hits_3;
float byLooseCombinedIsolationDeltaBetaCorr3HitsdR03_3, byMediumCombinedIsolationDeltaBetaCorr3HitsdR03_3, byTightCombinedIsolationDeltaBetaCorr3HitsdR03_3;
float extratau_veto, pt_top1, pt_top2, genweight, dphi_12, dphi_mumet, dphi_taumet;
float amcatNLO_weight, numGenJets;
float met_px, met_py;
float metSig, metcov00, metcov01, metcov10,metcov11, mvaMetcov00, mvaMetcov01,mvaMetcov10,mvaMetcov11, metcov00_v2, metcov01_v2, metcov10_v2,metcov11_v2;
float met_JESDown,met_UESDown;
float met_JESUp,met_UESUp,met_MESUp;
float metphi_JERDown,metphi_JESDown,metphi_UESDown,metphi_MESDown,metphi_EESDown,metphi_TESDown,metphi_PESDown;
float metphi_JERUp,metphi_JESUp,metphi_UESUp,metphi_MESUp,metphi_EESUp,metphi_TESUp,metphi_PESUp;
float genDR_2;
float byVLooseIsolationRerunMVArun2v1DBoldDMwLT_1, byVTightIsolationRerunMVArun2v1DBoldDMwLT_1, byLooseIsolationRerunMVArun2v1DBoldDMwLT_1, byMediumIsolationRerunMVArun2v1DBoldDMwLT_1, byTightIsolationRerunMVArun2v1DBoldDMwLT_1, byVVTightIsolationRerunMVArun2v1DBoldDMwLT_1,byIsolationRerunMVA3oldDMwLTraw_1;
float byVLooseIsolationRerunMVArun2v1DBoldDMwLT_2, byVTightIsolationRerunMVArun2v1DBoldDMwLT_2, byLooseIsolationRerunMVArun2v1DBoldDMwLT_2, byMediumIsolationRerunMVArun2v1DBoldDMwLT_2, byTightIsolationRerunMVArun2v1DBoldDMwLT_2, byVVTightIsolationRerunMVArun2v1DBoldDMwLT_2,byIsolationRerunMVA3oldDMwLTraw_2;
float matchIsoMu22eta2p1_2,matchIsoTkMu22eta2p1_2,matchIsoMu22_2,matchIsoTkMu22_2,matchIsoMu24_2,matchIsoTkMu24_2,filterIsoMu22eta2p1_2,filterIsoTkMu22eta2p1_2,filterIsoMu22_2,filterIsoTkMu22_2,filterIsoMu24_2,filterIsoTkMu24_2,filterIsoMu19Tau20_3,filterIsoMu21Tau20_3;
int njets_JetAbsoluteFlavMapDown,njets_JetAbsoluteMPFBiasDown,njets_JetAbsoluteScaleDown,njets_JetAbsoluteStatDown,njets_JetEnDown,njets_JetFlavorQCDDown,njets_JetFragmentationDown,njets_JetPileUpDataMCDown,njets_JetPileUpPtBBDown,njets_JetPileUpPtEC1Down,njets_JetPileUpPtEC2Down,njets_JetPileUpPtHFDown,njets_JetPileUpPtRefDown,njets_JetRelativeBalDown,njets_JetRelativeFSRDown,njets_JetRelativeJEREC1Down,njets_JetRelativeJEREC2Down,njets_JetRelativeJERHFDown,njets_JetRelativePtBBDown,njets_JetRelativePtEC1Down,njets_JetRelativePtEC2Down,njets_JetRelativePtHFDown,njets_JetRelativeStatECDown,njets_JetRelativeStatFSRDown,njets_JetRelativeStatHFDown,njets_JetSinglePionECALDown,njets_JetSinglePionHCALDown,njets_JetTimePtEtaDown;
int njets_JetAbsoluteFlavMapUp,njets_JetAbsoluteMPFBiasUp,njets_JetAbsoluteScaleUp,njets_JetAbsoluteStatUp,njets_JetEnUp,njets_JetFlavorQCDUp,njets_JetFragmentationUp,njets_JetPileUpDataMCUp,njets_JetPileUpPtBBUp,njets_JetPileUpPtEC1Up,njets_JetPileUpPtEC2Up,njets_JetPileUpPtHFUp,njets_JetPileUpPtRefUp,njets_JetRelativeBalUp,njets_JetRelativeFSRUp,njets_JetRelativeJEREC1Up,njets_JetRelativeJEREC2Up,njets_JetRelativeJERHFUp,njets_JetRelativePtBBUp,njets_JetRelativePtEC1Up,njets_JetRelativePtEC2Up,njets_JetRelativePtHFUp,njets_JetRelativeStatECUp,njets_JetRelativeStatFSRUp,njets_JetRelativeStatHFUp,njets_JetSinglePionECALUp,njets_JetSinglePionHCALUp,njets_JetTimePtEtaUp;
float mjj_JetAbsoluteFlavMapDown,mjj_JetAbsoluteMPFBiasDown,mjj_JetAbsoluteScaleDown,mjj_JetAbsoluteStatDown,mjj_JetEnDown,mjj_JetFlavorQCDDown,mjj_JetFragmentationDown,mjj_JetPileUpDataMCDown,mjj_JetPileUpPtBBDown,mjj_JetPileUpPtEC1Down,mjj_JetPileUpPtEC2Down,mjj_JetPileUpPtHFDown,mjj_JetPileUpPtRefDown,mjj_JetRelativeBalDown,mjj_JetRelativeFSRDown,mjj_JetRelativeJEREC1Down,mjj_JetRelativeJEREC2Down,mjj_JetRelativeJERHFDown,mjj_JetRelativePtBBDown,mjj_JetRelativePtEC1Down,mjj_JetRelativePtEC2Down,mjj_JetRelativePtHFDown,mjj_JetRelativeStatECDown,mjj_JetRelativeStatFSRDown,mjj_JetRelativeStatHFDown,mjjJetSinglePionECALDown,mjj_JetSinglePionHCALDown,mjj_JetTimePtEtaDown, mjj_JetSinglePionECALDown;
float mjj_JetAbsoluteFlavMapUp,mjj_JetAbsoluteMPFBiasUp,mjj_JetAbsoluteScaleUp,mjj_JetAbsoluteStatUp,mjj_JetEnUp,mjj_JetFlavorQCDUp,mjj_JetFragmentationUp,mjj_JetPileUpDataMCUp,mjj_JetPileUpPtBBUp,mjj_JetPileUpPtEC1Up,mjj_JetPileUpPtEC2Up,mjj_JetPileUpPtHFUp,mjj_JetPileUpPtRefUp,mjj_JetRelativeBalUp,mjj_JetRelativeFSRUp,mjj_JetRelativeJEREC1Up,mjj_JetRelativeJEREC2Up,mjj_JetRelativeJERHFUp,mjj_JetRelativePtBBUp,mjj_JetRelativePtEC1Up,mjj_JetRelativePtEC2Up,mjj_JetRelativePtHFUp,mjj_JetRelativeStatECUp,mjj_JetRelativeStatFSRUp,mjj_JetRelativeStatHFUp,mjj_JetSinglePionECALUp,mjj_JetSinglePionHCALUp,mjj_JetTimePtEtaUp;
float passDoubleMu;
float passDoubleTau35, matchDoubleTau35_1, matchDoubleTau35_2,filterDoubleTau35_1,filterDoubleTau35_2,passDoubleTauCmbIso35,matchDoubleTauCmbIso35_1,matchDoubleTauCmbIso35_2,filterDoubleTauCmbIso35_1,filterDoubleTauCmbIso35_2;
float genM,genpT,genpX,genpY,vispX,vispY, b_vispX;
float pt_1_, pt_2_, eta_1_, eta_2_, phi_1_, phi_2_, m_1_, m_2_, mvis_, metcov00_, metcov01_, metcov11_, weight_, met_, metphi_, fvalue_;
float t1_pt, t1_eta, t1_phi, t1_mass;
float t2_pt, t2_eta, t2_phi, t2_mass;
float j1_pt, j1_eta, j1_phi;
float j2_pt, j2_eta, j2_phi;
float b1_pt, b1_eta, b1_phi;
float b2_pt, b2_eta, b2_phi;
float m_sv, pt_sv;
float Dbkg;
float Phi, Phi1, costheta1,costheta2,costhetastar,Q2V1,Q2V2;
float higgs_pT, higgs_m, hjj_pT, hjj_m, dEtajj, dPhijj, cat_0jet, cat_boosted, cat_vbf, cat_inclusive;
float ME_sm_VBF, ME_sm_ggH, ME_bkg, Dbkg_VBF, Dbkg_ggH, NN_disc;


void fillTreeMVA(TTree* BG_Tree, float PT1, float PT2, float ETA1, float ETA2, float PHI1, float PHI2, float M1, float M2, float MET, float METPHI, float METCOV00, float METCOV01, float METCOV11, float MVIS, float TARGET, float WEIGHT) {
  pt_1_=PT1;
  pt_2_=PT2;
  eta_1_=ETA1;
  eta_2_=ETA2;
  pt_1_=PT1;
  pt_2_=PT2;
  phi_1_=PHI1;
  phi_2_=PHI2;
  m_1_=M1;
  m_2_=M2;
  met_=MET;
  metphi_=METPHI;
  mvis_=MVIS;
  metcov00_=METCOV00;
  metcov11_=METCOV11;
  metcov01_=METCOV01;
  weight_=WEIGHT;
  fvalue_=TARGET;
  BG_Tree->Fill();
}



void fillNNTree(TTree* namu, TLorentzVector tau1, TLorentzVector tau2, TLorentzVector jet1, TLorentzVector jet2, TLorentzVector mymet, float mymjj, float mypt_sv, float mym_sv, float mynjets, float bpt_1, float beta_1, float bphi_1, float bpt_2, float beta_2, float bphi_2,TLorentzVector Higgs, bool is_0jet, bool is_boosted, bool is_VBF){
  t1_pt = tau1.Pt();
  t1_eta = tau1.Eta();
  t1_phi = tau1.Phi();
  t1_mass = tau1.M();
  t2_pt = tau2.Pt();
  t2_eta = tau2.Eta();
  t2_phi = tau2.Phi();
  t2_mass = tau2.M();

  j1_pt = jet1.Pt();
  j1_eta = jet1.Eta();
  j1_phi = jet1.Phi();
  j2_pt = jet2.Pt();
  j2_eta = jet2.Eta();
  j2_phi = jet2.Phi();

  met = mymet.Pt();
  metphi = mymet.Phi();
  mjj = mymjj;
  njets = mynjets;
  pt_sv = mypt_sv;
  m_sv = mym_sv;

  b1_pt = bpt_1;
  b1_eta = beta_1;
  b1_phi = bphi_1;
  b2_pt = bpt_2;
  b2_eta = beta_2;
  b2_phi = bphi_2;

  

  higgs_pT = Higgs.Pt();
  higgs_m = Higgs.M();
  hjj_pT = (Higgs + jet1 + jet2).Pt();
  hjj_m = (Higgs + jet1 + jet2).M();
  dEtajj = fabs(jet1.Eta()-jet2.Eta());
  dPhijj = fabs(jet1.Phi()-jet2.Phi());//jet1.DeltaPhi(jet2);
  cat_0jet = is_0jet;
  cat_boosted = is_boosted;
  cat_vbf = is_VBF;
  cat_inclusive = false;
  if (cat_0jet || cat_boosted || cat_vbf) cat_inclusive = true;

  namu->Fill();
}