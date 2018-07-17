#ifndef HTAUTAUTREE_MT_H
#define HTAUTAUTREE_MT_H

#include <TROOT.h>
#include <TChain.h>
#include <TTree.h>
#include <vector>

using namespace std;

class HTauTauTree_mt {
public :
   TTree          *_tree;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types

   Float_t         EmbPtWeight;
   Float_t         Eta;
   Float_t         Flag_BadChargedCandidateFilter;
   Float_t         Flag_BadPFMuonFilter;
   Float_t         Flag_EcalDeadCellTriggerPrimitiveFilter;
   Float_t         Flag_HBHENoiseFilter;
   Float_t         Flag_HBHENoiseIsoFilter;
   Float_t         Flag_badCloneMuonFilter;
   Float_t         Flag_badGlobalMuonFilter;
   Float_t         Flag_eeBadScFilter;
   Float_t         Flag_globalTightHalo2016Filter;
   Float_t         Flag_goodVertices;
   Float_t         GenWeight;
   Float_t         Ht;
   Float_t         LT;
   Float_t         Mass;
   Float_t         MassError;
   Float_t         MassErrord1;
   Float_t         MassErrord2;
   Float_t         MassErrord3;
   Float_t         MassErrord4;
   Float_t         Mt;
   Float_t         NUP;
   Float_t         Phi;
   Float_t         Pt;
   Float_t         bjetCISVVeto20Loose;
   Float_t         bjetCISVVeto20Medium;
   Float_t         bjetCISVVeto20Tight;
   Float_t         bjetCISVVeto30Loose;
   Float_t         bjetCISVVeto30Medium;
   Float_t         bjetCISVVeto30Tight;
   Float_t         charge;
   Float_t         dielectronVeto;
   Float_t         dimuonVeto;
   Float_t         doubleEGroup;
   Float_t         doubleEPass;
   Float_t         doubleEPrescale;
   Float_t         doubleESingleMuGroup;
   Float_t         doubleESingleMuPass;
   Float_t         doubleESingleMuPrescale;
   Float_t         doubleE_23_12Group;
   Float_t         doubleE_23_12Pass;
   Float_t         doubleE_23_12Prescale;
   Float_t         doubleMuGroup;
   Float_t         doubleMuPass;
   Float_t         doubleMuPrescale;
   Float_t         doubleMuSingleEGroup;
   Float_t         doubleMuSingleEPass;
   Float_t         doubleMuSingleEPrescale;
   Float_t         doubleTau32Group;
   Float_t         doubleTau32Pass;
   Float_t         doubleTau32Prescale;
   Float_t         doubleTau35Group;
   Float_t         doubleTau35Pass;
   Float_t         doubleTau35Prescale;
   Float_t         doubleTau40Group;
   Float_t         doubleTau40Pass;
   Float_t         doubleTau40Prescale;
   Float_t         doubleTauCmbIso35RegGroup;
   Float_t         doubleTauCmbIso35RegPass;
   Float_t         doubleTauCmbIso35RegPrescale;
   Float_t         doubleTauCmbIso40Group;
   Float_t         doubleTauCmbIso40Pass;
   Float_t         doubleTauCmbIso40Prescale;
   Float_t         doubleTauCmbIso40RegGroup;
   Float_t         doubleTauCmbIso40RegPass;
   Float_t         doubleTauCmbIso40RegPrescale;
   Float_t         eVetoMVAIso;
   Float_t         eVetoMVAIsoVtx;
   Float_t         eVetoZTTp001dxyz;
   Float_t         eVetoZTTp001dxyzR0;
   ULong64_t       evt;
   Float_t         genEta;
   Float_t         genHTT;
   Float_t         genM;
   Float_t         genMass;
   Float_t         genPhi;
   Float_t         genpT;
   Float_t         genpX;
   Float_t         genpY;
   Float_t         isGtautau;
   Float_t         isWenu;
   Float_t         isWmunu;
   Float_t         isWtaunu;
   Float_t         isZee;
   Float_t         isZmumu;
   Float_t         isZtautau;
   Int_t           isdata;
   Float_t         j1csv;
   Float_t         j1eta;
   Float_t         j1hadronflavor;
   Float_t         j1partonflavor;
   Float_t         j1phi;
   Float_t         j1pt;
   Float_t         j1ptDown;
   Float_t         j1ptUp;
   Float_t         j1pu;
   Float_t         j1rawf;
   Float_t         j2csv;
   Float_t         j2eta;
   Float_t         j2hadronflavor;
   Float_t         j2partonflavor;
   Float_t         j2phi;
   Float_t         j2pt;
   Float_t         j2ptDown;
   Float_t         j2ptUp;
   Float_t         j2pu;
   Float_t         j2rawf;
   Float_t         jb1csv;
   Float_t         jb1csv_CSVL;
   Float_t         jb1eta;
   Float_t         jb1eta_CSVL;
   Float_t         jb1hadronflavor;
   Float_t         jb1hadronflavor_CSVL;
   Float_t         jb1partonflavor;
   Float_t         jb1partonflavor_CSVL;
   Float_t         jb1phi;
   Float_t         jb1phi_CSVL;
   Float_t         jb1pt;
   Float_t         jb1ptDown;
   Float_t         jb1ptDown_CSVL;
   Float_t         jb1ptUp;
   Float_t         jb1ptUp_CSVL;
   Float_t         jb1pt_CSVL;
   Float_t         jb1pu;
   Float_t         jb1pu_CSVL;
   Float_t         jb1rawf;
   Float_t         jb1rawf_CSVL;
   Float_t         jb2csv;
   Float_t         jb2csv_CSVL;
   Float_t         jb2eta;
   Float_t         jb2eta_CSVL;
   Float_t         jb2hadronflavor;
   Float_t         jb2hadronflavor_CSVL;
   Float_t         jb2partonflavor;
   Float_t         jb2partonflavor_CSVL;
   Float_t         jb2phi;
   Float_t         jb2phi_CSVL;
   Float_t         jb2pt;
   Float_t         jb2ptDown;
   Float_t         jb2ptDown_CSVL;
   Float_t         jb2ptUp;
   Float_t         jb2ptUp_CSVL;
   Float_t         jb2pt_CSVL;
   Float_t         jb2pu;
   Float_t         jb2pu_CSVL;
   Float_t         jb2rawf;
   Float_t         jb2rawf_CSVL;
   Float_t         jetVeto20;
   Float_t         jetVeto20_JetEnDown;
   Float_t         jetVeto20_JetEnUp;
   Float_t         jetVeto30;
   Float_t         jetVeto30_JetAbsoluteFlavMapDown;
   Float_t         jetVeto30_JetAbsoluteFlavMapUp;
   Float_t         jetVeto30_JetAbsoluteMPFBiasDown;
   Float_t         jetVeto30_JetAbsoluteMPFBiasUp;
   Float_t         jetVeto30_JetAbsoluteScaleDown;
   Float_t         jetVeto30_JetAbsoluteScaleUp;
   Float_t         jetVeto30_JetAbsoluteStatDown;
   Float_t         jetVeto30_JetAbsoluteStatUp;
   Float_t         jetVeto30_JetClosureDown;
   Float_t         jetVeto30_JetClosureUp;
   Float_t         jetVeto30_JetEnDown;
   Float_t         jetVeto30_JetEnUp;
   Float_t         jetVeto30_JetFlavorQCDDown;
   Float_t         jetVeto30_JetFlavorQCDUp;
   Float_t         jetVeto30_JetFragmentationDown;
   Float_t         jetVeto30_JetFragmentationUp;
   Float_t         jetVeto30_JetPileUpDataMCDown;
   Float_t         jetVeto30_JetPileUpDataMCUp;
   Float_t         jetVeto30_JetPileUpPtBBDown;
   Float_t         jetVeto30_JetPileUpPtBBUp;
   Float_t         jetVeto30_JetPileUpPtEC1Down;
   Float_t         jetVeto30_JetPileUpPtEC1Up;
   Float_t         jetVeto30_JetPileUpPtEC2Down;
   Float_t         jetVeto30_JetPileUpPtEC2Up;
   Float_t         jetVeto30_JetPileUpPtHFDown;
   Float_t         jetVeto30_JetPileUpPtHFUp;
   Float_t         jetVeto30_JetPileUpPtRefDown;
   Float_t         jetVeto30_JetPileUpPtRefUp;
   Float_t         jetVeto30_JetRelativeBalDown;
   Float_t         jetVeto30_JetRelativeBalUp;
   Float_t         jetVeto30_JetRelativeFSRDown;
   Float_t         jetVeto30_JetRelativeFSRUp;
   Float_t         jetVeto30_JetRelativeJEREC1Down;
   Float_t         jetVeto30_JetRelativeJEREC1Up;
   Float_t         jetVeto30_JetRelativeJEREC2Down;
   Float_t         jetVeto30_JetRelativeJEREC2Up;
   Float_t         jetVeto30_JetRelativeJERHFDown;
   Float_t         jetVeto30_JetRelativeJERHFUp;
   Float_t         jetVeto30_JetRelativePtBBDown;
   Float_t         jetVeto30_JetRelativePtBBUp;
   Float_t         jetVeto30_JetRelativePtEC1Down;
   Float_t         jetVeto30_JetRelativePtEC1Up;
   Float_t         jetVeto30_JetRelativePtEC2Down;
   Float_t         jetVeto30_JetRelativePtEC2Up;
   Float_t         jetVeto30_JetRelativePtHFDown;
   Float_t         jetVeto30_JetRelativePtHFUp;
   Float_t         jetVeto30_JetRelativeStatECDown;
   Float_t         jetVeto30_JetRelativeStatECUp;
   Float_t         jetVeto30_JetRelativeStatFSRDown;
   Float_t         jetVeto30_JetRelativeStatFSRUp;
   Float_t         jetVeto30_JetRelativeStatHFDown;
   Float_t         jetVeto30_JetRelativeStatHFUp;
   Float_t         jetVeto30_JetSinglePionECALDown;
   Float_t         jetVeto30_JetSinglePionECALUp;
   Float_t         jetVeto30_JetSinglePionHCALDown;
   Float_t         jetVeto30_JetSinglePionHCALUp;
   Float_t         jetVeto30_JetSubTotalAbsoluteDown;
   Float_t         jetVeto30_JetSubTotalAbsoluteUp;
   Float_t         jetVeto30_JetSubTotalMCDown;
   Float_t         jetVeto30_JetSubTotalMCUp;
   Float_t         jetVeto30_JetSubTotalPileUpDown;
   Float_t         jetVeto30_JetSubTotalPileUpUp;
   Float_t         jetVeto30_JetSubTotalPtDown;
   Float_t         jetVeto30_JetSubTotalPtUp;
   Float_t         jetVeto30_JetSubTotalRelativeDown;
   Float_t         jetVeto30_JetSubTotalRelativeUp;
   Float_t         jetVeto30_JetSubTotalScaleDown;
   Float_t         jetVeto30_JetSubTotalScaleUp;
   Float_t         jetVeto30_JetTimePtEtaDown;
   Float_t         jetVeto30_JetTimePtEtaUp;
   Float_t         jetVeto30_JetTotalDown;
   Float_t         jetVeto30_JetTotalUp;
   Int_t           lumi;
   Float_t         mAbsEta;
   Float_t         mBestTrackType;
   Float_t         mCharge;
   Float_t         mChi2LocalPosition;
   Float_t         mComesFromHiggs;
   Float_t         mDPhiToPfMet_ElectronEnDown;
   Float_t         mDPhiToPfMet_ElectronEnUp;
   Float_t         mDPhiToPfMet_JetEnDown;
   Float_t         mDPhiToPfMet_JetEnUp;
   Float_t         mDPhiToPfMet_JetResDown;
   Float_t         mDPhiToPfMet_JetResUp;
   Float_t         mDPhiToPfMet_MuonEnDown;
   Float_t         mDPhiToPfMet_MuonEnUp;
   Float_t         mDPhiToPfMet_PhotonEnDown;
   Float_t         mDPhiToPfMet_PhotonEnUp;
   Float_t         mDPhiToPfMet_TauEnDown;
   Float_t         mDPhiToPfMet_TauEnUp;
   Float_t         mDPhiToPfMet_UnclusteredEnDown;
   Float_t         mDPhiToPfMet_UnclusteredEnUp;
   Float_t         mDPhiToPfMet_type1;
   Float_t         mEcalIsoDR03;
   Float_t         mEffectiveArea2011;
   Float_t         mEffectiveArea2012;
   Float_t         mErsatzGenEta;
   Float_t         mErsatzGenM;
   Float_t         mErsatzGenPhi;
   Float_t         mErsatzGenpT;
   Float_t         mErsatzGenpX;
   Float_t         mErsatzGenpY;
   Float_t         mErsatzVispX;
   Float_t         mErsatzVispY;
   Float_t         mEta;
   Float_t         mEta_MuonEnDown;
   Float_t         mEta_MuonEnUp;
   Float_t         mGenCharge;
   Float_t         mGenDirectPromptTauDecayFinalState;
   Float_t         mGenEnergy;
   Float_t         mGenEta;
   Float_t         mGenIsPrompt;
   Float_t         mGenMotherPdgId;
   Float_t         mGenParticle;
   Float_t         mGenPdgId;
   Float_t         mGenPhi;
   Float_t         mGenPrompt;
   Float_t         mGenPromptFinalState;
   Float_t         mGenPromptTauDecay;
   Float_t         mGenPt;
   Float_t         mGenTauDecay;
   Float_t         mGenVZ;
   Float_t         mGenVtxPVMatch;
   Float_t         mHcalIsoDR03;
   Float_t         mIP3D;
   Float_t         mIP3DErr;
   Float_t         mIsGlobal;
   Float_t         mIsPFMuon;
   Float_t         mIsTracker;
   Float_t         mIsoDB03;
   Float_t         mIsoDB04;
   Float_t         mIsoMu22Filter;
   Float_t         mIsoMu22eta2p1Filter;
   Float_t         mIsoMu24Filter;
   Float_t         mIsoMu24eta2p1Filter;
   Float_t         mIsoTkMu22Filter;
   Float_t         mIsoTkMu22eta2p1Filter;
   Float_t         mIsoTkMu24Filter;
   Float_t         mIsoTkMu24eta2p1Filter;
   Float_t         mJetArea;
   Float_t         mJetBtag;
   Float_t         mJetEtaEtaMoment;
   Float_t         mJetEtaPhiMoment;
   Float_t         mJetEtaPhiSpread;
   Float_t         mJetHadronFlavour;
   Float_t         mJetPFCISVBtag;
   Float_t         mJetPartonFlavour;
   Float_t         mJetPhiPhiMoment;
   Float_t         mJetPt;
   Float_t         mLowestMll;
   Float_t         mMass;
   Float_t         mMatchedStations;
   Float_t         mMatchesDoubleESingleMu;
   Float_t         mMatchesDoubleMu;
   Float_t         mMatchesDoubleMuSingleE;
   Float_t         mMatchesIsoMu22Path;
   Float_t         mMatchesIsoMu22eta2p1Path;
   Float_t         mMatchesIsoMu24Path;
   Float_t         mMatchesIsoMu24eta2p1Path;
   Float_t         mMatchesIsoTkMu22Path;
   Float_t         mMatchesIsoTkMu22eta2p1Path;
   Float_t         mMatchesIsoTkMu24Path;
   Float_t         mMatchesIsoTkMu24eta2p1Path;
   Float_t         mMatchesMu19Tau20Filter;
   Float_t         mMatchesMu19Tau20Path;
   Float_t         mMatchesMu19Tau20sL1Filter;
   Float_t         mMatchesMu19Tau20sL1Path;
   Float_t         mMatchesMu21Tau20sL1Filter;
   Float_t         mMatchesMu21Tau20sL1Path;
   Float_t         mMatchesMu23Ele12DZPath;
   Float_t         mMatchesMu23Ele12Path;
   Float_t         mMatchesMu8Ele23DZPath;
   Float_t         mMatchesMu8Ele23Path;
   Float_t         mMatchesSingleESingleMu;
   Float_t         mMatchesSingleMu;
   Float_t         mMatchesSingleMuIso20;
   Float_t         mMatchesSingleMuIsoTk20;
   Float_t         mMatchesSingleMuSingleE;
   Float_t         mMatchesSingleMu_leg1;
   Float_t         mMatchesSingleMu_leg1_noiso;
   Float_t         mMatchesSingleMu_leg2;
   Float_t         mMatchesSingleMu_leg2_noiso;
   Float_t         mMatchesTripleMu;
   Float_t         mMtToPfMet_ElectronEnDown;
   Float_t         mMtToPfMet_ElectronEnUp;
   Float_t         mMtToPfMet_JetEnDown;
   Float_t         mMtToPfMet_JetEnUp;
   Float_t         mMtToPfMet_JetResDown;
   Float_t         mMtToPfMet_JetResUp;
   Float_t         mMtToPfMet_MuonEnDown;
   Float_t         mMtToPfMet_MuonEnUp;
   Float_t         mMtToPfMet_PhotonEnDown;
   Float_t         mMtToPfMet_PhotonEnUp;
   Float_t         mMtToPfMet_Raw;
   Float_t         mMtToPfMet_TauEnDown;
   Float_t         mMtToPfMet_TauEnUp;
   Float_t         mMtToPfMet_UnclusteredEnDown;
   Float_t         mMtToPfMet_UnclusteredEnUp;
   Float_t         mMtToPfMet_type1;
   Float_t         mMu23Ele12DZFilter;
   Float_t         mMu23Ele12Filter;
   Float_t         mMu8Ele23DZFilter;
   Float_t         mMu8Ele23Filter;
   Float_t         mMuonHits;
   Float_t         mNearestZMass;
   Float_t         mNormTrkChi2;
   Float_t         mNormalizedChi2;
   Float_t         mPFChargedHadronIsoR04;
   Float_t         mPFChargedIso;
   Float_t         mPFIDLoose;
   Float_t         mPFIDMedium;
   Float_t         mPFIDTight;
   Float_t         mPFNeutralHadronIsoR04;
   Float_t         mPFNeutralIso;
   Float_t         mPFPUChargedIso;
   Float_t         mPFPhotonIso;
   Float_t         mPFPhotonIsoR04;
   Float_t         mPFPileupIsoR04;
   Float_t         mPVDXY;
   Float_t         mPVDZ;
   Float_t         mPhi;
   Float_t         mPhi_MuonEnDown;
   Float_t         mPhi_MuonEnUp;
   Float_t         mPixHits;
   Float_t         mPt;
   Float_t         mPt_MuonEnDown;
   Float_t         mPt_MuonEnUp;
   Float_t         mRank;
   Float_t         mRelPFIsoDBDefault;
   Float_t         mRelPFIsoDBDefaultR04;
   Float_t         mRelPFIsoRho;
   Float_t         mRho;
   Float_t         mSIP2D;
   Float_t         mSIP3D;
   Float_t         mSegmentCompatibility;
   Float_t         mTkLayersWithMeasurement;
   Float_t         mTrkIsoDR03;
   Float_t         mTrkKink;
   Int_t           mTypeCode;
   Float_t         mVZ;
   Float_t         mValidFraction;
   Float_t         mZTTGenMatching;
   Float_t         m_t_CosThetaStar;
   Float_t         m_t_DPhi;
   Float_t         m_t_DR;
   Float_t         m_t_Eta;
   Float_t         m_t_Mass;
   Float_t         m_t_Mass_TauEnDown;
   Float_t         m_t_Mass_TauEnUp;
   Float_t         m_t_Mt;
   Float_t         m_t_MtTotal;
   Float_t         m_t_Mt_TauEnDown;
   Float_t         m_t_Mt_TauEnUp;
   Float_t         m_t_MvaMet;
   Float_t         m_t_MvaMetCovMatrix00;
   Float_t         m_t_MvaMetCovMatrix01;
   Float_t         m_t_MvaMetCovMatrix10;
   Float_t         m_t_MvaMetCovMatrix11;
   Float_t         m_t_MvaMetPhi;
   Float_t         m_t_PZeta;
   Float_t         m_t_PZetaLess0p85PZetaVis;
   Float_t         m_t_PZetaVis;
   Float_t         m_t_Phi;
   Float_t         m_t_Pt;
   Float_t         m_t_SS;
   Float_t         m_t_ToMETDPhi_Ty1;
   Float_t         m_t_collinearmass;
   Float_t         m_t_collinearmass_EleEnDown;
   Float_t         m_t_collinearmass_EleEnUp;
   Float_t         m_t_collinearmass_JetEnDown;
   Float_t         m_t_collinearmass_JetEnUp;
   Float_t         m_t_collinearmass_MuEnDown;
   Float_t         m_t_collinearmass_MuEnUp;
   Float_t         m_t_collinearmass_TauEnDown;
   Float_t         m_t_collinearmass_TauEnUp;
   Float_t         m_t_collinearmass_UnclusteredEnDown;
   Float_t         m_t_collinearmass_UnclusteredEnUp;
   Float_t         m_t_pt_tt;
   Float_t         metSig;
   Float_t         metcov00;
   Float_t         metcov01;
   Float_t         metcov10;
   Float_t         metcov11;
   Float_t         metcov00_DESYlike;
   Float_t         metcov01_DESYlike;
   Float_t         metcov10_DESYlike;
   Float_t         metcov11_DESYlike;
   Float_t         muGlbIsoVetoPt10;
   Float_t         muVetoPt15IsoIdVtx;
   Float_t         muVetoPt5;
   Float_t         muVetoPt5IsoIdVtx;
   Float_t         muVetoZTTp001dxyz;
   Float_t         muVetoZTTp001dxyzR0;
   Float_t         nTruePU;
   Float_t         numGenJets;
   Float_t         nvtx;
   Float_t         processID;
   Float_t         puppiMetEt;
   Float_t         puppiMetPhi;
   Float_t         pvChi2;
   Float_t         pvDX;
   Float_t         pvDY;
   Float_t         pvDZ;
   Int_t           pvIsFake;
   Int_t           pvIsValid;
   Float_t         pvNormChi2;
   Float_t         pvRho;
   Float_t         pvX;
   Float_t         pvY;
   Float_t         pvZ;
   Float_t         pvndof;
   Float_t         raw_pfMetEt;
   Float_t         raw_pfMetPhi;
   Float_t         recoilDaught;
   Float_t         recoilWithMet;
   Float_t         rho;
   Int_t           run;
   Float_t         singleE17SingleMu8Group;
   Float_t         singleE17SingleMu8Pass;
   Float_t         singleE17SingleMu8Prescale;
   Float_t         singleE20SingleTau28Group;
   Float_t         singleE20SingleTau28Pass;
   Float_t         singleE20SingleTau28Prescale;
   Float_t         singleE22SingleTau20SingleL1Group;
   Float_t         singleE22SingleTau20SingleL1Pass;
   Float_t         singleE22SingleTau20SingleL1Prescale;
   Float_t         singleE22SingleTau29Group;
   Float_t         singleE22SingleTau29Pass;
   Float_t         singleE22SingleTau29Prescale;
   Float_t         singleE23SingleMu8Group;
   Float_t         singleE23SingleMu8Pass;
   Float_t         singleE23SingleMu8Prescale;
   Float_t         singleE24SingleTau20Group;
   Float_t         singleE24SingleTau20Pass;
   Float_t         singleE24SingleTau20Prescale;
   Float_t         singleE24SingleTau20SingleL1Group;
   Float_t         singleE24SingleTau20SingleL1Pass;
   Float_t         singleE24SingleTau20SingleL1Prescale;
   Float_t         singleE24SingleTau30Group;
   Float_t         singleE24SingleTau30Pass;
   Float_t         singleE24SingleTau30Prescale;
   Float_t         singleE25eta2p1TightGroup;
   Float_t         singleE25eta2p1TightPass;
   Float_t         singleE25eta2p1TightPrescale;
   Float_t         singleE27SingleTau20SingleL1Group;
   Float_t         singleE27SingleTau20SingleL1Pass;
   Float_t         singleE27SingleTau20SingleL1Prescale;
   Float_t         singleE27TightGroup;
   Float_t         singleE27TightPass;
   Float_t         singleE27TightPrescale;
   Float_t         singleE27eta2p1LooseGroup;
   Float_t         singleE27eta2p1LoosePass;
   Float_t         singleE27eta2p1LoosePrescale;
   Float_t         singleE27eta2p1TightGroup;
   Float_t         singleE27eta2p1TightPass;
   Float_t         singleE27eta2p1TightPrescale;
   Float_t         singleE32SingleTau20SingleL1Group;
   Float_t         singleE32SingleTau20SingleL1Pass;
   Float_t         singleE32SingleTau20SingleL1Prescale;
   Float_t         singleE36SingleTau30Group;
   Float_t         singleE36SingleTau30Pass;
   Float_t         singleE36SingleTau30Prescale;
   Float_t         singleESingleMuGroup;
   Float_t         singleESingleMuPass;
   Float_t         singleESingleMuPrescale;
   Float_t         singleE_leg1Group;
   Float_t         singleE_leg1Pass;
   Float_t         singleE_leg1Prescale;
   Float_t         singleE_leg2Group;
   Float_t         singleE_leg2Pass;
   Float_t         singleE_leg2Prescale;
   Float_t         singleIsoMu20Group;
   Float_t         singleIsoMu20Pass;
   Float_t         singleIsoMu20Prescale;
   Float_t         singleIsoMu22Group;
   Float_t         singleIsoMu22Pass;
   Float_t         singleIsoMu22Prescale;
   Float_t         singleIsoMu22eta2p1Group;
   Float_t         singleIsoMu22eta2p1Pass;
   Float_t         singleIsoMu22eta2p1Prescale;
   Float_t         singleIsoMu24Group;
   Float_t         singleIsoMu24Pass;
   Float_t         singleIsoMu24Prescale;
   Float_t         singleIsoMu24eta2p1Group;
   Float_t         singleIsoMu24eta2p1Pass;
   Float_t         singleIsoMu24eta2p1Prescale;
   Float_t         singleIsoMu27Group;
   Float_t         singleIsoMu27Pass;
   Float_t         singleIsoMu27Prescale;
   Float_t         singleIsoTkMu20Group;
   Float_t         singleIsoTkMu20Pass;
   Float_t         singleIsoTkMu20Prescale;
   Float_t         singleIsoTkMu22Group;
   Float_t         singleIsoTkMu22Pass;
   Float_t         singleIsoTkMu22Prescale;
   Float_t         singleIsoTkMu22eta2p1Group;
   Float_t         singleIsoTkMu22eta2p1Pass;
   Float_t         singleIsoTkMu22eta2p1Prescale;
   Float_t         singleIsoTkMu24Group;
   Float_t         singleIsoTkMu24Pass;
   Float_t         singleIsoTkMu24Prescale;
   Float_t         singleIsoTkMu24eta2p1Group;
   Float_t         singleIsoTkMu24eta2p1Pass;
   Float_t         singleIsoTkMu24eta2p1Prescale;
   Float_t         singleMu17SingleE12Group;
   Float_t         singleMu17SingleE12Pass;
   Float_t         singleMu17SingleE12Prescale;
   Float_t         singleMu19eta2p1LooseTau20Group;
   Float_t         singleMu19eta2p1LooseTau20Pass;
   Float_t         singleMu19eta2p1LooseTau20Prescale;
   Float_t         singleMu19eta2p1LooseTau20singleL1Group;
   Float_t         singleMu19eta2p1LooseTau20singleL1Pass;
   Float_t         singleMu19eta2p1LooseTau20singleL1Prescale;
   Float_t         singleMu21eta2p1LooseTau20singleL1Group;
   Float_t         singleMu21eta2p1LooseTau20singleL1Pass;
   Float_t         singleMu21eta2p1LooseTau20singleL1Prescale;
   Float_t         singleMu23SingleE12DZGroup;
   Float_t         singleMu23SingleE12DZPass;
   Float_t         singleMu23SingleE12DZPrescale;
   Float_t         singleMu23SingleE12Group;
   Float_t         singleMu23SingleE12Pass;
   Float_t         singleMu23SingleE12Prescale;
   Float_t         singleMu23SingleE8Group;
   Float_t         singleMu23SingleE8Pass;
   Float_t         singleMu23SingleE8Prescale;
   Float_t         singleMu8SingleE23DZGroup;
   Float_t         singleMu8SingleE23DZPass;
   Float_t         singleMu8SingleE23DZPrescale;
   Float_t         singleMuGroup;
   Float_t         singleMuPass;
   Float_t         singleMuPrescale;
   Float_t         singleMuSingleEGroup;
   Float_t         singleMuSingleEPass;
   Float_t         singleMuSingleEPrescale;
   Float_t         singleMu_leg1Group;
   Float_t         singleMu_leg1Pass;
   Float_t         singleMu_leg1Prescale;
   Float_t         singleMu_leg1_noisoGroup;
   Float_t         singleMu_leg1_noisoPass;
   Float_t         singleMu_leg1_noisoPrescale;
   Float_t         singleMu_leg2Group;
   Float_t         singleMu_leg2Pass;
   Float_t         singleMu_leg2Prescale;
   Float_t         singleMu_leg2_noisoGroup;
   Float_t         singleMu_leg2_noisoPass;
   Float_t         singleMu_leg2_noisoPrescale;
   Float_t         singleTau140Group;
   Float_t         singleTau140Pass;
   Float_t         singleTau140Prescale;
   Float_t         singleTau140Trk50Group;
   Float_t         singleTau140Trk50Pass;
   Float_t         singleTau140Trk50Prescale;
   Float_t         tAbsEta;
   Float_t         tAgainstElectronLooseMVA6;
   Float_t         tAgainstElectronMVA6Raw;
   Float_t         tAgainstElectronMVA6category;
   Float_t         tAgainstElectronMediumMVA6;
   Float_t         tAgainstElectronTightMVA6;
   Float_t         tAgainstElectronVLooseMVA6;
   Float_t         tAgainstElectronVTightMVA6;
   Float_t         tAgainstMuonLoose3;
   Float_t         tAgainstMuonTight3;
   Float_t         tByCombinedIsolationDeltaBetaCorrRaw3Hits;
   Float_t         tByIsolationMVArun2v1DBdR03oldDMwLTraw;
   Float_t         tByIsolationMVArun2v1DBnewDMwLTraw;
   Float_t         tByIsolationMVArun2v1DBoldDMwLTraw;
   Float_t         tByIsolationMVArun2v1PWdR03oldDMwLTraw;
   Float_t         tByIsolationMVArun2v1PWnewDMwLTraw;
   Float_t         tByIsolationMVArun2v1PWoldDMwLTraw;
   Float_t         tByLooseCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByLooseIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         tByLooseIsolationMVArun2v1PWnewDMwLT;
   Float_t         tByLooseIsolationMVArun2v1PWoldDMwLT;
   Float_t         tByMediumCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByMediumIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByMediumIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByMediumIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByMediumIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         tByMediumIsolationMVArun2v1PWnewDMwLT;
   Float_t         tByMediumIsolationMVArun2v1PWoldDMwLT;
   Float_t         tByPhotonPtSumOutsideSignalCone;
   Float_t         tByTightCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         tByTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         tByTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1PWnewDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1PWoldDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         tByVTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         tByVTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         tCharge;
   Float_t         tChargedIsoPtSum;
   Float_t         tChargedIsoPtSumdR03;
   Float_t         tComesFromHiggs;
   Float_t         tDPhiToPfMet_ElectronEnDown;
   Float_t         tDPhiToPfMet_ElectronEnUp;
   Float_t         tDPhiToPfMet_JetEnDown;
   Float_t         tDPhiToPfMet_JetEnUp;
   Float_t         tDPhiToPfMet_JetResDown;
   Float_t         tDPhiToPfMet_JetResUp;
   Float_t         tDPhiToPfMet_MuonEnDown;
   Float_t         tDPhiToPfMet_MuonEnUp;
   Float_t         tDPhiToPfMet_PhotonEnDown;
   Float_t         tDPhiToPfMet_PhotonEnUp;
   Float_t         tDPhiToPfMet_TauEnDown;
   Float_t         tDPhiToPfMet_TauEnUp;
   Float_t         tDPhiToPfMet_UnclusteredEnDown;
   Float_t         tDPhiToPfMet_UnclusteredEnUp;
   Float_t         tDPhiToPfMet_type1;
   Float_t         tDecayMode;
   Float_t         tDecayModeFinding;
   Float_t         tDecayModeFindingNewDMs;
   Float_t         tElecOverlap;
   Float_t         tEta;
   Float_t         tEta_TauEnDown;
   Float_t         tEta_TauEnUp;
   Float_t         tFootprintCorrection;
   Float_t         tFootprintCorrectiondR03;
   Float_t         tGenCharge;
   Float_t         tGenDecayMode;
   Float_t         tGenEnergy;
   Float_t         tGenEta;
   Float_t         tGenIsPrompt;
   Float_t         tGenJetEta;
   Float_t         tGenJetPt;
   Float_t         tGenMotherEnergy;
   Float_t         tGenMotherEta;
   Float_t         tGenMotherPdgId;
   Float_t         tGenMotherPhi;
   Float_t         tGenMotherPt;
   Float_t         tGenPdgId;
   Float_t         tGenPhi;
   Float_t         tGenPt;
   Float_t         tGenStatus;
   Float_t         tGlobalMuonVtxOverlap;
   Float_t         tJetArea;
   Float_t         tJetBtag;
   Float_t         tJetEtaEtaMoment;
   Float_t         tJetEtaPhiMoment;
   Float_t         tJetEtaPhiSpread;
   Float_t         tJetHadronFlavour;
   Float_t         tJetPFCISVBtag;
   Float_t         tJetPartonFlavour;
   Float_t         tJetPhiPhiMoment;
   Float_t         tJetPt;
   Float_t         tLeadTrackPt;
   Float_t         tLowestMll;
   Float_t         tMass;
   Float_t         tMass_TauEnDown;
   Float_t         tMass_TauEnUp;
   Float_t         tMatchesDoubleTau32Filter;
   Float_t         tMatchesDoubleTau32Path;
   Float_t         tMatchesDoubleTau35Filter;
   Float_t         tMatchesDoubleTau35Path;
   Float_t         tMatchesDoubleTau40Filter;
   Float_t         tMatchesDoubleTau40Path;
   Float_t         tMatchesDoubleTauCmbIso35RegFilter;
   Float_t         tMatchesDoubleTauCmbIso35RegPath;
   Float_t         tMatchesDoubleTauCmbIso40Filter;
   Float_t         tMatchesDoubleTauCmbIso40Path;
   Float_t         tMatchesDoubleTauCmbIso40RegFilter;
   Float_t         tMatchesDoubleTauCmbIso40RegPath;
   Float_t         tMatchesEle24Tau20Filter;
   Float_t         tMatchesEle24Tau20L1Path;
   Float_t         tMatchesEle24Tau20Path;
   Float_t         tMatchesEle24Tau20sL1Filter;
   Float_t         tMatchesEle24Tau30Filter;
   Float_t         tMatchesEle24Tau30Path;
   Float_t         tMatchesMu19Tau20Filter;
   Float_t         tMatchesMu19Tau20Path;
   Float_t         tMatchesMu19Tau20sL1Filter;
   Float_t         tMatchesMu19Tau20sL1Path;
   Float_t         tMatchesMu21Tau20sL1Filter;
   Float_t         tMatchesMu21Tau20sL1Path;
   Float_t         tMtToPfMet_ElectronEnDown;
   Float_t         tMtToPfMet_ElectronEnUp;
   Float_t         tMtToPfMet_JetEnDown;
   Float_t         tMtToPfMet_JetEnUp;
   Float_t         tMtToPfMet_JetResDown;
   Float_t         tMtToPfMet_JetResUp;
   Float_t         tMtToPfMet_MuonEnDown;
   Float_t         tMtToPfMet_MuonEnUp;
   Float_t         tMtToPfMet_PhotonEnDown;
   Float_t         tMtToPfMet_PhotonEnUp;
   Float_t         tMtToPfMet_Raw;
   Float_t         tMtToPfMet_TauEnDown;
   Float_t         tMtToPfMet_TauEnUp;
   Float_t         tMtToPfMet_UnclusteredEnDown;
   Float_t         tMtToPfMet_UnclusteredEnUp;
   Float_t         tMtToPfMet_type1;
   Float_t         tMuOverlap;
   Float_t         tMuonIdIsoStdVtxOverlap;
   Float_t         tMuonIdIsoVtxOverlap;
   Float_t         tMuonIdVtxOverlap;
   Float_t         tNChrgHadrIsolationCands;
   Float_t         tNChrgHadrSignalCands;
   Float_t         tNGammaSignalCands;
   Float_t         tNNeutralHadrSignalCands;
   Float_t         tNSignalCands;
   Float_t         tNearestZMass;
   Float_t         tNeutralIsoPtSum;
   Float_t         tNeutralIsoPtSumWeight;
   Float_t         tNeutralIsoPtSumWeightdR03;
   Float_t         tNeutralIsoPtSumdR03;
   Float_t         tPVDXY;
   Float_t         tPVDZ;
   Float_t         tPhi;
   Float_t         tPhi_TauEnDown;
   Float_t         tPhi_TauEnUp;
   Float_t         tPhotonPtSumOutsideSignalCone;
   Float_t         tPhotonPtSumOutsideSignalConedR03;
   Float_t         tPt;
   Float_t         tPt_TauEnDown;
   Float_t         tPt_TauEnUp;
   Float_t         tPuCorrPtSum;
   Float_t         tRank;
   Float_t         tRerunMVArun2v1DBoldDMwLTLoose;
   Float_t         tRerunMVArun2v1DBoldDMwLTMedium;
   Float_t         tRerunMVArun2v1DBoldDMwLTTight;
   Float_t         tRerunMVArun2v1DBoldDMwLTVLoose;
   Float_t         tRerunMVArun2v1DBoldDMwLTVTight;
   Float_t         tRerunMVArun2v1DBoldDMwLTVVTight;
   Float_t         tRerunMVArun2v1DBoldDMwLTraw;
   Float_t         tVZ;
   Float_t         tZTTGenDR;
   Float_t         tZTTGenEta;
   Float_t         tZTTGenMatching;
   Float_t         tZTTGenPhi;
   Float_t         tZTTGenPt;
   Float_t         t_m_collinearmass;
   Float_t         t_m_collinearmass_JetEnDown;
   Float_t         t_m_collinearmass_JetEnUp;
   Float_t         t_m_collinearmass_UnclusteredEnDown;
   Float_t         t_m_collinearmass_UnclusteredEnUp;
   Float_t         tauVetoPt20Loose3HitsVtx;
   Float_t         tauVetoPt20TightMVALTVtx;
   Float_t         topQuarkPt1;
   Float_t         topQuarkPt2;
   Float_t         tripleEGroup;
   Float_t         tripleEPass;
   Float_t         tripleEPrescale;
   Float_t         tripleMuGroup;
   Float_t         tripleMuPass;
   Float_t         tripleMuPrescale;
   Float_t         type1_pfMetEt;
   Float_t         type1_pfMetPhi;
   Float_t         type1_pfMet_shiftedPhi_ElectronEnDown;
   Float_t         type1_pfMet_shiftedPhi_ElectronEnUp;
   Float_t         type1_pfMet_shiftedPhi_JetEnDown;
   Float_t         type1_pfMet_shiftedPhi_JetEnUp;
   Float_t         type1_pfMet_shiftedPhi_JetResDown;
   Float_t         type1_pfMet_shiftedPhi_JetResUp;
   Float_t         type1_pfMet_shiftedPhi_MuonEnDown;
   Float_t         type1_pfMet_shiftedPhi_MuonEnUp;
   Float_t         type1_pfMet_shiftedPhi_PhotonEnDown;
   Float_t         type1_pfMet_shiftedPhi_PhotonEnUp;
   Float_t         type1_pfMet_shiftedPhi_TauEnDown;
   Float_t         type1_pfMet_shiftedPhi_TauEnUp;
   Float_t         type1_pfMet_shiftedPhi_UnclusteredEnDown;
   Float_t         type1_pfMet_shiftedPhi_UnclusteredEnUp;
   Float_t         type1_pfMet_shiftedPt_ElectronEnDown;
   Float_t         type1_pfMet_shiftedPt_ElectronEnUp;
   Float_t         type1_pfMet_shiftedPt_JetEnDown;
   Float_t         type1_pfMet_shiftedPt_JetEnUp;
   Float_t         type1_pfMet_shiftedPt_JetResDown;
   Float_t         type1_pfMet_shiftedPt_JetResUp;
   Float_t         type1_pfMet_shiftedPt_MuonEnDown;
   Float_t         type1_pfMet_shiftedPt_MuonEnUp;
   Float_t         type1_pfMet_shiftedPt_PhotonEnDown;
   Float_t         type1_pfMet_shiftedPt_PhotonEnUp;
   Float_t         type1_pfMet_shiftedPt_TauEnDown;
   Float_t         type1_pfMet_shiftedPt_TauEnUp;
   Float_t         type1_pfMet_shiftedPt_UnclusteredEnDown;
   Float_t         type1_pfMet_shiftedPt_UnclusteredEnUp;
   Float_t         vbfDeta;
   Float_t         vbfDeta_JetEnDown;
   Float_t         vbfDeta_JetEnUp;
   Float_t         vbfDijetrap;
   Float_t         vbfDijetrap_JetEnDown;
   Float_t         vbfDijetrap_JetEnUp;
   Float_t         vbfDphi;
   Float_t         vbfDphi_JetEnDown;
   Float_t         vbfDphi_JetEnUp;
   Float_t         vbfDphihj;
   Float_t         vbfDphihj_JetEnDown;
   Float_t         vbfDphihj_JetEnUp;
   Float_t         vbfDphihjnomet;
   Float_t         vbfDphihjnomet_JetEnDown;
   Float_t         vbfDphihjnomet_JetEnUp;
   Float_t         vbfHrap;
   Float_t         vbfHrap_JetEnDown;
   Float_t         vbfHrap_JetEnUp;
   Float_t         vbfJetVeto20;
   Float_t         vbfJetVeto20_JetEnDown;
   Float_t         vbfJetVeto20_JetEnUp;
   Float_t         vbfJetVeto30;
   Float_t         vbfJetVeto30_JetEnDown;
   Float_t         vbfJetVeto30_JetEnUp;
   Float_t         vbfMVA;
   Float_t         vbfMVA_JetEnDown;
   Float_t         vbfMVA_JetEnUp;
   Float_t         vbfMass;
   Float_t         vbfMass_JetAbsoluteFlavMapDown;
   Float_t         vbfMass_JetAbsoluteFlavMapUp;
   Float_t         vbfMass_JetAbsoluteMPFBiasDown;
   Float_t         vbfMass_JetAbsoluteMPFBiasUp;
   Float_t         vbfMass_JetAbsoluteScaleDown;
   Float_t         vbfMass_JetAbsoluteScaleUp;
   Float_t         vbfMass_JetAbsoluteStatDown;
   Float_t         vbfMass_JetAbsoluteStatUp;
   Float_t         vbfMass_JetClosureDown;
   Float_t         vbfMass_JetClosureUp;
   Float_t         vbfMass_JetEnDown;
   Float_t         vbfMass_JetEnUp;
   Float_t         vbfMass_JetFlavorQCDDown;
   Float_t         vbfMass_JetFlavorQCDUp;
   Float_t         vbfMass_JetFragmentationDown;
   Float_t         vbfMass_JetFragmentationUp;
   Float_t         vbfMass_JetPileUpDataMCDown;
   Float_t         vbfMass_JetPileUpDataMCUp;
   Float_t         vbfMass_JetPileUpPtBBDown;
   Float_t         vbfMass_JetPileUpPtBBUp;
   Float_t         vbfMass_JetPileUpPtEC1Down;
   Float_t         vbfMass_JetPileUpPtEC1Up;
   Float_t         vbfMass_JetPileUpPtEC2Down;
   Float_t         vbfMass_JetPileUpPtEC2Up;
   Float_t         vbfMass_JetPileUpPtHFDown;
   Float_t         vbfMass_JetPileUpPtHFUp;
   Float_t         vbfMass_JetPileUpPtRefDown;
   Float_t         vbfMass_JetPileUpPtRefUp;
   Float_t         vbfMass_JetRelativeBalDown;
   Float_t         vbfMass_JetRelativeBalUp;
   Float_t         vbfMass_JetRelativeFSRDown;
   Float_t         vbfMass_JetRelativeFSRUp;
   Float_t         vbfMass_JetRelativeJEREC1Down;
   Float_t         vbfMass_JetRelativeJEREC1Up;
   Float_t         vbfMass_JetRelativeJEREC2Down;
   Float_t         vbfMass_JetRelativeJEREC2Up;
   Float_t         vbfMass_JetRelativeJERHFDown;
   Float_t         vbfMass_JetRelativeJERHFUp;
   Float_t         vbfMass_JetRelativePtBBDown;
   Float_t         vbfMass_JetRelativePtBBUp;
   Float_t         vbfMass_JetRelativePtEC1Down;
   Float_t         vbfMass_JetRelativePtEC1Up;
   Float_t         vbfMass_JetRelativePtEC2Down;
   Float_t         vbfMass_JetRelativePtEC2Up;
   Float_t         vbfMass_JetRelativePtHFDown;
   Float_t         vbfMass_JetRelativePtHFUp;
   Float_t         vbfMass_JetRelativeStatECDown;
   Float_t         vbfMass_JetRelativeStatECUp;
   Float_t         vbfMass_JetRelativeStatFSRDown;
   Float_t         vbfMass_JetRelativeStatFSRUp;
   Float_t         vbfMass_JetRelativeStatHFDown;
   Float_t         vbfMass_JetRelativeStatHFUp;
   Float_t         vbfMass_JetSinglePionECALDown;
   Float_t         vbfMass_JetSinglePionECALUp;
   Float_t         vbfMass_JetSinglePionHCALDown;
   Float_t         vbfMass_JetSinglePionHCALUp;
   Float_t         vbfMass_JetSubTotalAbsoluteDown;
   Float_t         vbfMass_JetSubTotalAbsoluteUp;
   Float_t         vbfMass_JetSubTotalMCDown;
   Float_t         vbfMass_JetSubTotalMCUp;
   Float_t         vbfMass_JetSubTotalPileUpDown;
   Float_t         vbfMass_JetSubTotalPileUpUp;
   Float_t         vbfMass_JetSubTotalPtDown;
   Float_t         vbfMass_JetSubTotalPtUp;
   Float_t         vbfMass_JetSubTotalRelativeDown;
   Float_t         vbfMass_JetSubTotalRelativeUp;
   Float_t         vbfMass_JetSubTotalScaleDown;
   Float_t         vbfMass_JetSubTotalScaleUp;
   Float_t         vbfMass_JetTimePtEtaDown;
   Float_t         vbfMass_JetTimePtEtaUp;
   Float_t         vbfMass_JetTotalDown;
   Float_t         vbfMass_JetTotalUp;
   Float_t         vbfNJets20;
   Float_t         vbfNJets20_JetEnDown;
   Float_t         vbfNJets20_JetEnUp;
   Float_t         vbfNJets30;
   Float_t         vbfNJets30_JetEnDown;
   Float_t         vbfNJets30_JetEnUp;
   Float_t         vbfVispt;
   Float_t         vbfVispt_JetEnDown;
   Float_t         vbfVispt_JetEnUp;
   Float_t         vbfdijetpt;
   Float_t         vbfdijetpt_JetEnDown;
   Float_t         vbfdijetpt_JetEnUp;
   Float_t         vbfj1eta;
   Float_t         vbfj1eta_JetEnDown;
   Float_t         vbfj1eta_JetEnUp;
   Float_t         vbfj1pt;
   Float_t         vbfj1pt_JetEnDown;
   Float_t         vbfj1pt_JetEnUp;
   Float_t         vbfj2eta;
   Float_t         vbfj2eta_JetEnDown;
   Float_t         vbfj2eta_JetEnUp;
   Float_t         vbfj2pt;
   Float_t         vbfj2pt_JetEnDown;
   Float_t         vbfj2pt_JetEnUp;
   Float_t         vispX;
   Float_t         vispY;
   Int_t           idx;

   // List of branches
   
   TBranch        *b_EmbPtWeight;   //!
   TBranch        *b_Eta;   //!
   TBranch        *b_Flag_BadChargedCandidateFilter;   //!
   TBranch        *b_Flag_BadPFMuonFilter;   //!
   TBranch        *b_Flag_EcalDeadCellTriggerPrimitiveFilter;   //!
   TBranch        *b_Flag_HBHENoiseFilter;   //!
   TBranch        *b_Flag_HBHENoiseIsoFilter;   //!
   TBranch        *b_Flag_badCloneMuonFilter;   //!
   TBranch        *b_Flag_badGlobalMuonFilter;   //!
   TBranch        *b_Flag_eeBadScFilter;   //!
   TBranch        *b_Flag_globalTightHalo2016Filter;   //!
   TBranch        *b_Flag_goodVertices;   //!
   TBranch        *b_GenWeight;   //!
   TBranch        *b_Ht;   //!
   TBranch        *b_LT;   //!
   TBranch        *b_Mass;   //!
   TBranch        *b_MassError;   //!
   TBranch        *b_MassErrord1;   //!
   TBranch        *b_MassErrord2;   //!
   TBranch        *b_MassErrord3;   //!
   TBranch        *b_MassErrord4;   //!
   TBranch        *b_Mt;   //!
   TBranch        *b_NUP;   //!
   TBranch        *b_Phi;   //!
   TBranch        *b_Pt;   //!
   TBranch        *b_bjetCISVVeto20Loose;   //!
   TBranch        *b_bjetCISVVeto20Medium;   //!
   TBranch        *b_bjetCISVVeto20Tight;   //!
   TBranch        *b_bjetCISVVeto30Loose;   //!
   TBranch        *b_bjetCISVVeto30Medium;   //!
   TBranch        *b_bjetCISVVeto30Tight;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_dielectronVeto;   //!
   TBranch        *b_dimuonVeto;   //!
   TBranch        *b_doubleEGroup;   //!
   TBranch        *b_doubleEPass;   //!
   TBranch        *b_doubleEPrescale;   //!
   TBranch        *b_doubleESingleMuGroup;   //!
   TBranch        *b_doubleESingleMuPass;   //!
   TBranch        *b_doubleESingleMuPrescale;   //!
   TBranch        *b_doubleE_23_12Group;   //!
   TBranch        *b_doubleE_23_12Pass;   //!
   TBranch        *b_doubleE_23_12Prescale;   //!
   TBranch        *b_doubleMuGroup;   //!
   TBranch        *b_doubleMuPass;   //!
   TBranch        *b_doubleMuPrescale;   //!
   TBranch        *b_doubleMuSingleEGroup;   //!
   TBranch        *b_doubleMuSingleEPass;   //!
   TBranch        *b_doubleMuSingleEPrescale;   //!
   TBranch        *b_doubleTau32Group;   //!
   TBranch        *b_doubleTau32Pass;   //!
   TBranch        *b_doubleTau32Prescale;   //!
   TBranch        *b_doubleTau35Group;   //!
   TBranch        *b_doubleTau35Pass;   //!
   TBranch        *b_doubleTau35Prescale;   //!
   TBranch        *b_doubleTau40Group;   //!
   TBranch        *b_doubleTau40Pass;   //!
   TBranch        *b_doubleTau40Prescale;   //!
   TBranch        *b_doubleTauCmbIso35RegGroup;   //!
   TBranch        *b_doubleTauCmbIso35RegPass;   //!
   TBranch        *b_doubleTauCmbIso35RegPrescale;   //!
   TBranch        *b_doubleTauCmbIso40Group;   //!
   TBranch        *b_doubleTauCmbIso40Pass;   //!
   TBranch        *b_doubleTauCmbIso40Prescale;   //!
   TBranch        *b_doubleTauCmbIso40RegGroup;   //!
   TBranch        *b_doubleTauCmbIso40RegPass;   //!
   TBranch        *b_doubleTauCmbIso40RegPrescale;   //!
   TBranch        *b_eVetoMVAIso;   //!
   TBranch        *b_eVetoMVAIsoVtx;   //!
   TBranch        *b_eVetoZTTp001dxyz;   //!
   TBranch        *b_eVetoZTTp001dxyzR0;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_genEta;   //!
   TBranch        *b_genHTT;   //!
   TBranch        *b_genM;   //!
   TBranch        *b_genMass;   //!
   TBranch        *b_genPhi;   //!
   TBranch        *b_genpT;   //!
   TBranch        *b_genpX;   //!
   TBranch        *b_genpY;   //!
   TBranch        *b_isGtautau;   //!
   TBranch        *b_isWenu;   //!
   TBranch        *b_isWmunu;   //!
   TBranch        *b_isWtaunu;   //!
   TBranch        *b_isZee;   //!
   TBranch        *b_isZmumu;   //!
   TBranch        *b_isZtautau;   //!
   TBranch        *b_isdata;   //!
   TBranch        *b_j1csv;   //!
   TBranch        *b_j1eta;   //!
   TBranch        *b_j1hadronflavor;   //!
   TBranch        *b_j1partonflavor;   //!
   TBranch        *b_j1phi;   //!
   TBranch        *b_j1pt;   //!
   TBranch        *b_j1ptDown;   //!
   TBranch        *b_j1ptUp;   //!
   TBranch        *b_j1pu;   //!
   TBranch        *b_j1rawf;   //!
   TBranch        *b_j2csv;   //!
   TBranch        *b_j2eta;   //!
   TBranch        *b_j2hadronflavor;   //!
   TBranch        *b_j2partonflavor;   //!
   TBranch        *b_j2phi;   //!
   TBranch        *b_j2pt;   //!
   TBranch        *b_j2ptDown;   //!
   TBranch        *b_j2ptUp;   //!
   TBranch        *b_j2pu;   //!
   TBranch        *b_j2rawf;   //!
   TBranch        *b_jb1csv;   //!
   TBranch        *b_jb1csv_CSVL;   //!
   TBranch        *b_jb1eta;   //!
   TBranch        *b_jb1eta_CSVL;   //!
   TBranch        *b_jb1hadronflavor;   //!
   TBranch        *b_jb1hadronflavor_CSVL;   //!
   TBranch        *b_jb1partonflavor;   //!
   TBranch        *b_jb1partonflavor_CSVL;   //!
   TBranch        *b_jb1phi;   //!
   TBranch        *b_jb1phi_CSVL;   //!
   TBranch        *b_jb1pt;   //!
   TBranch        *b_jb1ptDown;   //!
   TBranch        *b_jb1ptDown_CSVL;   //!
   TBranch        *b_jb1ptUp;   //!
   TBranch        *b_jb1ptUp_CSVL;   //!
   TBranch        *b_jb1pt_CSVL;   //!
   TBranch        *b_jb1pu;   //!
   TBranch        *b_jb1pu_CSVL;   //!
   TBranch        *b_jb1rawf;   //!
   TBranch        *b_jb1rawf_CSVL;   //!
   TBranch        *b_jb2csv;   //!
   TBranch        *b_jb2csv_CSVL;   //!
   TBranch        *b_jb2eta;   //!
   TBranch        *b_jb2eta_CSVL;   //!
   TBranch        *b_jb2hadronflavor;   //!
   TBranch        *b_jb2hadronflavor_CSVL;   //!
   TBranch        *b_jb2partonflavor;   //!
   TBranch        *b_jb2partonflavor_CSVL;   //!
   TBranch        *b_jb2phi;   //!
   TBranch        *b_jb2phi_CSVL;   //!
   TBranch        *b_jb2pt;   //!
   TBranch        *b_jb2ptDown;   //!
   TBranch        *b_jb2ptDown_CSVL;   //!
   TBranch        *b_jb2ptUp;   //!
   TBranch        *b_jb2ptUp_CSVL;   //!
   TBranch        *b_jb2pt_CSVL;   //!
   TBranch        *b_jb2pu;   //!
   TBranch        *b_jb2pu_CSVL;   //!
   TBranch        *b_jb2rawf;   //!
   TBranch        *b_jb2rawf_CSVL;   //!
   TBranch        *b_jetVeto20;   //!
   TBranch        *b_jetVeto20_JetEnDown;   //!
   TBranch        *b_jetVeto20_JetEnUp;   //!
   TBranch        *b_jetVeto30;   //!
   TBranch        *b_jetVeto30_JetAbsoluteFlavMapDown;   //!
   TBranch        *b_jetVeto30_JetAbsoluteFlavMapUp;   //!
   TBranch        *b_jetVeto30_JetAbsoluteMPFBiasDown;   //!
   TBranch        *b_jetVeto30_JetAbsoluteMPFBiasUp;   //!
   TBranch        *b_jetVeto30_JetAbsoluteScaleDown;   //!
   TBranch        *b_jetVeto30_JetAbsoluteScaleUp;   //!
   TBranch        *b_jetVeto30_JetAbsoluteStatDown;   //!
   TBranch        *b_jetVeto30_JetAbsoluteStatUp;   //!
   TBranch        *b_jetVeto30_JetClosureDown;   //!
   TBranch        *b_jetVeto30_JetClosureUp;   //!
   TBranch        *b_jetVeto30_JetEnDown;   //!
   TBranch        *b_jetVeto30_JetEnUp;   //!
   TBranch        *b_jetVeto30_JetFlavorQCDDown;   //!
   TBranch        *b_jetVeto30_JetFlavorQCDUp;   //!
   TBranch        *b_jetVeto30_JetFragmentationDown;   //!
   TBranch        *b_jetVeto30_JetFragmentationUp;   //!
   TBranch        *b_jetVeto30_JetPileUpDataMCDown;   //!
   TBranch        *b_jetVeto30_JetPileUpDataMCUp;   //!
   TBranch        *b_jetVeto30_JetPileUpPtBBDown;   //!
   TBranch        *b_jetVeto30_JetPileUpPtBBUp;   //!
   TBranch        *b_jetVeto30_JetPileUpPtEC1Down;   //!
   TBranch        *b_jetVeto30_JetPileUpPtEC1Up;   //!
   TBranch        *b_jetVeto30_JetPileUpPtEC2Down;   //!
   TBranch        *b_jetVeto30_JetPileUpPtEC2Up;   //!
   TBranch        *b_jetVeto30_JetPileUpPtHFDown;   //!
   TBranch        *b_jetVeto30_JetPileUpPtHFUp;   //!
   TBranch        *b_jetVeto30_JetPileUpPtRefDown;   //!
   TBranch        *b_jetVeto30_JetPileUpPtRefUp;   //!
   TBranch        *b_jetVeto30_JetRelativeBalDown;   //!
   TBranch        *b_jetVeto30_JetRelativeBalUp;   //!
   TBranch        *b_jetVeto30_JetRelativeFSRDown;   //!
   TBranch        *b_jetVeto30_JetRelativeFSRUp;   //!
   TBranch        *b_jetVeto30_JetRelativeJEREC1Down;   //!
   TBranch        *b_jetVeto30_JetRelativeJEREC1Up;   //!
   TBranch        *b_jetVeto30_JetRelativeJEREC2Down;   //!
   TBranch        *b_jetVeto30_JetRelativeJEREC2Up;   //!
   TBranch        *b_jetVeto30_JetRelativeJERHFDown;   //!
   TBranch        *b_jetVeto30_JetRelativeJERHFUp;   //!
   TBranch        *b_jetVeto30_JetRelativePtBBDown;   //!
   TBranch        *b_jetVeto30_JetRelativePtBBUp;   //!
   TBranch        *b_jetVeto30_JetRelativePtEC1Down;   //!
   TBranch        *b_jetVeto30_JetRelativePtEC1Up;   //!
   TBranch        *b_jetVeto30_JetRelativePtEC2Down;   //!
   TBranch        *b_jetVeto30_JetRelativePtEC2Up;   //!
   TBranch        *b_jetVeto30_JetRelativePtHFDown;   //!
   TBranch        *b_jetVeto30_JetRelativePtHFUp;   //!
   TBranch        *b_jetVeto30_JetRelativeStatECDown;   //!
   TBranch        *b_jetVeto30_JetRelativeStatECUp;   //!
   TBranch        *b_jetVeto30_JetRelativeStatFSRDown;   //!
   TBranch        *b_jetVeto30_JetRelativeStatFSRUp;   //!
   TBranch        *b_jetVeto30_JetRelativeStatHFDown;   //!
   TBranch        *b_jetVeto30_JetRelativeStatHFUp;   //!
   TBranch        *b_jetVeto30_JetSinglePionECALDown;   //!
   TBranch        *b_jetVeto30_JetSinglePionECALUp;   //!
   TBranch        *b_jetVeto30_JetSinglePionHCALDown;   //!
   TBranch        *b_jetVeto30_JetSinglePionHCALUp;   //!
   TBranch        *b_jetVeto30_JetSubTotalAbsoluteDown;   //!
   TBranch        *b_jetVeto30_JetSubTotalAbsoluteUp;   //!
   TBranch        *b_jetVeto30_JetSubTotalMCDown;   //!
   TBranch        *b_jetVeto30_JetSubTotalMCUp;   //!
   TBranch        *b_jetVeto30_JetSubTotalPileUpDown;   //!
   TBranch        *b_jetVeto30_JetSubTotalPileUpUp;   //!
   TBranch        *b_jetVeto30_JetSubTotalPtDown;   //!
   TBranch        *b_jetVeto30_JetSubTotalPtUp;   //!
   TBranch        *b_jetVeto30_JetSubTotalRelativeDown;   //!
   TBranch        *b_jetVeto30_JetSubTotalRelativeUp;   //!
   TBranch        *b_jetVeto30_JetSubTotalScaleDown;   //!
   TBranch        *b_jetVeto30_JetSubTotalScaleUp;   //!
   TBranch        *b_jetVeto30_JetTimePtEtaDown;   //!
   TBranch        *b_jetVeto30_JetTimePtEtaUp;   //!
   TBranch        *b_jetVeto30_JetTotalDown;   //!
   TBranch        *b_jetVeto30_JetTotalUp;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_mAbsEta;   //!
   TBranch        *b_mBestTrackType;   //!
   TBranch        *b_mCharge;   //!
   TBranch        *b_mChi2LocalPosition;   //!
   TBranch        *b_mComesFromHiggs;   //!
   TBranch        *b_mDPhiToPfMet_ElectronEnDown;   //!
   TBranch        *b_mDPhiToPfMet_ElectronEnUp;   //!
   TBranch        *b_mDPhiToPfMet_JetEnDown;   //!
   TBranch        *b_mDPhiToPfMet_JetEnUp;   //!
   TBranch        *b_mDPhiToPfMet_JetResDown;   //!
   TBranch        *b_mDPhiToPfMet_JetResUp;   //!
   TBranch        *b_mDPhiToPfMet_MuonEnDown;   //!
   TBranch        *b_mDPhiToPfMet_MuonEnUp;   //!
   TBranch        *b_mDPhiToPfMet_PhotonEnDown;   //!
   TBranch        *b_mDPhiToPfMet_PhotonEnUp;   //!
   TBranch        *b_mDPhiToPfMet_TauEnDown;   //!
   TBranch        *b_mDPhiToPfMet_TauEnUp;   //!
   TBranch        *b_mDPhiToPfMet_UnclusteredEnDown;   //!
   TBranch        *b_mDPhiToPfMet_UnclusteredEnUp;   //!
   TBranch        *b_mDPhiToPfMet_type1;   //!
   TBranch        *b_mEcalIsoDR03;   //!
   TBranch        *b_mEffectiveArea2011;   //!
   TBranch        *b_mEffectiveArea2012;   //!
   TBranch        *b_mErsatzGenEta;   //!
   TBranch        *b_mErsatzGenM;   //!
   TBranch        *b_mErsatzGenPhi;   //!
   TBranch        *b_mErsatzGenpT;   //!
   TBranch        *b_mErsatzGenpX;   //!
   TBranch        *b_mErsatzGenpY;   //!
   TBranch        *b_mErsatzVispX;   //!
   TBranch        *b_mErsatzVispY;   //!
   TBranch        *b_mEta;   //!
   TBranch        *b_mEta_MuonEnDown;   //!
   TBranch        *b_mEta_MuonEnUp;   //!
   TBranch        *b_mGenCharge;   //!
   TBranch        *b_mGenDirectPromptTauDecayFinalState;   //!
   TBranch        *b_mGenEnergy;   //!
   TBranch        *b_mGenEta;   //!
   TBranch        *b_mGenIsPrompt;   //!
   TBranch        *b_mGenMotherPdgId;   //!
   TBranch        *b_mGenParticle;   //!
   TBranch        *b_mGenPdgId;   //!
   TBranch        *b_mGenPhi;   //!
   TBranch        *b_mGenPrompt;   //!
   TBranch        *b_mGenPromptFinalState;   //!
   TBranch        *b_mGenPromptTauDecay;   //!
   TBranch        *b_mGenPt;   //!
   TBranch        *b_mGenTauDecay;   //!
   TBranch        *b_mGenVZ;   //!
   TBranch        *b_mGenVtxPVMatch;   //!
   TBranch        *b_mHcalIsoDR03;   //!
   TBranch        *b_mIP3D;   //!
   TBranch        *b_mIP3DErr;   //!
   TBranch        *b_mIsGlobal;   //!
   TBranch        *b_mIsPFMuon;   //!
   TBranch        *b_mIsTracker;   //!
   TBranch        *b_mIsoDB03;   //!
   TBranch        *b_mIsoDB04;   //!
   TBranch        *b_mIsoMu22Filter;   //!
   TBranch        *b_mIsoMu22eta2p1Filter;   //!
   TBranch        *b_mIsoMu24Filter;   //!
   TBranch        *b_mIsoMu24eta2p1Filter;   //!
   TBranch        *b_mIsoTkMu22Filter;   //!
   TBranch        *b_mIsoTkMu22eta2p1Filter;   //!
   TBranch        *b_mIsoTkMu24Filter;   //!
   TBranch        *b_mIsoTkMu24eta2p1Filter;   //!
   TBranch        *b_mJetArea;   //!
   TBranch        *b_mJetBtag;   //!
   TBranch        *b_mJetEtaEtaMoment;   //!
   TBranch        *b_mJetEtaPhiMoment;   //!
   TBranch        *b_mJetEtaPhiSpread;   //!
   TBranch        *b_mJetHadronFlavour;   //!
   TBranch        *b_mJetPFCISVBtag;   //!
   TBranch        *b_mJetPartonFlavour;   //!
   TBranch        *b_mJetPhiPhiMoment;   //!
   TBranch        *b_mJetPt;   //!
   TBranch        *b_mLowestMll;   //!
   TBranch        *b_mMass;   //!
   TBranch        *b_mMatchedStations;   //!
   TBranch        *b_mMatchesDoubleESingleMu;   //!
   TBranch        *b_mMatchesDoubleMu;   //!
   TBranch        *b_mMatchesDoubleMuSingleE;   //!
   TBranch        *b_mMatchesIsoMu22Path;   //!
   TBranch        *b_mMatchesIsoMu22eta2p1Path;   //!
   TBranch        *b_mMatchesIsoMu24Path;   //!
   TBranch        *b_mMatchesIsoMu24eta2p1Path;   //!
   TBranch        *b_mMatchesIsoTkMu22Path;   //!
   TBranch        *b_mMatchesIsoTkMu22eta2p1Path;   //!
   TBranch        *b_mMatchesIsoTkMu24Path;   //!
   TBranch        *b_mMatchesIsoTkMu24eta2p1Path;   //!
   TBranch        *b_mMatchesMu19Tau20Filter;   //!
   TBranch        *b_mMatchesMu19Tau20Path;   //!
   TBranch        *b_mMatchesMu19Tau20sL1Filter;   //!
   TBranch        *b_mMatchesMu19Tau20sL1Path;   //!
   TBranch        *b_mMatchesMu21Tau20sL1Filter;   //!
   TBranch        *b_mMatchesMu21Tau20sL1Path;   //!
   TBranch        *b_mMatchesMu23Ele12DZPath;   //!
   TBranch        *b_mMatchesMu23Ele12Path;   //!
   TBranch        *b_mMatchesMu8Ele23DZPath;   //!
   TBranch        *b_mMatchesMu8Ele23Path;   //!
   TBranch        *b_mMatchesSingleESingleMu;   //!
   TBranch        *b_mMatchesSingleMu;   //!
   TBranch        *b_mMatchesSingleMuIso20;   //!
   TBranch        *b_mMatchesSingleMuIsoTk20;   //!
   TBranch        *b_mMatchesSingleMuSingleE;   //!
   TBranch        *b_mMatchesSingleMu_leg1;   //!
   TBranch        *b_mMatchesSingleMu_leg1_noiso;   //!
   TBranch        *b_mMatchesSingleMu_leg2;   //!
   TBranch        *b_mMatchesSingleMu_leg2_noiso;   //!
   TBranch        *b_mMatchesTripleMu;   //!
   TBranch        *b_mMtToPfMet_ElectronEnDown;   //!
   TBranch        *b_mMtToPfMet_ElectronEnUp;   //!
   TBranch        *b_mMtToPfMet_JetEnDown;   //!
   TBranch        *b_mMtToPfMet_JetEnUp;   //!
   TBranch        *b_mMtToPfMet_JetResDown;   //!
   TBranch        *b_mMtToPfMet_JetResUp;   //!
   TBranch        *b_mMtToPfMet_MuonEnDown;   //!
   TBranch        *b_mMtToPfMet_MuonEnUp;   //!
   TBranch        *b_mMtToPfMet_PhotonEnDown;   //!
   TBranch        *b_mMtToPfMet_PhotonEnUp;   //!
   TBranch        *b_mMtToPfMet_Raw;   //!
   TBranch        *b_mMtToPfMet_TauEnDown;   //!
   TBranch        *b_mMtToPfMet_TauEnUp;   //!
   TBranch        *b_mMtToPfMet_UnclusteredEnDown;   //!
   TBranch        *b_mMtToPfMet_UnclusteredEnUp;   //!
   TBranch        *b_mMtToPfMet_type1;   //!
   TBranch        *b_mMu23Ele12DZFilter;   //!
   TBranch        *b_mMu23Ele12Filter;   //!
   TBranch        *b_mMu8Ele23DZFilter;   //!
   TBranch        *b_mMu8Ele23Filter;   //!
   TBranch        *b_mMuonHits;   //!
   TBranch        *b_mNearestZMass;   //!
   TBranch        *b_mNormTrkChi2;   //!
   TBranch        *b_mNormalizedChi2;   //!
   TBranch        *b_mPFChargedHadronIsoR04;   //!
   TBranch        *b_mPFChargedIso;   //!
   TBranch        *b_mPFIDLoose;   //!
   TBranch        *b_mPFIDMedium;   //!
   TBranch        *b_mPFIDTight;   //!
   TBranch        *b_mPFNeutralHadronIsoR04;   //!
   TBranch        *b_mPFNeutralIso;   //!
   TBranch        *b_mPFPUChargedIso;   //!
   TBranch        *b_mPFPhotonIso;   //!
   TBranch        *b_mPFPhotonIsoR04;   //!
   TBranch        *b_mPFPileupIsoR04;   //!
   TBranch        *b_mPVDXY;   //!
   TBranch        *b_mPVDZ;   //!
   TBranch        *b_mPhi;   //!
   TBranch        *b_mPhi_MuonEnDown;   //!
   TBranch        *b_mPhi_MuonEnUp;   //!
   TBranch        *b_mPixHits;   //!
   TBranch        *b_mPt;   //!
   TBranch        *b_mPt_MuonEnDown;   //!
   TBranch        *b_mPt_MuonEnUp;   //!
   TBranch        *b_mRank;   //!
   TBranch        *b_mRelPFIsoDBDefault;   //!
   TBranch        *b_mRelPFIsoDBDefaultR04;   //!
   TBranch        *b_mRelPFIsoRho;   //!
   TBranch        *b_mRho;   //!
   TBranch        *b_mSIP2D;   //!
   TBranch        *b_mSIP3D;   //!
   TBranch        *b_mSegmentCompatibility;   //!
   TBranch        *b_mTkLayersWithMeasurement;   //!
   TBranch        *b_mTrkIsoDR03;   //!
   TBranch        *b_mTrkKink;   //!
   TBranch        *b_mTypeCode;   //!
   TBranch        *b_mVZ;   //!
   TBranch        *b_mValidFraction;   //!
   TBranch        *b_mZTTGenMatching;   //!
   TBranch        *b_m_t_CosThetaStar;   //!
   TBranch        *b_m_t_DPhi;   //!
   TBranch        *b_m_t_DR;   //!
   TBranch        *b_m_t_Eta;   //!
   TBranch        *b_m_t_Mass;   //!
   TBranch        *b_m_t_Mass_TauEnDown;   //!
   TBranch        *b_m_t_Mass_TauEnUp;   //!
   TBranch        *b_m_t_Mt;   //!
   TBranch        *b_m_t_MtTotal;   //!
   TBranch        *b_m_t_Mt_TauEnDown;   //!
   TBranch        *b_m_t_Mt_TauEnUp;   //!
   TBranch        *b_m_t_MvaMet;   //!
   TBranch        *b_m_t_MvaMetCovMatrix00;   //!
   TBranch        *b_m_t_MvaMetCovMatrix01;   //!
   TBranch        *b_m_t_MvaMetCovMatrix10;   //!
   TBranch        *b_m_t_MvaMetCovMatrix11;   //!
   TBranch        *b_m_t_MvaMetPhi;   //!
   TBranch        *b_m_t_PZeta;   //!
   TBranch        *b_m_t_PZetaLess0p85PZetaVis;   //!
   TBranch        *b_m_t_PZetaVis;   //!
   TBranch        *b_m_t_Phi;   //!
   TBranch        *b_m_t_Pt;   //!
   TBranch        *b_m_t_SS;   //!
   TBranch        *b_m_t_ToMETDPhi_Ty1;   //!
   TBranch        *b_m_t_collinearmass;   //!
   TBranch        *b_m_t_collinearmass_EleEnDown;   //!
   TBranch        *b_m_t_collinearmass_EleEnUp;   //!
   TBranch        *b_m_t_collinearmass_JetEnDown;   //!
   TBranch        *b_m_t_collinearmass_JetEnUp;   //!
   TBranch        *b_m_t_collinearmass_MuEnDown;   //!
   TBranch        *b_m_t_collinearmass_MuEnUp;   //!
   TBranch        *b_m_t_collinearmass_TauEnDown;   //!
   TBranch        *b_m_t_collinearmass_TauEnUp;   //!
   TBranch        *b_m_t_collinearmass_UnclusteredEnDown;   //!
   TBranch        *b_m_t_collinearmass_UnclusteredEnUp;   //!
   TBranch        *b_m_t_pt_tt;   //!
   TBranch        *b_metSig;   //!
   TBranch        *b_metcov00;   //!
   TBranch        *b_metcov01;   //!
   TBranch        *b_metcov10;   //!
   TBranch        *b_metcov11;   //!
   TBranch        *b_metcov00_DESYlike;   //!
   TBranch        *b_metcov01_DESYlike;   //!
   TBranch        *b_metcov10_DESYlike;   //!
   TBranch        *b_metcov11_DESYlike;   //!
   TBranch        *b_muGlbIsoVetoPt10;   //!
   TBranch        *b_muVetoPt15IsoIdVtx;   //!
   TBranch        *b_muVetoPt5;   //!
   TBranch        *b_muVetoPt5IsoIdVtx;   //!
   TBranch        *b_muVetoZTTp001dxyz;   //!
   TBranch        *b_muVetoZTTp001dxyzR0;   //!
   TBranch        *b_nTruePU;   //!
   TBranch        *b_numGenJets;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_processID;   //!
   TBranch        *b_puppiMetEt;   //!
   TBranch        *b_puppiMetPhi;   //!
   TBranch        *b_pvChi2;   //!
   TBranch        *b_pvDX;   //!
   TBranch        *b_pvDY;   //!
   TBranch        *b_pvDZ;   //!
   TBranch        *b_pvIsFake;   //!
   TBranch        *b_pvIsValid;   //!
   TBranch        *b_pvNormChi2;   //!
   TBranch        *b_pvRho;   //!
   TBranch        *b_pvX;   //!
   TBranch        *b_pvY;   //!
   TBranch        *b_pvZ;   //!
   TBranch        *b_pvndof;   //!
   TBranch        *b_raw_pfMetEt;   //!
   TBranch        *b_raw_pfMetPhi;   //!
   TBranch        *b_recoilDaught;   //!
   TBranch        *b_recoilWithMet;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_run;   //!
   TBranch        *b_singleE17SingleMu8Group;   //!
   TBranch        *b_singleE17SingleMu8Pass;   //!
   TBranch        *b_singleE17SingleMu8Prescale;   //!
   TBranch        *b_singleE20SingleTau28Group;   //!
   TBranch        *b_singleE20SingleTau28Pass;   //!
   TBranch        *b_singleE20SingleTau28Prescale;   //!
   TBranch        *b_singleE22SingleTau20SingleL1Group;   //!
   TBranch        *b_singleE22SingleTau20SingleL1Pass;   //!
   TBranch        *b_singleE22SingleTau20SingleL1Prescale;   //!
   TBranch        *b_singleE22SingleTau29Group;   //!
   TBranch        *b_singleE22SingleTau29Pass;   //!
   TBranch        *b_singleE22SingleTau29Prescale;   //!
   TBranch        *b_singleE23SingleMu8Group;   //!
   TBranch        *b_singleE23SingleMu8Pass;   //!
   TBranch        *b_singleE23SingleMu8Prescale;   //!
   TBranch        *b_singleE24SingleTau20Group;   //!
   TBranch        *b_singleE24SingleTau20Pass;   //!
   TBranch        *b_singleE24SingleTau20Prescale;   //!
   TBranch        *b_singleE24SingleTau20SingleL1Group;   //!
   TBranch        *b_singleE24SingleTau20SingleL1Pass;   //!
   TBranch        *b_singleE24SingleTau20SingleL1Prescale;   //!
   TBranch        *b_singleE24SingleTau30Group;   //!
   TBranch        *b_singleE24SingleTau30Pass;   //!
   TBranch        *b_singleE24SingleTau30Prescale;   //!
   TBranch        *b_singleE25eta2p1TightGroup;   //!
   TBranch        *b_singleE25eta2p1TightPass;   //!
   TBranch        *b_singleE25eta2p1TightPrescale;   //!
   TBranch        *b_singleE27SingleTau20SingleL1Group;   //!
   TBranch        *b_singleE27SingleTau20SingleL1Pass;   //!
   TBranch        *b_singleE27SingleTau20SingleL1Prescale;   //!
   TBranch        *b_singleE27TightGroup;   //!
   TBranch        *b_singleE27TightPass;   //!
   TBranch        *b_singleE27TightPrescale;   //!
   TBranch        *b_singleE27eta2p1LooseGroup;   //!
   TBranch        *b_singleE27eta2p1LoosePass;   //!
   TBranch        *b_singleE27eta2p1LoosePrescale;   //!
   TBranch        *b_singleE27eta2p1TightGroup;   //!
   TBranch        *b_singleE27eta2p1TightPass;   //!
   TBranch        *b_singleE27eta2p1TightPrescale;   //!
   TBranch        *b_singleE32SingleTau20SingleL1Group;   //!
   TBranch        *b_singleE32SingleTau20SingleL1Pass;   //!
   TBranch        *b_singleE32SingleTau20SingleL1Prescale;   //!
   TBranch        *b_singleE36SingleTau30Group;   //!
   TBranch        *b_singleE36SingleTau30Pass;   //!
   TBranch        *b_singleE36SingleTau30Prescale;   //!
   TBranch        *b_singleESingleMuGroup;   //!
   TBranch        *b_singleESingleMuPass;   //!
   TBranch        *b_singleESingleMuPrescale;   //!
   TBranch        *b_singleE_leg1Group;   //!
   TBranch        *b_singleE_leg1Pass;   //!
   TBranch        *b_singleE_leg1Prescale;   //!
   TBranch        *b_singleE_leg2Group;   //!
   TBranch        *b_singleE_leg2Pass;   //!
   TBranch        *b_singleE_leg2Prescale;   //!
   TBranch        *b_singleIsoMu20Group;   //!
   TBranch        *b_singleIsoMu20Pass;   //!
   TBranch        *b_singleIsoMu20Prescale;   //!
   TBranch        *b_singleIsoMu22Group;   //!
   TBranch        *b_singleIsoMu22Pass;   //!
   TBranch        *b_singleIsoMu22Prescale;   //!
   TBranch        *b_singleIsoMu22eta2p1Group;   //!
   TBranch        *b_singleIsoMu22eta2p1Pass;   //!
   TBranch        *b_singleIsoMu22eta2p1Prescale;   //!
   TBranch        *b_singleIsoMu24Group;   //!
   TBranch        *b_singleIsoMu24Pass;   //!
   TBranch        *b_singleIsoMu24Prescale;   //!
   TBranch        *b_singleIsoMu24eta2p1Group;   //!
   TBranch        *b_singleIsoMu24eta2p1Pass;   //!
   TBranch        *b_singleIsoMu24eta2p1Prescale;   //!
   TBranch        *b_singleIsoMu27Group;   //!
   TBranch        *b_singleIsoMu27Pass;   //!
   TBranch        *b_singleIsoMu27Prescale;   //!
   TBranch        *b_singleIsoTkMu20Group;   //!
   TBranch        *b_singleIsoTkMu20Pass;   //!
   TBranch        *b_singleIsoTkMu20Prescale;   //!
   TBranch        *b_singleIsoTkMu22Group;   //!
   TBranch        *b_singleIsoTkMu22Pass;   //!
   TBranch        *b_singleIsoTkMu22Prescale;   //!
   TBranch        *b_singleIsoTkMu22eta2p1Group;   //!
   TBranch        *b_singleIsoTkMu22eta2p1Pass;   //!
   TBranch        *b_singleIsoTkMu22eta2p1Prescale;   //!
   TBranch        *b_singleIsoTkMu24Group;   //!
   TBranch        *b_singleIsoTkMu24Pass;   //!
   TBranch        *b_singleIsoTkMu24Prescale;   //!
   TBranch        *b_singleIsoTkMu24eta2p1Group;   //!
   TBranch        *b_singleIsoTkMu24eta2p1Pass;   //!
   TBranch        *b_singleIsoTkMu24eta2p1Prescale;   //!
   TBranch        *b_singleMu17SingleE12Group;   //!
   TBranch        *b_singleMu17SingleE12Pass;   //!
   TBranch        *b_singleMu17SingleE12Prescale;   //!
   TBranch        *b_singleMu19eta2p1LooseTau20Group;   //!
   TBranch        *b_singleMu19eta2p1LooseTau20Pass;   //!
   TBranch        *b_singleMu19eta2p1LooseTau20Prescale;   //!
   TBranch        *b_singleMu19eta2p1LooseTau20singleL1Group;   //!
   TBranch        *b_singleMu19eta2p1LooseTau20singleL1Pass;   //!
   TBranch        *b_singleMu19eta2p1LooseTau20singleL1Prescale;   //!
   TBranch        *b_singleMu21eta2p1LooseTau20singleL1Group;   //!
   TBranch        *b_singleMu21eta2p1LooseTau20singleL1Pass;   //!
   TBranch        *b_singleMu21eta2p1LooseTau20singleL1Prescale;   //!
   TBranch        *b_singleMu23SingleE12DZGroup;   //!
   TBranch        *b_singleMu23SingleE12DZPass;   //!
   TBranch        *b_singleMu23SingleE12DZPrescale;   //!
   TBranch        *b_singleMu23SingleE12Group;   //!
   TBranch        *b_singleMu23SingleE12Pass;   //!
   TBranch        *b_singleMu23SingleE12Prescale;   //!
   TBranch        *b_singleMu23SingleE8Group;   //!
   TBranch        *b_singleMu23SingleE8Pass;   //!
   TBranch        *b_singleMu23SingleE8Prescale;   //!
   TBranch        *b_singleMu8SingleE23DZGroup;   //!
   TBranch        *b_singleMu8SingleE23DZPass;   //!
   TBranch        *b_singleMu8SingleE23DZPrescale;   //!
   TBranch        *b_singleMuGroup;   //!
   TBranch        *b_singleMuPass;   //!
   TBranch        *b_singleMuPrescale;   //!
   TBranch        *b_singleMuSingleEGroup;   //!
   TBranch        *b_singleMuSingleEPass;   //!
   TBranch        *b_singleMuSingleEPrescale;   //!
   TBranch        *b_singleMu_leg1Group;   //!
   TBranch        *b_singleMu_leg1Pass;   //!
   TBranch        *b_singleMu_leg1Prescale;   //!
   TBranch        *b_singleMu_leg1_noisoGroup;   //!
   TBranch        *b_singleMu_leg1_noisoPass;   //!
   TBranch        *b_singleMu_leg1_noisoPrescale;   //!
   TBranch        *b_singleMu_leg2Group;   //!
   TBranch        *b_singleMu_leg2Pass;   //!
   TBranch        *b_singleMu_leg2Prescale;   //!
   TBranch        *b_singleMu_leg2_noisoGroup;   //!
   TBranch        *b_singleMu_leg2_noisoPass;   //!
   TBranch        *b_singleMu_leg2_noisoPrescale;   //!
   TBranch        *b_singleTau140Group;   //!
   TBranch        *b_singleTau140Pass;   //!
   TBranch        *b_singleTau140Prescale;   //!
   TBranch        *b_singleTau140Trk50Group;   //!
   TBranch        *b_singleTau140Trk50Pass;   //!
   TBranch        *b_singleTau140Trk50Prescale;   //!
   TBranch        *b_tAbsEta;   //!
   TBranch        *b_tAgainstElectronLooseMVA6;   //!
   TBranch        *b_tAgainstElectronMVA6Raw;   //!
   TBranch        *b_tAgainstElectronMVA6category;   //!
   TBranch        *b_tAgainstElectronMediumMVA6;   //!
   TBranch        *b_tAgainstElectronTightMVA6;   //!
   TBranch        *b_tAgainstElectronVLooseMVA6;   //!
   TBranch        *b_tAgainstElectronVTightMVA6;   //!
   TBranch        *b_tAgainstMuonLoose3;   //!
   TBranch        *b_tAgainstMuonTight3;   //!
   TBranch        *b_tByCombinedIsolationDeltaBetaCorrRaw3Hits;   //!
   TBranch        *b_tByIsolationMVArun2v1DBdR03oldDMwLTraw;   //!
   TBranch        *b_tByIsolationMVArun2v1DBnewDMwLTraw;   //!
   TBranch        *b_tByIsolationMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_tByIsolationMVArun2v1PWdR03oldDMwLTraw;   //!
   TBranch        *b_tByIsolationMVArun2v1PWnewDMwLTraw;   //!
   TBranch        *b_tByIsolationMVArun2v1PWoldDMwLTraw;   //!
   TBranch        *b_tByLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tByMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tByPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_tByTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_tCharge;   //!
   TBranch        *b_tChargedIsoPtSum;   //!
   TBranch        *b_tChargedIsoPtSumdR03;   //!
   TBranch        *b_tComesFromHiggs;   //!
   TBranch        *b_tDPhiToPfMet_ElectronEnDown;   //!
   TBranch        *b_tDPhiToPfMet_ElectronEnUp;   //!
   TBranch        *b_tDPhiToPfMet_JetEnDown;   //!
   TBranch        *b_tDPhiToPfMet_JetEnUp;   //!
   TBranch        *b_tDPhiToPfMet_JetResDown;   //!
   TBranch        *b_tDPhiToPfMet_JetResUp;   //!
   TBranch        *b_tDPhiToPfMet_MuonEnDown;   //!
   TBranch        *b_tDPhiToPfMet_MuonEnUp;   //!
   TBranch        *b_tDPhiToPfMet_PhotonEnDown;   //!
   TBranch        *b_tDPhiToPfMet_PhotonEnUp;   //!
   TBranch        *b_tDPhiToPfMet_TauEnDown;   //!
   TBranch        *b_tDPhiToPfMet_TauEnUp;   //!
   TBranch        *b_tDPhiToPfMet_UnclusteredEnDown;   //!
   TBranch        *b_tDPhiToPfMet_UnclusteredEnUp;   //!
   TBranch        *b_tDPhiToPfMet_type1;   //!
   TBranch        *b_tDecayMode;   //!
   TBranch        *b_tDecayModeFinding;   //!
   TBranch        *b_tDecayModeFindingNewDMs;   //!
   TBranch        *b_tElecOverlap;   //!
   TBranch        *b_tEta;   //!
   TBranch        *b_tEta_TauEnDown;   //!
   TBranch        *b_tEta_TauEnUp;   //!
   TBranch        *b_tFootprintCorrection;   //!
   TBranch        *b_tFootprintCorrectiondR03;   //!
   TBranch        *b_tGenCharge;   //!
   TBranch        *b_tGenDecayMode;   //!
   TBranch        *b_tGenEnergy;   //!
   TBranch        *b_tGenEta;   //!
   TBranch        *b_tGenIsPrompt;   //!
   TBranch        *b_tGenJetEta;   //!
   TBranch        *b_tGenJetPt;   //!
   TBranch        *b_tGenMotherEnergy;   //!
   TBranch        *b_tGenMotherEta;   //!
   TBranch        *b_tGenMotherPdgId;   //!
   TBranch        *b_tGenMotherPhi;   //!
   TBranch        *b_tGenMotherPt;   //!
   TBranch        *b_tGenPdgId;   //!
   TBranch        *b_tGenPhi;   //!
   TBranch        *b_tGenPt;   //!
   TBranch        *b_tGenStatus;   //!
   TBranch        *b_tGlobalMuonVtxOverlap;   //!
   TBranch        *b_tJetArea;   //!
   TBranch        *b_tJetBtag;   //!
   TBranch        *b_tJetEtaEtaMoment;   //!
   TBranch        *b_tJetEtaPhiMoment;   //!
   TBranch        *b_tJetEtaPhiSpread;   //!
   TBranch        *b_tJetHadronFlavour;   //!
   TBranch        *b_tJetPFCISVBtag;   //!
   TBranch        *b_tJetPartonFlavour;   //!
   TBranch        *b_tJetPhiPhiMoment;   //!
   TBranch        *b_tJetPt;   //!
   TBranch        *b_tLeadTrackPt;   //!
   TBranch        *b_tLowestMll;   //!
   TBranch        *b_tMass;   //!
   TBranch        *b_tMass_TauEnDown;   //!
   TBranch        *b_tMass_TauEnUp;   //!
   TBranch        *b_tMatchesDoubleTau32Filter;   //!
   TBranch        *b_tMatchesDoubleTau32Path;   //!
   TBranch        *b_tMatchesDoubleTau35Filter;   //!
   TBranch        *b_tMatchesDoubleTau35Path;   //!
   TBranch        *b_tMatchesDoubleTau40Filter;   //!
   TBranch        *b_tMatchesDoubleTau40Path;   //!
   TBranch        *b_tMatchesDoubleTauCmbIso35RegFilter;   //!
   TBranch        *b_tMatchesDoubleTauCmbIso35RegPath;   //!
   TBranch        *b_tMatchesDoubleTauCmbIso40Filter;   //!
   TBranch        *b_tMatchesDoubleTauCmbIso40Path;   //!
   TBranch        *b_tMatchesDoubleTauCmbIso40RegFilter;   //!
   TBranch        *b_tMatchesDoubleTauCmbIso40RegPath;   //!
   TBranch        *b_tMatchesEle24Tau20Filter;   //!
   TBranch        *b_tMatchesEle24Tau20L1Path;   //!
   TBranch        *b_tMatchesEle24Tau20Path;   //!
   TBranch        *b_tMatchesEle24Tau20sL1Filter;   //!
   TBranch        *b_tMatchesEle24Tau30Filter;   //!
   TBranch        *b_tMatchesEle24Tau30Path;   //!
   TBranch        *b_tMatchesMu19Tau20Filter;   //!
   TBranch        *b_tMatchesMu19Tau20Path;   //!
   TBranch        *b_tMatchesMu19Tau20sL1Filter;   //!
   TBranch        *b_tMatchesMu19Tau20sL1Path;   //!
   TBranch        *b_tMatchesMu21Tau20sL1Filter;   //!
   TBranch        *b_tMatchesMu21Tau20sL1Path;   //!
   TBranch        *b_tMtToPfMet_ElectronEnDown;   //!
   TBranch        *b_tMtToPfMet_ElectronEnUp;   //!
   TBranch        *b_tMtToPfMet_JetEnDown;   //!
   TBranch        *b_tMtToPfMet_JetEnUp;   //!
   TBranch        *b_tMtToPfMet_JetResDown;   //!
   TBranch        *b_tMtToPfMet_JetResUp;   //!
   TBranch        *b_tMtToPfMet_MuonEnDown;   //!
   TBranch        *b_tMtToPfMet_MuonEnUp;   //!
   TBranch        *b_tMtToPfMet_PhotonEnDown;   //!
   TBranch        *b_tMtToPfMet_PhotonEnUp;   //!
   TBranch        *b_tMtToPfMet_Raw;   //!
   TBranch        *b_tMtToPfMet_TauEnDown;   //!
   TBranch        *b_tMtToPfMet_TauEnUp;   //!
   TBranch        *b_tMtToPfMet_UnclusteredEnDown;   //!
   TBranch        *b_tMtToPfMet_UnclusteredEnUp;   //!
   TBranch        *b_tMtToPfMet_type1;   //!
   TBranch        *b_tMuOverlap;   //!
   TBranch        *b_tMuonIdIsoStdVtxOverlap;   //!
   TBranch        *b_tMuonIdIsoVtxOverlap;   //!
   TBranch        *b_tMuonIdVtxOverlap;   //!
   TBranch        *b_tNChrgHadrIsolationCands;   //!
   TBranch        *b_tNChrgHadrSignalCands;   //!
   TBranch        *b_tNGammaSignalCands;   //!
   TBranch        *b_tNNeutralHadrSignalCands;   //!
   TBranch        *b_tNSignalCands;   //!
   TBranch        *b_tNearestZMass;   //!
   TBranch        *b_tNeutralIsoPtSum;   //!
   TBranch        *b_tNeutralIsoPtSumWeight;   //!
   TBranch        *b_tNeutralIsoPtSumWeightdR03;   //!
   TBranch        *b_tNeutralIsoPtSumdR03;   //!
   TBranch        *b_tPVDXY;   //!
   TBranch        *b_tPVDZ;   //!
   TBranch        *b_tPhi;   //!
   TBranch        *b_tPhi_TauEnDown;   //!
   TBranch        *b_tPhi_TauEnUp;   //!
   TBranch        *b_tPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_tPhotonPtSumOutsideSignalConedR03;   //!
   TBranch        *b_tPt;   //!
   TBranch        *b_tPt_TauEnDown;   //!
   TBranch        *b_tPt_TauEnUp;   //!
   TBranch        *b_tPuCorrPtSum;   //!
   TBranch        *b_tRank;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTLoose;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTMedium;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTTight;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTVLoose;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTVTight;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTVVTight;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_tVZ;   //!
   TBranch        *b_tZTTGenDR;   //!
   TBranch        *b_tZTTGenEta;   //!
   TBranch        *b_tZTTGenMatching;   //!
   TBranch        *b_tZTTGenPhi;   //!
   TBranch        *b_tZTTGenPt;   //!
   TBranch        *b_t_m_collinearmass;   //!
   TBranch        *b_t_m_collinearmass_JetEnDown;   //!
   TBranch        *b_t_m_collinearmass_JetEnUp;   //!
   TBranch        *b_t_m_collinearmass_UnclusteredEnDown;   //!
   TBranch        *b_t_m_collinearmass_UnclusteredEnUp;   //!
   TBranch        *b_tauVetoPt20Loose3HitsVtx;   //!
   TBranch        *b_tauVetoPt20TightMVALTVtx;   //!
   TBranch        *b_topQuarkPt1;   //!
   TBranch        *b_topQuarkPt2;   //!
   TBranch        *b_tripleEGroup;   //!
   TBranch        *b_tripleEPass;   //!
   TBranch        *b_tripleEPrescale;   //!
   TBranch        *b_tripleMuGroup;   //!
   TBranch        *b_tripleMuPass;   //!
   TBranch        *b_tripleMuPrescale;   //!
   TBranch        *b_type1_pfMetEt;   //!
   TBranch        *b_type1_pfMetPhi;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_ElectronEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_ElectronEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetResDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetResUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_MuonEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_MuonEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_PhotonEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_PhotonEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_TauEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_TauEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_UnclusteredEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_UnclusteredEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_ElectronEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_ElectronEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetResDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetResUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_MuonEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_MuonEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_PhotonEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_PhotonEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_TauEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_TauEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_UnclusteredEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_UnclusteredEnUp;   //!
   TBranch        *b_vbfDeta;   //!
   TBranch        *b_vbfDeta_JetEnDown;   //!
   TBranch        *b_vbfDeta_JetEnUp;   //!
   TBranch        *b_vbfDijetrap;   //!
   TBranch        *b_vbfDijetrap_JetEnDown;   //!
   TBranch        *b_vbfDijetrap_JetEnUp;   //!
   TBranch        *b_vbfDphi;   //!
   TBranch        *b_vbfDphi_JetEnDown;   //!
   TBranch        *b_vbfDphi_JetEnUp;   //!
   TBranch        *b_vbfDphihj;   //!
   TBranch        *b_vbfDphihj_JetEnDown;   //!
   TBranch        *b_vbfDphihj_JetEnUp;   //!
   TBranch        *b_vbfDphihjnomet;   //!
   TBranch        *b_vbfDphihjnomet_JetEnDown;   //!
   TBranch        *b_vbfDphihjnomet_JetEnUp;   //!
   TBranch        *b_vbfHrap;   //!
   TBranch        *b_vbfHrap_JetEnDown;   //!
   TBranch        *b_vbfHrap_JetEnUp;   //!
   TBranch        *b_vbfJetVeto20;   //!
   TBranch        *b_vbfJetVeto20_JetEnDown;   //!
   TBranch        *b_vbfJetVeto20_JetEnUp;   //!
   TBranch        *b_vbfJetVeto30;   //!
   TBranch        *b_vbfJetVeto30_JetEnDown;   //!
   TBranch        *b_vbfJetVeto30_JetEnUp;   //!
   TBranch        *b_vbfMVA;   //!
   TBranch        *b_vbfMVA_JetEnDown;   //!
   TBranch        *b_vbfMVA_JetEnUp;   //!
   TBranch        *b_vbfMass;   //!
   TBranch        *b_vbfMass_JetAbsoluteFlavMapDown;   //!
   TBranch        *b_vbfMass_JetAbsoluteFlavMapUp;   //!
   TBranch        *b_vbfMass_JetAbsoluteMPFBiasDown;   //!
   TBranch        *b_vbfMass_JetAbsoluteMPFBiasUp;   //!
   TBranch        *b_vbfMass_JetAbsoluteScaleDown;   //!
   TBranch        *b_vbfMass_JetAbsoluteScaleUp;   //!
   TBranch        *b_vbfMass_JetAbsoluteStatDown;   //!
   TBranch        *b_vbfMass_JetAbsoluteStatUp;   //!
   TBranch        *b_vbfMass_JetClosureDown;   //!
   TBranch        *b_vbfMass_JetClosureUp;   //!
   TBranch        *b_vbfMass_JetEnDown;   //!
   TBranch        *b_vbfMass_JetEnUp;   //!
   TBranch        *b_vbfMass_JetFlavorQCDDown;   //!
   TBranch        *b_vbfMass_JetFlavorQCDUp;   //!
   TBranch        *b_vbfMass_JetFragmentationDown;   //!
   TBranch        *b_vbfMass_JetFragmentationUp;   //!
   TBranch        *b_vbfMass_JetPileUpDataMCDown;   //!
   TBranch        *b_vbfMass_JetPileUpDataMCUp;   //!
   TBranch        *b_vbfMass_JetPileUpPtBBDown;   //!
   TBranch        *b_vbfMass_JetPileUpPtBBUp;   //!
   TBranch        *b_vbfMass_JetPileUpPtEC1Down;   //!
   TBranch        *b_vbfMass_JetPileUpPtEC1Up;   //!
   TBranch        *b_vbfMass_JetPileUpPtEC2Down;   //!
   TBranch        *b_vbfMass_JetPileUpPtEC2Up;   //!
   TBranch        *b_vbfMass_JetPileUpPtHFDown;   //!
   TBranch        *b_vbfMass_JetPileUpPtHFUp;   //!
   TBranch        *b_vbfMass_JetPileUpPtRefDown;   //!
   TBranch        *b_vbfMass_JetPileUpPtRefUp;   //!
   TBranch        *b_vbfMass_JetRelativeBalDown;   //!
   TBranch        *b_vbfMass_JetRelativeBalUp;   //!
   TBranch        *b_vbfMass_JetRelativeFSRDown;   //!
   TBranch        *b_vbfMass_JetRelativeFSRUp;   //!
   TBranch        *b_vbfMass_JetRelativeJEREC1Down;   //!
   TBranch        *b_vbfMass_JetRelativeJEREC1Up;   //!
   TBranch        *b_vbfMass_JetRelativeJEREC2Down;   //!
   TBranch        *b_vbfMass_JetRelativeJEREC2Up;   //!
   TBranch        *b_vbfMass_JetRelativeJERHFDown;   //!
   TBranch        *b_vbfMass_JetRelativeJERHFUp;   //!
   TBranch        *b_vbfMass_JetRelativePtBBDown;   //!
   TBranch        *b_vbfMass_JetRelativePtBBUp;   //!
   TBranch        *b_vbfMass_JetRelativePtEC1Down;   //!
   TBranch        *b_vbfMass_JetRelativePtEC1Up;   //!
   TBranch        *b_vbfMass_JetRelativePtEC2Down;   //!
   TBranch        *b_vbfMass_JetRelativePtEC2Up;   //!
   TBranch        *b_vbfMass_JetRelativePtHFDown;   //!
   TBranch        *b_vbfMass_JetRelativePtHFUp;   //!
   TBranch        *b_vbfMass_JetRelativeStatECDown;   //!
   TBranch        *b_vbfMass_JetRelativeStatECUp;   //!
   TBranch        *b_vbfMass_JetRelativeStatFSRDown;   //!
   TBranch        *b_vbfMass_JetRelativeStatFSRUp;   //!
   TBranch        *b_vbfMass_JetRelativeStatHFDown;   //!
   TBranch        *b_vbfMass_JetRelativeStatHFUp;   //!
   TBranch        *b_vbfMass_JetSinglePionECALDown;   //!
   TBranch        *b_vbfMass_JetSinglePionECALUp;   //!
   TBranch        *b_vbfMass_JetSinglePionHCALDown;   //!
   TBranch        *b_vbfMass_JetSinglePionHCALUp;   //!
   TBranch        *b_vbfMass_JetSubTotalAbsoluteDown;   //!
   TBranch        *b_vbfMass_JetSubTotalAbsoluteUp;   //!
   TBranch        *b_vbfMass_JetSubTotalMCDown;   //!
   TBranch        *b_vbfMass_JetSubTotalMCUp;   //!
   TBranch        *b_vbfMass_JetSubTotalPileUpDown;   //!
   TBranch        *b_vbfMass_JetSubTotalPileUpUp;   //!
   TBranch        *b_vbfMass_JetSubTotalPtDown;   //!
   TBranch        *b_vbfMass_JetSubTotalPtUp;   //!
   TBranch        *b_vbfMass_JetSubTotalRelativeDown;   //!
   TBranch        *b_vbfMass_JetSubTotalRelativeUp;   //!
   TBranch        *b_vbfMass_JetSubTotalScaleDown;   //!
   TBranch        *b_vbfMass_JetSubTotalScaleUp;   //!
   TBranch        *b_vbfMass_JetTimePtEtaDown;   //!
   TBranch        *b_vbfMass_JetTimePtEtaUp;   //!
   TBranch        *b_vbfMass_JetTotalDown;   //!
   TBranch        *b_vbfMass_JetTotalUp;   //!
   TBranch        *b_vbfNJets20;   //!
   TBranch        *b_vbfNJets20_JetEnDown;   //!
   TBranch        *b_vbfNJets20_JetEnUp;   //!
   TBranch        *b_vbfNJets30;   //!
   TBranch        *b_vbfNJets30_JetEnDown;   //!
   TBranch        *b_vbfNJets30_JetEnUp;   //!
   TBranch        *b_vbfVispt;   //!
   TBranch        *b_vbfVispt_JetEnDown;   //!
   TBranch        *b_vbfVispt_JetEnUp;   //!
   TBranch        *b_vbfdijetpt;   //!
   TBranch        *b_vbfdijetpt_JetEnDown;   //!
   TBranch        *b_vbfdijetpt_JetEnUp;   //!
   TBranch        *b_vbfj1eta;   //!
   TBranch        *b_vbfj1eta_JetEnDown;   //!
   TBranch        *b_vbfj1eta_JetEnUp;   //!
   TBranch        *b_vbfj1pt;   //!
   TBranch        *b_vbfj1pt_JetEnDown;   //!
   TBranch        *b_vbfj1pt_JetEnUp;   //!
   TBranch        *b_vbfj2eta;   //!
   TBranch        *b_vbfj2eta_JetEnDown;   //!
   TBranch        *b_vbfj2eta_JetEnUp;   //!
   TBranch        *b_vbfj2pt;   //!
   TBranch        *b_vbfj2pt_JetEnDown;   //!
   TBranch        *b_vbfj2pt_JetEnUp;   //!
   TBranch        *b_vispX;   //!
   TBranch        *b_vispY;   //!
   TBranch        *b_idx;   //!


   // methods
   HTauTauTree_mt (TTree* tree); //ctor
   ~HTauTauTree_mt();
   void Init(TTree* tree);
   Int_t GetEntry(int entry);
   Long64_t GetEntries();
   TTree* GetTree();
};

HTauTauTree_mt::HTauTauTree_mt (TTree* tree)
{
    Init(tree);
}

HTauTauTree_mt::~HTauTauTree_mt() {}

void HTauTauTree_mt::Init(TTree* tree)
{
   // Set object pointer

   // Set branch addresses and branch pointers
   if (!tree) return;
   _tree = tree;  
   _tree->SetMakeClass(1); // needed especially when compiling

   _tree->SetBranchAddress("EmbPtWeight", &EmbPtWeight, &b_EmbPtWeight);
   _tree->SetBranchAddress("Eta", &Eta, &b_Eta);
   _tree->SetBranchAddress("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter, &b_Flag_BadChargedCandidateFilter);
   _tree->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, &b_Flag_BadPFMuonFilter);
   _tree->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   _tree->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   _tree->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   _tree->SetBranchAddress("Flag_badCloneMuonFilter", &Flag_badCloneMuonFilter, &b_Flag_badCloneMuonFilter);
   _tree->SetBranchAddress("Flag_badGlobalMuonFilter", &Flag_badGlobalMuonFilter, &b_Flag_badGlobalMuonFilter);
   _tree->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   _tree->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
   _tree->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   _tree->SetBranchAddress("GenWeight", &GenWeight, &b_GenWeight);
   _tree->SetBranchAddress("Ht", &Ht, &b_Ht);
   _tree->SetBranchAddress("LT", &LT, &b_LT);
   _tree->SetBranchAddress("Mass", &Mass, &b_Mass);
   _tree->SetBranchAddress("MassError", &MassError, &b_MassError);
   _tree->SetBranchAddress("MassErrord1", &MassErrord1, &b_MassErrord1);
   _tree->SetBranchAddress("MassErrord2", &MassErrord2, &b_MassErrord2);
   _tree->SetBranchAddress("MassErrord3", &MassErrord3, &b_MassErrord3);
   _tree->SetBranchAddress("MassErrord4", &MassErrord4, &b_MassErrord4);
   _tree->SetBranchAddress("Mt", &Mt, &b_Mt);
   _tree->SetBranchAddress("NUP", &NUP, &b_NUP);
   _tree->SetBranchAddress("Phi", &Phi, &b_Phi);
   _tree->SetBranchAddress("Pt", &Pt, &b_Pt);
   _tree->SetBranchAddress("bjetCISVVeto20Loose", &bjetCISVVeto20Loose, &b_bjetCISVVeto20Loose);
   _tree->SetBranchAddress("bjetCISVVeto20Medium", &bjetCISVVeto20Medium, &b_bjetCISVVeto20Medium);
   _tree->SetBranchAddress("bjetCISVVeto20Tight", &bjetCISVVeto20Tight, &b_bjetCISVVeto20Tight);
   _tree->SetBranchAddress("bjetCISVVeto30Loose", &bjetCISVVeto30Loose, &b_bjetCISVVeto30Loose);
   _tree->SetBranchAddress("bjetCISVVeto30Medium", &bjetCISVVeto30Medium, &b_bjetCISVVeto30Medium);
   _tree->SetBranchAddress("bjetCISVVeto30Tight", &bjetCISVVeto30Tight, &b_bjetCISVVeto30Tight);
   _tree->SetBranchAddress("charge", &charge, &b_charge);
   _tree->SetBranchAddress("dielectronVeto", &dielectronVeto, &b_dielectronVeto);
   _tree->SetBranchAddress("dimuonVeto", &dimuonVeto, &b_dimuonVeto);
   _tree->SetBranchAddress("doubleEGroup", &doubleEGroup, &b_doubleEGroup);
   _tree->SetBranchAddress("doubleEPass", &doubleEPass, &b_doubleEPass);
   _tree->SetBranchAddress("doubleEPrescale", &doubleEPrescale, &b_doubleEPrescale);
   _tree->SetBranchAddress("doubleESingleMuGroup", &doubleESingleMuGroup, &b_doubleESingleMuGroup);
   _tree->SetBranchAddress("doubleESingleMuPass", &doubleESingleMuPass, &b_doubleESingleMuPass);
   _tree->SetBranchAddress("doubleESingleMuPrescale", &doubleESingleMuPrescale, &b_doubleESingleMuPrescale);
   _tree->SetBranchAddress("doubleE_23_12Group", &doubleE_23_12Group, &b_doubleE_23_12Group);
   _tree->SetBranchAddress("doubleE_23_12Pass", &doubleE_23_12Pass, &b_doubleE_23_12Pass);
   _tree->SetBranchAddress("doubleE_23_12Prescale", &doubleE_23_12Prescale, &b_doubleE_23_12Prescale);
   _tree->SetBranchAddress("doubleMuGroup", &doubleMuGroup, &b_doubleMuGroup);
   _tree->SetBranchAddress("doubleMuPass", &doubleMuPass, &b_doubleMuPass);
   _tree->SetBranchAddress("doubleMuPrescale", &doubleMuPrescale, &b_doubleMuPrescale);
   _tree->SetBranchAddress("doubleMuSingleEGroup", &doubleMuSingleEGroup, &b_doubleMuSingleEGroup);
   _tree->SetBranchAddress("doubleMuSingleEPass", &doubleMuSingleEPass, &b_doubleMuSingleEPass);
   _tree->SetBranchAddress("doubleMuSingleEPrescale", &doubleMuSingleEPrescale, &b_doubleMuSingleEPrescale);
   _tree->SetBranchAddress("doubleTau32Group", &doubleTau32Group, &b_doubleTau32Group);
   _tree->SetBranchAddress("doubleTau32Pass", &doubleTau32Pass, &b_doubleTau32Pass);
   _tree->SetBranchAddress("doubleTau32Prescale", &doubleTau32Prescale, &b_doubleTau32Prescale);
   _tree->SetBranchAddress("doubleTau35Group", &doubleTau35Group, &b_doubleTau35Group);
   _tree->SetBranchAddress("doubleTau35Pass", &doubleTau35Pass, &b_doubleTau35Pass);
   _tree->SetBranchAddress("doubleTau35Prescale", &doubleTau35Prescale, &b_doubleTau35Prescale);
   _tree->SetBranchAddress("doubleTau40Group", &doubleTau40Group, &b_doubleTau40Group);
   _tree->SetBranchAddress("doubleTau40Pass", &doubleTau40Pass, &b_doubleTau40Pass);
   _tree->SetBranchAddress("doubleTau40Prescale", &doubleTau40Prescale, &b_doubleTau40Prescale);
   _tree->SetBranchAddress("doubleTauCmbIso35RegGroup", &doubleTauCmbIso35RegGroup, &b_doubleTauCmbIso35RegGroup);
   _tree->SetBranchAddress("doubleTauCmbIso35RegPass", &doubleTauCmbIso35RegPass, &b_doubleTauCmbIso35RegPass);
   _tree->SetBranchAddress("doubleTauCmbIso35RegPrescale", &doubleTauCmbIso35RegPrescale, &b_doubleTauCmbIso35RegPrescale);
   _tree->SetBranchAddress("doubleTauCmbIso40Group", &doubleTauCmbIso40Group, &b_doubleTauCmbIso40Group);
   _tree->SetBranchAddress("doubleTauCmbIso40Pass", &doubleTauCmbIso40Pass, &b_doubleTauCmbIso40Pass);
   _tree->SetBranchAddress("doubleTauCmbIso40Prescale", &doubleTauCmbIso40Prescale, &b_doubleTauCmbIso40Prescale);
   _tree->SetBranchAddress("doubleTauCmbIso40RegGroup", &doubleTauCmbIso40RegGroup, &b_doubleTauCmbIso40RegGroup);
   _tree->SetBranchAddress("doubleTauCmbIso40RegPass", &doubleTauCmbIso40RegPass, &b_doubleTauCmbIso40RegPass);
   _tree->SetBranchAddress("doubleTauCmbIso40RegPrescale", &doubleTauCmbIso40RegPrescale, &b_doubleTauCmbIso40RegPrescale);
   _tree->SetBranchAddress("eVetoMVAIso", &eVetoMVAIso, &b_eVetoMVAIso);
   _tree->SetBranchAddress("eVetoMVAIsoVtx", &eVetoMVAIsoVtx, &b_eVetoMVAIsoVtx);
   _tree->SetBranchAddress("eVetoZTTp001dxyz", &eVetoZTTp001dxyz, &b_eVetoZTTp001dxyz);
   _tree->SetBranchAddress("eVetoZTTp001dxyzR0", &eVetoZTTp001dxyzR0, &b_eVetoZTTp001dxyzR0);
   _tree->SetBranchAddress("evt", &evt, &b_evt);
   _tree->SetBranchAddress("genEta", &genEta, &b_genEta);
   _tree->SetBranchAddress("genHTT", &genHTT, &b_genHTT);
   _tree->SetBranchAddress("genM", &genM, &b_genM);
   _tree->SetBranchAddress("genMass", &genMass, &b_genMass);
   _tree->SetBranchAddress("genPhi", &genPhi, &b_genPhi);
   _tree->SetBranchAddress("genpT", &genpT, &b_genpT);
   _tree->SetBranchAddress("genpX", &genpX, &b_genpX);
   _tree->SetBranchAddress("genpY", &genpY, &b_genpY);
   _tree->SetBranchAddress("isGtautau", &isGtautau, &b_isGtautau);
   _tree->SetBranchAddress("isWenu", &isWenu, &b_isWenu);
   _tree->SetBranchAddress("isWmunu", &isWmunu, &b_isWmunu);
   _tree->SetBranchAddress("isWtaunu", &isWtaunu, &b_isWtaunu);
   _tree->SetBranchAddress("isZee", &isZee, &b_isZee);
   _tree->SetBranchAddress("isZmumu", &isZmumu, &b_isZmumu);
   _tree->SetBranchAddress("isZtautau", &isZtautau, &b_isZtautau);
   _tree->SetBranchAddress("isdata", &isdata, &b_isdata);
   _tree->SetBranchAddress("j1csv", &j1csv, &b_j1csv);
   _tree->SetBranchAddress("j1eta", &j1eta, &b_j1eta);
   _tree->SetBranchAddress("j1hadronflavor", &j1hadronflavor, &b_j1hadronflavor);
   _tree->SetBranchAddress("j1partonflavor", &j1partonflavor, &b_j1partonflavor);
   _tree->SetBranchAddress("j1phi", &j1phi, &b_j1phi);
   _tree->SetBranchAddress("j1pt", &j1pt, &b_j1pt);
   _tree->SetBranchAddress("j1ptDown", &j1ptDown, &b_j1ptDown);
   _tree->SetBranchAddress("j1ptUp", &j1ptUp, &b_j1ptUp);
   _tree->SetBranchAddress("j1pu", &j1pu, &b_j1pu);
   _tree->SetBranchAddress("j1rawf", &j1rawf, &b_j1rawf);
   _tree->SetBranchAddress("j2csv", &j2csv, &b_j2csv);
   _tree->SetBranchAddress("j2eta", &j2eta, &b_j2eta);
   _tree->SetBranchAddress("j2hadronflavor", &j2hadronflavor, &b_j2hadronflavor);
   _tree->SetBranchAddress("j2partonflavor", &j2partonflavor, &b_j2partonflavor);
   _tree->SetBranchAddress("j2phi", &j2phi, &b_j2phi);
   _tree->SetBranchAddress("j2pt", &j2pt, &b_j2pt);
   _tree->SetBranchAddress("j2ptDown", &j2ptDown, &b_j2ptDown);
   _tree->SetBranchAddress("j2ptUp", &j2ptUp, &b_j2ptUp);
   _tree->SetBranchAddress("j2pu", &j2pu, &b_j2pu);
   _tree->SetBranchAddress("j2rawf", &j2rawf, &b_j2rawf);
   _tree->SetBranchAddress("jb1csv", &jb1csv, &b_jb1csv);
   _tree->SetBranchAddress("jb1csv_CSVL", &jb1csv_CSVL, &b_jb1csv_CSVL);
   _tree->SetBranchAddress("jb1eta", &jb1eta, &b_jb1eta);
   _tree->SetBranchAddress("jb1eta_CSVL", &jb1eta_CSVL, &b_jb1eta_CSVL);
   _tree->SetBranchAddress("jb1hadronflavor", &jb1hadronflavor, &b_jb1hadronflavor);
   _tree->SetBranchAddress("jb1hadronflavor_CSVL", &jb1hadronflavor_CSVL, &b_jb1hadronflavor_CSVL);
   _tree->SetBranchAddress("jb1partonflavor", &jb1partonflavor, &b_jb1partonflavor);
   _tree->SetBranchAddress("jb1partonflavor_CSVL", &jb1partonflavor_CSVL, &b_jb1partonflavor_CSVL);
   _tree->SetBranchAddress("jb1phi", &jb1phi, &b_jb1phi);
   _tree->SetBranchAddress("jb1phi_CSVL", &jb1phi_CSVL, &b_jb1phi_CSVL);
   _tree->SetBranchAddress("jb1pt", &jb1pt, &b_jb1pt);
   _tree->SetBranchAddress("jb1ptDown", &jb1ptDown, &b_jb1ptDown);
   _tree->SetBranchAddress("jb1ptDown_CSVL", &jb1ptDown_CSVL, &b_jb1ptDown_CSVL);
   _tree->SetBranchAddress("jb1ptUp", &jb1ptUp, &b_jb1ptUp);
   _tree->SetBranchAddress("jb1ptUp_CSVL", &jb1ptUp_CSVL, &b_jb1ptUp_CSVL);
   _tree->SetBranchAddress("jb1pt_CSVL", &jb1pt_CSVL, &b_jb1pt_CSVL);
   _tree->SetBranchAddress("jb1pu", &jb1pu, &b_jb1pu);
   _tree->SetBranchAddress("jb1pu_CSVL", &jb1pu_CSVL, &b_jb1pu_CSVL);
   _tree->SetBranchAddress("jb1rawf", &jb1rawf, &b_jb1rawf);
   _tree->SetBranchAddress("jb1rawf_CSVL", &jb1rawf_CSVL, &b_jb1rawf_CSVL);
   _tree->SetBranchAddress("jb2csv", &jb2csv, &b_jb2csv);
   _tree->SetBranchAddress("jb2csv_CSVL", &jb2csv_CSVL, &b_jb2csv_CSVL);
   _tree->SetBranchAddress("jb2eta", &jb2eta, &b_jb2eta);
   _tree->SetBranchAddress("jb2eta_CSVL", &jb2eta_CSVL, &b_jb2eta_CSVL);
   _tree->SetBranchAddress("jb2hadronflavor", &jb2hadronflavor, &b_jb2hadronflavor);
   _tree->SetBranchAddress("jb2hadronflavor_CSVL", &jb2hadronflavor_CSVL, &b_jb2hadronflavor_CSVL);
   _tree->SetBranchAddress("jb2partonflavor", &jb2partonflavor, &b_jb2partonflavor);
   _tree->SetBranchAddress("jb2partonflavor_CSVL", &jb2partonflavor_CSVL, &b_jb2partonflavor_CSVL);
   _tree->SetBranchAddress("jb2phi", &jb2phi, &b_jb2phi);
   _tree->SetBranchAddress("jb2phi_CSVL", &jb2phi_CSVL, &b_jb2phi_CSVL);
   _tree->SetBranchAddress("jb2pt", &jb2pt, &b_jb2pt);
   _tree->SetBranchAddress("jb2ptDown", &jb2ptDown, &b_jb2ptDown);
   _tree->SetBranchAddress("jb2ptDown_CSVL", &jb2ptDown_CSVL, &b_jb2ptDown_CSVL);
   _tree->SetBranchAddress("jb2ptUp", &jb2ptUp, &b_jb2ptUp);
   _tree->SetBranchAddress("jb2ptUp_CSVL", &jb2ptUp_CSVL, &b_jb2ptUp_CSVL);
   _tree->SetBranchAddress("jb2pt_CSVL", &jb2pt_CSVL, &b_jb2pt_CSVL);
   _tree->SetBranchAddress("jb2pu", &jb2pu, &b_jb2pu);
   _tree->SetBranchAddress("jb2pu_CSVL", &jb2pu_CSVL, &b_jb2pu_CSVL);
   _tree->SetBranchAddress("jb2rawf", &jb2rawf, &b_jb2rawf);
   _tree->SetBranchAddress("jb2rawf_CSVL", &jb2rawf_CSVL, &b_jb2rawf_CSVL);
   _tree->SetBranchAddress("jetVeto20", &jetVeto20, &b_jetVeto20);
   _tree->SetBranchAddress("jetVeto20_JetEnDown", &jetVeto20_JetEnDown, &b_jetVeto20_JetEnDown);
   _tree->SetBranchAddress("jetVeto20_JetEnUp", &jetVeto20_JetEnUp, &b_jetVeto20_JetEnUp);
   _tree->SetBranchAddress("jetVeto30", &jetVeto30, &b_jetVeto30);
   _tree->SetBranchAddress("jetVeto30_JetAbsoluteFlavMapDown", &jetVeto30_JetAbsoluteFlavMapDown, &b_jetVeto30_JetAbsoluteFlavMapDown);
   _tree->SetBranchAddress("jetVeto30_JetAbsoluteFlavMapUp", &jetVeto30_JetAbsoluteFlavMapUp, &b_jetVeto30_JetAbsoluteFlavMapUp);
   _tree->SetBranchAddress("jetVeto30_JetAbsoluteMPFBiasDown", &jetVeto30_JetAbsoluteMPFBiasDown, &b_jetVeto30_JetAbsoluteMPFBiasDown);
   _tree->SetBranchAddress("jetVeto30_JetAbsoluteMPFBiasUp", &jetVeto30_JetAbsoluteMPFBiasUp, &b_jetVeto30_JetAbsoluteMPFBiasUp);
   _tree->SetBranchAddress("jetVeto30_JetAbsoluteScaleDown", &jetVeto30_JetAbsoluteScaleDown, &b_jetVeto30_JetAbsoluteScaleDown);
   _tree->SetBranchAddress("jetVeto30_JetAbsoluteScaleUp", &jetVeto30_JetAbsoluteScaleUp, &b_jetVeto30_JetAbsoluteScaleUp);
   _tree->SetBranchAddress("jetVeto30_JetAbsoluteStatDown", &jetVeto30_JetAbsoluteStatDown, &b_jetVeto30_JetAbsoluteStatDown);
   _tree->SetBranchAddress("jetVeto30_JetAbsoluteStatUp", &jetVeto30_JetAbsoluteStatUp, &b_jetVeto30_JetAbsoluteStatUp);
   _tree->SetBranchAddress("jetVeto30_JetClosureDown", &jetVeto30_JetClosureDown, &b_jetVeto30_JetClosureDown);
   _tree->SetBranchAddress("jetVeto30_JetClosureUp", &jetVeto30_JetClosureUp, &b_jetVeto30_JetClosureUp);
   _tree->SetBranchAddress("jetVeto30_JetEnDown", &jetVeto30_JetEnDown, &b_jetVeto30_JetEnDown);
   _tree->SetBranchAddress("jetVeto30_JetEnUp", &jetVeto30_JetEnUp, &b_jetVeto30_JetEnUp);
   _tree->SetBranchAddress("jetVeto30_JetFlavorQCDDown", &jetVeto30_JetFlavorQCDDown, &b_jetVeto30_JetFlavorQCDDown);
   _tree->SetBranchAddress("jetVeto30_JetFlavorQCDUp", &jetVeto30_JetFlavorQCDUp, &b_jetVeto30_JetFlavorQCDUp);
   _tree->SetBranchAddress("jetVeto30_JetFragmentationDown", &jetVeto30_JetFragmentationDown, &b_jetVeto30_JetFragmentationDown);
   _tree->SetBranchAddress("jetVeto30_JetFragmentationUp", &jetVeto30_JetFragmentationUp, &b_jetVeto30_JetFragmentationUp);
   _tree->SetBranchAddress("jetVeto30_JetPileUpDataMCDown", &jetVeto30_JetPileUpDataMCDown, &b_jetVeto30_JetPileUpDataMCDown);
   _tree->SetBranchAddress("jetVeto30_JetPileUpDataMCUp", &jetVeto30_JetPileUpDataMCUp, &b_jetVeto30_JetPileUpDataMCUp);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtBBDown", &jetVeto30_JetPileUpPtBBDown, &b_jetVeto30_JetPileUpPtBBDown);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtBBUp", &jetVeto30_JetPileUpPtBBUp, &b_jetVeto30_JetPileUpPtBBUp);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtEC1Down", &jetVeto30_JetPileUpPtEC1Down, &b_jetVeto30_JetPileUpPtEC1Down);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtEC1Up", &jetVeto30_JetPileUpPtEC1Up, &b_jetVeto30_JetPileUpPtEC1Up);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtEC2Down", &jetVeto30_JetPileUpPtEC2Down, &b_jetVeto30_JetPileUpPtEC2Down);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtEC2Up", &jetVeto30_JetPileUpPtEC2Up, &b_jetVeto30_JetPileUpPtEC2Up);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtHFDown", &jetVeto30_JetPileUpPtHFDown, &b_jetVeto30_JetPileUpPtHFDown);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtHFUp", &jetVeto30_JetPileUpPtHFUp, &b_jetVeto30_JetPileUpPtHFUp);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtRefDown", &jetVeto30_JetPileUpPtRefDown, &b_jetVeto30_JetPileUpPtRefDown);
   _tree->SetBranchAddress("jetVeto30_JetPileUpPtRefUp", &jetVeto30_JetPileUpPtRefUp, &b_jetVeto30_JetPileUpPtRefUp);
   _tree->SetBranchAddress("jetVeto30_JetRelativeBalDown", &jetVeto30_JetRelativeBalDown, &b_jetVeto30_JetRelativeBalDown);
   _tree->SetBranchAddress("jetVeto30_JetRelativeBalUp", &jetVeto30_JetRelativeBalUp, &b_jetVeto30_JetRelativeBalUp);
   _tree->SetBranchAddress("jetVeto30_JetRelativeFSRDown", &jetVeto30_JetRelativeFSRDown, &b_jetVeto30_JetRelativeFSRDown);
   _tree->SetBranchAddress("jetVeto30_JetRelativeFSRUp", &jetVeto30_JetRelativeFSRUp, &b_jetVeto30_JetRelativeFSRUp);
   _tree->SetBranchAddress("jetVeto30_JetRelativeJEREC1Down", &jetVeto30_JetRelativeJEREC1Down, &b_jetVeto30_JetRelativeJEREC1Down);
   _tree->SetBranchAddress("jetVeto30_JetRelativeJEREC1Up", &jetVeto30_JetRelativeJEREC1Up, &b_jetVeto30_JetRelativeJEREC1Up);
   _tree->SetBranchAddress("jetVeto30_JetRelativeJEREC2Down", &jetVeto30_JetRelativeJEREC2Down, &b_jetVeto30_JetRelativeJEREC2Down);
   _tree->SetBranchAddress("jetVeto30_JetRelativeJEREC2Up", &jetVeto30_JetRelativeJEREC2Up, &b_jetVeto30_JetRelativeJEREC2Up);
   _tree->SetBranchAddress("jetVeto30_JetRelativeJERHFDown", &jetVeto30_JetRelativeJERHFDown, &b_jetVeto30_JetRelativeJERHFDown);
   _tree->SetBranchAddress("jetVeto30_JetRelativeJERHFUp", &jetVeto30_JetRelativeJERHFUp, &b_jetVeto30_JetRelativeJERHFUp);
   _tree->SetBranchAddress("jetVeto30_JetRelativePtBBDown", &jetVeto30_JetRelativePtBBDown, &b_jetVeto30_JetRelativePtBBDown);
   _tree->SetBranchAddress("jetVeto30_JetRelativePtBBUp", &jetVeto30_JetRelativePtBBUp, &b_jetVeto30_JetRelativePtBBUp);
   _tree->SetBranchAddress("jetVeto30_JetRelativePtEC1Down", &jetVeto30_JetRelativePtEC1Down, &b_jetVeto30_JetRelativePtEC1Down);
   _tree->SetBranchAddress("jetVeto30_JetRelativePtEC1Up", &jetVeto30_JetRelativePtEC1Up, &b_jetVeto30_JetRelativePtEC1Up);
   _tree->SetBranchAddress("jetVeto30_JetRelativePtEC2Down", &jetVeto30_JetRelativePtEC2Down, &b_jetVeto30_JetRelativePtEC2Down);
   _tree->SetBranchAddress("jetVeto30_JetRelativePtEC2Up", &jetVeto30_JetRelativePtEC2Up, &b_jetVeto30_JetRelativePtEC2Up);
   _tree->SetBranchAddress("jetVeto30_JetRelativePtHFDown", &jetVeto30_JetRelativePtHFDown, &b_jetVeto30_JetRelativePtHFDown);
   _tree->SetBranchAddress("jetVeto30_JetRelativePtHFUp", &jetVeto30_JetRelativePtHFUp, &b_jetVeto30_JetRelativePtHFUp);
   _tree->SetBranchAddress("jetVeto30_JetRelativeStatECDown", &jetVeto30_JetRelativeStatECDown, &b_jetVeto30_JetRelativeStatECDown);
   _tree->SetBranchAddress("jetVeto30_JetRelativeStatECUp", &jetVeto30_JetRelativeStatECUp, &b_jetVeto30_JetRelativeStatECUp);
   _tree->SetBranchAddress("jetVeto30_JetRelativeStatFSRDown", &jetVeto30_JetRelativeStatFSRDown, &b_jetVeto30_JetRelativeStatFSRDown);
   _tree->SetBranchAddress("jetVeto30_JetRelativeStatFSRUp", &jetVeto30_JetRelativeStatFSRUp, &b_jetVeto30_JetRelativeStatFSRUp);
   _tree->SetBranchAddress("jetVeto30_JetRelativeStatHFDown", &jetVeto30_JetRelativeStatHFDown, &b_jetVeto30_JetRelativeStatHFDown);
   _tree->SetBranchAddress("jetVeto30_JetRelativeStatHFUp", &jetVeto30_JetRelativeStatHFUp, &b_jetVeto30_JetRelativeStatHFUp);
   _tree->SetBranchAddress("jetVeto30_JetSinglePionECALDown", &jetVeto30_JetSinglePionECALDown, &b_jetVeto30_JetSinglePionECALDown);
   _tree->SetBranchAddress("jetVeto30_JetSinglePionECALUp", &jetVeto30_JetSinglePionECALUp, &b_jetVeto30_JetSinglePionECALUp);
   _tree->SetBranchAddress("jetVeto30_JetSinglePionHCALDown", &jetVeto30_JetSinglePionHCALDown, &b_jetVeto30_JetSinglePionHCALDown);
   _tree->SetBranchAddress("jetVeto30_JetSinglePionHCALUp", &jetVeto30_JetSinglePionHCALUp, &b_jetVeto30_JetSinglePionHCALUp);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalAbsoluteDown", &jetVeto30_JetSubTotalAbsoluteDown, &b_jetVeto30_JetSubTotalAbsoluteDown);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalAbsoluteUp", &jetVeto30_JetSubTotalAbsoluteUp, &b_jetVeto30_JetSubTotalAbsoluteUp);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalMCDown", &jetVeto30_JetSubTotalMCDown, &b_jetVeto30_JetSubTotalMCDown);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalMCUp", &jetVeto30_JetSubTotalMCUp, &b_jetVeto30_JetSubTotalMCUp);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalPileUpDown", &jetVeto30_JetSubTotalPileUpDown, &b_jetVeto30_JetSubTotalPileUpDown);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalPileUpUp", &jetVeto30_JetSubTotalPileUpUp, &b_jetVeto30_JetSubTotalPileUpUp);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalPtDown", &jetVeto30_JetSubTotalPtDown, &b_jetVeto30_JetSubTotalPtDown);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalPtUp", &jetVeto30_JetSubTotalPtUp, &b_jetVeto30_JetSubTotalPtUp);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalRelativeDown", &jetVeto30_JetSubTotalRelativeDown, &b_jetVeto30_JetSubTotalRelativeDown);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalRelativeUp", &jetVeto30_JetSubTotalRelativeUp, &b_jetVeto30_JetSubTotalRelativeUp);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalScaleDown", &jetVeto30_JetSubTotalScaleDown, &b_jetVeto30_JetSubTotalScaleDown);
   _tree->SetBranchAddress("jetVeto30_JetSubTotalScaleUp", &jetVeto30_JetSubTotalScaleUp, &b_jetVeto30_JetSubTotalScaleUp);
   _tree->SetBranchAddress("jetVeto30_JetTimePtEtaDown", &jetVeto30_JetTimePtEtaDown, &b_jetVeto30_JetTimePtEtaDown);
   _tree->SetBranchAddress("jetVeto30_JetTimePtEtaUp", &jetVeto30_JetTimePtEtaUp, &b_jetVeto30_JetTimePtEtaUp);
   _tree->SetBranchAddress("jetVeto30_JetTotalDown", &jetVeto30_JetTotalDown, &b_jetVeto30_JetTotalDown);
   _tree->SetBranchAddress("jetVeto30_JetTotalUp", &jetVeto30_JetTotalUp, &b_jetVeto30_JetTotalUp);
   _tree->SetBranchAddress("lumi", &lumi, &b_lumi);
   _tree->SetBranchAddress("mAbsEta", &mAbsEta, &b_mAbsEta);
   _tree->SetBranchAddress("mBestTrackType", &mBestTrackType, &b_mBestTrackType);
   _tree->SetBranchAddress("mCharge", &mCharge, &b_mCharge);
   _tree->SetBranchAddress("mChi2LocalPosition", &mChi2LocalPosition, &b_mChi2LocalPosition);
   _tree->SetBranchAddress("mComesFromHiggs", &mComesFromHiggs, &b_mComesFromHiggs);
   _tree->SetBranchAddress("mDPhiToPfMet_ElectronEnDown", &mDPhiToPfMet_ElectronEnDown, &b_mDPhiToPfMet_ElectronEnDown);
   _tree->SetBranchAddress("mDPhiToPfMet_ElectronEnUp", &mDPhiToPfMet_ElectronEnUp, &b_mDPhiToPfMet_ElectronEnUp);
   _tree->SetBranchAddress("mDPhiToPfMet_JetEnDown", &mDPhiToPfMet_JetEnDown, &b_mDPhiToPfMet_JetEnDown);
   _tree->SetBranchAddress("mDPhiToPfMet_JetEnUp", &mDPhiToPfMet_JetEnUp, &b_mDPhiToPfMet_JetEnUp);
   _tree->SetBranchAddress("mDPhiToPfMet_JetResDown", &mDPhiToPfMet_JetResDown, &b_mDPhiToPfMet_JetResDown);
   _tree->SetBranchAddress("mDPhiToPfMet_JetResUp", &mDPhiToPfMet_JetResUp, &b_mDPhiToPfMet_JetResUp);
   _tree->SetBranchAddress("mDPhiToPfMet_MuonEnDown", &mDPhiToPfMet_MuonEnDown, &b_mDPhiToPfMet_MuonEnDown);
   _tree->SetBranchAddress("mDPhiToPfMet_MuonEnUp", &mDPhiToPfMet_MuonEnUp, &b_mDPhiToPfMet_MuonEnUp);
   _tree->SetBranchAddress("mDPhiToPfMet_PhotonEnDown", &mDPhiToPfMet_PhotonEnDown, &b_mDPhiToPfMet_PhotonEnDown);
   _tree->SetBranchAddress("mDPhiToPfMet_PhotonEnUp", &mDPhiToPfMet_PhotonEnUp, &b_mDPhiToPfMet_PhotonEnUp);
   _tree->SetBranchAddress("mDPhiToPfMet_TauEnDown", &mDPhiToPfMet_TauEnDown, &b_mDPhiToPfMet_TauEnDown);
   _tree->SetBranchAddress("mDPhiToPfMet_TauEnUp", &mDPhiToPfMet_TauEnUp, &b_mDPhiToPfMet_TauEnUp);
   _tree->SetBranchAddress("mDPhiToPfMet_UnclusteredEnDown", &mDPhiToPfMet_UnclusteredEnDown, &b_mDPhiToPfMet_UnclusteredEnDown);
   _tree->SetBranchAddress("mDPhiToPfMet_UnclusteredEnUp", &mDPhiToPfMet_UnclusteredEnUp, &b_mDPhiToPfMet_UnclusteredEnUp);
   _tree->SetBranchAddress("mDPhiToPfMet_type1", &mDPhiToPfMet_type1, &b_mDPhiToPfMet_type1);
   _tree->SetBranchAddress("mEcalIsoDR03", &mEcalIsoDR03, &b_mEcalIsoDR03);
   _tree->SetBranchAddress("mEffectiveArea2011", &mEffectiveArea2011, &b_mEffectiveArea2011);
   _tree->SetBranchAddress("mEffectiveArea2012", &mEffectiveArea2012, &b_mEffectiveArea2012);
   _tree->SetBranchAddress("mErsatzGenEta", &mErsatzGenEta, &b_mErsatzGenEta);
   _tree->SetBranchAddress("mErsatzGenM", &mErsatzGenM, &b_mErsatzGenM);
   _tree->SetBranchAddress("mErsatzGenPhi", &mErsatzGenPhi, &b_mErsatzGenPhi);
   _tree->SetBranchAddress("mErsatzGenpT", &mErsatzGenpT, &b_mErsatzGenpT);
   _tree->SetBranchAddress("mErsatzGenpX", &mErsatzGenpX, &b_mErsatzGenpX);
   _tree->SetBranchAddress("mErsatzGenpY", &mErsatzGenpY, &b_mErsatzGenpY);
   _tree->SetBranchAddress("mErsatzVispX", &mErsatzVispX, &b_mErsatzVispX);
   _tree->SetBranchAddress("mErsatzVispY", &mErsatzVispY, &b_mErsatzVispY);
   _tree->SetBranchAddress("mEta", &mEta, &b_mEta);
   _tree->SetBranchAddress("mEta_MuonEnDown", &mEta_MuonEnDown, &b_mEta_MuonEnDown);
   _tree->SetBranchAddress("mEta_MuonEnUp", &mEta_MuonEnUp, &b_mEta_MuonEnUp);
   _tree->SetBranchAddress("mGenCharge", &mGenCharge, &b_mGenCharge);
   _tree->SetBranchAddress("mGenDirectPromptTauDecayFinalState", &mGenDirectPromptTauDecayFinalState, &b_mGenDirectPromptTauDecayFinalState);
   _tree->SetBranchAddress("mGenEnergy", &mGenEnergy, &b_mGenEnergy);
   _tree->SetBranchAddress("mGenEta", &mGenEta, &b_mGenEta);
   _tree->SetBranchAddress("mGenIsPrompt", &mGenIsPrompt, &b_mGenIsPrompt);
   _tree->SetBranchAddress("mGenMotherPdgId", &mGenMotherPdgId, &b_mGenMotherPdgId);
   _tree->SetBranchAddress("mGenParticle", &mGenParticle, &b_mGenParticle);
   _tree->SetBranchAddress("mGenPdgId", &mGenPdgId, &b_mGenPdgId);
   _tree->SetBranchAddress("mGenPhi", &mGenPhi, &b_mGenPhi);
   _tree->SetBranchAddress("mGenPrompt", &mGenPrompt, &b_mGenPrompt);
   _tree->SetBranchAddress("mGenPromptFinalState", &mGenPromptFinalState, &b_mGenPromptFinalState);
   _tree->SetBranchAddress("mGenPromptTauDecay", &mGenPromptTauDecay, &b_mGenPromptTauDecay);
   _tree->SetBranchAddress("mGenPt", &mGenPt, &b_mGenPt);
   _tree->SetBranchAddress("mGenTauDecay", &mGenTauDecay, &b_mGenTauDecay);
   _tree->SetBranchAddress("mGenVZ", &mGenVZ, &b_mGenVZ);
   _tree->SetBranchAddress("mGenVtxPVMatch", &mGenVtxPVMatch, &b_mGenVtxPVMatch);
   _tree->SetBranchAddress("mHcalIsoDR03", &mHcalIsoDR03, &b_mHcalIsoDR03);
   _tree->SetBranchAddress("mIP3D", &mIP3D, &b_mIP3D);
   _tree->SetBranchAddress("mIP3DErr", &mIP3DErr, &b_mIP3DErr);
   _tree->SetBranchAddress("mIsGlobal", &mIsGlobal, &b_mIsGlobal);
   _tree->SetBranchAddress("mIsPFMuon", &mIsPFMuon, &b_mIsPFMuon);
   _tree->SetBranchAddress("mIsTracker", &mIsTracker, &b_mIsTracker);
   _tree->SetBranchAddress("mIsoDB03", &mIsoDB03, &b_mIsoDB03);
   _tree->SetBranchAddress("mIsoDB04", &mIsoDB04, &b_mIsoDB04);
   _tree->SetBranchAddress("mIsoMu22Filter", &mIsoMu22Filter, &b_mIsoMu22Filter);
   _tree->SetBranchAddress("mIsoMu22eta2p1Filter", &mIsoMu22eta2p1Filter, &b_mIsoMu22eta2p1Filter);
   _tree->SetBranchAddress("mIsoMu24Filter", &mIsoMu24Filter, &b_mIsoMu24Filter);
   _tree->SetBranchAddress("mIsoMu24eta2p1Filter", &mIsoMu24eta2p1Filter, &b_mIsoMu24eta2p1Filter);
   _tree->SetBranchAddress("mIsoTkMu22Filter", &mIsoTkMu22Filter, &b_mIsoTkMu22Filter);
   _tree->SetBranchAddress("mIsoTkMu22eta2p1Filter", &mIsoTkMu22eta2p1Filter, &b_mIsoTkMu22eta2p1Filter);
   _tree->SetBranchAddress("mIsoTkMu24Filter", &mIsoTkMu24Filter, &b_mIsoTkMu24Filter);
   _tree->SetBranchAddress("mIsoTkMu24eta2p1Filter", &mIsoTkMu24eta2p1Filter, &b_mIsoTkMu24eta2p1Filter);
   _tree->SetBranchAddress("mJetArea", &mJetArea, &b_mJetArea);
   _tree->SetBranchAddress("mJetBtag", &mJetBtag, &b_mJetBtag);
   _tree->SetBranchAddress("mJetEtaEtaMoment", &mJetEtaEtaMoment, &b_mJetEtaEtaMoment);
   _tree->SetBranchAddress("mJetEtaPhiMoment", &mJetEtaPhiMoment, &b_mJetEtaPhiMoment);
   _tree->SetBranchAddress("mJetEtaPhiSpread", &mJetEtaPhiSpread, &b_mJetEtaPhiSpread);
   _tree->SetBranchAddress("mJetHadronFlavour", &mJetHadronFlavour, &b_mJetHadronFlavour);
   _tree->SetBranchAddress("mJetPFCISVBtag", &mJetPFCISVBtag, &b_mJetPFCISVBtag);
   _tree->SetBranchAddress("mJetPartonFlavour", &mJetPartonFlavour, &b_mJetPartonFlavour);
   _tree->SetBranchAddress("mJetPhiPhiMoment", &mJetPhiPhiMoment, &b_mJetPhiPhiMoment);
   _tree->SetBranchAddress("mJetPt", &mJetPt, &b_mJetPt);
   _tree->SetBranchAddress("mLowestMll", &mLowestMll, &b_mLowestMll);
   _tree->SetBranchAddress("mMass", &mMass, &b_mMass);
   _tree->SetBranchAddress("mMatchedStations", &mMatchedStations, &b_mMatchedStations);
   _tree->SetBranchAddress("mMatchesDoubleESingleMu", &mMatchesDoubleESingleMu, &b_mMatchesDoubleESingleMu);
   _tree->SetBranchAddress("mMatchesDoubleMu", &mMatchesDoubleMu, &b_mMatchesDoubleMu);
   _tree->SetBranchAddress("mMatchesDoubleMuSingleE", &mMatchesDoubleMuSingleE, &b_mMatchesDoubleMuSingleE);
   _tree->SetBranchAddress("mMatchesIsoMu22Path", &mMatchesIsoMu22Path, &b_mMatchesIsoMu22Path);
   _tree->SetBranchAddress("mMatchesIsoMu22eta2p1Path", &mMatchesIsoMu22eta2p1Path, &b_mMatchesIsoMu22eta2p1Path);
   _tree->SetBranchAddress("mMatchesIsoMu24Path", &mMatchesIsoMu24Path, &b_mMatchesIsoMu24Path);
   _tree->SetBranchAddress("mMatchesIsoMu24eta2p1Path", &mMatchesIsoMu24eta2p1Path, &b_mMatchesIsoMu24eta2p1Path);
   _tree->SetBranchAddress("mMatchesIsoTkMu22Path", &mMatchesIsoTkMu22Path, &b_mMatchesIsoTkMu22Path);
   _tree->SetBranchAddress("mMatchesIsoTkMu22eta2p1Path", &mMatchesIsoTkMu22eta2p1Path, &b_mMatchesIsoTkMu22eta2p1Path);
   _tree->SetBranchAddress("mMatchesIsoTkMu24Path", &mMatchesIsoTkMu24Path, &b_mMatchesIsoTkMu24Path);
   _tree->SetBranchAddress("mMatchesIsoTkMu24eta2p1Path", &mMatchesIsoTkMu24eta2p1Path, &b_mMatchesIsoTkMu24eta2p1Path);
   _tree->SetBranchAddress("mMatchesMu19Tau20Filter", &mMatchesMu19Tau20Filter, &b_mMatchesMu19Tau20Filter);
   _tree->SetBranchAddress("mMatchesMu19Tau20Path", &mMatchesMu19Tau20Path, &b_mMatchesMu19Tau20Path);
   _tree->SetBranchAddress("mMatchesMu19Tau20sL1Filter", &mMatchesMu19Tau20sL1Filter, &b_mMatchesMu19Tau20sL1Filter);
   _tree->SetBranchAddress("mMatchesMu19Tau20sL1Path", &mMatchesMu19Tau20sL1Path, &b_mMatchesMu19Tau20sL1Path);
   _tree->SetBranchAddress("mMatchesMu21Tau20sL1Filter", &mMatchesMu21Tau20sL1Filter, &b_mMatchesMu21Tau20sL1Filter);
   _tree->SetBranchAddress("mMatchesMu21Tau20sL1Path", &mMatchesMu21Tau20sL1Path, &b_mMatchesMu21Tau20sL1Path);
   _tree->SetBranchAddress("mMatchesMu23Ele12DZPath", &mMatchesMu23Ele12DZPath, &b_mMatchesMu23Ele12DZPath);
   _tree->SetBranchAddress("mMatchesMu23Ele12Path", &mMatchesMu23Ele12Path, &b_mMatchesMu23Ele12Path);
   _tree->SetBranchAddress("mMatchesMu8Ele23DZPath", &mMatchesMu8Ele23DZPath, &b_mMatchesMu8Ele23DZPath);
   _tree->SetBranchAddress("mMatchesMu8Ele23Path", &mMatchesMu8Ele23Path, &b_mMatchesMu8Ele23Path);
   _tree->SetBranchAddress("mMatchesSingleESingleMu", &mMatchesSingleESingleMu, &b_mMatchesSingleESingleMu);
   _tree->SetBranchAddress("mMatchesSingleMu", &mMatchesSingleMu, &b_mMatchesSingleMu);
   _tree->SetBranchAddress("mMatchesSingleMuIso20", &mMatchesSingleMuIso20, &b_mMatchesSingleMuIso20);
   _tree->SetBranchAddress("mMatchesSingleMuIsoTk20", &mMatchesSingleMuIsoTk20, &b_mMatchesSingleMuIsoTk20);
   _tree->SetBranchAddress("mMatchesSingleMuSingleE", &mMatchesSingleMuSingleE, &b_mMatchesSingleMuSingleE);
   _tree->SetBranchAddress("mMatchesSingleMu_leg1", &mMatchesSingleMu_leg1, &b_mMatchesSingleMu_leg1);
   _tree->SetBranchAddress("mMatchesSingleMu_leg1_noiso", &mMatchesSingleMu_leg1_noiso, &b_mMatchesSingleMu_leg1_noiso);
   _tree->SetBranchAddress("mMatchesSingleMu_leg2", &mMatchesSingleMu_leg2, &b_mMatchesSingleMu_leg2);
   _tree->SetBranchAddress("mMatchesSingleMu_leg2_noiso", &mMatchesSingleMu_leg2_noiso, &b_mMatchesSingleMu_leg2_noiso);
   _tree->SetBranchAddress("mMatchesTripleMu", &mMatchesTripleMu, &b_mMatchesTripleMu);
   _tree->SetBranchAddress("mMtToPfMet_ElectronEnDown", &mMtToPfMet_ElectronEnDown, &b_mMtToPfMet_ElectronEnDown);
   _tree->SetBranchAddress("mMtToPfMet_ElectronEnUp", &mMtToPfMet_ElectronEnUp, &b_mMtToPfMet_ElectronEnUp);
   _tree->SetBranchAddress("mMtToPfMet_JetEnDown", &mMtToPfMet_JetEnDown, &b_mMtToPfMet_JetEnDown);
   _tree->SetBranchAddress("mMtToPfMet_JetEnUp", &mMtToPfMet_JetEnUp, &b_mMtToPfMet_JetEnUp);
   _tree->SetBranchAddress("mMtToPfMet_JetResDown", &mMtToPfMet_JetResDown, &b_mMtToPfMet_JetResDown);
   _tree->SetBranchAddress("mMtToPfMet_JetResUp", &mMtToPfMet_JetResUp, &b_mMtToPfMet_JetResUp);
   _tree->SetBranchAddress("mMtToPfMet_MuonEnDown", &mMtToPfMet_MuonEnDown, &b_mMtToPfMet_MuonEnDown);
   _tree->SetBranchAddress("mMtToPfMet_MuonEnUp", &mMtToPfMet_MuonEnUp, &b_mMtToPfMet_MuonEnUp);
   _tree->SetBranchAddress("mMtToPfMet_PhotonEnDown", &mMtToPfMet_PhotonEnDown, &b_mMtToPfMet_PhotonEnDown);
   _tree->SetBranchAddress("mMtToPfMet_PhotonEnUp", &mMtToPfMet_PhotonEnUp, &b_mMtToPfMet_PhotonEnUp);
   _tree->SetBranchAddress("mMtToPfMet_Raw", &mMtToPfMet_Raw, &b_mMtToPfMet_Raw);
   _tree->SetBranchAddress("mMtToPfMet_TauEnDown", &mMtToPfMet_TauEnDown, &b_mMtToPfMet_TauEnDown);
   _tree->SetBranchAddress("mMtToPfMet_TauEnUp", &mMtToPfMet_TauEnUp, &b_mMtToPfMet_TauEnUp);
   _tree->SetBranchAddress("mMtToPfMet_UnclusteredEnDown", &mMtToPfMet_UnclusteredEnDown, &b_mMtToPfMet_UnclusteredEnDown);
   _tree->SetBranchAddress("mMtToPfMet_UnclusteredEnUp", &mMtToPfMet_UnclusteredEnUp, &b_mMtToPfMet_UnclusteredEnUp);
   _tree->SetBranchAddress("mMtToPfMet_type1", &mMtToPfMet_type1, &b_mMtToPfMet_type1);
   _tree->SetBranchAddress("mMu23Ele12DZFilter", &mMu23Ele12DZFilter, &b_mMu23Ele12DZFilter);
   _tree->SetBranchAddress("mMu23Ele12Filter", &mMu23Ele12Filter, &b_mMu23Ele12Filter);
   _tree->SetBranchAddress("mMu8Ele23DZFilter", &mMu8Ele23DZFilter, &b_mMu8Ele23DZFilter);
   _tree->SetBranchAddress("mMu8Ele23Filter", &mMu8Ele23Filter, &b_mMu8Ele23Filter);
   _tree->SetBranchAddress("mMuonHits", &mMuonHits, &b_mMuonHits);
   _tree->SetBranchAddress("mNearestZMass", &mNearestZMass, &b_mNearestZMass);
   _tree->SetBranchAddress("mNormTrkChi2", &mNormTrkChi2, &b_mNormTrkChi2);
   _tree->SetBranchAddress("mNormalizedChi2", &mNormalizedChi2, &b_mNormalizedChi2);
   _tree->SetBranchAddress("mPFChargedHadronIsoR04", &mPFChargedHadronIsoR04, &b_mPFChargedHadronIsoR04);
   _tree->SetBranchAddress("mPFChargedIso", &mPFChargedIso, &b_mPFChargedIso);
   _tree->SetBranchAddress("mPFIDLoose", &mPFIDLoose, &b_mPFIDLoose);
   _tree->SetBranchAddress("mPFIDMedium", &mPFIDMedium, &b_mPFIDMedium);
   _tree->SetBranchAddress("mPFIDTight", &mPFIDTight, &b_mPFIDTight);
   _tree->SetBranchAddress("mPFNeutralHadronIsoR04", &mPFNeutralHadronIsoR04, &b_mPFNeutralHadronIsoR04);
   _tree->SetBranchAddress("mPFNeutralIso", &mPFNeutralIso, &b_mPFNeutralIso);
   _tree->SetBranchAddress("mPFPUChargedIso", &mPFPUChargedIso, &b_mPFPUChargedIso);
   _tree->SetBranchAddress("mPFPhotonIso", &mPFPhotonIso, &b_mPFPhotonIso);
   _tree->SetBranchAddress("mPFPhotonIsoR04", &mPFPhotonIsoR04, &b_mPFPhotonIsoR04);
   _tree->SetBranchAddress("mPFPileupIsoR04", &mPFPileupIsoR04, &b_mPFPileupIsoR04);
   _tree->SetBranchAddress("mPVDXY", &mPVDXY, &b_mPVDXY);
   _tree->SetBranchAddress("mPVDZ", &mPVDZ, &b_mPVDZ);
   _tree->SetBranchAddress("mPhi", &mPhi, &b_mPhi);
   _tree->SetBranchAddress("mPhi_MuonEnDown", &mPhi_MuonEnDown, &b_mPhi_MuonEnDown);
   _tree->SetBranchAddress("mPhi_MuonEnUp", &mPhi_MuonEnUp, &b_mPhi_MuonEnUp);
   _tree->SetBranchAddress("mPixHits", &mPixHits, &b_mPixHits);
   _tree->SetBranchAddress("mPt", &mPt, &b_mPt);
   _tree->SetBranchAddress("mPt_MuonEnDown", &mPt_MuonEnDown, &b_mPt_MuonEnDown);
   _tree->SetBranchAddress("mPt_MuonEnUp", &mPt_MuonEnUp, &b_mPt_MuonEnUp);
   _tree->SetBranchAddress("mRank", &mRank, &b_mRank);
   _tree->SetBranchAddress("mRelPFIsoDBDefault", &mRelPFIsoDBDefault, &b_mRelPFIsoDBDefault);
   _tree->SetBranchAddress("mRelPFIsoDBDefaultR04", &mRelPFIsoDBDefaultR04, &b_mRelPFIsoDBDefaultR04);
   _tree->SetBranchAddress("mRelPFIsoRho", &mRelPFIsoRho, &b_mRelPFIsoRho);
   _tree->SetBranchAddress("mRho", &mRho, &b_mRho);
   _tree->SetBranchAddress("mSIP2D", &mSIP2D, &b_mSIP2D);
   _tree->SetBranchAddress("mSIP3D", &mSIP3D, &b_mSIP3D);
   _tree->SetBranchAddress("mSegmentCompatibility", &mSegmentCompatibility, &b_mSegmentCompatibility);
   _tree->SetBranchAddress("mTkLayersWithMeasurement", &mTkLayersWithMeasurement, &b_mTkLayersWithMeasurement);
   _tree->SetBranchAddress("mTrkIsoDR03", &mTrkIsoDR03, &b_mTrkIsoDR03);
   _tree->SetBranchAddress("mTrkKink", &mTrkKink, &b_mTrkKink);
   _tree->SetBranchAddress("mTypeCode", &mTypeCode, &b_mTypeCode);
   _tree->SetBranchAddress("mVZ", &mVZ, &b_mVZ);
   _tree->SetBranchAddress("mValidFraction", &mValidFraction, &b_mValidFraction);
   _tree->SetBranchAddress("mZTTGenMatching", &mZTTGenMatching, &b_mZTTGenMatching);
   _tree->SetBranchAddress("m_t_CosThetaStar", &m_t_CosThetaStar, &b_m_t_CosThetaStar);
   _tree->SetBranchAddress("m_t_DPhi", &m_t_DPhi, &b_m_t_DPhi);
   _tree->SetBranchAddress("m_t_DR", &m_t_DR, &b_m_t_DR);
   _tree->SetBranchAddress("m_t_Eta", &m_t_Eta, &b_m_t_Eta);
   _tree->SetBranchAddress("m_t_Mass", &m_t_Mass, &b_m_t_Mass);
   _tree->SetBranchAddress("m_t_Mass_TauEnDown", &m_t_Mass_TauEnDown, &b_m_t_Mass_TauEnDown);
   _tree->SetBranchAddress("m_t_Mass_TauEnUp", &m_t_Mass_TauEnUp, &b_m_t_Mass_TauEnUp);
   _tree->SetBranchAddress("m_t_Mt", &m_t_Mt, &b_m_t_Mt);
   _tree->SetBranchAddress("m_t_MtTotal", &m_t_MtTotal, &b_m_t_MtTotal);
   _tree->SetBranchAddress("m_t_Mt_TauEnDown", &m_t_Mt_TauEnDown, &b_m_t_Mt_TauEnDown);
   _tree->SetBranchAddress("m_t_Mt_TauEnUp", &m_t_Mt_TauEnUp, &b_m_t_Mt_TauEnUp);
   _tree->SetBranchAddress("m_t_MvaMet", &m_t_MvaMet, &b_m_t_MvaMet);
   _tree->SetBranchAddress("m_t_MvaMetCovMatrix00", &m_t_MvaMetCovMatrix00, &b_m_t_MvaMetCovMatrix00);
   _tree->SetBranchAddress("m_t_MvaMetCovMatrix01", &m_t_MvaMetCovMatrix01, &b_m_t_MvaMetCovMatrix01);
   _tree->SetBranchAddress("m_t_MvaMetCovMatrix10", &m_t_MvaMetCovMatrix10, &b_m_t_MvaMetCovMatrix10);
   _tree->SetBranchAddress("m_t_MvaMetCovMatrix11", &m_t_MvaMetCovMatrix11, &b_m_t_MvaMetCovMatrix11);
   _tree->SetBranchAddress("m_t_MvaMetPhi", &m_t_MvaMetPhi, &b_m_t_MvaMetPhi);
   _tree->SetBranchAddress("m_t_PZeta", &m_t_PZeta, &b_m_t_PZeta);
   _tree->SetBranchAddress("m_t_PZetaLess0p85PZetaVis", &m_t_PZetaLess0p85PZetaVis, &b_m_t_PZetaLess0p85PZetaVis);
   _tree->SetBranchAddress("m_t_PZetaVis", &m_t_PZetaVis, &b_m_t_PZetaVis);
   _tree->SetBranchAddress("m_t_Phi", &m_t_Phi, &b_m_t_Phi);
   _tree->SetBranchAddress("m_t_Pt", &m_t_Pt, &b_m_t_Pt);
   _tree->SetBranchAddress("m_t_SS", &m_t_SS, &b_m_t_SS);
   _tree->SetBranchAddress("m_t_ToMETDPhi_Ty1", &m_t_ToMETDPhi_Ty1, &b_m_t_ToMETDPhi_Ty1);
   _tree->SetBranchAddress("m_t_collinearmass", &m_t_collinearmass, &b_m_t_collinearmass);
   _tree->SetBranchAddress("m_t_collinearmass_EleEnDown", &m_t_collinearmass_EleEnDown, &b_m_t_collinearmass_EleEnDown);
   _tree->SetBranchAddress("m_t_collinearmass_EleEnUp", &m_t_collinearmass_EleEnUp, &b_m_t_collinearmass_EleEnUp);
   _tree->SetBranchAddress("m_t_collinearmass_JetEnDown", &m_t_collinearmass_JetEnDown, &b_m_t_collinearmass_JetEnDown);
   _tree->SetBranchAddress("m_t_collinearmass_JetEnUp", &m_t_collinearmass_JetEnUp, &b_m_t_collinearmass_JetEnUp);
   _tree->SetBranchAddress("m_t_collinearmass_MuEnDown", &m_t_collinearmass_MuEnDown, &b_m_t_collinearmass_MuEnDown);
   _tree->SetBranchAddress("m_t_collinearmass_MuEnUp", &m_t_collinearmass_MuEnUp, &b_m_t_collinearmass_MuEnUp);
   _tree->SetBranchAddress("m_t_collinearmass_TauEnDown", &m_t_collinearmass_TauEnDown, &b_m_t_collinearmass_TauEnDown);
   _tree->SetBranchAddress("m_t_collinearmass_TauEnUp", &m_t_collinearmass_TauEnUp, &b_m_t_collinearmass_TauEnUp);
   _tree->SetBranchAddress("m_t_collinearmass_UnclusteredEnDown", &m_t_collinearmass_UnclusteredEnDown, &b_m_t_collinearmass_UnclusteredEnDown);
   _tree->SetBranchAddress("m_t_collinearmass_UnclusteredEnUp", &m_t_collinearmass_UnclusteredEnUp, &b_m_t_collinearmass_UnclusteredEnUp);
   _tree->SetBranchAddress("m_t_pt_tt", &m_t_pt_tt, &b_m_t_pt_tt);
   _tree->SetBranchAddress("metSig", &metSig, &b_metSig);
   _tree->SetBranchAddress("metcov00", &metcov00, &b_metcov00);
   _tree->SetBranchAddress("metcov01", &metcov01, &b_metcov01);
   _tree->SetBranchAddress("metcov10", &metcov10, &b_metcov10);
   _tree->SetBranchAddress("metcov11", &metcov11, &b_metcov11);
   _tree->SetBranchAddress("metcov00_DESYlike", &metcov00_DESYlike, &b_metcov00_DESYlike);
   _tree->SetBranchAddress("metcov01_DESYlike", &metcov01_DESYlike, &b_metcov01_DESYlike);
   _tree->SetBranchAddress("metcov10_DESYlike", &metcov10_DESYlike, &b_metcov10_DESYlike);
   _tree->SetBranchAddress("metcov11_DESYlike", &metcov11_DESYlike, &b_metcov11_DESYlike);
   _tree->SetBranchAddress("muGlbIsoVetoPt10", &muGlbIsoVetoPt10, &b_muGlbIsoVetoPt10);
   _tree->SetBranchAddress("muVetoPt15IsoIdVtx", &muVetoPt15IsoIdVtx, &b_muVetoPt15IsoIdVtx);
   _tree->SetBranchAddress("muVetoPt5", &muVetoPt5, &b_muVetoPt5);
   _tree->SetBranchAddress("muVetoPt5IsoIdVtx", &muVetoPt5IsoIdVtx, &b_muVetoPt5IsoIdVtx);
   _tree->SetBranchAddress("muVetoZTTp001dxyz", &muVetoZTTp001dxyz, &b_muVetoZTTp001dxyz);
   _tree->SetBranchAddress("muVetoZTTp001dxyzR0", &muVetoZTTp001dxyzR0, &b_muVetoZTTp001dxyzR0);
   _tree->SetBranchAddress("nTruePU", &nTruePU, &b_nTruePU);
   _tree->SetBranchAddress("numGenJets", &numGenJets, &b_numGenJets);
   _tree->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   _tree->SetBranchAddress("processID", &processID, &b_processID);
   _tree->SetBranchAddress("puppiMetEt", &puppiMetEt, &b_puppiMetEt);
   _tree->SetBranchAddress("puppiMetPhi", &puppiMetPhi, &b_puppiMetPhi);
   _tree->SetBranchAddress("pvChi2", &pvChi2, &b_pvChi2);
   _tree->SetBranchAddress("pvDX", &pvDX, &b_pvDX);
   _tree->SetBranchAddress("pvDY", &pvDY, &b_pvDY);
   _tree->SetBranchAddress("pvDZ", &pvDZ, &b_pvDZ);
   _tree->SetBranchAddress("pvIsFake", &pvIsFake, &b_pvIsFake);
   _tree->SetBranchAddress("pvIsValid", &pvIsValid, &b_pvIsValid);
   _tree->SetBranchAddress("pvNormChi2", &pvNormChi2, &b_pvNormChi2);
   _tree->SetBranchAddress("pvRho", &pvRho, &b_pvRho);
   _tree->SetBranchAddress("pvX", &pvX, &b_pvX);
   _tree->SetBranchAddress("pvY", &pvY, &b_pvY);
   _tree->SetBranchAddress("pvZ", &pvZ, &b_pvZ);
   _tree->SetBranchAddress("pvndof", &pvndof, &b_pvndof);
   _tree->SetBranchAddress("raw_pfMetEt", &raw_pfMetEt, &b_raw_pfMetEt);
   _tree->SetBranchAddress("raw_pfMetPhi", &raw_pfMetPhi, &b_raw_pfMetPhi);
   _tree->SetBranchAddress("recoilDaught", &recoilDaught, &b_recoilDaught);
   _tree->SetBranchAddress("recoilWithMet", &recoilWithMet, &b_recoilWithMet);
   _tree->SetBranchAddress("rho", &rho, &b_rho);
   _tree->SetBranchAddress("run", &run, &b_run);
   _tree->SetBranchAddress("singleE17SingleMu8Group", &singleE17SingleMu8Group, &b_singleE17SingleMu8Group);
   _tree->SetBranchAddress("singleE17SingleMu8Pass", &singleE17SingleMu8Pass, &b_singleE17SingleMu8Pass);
   _tree->SetBranchAddress("singleE17SingleMu8Prescale", &singleE17SingleMu8Prescale, &b_singleE17SingleMu8Prescale);
   _tree->SetBranchAddress("singleE20SingleTau28Group", &singleE20SingleTau28Group, &b_singleE20SingleTau28Group);
   _tree->SetBranchAddress("singleE20SingleTau28Pass", &singleE20SingleTau28Pass, &b_singleE20SingleTau28Pass);
   _tree->SetBranchAddress("singleE20SingleTau28Prescale", &singleE20SingleTau28Prescale, &b_singleE20SingleTau28Prescale);
   _tree->SetBranchAddress("singleE22SingleTau20SingleL1Group", &singleE22SingleTau20SingleL1Group, &b_singleE22SingleTau20SingleL1Group);
   _tree->SetBranchAddress("singleE22SingleTau20SingleL1Pass", &singleE22SingleTau20SingleL1Pass, &b_singleE22SingleTau20SingleL1Pass);
   _tree->SetBranchAddress("singleE22SingleTau20SingleL1Prescale", &singleE22SingleTau20SingleL1Prescale, &b_singleE22SingleTau20SingleL1Prescale);
   _tree->SetBranchAddress("singleE22SingleTau29Group", &singleE22SingleTau29Group, &b_singleE22SingleTau29Group);
   _tree->SetBranchAddress("singleE22SingleTau29Pass", &singleE22SingleTau29Pass, &b_singleE22SingleTau29Pass);
   _tree->SetBranchAddress("singleE22SingleTau29Prescale", &singleE22SingleTau29Prescale, &b_singleE22SingleTau29Prescale);
   _tree->SetBranchAddress("singleE23SingleMu8Group", &singleE23SingleMu8Group, &b_singleE23SingleMu8Group);
   _tree->SetBranchAddress("singleE23SingleMu8Pass", &singleE23SingleMu8Pass, &b_singleE23SingleMu8Pass);
   _tree->SetBranchAddress("singleE23SingleMu8Prescale", &singleE23SingleMu8Prescale, &b_singleE23SingleMu8Prescale);
   _tree->SetBranchAddress("singleE24SingleTau20Group", &singleE24SingleTau20Group, &b_singleE24SingleTau20Group);
   _tree->SetBranchAddress("singleE24SingleTau20Pass", &singleE24SingleTau20Pass, &b_singleE24SingleTau20Pass);
   _tree->SetBranchAddress("singleE24SingleTau20Prescale", &singleE24SingleTau20Prescale, &b_singleE24SingleTau20Prescale);
   _tree->SetBranchAddress("singleE24SingleTau20SingleL1Group", &singleE24SingleTau20SingleL1Group, &b_singleE24SingleTau20SingleL1Group);
   _tree->SetBranchAddress("singleE24SingleTau20SingleL1Pass", &singleE24SingleTau20SingleL1Pass, &b_singleE24SingleTau20SingleL1Pass);
   _tree->SetBranchAddress("singleE24SingleTau20SingleL1Prescale", &singleE24SingleTau20SingleL1Prescale, &b_singleE24SingleTau20SingleL1Prescale);
   _tree->SetBranchAddress("singleE24SingleTau30Group", &singleE24SingleTau30Group, &b_singleE24SingleTau30Group);
   _tree->SetBranchAddress("singleE24SingleTau30Pass", &singleE24SingleTau30Pass, &b_singleE24SingleTau30Pass);
   _tree->SetBranchAddress("singleE24SingleTau30Prescale", &singleE24SingleTau30Prescale, &b_singleE24SingleTau30Prescale);
   _tree->SetBranchAddress("singleE25eta2p1TightGroup", &singleE25eta2p1TightGroup, &b_singleE25eta2p1TightGroup);
   _tree->SetBranchAddress("singleE25eta2p1TightPass", &singleE25eta2p1TightPass, &b_singleE25eta2p1TightPass);
   _tree->SetBranchAddress("singleE25eta2p1TightPrescale", &singleE25eta2p1TightPrescale, &b_singleE25eta2p1TightPrescale);
   _tree->SetBranchAddress("singleE27SingleTau20SingleL1Group", &singleE27SingleTau20SingleL1Group, &b_singleE27SingleTau20SingleL1Group);
   _tree->SetBranchAddress("singleE27SingleTau20SingleL1Pass", &singleE27SingleTau20SingleL1Pass, &b_singleE27SingleTau20SingleL1Pass);
   _tree->SetBranchAddress("singleE27SingleTau20SingleL1Prescale", &singleE27SingleTau20SingleL1Prescale, &b_singleE27SingleTau20SingleL1Prescale);
   _tree->SetBranchAddress("singleE27TightGroup", &singleE27TightGroup, &b_singleE27TightGroup);
   _tree->SetBranchAddress("singleE27TightPass", &singleE27TightPass, &b_singleE27TightPass);
   _tree->SetBranchAddress("singleE27TightPrescale", &singleE27TightPrescale, &b_singleE27TightPrescale);
   _tree->SetBranchAddress("singleE27eta2p1LooseGroup", &singleE27eta2p1LooseGroup, &b_singleE27eta2p1LooseGroup);
   _tree->SetBranchAddress("singleE27eta2p1LoosePass", &singleE27eta2p1LoosePass, &b_singleE27eta2p1LoosePass);
   _tree->SetBranchAddress("singleE27eta2p1LoosePrescale", &singleE27eta2p1LoosePrescale, &b_singleE27eta2p1LoosePrescale);
   _tree->SetBranchAddress("singleE27eta2p1TightGroup", &singleE27eta2p1TightGroup, &b_singleE27eta2p1TightGroup);
   _tree->SetBranchAddress("singleE27eta2p1TightPass", &singleE27eta2p1TightPass, &b_singleE27eta2p1TightPass);
   _tree->SetBranchAddress("singleE27eta2p1TightPrescale", &singleE27eta2p1TightPrescale, &b_singleE27eta2p1TightPrescale);
   _tree->SetBranchAddress("singleE32SingleTau20SingleL1Group", &singleE32SingleTau20SingleL1Group, &b_singleE32SingleTau20SingleL1Group);
   _tree->SetBranchAddress("singleE32SingleTau20SingleL1Pass", &singleE32SingleTau20SingleL1Pass, &b_singleE32SingleTau20SingleL1Pass);
   _tree->SetBranchAddress("singleE32SingleTau20SingleL1Prescale", &singleE32SingleTau20SingleL1Prescale, &b_singleE32SingleTau20SingleL1Prescale);
   _tree->SetBranchAddress("singleE36SingleTau30Group", &singleE36SingleTau30Group, &b_singleE36SingleTau30Group);
   _tree->SetBranchAddress("singleE36SingleTau30Pass", &singleE36SingleTau30Pass, &b_singleE36SingleTau30Pass);
   _tree->SetBranchAddress("singleE36SingleTau30Prescale", &singleE36SingleTau30Prescale, &b_singleE36SingleTau30Prescale);
   _tree->SetBranchAddress("singleESingleMuGroup", &singleESingleMuGroup, &b_singleESingleMuGroup);
   _tree->SetBranchAddress("singleESingleMuPass", &singleESingleMuPass, &b_singleESingleMuPass);
   _tree->SetBranchAddress("singleESingleMuPrescale", &singleESingleMuPrescale, &b_singleESingleMuPrescale);
   _tree->SetBranchAddress("singleE_leg1Group", &singleE_leg1Group, &b_singleE_leg1Group);
   _tree->SetBranchAddress("singleE_leg1Pass", &singleE_leg1Pass, &b_singleE_leg1Pass);
   _tree->SetBranchAddress("singleE_leg1Prescale", &singleE_leg1Prescale, &b_singleE_leg1Prescale);
   _tree->SetBranchAddress("singleE_leg2Group", &singleE_leg2Group, &b_singleE_leg2Group);
   _tree->SetBranchAddress("singleE_leg2Pass", &singleE_leg2Pass, &b_singleE_leg2Pass);
   _tree->SetBranchAddress("singleE_leg2Prescale", &singleE_leg2Prescale, &b_singleE_leg2Prescale);
   _tree->SetBranchAddress("singleIsoMu20Group", &singleIsoMu20Group, &b_singleIsoMu20Group);
   _tree->SetBranchAddress("singleIsoMu20Pass", &singleIsoMu20Pass, &b_singleIsoMu20Pass);
   _tree->SetBranchAddress("singleIsoMu20Prescale", &singleIsoMu20Prescale, &b_singleIsoMu20Prescale);
   _tree->SetBranchAddress("singleIsoMu22Group", &singleIsoMu22Group, &b_singleIsoMu22Group);
   _tree->SetBranchAddress("singleIsoMu22Pass", &singleIsoMu22Pass, &b_singleIsoMu22Pass);
   _tree->SetBranchAddress("singleIsoMu22Prescale", &singleIsoMu22Prescale, &b_singleIsoMu22Prescale);
   _tree->SetBranchAddress("singleIsoMu22eta2p1Group", &singleIsoMu22eta2p1Group, &b_singleIsoMu22eta2p1Group);
   _tree->SetBranchAddress("singleIsoMu22eta2p1Pass", &singleIsoMu22eta2p1Pass, &b_singleIsoMu22eta2p1Pass);
   _tree->SetBranchAddress("singleIsoMu22eta2p1Prescale", &singleIsoMu22eta2p1Prescale, &b_singleIsoMu22eta2p1Prescale);
   _tree->SetBranchAddress("singleIsoMu24Group", &singleIsoMu24Group, &b_singleIsoMu24Group);
   _tree->SetBranchAddress("singleIsoMu24Pass", &singleIsoMu24Pass, &b_singleIsoMu24Pass);
   _tree->SetBranchAddress("singleIsoMu24Prescale", &singleIsoMu24Prescale, &b_singleIsoMu24Prescale);
   _tree->SetBranchAddress("singleIsoMu24eta2p1Group", &singleIsoMu24eta2p1Group, &b_singleIsoMu24eta2p1Group);
   _tree->SetBranchAddress("singleIsoMu24eta2p1Pass", &singleIsoMu24eta2p1Pass, &b_singleIsoMu24eta2p1Pass);
   _tree->SetBranchAddress("singleIsoMu24eta2p1Prescale", &singleIsoMu24eta2p1Prescale, &b_singleIsoMu24eta2p1Prescale);
   _tree->SetBranchAddress("singleIsoMu27Group", &singleIsoMu27Group, &b_singleIsoMu27Group);
   _tree->SetBranchAddress("singleIsoMu27Pass", &singleIsoMu27Pass, &b_singleIsoMu27Pass);
   _tree->SetBranchAddress("singleIsoMu27Prescale", &singleIsoMu27Prescale, &b_singleIsoMu27Prescale);
   _tree->SetBranchAddress("singleIsoTkMu20Group", &singleIsoTkMu20Group, &b_singleIsoTkMu20Group);
   _tree->SetBranchAddress("singleIsoTkMu20Pass", &singleIsoTkMu20Pass, &b_singleIsoTkMu20Pass);
   _tree->SetBranchAddress("singleIsoTkMu20Prescale", &singleIsoTkMu20Prescale, &b_singleIsoTkMu20Prescale);
   _tree->SetBranchAddress("singleIsoTkMu22Group", &singleIsoTkMu22Group, &b_singleIsoTkMu22Group);
   _tree->SetBranchAddress("singleIsoTkMu22Pass", &singleIsoTkMu22Pass, &b_singleIsoTkMu22Pass);
   _tree->SetBranchAddress("singleIsoTkMu22Prescale", &singleIsoTkMu22Prescale, &b_singleIsoTkMu22Prescale);
   _tree->SetBranchAddress("singleIsoTkMu22eta2p1Group", &singleIsoTkMu22eta2p1Group, &b_singleIsoTkMu22eta2p1Group);
   _tree->SetBranchAddress("singleIsoTkMu22eta2p1Pass", &singleIsoTkMu22eta2p1Pass, &b_singleIsoTkMu22eta2p1Pass);
   _tree->SetBranchAddress("singleIsoTkMu22eta2p1Prescale", &singleIsoTkMu22eta2p1Prescale, &b_singleIsoTkMu22eta2p1Prescale);
   _tree->SetBranchAddress("singleIsoTkMu24Group", &singleIsoTkMu24Group, &b_singleIsoTkMu24Group);
   _tree->SetBranchAddress("singleIsoTkMu24Pass", &singleIsoTkMu24Pass, &b_singleIsoTkMu24Pass);
   _tree->SetBranchAddress("singleIsoTkMu24Prescale", &singleIsoTkMu24Prescale, &b_singleIsoTkMu24Prescale);
   _tree->SetBranchAddress("singleIsoTkMu24eta2p1Group", &singleIsoTkMu24eta2p1Group, &b_singleIsoTkMu24eta2p1Group);
   _tree->SetBranchAddress("singleIsoTkMu24eta2p1Pass", &singleIsoTkMu24eta2p1Pass, &b_singleIsoTkMu24eta2p1Pass);
   _tree->SetBranchAddress("singleIsoTkMu24eta2p1Prescale", &singleIsoTkMu24eta2p1Prescale, &b_singleIsoTkMu24eta2p1Prescale);
   _tree->SetBranchAddress("singleMu17SingleE12Group", &singleMu17SingleE12Group, &b_singleMu17SingleE12Group);
   _tree->SetBranchAddress("singleMu17SingleE12Pass", &singleMu17SingleE12Pass, &b_singleMu17SingleE12Pass);
   _tree->SetBranchAddress("singleMu17SingleE12Prescale", &singleMu17SingleE12Prescale, &b_singleMu17SingleE12Prescale);
   _tree->SetBranchAddress("singleMu19eta2p1LooseTau20Group", &singleMu19eta2p1LooseTau20Group, &b_singleMu19eta2p1LooseTau20Group);
   _tree->SetBranchAddress("singleMu19eta2p1LooseTau20Pass", &singleMu19eta2p1LooseTau20Pass, &b_singleMu19eta2p1LooseTau20Pass);
   _tree->SetBranchAddress("singleMu19eta2p1LooseTau20Prescale", &singleMu19eta2p1LooseTau20Prescale, &b_singleMu19eta2p1LooseTau20Prescale);
   _tree->SetBranchAddress("singleMu19eta2p1LooseTau20singleL1Group", &singleMu19eta2p1LooseTau20singleL1Group, &b_singleMu19eta2p1LooseTau20singleL1Group);
   _tree->SetBranchAddress("singleMu19eta2p1LooseTau20singleL1Pass", &singleMu19eta2p1LooseTau20singleL1Pass, &b_singleMu19eta2p1LooseTau20singleL1Pass);
   _tree->SetBranchAddress("singleMu19eta2p1LooseTau20singleL1Prescale", &singleMu19eta2p1LooseTau20singleL1Prescale, &b_singleMu19eta2p1LooseTau20singleL1Prescale);
   _tree->SetBranchAddress("singleMu21eta2p1LooseTau20singleL1Group", &singleMu21eta2p1LooseTau20singleL1Group, &b_singleMu21eta2p1LooseTau20singleL1Group);
   _tree->SetBranchAddress("singleMu21eta2p1LooseTau20singleL1Pass", &singleMu21eta2p1LooseTau20singleL1Pass, &b_singleMu21eta2p1LooseTau20singleL1Pass);
   _tree->SetBranchAddress("singleMu21eta2p1LooseTau20singleL1Prescale", &singleMu21eta2p1LooseTau20singleL1Prescale, &b_singleMu21eta2p1LooseTau20singleL1Prescale);
   _tree->SetBranchAddress("singleMu23SingleE12DZGroup", &singleMu23SingleE12DZGroup, &b_singleMu23SingleE12DZGroup);
   _tree->SetBranchAddress("singleMu23SingleE12DZPass", &singleMu23SingleE12DZPass, &b_singleMu23SingleE12DZPass);
   _tree->SetBranchAddress("singleMu23SingleE12DZPrescale", &singleMu23SingleE12DZPrescale, &b_singleMu23SingleE12DZPrescale);
   _tree->SetBranchAddress("singleMu23SingleE12Group", &singleMu23SingleE12Group, &b_singleMu23SingleE12Group);
   _tree->SetBranchAddress("singleMu23SingleE12Pass", &singleMu23SingleE12Pass, &b_singleMu23SingleE12Pass);
   _tree->SetBranchAddress("singleMu23SingleE12Prescale", &singleMu23SingleE12Prescale, &b_singleMu23SingleE12Prescale);
   _tree->SetBranchAddress("singleMu23SingleE8Group", &singleMu23SingleE8Group, &b_singleMu23SingleE8Group);
   _tree->SetBranchAddress("singleMu23SingleE8Pass", &singleMu23SingleE8Pass, &b_singleMu23SingleE8Pass);
   _tree->SetBranchAddress("singleMu23SingleE8Prescale", &singleMu23SingleE8Prescale, &b_singleMu23SingleE8Prescale);
   _tree->SetBranchAddress("singleMu8SingleE23DZGroup", &singleMu8SingleE23DZGroup, &b_singleMu8SingleE23DZGroup);
   _tree->SetBranchAddress("singleMu8SingleE23DZPass", &singleMu8SingleE23DZPass, &b_singleMu8SingleE23DZPass);
   _tree->SetBranchAddress("singleMu8SingleE23DZPrescale", &singleMu8SingleE23DZPrescale, &b_singleMu8SingleE23DZPrescale);
   _tree->SetBranchAddress("singleMuGroup", &singleMuGroup, &b_singleMuGroup);
   _tree->SetBranchAddress("singleMuPass", &singleMuPass, &b_singleMuPass);
   _tree->SetBranchAddress("singleMuPrescale", &singleMuPrescale, &b_singleMuPrescale);
   _tree->SetBranchAddress("singleMuSingleEGroup", &singleMuSingleEGroup, &b_singleMuSingleEGroup);
   _tree->SetBranchAddress("singleMuSingleEPass", &singleMuSingleEPass, &b_singleMuSingleEPass);
   _tree->SetBranchAddress("singleMuSingleEPrescale", &singleMuSingleEPrescale, &b_singleMuSingleEPrescale);
   _tree->SetBranchAddress("singleMu_leg1Group", &singleMu_leg1Group, &b_singleMu_leg1Group);
   _tree->SetBranchAddress("singleMu_leg1Pass", &singleMu_leg1Pass, &b_singleMu_leg1Pass);
   _tree->SetBranchAddress("singleMu_leg1Prescale", &singleMu_leg1Prescale, &b_singleMu_leg1Prescale);
   _tree->SetBranchAddress("singleMu_leg1_noisoGroup", &singleMu_leg1_noisoGroup, &b_singleMu_leg1_noisoGroup);
   _tree->SetBranchAddress("singleMu_leg1_noisoPass", &singleMu_leg1_noisoPass, &b_singleMu_leg1_noisoPass);
   _tree->SetBranchAddress("singleMu_leg1_noisoPrescale", &singleMu_leg1_noisoPrescale, &b_singleMu_leg1_noisoPrescale);
   _tree->SetBranchAddress("singleMu_leg2Group", &singleMu_leg2Group, &b_singleMu_leg2Group);
   _tree->SetBranchAddress("singleMu_leg2Pass", &singleMu_leg2Pass, &b_singleMu_leg2Pass);
   _tree->SetBranchAddress("singleMu_leg2Prescale", &singleMu_leg2Prescale, &b_singleMu_leg2Prescale);
   _tree->SetBranchAddress("singleMu_leg2_noisoGroup", &singleMu_leg2_noisoGroup, &b_singleMu_leg2_noisoGroup);
   _tree->SetBranchAddress("singleMu_leg2_noisoPass", &singleMu_leg2_noisoPass, &b_singleMu_leg2_noisoPass);
   _tree->SetBranchAddress("singleMu_leg2_noisoPrescale", &singleMu_leg2_noisoPrescale, &b_singleMu_leg2_noisoPrescale);
   _tree->SetBranchAddress("singleTau140Group", &singleTau140Group, &b_singleTau140Group);
   _tree->SetBranchAddress("singleTau140Pass", &singleTau140Pass, &b_singleTau140Pass);
   _tree->SetBranchAddress("singleTau140Prescale", &singleTau140Prescale, &b_singleTau140Prescale);
   _tree->SetBranchAddress("singleTau140Trk50Group", &singleTau140Trk50Group, &b_singleTau140Trk50Group);
   _tree->SetBranchAddress("singleTau140Trk50Pass", &singleTau140Trk50Pass, &b_singleTau140Trk50Pass);
   _tree->SetBranchAddress("singleTau140Trk50Prescale", &singleTau140Trk50Prescale, &b_singleTau140Trk50Prescale);
   _tree->SetBranchAddress("tAbsEta", &tAbsEta, &b_tAbsEta);
   _tree->SetBranchAddress("tAgainstElectronLooseMVA6", &tAgainstElectronLooseMVA6, &b_tAgainstElectronLooseMVA6);
   _tree->SetBranchAddress("tAgainstElectronMVA6Raw", &tAgainstElectronMVA6Raw, &b_tAgainstElectronMVA6Raw);
   _tree->SetBranchAddress("tAgainstElectronMVA6category", &tAgainstElectronMVA6category, &b_tAgainstElectronMVA6category);
   _tree->SetBranchAddress("tAgainstElectronMediumMVA6", &tAgainstElectronMediumMVA6, &b_tAgainstElectronMediumMVA6);
   _tree->SetBranchAddress("tAgainstElectronTightMVA6", &tAgainstElectronTightMVA6, &b_tAgainstElectronTightMVA6);
   _tree->SetBranchAddress("tAgainstElectronVLooseMVA6", &tAgainstElectronVLooseMVA6, &b_tAgainstElectronVLooseMVA6);
   _tree->SetBranchAddress("tAgainstElectronVTightMVA6", &tAgainstElectronVTightMVA6, &b_tAgainstElectronVTightMVA6);
   _tree->SetBranchAddress("tAgainstMuonLoose3", &tAgainstMuonLoose3, &b_tAgainstMuonLoose3);
   _tree->SetBranchAddress("tAgainstMuonTight3", &tAgainstMuonTight3, &b_tAgainstMuonTight3);
   _tree->SetBranchAddress("tByCombinedIsolationDeltaBetaCorrRaw3Hits", &tByCombinedIsolationDeltaBetaCorrRaw3Hits, &b_tByCombinedIsolationDeltaBetaCorrRaw3Hits);
   _tree->SetBranchAddress("tByIsolationMVArun2v1DBdR03oldDMwLTraw", &tByIsolationMVArun2v1DBdR03oldDMwLTraw, &b_tByIsolationMVArun2v1DBdR03oldDMwLTraw);
   _tree->SetBranchAddress("tByIsolationMVArun2v1DBnewDMwLTraw", &tByIsolationMVArun2v1DBnewDMwLTraw, &b_tByIsolationMVArun2v1DBnewDMwLTraw);
   _tree->SetBranchAddress("tByIsolationMVArun2v1DBoldDMwLTraw", &tByIsolationMVArun2v1DBoldDMwLTraw, &b_tByIsolationMVArun2v1DBoldDMwLTraw);
   _tree->SetBranchAddress("tByIsolationMVArun2v1PWdR03oldDMwLTraw", &tByIsolationMVArun2v1PWdR03oldDMwLTraw, &b_tByIsolationMVArun2v1PWdR03oldDMwLTraw);
   _tree->SetBranchAddress("tByIsolationMVArun2v1PWnewDMwLTraw", &tByIsolationMVArun2v1PWnewDMwLTraw, &b_tByIsolationMVArun2v1PWnewDMwLTraw);
   _tree->SetBranchAddress("tByIsolationMVArun2v1PWoldDMwLTraw", &tByIsolationMVArun2v1PWoldDMwLTraw, &b_tByIsolationMVArun2v1PWoldDMwLTraw);
   _tree->SetBranchAddress("tByLooseCombinedIsolationDeltaBetaCorr3Hits", &tByLooseCombinedIsolationDeltaBetaCorr3Hits, &b_tByLooseCombinedIsolationDeltaBetaCorr3Hits);
   _tree->SetBranchAddress("tByLooseIsolationMVArun2v1DBdR03oldDMwLT", &tByLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_tByLooseIsolationMVArun2v1DBdR03oldDMwLT);
   _tree->SetBranchAddress("tByLooseIsolationMVArun2v1DBnewDMwLT", &tByLooseIsolationMVArun2v1DBnewDMwLT, &b_tByLooseIsolationMVArun2v1DBnewDMwLT);
   _tree->SetBranchAddress("tByLooseIsolationMVArun2v1DBoldDMwLT", &tByLooseIsolationMVArun2v1DBoldDMwLT, &b_tByLooseIsolationMVArun2v1DBoldDMwLT);
   _tree->SetBranchAddress("tByLooseIsolationMVArun2v1PWdR03oldDMwLT", &tByLooseIsolationMVArun2v1PWdR03oldDMwLT, &b_tByLooseIsolationMVArun2v1PWdR03oldDMwLT);
   _tree->SetBranchAddress("tByLooseIsolationMVArun2v1PWnewDMwLT", &tByLooseIsolationMVArun2v1PWnewDMwLT, &b_tByLooseIsolationMVArun2v1PWnewDMwLT);
   _tree->SetBranchAddress("tByLooseIsolationMVArun2v1PWoldDMwLT", &tByLooseIsolationMVArun2v1PWoldDMwLT, &b_tByLooseIsolationMVArun2v1PWoldDMwLT);
   _tree->SetBranchAddress("tByMediumCombinedIsolationDeltaBetaCorr3Hits", &tByMediumCombinedIsolationDeltaBetaCorr3Hits, &b_tByMediumCombinedIsolationDeltaBetaCorr3Hits);
   _tree->SetBranchAddress("tByMediumIsolationMVArun2v1DBdR03oldDMwLT", &tByMediumIsolationMVArun2v1DBdR03oldDMwLT, &b_tByMediumIsolationMVArun2v1DBdR03oldDMwLT);
   _tree->SetBranchAddress("tByMediumIsolationMVArun2v1DBnewDMwLT", &tByMediumIsolationMVArun2v1DBnewDMwLT, &b_tByMediumIsolationMVArun2v1DBnewDMwLT);
   _tree->SetBranchAddress("tByMediumIsolationMVArun2v1DBoldDMwLT", &tByMediumIsolationMVArun2v1DBoldDMwLT, &b_tByMediumIsolationMVArun2v1DBoldDMwLT);
   _tree->SetBranchAddress("tByMediumIsolationMVArun2v1PWdR03oldDMwLT", &tByMediumIsolationMVArun2v1PWdR03oldDMwLT, &b_tByMediumIsolationMVArun2v1PWdR03oldDMwLT);
   _tree->SetBranchAddress("tByMediumIsolationMVArun2v1PWnewDMwLT", &tByMediumIsolationMVArun2v1PWnewDMwLT, &b_tByMediumIsolationMVArun2v1PWnewDMwLT);
   _tree->SetBranchAddress("tByMediumIsolationMVArun2v1PWoldDMwLT", &tByMediumIsolationMVArun2v1PWoldDMwLT, &b_tByMediumIsolationMVArun2v1PWoldDMwLT);
   _tree->SetBranchAddress("tByPhotonPtSumOutsideSignalCone", &tByPhotonPtSumOutsideSignalCone, &b_tByPhotonPtSumOutsideSignalCone);
   _tree->SetBranchAddress("tByTightCombinedIsolationDeltaBetaCorr3Hits", &tByTightCombinedIsolationDeltaBetaCorr3Hits, &b_tByTightCombinedIsolationDeltaBetaCorr3Hits);
   _tree->SetBranchAddress("tByTightIsolationMVArun2v1DBdR03oldDMwLT", &tByTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByTightIsolationMVArun2v1DBdR03oldDMwLT);
   _tree->SetBranchAddress("tByTightIsolationMVArun2v1DBnewDMwLT", &tByTightIsolationMVArun2v1DBnewDMwLT, &b_tByTightIsolationMVArun2v1DBnewDMwLT);
   _tree->SetBranchAddress("tByTightIsolationMVArun2v1DBoldDMwLT", &tByTightIsolationMVArun2v1DBoldDMwLT, &b_tByTightIsolationMVArun2v1DBoldDMwLT);
   _tree->SetBranchAddress("tByTightIsolationMVArun2v1PWdR03oldDMwLT", &tByTightIsolationMVArun2v1PWdR03oldDMwLT, &b_tByTightIsolationMVArun2v1PWdR03oldDMwLT);
   _tree->SetBranchAddress("tByTightIsolationMVArun2v1PWnewDMwLT", &tByTightIsolationMVArun2v1PWnewDMwLT, &b_tByTightIsolationMVArun2v1PWnewDMwLT);
   _tree->SetBranchAddress("tByTightIsolationMVArun2v1PWoldDMwLT", &tByTightIsolationMVArun2v1PWoldDMwLT, &b_tByTightIsolationMVArun2v1PWoldDMwLT);
   _tree->SetBranchAddress("tByVLooseIsolationMVArun2v1DBdR03oldDMwLT", &tByVLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVLooseIsolationMVArun2v1DBdR03oldDMwLT);
   _tree->SetBranchAddress("tByVLooseIsolationMVArun2v1DBnewDMwLT", &tByVLooseIsolationMVArun2v1DBnewDMwLT, &b_tByVLooseIsolationMVArun2v1DBnewDMwLT);
   _tree->SetBranchAddress("tByVLooseIsolationMVArun2v1DBoldDMwLT", &tByVLooseIsolationMVArun2v1DBoldDMwLT, &b_tByVLooseIsolationMVArun2v1DBoldDMwLT);
   _tree->SetBranchAddress("tByVLooseIsolationMVArun2v1PWdR03oldDMwLT", &tByVLooseIsolationMVArun2v1PWdR03oldDMwLT, &b_tByVLooseIsolationMVArun2v1PWdR03oldDMwLT);
   _tree->SetBranchAddress("tByVLooseIsolationMVArun2v1PWnewDMwLT", &tByVLooseIsolationMVArun2v1PWnewDMwLT, &b_tByVLooseIsolationMVArun2v1PWnewDMwLT);
   _tree->SetBranchAddress("tByVLooseIsolationMVArun2v1PWoldDMwLT", &tByVLooseIsolationMVArun2v1PWoldDMwLT, &b_tByVLooseIsolationMVArun2v1PWoldDMwLT);
   _tree->SetBranchAddress("tByVTightIsolationMVArun2v1DBdR03oldDMwLT", &tByVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVTightIsolationMVArun2v1DBdR03oldDMwLT);
   _tree->SetBranchAddress("tByVTightIsolationMVArun2v1DBnewDMwLT", &tByVTightIsolationMVArun2v1DBnewDMwLT, &b_tByVTightIsolationMVArun2v1DBnewDMwLT);
   _tree->SetBranchAddress("tByVTightIsolationMVArun2v1DBoldDMwLT", &tByVTightIsolationMVArun2v1DBoldDMwLT, &b_tByVTightIsolationMVArun2v1DBoldDMwLT);
   _tree->SetBranchAddress("tByVTightIsolationMVArun2v1PWdR03oldDMwLT", &tByVTightIsolationMVArun2v1PWdR03oldDMwLT, &b_tByVTightIsolationMVArun2v1PWdR03oldDMwLT);
   _tree->SetBranchAddress("tByVTightIsolationMVArun2v1PWnewDMwLT", &tByVTightIsolationMVArun2v1PWnewDMwLT, &b_tByVTightIsolationMVArun2v1PWnewDMwLT);
   _tree->SetBranchAddress("tByVTightIsolationMVArun2v1PWoldDMwLT", &tByVTightIsolationMVArun2v1PWoldDMwLT, &b_tByVTightIsolationMVArun2v1PWoldDMwLT);
   _tree->SetBranchAddress("tByVVTightIsolationMVArun2v1DBdR03oldDMwLT", &tByVVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVVTightIsolationMVArun2v1DBdR03oldDMwLT);
   _tree->SetBranchAddress("tByVVTightIsolationMVArun2v1DBnewDMwLT", &tByVVTightIsolationMVArun2v1DBnewDMwLT, &b_tByVVTightIsolationMVArun2v1DBnewDMwLT);
   _tree->SetBranchAddress("tByVVTightIsolationMVArun2v1DBoldDMwLT", &tByVVTightIsolationMVArun2v1DBoldDMwLT, &b_tByVVTightIsolationMVArun2v1DBoldDMwLT);
   _tree->SetBranchAddress("tByVVTightIsolationMVArun2v1PWdR03oldDMwLT", &tByVVTightIsolationMVArun2v1PWdR03oldDMwLT, &b_tByVVTightIsolationMVArun2v1PWdR03oldDMwLT);
   _tree->SetBranchAddress("tByVVTightIsolationMVArun2v1PWnewDMwLT", &tByVVTightIsolationMVArun2v1PWnewDMwLT, &b_tByVVTightIsolationMVArun2v1PWnewDMwLT);
   _tree->SetBranchAddress("tByVVTightIsolationMVArun2v1PWoldDMwLT", &tByVVTightIsolationMVArun2v1PWoldDMwLT, &b_tByVVTightIsolationMVArun2v1PWoldDMwLT);
   _tree->SetBranchAddress("tCharge", &tCharge, &b_tCharge);
   _tree->SetBranchAddress("tChargedIsoPtSum", &tChargedIsoPtSum, &b_tChargedIsoPtSum);
   _tree->SetBranchAddress("tChargedIsoPtSumdR03", &tChargedIsoPtSumdR03, &b_tChargedIsoPtSumdR03);
   _tree->SetBranchAddress("tComesFromHiggs", &tComesFromHiggs, &b_tComesFromHiggs);
   _tree->SetBranchAddress("tDPhiToPfMet_ElectronEnDown", &tDPhiToPfMet_ElectronEnDown, &b_tDPhiToPfMet_ElectronEnDown);
   _tree->SetBranchAddress("tDPhiToPfMet_ElectronEnUp", &tDPhiToPfMet_ElectronEnUp, &b_tDPhiToPfMet_ElectronEnUp);
   _tree->SetBranchAddress("tDPhiToPfMet_JetEnDown", &tDPhiToPfMet_JetEnDown, &b_tDPhiToPfMet_JetEnDown);
   _tree->SetBranchAddress("tDPhiToPfMet_JetEnUp", &tDPhiToPfMet_JetEnUp, &b_tDPhiToPfMet_JetEnUp);
   _tree->SetBranchAddress("tDPhiToPfMet_JetResDown", &tDPhiToPfMet_JetResDown, &b_tDPhiToPfMet_JetResDown);
   _tree->SetBranchAddress("tDPhiToPfMet_JetResUp", &tDPhiToPfMet_JetResUp, &b_tDPhiToPfMet_JetResUp);
   _tree->SetBranchAddress("tDPhiToPfMet_MuonEnDown", &tDPhiToPfMet_MuonEnDown, &b_tDPhiToPfMet_MuonEnDown);
   _tree->SetBranchAddress("tDPhiToPfMet_MuonEnUp", &tDPhiToPfMet_MuonEnUp, &b_tDPhiToPfMet_MuonEnUp);
   _tree->SetBranchAddress("tDPhiToPfMet_PhotonEnDown", &tDPhiToPfMet_PhotonEnDown, &b_tDPhiToPfMet_PhotonEnDown);
   _tree->SetBranchAddress("tDPhiToPfMet_PhotonEnUp", &tDPhiToPfMet_PhotonEnUp, &b_tDPhiToPfMet_PhotonEnUp);
   _tree->SetBranchAddress("tDPhiToPfMet_TauEnDown", &tDPhiToPfMet_TauEnDown, &b_tDPhiToPfMet_TauEnDown);
   _tree->SetBranchAddress("tDPhiToPfMet_TauEnUp", &tDPhiToPfMet_TauEnUp, &b_tDPhiToPfMet_TauEnUp);
   _tree->SetBranchAddress("tDPhiToPfMet_UnclusteredEnDown", &tDPhiToPfMet_UnclusteredEnDown, &b_tDPhiToPfMet_UnclusteredEnDown);
   _tree->SetBranchAddress("tDPhiToPfMet_UnclusteredEnUp", &tDPhiToPfMet_UnclusteredEnUp, &b_tDPhiToPfMet_UnclusteredEnUp);
   _tree->SetBranchAddress("tDPhiToPfMet_type1", &tDPhiToPfMet_type1, &b_tDPhiToPfMet_type1);
   _tree->SetBranchAddress("tDecayMode", &tDecayMode, &b_tDecayMode);
   _tree->SetBranchAddress("tDecayModeFinding", &tDecayModeFinding, &b_tDecayModeFinding);
   _tree->SetBranchAddress("tDecayModeFindingNewDMs", &tDecayModeFindingNewDMs, &b_tDecayModeFindingNewDMs);
   _tree->SetBranchAddress("tElecOverlap", &tElecOverlap, &b_tElecOverlap);
   _tree->SetBranchAddress("tEta", &tEta, &b_tEta);
   _tree->SetBranchAddress("tEta_TauEnDown", &tEta_TauEnDown, &b_tEta_TauEnDown);
   _tree->SetBranchAddress("tEta_TauEnUp", &tEta_TauEnUp, &b_tEta_TauEnUp);
   _tree->SetBranchAddress("tFootprintCorrection", &tFootprintCorrection, &b_tFootprintCorrection);
   _tree->SetBranchAddress("tFootprintCorrectiondR03", &tFootprintCorrectiondR03, &b_tFootprintCorrectiondR03);
   _tree->SetBranchAddress("tGenCharge", &tGenCharge, &b_tGenCharge);
   _tree->SetBranchAddress("tGenDecayMode", &tGenDecayMode, &b_tGenDecayMode);
   _tree->SetBranchAddress("tGenEnergy", &tGenEnergy, &b_tGenEnergy);
   _tree->SetBranchAddress("tGenEta", &tGenEta, &b_tGenEta);
   _tree->SetBranchAddress("tGenIsPrompt", &tGenIsPrompt, &b_tGenIsPrompt);
   _tree->SetBranchAddress("tGenJetEta", &tGenJetEta, &b_tGenJetEta);
   _tree->SetBranchAddress("tGenJetPt", &tGenJetPt, &b_tGenJetPt);
   _tree->SetBranchAddress("tGenMotherEnergy", &tGenMotherEnergy, &b_tGenMotherEnergy);
   _tree->SetBranchAddress("tGenMotherEta", &tGenMotherEta, &b_tGenMotherEta);
   _tree->SetBranchAddress("tGenMotherPdgId", &tGenMotherPdgId, &b_tGenMotherPdgId);
   _tree->SetBranchAddress("tGenMotherPhi", &tGenMotherPhi, &b_tGenMotherPhi);
   _tree->SetBranchAddress("tGenMotherPt", &tGenMotherPt, &b_tGenMotherPt);
   _tree->SetBranchAddress("tGenPdgId", &tGenPdgId, &b_tGenPdgId);
   _tree->SetBranchAddress("tGenPhi", &tGenPhi, &b_tGenPhi);
   _tree->SetBranchAddress("tGenPt", &tGenPt, &b_tGenPt);
   _tree->SetBranchAddress("tGenStatus", &tGenStatus, &b_tGenStatus);
   _tree->SetBranchAddress("tGlobalMuonVtxOverlap", &tGlobalMuonVtxOverlap, &b_tGlobalMuonVtxOverlap);
   _tree->SetBranchAddress("tJetArea", &tJetArea, &b_tJetArea);
   _tree->SetBranchAddress("tJetBtag", &tJetBtag, &b_tJetBtag);
   _tree->SetBranchAddress("tJetEtaEtaMoment", &tJetEtaEtaMoment, &b_tJetEtaEtaMoment);
   _tree->SetBranchAddress("tJetEtaPhiMoment", &tJetEtaPhiMoment, &b_tJetEtaPhiMoment);
   _tree->SetBranchAddress("tJetEtaPhiSpread", &tJetEtaPhiSpread, &b_tJetEtaPhiSpread);
   _tree->SetBranchAddress("tJetHadronFlavour", &tJetHadronFlavour, &b_tJetHadronFlavour);
   _tree->SetBranchAddress("tJetPFCISVBtag", &tJetPFCISVBtag, &b_tJetPFCISVBtag);
   _tree->SetBranchAddress("tJetPartonFlavour", &tJetPartonFlavour, &b_tJetPartonFlavour);
   _tree->SetBranchAddress("tJetPhiPhiMoment", &tJetPhiPhiMoment, &b_tJetPhiPhiMoment);
   _tree->SetBranchAddress("tJetPt", &tJetPt, &b_tJetPt);
   _tree->SetBranchAddress("tLeadTrackPt", &tLeadTrackPt, &b_tLeadTrackPt);
   _tree->SetBranchAddress("tLowestMll", &tLowestMll, &b_tLowestMll);
   _tree->SetBranchAddress("tMass", &tMass, &b_tMass);
   _tree->SetBranchAddress("tMass_TauEnDown", &tMass_TauEnDown, &b_tMass_TauEnDown);
   _tree->SetBranchAddress("tMass_TauEnUp", &tMass_TauEnUp, &b_tMass_TauEnUp);
   _tree->SetBranchAddress("tMatchesDoubleTau32Filter", &tMatchesDoubleTau32Filter, &b_tMatchesDoubleTau32Filter);
   _tree->SetBranchAddress("tMatchesDoubleTau32Path", &tMatchesDoubleTau32Path, &b_tMatchesDoubleTau32Path);
   _tree->SetBranchAddress("tMatchesDoubleTau35Filter", &tMatchesDoubleTau35Filter, &b_tMatchesDoubleTau35Filter);
   _tree->SetBranchAddress("tMatchesDoubleTau35Path", &tMatchesDoubleTau35Path, &b_tMatchesDoubleTau35Path);
   _tree->SetBranchAddress("tMatchesDoubleTau40Filter", &tMatchesDoubleTau40Filter, &b_tMatchesDoubleTau40Filter);
   _tree->SetBranchAddress("tMatchesDoubleTau40Path", &tMatchesDoubleTau40Path, &b_tMatchesDoubleTau40Path);
   _tree->SetBranchAddress("tMatchesDoubleTauCmbIso35RegFilter", &tMatchesDoubleTauCmbIso35RegFilter, &b_tMatchesDoubleTauCmbIso35RegFilter);
   _tree->SetBranchAddress("tMatchesDoubleTauCmbIso35RegPath", &tMatchesDoubleTauCmbIso35RegPath, &b_tMatchesDoubleTauCmbIso35RegPath);
   _tree->SetBranchAddress("tMatchesDoubleTauCmbIso40Filter", &tMatchesDoubleTauCmbIso40Filter, &b_tMatchesDoubleTauCmbIso40Filter);
   _tree->SetBranchAddress("tMatchesDoubleTauCmbIso40Path", &tMatchesDoubleTauCmbIso40Path, &b_tMatchesDoubleTauCmbIso40Path);
   _tree->SetBranchAddress("tMatchesDoubleTauCmbIso40RegFilter", &tMatchesDoubleTauCmbIso40RegFilter, &b_tMatchesDoubleTauCmbIso40RegFilter);
   _tree->SetBranchAddress("tMatchesDoubleTauCmbIso40RegPath", &tMatchesDoubleTauCmbIso40RegPath, &b_tMatchesDoubleTauCmbIso40RegPath);
   _tree->SetBranchAddress("tMatchesEle24Tau20Filter", &tMatchesEle24Tau20Filter, &b_tMatchesEle24Tau20Filter);
   _tree->SetBranchAddress("tMatchesEle24Tau20L1Path", &tMatchesEle24Tau20L1Path, &b_tMatchesEle24Tau20L1Path);
   _tree->SetBranchAddress("tMatchesEle24Tau20Path", &tMatchesEle24Tau20Path, &b_tMatchesEle24Tau20Path);
   _tree->SetBranchAddress("tMatchesEle24Tau20sL1Filter", &tMatchesEle24Tau20sL1Filter, &b_tMatchesEle24Tau20sL1Filter);
   _tree->SetBranchAddress("tMatchesEle24Tau30Filter", &tMatchesEle24Tau30Filter, &b_tMatchesEle24Tau30Filter);
   _tree->SetBranchAddress("tMatchesEle24Tau30Path", &tMatchesEle24Tau30Path, &b_tMatchesEle24Tau30Path);
   _tree->SetBranchAddress("tMatchesMu19Tau20Filter", &tMatchesMu19Tau20Filter, &b_tMatchesMu19Tau20Filter);
   _tree->SetBranchAddress("tMatchesMu19Tau20Path", &tMatchesMu19Tau20Path, &b_tMatchesMu19Tau20Path);
   _tree->SetBranchAddress("tMatchesMu19Tau20sL1Filter", &tMatchesMu19Tau20sL1Filter, &b_tMatchesMu19Tau20sL1Filter);
   _tree->SetBranchAddress("tMatchesMu19Tau20sL1Path", &tMatchesMu19Tau20sL1Path, &b_tMatchesMu19Tau20sL1Path);
   _tree->SetBranchAddress("tMatchesMu21Tau20sL1Filter", &tMatchesMu21Tau20sL1Filter, &b_tMatchesMu21Tau20sL1Filter);
   _tree->SetBranchAddress("tMatchesMu21Tau20sL1Path", &tMatchesMu21Tau20sL1Path, &b_tMatchesMu21Tau20sL1Path);
   _tree->SetBranchAddress("tMtToPfMet_ElectronEnDown", &tMtToPfMet_ElectronEnDown, &b_tMtToPfMet_ElectronEnDown);
   _tree->SetBranchAddress("tMtToPfMet_ElectronEnUp", &tMtToPfMet_ElectronEnUp, &b_tMtToPfMet_ElectronEnUp);
   _tree->SetBranchAddress("tMtToPfMet_JetEnDown", &tMtToPfMet_JetEnDown, &b_tMtToPfMet_JetEnDown);
   _tree->SetBranchAddress("tMtToPfMet_JetEnUp", &tMtToPfMet_JetEnUp, &b_tMtToPfMet_JetEnUp);
   _tree->SetBranchAddress("tMtToPfMet_JetResDown", &tMtToPfMet_JetResDown, &b_tMtToPfMet_JetResDown);
   _tree->SetBranchAddress("tMtToPfMet_JetResUp", &tMtToPfMet_JetResUp, &b_tMtToPfMet_JetResUp);
   _tree->SetBranchAddress("tMtToPfMet_MuonEnDown", &tMtToPfMet_MuonEnDown, &b_tMtToPfMet_MuonEnDown);
   _tree->SetBranchAddress("tMtToPfMet_MuonEnUp", &tMtToPfMet_MuonEnUp, &b_tMtToPfMet_MuonEnUp);
   _tree->SetBranchAddress("tMtToPfMet_PhotonEnDown", &tMtToPfMet_PhotonEnDown, &b_tMtToPfMet_PhotonEnDown);
   _tree->SetBranchAddress("tMtToPfMet_PhotonEnUp", &tMtToPfMet_PhotonEnUp, &b_tMtToPfMet_PhotonEnUp);
   _tree->SetBranchAddress("tMtToPfMet_Raw", &tMtToPfMet_Raw, &b_tMtToPfMet_Raw);
   _tree->SetBranchAddress("tMtToPfMet_TauEnDown", &tMtToPfMet_TauEnDown, &b_tMtToPfMet_TauEnDown);
   _tree->SetBranchAddress("tMtToPfMet_TauEnUp", &tMtToPfMet_TauEnUp, &b_tMtToPfMet_TauEnUp);
   _tree->SetBranchAddress("tMtToPfMet_UnclusteredEnDown", &tMtToPfMet_UnclusteredEnDown, &b_tMtToPfMet_UnclusteredEnDown);
   _tree->SetBranchAddress("tMtToPfMet_UnclusteredEnUp", &tMtToPfMet_UnclusteredEnUp, &b_tMtToPfMet_UnclusteredEnUp);
   _tree->SetBranchAddress("tMtToPfMet_type1", &tMtToPfMet_type1, &b_tMtToPfMet_type1);
   _tree->SetBranchAddress("tMuOverlap", &tMuOverlap, &b_tMuOverlap);
   _tree->SetBranchAddress("tMuonIdIsoStdVtxOverlap", &tMuonIdIsoStdVtxOverlap, &b_tMuonIdIsoStdVtxOverlap);
   _tree->SetBranchAddress("tMuonIdIsoVtxOverlap", &tMuonIdIsoVtxOverlap, &b_tMuonIdIsoVtxOverlap);
   _tree->SetBranchAddress("tMuonIdVtxOverlap", &tMuonIdVtxOverlap, &b_tMuonIdVtxOverlap);
   _tree->SetBranchAddress("tNChrgHadrIsolationCands", &tNChrgHadrIsolationCands, &b_tNChrgHadrIsolationCands);
   _tree->SetBranchAddress("tNChrgHadrSignalCands", &tNChrgHadrSignalCands, &b_tNChrgHadrSignalCands);
   _tree->SetBranchAddress("tNGammaSignalCands", &tNGammaSignalCands, &b_tNGammaSignalCands);
   _tree->SetBranchAddress("tNNeutralHadrSignalCands", &tNNeutralHadrSignalCands, &b_tNNeutralHadrSignalCands);
   _tree->SetBranchAddress("tNSignalCands", &tNSignalCands, &b_tNSignalCands);
   _tree->SetBranchAddress("tNearestZMass", &tNearestZMass, &b_tNearestZMass);
   _tree->SetBranchAddress("tNeutralIsoPtSum", &tNeutralIsoPtSum, &b_tNeutralIsoPtSum);
   _tree->SetBranchAddress("tNeutralIsoPtSumWeight", &tNeutralIsoPtSumWeight, &b_tNeutralIsoPtSumWeight);
   _tree->SetBranchAddress("tNeutralIsoPtSumWeightdR03", &tNeutralIsoPtSumWeightdR03, &b_tNeutralIsoPtSumWeightdR03);
   _tree->SetBranchAddress("tNeutralIsoPtSumdR03", &tNeutralIsoPtSumdR03, &b_tNeutralIsoPtSumdR03);
   _tree->SetBranchAddress("tPVDXY", &tPVDXY, &b_tPVDXY);
   _tree->SetBranchAddress("tPVDZ", &tPVDZ, &b_tPVDZ);
   _tree->SetBranchAddress("tPhi", &tPhi, &b_tPhi);
   _tree->SetBranchAddress("tPhi_TauEnDown", &tPhi_TauEnDown, &b_tPhi_TauEnDown);
   _tree->SetBranchAddress("tPhi_TauEnUp", &tPhi_TauEnUp, &b_tPhi_TauEnUp);
   _tree->SetBranchAddress("tPhotonPtSumOutsideSignalCone", &tPhotonPtSumOutsideSignalCone, &b_tPhotonPtSumOutsideSignalCone);
   _tree->SetBranchAddress("tPhotonPtSumOutsideSignalConedR03", &tPhotonPtSumOutsideSignalConedR03, &b_tPhotonPtSumOutsideSignalConedR03);
   _tree->SetBranchAddress("tPt", &tPt, &b_tPt);
   _tree->SetBranchAddress("tPt_TauEnDown", &tPt_TauEnDown, &b_tPt_TauEnDown);
   _tree->SetBranchAddress("tPt_TauEnUp", &tPt_TauEnUp, &b_tPt_TauEnUp);
   _tree->SetBranchAddress("tPuCorrPtSum", &tPuCorrPtSum, &b_tPuCorrPtSum);
   _tree->SetBranchAddress("tRank", &tRank, &b_tRank);
   _tree->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTLoose", &tRerunMVArun2v1DBoldDMwLTLoose, &b_tRerunMVArun2v1DBoldDMwLTLoose);
   _tree->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTMedium", &tRerunMVArun2v1DBoldDMwLTMedium, &b_tRerunMVArun2v1DBoldDMwLTMedium);
   _tree->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTTight", &tRerunMVArun2v1DBoldDMwLTTight, &b_tRerunMVArun2v1DBoldDMwLTTight);
   _tree->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTVLoose", &tRerunMVArun2v1DBoldDMwLTVLoose, &b_tRerunMVArun2v1DBoldDMwLTVLoose);
   _tree->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTVTight", &tRerunMVArun2v1DBoldDMwLTVTight, &b_tRerunMVArun2v1DBoldDMwLTVTight);
   _tree->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTVVTight", &tRerunMVArun2v1DBoldDMwLTVVTight, &b_tRerunMVArun2v1DBoldDMwLTVVTight);
   _tree->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTraw", &tRerunMVArun2v1DBoldDMwLTraw, &b_tRerunMVArun2v1DBoldDMwLTraw);
   _tree->SetBranchAddress("tVZ", &tVZ, &b_tVZ);
   _tree->SetBranchAddress("tZTTGenDR", &tZTTGenDR, &b_tZTTGenDR);
   _tree->SetBranchAddress("tZTTGenEta", &tZTTGenEta, &b_tZTTGenEta);
   _tree->SetBranchAddress("tZTTGenMatching", &tZTTGenMatching, &b_tZTTGenMatching);
   _tree->SetBranchAddress("tZTTGenPhi", &tZTTGenPhi, &b_tZTTGenPhi);
   _tree->SetBranchAddress("tZTTGenPt", &tZTTGenPt, &b_tZTTGenPt);
   _tree->SetBranchAddress("t_m_collinearmass", &t_m_collinearmass, &b_t_m_collinearmass);
   _tree->SetBranchAddress("t_m_collinearmass_JetEnDown", &t_m_collinearmass_JetEnDown, &b_t_m_collinearmass_JetEnDown);
   _tree->SetBranchAddress("t_m_collinearmass_JetEnUp", &t_m_collinearmass_JetEnUp, &b_t_m_collinearmass_JetEnUp);
   _tree->SetBranchAddress("t_m_collinearmass_UnclusteredEnDown", &t_m_collinearmass_UnclusteredEnDown, &b_t_m_collinearmass_UnclusteredEnDown);
   _tree->SetBranchAddress("t_m_collinearmass_UnclusteredEnUp", &t_m_collinearmass_UnclusteredEnUp, &b_t_m_collinearmass_UnclusteredEnUp);
   _tree->SetBranchAddress("tauVetoPt20Loose3HitsVtx", &tauVetoPt20Loose3HitsVtx, &b_tauVetoPt20Loose3HitsVtx);
   _tree->SetBranchAddress("tauVetoPt20TightMVALTVtx", &tauVetoPt20TightMVALTVtx, &b_tauVetoPt20TightMVALTVtx);
   _tree->SetBranchAddress("topQuarkPt1", &topQuarkPt1, &b_topQuarkPt1);
   _tree->SetBranchAddress("topQuarkPt2", &topQuarkPt2, &b_topQuarkPt2);
   _tree->SetBranchAddress("tripleEGroup", &tripleEGroup, &b_tripleEGroup);
   _tree->SetBranchAddress("tripleEPass", &tripleEPass, &b_tripleEPass);
   _tree->SetBranchAddress("tripleEPrescale", &tripleEPrescale, &b_tripleEPrescale);
   _tree->SetBranchAddress("tripleMuGroup", &tripleMuGroup, &b_tripleMuGroup);
   _tree->SetBranchAddress("tripleMuPass", &tripleMuPass, &b_tripleMuPass);
   _tree->SetBranchAddress("tripleMuPrescale", &tripleMuPrescale, &b_tripleMuPrescale);
   _tree->SetBranchAddress("type1_pfMetEt", &type1_pfMetEt, &b_type1_pfMetEt);
   _tree->SetBranchAddress("type1_pfMetPhi", &type1_pfMetPhi, &b_type1_pfMetPhi);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_ElectronEnDown", &type1_pfMet_shiftedPhi_ElectronEnDown, &b_type1_pfMet_shiftedPhi_ElectronEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_ElectronEnUp", &type1_pfMet_shiftedPhi_ElectronEnUp, &b_type1_pfMet_shiftedPhi_ElectronEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_JetEnDown", &type1_pfMet_shiftedPhi_JetEnDown, &b_type1_pfMet_shiftedPhi_JetEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_JetEnUp", &type1_pfMet_shiftedPhi_JetEnUp, &b_type1_pfMet_shiftedPhi_JetEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_JetResDown", &type1_pfMet_shiftedPhi_JetResDown, &b_type1_pfMet_shiftedPhi_JetResDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_JetResUp", &type1_pfMet_shiftedPhi_JetResUp, &b_type1_pfMet_shiftedPhi_JetResUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_MuonEnDown", &type1_pfMet_shiftedPhi_MuonEnDown, &b_type1_pfMet_shiftedPhi_MuonEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_MuonEnUp", &type1_pfMet_shiftedPhi_MuonEnUp, &b_type1_pfMet_shiftedPhi_MuonEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_PhotonEnDown", &type1_pfMet_shiftedPhi_PhotonEnDown, &b_type1_pfMet_shiftedPhi_PhotonEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_PhotonEnUp", &type1_pfMet_shiftedPhi_PhotonEnUp, &b_type1_pfMet_shiftedPhi_PhotonEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_TauEnDown", &type1_pfMet_shiftedPhi_TauEnDown, &b_type1_pfMet_shiftedPhi_TauEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_TauEnUp", &type1_pfMet_shiftedPhi_TauEnUp, &b_type1_pfMet_shiftedPhi_TauEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_UnclusteredEnDown", &type1_pfMet_shiftedPhi_UnclusteredEnDown, &b_type1_pfMet_shiftedPhi_UnclusteredEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPhi_UnclusteredEnUp", &type1_pfMet_shiftedPhi_UnclusteredEnUp, &b_type1_pfMet_shiftedPhi_UnclusteredEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_ElectronEnDown", &type1_pfMet_shiftedPt_ElectronEnDown, &b_type1_pfMet_shiftedPt_ElectronEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_ElectronEnUp", &type1_pfMet_shiftedPt_ElectronEnUp, &b_type1_pfMet_shiftedPt_ElectronEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_JetEnDown", &type1_pfMet_shiftedPt_JetEnDown, &b_type1_pfMet_shiftedPt_JetEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_JetEnUp", &type1_pfMet_shiftedPt_JetEnUp, &b_type1_pfMet_shiftedPt_JetEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_JetResDown", &type1_pfMet_shiftedPt_JetResDown, &b_type1_pfMet_shiftedPt_JetResDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_JetResUp", &type1_pfMet_shiftedPt_JetResUp, &b_type1_pfMet_shiftedPt_JetResUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_MuonEnDown", &type1_pfMet_shiftedPt_MuonEnDown, &b_type1_pfMet_shiftedPt_MuonEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_MuonEnUp", &type1_pfMet_shiftedPt_MuonEnUp, &b_type1_pfMet_shiftedPt_MuonEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_PhotonEnDown", &type1_pfMet_shiftedPt_PhotonEnDown, &b_type1_pfMet_shiftedPt_PhotonEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_PhotonEnUp", &type1_pfMet_shiftedPt_PhotonEnUp, &b_type1_pfMet_shiftedPt_PhotonEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_TauEnDown", &type1_pfMet_shiftedPt_TauEnDown, &b_type1_pfMet_shiftedPt_TauEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_TauEnUp", &type1_pfMet_shiftedPt_TauEnUp, &b_type1_pfMet_shiftedPt_TauEnUp);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_UnclusteredEnDown", &type1_pfMet_shiftedPt_UnclusteredEnDown, &b_type1_pfMet_shiftedPt_UnclusteredEnDown);
   _tree->SetBranchAddress("type1_pfMet_shiftedPt_UnclusteredEnUp", &type1_pfMet_shiftedPt_UnclusteredEnUp, &b_type1_pfMet_shiftedPt_UnclusteredEnUp);
   _tree->SetBranchAddress("vbfDeta", &vbfDeta, &b_vbfDeta);
   _tree->SetBranchAddress("vbfDeta_JetEnDown", &vbfDeta_JetEnDown, &b_vbfDeta_JetEnDown);
   _tree->SetBranchAddress("vbfDeta_JetEnUp", &vbfDeta_JetEnUp, &b_vbfDeta_JetEnUp);
   _tree->SetBranchAddress("vbfDijetrap", &vbfDijetrap, &b_vbfDijetrap);
   _tree->SetBranchAddress("vbfDijetrap_JetEnDown", &vbfDijetrap_JetEnDown, &b_vbfDijetrap_JetEnDown);
   _tree->SetBranchAddress("vbfDijetrap_JetEnUp", &vbfDijetrap_JetEnUp, &b_vbfDijetrap_JetEnUp);
   _tree->SetBranchAddress("vbfDphi", &vbfDphi, &b_vbfDphi);
   _tree->SetBranchAddress("vbfDphi_JetEnDown", &vbfDphi_JetEnDown, &b_vbfDphi_JetEnDown);
   _tree->SetBranchAddress("vbfDphi_JetEnUp", &vbfDphi_JetEnUp, &b_vbfDphi_JetEnUp);
   _tree->SetBranchAddress("vbfDphihj", &vbfDphihj, &b_vbfDphihj);
   _tree->SetBranchAddress("vbfDphihj_JetEnDown", &vbfDphihj_JetEnDown, &b_vbfDphihj_JetEnDown);
   _tree->SetBranchAddress("vbfDphihj_JetEnUp", &vbfDphihj_JetEnUp, &b_vbfDphihj_JetEnUp);
   _tree->SetBranchAddress("vbfDphihjnomet", &vbfDphihjnomet, &b_vbfDphihjnomet);
   _tree->SetBranchAddress("vbfDphihjnomet_JetEnDown", &vbfDphihjnomet_JetEnDown, &b_vbfDphihjnomet_JetEnDown);
   _tree->SetBranchAddress("vbfDphihjnomet_JetEnUp", &vbfDphihjnomet_JetEnUp, &b_vbfDphihjnomet_JetEnUp);
   _tree->SetBranchAddress("vbfHrap", &vbfHrap, &b_vbfHrap);
   _tree->SetBranchAddress("vbfHrap_JetEnDown", &vbfHrap_JetEnDown, &b_vbfHrap_JetEnDown);
   _tree->SetBranchAddress("vbfHrap_JetEnUp", &vbfHrap_JetEnUp, &b_vbfHrap_JetEnUp);
   _tree->SetBranchAddress("vbfJetVeto20", &vbfJetVeto20, &b_vbfJetVeto20);
   _tree->SetBranchAddress("vbfJetVeto20_JetEnDown", &vbfJetVeto20_JetEnDown, &b_vbfJetVeto20_JetEnDown);
   _tree->SetBranchAddress("vbfJetVeto20_JetEnUp", &vbfJetVeto20_JetEnUp, &b_vbfJetVeto20_JetEnUp);
   _tree->SetBranchAddress("vbfJetVeto30", &vbfJetVeto30, &b_vbfJetVeto30);
   _tree->SetBranchAddress("vbfJetVeto30_JetEnDown", &vbfJetVeto30_JetEnDown, &b_vbfJetVeto30_JetEnDown);
   _tree->SetBranchAddress("vbfJetVeto30_JetEnUp", &vbfJetVeto30_JetEnUp, &b_vbfJetVeto30_JetEnUp);
   _tree->SetBranchAddress("vbfMVA", &vbfMVA, &b_vbfMVA);
   _tree->SetBranchAddress("vbfMVA_JetEnDown", &vbfMVA_JetEnDown, &b_vbfMVA_JetEnDown);
   _tree->SetBranchAddress("vbfMVA_JetEnUp", &vbfMVA_JetEnUp, &b_vbfMVA_JetEnUp);
   _tree->SetBranchAddress("vbfMass", &vbfMass, &b_vbfMass);
   _tree->SetBranchAddress("vbfMass_JetAbsoluteFlavMapDown", &vbfMass_JetAbsoluteFlavMapDown, &b_vbfMass_JetAbsoluteFlavMapDown);
   _tree->SetBranchAddress("vbfMass_JetAbsoluteFlavMapUp", &vbfMass_JetAbsoluteFlavMapUp, &b_vbfMass_JetAbsoluteFlavMapUp);
   _tree->SetBranchAddress("vbfMass_JetAbsoluteMPFBiasDown", &vbfMass_JetAbsoluteMPFBiasDown, &b_vbfMass_JetAbsoluteMPFBiasDown);
   _tree->SetBranchAddress("vbfMass_JetAbsoluteMPFBiasUp", &vbfMass_JetAbsoluteMPFBiasUp, &b_vbfMass_JetAbsoluteMPFBiasUp);
   _tree->SetBranchAddress("vbfMass_JetAbsoluteScaleDown", &vbfMass_JetAbsoluteScaleDown, &b_vbfMass_JetAbsoluteScaleDown);
   _tree->SetBranchAddress("vbfMass_JetAbsoluteScaleUp", &vbfMass_JetAbsoluteScaleUp, &b_vbfMass_JetAbsoluteScaleUp);
   _tree->SetBranchAddress("vbfMass_JetAbsoluteStatDown", &vbfMass_JetAbsoluteStatDown, &b_vbfMass_JetAbsoluteStatDown);
   _tree->SetBranchAddress("vbfMass_JetAbsoluteStatUp", &vbfMass_JetAbsoluteStatUp, &b_vbfMass_JetAbsoluteStatUp);
   _tree->SetBranchAddress("vbfMass_JetClosureDown", &vbfMass_JetClosureDown, &b_vbfMass_JetClosureDown);
   _tree->SetBranchAddress("vbfMass_JetClosureUp", &vbfMass_JetClosureUp, &b_vbfMass_JetClosureUp);
   _tree->SetBranchAddress("vbfMass_JetEnDown", &vbfMass_JetEnDown, &b_vbfMass_JetEnDown);
   _tree->SetBranchAddress("vbfMass_JetEnUp", &vbfMass_JetEnUp, &b_vbfMass_JetEnUp);
   _tree->SetBranchAddress("vbfMass_JetFlavorQCDDown", &vbfMass_JetFlavorQCDDown, &b_vbfMass_JetFlavorQCDDown);
   _tree->SetBranchAddress("vbfMass_JetFlavorQCDUp", &vbfMass_JetFlavorQCDUp, &b_vbfMass_JetFlavorQCDUp);
   _tree->SetBranchAddress("vbfMass_JetFragmentationDown", &vbfMass_JetFragmentationDown, &b_vbfMass_JetFragmentationDown);
   _tree->SetBranchAddress("vbfMass_JetFragmentationUp", &vbfMass_JetFragmentationUp, &b_vbfMass_JetFragmentationUp);
   _tree->SetBranchAddress("vbfMass_JetPileUpDataMCDown", &vbfMass_JetPileUpDataMCDown, &b_vbfMass_JetPileUpDataMCDown);
   _tree->SetBranchAddress("vbfMass_JetPileUpDataMCUp", &vbfMass_JetPileUpDataMCUp, &b_vbfMass_JetPileUpDataMCUp);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtBBDown", &vbfMass_JetPileUpPtBBDown, &b_vbfMass_JetPileUpPtBBDown);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtBBUp", &vbfMass_JetPileUpPtBBUp, &b_vbfMass_JetPileUpPtBBUp);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtEC1Down", &vbfMass_JetPileUpPtEC1Down, &b_vbfMass_JetPileUpPtEC1Down);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtEC1Up", &vbfMass_JetPileUpPtEC1Up, &b_vbfMass_JetPileUpPtEC1Up);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtEC2Down", &vbfMass_JetPileUpPtEC2Down, &b_vbfMass_JetPileUpPtEC2Down);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtEC2Up", &vbfMass_JetPileUpPtEC2Up, &b_vbfMass_JetPileUpPtEC2Up);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtHFDown", &vbfMass_JetPileUpPtHFDown, &b_vbfMass_JetPileUpPtHFDown);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtHFUp", &vbfMass_JetPileUpPtHFUp, &b_vbfMass_JetPileUpPtHFUp);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtRefDown", &vbfMass_JetPileUpPtRefDown, &b_vbfMass_JetPileUpPtRefDown);
   _tree->SetBranchAddress("vbfMass_JetPileUpPtRefUp", &vbfMass_JetPileUpPtRefUp, &b_vbfMass_JetPileUpPtRefUp);
   _tree->SetBranchAddress("vbfMass_JetRelativeBalDown", &vbfMass_JetRelativeBalDown, &b_vbfMass_JetRelativeBalDown);
   _tree->SetBranchAddress("vbfMass_JetRelativeBalUp", &vbfMass_JetRelativeBalUp, &b_vbfMass_JetRelativeBalUp);
   _tree->SetBranchAddress("vbfMass_JetRelativeFSRDown", &vbfMass_JetRelativeFSRDown, &b_vbfMass_JetRelativeFSRDown);
   _tree->SetBranchAddress("vbfMass_JetRelativeFSRUp", &vbfMass_JetRelativeFSRUp, &b_vbfMass_JetRelativeFSRUp);
   _tree->SetBranchAddress("vbfMass_JetRelativeJEREC1Down", &vbfMass_JetRelativeJEREC1Down, &b_vbfMass_JetRelativeJEREC1Down);
   _tree->SetBranchAddress("vbfMass_JetRelativeJEREC1Up", &vbfMass_JetRelativeJEREC1Up, &b_vbfMass_JetRelativeJEREC1Up);
   _tree->SetBranchAddress("vbfMass_JetRelativeJEREC2Down", &vbfMass_JetRelativeJEREC2Down, &b_vbfMass_JetRelativeJEREC2Down);
   _tree->SetBranchAddress("vbfMass_JetRelativeJEREC2Up", &vbfMass_JetRelativeJEREC2Up, &b_vbfMass_JetRelativeJEREC2Up);
   _tree->SetBranchAddress("vbfMass_JetRelativeJERHFDown", &vbfMass_JetRelativeJERHFDown, &b_vbfMass_JetRelativeJERHFDown);
   _tree->SetBranchAddress("vbfMass_JetRelativeJERHFUp", &vbfMass_JetRelativeJERHFUp, &b_vbfMass_JetRelativeJERHFUp);
   _tree->SetBranchAddress("vbfMass_JetRelativePtBBDown", &vbfMass_JetRelativePtBBDown, &b_vbfMass_JetRelativePtBBDown);
   _tree->SetBranchAddress("vbfMass_JetRelativePtBBUp", &vbfMass_JetRelativePtBBUp, &b_vbfMass_JetRelativePtBBUp);
   _tree->SetBranchAddress("vbfMass_JetRelativePtEC1Down", &vbfMass_JetRelativePtEC1Down, &b_vbfMass_JetRelativePtEC1Down);
   _tree->SetBranchAddress("vbfMass_JetRelativePtEC1Up", &vbfMass_JetRelativePtEC1Up, &b_vbfMass_JetRelativePtEC1Up);
   _tree->SetBranchAddress("vbfMass_JetRelativePtEC2Down", &vbfMass_JetRelativePtEC2Down, &b_vbfMass_JetRelativePtEC2Down);
   _tree->SetBranchAddress("vbfMass_JetRelativePtEC2Up", &vbfMass_JetRelativePtEC2Up, &b_vbfMass_JetRelativePtEC2Up);
   _tree->SetBranchAddress("vbfMass_JetRelativePtHFDown", &vbfMass_JetRelativePtHFDown, &b_vbfMass_JetRelativePtHFDown);
   _tree->SetBranchAddress("vbfMass_JetRelativePtHFUp", &vbfMass_JetRelativePtHFUp, &b_vbfMass_JetRelativePtHFUp);
   _tree->SetBranchAddress("vbfMass_JetRelativeStatECDown", &vbfMass_JetRelativeStatECDown, &b_vbfMass_JetRelativeStatECDown);
   _tree->SetBranchAddress("vbfMass_JetRelativeStatECUp", &vbfMass_JetRelativeStatECUp, &b_vbfMass_JetRelativeStatECUp);
   _tree->SetBranchAddress("vbfMass_JetRelativeStatFSRDown", &vbfMass_JetRelativeStatFSRDown, &b_vbfMass_JetRelativeStatFSRDown);
   _tree->SetBranchAddress("vbfMass_JetRelativeStatFSRUp", &vbfMass_JetRelativeStatFSRUp, &b_vbfMass_JetRelativeStatFSRUp);
   _tree->SetBranchAddress("vbfMass_JetRelativeStatHFDown", &vbfMass_JetRelativeStatHFDown, &b_vbfMass_JetRelativeStatHFDown);
   _tree->SetBranchAddress("vbfMass_JetRelativeStatHFUp", &vbfMass_JetRelativeStatHFUp, &b_vbfMass_JetRelativeStatHFUp);
   _tree->SetBranchAddress("vbfMass_JetSinglePionECALDown", &vbfMass_JetSinglePionECALDown, &b_vbfMass_JetSinglePionECALDown);
   _tree->SetBranchAddress("vbfMass_JetSinglePionECALUp", &vbfMass_JetSinglePionECALUp, &b_vbfMass_JetSinglePionECALUp);
   _tree->SetBranchAddress("vbfMass_JetSinglePionHCALDown", &vbfMass_JetSinglePionHCALDown, &b_vbfMass_JetSinglePionHCALDown);
   _tree->SetBranchAddress("vbfMass_JetSinglePionHCALUp", &vbfMass_JetSinglePionHCALUp, &b_vbfMass_JetSinglePionHCALUp);
   _tree->SetBranchAddress("vbfMass_JetSubTotalAbsoluteDown", &vbfMass_JetSubTotalAbsoluteDown, &b_vbfMass_JetSubTotalAbsoluteDown);
   _tree->SetBranchAddress("vbfMass_JetSubTotalAbsoluteUp", &vbfMass_JetSubTotalAbsoluteUp, &b_vbfMass_JetSubTotalAbsoluteUp);
   _tree->SetBranchAddress("vbfMass_JetSubTotalMCDown", &vbfMass_JetSubTotalMCDown, &b_vbfMass_JetSubTotalMCDown);
   _tree->SetBranchAddress("vbfMass_JetSubTotalMCUp", &vbfMass_JetSubTotalMCUp, &b_vbfMass_JetSubTotalMCUp);
   _tree->SetBranchAddress("vbfMass_JetSubTotalPileUpDown", &vbfMass_JetSubTotalPileUpDown, &b_vbfMass_JetSubTotalPileUpDown);
   _tree->SetBranchAddress("vbfMass_JetSubTotalPileUpUp", &vbfMass_JetSubTotalPileUpUp, &b_vbfMass_JetSubTotalPileUpUp);
   _tree->SetBranchAddress("vbfMass_JetSubTotalPtDown", &vbfMass_JetSubTotalPtDown, &b_vbfMass_JetSubTotalPtDown);
   _tree->SetBranchAddress("vbfMass_JetSubTotalPtUp", &vbfMass_JetSubTotalPtUp, &b_vbfMass_JetSubTotalPtUp);
   _tree->SetBranchAddress("vbfMass_JetSubTotalRelativeDown", &vbfMass_JetSubTotalRelativeDown, &b_vbfMass_JetSubTotalRelativeDown);
   _tree->SetBranchAddress("vbfMass_JetSubTotalRelativeUp", &vbfMass_JetSubTotalRelativeUp, &b_vbfMass_JetSubTotalRelativeUp);
   _tree->SetBranchAddress("vbfMass_JetSubTotalScaleDown", &vbfMass_JetSubTotalScaleDown, &b_vbfMass_JetSubTotalScaleDown);
   _tree->SetBranchAddress("vbfMass_JetSubTotalScaleUp", &vbfMass_JetSubTotalScaleUp, &b_vbfMass_JetSubTotalScaleUp);
   _tree->SetBranchAddress("vbfMass_JetTimePtEtaDown", &vbfMass_JetTimePtEtaDown, &b_vbfMass_JetTimePtEtaDown);
   _tree->SetBranchAddress("vbfMass_JetTimePtEtaUp", &vbfMass_JetTimePtEtaUp, &b_vbfMass_JetTimePtEtaUp);
   _tree->SetBranchAddress("vbfMass_JetTotalDown", &vbfMass_JetTotalDown, &b_vbfMass_JetTotalDown);
   _tree->SetBranchAddress("vbfMass_JetTotalUp", &vbfMass_JetTotalUp, &b_vbfMass_JetTotalUp);
   _tree->SetBranchAddress("vbfNJets20", &vbfNJets20, &b_vbfNJets20);
   _tree->SetBranchAddress("vbfNJets20_JetEnDown", &vbfNJets20_JetEnDown, &b_vbfNJets20_JetEnDown);
   _tree->SetBranchAddress("vbfNJets20_JetEnUp", &vbfNJets20_JetEnUp, &b_vbfNJets20_JetEnUp);
   _tree->SetBranchAddress("vbfNJets30", &vbfNJets30, &b_vbfNJets30);
   _tree->SetBranchAddress("vbfNJets30_JetEnDown", &vbfNJets30_JetEnDown, &b_vbfNJets30_JetEnDown);
   _tree->SetBranchAddress("vbfNJets30_JetEnUp", &vbfNJets30_JetEnUp, &b_vbfNJets30_JetEnUp);
   _tree->SetBranchAddress("vbfVispt", &vbfVispt, &b_vbfVispt);
   _tree->SetBranchAddress("vbfVispt_JetEnDown", &vbfVispt_JetEnDown, &b_vbfVispt_JetEnDown);
   _tree->SetBranchAddress("vbfVispt_JetEnUp", &vbfVispt_JetEnUp, &b_vbfVispt_JetEnUp);
   _tree->SetBranchAddress("vbfdijetpt", &vbfdijetpt, &b_vbfdijetpt);
   _tree->SetBranchAddress("vbfdijetpt_JetEnDown", &vbfdijetpt_JetEnDown, &b_vbfdijetpt_JetEnDown);
   _tree->SetBranchAddress("vbfdijetpt_JetEnUp", &vbfdijetpt_JetEnUp, &b_vbfdijetpt_JetEnUp);
   _tree->SetBranchAddress("vbfj1eta", &vbfj1eta, &b_vbfj1eta);
   _tree->SetBranchAddress("vbfj1eta_JetEnDown", &vbfj1eta_JetEnDown, &b_vbfj1eta_JetEnDown);
   _tree->SetBranchAddress("vbfj1eta_JetEnUp", &vbfj1eta_JetEnUp, &b_vbfj1eta_JetEnUp);
   _tree->SetBranchAddress("vbfj1pt", &vbfj1pt, &b_vbfj1pt);
   _tree->SetBranchAddress("vbfj1pt_JetEnDown", &vbfj1pt_JetEnDown, &b_vbfj1pt_JetEnDown);
   _tree->SetBranchAddress("vbfj1pt_JetEnUp", &vbfj1pt_JetEnUp, &b_vbfj1pt_JetEnUp);
   _tree->SetBranchAddress("vbfj2eta", &vbfj2eta, &b_vbfj2eta);
   _tree->SetBranchAddress("vbfj2eta_JetEnDown", &vbfj2eta_JetEnDown, &b_vbfj2eta_JetEnDown);
   _tree->SetBranchAddress("vbfj2eta_JetEnUp", &vbfj2eta_JetEnUp, &b_vbfj2eta_JetEnUp);
   _tree->SetBranchAddress("vbfj2pt", &vbfj2pt, &b_vbfj2pt);
   _tree->SetBranchAddress("vbfj2pt_JetEnDown", &vbfj2pt_JetEnDown, &b_vbfj2pt_JetEnDown);
   _tree->SetBranchAddress("vbfj2pt_JetEnUp", &vbfj2pt_JetEnUp, &b_vbfj2pt_JetEnUp);
   _tree->SetBranchAddress("vispX", &vispX, &b_vispX);
   _tree->SetBranchAddress("vispY", &vispY, &b_vispY);
   _tree->SetBranchAddress("idx", &idx, &b_idx);
}

Int_t HTauTauTree_mt::GetEntry(int entry)
{
    return _tree->GetEntry(entry);
} 

Long64_t HTauTauTree_mt::GetEntries()
{
    return _tree->GetEntries();
}

TTree* HTauTauTree_mt::GetTree()
{
    return _tree;
}

#endif
