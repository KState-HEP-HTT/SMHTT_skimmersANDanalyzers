#ifndef HTauTauTree_et_h
#define HTauTauTree_et_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>

using namespace std;

// Header file for the classes stored in the TTree if any.

class HTauTauTree_et {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         DoubleMediumTau35Group;
   Float_t         DoubleMediumTau35Pass;
   Float_t         DoubleMediumTau35Prescale;
   Float_t         DoubleMediumTau40Group;
   Float_t         DoubleMediumTau40Pass;
   Float_t         DoubleMediumTau40Prescale;
   Float_t         DoubleTightTau35Group;
   Float_t         DoubleTightTau35Pass;
   Float_t         DoubleTightTau35Prescale;
   Float_t         DoubleTightTau40Group;
   Float_t         DoubleTightTau40Pass;
   Float_t         DoubleTightTau40Prescale;
   Float_t         Ele24Tau30Group;
   Float_t         Ele24Tau30Pass;
   Float_t         Ele24Tau30Prescale;
   Float_t         Ele32WPTightGroup;
   Float_t         Ele32WPTightPass;
   Float_t         Ele32WPTightPrescale;
   Float_t         Ele35WPTightGroup;
   Float_t         Ele35WPTightPass;
   Float_t         Ele35WPTightPrescale;
   Float_t         EmbPtWeight;
   Float_t         Eta;
   Float_t         GenWeight;
   Float_t         Ht;
   Float_t         IsoMu20Group;
   Float_t         IsoMu20Pass;
   Float_t         IsoMu20Prescale;
   Float_t         IsoMu24Group;
   Float_t         IsoMu24Pass;
   Float_t         IsoMu24Prescale;
   Float_t         IsoMu24_eta2p1Group;
   Float_t         IsoMu24_eta2p1Pass;
   Float_t         IsoMu24_eta2p1Prescale;
   Float_t         IsoMu27Group;
   Float_t         IsoMu27Pass;
   Float_t         IsoMu27Prescale;
   Float_t         LT;
   Float_t         Mass;
   Float_t         MassError;
   Float_t         MassErrord1;
   Float_t         MassErrord2;
   Float_t         MassErrord3;
   Float_t         MassErrord4;
   Float_t         Mt;
   Float_t         Mu20Tau27Group;
   Float_t         Mu20Tau27Pass;
   Float_t         Mu20Tau27Prescale;
   Float_t         Mu50Group;
   Float_t         Mu50Pass;
   Float_t         Mu50Prescale;
   Float_t         NUP;
   Float_t         Phi;
   Float_t         Pt;
   Float_t         bjetCISVVeto20Loose;
   Float_t         bjetCISVVeto20Medium;
   Float_t         bjetCISVVeto20Tight;
   Float_t         bjetCISVVeto30Loose;
   Float_t         bjetCISVVeto30Medium;
   Float_t         bjetCISVVeto30Tight;
   Float_t         bjetDeepCSVVeto20Loose;
   Float_t         bjetDeepCSVVeto20Medium;
   Float_t         bjetDeepCSVVeto20Tight;
   Float_t         bjetDeepCSVVeto30Loose;
   Float_t         bjetDeepCSVVeto30Medium;
   Float_t         bjetDeepCSVVeto30Tight;
   Float_t         charge;
   Float_t         dielectronVeto;
   Float_t         dimuonVeto;
   Float_t         doubleE_23_12Group;
   Float_t         doubleE_23_12Pass;
   Float_t         doubleE_23_12Prescale;
   Float_t         doubleE_23_12_DZGroup;
   Float_t         doubleE_23_12_DZPass;
   Float_t         doubleE_23_12_DZPrescale;
   Float_t         doubleMuDZGroup;
   Float_t         doubleMuDZPass;
   Float_t         doubleMuDZPrescale;
   Float_t         doubleMuDZminMass3p8Group;
   Float_t         doubleMuDZminMass3p8Pass;
   Float_t         doubleMuDZminMass3p8Prescale;
   Float_t         doubleMuDZminMass8Group;
   Float_t         doubleMuDZminMass8Pass;
   Float_t         doubleMuDZminMass8Prescale;
   Float_t         eCBIDLoose;
   Float_t         eCBIDMedium;
   Float_t         eCBIDTight;
   Float_t         eCBIDVeto;
   Float_t         eCharge;
   Float_t         eChargeIdLoose;
   Float_t         eChargeIdMed;
   Float_t         eChargeIdTight;
   Float_t         eComesFromHiggs;
   Float_t         eE1x5;
   Float_t         eE2x5Max;
   Float_t         eE5x5;
   Float_t         eEcalIsoDR03;
   Float_t         eEnergyError;
   Float_t         eEta;
   Float_t         eGenCharge;
   Float_t         eGenDirectPromptTauDecay;
   Float_t         eGenEnergy;
   Float_t         eGenEta;
   Float_t         eGenIsPrompt;
   Float_t         eGenMotherPdgId;
   Float_t         eGenParticle;
   Float_t         eGenPdgId;
   Float_t         eGenPhi;
   Float_t         eGenPrompt;
   Float_t         eGenPromptTauDecay;
   Float_t         eGenPt;
   Float_t         eGenTauDecay;
   Float_t         eGenVZ;
   Float_t         eGenVtxPVMatch;
   Float_t         eHadronicDepth1OverEm;
   Float_t         eHadronicDepth2OverEm;
   Float_t         eHadronicOverEM;
   Float_t         eHcalIsoDR03;
   Float_t         eIP3D;
   Float_t         eIP3DErr;
   Float_t         eIsoDB03;
   Float_t         eJetArea;
   Float_t         eJetBtag;
   Float_t         eJetDR;
   Float_t         eJetEtaEtaMoment;
   Float_t         eJetEtaPhiMoment;
   Float_t         eJetEtaPhiSpread;
   Float_t         eJetHadronFlavour;
   Float_t         eJetPFCISVBtag;
   Float_t         eJetPartonFlavour;
   Float_t         eJetPhiPhiMoment;
   Float_t         eJetPt;
   Float_t         eLowestMll;
   Float_t         eMVAIsoLoose;
   Float_t         eMVAIsoWP80;
   Float_t         eMVAIsoWP90;
   Float_t         eMVANoisoLoose;
   Float_t         eMVANoisoWP80;
   Float_t         eMVANoisoWP90;
   Float_t         eMass;
   Float_t         eMatchesEle24Tau30Filter;
   Float_t         eMatchesEle24Tau30Path;
   Float_t         eMatchesEle32Filter;
   Float_t         eMatchesEle32Path;
   Float_t         eMatchesEle35Filter;
   Float_t         eMatchesEle35Path;
   Float_t         eMissingHits;
   Float_t         eNearMuonVeto;
   Float_t         eNearestMuonDR;
   Float_t         eNearestZMass;
   Float_t         ePFChargedIso;
   Float_t         ePFNeutralIso;
   Float_t         ePFPUChargedIso;
   Float_t         ePFPhotonIso;
   Float_t         ePVDXY;
   Float_t         ePVDZ;
   Float_t         ePassesConversionVeto;
   Float_t         ePhi;
   Float_t         ePt;
   Float_t         eRelIso;
   Float_t         eRelPFIsoDB;
   Float_t         eRelPFIsoRho;
   Float_t         eRho;
   Float_t         eSCEnergy;
   Float_t         eSCEta;
   Float_t         eSCEtaWidth;
   Float_t         eSCPhi;
   Float_t         eSCPhiWidth;
   Float_t         eSCPreshowerEnergy;
   Float_t         eSCRawEnergy;
   Float_t         eSIP2D;
   Float_t         eSIP3D;
   Float_t         eSigmaIEtaIEta;
   Float_t         eTrkIsoDR03;
   Float_t         eVZ;
   Float_t         eVetoMVAIso;
   Float_t         eVetoZTTp001dxyz;
   Float_t         eVetoZTTp001dxyzR0;
   Float_t         eZTTGenMatching;
   Float_t         e_t_doubleL1IsoTauMatch;
   Float_t         edeltaEtaSuperClusterTrackAtVtx;
   Float_t         edeltaPhiSuperClusterTrackAtVtx;
   Float_t         eeSuperClusterOverP;
   Float_t         eecalEnergy;
   Float_t         efBrem;
   Float_t         etrackMomentumAtVtxP;
   ULong64_t       evt;
   Float_t         genEta;
   Float_t         genHTT;
   Float_t         genM;
   Float_t         genMass;
   Float_t         genPhi;
   Float_t         genpT;
   Float_t         genpX;
   Float_t         genpY;
   Int_t           isdata;
   Float_t         j1csv;
   Float_t         j1eta;
   Float_t         j1hadronflavor;
   Float_t         j1phi;
   Float_t         j1pt;
   Float_t         j2csv;
   Float_t         j2eta;
   Float_t         j2hadronflavor;
   Float_t         j2phi;
   Float_t         j2pt;
   Float_t         jb1csv;
   Float_t         jb1eta;
   Float_t         jb1hadronflavor;
   Float_t         jb1phi;
   Float_t         jb1pt;
   Float_t         jb2csv;
   Float_t         jb2eta;
   Float_t         jb2hadronflavor;
   Float_t         jb2phi;
   Float_t         jb2pt;
   Float_t         jetVeto20;
   Float_t         jetVeto20_JetEnDown;
   Float_t         jetVeto20_JetEnUp;
   Float_t         jetVeto30;
   Float_t         jetVeto30_JetEnDown;
   Float_t         jetVeto30_JetEnUp;
   Int_t           lumi;
   Float_t         metSig;
   Float_t         metcov00;
   Float_t         metcov00_DESYlike;
   Float_t         metcov01;
   Float_t         metcov01_DESYlike;
   Float_t         metcov10;
   Float_t         metcov10_DESYlike;
   Float_t         metcov11;
   Float_t         metcov11_DESYlike;
   Float_t         mu12e23DZGroup;
   Float_t         mu12e23DZPass;
   Float_t         mu12e23DZPrescale;
   Float_t         mu12e23Group;
   Float_t         mu12e23Pass;
   Float_t         mu12e23Prescale;
   Float_t         mu23e12DZGroup;
   Float_t         mu23e12DZPass;
   Float_t         mu23e12DZPrescale;
   Float_t         mu23e12Group;
   Float_t         mu23e12Pass;
   Float_t         mu23e12Prescale;
   Float_t         muGlbIsoVetoPt10;
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
   Float_t         recoilDaught;
   Float_t         recoilWithMet;
   Float_t         rho;
   Int_t           run;
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
   Float_t         tByLooseCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByMediumCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByMediumIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByMediumIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByMediumIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByPhotonPtSumOutsideSignalCone;
   Float_t         tByTightCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         tByTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         tByVVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         tCharge;
   Float_t         tChargedIsoPtSum;
   Float_t         tChargedIsoPtSumdR03;
   Float_t         tComesFromHiggs;
   Float_t         tDecayMode;
   Float_t         tDecayModeFinding;
   Float_t         tDecayModeFindingNewDMs;
   Float_t         tEta;
   Float_t         tFootprintCorrection;
   Float_t         tFootprintCorrectiondR03;
   Float_t         tGenCharge;
   Float_t         tGenDecayMode;
   Float_t         tGenEnergy;
   Float_t         tGenEta;
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
   Float_t         tJetArea;
   Float_t         tJetBtag;
   Float_t         tJetDR;
   Float_t         tJetEtaEtaMoment;
   Float_t         tJetEtaPhiMoment;
   Float_t         tJetEtaPhiSpread;
   Float_t         tJetHadronFlavour;
   Float_t         tJetPFCISVBtag;
   Float_t         tJetPartonFlavour;
   Float_t         tJetPhiPhiMoment;
   Float_t         tJetPt;
   Float_t         tL1IsoTauMatch;
   Float_t         tL1IsoTauPt;
   Float_t         tLeadTrackPt;
   Float_t         tLowestMll;
   Float_t         tMass;
   Float_t         tMatchesDoubleMediumTau35Filter;
   Float_t         tMatchesDoubleMediumTau35Path;
   Float_t         tMatchesDoubleMediumTau40Filter;
   Float_t         tMatchesDoubleMediumTau40Path;
   Float_t         tMatchesDoubleTightTau35Filter;
   Float_t         tMatchesDoubleTightTau35Path;
   Float_t         tMatchesDoubleTightTau40Filter;
   Float_t         tMatchesDoubleTightTau40Path;
   Float_t         tMatchesEle24Tau30Filter;
   Float_t         tMatchesEle24Tau30Path;
   Float_t         tMatchesIsoMu20Tau27Filter;
   Float_t         tMatchesIsoMu20Tau27Path;
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
   Float_t         tPhotonPtSumOutsideSignalCone;
   Float_t         tPhotonPtSumOutsideSignalConedR03;
   Float_t         tPt;
   Float_t         tPuCorrPtSum;
   Float_t         tRerunMVArun2v1DBoldDMwLTLoose;
   Float_t         tRerunMVArun2v1DBoldDMwLTMedium;
   Float_t         tRerunMVArun2v1DBoldDMwLTTight;
   Float_t         tRerunMVArun2v1DBoldDMwLTVLoose;
   Float_t         tRerunMVArun2v1DBoldDMwLTVTight;
   Float_t         tRerunMVArun2v1DBoldDMwLTVVTight;
   Float_t         tRerunMVArun2v1DBoldDMwLTraw;
   Float_t         tRerunMVArun2v2DBoldDMwLTLoose;
   Float_t         tRerunMVArun2v2DBoldDMwLTMedium;
   Float_t         tRerunMVArun2v2DBoldDMwLTTight;
   Float_t         tRerunMVArun2v2DBoldDMwLTVLoose;
   Float_t         tRerunMVArun2v2DBoldDMwLTVTight;
   Float_t         tRerunMVArun2v2DBoldDMwLTVVLoose;
   Float_t         tRerunMVArun2v2DBoldDMwLTVVTight;
   Float_t         tRerunMVArun2v2DBoldDMwLTraw;
   Float_t         tVZ;
   Float_t         tZTTGenDR;
   Float_t         tZTTGenEta;
   Float_t         tZTTGenMatching;
   Float_t         tZTTGenPhi;
   Float_t         tZTTGenPt;
   Float_t         tauVetoPt20Loose3HitsVtx;
   Float_t         tauVetoPt20TightMVALTVtx;
   Float_t         topQuarkPt1;
   Float_t         topQuarkPt2;
   Float_t         tripleEGroup;
   Float_t         tripleEPass;
   Float_t         tripleEPrescale;
   Float_t         tripleMu12_10_5Group;
   Float_t         tripleMu12_10_5Pass;
   Float_t         tripleMu12_10_5Prescale;
   Float_t         type1_pfMetEt;
   Float_t         type1_pfMetPhi;
   Float_t         vbfDeta;
   Float_t         vbfJetVeto20;
   Float_t         vbfJetVeto30;
   Float_t         vbfMass;
   Float_t         vbfNJets20;
   Float_t         vbfNJets30;
   Float_t         vbfj1eta;
   Float_t         vbfj1pt;
   Float_t         vbfj2eta;
   Float_t         vbfj2pt;
   Float_t         vispX;
   Float_t         vispY;
   Int_t           idx;

   // List of branches
   TBranch        *b_DoubleMediumTau35Group;   //!
   TBranch        *b_DoubleMediumTau35Pass;   //!
   TBranch        *b_DoubleMediumTau35Prescale;   //!
   TBranch        *b_DoubleMediumTau40Group;   //!
   TBranch        *b_DoubleMediumTau40Pass;   //!
   TBranch        *b_DoubleMediumTau40Prescale;   //!
   TBranch        *b_DoubleTightTau35Group;   //!
   TBranch        *b_DoubleTightTau35Pass;   //!
   TBranch        *b_DoubleTightTau35Prescale;   //!
   TBranch        *b_DoubleTightTau40Group;   //!
   TBranch        *b_DoubleTightTau40Pass;   //!
   TBranch        *b_DoubleTightTau40Prescale;   //!
   TBranch        *b_Ele24Tau30Group;   //!
   TBranch        *b_Ele24Tau30Pass;   //!
   TBranch        *b_Ele24Tau30Prescale;   //!
   TBranch        *b_Ele32WPTightGroup;   //!
   TBranch        *b_Ele32WPTightPass;   //!
   TBranch        *b_Ele32WPTightPrescale;   //!
   TBranch        *b_Ele35WPTightGroup;   //!
   TBranch        *b_Ele35WPTightPass;   //!
   TBranch        *b_Ele35WPTightPrescale;   //!
   TBranch        *b_EmbPtWeight;   //!
   TBranch        *b_Eta;   //!
   TBranch        *b_GenWeight;   //!
   TBranch        *b_Ht;   //!
   TBranch        *b_IsoMu20Group;   //!
   TBranch        *b_IsoMu20Pass;   //!
   TBranch        *b_IsoMu20Prescale;   //!
   TBranch        *b_IsoMu24Group;   //!
   TBranch        *b_IsoMu24Pass;   //!
   TBranch        *b_IsoMu24Prescale;   //!
   TBranch        *b_IsoMu24_eta2p1Group;   //!
   TBranch        *b_IsoMu24_eta2p1Pass;   //!
   TBranch        *b_IsoMu24_eta2p1Prescale;   //!
   TBranch        *b_IsoMu27Group;   //!
   TBranch        *b_IsoMu27Pass;   //!
   TBranch        *b_IsoMu27Prescale;   //!
   TBranch        *b_LT;   //!
   TBranch        *b_Mass;   //!
   TBranch        *b_MassError;   //!
   TBranch        *b_MassErrord1;   //!
   TBranch        *b_MassErrord2;   //!
   TBranch        *b_MassErrord3;   //!
   TBranch        *b_MassErrord4;   //!
   TBranch        *b_Mt;   //!
   TBranch        *b_Mu20Tau27Group;   //!
   TBranch        *b_Mu20Tau27Pass;   //!
   TBranch        *b_Mu20Tau27Prescale;   //!
   TBranch        *b_Mu50Group;   //!
   TBranch        *b_Mu50Pass;   //!
   TBranch        *b_Mu50Prescale;   //!
   TBranch        *b_NUP;   //!
   TBranch        *b_Phi;   //!
   TBranch        *b_Pt;   //!
   TBranch        *b_bjetCISVVeto20Loose;   //!
   TBranch        *b_bjetCISVVeto20Medium;   //!
   TBranch        *b_bjetCISVVeto20Tight;   //!
   TBranch        *b_bjetCISVVeto30Loose;   //!
   TBranch        *b_bjetCISVVeto30Medium;   //!
   TBranch        *b_bjetCISVVeto30Tight;   //!
   TBranch        *b_bjetDeepCSVVeto20Loose;   //!
   TBranch        *b_bjetDeepCSVVeto20Medium;   //!
   TBranch        *b_bjetDeepCSVVeto20Tight;   //!
   TBranch        *b_bjetDeepCSVVeto30Loose;   //!
   TBranch        *b_bjetDeepCSVVeto30Medium;   //!
   TBranch        *b_bjetDeepCSVVeto30Tight;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_dielectronVeto;   //!
   TBranch        *b_dimuonVeto;   //!
   TBranch        *b_doubleE_23_12Group;   //!
   TBranch        *b_doubleE_23_12Pass;   //!
   TBranch        *b_doubleE_23_12Prescale;   //!
   TBranch        *b_doubleE_23_12_DZGroup;   //!
   TBranch        *b_doubleE_23_12_DZPass;   //!
   TBranch        *b_doubleE_23_12_DZPrescale;   //!
   TBranch        *b_doubleMuDZGroup;   //!
   TBranch        *b_doubleMuDZPass;   //!
   TBranch        *b_doubleMuDZPrescale;   //!
   TBranch        *b_doubleMuDZminMass3p8Group;   //!
   TBranch        *b_doubleMuDZminMass3p8Pass;   //!
   TBranch        *b_doubleMuDZminMass3p8Prescale;   //!
   TBranch        *b_doubleMuDZminMass8Group;   //!
   TBranch        *b_doubleMuDZminMass8Pass;   //!
   TBranch        *b_doubleMuDZminMass8Prescale;   //!
   TBranch        *b_eCBIDLoose;   //!
   TBranch        *b_eCBIDMedium;   //!
   TBranch        *b_eCBIDTight;   //!
   TBranch        *b_eCBIDVeto;   //!
   TBranch        *b_eCharge;   //!
   TBranch        *b_eChargeIdLoose;   //!
   TBranch        *b_eChargeIdMed;   //!
   TBranch        *b_eChargeIdTight;   //!
   TBranch        *b_eComesFromHiggs;   //!
   TBranch        *b_eE1x5;   //!
   TBranch        *b_eE2x5Max;   //!
   TBranch        *b_eE5x5;   //!
   TBranch        *b_eEcalIsoDR03;   //!
   TBranch        *b_eEnergyError;   //!
   TBranch        *b_eEta;   //!
   TBranch        *b_eGenCharge;   //!
   TBranch        *b_eGenDirectPromptTauDecay;   //!
   TBranch        *b_eGenEnergy;   //!
   TBranch        *b_eGenEta;   //!
   TBranch        *b_eGenIsPrompt;   //!
   TBranch        *b_eGenMotherPdgId;   //!
   TBranch        *b_eGenParticle;   //!
   TBranch        *b_eGenPdgId;   //!
   TBranch        *b_eGenPhi;   //!
   TBranch        *b_eGenPrompt;   //!
   TBranch        *b_eGenPromptTauDecay;   //!
   TBranch        *b_eGenPt;   //!
   TBranch        *b_eGenTauDecay;   //!
   TBranch        *b_eGenVZ;   //!
   TBranch        *b_eGenVtxPVMatch;   //!
   TBranch        *b_eHadronicDepth1OverEm;   //!
   TBranch        *b_eHadronicDepth2OverEm;   //!
   TBranch        *b_eHadronicOverEM;   //!
   TBranch        *b_eHcalIsoDR03;   //!
   TBranch        *b_eIP3D;   //!
   TBranch        *b_eIP3DErr;   //!
   TBranch        *b_eIsoDB03;   //!
   TBranch        *b_eJetArea;   //!
   TBranch        *b_eJetBtag;   //!
   TBranch        *b_eJetDR;   //!
   TBranch        *b_eJetEtaEtaMoment;   //!
   TBranch        *b_eJetEtaPhiMoment;   //!
   TBranch        *b_eJetEtaPhiSpread;   //!
   TBranch        *b_eJetHadronFlavour;   //!
   TBranch        *b_eJetPFCISVBtag;   //!
   TBranch        *b_eJetPartonFlavour;   //!
   TBranch        *b_eJetPhiPhiMoment;   //!
   TBranch        *b_eJetPt;   //!
   TBranch        *b_eLowestMll;   //!
   TBranch        *b_eMVAIsoLoose;   //!
   TBranch        *b_eMVAIsoWP80;   //!
   TBranch        *b_eMVAIsoWP90;   //!
   TBranch        *b_eMVANoisoLoose;   //!
   TBranch        *b_eMVANoisoWP80;   //!
   TBranch        *b_eMVANoisoWP90;   //!
   TBranch        *b_eMass;   //!
   TBranch        *b_eMatchesEle24Tau30Filter;   //!
   TBranch        *b_eMatchesEle24Tau30Path;   //!
   TBranch        *b_eMatchesEle32Filter;   //!
   TBranch        *b_eMatchesEle32Path;   //!
   TBranch        *b_eMatchesEle35Filter;   //!
   TBranch        *b_eMatchesEle35Path;   //!
   TBranch        *b_eMissingHits;   //!
   TBranch        *b_eNearMuonVeto;   //!
   TBranch        *b_eNearestMuonDR;   //!
   TBranch        *b_eNearestZMass;   //!
   TBranch        *b_ePFChargedIso;   //!
   TBranch        *b_ePFNeutralIso;   //!
   TBranch        *b_ePFPUChargedIso;   //!
   TBranch        *b_ePFPhotonIso;   //!
   TBranch        *b_ePVDXY;   //!
   TBranch        *b_ePVDZ;   //!
   TBranch        *b_ePassesConversionVeto;   //!
   TBranch        *b_ePhi;   //!
   TBranch        *b_ePt;   //!
   TBranch        *b_eRelIso;   //!
   TBranch        *b_eRelPFIsoDB;   //!
   TBranch        *b_eRelPFIsoRho;   //!
   TBranch        *b_eRho;   //!
   TBranch        *b_eSCEnergy;   //!
   TBranch        *b_eSCEta;   //!
   TBranch        *b_eSCEtaWidth;   //!
   TBranch        *b_eSCPhi;   //!
   TBranch        *b_eSCPhiWidth;   //!
   TBranch        *b_eSCPreshowerEnergy;   //!
   TBranch        *b_eSCRawEnergy;   //!
   TBranch        *b_eSIP2D;   //!
   TBranch        *b_eSIP3D;   //!
   TBranch        *b_eSigmaIEtaIEta;   //!
   TBranch        *b_eTrkIsoDR03;   //!
   TBranch        *b_eVZ;   //!
   TBranch        *b_eVetoMVAIso;   //!
   TBranch        *b_eVetoZTTp001dxyz;   //!
   TBranch        *b_eVetoZTTp001dxyzR0;   //!
   TBranch        *b_eZTTGenMatching;   //!
   TBranch        *b_e_t_doubleL1IsoTauMatch;   //!
   TBranch        *b_edeltaEtaSuperClusterTrackAtVtx;   //!
   TBranch        *b_edeltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b_eeSuperClusterOverP;   //!
   TBranch        *b_eecalEnergy;   //!
   TBranch        *b_efBrem;   //!
   TBranch        *b_etrackMomentumAtVtxP;   //!
   TBranch        *b_evt;   //!
   TBranch        *b_genEta;   //!
   TBranch        *b_genHTT;   //!
   TBranch        *b_genM;   //!
   TBranch        *b_genMass;   //!
   TBranch        *b_genPhi;   //!
   TBranch        *b_genpT;   //!
   TBranch        *b_genpX;   //!
   TBranch        *b_genpY;   //!
   TBranch        *b_isdata;   //!
   TBranch        *b_j1csv;   //!
   TBranch        *b_j1eta;   //!
   TBranch        *b_j1hadronflavor;   //!
   TBranch        *b_j1phi;   //!
   TBranch        *b_j1pt;   //!
   TBranch        *b_j2csv;   //!
   TBranch        *b_j2eta;   //!
   TBranch        *b_j2hadronflavor;   //!
   TBranch        *b_j2phi;   //!
   TBranch        *b_j2pt;   //!
   TBranch        *b_jb1csv;   //!
   TBranch        *b_jb1eta;   //!
   TBranch        *b_jb1hadronflavor;   //!
   TBranch        *b_jb1phi;   //!
   TBranch        *b_jb1pt;   //!
   TBranch        *b_jb2csv;   //!
   TBranch        *b_jb2eta;   //!
   TBranch        *b_jb2hadronflavor;   //!
   TBranch        *b_jb2phi;   //!
   TBranch        *b_jb2pt;   //!
   TBranch        *b_jetVeto20;   //!
   TBranch        *b_jetVeto20_JetEnDown;   //!
   TBranch        *b_jetVeto20_JetEnUp;   //!
   TBranch        *b_jetVeto30;   //!
   TBranch        *b_jetVeto30_JetEnDown;   //!
   TBranch        *b_jetVeto30_JetEnUp;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_metSig;   //!
   TBranch        *b_metcov00;   //!
   TBranch        *b_metcov00_DESYlike;   //!
   TBranch        *b_metcov01;   //!
   TBranch        *b_metcov01_DESYlike;   //!
   TBranch        *b_metcov10;   //!
   TBranch        *b_metcov10_DESYlike;   //!
   TBranch        *b_metcov11;   //!
   TBranch        *b_metcov11_DESYlike;   //!
   TBranch        *b_mu12e23DZGroup;   //!
   TBranch        *b_mu12e23DZPass;   //!
   TBranch        *b_mu12e23DZPrescale;   //!
   TBranch        *b_mu12e23Group;   //!
   TBranch        *b_mu12e23Pass;   //!
   TBranch        *b_mu12e23Prescale;   //!
   TBranch        *b_mu23e12DZGroup;   //!
   TBranch        *b_mu23e12DZPass;   //!
   TBranch        *b_mu23e12DZPrescale;   //!
   TBranch        *b_mu23e12Group;   //!
   TBranch        *b_mu23e12Pass;   //!
   TBranch        *b_mu23e12Prescale;   //!
   TBranch        *b_muGlbIsoVetoPt10;   //!
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
   TBranch        *b_recoilDaught;   //!
   TBranch        *b_recoilWithMet;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_run;   //!
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
   TBranch        *b_tByLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByMediumIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_tByTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tByVVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tCharge;   //!
   TBranch        *b_tChargedIsoPtSum;   //!
   TBranch        *b_tChargedIsoPtSumdR03;   //!
   TBranch        *b_tComesFromHiggs;   //!
   TBranch        *b_tDecayMode;   //!
   TBranch        *b_tDecayModeFinding;   //!
   TBranch        *b_tDecayModeFindingNewDMs;   //!
   TBranch        *b_tEta;   //!
   TBranch        *b_tFootprintCorrection;   //!
   TBranch        *b_tFootprintCorrectiondR03;   //!
   TBranch        *b_tGenCharge;   //!
   TBranch        *b_tGenDecayMode;   //!
   TBranch        *b_tGenEnergy;   //!
   TBranch        *b_tGenEta;   //!
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
   TBranch        *b_tJetArea;   //!
   TBranch        *b_tJetBtag;   //!
   TBranch        *b_tJetDR;   //!
   TBranch        *b_tJetEtaEtaMoment;   //!
   TBranch        *b_tJetEtaPhiMoment;   //!
   TBranch        *b_tJetEtaPhiSpread;   //!
   TBranch        *b_tJetHadronFlavour;   //!
   TBranch        *b_tJetPFCISVBtag;   //!
   TBranch        *b_tJetPartonFlavour;   //!
   TBranch        *b_tJetPhiPhiMoment;   //!
   TBranch        *b_tJetPt;   //!
   TBranch        *b_tL1IsoTauMatch;   //!
   TBranch        *b_tL1IsoTauPt;   //!
   TBranch        *b_tLeadTrackPt;   //!
   TBranch        *b_tLowestMll;   //!
   TBranch        *b_tMass;   //!
   TBranch        *b_tMatchesDoubleMediumTau35Filter;   //!
   TBranch        *b_tMatchesDoubleMediumTau35Path;   //!
   TBranch        *b_tMatchesDoubleMediumTau40Filter;   //!
   TBranch        *b_tMatchesDoubleMediumTau40Path;   //!
   TBranch        *b_tMatchesDoubleTightTau35Filter;   //!
   TBranch        *b_tMatchesDoubleTightTau35Path;   //!
   TBranch        *b_tMatchesDoubleTightTau40Filter;   //!
   TBranch        *b_tMatchesDoubleTightTau40Path;   //!
   TBranch        *b_tMatchesEle24Tau30Filter;   //!
   TBranch        *b_tMatchesEle24Tau30Path;   //!
   TBranch        *b_tMatchesIsoMu20Tau27Filter;   //!
   TBranch        *b_tMatchesIsoMu20Tau27Path;   //!
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
   TBranch        *b_tPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_tPhotonPtSumOutsideSignalConedR03;   //!
   TBranch        *b_tPt;   //!
   TBranch        *b_tPuCorrPtSum;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTLoose;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTMedium;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTTight;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTVLoose;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTVTight;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTVVTight;   //!
   TBranch        *b_tRerunMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTLoose;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTMedium;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTTight;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTVLoose;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTVTight;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTVVLoose;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTVVTight;   //!
   TBranch        *b_tRerunMVArun2v2DBoldDMwLTraw;   //!
   TBranch        *b_tVZ;   //!
   TBranch        *b_tZTTGenDR;   //!
   TBranch        *b_tZTTGenEta;   //!
   TBranch        *b_tZTTGenMatching;   //!
   TBranch        *b_tZTTGenPhi;   //!
   TBranch        *b_tZTTGenPt;   //!
   TBranch        *b_tauVetoPt20Loose3HitsVtx;   //!
   TBranch        *b_tauVetoPt20TightMVALTVtx;   //!
   TBranch        *b_topQuarkPt1;   //!
   TBranch        *b_topQuarkPt2;   //!
   TBranch        *b_tripleEGroup;   //!
   TBranch        *b_tripleEPass;   //!
   TBranch        *b_tripleEPrescale;   //!
   TBranch        *b_tripleMu12_10_5Group;   //!
   TBranch        *b_tripleMu12_10_5Pass;   //!
   TBranch        *b_tripleMu12_10_5Prescale;   //!
   TBranch        *b_type1_pfMetEt;   //!
   TBranch        *b_type1_pfMetPhi;   //!
   TBranch        *b_vbfDeta;   //!
   TBranch        *b_vbfJetVeto20;   //!
   TBranch        *b_vbfJetVeto30;   //!
   TBranch        *b_vbfMass;   //!
   TBranch        *b_vbfNJets20;   //!
   TBranch        *b_vbfNJets30;   //!
   TBranch        *b_vbfj1eta;   //!
   TBranch        *b_vbfj1pt;   //!
   TBranch        *b_vbfj2eta;   //!
   TBranch        *b_vbfj2pt;   //!
   TBranch        *b_vispX;   //!
   TBranch        *b_vispY;   //!
   TBranch        *b_idx;   //!

   HTauTauTree_et(TTree *tree=0);
   virtual ~HTauTauTree_et();
   virtual void     Init(TTree *tree);
   virtual Int_t    GetEntry(Long64_t entry); 
   virtual Long64_t GetEntries(); 
   TTree* GetTree(); 
};


HTauTauTree_et::HTauTauTree_et(TTree *tree) : fChain(0) 
{
   Init(tree);
}

HTauTauTree_et::~HTauTauTree_et() {}

Int_t HTauTauTree_et::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t HTauTauTree_et::GetEntries()  
{
  return fChain->GetEntries();
}
TTree* HTauTauTree_et::GetTree()   
{
  return fChain;
}

void HTauTauTree_et::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("DoubleMediumTau35Group", &DoubleMediumTau35Group, &b_DoubleMediumTau35Group);
   fChain->SetBranchAddress("DoubleMediumTau35Pass", &DoubleMediumTau35Pass, &b_DoubleMediumTau35Pass);
   fChain->SetBranchAddress("DoubleMediumTau35Prescale", &DoubleMediumTau35Prescale, &b_DoubleMediumTau35Prescale);
   fChain->SetBranchAddress("DoubleMediumTau40Group", &DoubleMediumTau40Group, &b_DoubleMediumTau40Group);
   fChain->SetBranchAddress("DoubleMediumTau40Pass", &DoubleMediumTau40Pass, &b_DoubleMediumTau40Pass);
   fChain->SetBranchAddress("DoubleMediumTau40Prescale", &DoubleMediumTau40Prescale, &b_DoubleMediumTau40Prescale);
   fChain->SetBranchAddress("DoubleTightTau35Group", &DoubleTightTau35Group, &b_DoubleTightTau35Group);
   fChain->SetBranchAddress("DoubleTightTau35Pass", &DoubleTightTau35Pass, &b_DoubleTightTau35Pass);
   fChain->SetBranchAddress("DoubleTightTau35Prescale", &DoubleTightTau35Prescale, &b_DoubleTightTau35Prescale);
   fChain->SetBranchAddress("DoubleTightTau40Group", &DoubleTightTau40Group, &b_DoubleTightTau40Group);
   fChain->SetBranchAddress("DoubleTightTau40Pass", &DoubleTightTau40Pass, &b_DoubleTightTau40Pass);
   fChain->SetBranchAddress("DoubleTightTau40Prescale", &DoubleTightTau40Prescale, &b_DoubleTightTau40Prescale);
   fChain->SetBranchAddress("Ele24Tau30Group", &Ele24Tau30Group, &b_Ele24Tau30Group);
   fChain->SetBranchAddress("Ele24Tau30Pass", &Ele24Tau30Pass, &b_Ele24Tau30Pass);
   fChain->SetBranchAddress("Ele24Tau30Prescale", &Ele24Tau30Prescale, &b_Ele24Tau30Prescale);
   fChain->SetBranchAddress("Ele32WPTightGroup", &Ele32WPTightGroup, &b_Ele32WPTightGroup);
   fChain->SetBranchAddress("Ele32WPTightPass", &Ele32WPTightPass, &b_Ele32WPTightPass);
   fChain->SetBranchAddress("Ele32WPTightPrescale", &Ele32WPTightPrescale, &b_Ele32WPTightPrescale);
   fChain->SetBranchAddress("Ele35WPTightGroup", &Ele35WPTightGroup, &b_Ele35WPTightGroup);
   fChain->SetBranchAddress("Ele35WPTightPass", &Ele35WPTightPass, &b_Ele35WPTightPass);
   fChain->SetBranchAddress("Ele35WPTightPrescale", &Ele35WPTightPrescale, &b_Ele35WPTightPrescale);
   fChain->SetBranchAddress("EmbPtWeight", &EmbPtWeight, &b_EmbPtWeight);
   fChain->SetBranchAddress("Eta", &Eta, &b_Eta);
   fChain->SetBranchAddress("GenWeight", &GenWeight, &b_GenWeight);
   fChain->SetBranchAddress("Ht", &Ht, &b_Ht);
   fChain->SetBranchAddress("IsoMu20Group", &IsoMu20Group, &b_IsoMu20Group);
   fChain->SetBranchAddress("IsoMu20Pass", &IsoMu20Pass, &b_IsoMu20Pass);
   fChain->SetBranchAddress("IsoMu20Prescale", &IsoMu20Prescale, &b_IsoMu20Prescale);
   fChain->SetBranchAddress("IsoMu24Group", &IsoMu24Group, &b_IsoMu24Group);
   fChain->SetBranchAddress("IsoMu24Pass", &IsoMu24Pass, &b_IsoMu24Pass);
   fChain->SetBranchAddress("IsoMu24Prescale", &IsoMu24Prescale, &b_IsoMu24Prescale);
   fChain->SetBranchAddress("IsoMu24_eta2p1Group", &IsoMu24_eta2p1Group, &b_IsoMu24_eta2p1Group);
   fChain->SetBranchAddress("IsoMu24_eta2p1Pass", &IsoMu24_eta2p1Pass, &b_IsoMu24_eta2p1Pass);
   fChain->SetBranchAddress("IsoMu24_eta2p1Prescale", &IsoMu24_eta2p1Prescale, &b_IsoMu24_eta2p1Prescale);
   fChain->SetBranchAddress("IsoMu27Group", &IsoMu27Group, &b_IsoMu27Group);
   fChain->SetBranchAddress("IsoMu27Pass", &IsoMu27Pass, &b_IsoMu27Pass);
   fChain->SetBranchAddress("IsoMu27Prescale", &IsoMu27Prescale, &b_IsoMu27Prescale);
   fChain->SetBranchAddress("LT", &LT, &b_LT);
   fChain->SetBranchAddress("Mass", &Mass, &b_Mass);
   fChain->SetBranchAddress("MassError", &MassError, &b_MassError);
   fChain->SetBranchAddress("MassErrord1", &MassErrord1, &b_MassErrord1);
   fChain->SetBranchAddress("MassErrord2", &MassErrord2, &b_MassErrord2);
   fChain->SetBranchAddress("MassErrord3", &MassErrord3, &b_MassErrord3);
   fChain->SetBranchAddress("MassErrord4", &MassErrord4, &b_MassErrord4);
   fChain->SetBranchAddress("Mt", &Mt, &b_Mt);
   fChain->SetBranchAddress("Mu20Tau27Group", &Mu20Tau27Group, &b_Mu20Tau27Group);
   fChain->SetBranchAddress("Mu20Tau27Pass", &Mu20Tau27Pass, &b_Mu20Tau27Pass);
   fChain->SetBranchAddress("Mu20Tau27Prescale", &Mu20Tau27Prescale, &b_Mu20Tau27Prescale);
   fChain->SetBranchAddress("Mu50Group", &Mu50Group, &b_Mu50Group);
   fChain->SetBranchAddress("Mu50Pass", &Mu50Pass, &b_Mu50Pass);
   fChain->SetBranchAddress("Mu50Prescale", &Mu50Prescale, &b_Mu50Prescale);
   fChain->SetBranchAddress("NUP", &NUP, &b_NUP);
   fChain->SetBranchAddress("Phi", &Phi, &b_Phi);
   fChain->SetBranchAddress("Pt", &Pt, &b_Pt);
   fChain->SetBranchAddress("bjetCISVVeto20Loose", &bjetCISVVeto20Loose, &b_bjetCISVVeto20Loose);
   fChain->SetBranchAddress("bjetCISVVeto20Medium", &bjetCISVVeto20Medium, &b_bjetCISVVeto20Medium);
   fChain->SetBranchAddress("bjetCISVVeto20Tight", &bjetCISVVeto20Tight, &b_bjetCISVVeto20Tight);
   fChain->SetBranchAddress("bjetCISVVeto30Loose", &bjetCISVVeto30Loose, &b_bjetCISVVeto30Loose);
   fChain->SetBranchAddress("bjetCISVVeto30Medium", &bjetCISVVeto30Medium, &b_bjetCISVVeto30Medium);
   fChain->SetBranchAddress("bjetCISVVeto30Tight", &bjetCISVVeto30Tight, &b_bjetCISVVeto30Tight);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Loose", &bjetDeepCSVVeto20Loose, &b_bjetDeepCSVVeto20Loose);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Medium", &bjetDeepCSVVeto20Medium, &b_bjetDeepCSVVeto20Medium);
   fChain->SetBranchAddress("bjetDeepCSVVeto20Tight", &bjetDeepCSVVeto20Tight, &b_bjetDeepCSVVeto20Tight);
   fChain->SetBranchAddress("bjetDeepCSVVeto30Loose", &bjetDeepCSVVeto30Loose, &b_bjetDeepCSVVeto30Loose);
   fChain->SetBranchAddress("bjetDeepCSVVeto30Medium", &bjetDeepCSVVeto30Medium, &b_bjetDeepCSVVeto30Medium);
   fChain->SetBranchAddress("bjetDeepCSVVeto30Tight", &bjetDeepCSVVeto30Tight, &b_bjetDeepCSVVeto30Tight);
   fChain->SetBranchAddress("charge", &charge, &b_charge);
   fChain->SetBranchAddress("dielectronVeto", &dielectronVeto, &b_dielectronVeto);
   fChain->SetBranchAddress("dimuonVeto", &dimuonVeto, &b_dimuonVeto);
   fChain->SetBranchAddress("doubleE_23_12Group", &doubleE_23_12Group, &b_doubleE_23_12Group);
   fChain->SetBranchAddress("doubleE_23_12Pass", &doubleE_23_12Pass, &b_doubleE_23_12Pass);
   fChain->SetBranchAddress("doubleE_23_12Prescale", &doubleE_23_12Prescale, &b_doubleE_23_12Prescale);
   fChain->SetBranchAddress("doubleE_23_12_DZGroup", &doubleE_23_12_DZGroup, &b_doubleE_23_12_DZGroup);
   fChain->SetBranchAddress("doubleE_23_12_DZPass", &doubleE_23_12_DZPass, &b_doubleE_23_12_DZPass);
   fChain->SetBranchAddress("doubleE_23_12_DZPrescale", &doubleE_23_12_DZPrescale, &b_doubleE_23_12_DZPrescale);
   fChain->SetBranchAddress("doubleMuDZGroup", &doubleMuDZGroup, &b_doubleMuDZGroup);
   fChain->SetBranchAddress("doubleMuDZPass", &doubleMuDZPass, &b_doubleMuDZPass);
   fChain->SetBranchAddress("doubleMuDZPrescale", &doubleMuDZPrescale, &b_doubleMuDZPrescale);
   fChain->SetBranchAddress("doubleMuDZminMass3p8Group", &doubleMuDZminMass3p8Group, &b_doubleMuDZminMass3p8Group);
   fChain->SetBranchAddress("doubleMuDZminMass3p8Pass", &doubleMuDZminMass3p8Pass, &b_doubleMuDZminMass3p8Pass);
   fChain->SetBranchAddress("doubleMuDZminMass3p8Prescale", &doubleMuDZminMass3p8Prescale, &b_doubleMuDZminMass3p8Prescale);
   fChain->SetBranchAddress("doubleMuDZminMass8Group", &doubleMuDZminMass8Group, &b_doubleMuDZminMass8Group);
   fChain->SetBranchAddress("doubleMuDZminMass8Pass", &doubleMuDZminMass8Pass, &b_doubleMuDZminMass8Pass);
   fChain->SetBranchAddress("doubleMuDZminMass8Prescale", &doubleMuDZminMass8Prescale, &b_doubleMuDZminMass8Prescale);
   fChain->SetBranchAddress("eCBIDLoose", &eCBIDLoose, &b_eCBIDLoose);
   fChain->SetBranchAddress("eCBIDMedium", &eCBIDMedium, &b_eCBIDMedium);
   fChain->SetBranchAddress("eCBIDTight", &eCBIDTight, &b_eCBIDTight);
   fChain->SetBranchAddress("eCBIDVeto", &eCBIDVeto, &b_eCBIDVeto);
   fChain->SetBranchAddress("eCharge", &eCharge, &b_eCharge);
   fChain->SetBranchAddress("eChargeIdLoose", &eChargeIdLoose, &b_eChargeIdLoose);
   fChain->SetBranchAddress("eChargeIdMed", &eChargeIdMed, &b_eChargeIdMed);
   fChain->SetBranchAddress("eChargeIdTight", &eChargeIdTight, &b_eChargeIdTight);
   fChain->SetBranchAddress("eComesFromHiggs", &eComesFromHiggs, &b_eComesFromHiggs);
   fChain->SetBranchAddress("eE1x5", &eE1x5, &b_eE1x5);
   fChain->SetBranchAddress("eE2x5Max", &eE2x5Max, &b_eE2x5Max);
   fChain->SetBranchAddress("eE5x5", &eE5x5, &b_eE5x5);
   fChain->SetBranchAddress("eEcalIsoDR03", &eEcalIsoDR03, &b_eEcalIsoDR03);
   fChain->SetBranchAddress("eEnergyError", &eEnergyError, &b_eEnergyError);
   fChain->SetBranchAddress("eEta", &eEta, &b_eEta);
   fChain->SetBranchAddress("eGenCharge", &eGenCharge, &b_eGenCharge);
   fChain->SetBranchAddress("eGenDirectPromptTauDecay", &eGenDirectPromptTauDecay, &b_eGenDirectPromptTauDecay);
   fChain->SetBranchAddress("eGenEnergy", &eGenEnergy, &b_eGenEnergy);
   fChain->SetBranchAddress("eGenEta", &eGenEta, &b_eGenEta);
   fChain->SetBranchAddress("eGenIsPrompt", &eGenIsPrompt, &b_eGenIsPrompt);
   fChain->SetBranchAddress("eGenMotherPdgId", &eGenMotherPdgId, &b_eGenMotherPdgId);
   fChain->SetBranchAddress("eGenParticle", &eGenParticle, &b_eGenParticle);
   fChain->SetBranchAddress("eGenPdgId", &eGenPdgId, &b_eGenPdgId);
   fChain->SetBranchAddress("eGenPhi", &eGenPhi, &b_eGenPhi);
   fChain->SetBranchAddress("eGenPrompt", &eGenPrompt, &b_eGenPrompt);
   fChain->SetBranchAddress("eGenPromptTauDecay", &eGenPromptTauDecay, &b_eGenPromptTauDecay);
   fChain->SetBranchAddress("eGenPt", &eGenPt, &b_eGenPt);
   fChain->SetBranchAddress("eGenTauDecay", &eGenTauDecay, &b_eGenTauDecay);
   fChain->SetBranchAddress("eGenVZ", &eGenVZ, &b_eGenVZ);
   fChain->SetBranchAddress("eGenVtxPVMatch", &eGenVtxPVMatch, &b_eGenVtxPVMatch);
   fChain->SetBranchAddress("eHadronicDepth1OverEm", &eHadronicDepth1OverEm, &b_eHadronicDepth1OverEm);
   fChain->SetBranchAddress("eHadronicDepth2OverEm", &eHadronicDepth2OverEm, &b_eHadronicDepth2OverEm);
   fChain->SetBranchAddress("eHadronicOverEM", &eHadronicOverEM, &b_eHadronicOverEM);
   fChain->SetBranchAddress("eHcalIsoDR03", &eHcalIsoDR03, &b_eHcalIsoDR03);
   fChain->SetBranchAddress("eIP3D", &eIP3D, &b_eIP3D);
   fChain->SetBranchAddress("eIP3DErr", &eIP3DErr, &b_eIP3DErr);
   fChain->SetBranchAddress("eIsoDB03", &eIsoDB03, &b_eIsoDB03);
   fChain->SetBranchAddress("eJetArea", &eJetArea, &b_eJetArea);
   fChain->SetBranchAddress("eJetBtag", &eJetBtag, &b_eJetBtag);
   fChain->SetBranchAddress("eJetDR", &eJetDR, &b_eJetDR);
   fChain->SetBranchAddress("eJetEtaEtaMoment", &eJetEtaEtaMoment, &b_eJetEtaEtaMoment);
   fChain->SetBranchAddress("eJetEtaPhiMoment", &eJetEtaPhiMoment, &b_eJetEtaPhiMoment);
   fChain->SetBranchAddress("eJetEtaPhiSpread", &eJetEtaPhiSpread, &b_eJetEtaPhiSpread);
   fChain->SetBranchAddress("eJetHadronFlavour", &eJetHadronFlavour, &b_eJetHadronFlavour);
   fChain->SetBranchAddress("eJetPFCISVBtag", &eJetPFCISVBtag, &b_eJetPFCISVBtag);
   fChain->SetBranchAddress("eJetPartonFlavour", &eJetPartonFlavour, &b_eJetPartonFlavour);
   fChain->SetBranchAddress("eJetPhiPhiMoment", &eJetPhiPhiMoment, &b_eJetPhiPhiMoment);
   fChain->SetBranchAddress("eJetPt", &eJetPt, &b_eJetPt);
   fChain->SetBranchAddress("eLowestMll", &eLowestMll, &b_eLowestMll);
   fChain->SetBranchAddress("eMVAIsoLoose", &eMVAIsoLoose, &b_eMVAIsoLoose);
   fChain->SetBranchAddress("eMVAIsoWP80", &eMVAIsoWP80, &b_eMVAIsoWP80);
   fChain->SetBranchAddress("eMVAIsoWP90", &eMVAIsoWP90, &b_eMVAIsoWP90);
   fChain->SetBranchAddress("eMVANoisoLoose", &eMVANoisoLoose, &b_eMVANoisoLoose);
   fChain->SetBranchAddress("eMVANoisoWP80", &eMVANoisoWP80, &b_eMVANoisoWP80);
   fChain->SetBranchAddress("eMVANoisoWP90", &eMVANoisoWP90, &b_eMVANoisoWP90);
   fChain->SetBranchAddress("eMass", &eMass, &b_eMass);
   fChain->SetBranchAddress("eMatchesEle24Tau30Filter", &eMatchesEle24Tau30Filter, &b_eMatchesEle24Tau30Filter);
   fChain->SetBranchAddress("eMatchesEle24Tau30Path", &eMatchesEle24Tau30Path, &b_eMatchesEle24Tau30Path);
   fChain->SetBranchAddress("eMatchesEle32Filter", &eMatchesEle32Filter, &b_eMatchesEle32Filter);
   fChain->SetBranchAddress("eMatchesEle32Path", &eMatchesEle32Path, &b_eMatchesEle32Path);
   fChain->SetBranchAddress("eMatchesEle35Filter", &eMatchesEle35Filter, &b_eMatchesEle35Filter);
   fChain->SetBranchAddress("eMatchesEle35Path", &eMatchesEle35Path, &b_eMatchesEle35Path);
   fChain->SetBranchAddress("eMissingHits", &eMissingHits, &b_eMissingHits);
   fChain->SetBranchAddress("eNearMuonVeto", &eNearMuonVeto, &b_eNearMuonVeto);
   fChain->SetBranchAddress("eNearestMuonDR", &eNearestMuonDR, &b_eNearestMuonDR);
   fChain->SetBranchAddress("eNearestZMass", &eNearestZMass, &b_eNearestZMass);
   fChain->SetBranchAddress("ePFChargedIso", &ePFChargedIso, &b_ePFChargedIso);
   fChain->SetBranchAddress("ePFNeutralIso", &ePFNeutralIso, &b_ePFNeutralIso);
   fChain->SetBranchAddress("ePFPUChargedIso", &ePFPUChargedIso, &b_ePFPUChargedIso);
   fChain->SetBranchAddress("ePFPhotonIso", &ePFPhotonIso, &b_ePFPhotonIso);
   fChain->SetBranchAddress("ePVDXY", &ePVDXY, &b_ePVDXY);
   fChain->SetBranchAddress("ePVDZ", &ePVDZ, &b_ePVDZ);
   fChain->SetBranchAddress("ePassesConversionVeto", &ePassesConversionVeto, &b_ePassesConversionVeto);
   fChain->SetBranchAddress("ePhi", &ePhi, &b_ePhi);
   fChain->SetBranchAddress("ePt", &ePt, &b_ePt);
   fChain->SetBranchAddress("eRelIso", &eRelIso, &b_eRelIso);
   fChain->SetBranchAddress("eRelPFIsoDB", &eRelPFIsoDB, &b_eRelPFIsoDB);
   fChain->SetBranchAddress("eRelPFIsoRho", &eRelPFIsoRho, &b_eRelPFIsoRho);
   fChain->SetBranchAddress("eRho", &eRho, &b_eRho);
   fChain->SetBranchAddress("eSCEnergy", &eSCEnergy, &b_eSCEnergy);
   fChain->SetBranchAddress("eSCEta", &eSCEta, &b_eSCEta);
   fChain->SetBranchAddress("eSCEtaWidth", &eSCEtaWidth, &b_eSCEtaWidth);
   fChain->SetBranchAddress("eSCPhi", &eSCPhi, &b_eSCPhi);
   fChain->SetBranchAddress("eSCPhiWidth", &eSCPhiWidth, &b_eSCPhiWidth);
   fChain->SetBranchAddress("eSCPreshowerEnergy", &eSCPreshowerEnergy, &b_eSCPreshowerEnergy);
   fChain->SetBranchAddress("eSCRawEnergy", &eSCRawEnergy, &b_eSCRawEnergy);
   fChain->SetBranchAddress("eSIP2D", &eSIP2D, &b_eSIP2D);
   fChain->SetBranchAddress("eSIP3D", &eSIP3D, &b_eSIP3D);
   fChain->SetBranchAddress("eSigmaIEtaIEta", &eSigmaIEtaIEta, &b_eSigmaIEtaIEta);
   fChain->SetBranchAddress("eTrkIsoDR03", &eTrkIsoDR03, &b_eTrkIsoDR03);
   fChain->SetBranchAddress("eVZ", &eVZ, &b_eVZ);
   fChain->SetBranchAddress("eVetoMVAIso", &eVetoMVAIso, &b_eVetoMVAIso);
   fChain->SetBranchAddress("eVetoZTTp001dxyz", &eVetoZTTp001dxyz, &b_eVetoZTTp001dxyz);
   fChain->SetBranchAddress("eVetoZTTp001dxyzR0", &eVetoZTTp001dxyzR0, &b_eVetoZTTp001dxyzR0);
   fChain->SetBranchAddress("eZTTGenMatching", &eZTTGenMatching, &b_eZTTGenMatching);
   fChain->SetBranchAddress("e_t_doubleL1IsoTauMatch", &e_t_doubleL1IsoTauMatch, &b_e_t_doubleL1IsoTauMatch);
   fChain->SetBranchAddress("edeltaEtaSuperClusterTrackAtVtx", &edeltaEtaSuperClusterTrackAtVtx, &b_edeltaEtaSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("edeltaPhiSuperClusterTrackAtVtx", &edeltaPhiSuperClusterTrackAtVtx, &b_edeltaPhiSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("eeSuperClusterOverP", &eeSuperClusterOverP, &b_eeSuperClusterOverP);
   fChain->SetBranchAddress("eecalEnergy", &eecalEnergy, &b_eecalEnergy);
   fChain->SetBranchAddress("efBrem", &efBrem, &b_efBrem);
   fChain->SetBranchAddress("etrackMomentumAtVtxP", &etrackMomentumAtVtxP, &b_etrackMomentumAtVtxP);
   fChain->SetBranchAddress("evt", &evt, &b_evt);
   fChain->SetBranchAddress("genEta", &genEta, &b_genEta);
   fChain->SetBranchAddress("genHTT", &genHTT, &b_genHTT);
   fChain->SetBranchAddress("genM", &genM, &b_genM);
   fChain->SetBranchAddress("genMass", &genMass, &b_genMass);
   fChain->SetBranchAddress("genPhi", &genPhi, &b_genPhi);
   fChain->SetBranchAddress("genpT", &genpT, &b_genpT);
   fChain->SetBranchAddress("genpX", &genpX, &b_genpX);
   fChain->SetBranchAddress("genpY", &genpY, &b_genpY);
   fChain->SetBranchAddress("isdata", &isdata, &b_isdata);
   fChain->SetBranchAddress("j1csv", &j1csv, &b_j1csv);
   fChain->SetBranchAddress("j1eta", &j1eta, &b_j1eta);
   fChain->SetBranchAddress("j1hadronflavor", &j1hadronflavor, &b_j1hadronflavor);
   fChain->SetBranchAddress("j1phi", &j1phi, &b_j1phi);
   fChain->SetBranchAddress("j1pt", &j1pt, &b_j1pt);
   fChain->SetBranchAddress("j2csv", &j2csv, &b_j2csv);
   fChain->SetBranchAddress("j2eta", &j2eta, &b_j2eta);
   fChain->SetBranchAddress("j2hadronflavor", &j2hadronflavor, &b_j2hadronflavor);
   fChain->SetBranchAddress("j2phi", &j2phi, &b_j2phi);
   fChain->SetBranchAddress("j2pt", &j2pt, &b_j2pt);
   fChain->SetBranchAddress("jb1csv", &jb1csv, &b_jb1csv);
   fChain->SetBranchAddress("jb1eta", &jb1eta, &b_jb1eta);
   fChain->SetBranchAddress("jb1hadronflavor", &jb1hadronflavor, &b_jb1hadronflavor);
   fChain->SetBranchAddress("jb1phi", &jb1phi, &b_jb1phi);
   fChain->SetBranchAddress("jb1pt", &jb1pt, &b_jb1pt);
   fChain->SetBranchAddress("jb2csv", &jb2csv, &b_jb2csv);
   fChain->SetBranchAddress("jb2eta", &jb2eta, &b_jb2eta);
   fChain->SetBranchAddress("jb2hadronflavor", &jb2hadronflavor, &b_jb2hadronflavor);
   fChain->SetBranchAddress("jb2phi", &jb2phi, &b_jb2phi);
   fChain->SetBranchAddress("jb2pt", &jb2pt, &b_jb2pt);
   fChain->SetBranchAddress("jetVeto20", &jetVeto20, &b_jetVeto20);
   fChain->SetBranchAddress("jetVeto20_JetEnDown", &jetVeto20_JetEnDown, &b_jetVeto20_JetEnDown);
   fChain->SetBranchAddress("jetVeto20_JetEnUp", &jetVeto20_JetEnUp, &b_jetVeto20_JetEnUp);
   fChain->SetBranchAddress("jetVeto30", &jetVeto30, &b_jetVeto30);
   fChain->SetBranchAddress("jetVeto30_JetEnDown", &jetVeto30_JetEnDown, &b_jetVeto30_JetEnDown);
   fChain->SetBranchAddress("jetVeto30_JetEnUp", &jetVeto30_JetEnUp, &b_jetVeto30_JetEnUp);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("metSig", &metSig, &b_metSig);
   fChain->SetBranchAddress("metcov00", &metcov00, &b_metcov00);
   fChain->SetBranchAddress("metcov00_DESYlike", &metcov00_DESYlike, &b_metcov00_DESYlike);
   fChain->SetBranchAddress("metcov01", &metcov01, &b_metcov01);
   fChain->SetBranchAddress("metcov01_DESYlike", &metcov01_DESYlike, &b_metcov01_DESYlike);
   fChain->SetBranchAddress("metcov10", &metcov10, &b_metcov10);
   fChain->SetBranchAddress("metcov10_DESYlike", &metcov10_DESYlike, &b_metcov10_DESYlike);
   fChain->SetBranchAddress("metcov11", &metcov11, &b_metcov11);
   fChain->SetBranchAddress("metcov11_DESYlike", &metcov11_DESYlike, &b_metcov11_DESYlike);
   fChain->SetBranchAddress("mu12e23DZGroup", &mu12e23DZGroup, &b_mu12e23DZGroup);
   fChain->SetBranchAddress("mu12e23DZPass", &mu12e23DZPass, &b_mu12e23DZPass);
   fChain->SetBranchAddress("mu12e23DZPrescale", &mu12e23DZPrescale, &b_mu12e23DZPrescale);
   fChain->SetBranchAddress("mu12e23Group", &mu12e23Group, &b_mu12e23Group);
   fChain->SetBranchAddress("mu12e23Pass", &mu12e23Pass, &b_mu12e23Pass);
   fChain->SetBranchAddress("mu12e23Prescale", &mu12e23Prescale, &b_mu12e23Prescale);
   fChain->SetBranchAddress("mu23e12DZGroup", &mu23e12DZGroup, &b_mu23e12DZGroup);
   fChain->SetBranchAddress("mu23e12DZPass", &mu23e12DZPass, &b_mu23e12DZPass);
   fChain->SetBranchAddress("mu23e12DZPrescale", &mu23e12DZPrescale, &b_mu23e12DZPrescale);
   fChain->SetBranchAddress("mu23e12Group", &mu23e12Group, &b_mu23e12Group);
   fChain->SetBranchAddress("mu23e12Pass", &mu23e12Pass, &b_mu23e12Pass);
   fChain->SetBranchAddress("mu23e12Prescale", &mu23e12Prescale, &b_mu23e12Prescale);
   fChain->SetBranchAddress("muGlbIsoVetoPt10", &muGlbIsoVetoPt10, &b_muGlbIsoVetoPt10);
   fChain->SetBranchAddress("muVetoZTTp001dxyz", &muVetoZTTp001dxyz, &b_muVetoZTTp001dxyz);
   fChain->SetBranchAddress("muVetoZTTp001dxyzR0", &muVetoZTTp001dxyzR0, &b_muVetoZTTp001dxyzR0);
   fChain->SetBranchAddress("nTruePU", &nTruePU, &b_nTruePU);
   fChain->SetBranchAddress("numGenJets", &numGenJets, &b_numGenJets);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("processID", &processID, &b_processID);
   fChain->SetBranchAddress("puppiMetEt", &puppiMetEt, &b_puppiMetEt);
   fChain->SetBranchAddress("puppiMetPhi", &puppiMetPhi, &b_puppiMetPhi);
   fChain->SetBranchAddress("pvChi2", &pvChi2, &b_pvChi2);
   fChain->SetBranchAddress("pvDX", &pvDX, &b_pvDX);
   fChain->SetBranchAddress("pvDY", &pvDY, &b_pvDY);
   fChain->SetBranchAddress("pvDZ", &pvDZ, &b_pvDZ);
   fChain->SetBranchAddress("pvIsFake", &pvIsFake, &b_pvIsFake);
   fChain->SetBranchAddress("pvIsValid", &pvIsValid, &b_pvIsValid);
   fChain->SetBranchAddress("pvNormChi2", &pvNormChi2, &b_pvNormChi2);
   fChain->SetBranchAddress("pvRho", &pvRho, &b_pvRho);
   fChain->SetBranchAddress("pvX", &pvX, &b_pvX);
   fChain->SetBranchAddress("pvY", &pvY, &b_pvY);
   fChain->SetBranchAddress("pvZ", &pvZ, &b_pvZ);
   fChain->SetBranchAddress("pvndof", &pvndof, &b_pvndof);
   fChain->SetBranchAddress("recoilDaught", &recoilDaught, &b_recoilDaught);
   fChain->SetBranchAddress("recoilWithMet", &recoilWithMet, &b_recoilWithMet);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("tAgainstElectronLooseMVA6", &tAgainstElectronLooseMVA6, &b_tAgainstElectronLooseMVA6);
   fChain->SetBranchAddress("tAgainstElectronMVA6Raw", &tAgainstElectronMVA6Raw, &b_tAgainstElectronMVA6Raw);
   fChain->SetBranchAddress("tAgainstElectronMVA6category", &tAgainstElectronMVA6category, &b_tAgainstElectronMVA6category);
   fChain->SetBranchAddress("tAgainstElectronMediumMVA6", &tAgainstElectronMediumMVA6, &b_tAgainstElectronMediumMVA6);
   fChain->SetBranchAddress("tAgainstElectronTightMVA6", &tAgainstElectronTightMVA6, &b_tAgainstElectronTightMVA6);
   fChain->SetBranchAddress("tAgainstElectronVLooseMVA6", &tAgainstElectronVLooseMVA6, &b_tAgainstElectronVLooseMVA6);
   fChain->SetBranchAddress("tAgainstElectronVTightMVA6", &tAgainstElectronVTightMVA6, &b_tAgainstElectronVTightMVA6);
   fChain->SetBranchAddress("tAgainstMuonLoose3", &tAgainstMuonLoose3, &b_tAgainstMuonLoose3);
   fChain->SetBranchAddress("tAgainstMuonTight3", &tAgainstMuonTight3, &b_tAgainstMuonTight3);
   fChain->SetBranchAddress("tByCombinedIsolationDeltaBetaCorrRaw3Hits", &tByCombinedIsolationDeltaBetaCorrRaw3Hits, &b_tByCombinedIsolationDeltaBetaCorrRaw3Hits);
   fChain->SetBranchAddress("tByIsolationMVArun2v1DBdR03oldDMwLTraw", &tByIsolationMVArun2v1DBdR03oldDMwLTraw, &b_tByIsolationMVArun2v1DBdR03oldDMwLTraw);
   fChain->SetBranchAddress("tByIsolationMVArun2v1DBnewDMwLTraw", &tByIsolationMVArun2v1DBnewDMwLTraw, &b_tByIsolationMVArun2v1DBnewDMwLTraw);
   fChain->SetBranchAddress("tByIsolationMVArun2v1DBoldDMwLTraw", &tByIsolationMVArun2v1DBoldDMwLTraw, &b_tByIsolationMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("tByLooseCombinedIsolationDeltaBetaCorr3Hits", &tByLooseCombinedIsolationDeltaBetaCorr3Hits, &b_tByLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("tByLooseIsolationMVArun2v1DBdR03oldDMwLT", &tByLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_tByLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByLooseIsolationMVArun2v1DBnewDMwLT", &tByLooseIsolationMVArun2v1DBnewDMwLT, &b_tByLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByLooseIsolationMVArun2v1DBoldDMwLT", &tByLooseIsolationMVArun2v1DBoldDMwLT, &b_tByLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByMediumCombinedIsolationDeltaBetaCorr3Hits", &tByMediumCombinedIsolationDeltaBetaCorr3Hits, &b_tByMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("tByMediumIsolationMVArun2v1DBdR03oldDMwLT", &tByMediumIsolationMVArun2v1DBdR03oldDMwLT, &b_tByMediumIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByMediumIsolationMVArun2v1DBnewDMwLT", &tByMediumIsolationMVArun2v1DBnewDMwLT, &b_tByMediumIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByMediumIsolationMVArun2v1DBoldDMwLT", &tByMediumIsolationMVArun2v1DBoldDMwLT, &b_tByMediumIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByPhotonPtSumOutsideSignalCone", &tByPhotonPtSumOutsideSignalCone, &b_tByPhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("tByTightCombinedIsolationDeltaBetaCorr3Hits", &tByTightCombinedIsolationDeltaBetaCorr3Hits, &b_tByTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("tByTightIsolationMVArun2v1DBdR03oldDMwLT", &tByTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByTightIsolationMVArun2v1DBnewDMwLT", &tByTightIsolationMVArun2v1DBnewDMwLT, &b_tByTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByTightIsolationMVArun2v1DBoldDMwLT", &tByTightIsolationMVArun2v1DBoldDMwLT, &b_tByTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByVLooseIsolationMVArun2v1DBdR03oldDMwLT", &tByVLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByVLooseIsolationMVArun2v1DBnewDMwLT", &tByVLooseIsolationMVArun2v1DBnewDMwLT, &b_tByVLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByVLooseIsolationMVArun2v1DBoldDMwLT", &tByVLooseIsolationMVArun2v1DBoldDMwLT, &b_tByVLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByVTightIsolationMVArun2v1DBdR03oldDMwLT", &tByVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByVTightIsolationMVArun2v1DBnewDMwLT", &tByVTightIsolationMVArun2v1DBnewDMwLT, &b_tByVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByVTightIsolationMVArun2v1DBoldDMwLT", &tByVTightIsolationMVArun2v1DBoldDMwLT, &b_tByVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tByVVTightIsolationMVArun2v1DBdR03oldDMwLT", &tByVVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_tByVVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tByVVTightIsolationMVArun2v1DBnewDMwLT", &tByVVTightIsolationMVArun2v1DBnewDMwLT, &b_tByVVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tByVVTightIsolationMVArun2v1DBoldDMwLT", &tByVVTightIsolationMVArun2v1DBoldDMwLT, &b_tByVVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tCharge", &tCharge, &b_tCharge);
   fChain->SetBranchAddress("tChargedIsoPtSum", &tChargedIsoPtSum, &b_tChargedIsoPtSum);
   fChain->SetBranchAddress("tChargedIsoPtSumdR03", &tChargedIsoPtSumdR03, &b_tChargedIsoPtSumdR03);
   fChain->SetBranchAddress("tComesFromHiggs", &tComesFromHiggs, &b_tComesFromHiggs);
   fChain->SetBranchAddress("tDecayMode", &tDecayMode, &b_tDecayMode);
   fChain->SetBranchAddress("tDecayModeFinding", &tDecayModeFinding, &b_tDecayModeFinding);
   fChain->SetBranchAddress("tDecayModeFindingNewDMs", &tDecayModeFindingNewDMs, &b_tDecayModeFindingNewDMs);
   fChain->SetBranchAddress("tEta", &tEta, &b_tEta);
   fChain->SetBranchAddress("tFootprintCorrection", &tFootprintCorrection, &b_tFootprintCorrection);
   fChain->SetBranchAddress("tFootprintCorrectiondR03", &tFootprintCorrectiondR03, &b_tFootprintCorrectiondR03);
   fChain->SetBranchAddress("tGenCharge", &tGenCharge, &b_tGenCharge);
   fChain->SetBranchAddress("tGenDecayMode", &tGenDecayMode, &b_tGenDecayMode);
   fChain->SetBranchAddress("tGenEnergy", &tGenEnergy, &b_tGenEnergy);
   fChain->SetBranchAddress("tGenEta", &tGenEta, &b_tGenEta);
   fChain->SetBranchAddress("tGenJetEta", &tGenJetEta, &b_tGenJetEta);
   fChain->SetBranchAddress("tGenJetPt", &tGenJetPt, &b_tGenJetPt);
   fChain->SetBranchAddress("tGenMotherEnergy", &tGenMotherEnergy, &b_tGenMotherEnergy);
   fChain->SetBranchAddress("tGenMotherEta", &tGenMotherEta, &b_tGenMotherEta);
   fChain->SetBranchAddress("tGenMotherPdgId", &tGenMotherPdgId, &b_tGenMotherPdgId);
   fChain->SetBranchAddress("tGenMotherPhi", &tGenMotherPhi, &b_tGenMotherPhi);
   fChain->SetBranchAddress("tGenMotherPt", &tGenMotherPt, &b_tGenMotherPt);
   fChain->SetBranchAddress("tGenPdgId", &tGenPdgId, &b_tGenPdgId);
   fChain->SetBranchAddress("tGenPhi", &tGenPhi, &b_tGenPhi);
   fChain->SetBranchAddress("tGenPt", &tGenPt, &b_tGenPt);
   fChain->SetBranchAddress("tGenStatus", &tGenStatus, &b_tGenStatus);
   fChain->SetBranchAddress("tJetArea", &tJetArea, &b_tJetArea);
   fChain->SetBranchAddress("tJetBtag", &tJetBtag, &b_tJetBtag);
   fChain->SetBranchAddress("tJetDR", &tJetDR, &b_tJetDR);
   fChain->SetBranchAddress("tJetEtaEtaMoment", &tJetEtaEtaMoment, &b_tJetEtaEtaMoment);
   fChain->SetBranchAddress("tJetEtaPhiMoment", &tJetEtaPhiMoment, &b_tJetEtaPhiMoment);
   fChain->SetBranchAddress("tJetEtaPhiSpread", &tJetEtaPhiSpread, &b_tJetEtaPhiSpread);
   fChain->SetBranchAddress("tJetHadronFlavour", &tJetHadronFlavour, &b_tJetHadronFlavour);
   fChain->SetBranchAddress("tJetPFCISVBtag", &tJetPFCISVBtag, &b_tJetPFCISVBtag);
   fChain->SetBranchAddress("tJetPartonFlavour", &tJetPartonFlavour, &b_tJetPartonFlavour);
   fChain->SetBranchAddress("tJetPhiPhiMoment", &tJetPhiPhiMoment, &b_tJetPhiPhiMoment);
   fChain->SetBranchAddress("tJetPt", &tJetPt, &b_tJetPt);
   fChain->SetBranchAddress("tL1IsoTauMatch", &tL1IsoTauMatch, &b_tL1IsoTauMatch);
   fChain->SetBranchAddress("tL1IsoTauPt", &tL1IsoTauPt, &b_tL1IsoTauPt);
   fChain->SetBranchAddress("tLeadTrackPt", &tLeadTrackPt, &b_tLeadTrackPt);
   fChain->SetBranchAddress("tLowestMll", &tLowestMll, &b_tLowestMll);
   fChain->SetBranchAddress("tMass", &tMass, &b_tMass);
   fChain->SetBranchAddress("tMatchesDoubleMediumTau35Filter", &tMatchesDoubleMediumTau35Filter, &b_tMatchesDoubleMediumTau35Filter);
   fChain->SetBranchAddress("tMatchesDoubleMediumTau35Path", &tMatchesDoubleMediumTau35Path, &b_tMatchesDoubleMediumTau35Path);
   fChain->SetBranchAddress("tMatchesDoubleMediumTau40Filter", &tMatchesDoubleMediumTau40Filter, &b_tMatchesDoubleMediumTau40Filter);
   fChain->SetBranchAddress("tMatchesDoubleMediumTau40Path", &tMatchesDoubleMediumTau40Path, &b_tMatchesDoubleMediumTau40Path);
   fChain->SetBranchAddress("tMatchesDoubleTightTau35Filter", &tMatchesDoubleTightTau35Filter, &b_tMatchesDoubleTightTau35Filter);
   fChain->SetBranchAddress("tMatchesDoubleTightTau35Path", &tMatchesDoubleTightTau35Path, &b_tMatchesDoubleTightTau35Path);
   fChain->SetBranchAddress("tMatchesDoubleTightTau40Filter", &tMatchesDoubleTightTau40Filter, &b_tMatchesDoubleTightTau40Filter);
   fChain->SetBranchAddress("tMatchesDoubleTightTau40Path", &tMatchesDoubleTightTau40Path, &b_tMatchesDoubleTightTau40Path);
   fChain->SetBranchAddress("tMatchesEle24Tau30Filter", &tMatchesEle24Tau30Filter, &b_tMatchesEle24Tau30Filter);
   fChain->SetBranchAddress("tMatchesEle24Tau30Path", &tMatchesEle24Tau30Path, &b_tMatchesEle24Tau30Path);
   fChain->SetBranchAddress("tMatchesIsoMu20Tau27Filter", &tMatchesIsoMu20Tau27Filter, &b_tMatchesIsoMu20Tau27Filter);
   fChain->SetBranchAddress("tMatchesIsoMu20Tau27Path", &tMatchesIsoMu20Tau27Path, &b_tMatchesIsoMu20Tau27Path);
   fChain->SetBranchAddress("tNChrgHadrIsolationCands", &tNChrgHadrIsolationCands, &b_tNChrgHadrIsolationCands);
   fChain->SetBranchAddress("tNChrgHadrSignalCands", &tNChrgHadrSignalCands, &b_tNChrgHadrSignalCands);
   fChain->SetBranchAddress("tNGammaSignalCands", &tNGammaSignalCands, &b_tNGammaSignalCands);
   fChain->SetBranchAddress("tNNeutralHadrSignalCands", &tNNeutralHadrSignalCands, &b_tNNeutralHadrSignalCands);
   fChain->SetBranchAddress("tNSignalCands", &tNSignalCands, &b_tNSignalCands);
   fChain->SetBranchAddress("tNearestZMass", &tNearestZMass, &b_tNearestZMass);
   fChain->SetBranchAddress("tNeutralIsoPtSum", &tNeutralIsoPtSum, &b_tNeutralIsoPtSum);
   fChain->SetBranchAddress("tNeutralIsoPtSumWeight", &tNeutralIsoPtSumWeight, &b_tNeutralIsoPtSumWeight);
   fChain->SetBranchAddress("tNeutralIsoPtSumWeightdR03", &tNeutralIsoPtSumWeightdR03, &b_tNeutralIsoPtSumWeightdR03);
   fChain->SetBranchAddress("tNeutralIsoPtSumdR03", &tNeutralIsoPtSumdR03, &b_tNeutralIsoPtSumdR03);
   fChain->SetBranchAddress("tPVDXY", &tPVDXY, &b_tPVDXY);
   fChain->SetBranchAddress("tPVDZ", &tPVDZ, &b_tPVDZ);
   fChain->SetBranchAddress("tPhi", &tPhi, &b_tPhi);
   fChain->SetBranchAddress("tPhotonPtSumOutsideSignalCone", &tPhotonPtSumOutsideSignalCone, &b_tPhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("tPhotonPtSumOutsideSignalConedR03", &tPhotonPtSumOutsideSignalConedR03, &b_tPhotonPtSumOutsideSignalConedR03);
   fChain->SetBranchAddress("tPt", &tPt, &b_tPt);
   fChain->SetBranchAddress("tPuCorrPtSum", &tPuCorrPtSum, &b_tPuCorrPtSum);
   fChain->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTLoose", &tRerunMVArun2v1DBoldDMwLTLoose, &b_tRerunMVArun2v1DBoldDMwLTLoose);
   fChain->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTMedium", &tRerunMVArun2v1DBoldDMwLTMedium, &b_tRerunMVArun2v1DBoldDMwLTMedium);
   fChain->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTTight", &tRerunMVArun2v1DBoldDMwLTTight, &b_tRerunMVArun2v1DBoldDMwLTTight);
   fChain->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTVLoose", &tRerunMVArun2v1DBoldDMwLTVLoose, &b_tRerunMVArun2v1DBoldDMwLTVLoose);
   fChain->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTVTight", &tRerunMVArun2v1DBoldDMwLTVTight, &b_tRerunMVArun2v1DBoldDMwLTVTight);
   fChain->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTVVTight", &tRerunMVArun2v1DBoldDMwLTVVTight, &b_tRerunMVArun2v1DBoldDMwLTVVTight);
   fChain->SetBranchAddress("tRerunMVArun2v1DBoldDMwLTraw", &tRerunMVArun2v1DBoldDMwLTraw, &b_tRerunMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTLoose", &tRerunMVArun2v2DBoldDMwLTLoose, &b_tRerunMVArun2v2DBoldDMwLTLoose);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTMedium", &tRerunMVArun2v2DBoldDMwLTMedium, &b_tRerunMVArun2v2DBoldDMwLTMedium);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTTight", &tRerunMVArun2v2DBoldDMwLTTight, &b_tRerunMVArun2v2DBoldDMwLTTight);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTVLoose", &tRerunMVArun2v2DBoldDMwLTVLoose, &b_tRerunMVArun2v2DBoldDMwLTVLoose);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTVTight", &tRerunMVArun2v2DBoldDMwLTVTight, &b_tRerunMVArun2v2DBoldDMwLTVTight);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTVVLoose", &tRerunMVArun2v2DBoldDMwLTVVLoose, &b_tRerunMVArun2v2DBoldDMwLTVVLoose);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTVVTight", &tRerunMVArun2v2DBoldDMwLTVVTight, &b_tRerunMVArun2v2DBoldDMwLTVVTight);
   fChain->SetBranchAddress("tRerunMVArun2v2DBoldDMwLTraw", &tRerunMVArun2v2DBoldDMwLTraw, &b_tRerunMVArun2v2DBoldDMwLTraw);
   fChain->SetBranchAddress("tVZ", &tVZ, &b_tVZ);
   fChain->SetBranchAddress("tZTTGenDR", &tZTTGenDR, &b_tZTTGenDR);
   fChain->SetBranchAddress("tZTTGenEta", &tZTTGenEta, &b_tZTTGenEta);
   fChain->SetBranchAddress("tZTTGenMatching", &tZTTGenMatching, &b_tZTTGenMatching);
   fChain->SetBranchAddress("tZTTGenPhi", &tZTTGenPhi, &b_tZTTGenPhi);
   fChain->SetBranchAddress("tZTTGenPt", &tZTTGenPt, &b_tZTTGenPt);
   fChain->SetBranchAddress("tauVetoPt20Loose3HitsVtx", &tauVetoPt20Loose3HitsVtx, &b_tauVetoPt20Loose3HitsVtx);
   fChain->SetBranchAddress("tauVetoPt20TightMVALTVtx", &tauVetoPt20TightMVALTVtx, &b_tauVetoPt20TightMVALTVtx);
   fChain->SetBranchAddress("topQuarkPt1", &topQuarkPt1, &b_topQuarkPt1);
   fChain->SetBranchAddress("topQuarkPt2", &topQuarkPt2, &b_topQuarkPt2);
   fChain->SetBranchAddress("tripleEGroup", &tripleEGroup, &b_tripleEGroup);
   fChain->SetBranchAddress("tripleEPass", &tripleEPass, &b_tripleEPass);
   fChain->SetBranchAddress("tripleEPrescale", &tripleEPrescale, &b_tripleEPrescale);
   fChain->SetBranchAddress("tripleMu12_10_5Group", &tripleMu12_10_5Group, &b_tripleMu12_10_5Group);
   fChain->SetBranchAddress("tripleMu12_10_5Pass", &tripleMu12_10_5Pass, &b_tripleMu12_10_5Pass);
   fChain->SetBranchAddress("tripleMu12_10_5Prescale", &tripleMu12_10_5Prescale, &b_tripleMu12_10_5Prescale);
   fChain->SetBranchAddress("type1_pfMetEt", &type1_pfMetEt, &b_type1_pfMetEt);
   fChain->SetBranchAddress("type1_pfMetPhi", &type1_pfMetPhi, &b_type1_pfMetPhi);
   fChain->SetBranchAddress("vbfDeta", &vbfDeta, &b_vbfDeta);
   fChain->SetBranchAddress("vbfJetVeto20", &vbfJetVeto20, &b_vbfJetVeto20);
   fChain->SetBranchAddress("vbfJetVeto30", &vbfJetVeto30, &b_vbfJetVeto30);
   fChain->SetBranchAddress("vbfMass", &vbfMass, &b_vbfMass);
   fChain->SetBranchAddress("vbfNJets20", &vbfNJets20, &b_vbfNJets20);
   fChain->SetBranchAddress("vbfNJets30", &vbfNJets30, &b_vbfNJets30);
   fChain->SetBranchAddress("vbfj1eta", &vbfj1eta, &b_vbfj1eta);
   fChain->SetBranchAddress("vbfj1pt", &vbfj1pt, &b_vbfj1pt);
   fChain->SetBranchAddress("vbfj2eta", &vbfj2eta, &b_vbfj2eta);
   fChain->SetBranchAddress("vbfj2pt", &vbfj2pt, &b_vbfj2pt);
   fChain->SetBranchAddress("vispX", &vispX, &b_vispX);
   fChain->SetBranchAddress("vispY", &vispY, &b_vispY);
   fChain->SetBranchAddress("idx", &idx, &b_idx);
}

#endif // #ifdef HTauTauTree_et_cxx
