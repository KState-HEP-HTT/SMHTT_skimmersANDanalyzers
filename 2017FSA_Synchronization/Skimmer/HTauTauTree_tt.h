#ifndef HTauTauTree_tt_h
#define HTauTauTree_tt_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <vector>

using namespace std;

// Header file for the classes stored in the TTree if any.

class HTauTauTree_tt {
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
   Float_t         eVetoMVAIso;
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
   Float_t         t1AgainstElectronLooseMVA6;
   Float_t         t1AgainstElectronMVA6Raw;
   Float_t         t1AgainstElectronMVA6category;
   Float_t         t1AgainstElectronMediumMVA6;
   Float_t         t1AgainstElectronTightMVA6;
   Float_t         t1AgainstElectronVLooseMVA6;
   Float_t         t1AgainstElectronVTightMVA6;
   Float_t         t1AgainstMuonLoose3;
   Float_t         t1AgainstMuonTight3;
   Float_t         t1ByCombinedIsolationDeltaBetaCorrRaw3Hits;
   Float_t         t1ByIsolationMVArun2v1DBdR03oldDMwLTraw;
   Float_t         t1ByIsolationMVArun2v1DBnewDMwLTraw;
   Float_t         t1ByIsolationMVArun2v1DBoldDMwLTraw;
   Float_t         t1ByLooseCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByMediumCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByMediumIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByMediumIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByPhotonPtSumOutsideSignalCone;
   Float_t         t1ByTightCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t1ByTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1Charge;
   Float_t         t1ChargedIsoPtSum;
   Float_t         t1ChargedIsoPtSumdR03;
   Float_t         t1ComesFromHiggs;
   Float_t         t1DecayMode;
   Float_t         t1DecayModeFinding;
   Float_t         t1DecayModeFindingNewDMs;
   Float_t         t1Eta;
   Float_t         t1FootprintCorrection;
   Float_t         t1FootprintCorrectiondR03;
   Float_t         t1GenCharge;
   Float_t         t1GenDecayMode;
   Float_t         t1GenEnergy;
   Float_t         t1GenEta;
   Float_t         t1GenJetEta;
   Float_t         t1GenJetPt;
   Float_t         t1GenMotherEnergy;
   Float_t         t1GenMotherEta;
   Float_t         t1GenMotherPdgId;
   Float_t         t1GenMotherPhi;
   Float_t         t1GenMotherPt;
   Float_t         t1GenPdgId;
   Float_t         t1GenPhi;
   Float_t         t1GenPt;
   Float_t         t1GenStatus;
   Float_t         t1JetArea;
   Float_t         t1JetBtag;
   Float_t         t1JetDR;
   Float_t         t1JetEtaEtaMoment;
   Float_t         t1JetEtaPhiMoment;
   Float_t         t1JetEtaPhiSpread;
   Float_t         t1JetHadronFlavour;
   Float_t         t1JetPFCISVBtag;
   Float_t         t1JetPartonFlavour;
   Float_t         t1JetPhiPhiMoment;
   Float_t         t1JetPt;
   Float_t         t1L1IsoTauMatch;
   Float_t         t1L1IsoTauPt;
   Float_t         t1LeadTrackPt;
   Float_t         t1LowestMll;
   Float_t         t1Mass;
   Float_t         t1MatchesDoubleMediumTau35Filter;
   Float_t         t1MatchesDoubleMediumTau35Path;
   Float_t         t1MatchesDoubleMediumTau40Filter;
   Float_t         t1MatchesDoubleMediumTau40Path;
   Float_t         t1MatchesDoubleTightTau35Filter;
   Float_t         t1MatchesDoubleTightTau35Path;
   Float_t         t1MatchesDoubleTightTau40Filter;
   Float_t         t1MatchesDoubleTightTau40Path;
   Float_t         t1MatchesEle24Tau30Filter;
   Float_t         t1MatchesEle24Tau30Path;
   Float_t         t1MatchesIsoMu20Tau27Filter;
   Float_t         t1MatchesIsoMu20Tau27Path;
   Float_t         t1NChrgHadrIsolationCands;
   Float_t         t1NChrgHadrSignalCands;
   Float_t         t1NGammaSignalCands;
   Float_t         t1NNeutralHadrSignalCands;
   Float_t         t1NSignalCands;
   Float_t         t1NearestZMass;
   Float_t         t1NeutralIsoPtSum;
   Float_t         t1NeutralIsoPtSumWeight;
   Float_t         t1NeutralIsoPtSumWeightdR03;
   Float_t         t1NeutralIsoPtSumdR03;
   Float_t         t1PVDXY;
   Float_t         t1PVDZ;
   Float_t         t1Phi;
   Float_t         t1PhotonPtSumOutsideSignalCone;
   Float_t         t1PhotonPtSumOutsideSignalConedR03;
   Float_t         t1Pt;
   Float_t         t1PuCorrPtSum;
   Float_t         t1RerunMVArun2v1DBoldDMwLTLoose;
   Float_t         t1RerunMVArun2v1DBoldDMwLTMedium;
   Float_t         t1RerunMVArun2v1DBoldDMwLTTight;
   Float_t         t1RerunMVArun2v1DBoldDMwLTVLoose;
   Float_t         t1RerunMVArun2v1DBoldDMwLTVTight;
   Float_t         t1RerunMVArun2v1DBoldDMwLTVVTight;
   Float_t         t1RerunMVArun2v1DBoldDMwLTraw;
   Float_t         t1RerunMVArun2v2DBoldDMwLTLoose;
   Float_t         t1RerunMVArun2v2DBoldDMwLTMedium;
   Float_t         t1RerunMVArun2v2DBoldDMwLTTight;
   Float_t         t1RerunMVArun2v2DBoldDMwLTVLoose;
   Float_t         t1RerunMVArun2v2DBoldDMwLTVTight;
   Float_t         t1RerunMVArun2v2DBoldDMwLTVVLoose;
   Float_t         t1RerunMVArun2v2DBoldDMwLTVVTight;
   Float_t         t1RerunMVArun2v2DBoldDMwLTraw;
   Float_t         t1VZ;
   Float_t         t1ZTTGenDR;
   Float_t         t1ZTTGenEta;
   Float_t         t1ZTTGenMatching;
   Float_t         t1ZTTGenPhi;
   Float_t         t1ZTTGenPt;
   Float_t         t1_t2_doubleL1IsoTauMatch;
   Float_t         t2AgainstElectronLooseMVA6;
   Float_t         t2AgainstElectronMVA6Raw;
   Float_t         t2AgainstElectronMVA6category;
   Float_t         t2AgainstElectronMediumMVA6;
   Float_t         t2AgainstElectronTightMVA6;
   Float_t         t2AgainstElectronVLooseMVA6;
   Float_t         t2AgainstElectronVTightMVA6;
   Float_t         t2AgainstMuonLoose3;
   Float_t         t2AgainstMuonTight3;
   Float_t         t2ByCombinedIsolationDeltaBetaCorrRaw3Hits;
   Float_t         t2ByIsolationMVArun2v1DBdR03oldDMwLTraw;
   Float_t         t2ByIsolationMVArun2v1DBnewDMwLTraw;
   Float_t         t2ByIsolationMVArun2v1DBoldDMwLTraw;
   Float_t         t2ByLooseCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByMediumCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByMediumIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByMediumIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByPhotonPtSumOutsideSignalCone;
   Float_t         t2ByTightCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t2ByTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2Charge;
   Float_t         t2ChargedIsoPtSum;
   Float_t         t2ChargedIsoPtSumdR03;
   Float_t         t2ComesFromHiggs;
   Float_t         t2DecayMode;
   Float_t         t2DecayModeFinding;
   Float_t         t2DecayModeFindingNewDMs;
   Float_t         t2Eta;
   Float_t         t2FootprintCorrection;
   Float_t         t2FootprintCorrectiondR03;
   Float_t         t2GenCharge;
   Float_t         t2GenDecayMode;
   Float_t         t2GenEnergy;
   Float_t         t2GenEta;
   Float_t         t2GenJetEta;
   Float_t         t2GenJetPt;
   Float_t         t2GenMotherEnergy;
   Float_t         t2GenMotherEta;
   Float_t         t2GenMotherPdgId;
   Float_t         t2GenMotherPhi;
   Float_t         t2GenMotherPt;
   Float_t         t2GenPdgId;
   Float_t         t2GenPhi;
   Float_t         t2GenPt;
   Float_t         t2GenStatus;
   Float_t         t2JetArea;
   Float_t         t2JetBtag;
   Float_t         t2JetDR;
   Float_t         t2JetEtaEtaMoment;
   Float_t         t2JetEtaPhiMoment;
   Float_t         t2JetEtaPhiSpread;
   Float_t         t2JetHadronFlavour;
   Float_t         t2JetPFCISVBtag;
   Float_t         t2JetPartonFlavour;
   Float_t         t2JetPhiPhiMoment;
   Float_t         t2JetPt;
   Float_t         t2L1IsoTauMatch;
   Float_t         t2L1IsoTauPt;
   Float_t         t2LeadTrackPt;
   Float_t         t2LowestMll;
   Float_t         t2Mass;
   Float_t         t2MatchesDoubleMediumTau35Filter;
   Float_t         t2MatchesDoubleMediumTau35Path;
   Float_t         t2MatchesDoubleMediumTau40Filter;
   Float_t         t2MatchesDoubleMediumTau40Path;
   Float_t         t2MatchesDoubleTightTau35Filter;
   Float_t         t2MatchesDoubleTightTau35Path;
   Float_t         t2MatchesDoubleTightTau40Filter;
   Float_t         t2MatchesDoubleTightTau40Path;
   Float_t         t2MatchesEle24Tau30Filter;
   Float_t         t2MatchesEle24Tau30Path;
   Float_t         t2MatchesIsoMu20Tau27Filter;
   Float_t         t2MatchesIsoMu20Tau27Path;
   Float_t         t2NChrgHadrIsolationCands;
   Float_t         t2NChrgHadrSignalCands;
   Float_t         t2NGammaSignalCands;
   Float_t         t2NNeutralHadrSignalCands;
   Float_t         t2NSignalCands;
   Float_t         t2NearestZMass;
   Float_t         t2NeutralIsoPtSum;
   Float_t         t2NeutralIsoPtSumWeight;
   Float_t         t2NeutralIsoPtSumWeightdR03;
   Float_t         t2NeutralIsoPtSumdR03;
   Float_t         t2PVDXY;
   Float_t         t2PVDZ;
   Float_t         t2Phi;
   Float_t         t2PhotonPtSumOutsideSignalCone;
   Float_t         t2PhotonPtSumOutsideSignalConedR03;
   Float_t         t2Pt;
   Float_t         t2PuCorrPtSum;
   Float_t         t2RerunMVArun2v1DBoldDMwLTLoose;
   Float_t         t2RerunMVArun2v1DBoldDMwLTMedium;
   Float_t         t2RerunMVArun2v1DBoldDMwLTTight;
   Float_t         t2RerunMVArun2v1DBoldDMwLTVLoose;
   Float_t         t2RerunMVArun2v1DBoldDMwLTVTight;
   Float_t         t2RerunMVArun2v1DBoldDMwLTVVTight;
   Float_t         t2RerunMVArun2v1DBoldDMwLTraw;
   Float_t         t2RerunMVArun2v2DBoldDMwLTLoose;
   Float_t         t2RerunMVArun2v2DBoldDMwLTMedium;
   Float_t         t2RerunMVArun2v2DBoldDMwLTTight;
   Float_t         t2RerunMVArun2v2DBoldDMwLTVLoose;
   Float_t         t2RerunMVArun2v2DBoldDMwLTVTight;
   Float_t         t2RerunMVArun2v2DBoldDMwLTVVLoose;
   Float_t         t2RerunMVArun2v2DBoldDMwLTVVTight;
   Float_t         t2RerunMVArun2v2DBoldDMwLTraw;
   Float_t         t2VZ;
   Float_t         t2ZTTGenDR;
   Float_t         t2ZTTGenEta;
   Float_t         t2ZTTGenMatching;
   Float_t         t2ZTTGenPhi;
   Float_t         t2ZTTGenPt;
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
   TBranch        *b_eVetoMVAIso;   //!
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
   TBranch        *b_t1AgainstElectronLooseMVA6;   //!
   TBranch        *b_t1AgainstElectronMVA6Raw;   //!
   TBranch        *b_t1AgainstElectronMVA6category;   //!
   TBranch        *b_t1AgainstElectronMediumMVA6;   //!
   TBranch        *b_t1AgainstElectronTightMVA6;   //!
   TBranch        *b_t1AgainstElectronVLooseMVA6;   //!
   TBranch        *b_t1AgainstElectronVTightMVA6;   //!
   TBranch        *b_t1AgainstMuonLoose3;   //!
   TBranch        *b_t1AgainstMuonTight3;   //!
   TBranch        *b_t1ByCombinedIsolationDeltaBetaCorrRaw3Hits;   //!
   TBranch        *b_t1ByIsolationMVArun2v1DBdR03oldDMwLTraw;   //!
   TBranch        *b_t1ByIsolationMVArun2v1DBnewDMwLTraw;   //!
   TBranch        *b_t1ByIsolationMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_t1ByLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_t1ByTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1Charge;   //!
   TBranch        *b_t1ChargedIsoPtSum;   //!
   TBranch        *b_t1ChargedIsoPtSumdR03;   //!
   TBranch        *b_t1ComesFromHiggs;   //!
   TBranch        *b_t1DecayMode;   //!
   TBranch        *b_t1DecayModeFinding;   //!
   TBranch        *b_t1DecayModeFindingNewDMs;   //!
   TBranch        *b_t1Eta;   //!
   TBranch        *b_t1FootprintCorrection;   //!
   TBranch        *b_t1FootprintCorrectiondR03;   //!
   TBranch        *b_t1GenCharge;   //!
   TBranch        *b_t1GenDecayMode;   //!
   TBranch        *b_t1GenEnergy;   //!
   TBranch        *b_t1GenEta;   //!
   TBranch        *b_t1GenJetEta;   //!
   TBranch        *b_t1GenJetPt;   //!
   TBranch        *b_t1GenMotherEnergy;   //!
   TBranch        *b_t1GenMotherEta;   //!
   TBranch        *b_t1GenMotherPdgId;   //!
   TBranch        *b_t1GenMotherPhi;   //!
   TBranch        *b_t1GenMotherPt;   //!
   TBranch        *b_t1GenPdgId;   //!
   TBranch        *b_t1GenPhi;   //!
   TBranch        *b_t1GenPt;   //!
   TBranch        *b_t1GenStatus;   //!
   TBranch        *b_t1JetArea;   //!
   TBranch        *b_t1JetBtag;   //!
   TBranch        *b_t1JetDR;   //!
   TBranch        *b_t1JetEtaEtaMoment;   //!
   TBranch        *b_t1JetEtaPhiMoment;   //!
   TBranch        *b_t1JetEtaPhiSpread;   //!
   TBranch        *b_t1JetHadronFlavour;   //!
   TBranch        *b_t1JetPFCISVBtag;   //!
   TBranch        *b_t1JetPartonFlavour;   //!
   TBranch        *b_t1JetPhiPhiMoment;   //!
   TBranch        *b_t1JetPt;   //!
   TBranch        *b_t1L1IsoTauMatch;   //!
   TBranch        *b_t1L1IsoTauPt;   //!
   TBranch        *b_t1LeadTrackPt;   //!
   TBranch        *b_t1LowestMll;   //!
   TBranch        *b_t1Mass;   //!
   TBranch        *b_t1MatchesDoubleMediumTau35Filter;   //!
   TBranch        *b_t1MatchesDoubleMediumTau35Path;   //!
   TBranch        *b_t1MatchesDoubleMediumTau40Filter;   //!
   TBranch        *b_t1MatchesDoubleMediumTau40Path;   //!
   TBranch        *b_t1MatchesDoubleTightTau35Filter;   //!
   TBranch        *b_t1MatchesDoubleTightTau35Path;   //!
   TBranch        *b_t1MatchesDoubleTightTau40Filter;   //!
   TBranch        *b_t1MatchesDoubleTightTau40Path;   //!
   TBranch        *b_t1MatchesEle24Tau30Filter;   //!
   TBranch        *b_t1MatchesEle24Tau30Path;   //!
   TBranch        *b_t1MatchesIsoMu20Tau27Filter;   //!
   TBranch        *b_t1MatchesIsoMu20Tau27Path;   //!
   TBranch        *b_t1NChrgHadrIsolationCands;   //!
   TBranch        *b_t1NChrgHadrSignalCands;   //!
   TBranch        *b_t1NGammaSignalCands;   //!
   TBranch        *b_t1NNeutralHadrSignalCands;   //!
   TBranch        *b_t1NSignalCands;   //!
   TBranch        *b_t1NearestZMass;   //!
   TBranch        *b_t1NeutralIsoPtSum;   //!
   TBranch        *b_t1NeutralIsoPtSumWeight;   //!
   TBranch        *b_t1NeutralIsoPtSumWeightdR03;   //!
   TBranch        *b_t1NeutralIsoPtSumdR03;   //!
   TBranch        *b_t1PVDXY;   //!
   TBranch        *b_t1PVDZ;   //!
   TBranch        *b_t1Phi;   //!
   TBranch        *b_t1PhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_t1PhotonPtSumOutsideSignalConedR03;   //!
   TBranch        *b_t1Pt;   //!
   TBranch        *b_t1PuCorrPtSum;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTLoose;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTMedium;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTTight;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTVLoose;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTVTight;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTVVTight;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_t1RerunMVArun2v2DBoldDMwLTLoose;   //!
   TBranch        *b_t1RerunMVArun2v2DBoldDMwLTMedium;   //!
   TBranch        *b_t1RerunMVArun2v2DBoldDMwLTTight;   //!
   TBranch        *b_t1RerunMVArun2v2DBoldDMwLTVLoose;   //!
   TBranch        *b_t1RerunMVArun2v2DBoldDMwLTVTight;   //!
   TBranch        *b_t1RerunMVArun2v2DBoldDMwLTVVLoose;   //!
   TBranch        *b_t1RerunMVArun2v2DBoldDMwLTVVTight;   //!
   TBranch        *b_t1RerunMVArun2v2DBoldDMwLTraw;   //!
   TBranch        *b_t1VZ;   //!
   TBranch        *b_t1ZTTGenDR;   //!
   TBranch        *b_t1ZTTGenEta;   //!
   TBranch        *b_t1ZTTGenMatching;   //!
   TBranch        *b_t1ZTTGenPhi;   //!
   TBranch        *b_t1ZTTGenPt;   //!
   TBranch        *b_t1_t2_doubleL1IsoTauMatch;   //!
   TBranch        *b_t2AgainstElectronLooseMVA6;   //!
   TBranch        *b_t2AgainstElectronMVA6Raw;   //!
   TBranch        *b_t2AgainstElectronMVA6category;   //!
   TBranch        *b_t2AgainstElectronMediumMVA6;   //!
   TBranch        *b_t2AgainstElectronTightMVA6;   //!
   TBranch        *b_t2AgainstElectronVLooseMVA6;   //!
   TBranch        *b_t2AgainstElectronVTightMVA6;   //!
   TBranch        *b_t2AgainstMuonLoose3;   //!
   TBranch        *b_t2AgainstMuonTight3;   //!
   TBranch        *b_t2ByCombinedIsolationDeltaBetaCorrRaw3Hits;   //!
   TBranch        *b_t2ByIsolationMVArun2v1DBdR03oldDMwLTraw;   //!
   TBranch        *b_t2ByIsolationMVArun2v1DBnewDMwLTraw;   //!
   TBranch        *b_t2ByIsolationMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_t2ByLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_t2ByTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2Charge;   //!
   TBranch        *b_t2ChargedIsoPtSum;   //!
   TBranch        *b_t2ChargedIsoPtSumdR03;   //!
   TBranch        *b_t2ComesFromHiggs;   //!
   TBranch        *b_t2DecayMode;   //!
   TBranch        *b_t2DecayModeFinding;   //!
   TBranch        *b_t2DecayModeFindingNewDMs;   //!
   TBranch        *b_t2Eta;   //!
   TBranch        *b_t2FootprintCorrection;   //!
   TBranch        *b_t2FootprintCorrectiondR03;   //!
   TBranch        *b_t2GenCharge;   //!
   TBranch        *b_t2GenDecayMode;   //!
   TBranch        *b_t2GenEnergy;   //!
   TBranch        *b_t2GenEta;   //!
   TBranch        *b_t2GenJetEta;   //!
   TBranch        *b_t2GenJetPt;   //!
   TBranch        *b_t2GenMotherEnergy;   //!
   TBranch        *b_t2GenMotherEta;   //!
   TBranch        *b_t2GenMotherPdgId;   //!
   TBranch        *b_t2GenMotherPhi;   //!
   TBranch        *b_t2GenMotherPt;   //!
   TBranch        *b_t2GenPdgId;   //!
   TBranch        *b_t2GenPhi;   //!
   TBranch        *b_t2GenPt;   //!
   TBranch        *b_t2GenStatus;   //!
   TBranch        *b_t2JetArea;   //!
   TBranch        *b_t2JetBtag;   //!
   TBranch        *b_t2JetDR;   //!
   TBranch        *b_t2JetEtaEtaMoment;   //!
   TBranch        *b_t2JetEtaPhiMoment;   //!
   TBranch        *b_t2JetEtaPhiSpread;   //!
   TBranch        *b_t2JetHadronFlavour;   //!
   TBranch        *b_t2JetPFCISVBtag;   //!
   TBranch        *b_t2JetPartonFlavour;   //!
   TBranch        *b_t2JetPhiPhiMoment;   //!
   TBranch        *b_t2JetPt;   //!
   TBranch        *b_t2L1IsoTauMatch;   //!
   TBranch        *b_t2L1IsoTauPt;   //!
   TBranch        *b_t2LeadTrackPt;   //!
   TBranch        *b_t2LowestMll;   //!
   TBranch        *b_t2Mass;   //!
   TBranch        *b_t2MatchesDoubleMediumTau35Filter;   //!
   TBranch        *b_t2MatchesDoubleMediumTau35Path;   //!
   TBranch        *b_t2MatchesDoubleMediumTau40Filter;   //!
   TBranch        *b_t2MatchesDoubleMediumTau40Path;   //!
   TBranch        *b_t2MatchesDoubleTightTau35Filter;   //!
   TBranch        *b_t2MatchesDoubleTightTau35Path;   //!
   TBranch        *b_t2MatchesDoubleTightTau40Filter;   //!
   TBranch        *b_t2MatchesDoubleTightTau40Path;   //!
   TBranch        *b_t2MatchesEle24Tau30Filter;   //!
   TBranch        *b_t2MatchesEle24Tau30Path;   //!
   TBranch        *b_t2MatchesIsoMu20Tau27Filter;   //!
   TBranch        *b_t2MatchesIsoMu20Tau27Path;   //!
   TBranch        *b_t2NChrgHadrIsolationCands;   //!
   TBranch        *b_t2NChrgHadrSignalCands;   //!
   TBranch        *b_t2NGammaSignalCands;   //!
   TBranch        *b_t2NNeutralHadrSignalCands;   //!
   TBranch        *b_t2NSignalCands;   //!
   TBranch        *b_t2NearestZMass;   //!
   TBranch        *b_t2NeutralIsoPtSum;   //!
   TBranch        *b_t2NeutralIsoPtSumWeight;   //!
   TBranch        *b_t2NeutralIsoPtSumWeightdR03;   //!
   TBranch        *b_t2NeutralIsoPtSumdR03;   //!
   TBranch        *b_t2PVDXY;   //!
   TBranch        *b_t2PVDZ;   //!
   TBranch        *b_t2Phi;   //!
   TBranch        *b_t2PhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_t2PhotonPtSumOutsideSignalConedR03;   //!
   TBranch        *b_t2Pt;   //!
   TBranch        *b_t2PuCorrPtSum;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTLoose;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTMedium;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTTight;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTVLoose;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTVTight;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTVVTight;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_t2RerunMVArun2v2DBoldDMwLTLoose;   //!
   TBranch        *b_t2RerunMVArun2v2DBoldDMwLTMedium;   //!
   TBranch        *b_t2RerunMVArun2v2DBoldDMwLTTight;   //!
   TBranch        *b_t2RerunMVArun2v2DBoldDMwLTVLoose;   //!
   TBranch        *b_t2RerunMVArun2v2DBoldDMwLTVTight;   //!
   TBranch        *b_t2RerunMVArun2v2DBoldDMwLTVVLoose;   //!
   TBranch        *b_t2RerunMVArun2v2DBoldDMwLTVVTight;   //!
   TBranch        *b_t2RerunMVArun2v2DBoldDMwLTraw;   //!
   TBranch        *b_t2VZ;   //!
   TBranch        *b_t2ZTTGenDR;   //!
   TBranch        *b_t2ZTTGenEta;   //!
   TBranch        *b_t2ZTTGenMatching;   //!
   TBranch        *b_t2ZTTGenPhi;   //!
   TBranch        *b_t2ZTTGenPt;   //!
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

   HTauTauTree_tt(TTree *tree=0);
   virtual ~HTauTauTree_tt();
   virtual void     Init(TTree *tree);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t GetEntries();
   TTree* GetTree();
};


HTauTauTree_tt::HTauTauTree_tt(TTree *tree) : fChain(0) 
{
   Init(tree);
}

HTauTauTree_tt::~HTauTauTree_tt() {}

Int_t HTauTauTree_tt::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HTauTauTree_tt::GetEntries()
{
  return fChain->GetEntries();
}
TTree* HTauTauTree_tt::GetTree()
{
  return fChain;
}

void HTauTauTree_tt::Init(TTree *tree)
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
   fChain->SetBranchAddress("eVetoMVAIso", &eVetoMVAIso, &b_eVetoMVAIso);
   fChain->SetBranchAddress("eVetoZTTp001dxyz", &eVetoZTTp001dxyz, &b_eVetoZTTp001dxyz);
   fChain->SetBranchAddress("eVetoZTTp001dxyzR0", &eVetoZTTp001dxyzR0, &b_eVetoZTTp001dxyzR0);
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
   fChain->SetBranchAddress("t1AgainstElectronLooseMVA6", &t1AgainstElectronLooseMVA6, &b_t1AgainstElectronLooseMVA6);
   fChain->SetBranchAddress("t1AgainstElectronMVA6Raw", &t1AgainstElectronMVA6Raw, &b_t1AgainstElectronMVA6Raw);
   fChain->SetBranchAddress("t1AgainstElectronMVA6category", &t1AgainstElectronMVA6category, &b_t1AgainstElectronMVA6category);
   fChain->SetBranchAddress("t1AgainstElectronMediumMVA6", &t1AgainstElectronMediumMVA6, &b_t1AgainstElectronMediumMVA6);
   fChain->SetBranchAddress("t1AgainstElectronTightMVA6", &t1AgainstElectronTightMVA6, &b_t1AgainstElectronTightMVA6);
   fChain->SetBranchAddress("t1AgainstElectronVLooseMVA6", &t1AgainstElectronVLooseMVA6, &b_t1AgainstElectronVLooseMVA6);
   fChain->SetBranchAddress("t1AgainstElectronVTightMVA6", &t1AgainstElectronVTightMVA6, &b_t1AgainstElectronVTightMVA6);
   fChain->SetBranchAddress("t1AgainstMuonLoose3", &t1AgainstMuonLoose3, &b_t1AgainstMuonLoose3);
   fChain->SetBranchAddress("t1AgainstMuonTight3", &t1AgainstMuonTight3, &b_t1AgainstMuonTight3);
   fChain->SetBranchAddress("t1ByCombinedIsolationDeltaBetaCorrRaw3Hits", &t1ByCombinedIsolationDeltaBetaCorrRaw3Hits, &b_t1ByCombinedIsolationDeltaBetaCorrRaw3Hits);
   fChain->SetBranchAddress("t1ByIsolationMVArun2v1DBdR03oldDMwLTraw", &t1ByIsolationMVArun2v1DBdR03oldDMwLTraw, &b_t1ByIsolationMVArun2v1DBdR03oldDMwLTraw);
   fChain->SetBranchAddress("t1ByIsolationMVArun2v1DBnewDMwLTraw", &t1ByIsolationMVArun2v1DBnewDMwLTraw, &b_t1ByIsolationMVArun2v1DBnewDMwLTraw);
   fChain->SetBranchAddress("t1ByIsolationMVArun2v1DBoldDMwLTraw", &t1ByIsolationMVArun2v1DBoldDMwLTraw, &b_t1ByIsolationMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("t1ByLooseCombinedIsolationDeltaBetaCorr3Hits", &t1ByLooseCombinedIsolationDeltaBetaCorr3Hits, &b_t1ByLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT", &t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1DBnewDMwLT", &t1ByLooseIsolationMVArun2v1DBnewDMwLT, &b_t1ByLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1DBoldDMwLT", &t1ByLooseIsolationMVArun2v1DBoldDMwLT, &b_t1ByLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByMediumCombinedIsolationDeltaBetaCorr3Hits", &t1ByMediumCombinedIsolationDeltaBetaCorr3Hits, &b_t1ByMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT", &t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1DBnewDMwLT", &t1ByMediumIsolationMVArun2v1DBnewDMwLT, &b_t1ByMediumIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1DBoldDMwLT", &t1ByMediumIsolationMVArun2v1DBoldDMwLT, &b_t1ByMediumIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByPhotonPtSumOutsideSignalCone", &t1ByPhotonPtSumOutsideSignalCone, &b_t1ByPhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("t1ByTightCombinedIsolationDeltaBetaCorr3Hits", &t1ByTightCombinedIsolationDeltaBetaCorr3Hits, &b_t1ByTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1DBdR03oldDMwLT", &t1ByTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1DBnewDMwLT", &t1ByTightIsolationMVArun2v1DBnewDMwLT, &b_t1ByTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1DBoldDMwLT", &t1ByTightIsolationMVArun2v1DBoldDMwLT, &b_t1ByTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT", &t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1DBnewDMwLT", &t1ByVLooseIsolationMVArun2v1DBnewDMwLT, &b_t1ByVLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1DBoldDMwLT", &t1ByVLooseIsolationMVArun2v1DBoldDMwLT, &b_t1ByVLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT", &t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1DBnewDMwLT", &t1ByVTightIsolationMVArun2v1DBnewDMwLT, &b_t1ByVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1DBoldDMwLT", &t1ByVTightIsolationMVArun2v1DBoldDMwLT, &b_t1ByVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT", &t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1DBnewDMwLT", &t1ByVVTightIsolationMVArun2v1DBnewDMwLT, &b_t1ByVVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1DBoldDMwLT", &t1ByVVTightIsolationMVArun2v1DBoldDMwLT, &b_t1ByVVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1Charge", &t1Charge, &b_t1Charge);
   fChain->SetBranchAddress("t1ChargedIsoPtSum", &t1ChargedIsoPtSum, &b_t1ChargedIsoPtSum);
   fChain->SetBranchAddress("t1ChargedIsoPtSumdR03", &t1ChargedIsoPtSumdR03, &b_t1ChargedIsoPtSumdR03);
   fChain->SetBranchAddress("t1ComesFromHiggs", &t1ComesFromHiggs, &b_t1ComesFromHiggs);
   fChain->SetBranchAddress("t1DecayMode", &t1DecayMode, &b_t1DecayMode);
   fChain->SetBranchAddress("t1DecayModeFinding", &t1DecayModeFinding, &b_t1DecayModeFinding);
   fChain->SetBranchAddress("t1DecayModeFindingNewDMs", &t1DecayModeFindingNewDMs, &b_t1DecayModeFindingNewDMs);
   fChain->SetBranchAddress("t1Eta", &t1Eta, &b_t1Eta);
   fChain->SetBranchAddress("t1FootprintCorrection", &t1FootprintCorrection, &b_t1FootprintCorrection);
   fChain->SetBranchAddress("t1FootprintCorrectiondR03", &t1FootprintCorrectiondR03, &b_t1FootprintCorrectiondR03);
   fChain->SetBranchAddress("t1GenCharge", &t1GenCharge, &b_t1GenCharge);
   fChain->SetBranchAddress("t1GenDecayMode", &t1GenDecayMode, &b_t1GenDecayMode);
   fChain->SetBranchAddress("t1GenEnergy", &t1GenEnergy, &b_t1GenEnergy);
   fChain->SetBranchAddress("t1GenEta", &t1GenEta, &b_t1GenEta);
   fChain->SetBranchAddress("t1GenJetEta", &t1GenJetEta, &b_t1GenJetEta);
   fChain->SetBranchAddress("t1GenJetPt", &t1GenJetPt, &b_t1GenJetPt);
   fChain->SetBranchAddress("t1GenMotherEnergy", &t1GenMotherEnergy, &b_t1GenMotherEnergy);
   fChain->SetBranchAddress("t1GenMotherEta", &t1GenMotherEta, &b_t1GenMotherEta);
   fChain->SetBranchAddress("t1GenMotherPdgId", &t1GenMotherPdgId, &b_t1GenMotherPdgId);
   fChain->SetBranchAddress("t1GenMotherPhi", &t1GenMotherPhi, &b_t1GenMotherPhi);
   fChain->SetBranchAddress("t1GenMotherPt", &t1GenMotherPt, &b_t1GenMotherPt);
   fChain->SetBranchAddress("t1GenPdgId", &t1GenPdgId, &b_t1GenPdgId);
   fChain->SetBranchAddress("t1GenPhi", &t1GenPhi, &b_t1GenPhi);
   fChain->SetBranchAddress("t1GenPt", &t1GenPt, &b_t1GenPt);
   fChain->SetBranchAddress("t1GenStatus", &t1GenStatus, &b_t1GenStatus);
   fChain->SetBranchAddress("t1JetArea", &t1JetArea, &b_t1JetArea);
   fChain->SetBranchAddress("t1JetBtag", &t1JetBtag, &b_t1JetBtag);
   fChain->SetBranchAddress("t1JetDR", &t1JetDR, &b_t1JetDR);
   fChain->SetBranchAddress("t1JetEtaEtaMoment", &t1JetEtaEtaMoment, &b_t1JetEtaEtaMoment);
   fChain->SetBranchAddress("t1JetEtaPhiMoment", &t1JetEtaPhiMoment, &b_t1JetEtaPhiMoment);
   fChain->SetBranchAddress("t1JetEtaPhiSpread", &t1JetEtaPhiSpread, &b_t1JetEtaPhiSpread);
   fChain->SetBranchAddress("t1JetHadronFlavour", &t1JetHadronFlavour, &b_t1JetHadronFlavour);
   fChain->SetBranchAddress("t1JetPFCISVBtag", &t1JetPFCISVBtag, &b_t1JetPFCISVBtag);
   fChain->SetBranchAddress("t1JetPartonFlavour", &t1JetPartonFlavour, &b_t1JetPartonFlavour);
   fChain->SetBranchAddress("t1JetPhiPhiMoment", &t1JetPhiPhiMoment, &b_t1JetPhiPhiMoment);
   fChain->SetBranchAddress("t1JetPt", &t1JetPt, &b_t1JetPt);
   fChain->SetBranchAddress("t1L1IsoTauMatch", &t1L1IsoTauMatch, &b_t1L1IsoTauMatch);
   fChain->SetBranchAddress("t1L1IsoTauPt", &t1L1IsoTauPt, &b_t1L1IsoTauPt);
   fChain->SetBranchAddress("t1LeadTrackPt", &t1LeadTrackPt, &b_t1LeadTrackPt);
   fChain->SetBranchAddress("t1LowestMll", &t1LowestMll, &b_t1LowestMll);
   fChain->SetBranchAddress("t1Mass", &t1Mass, &b_t1Mass);
   fChain->SetBranchAddress("t1MatchesDoubleMediumTau35Filter", &t1MatchesDoubleMediumTau35Filter, &b_t1MatchesDoubleMediumTau35Filter);
   fChain->SetBranchAddress("t1MatchesDoubleMediumTau35Path", &t1MatchesDoubleMediumTau35Path, &b_t1MatchesDoubleMediumTau35Path);
   fChain->SetBranchAddress("t1MatchesDoubleMediumTau40Filter", &t1MatchesDoubleMediumTau40Filter, &b_t1MatchesDoubleMediumTau40Filter);
   fChain->SetBranchAddress("t1MatchesDoubleMediumTau40Path", &t1MatchesDoubleMediumTau40Path, &b_t1MatchesDoubleMediumTau40Path);
   fChain->SetBranchAddress("t1MatchesDoubleTightTau35Filter", &t1MatchesDoubleTightTau35Filter, &b_t1MatchesDoubleTightTau35Filter);
   fChain->SetBranchAddress("t1MatchesDoubleTightTau35Path", &t1MatchesDoubleTightTau35Path, &b_t1MatchesDoubleTightTau35Path);
   fChain->SetBranchAddress("t1MatchesDoubleTightTau40Filter", &t1MatchesDoubleTightTau40Filter, &b_t1MatchesDoubleTightTau40Filter);
   fChain->SetBranchAddress("t1MatchesDoubleTightTau40Path", &t1MatchesDoubleTightTau40Path, &b_t1MatchesDoubleTightTau40Path);
   fChain->SetBranchAddress("t1MatchesEle24Tau30Filter", &t1MatchesEle24Tau30Filter, &b_t1MatchesEle24Tau30Filter);
   fChain->SetBranchAddress("t1MatchesEle24Tau30Path", &t1MatchesEle24Tau30Path, &b_t1MatchesEle24Tau30Path);
   fChain->SetBranchAddress("t1MatchesIsoMu20Tau27Filter", &t1MatchesIsoMu20Tau27Filter, &b_t1MatchesIsoMu20Tau27Filter);
   fChain->SetBranchAddress("t1MatchesIsoMu20Tau27Path", &t1MatchesIsoMu20Tau27Path, &b_t1MatchesIsoMu20Tau27Path);
   fChain->SetBranchAddress("t1NChrgHadrIsolationCands", &t1NChrgHadrIsolationCands, &b_t1NChrgHadrIsolationCands);
   fChain->SetBranchAddress("t1NChrgHadrSignalCands", &t1NChrgHadrSignalCands, &b_t1NChrgHadrSignalCands);
   fChain->SetBranchAddress("t1NGammaSignalCands", &t1NGammaSignalCands, &b_t1NGammaSignalCands);
   fChain->SetBranchAddress("t1NNeutralHadrSignalCands", &t1NNeutralHadrSignalCands, &b_t1NNeutralHadrSignalCands);
   fChain->SetBranchAddress("t1NSignalCands", &t1NSignalCands, &b_t1NSignalCands);
   fChain->SetBranchAddress("t1NearestZMass", &t1NearestZMass, &b_t1NearestZMass);
   fChain->SetBranchAddress("t1NeutralIsoPtSum", &t1NeutralIsoPtSum, &b_t1NeutralIsoPtSum);
   fChain->SetBranchAddress("t1NeutralIsoPtSumWeight", &t1NeutralIsoPtSumWeight, &b_t1NeutralIsoPtSumWeight);
   fChain->SetBranchAddress("t1NeutralIsoPtSumWeightdR03", &t1NeutralIsoPtSumWeightdR03, &b_t1NeutralIsoPtSumWeightdR03);
   fChain->SetBranchAddress("t1NeutralIsoPtSumdR03", &t1NeutralIsoPtSumdR03, &b_t1NeutralIsoPtSumdR03);
   fChain->SetBranchAddress("t1PVDXY", &t1PVDXY, &b_t1PVDXY);
   fChain->SetBranchAddress("t1PVDZ", &t1PVDZ, &b_t1PVDZ);
   fChain->SetBranchAddress("t1Phi", &t1Phi, &b_t1Phi);
   fChain->SetBranchAddress("t1PhotonPtSumOutsideSignalCone", &t1PhotonPtSumOutsideSignalCone, &b_t1PhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("t1PhotonPtSumOutsideSignalConedR03", &t1PhotonPtSumOutsideSignalConedR03, &b_t1PhotonPtSumOutsideSignalConedR03);
   fChain->SetBranchAddress("t1Pt", &t1Pt, &b_t1Pt);
   fChain->SetBranchAddress("t1PuCorrPtSum", &t1PuCorrPtSum, &b_t1PuCorrPtSum);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTLoose", &t1RerunMVArun2v1DBoldDMwLTLoose, &b_t1RerunMVArun2v1DBoldDMwLTLoose);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTMedium", &t1RerunMVArun2v1DBoldDMwLTMedium, &b_t1RerunMVArun2v1DBoldDMwLTMedium);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTTight", &t1RerunMVArun2v1DBoldDMwLTTight, &b_t1RerunMVArun2v1DBoldDMwLTTight);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTVLoose", &t1RerunMVArun2v1DBoldDMwLTVLoose, &b_t1RerunMVArun2v1DBoldDMwLTVLoose);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTVTight", &t1RerunMVArun2v1DBoldDMwLTVTight, &b_t1RerunMVArun2v1DBoldDMwLTVTight);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTVVTight", &t1RerunMVArun2v1DBoldDMwLTVVTight, &b_t1RerunMVArun2v1DBoldDMwLTVVTight);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTraw", &t1RerunMVArun2v1DBoldDMwLTraw, &b_t1RerunMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("t1RerunMVArun2v2DBoldDMwLTLoose", &t1RerunMVArun2v2DBoldDMwLTLoose, &b_t1RerunMVArun2v2DBoldDMwLTLoose);
   fChain->SetBranchAddress("t1RerunMVArun2v2DBoldDMwLTMedium", &t1RerunMVArun2v2DBoldDMwLTMedium, &b_t1RerunMVArun2v2DBoldDMwLTMedium);
   fChain->SetBranchAddress("t1RerunMVArun2v2DBoldDMwLTTight", &t1RerunMVArun2v2DBoldDMwLTTight, &b_t1RerunMVArun2v2DBoldDMwLTTight);
   fChain->SetBranchAddress("t1RerunMVArun2v2DBoldDMwLTVLoose", &t1RerunMVArun2v2DBoldDMwLTVLoose, &b_t1RerunMVArun2v2DBoldDMwLTVLoose);
   fChain->SetBranchAddress("t1RerunMVArun2v2DBoldDMwLTVTight", &t1RerunMVArun2v2DBoldDMwLTVTight, &b_t1RerunMVArun2v2DBoldDMwLTVTight);
   fChain->SetBranchAddress("t1RerunMVArun2v2DBoldDMwLTVVLoose", &t1RerunMVArun2v2DBoldDMwLTVVLoose, &b_t1RerunMVArun2v2DBoldDMwLTVVLoose);
   fChain->SetBranchAddress("t1RerunMVArun2v2DBoldDMwLTVVTight", &t1RerunMVArun2v2DBoldDMwLTVVTight, &b_t1RerunMVArun2v2DBoldDMwLTVVTight);
   fChain->SetBranchAddress("t1RerunMVArun2v2DBoldDMwLTraw", &t1RerunMVArun2v2DBoldDMwLTraw, &b_t1RerunMVArun2v2DBoldDMwLTraw);
   fChain->SetBranchAddress("t1VZ", &t1VZ, &b_t1VZ);
   fChain->SetBranchAddress("t1ZTTGenDR", &t1ZTTGenDR, &b_t1ZTTGenDR);
   fChain->SetBranchAddress("t1ZTTGenEta", &t1ZTTGenEta, &b_t1ZTTGenEta);
   fChain->SetBranchAddress("t1ZTTGenMatching", &t1ZTTGenMatching, &b_t1ZTTGenMatching);
   fChain->SetBranchAddress("t1ZTTGenPhi", &t1ZTTGenPhi, &b_t1ZTTGenPhi);
   fChain->SetBranchAddress("t1ZTTGenPt", &t1ZTTGenPt, &b_t1ZTTGenPt);
   fChain->SetBranchAddress("t1_t2_doubleL1IsoTauMatch", &t1_t2_doubleL1IsoTauMatch, &b_t1_t2_doubleL1IsoTauMatch);
   fChain->SetBranchAddress("t2AgainstElectronLooseMVA6", &t2AgainstElectronLooseMVA6, &b_t2AgainstElectronLooseMVA6);
   fChain->SetBranchAddress("t2AgainstElectronMVA6Raw", &t2AgainstElectronMVA6Raw, &b_t2AgainstElectronMVA6Raw);
   fChain->SetBranchAddress("t2AgainstElectronMVA6category", &t2AgainstElectronMVA6category, &b_t2AgainstElectronMVA6category);
   fChain->SetBranchAddress("t2AgainstElectronMediumMVA6", &t2AgainstElectronMediumMVA6, &b_t2AgainstElectronMediumMVA6);
   fChain->SetBranchAddress("t2AgainstElectronTightMVA6", &t2AgainstElectronTightMVA6, &b_t2AgainstElectronTightMVA6);
   fChain->SetBranchAddress("t2AgainstElectronVLooseMVA6", &t2AgainstElectronVLooseMVA6, &b_t2AgainstElectronVLooseMVA6);
   fChain->SetBranchAddress("t2AgainstElectronVTightMVA6", &t2AgainstElectronVTightMVA6, &b_t2AgainstElectronVTightMVA6);
   fChain->SetBranchAddress("t2AgainstMuonLoose3", &t2AgainstMuonLoose3, &b_t2AgainstMuonLoose3);
   fChain->SetBranchAddress("t2AgainstMuonTight3", &t2AgainstMuonTight3, &b_t2AgainstMuonTight3);
   fChain->SetBranchAddress("t2ByCombinedIsolationDeltaBetaCorrRaw3Hits", &t2ByCombinedIsolationDeltaBetaCorrRaw3Hits, &b_t2ByCombinedIsolationDeltaBetaCorrRaw3Hits);
   fChain->SetBranchAddress("t2ByIsolationMVArun2v1DBdR03oldDMwLTraw", &t2ByIsolationMVArun2v1DBdR03oldDMwLTraw, &b_t2ByIsolationMVArun2v1DBdR03oldDMwLTraw);
   fChain->SetBranchAddress("t2ByIsolationMVArun2v1DBnewDMwLTraw", &t2ByIsolationMVArun2v1DBnewDMwLTraw, &b_t2ByIsolationMVArun2v1DBnewDMwLTraw);
   fChain->SetBranchAddress("t2ByIsolationMVArun2v1DBoldDMwLTraw", &t2ByIsolationMVArun2v1DBoldDMwLTraw, &b_t2ByIsolationMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("t2ByLooseCombinedIsolationDeltaBetaCorr3Hits", &t2ByLooseCombinedIsolationDeltaBetaCorr3Hits, &b_t2ByLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT", &t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1DBnewDMwLT", &t2ByLooseIsolationMVArun2v1DBnewDMwLT, &b_t2ByLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1DBoldDMwLT", &t2ByLooseIsolationMVArun2v1DBoldDMwLT, &b_t2ByLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByMediumCombinedIsolationDeltaBetaCorr3Hits", &t2ByMediumCombinedIsolationDeltaBetaCorr3Hits, &b_t2ByMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT", &t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1DBnewDMwLT", &t2ByMediumIsolationMVArun2v1DBnewDMwLT, &b_t2ByMediumIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1DBoldDMwLT", &t2ByMediumIsolationMVArun2v1DBoldDMwLT, &b_t2ByMediumIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByPhotonPtSumOutsideSignalCone", &t2ByPhotonPtSumOutsideSignalCone, &b_t2ByPhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("t2ByTightCombinedIsolationDeltaBetaCorr3Hits", &t2ByTightCombinedIsolationDeltaBetaCorr3Hits, &b_t2ByTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1DBdR03oldDMwLT", &t2ByTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1DBnewDMwLT", &t2ByTightIsolationMVArun2v1DBnewDMwLT, &b_t2ByTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1DBoldDMwLT", &t2ByTightIsolationMVArun2v1DBoldDMwLT, &b_t2ByTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT", &t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1DBnewDMwLT", &t2ByVLooseIsolationMVArun2v1DBnewDMwLT, &b_t2ByVLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1DBoldDMwLT", &t2ByVLooseIsolationMVArun2v1DBoldDMwLT, &b_t2ByVLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT", &t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1DBnewDMwLT", &t2ByVTightIsolationMVArun2v1DBnewDMwLT, &b_t2ByVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1DBoldDMwLT", &t2ByVTightIsolationMVArun2v1DBoldDMwLT, &b_t2ByVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT", &t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1DBnewDMwLT", &t2ByVVTightIsolationMVArun2v1DBnewDMwLT, &b_t2ByVVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1DBoldDMwLT", &t2ByVVTightIsolationMVArun2v1DBoldDMwLT, &b_t2ByVVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2Charge", &t2Charge, &b_t2Charge);
   fChain->SetBranchAddress("t2ChargedIsoPtSum", &t2ChargedIsoPtSum, &b_t2ChargedIsoPtSum);
   fChain->SetBranchAddress("t2ChargedIsoPtSumdR03", &t2ChargedIsoPtSumdR03, &b_t2ChargedIsoPtSumdR03);
   fChain->SetBranchAddress("t2ComesFromHiggs", &t2ComesFromHiggs, &b_t2ComesFromHiggs);
   fChain->SetBranchAddress("t2DecayMode", &t2DecayMode, &b_t2DecayMode);
   fChain->SetBranchAddress("t2DecayModeFinding", &t2DecayModeFinding, &b_t2DecayModeFinding);
   fChain->SetBranchAddress("t2DecayModeFindingNewDMs", &t2DecayModeFindingNewDMs, &b_t2DecayModeFindingNewDMs);
   fChain->SetBranchAddress("t2Eta", &t2Eta, &b_t2Eta);
   fChain->SetBranchAddress("t2FootprintCorrection", &t2FootprintCorrection, &b_t2FootprintCorrection);
   fChain->SetBranchAddress("t2FootprintCorrectiondR03", &t2FootprintCorrectiondR03, &b_t2FootprintCorrectiondR03);
   fChain->SetBranchAddress("t2GenCharge", &t2GenCharge, &b_t2GenCharge);
   fChain->SetBranchAddress("t2GenDecayMode", &t2GenDecayMode, &b_t2GenDecayMode);
   fChain->SetBranchAddress("t2GenEnergy", &t2GenEnergy, &b_t2GenEnergy);
   fChain->SetBranchAddress("t2GenEta", &t2GenEta, &b_t2GenEta);
   fChain->SetBranchAddress("t2GenJetEta", &t2GenJetEta, &b_t2GenJetEta);
   fChain->SetBranchAddress("t2GenJetPt", &t2GenJetPt, &b_t2GenJetPt);
   fChain->SetBranchAddress("t2GenMotherEnergy", &t2GenMotherEnergy, &b_t2GenMotherEnergy);
   fChain->SetBranchAddress("t2GenMotherEta", &t2GenMotherEta, &b_t2GenMotherEta);
   fChain->SetBranchAddress("t2GenMotherPdgId", &t2GenMotherPdgId, &b_t2GenMotherPdgId);
   fChain->SetBranchAddress("t2GenMotherPhi", &t2GenMotherPhi, &b_t2GenMotherPhi);
   fChain->SetBranchAddress("t2GenMotherPt", &t2GenMotherPt, &b_t2GenMotherPt);
   fChain->SetBranchAddress("t2GenPdgId", &t2GenPdgId, &b_t2GenPdgId);
   fChain->SetBranchAddress("t2GenPhi", &t2GenPhi, &b_t2GenPhi);
   fChain->SetBranchAddress("t2GenPt", &t2GenPt, &b_t2GenPt);
   fChain->SetBranchAddress("t2GenStatus", &t2GenStatus, &b_t2GenStatus);
   fChain->SetBranchAddress("t2JetArea", &t2JetArea, &b_t2JetArea);
   fChain->SetBranchAddress("t2JetBtag", &t2JetBtag, &b_t2JetBtag);
   fChain->SetBranchAddress("t2JetDR", &t2JetDR, &b_t2JetDR);
   fChain->SetBranchAddress("t2JetEtaEtaMoment", &t2JetEtaEtaMoment, &b_t2JetEtaEtaMoment);
   fChain->SetBranchAddress("t2JetEtaPhiMoment", &t2JetEtaPhiMoment, &b_t2JetEtaPhiMoment);
   fChain->SetBranchAddress("t2JetEtaPhiSpread", &t2JetEtaPhiSpread, &b_t2JetEtaPhiSpread);
   fChain->SetBranchAddress("t2JetHadronFlavour", &t2JetHadronFlavour, &b_t2JetHadronFlavour);
   fChain->SetBranchAddress("t2JetPFCISVBtag", &t2JetPFCISVBtag, &b_t2JetPFCISVBtag);
   fChain->SetBranchAddress("t2JetPartonFlavour", &t2JetPartonFlavour, &b_t2JetPartonFlavour);
   fChain->SetBranchAddress("t2JetPhiPhiMoment", &t2JetPhiPhiMoment, &b_t2JetPhiPhiMoment);
   fChain->SetBranchAddress("t2JetPt", &t2JetPt, &b_t2JetPt);
   fChain->SetBranchAddress("t2L1IsoTauMatch", &t2L1IsoTauMatch, &b_t2L1IsoTauMatch);
   fChain->SetBranchAddress("t2L1IsoTauPt", &t2L1IsoTauPt, &b_t2L1IsoTauPt);
   fChain->SetBranchAddress("t2LeadTrackPt", &t2LeadTrackPt, &b_t2LeadTrackPt);
   fChain->SetBranchAddress("t2LowestMll", &t2LowestMll, &b_t2LowestMll);
   fChain->SetBranchAddress("t2Mass", &t2Mass, &b_t2Mass);
   fChain->SetBranchAddress("t2MatchesDoubleMediumTau35Filter", &t2MatchesDoubleMediumTau35Filter, &b_t2MatchesDoubleMediumTau35Filter);
   fChain->SetBranchAddress("t2MatchesDoubleMediumTau35Path", &t2MatchesDoubleMediumTau35Path, &b_t2MatchesDoubleMediumTau35Path);
   fChain->SetBranchAddress("t2MatchesDoubleMediumTau40Filter", &t2MatchesDoubleMediumTau40Filter, &b_t2MatchesDoubleMediumTau40Filter);
   fChain->SetBranchAddress("t2MatchesDoubleMediumTau40Path", &t2MatchesDoubleMediumTau40Path, &b_t2MatchesDoubleMediumTau40Path);
   fChain->SetBranchAddress("t2MatchesDoubleTightTau35Filter", &t2MatchesDoubleTightTau35Filter, &b_t2MatchesDoubleTightTau35Filter);
   fChain->SetBranchAddress("t2MatchesDoubleTightTau35Path", &t2MatchesDoubleTightTau35Path, &b_t2MatchesDoubleTightTau35Path);
   fChain->SetBranchAddress("t2MatchesDoubleTightTau40Filter", &t2MatchesDoubleTightTau40Filter, &b_t2MatchesDoubleTightTau40Filter);
   fChain->SetBranchAddress("t2MatchesDoubleTightTau40Path", &t2MatchesDoubleTightTau40Path, &b_t2MatchesDoubleTightTau40Path);
   fChain->SetBranchAddress("t2MatchesEle24Tau30Filter", &t2MatchesEle24Tau30Filter, &b_t2MatchesEle24Tau30Filter);
   fChain->SetBranchAddress("t2MatchesEle24Tau30Path", &t2MatchesEle24Tau30Path, &b_t2MatchesEle24Tau30Path);
   fChain->SetBranchAddress("t2MatchesIsoMu20Tau27Filter", &t2MatchesIsoMu20Tau27Filter, &b_t2MatchesIsoMu20Tau27Filter);
   fChain->SetBranchAddress("t2MatchesIsoMu20Tau27Path", &t2MatchesIsoMu20Tau27Path, &b_t2MatchesIsoMu20Tau27Path);
   fChain->SetBranchAddress("t2NChrgHadrIsolationCands", &t2NChrgHadrIsolationCands, &b_t2NChrgHadrIsolationCands);
   fChain->SetBranchAddress("t2NChrgHadrSignalCands", &t2NChrgHadrSignalCands, &b_t2NChrgHadrSignalCands);
   fChain->SetBranchAddress("t2NGammaSignalCands", &t2NGammaSignalCands, &b_t2NGammaSignalCands);
   fChain->SetBranchAddress("t2NNeutralHadrSignalCands", &t2NNeutralHadrSignalCands, &b_t2NNeutralHadrSignalCands);
   fChain->SetBranchAddress("t2NSignalCands", &t2NSignalCands, &b_t2NSignalCands);
   fChain->SetBranchAddress("t2NearestZMass", &t2NearestZMass, &b_t2NearestZMass);
   fChain->SetBranchAddress("t2NeutralIsoPtSum", &t2NeutralIsoPtSum, &b_t2NeutralIsoPtSum);
   fChain->SetBranchAddress("t2NeutralIsoPtSumWeight", &t2NeutralIsoPtSumWeight, &b_t2NeutralIsoPtSumWeight);
   fChain->SetBranchAddress("t2NeutralIsoPtSumWeightdR03", &t2NeutralIsoPtSumWeightdR03, &b_t2NeutralIsoPtSumWeightdR03);
   fChain->SetBranchAddress("t2NeutralIsoPtSumdR03", &t2NeutralIsoPtSumdR03, &b_t2NeutralIsoPtSumdR03);
   fChain->SetBranchAddress("t2PVDXY", &t2PVDXY, &b_t2PVDXY);
   fChain->SetBranchAddress("t2PVDZ", &t2PVDZ, &b_t2PVDZ);
   fChain->SetBranchAddress("t2Phi", &t2Phi, &b_t2Phi);
   fChain->SetBranchAddress("t2PhotonPtSumOutsideSignalCone", &t2PhotonPtSumOutsideSignalCone, &b_t2PhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("t2PhotonPtSumOutsideSignalConedR03", &t2PhotonPtSumOutsideSignalConedR03, &b_t2PhotonPtSumOutsideSignalConedR03);
   fChain->SetBranchAddress("t2Pt", &t2Pt, &b_t2Pt);
   fChain->SetBranchAddress("t2PuCorrPtSum", &t2PuCorrPtSum, &b_t2PuCorrPtSum);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTLoose", &t2RerunMVArun2v1DBoldDMwLTLoose, &b_t2RerunMVArun2v1DBoldDMwLTLoose);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTMedium", &t2RerunMVArun2v1DBoldDMwLTMedium, &b_t2RerunMVArun2v1DBoldDMwLTMedium);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTTight", &t2RerunMVArun2v1DBoldDMwLTTight, &b_t2RerunMVArun2v1DBoldDMwLTTight);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTVLoose", &t2RerunMVArun2v1DBoldDMwLTVLoose, &b_t2RerunMVArun2v1DBoldDMwLTVLoose);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTVTight", &t2RerunMVArun2v1DBoldDMwLTVTight, &b_t2RerunMVArun2v1DBoldDMwLTVTight);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTVVTight", &t2RerunMVArun2v1DBoldDMwLTVVTight, &b_t2RerunMVArun2v1DBoldDMwLTVVTight);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTraw", &t2RerunMVArun2v1DBoldDMwLTraw, &b_t2RerunMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("t2RerunMVArun2v2DBoldDMwLTLoose", &t2RerunMVArun2v2DBoldDMwLTLoose, &b_t2RerunMVArun2v2DBoldDMwLTLoose);
   fChain->SetBranchAddress("t2RerunMVArun2v2DBoldDMwLTMedium", &t2RerunMVArun2v2DBoldDMwLTMedium, &b_t2RerunMVArun2v2DBoldDMwLTMedium);
   fChain->SetBranchAddress("t2RerunMVArun2v2DBoldDMwLTTight", &t2RerunMVArun2v2DBoldDMwLTTight, &b_t2RerunMVArun2v2DBoldDMwLTTight);
   fChain->SetBranchAddress("t2RerunMVArun2v2DBoldDMwLTVLoose", &t2RerunMVArun2v2DBoldDMwLTVLoose, &b_t2RerunMVArun2v2DBoldDMwLTVLoose);
   fChain->SetBranchAddress("t2RerunMVArun2v2DBoldDMwLTVTight", &t2RerunMVArun2v2DBoldDMwLTVTight, &b_t2RerunMVArun2v2DBoldDMwLTVTight);
   fChain->SetBranchAddress("t2RerunMVArun2v2DBoldDMwLTVVLoose", &t2RerunMVArun2v2DBoldDMwLTVVLoose, &b_t2RerunMVArun2v2DBoldDMwLTVVLoose);
   fChain->SetBranchAddress("t2RerunMVArun2v2DBoldDMwLTVVTight", &t2RerunMVArun2v2DBoldDMwLTVVTight, &b_t2RerunMVArun2v2DBoldDMwLTVVTight);
   fChain->SetBranchAddress("t2RerunMVArun2v2DBoldDMwLTraw", &t2RerunMVArun2v2DBoldDMwLTraw, &b_t2RerunMVArun2v2DBoldDMwLTraw);
   fChain->SetBranchAddress("t2VZ", &t2VZ, &b_t2VZ);
   fChain->SetBranchAddress("t2ZTTGenDR", &t2ZTTGenDR, &b_t2ZTTGenDR);
   fChain->SetBranchAddress("t2ZTTGenEta", &t2ZTTGenEta, &b_t2ZTTGenEta);
   fChain->SetBranchAddress("t2ZTTGenMatching", &t2ZTTGenMatching, &b_t2ZTTGenMatching);
   fChain->SetBranchAddress("t2ZTTGenPhi", &t2ZTTGenPhi, &b_t2ZTTGenPhi);
   fChain->SetBranchAddress("t2ZTTGenPt", &t2ZTTGenPt, &b_t2ZTTGenPt);
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


#endif // #ifdef HTauTauTree_tt_cxx
