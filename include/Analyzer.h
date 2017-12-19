//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 22 08:46:44 2017 by ROOT version 6.09/01
// from TTree candTree/Event Summary
// found on file: Moriond_2017/ggH125/ZZ4lAnalysis.root
//////////////////////////////////////////////////////////

#ifndef Analyzer_h
#define Analyzer_h

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TProfile.h"
#include "TGraph.h"
#include "TSpline.h"
#include "TMultiGraph.h"
#include "TGraphErrors.h"
#include "TPaveLabel.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <iostream>
#include "assert.h"

// My files
#include "Settings.h"
#include "Functions.h"
#include "FakeRates.h"

using namespace std;

class Analyzer {
	public :
	TTree          *fChain;   //!pointer to the analyzed TTree or TChain
	Int_t           fCurrent; //!current Tree number in a TChain
	
	// Fixed size dimensions of array or collections stored in the TTree if any.
	
	// Declaration of leaf types
	Int_t           RunNumber;
	Long64_t        EventNumber;
	Int_t           LumiNumber;
	Short_t         NRecoMu;
	Short_t         NRecoEle;
	Short_t         Nvtx;
	Short_t         NObsInt;
	Float_t         NTrueInt;
	Float_t         PFMET;
	Float_t         PFMET_jesUp;
	Float_t         PFMET_jesDn;
	Float_t         PFMETPhi;
	Short_t         nCleanedJets;
	Short_t         nCleanedJetsPt30;
	Short_t         nCleanedJetsPt30_jecUp;
	Short_t         nCleanedJetsPt30_jecDn;
	Short_t         nCleanedJetsPt30BTagged;
	Short_t         nCleanedJetsPt30BTagged_bTagSF;
	Short_t         nCleanedJetsPt30BTagged_bTagSFUp;
	Short_t         nCleanedJetsPt30BTagged_bTagSFDn;
	Short_t         trigWord;
	Float_t         ZZMass;
	Float_t         ZZMassErr;
	Float_t         ZZMassErrCorr;
	Float_t         ZZMassPreFSR;
	Short_t         ZZsel;
	Float_t         ZZPt;
	Float_t         ZZEta;
	Float_t         ZZPhi;
	Int_t           CRflag;
	Float_t         Z1Mass;
	Float_t         Z1Pt;
	Short_t         Z1Flav;
	Float_t         ZZMassRefit;
	Float_t         ZZMassRefitErr;
	Float_t         ZZMassUnrefitErr;
	Float_t         Z2Mass;
	Float_t         Z2Pt;
	Short_t         Z2Flav;
	Float_t         costhetastar;
	Float_t         helphi;
	Float_t         helcosthetaZ1;
	Float_t         helcosthetaZ2;
	Float_t         phistarZ1;
	Float_t         phistarZ2;
	Float_t         xi;
	Float_t         xistar;
	vector<float>   *LepPt;
	vector<float>   *LepEta;
	vector<float>   *LepPhi;
	vector<short>   *LepLepId;
	vector<float>   *LepSIP;
	vector<float>   *LepTime;
	vector<bool>    *LepisID;
	vector<short>   *LepisLoose;
	vector<float>   *LepBDT;
	vector<char>    *LepMissingHit;
	vector<float>   *LepCombRelIsoPF;
	vector<float>   *LepRecoSF;
	vector<float>   *LepRecoSF_Unc;
	vector<float>   *LepSelSF;
	vector<float>   *LepSelSF_Unc;
	vector<float>   *fsrPt;
	vector<float>   *fsrEta;
	vector<float>   *fsrPhi;
	vector<short>   *fsrLept;
	Bool_t          passIsoPreFSR;
	vector<float>   *JetPt;
	vector<float>   *JetEta;
	vector<float>   *JetPhi;
	vector<float>   *JetMass;
	vector<float>   *JetBTagger;
	vector<float>   *JetIsBtagged;
	vector<float>   *JetIsBtaggedWithSF;
	vector<float>   *JetIsBtaggedWithSFUp;
	vector<float>   *JetIsBtaggedWithSFDn;
	vector<float>   *JetQGLikelihood;
	vector<float>   *JetAxis2;
	vector<float>   *JetMult;
	vector<float>   *JetPtD;
	vector<float>   *JetSigma;
	vector<short>   *JetHadronFlavour;
	vector<short>   *JetPartonFlavour;
	vector<float>   *JetJERUp;
	vector<float>   *JetJERDown;
	vector<short>   *JetPUID;
	vector<float>   *JetPUValue;
	Float_t         DiJetMass;
	Float_t         DiJetDEta;
	Float_t         DiJetFisher;
	Short_t         nExtraLep;
	Short_t         nExtraZ;
	vector<float>   *ExtraLepPt;
	vector<float>   *ExtraLepEta;
	vector<float>   *ExtraLepPhi;
	vector<short>   *ExtraLepLepId;
	Float_t         ZXFakeweight;
	Float_t         KFactor_QCD_ggZZ_Nominal;
	Float_t         KFactor_QCD_ggZZ_PDFScaleDn;
	Float_t         KFactor_QCD_ggZZ_PDFScaleUp;
	Float_t         KFactor_QCD_ggZZ_QCDScaleDn;
	Float_t         KFactor_QCD_ggZZ_QCDScaleUp;
	Float_t         KFactor_QCD_ggZZ_AsDn;
	Float_t         KFactor_QCD_ggZZ_AsUp;
	Float_t         KFactor_QCD_ggZZ_PDFReplicaDn;
	Float_t         KFactor_QCD_ggZZ_PDFReplicaUp;
	Float_t         KFactor_EW_qqZZ;
	Float_t         KFactor_QCD_qqZZ_M;
	Short_t         genFinalState;
	Int_t           genProcessId;
	Float_t         genHEPMCweight;
	Float_t         PUWeight;
	Float_t         PUWeight_Dn;
	Float_t         PUWeight_Up;
	Float_t         dataMCWeight;
	Float_t         dataMCWeight_Unc;
	Float_t         trigEffWeight;
	Float_t         overallEventWeight;
	Float_t         HqTMCweight;
	Float_t         xsec;
	Short_t         genExtInfo;
	Float_t         GenHMass;
	Float_t         GenHPt;
	Float_t         GenHRapidity;
	Float_t         GenZ1Mass;
	Float_t         GenZ1Pt;
	Float_t         GenZ1Phi;
	Float_t         GenZ1Flav;
	Float_t         GenZ2Mass;
	Float_t         GenZ2Pt;
	Float_t         GenZ2Phi;
	Float_t         GenZ2Flav;
	Float_t         GenLep1Pt;
	Float_t         GenLep1Eta;
	Float_t         GenLep1Phi;
	Short_t         GenLep1Id;
	Float_t         GenLep2Pt;
	Float_t         GenLep2Eta;
	Float_t         GenLep2Phi;
	Short_t         GenLep2Id;
	Float_t         GenLep3Pt;
	Float_t         GenLep3Eta;
	Float_t         GenLep3Phi;
	Short_t         GenLep3Id;
	Float_t         GenLep4Pt;
	Float_t         GenLep4Eta;
	Float_t         GenLep4Phi;
	Short_t         GenLep4Id;
	Float_t         GenAssocLep1Pt;
	Float_t         GenAssocLep1Eta;
	Float_t         GenAssocLep1Phi;
	Short_t         GenAssocLep1Id;
	Float_t         GenAssocLep2Pt;
	Float_t         GenAssocLep2Eta;
	Float_t         GenAssocLep2Phi;
	Short_t         GenAssocLep2Id;
	vector<float>   *LHEMotherPz;
	vector<float>   *LHEMotherE;
	vector<short>   *LHEMotherId;
	vector<float>   *LHEDaughterPt;
	vector<float>   *LHEDaughterEta;
	vector<float>   *LHEDaughterPhi;
	vector<float>   *LHEDaughterMass;
	vector<short>   *LHEDaughterId;
	vector<float>   *LHEAssociatedParticlePt;
	vector<float>   *LHEAssociatedParticleEta;
	vector<float>   *LHEAssociatedParticlePhi;
	vector<float>   *LHEAssociatedParticleMass;
	vector<short>   *LHEAssociatedParticleId;
	Float_t         LHEPDFScale;
	Float_t         LHEweight_QCDscale_muR1_muF1;
	Float_t         LHEweight_QCDscale_muR1_muF2;
	Float_t         LHEweight_QCDscale_muR1_muF0p5;
	Float_t         LHEweight_QCDscale_muR2_muF1;
	Float_t         LHEweight_QCDscale_muR2_muF2;
	Float_t         LHEweight_QCDscale_muR2_muF0p5;
	Float_t         LHEweight_QCDscale_muR0p5_muF1;
	Float_t         LHEweight_QCDscale_muR0p5_muF2;
	Float_t         LHEweight_QCDscale_muR0p5_muF0p5;
	Float_t         LHEweight_PDFVariation_Up;
	Float_t         LHEweight_PDFVariation_Dn;
	Float_t         LHEweight_AsMZ_Up;
	Float_t         LHEweight_AsMZ_Dn;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz2_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz4_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghza2_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghza4_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_gha2_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_gha4_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen;
	Float_t         p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen;
	Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal;
	Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECNominal;
	Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal;
	Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal;
	Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal;
	Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal;
	Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal;
	Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal;
	Float_t         p_HadZH_mavjj_JECNominal;
	Float_t         p_HadWH_mavjj_JECNominal;
	Float_t         p_HadZH_mavjj_true_JECNominal;
	Float_t         p_HadWH_mavjj_true_JECNominal;
	Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECNominal;
	Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECNominal;
	Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECNominal;
	Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal;
	Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal;
	Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal;
	Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal;
	Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal;
	Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal;
	Float_t         p_bbH_SIG_kappa_1_JHUGen_JECNominal;
	Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp;
	Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECUp;
	Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp;
	Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp;
	Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECUp;
	Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECUp;
	Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp;
	Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp;
	Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECUp;
	Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp;
	Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECUp;
	Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECUp;
	Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp;
	Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp;
	Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp;
	Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp;
	Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp;
	Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp;
	Float_t         p_bbH_SIG_kappa_1_JHUGen_JECUp;
	Float_t         pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn;
	Float_t         p_JVBF_SIG_ghv1_1_JHUGen_JECDn;
	Float_t         p_JQCD_SIG_ghg2_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv2_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv4_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghza2_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghza4_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_gha2_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_gha4_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn;
	Float_t         p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn;
	Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECDn;
	Float_t         p_JJQCD_SIG_ghg4_1_JHUGen_JECDn;
	Float_t         p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz2_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz4_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghza2_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghza4_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_gha2_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_gha4_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn;
	Float_t         p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn;
	Float_t         p_HadWH_SIG_ghw1_1_JHUGen_JECDn;
	Float_t         p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn;
	Float_t         p_HadWH_SIG_ghw2_1_JHUGen_JECDn;
	Float_t         p_HadWH_SIG_ghw4_1_JHUGen_JECDn;
	Float_t         p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn;
	Float_t         p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn;
	Float_t         p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn;
	Float_t         p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn;
	Float_t         p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn;
	Float_t         p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn;
	Float_t         p_bbH_SIG_kappa_1_JHUGen_JECDn;
	Float_t         p_LepZH_SIG_ghz1_1_JHUGen;
	Float_t         p_LepZH_SIG_ghz1prime2_1E4_JHUGen;
	Float_t         p_LepZH_SIG_ghz2_1_JHUGen;
	Float_t         p_LepZH_SIG_ghz4_1_JHUGen;
	Float_t         p_LepZH_SIG_ghza1prime2_1E4_JHUGen;
	Float_t         p_LepZH_SIG_ghza2_1_JHUGen;
	Float_t         p_LepZH_SIG_ghza4_1_JHUGen;
	Float_t         p_LepZH_SIG_gha2_1_JHUGen;
	Float_t         p_LepZH_SIG_gha4_1_JHUGen;
	Float_t         p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen;
	Float_t         p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen;
	Float_t         p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen;
	Float_t         p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen;
	Float_t         p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen;
	Float_t         p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen;
	Float_t         p_LepZH_SIG_ghz1_1_gha2_1_JHUGen;
	Float_t         p_LepZH_SIG_ghz1_1_gha4_1_JHUGen;
	Float_t         p_LepWH_SIG_ghw1_1_JHUGen;
	Float_t         p_LepWH_SIG_ghw1prime2_1E4_JHUGen;
	Float_t         p_LepWH_SIG_ghw2_1_JHUGen;
	Float_t         p_LepWH_SIG_ghw4_1_JHUGen;
	Float_t         p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen;
	Float_t         p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen;
	Float_t         p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen;
	Float_t         p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen;
	Float_t         p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gZPz1_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gZPz2_1_JHUGen;
	Float_t         p_GG_SIG_gXg1_1_gXz1_1_JHUGen;
	Float_t         p_GG_SIG_gXg2_1_gXz2_1_JHUGen;
	Float_t         p_GG_SIG_gXg3_1_gXz3_1_JHUGen;
	Float_t         p_GG_SIG_gXg4_1_gXz4_1_JHUGen;
	Float_t         p_GG_SIG_gXg1_1_gXz5_1_JHUGen;
	Float_t         p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen;
	Float_t         p_GG_SIG_gXg1_1_gXz6_1_JHUGen;
	Float_t         p_GG_SIG_gXg1_1_gXz7_1_JHUGen;
	Float_t         p_GG_SIG_gXg5_1_gXz8_1_JHUGen;
	Float_t         p_GG_SIG_gXg5_1_gXz9_1_JHUGen;
	Float_t         p_GG_SIG_gXg5_1_gXz10_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen;
	Float_t         p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz1_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz2_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz3_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz4_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz5_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz6_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz7_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz8_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz9_1_JHUGen;
	Float_t         p_INDEPENDENT_SIG_gXz10_1_JHUGen;
	Float_t         pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;
	Float_t         p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;
	Float_t         p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM;
	Float_t         p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM;
	Float_t         pConst_GG_BKG_MCFM;
	Float_t         p_GG_BKG_MCFM;
	Float_t         pConst_QQB_BKG_MCFM;
	Float_t         p_QQB_BKG_MCFM;
	Float_t         p_ZJJ_BKG_MCFM;
	Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECNominal;
	Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECNominal;
	Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECNominal;
	Float_t         p_JJEW_BKG_MCFM_JECNominal;
	Float_t         p_JJVBF_BKG_MCFM_JECNominal;
	Float_t         p_JJQCD_BKG_MCFM_JECNominal;
	Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECUp;
	Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECUp;
	Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECUp;
	Float_t         p_JJEW_BKG_MCFM_JECUp;
	Float_t         p_JJVBF_BKG_MCFM_JECUp;
	Float_t         p_JJQCD_BKG_MCFM_JECUp;
	Float_t         p_JJEW_SIG_ghv1_1_MCFM_JECDn;
	Float_t         p_JJEW_BSI_ghv1_1_MCFM_JECDn;
	Float_t         p_JJEW_BSI_ghv1_i_MCFM_JECDn;
	Float_t         p_JJEW_BKG_MCFM_JECDn;
	Float_t         p_JJVBF_BKG_MCFM_JECDn;
	Float_t         p_JJQCD_BKG_MCFM_JECDn;
	Float_t         p_m4l_SIG;
	Float_t         p_m4l_BKG;
	Float_t         p_m4l_SIG_ScaleDown;
	Float_t         p_m4l_BKG_ScaleDown;
	Float_t         p_m4l_SIG_ResDown;
	Float_t         p_m4l_BKG_ResDown;
	Float_t         p_m4l_SIG_ScaleUp;
	Float_t         p_m4l_BKG_ScaleUp;
	Float_t         p_m4l_SIG_ResUp;
	Float_t         p_m4l_BKG_ResUp;
	Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ;
	Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ;
	Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ;
	Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ;
	Float_t         p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ;
	Float_t         p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ;
	Float_t         p_Gen_CPStoBWPropRewgt;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1prime2_1E4_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz2_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz4_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghza1prime2_1E4_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghza2_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghza4_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_gha2_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_gha4_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4i_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_i_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_i_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4i_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_i_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_i_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_i_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_1_MCFM;
	Float_t         p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghz1_1_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghz1_i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghz2_1_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghz2_i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghz4_1_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghz4_i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghza2_1_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghza2_i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghza4_1_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_ghza4_i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_gha2_1_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_gha2_i_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_gha4_1_MCFM;
	Float_t         p_Gen_GG_BSI_kappaTopBot_1_gha4_i_MCFM;
	Float_t         p_Gen_GG_BKG_MCFM;
	Float_t         p_Gen_QQB_BKG_MCFM;
	Float_t         p_Gen_GG_SIG_gXg1_1_gXz1_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg2_1_gXz2_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg3_1_gXz3_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg4_1_gXz4_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg1_1_gXz5_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg1_1_gXz6_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg1_1_gXz7_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg5_1_gXz8_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg5_1_gXz9_1_JHUGen;
	Float_t         p_Gen_GG_SIG_gXg5_1_gXz10_1_JHUGen;
	
	// List of branches
	TBranch        *b_RunNumber;   //!
	TBranch        *b_EventNumber;   //!
	TBranch        *b_LumiNumber;   //!
	TBranch        *b_NRecoMu;   //!
	TBranch        *b_NRecoEle;   //!
	TBranch        *b_Nvtx;   //!
	TBranch        *b_NObsInt;   //!
	TBranch        *b_NTrueInt;   //!
	TBranch        *b_PFMET;   //!
	TBranch        *b_PFMET_jesUp;   //!
	TBranch        *b_PFMET_jesDn;   //!
	TBranch        *b_PFMETPhi;   //!
	TBranch        *b_nCleanedJets;   //!
	TBranch        *b_nCleanedJetsPt30;   //!
	TBranch        *b_nCleanedJetsPt30_jecUp;   //!
	TBranch        *b_nCleanedJetsPt30_jecDn;   //!
	TBranch        *b_nCleanedJetsPt30BTagged;   //!
	TBranch        *b_nCleanedJetsPt30BTagged_bTagSF;   //!
	TBranch        *b_nCleanedJetsPt30BTagged_bTagSFUp;   //!
	TBranch        *b_nCleanedJetsPt30BTagged_bTagSFDn;   //!
	TBranch        *b_trigWord;   //!
	TBranch        *b_ZZMass;   //!
	TBranch        *b_ZZMassErr;   //!
	TBranch        *b_ZZMassErrCorr;   //!
	TBranch        *b_ZZMassPreFSR;   //!
	TBranch        *b_ZZsel;   //!
	TBranch        *b_ZZPt;   //!
	TBranch        *b_ZZEta;   //!
	TBranch        *b_ZZPhi;   //!
	TBranch        *b_CRflag;   //!
	TBranch        *b_Z1Mass;   //!
	TBranch        *b_Z1Pt;   //!
	TBranch        *b_Z1Flav;   //!
	TBranch        *b_ZZMassRefit;   //!
	TBranch        *b_ZZMassRefitErr;   //!
	TBranch        *b_ZZMassUnrefitErr;   //!
	TBranch        *b_Z2Mass;   //!
	TBranch        *b_Z2Pt;   //!
	TBranch        *b_Z2Flav;   //!
	TBranch        *b_costhetastar;   //!
	TBranch        *b_helphi;   //!
	TBranch        *b_helcosthetaZ1;   //!
	TBranch        *b_helcosthetaZ2;   //!
	TBranch        *b_phistarZ1;   //!
	TBranch        *b_phistarZ2;   //!
	TBranch        *b_xi;   //!
	TBranch        *b_xistar;   //!
	TBranch        *b_LepPt;   //!
	TBranch        *b_LepEta;   //!
	TBranch        *b_LepPhi;   //!
	TBranch        *b_LepLepId;   //!
	TBranch        *b_LepSIP;   //!
	TBranch        *b_LepTime;   //!
	TBranch        *b_LepisID;   //!
	TBranch        *b_LepisLoose;   //!
	TBranch        *b_LepBDT;   //!
	TBranch        *b_LepMissingHit;   //!
	TBranch        *b_LepCombRelIsoPF;   //!
	TBranch        *b_LepRecoSF;   //!
	TBranch        *b_LepRecoSF_Unc;   //!
	TBranch        *b_LepSelSF;   //!
	TBranch        *b_LepSelSF_Unc;   //!
	TBranch        *b_fsrPt;   //!
	TBranch        *b_fsrEta;   //!
	TBranch        *b_fsrPhi;   //!
	TBranch        *b_fsrLept;   //!
	TBranch        *b_passIsoPreFSR;   //!
	TBranch        *b_JetPt;   //!
	TBranch        *b_JetEta;   //!
	TBranch        *b_JetPhi;   //!
	TBranch        *b_JetMass;   //!
	TBranch        *b_JetBTagger;   //!
	TBranch        *b_JetIsBtagged;   //!
	TBranch        *b_JetIsBtaggedWithSF;   //!
	TBranch        *b_JetIsBtaggedWithSFUp;   //!
	TBranch        *b_JetIsBtaggedWithSFDn;   //!
	TBranch        *b_JetQGLikelihood;   //!
	TBranch        *b_JetAxis2;   //!
	TBranch        *b_JetMult;   //!
	TBranch        *b_JetPtD;   //!
	TBranch        *b_JetSigma;   //!
	TBranch        *b_JetHadronFlavour;   //!
	TBranch        *b_JetPartonFlavour;   //!
	TBranch        *b_JetJERUp;   //!
	TBranch        *b_JetJERDown;   //!
	TBranch        *b_JetPUID;   //!
	TBranch        *b_JetPUValue;   //!
	TBranch        *b_DiJetMass;   //!
	TBranch        *b_DiJetDEta;   //!
	TBranch        *b_DiJetFisher;   //!
	TBranch        *b_nExtraLep;   //!
	TBranch        *b_nExtraZ;   //!
	TBranch        *b_ExtraLepPt;   //!
	TBranch        *b_ExtraLepEta;   //!
	TBranch        *b_ExtraLepPhi;   //!
	TBranch        *b_ExtraLepLepId;   //!
	TBranch        *b_ZXFakeweight;   //!
	TBranch        *b_KFactor_QCD_ggZZ_Nominal;   //!
	TBranch        *b_KFactor_QCD_ggZZ_PDFScaleDn;   //!
	TBranch        *b_KFactor_QCD_ggZZ_PDFScaleUp;   //!
	TBranch        *b_KFactor_QCD_ggZZ_QCDScaleDn;   //!
	TBranch        *b_KFactor_QCD_ggZZ_QCDScaleUp;   //!
	TBranch        *b_KFactor_QCD_ggZZ_AsDn;   //!
	TBranch        *b_KFactor_QCD_ggZZ_AsUp;   //!
	TBranch        *b_KFactor_QCD_ggZZ_PDFReplicaDn;   //!
	TBranch        *b_KFactor_QCD_ggZZ_PDFReplicaUp;   //!
	TBranch        *b_KFactor_EW_qqZZ;
	TBranch        *b_KFactor_QCD_qqZZ_M;
	TBranch        *b_genFinalState;   //!
	TBranch        *b_genProcessId;   //!
	TBranch        *b_genHEPMCweight;   //!
	TBranch        *b_PUWeight;   //!
	TBranch        *b_PUWeight_Dn;   //!
	TBranch        *b_PUWeight_Up;   //!
	TBranch        *b_dataMCWeight;   //!
	TBranch        *b_dataMCWeight_Unc;   //!
	TBranch        *b_trigEffWeight;   //!
	TBranch        *b_overallEventWeight;   //!
	TBranch        *b_HqTMCweight;   //!
	TBranch        *b_xsec;   //!
	TBranch        *b_genExtInfo;   //!
	TBranch        *b_GenHMass;   //!
	TBranch        *b_GenHPt;   //!
	TBranch        *b_GenHRapidity;   //!
	TBranch        *b_GenZ1Mass;   //!
	TBranch        *b_GenZ1Pt;   //!
	TBranch        *b_GenZ1Phi;   //!
	TBranch        *b_GenZ1Flav;   //!
	TBranch        *b_GenZ2Mass;   //!
	TBranch        *b_GenZ2Pt;   //!
	TBranch        *b_GenZ2Phi;   //!
	TBranch        *b_GenZ2Flav;   //!
	TBranch        *b_GenLep1Pt;   //!
	TBranch        *b_GenLep1Eta;   //!
	TBranch        *b_GenLep1Phi;   //!
	TBranch        *b_GenLep1Id;   //!
	TBranch        *b_GenLep2Pt;   //!
	TBranch        *b_GenLep2Eta;   //!
	TBranch        *b_GenLep2Phi;   //!
	TBranch        *b_GenLep2Id;   //!
	TBranch        *b_GenLep3Pt;   //!
	TBranch        *b_GenLep3Eta;   //!
	TBranch        *b_GenLep3Phi;   //!
	TBranch        *b_GenLep3Id;   //!
	TBranch        *b_GenLep4Pt;   //!
	TBranch        *b_GenLep4Eta;   //!
	TBranch        *b_GenLep4Phi;   //!
	TBranch        *b_GenLep4Id;   //!
	TBranch        *b_GenAssocLep1Pt;   //!
	TBranch        *b_GenAssocLep1Eta;   //!
	TBranch        *b_GenAssocLep1Phi;   //!
	TBranch        *b_GenAssocLep1Id;   //!
	TBranch        *b_GenAssocLep2Pt;   //!
	TBranch        *b_GenAssocLep2Eta;   //!
	TBranch        *b_GenAssocLep2Phi;   //!
	TBranch        *b_GenAssocLep2Id;   //!
	TBranch        *b_LHEMotherPz;   //!
	TBranch        *b_LHEMotherE;   //!
	TBranch        *b_LHEMotherId;   //!
	TBranch        *b_LHEDaughterPt;   //!
	TBranch        *b_LHEDaughterEta;   //!
	TBranch        *b_LHEDaughterPhi;   //!
	TBranch        *b_LHEDaughterMass;   //!
	TBranch        *b_LHEDaughterId;   //!
	TBranch        *b_LHEAssociatedParticlePt;   //!
	TBranch        *b_LHEAssociatedParticleEta;   //!
	TBranch        *b_LHEAssociatedParticlePhi;   //!
	TBranch        *b_LHEAssociatedParticleMass;   //!
	TBranch        *b_LHEAssociatedParticleId;   //!
	TBranch        *b_LHEPDFScale;   //!
	TBranch        *b_LHEweight_QCDscale_muR1_muF1;   //!
	TBranch        *b_LHEweight_QCDscale_muR1_muF2;   //!
	TBranch        *b_LHEweight_QCDscale_muR1_muF0p5;   //!
	TBranch        *b_LHEweight_QCDscale_muR2_muF1;   //!
	TBranch        *b_LHEweight_QCDscale_muR2_muF2;   //!
	TBranch        *b_LHEweight_QCDscale_muR2_muF0p5;   //!
	TBranch        *b_LHEweight_QCDscale_muR0p5_muF1;   //!
	TBranch        *b_LHEweight_QCDscale_muR0p5_muF2;   //!
	TBranch        *b_LHEweight_QCDscale_muR0p5_muF0p5;   //!
	TBranch        *b_LHEweight_PDFVariation_Up;   //!
	TBranch        *b_LHEweight_PDFVariation_Dn;   //!
	TBranch        *b_LHEweight_AsMZ_Up;   //!
	TBranch        *b_LHEweight_AsMZ_Dn;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz2_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz4_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghza2_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghza4_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_gha2_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_gha4_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen;   //!
	TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadZH_mavjj_JECNominal;
	TBranch        *b_p_HadWH_mavjj_JECNominal;
	TBranch        *b_p_HadZH_mavjj_true_JECNominal;
	TBranch        *b_p_HadWH_mavjj_true_JECNominal;
	TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal;   //!
	TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECNominal;   //!
	TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp;   //!
	TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECUp;   //!
	TBranch        *b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JQCD_SIG_ghg2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghza2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghza4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_gha2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_gha4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJQCD_SIG_ghg4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghza2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghza4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_gha2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_gha4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_HadWH_SIG_ghw2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadWH_SIG_ghw4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn;   //!
	TBranch        *b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn;   //!
	TBranch        *b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn;   //!
	TBranch        *b_p_bbH_SIG_kappa_1_JHUGen_JECDn;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz2_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz4_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghza1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghza2_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghza4_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_gha2_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_gha4_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_gha2_1_JHUGen;   //!
	TBranch        *b_p_LepZH_SIG_ghz1_1_gha4_1_JHUGen;   //!
	TBranch        *b_p_LepWH_SIG_ghw1_1_JHUGen;   //!
	TBranch        *b_p_LepWH_SIG_ghw1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_LepWH_SIG_ghw2_1_JHUGen;   //!
	TBranch        *b_p_LepWH_SIG_ghw4_1_JHUGen;   //!
	TBranch        *b_p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen;   //!
	TBranch        *b_p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen;   //!
	TBranch        *b_p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gZPz1_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gZPz2_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg1_1_gXz1_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg2_1_gXz2_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg3_1_gXz3_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg4_1_gXz4_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg1_1_gXz5_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg1_1_gXz6_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg1_1_gXz7_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg5_1_gXz8_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg5_1_gXz9_1_JHUGen;   //!
	TBranch        *b_p_GG_SIG_gXg5_1_gXz10_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen;   //!
	TBranch        *b_p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz1_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz2_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz3_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz4_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz5_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz6_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz7_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz8_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz9_1_JHUGen;   //!
	TBranch        *b_p_INDEPENDENT_SIG_gXz10_1_JHUGen;   //!
	TBranch        *b_pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;   //!
	TBranch        *b_p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;   //!
	TBranch        *b_p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM;   //!
	TBranch        *b_p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM;   //!
	TBranch        *b_pConst_GG_BKG_MCFM;   //!
	TBranch        *b_p_GG_BKG_MCFM;   //!
	TBranch        *b_pConst_QQB_BKG_MCFM;   //!
	TBranch        *b_p_QQB_BKG_MCFM;   //!
	TBranch        *b_p_ZJJ_BKG_MCFM;   //!
	TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECNominal;   //!
	TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECNominal;   //!
	TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECNominal;   //!
	TBranch        *b_p_JJEW_BKG_MCFM_JECNominal;   //!
	TBranch        *b_p_JJVBF_BKG_MCFM_JECNominal;   //!
	TBranch        *b_p_JJQCD_BKG_MCFM_JECNominal;   //!
	TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECUp;   //!
	TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECUp;   //!
	TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECUp;   //!
	TBranch        *b_p_JJEW_BKG_MCFM_JECUp;   //!
	TBranch        *b_p_JJVBF_BKG_MCFM_JECUp;   //!
	TBranch        *b_p_JJQCD_BKG_MCFM_JECUp;   //!
	TBranch        *b_p_JJEW_SIG_ghv1_1_MCFM_JECDn;   //!
	TBranch        *b_p_JJEW_BSI_ghv1_1_MCFM_JECDn;   //!
	TBranch        *b_p_JJEW_BSI_ghv1_i_MCFM_JECDn;   //!
	TBranch        *b_p_JJEW_BKG_MCFM_JECDn;   //!
	TBranch        *b_p_JJVBF_BKG_MCFM_JECDn;   //!
	TBranch        *b_p_JJQCD_BKG_MCFM_JECDn;   //!
	TBranch        *b_p_m4l_SIG;   //!
	TBranch        *b_p_m4l_BKG;   //!
	TBranch        *b_p_m4l_SIG_ScaleDown;   //!
	TBranch        *b_p_m4l_BKG_ScaleDown;   //!
	TBranch        *b_p_m4l_SIG_ResDown;   //!
	TBranch        *b_p_m4l_BKG_ResDown;   //!
	TBranch        *b_p_m4l_SIG_ScaleUp;   //!
	TBranch        *b_p_m4l_BKG_ScaleUp;   //!
	TBranch        *b_p_m4l_SIG_ResUp;   //!
	TBranch        *b_p_m4l_BKG_ResUp;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ;   //!
	TBranch        *b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ;   //!
	TBranch        *b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ;   //!
	TBranch        *b_p_Gen_CPStoBWPropRewgt;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1prime2_1E4_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghza1prime2_1E4_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghza2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghza4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_gha2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_gha4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4i_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4i_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghz1_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghz1_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghz2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghz2_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghz4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghz4_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghza2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghza2_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghza4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_ghza4_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_gha2_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_gha2_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_gha4_1_MCFM;   //!
	TBranch        *b_p_Gen_GG_BSI_kappaTopBot_1_gha4_i_MCFM;   //!
	TBranch        *b_p_Gen_GG_BKG_MCFM;   //!
	TBranch        *b_p_Gen_QQB_BKG_MCFM;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg1_1_gXz1_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg2_1_gXz2_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg3_1_gXz3_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg4_1_gXz4_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg1_1_gXz5_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg1_1_gXz6_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg1_1_gXz7_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg5_1_gXz8_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg5_1_gXz9_1_JHUGen;   //!
	TBranch        *b_p_Gen_GG_SIG_gXg5_1_gXz10_1_JHUGen;   //!
	
	TH1F  *hCounters;
	TFile *inputfile;
	TString input_file_name;
	Long64_t gen_sum_weights;
	Float_t _k_factor;
	Float_t _event_weight;
	Float_t _lumi;
	Float_t _xsec;
	
	Int_t   m4l_bins;
	Double_t m4l_slices[99];
	Int_t   m4l_bins2;
	Double_t m4l_slices2[99];
	Int_t   m4l_bins3;
	Double_t m4l_slices3[99];
	
	vector<TString> _s_cat;
	vector<TString> _s_ac;
	
	// /170623/ production
	//	Float_t oldWP_VBF2j = 0.478278;
	//	Float_t oldWP_VBF1j = 0.3743;
	//	Float_t oldWP_WH    = 0.936489;
	//	Float_t oldWP_ZH    = 0.946945;
	//	Float_t oldWP_VH    = 0.941161;
	
	// /171005/ production
	//	Float_t oldWP_VBF2j = 0.141022;
	//	Float_t oldWP_VBF1j = 0.3743;
	//	Float_t oldWP_WH    = 0.159785;
	//	Float_t oldWP_ZH    = 0.185325;
	//	Float_t oldWP_VH    = 0.173612;
	
	// /171005/ production new cConstants
	Float_t oldWP_VBF2j = 0.474421;
	Float_t oldWP_VBF1j = 0.370614;
	Float_t oldWP_WH    = 0.159785;//update
	Float_t oldWP_ZH    = 0.185325;//update
	Float_t oldWP_VH    = 0.879954;
	
	
	Float_t DVBF1j_ME;
	Float_t DVBF2j_ME;
	Float_t DWH_ME;
	Float_t DZH_ME;
	Float_t DVH_ME;
	
	Float_t D_BKG_DEC;
	Float_t D_BKG_VBF_DEC;
	
	Float_t D_0MH_DEC;
	Float_t D_0PH_DEC;
	Float_t D_0L1_DEC;
	Float_t D_0L1Zgs_DEC;
	
	Float_t D_0MH_VBF_DEC;
	Float_t D_0PH_VBF_DEC;
	Float_t D_0L1_VBF_DEC;
	Float_t D_0L1Zgs_VBF_DEC;
	
	Float_t D_0MH_VBF;
	Float_t D_0PH_VBF;
	Float_t D_0L1_VBF;
	Float_t D_0L1Zgs_VBF;
	
	Float_t D_0MH_WH;
	Float_t D_0PH_WH;
	Float_t D_0L1_WH;
	Float_t D_0L1Zgs_WH;
	
	Float_t D_0MH_ZH;
	Float_t D_0PH_ZH;
	Float_t D_0L1_ZH;
	Float_t D_0L1Zgs_ZH;
	
	FakeRates *FR;
	vector<float> _fs_ROS_SS;
	
	TFile *VBF1j_file;
	TFile *VBF2j_file;
	TFile *WH_file;
	TFile *ZH_file;
	
	TFile *DBKG_file_4e;
	TFile *DBKG_file_4mu;
	TFile *DBKG_file_2e2mu;
	
	TFile *g_Decay_g2_file;
	TFile *g_Decay_g4_file;
	TFile *g_Decay_L1_file;
	TFile *g_Decay_L1Zgs_file;
	
	TFile *g_VBF_g2_file;
	TFile *g_VBF_g4_file;
	TFile *g_VBF_L1_file;
	TFile *g_VBF_L1Zgs_file;
	
	TFile *g_WH_g2_file;
	TFile *g_WH_g4_file;
	TFile *g_WH_L1_file;
	TFile *g_WH_L1Zgs_file;
	
	TFile *g_ZH_g2_file;
	TFile *g_ZH_g4_file;
	TFile *g_ZH_L1_file;
	TFile *g_ZH_L1Zgs_file;
	
	TSpline3 *VBF1j_spline;
	TSpline3 *VBF2j_spline;
	TSpline3 *WH_spline;
	TSpline3 *ZH_spline;
	
	TSpline3 *DBKG_spline_4e;
	TSpline3 *DBKG_spline_4mu;
	TSpline3 *DBKG_spline_2e2mu;
	
	TSpline3 *g_Decay_g2_spline;
	TSpline3 *g_Decay_g4_spline;
	TSpline3 *g_Decay_L1_spline;
	TSpline3 *g_Decay_L1Zgs_spline;
	
	TSpline3 *g_VBF_g2_spline;
	TSpline3 *g_VBF_g4_spline;
	TSpline3 *g_VBF_L1_spline;
	TSpline3 *g_VBF_L1Zgs_spline;
	
	TSpline3 *g_WH_g2_spline;
	TSpline3 *g_WH_g4_spline;
	TSpline3 *g_WH_L1_spline;
	TSpline3 *g_WH_L1Zgs_spline;
	
	TSpline3 *g_ZH_g2_spline;
	TSpline3 *g_ZH_g4_spline;
	TSpline3 *g_ZH_L1_spline;
	TSpline3 *g_ZH_L1Zgs_spline;
	
	TProfile *p2j,*p1j;
	TH1F *histos_1D[Settings::num_of_1D_hist_names];
	TH2F *histos_2D[Settings::num_of_categories_OnShell][Settings::num_of_2D_hist_names][Settings::num_of_anomalous_couplings];
	
	Analyzer(bool splines = false);
	virtual ~Analyzer();
	virtual Int_t    Cut(Long64_t entry);
	virtual Int_t    GetEntry(Long64_t entry);
	virtual Long64_t LoadTree(Long64_t entry);
	virtual void     Init(TTree *tree, TString filename);
	virtual void     LoadConstants();
	virtual void     LoadFakeRates();
	virtual void     DeclareHistos();
	virtual void     ResetHistos();
	virtual void     RebinHistos();
	virtual void     RebinHistosSplines();
	virtual void     RebinHistosSplinesqq();
	virtual void     WriteHistos(TString sample);
	virtual void     WriteGraphs(TString sample);
	virtual void     WriteSplines(TString sample);
	virtual void     FillHistos(TString filename, Float_t lumi, bool only2jEvents );
	virtual void     Loop(bool only2jEvetns);
	virtual void     LoopForEff(TString filename, Float_t lumi, bool shiftWP, bool only2jEvents, TH1F *hist_1D[Settings::num_of_1D_hist_names]);
	virtual Bool_t   Notify();
	virtual void     Show(Long64_t entry = -1);
	virtual float getDVBF2jetsConstant_old(float ZZMass);
	virtual float getDVBF1jetConstant_old(float ZZMass);
	virtual float getDWHhConstant_old(float ZZMass);
	virtual float getDZHhConstant_old(float ZZMass);
	virtual float getDVBF2jetsConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP);
	virtual float getDVBF1jetConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP);
	virtual float getDWHhConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP);
	virtual float getDZHhConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP);
	virtual float getDVBF2jetsWP(float ZZMass, bool useQGTagging);
	virtual float getDVBF1jetWP(float ZZMass, bool useQGTagging);
	virtual float getDWHhWP(float ZZMass, bool useQGTagging);
	virtual float getDZHhWP(float ZZMass, bool useQGTagging);
	virtual float ShiftWPfactor(float oldWP, float newWP);
	virtual float getDbkgkinConstant_old(int ZZflav, float ZZMass);
	virtual float GetDBKGcConstant(Short_t Z1Flav, Short_t Z2Flav, float ZZMass );
};

#endif

#ifdef Analyzer_cxx
Analyzer::Analyzer(bool splines) : fChain(0)
{
	// if parameter tree is not specified (or zero), connect the file
	// used to generate this class and read the Tree.
	m4l_bins     = 18;
	m4l_slices[0]=105;m4l_slices[1]=140;m4l_slices[2]=150;m4l_slices[3]=160;m4l_slices[4]=170;m4l_slices[5]=180;m4l_slices[6]=190;m4l_slices[7]=220;m4l_slices[8]=250;m4l_slices[9]=300;m4l_slices[10]=400;
	m4l_slices[11]=500;m4l_slices[12]=600;m4l_slices[13]=700;m4l_slices[14]=800;m4l_slices[15]=900;m4l_slices[16]=1500;m4l_slices[17]=2500;m4l_slices[18]=3500;
	
	m4l_bins3     = 13;
	m4l_slices3[0]=105;m4l_slices3[1]=140;m4l_slices3[2]=180;m4l_slices3[3]=220;m4l_slices3[4]=300;m4l_slices3[5]=400;m4l_slices3[6]=500;m4l_slices3[7]=600;m4l_slices3[8]=700;m4l_slices3[9]=800;m4l_slices3[10]=1500;
	m4l_slices3[11]=2000;m4l_slices3[12]=3000;m4l_slices3[13]=4000;
	
	if (splines)
	{
		m4l_bins     = 10;
		m4l_slices[0]=70;m4l_slices[1]=125;m4l_slices[2]=140;m4l_slices[3]=160;m4l_slices[4]=250;m4l_slices[5]=470;m4l_slices[6]=780;m4l_slices[7]=1200;m4l_slices[8]=1700;m4l_slices[9]=2160;m4l_slices[10]=3500;
		
		m4l_bins3     = 10;
		m4l_slices3[0]=70;m4l_slices3[1]=125;m4l_slices3[2]=140;m4l_slices3[3]=160;m4l_slices3[4]=250;m4l_slices3[5]=470;m4l_slices3[6]=780;m4l_slices3[7]=1200;m4l_slices3[8]=1700;m4l_slices3[9]=2160;m4l_slices3[10]=3500;
		//=======================================================
	}
	
	DeclareHistos();
	
	LoadConstants();
	LoadFakeRates();
}

Analyzer::~Analyzer()
{
	if (!fChain) return;
	delete fChain->GetCurrentFile();
}

void Analyzer::FillHistos(TString filename, Float_t lumi, bool only2jEvents)
{
	// if parameter tree is not specified (or zero), connect the file
	// used to generate this class and read the Tree.
	_lumi = lumi;
	input_file_name = filename;
	
	TTree *tree;
	inputfile = TFile::Open(filename);
	TDirectory * dir = (TDirectory*)inputfile->Get(filename);
	tree = (TTree*)inputfile->Get("ZZTree/candTree");
	if ( input_file_name.Contains("Data")) tree = (TTree*)inputfile->Get("CRZLLTree/candTree");
	
	Init(tree,filename);
	Loop(only2jEvents);
}

Int_t Analyzer::GetEntry(Long64_t entry)
{
	// Read contents of entry.
	if (!fChain) return 0;
	return fChain->GetEntry(entry);
}
Long64_t Analyzer::LoadTree(Long64_t entry)
{
	// Set the environment to read one entry
	if (!fChain) return -5;
	Long64_t centry = fChain->LoadTree(entry);
	if (centry < 0) return centry;
	if (fChain->GetTreeNumber() != fCurrent) {
		fCurrent = fChain->GetTreeNumber();
		Notify();
	}
	return centry;
}

void Analyzer::Init(TTree *tree, TString filename)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).
	
	// Set object pointer
	LepPt = 0;
	LepEta = 0;
	LepPhi = 0;
	LepLepId = 0;
	LepSIP = 0;
	LepTime = 0;
	LepisID = 0;
	LepisLoose = 0;
	LepBDT = 0;
	LepMissingHit = 0;
	LepCombRelIsoPF = 0;
	LepRecoSF = 0;
	LepRecoSF_Unc = 0;
	LepSelSF = 0;
	LepSelSF_Unc = 0;
	fsrPt = 0;
	fsrEta = 0;
	fsrPhi = 0;
	fsrLept = 0;
	JetPt = 0;
	JetEta = 0;
	JetPhi = 0;
	JetMass = 0;
	JetBTagger = 0;
	JetIsBtagged = 0;
	JetIsBtaggedWithSF = 0;
	JetIsBtaggedWithSFUp = 0;
	JetIsBtaggedWithSFDn = 0;
	JetQGLikelihood = 0;
	JetAxis2 = 0;
	JetMult = 0;
	JetPtD = 0;
	JetSigma = 0;
	JetHadronFlavour = 0;
	JetPartonFlavour = 0;
	JetJERUp = 0;
	JetJERDown = 0;
	JetPUID = 0;
	JetPUValue = 0;
	ExtraLepPt = 0;
	ExtraLepEta = 0;
	ExtraLepPhi = 0;
	ExtraLepLepId = 0;
	LHEMotherPz = 0;
	LHEMotherE = 0;
	LHEMotherId = 0;
	LHEDaughterPt = 0;
	LHEDaughterEta = 0;
	LHEDaughterPhi = 0;
	LHEDaughterMass = 0;
	LHEDaughterId = 0;
	LHEAssociatedParticlePt = 0;
	LHEAssociatedParticleEta = 0;
	LHEAssociatedParticlePhi = 0;
	LHEAssociatedParticleMass = 0;
	LHEAssociatedParticleId = 0;
	// Set branch addresses and branch pointers
	if (!tree) return;
	fChain = tree;
	fCurrent = -1;
	fChain->SetMakeClass(1);
	
	fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
	fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
	fChain->SetBranchAddress("LumiNumber", &LumiNumber, &b_LumiNumber);
	fChain->SetBranchAddress("NRecoMu", &NRecoMu, &b_NRecoMu);
	fChain->SetBranchAddress("NRecoEle", &NRecoEle, &b_NRecoEle);
	fChain->SetBranchAddress("Nvtx", &Nvtx, &b_Nvtx);
	fChain->SetBranchAddress("NObsInt", &NObsInt, &b_NObsInt);
	fChain->SetBranchAddress("NTrueInt", &NTrueInt, &b_NTrueInt);
	fChain->SetBranchAddress("PFMET", &PFMET, &b_PFMET);
	fChain->SetBranchAddress("PFMET_jesUp", &PFMET_jesUp, &b_PFMET_jesUp);
	fChain->SetBranchAddress("PFMET_jesDn", &PFMET_jesDn, &b_PFMET_jesDn);
	fChain->SetBranchAddress("PFMETPhi", &PFMETPhi, &b_PFMETPhi);
	fChain->SetBranchAddress("nCleanedJets", &nCleanedJets, &b_nCleanedJets);
	fChain->SetBranchAddress("nCleanedJetsPt30", &nCleanedJetsPt30, &b_nCleanedJetsPt30);
	fChain->SetBranchAddress("nCleanedJetsPt30_jecUp", &nCleanedJetsPt30_jecUp, &b_nCleanedJetsPt30_jecUp);
	fChain->SetBranchAddress("nCleanedJetsPt30_jecDn", &nCleanedJetsPt30_jecDn, &b_nCleanedJetsPt30_jecDn);
	fChain->SetBranchAddress("nCleanedJetsPt30BTagged", &nCleanedJetsPt30BTagged, &b_nCleanedJetsPt30BTagged);
	fChain->SetBranchAddress("nCleanedJetsPt30BTagged_bTagSF", &nCleanedJetsPt30BTagged_bTagSF, &b_nCleanedJetsPt30BTagged_bTagSF);
	fChain->SetBranchAddress("nCleanedJetsPt30BTagged_bTagSFUp", &nCleanedJetsPt30BTagged_bTagSFUp, &b_nCleanedJetsPt30BTagged_bTagSFUp);
	fChain->SetBranchAddress("nCleanedJetsPt30BTagged_bTagSFDn", &nCleanedJetsPt30BTagged_bTagSFDn, &b_nCleanedJetsPt30BTagged_bTagSFDn);
	fChain->SetBranchAddress("trigWord", &trigWord, &b_trigWord);
	fChain->SetBranchAddress("ZZMass", &ZZMass, &b_ZZMass);
	fChain->SetBranchAddress("ZZMassErr", &ZZMassErr, &b_ZZMassErr);
	fChain->SetBranchAddress("ZZMassErrCorr", &ZZMassErrCorr, &b_ZZMassErrCorr);
	fChain->SetBranchAddress("ZZMassPreFSR", &ZZMassPreFSR, &b_ZZMassPreFSR);
	fChain->SetBranchAddress("ZZsel", &ZZsel, &b_ZZsel);
	fChain->SetBranchAddress("ZZPt", &ZZPt, &b_ZZPt);
	fChain->SetBranchAddress("ZZEta", &ZZEta, &b_ZZEta);
	fChain->SetBranchAddress("ZZPhi", &ZZPhi, &b_ZZPhi);
	fChain->SetBranchAddress("CRflag", &CRflag, &b_CRflag);
	fChain->SetBranchAddress("Z1Mass", &Z1Mass, &b_Z1Mass);
	fChain->SetBranchAddress("Z1Pt", &Z1Pt, &b_Z1Pt);
	fChain->SetBranchAddress("Z1Flav", &Z1Flav, &b_Z1Flav);
	fChain->SetBranchAddress("ZZMassRefit", &ZZMassRefit, &b_ZZMassRefit);
	fChain->SetBranchAddress("ZZMassRefitErr", &ZZMassRefitErr, &b_ZZMassRefitErr);
	fChain->SetBranchAddress("ZZMassUnrefitErr", &ZZMassUnrefitErr, &b_ZZMassUnrefitErr);
	fChain->SetBranchAddress("Z2Mass", &Z2Mass, &b_Z2Mass);
	fChain->SetBranchAddress("Z2Pt", &Z2Pt, &b_Z2Pt);
	fChain->SetBranchAddress("Z2Flav", &Z2Flav, &b_Z2Flav);
	fChain->SetBranchAddress("costhetastar", &costhetastar, &b_costhetastar);
	fChain->SetBranchAddress("helphi", &helphi, &b_helphi);
	fChain->SetBranchAddress("helcosthetaZ1", &helcosthetaZ1, &b_helcosthetaZ1);
	fChain->SetBranchAddress("helcosthetaZ2", &helcosthetaZ2, &b_helcosthetaZ2);
	fChain->SetBranchAddress("phistarZ1", &phistarZ1, &b_phistarZ1);
	fChain->SetBranchAddress("phistarZ2", &phistarZ2, &b_phistarZ2);
	fChain->SetBranchAddress("xi", &xi, &b_xi);
	fChain->SetBranchAddress("xistar", &xistar, &b_xistar);
	fChain->SetBranchAddress("LepPt", &LepPt, &b_LepPt);
	fChain->SetBranchAddress("LepEta", &LepEta, &b_LepEta);
	fChain->SetBranchAddress("LepPhi", &LepPhi, &b_LepPhi);
	fChain->SetBranchAddress("LepLepId", &LepLepId, &b_LepLepId);
	fChain->SetBranchAddress("LepSIP", &LepSIP, &b_LepSIP);
	fChain->SetBranchAddress("LepTime", &LepTime, &b_LepTime);
	fChain->SetBranchAddress("LepisID", &LepisID, &b_LepisID);
	fChain->SetBranchAddress("LepisLoose", &LepisLoose, &b_LepisLoose);
	fChain->SetBranchAddress("LepBDT", &LepBDT, &b_LepBDT);
	fChain->SetBranchAddress("LepMissingHit", &LepMissingHit, &b_LepMissingHit);
	fChain->SetBranchAddress("LepCombRelIsoPF", &LepCombRelIsoPF, &b_LepCombRelIsoPF);
	fChain->SetBranchAddress("LepRecoSF", &LepRecoSF, &b_LepRecoSF);
	fChain->SetBranchAddress("LepRecoSF_Unc", &LepRecoSF_Unc, &b_LepRecoSF_Unc);
	fChain->SetBranchAddress("LepSelSF", &LepSelSF, &b_LepSelSF);
	fChain->SetBranchAddress("LepSelSF_Unc", &LepSelSF_Unc, &b_LepSelSF_Unc);
	fChain->SetBranchAddress("fsrPt", &fsrPt, &b_fsrPt);
	fChain->SetBranchAddress("fsrEta", &fsrEta, &b_fsrEta);
	fChain->SetBranchAddress("fsrPhi", &fsrPhi, &b_fsrPhi);
	fChain->SetBranchAddress("fsrLept", &fsrLept, &b_fsrLept);
	fChain->SetBranchAddress("passIsoPreFSR", &passIsoPreFSR, &b_passIsoPreFSR);
	fChain->SetBranchAddress("JetPt", &JetPt, &b_JetPt);
	fChain->SetBranchAddress("JetEta", &JetEta, &b_JetEta);
	fChain->SetBranchAddress("JetPhi", &JetPhi, &b_JetPhi);
	fChain->SetBranchAddress("JetMass", &JetMass, &b_JetMass);
	fChain->SetBranchAddress("JetBTagger", &JetBTagger, &b_JetBTagger);
	fChain->SetBranchAddress("JetIsBtagged", &JetIsBtagged, &b_JetIsBtagged);
	fChain->SetBranchAddress("JetIsBtaggedWithSF", &JetIsBtaggedWithSF, &b_JetIsBtaggedWithSF);
	fChain->SetBranchAddress("JetIsBtaggedWithSFUp", &JetIsBtaggedWithSFUp, &b_JetIsBtaggedWithSFUp);
	fChain->SetBranchAddress("JetIsBtaggedWithSFDn", &JetIsBtaggedWithSFDn, &b_JetIsBtaggedWithSFDn);
	fChain->SetBranchAddress("JetQGLikelihood", &JetQGLikelihood, &b_JetQGLikelihood);
	fChain->SetBranchAddress("JetAxis2", &JetAxis2, &b_JetAxis2);
	fChain->SetBranchAddress("JetMult", &JetMult, &b_JetMult);
	fChain->SetBranchAddress("JetPtD", &JetPtD, &b_JetPtD);
	fChain->SetBranchAddress("JetSigma", &JetSigma, &b_JetSigma);
	fChain->SetBranchAddress("JetHadronFlavour", &JetHadronFlavour, &b_JetHadronFlavour);
	fChain->SetBranchAddress("JetPartonFlavour", &JetPartonFlavour, &b_JetPartonFlavour);
	fChain->SetBranchAddress("JetJERUp", &JetJERUp, &b_JetJERUp);
	fChain->SetBranchAddress("JetJERDown", &JetJERDown, &b_JetJERDown);
	fChain->SetBranchAddress("JetPUID", &JetPUID, &b_JetPUID);
	fChain->SetBranchAddress("JetPUValue", &JetPUValue, &b_JetPUValue);
	fChain->SetBranchAddress("DiJetMass", &DiJetMass, &b_DiJetMass);
	fChain->SetBranchAddress("DiJetDEta", &DiJetDEta, &b_DiJetDEta);
	fChain->SetBranchAddress("DiJetFisher", &DiJetFisher, &b_DiJetFisher);
	fChain->SetBranchAddress("nExtraLep", &nExtraLep, &b_nExtraLep);
	fChain->SetBranchAddress("nExtraZ", &nExtraZ, &b_nExtraZ);
	fChain->SetBranchAddress("ExtraLepPt", &ExtraLepPt, &b_ExtraLepPt);
	fChain->SetBranchAddress("ExtraLepEta", &ExtraLepEta, &b_ExtraLepEta);
	fChain->SetBranchAddress("ExtraLepPhi", &ExtraLepPhi, &b_ExtraLepPhi);
	fChain->SetBranchAddress("ExtraLepLepId", &ExtraLepLepId, &b_ExtraLepLepId);
	fChain->SetBranchAddress("ZXFakeweight", &ZXFakeweight, &b_ZXFakeweight);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_Nominal", &KFactor_QCD_ggZZ_Nominal, &b_KFactor_QCD_ggZZ_Nominal);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_PDFScaleDn", &KFactor_QCD_ggZZ_PDFScaleDn, &b_KFactor_QCD_ggZZ_PDFScaleDn);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_PDFScaleUp", &KFactor_QCD_ggZZ_PDFScaleUp, &b_KFactor_QCD_ggZZ_PDFScaleUp);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_QCDScaleDn", &KFactor_QCD_ggZZ_QCDScaleDn, &b_KFactor_QCD_ggZZ_QCDScaleDn);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_QCDScaleUp", &KFactor_QCD_ggZZ_QCDScaleUp, &b_KFactor_QCD_ggZZ_QCDScaleUp);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_AsDn", &KFactor_QCD_ggZZ_AsDn, &b_KFactor_QCD_ggZZ_AsDn);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_AsUp", &KFactor_QCD_ggZZ_AsUp, &b_KFactor_QCD_ggZZ_AsUp);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_PDFReplicaDn", &KFactor_QCD_ggZZ_PDFReplicaDn, &b_KFactor_QCD_ggZZ_PDFReplicaDn);
	if ( filename.Contains("ggTo")) fChain->SetBranchAddress("KFactor_QCD_ggZZ_PDFReplicaUp", &KFactor_QCD_ggZZ_PDFReplicaUp, &b_KFactor_QCD_ggZZ_PDFReplicaUp);
	if ( filename.Contains("ZZTo4l")) fChain->SetBranchAddress("KFactor_EW_qqZZ", &KFactor_EW_qqZZ, &b_KFactor_EW_qqZZ);
	if ( filename.Contains("ZZTo4l")) fChain->SetBranchAddress("KFactor_QCD_qqZZ_M", &KFactor_QCD_qqZZ_M, &b_KFactor_QCD_qqZZ_M);
	if ( !filename.Contains("Data"))
	{
		fChain->SetBranchAddress("genFinalState", &genFinalState, &b_genFinalState);
		fChain->SetBranchAddress("genProcessId", &genProcessId, &b_genProcessId);
		fChain->SetBranchAddress("genHEPMCweight", &genHEPMCweight, &b_genHEPMCweight);
		fChain->SetBranchAddress("PUWeight", &PUWeight, &b_PUWeight);
		fChain->SetBranchAddress("PUWeight_Dn", &PUWeight_Dn, &b_PUWeight_Dn);
		fChain->SetBranchAddress("PUWeight_Up", &PUWeight_Up, &b_PUWeight_Up);
		fChain->SetBranchAddress("dataMCWeight", &dataMCWeight, &b_dataMCWeight);
		//   fChain->SetBranchAddress("dataMCWeight_Unc", &dataMCWeight_Unc, &b_dataMCWeight_Unc);
		fChain->SetBranchAddress("trigEffWeight", &trigEffWeight, &b_trigEffWeight);
		fChain->SetBranchAddress("overallEventWeight", &overallEventWeight, &b_overallEventWeight);
		fChain->SetBranchAddress("HqTMCweight", &HqTMCweight, &b_HqTMCweight);
		fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
		fChain->SetBranchAddress("genExtInfo", &genExtInfo, &b_genExtInfo);
		fChain->SetBranchAddress("GenHMass", &GenHMass, &b_GenHMass);
		fChain->SetBranchAddress("GenHPt", &GenHPt, &b_GenHPt);
		fChain->SetBranchAddress("GenHRapidity", &GenHRapidity, &b_GenHRapidity);
		fChain->SetBranchAddress("GenZ1Mass", &GenZ1Mass, &b_GenZ1Mass);
		fChain->SetBranchAddress("GenZ1Pt", &GenZ1Pt, &b_GenZ1Pt);
		fChain->SetBranchAddress("GenZ1Phi", &GenZ1Phi, &b_GenZ1Phi);
		fChain->SetBranchAddress("GenZ1Flav", &GenZ1Flav, &b_GenZ1Flav);
		fChain->SetBranchAddress("GenZ2Mass", &GenZ2Mass, &b_GenZ2Mass);
		fChain->SetBranchAddress("GenZ2Pt", &GenZ2Pt, &b_GenZ2Pt);
		fChain->SetBranchAddress("GenZ2Phi", &GenZ2Phi, &b_GenZ2Phi);
		fChain->SetBranchAddress("GenZ2Flav", &GenZ2Flav, &b_GenZ2Flav);
		fChain->SetBranchAddress("GenLep1Pt", &GenLep1Pt, &b_GenLep1Pt);
		fChain->SetBranchAddress("GenLep1Eta", &GenLep1Eta, &b_GenLep1Eta);
		fChain->SetBranchAddress("GenLep1Phi", &GenLep1Phi, &b_GenLep1Phi);
		fChain->SetBranchAddress("GenLep1Id", &GenLep1Id, &b_GenLep1Id);
		fChain->SetBranchAddress("GenLep2Pt", &GenLep2Pt, &b_GenLep2Pt);
		fChain->SetBranchAddress("GenLep2Eta", &GenLep2Eta, &b_GenLep2Eta);
		fChain->SetBranchAddress("GenLep2Phi", &GenLep2Phi, &b_GenLep2Phi);
		fChain->SetBranchAddress("GenLep2Id", &GenLep2Id, &b_GenLep2Id);
		fChain->SetBranchAddress("GenLep3Pt", &GenLep3Pt, &b_GenLep3Pt);
		fChain->SetBranchAddress("GenLep3Eta", &GenLep3Eta, &b_GenLep3Eta);
		fChain->SetBranchAddress("GenLep3Phi", &GenLep3Phi, &b_GenLep3Phi);
		fChain->SetBranchAddress("GenLep3Id", &GenLep3Id, &b_GenLep3Id);
		fChain->SetBranchAddress("GenLep4Pt", &GenLep4Pt, &b_GenLep4Pt);
		fChain->SetBranchAddress("GenLep4Eta", &GenLep4Eta, &b_GenLep4Eta);
		fChain->SetBranchAddress("GenLep4Phi", &GenLep4Phi, &b_GenLep4Phi);
		fChain->SetBranchAddress("GenLep4Id", &GenLep4Id, &b_GenLep4Id);
		fChain->SetBranchAddress("GenAssocLep1Pt", &GenAssocLep1Pt, &b_GenAssocLep1Pt);
		fChain->SetBranchAddress("GenAssocLep1Eta", &GenAssocLep1Eta, &b_GenAssocLep1Eta);
		fChain->SetBranchAddress("GenAssocLep1Phi", &GenAssocLep1Phi, &b_GenAssocLep1Phi);
		fChain->SetBranchAddress("GenAssocLep1Id", &GenAssocLep1Id, &b_GenAssocLep1Id);
		fChain->SetBranchAddress("GenAssocLep2Pt", &GenAssocLep2Pt, &b_GenAssocLep2Pt);
		fChain->SetBranchAddress("GenAssocLep2Eta", &GenAssocLep2Eta, &b_GenAssocLep2Eta);
		fChain->SetBranchAddress("GenAssocLep2Phi", &GenAssocLep2Phi, &b_GenAssocLep2Phi);
		fChain->SetBranchAddress("GenAssocLep2Id", &GenAssocLep2Id, &b_GenAssocLep2Id);
	}
	//   fChain->SetBranchAddress("LHEMotherPz", &LHEMotherPz, &b_LHEMotherPz);
	//   fChain->SetBranchAddress("LHEMotherE", &LHEMotherE, &b_LHEMotherE);
	//   fChain->SetBranchAddress("LHEMotherId", &LHEMotherId, &b_LHEMotherId);
	//   fChain->SetBranchAddress("LHEDaughterPt", &LHEDaughterPt, &b_LHEDaughterPt);
	//   fChain->SetBranchAddress("LHEDaughterEta", &LHEDaughterEta, &b_LHEDaughterEta);
	//   fChain->SetBranchAddress("LHEDaughterPhi", &LHEDaughterPhi, &b_LHEDaughterPhi);
	//   fChain->SetBranchAddress("LHEDaughterMass", &LHEDaughterMass, &b_LHEDaughterMass);
	//   fChain->SetBranchAddress("LHEDaughterId", &LHEDaughterId, &b_LHEDaughterId);
	//   fChain->SetBranchAddress("LHEAssociatedParticlePt", &LHEAssociatedParticlePt, &b_LHEAssociatedParticlePt);
	//   fChain->SetBranchAddress("LHEAssociatedParticleEta", &LHEAssociatedParticleEta, &b_LHEAssociatedParticleEta);
	//   fChain->SetBranchAddress("LHEAssociatedParticlePhi", &LHEAssociatedParticlePhi, &b_LHEAssociatedParticlePhi);
	//   fChain->SetBranchAddress("LHEAssociatedParticleMass", &LHEAssociatedParticleMass, &b_LHEAssociatedParticleMass);
	//   fChain->SetBranchAddress("LHEAssociatedParticleId", &LHEAssociatedParticleId, &b_LHEAssociatedParticleId);
	//   fChain->SetBranchAddress("LHEPDFScale", &LHEPDFScale, &b_LHEPDFScale);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR1_muF1", &LHEweight_QCDscale_muR1_muF1, &b_LHEweight_QCDscale_muR1_muF1);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR1_muF2", &LHEweight_QCDscale_muR1_muF2, &b_LHEweight_QCDscale_muR1_muF2);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR1_muF0p5", &LHEweight_QCDscale_muR1_muF0p5, &b_LHEweight_QCDscale_muR1_muF0p5);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR2_muF1", &LHEweight_QCDscale_muR2_muF1, &b_LHEweight_QCDscale_muR2_muF1);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR2_muF2", &LHEweight_QCDscale_muR2_muF2, &b_LHEweight_QCDscale_muR2_muF2);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR2_muF0p5", &LHEweight_QCDscale_muR2_muF0p5, &b_LHEweight_QCDscale_muR2_muF0p5);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF1", &LHEweight_QCDscale_muR0p5_muF1, &b_LHEweight_QCDscale_muR0p5_muF1);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF2", &LHEweight_QCDscale_muR0p5_muF2, &b_LHEweight_QCDscale_muR0p5_muF2);
	//   fChain->SetBranchAddress("LHEweight_QCDscale_muR0p5_muF0p5", &LHEweight_QCDscale_muR0p5_muF0p5, &b_LHEweight_QCDscale_muR0p5_muF0p5);
	//   fChain->SetBranchAddress("LHEweight_PDFVariation_Up", &LHEweight_PDFVariation_Up, &b_LHEweight_PDFVariation_Up);
	//   fChain->SetBranchAddress("LHEweight_PDFVariation_Dn", &LHEweight_PDFVariation_Dn, &b_LHEweight_PDFVariation_Dn);
	//   fChain->SetBranchAddress("LHEweight_AsMZ_Up", &LHEweight_AsMZ_Up, &b_LHEweight_AsMZ_Up);
	//   fChain->SetBranchAddress("LHEweight_AsMZ_Dn", &LHEweight_AsMZ_Dn, &b_LHEweight_AsMZ_Dn);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen", &p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz2_1_JHUGen", &p_GG_SIG_ghg2_1_ghz2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz2_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz4_1_JHUGen", &p_GG_SIG_ghg2_1_ghz4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz4_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen", &p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen, &b_p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghza2_1_JHUGen", &p_GG_SIG_ghg2_1_ghza2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghza2_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghza4_1_JHUGen", &p_GG_SIG_ghg2_1_ghza4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghza4_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_gha2_1_JHUGen", &p_GG_SIG_ghg2_1_gha2_1_JHUGen, &b_p_GG_SIG_ghg2_1_gha2_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_gha4_1_JHUGen", &p_GG_SIG_ghg2_1_gha4_1_JHUGen, &b_p_GG_SIG_ghg2_1_gha4_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz2_i_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghz4_i_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghza1prime2_1E4i_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghza2_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_ghza4_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_gha2_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen", &p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen, &b_p_GG_SIG_ghg2_1_ghz1_1_gha4_1_JHUGen);
	fChain->SetBranchAddress("pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal", &pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal, &b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JVBF_SIG_ghv1_1_JHUGen_JECNominal", &p_JVBF_SIG_ghv1_1_JHUGen_JECNominal, &b_p_JVBF_SIG_ghv1_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JQCD_SIG_ghg2_1_JHUGen_JECNominal", &p_JQCD_SIG_ghg2_1_JHUGen_JECNominal, &b_p_JQCD_SIG_ghg2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal", &p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghza2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghza4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_gha2_1_JHUGen_JECNominal", &p_JJVBF_SIG_gha2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_gha2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_gha4_1_JHUGen_JECNominal", &p_JJVBF_SIG_gha4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_gha4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal", &p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal, &b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal", &p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal", &p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal, &b_p_JJQCD_SIG_ghg4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal", &p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal, &b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal", &p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal", &p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal, &b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghza2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghza2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghza4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghza4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_gha2_1_JHUGen_JECNominal", &p_HadZH_SIG_gha2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_gha2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_gha4_1_JHUGen_JECNominal", &p_HadZH_SIG_gha4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_gha4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal", &p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal, &b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadZH_mavjj_JECNominal", &p_HadZH_mavjj_JECNominal, &b_p_HadZH_mavjj_JECNominal);
	fChain->SetBranchAddress("p_HadWH_mavjj_JECNominal", &p_HadWH_mavjj_JECNominal, &b_p_HadWH_mavjj_JECNominal);
	fChain->SetBranchAddress("p_HadZH_mavjj_true_JECNominal", &p_HadZH_mavjj_true_JECNominal, &b_p_HadZH_mavjj_true_JECNominal);
	fChain->SetBranchAddress("p_HadWH_mavjj_true_JECNominal", &p_HadWH_mavjj_true_JECNominal, &b_p_HadWH_mavjj_true_JECNominal);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw1_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal", &p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw2_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw2_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw4_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw4_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal", &p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal", &p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal, &b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal", &p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal, &b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal", &p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal, &b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal", &p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal, &b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("p_bbH_SIG_kappa_1_JHUGen_JECNominal", &p_bbH_SIG_kappa_1_JHUGen_JECNominal, &b_p_bbH_SIG_kappa_1_JHUGen_JECNominal);
	fChain->SetBranchAddress("pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp", &pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp, &b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JVBF_SIG_ghv1_1_JHUGen_JECUp", &p_JVBF_SIG_ghv1_1_JHUGen_JECUp, &b_p_JVBF_SIG_ghv1_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JQCD_SIG_ghg2_1_JHUGen_JECUp", &p_JQCD_SIG_ghg2_1_JHUGen_JECUp, &b_p_JQCD_SIG_ghg2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp", &p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp", &p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp, &b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghza2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghza2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghza4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghza4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_gha2_1_JHUGen_JECUp", &p_JJVBF_SIG_gha2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_gha2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_gha4_1_JHUGen_JECUp", &p_JJVBF_SIG_gha4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_gha4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp", &p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp, &b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECUp", &p_JJQCD_SIG_ghg2_1_JHUGen_JECUp, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg4_1_JHUGen_JECUp", &p_JJQCD_SIG_ghg4_1_JHUGen_JECUp, &b_p_JJQCD_SIG_ghg4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp", &p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp, &b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp", &p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz2_1_JHUGen_JECUp", &p_HadZH_SIG_ghz2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz4_1_JHUGen_JECUp", &p_HadZH_SIG_ghz4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp", &p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp, &b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza2_1_JHUGen_JECUp", &p_HadZH_SIG_ghza2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghza2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza4_1_JHUGen_JECUp", &p_HadZH_SIG_ghza4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghza4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_gha2_1_JHUGen_JECUp", &p_HadZH_SIG_gha2_1_JHUGen_JECUp, &b_p_HadZH_SIG_gha2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_gha4_1_JHUGen_JECUp", &p_HadZH_SIG_gha4_1_JHUGen_JECUp, &b_p_HadZH_SIG_gha4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp", &p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp, &b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_JHUGen_JECUp", &p_HadWH_SIG_ghw1_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp", &p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw2_1_JHUGen_JECUp", &p_HadWH_SIG_ghw2_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw4_1_JHUGen_JECUp", &p_HadWH_SIG_ghw4_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp", &p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp", &p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp", &p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp, &b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp", &p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp, &b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp", &p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp, &b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp", &p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp, &b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECUp);
	fChain->SetBranchAddress("p_bbH_SIG_kappa_1_JHUGen_JECUp", &p_bbH_SIG_kappa_1_JHUGen_JECUp, &b_p_bbH_SIG_kappa_1_JHUGen_JECUp);
	fChain->SetBranchAddress("pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn", &pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn, &b_pAux_JVBF_SIG_ghv1_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JVBF_SIG_ghv1_1_JHUGen_JECDn", &p_JVBF_SIG_ghv1_1_JHUGen_JECDn, &b_p_JVBF_SIG_ghv1_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JQCD_SIG_ghg2_1_JHUGen_JECDn", &p_JQCD_SIG_ghg2_1_JHUGen_JECDn, &b_p_JQCD_SIG_ghg2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn", &p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn", &p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn, &b_p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghza2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghza2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghza4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghza4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghza4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_gha2_1_JHUGen_JECDn", &p_JJVBF_SIG_gha2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_gha2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_gha4_1_JHUGen_JECDn", &p_JJVBF_SIG_gha4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_gha4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghv1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghv2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghv4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghza1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghza2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_ghza4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_gha2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn", &p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn, &b_p_JJVBF_SIG_ghv1_1_gha4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECDn", &p_JJQCD_SIG_ghg2_1_JHUGen_JECDn, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg4_1_JHUGen_JECDn", &p_JJQCD_SIG_ghg4_1_JHUGen_JECDn, &b_p_JJQCD_SIG_ghg4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn", &p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn, &b_p_JJQCD_SIG_ghg2_1_ghg4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn", &p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz2_1_JHUGen_JECDn", &p_HadZH_SIG_ghz2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz4_1_JHUGen_JECDn", &p_HadZH_SIG_ghz4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn", &p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn, &b_p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza2_1_JHUGen_JECDn", &p_HadZH_SIG_ghza2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghza2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghza4_1_JHUGen_JECDn", &p_HadZH_SIG_ghza4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghza4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_gha2_1_JHUGen_JECDn", &p_HadZH_SIG_gha2_1_JHUGen_JECDn, &b_p_HadZH_SIG_gha2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_gha4_1_JHUGen_JECDn", &p_HadZH_SIG_gha4_1_JHUGen_JECDn, &b_p_HadZH_SIG_gha4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghz2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghz4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghza2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_ghza4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_gha2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn", &p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn, &b_p_HadZH_SIG_ghz1_1_gha4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_JHUGen_JECDn", &p_HadWH_SIG_ghw1_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn", &p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw2_1_JHUGen_JECDn", &p_HadWH_SIG_ghw2_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw4_1_JHUGen_JECDn", &p_HadWH_SIG_ghw4_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn", &p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn", &p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1_1_ghw2_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn", &p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn, &b_p_HadWH_SIG_ghw1_1_ghw4_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn", &p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn, &b_p_ttHUndecayed_SIG_kappa_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn", &p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn, &b_p_ttHUndecayed_SIG_kappatilde_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn", &p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn, &b_p_ttHUndecayed_SIG_kappa_1_kappatilde_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_bbH_SIG_kappa_1_JHUGen_JECDn", &p_bbH_SIG_kappa_1_JHUGen_JECDn, &b_p_bbH_SIG_kappa_1_JHUGen_JECDn);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_JHUGen", &p_LepZH_SIG_ghz1_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1prime2_1E4_JHUGen", &p_LepZH_SIG_ghz1prime2_1E4_JHUGen, &b_p_LepZH_SIG_ghz1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz2_1_JHUGen", &p_LepZH_SIG_ghz2_1_JHUGen, &b_p_LepZH_SIG_ghz2_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz4_1_JHUGen", &p_LepZH_SIG_ghz4_1_JHUGen, &b_p_LepZH_SIG_ghz4_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghza1prime2_1E4_JHUGen", &p_LepZH_SIG_ghza1prime2_1E4_JHUGen, &b_p_LepZH_SIG_ghza1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghza2_1_JHUGen", &p_LepZH_SIG_ghza2_1_JHUGen, &b_p_LepZH_SIG_ghza2_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghza4_1_JHUGen", &p_LepZH_SIG_ghza4_1_JHUGen, &b_p_LepZH_SIG_ghza4_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_gha2_1_JHUGen", &p_LepZH_SIG_gha2_1_JHUGen, &b_p_LepZH_SIG_gha2_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_gha4_1_JHUGen", &p_LepZH_SIG_gha4_1_JHUGen, &b_p_LepZH_SIG_gha4_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen", &p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghz1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen", &p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghz2_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen", &p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghz4_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen", &p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghza1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen", &p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghza2_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen", &p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_ghza4_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_gha2_1_JHUGen", &p_LepZH_SIG_ghz1_1_gha2_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_gha2_1_JHUGen);
	fChain->SetBranchAddress("p_LepZH_SIG_ghz1_1_gha4_1_JHUGen", &p_LepZH_SIG_ghz1_1_gha4_1_JHUGen, &b_p_LepZH_SIG_ghz1_1_gha4_1_JHUGen);
	fChain->SetBranchAddress("p_LepWH_SIG_ghw1_1_JHUGen", &p_LepWH_SIG_ghw1_1_JHUGen, &b_p_LepWH_SIG_ghw1_1_JHUGen);
	fChain->SetBranchAddress("p_LepWH_SIG_ghw1prime2_1E4_JHUGen", &p_LepWH_SIG_ghw1prime2_1E4_JHUGen, &b_p_LepWH_SIG_ghw1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_LepWH_SIG_ghw2_1_JHUGen", &p_LepWH_SIG_ghw2_1_JHUGen, &b_p_LepWH_SIG_ghw2_1_JHUGen);
	fChain->SetBranchAddress("p_LepWH_SIG_ghw4_1_JHUGen", &p_LepWH_SIG_ghw4_1_JHUGen, &b_p_LepWH_SIG_ghw4_1_JHUGen);
	fChain->SetBranchAddress("p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen", &p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen, &b_p_LepWH_SIG_ghw1_1_ghw1prime2_1E4_JHUGen);
	fChain->SetBranchAddress("p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen", &p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen, &b_p_LepWH_SIG_ghw1_1_ghw2_1_JHUGen);
	fChain->SetBranchAddress("p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen", &p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen, &b_p_LepWH_SIG_ghw1_1_ghw4_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen", &p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen, &b_p_QQB_SIG_ZPqqLR_1_gZPz1_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen", &p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen, &b_p_QQB_SIG_ZPqqLR_1_gZPz2_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gZPz1_1_JHUGen", &p_INDEPENDENT_SIG_gZPz1_1_JHUGen, &b_p_INDEPENDENT_SIG_gZPz1_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gZPz2_1_JHUGen", &p_INDEPENDENT_SIG_gZPz2_1_JHUGen, &b_p_INDEPENDENT_SIG_gZPz2_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz1_1_JHUGen", &p_GG_SIG_gXg1_1_gXz1_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz1_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg2_1_gXz2_1_JHUGen", &p_GG_SIG_gXg2_1_gXz2_1_JHUGen, &b_p_GG_SIG_gXg2_1_gXz2_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg3_1_gXz3_1_JHUGen", &p_GG_SIG_gXg3_1_gXz3_1_JHUGen, &b_p_GG_SIG_gXg3_1_gXz3_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg4_1_gXz4_1_JHUGen", &p_GG_SIG_gXg4_1_gXz4_1_JHUGen, &b_p_GG_SIG_gXg4_1_gXz4_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz5_1_JHUGen", &p_GG_SIG_gXg1_1_gXz5_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz5_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen", &p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz6_1_JHUGen", &p_GG_SIG_gXg1_1_gXz6_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz6_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg1_1_gXz7_1_JHUGen", &p_GG_SIG_gXg1_1_gXz7_1_JHUGen, &b_p_GG_SIG_gXg1_1_gXz7_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg5_1_gXz8_1_JHUGen", &p_GG_SIG_gXg5_1_gXz8_1_JHUGen, &b_p_GG_SIG_gXg5_1_gXz8_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg5_1_gXz9_1_JHUGen", &p_GG_SIG_gXg5_1_gXz9_1_JHUGen, &b_p_GG_SIG_gXg5_1_gXz9_1_JHUGen);
	fChain->SetBranchAddress("p_GG_SIG_gXg5_1_gXz10_1_JHUGen", &p_GG_SIG_gXg5_1_gXz10_1_JHUGen, &b_p_GG_SIG_gXg5_1_gXz10_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz1_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz2_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz3_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz4_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz5_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz1_1_gXz5_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz6_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz7_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz8_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz9_1_JHUGen);
	fChain->SetBranchAddress("p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen", &p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen, &b_p_QQB_SIG_XqqLR_1_gXz10_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz1_1_JHUGen", &p_INDEPENDENT_SIG_gXz1_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz1_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz2_1_JHUGen", &p_INDEPENDENT_SIG_gXz2_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz2_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz3_1_JHUGen", &p_INDEPENDENT_SIG_gXz3_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz3_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz4_1_JHUGen", &p_INDEPENDENT_SIG_gXz4_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz4_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz5_1_JHUGen", &p_INDEPENDENT_SIG_gXz5_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz5_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen", &p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz1_1_gXz5_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz6_1_JHUGen", &p_INDEPENDENT_SIG_gXz6_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz6_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz7_1_JHUGen", &p_INDEPENDENT_SIG_gXz7_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz7_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz8_1_JHUGen", &p_INDEPENDENT_SIG_gXz8_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz8_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz9_1_JHUGen", &p_INDEPENDENT_SIG_gXz9_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz9_1_JHUGen);
	fChain->SetBranchAddress("p_INDEPENDENT_SIG_gXz10_1_JHUGen", &p_INDEPENDENT_SIG_gXz10_1_JHUGen, &b_p_INDEPENDENT_SIG_gXz10_1_JHUGen);
	fChain->SetBranchAddress("pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM", &pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM, &b_pConst_GG_SIG_kappaTopBot_1_ghz1_1_MCFM);
	fChain->SetBranchAddress("p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM", &p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM, &b_p_GG_SIG_kappaTopBot_1_ghz1_1_MCFM);
	fChain->SetBranchAddress("p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM", &p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM, &b_p_GG_BSI_kappaTopBot_1_ghz1_1_MCFM);
	fChain->SetBranchAddress("p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM", &p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM, &b_p_GG_BSI_kappaTopBot_1_ghz1_i_MCFM);
	fChain->SetBranchAddress("pConst_GG_BKG_MCFM", &pConst_GG_BKG_MCFM, &b_pConst_GG_BKG_MCFM);
	fChain->SetBranchAddress("p_GG_BKG_MCFM", &p_GG_BKG_MCFM, &b_p_GG_BKG_MCFM);
	fChain->SetBranchAddress("pConst_QQB_BKG_MCFM", &pConst_QQB_BKG_MCFM, &b_pConst_QQB_BKG_MCFM);
	fChain->SetBranchAddress("p_QQB_BKG_MCFM", &p_QQB_BKG_MCFM, &b_p_QQB_BKG_MCFM);
	fChain->SetBranchAddress("p_ZJJ_BKG_MCFM", &p_ZJJ_BKG_MCFM, &b_p_ZJJ_BKG_MCFM);
	fChain->SetBranchAddress("p_JJEW_SIG_ghv1_1_MCFM_JECNominal", &p_JJEW_SIG_ghv1_1_MCFM_JECNominal, &b_p_JJEW_SIG_ghv1_1_MCFM_JECNominal);
	fChain->SetBranchAddress("p_JJEW_BSI_ghv1_1_MCFM_JECNominal", &p_JJEW_BSI_ghv1_1_MCFM_JECNominal, &b_p_JJEW_BSI_ghv1_1_MCFM_JECNominal);
	fChain->SetBranchAddress("p_JJEW_BSI_ghv1_i_MCFM_JECNominal", &p_JJEW_BSI_ghv1_i_MCFM_JECNominal, &b_p_JJEW_BSI_ghv1_i_MCFM_JECNominal);
	fChain->SetBranchAddress("p_JJEW_BKG_MCFM_JECNominal", &p_JJEW_BKG_MCFM_JECNominal, &b_p_JJEW_BKG_MCFM_JECNominal);
	fChain->SetBranchAddress("p_JJVBF_BKG_MCFM_JECNominal", &p_JJVBF_BKG_MCFM_JECNominal, &b_p_JJVBF_BKG_MCFM_JECNominal);
	fChain->SetBranchAddress("p_JJQCD_BKG_MCFM_JECNominal", &p_JJQCD_BKG_MCFM_JECNominal, &b_p_JJQCD_BKG_MCFM_JECNominal);
	fChain->SetBranchAddress("p_JJEW_SIG_ghv1_1_MCFM_JECUp", &p_JJEW_SIG_ghv1_1_MCFM_JECUp, &b_p_JJEW_SIG_ghv1_1_MCFM_JECUp);
	fChain->SetBranchAddress("p_JJEW_BSI_ghv1_1_MCFM_JECUp", &p_JJEW_BSI_ghv1_1_MCFM_JECUp, &b_p_JJEW_BSI_ghv1_1_MCFM_JECUp);
	fChain->SetBranchAddress("p_JJEW_BSI_ghv1_i_MCFM_JECUp", &p_JJEW_BSI_ghv1_i_MCFM_JECUp, &b_p_JJEW_BSI_ghv1_i_MCFM_JECUp);
	fChain->SetBranchAddress("p_JJEW_BKG_MCFM_JECUp", &p_JJEW_BKG_MCFM_JECUp, &b_p_JJEW_BKG_MCFM_JECUp);
	fChain->SetBranchAddress("p_JJVBF_BKG_MCFM_JECUp", &p_JJVBF_BKG_MCFM_JECUp, &b_p_JJVBF_BKG_MCFM_JECUp);
	fChain->SetBranchAddress("p_JJQCD_BKG_MCFM_JECUp", &p_JJQCD_BKG_MCFM_JECUp, &b_p_JJQCD_BKG_MCFM_JECUp);
	fChain->SetBranchAddress("p_JJEW_SIG_ghv1_1_MCFM_JECDn", &p_JJEW_SIG_ghv1_1_MCFM_JECDn, &b_p_JJEW_SIG_ghv1_1_MCFM_JECDn);
	fChain->SetBranchAddress("p_JJEW_BSI_ghv1_1_MCFM_JECDn", &p_JJEW_BSI_ghv1_1_MCFM_JECDn, &b_p_JJEW_BSI_ghv1_1_MCFM_JECDn);
	fChain->SetBranchAddress("p_JJEW_BSI_ghv1_i_MCFM_JECDn", &p_JJEW_BSI_ghv1_i_MCFM_JECDn, &b_p_JJEW_BSI_ghv1_i_MCFM_JECDn);
	fChain->SetBranchAddress("p_JJEW_BKG_MCFM_JECDn", &p_JJEW_BKG_MCFM_JECDn, &b_p_JJEW_BKG_MCFM_JECDn);
	fChain->SetBranchAddress("p_JJVBF_BKG_MCFM_JECDn", &p_JJVBF_BKG_MCFM_JECDn, &b_p_JJVBF_BKG_MCFM_JECDn);
	fChain->SetBranchAddress("p_JJQCD_BKG_MCFM_JECDn", &p_JJQCD_BKG_MCFM_JECDn, &b_p_JJQCD_BKG_MCFM_JECDn);
	fChain->SetBranchAddress("p_m4l_SIG", &p_m4l_SIG, &b_p_m4l_SIG);
	fChain->SetBranchAddress("p_m4l_BKG", &p_m4l_BKG, &b_p_m4l_BKG);
	fChain->SetBranchAddress("p_m4l_SIG_ScaleDown", &p_m4l_SIG_ScaleDown, &b_p_m4l_SIG_ScaleDown);
	fChain->SetBranchAddress("p_m4l_BKG_ScaleDown", &p_m4l_BKG_ScaleDown, &b_p_m4l_BKG_ScaleDown);
	fChain->SetBranchAddress("p_m4l_SIG_ResDown", &p_m4l_SIG_ResDown, &b_p_m4l_SIG_ResDown);
	fChain->SetBranchAddress("p_m4l_BKG_ResDown", &p_m4l_BKG_ResDown, &b_p_m4l_BKG_ResDown);
	fChain->SetBranchAddress("p_m4l_SIG_ScaleUp", &p_m4l_SIG_ScaleUp, &b_p_m4l_SIG_ScaleUp);
	fChain->SetBranchAddress("p_m4l_BKG_ScaleUp", &p_m4l_BKG_ScaleUp, &b_p_m4l_BKG_ScaleUp);
	fChain->SetBranchAddress("p_m4l_SIG_ResUp", &p_m4l_SIG_ResUp, &b_p_m4l_SIG_ResUp);
	fChain->SetBranchAddress("p_m4l_BKG_ResUp", &p_m4l_BKG_ResUp, &b_p_m4l_BKG_ResUp);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ", &p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal_BestDJJ);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ", &p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal_BestDJJ);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ", &p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECUp_BestDJJ);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ", &p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECUp_BestDJJ);
	fChain->SetBranchAddress("p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ", &p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ, &b_p_JJVBF_SIG_ghv1_1_JHUGen_JECDn_BestDJJ);
	fChain->SetBranchAddress("p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ", &p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ, &b_p_JJQCD_SIG_ghg2_1_JHUGen_JECDn_BestDJJ);
	//   fChain->SetBranchAddress("p_Gen_CPStoBWPropRewgt", &p_Gen_CPStoBWPropRewgt, &b_p_Gen_CPStoBWPropRewgt);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1prime2_1E4_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1prime2_1E4_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1prime2_1E4_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz2_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz2_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz4_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz4_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghza1prime2_1E4_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghza1prime2_1E4_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghza1prime2_1E4_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghza2_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghza2_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghza2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghza4_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghza4_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghza4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_gha2_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_gha2_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_gha2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_gha4_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_gha4_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_gha4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4i_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4i_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz1prime2_1E4i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_i_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_i_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz2_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_i_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_i_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghz4_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4i_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4i_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza1prime2_1E4i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_i_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_i_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza2_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_i_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_i_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_ghza4_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_i_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_i_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha2_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_1_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_1_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_i_MCFM", &p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_i_MCFM, &b_p_Gen_GG_SIG_kappaTopBot_1_ghz1_1_gha4_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghz1_1_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghz1_1_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghz1_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghz1_i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghz1_i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghz1_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghz1prime2_1E4i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghz2_1_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghz2_1_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghz2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghz2_i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghz2_i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghz2_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghz4_1_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghz4_1_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghz4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghz4_i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghz4_i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghz4_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghza1prime2_1E4i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghza2_1_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghza2_1_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghza2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghza2_i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghza2_i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghza2_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghza4_1_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghza4_1_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghza4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_ghza4_i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_ghza4_i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_ghza4_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_gha2_1_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_gha2_1_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_gha2_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_gha2_i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_gha2_i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_gha2_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_gha4_1_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_gha4_1_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_gha4_1_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BSI_kappaTopBot_1_gha4_i_MCFM", &p_Gen_GG_BSI_kappaTopBot_1_gha4_i_MCFM, &b_p_Gen_GG_BSI_kappaTopBot_1_gha4_i_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_BKG_MCFM", &p_Gen_GG_BKG_MCFM, &b_p_Gen_GG_BKG_MCFM);
	//   fChain->SetBranchAddress("p_Gen_QQB_BKG_MCFM", &p_Gen_QQB_BKG_MCFM, &b_p_Gen_QQB_BKG_MCFM);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg1_1_gXz1_1_JHUGen", &p_Gen_GG_SIG_gXg1_1_gXz1_1_JHUGen, &b_p_Gen_GG_SIG_gXg1_1_gXz1_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg2_1_gXz2_1_JHUGen", &p_Gen_GG_SIG_gXg2_1_gXz2_1_JHUGen, &b_p_Gen_GG_SIG_gXg2_1_gXz2_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg3_1_gXz3_1_JHUGen", &p_Gen_GG_SIG_gXg3_1_gXz3_1_JHUGen, &b_p_Gen_GG_SIG_gXg3_1_gXz3_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg4_1_gXz4_1_JHUGen", &p_Gen_GG_SIG_gXg4_1_gXz4_1_JHUGen, &b_p_Gen_GG_SIG_gXg4_1_gXz4_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg1_1_gXz5_1_JHUGen", &p_Gen_GG_SIG_gXg1_1_gXz5_1_JHUGen, &b_p_Gen_GG_SIG_gXg1_1_gXz5_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen", &p_Gen_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen, &b_p_Gen_GG_SIG_gXg1_1_gXz1_1_gXz5_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg1_1_gXz6_1_JHUGen", &p_Gen_GG_SIG_gXg1_1_gXz6_1_JHUGen, &b_p_Gen_GG_SIG_gXg1_1_gXz6_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg1_1_gXz7_1_JHUGen", &p_Gen_GG_SIG_gXg1_1_gXz7_1_JHUGen, &b_p_Gen_GG_SIG_gXg1_1_gXz7_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg5_1_gXz8_1_JHUGen", &p_Gen_GG_SIG_gXg5_1_gXz8_1_JHUGen, &b_p_Gen_GG_SIG_gXg5_1_gXz8_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg5_1_gXz9_1_JHUGen", &p_Gen_GG_SIG_gXg5_1_gXz9_1_JHUGen, &b_p_Gen_GG_SIG_gXg5_1_gXz9_1_JHUGen);
	//   fChain->SetBranchAddress("p_Gen_GG_SIG_gXg5_1_gXz10_1_JHUGen", &p_Gen_GG_SIG_gXg5_1_gXz10_1_JHUGen, &b_p_Gen_GG_SIG_gXg5_1_gXz10_1_JHUGen);
	Notify();
}

Bool_t Analyzer::Notify()
{
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make changes
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.
	
	return kTRUE;
}

void Analyzer::Show(Long64_t entry)
{
	// Print contents of entry.
	// If entry is not specified, print current entry
	if (!fChain) return;
	fChain->Show(entry);
}
Int_t Analyzer::Cut(Long64_t entry)
{
	// This function may be called from Loop.
	// returns  1 if entry is accepted.
	// returns -1 otherwise.
	return 1;
}
#endif // #ifdef Analyzer_cxx
