#define Analyzer_cxx
#include "../include/Analyzer.h"
#include "../include/Functions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyzer::Loop(bool only2jEvents, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
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
   DBKG_file_4e = new TFile("cConstants/SmoothKDConstant_m4l_Dbkgkin_4e13TeV.root");
   DBKG_spline_4e = (TSpline3*)DBKG_file_4e->Get("sp_gr_varTrue_Constant_Smooth");
   DBKG_file_4mu = new TFile("cConstants/SmoothKDConstant_m4l_Dbkgkin_4mu13TeV.root");
   DBKG_spline_4mu = (TSpline3*)DBKG_file_4mu->Get("sp_gr_varTrue_Constant_Smooth");
   DBKG_file_2e2mu = new TFile("cConstants/SmoothKDConstant_m4l_Dbkgkin_2e2mu13TeV.root");
   DBKG_spline_2e2mu = (TSpline3*)DBKG_file_2e2mu->Get("sp_gr_varTrue_Constant_Smooth");
   
   g_Decay_g2_file   = new TFile("cConstants/gConstant_HZZ2e2mu_g2.root");
   g_Decay_g2_spline = (TSpline3*) g_Decay_g2_file->Get("sp_tgfinal_HZZ2e2mu_SM_over_tgfinal_HZZ2e2mu_g2");
   g_Decay_g4_file   = new TFile("cConstants/gConstant_HZZ2e2mu_g4.root");
   g_Decay_g4_spline = (TSpline3*) g_Decay_g4_file->Get("sp_tgfinal_HZZ2e2mu_SM_over_tgfinal_HZZ2e2mu_g4");
   g_Decay_L1_file   = new TFile("cConstants/gConstant_HZZ2e2mu_L1.root");
   g_Decay_L1_spline = (TSpline3*) g_Decay_L1_file->Get("sp_tgfinal_HZZ2e2mu_SM_over_tgfinal_HZZ2e2mu_L1");
   g_Decay_L1Zgs_file   = new TFile("cConstants/gConstant_HZZ2e2mu_L1Zgs.root");
   g_Decay_L1Zgs_spline = (TSpline3*) g_Decay_L1Zgs_file->Get("sp_tgfinal_HZZ2e2mu_SM_photoncut_over_tgfinal_HZZ2e2mu_L1Zgs");


   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {//Loop over events
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      if ( input_file_name.Contains("VBFH1500")) _xsec = 0.02288;
      if ( input_file_name.Contains("VBFH2000")) _xsec = 0.007052;
      if ( input_file_name.Contains("VBFH2500")) _xsec = 0.00236;
      if ( input_file_name.Contains("VBFH3000")) _xsec = 0.0008253;
      else _xsec = xsec;
      
      // K factors
      //=================================
      _k_factor = 1;
      if ( input_file_name.Contains("ZZTo4l"))
      {
         _k_factor = KFactor_EW_qqZZ * KFactor_QCD_qqZZ_M; // As of Moriond2016
      }
//      else if ( input_file_name.Contains("ggTo"))
//      {
//         _k_factor = KFactor_QCD_ggZZ_Nominal; // as of Moriond2016
//      }
      //================================= _k_factor = calculate_K_factor(input_file_name);
      
      // Final event weight
      _event_weight = (_k_factor * overallEventWeight) / gen_sum_weights; //removed xsec
      //_event_weight = (_lumi * 1000 *_k_factor * _xsec * overallEventWeight) / gen_sum_weights;
      //cout << "weight=" << _event_weight << "   lumi="<< _lumi << "  xsec="<< xsec<< "   k_factor=" << _k_factor<< "   overalEveW=" << overallEventWeight << endl;

      
      // DISCRIMINANTS
      //=================================
      Float_t cConstant_VBF2j = VBF2j_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VBF2j, 0.5);
//      Float_t cConstant_VBF1j = VBF1j_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VBF1j, 0.5);
      Float_t cConstant_ZH    = ZH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
      Float_t cConstant_WH    = WH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
      
   
      if (p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal != 0) DVBF2j_ME = 1./(1.+ cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal/p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal);
      else DVBF2j_ME = -1;
      
      if (p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal != 0) DVBF2j_ME_BSM = 1./(1.+ cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal/p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal);
      else DVBF2j_ME_BSM = -1;

//      if (p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal != 0) DVBF1j_ME = 1./(1.+ cConstant_VBF1j*p_JQCD_SIG_ghg2_1_JHUGen_JECNominal/(p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal));
//      else DVBF1j_ME = -1;
		
//		if (p_JVBF_SIG_ghv4_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv4_1_JHUGen_JECNominal != 0) DVBF1j_ME_BSM = 1./(1.+ cConstant_VBF1j*p_JQCD_SIG_ghg2_1_JHUGen_JECNominal/(p_JVBF_SIG_ghv4_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv4_1_JHUGen_JECNominal));
//		else DVBF1j_ME_BSM = -1;

      if (p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*p_HadZH_mavjj_JECNominal != 0) DZH_ME = 1./(1.+ cConstant_ZH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal)/(p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*p_HadZH_mavjj_JECNominal));
      else DZH_ME = -1;
      
      if (p_HadZH_SIG_ghz4_1_JHUGen_JECNominal*p_HadZH_mavjj_JECNominal != 0) DZH_ME_BSM = 1./(1.+ cConstant_ZH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal)/(p_HadZH_SIG_ghz4_1_JHUGen_JECNominal*p_HadZH_mavjj_JECNominal));
      else DZH_ME_BSM = -1;

      if (p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*p_HadWH_mavjj_JECNominal != 0) DWH_ME = 1./(1.+ cConstant_WH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal)/(p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*p_HadWH_mavjj_JECNominal));
      else DWH_ME = -1;
      
      if (p_HadWH_SIG_ghw4_1_JHUGen_JECNominal*p_HadWH_mavjj_JECNominal != 0) DWH_ME_BSM = 1./(1.+ cConstant_WH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal)/(p_HadWH_SIG_ghw4_1_JHUGen_JECNominal*p_HadWH_mavjj_JECNominal));
      else DWH_ME_BSM = -1;
      
      DVH_ME     = TMath::Max( DZH_ME, DWH_ME );
      DVH_ME_BSM = TMath::Max( DZH_ME_BSM, DWH_ME_BSM );

      //=================================
      
      //=================================
      // PRODUCTION DISCRIMINANTS
      //=================================
      if ( 1 > 0) //if( !((nCleanedJetsPt30 >= 2) && ((DVBF2j_ME > 0.5) || (DVBF2j_ME_BSM > 0.5) || (DVH_ME > 0.5)) || (DVH_ME_BSM > 0.5) ))//untagged category
      {
         Float_t cConstant_DBKG = GetDBKGcConstant(Z1Flav, Z2Flav, ZZMass);
         Float_t g_Decay_g2    = g_Decay_g2_spline->Eval(ZZMass);
         Float_t g_Decay_g4    = g_Decay_g4_spline->Eval(ZZMass);
         Float_t g_Decay_gL1   = g_Decay_L1_spline->Eval(ZZMass)*pow(10,-4);
         Float_t g_Decay_gL1Zs = g_Decay_L1Zgs_spline->Eval(ZZMass)*pow(10,-4);
   
         
         D_BKG_DEC = 1. / ( 1. + cConstant_DBKG*p_QQB_BKG_MCFM/p_GG_SIG_ghg2_1_ghz1_1_JHUGen);
         D_0MH_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / (p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_Decay_g4 * g_Decay_g4 * p_GG_SIG_ghg2_1_ghz4_1_JHUGen );
         D_0PH_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / (p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_Decay_g2 * g_Decay_g2 * p_GG_SIG_ghg2_1_ghz2_1_JHUGen );
         D_0L1_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / (p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_Decay_gL1 * g_Decay_gL1 * p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen);
         D_0L1Zgs_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / (p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_Decay_gL1Zs * g_Decay_gL1Zs * p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen);
//         cout << "DL1= " << D_0L1_DEC << endl;
//         cout << "g= " << g_Decay_gL1 << endl;
//         cout << "PA= " << p_GG_SIG_ghg2_1_ghz1_1_JHUGen << endl;
//         cout << "PB= " << p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen << endl;
      }
      
      //=================================
		
		if ( only2jEvents && nCleanedJetsPt30 >= 2)
		{
			histos_1D[Settings::M4l_allevents]->Fill(ZZMass, _event_weight);
			histos_1D[Settings::M4l_counter]->Fill(ZZMass);
			p->Fill(ZZMass,ZZMass,_event_weight);
		}
		
		else if (  !only2jEvents )
		{
			histos_1D[Settings::M4l_allevents]->Fill(ZZMass, _event_weight);
			histos_1D[Settings::M4l_counter]->Fill(ZZMass);
			p->Fill(ZZMass,ZZMass,_event_weight);
		}

      if (nCleanedJetsPt30 >= 2)
      {
         histos_2D[Settings::D_VBF2j]->Fill(ZZMass, DVBF2j_ME, _event_weight);
         histos_2D[Settings::D_VH]->Fill(ZZMass,DVH_ME, _event_weight);

      }
      histos_2D[Settings::D_BKG_DEC]->Fill(ZZMass,D_BKG_DEC,_event_weight);
      histos_2D[Settings::D_0M_DEC]->Fill(ZZMass,D_0MH_DEC,_event_weight);
      histos_2D[Settings::D_0hP_DEC]->Fill(ZZMass,D_0PH_DEC,_event_weight);
      histos_2D[Settings::D_L1_DEC]->Fill(ZZMass,D_0L1_DEC,_event_weight);
      histos_2D[Settings::D_L1Zgs_DEC]->Fill(ZZMass,D_0L1Zgs_DEC,_event_weight);
      if( DVBF2j_ME > 0.5 && nCleanedJetsPt30 >= 2) histos_1D[Settings::M4l_DVBF2j]->Fill(ZZMass, _event_weight);
      if( DVH_ME > 0.5 && nCleanedJetsPt30 >= 2) histos_1D[Settings::M4l_DVH]->Fill(ZZMass, _event_weight);
      
   }//Kraj loop-a po eventovima
   
   VBF1j_file->Close();
   VBF2j_file->Close();
   WH_file->Close();
   ZH_file->Close();
   
   g_Decay_g2_file->Close();
   g_Decay_g4_file->Close();
   g_Decay_L1_file->Close();
   g_Decay_L1Zgs_file->Close();
   
   cout << "[INFO] File " << input_file_name << " is processed." << endl;
}


void Analyzer::LoopForEff(bool shiftWP, bool only2jEvents , TH1F *histos_1D[])
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
      
      if (ZZMass < 110 || ZZMass > 140) continue;
      
      if ( input_file_name.Contains("VBFH1500")) _xsec = 0.02288;
      if ( input_file_name.Contains("VBFH2000")) _xsec = 0.007052;
      if ( input_file_name.Contains("VBFH2500")) _xsec = 0.00236;
      if ( input_file_name.Contains("VBFH3000")) _xsec = 0.0008253;
      else _xsec = xsec;
      
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
      _event_weight = (_lumi * 1000 * _xsec *_k_factor * overallEventWeight) / gen_sum_weights; //removed xsec
      //cout << "weight=" << _event_weight << "   lumi="<< _lumi << "  xsec="<< xsec<< "   k_factor=" << _k_factor<< "   overalEveW=" << overallEventWeight << endl;
      
      
      //=================================
      // CATEGORISATION DISCRIMINANTS
      //=================================
      Float_t cConstant_VBF2j, cConstant_VBF1j, cConstant_WH, cConstant_ZH, ZH_mavjj, WH_mavjj;
      if(input_file_name.Contains("170623"))
      {
         if (shiftWP) cConstant_VBF2j = VBF2j_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VBF2j, 0.5);
         else cConstant_VBF2j = VBF2j_spline->Eval(ZZMass);
			
			if (shiftWP) cConstant_VBF1j = VBF1j_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VBF1j, 0.5);
			else cConstant_VBF1j = VBF1j_spline->Eval(ZZMass);
			
         if (shiftWP) cConstant_ZH    = ZH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
         else cConstant_ZH    = ZH_spline->Eval(ZZMass);
         if (shiftWP) cConstant_WH    = WH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
         else cConstant_WH    = WH_spline->Eval(ZZMass);
         
         WH_mavjj        = p_HadWH_mavjj_JECNominal;
         ZH_mavjj        = p_HadZH_mavjj_JECNominal;
      }
      
      else if(input_file_name.Contains("Moriond"))
      {
         cConstant_VBF2j = getDVBF2jetsConstant_shiftWP(ZZMass,false,0.5);
         cConstant_VBF1j = getDVBF1jetConstant_shiftWP(ZZMass,false,0.5);
         cConstant_ZH    = getDZHhConstant_shiftWP(ZZMass,false,0.5);
         cConstant_WH    = getDWHhConstant_shiftWP(ZZMass,false,0.5);
         WH_mavjj = 1.;
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
		
      
      if (nCleanedJetsPt30 >= 2) histos_1D[Settings::M4l_DVBF2j]->Fill(DVBF2j_ME, _event_weight);
      else if (!only2jEvents) histos_1D[Settings::M4l_DVBF2j]->Fill(0., _event_weight);
      if (nCleanedJetsPt30 >= 2) histos_1D[Settings::M4l_DVH]->Fill(DVH_ME, _event_weight);
      else if (!only2jEvents) histos_1D[Settings::M4l_DVH]->Fill(0., _event_weight);
		if (nCleanedJetsPt30 == 1) histos_1D[Settings::M4l_DVBF1j]->Fill(DVBF1j_ME, _event_weight);
		else if (!only2jEvents) histos_1D[Settings::M4l_DVBF1j]->Fill(0., _event_weight);
      
      
   }//Kraj loop-a po eventovima
   
   VBF1j_file->Close();
   VBF2j_file->Close();
   WH_file->Close();
   ZH_file->Close();
   
   cout << "[INFO] File " << input_file_name << " is processed." << endl;
}


void Analyzer::LoopForCat(bool newArbitration, TH1F *histo)
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
      
      if ( input_file_name.Contains("VBFH1500")) _xsec = 0.02288;
      if ( input_file_name.Contains("VBFH2000")) _xsec = 0.007052;
      if ( input_file_name.Contains("VBFH2500")) _xsec = 0.00236;
      if ( input_file_name.Contains("VBFH3000")) _xsec = 0.0008253;
      else _xsec = xsec;
      
      // K factors
      //=================================
      _k_factor = 1;
      if ( input_file_name.Contains("ZZTo4l"))
      {
         _k_factor = KFactor_EW_qqZZ * KFactor_QCD_qqZZ_M; // As of Moriond2016
      }
//      else if ( input_file_name.Contains("ggTo"))
//      {
//         _k_factor = KFactor_QCD_ggZZ_Nominal; // as of Moriond2016
//      }
      //================================= _k_factor = calculate_K_factor(input_file_name);
      
      // Final event weight
      _event_weight = (1000 * _lumi * _xsec *_k_factor * overallEventWeight) / gen_sum_weights;
      
      
      //=================================
      // CATEGORISATION DISCRIMINANTS
      //=================================
      Float_t cConstant_VBF2j, cConstant_VBF1j, cConstant_WH, cConstant_ZH, ZH_mavjj, WH_mavjj;

      cConstant_VBF2j = VBF2j_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VBF2j, 0.5);
      cConstant_VBF1j = VBF1j_spline->Eval(ZZMass);
      cConstant_ZH    = ZH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
      cConstant_WH    = WH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
      
      WH_mavjj        = p_HadWH_mavjj_JECNominal;
      ZH_mavjj        = p_HadZH_mavjj_JECNominal;
      
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
      
      if( newArbitration)
      {
         if ( nCleanedJetsPt30 >= 2 && (DVBF2j_ME > 0.5) && (DVH_ME > 0.5) ) cout << "DVBF2j = " << DVBF2j_ME <<"  DVH= "<< DVH_ME << endl;
         if(nCleanedJetsPt30 >= 2 && (DVBF2j_ME > 0.5 || DVH_ME > 0.5))
         {
            if ( DVBF2j_ME >= DVH_ME ) histo->Fill("VBF2j-tagged",_event_weight);
            else histo->Fill("VH-hadr.tagged",_event_weight);
         }
         else histo->Fill("Untagged",_event_weight);
      }

      if( !newArbitration)
      {
         if( nCleanedJetsPt30 >= 2 && DVBF2j_ME > 0.5) histo->Fill("VBF2j-tagged",_event_weight);
         else if(nCleanedJetsPt30 >=2 && DVH_ME > 0.5) histo->Fill("VH-hadr.tagged", _event_weight);
         else histo->Fill("Untagged",_event_weight);
      }

      
      
   }//Kraj loop-a po eventovima
   
   VBF1j_file->Close();
   VBF2j_file->Close();
   WH_file->Close();
   ZH_file->Close();
   
   cout << "[INFO] File " << input_file_name << " is processed." << endl;
}


void Analyzer::LoopForNJets(TH1F *histo)
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
		
		if ( input_file_name.Contains("VBFH1500")) _xsec = 0.02288;
		if ( input_file_name.Contains("VBFH2000")) _xsec = 0.007052;
		if ( input_file_name.Contains("VBFH2500")) _xsec = 0.00236;
		if ( input_file_name.Contains("VBFH3000")) _xsec = 0.0008253;
		else _xsec = xsec;
		
		// K factors
		//=================================
		_k_factor = 1;
		
		// Final event weight
		_event_weight = (1000 * _lumi * _xsec *_k_factor * overallEventWeight) / gen_sum_weights;
		
		
		//=================================
		// CATEGORISATION DISCRIMINANTS
		//=================================
		Float_t cConstant_VBF2j, cConstant_VBF1j, cConstant_WH, cConstant_ZH, ZH_mavjj, WH_mavjj;
		
		cConstant_VBF2j = VBF2j_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VBF2j, 0.5);
		cConstant_VBF1j = VBF1j_spline->Eval(ZZMass);
		cConstant_ZH    = ZH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
		cConstant_WH    = WH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
		
		WH_mavjj        = p_HadWH_mavjj_JECNominal;
		ZH_mavjj        = p_HadZH_mavjj_JECNominal;
		
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
		Int_t NVBFJets = 0;
		if( nCleanedJetsPt30 > 2 && DVBF2j_ME > 0.5)
		{
			for(int i = 0; i < JetEta->size() - 2; i++)
			{
				if(JetEta->at(0) < 0 && JetEta->at(1) > 0 && (JetEta->at(2+i) > JetEta->at(0) && JetEta->at(2+i) < JetEta->at(1))) NVBFJets++;
				if(JetEta->at(0) > 0 && JetEta->at(1) < 0 && (JetEta->at(2+i) > JetEta->at(1) && JetEta->at(2+i) < JetEta->at(0))) NVBFJets++;
			}
			
			histo->Fill(NVBFJets,_event_weight);
		}

		
		
		
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

float Analyzer::ShiftWPfactor(float oldWP, float newWP) {
   return (oldWP/newWP) * ((1-newWP)/(1-oldWP));
}

float Analyzer::getDbkgkinConstant_old(int ZZflav, float ZZMass){ // ZZflav==id1*id2*id3*id4
   float par[14]={
      0.775,
      -0.565,
      70.,
      5.90,
      -0.235,
      130.1,
      13.25,
      -0.33,
      191.04,
      16.05,
      187.47,
      -0.21,
      1700.,
      400.
   };
   if (abs(ZZflav)==121*121 || abs(ZZflav)==121*242 || abs(ZZflav)==242*242) par[11]=-0.42; // 4e
   float kappa =
   par[0]
   +par[1]*exp(-pow(((ZZMass-par[2])/par[3]), 2))
   +par[4]*exp(-pow(((ZZMass-par[5])/par[6]), 2))
   +par[7]*(
            exp(-pow(((ZZMass-par[8])/par[9]), 2))*(ZZMass<par[8])
            + exp(-pow(((ZZMass-par[8])/par[10]), 2))*(ZZMass>=par[8])
            )
   + par[11]*exp(-pow(((ZZMass-par[12])/par[13]), 2));
   
   float constant = kappa/(1.-kappa);
   return constant;
}

float Analyzer::GetDBKGcConstant(Short_t Z1Flav, Short_t Z2Flav, float ZZMass )
{
   double cConstant = 1.;
   
   if ( Z1Flav == -121 )
   {
      if ( Z2Flav == -121 )
         cConstant = DBKG_spline_4e->Eval(ZZMass); //4e final state
      else if ( Z2Flav == -169 )
         cConstant = DBKG_spline_2e2mu->Eval(ZZMass); // 2e2mu
      else
         cerr << "[ERROR] " << endl;
   }
   else if ( Z1Flav == -169 )
   {
      if ( Z2Flav == -121 )
         cConstant = DBKG_spline_2e2mu->Eval(ZZMass); //2mu2e
      else if ( Z2Flav == -169 )
         cConstant = DBKG_spline_4mu->Eval(ZZMass); //4mu
      else
         cerr << "[ERROR] " << endl;
   }
   else
   {
      cerr << "[ERROR] " << endl;
   }
   
   return cConstant;
}
