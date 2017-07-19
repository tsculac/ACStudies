#define Analyzer_cxx
#include "Analyzer.h"
#include "Functions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyzer::Loop(TProfile *p, TH1F *h, TH1F *h_VBF2j, TH1F *h_VH, TH2F *h2_VBF2j, TH2F *h2_VH)
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   
   hCounters = (TH1F*)inputfile->Get("ZZTree/Counters");
   gen_sum_weights = (Long64_t)hCounters->GetBinContent(40);
   
   VBF1j_file   = new TFile("cConstants/SmoothKDConstant_m4l_DjVBF13TeV.root");
   VBF1j_spline = (TSpline3*)VBF1j_file->Get("sp_gr_varTrue_Constant_Smooth");
   VBF2j_file = new TFile("cConstants/SmoothKDConstant_m4l_DjjVBF13TeV.root");
   VBF2j_spline = (TSpline3*)VBF2j_file->Get("sp_gr_varTrue_Constant_Smooth");
   WH_file = new TFile("cConstants/SmoothKDConstant_m4l_DjjWH13TeV.root");
   WH_spline = (TSpline3*)WH_file->Get("sp_gr_varTrue_Constant_Smooth");
   ZH_file = new TFile("cConstants/SmoothKDConstant_m4l_DjjZH13TeV.root");
   ZH_spline = (TSpline3*)ZH_file->Get("sp_gr_varTrue_Constant_Smooth");

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {//Loop po eventovima
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      if (nCleanedJetsPt30 <= 1) continue;
      
      // K factors
      //=================================
      _k_factor = 1;
      if ( input_file_name.Contains("ZZTo4l"))
      {
         _k_factor = KFactor_EW_qqZZ * KFactor_QCD_qqZZ_M; // As of Moriond2016
      }
      else if ( input_file_name.Contains("ggTo"))
      {
         _k_factor = KFactor_QCD_ggZZ_Nominal; // as of Moriond2016
      }
      //================================= _k_factor = calculate_K_factor(input_file_name);
      
      // Final event weight
      _event_weight = (_lumi * 1000 * xsec *_k_factor * overallEventWeight) / gen_sum_weights; //removed xsec
      //cout << "weight=" << _event_weight << "   lumi="<< _lumi << "  xsec="<< xsec<< "   k_factor=" << _k_factor<< "   overalEveW=" << overallEventWeight << endl;

      
      // DISCRIMINANTS
      //=================================
      Float_t cConstant_VBF2j = VBF1j_spline->Eval(ZZMass);
      Float_t cConstant_VBF1j = VBF2j_spline->Eval(ZZMass);
      Float_t cConstant_ZH    = ZH_spline->Eval(ZZMass);
      Float_t cConstant_WH    = WH_spline->Eval(ZZMass);
      
   
      if (p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal != 0) DVBF2j_ME = 1./(1.+ cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal/p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal);
      else DVBF2j_ME = -1;

      if (p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal != 0) DVBF1j_ME = 1./(1.+ cConstant_VBF1j*p_JQCD_SIG_ghg2_1_JHUGen_JECNominal/(p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal));
      else DVBF1j_ME = -1;

      if (p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*p_HadZH_mavjj_JECNominal != 0) DZH_ME = 1./(1.+ cConstant_ZH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal)/(p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*p_HadZH_mavjj_JECNominal));
      else DZH_ME = -1;

      if (p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*p_HadWH_mavjj_JECNominal != 0) DWH_ME = 1./(1.+ cConstant_WH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal)/(p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*p_HadWH_mavjj_JECNominal));
      else DWH_ME = -1;
      
      DVH_ME = TMath::Max( DZH_ME, DWH_ME );

      //=================================
      
      
      p->Fill(ZZMass,ZZMass,_event_weight);
      h->Fill(ZZMass, _event_weight);
      h2_VBF2j->Fill(ZZMass, DVBF2j_ME, _event_weight);
      h2_VH->Fill(ZZMass,DVH_ME, _event_weight);
      if( DVBF2j_ME > 0.5 ) h_VBF2j->Fill(ZZMass, _event_weight);
      if( DVH_ME > 0.5 ) h_VH->Fill(ZZMass, _event_weight);
      
      
   }//Kraj loop-a po eventovima
   
   VBF1j_file->Close();
   VBF2j_file->Close();
   WH_file->Close();
   ZH_file->Close();
   
   cout << "[INFO] File " << input_file_name << " is processed." << endl;
}


void Analyzer::LoopForEff(TH1F *h_VBF2j, TH1F *h_VH)
{
   if (fChain == 0) return;
   
   Long64_t nentries = fChain->GetEntriesFast();
   
   hCounters = (TH1F*)inputfile->Get("ZZTree/Counters");
   gen_sum_weights = (Long64_t)hCounters->GetBinContent(40);
   
   VBF1j_file   = new TFile("cConstants/SmoothKDConstant_m4l_DjVBF13TeV.root");
   VBF1j_spline = (TSpline3*)VBF1j_file->Get("sp_gr_varTrue_Constant_Smooth");
   VBF2j_file = new TFile("cConstants/SmoothKDConstant_m4l_DjjVBF13TeV.root");
   VBF2j_spline = (TSpline3*)VBF2j_file->Get("sp_gr_varTrue_Constant_Smooth");
   WH_file = new TFile("cConstants/SmoothKDConstant_m4l_DjjWH13TeV.root");
   WH_spline = (TSpline3*)WH_file->Get("sp_gr_varTrue_Constant_Smooth");
   ZH_file = new TFile("cConstants/SmoothKDConstant_m4l_DjjZH13TeV.root");
   ZH_spline = (TSpline3*)ZH_file->Get("sp_gr_varTrue_Constant_Smooth");
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {//Loop po eventovima
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      if (nCleanedJetsPt30 <= 1) continue;
      if (ZZMass < 110 || ZZMass > 140) continue;
      
      // K factors
      //=================================
      _k_factor = 1;
      if ( input_file_name.Contains("ZZTo4l"))
      {
         _k_factor = KFactor_EW_qqZZ * KFactor_QCD_qqZZ_M; // As of Moriond2016
      }
      else if ( input_file_name.Contains("ggTo"))
      {
         _k_factor = KFactor_QCD_ggZZ_Nominal; // as of Moriond2016
      }
      //================================= _k_factor = calculate_K_factor(input_file_name);
      
      // Final event weight
      _event_weight = (_lumi * 1000 * xsec *_k_factor * overallEventWeight) / gen_sum_weights; //removed xsec
      //cout << "weight=" << _event_weight << "   lumi="<< _lumi << "  xsec="<< xsec<< "   k_factor=" << _k_factor<< "   overalEveW=" << overallEventWeight << endl;
      
      
      // DISCRIMINANTS
      //=================================
      Float_t cConstant_VBF2j, cConstant_VBF1j, cConstant_WH, cConstant_ZH, ZH_mavjj, WH_mavjj;
      if(input_file_name.Contains("170623"))
      {
         cConstant_VBF2j = VBF1j_spline->Eval(ZZMass);
         cConstant_VBF1j = VBF2j_spline->Eval(ZZMass);
         cConstant_ZH    = ZH_spline->Eval(ZZMass);
         cConstant_WH    = WH_spline->Eval(ZZMass);
         WH_mavjj        = p_HadWH_mavjj_JECNominal;
         ZH_mavjj        = p_HadZH_mavjj_JECNominal;
      }
      
      else if(input_file_name.Contains("Moriond"))
      {
         cConstant_VBF2j = getDVBF2jetsConstant_shiftWP(ZZMass,false,0.5);
         cConstant_VBF1j = getDVBF1jetConstant_shiftWP(ZZMass,false,0.5);
         cConstant_ZH    = getDZHhConstant_shiftWP(ZZMass,false,0.5);
         cConstant_WH    = getDWHhConstant_shiftWP(ZZMass,false,0.5);
         ZH_mavjj = 1.;
         ZH_mavjj = 1.;
      }
         
         if (p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal != 0) DVBF2j_ME = 1./(1.+ cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal/p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal);
         else DVBF2j_ME = -1;
         
         if (p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal != 0) DVBF1j_ME = 1./(1.+ cConstant_VBF1j*p_JQCD_SIG_ghg2_1_JHUGen_JECNominal/(p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal));
         else DVBF1j_ME = -1;
         
         if (p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*ZH_mavjj != 0) DZH_ME = 1./(1.+ cConstant_ZH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal)/(p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*ZH_mavjj));
         else DZH_ME = -1;
         
         if (p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*WH_mavjj != 0) DWH_ME = 1./(1.+ cConstant_WH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal)/(p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*WH_mavjj));
         else DWH_ME = -1;
         
         DVH_ME = TMath::Max( DZH_ME, DWH_ME );
      
      //=================================
      
      
      h_VBF2j->Fill(DVBF2j_ME, _event_weight);
      h_VH->Fill(DVH_ME, _event_weight);
      
      
   }//Kraj loop-a po eventovima
   
   VBF1j_file->Close();
   VBF2j_file->Close();
   WH_file->Close();
   ZH_file->Close();
   
   cout << "[INFO] File " << input_file_name << " is processed." << endl;
}

float Analyzer::getDVBF2jetsConstant_old(float ZZMass){
   float par[9]={
      1.876,
      -55.488,
      403.32,
      0.3906,
      80.8,
      27.7,
      -0.06,
      54.97,
      309.96
   };
   float kappa =
   pow(1.-atan((ZZMass-par[1])/par[2])*2./TMath::Pi(), par[0])
   + par[3]*exp(-pow((ZZMass-par[4])/par[5], 2))
   + par[6]*exp(-pow((ZZMass-par[7])/par[8], 2));
   float constant = kappa/(1.-kappa);
   return constant;
}
float Analyzer::getDVBF1jetConstant_old(float ZZMass){
   float par[8]={
      0.395,
      -0.07,
      85.,
      30.,
      -0.691,
      -5659.47,
      5734.37,
      0.75
   };
   float kappa =
   par[0]
   + par[1]*exp(-pow((ZZMass-par[2])/par[3], 2))
   + par[4]*pow(log((ZZMass-par[5])/par[6]), par[7])*(ZZMass>=(par[5]+par[6]));
   float constant = kappa/(1.-kappa);
   return constant;
}
float Analyzer::getDWHhConstant_old(float ZZMass){
   return 1e-3;
}
float Analyzer::getDZHhConstant_old(float ZZMass){
   return 1e-4;
}

float Analyzer::getDVBF2jetsWP(float ZZMass, bool useQGTagging){
   if (useQGTagging)
      return 0.363;
   else
      return 1.043-460./(ZZMass+634.);
}
float Analyzer::getDVBF1jetWP(float ZZMass, bool useQGTagging){
   if (useQGTagging)
      return 0.716;
   else
      return 0.697;
}
float Analyzer::getDWHhWP(float ZZMass, bool useQGTagging){
   if (useQGTagging)
      return 0.965;
   else
      return 0.951;
}
float Analyzer::getDZHhWP(float ZZMass, bool useQGTagging){
   if (useQGTagging)
      return 0.9952;
   else
      return 0.9937;
}

float Analyzer::getDVBF2jetsConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP) {
   float oldc = getDVBF2jetsConstant_old(ZZMass);
   float oldWP = getDVBF2jetsWP(ZZMass, useQGTagging);
   return oldc * (oldWP/newWP) * ((1-newWP)/(1-oldWP));
}
float Analyzer::getDVBF1jetConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP) {
   float oldc = getDVBF1jetConstant_old(ZZMass);
   float oldWP = getDVBF1jetWP(ZZMass, useQGTagging);
   return oldc * (oldWP/newWP) * ((1-newWP)/(1-oldWP));
}

float Analyzer::getDWHhConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP) {
   float oldc = getDWHhConstant_old(ZZMass);
   float oldWP = getDWHhWP(ZZMass, useQGTagging);
   return oldc * (oldWP/newWP) * ((1-newWP)/(1-oldWP));
}

float Analyzer::getDZHhConstant_shiftWP(float ZZMass, bool useQGTagging, float newWP) {
   float oldc = getDZHhConstant_old(ZZMass);
   float oldWP = getDZHhWP(ZZMass, useQGTagging);
   return oldc * (oldWP/newWP) * ((1-newWP)/(1-oldWP));
}

