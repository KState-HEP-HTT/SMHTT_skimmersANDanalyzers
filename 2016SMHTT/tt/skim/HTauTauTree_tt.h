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
   Float_t         t1AbsEta;
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
   Float_t         t1ByIsolationMVArun2v1PWdR03oldDMwLTraw;
   Float_t         t1ByIsolationMVArun2v1PWnewDMwLTraw;
   Float_t         t1ByIsolationMVArun2v1PWoldDMwLTraw;
   Float_t         t1ByLooseCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByLooseIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t1ByLooseIsolationMVArun2v1PWnewDMwLT;
   Float_t         t1ByLooseIsolationMVArun2v1PWoldDMwLT;
   Float_t         t1ByMediumCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByMediumIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByMediumIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByMediumIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t1ByMediumIsolationMVArun2v1PWnewDMwLT;
   Float_t         t1ByMediumIsolationMVArun2v1PWoldDMwLT;
   Float_t         t1ByPhotonPtSumOutsideSignalCone;
   Float_t         t1ByTightCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t1ByTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t1ByTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         t1ByTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1PWnewDMwLT;
   Float_t         t1ByVLooseIsolationMVArun2v1PWoldDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         t1ByVTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         t1ByVVTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         t1Charge;
   Float_t         t1ChargedIsoPtSum;
   Float_t         t1ChargedIsoPtSumdR03;
   Float_t         t1ComesFromHiggs;
   Float_t         t1DPhiToPfMet_ElectronEnDown;
   Float_t         t1DPhiToPfMet_ElectronEnUp;
   Float_t         t1DPhiToPfMet_JetEnDown;
   Float_t         t1DPhiToPfMet_JetEnUp;
   Float_t         t1DPhiToPfMet_JetResDown;
   Float_t         t1DPhiToPfMet_JetResUp;
   Float_t         t1DPhiToPfMet_MuonEnDown;
   Float_t         t1DPhiToPfMet_MuonEnUp;
   Float_t         t1DPhiToPfMet_PhotonEnDown;
   Float_t         t1DPhiToPfMet_PhotonEnUp;
   Float_t         t1DPhiToPfMet_TauEnDown;
   Float_t         t1DPhiToPfMet_TauEnUp;
   Float_t         t1DPhiToPfMet_UnclusteredEnDown;
   Float_t         t1DPhiToPfMet_UnclusteredEnUp;
   Float_t         t1DPhiToPfMet_type1;
   Float_t         t1DecayMode;
   Float_t         t1DecayModeFinding;
   Float_t         t1DecayModeFindingNewDMs;
   Float_t         t1ElecOverlap;
   Float_t         t1Eta;
   Float_t         t1Eta_TauEnDown;
   Float_t         t1Eta_TauEnUp;
   Float_t         t1FootprintCorrection;
   Float_t         t1FootprintCorrectiondR03;
   Float_t         t1GenCharge;
   Float_t         t1GenDecayMode;
   Float_t         t1GenEnergy;
   Float_t         t1GenEta;
   Float_t         t1GenIsPrompt;
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
   Float_t         t1GlobalMuonVtxOverlap;
   Float_t         t1JetArea;
   Float_t         t1JetBtag;
   Float_t         t1JetEtaEtaMoment;
   Float_t         t1JetEtaPhiMoment;
   Float_t         t1JetEtaPhiSpread;
   Float_t         t1JetHadronFlavour;
   Float_t         t1JetPFCISVBtag;
   Float_t         t1JetPartonFlavour;
   Float_t         t1JetPhiPhiMoment;
   Float_t         t1JetPt;
   Float_t         t1LeadTrackPt;
   Float_t         t1LowestMll;
   Float_t         t1Mass;
   Float_t         t1Mass_TauEnDown;
   Float_t         t1Mass_TauEnUp;
   Float_t         t1MatchesDoubleTau32Filter;
   Float_t         t1MatchesDoubleTau32Path;
   Float_t         t1MatchesDoubleTau35Filter;
   Float_t         t1MatchesDoubleTau35Path;
   Float_t         t1MatchesDoubleTau40Filter;
   Float_t         t1MatchesDoubleTau40Path;
   Float_t         t1MatchesDoubleTauCmbIso35RegFilter;
   Float_t         t1MatchesDoubleTauCmbIso35RegPath;
   Float_t         t1MatchesDoubleTauCmbIso40Filter;
   Float_t         t1MatchesDoubleTauCmbIso40Path;
   Float_t         t1MatchesDoubleTauCmbIso40RegFilter;
   Float_t         t1MatchesDoubleTauCmbIso40RegPath;
   Float_t         t1MatchesEle24Tau20Filter;
   Float_t         t1MatchesEle24Tau20L1Path;
   Float_t         t1MatchesEle24Tau20Path;
   Float_t         t1MatchesEle24Tau20sL1Filter;
   Float_t         t1MatchesEle24Tau30Filter;
   Float_t         t1MatchesEle24Tau30Path;
   Float_t         t1MatchesMu19Tau20Filter;
   Float_t         t1MatchesMu19Tau20Path;
   Float_t         t1MatchesMu19Tau20sL1Filter;
   Float_t         t1MatchesMu19Tau20sL1Path;
   Float_t         t1MatchesMu21Tau20sL1Filter;
   Float_t         t1MatchesMu21Tau20sL1Path;
   Float_t         t1MtToPfMet_ElectronEnDown;
   Float_t         t1MtToPfMet_ElectronEnUp;
   Float_t         t1MtToPfMet_JetEnDown;
   Float_t         t1MtToPfMet_JetEnUp;
   Float_t         t1MtToPfMet_JetResDown;
   Float_t         t1MtToPfMet_JetResUp;
   Float_t         t1MtToPfMet_MuonEnDown;
   Float_t         t1MtToPfMet_MuonEnUp;
   Float_t         t1MtToPfMet_PhotonEnDown;
   Float_t         t1MtToPfMet_PhotonEnUp;
   Float_t         t1MtToPfMet_Raw;
   Float_t         t1MtToPfMet_TauEnDown;
   Float_t         t1MtToPfMet_TauEnUp;
   Float_t         t1MtToPfMet_UnclusteredEnDown;
   Float_t         t1MtToPfMet_UnclusteredEnUp;
   Float_t         t1MtToPfMet_type1;
   Float_t         t1MuOverlap;
   Float_t         t1MuonIdIsoStdVtxOverlap;
   Float_t         t1MuonIdIsoVtxOverlap;
   Float_t         t1MuonIdVtxOverlap;
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
   Float_t         t1Phi_TauEnDown;
   Float_t         t1Phi_TauEnUp;
   Float_t         t1PhotonPtSumOutsideSignalCone;
   Float_t         t1PhotonPtSumOutsideSignalConedR03;
   Float_t         t1Pt;
   Float_t         t1Pt_TauEnDown;
   Float_t         t1Pt_TauEnUp;
   Float_t         t1PuCorrPtSum;
   Float_t         t1Rank;
   Float_t         t1RerunMVArun2v1DBoldDMwLTLoose;
   Float_t         t1RerunMVArun2v1DBoldDMwLTMedium;
   Float_t         t1RerunMVArun2v1DBoldDMwLTTight;
   Float_t         t1RerunMVArun2v1DBoldDMwLTVLoose;
   Float_t         t1RerunMVArun2v1DBoldDMwLTVTight;
   Float_t         t1RerunMVArun2v1DBoldDMwLTVVTight;
   Float_t         t1RerunMVArun2v1DBoldDMwLTraw;
   Float_t         t1VZ;
   Float_t         t1ZTTGenDR;
   Float_t         t1ZTTGenEta;
   Float_t         t1ZTTGenMatching;
   Float_t         t1ZTTGenPhi;
   Float_t         t1ZTTGenPt;
   Float_t         t1_t2_CosThetaStar;
   Float_t         t1_t2_DPhi;
   Float_t         t1_t2_DR;
   Float_t         t1_t2_Eta;
   Float_t         t1_t2_Mass;
   Float_t         t1_t2_Mass_TauEnDown;
   Float_t         t1_t2_Mass_TauEnUp;
   Float_t         t1_t2_Mt;
   Float_t         t1_t2_MtTotal;
   Float_t         t1_t2_Mt_TauEnDown;
   Float_t         t1_t2_Mt_TauEnUp;
   Float_t         t1_t2_MvaMet;
   Float_t         t1_t2_MvaMetCovMatrix00;
   Float_t         t1_t2_MvaMetCovMatrix01;
   Float_t         t1_t2_MvaMetCovMatrix10;
   Float_t         t1_t2_MvaMetCovMatrix11;
   Float_t         t1_t2_MvaMetPhi;
   Float_t         t1_t2_PZeta;
   Float_t         t1_t2_PZetaLess0p85PZetaVis;
   Float_t         t1_t2_PZetaVis;
   Float_t         t1_t2_Phi;
   Float_t         t1_t2_Pt;
   Float_t         t1_t2_SS;
   Float_t         t1_t2_ToMETDPhi_Ty1;
   Float_t         t1_t2_collinearmass;
   Float_t         t1_t2_collinearmass_EleEnDown;
   Float_t         t1_t2_collinearmass_EleEnUp;
   Float_t         t1_t2_collinearmass_JetEnDown;
   Float_t         t1_t2_collinearmass_JetEnUp;
   Float_t         t1_t2_collinearmass_MuEnDown;
   Float_t         t1_t2_collinearmass_MuEnUp;
   Float_t         t1_t2_collinearmass_TauEnDown;
   Float_t         t1_t2_collinearmass_TauEnUp;
   Float_t         t1_t2_collinearmass_UnclusteredEnDown;
   Float_t         t1_t2_collinearmass_UnclusteredEnUp;
   Float_t         t1_t2_pt_tt;
   Float_t         t2AbsEta;
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
   Float_t         t2ByIsolationMVArun2v1PWdR03oldDMwLTraw;
   Float_t         t2ByIsolationMVArun2v1PWnewDMwLTraw;
   Float_t         t2ByIsolationMVArun2v1PWoldDMwLTraw;
   Float_t         t2ByLooseCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByLooseIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t2ByLooseIsolationMVArun2v1PWnewDMwLT;
   Float_t         t2ByLooseIsolationMVArun2v1PWoldDMwLT;
   Float_t         t2ByMediumCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByMediumIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByMediumIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByMediumIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t2ByMediumIsolationMVArun2v1PWnewDMwLT;
   Float_t         t2ByMediumIsolationMVArun2v1PWoldDMwLT;
   Float_t         t2ByPhotonPtSumOutsideSignalCone;
   Float_t         t2ByTightCombinedIsolationDeltaBetaCorr3Hits;
   Float_t         t2ByTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t2ByTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         t2ByTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1PWnewDMwLT;
   Float_t         t2ByVLooseIsolationMVArun2v1PWoldDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         t2ByVTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1DBnewDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1DBoldDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1PWdR03oldDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1PWnewDMwLT;
   Float_t         t2ByVVTightIsolationMVArun2v1PWoldDMwLT;
   Float_t         t2Charge;
   Float_t         t2ChargedIsoPtSum;
   Float_t         t2ChargedIsoPtSumdR03;
   Float_t         t2ComesFromHiggs;
   Float_t         t2DPhiToPfMet_ElectronEnDown;
   Float_t         t2DPhiToPfMet_ElectronEnUp;
   Float_t         t2DPhiToPfMet_JetEnDown;
   Float_t         t2DPhiToPfMet_JetEnUp;
   Float_t         t2DPhiToPfMet_JetResDown;
   Float_t         t2DPhiToPfMet_JetResUp;
   Float_t         t2DPhiToPfMet_MuonEnDown;
   Float_t         t2DPhiToPfMet_MuonEnUp;
   Float_t         t2DPhiToPfMet_PhotonEnDown;
   Float_t         t2DPhiToPfMet_PhotonEnUp;
   Float_t         t2DPhiToPfMet_TauEnDown;
   Float_t         t2DPhiToPfMet_TauEnUp;
   Float_t         t2DPhiToPfMet_UnclusteredEnDown;
   Float_t         t2DPhiToPfMet_UnclusteredEnUp;
   Float_t         t2DPhiToPfMet_type1;
   Float_t         t2DecayMode;
   Float_t         t2DecayModeFinding;
   Float_t         t2DecayModeFindingNewDMs;
   Float_t         t2ElecOverlap;
   Float_t         t2Eta;
   Float_t         t2Eta_TauEnDown;
   Float_t         t2Eta_TauEnUp;
   Float_t         t2FootprintCorrection;
   Float_t         t2FootprintCorrectiondR03;
   Float_t         t2GenCharge;
   Float_t         t2GenDecayMode;
   Float_t         t2GenEnergy;
   Float_t         t2GenEta;
   Float_t         t2GenIsPrompt;
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
   Float_t         t2GlobalMuonVtxOverlap;
   Float_t         t2JetArea;
   Float_t         t2JetBtag;
   Float_t         t2JetEtaEtaMoment;
   Float_t         t2JetEtaPhiMoment;
   Float_t         t2JetEtaPhiSpread;
   Float_t         t2JetHadronFlavour;
   Float_t         t2JetPFCISVBtag;
   Float_t         t2JetPartonFlavour;
   Float_t         t2JetPhiPhiMoment;
   Float_t         t2JetPt;
   Float_t         t2LeadTrackPt;
   Float_t         t2LowestMll;
   Float_t         t2Mass;
   Float_t         t2Mass_TauEnDown;
   Float_t         t2Mass_TauEnUp;
   Float_t         t2MatchesDoubleTau32Filter;
   Float_t         t2MatchesDoubleTau32Path;
   Float_t         t2MatchesDoubleTau35Filter;
   Float_t         t2MatchesDoubleTau35Path;
   Float_t         t2MatchesDoubleTau40Filter;
   Float_t         t2MatchesDoubleTau40Path;
   Float_t         t2MatchesDoubleTauCmbIso35RegFilter;
   Float_t         t2MatchesDoubleTauCmbIso35RegPath;
   Float_t         t2MatchesDoubleTauCmbIso40Filter;
   Float_t         t2MatchesDoubleTauCmbIso40Path;
   Float_t         t2MatchesDoubleTauCmbIso40RegFilter;
   Float_t         t2MatchesDoubleTauCmbIso40RegPath;
   Float_t         t2MatchesEle24Tau20Filter;
   Float_t         t2MatchesEle24Tau20L1Path;
   Float_t         t2MatchesEle24Tau20Path;
   Float_t         t2MatchesEle24Tau20sL1Filter;
   Float_t         t2MatchesEle24Tau30Filter;
   Float_t         t2MatchesEle24Tau30Path;
   Float_t         t2MatchesMu19Tau20Filter;
   Float_t         t2MatchesMu19Tau20Path;
   Float_t         t2MatchesMu19Tau20sL1Filter;
   Float_t         t2MatchesMu19Tau20sL1Path;
   Float_t         t2MatchesMu21Tau20sL1Filter;
   Float_t         t2MatchesMu21Tau20sL1Path;
   Float_t         t2MtToPfMet_ElectronEnDown;
   Float_t         t2MtToPfMet_ElectronEnUp;
   Float_t         t2MtToPfMet_JetEnDown;
   Float_t         t2MtToPfMet_JetEnUp;
   Float_t         t2MtToPfMet_JetResDown;
   Float_t         t2MtToPfMet_JetResUp;
   Float_t         t2MtToPfMet_MuonEnDown;
   Float_t         t2MtToPfMet_MuonEnUp;
   Float_t         t2MtToPfMet_PhotonEnDown;
   Float_t         t2MtToPfMet_PhotonEnUp;
   Float_t         t2MtToPfMet_Raw;
   Float_t         t2MtToPfMet_TauEnDown;
   Float_t         t2MtToPfMet_TauEnUp;
   Float_t         t2MtToPfMet_UnclusteredEnDown;
   Float_t         t2MtToPfMet_UnclusteredEnUp;
   Float_t         t2MtToPfMet_type1;
   Float_t         t2MuOverlap;
   Float_t         t2MuonIdIsoStdVtxOverlap;
   Float_t         t2MuonIdIsoVtxOverlap;
   Float_t         t2MuonIdVtxOverlap;
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
   Float_t         t2Phi_TauEnDown;
   Float_t         t2Phi_TauEnUp;
   Float_t         t2PhotonPtSumOutsideSignalCone;
   Float_t         t2PhotonPtSumOutsideSignalConedR03;
   Float_t         t2Pt;
   Float_t         t2Pt_TauEnDown;
   Float_t         t2Pt_TauEnUp;
   Float_t         t2PuCorrPtSum;
   Float_t         t2Rank;
   Float_t         t2RerunMVArun2v1DBoldDMwLTLoose;
   Float_t         t2RerunMVArun2v1DBoldDMwLTMedium;
   Float_t         t2RerunMVArun2v1DBoldDMwLTTight;
   Float_t         t2RerunMVArun2v1DBoldDMwLTVLoose;
   Float_t         t2RerunMVArun2v1DBoldDMwLTVTight;
   Float_t         t2RerunMVArun2v1DBoldDMwLTVVTight;
   Float_t         t2RerunMVArun2v1DBoldDMwLTraw;
   Float_t         t2VZ;
   Float_t         t2ZTTGenDR;
   Float_t         t2ZTTGenEta;
   Float_t         t2ZTTGenMatching;
   Float_t         t2ZTTGenPhi;
   Float_t         t2ZTTGenPt;
   Float_t         t2_t1_collinearmass;
   Float_t         t2_t1_collinearmass_JetEnDown;
   Float_t         t2_t1_collinearmass_JetEnUp;
   Float_t         t2_t1_collinearmass_UnclusteredEnDown;
   Float_t         t2_t1_collinearmass_UnclusteredEnUp;
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

   Float_t         type1_pfMet_shiftedPhi_JetEnDown;
   Float_t         type1_pfMet_shiftedPhi_JetEnUp;
   Float_t         type1_pfMet_shiftedPhi_JetResDown;
   Float_t         type1_pfMet_shiftedPhi_JetResUp;
   Float_t         type1_pfMet_shiftedPhi_UnclusteredEnDown;
   Float_t         type1_pfMet_shiftedPhi_UnclusteredEnUp;
   Float_t         type1_pfMet_shiftedPt_JetEnDown;
   Float_t         type1_pfMet_shiftedPt_JetEnUp;
   Float_t         type1_pfMet_shiftedPt_JetResDown;
   Float_t         type1_pfMet_shiftedPt_JetResUp;
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
   TBranch        *b_metSig;   //!
   TBranch        *b_metcov00;        //!
   TBranch        *b_metcov01;        //!
   TBranch        *b_metcov10;        //!
   TBranch        *b_metcov11;        //!
   TBranch        *b_metcov00_DESYlike; //!
   TBranch        *b_metcov01_DESYlike; //!
   TBranch        *b_metcov10_DESYlike; //!
   TBranch        *b_metcov11_DESYlike; //!
   TBranch        *b_muGlbIsoVetoPt10;            //!
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
   TBranch        *b_t1AbsEta;   //!
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
   TBranch        *b_t1ByIsolationMVArun2v1PWdR03oldDMwLTraw;   //!
   TBranch        *b_t1ByIsolationMVArun2v1PWnewDMwLTraw;   //!
   TBranch        *b_t1ByIsolationMVArun2v1PWoldDMwLTraw;   //!
   TBranch        *b_t1ByLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t1ByLooseIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t1ByMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t1ByMediumIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t1ByPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_t1ByTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t1ByTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t1ByVLooseIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t1ByVTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t1ByVVTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t1Charge;   //!
   TBranch        *b_t1ChargedIsoPtSum;   //!
   TBranch        *b_t1ChargedIsoPtSumdR03;   //!
   TBranch        *b_t1ComesFromHiggs;   //!
   TBranch        *b_t1DPhiToPfMet_ElectronEnDown;   //!
   TBranch        *b_t1DPhiToPfMet_ElectronEnUp;   //!
   TBranch        *b_t1DPhiToPfMet_JetEnDown;   //!
   TBranch        *b_t1DPhiToPfMet_JetEnUp;   //!
   TBranch        *b_t1DPhiToPfMet_JetResDown;   //!
   TBranch        *b_t1DPhiToPfMet_JetResUp;   //!
   TBranch        *b_t1DPhiToPfMet_MuonEnDown;   //!
   TBranch        *b_t1DPhiToPfMet_MuonEnUp;   //!
   TBranch        *b_t1DPhiToPfMet_PhotonEnDown;   //!
   TBranch        *b_t1DPhiToPfMet_PhotonEnUp;   //!
   TBranch        *b_t1DPhiToPfMet_TauEnDown;   //!
   TBranch        *b_t1DPhiToPfMet_TauEnUp;   //!
   TBranch        *b_t1DPhiToPfMet_UnclusteredEnDown;   //!
   TBranch        *b_t1DPhiToPfMet_UnclusteredEnUp;   //!
   TBranch        *b_t1DPhiToPfMet_type1;   //!
   TBranch        *b_t1DecayMode;   //!
   TBranch        *b_t1DecayModeFinding;   //!
   TBranch        *b_t1DecayModeFindingNewDMs;   //!
   TBranch        *b_t1ElecOverlap;   //!
   TBranch        *b_t1Eta;   //!
   TBranch        *b_t1Eta_TauEnDown;   //!
   TBranch        *b_t1Eta_TauEnUp;   //!
   TBranch        *b_t1FootprintCorrection;   //!
   TBranch        *b_t1FootprintCorrectiondR03;   //!
   TBranch        *b_t1GenCharge;   //!
   TBranch        *b_t1GenDecayMode;   //!
   TBranch        *b_t1GenEnergy;   //!
   TBranch        *b_t1GenEta;   //!
   TBranch        *b_t1GenIsPrompt;   //!
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
   TBranch        *b_t1GlobalMuonVtxOverlap;   //!
   TBranch        *b_t1JetArea;   //!
   TBranch        *b_t1JetBtag;   //!
   TBranch        *b_t1JetEtaEtaMoment;   //!
   TBranch        *b_t1JetEtaPhiMoment;   //!
   TBranch        *b_t1JetEtaPhiSpread;   //!
   TBranch        *b_t1JetHadronFlavour;   //!
   TBranch        *b_t1JetPFCISVBtag;   //!
   TBranch        *b_t1JetPartonFlavour;   //!
   TBranch        *b_t1JetPhiPhiMoment;   //!
   TBranch        *b_t1JetPt;   //!
   TBranch        *b_t1LeadTrackPt;   //!
   TBranch        *b_t1LowestMll;   //!
   TBranch        *b_t1Mass;   //!
   TBranch        *b_t1Mass_TauEnDown;   //!
   TBranch        *b_t1Mass_TauEnUp;   //!
   TBranch        *b_t1MatchesDoubleTau32Filter;   //!
   TBranch        *b_t1MatchesDoubleTau32Path;   //!
   TBranch        *b_t1MatchesDoubleTau35Filter;   //!
   TBranch        *b_t1MatchesDoubleTau35Path;   //!
   TBranch        *b_t1MatchesDoubleTau40Filter;   //!
   TBranch        *b_t1MatchesDoubleTau40Path;   //!
   TBranch        *b_t1MatchesDoubleTauCmbIso35RegFilter;   //!
   TBranch        *b_t1MatchesDoubleTauCmbIso35RegPath;   //!
   TBranch        *b_t1MatchesDoubleTauCmbIso40Filter;   //!
   TBranch        *b_t1MatchesDoubleTauCmbIso40Path;   //!
   TBranch        *b_t1MatchesDoubleTauCmbIso40RegFilter;   //!
   TBranch        *b_t1MatchesDoubleTauCmbIso40RegPath;   //!
   TBranch        *b_t1MatchesEle24Tau20Filter;   //!
   TBranch        *b_t1MatchesEle24Tau20L1Path;   //!
   TBranch        *b_t1MatchesEle24Tau20Path;   //!
   TBranch        *b_t1MatchesEle24Tau20sL1Filter;   //!
   TBranch        *b_t1MatchesEle24Tau30Filter;   //!
   TBranch        *b_t1MatchesEle24Tau30Path;   //!
   TBranch        *b_t1MatchesMu19Tau20Filter;   //!
   TBranch        *b_t1MatchesMu19Tau20Path;   //!
   TBranch        *b_t1MatchesMu19Tau20sL1Filter;   //!
   TBranch        *b_t1MatchesMu19Tau20sL1Path;   //!
   TBranch        *b_t1MatchesMu21Tau20sL1Filter;   //!
   TBranch        *b_t1MatchesMu21Tau20sL1Path;   //!
   TBranch        *b_t1MtToPfMet_ElectronEnDown;   //!
   TBranch        *b_t1MtToPfMet_ElectronEnUp;   //!
   TBranch        *b_t1MtToPfMet_JetEnDown;   //!
   TBranch        *b_t1MtToPfMet_JetEnUp;   //!
   TBranch        *b_t1MtToPfMet_JetResDown;   //!
   TBranch        *b_t1MtToPfMet_JetResUp;   //!
   TBranch        *b_t1MtToPfMet_MuonEnDown;   //!
   TBranch        *b_t1MtToPfMet_MuonEnUp;   //!
   TBranch        *b_t1MtToPfMet_PhotonEnDown;   //!
   TBranch        *b_t1MtToPfMet_PhotonEnUp;   //!
   TBranch        *b_t1MtToPfMet_Raw;   //!
   TBranch        *b_t1MtToPfMet_TauEnDown;   //!
   TBranch        *b_t1MtToPfMet_TauEnUp;   //!
   TBranch        *b_t1MtToPfMet_UnclusteredEnDown;   //!
   TBranch        *b_t1MtToPfMet_UnclusteredEnUp;   //!
   TBranch        *b_t1MtToPfMet_type1;   //!
   TBranch        *b_t1MuOverlap;   //!
   TBranch        *b_t1MuonIdIsoStdVtxOverlap;   //!
   TBranch        *b_t1MuonIdIsoVtxOverlap;   //!
   TBranch        *b_t1MuonIdVtxOverlap;   //!
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
   TBranch        *b_t1Phi_TauEnDown;   //!
   TBranch        *b_t1Phi_TauEnUp;   //!
   TBranch        *b_t1PhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_t1PhotonPtSumOutsideSignalConedR03;   //!
   TBranch        *b_t1Pt;   //!
   TBranch        *b_t1Pt_TauEnDown;   //!
   TBranch        *b_t1Pt_TauEnUp;   //!
   TBranch        *b_t1PuCorrPtSum;   //!
   TBranch        *b_t1Rank;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTLoose;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTMedium;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTTight;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTVLoose;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTVTight;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTVVTight;   //!
   TBranch        *b_t1RerunMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_t1VZ;   //!
   TBranch        *b_t1ZTTGenDR;   //!
   TBranch        *b_t1ZTTGenEta;   //!
   TBranch        *b_t1ZTTGenMatching;   //!
   TBranch        *b_t1ZTTGenPhi;   //!
   TBranch        *b_t1ZTTGenPt;   //!
   TBranch        *b_t1_t2_CosThetaStar;   //!
   TBranch        *b_t1_t2_DPhi;   //!
   TBranch        *b_t1_t2_DR;   //!
   TBranch        *b_t1_t2_Eta;   //!
   TBranch        *b_t1_t2_Mass;   //!
   TBranch        *b_t1_t2_Mass_TauEnDown;   //!
   TBranch        *b_t1_t2_Mass_TauEnUp;   //!
   TBranch        *b_t1_t2_Mt;   //!
   TBranch        *b_t1_t2_MtTotal;   //!
   TBranch        *b_t1_t2_Mt_TauEnDown;   //!
   TBranch        *b_t1_t2_Mt_TauEnUp;   //!
   TBranch        *b_t1_t2_MvaMet;   //!
   TBranch        *b_t1_t2_MvaMetCovMatrix00;   //!
   TBranch        *b_t1_t2_MvaMetCovMatrix01;   //!
   TBranch        *b_t1_t2_MvaMetCovMatrix10;   //!
   TBranch        *b_t1_t2_MvaMetCovMatrix11;   //!
   TBranch        *b_t1_t2_MvaMetPhi;   //!
   TBranch        *b_t1_t2_PZeta;   //!
   TBranch        *b_t1_t2_PZetaLess0p85PZetaVis;   //!
   TBranch        *b_t1_t2_PZetaVis;   //!
   TBranch        *b_t1_t2_Phi;   //!
   TBranch        *b_t1_t2_Pt;   //!
   TBranch        *b_t1_t2_SS;   //!
   TBranch        *b_t1_t2_ToMETDPhi_Ty1;   //!
   TBranch        *b_t1_t2_collinearmass;   //!
   TBranch        *b_t1_t2_collinearmass_EleEnDown;   //!
   TBranch        *b_t1_t2_collinearmass_EleEnUp;   //!
   TBranch        *b_t1_t2_collinearmass_JetEnDown;   //!
   TBranch        *b_t1_t2_collinearmass_JetEnUp;   //!
   TBranch        *b_t1_t2_collinearmass_MuEnDown;   //!
   TBranch        *b_t1_t2_collinearmass_MuEnUp;   //!
   TBranch        *b_t1_t2_collinearmass_TauEnDown;   //!
   TBranch        *b_t1_t2_collinearmass_TauEnUp;   //!
   TBranch        *b_t1_t2_collinearmass_UnclusteredEnDown;   //!
   TBranch        *b_t1_t2_collinearmass_UnclusteredEnUp;   //!
   TBranch        *b_t1_t2_pt_tt;   //!
   TBranch        *b_t2AbsEta;   //!
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
   TBranch        *b_t2ByIsolationMVArun2v1PWdR03oldDMwLTraw;   //!
   TBranch        *b_t2ByIsolationMVArun2v1PWnewDMwLTraw;   //!
   TBranch        *b_t2ByIsolationMVArun2v1PWoldDMwLTraw;   //!
   TBranch        *b_t2ByLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t2ByLooseIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t2ByMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t2ByMediumIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t2ByPhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_t2ByTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t2ByTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t2ByVLooseIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t2ByVTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1PWdR03oldDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1PWnewDMwLT;   //!
   TBranch        *b_t2ByVVTightIsolationMVArun2v1PWoldDMwLT;   //!
   TBranch        *b_t2Charge;   //!
   TBranch        *b_t2ChargedIsoPtSum;   //!
   TBranch        *b_t2ChargedIsoPtSumdR03;   //!
   TBranch        *b_t2ComesFromHiggs;   //!
   TBranch        *b_t2DPhiToPfMet_ElectronEnDown;   //!
   TBranch        *b_t2DPhiToPfMet_ElectronEnUp;   //!
   TBranch        *b_t2DPhiToPfMet_JetEnDown;   //!
   TBranch        *b_t2DPhiToPfMet_JetEnUp;   //!
   TBranch        *b_t2DPhiToPfMet_JetResDown;   //!
   TBranch        *b_t2DPhiToPfMet_JetResUp;   //!
   TBranch        *b_t2DPhiToPfMet_MuonEnDown;   //!
   TBranch        *b_t2DPhiToPfMet_MuonEnUp;   //!
   TBranch        *b_t2DPhiToPfMet_PhotonEnDown;   //!
   TBranch        *b_t2DPhiToPfMet_PhotonEnUp;   //!
   TBranch        *b_t2DPhiToPfMet_TauEnDown;   //!
   TBranch        *b_t2DPhiToPfMet_TauEnUp;   //!
   TBranch        *b_t2DPhiToPfMet_UnclusteredEnDown;   //!
   TBranch        *b_t2DPhiToPfMet_UnclusteredEnUp;   //!
   TBranch        *b_t2DPhiToPfMet_type1;   //!
   TBranch        *b_t2DecayMode;   //!
   TBranch        *b_t2DecayModeFinding;   //!
   TBranch        *b_t2DecayModeFindingNewDMs;   //!
   TBranch        *b_t2ElecOverlap;   //!
   TBranch        *b_t2Eta;   //!
   TBranch        *b_t2Eta_TauEnDown;   //!
   TBranch        *b_t2Eta_TauEnUp;   //!
   TBranch        *b_t2FootprintCorrection;   //!
   TBranch        *b_t2FootprintCorrectiondR03;   //!
   TBranch        *b_t2GenCharge;   //!
   TBranch        *b_t2GenDecayMode;   //!
   TBranch        *b_t2GenEnergy;   //!
   TBranch        *b_t2GenEta;   //!
   TBranch        *b_t2GenIsPrompt;   //!
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
   TBranch        *b_t2GlobalMuonVtxOverlap;   //!
   TBranch        *b_t2JetArea;   //!
   TBranch        *b_t2JetBtag;   //!
   TBranch        *b_t2JetEtaEtaMoment;   //!
   TBranch        *b_t2JetEtaPhiMoment;   //!
   TBranch        *b_t2JetEtaPhiSpread;   //!
   TBranch        *b_t2JetHadronFlavour;   //!
   TBranch        *b_t2JetPFCISVBtag;   //!
   TBranch        *b_t2JetPartonFlavour;   //!
   TBranch        *b_t2JetPhiPhiMoment;   //!
   TBranch        *b_t2JetPt;   //!
   TBranch        *b_t2LeadTrackPt;   //!
   TBranch        *b_t2LowestMll;   //!
   TBranch        *b_t2Mass;   //!
   TBranch        *b_t2Mass_TauEnDown;   //!
   TBranch        *b_t2Mass_TauEnUp;   //!
   TBranch        *b_t2MatchesDoubleTau32Filter;   //!
   TBranch        *b_t2MatchesDoubleTau32Path;   //!
   TBranch        *b_t2MatchesDoubleTau35Filter;   //!
   TBranch        *b_t2MatchesDoubleTau35Path;   //!
   TBranch        *b_t2MatchesDoubleTau40Filter;   //!
   TBranch        *b_t2MatchesDoubleTau40Path;   //!
   TBranch        *b_t2MatchesDoubleTauCmbIso35RegFilter;   //!
   TBranch        *b_t2MatchesDoubleTauCmbIso35RegPath;   //!
   TBranch        *b_t2MatchesDoubleTauCmbIso40Filter;   //!
   TBranch        *b_t2MatchesDoubleTauCmbIso40Path;   //!
   TBranch        *b_t2MatchesDoubleTauCmbIso40RegFilter;   //!
   TBranch        *b_t2MatchesDoubleTauCmbIso40RegPath;   //!
   TBranch        *b_t2MatchesEle24Tau20Filter;   //!
   TBranch        *b_t2MatchesEle24Tau20L1Path;   //!
   TBranch        *b_t2MatchesEle24Tau20Path;   //!
   TBranch        *b_t2MatchesEle24Tau20sL1Filter;   //!
   TBranch        *b_t2MatchesEle24Tau30Filter;   //!
   TBranch        *b_t2MatchesEle24Tau30Path;   //!
   TBranch        *b_t2MatchesMu19Tau20Filter;   //!
   TBranch        *b_t2MatchesMu19Tau20Path;   //!
   TBranch        *b_t2MatchesMu19Tau20sL1Filter;   //!
   TBranch        *b_t2MatchesMu19Tau20sL1Path;   //!
   TBranch        *b_t2MatchesMu21Tau20sL1Filter;   //!
   TBranch        *b_t2MatchesMu21Tau20sL1Path;   //!
   TBranch        *b_t2MtToPfMet_ElectronEnDown;   //!
   TBranch        *b_t2MtToPfMet_ElectronEnUp;   //!
   TBranch        *b_t2MtToPfMet_JetEnDown;   //!
   TBranch        *b_t2MtToPfMet_JetEnUp;   //!
   TBranch        *b_t2MtToPfMet_JetResDown;   //!
   TBranch        *b_t2MtToPfMet_JetResUp;   //!
   TBranch        *b_t2MtToPfMet_MuonEnDown;   //!
   TBranch        *b_t2MtToPfMet_MuonEnUp;   //!
   TBranch        *b_t2MtToPfMet_PhotonEnDown;   //!
   TBranch        *b_t2MtToPfMet_PhotonEnUp;   //!
   TBranch        *b_t2MtToPfMet_Raw;   //!
   TBranch        *b_t2MtToPfMet_TauEnDown;   //!
   TBranch        *b_t2MtToPfMet_TauEnUp;   //!
   TBranch        *b_t2MtToPfMet_UnclusteredEnDown;   //!
   TBranch        *b_t2MtToPfMet_UnclusteredEnUp;   //!
   TBranch        *b_t2MtToPfMet_type1;   //!
   TBranch        *b_t2MuOverlap;   //!
   TBranch        *b_t2MuonIdIsoStdVtxOverlap;   //!
   TBranch        *b_t2MuonIdIsoVtxOverlap;   //!
   TBranch        *b_t2MuonIdVtxOverlap;   //!
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
   TBranch        *b_t2Phi_TauEnDown;   //!
   TBranch        *b_t2Phi_TauEnUp;   //!
   TBranch        *b_t2PhotonPtSumOutsideSignalCone;   //!
   TBranch        *b_t2PhotonPtSumOutsideSignalConedR03;   //!
   TBranch        *b_t2Pt;   //!
   TBranch        *b_t2Pt_TauEnDown;   //!
   TBranch        *b_t2Pt_TauEnUp;   //!
   TBranch        *b_t2PuCorrPtSum;   //!
   TBranch        *b_t2Rank;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTLoose;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTMedium;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTTight;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTVLoose;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTVTight;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTVVTight;   //!
   TBranch        *b_t2RerunMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_t2VZ;   //!
   TBranch        *b_t2ZTTGenDR;   //!
   TBranch        *b_t2ZTTGenEta;   //!
   TBranch        *b_t2ZTTGenMatching;   //!
   TBranch        *b_t2ZTTGenPhi;   //!
   TBranch        *b_t2ZTTGenPt;   //!
   TBranch        *b_t2_t1_collinearmass;   //!
   TBranch        *b_t2_t1_collinearmass_JetEnDown;   //!
   TBranch        *b_t2_t1_collinearmass_JetEnUp;   //!
   TBranch        *b_t2_t1_collinearmass_UnclusteredEnDown;   //!
   TBranch        *b_t2_t1_collinearmass_UnclusteredEnUp;   //!
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
   //TBranch        *b_type1_pfMet_shiftedPhi_ElectronEnDown;   //!
   //TBranch        *b_type1_pfMet_shiftedPhi_ElectronEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetResDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_JetResUp;   //!
   //TBranch        *b_type1_pfMet_shiftedPhi_MuonEnDown;   //!
   //TBranch        *b_type1_pfMet_shiftedPhi_MuonEnUp;   //!
   //TBranch        *b_type1_pfMet_shiftedPhi_PhotonEnDown;   //!
   //TBranch        *b_type1_pfMet_shiftedPhi_PhotonEnUp;   //!
   //TBranch        *b_type1_pfMet_shiftedPhi_TauEnDown;   //!
   //TBranch        *b_type1_pfMet_shiftedPhi_TauEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_UnclusteredEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPhi_UnclusteredEnUp;   //!
   //TBranch        *b_type1_pfMet_shiftedPt_ElectronEnDown;   //!
   //TBranch        *b_type1_pfMet_shiftedPt_ElectronEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEnDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetEnUp;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetResDown;   //!
   TBranch        *b_type1_pfMet_shiftedPt_JetResUp;   //!
   //TBranch        *b_type1_pfMet_shiftedPt_MuonEnDown;   //!
   //TBranch        *b_type1_pfMet_shiftedPt_MuonEnUp;   //!
   //TBranch        *b_type1_pfMet_shiftedPt_PhotonEnDown;   //!
   //TBranch        *b_type1_pfMet_shiftedPt_PhotonEnUp;   //!
   //TBranch        *b_type1_pfMet_shiftedPt_TauEnDown;   //!
   //TBranch        *b_type1_pfMet_shiftedPt_TauEnUp;   //!
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

   fChain->SetBranchAddress("EmbPtWeight", &EmbPtWeight, &b_EmbPtWeight);
   fChain->SetBranchAddress("Eta", &Eta, &b_Eta);
   fChain->SetBranchAddress("Flag_BadChargedCandidateFilter", &Flag_BadChargedCandidateFilter, &b_Flag_BadChargedCandidateFilter);
   fChain->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, &b_Flag_BadPFMuonFilter);
   fChain->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, &b_Flag_EcalDeadCellTriggerPrimitiveFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, &b_Flag_HBHENoiseFilter);
   fChain->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, &b_Flag_HBHENoiseIsoFilter);
   fChain->SetBranchAddress("Flag_badCloneMuonFilter", &Flag_badCloneMuonFilter, &b_Flag_badCloneMuonFilter);
   fChain->SetBranchAddress("Flag_badGlobalMuonFilter", &Flag_badGlobalMuonFilter, &b_Flag_badGlobalMuonFilter);
   fChain->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter, &b_Flag_eeBadScFilter);
   fChain->SetBranchAddress("Flag_globalTightHalo2016Filter", &Flag_globalTightHalo2016Filter, &b_Flag_globalTightHalo2016Filter);
   fChain->SetBranchAddress("Flag_goodVertices", &Flag_goodVertices, &b_Flag_goodVertices);
   fChain->SetBranchAddress("GenWeight", &GenWeight, &b_GenWeight);
   fChain->SetBranchAddress("Ht", &Ht, &b_Ht);
   fChain->SetBranchAddress("LT", &LT, &b_LT);
   fChain->SetBranchAddress("Mass", &Mass, &b_Mass);
   fChain->SetBranchAddress("MassError", &MassError, &b_MassError);
   fChain->SetBranchAddress("MassErrord1", &MassErrord1, &b_MassErrord1);
   fChain->SetBranchAddress("MassErrord2", &MassErrord2, &b_MassErrord2);
   fChain->SetBranchAddress("MassErrord3", &MassErrord3, &b_MassErrord3);
   fChain->SetBranchAddress("MassErrord4", &MassErrord4, &b_MassErrord4);
   fChain->SetBranchAddress("Mt", &Mt, &b_Mt);
   fChain->SetBranchAddress("NUP", &NUP, &b_NUP);
   fChain->SetBranchAddress("Phi", &Phi, &b_Phi);
   fChain->SetBranchAddress("Pt", &Pt, &b_Pt);
   fChain->SetBranchAddress("bjetCISVVeto20Loose", &bjetCISVVeto20Loose, &b_bjetCISVVeto20Loose);
   fChain->SetBranchAddress("bjetCISVVeto20Medium", &bjetCISVVeto20Medium, &b_bjetCISVVeto20Medium);
   fChain->SetBranchAddress("bjetCISVVeto20Tight", &bjetCISVVeto20Tight, &b_bjetCISVVeto20Tight);
   fChain->SetBranchAddress("bjetCISVVeto30Loose", &bjetCISVVeto30Loose, &b_bjetCISVVeto30Loose);
   fChain->SetBranchAddress("bjetCISVVeto30Medium", &bjetCISVVeto30Medium, &b_bjetCISVVeto30Medium);
   fChain->SetBranchAddress("bjetCISVVeto30Tight", &bjetCISVVeto30Tight, &b_bjetCISVVeto30Tight);
   fChain->SetBranchAddress("charge", &charge, &b_charge);
   fChain->SetBranchAddress("dielectronVeto", &dielectronVeto, &b_dielectronVeto);
   fChain->SetBranchAddress("dimuonVeto", &dimuonVeto, &b_dimuonVeto);
   fChain->SetBranchAddress("doubleEGroup", &doubleEGroup, &b_doubleEGroup);
   fChain->SetBranchAddress("doubleEPass", &doubleEPass, &b_doubleEPass);
   fChain->SetBranchAddress("doubleEPrescale", &doubleEPrescale, &b_doubleEPrescale);
   fChain->SetBranchAddress("doubleESingleMuGroup", &doubleESingleMuGroup, &b_doubleESingleMuGroup);
   fChain->SetBranchAddress("doubleESingleMuPass", &doubleESingleMuPass, &b_doubleESingleMuPass);
   fChain->SetBranchAddress("doubleESingleMuPrescale", &doubleESingleMuPrescale, &b_doubleESingleMuPrescale);
   fChain->SetBranchAddress("doubleE_23_12Group", &doubleE_23_12Group, &b_doubleE_23_12Group);
   fChain->SetBranchAddress("doubleE_23_12Pass", &doubleE_23_12Pass, &b_doubleE_23_12Pass);
   fChain->SetBranchAddress("doubleE_23_12Prescale", &doubleE_23_12Prescale, &b_doubleE_23_12Prescale);
   fChain->SetBranchAddress("doubleMuGroup", &doubleMuGroup, &b_doubleMuGroup);
   fChain->SetBranchAddress("doubleMuPass", &doubleMuPass, &b_doubleMuPass);
   fChain->SetBranchAddress("doubleMuPrescale", &doubleMuPrescale, &b_doubleMuPrescale);
   fChain->SetBranchAddress("doubleMuSingleEGroup", &doubleMuSingleEGroup, &b_doubleMuSingleEGroup);
   fChain->SetBranchAddress("doubleMuSingleEPass", &doubleMuSingleEPass, &b_doubleMuSingleEPass);
   fChain->SetBranchAddress("doubleMuSingleEPrescale", &doubleMuSingleEPrescale, &b_doubleMuSingleEPrescale);
   fChain->SetBranchAddress("doubleTau32Group", &doubleTau32Group, &b_doubleTau32Group);
   fChain->SetBranchAddress("doubleTau32Pass", &doubleTau32Pass, &b_doubleTau32Pass);
   fChain->SetBranchAddress("doubleTau32Prescale", &doubleTau32Prescale, &b_doubleTau32Prescale);
   fChain->SetBranchAddress("doubleTau35Group", &doubleTau35Group, &b_doubleTau35Group);
   fChain->SetBranchAddress("doubleTau35Pass", &doubleTau35Pass, &b_doubleTau35Pass);
   fChain->SetBranchAddress("doubleTau35Prescale", &doubleTau35Prescale, &b_doubleTau35Prescale);
   fChain->SetBranchAddress("doubleTau40Group", &doubleTau40Group, &b_doubleTau40Group);
   fChain->SetBranchAddress("doubleTau40Pass", &doubleTau40Pass, &b_doubleTau40Pass);
   fChain->SetBranchAddress("doubleTau40Prescale", &doubleTau40Prescale, &b_doubleTau40Prescale);
   fChain->SetBranchAddress("doubleTauCmbIso35RegGroup", &doubleTauCmbIso35RegGroup, &b_doubleTauCmbIso35RegGroup);
   fChain->SetBranchAddress("doubleTauCmbIso35RegPass", &doubleTauCmbIso35RegPass, &b_doubleTauCmbIso35RegPass);
   fChain->SetBranchAddress("doubleTauCmbIso35RegPrescale", &doubleTauCmbIso35RegPrescale, &b_doubleTauCmbIso35RegPrescale);
   fChain->SetBranchAddress("doubleTauCmbIso40Group", &doubleTauCmbIso40Group, &b_doubleTauCmbIso40Group);
   fChain->SetBranchAddress("doubleTauCmbIso40Pass", &doubleTauCmbIso40Pass, &b_doubleTauCmbIso40Pass);
   fChain->SetBranchAddress("doubleTauCmbIso40Prescale", &doubleTauCmbIso40Prescale, &b_doubleTauCmbIso40Prescale);
   fChain->SetBranchAddress("doubleTauCmbIso40RegGroup", &doubleTauCmbIso40RegGroup, &b_doubleTauCmbIso40RegGroup);
   fChain->SetBranchAddress("doubleTauCmbIso40RegPass", &doubleTauCmbIso40RegPass, &b_doubleTauCmbIso40RegPass);
   fChain->SetBranchAddress("doubleTauCmbIso40RegPrescale", &doubleTauCmbIso40RegPrescale, &b_doubleTauCmbIso40RegPrescale);
   fChain->SetBranchAddress("eVetoMVAIso", &eVetoMVAIso, &b_eVetoMVAIso);
   fChain->SetBranchAddress("eVetoMVAIsoVtx", &eVetoMVAIsoVtx, &b_eVetoMVAIsoVtx);
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
   fChain->SetBranchAddress("isGtautau", &isGtautau, &b_isGtautau);
   fChain->SetBranchAddress("isWenu", &isWenu, &b_isWenu);
   fChain->SetBranchAddress("isWmunu", &isWmunu, &b_isWmunu);
   fChain->SetBranchAddress("isWtaunu", &isWtaunu, &b_isWtaunu);
   fChain->SetBranchAddress("isZee", &isZee, &b_isZee);
   fChain->SetBranchAddress("isZmumu", &isZmumu, &b_isZmumu);
   fChain->SetBranchAddress("isZtautau", &isZtautau, &b_isZtautau);
   fChain->SetBranchAddress("isdata", &isdata, &b_isdata);
   fChain->SetBranchAddress("j1csv", &j1csv, &b_j1csv);
   fChain->SetBranchAddress("j1eta", &j1eta, &b_j1eta);
   fChain->SetBranchAddress("j1hadronflavor", &j1hadronflavor, &b_j1hadronflavor);
   fChain->SetBranchAddress("j1partonflavor", &j1partonflavor, &b_j1partonflavor);
   fChain->SetBranchAddress("j1phi", &j1phi, &b_j1phi);
   fChain->SetBranchAddress("j1pt", &j1pt, &b_j1pt);
   fChain->SetBranchAddress("j1ptDown", &j1ptDown, &b_j1ptDown);
   fChain->SetBranchAddress("j1ptUp", &j1ptUp, &b_j1ptUp);
   fChain->SetBranchAddress("j1pu", &j1pu, &b_j1pu);
   fChain->SetBranchAddress("j1rawf", &j1rawf, &b_j1rawf);
   fChain->SetBranchAddress("j2csv", &j2csv, &b_j2csv);
   fChain->SetBranchAddress("j2eta", &j2eta, &b_j2eta);
   fChain->SetBranchAddress("j2hadronflavor", &j2hadronflavor, &b_j2hadronflavor);
   fChain->SetBranchAddress("j2partonflavor", &j2partonflavor, &b_j2partonflavor);
   fChain->SetBranchAddress("j2phi", &j2phi, &b_j2phi);
   fChain->SetBranchAddress("j2pt", &j2pt, &b_j2pt);
   fChain->SetBranchAddress("j2ptDown", &j2ptDown, &b_j2ptDown);
   fChain->SetBranchAddress("j2ptUp", &j2ptUp, &b_j2ptUp);
   fChain->SetBranchAddress("j2pu", &j2pu, &b_j2pu);
   fChain->SetBranchAddress("j2rawf", &j2rawf, &b_j2rawf);
   fChain->SetBranchAddress("jb1csv", &jb1csv, &b_jb1csv);
   fChain->SetBranchAddress("jb1csv_CSVL", &jb1csv_CSVL, &b_jb1csv_CSVL);
   fChain->SetBranchAddress("jb1eta", &jb1eta, &b_jb1eta);
   fChain->SetBranchAddress("jb1eta_CSVL", &jb1eta_CSVL, &b_jb1eta_CSVL);
   fChain->SetBranchAddress("jb1hadronflavor", &jb1hadronflavor, &b_jb1hadronflavor);
   fChain->SetBranchAddress("jb1hadronflavor_CSVL", &jb1hadronflavor_CSVL, &b_jb1hadronflavor_CSVL);
   fChain->SetBranchAddress("jb1partonflavor", &jb1partonflavor, &b_jb1partonflavor);
   fChain->SetBranchAddress("jb1partonflavor_CSVL", &jb1partonflavor_CSVL, &b_jb1partonflavor_CSVL);
   fChain->SetBranchAddress("jb1phi", &jb1phi, &b_jb1phi);
   fChain->SetBranchAddress("jb1phi_CSVL", &jb1phi_CSVL, &b_jb1phi_CSVL);
   fChain->SetBranchAddress("jb1pt", &jb1pt, &b_jb1pt);
   fChain->SetBranchAddress("jb1ptDown", &jb1ptDown, &b_jb1ptDown);
   fChain->SetBranchAddress("jb1ptDown_CSVL", &jb1ptDown_CSVL, &b_jb1ptDown_CSVL);
   fChain->SetBranchAddress("jb1ptUp", &jb1ptUp, &b_jb1ptUp);
   fChain->SetBranchAddress("jb1ptUp_CSVL", &jb1ptUp_CSVL, &b_jb1ptUp_CSVL);
   fChain->SetBranchAddress("jb1pt_CSVL", &jb1pt_CSVL, &b_jb1pt_CSVL);
   fChain->SetBranchAddress("jb1pu", &jb1pu, &b_jb1pu);
   fChain->SetBranchAddress("jb1pu_CSVL", &jb1pu_CSVL, &b_jb1pu_CSVL);
   fChain->SetBranchAddress("jb1rawf", &jb1rawf, &b_jb1rawf);
   fChain->SetBranchAddress("jb1rawf_CSVL", &jb1rawf_CSVL, &b_jb1rawf_CSVL);
   fChain->SetBranchAddress("jb2csv", &jb2csv, &b_jb2csv);
   fChain->SetBranchAddress("jb2csv_CSVL", &jb2csv_CSVL, &b_jb2csv_CSVL);
   fChain->SetBranchAddress("jb2eta", &jb2eta, &b_jb2eta);
   fChain->SetBranchAddress("jb2eta_CSVL", &jb2eta_CSVL, &b_jb2eta_CSVL);
   fChain->SetBranchAddress("jb2hadronflavor", &jb2hadronflavor, &b_jb2hadronflavor);
   fChain->SetBranchAddress("jb2hadronflavor_CSVL", &jb2hadronflavor_CSVL, &b_jb2hadronflavor_CSVL);
   fChain->SetBranchAddress("jb2partonflavor", &jb2partonflavor, &b_jb2partonflavor);
   fChain->SetBranchAddress("jb2partonflavor_CSVL", &jb2partonflavor_CSVL, &b_jb2partonflavor_CSVL);
   fChain->SetBranchAddress("jb2phi", &jb2phi, &b_jb2phi);
   fChain->SetBranchAddress("jb2phi_CSVL", &jb2phi_CSVL, &b_jb2phi_CSVL);
   fChain->SetBranchAddress("jb2pt", &jb2pt, &b_jb2pt);
   fChain->SetBranchAddress("jb2ptDown", &jb2ptDown, &b_jb2ptDown);
   fChain->SetBranchAddress("jb2ptDown_CSVL", &jb2ptDown_CSVL, &b_jb2ptDown_CSVL);
   fChain->SetBranchAddress("jb2ptUp", &jb2ptUp, &b_jb2ptUp);
   fChain->SetBranchAddress("jb2ptUp_CSVL", &jb2ptUp_CSVL, &b_jb2ptUp_CSVL);
   fChain->SetBranchAddress("jb2pt_CSVL", &jb2pt_CSVL, &b_jb2pt_CSVL);
   fChain->SetBranchAddress("jb2pu", &jb2pu, &b_jb2pu);
   fChain->SetBranchAddress("jb2pu_CSVL", &jb2pu_CSVL, &b_jb2pu_CSVL);
   fChain->SetBranchAddress("jb2rawf", &jb2rawf, &b_jb2rawf);
   fChain->SetBranchAddress("jb2rawf_CSVL", &jb2rawf_CSVL, &b_jb2rawf_CSVL);
   fChain->SetBranchAddress("jetVeto20", &jetVeto20, &b_jetVeto20);
   fChain->SetBranchAddress("jetVeto20_JetEnDown", &jetVeto20_JetEnDown, &b_jetVeto20_JetEnDown);
   fChain->SetBranchAddress("jetVeto20_JetEnUp", &jetVeto20_JetEnUp, &b_jetVeto20_JetEnUp);
   fChain->SetBranchAddress("jetVeto30", &jetVeto30, &b_jetVeto30);
   fChain->SetBranchAddress("jetVeto30_JetAbsoluteFlavMapDown", &jetVeto30_JetAbsoluteFlavMapDown, &b_jetVeto30_JetAbsoluteFlavMapDown);
   fChain->SetBranchAddress("jetVeto30_JetAbsoluteFlavMapUp", &jetVeto30_JetAbsoluteFlavMapUp, &b_jetVeto30_JetAbsoluteFlavMapUp);
   fChain->SetBranchAddress("jetVeto30_JetAbsoluteMPFBiasDown", &jetVeto30_JetAbsoluteMPFBiasDown, &b_jetVeto30_JetAbsoluteMPFBiasDown);
   fChain->SetBranchAddress("jetVeto30_JetAbsoluteMPFBiasUp", &jetVeto30_JetAbsoluteMPFBiasUp, &b_jetVeto30_JetAbsoluteMPFBiasUp);
   fChain->SetBranchAddress("jetVeto30_JetAbsoluteScaleDown", &jetVeto30_JetAbsoluteScaleDown, &b_jetVeto30_JetAbsoluteScaleDown);
   fChain->SetBranchAddress("jetVeto30_JetAbsoluteScaleUp", &jetVeto30_JetAbsoluteScaleUp, &b_jetVeto30_JetAbsoluteScaleUp);
   fChain->SetBranchAddress("jetVeto30_JetAbsoluteStatDown", &jetVeto30_JetAbsoluteStatDown, &b_jetVeto30_JetAbsoluteStatDown);
   fChain->SetBranchAddress("jetVeto30_JetAbsoluteStatUp", &jetVeto30_JetAbsoluteStatUp, &b_jetVeto30_JetAbsoluteStatUp);
   fChain->SetBranchAddress("jetVeto30_JetClosureDown", &jetVeto30_JetClosureDown, &b_jetVeto30_JetClosureDown);
   fChain->SetBranchAddress("jetVeto30_JetClosureUp", &jetVeto30_JetClosureUp, &b_jetVeto30_JetClosureUp);
   fChain->SetBranchAddress("jetVeto30_JetEnDown", &jetVeto30_JetEnDown, &b_jetVeto30_JetEnDown);
   fChain->SetBranchAddress("jetVeto30_JetEnUp", &jetVeto30_JetEnUp, &b_jetVeto30_JetEnUp);
   fChain->SetBranchAddress("jetVeto30_JetFlavorQCDDown", &jetVeto30_JetFlavorQCDDown, &b_jetVeto30_JetFlavorQCDDown);
   fChain->SetBranchAddress("jetVeto30_JetFlavorQCDUp", &jetVeto30_JetFlavorQCDUp, &b_jetVeto30_JetFlavorQCDUp);
   fChain->SetBranchAddress("jetVeto30_JetFragmentationDown", &jetVeto30_JetFragmentationDown, &b_jetVeto30_JetFragmentationDown);
   fChain->SetBranchAddress("jetVeto30_JetFragmentationUp", &jetVeto30_JetFragmentationUp, &b_jetVeto30_JetFragmentationUp);
   fChain->SetBranchAddress("jetVeto30_JetPileUpDataMCDown", &jetVeto30_JetPileUpDataMCDown, &b_jetVeto30_JetPileUpDataMCDown);
   fChain->SetBranchAddress("jetVeto30_JetPileUpDataMCUp", &jetVeto30_JetPileUpDataMCUp, &b_jetVeto30_JetPileUpDataMCUp);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtBBDown", &jetVeto30_JetPileUpPtBBDown, &b_jetVeto30_JetPileUpPtBBDown);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtBBUp", &jetVeto30_JetPileUpPtBBUp, &b_jetVeto30_JetPileUpPtBBUp);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtEC1Down", &jetVeto30_JetPileUpPtEC1Down, &b_jetVeto30_JetPileUpPtEC1Down);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtEC1Up", &jetVeto30_JetPileUpPtEC1Up, &b_jetVeto30_JetPileUpPtEC1Up);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtEC2Down", &jetVeto30_JetPileUpPtEC2Down, &b_jetVeto30_JetPileUpPtEC2Down);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtEC2Up", &jetVeto30_JetPileUpPtEC2Up, &b_jetVeto30_JetPileUpPtEC2Up);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtHFDown", &jetVeto30_JetPileUpPtHFDown, &b_jetVeto30_JetPileUpPtHFDown);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtHFUp", &jetVeto30_JetPileUpPtHFUp, &b_jetVeto30_JetPileUpPtHFUp);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtRefDown", &jetVeto30_JetPileUpPtRefDown, &b_jetVeto30_JetPileUpPtRefDown);
   fChain->SetBranchAddress("jetVeto30_JetPileUpPtRefUp", &jetVeto30_JetPileUpPtRefUp, &b_jetVeto30_JetPileUpPtRefUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativeBalDown", &jetVeto30_JetRelativeBalDown, &b_jetVeto30_JetRelativeBalDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativeBalUp", &jetVeto30_JetRelativeBalUp, &b_jetVeto30_JetRelativeBalUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativeFSRDown", &jetVeto30_JetRelativeFSRDown, &b_jetVeto30_JetRelativeFSRDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativeFSRUp", &jetVeto30_JetRelativeFSRUp, &b_jetVeto30_JetRelativeFSRUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativeJEREC1Down", &jetVeto30_JetRelativeJEREC1Down, &b_jetVeto30_JetRelativeJEREC1Down);
   fChain->SetBranchAddress("jetVeto30_JetRelativeJEREC1Up", &jetVeto30_JetRelativeJEREC1Up, &b_jetVeto30_JetRelativeJEREC1Up);
   fChain->SetBranchAddress("jetVeto30_JetRelativeJEREC2Down", &jetVeto30_JetRelativeJEREC2Down, &b_jetVeto30_JetRelativeJEREC2Down);
   fChain->SetBranchAddress("jetVeto30_JetRelativeJEREC2Up", &jetVeto30_JetRelativeJEREC2Up, &b_jetVeto30_JetRelativeJEREC2Up);
   fChain->SetBranchAddress("jetVeto30_JetRelativeJERHFDown", &jetVeto30_JetRelativeJERHFDown, &b_jetVeto30_JetRelativeJERHFDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativeJERHFUp", &jetVeto30_JetRelativeJERHFUp, &b_jetVeto30_JetRelativeJERHFUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativePtBBDown", &jetVeto30_JetRelativePtBBDown, &b_jetVeto30_JetRelativePtBBDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativePtBBUp", &jetVeto30_JetRelativePtBBUp, &b_jetVeto30_JetRelativePtBBUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativePtEC1Down", &jetVeto30_JetRelativePtEC1Down, &b_jetVeto30_JetRelativePtEC1Down);
   fChain->SetBranchAddress("jetVeto30_JetRelativePtEC1Up", &jetVeto30_JetRelativePtEC1Up, &b_jetVeto30_JetRelativePtEC1Up);
   fChain->SetBranchAddress("jetVeto30_JetRelativePtEC2Down", &jetVeto30_JetRelativePtEC2Down, &b_jetVeto30_JetRelativePtEC2Down);
   fChain->SetBranchAddress("jetVeto30_JetRelativePtEC2Up", &jetVeto30_JetRelativePtEC2Up, &b_jetVeto30_JetRelativePtEC2Up);
   fChain->SetBranchAddress("jetVeto30_JetRelativePtHFDown", &jetVeto30_JetRelativePtHFDown, &b_jetVeto30_JetRelativePtHFDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativePtHFUp", &jetVeto30_JetRelativePtHFUp, &b_jetVeto30_JetRelativePtHFUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativeStatECDown", &jetVeto30_JetRelativeStatECDown, &b_jetVeto30_JetRelativeStatECDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativeStatECUp", &jetVeto30_JetRelativeStatECUp, &b_jetVeto30_JetRelativeStatECUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativeStatFSRDown", &jetVeto30_JetRelativeStatFSRDown, &b_jetVeto30_JetRelativeStatFSRDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativeStatFSRUp", &jetVeto30_JetRelativeStatFSRUp, &b_jetVeto30_JetRelativeStatFSRUp);
   fChain->SetBranchAddress("jetVeto30_JetRelativeStatHFDown", &jetVeto30_JetRelativeStatHFDown, &b_jetVeto30_JetRelativeStatHFDown);
   fChain->SetBranchAddress("jetVeto30_JetRelativeStatHFUp", &jetVeto30_JetRelativeStatHFUp, &b_jetVeto30_JetRelativeStatHFUp);
   fChain->SetBranchAddress("jetVeto30_JetSinglePionECALDown", &jetVeto30_JetSinglePionECALDown, &b_jetVeto30_JetSinglePionECALDown);
   fChain->SetBranchAddress("jetVeto30_JetSinglePionECALUp", &jetVeto30_JetSinglePionECALUp, &b_jetVeto30_JetSinglePionECALUp);
   fChain->SetBranchAddress("jetVeto30_JetSinglePionHCALDown", &jetVeto30_JetSinglePionHCALDown, &b_jetVeto30_JetSinglePionHCALDown);
   fChain->SetBranchAddress("jetVeto30_JetSinglePionHCALUp", &jetVeto30_JetSinglePionHCALUp, &b_jetVeto30_JetSinglePionHCALUp);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalAbsoluteDown", &jetVeto30_JetSubTotalAbsoluteDown, &b_jetVeto30_JetSubTotalAbsoluteDown);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalAbsoluteUp", &jetVeto30_JetSubTotalAbsoluteUp, &b_jetVeto30_JetSubTotalAbsoluteUp);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalMCDown", &jetVeto30_JetSubTotalMCDown, &b_jetVeto30_JetSubTotalMCDown);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalMCUp", &jetVeto30_JetSubTotalMCUp, &b_jetVeto30_JetSubTotalMCUp);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalPileUpDown", &jetVeto30_JetSubTotalPileUpDown, &b_jetVeto30_JetSubTotalPileUpDown);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalPileUpUp", &jetVeto30_JetSubTotalPileUpUp, &b_jetVeto30_JetSubTotalPileUpUp);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalPtDown", &jetVeto30_JetSubTotalPtDown, &b_jetVeto30_JetSubTotalPtDown);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalPtUp", &jetVeto30_JetSubTotalPtUp, &b_jetVeto30_JetSubTotalPtUp);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalRelativeDown", &jetVeto30_JetSubTotalRelativeDown, &b_jetVeto30_JetSubTotalRelativeDown);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalRelativeUp", &jetVeto30_JetSubTotalRelativeUp, &b_jetVeto30_JetSubTotalRelativeUp);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalScaleDown", &jetVeto30_JetSubTotalScaleDown, &b_jetVeto30_JetSubTotalScaleDown);
   fChain->SetBranchAddress("jetVeto30_JetSubTotalScaleUp", &jetVeto30_JetSubTotalScaleUp, &b_jetVeto30_JetSubTotalScaleUp);
   fChain->SetBranchAddress("jetVeto30_JetTimePtEtaDown", &jetVeto30_JetTimePtEtaDown, &b_jetVeto30_JetTimePtEtaDown);
   fChain->SetBranchAddress("jetVeto30_JetTimePtEtaUp", &jetVeto30_JetTimePtEtaUp, &b_jetVeto30_JetTimePtEtaUp);
   fChain->SetBranchAddress("jetVeto30_JetTotalDown", &jetVeto30_JetTotalDown, &b_jetVeto30_JetTotalDown);
   fChain->SetBranchAddress("jetVeto30_JetTotalUp", &jetVeto30_JetTotalUp, &b_jetVeto30_JetTotalUp);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("metSig", &metSig, &b_metSig);
   fChain->SetBranchAddress("metcov00", &metcov00, &b_metcov00);
   fChain->SetBranchAddress("metcov01", &metcov01, &b_metcov01);
   fChain->SetBranchAddress("metcov10", &metcov10, &b_metcov10);
   fChain->SetBranchAddress("metcov11", &metcov11, &b_metcov11);
   fChain->SetBranchAddress("metcov00_DESYlike", &metcov00_DESYlike, &b_metcov00_DESYlike);
   fChain->SetBranchAddress("metcov01_DESYlike", &metcov01_DESYlike, &b_metcov01_DESYlike);
   fChain->SetBranchAddress("metcov10_DESYlike", &metcov10_DESYlike, &b_metcov10_DESYlike);
   fChain->SetBranchAddress("metcov11_DESYlike", &metcov11_DESYlike, &b_metcov11_DESYlike);
   fChain->SetBranchAddress("muGlbIsoVetoPt10", &muGlbIsoVetoPt10, &b_muGlbIsoVetoPt10);
   fChain->SetBranchAddress("muVetoPt15IsoIdVtx", &muVetoPt15IsoIdVtx, &b_muVetoPt15IsoIdVtx);
   fChain->SetBranchAddress("muVetoPt5", &muVetoPt5, &b_muVetoPt5);
   fChain->SetBranchAddress("muVetoPt5IsoIdVtx", &muVetoPt5IsoIdVtx, &b_muVetoPt5IsoIdVtx);
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
   fChain->SetBranchAddress("raw_pfMetEt", &raw_pfMetEt, &b_raw_pfMetEt);
   fChain->SetBranchAddress("raw_pfMetPhi", &raw_pfMetPhi, &b_raw_pfMetPhi);
   fChain->SetBranchAddress("recoilDaught", &recoilDaught, &b_recoilDaught);
   fChain->SetBranchAddress("recoilWithMet", &recoilWithMet, &b_recoilWithMet);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("singleE17SingleMu8Group", &singleE17SingleMu8Group, &b_singleE17SingleMu8Group);
   fChain->SetBranchAddress("singleE17SingleMu8Pass", &singleE17SingleMu8Pass, &b_singleE17SingleMu8Pass);
   fChain->SetBranchAddress("singleE17SingleMu8Prescale", &singleE17SingleMu8Prescale, &b_singleE17SingleMu8Prescale);
   fChain->SetBranchAddress("singleE20SingleTau28Group", &singleE20SingleTau28Group, &b_singleE20SingleTau28Group);
   fChain->SetBranchAddress("singleE20SingleTau28Pass", &singleE20SingleTau28Pass, &b_singleE20SingleTau28Pass);
   fChain->SetBranchAddress("singleE20SingleTau28Prescale", &singleE20SingleTau28Prescale, &b_singleE20SingleTau28Prescale);
   fChain->SetBranchAddress("singleE22SingleTau20SingleL1Group", &singleE22SingleTau20SingleL1Group, &b_singleE22SingleTau20SingleL1Group);
   fChain->SetBranchAddress("singleE22SingleTau20SingleL1Pass", &singleE22SingleTau20SingleL1Pass, &b_singleE22SingleTau20SingleL1Pass);
   fChain->SetBranchAddress("singleE22SingleTau20SingleL1Prescale", &singleE22SingleTau20SingleL1Prescale, &b_singleE22SingleTau20SingleL1Prescale);
   fChain->SetBranchAddress("singleE22SingleTau29Group", &singleE22SingleTau29Group, &b_singleE22SingleTau29Group);
   fChain->SetBranchAddress("singleE22SingleTau29Pass", &singleE22SingleTau29Pass, &b_singleE22SingleTau29Pass);
   fChain->SetBranchAddress("singleE22SingleTau29Prescale", &singleE22SingleTau29Prescale, &b_singleE22SingleTau29Prescale);
   fChain->SetBranchAddress("singleE23SingleMu8Group", &singleE23SingleMu8Group, &b_singleE23SingleMu8Group);
   fChain->SetBranchAddress("singleE23SingleMu8Pass", &singleE23SingleMu8Pass, &b_singleE23SingleMu8Pass);
   fChain->SetBranchAddress("singleE23SingleMu8Prescale", &singleE23SingleMu8Prescale, &b_singleE23SingleMu8Prescale);
   fChain->SetBranchAddress("singleE24SingleTau20Group", &singleE24SingleTau20Group, &b_singleE24SingleTau20Group);
   fChain->SetBranchAddress("singleE24SingleTau20Pass", &singleE24SingleTau20Pass, &b_singleE24SingleTau20Pass);
   fChain->SetBranchAddress("singleE24SingleTau20Prescale", &singleE24SingleTau20Prescale, &b_singleE24SingleTau20Prescale);
   fChain->SetBranchAddress("singleE24SingleTau20SingleL1Group", &singleE24SingleTau20SingleL1Group, &b_singleE24SingleTau20SingleL1Group);
   fChain->SetBranchAddress("singleE24SingleTau20SingleL1Pass", &singleE24SingleTau20SingleL1Pass, &b_singleE24SingleTau20SingleL1Pass);
   fChain->SetBranchAddress("singleE24SingleTau20SingleL1Prescale", &singleE24SingleTau20SingleL1Prescale, &b_singleE24SingleTau20SingleL1Prescale);
   fChain->SetBranchAddress("singleE24SingleTau30Group", &singleE24SingleTau30Group, &b_singleE24SingleTau30Group);
   fChain->SetBranchAddress("singleE24SingleTau30Pass", &singleE24SingleTau30Pass, &b_singleE24SingleTau30Pass);
   fChain->SetBranchAddress("singleE24SingleTau30Prescale", &singleE24SingleTau30Prescale, &b_singleE24SingleTau30Prescale);
   fChain->SetBranchAddress("singleE25eta2p1TightGroup", &singleE25eta2p1TightGroup, &b_singleE25eta2p1TightGroup);
   fChain->SetBranchAddress("singleE25eta2p1TightPass", &singleE25eta2p1TightPass, &b_singleE25eta2p1TightPass);
   fChain->SetBranchAddress("singleE25eta2p1TightPrescale", &singleE25eta2p1TightPrescale, &b_singleE25eta2p1TightPrescale);
   fChain->SetBranchAddress("singleE27SingleTau20SingleL1Group", &singleE27SingleTau20SingleL1Group, &b_singleE27SingleTau20SingleL1Group);
   fChain->SetBranchAddress("singleE27SingleTau20SingleL1Pass", &singleE27SingleTau20SingleL1Pass, &b_singleE27SingleTau20SingleL1Pass);
   fChain->SetBranchAddress("singleE27SingleTau20SingleL1Prescale", &singleE27SingleTau20SingleL1Prescale, &b_singleE27SingleTau20SingleL1Prescale);
   fChain->SetBranchAddress("singleE27TightGroup", &singleE27TightGroup, &b_singleE27TightGroup);
   fChain->SetBranchAddress("singleE27TightPass", &singleE27TightPass, &b_singleE27TightPass);
   fChain->SetBranchAddress("singleE27TightPrescale", &singleE27TightPrescale, &b_singleE27TightPrescale);
   fChain->SetBranchAddress("singleE27eta2p1LooseGroup", &singleE27eta2p1LooseGroup, &b_singleE27eta2p1LooseGroup);
   fChain->SetBranchAddress("singleE27eta2p1LoosePass", &singleE27eta2p1LoosePass, &b_singleE27eta2p1LoosePass);
   fChain->SetBranchAddress("singleE27eta2p1LoosePrescale", &singleE27eta2p1LoosePrescale, &b_singleE27eta2p1LoosePrescale);
   fChain->SetBranchAddress("singleE27eta2p1TightGroup", &singleE27eta2p1TightGroup, &b_singleE27eta2p1TightGroup);
   fChain->SetBranchAddress("singleE27eta2p1TightPass", &singleE27eta2p1TightPass, &b_singleE27eta2p1TightPass);
   fChain->SetBranchAddress("singleE27eta2p1TightPrescale", &singleE27eta2p1TightPrescale, &b_singleE27eta2p1TightPrescale);
   fChain->SetBranchAddress("singleE32SingleTau20SingleL1Group", &singleE32SingleTau20SingleL1Group, &b_singleE32SingleTau20SingleL1Group);
   fChain->SetBranchAddress("singleE32SingleTau20SingleL1Pass", &singleE32SingleTau20SingleL1Pass, &b_singleE32SingleTau20SingleL1Pass);
   fChain->SetBranchAddress("singleE32SingleTau20SingleL1Prescale", &singleE32SingleTau20SingleL1Prescale, &b_singleE32SingleTau20SingleL1Prescale);
   fChain->SetBranchAddress("singleE36SingleTau30Group", &singleE36SingleTau30Group, &b_singleE36SingleTau30Group);
   fChain->SetBranchAddress("singleE36SingleTau30Pass", &singleE36SingleTau30Pass, &b_singleE36SingleTau30Pass);
   fChain->SetBranchAddress("singleE36SingleTau30Prescale", &singleE36SingleTau30Prescale, &b_singleE36SingleTau30Prescale);
   fChain->SetBranchAddress("singleESingleMuGroup", &singleESingleMuGroup, &b_singleESingleMuGroup);
   fChain->SetBranchAddress("singleESingleMuPass", &singleESingleMuPass, &b_singleESingleMuPass);
   fChain->SetBranchAddress("singleESingleMuPrescale", &singleESingleMuPrescale, &b_singleESingleMuPrescale);
   fChain->SetBranchAddress("singleE_leg1Group", &singleE_leg1Group, &b_singleE_leg1Group);
   fChain->SetBranchAddress("singleE_leg1Pass", &singleE_leg1Pass, &b_singleE_leg1Pass);
   fChain->SetBranchAddress("singleE_leg1Prescale", &singleE_leg1Prescale, &b_singleE_leg1Prescale);
   fChain->SetBranchAddress("singleE_leg2Group", &singleE_leg2Group, &b_singleE_leg2Group);
   fChain->SetBranchAddress("singleE_leg2Pass", &singleE_leg2Pass, &b_singleE_leg2Pass);
   fChain->SetBranchAddress("singleE_leg2Prescale", &singleE_leg2Prescale, &b_singleE_leg2Prescale);
   fChain->SetBranchAddress("singleIsoMu20Group", &singleIsoMu20Group, &b_singleIsoMu20Group);
   fChain->SetBranchAddress("singleIsoMu20Pass", &singleIsoMu20Pass, &b_singleIsoMu20Pass);
   fChain->SetBranchAddress("singleIsoMu20Prescale", &singleIsoMu20Prescale, &b_singleIsoMu20Prescale);
   fChain->SetBranchAddress("singleIsoMu22Group", &singleIsoMu22Group, &b_singleIsoMu22Group);
   fChain->SetBranchAddress("singleIsoMu22Pass", &singleIsoMu22Pass, &b_singleIsoMu22Pass);
   fChain->SetBranchAddress("singleIsoMu22Prescale", &singleIsoMu22Prescale, &b_singleIsoMu22Prescale);
   fChain->SetBranchAddress("singleIsoMu22eta2p1Group", &singleIsoMu22eta2p1Group, &b_singleIsoMu22eta2p1Group);
   fChain->SetBranchAddress("singleIsoMu22eta2p1Pass", &singleIsoMu22eta2p1Pass, &b_singleIsoMu22eta2p1Pass);
   fChain->SetBranchAddress("singleIsoMu22eta2p1Prescale", &singleIsoMu22eta2p1Prescale, &b_singleIsoMu22eta2p1Prescale);
   fChain->SetBranchAddress("singleIsoMu24Group", &singleIsoMu24Group, &b_singleIsoMu24Group);
   fChain->SetBranchAddress("singleIsoMu24Pass", &singleIsoMu24Pass, &b_singleIsoMu24Pass);
   fChain->SetBranchAddress("singleIsoMu24Prescale", &singleIsoMu24Prescale, &b_singleIsoMu24Prescale);
   fChain->SetBranchAddress("singleIsoMu24eta2p1Group", &singleIsoMu24eta2p1Group, &b_singleIsoMu24eta2p1Group);
   fChain->SetBranchAddress("singleIsoMu24eta2p1Pass", &singleIsoMu24eta2p1Pass, &b_singleIsoMu24eta2p1Pass);
   fChain->SetBranchAddress("singleIsoMu24eta2p1Prescale", &singleIsoMu24eta2p1Prescale, &b_singleIsoMu24eta2p1Prescale);
   fChain->SetBranchAddress("singleIsoMu27Group", &singleIsoMu27Group, &b_singleIsoMu27Group);
   fChain->SetBranchAddress("singleIsoMu27Pass", &singleIsoMu27Pass, &b_singleIsoMu27Pass);
   fChain->SetBranchAddress("singleIsoMu27Prescale", &singleIsoMu27Prescale, &b_singleIsoMu27Prescale);
   fChain->SetBranchAddress("singleIsoTkMu20Group", &singleIsoTkMu20Group, &b_singleIsoTkMu20Group);
   fChain->SetBranchAddress("singleIsoTkMu20Pass", &singleIsoTkMu20Pass, &b_singleIsoTkMu20Pass);
   fChain->SetBranchAddress("singleIsoTkMu20Prescale", &singleIsoTkMu20Prescale, &b_singleIsoTkMu20Prescale);
   fChain->SetBranchAddress("singleIsoTkMu22Group", &singleIsoTkMu22Group, &b_singleIsoTkMu22Group);
   fChain->SetBranchAddress("singleIsoTkMu22Pass", &singleIsoTkMu22Pass, &b_singleIsoTkMu22Pass);
   fChain->SetBranchAddress("singleIsoTkMu22Prescale", &singleIsoTkMu22Prescale, &b_singleIsoTkMu22Prescale);
   fChain->SetBranchAddress("singleIsoTkMu22eta2p1Group", &singleIsoTkMu22eta2p1Group, &b_singleIsoTkMu22eta2p1Group);
   fChain->SetBranchAddress("singleIsoTkMu22eta2p1Pass", &singleIsoTkMu22eta2p1Pass, &b_singleIsoTkMu22eta2p1Pass);
   fChain->SetBranchAddress("singleIsoTkMu22eta2p1Prescale", &singleIsoTkMu22eta2p1Prescale, &b_singleIsoTkMu22eta2p1Prescale);
   fChain->SetBranchAddress("singleIsoTkMu24Group", &singleIsoTkMu24Group, &b_singleIsoTkMu24Group);
   fChain->SetBranchAddress("singleIsoTkMu24Pass", &singleIsoTkMu24Pass, &b_singleIsoTkMu24Pass);
   fChain->SetBranchAddress("singleIsoTkMu24Prescale", &singleIsoTkMu24Prescale, &b_singleIsoTkMu24Prescale);
   fChain->SetBranchAddress("singleIsoTkMu24eta2p1Group", &singleIsoTkMu24eta2p1Group, &b_singleIsoTkMu24eta2p1Group);
   fChain->SetBranchAddress("singleIsoTkMu24eta2p1Pass", &singleIsoTkMu24eta2p1Pass, &b_singleIsoTkMu24eta2p1Pass);
   fChain->SetBranchAddress("singleIsoTkMu24eta2p1Prescale", &singleIsoTkMu24eta2p1Prescale, &b_singleIsoTkMu24eta2p1Prescale);
   fChain->SetBranchAddress("singleMu17SingleE12Group", &singleMu17SingleE12Group, &b_singleMu17SingleE12Group);
   fChain->SetBranchAddress("singleMu17SingleE12Pass", &singleMu17SingleE12Pass, &b_singleMu17SingleE12Pass);
   fChain->SetBranchAddress("singleMu17SingleE12Prescale", &singleMu17SingleE12Prescale, &b_singleMu17SingleE12Prescale);
   fChain->SetBranchAddress("singleMu19eta2p1LooseTau20Group", &singleMu19eta2p1LooseTau20Group, &b_singleMu19eta2p1LooseTau20Group);
   fChain->SetBranchAddress("singleMu19eta2p1LooseTau20Pass", &singleMu19eta2p1LooseTau20Pass, &b_singleMu19eta2p1LooseTau20Pass);
   fChain->SetBranchAddress("singleMu19eta2p1LooseTau20Prescale", &singleMu19eta2p1LooseTau20Prescale, &b_singleMu19eta2p1LooseTau20Prescale);
   fChain->SetBranchAddress("singleMu19eta2p1LooseTau20singleL1Group", &singleMu19eta2p1LooseTau20singleL1Group, &b_singleMu19eta2p1LooseTau20singleL1Group);
   fChain->SetBranchAddress("singleMu19eta2p1LooseTau20singleL1Pass", &singleMu19eta2p1LooseTau20singleL1Pass, &b_singleMu19eta2p1LooseTau20singleL1Pass);
   fChain->SetBranchAddress("singleMu19eta2p1LooseTau20singleL1Prescale", &singleMu19eta2p1LooseTau20singleL1Prescale, &b_singleMu19eta2p1LooseTau20singleL1Prescale);
   fChain->SetBranchAddress("singleMu21eta2p1LooseTau20singleL1Group", &singleMu21eta2p1LooseTau20singleL1Group, &b_singleMu21eta2p1LooseTau20singleL1Group);
   fChain->SetBranchAddress("singleMu21eta2p1LooseTau20singleL1Pass", &singleMu21eta2p1LooseTau20singleL1Pass, &b_singleMu21eta2p1LooseTau20singleL1Pass);
   fChain->SetBranchAddress("singleMu21eta2p1LooseTau20singleL1Prescale", &singleMu21eta2p1LooseTau20singleL1Prescale, &b_singleMu21eta2p1LooseTau20singleL1Prescale);
   fChain->SetBranchAddress("singleMu23SingleE12DZGroup", &singleMu23SingleE12DZGroup, &b_singleMu23SingleE12DZGroup);
   fChain->SetBranchAddress("singleMu23SingleE12DZPass", &singleMu23SingleE12DZPass, &b_singleMu23SingleE12DZPass);
   fChain->SetBranchAddress("singleMu23SingleE12DZPrescale", &singleMu23SingleE12DZPrescale, &b_singleMu23SingleE12DZPrescale);
   fChain->SetBranchAddress("singleMu23SingleE12Group", &singleMu23SingleE12Group, &b_singleMu23SingleE12Group);
   fChain->SetBranchAddress("singleMu23SingleE12Pass", &singleMu23SingleE12Pass, &b_singleMu23SingleE12Pass);
   fChain->SetBranchAddress("singleMu23SingleE12Prescale", &singleMu23SingleE12Prescale, &b_singleMu23SingleE12Prescale);
   fChain->SetBranchAddress("singleMu23SingleE8Group", &singleMu23SingleE8Group, &b_singleMu23SingleE8Group);
   fChain->SetBranchAddress("singleMu23SingleE8Pass", &singleMu23SingleE8Pass, &b_singleMu23SingleE8Pass);
   fChain->SetBranchAddress("singleMu23SingleE8Prescale", &singleMu23SingleE8Prescale, &b_singleMu23SingleE8Prescale);
   fChain->SetBranchAddress("singleMu8SingleE23DZGroup", &singleMu8SingleE23DZGroup, &b_singleMu8SingleE23DZGroup);
   fChain->SetBranchAddress("singleMu8SingleE23DZPass", &singleMu8SingleE23DZPass, &b_singleMu8SingleE23DZPass);
   fChain->SetBranchAddress("singleMu8SingleE23DZPrescale", &singleMu8SingleE23DZPrescale, &b_singleMu8SingleE23DZPrescale);
   fChain->SetBranchAddress("singleMuGroup", &singleMuGroup, &b_singleMuGroup);
   fChain->SetBranchAddress("singleMuPass", &singleMuPass, &b_singleMuPass);
   fChain->SetBranchAddress("singleMuPrescale", &singleMuPrescale, &b_singleMuPrescale);
   fChain->SetBranchAddress("singleMuSingleEGroup", &singleMuSingleEGroup, &b_singleMuSingleEGroup);
   fChain->SetBranchAddress("singleMuSingleEPass", &singleMuSingleEPass, &b_singleMuSingleEPass);
   fChain->SetBranchAddress("singleMuSingleEPrescale", &singleMuSingleEPrescale, &b_singleMuSingleEPrescale);
   fChain->SetBranchAddress("singleMu_leg1Group", &singleMu_leg1Group, &b_singleMu_leg1Group);
   fChain->SetBranchAddress("singleMu_leg1Pass", &singleMu_leg1Pass, &b_singleMu_leg1Pass);
   fChain->SetBranchAddress("singleMu_leg1Prescale", &singleMu_leg1Prescale, &b_singleMu_leg1Prescale);
   fChain->SetBranchAddress("singleMu_leg1_noisoGroup", &singleMu_leg1_noisoGroup, &b_singleMu_leg1_noisoGroup);
   fChain->SetBranchAddress("singleMu_leg1_noisoPass", &singleMu_leg1_noisoPass, &b_singleMu_leg1_noisoPass);
   fChain->SetBranchAddress("singleMu_leg1_noisoPrescale", &singleMu_leg1_noisoPrescale, &b_singleMu_leg1_noisoPrescale);
   fChain->SetBranchAddress("singleMu_leg2Group", &singleMu_leg2Group, &b_singleMu_leg2Group);
   fChain->SetBranchAddress("singleMu_leg2Pass", &singleMu_leg2Pass, &b_singleMu_leg2Pass);
   fChain->SetBranchAddress("singleMu_leg2Prescale", &singleMu_leg2Prescale, &b_singleMu_leg2Prescale);
   fChain->SetBranchAddress("singleMu_leg2_noisoGroup", &singleMu_leg2_noisoGroup, &b_singleMu_leg2_noisoGroup);
   fChain->SetBranchAddress("singleMu_leg2_noisoPass", &singleMu_leg2_noisoPass, &b_singleMu_leg2_noisoPass);
   fChain->SetBranchAddress("singleMu_leg2_noisoPrescale", &singleMu_leg2_noisoPrescale, &b_singleMu_leg2_noisoPrescale);
   fChain->SetBranchAddress("singleTau140Group", &singleTau140Group, &b_singleTau140Group);
   fChain->SetBranchAddress("singleTau140Pass", &singleTau140Pass, &b_singleTau140Pass);
   fChain->SetBranchAddress("singleTau140Prescale", &singleTau140Prescale, &b_singleTau140Prescale);
   fChain->SetBranchAddress("singleTau140Trk50Group", &singleTau140Trk50Group, &b_singleTau140Trk50Group);
   fChain->SetBranchAddress("singleTau140Trk50Pass", &singleTau140Trk50Pass, &b_singleTau140Trk50Pass);
   fChain->SetBranchAddress("singleTau140Trk50Prescale", &singleTau140Trk50Prescale, &b_singleTau140Trk50Prescale);
   fChain->SetBranchAddress("t1AbsEta", &t1AbsEta, &b_t1AbsEta);
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
   fChain->SetBranchAddress("t1ByIsolationMVArun2v1PWdR03oldDMwLTraw", &t1ByIsolationMVArun2v1PWdR03oldDMwLTraw, &b_t1ByIsolationMVArun2v1PWdR03oldDMwLTraw);
   fChain->SetBranchAddress("t1ByIsolationMVArun2v1PWnewDMwLTraw", &t1ByIsolationMVArun2v1PWnewDMwLTraw, &b_t1ByIsolationMVArun2v1PWnewDMwLTraw);
   fChain->SetBranchAddress("t1ByIsolationMVArun2v1PWoldDMwLTraw", &t1ByIsolationMVArun2v1PWoldDMwLTraw, &b_t1ByIsolationMVArun2v1PWoldDMwLTraw);
   fChain->SetBranchAddress("t1ByLooseCombinedIsolationDeltaBetaCorr3Hits", &t1ByLooseCombinedIsolationDeltaBetaCorr3Hits, &b_t1ByLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT", &t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1DBnewDMwLT", &t1ByLooseIsolationMVArun2v1DBnewDMwLT, &b_t1ByLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1DBoldDMwLT", &t1ByLooseIsolationMVArun2v1DBoldDMwLT, &b_t1ByLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1PWdR03oldDMwLT", &t1ByLooseIsolationMVArun2v1PWdR03oldDMwLT, &b_t1ByLooseIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1PWnewDMwLT", &t1ByLooseIsolationMVArun2v1PWnewDMwLT, &b_t1ByLooseIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t1ByLooseIsolationMVArun2v1PWoldDMwLT", &t1ByLooseIsolationMVArun2v1PWoldDMwLT, &b_t1ByLooseIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t1ByMediumCombinedIsolationDeltaBetaCorr3Hits", &t1ByMediumCombinedIsolationDeltaBetaCorr3Hits, &b_t1ByMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT", &t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByMediumIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1DBnewDMwLT", &t1ByMediumIsolationMVArun2v1DBnewDMwLT, &b_t1ByMediumIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1DBoldDMwLT", &t1ByMediumIsolationMVArun2v1DBoldDMwLT, &b_t1ByMediumIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1PWdR03oldDMwLT", &t1ByMediumIsolationMVArun2v1PWdR03oldDMwLT, &b_t1ByMediumIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1PWnewDMwLT", &t1ByMediumIsolationMVArun2v1PWnewDMwLT, &b_t1ByMediumIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t1ByMediumIsolationMVArun2v1PWoldDMwLT", &t1ByMediumIsolationMVArun2v1PWoldDMwLT, &b_t1ByMediumIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t1ByPhotonPtSumOutsideSignalCone", &t1ByPhotonPtSumOutsideSignalCone, &b_t1ByPhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("t1ByTightCombinedIsolationDeltaBetaCorr3Hits", &t1ByTightCombinedIsolationDeltaBetaCorr3Hits, &b_t1ByTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1DBdR03oldDMwLT", &t1ByTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1DBnewDMwLT", &t1ByTightIsolationMVArun2v1DBnewDMwLT, &b_t1ByTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1DBoldDMwLT", &t1ByTightIsolationMVArun2v1DBoldDMwLT, &b_t1ByTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1PWdR03oldDMwLT", &t1ByTightIsolationMVArun2v1PWdR03oldDMwLT, &b_t1ByTightIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1PWnewDMwLT", &t1ByTightIsolationMVArun2v1PWnewDMwLT, &b_t1ByTightIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t1ByTightIsolationMVArun2v1PWoldDMwLT", &t1ByTightIsolationMVArun2v1PWoldDMwLT, &b_t1ByTightIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT", &t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByVLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1DBnewDMwLT", &t1ByVLooseIsolationMVArun2v1DBnewDMwLT, &b_t1ByVLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1DBoldDMwLT", &t1ByVLooseIsolationMVArun2v1DBoldDMwLT, &b_t1ByVLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1PWdR03oldDMwLT", &t1ByVLooseIsolationMVArun2v1PWdR03oldDMwLT, &b_t1ByVLooseIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1PWnewDMwLT", &t1ByVLooseIsolationMVArun2v1PWnewDMwLT, &b_t1ByVLooseIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t1ByVLooseIsolationMVArun2v1PWoldDMwLT", &t1ByVLooseIsolationMVArun2v1PWoldDMwLT, &b_t1ByVLooseIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT", &t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1DBnewDMwLT", &t1ByVTightIsolationMVArun2v1DBnewDMwLT, &b_t1ByVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1DBoldDMwLT", &t1ByVTightIsolationMVArun2v1DBoldDMwLT, &b_t1ByVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1PWdR03oldDMwLT", &t1ByVTightIsolationMVArun2v1PWdR03oldDMwLT, &b_t1ByVTightIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1PWnewDMwLT", &t1ByVTightIsolationMVArun2v1PWnewDMwLT, &b_t1ByVTightIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t1ByVTightIsolationMVArun2v1PWoldDMwLT", &t1ByVTightIsolationMVArun2v1PWoldDMwLT, &b_t1ByVTightIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT", &t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t1ByVVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1DBnewDMwLT", &t1ByVVTightIsolationMVArun2v1DBnewDMwLT, &b_t1ByVVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1DBoldDMwLT", &t1ByVVTightIsolationMVArun2v1DBoldDMwLT, &b_t1ByVVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1PWdR03oldDMwLT", &t1ByVVTightIsolationMVArun2v1PWdR03oldDMwLT, &b_t1ByVVTightIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1PWnewDMwLT", &t1ByVVTightIsolationMVArun2v1PWnewDMwLT, &b_t1ByVVTightIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t1ByVVTightIsolationMVArun2v1PWoldDMwLT", &t1ByVVTightIsolationMVArun2v1PWoldDMwLT, &b_t1ByVVTightIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t1Charge", &t1Charge, &b_t1Charge);
   fChain->SetBranchAddress("t1ChargedIsoPtSum", &t1ChargedIsoPtSum, &b_t1ChargedIsoPtSum);
   fChain->SetBranchAddress("t1ChargedIsoPtSumdR03", &t1ChargedIsoPtSumdR03, &b_t1ChargedIsoPtSumdR03);
   fChain->SetBranchAddress("t1ComesFromHiggs", &t1ComesFromHiggs, &b_t1ComesFromHiggs);
   fChain->SetBranchAddress("t1DPhiToPfMet_ElectronEnDown", &t1DPhiToPfMet_ElectronEnDown, &b_t1DPhiToPfMet_ElectronEnDown);
   fChain->SetBranchAddress("t1DPhiToPfMet_ElectronEnUp", &t1DPhiToPfMet_ElectronEnUp, &b_t1DPhiToPfMet_ElectronEnUp);
   fChain->SetBranchAddress("t1DPhiToPfMet_JetEnDown", &t1DPhiToPfMet_JetEnDown, &b_t1DPhiToPfMet_JetEnDown);
   fChain->SetBranchAddress("t1DPhiToPfMet_JetEnUp", &t1DPhiToPfMet_JetEnUp, &b_t1DPhiToPfMet_JetEnUp);
   fChain->SetBranchAddress("t1DPhiToPfMet_JetResDown", &t1DPhiToPfMet_JetResDown, &b_t1DPhiToPfMet_JetResDown);
   fChain->SetBranchAddress("t1DPhiToPfMet_JetResUp", &t1DPhiToPfMet_JetResUp, &b_t1DPhiToPfMet_JetResUp);
   fChain->SetBranchAddress("t1DPhiToPfMet_MuonEnDown", &t1DPhiToPfMet_MuonEnDown, &b_t1DPhiToPfMet_MuonEnDown);
   fChain->SetBranchAddress("t1DPhiToPfMet_MuonEnUp", &t1DPhiToPfMet_MuonEnUp, &b_t1DPhiToPfMet_MuonEnUp);
   fChain->SetBranchAddress("t1DPhiToPfMet_PhotonEnDown", &t1DPhiToPfMet_PhotonEnDown, &b_t1DPhiToPfMet_PhotonEnDown);
   fChain->SetBranchAddress("t1DPhiToPfMet_PhotonEnUp", &t1DPhiToPfMet_PhotonEnUp, &b_t1DPhiToPfMet_PhotonEnUp);
   fChain->SetBranchAddress("t1DPhiToPfMet_TauEnDown", &t1DPhiToPfMet_TauEnDown, &b_t1DPhiToPfMet_TauEnDown);
   fChain->SetBranchAddress("t1DPhiToPfMet_TauEnUp", &t1DPhiToPfMet_TauEnUp, &b_t1DPhiToPfMet_TauEnUp);
   fChain->SetBranchAddress("t1DPhiToPfMet_UnclusteredEnDown", &t1DPhiToPfMet_UnclusteredEnDown, &b_t1DPhiToPfMet_UnclusteredEnDown);
   fChain->SetBranchAddress("t1DPhiToPfMet_UnclusteredEnUp", &t1DPhiToPfMet_UnclusteredEnUp, &b_t1DPhiToPfMet_UnclusteredEnUp);
   fChain->SetBranchAddress("t1DPhiToPfMet_type1", &t1DPhiToPfMet_type1, &b_t1DPhiToPfMet_type1);
   fChain->SetBranchAddress("t1DecayMode", &t1DecayMode, &b_t1DecayMode);
   fChain->SetBranchAddress("t1DecayModeFinding", &t1DecayModeFinding, &b_t1DecayModeFinding);
   fChain->SetBranchAddress("t1DecayModeFindingNewDMs", &t1DecayModeFindingNewDMs, &b_t1DecayModeFindingNewDMs);
   fChain->SetBranchAddress("t1ElecOverlap", &t1ElecOverlap, &b_t1ElecOverlap);
   fChain->SetBranchAddress("t1Eta", &t1Eta, &b_t1Eta);
   fChain->SetBranchAddress("t1Eta_TauEnDown", &t1Eta_TauEnDown, &b_t1Eta_TauEnDown);
   fChain->SetBranchAddress("t1Eta_TauEnUp", &t1Eta_TauEnUp, &b_t1Eta_TauEnUp);
   fChain->SetBranchAddress("t1FootprintCorrection", &t1FootprintCorrection, &b_t1FootprintCorrection);
   fChain->SetBranchAddress("t1FootprintCorrectiondR03", &t1FootprintCorrectiondR03, &b_t1FootprintCorrectiondR03);
   fChain->SetBranchAddress("t1GenCharge", &t1GenCharge, &b_t1GenCharge);
   fChain->SetBranchAddress("t1GenDecayMode", &t1GenDecayMode, &b_t1GenDecayMode);
   fChain->SetBranchAddress("t1GenEnergy", &t1GenEnergy, &b_t1GenEnergy);
   fChain->SetBranchAddress("t1GenEta", &t1GenEta, &b_t1GenEta);
   fChain->SetBranchAddress("t1GenIsPrompt", &t1GenIsPrompt, &b_t1GenIsPrompt);
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
   fChain->SetBranchAddress("t1GlobalMuonVtxOverlap", &t1GlobalMuonVtxOverlap, &b_t1GlobalMuonVtxOverlap);
   fChain->SetBranchAddress("t1JetArea", &t1JetArea, &b_t1JetArea);
   fChain->SetBranchAddress("t1JetBtag", &t1JetBtag, &b_t1JetBtag);
   fChain->SetBranchAddress("t1JetEtaEtaMoment", &t1JetEtaEtaMoment, &b_t1JetEtaEtaMoment);
   fChain->SetBranchAddress("t1JetEtaPhiMoment", &t1JetEtaPhiMoment, &b_t1JetEtaPhiMoment);
   fChain->SetBranchAddress("t1JetEtaPhiSpread", &t1JetEtaPhiSpread, &b_t1JetEtaPhiSpread);
   fChain->SetBranchAddress("t1JetHadronFlavour", &t1JetHadronFlavour, &b_t1JetHadronFlavour);
   fChain->SetBranchAddress("t1JetPFCISVBtag", &t1JetPFCISVBtag, &b_t1JetPFCISVBtag);
   fChain->SetBranchAddress("t1JetPartonFlavour", &t1JetPartonFlavour, &b_t1JetPartonFlavour);
   fChain->SetBranchAddress("t1JetPhiPhiMoment", &t1JetPhiPhiMoment, &b_t1JetPhiPhiMoment);
   fChain->SetBranchAddress("t1JetPt", &t1JetPt, &b_t1JetPt);
   fChain->SetBranchAddress("t1LeadTrackPt", &t1LeadTrackPt, &b_t1LeadTrackPt);
   fChain->SetBranchAddress("t1LowestMll", &t1LowestMll, &b_t1LowestMll);
   fChain->SetBranchAddress("t1Mass", &t1Mass, &b_t1Mass);
   fChain->SetBranchAddress("t1Mass_TauEnDown", &t1Mass_TauEnDown, &b_t1Mass_TauEnDown);
   fChain->SetBranchAddress("t1Mass_TauEnUp", &t1Mass_TauEnUp, &b_t1Mass_TauEnUp);
   fChain->SetBranchAddress("t1MatchesDoubleTau32Filter", &t1MatchesDoubleTau32Filter, &b_t1MatchesDoubleTau32Filter);
   fChain->SetBranchAddress("t1MatchesDoubleTau32Path", &t1MatchesDoubleTau32Path, &b_t1MatchesDoubleTau32Path);
   fChain->SetBranchAddress("t1MatchesDoubleTau35Filter", &t1MatchesDoubleTau35Filter, &b_t1MatchesDoubleTau35Filter);
   fChain->SetBranchAddress("t1MatchesDoubleTau35Path", &t1MatchesDoubleTau35Path, &b_t1MatchesDoubleTau35Path);
   fChain->SetBranchAddress("t1MatchesDoubleTau40Filter", &t1MatchesDoubleTau40Filter, &b_t1MatchesDoubleTau40Filter);
   fChain->SetBranchAddress("t1MatchesDoubleTau40Path", &t1MatchesDoubleTau40Path, &b_t1MatchesDoubleTau40Path);
   fChain->SetBranchAddress("t1MatchesDoubleTauCmbIso35RegFilter", &t1MatchesDoubleTauCmbIso35RegFilter, &b_t1MatchesDoubleTauCmbIso35RegFilter);
   fChain->SetBranchAddress("t1MatchesDoubleTauCmbIso35RegPath", &t1MatchesDoubleTauCmbIso35RegPath, &b_t1MatchesDoubleTauCmbIso35RegPath);
   fChain->SetBranchAddress("t1MatchesDoubleTauCmbIso40Filter", &t1MatchesDoubleTauCmbIso40Filter, &b_t1MatchesDoubleTauCmbIso40Filter);
   fChain->SetBranchAddress("t1MatchesDoubleTauCmbIso40Path", &t1MatchesDoubleTauCmbIso40Path, &b_t1MatchesDoubleTauCmbIso40Path);
   fChain->SetBranchAddress("t1MatchesDoubleTauCmbIso40RegFilter", &t1MatchesDoubleTauCmbIso40RegFilter, &b_t1MatchesDoubleTauCmbIso40RegFilter);
   fChain->SetBranchAddress("t1MatchesDoubleTauCmbIso40RegPath", &t1MatchesDoubleTauCmbIso40RegPath, &b_t1MatchesDoubleTauCmbIso40RegPath);
   fChain->SetBranchAddress("t1MatchesEle24Tau20Filter", &t1MatchesEle24Tau20Filter, &b_t1MatchesEle24Tau20Filter);
   fChain->SetBranchAddress("t1MatchesEle24Tau20L1Path", &t1MatchesEle24Tau20L1Path, &b_t1MatchesEle24Tau20L1Path);
   fChain->SetBranchAddress("t1MatchesEle24Tau20Path", &t1MatchesEle24Tau20Path, &b_t1MatchesEle24Tau20Path);
   fChain->SetBranchAddress("t1MatchesEle24Tau20sL1Filter", &t1MatchesEle24Tau20sL1Filter, &b_t1MatchesEle24Tau20sL1Filter);
   fChain->SetBranchAddress("t1MatchesEle24Tau30Filter", &t1MatchesEle24Tau30Filter, &b_t1MatchesEle24Tau30Filter);
   fChain->SetBranchAddress("t1MatchesEle24Tau30Path", &t1MatchesEle24Tau30Path, &b_t1MatchesEle24Tau30Path);
   fChain->SetBranchAddress("t1MatchesMu19Tau20Filter", &t1MatchesMu19Tau20Filter, &b_t1MatchesMu19Tau20Filter);
   fChain->SetBranchAddress("t1MatchesMu19Tau20Path", &t1MatchesMu19Tau20Path, &b_t1MatchesMu19Tau20Path);
   fChain->SetBranchAddress("t1MatchesMu19Tau20sL1Filter", &t1MatchesMu19Tau20sL1Filter, &b_t1MatchesMu19Tau20sL1Filter);
   fChain->SetBranchAddress("t1MatchesMu19Tau20sL1Path", &t1MatchesMu19Tau20sL1Path, &b_t1MatchesMu19Tau20sL1Path);
   fChain->SetBranchAddress("t1MatchesMu21Tau20sL1Filter", &t1MatchesMu21Tau20sL1Filter, &b_t1MatchesMu21Tau20sL1Filter);
   fChain->SetBranchAddress("t1MatchesMu21Tau20sL1Path", &t1MatchesMu21Tau20sL1Path, &b_t1MatchesMu21Tau20sL1Path);
   fChain->SetBranchAddress("t1MtToPfMet_ElectronEnDown", &t1MtToPfMet_ElectronEnDown, &b_t1MtToPfMet_ElectronEnDown);
   fChain->SetBranchAddress("t1MtToPfMet_ElectronEnUp", &t1MtToPfMet_ElectronEnUp, &b_t1MtToPfMet_ElectronEnUp);
   fChain->SetBranchAddress("t1MtToPfMet_JetEnDown", &t1MtToPfMet_JetEnDown, &b_t1MtToPfMet_JetEnDown);
   fChain->SetBranchAddress("t1MtToPfMet_JetEnUp", &t1MtToPfMet_JetEnUp, &b_t1MtToPfMet_JetEnUp);
   fChain->SetBranchAddress("t1MtToPfMet_JetResDown", &t1MtToPfMet_JetResDown, &b_t1MtToPfMet_JetResDown);
   fChain->SetBranchAddress("t1MtToPfMet_JetResUp", &t1MtToPfMet_JetResUp, &b_t1MtToPfMet_JetResUp);
   fChain->SetBranchAddress("t1MtToPfMet_MuonEnDown", &t1MtToPfMet_MuonEnDown, &b_t1MtToPfMet_MuonEnDown);
   fChain->SetBranchAddress("t1MtToPfMet_MuonEnUp", &t1MtToPfMet_MuonEnUp, &b_t1MtToPfMet_MuonEnUp);
   fChain->SetBranchAddress("t1MtToPfMet_PhotonEnDown", &t1MtToPfMet_PhotonEnDown, &b_t1MtToPfMet_PhotonEnDown);
   fChain->SetBranchAddress("t1MtToPfMet_PhotonEnUp", &t1MtToPfMet_PhotonEnUp, &b_t1MtToPfMet_PhotonEnUp);
   fChain->SetBranchAddress("t1MtToPfMet_Raw", &t1MtToPfMet_Raw, &b_t1MtToPfMet_Raw);
   fChain->SetBranchAddress("t1MtToPfMet_TauEnDown", &t1MtToPfMet_TauEnDown, &b_t1MtToPfMet_TauEnDown);
   fChain->SetBranchAddress("t1MtToPfMet_TauEnUp", &t1MtToPfMet_TauEnUp, &b_t1MtToPfMet_TauEnUp);
   fChain->SetBranchAddress("t1MtToPfMet_UnclusteredEnDown", &t1MtToPfMet_UnclusteredEnDown, &b_t1MtToPfMet_UnclusteredEnDown);
   fChain->SetBranchAddress("t1MtToPfMet_UnclusteredEnUp", &t1MtToPfMet_UnclusteredEnUp, &b_t1MtToPfMet_UnclusteredEnUp);
   fChain->SetBranchAddress("t1MtToPfMet_type1", &t1MtToPfMet_type1, &b_t1MtToPfMet_type1);
   fChain->SetBranchAddress("t1MuOverlap", &t1MuOverlap, &b_t1MuOverlap);
   fChain->SetBranchAddress("t1MuonIdIsoStdVtxOverlap", &t1MuonIdIsoStdVtxOverlap, &b_t1MuonIdIsoStdVtxOverlap);
   fChain->SetBranchAddress("t1MuonIdIsoVtxOverlap", &t1MuonIdIsoVtxOverlap, &b_t1MuonIdIsoVtxOverlap);
   fChain->SetBranchAddress("t1MuonIdVtxOverlap", &t1MuonIdVtxOverlap, &b_t1MuonIdVtxOverlap);
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
   fChain->SetBranchAddress("t1Phi_TauEnDown", &t1Phi_TauEnDown, &b_t1Phi_TauEnDown);
   fChain->SetBranchAddress("t1Phi_TauEnUp", &t1Phi_TauEnUp, &b_t1Phi_TauEnUp);
   fChain->SetBranchAddress("t1PhotonPtSumOutsideSignalCone", &t1PhotonPtSumOutsideSignalCone, &b_t1PhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("t1PhotonPtSumOutsideSignalConedR03", &t1PhotonPtSumOutsideSignalConedR03, &b_t1PhotonPtSumOutsideSignalConedR03);
   fChain->SetBranchAddress("t1Pt", &t1Pt, &b_t1Pt);
   fChain->SetBranchAddress("t1Pt_TauEnDown", &t1Pt_TauEnDown, &b_t1Pt_TauEnDown);
   fChain->SetBranchAddress("t1Pt_TauEnUp", &t1Pt_TauEnUp, &b_t1Pt_TauEnUp);
   fChain->SetBranchAddress("t1PuCorrPtSum", &t1PuCorrPtSum, &b_t1PuCorrPtSum);
   fChain->SetBranchAddress("t1Rank", &t1Rank, &b_t1Rank);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTLoose", &t1RerunMVArun2v1DBoldDMwLTLoose, &b_t1RerunMVArun2v1DBoldDMwLTLoose);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTMedium", &t1RerunMVArun2v1DBoldDMwLTMedium, &b_t1RerunMVArun2v1DBoldDMwLTMedium);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTTight", &t1RerunMVArun2v1DBoldDMwLTTight, &b_t1RerunMVArun2v1DBoldDMwLTTight);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTVLoose", &t1RerunMVArun2v1DBoldDMwLTVLoose, &b_t1RerunMVArun2v1DBoldDMwLTVLoose);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTVTight", &t1RerunMVArun2v1DBoldDMwLTVTight, &b_t1RerunMVArun2v1DBoldDMwLTVTight);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTVVTight", &t1RerunMVArun2v1DBoldDMwLTVVTight, &b_t1RerunMVArun2v1DBoldDMwLTVVTight);
   fChain->SetBranchAddress("t1RerunMVArun2v1DBoldDMwLTraw", &t1RerunMVArun2v1DBoldDMwLTraw, &b_t1RerunMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("t1VZ", &t1VZ, &b_t1VZ);
   fChain->SetBranchAddress("t1ZTTGenDR", &t1ZTTGenDR, &b_t1ZTTGenDR);
   fChain->SetBranchAddress("t1ZTTGenEta", &t1ZTTGenEta, &b_t1ZTTGenEta);
   fChain->SetBranchAddress("t1ZTTGenMatching", &t1ZTTGenMatching, &b_t1ZTTGenMatching);
   fChain->SetBranchAddress("t1ZTTGenPhi", &t1ZTTGenPhi, &b_t1ZTTGenPhi);
   fChain->SetBranchAddress("t1ZTTGenPt", &t1ZTTGenPt, &b_t1ZTTGenPt);
   fChain->SetBranchAddress("t1_t2_CosThetaStar", &t1_t2_CosThetaStar, &b_t1_t2_CosThetaStar);
   fChain->SetBranchAddress("t1_t2_DPhi", &t1_t2_DPhi, &b_t1_t2_DPhi);
   fChain->SetBranchAddress("t1_t2_DR", &t1_t2_DR, &b_t1_t2_DR);
   fChain->SetBranchAddress("t1_t2_Eta", &t1_t2_Eta, &b_t1_t2_Eta);
   fChain->SetBranchAddress("t1_t2_Mass", &t1_t2_Mass, &b_t1_t2_Mass);
   fChain->SetBranchAddress("t1_t2_Mass_TauEnDown", &t1_t2_Mass_TauEnDown, &b_t1_t2_Mass_TauEnDown);
   fChain->SetBranchAddress("t1_t2_Mass_TauEnUp", &t1_t2_Mass_TauEnUp, &b_t1_t2_Mass_TauEnUp);
   fChain->SetBranchAddress("t1_t2_Mt", &t1_t2_Mt, &b_t1_t2_Mt);
   fChain->SetBranchAddress("t1_t2_MtTotal", &t1_t2_MtTotal, &b_t1_t2_MtTotal);
   fChain->SetBranchAddress("t1_t2_Mt_TauEnDown", &t1_t2_Mt_TauEnDown, &b_t1_t2_Mt_TauEnDown);
   fChain->SetBranchAddress("t1_t2_Mt_TauEnUp", &t1_t2_Mt_TauEnUp, &b_t1_t2_Mt_TauEnUp);
   fChain->SetBranchAddress("t1_t2_MvaMet", &t1_t2_MvaMet, &b_t1_t2_MvaMet);
   fChain->SetBranchAddress("t1_t2_MvaMetCovMatrix00", &t1_t2_MvaMetCovMatrix00, &b_t1_t2_MvaMetCovMatrix00);
   fChain->SetBranchAddress("t1_t2_MvaMetCovMatrix01", &t1_t2_MvaMetCovMatrix01, &b_t1_t2_MvaMetCovMatrix01);
   fChain->SetBranchAddress("t1_t2_MvaMetCovMatrix10", &t1_t2_MvaMetCovMatrix10, &b_t1_t2_MvaMetCovMatrix10);
   fChain->SetBranchAddress("t1_t2_MvaMetCovMatrix11", &t1_t2_MvaMetCovMatrix11, &b_t1_t2_MvaMetCovMatrix11);
   fChain->SetBranchAddress("t1_t2_MvaMetPhi", &t1_t2_MvaMetPhi, &b_t1_t2_MvaMetPhi);
   fChain->SetBranchAddress("t1_t2_PZeta", &t1_t2_PZeta, &b_t1_t2_PZeta);
   fChain->SetBranchAddress("t1_t2_PZetaLess0p85PZetaVis", &t1_t2_PZetaLess0p85PZetaVis, &b_t1_t2_PZetaLess0p85PZetaVis);
   fChain->SetBranchAddress("t1_t2_PZetaVis", &t1_t2_PZetaVis, &b_t1_t2_PZetaVis);
   fChain->SetBranchAddress("t1_t2_Phi", &t1_t2_Phi, &b_t1_t2_Phi);
   fChain->SetBranchAddress("t1_t2_Pt", &t1_t2_Pt, &b_t1_t2_Pt);
   fChain->SetBranchAddress("t1_t2_SS", &t1_t2_SS, &b_t1_t2_SS);
   fChain->SetBranchAddress("t1_t2_ToMETDPhi_Ty1", &t1_t2_ToMETDPhi_Ty1, &b_t1_t2_ToMETDPhi_Ty1);
   fChain->SetBranchAddress("t1_t2_collinearmass", &t1_t2_collinearmass, &b_t1_t2_collinearmass);
   fChain->SetBranchAddress("t1_t2_collinearmass_EleEnDown", &t1_t2_collinearmass_EleEnDown, &b_t1_t2_collinearmass_EleEnDown);
   fChain->SetBranchAddress("t1_t2_collinearmass_EleEnUp", &t1_t2_collinearmass_EleEnUp, &b_t1_t2_collinearmass_EleEnUp);
   fChain->SetBranchAddress("t1_t2_collinearmass_JetEnDown", &t1_t2_collinearmass_JetEnDown, &b_t1_t2_collinearmass_JetEnDown);
   fChain->SetBranchAddress("t1_t2_collinearmass_JetEnUp", &t1_t2_collinearmass_JetEnUp, &b_t1_t2_collinearmass_JetEnUp);
   fChain->SetBranchAddress("t1_t2_collinearmass_MuEnDown", &t1_t2_collinearmass_MuEnDown, &b_t1_t2_collinearmass_MuEnDown);
   fChain->SetBranchAddress("t1_t2_collinearmass_MuEnUp", &t1_t2_collinearmass_MuEnUp, &b_t1_t2_collinearmass_MuEnUp);
   fChain->SetBranchAddress("t1_t2_collinearmass_TauEnDown", &t1_t2_collinearmass_TauEnDown, &b_t1_t2_collinearmass_TauEnDown);
   fChain->SetBranchAddress("t1_t2_collinearmass_TauEnUp", &t1_t2_collinearmass_TauEnUp, &b_t1_t2_collinearmass_TauEnUp);
   fChain->SetBranchAddress("t1_t2_collinearmass_UnclusteredEnDown", &t1_t2_collinearmass_UnclusteredEnDown, &b_t1_t2_collinearmass_UnclusteredEnDown);
   fChain->SetBranchAddress("t1_t2_collinearmass_UnclusteredEnUp", &t1_t2_collinearmass_UnclusteredEnUp, &b_t1_t2_collinearmass_UnclusteredEnUp);
   fChain->SetBranchAddress("t1_t2_pt_tt", &t1_t2_pt_tt, &b_t1_t2_pt_tt);
   fChain->SetBranchAddress("t2AbsEta", &t2AbsEta, &b_t2AbsEta);
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
   fChain->SetBranchAddress("t2ByIsolationMVArun2v1PWdR03oldDMwLTraw", &t2ByIsolationMVArun2v1PWdR03oldDMwLTraw, &b_t2ByIsolationMVArun2v1PWdR03oldDMwLTraw);
   fChain->SetBranchAddress("t2ByIsolationMVArun2v1PWnewDMwLTraw", &t2ByIsolationMVArun2v1PWnewDMwLTraw, &b_t2ByIsolationMVArun2v1PWnewDMwLTraw);
   fChain->SetBranchAddress("t2ByIsolationMVArun2v1PWoldDMwLTraw", &t2ByIsolationMVArun2v1PWoldDMwLTraw, &b_t2ByIsolationMVArun2v1PWoldDMwLTraw);
   fChain->SetBranchAddress("t2ByLooseCombinedIsolationDeltaBetaCorr3Hits", &t2ByLooseCombinedIsolationDeltaBetaCorr3Hits, &b_t2ByLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT", &t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1DBnewDMwLT", &t2ByLooseIsolationMVArun2v1DBnewDMwLT, &b_t2ByLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1DBoldDMwLT", &t2ByLooseIsolationMVArun2v1DBoldDMwLT, &b_t2ByLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1PWdR03oldDMwLT", &t2ByLooseIsolationMVArun2v1PWdR03oldDMwLT, &b_t2ByLooseIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1PWnewDMwLT", &t2ByLooseIsolationMVArun2v1PWnewDMwLT, &b_t2ByLooseIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t2ByLooseIsolationMVArun2v1PWoldDMwLT", &t2ByLooseIsolationMVArun2v1PWoldDMwLT, &b_t2ByLooseIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t2ByMediumCombinedIsolationDeltaBetaCorr3Hits", &t2ByMediumCombinedIsolationDeltaBetaCorr3Hits, &b_t2ByMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT", &t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByMediumIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1DBnewDMwLT", &t2ByMediumIsolationMVArun2v1DBnewDMwLT, &b_t2ByMediumIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1DBoldDMwLT", &t2ByMediumIsolationMVArun2v1DBoldDMwLT, &b_t2ByMediumIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1PWdR03oldDMwLT", &t2ByMediumIsolationMVArun2v1PWdR03oldDMwLT, &b_t2ByMediumIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1PWnewDMwLT", &t2ByMediumIsolationMVArun2v1PWnewDMwLT, &b_t2ByMediumIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t2ByMediumIsolationMVArun2v1PWoldDMwLT", &t2ByMediumIsolationMVArun2v1PWoldDMwLT, &b_t2ByMediumIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t2ByPhotonPtSumOutsideSignalCone", &t2ByPhotonPtSumOutsideSignalCone, &b_t2ByPhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("t2ByTightCombinedIsolationDeltaBetaCorr3Hits", &t2ByTightCombinedIsolationDeltaBetaCorr3Hits, &b_t2ByTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1DBdR03oldDMwLT", &t2ByTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1DBnewDMwLT", &t2ByTightIsolationMVArun2v1DBnewDMwLT, &b_t2ByTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1DBoldDMwLT", &t2ByTightIsolationMVArun2v1DBoldDMwLT, &b_t2ByTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1PWdR03oldDMwLT", &t2ByTightIsolationMVArun2v1PWdR03oldDMwLT, &b_t2ByTightIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1PWnewDMwLT", &t2ByTightIsolationMVArun2v1PWnewDMwLT, &b_t2ByTightIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t2ByTightIsolationMVArun2v1PWoldDMwLT", &t2ByTightIsolationMVArun2v1PWoldDMwLT, &b_t2ByTightIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT", &t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByVLooseIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1DBnewDMwLT", &t2ByVLooseIsolationMVArun2v1DBnewDMwLT, &b_t2ByVLooseIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1DBoldDMwLT", &t2ByVLooseIsolationMVArun2v1DBoldDMwLT, &b_t2ByVLooseIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1PWdR03oldDMwLT", &t2ByVLooseIsolationMVArun2v1PWdR03oldDMwLT, &b_t2ByVLooseIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1PWnewDMwLT", &t2ByVLooseIsolationMVArun2v1PWnewDMwLT, &b_t2ByVLooseIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t2ByVLooseIsolationMVArun2v1PWoldDMwLT", &t2ByVLooseIsolationMVArun2v1PWoldDMwLT, &b_t2ByVLooseIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT", &t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1DBnewDMwLT", &t2ByVTightIsolationMVArun2v1DBnewDMwLT, &b_t2ByVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1DBoldDMwLT", &t2ByVTightIsolationMVArun2v1DBoldDMwLT, &b_t2ByVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1PWdR03oldDMwLT", &t2ByVTightIsolationMVArun2v1PWdR03oldDMwLT, &b_t2ByVTightIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1PWnewDMwLT", &t2ByVTightIsolationMVArun2v1PWnewDMwLT, &b_t2ByVTightIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t2ByVTightIsolationMVArun2v1PWoldDMwLT", &t2ByVTightIsolationMVArun2v1PWoldDMwLT, &b_t2ByVTightIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT", &t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT, &b_t2ByVVTightIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1DBnewDMwLT", &t2ByVVTightIsolationMVArun2v1DBnewDMwLT, &b_t2ByVVTightIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1DBoldDMwLT", &t2ByVVTightIsolationMVArun2v1DBoldDMwLT, &b_t2ByVVTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1PWdR03oldDMwLT", &t2ByVVTightIsolationMVArun2v1PWdR03oldDMwLT, &b_t2ByVVTightIsolationMVArun2v1PWdR03oldDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1PWnewDMwLT", &t2ByVVTightIsolationMVArun2v1PWnewDMwLT, &b_t2ByVVTightIsolationMVArun2v1PWnewDMwLT);
   fChain->SetBranchAddress("t2ByVVTightIsolationMVArun2v1PWoldDMwLT", &t2ByVVTightIsolationMVArun2v1PWoldDMwLT, &b_t2ByVVTightIsolationMVArun2v1PWoldDMwLT);
   fChain->SetBranchAddress("t2Charge", &t2Charge, &b_t2Charge);
   fChain->SetBranchAddress("t2ChargedIsoPtSum", &t2ChargedIsoPtSum, &b_t2ChargedIsoPtSum);
   fChain->SetBranchAddress("t2ChargedIsoPtSumdR03", &t2ChargedIsoPtSumdR03, &b_t2ChargedIsoPtSumdR03);
   fChain->SetBranchAddress("t2ComesFromHiggs", &t2ComesFromHiggs, &b_t2ComesFromHiggs);
   fChain->SetBranchAddress("t2DPhiToPfMet_ElectronEnDown", &t2DPhiToPfMet_ElectronEnDown, &b_t2DPhiToPfMet_ElectronEnDown);
   fChain->SetBranchAddress("t2DPhiToPfMet_ElectronEnUp", &t2DPhiToPfMet_ElectronEnUp, &b_t2DPhiToPfMet_ElectronEnUp);
   fChain->SetBranchAddress("t2DPhiToPfMet_JetEnDown", &t2DPhiToPfMet_JetEnDown, &b_t2DPhiToPfMet_JetEnDown);
   fChain->SetBranchAddress("t2DPhiToPfMet_JetEnUp", &t2DPhiToPfMet_JetEnUp, &b_t2DPhiToPfMet_JetEnUp);
   fChain->SetBranchAddress("t2DPhiToPfMet_JetResDown", &t2DPhiToPfMet_JetResDown, &b_t2DPhiToPfMet_JetResDown);
   fChain->SetBranchAddress("t2DPhiToPfMet_JetResUp", &t2DPhiToPfMet_JetResUp, &b_t2DPhiToPfMet_JetResUp);
   fChain->SetBranchAddress("t2DPhiToPfMet_MuonEnDown", &t2DPhiToPfMet_MuonEnDown, &b_t2DPhiToPfMet_MuonEnDown);
   fChain->SetBranchAddress("t2DPhiToPfMet_MuonEnUp", &t2DPhiToPfMet_MuonEnUp, &b_t2DPhiToPfMet_MuonEnUp);
   fChain->SetBranchAddress("t2DPhiToPfMet_PhotonEnDown", &t2DPhiToPfMet_PhotonEnDown, &b_t2DPhiToPfMet_PhotonEnDown);
   fChain->SetBranchAddress("t2DPhiToPfMet_PhotonEnUp", &t2DPhiToPfMet_PhotonEnUp, &b_t2DPhiToPfMet_PhotonEnUp);
   fChain->SetBranchAddress("t2DPhiToPfMet_TauEnDown", &t2DPhiToPfMet_TauEnDown, &b_t2DPhiToPfMet_TauEnDown);
   fChain->SetBranchAddress("t2DPhiToPfMet_TauEnUp", &t2DPhiToPfMet_TauEnUp, &b_t2DPhiToPfMet_TauEnUp);
   fChain->SetBranchAddress("t2DPhiToPfMet_UnclusteredEnDown", &t2DPhiToPfMet_UnclusteredEnDown, &b_t2DPhiToPfMet_UnclusteredEnDown);
   fChain->SetBranchAddress("t2DPhiToPfMet_UnclusteredEnUp", &t2DPhiToPfMet_UnclusteredEnUp, &b_t2DPhiToPfMet_UnclusteredEnUp);
   fChain->SetBranchAddress("t2DPhiToPfMet_type1", &t2DPhiToPfMet_type1, &b_t2DPhiToPfMet_type1);
   fChain->SetBranchAddress("t2DecayMode", &t2DecayMode, &b_t2DecayMode);
   fChain->SetBranchAddress("t2DecayModeFinding", &t2DecayModeFinding, &b_t2DecayModeFinding);
   fChain->SetBranchAddress("t2DecayModeFindingNewDMs", &t2DecayModeFindingNewDMs, &b_t2DecayModeFindingNewDMs);
   fChain->SetBranchAddress("t2ElecOverlap", &t2ElecOverlap, &b_t2ElecOverlap);
   fChain->SetBranchAddress("t2Eta", &t2Eta, &b_t2Eta);
   fChain->SetBranchAddress("t2Eta_TauEnDown", &t2Eta_TauEnDown, &b_t2Eta_TauEnDown);
   fChain->SetBranchAddress("t2Eta_TauEnUp", &t2Eta_TauEnUp, &b_t2Eta_TauEnUp);
   fChain->SetBranchAddress("t2FootprintCorrection", &t2FootprintCorrection, &b_t2FootprintCorrection);
   fChain->SetBranchAddress("t2FootprintCorrectiondR03", &t2FootprintCorrectiondR03, &b_t2FootprintCorrectiondR03);
   fChain->SetBranchAddress("t2GenCharge", &t2GenCharge, &b_t2GenCharge);
   fChain->SetBranchAddress("t2GenDecayMode", &t2GenDecayMode, &b_t2GenDecayMode);
   fChain->SetBranchAddress("t2GenEnergy", &t2GenEnergy, &b_t2GenEnergy);
   fChain->SetBranchAddress("t2GenEta", &t2GenEta, &b_t2GenEta);
   fChain->SetBranchAddress("t2GenIsPrompt", &t2GenIsPrompt, &b_t2GenIsPrompt);
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
   fChain->SetBranchAddress("t2GlobalMuonVtxOverlap", &t2GlobalMuonVtxOverlap, &b_t2GlobalMuonVtxOverlap);
   fChain->SetBranchAddress("t2JetArea", &t2JetArea, &b_t2JetArea);
   fChain->SetBranchAddress("t2JetBtag", &t2JetBtag, &b_t2JetBtag);
   fChain->SetBranchAddress("t2JetEtaEtaMoment", &t2JetEtaEtaMoment, &b_t2JetEtaEtaMoment);
   fChain->SetBranchAddress("t2JetEtaPhiMoment", &t2JetEtaPhiMoment, &b_t2JetEtaPhiMoment);
   fChain->SetBranchAddress("t2JetEtaPhiSpread", &t2JetEtaPhiSpread, &b_t2JetEtaPhiSpread);
   fChain->SetBranchAddress("t2JetHadronFlavour", &t2JetHadronFlavour, &b_t2JetHadronFlavour);
   fChain->SetBranchAddress("t2JetPFCISVBtag", &t2JetPFCISVBtag, &b_t2JetPFCISVBtag);
   fChain->SetBranchAddress("t2JetPartonFlavour", &t2JetPartonFlavour, &b_t2JetPartonFlavour);
   fChain->SetBranchAddress("t2JetPhiPhiMoment", &t2JetPhiPhiMoment, &b_t2JetPhiPhiMoment);
   fChain->SetBranchAddress("t2JetPt", &t2JetPt, &b_t2JetPt);
   fChain->SetBranchAddress("t2LeadTrackPt", &t2LeadTrackPt, &b_t2LeadTrackPt);
   fChain->SetBranchAddress("t2LowestMll", &t2LowestMll, &b_t2LowestMll);
   fChain->SetBranchAddress("t2Mass", &t2Mass, &b_t2Mass);
   fChain->SetBranchAddress("t2Mass_TauEnDown", &t2Mass_TauEnDown, &b_t2Mass_TauEnDown);
   fChain->SetBranchAddress("t2Mass_TauEnUp", &t2Mass_TauEnUp, &b_t2Mass_TauEnUp);
   fChain->SetBranchAddress("t2MatchesDoubleTau32Filter", &t2MatchesDoubleTau32Filter, &b_t2MatchesDoubleTau32Filter);
   fChain->SetBranchAddress("t2MatchesDoubleTau32Path", &t2MatchesDoubleTau32Path, &b_t2MatchesDoubleTau32Path);
   fChain->SetBranchAddress("t2MatchesDoubleTau35Filter", &t2MatchesDoubleTau35Filter, &b_t2MatchesDoubleTau35Filter);
   fChain->SetBranchAddress("t2MatchesDoubleTau35Path", &t2MatchesDoubleTau35Path, &b_t2MatchesDoubleTau35Path);
   fChain->SetBranchAddress("t2MatchesDoubleTau40Filter", &t2MatchesDoubleTau40Filter, &b_t2MatchesDoubleTau40Filter);
   fChain->SetBranchAddress("t2MatchesDoubleTau40Path", &t2MatchesDoubleTau40Path, &b_t2MatchesDoubleTau40Path);
   fChain->SetBranchAddress("t2MatchesDoubleTauCmbIso35RegFilter", &t2MatchesDoubleTauCmbIso35RegFilter, &b_t2MatchesDoubleTauCmbIso35RegFilter);
   fChain->SetBranchAddress("t2MatchesDoubleTauCmbIso35RegPath", &t2MatchesDoubleTauCmbIso35RegPath, &b_t2MatchesDoubleTauCmbIso35RegPath);
   fChain->SetBranchAddress("t2MatchesDoubleTauCmbIso40Filter", &t2MatchesDoubleTauCmbIso40Filter, &b_t2MatchesDoubleTauCmbIso40Filter);
   fChain->SetBranchAddress("t2MatchesDoubleTauCmbIso40Path", &t2MatchesDoubleTauCmbIso40Path, &b_t2MatchesDoubleTauCmbIso40Path);
   fChain->SetBranchAddress("t2MatchesDoubleTauCmbIso40RegFilter", &t2MatchesDoubleTauCmbIso40RegFilter, &b_t2MatchesDoubleTauCmbIso40RegFilter);
   fChain->SetBranchAddress("t2MatchesDoubleTauCmbIso40RegPath", &t2MatchesDoubleTauCmbIso40RegPath, &b_t2MatchesDoubleTauCmbIso40RegPath);
   fChain->SetBranchAddress("t2MatchesEle24Tau20Filter", &t2MatchesEle24Tau20Filter, &b_t2MatchesEle24Tau20Filter);
   fChain->SetBranchAddress("t2MatchesEle24Tau20L1Path", &t2MatchesEle24Tau20L1Path, &b_t2MatchesEle24Tau20L1Path);
   fChain->SetBranchAddress("t2MatchesEle24Tau20Path", &t2MatchesEle24Tau20Path, &b_t2MatchesEle24Tau20Path);
   fChain->SetBranchAddress("t2MatchesEle24Tau20sL1Filter", &t2MatchesEle24Tau20sL1Filter, &b_t2MatchesEle24Tau20sL1Filter);
   fChain->SetBranchAddress("t2MatchesEle24Tau30Filter", &t2MatchesEle24Tau30Filter, &b_t2MatchesEle24Tau30Filter);
   fChain->SetBranchAddress("t2MatchesEle24Tau30Path", &t2MatchesEle24Tau30Path, &b_t2MatchesEle24Tau30Path);
   fChain->SetBranchAddress("t2MatchesMu19Tau20Filter", &t2MatchesMu19Tau20Filter, &b_t2MatchesMu19Tau20Filter);
   fChain->SetBranchAddress("t2MatchesMu19Tau20Path", &t2MatchesMu19Tau20Path, &b_t2MatchesMu19Tau20Path);
   fChain->SetBranchAddress("t2MatchesMu19Tau20sL1Filter", &t2MatchesMu19Tau20sL1Filter, &b_t2MatchesMu19Tau20sL1Filter);
   fChain->SetBranchAddress("t2MatchesMu19Tau20sL1Path", &t2MatchesMu19Tau20sL1Path, &b_t2MatchesMu19Tau20sL1Path);
   fChain->SetBranchAddress("t2MatchesMu21Tau20sL1Filter", &t2MatchesMu21Tau20sL1Filter, &b_t2MatchesMu21Tau20sL1Filter);
   fChain->SetBranchAddress("t2MatchesMu21Tau20sL1Path", &t2MatchesMu21Tau20sL1Path, &b_t2MatchesMu21Tau20sL1Path);
   fChain->SetBranchAddress("t2MtToPfMet_ElectronEnDown", &t2MtToPfMet_ElectronEnDown, &b_t2MtToPfMet_ElectronEnDown);
   fChain->SetBranchAddress("t2MtToPfMet_ElectronEnUp", &t2MtToPfMet_ElectronEnUp, &b_t2MtToPfMet_ElectronEnUp);
   fChain->SetBranchAddress("t2MtToPfMet_JetEnDown", &t2MtToPfMet_JetEnDown, &b_t2MtToPfMet_JetEnDown);
   fChain->SetBranchAddress("t2MtToPfMet_JetEnUp", &t2MtToPfMet_JetEnUp, &b_t2MtToPfMet_JetEnUp);
   fChain->SetBranchAddress("t2MtToPfMet_JetResDown", &t2MtToPfMet_JetResDown, &b_t2MtToPfMet_JetResDown);
   fChain->SetBranchAddress("t2MtToPfMet_JetResUp", &t2MtToPfMet_JetResUp, &b_t2MtToPfMet_JetResUp);
   fChain->SetBranchAddress("t2MtToPfMet_MuonEnDown", &t2MtToPfMet_MuonEnDown, &b_t2MtToPfMet_MuonEnDown);
   fChain->SetBranchAddress("t2MtToPfMet_MuonEnUp", &t2MtToPfMet_MuonEnUp, &b_t2MtToPfMet_MuonEnUp);
   fChain->SetBranchAddress("t2MtToPfMet_PhotonEnDown", &t2MtToPfMet_PhotonEnDown, &b_t2MtToPfMet_PhotonEnDown);
   fChain->SetBranchAddress("t2MtToPfMet_PhotonEnUp", &t2MtToPfMet_PhotonEnUp, &b_t2MtToPfMet_PhotonEnUp);
   fChain->SetBranchAddress("t2MtToPfMet_Raw", &t2MtToPfMet_Raw, &b_t2MtToPfMet_Raw);
   fChain->SetBranchAddress("t2MtToPfMet_TauEnDown", &t2MtToPfMet_TauEnDown, &b_t2MtToPfMet_TauEnDown);
   fChain->SetBranchAddress("t2MtToPfMet_TauEnUp", &t2MtToPfMet_TauEnUp, &b_t2MtToPfMet_TauEnUp);
   fChain->SetBranchAddress("t2MtToPfMet_UnclusteredEnDown", &t2MtToPfMet_UnclusteredEnDown, &b_t2MtToPfMet_UnclusteredEnDown);
   fChain->SetBranchAddress("t2MtToPfMet_UnclusteredEnUp", &t2MtToPfMet_UnclusteredEnUp, &b_t2MtToPfMet_UnclusteredEnUp);
   fChain->SetBranchAddress("t2MtToPfMet_type1", &t2MtToPfMet_type1, &b_t2MtToPfMet_type1);
   fChain->SetBranchAddress("t2MuOverlap", &t2MuOverlap, &b_t2MuOverlap);
   fChain->SetBranchAddress("t2MuonIdIsoStdVtxOverlap", &t2MuonIdIsoStdVtxOverlap, &b_t2MuonIdIsoStdVtxOverlap);
   fChain->SetBranchAddress("t2MuonIdIsoVtxOverlap", &t2MuonIdIsoVtxOverlap, &b_t2MuonIdIsoVtxOverlap);
   fChain->SetBranchAddress("t2MuonIdVtxOverlap", &t2MuonIdVtxOverlap, &b_t2MuonIdVtxOverlap);
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
   fChain->SetBranchAddress("t2Phi_TauEnDown", &t2Phi_TauEnDown, &b_t2Phi_TauEnDown);
   fChain->SetBranchAddress("t2Phi_TauEnUp", &t2Phi_TauEnUp, &b_t2Phi_TauEnUp);
   fChain->SetBranchAddress("t2PhotonPtSumOutsideSignalCone", &t2PhotonPtSumOutsideSignalCone, &b_t2PhotonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("t2PhotonPtSumOutsideSignalConedR03", &t2PhotonPtSumOutsideSignalConedR03, &b_t2PhotonPtSumOutsideSignalConedR03);
   fChain->SetBranchAddress("t2Pt", &t2Pt, &b_t2Pt);
   fChain->SetBranchAddress("t2Pt_TauEnDown", &t2Pt_TauEnDown, &b_t2Pt_TauEnDown);
   fChain->SetBranchAddress("t2Pt_TauEnUp", &t2Pt_TauEnUp, &b_t2Pt_TauEnUp);
   fChain->SetBranchAddress("t2PuCorrPtSum", &t2PuCorrPtSum, &b_t2PuCorrPtSum);
   fChain->SetBranchAddress("t2Rank", &t2Rank, &b_t2Rank);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTLoose", &t2RerunMVArun2v1DBoldDMwLTLoose, &b_t2RerunMVArun2v1DBoldDMwLTLoose);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTMedium", &t2RerunMVArun2v1DBoldDMwLTMedium, &b_t2RerunMVArun2v1DBoldDMwLTMedium);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTTight", &t2RerunMVArun2v1DBoldDMwLTTight, &b_t2RerunMVArun2v1DBoldDMwLTTight);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTVLoose", &t2RerunMVArun2v1DBoldDMwLTVLoose, &b_t2RerunMVArun2v1DBoldDMwLTVLoose);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTVTight", &t2RerunMVArun2v1DBoldDMwLTVTight, &b_t2RerunMVArun2v1DBoldDMwLTVTight);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTVVTight", &t2RerunMVArun2v1DBoldDMwLTVVTight, &b_t2RerunMVArun2v1DBoldDMwLTVVTight);
   fChain->SetBranchAddress("t2RerunMVArun2v1DBoldDMwLTraw", &t2RerunMVArun2v1DBoldDMwLTraw, &b_t2RerunMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("t2VZ", &t2VZ, &b_t2VZ);
   fChain->SetBranchAddress("t2ZTTGenDR", &t2ZTTGenDR, &b_t2ZTTGenDR);
   fChain->SetBranchAddress("t2ZTTGenEta", &t2ZTTGenEta, &b_t2ZTTGenEta);
   fChain->SetBranchAddress("t2ZTTGenMatching", &t2ZTTGenMatching, &b_t2ZTTGenMatching);
   fChain->SetBranchAddress("t2ZTTGenPhi", &t2ZTTGenPhi, &b_t2ZTTGenPhi);
   fChain->SetBranchAddress("t2ZTTGenPt", &t2ZTTGenPt, &b_t2ZTTGenPt);
   fChain->SetBranchAddress("t2_t1_collinearmass", &t2_t1_collinearmass, &b_t2_t1_collinearmass);
   fChain->SetBranchAddress("t2_t1_collinearmass_JetEnDown", &t2_t1_collinearmass_JetEnDown, &b_t2_t1_collinearmass_JetEnDown);
   fChain->SetBranchAddress("t2_t1_collinearmass_JetEnUp", &t2_t1_collinearmass_JetEnUp, &b_t2_t1_collinearmass_JetEnUp);
   fChain->SetBranchAddress("t2_t1_collinearmass_UnclusteredEnDown", &t2_t1_collinearmass_UnclusteredEnDown, &b_t2_t1_collinearmass_UnclusteredEnDown);
   fChain->SetBranchAddress("t2_t1_collinearmass_UnclusteredEnUp", &t2_t1_collinearmass_UnclusteredEnUp, &b_t2_t1_collinearmass_UnclusteredEnUp);
   fChain->SetBranchAddress("tauVetoPt20Loose3HitsVtx", &tauVetoPt20Loose3HitsVtx, &b_tauVetoPt20Loose3HitsVtx);
   fChain->SetBranchAddress("tauVetoPt20TightMVALTVtx", &tauVetoPt20TightMVALTVtx, &b_tauVetoPt20TightMVALTVtx);
   fChain->SetBranchAddress("topQuarkPt1", &topQuarkPt1, &b_topQuarkPt1);
   fChain->SetBranchAddress("topQuarkPt2", &topQuarkPt2, &b_topQuarkPt2);
   fChain->SetBranchAddress("tripleEGroup", &tripleEGroup, &b_tripleEGroup);
   fChain->SetBranchAddress("tripleEPass", &tripleEPass, &b_tripleEPass);
   fChain->SetBranchAddress("tripleEPrescale", &tripleEPrescale, &b_tripleEPrescale);
   fChain->SetBranchAddress("tripleMuGroup", &tripleMuGroup, &b_tripleMuGroup);
   fChain->SetBranchAddress("tripleMuPass", &tripleMuPass, &b_tripleMuPass);
   fChain->SetBranchAddress("tripleMuPrescale", &tripleMuPrescale, &b_tripleMuPrescale);
   fChain->SetBranchAddress("type1_pfMetEt", &type1_pfMetEt, &b_type1_pfMetEt);
   fChain->SetBranchAddress("type1_pfMetPhi", &type1_pfMetPhi, &b_type1_pfMetPhi);
   //   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_ElectronEnDown", &type1_pfMet_shiftedPhi_ElectronEnDown, &b_type1_pfMet_shiftedPhi_ElectronEnDown);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPhi_ElectronEnUp", &type1_pfMet_shiftedPhi_ElectronEnUp, &b_type1_pfMet_shiftedPhi_ElectronEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEnDown", &type1_pfMet_shiftedPhi_JetEnDown, &b_type1_pfMet_shiftedPhi_JetEnDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetEnUp", &type1_pfMet_shiftedPhi_JetEnUp, &b_type1_pfMet_shiftedPhi_JetEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetResDown", &type1_pfMet_shiftedPhi_JetResDown, &b_type1_pfMet_shiftedPhi_JetResDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_JetResUp", &type1_pfMet_shiftedPhi_JetResUp, &b_type1_pfMet_shiftedPhi_JetResUp);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPhi_MuonEnDown", &type1_pfMet_shiftedPhi_MuonEnDown, &b_type1_pfMet_shiftedPhi_MuonEnDown);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPhi_MuonEnUp", &type1_pfMet_shiftedPhi_MuonEnUp, &b_type1_pfMet_shiftedPhi_MuonEnUp);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPhi_PhotonEnDown", &type1_pfMet_shiftedPhi_PhotonEnDown, &b_type1_pfMet_shiftedPhi_PhotonEnDown);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPhi_PhotonEnUp", &type1_pfMet_shiftedPhi_PhotonEnUp, &b_type1_pfMet_shiftedPhi_PhotonEnUp);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPhi_TauEnDown", &type1_pfMet_shiftedPhi_TauEnDown, &b_type1_pfMet_shiftedPhi_TauEnDown);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPhi_TauEnUp", &type1_pfMet_shiftedPhi_TauEnUp, &b_type1_pfMet_shiftedPhi_TauEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_UnclusteredEnDown", &type1_pfMet_shiftedPhi_UnclusteredEnDown, &b_type1_pfMet_shiftedPhi_UnclusteredEnDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPhi_UnclusteredEnUp", &type1_pfMet_shiftedPhi_UnclusteredEnUp, &b_type1_pfMet_shiftedPhi_UnclusteredEnUp);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPt_ElectronEnDown", &type1_pfMet_shiftedPt_ElectronEnDown, &b_type1_pfMet_shiftedPt_ElectronEnDown);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPt_ElectronEnUp", &type1_pfMet_shiftedPt_ElectronEnUp, &b_type1_pfMet_shiftedPt_ElectronEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEnDown", &type1_pfMet_shiftedPt_JetEnDown, &b_type1_pfMet_shiftedPt_JetEnDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetEnUp", &type1_pfMet_shiftedPt_JetEnUp, &b_type1_pfMet_shiftedPt_JetEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetResDown", &type1_pfMet_shiftedPt_JetResDown, &b_type1_pfMet_shiftedPt_JetResDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_JetResUp", &type1_pfMet_shiftedPt_JetResUp, &b_type1_pfMet_shiftedPt_JetResUp);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPt_MuonEnDown", &type1_pfMet_shiftedPt_MuonEnDown, &b_type1_pfMet_shiftedPt_MuonEnDown);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPt_MuonEnUp", &type1_pfMet_shiftedPt_MuonEnUp, &b_type1_pfMet_shiftedPt_MuonEnUp);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPt_PhotonEnDown", &type1_pfMet_shiftedPt_PhotonEnDown, &b_type1_pfMet_shiftedPt_PhotonEnDown);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPt_PhotonEnUp", &type1_pfMet_shiftedPt_PhotonEnUp, &b_type1_pfMet_shiftedPt_PhotonEnUp);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPt_TauEnDown", &type1_pfMet_shiftedPt_TauEnDown, &b_type1_pfMet_shiftedPt_TauEnDown);
   //fChain->SetBranchAddress("type1_pfMet_shiftedPt_TauEnUp", &type1_pfMet_shiftedPt_TauEnUp, &b_type1_pfMet_shiftedPt_TauEnUp);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_UnclusteredEnDown", &type1_pfMet_shiftedPt_UnclusteredEnDown, &b_type1_pfMet_shiftedPt_UnclusteredEnDown);
   fChain->SetBranchAddress("type1_pfMet_shiftedPt_UnclusteredEnUp", &type1_pfMet_shiftedPt_UnclusteredEnUp, &b_type1_pfMet_shiftedPt_UnclusteredEnUp);
   fChain->SetBranchAddress("vbfDeta", &vbfDeta, &b_vbfDeta);
   fChain->SetBranchAddress("vbfDeta_JetEnDown", &vbfDeta_JetEnDown, &b_vbfDeta_JetEnDown);
   fChain->SetBranchAddress("vbfDeta_JetEnUp", &vbfDeta_JetEnUp, &b_vbfDeta_JetEnUp);
   fChain->SetBranchAddress("vbfDijetrap", &vbfDijetrap, &b_vbfDijetrap);
   fChain->SetBranchAddress("vbfDijetrap_JetEnDown", &vbfDijetrap_JetEnDown, &b_vbfDijetrap_JetEnDown);
   fChain->SetBranchAddress("vbfDijetrap_JetEnUp", &vbfDijetrap_JetEnUp, &b_vbfDijetrap_JetEnUp);
   fChain->SetBranchAddress("vbfDphi", &vbfDphi, &b_vbfDphi);
   fChain->SetBranchAddress("vbfDphi_JetEnDown", &vbfDphi_JetEnDown, &b_vbfDphi_JetEnDown);
   fChain->SetBranchAddress("vbfDphi_JetEnUp", &vbfDphi_JetEnUp, &b_vbfDphi_JetEnUp);
   fChain->SetBranchAddress("vbfDphihj", &vbfDphihj, &b_vbfDphihj);
   fChain->SetBranchAddress("vbfDphihj_JetEnDown", &vbfDphihj_JetEnDown, &b_vbfDphihj_JetEnDown);
   fChain->SetBranchAddress("vbfDphihj_JetEnUp", &vbfDphihj_JetEnUp, &b_vbfDphihj_JetEnUp);
   fChain->SetBranchAddress("vbfDphihjnomet", &vbfDphihjnomet, &b_vbfDphihjnomet);
   fChain->SetBranchAddress("vbfDphihjnomet_JetEnDown", &vbfDphihjnomet_JetEnDown, &b_vbfDphihjnomet_JetEnDown);
   fChain->SetBranchAddress("vbfDphihjnomet_JetEnUp", &vbfDphihjnomet_JetEnUp, &b_vbfDphihjnomet_JetEnUp);
   fChain->SetBranchAddress("vbfHrap", &vbfHrap, &b_vbfHrap);
   fChain->SetBranchAddress("vbfHrap_JetEnDown", &vbfHrap_JetEnDown, &b_vbfHrap_JetEnDown);
   fChain->SetBranchAddress("vbfHrap_JetEnUp", &vbfHrap_JetEnUp, &b_vbfHrap_JetEnUp);
   fChain->SetBranchAddress("vbfJetVeto20", &vbfJetVeto20, &b_vbfJetVeto20);
   fChain->SetBranchAddress("vbfJetVeto20_JetEnDown", &vbfJetVeto20_JetEnDown, &b_vbfJetVeto20_JetEnDown);
   fChain->SetBranchAddress("vbfJetVeto20_JetEnUp", &vbfJetVeto20_JetEnUp, &b_vbfJetVeto20_JetEnUp);
   fChain->SetBranchAddress("vbfJetVeto30", &vbfJetVeto30, &b_vbfJetVeto30);
   fChain->SetBranchAddress("vbfJetVeto30_JetEnDown", &vbfJetVeto30_JetEnDown, &b_vbfJetVeto30_JetEnDown);
   fChain->SetBranchAddress("vbfJetVeto30_JetEnUp", &vbfJetVeto30_JetEnUp, &b_vbfJetVeto30_JetEnUp);
   fChain->SetBranchAddress("vbfMVA", &vbfMVA, &b_vbfMVA);
   fChain->SetBranchAddress("vbfMVA_JetEnDown", &vbfMVA_JetEnDown, &b_vbfMVA_JetEnDown);
   fChain->SetBranchAddress("vbfMVA_JetEnUp", &vbfMVA_JetEnUp, &b_vbfMVA_JetEnUp);
   fChain->SetBranchAddress("vbfMass", &vbfMass, &b_vbfMass);
   fChain->SetBranchAddress("vbfMass_JetAbsoluteFlavMapDown", &vbfMass_JetAbsoluteFlavMapDown, &b_vbfMass_JetAbsoluteFlavMapDown);
   fChain->SetBranchAddress("vbfMass_JetAbsoluteFlavMapUp", &vbfMass_JetAbsoluteFlavMapUp, &b_vbfMass_JetAbsoluteFlavMapUp);
   fChain->SetBranchAddress("vbfMass_JetAbsoluteMPFBiasDown", &vbfMass_JetAbsoluteMPFBiasDown, &b_vbfMass_JetAbsoluteMPFBiasDown);
   fChain->SetBranchAddress("vbfMass_JetAbsoluteMPFBiasUp", &vbfMass_JetAbsoluteMPFBiasUp, &b_vbfMass_JetAbsoluteMPFBiasUp);
   fChain->SetBranchAddress("vbfMass_JetAbsoluteScaleDown", &vbfMass_JetAbsoluteScaleDown, &b_vbfMass_JetAbsoluteScaleDown);
   fChain->SetBranchAddress("vbfMass_JetAbsoluteScaleUp", &vbfMass_JetAbsoluteScaleUp, &b_vbfMass_JetAbsoluteScaleUp);
   fChain->SetBranchAddress("vbfMass_JetAbsoluteStatDown", &vbfMass_JetAbsoluteStatDown, &b_vbfMass_JetAbsoluteStatDown);
   fChain->SetBranchAddress("vbfMass_JetAbsoluteStatUp", &vbfMass_JetAbsoluteStatUp, &b_vbfMass_JetAbsoluteStatUp);
   fChain->SetBranchAddress("vbfMass_JetClosureDown", &vbfMass_JetClosureDown, &b_vbfMass_JetClosureDown);
   fChain->SetBranchAddress("vbfMass_JetClosureUp", &vbfMass_JetClosureUp, &b_vbfMass_JetClosureUp);
   fChain->SetBranchAddress("vbfMass_JetEnDown", &vbfMass_JetEnDown, &b_vbfMass_JetEnDown);
   fChain->SetBranchAddress("vbfMass_JetEnUp", &vbfMass_JetEnUp, &b_vbfMass_JetEnUp);
   fChain->SetBranchAddress("vbfMass_JetFlavorQCDDown", &vbfMass_JetFlavorQCDDown, &b_vbfMass_JetFlavorQCDDown);
   fChain->SetBranchAddress("vbfMass_JetFlavorQCDUp", &vbfMass_JetFlavorQCDUp, &b_vbfMass_JetFlavorQCDUp);
   fChain->SetBranchAddress("vbfMass_JetFragmentationDown", &vbfMass_JetFragmentationDown, &b_vbfMass_JetFragmentationDown);
   fChain->SetBranchAddress("vbfMass_JetFragmentationUp", &vbfMass_JetFragmentationUp, &b_vbfMass_JetFragmentationUp);
   fChain->SetBranchAddress("vbfMass_JetPileUpDataMCDown", &vbfMass_JetPileUpDataMCDown, &b_vbfMass_JetPileUpDataMCDown);
   fChain->SetBranchAddress("vbfMass_JetPileUpDataMCUp", &vbfMass_JetPileUpDataMCUp, &b_vbfMass_JetPileUpDataMCUp);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtBBDown", &vbfMass_JetPileUpPtBBDown, &b_vbfMass_JetPileUpPtBBDown);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtBBUp", &vbfMass_JetPileUpPtBBUp, &b_vbfMass_JetPileUpPtBBUp);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtEC1Down", &vbfMass_JetPileUpPtEC1Down, &b_vbfMass_JetPileUpPtEC1Down);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtEC1Up", &vbfMass_JetPileUpPtEC1Up, &b_vbfMass_JetPileUpPtEC1Up);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtEC2Down", &vbfMass_JetPileUpPtEC2Down, &b_vbfMass_JetPileUpPtEC2Down);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtEC2Up", &vbfMass_JetPileUpPtEC2Up, &b_vbfMass_JetPileUpPtEC2Up);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtHFDown", &vbfMass_JetPileUpPtHFDown, &b_vbfMass_JetPileUpPtHFDown);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtHFUp", &vbfMass_JetPileUpPtHFUp, &b_vbfMass_JetPileUpPtHFUp);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtRefDown", &vbfMass_JetPileUpPtRefDown, &b_vbfMass_JetPileUpPtRefDown);
   fChain->SetBranchAddress("vbfMass_JetPileUpPtRefUp", &vbfMass_JetPileUpPtRefUp, &b_vbfMass_JetPileUpPtRefUp);
   fChain->SetBranchAddress("vbfMass_JetRelativeBalDown", &vbfMass_JetRelativeBalDown, &b_vbfMass_JetRelativeBalDown);
   fChain->SetBranchAddress("vbfMass_JetRelativeBalUp", &vbfMass_JetRelativeBalUp, &b_vbfMass_JetRelativeBalUp);
   fChain->SetBranchAddress("vbfMass_JetRelativeFSRDown", &vbfMass_JetRelativeFSRDown, &b_vbfMass_JetRelativeFSRDown);
   fChain->SetBranchAddress("vbfMass_JetRelativeFSRUp", &vbfMass_JetRelativeFSRUp, &b_vbfMass_JetRelativeFSRUp);
   fChain->SetBranchAddress("vbfMass_JetRelativeJEREC1Down", &vbfMass_JetRelativeJEREC1Down, &b_vbfMass_JetRelativeJEREC1Down);
   fChain->SetBranchAddress("vbfMass_JetRelativeJEREC1Up", &vbfMass_JetRelativeJEREC1Up, &b_vbfMass_JetRelativeJEREC1Up);
   fChain->SetBranchAddress("vbfMass_JetRelativeJEREC2Down", &vbfMass_JetRelativeJEREC2Down, &b_vbfMass_JetRelativeJEREC2Down);
   fChain->SetBranchAddress("vbfMass_JetRelativeJEREC2Up", &vbfMass_JetRelativeJEREC2Up, &b_vbfMass_JetRelativeJEREC2Up);
   fChain->SetBranchAddress("vbfMass_JetRelativeJERHFDown", &vbfMass_JetRelativeJERHFDown, &b_vbfMass_JetRelativeJERHFDown);
   fChain->SetBranchAddress("vbfMass_JetRelativeJERHFUp", &vbfMass_JetRelativeJERHFUp, &b_vbfMass_JetRelativeJERHFUp);
   fChain->SetBranchAddress("vbfMass_JetRelativePtBBDown", &vbfMass_JetRelativePtBBDown, &b_vbfMass_JetRelativePtBBDown);
   fChain->SetBranchAddress("vbfMass_JetRelativePtBBUp", &vbfMass_JetRelativePtBBUp, &b_vbfMass_JetRelativePtBBUp);
   fChain->SetBranchAddress("vbfMass_JetRelativePtEC1Down", &vbfMass_JetRelativePtEC1Down, &b_vbfMass_JetRelativePtEC1Down);
   fChain->SetBranchAddress("vbfMass_JetRelativePtEC1Up", &vbfMass_JetRelativePtEC1Up, &b_vbfMass_JetRelativePtEC1Up);
   fChain->SetBranchAddress("vbfMass_JetRelativePtEC2Down", &vbfMass_JetRelativePtEC2Down, &b_vbfMass_JetRelativePtEC2Down);
   fChain->SetBranchAddress("vbfMass_JetRelativePtEC2Up", &vbfMass_JetRelativePtEC2Up, &b_vbfMass_JetRelativePtEC2Up);
   fChain->SetBranchAddress("vbfMass_JetRelativePtHFDown", &vbfMass_JetRelativePtHFDown, &b_vbfMass_JetRelativePtHFDown);
   fChain->SetBranchAddress("vbfMass_JetRelativePtHFUp", &vbfMass_JetRelativePtHFUp, &b_vbfMass_JetRelativePtHFUp);
   fChain->SetBranchAddress("vbfMass_JetRelativeStatECDown", &vbfMass_JetRelativeStatECDown, &b_vbfMass_JetRelativeStatECDown);
   fChain->SetBranchAddress("vbfMass_JetRelativeStatECUp", &vbfMass_JetRelativeStatECUp, &b_vbfMass_JetRelativeStatECUp);
   fChain->SetBranchAddress("vbfMass_JetRelativeStatFSRDown", &vbfMass_JetRelativeStatFSRDown, &b_vbfMass_JetRelativeStatFSRDown);
   fChain->SetBranchAddress("vbfMass_JetRelativeStatFSRUp", &vbfMass_JetRelativeStatFSRUp, &b_vbfMass_JetRelativeStatFSRUp);
   fChain->SetBranchAddress("vbfMass_JetRelativeStatHFDown", &vbfMass_JetRelativeStatHFDown, &b_vbfMass_JetRelativeStatHFDown);
   fChain->SetBranchAddress("vbfMass_JetRelativeStatHFUp", &vbfMass_JetRelativeStatHFUp, &b_vbfMass_JetRelativeStatHFUp);
   fChain->SetBranchAddress("vbfMass_JetSinglePionECALDown", &vbfMass_JetSinglePionECALDown, &b_vbfMass_JetSinglePionECALDown);
   fChain->SetBranchAddress("vbfMass_JetSinglePionECALUp", &vbfMass_JetSinglePionECALUp, &b_vbfMass_JetSinglePionECALUp);
   fChain->SetBranchAddress("vbfMass_JetSinglePionHCALDown", &vbfMass_JetSinglePionHCALDown, &b_vbfMass_JetSinglePionHCALDown);
   fChain->SetBranchAddress("vbfMass_JetSinglePionHCALUp", &vbfMass_JetSinglePionHCALUp, &b_vbfMass_JetSinglePionHCALUp);
   fChain->SetBranchAddress("vbfMass_JetSubTotalAbsoluteDown", &vbfMass_JetSubTotalAbsoluteDown, &b_vbfMass_JetSubTotalAbsoluteDown);
   fChain->SetBranchAddress("vbfMass_JetSubTotalAbsoluteUp", &vbfMass_JetSubTotalAbsoluteUp, &b_vbfMass_JetSubTotalAbsoluteUp);
   fChain->SetBranchAddress("vbfMass_JetSubTotalMCDown", &vbfMass_JetSubTotalMCDown, &b_vbfMass_JetSubTotalMCDown);
   fChain->SetBranchAddress("vbfMass_JetSubTotalMCUp", &vbfMass_JetSubTotalMCUp, &b_vbfMass_JetSubTotalMCUp);
   fChain->SetBranchAddress("vbfMass_JetSubTotalPileUpDown", &vbfMass_JetSubTotalPileUpDown, &b_vbfMass_JetSubTotalPileUpDown);
   fChain->SetBranchAddress("vbfMass_JetSubTotalPileUpUp", &vbfMass_JetSubTotalPileUpUp, &b_vbfMass_JetSubTotalPileUpUp);
   fChain->SetBranchAddress("vbfMass_JetSubTotalPtDown", &vbfMass_JetSubTotalPtDown, &b_vbfMass_JetSubTotalPtDown);
   fChain->SetBranchAddress("vbfMass_JetSubTotalPtUp", &vbfMass_JetSubTotalPtUp, &b_vbfMass_JetSubTotalPtUp);
   fChain->SetBranchAddress("vbfMass_JetSubTotalRelativeDown", &vbfMass_JetSubTotalRelativeDown, &b_vbfMass_JetSubTotalRelativeDown);
   fChain->SetBranchAddress("vbfMass_JetSubTotalRelativeUp", &vbfMass_JetSubTotalRelativeUp, &b_vbfMass_JetSubTotalRelativeUp);
   fChain->SetBranchAddress("vbfMass_JetSubTotalScaleDown", &vbfMass_JetSubTotalScaleDown, &b_vbfMass_JetSubTotalScaleDown);
   fChain->SetBranchAddress("vbfMass_JetSubTotalScaleUp", &vbfMass_JetSubTotalScaleUp, &b_vbfMass_JetSubTotalScaleUp);
   fChain->SetBranchAddress("vbfMass_JetTimePtEtaDown", &vbfMass_JetTimePtEtaDown, &b_vbfMass_JetTimePtEtaDown);
   fChain->SetBranchAddress("vbfMass_JetTimePtEtaUp", &vbfMass_JetTimePtEtaUp, &b_vbfMass_JetTimePtEtaUp);
   fChain->SetBranchAddress("vbfMass_JetTotalDown", &vbfMass_JetTotalDown, &b_vbfMass_JetTotalDown);
   fChain->SetBranchAddress("vbfMass_JetTotalUp", &vbfMass_JetTotalUp, &b_vbfMass_JetTotalUp);
   fChain->SetBranchAddress("vbfNJets20", &vbfNJets20, &b_vbfNJets20);
   fChain->SetBranchAddress("vbfNJets20_JetEnDown", &vbfNJets20_JetEnDown, &b_vbfNJets20_JetEnDown);
   fChain->SetBranchAddress("vbfNJets20_JetEnUp", &vbfNJets20_JetEnUp, &b_vbfNJets20_JetEnUp);
   fChain->SetBranchAddress("vbfNJets30", &vbfNJets30, &b_vbfNJets30);
   fChain->SetBranchAddress("vbfNJets30_JetEnDown", &vbfNJets30_JetEnDown, &b_vbfNJets30_JetEnDown);
   fChain->SetBranchAddress("vbfNJets30_JetEnUp", &vbfNJets30_JetEnUp, &b_vbfNJets30_JetEnUp);
   fChain->SetBranchAddress("vbfVispt", &vbfVispt, &b_vbfVispt);
   fChain->SetBranchAddress("vbfVispt_JetEnDown", &vbfVispt_JetEnDown, &b_vbfVispt_JetEnDown);
   fChain->SetBranchAddress("vbfVispt_JetEnUp", &vbfVispt_JetEnUp, &b_vbfVispt_JetEnUp);
   fChain->SetBranchAddress("vbfdijetpt", &vbfdijetpt, &b_vbfdijetpt);
   fChain->SetBranchAddress("vbfdijetpt_JetEnDown", &vbfdijetpt_JetEnDown, &b_vbfdijetpt_JetEnDown);
   fChain->SetBranchAddress("vbfdijetpt_JetEnUp", &vbfdijetpt_JetEnUp, &b_vbfdijetpt_JetEnUp);
   fChain->SetBranchAddress("vbfj1eta", &vbfj1eta, &b_vbfj1eta);
   fChain->SetBranchAddress("vbfj1eta_JetEnDown", &vbfj1eta_JetEnDown, &b_vbfj1eta_JetEnDown);
   fChain->SetBranchAddress("vbfj1eta_JetEnUp", &vbfj1eta_JetEnUp, &b_vbfj1eta_JetEnUp);
   fChain->SetBranchAddress("vbfj1pt", &vbfj1pt, &b_vbfj1pt);
   fChain->SetBranchAddress("vbfj1pt_JetEnDown", &vbfj1pt_JetEnDown, &b_vbfj1pt_JetEnDown);
   fChain->SetBranchAddress("vbfj1pt_JetEnUp", &vbfj1pt_JetEnUp, &b_vbfj1pt_JetEnUp);
   fChain->SetBranchAddress("vbfj2eta", &vbfj2eta, &b_vbfj2eta);
   fChain->SetBranchAddress("vbfj2eta_JetEnDown", &vbfj2eta_JetEnDown, &b_vbfj2eta_JetEnDown);
   fChain->SetBranchAddress("vbfj2eta_JetEnUp", &vbfj2eta_JetEnUp, &b_vbfj2eta_JetEnUp);
   fChain->SetBranchAddress("vbfj2pt", &vbfj2pt, &b_vbfj2pt);
   fChain->SetBranchAddress("vbfj2pt_JetEnDown", &vbfj2pt_JetEnDown, &b_vbfj2pt_JetEnDown);
   fChain->SetBranchAddress("vbfj2pt_JetEnUp", &vbfj2pt_JetEnUp, &b_vbfj2pt_JetEnUp);
   fChain->SetBranchAddress("vispX", &vispX, &b_vispX);
   fChain->SetBranchAddress("vispY", &vispY, &b_vispY);
   fChain->SetBranchAddress("idx", &idx, &b_idx);
}


#endif // #ifdef HTauTauTree_tt_cxx
