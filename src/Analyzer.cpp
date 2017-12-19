#define Analyzer_cxx
#include "../include/Analyzer.h"
#include "../include/Functions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


void Analyzer::DeclareHistos()
{
	p2j       = new TProfile("p2j","p",m4l_bins, m4l_slices);
	p1j       = new TProfile("p1j","p",m4l_bins, m4l_slices);

	histos_1D[Settings::M4l_allevents] = new TH1F("h", "h", m4l_bins, m4l_slices);
	histos_1D[Settings::M4l_2j_events] = new TH1F("h1", "h1", m4l_bins, m4l_slices);
	histos_1D[Settings::M4l_1j_events] = new TH1F("h2", "h2", m4l_bins, m4l_slices);
	histos_1D[Settings::M4l_counter]   = new TH1F("h_counter", "h_counter", 3000,70,3070);
	histos_1D[Settings::M4l_DVBF2j]    = new TH1F("h_VBF2j", "h_VBF2j", m4l_bins, m4l_slices);
	histos_1D[Settings::M4l_DVBF1j]    = new TH1F("h_VBF1j", "h_VBF1j", m4l_bins, m4l_slices);
	histos_1D[Settings::M4l_DVH]       = new TH1F("h_VH", "h_VH", m4l_bins, m4l_slices);
	
	_s_cat.push_back("untag");
	_s_cat.push_back("VBFtag");
	_s_cat.push_back("VHtag");
	_s_cat.push_back("incl");
	
	_s_ac.push_back("SM");
	_s_ac.push_back("fa3");
	_s_ac.push_back("fa2");
	_s_ac.push_back("fL1");
	_s_ac.push_back("fL1Zgs");
	
	
	for ( int i_cat = 0; i_cat < Settings::num_of_categories_OnShell ; i_cat ++)
	{
		for ( int i_ac = 0; i_ac < Settings::num_of_anomalous_couplings ; i_ac ++)
		{
			histos_2D[i_cat][Settings::D_VBF2j][i_ac]       = new TH2F("DVBF2jVsM4l_" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac),"", m4l_bins, m4l_slices, 100, 0., 1.);
			histos_2D[i_cat][Settings::D_VBF1j][i_ac]       = new TH2F("DVBF1jVsM4l_" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac),"", m4l_bins, m4l_slices, 100, 0., 1.);
			histos_2D[i_cat][Settings::D_VH][i_ac]          = new TH2F("DVHVsM4l_" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac),"", m4l_bins, m4l_slices, 100, 0., 1.);
			
			
			histos_2D[i_cat][Settings::D_BKG_DEC][i_ac]     = new TH2F("DBKGDECVsM4l" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac),"", m4l_bins3, m4l_slices3, 100, 0., 1.);
			histos_2D[i_cat][Settings::D_DEC][i_ac]         = new TH2F("DDECVsM4l" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac) ,"", m4l_bins3, m4l_slices3, 100, 0., 1.);
			histos_2D[i_cat][Settings::D_BKG_VBF_DEC][i_ac] = new TH2F("DBKGVBFDECVsM4l" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac),"", m4l_bins3, m4l_slices3, 100, 0., 1.);
			histos_2D[i_cat][Settings::D_VBF_DEC][i_ac]     = new TH2F("DVBFDECVsM4l" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac),"", m4l_bins3, m4l_slices3, 100, 0., 1.);
		}

	}

	
}

void Analyzer::ResetHistos()
{
	p2j->Reset();
	p1j->Reset();
	for (int i = 0; i < Settings::num_of_1D_hist_names ; i++) histos_1D[i]->Reset();
	for (int j = 0; j < Settings::num_of_2D_hist_names ; j++)
	{
		for (int i = 0; i < Settings::num_of_categories_OnShell ; i++)
		{
			for (int k = 0; k < Settings::num_of_anomalous_couplings; k ++ ) histos_2D[i][j][k]->Reset();
		}
		
	}
}

void Analyzer::WriteHistos(TString sample)
{
	p2j->SetName("M4l_TProfile_2jet_" + sample);
	p2j->Write();
	p1j->SetName("M4l_TProfile_1jet_" + sample);
	p1j->Write();
	histos_1D[Settings::M4l_allevents]->SetName("M4l_" + sample);
	histos_1D[Settings::M4l_allevents]->Write();
	histos_1D[Settings::M4l_2j_events]->SetName("M4_2j_" + sample);
	histos_1D[Settings::M4l_2j_events]->Write();
	histos_1D[Settings::M4l_1j_events]->SetName("M4l_1j_" + sample);
	histos_1D[Settings::M4l_1j_events]->Write();
	histos_1D[Settings::M4l_DVBF2j]->SetName("M4l_DVBF2j_" + sample);
	histos_1D[Settings::M4l_DVBF2j]->Write();
	histos_1D[Settings::M4l_DVBF1j]->SetName("M4l_DVBF1j_" + sample);
	histos_1D[Settings::M4l_DVBF1j]->Write();
	histos_1D[Settings::M4l_DVH]->SetName("M4l_DVH_" + sample);
	histos_1D[Settings::M4l_DVH]->Write();
	histos_1D[Settings::M4l_counter]->SetName("M4l_counter_" + sample);
	histos_1D[Settings::M4l_counter]->Write();
	for ( int i_cat = 0; i_cat < Settings::num_of_categories_OnShell ; i_cat ++)
	{
		for ( int i_ac = 0; i_ac < Settings::num_of_anomalous_couplings ; i_ac ++)
		{
			histos_2D[i_cat][Settings::D_VBF2j][i_ac]->SetName("DVBF2jVsM4l_" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac) + "_" + sample);
			histos_2D[i_cat][Settings::D_VBF1j][i_ac]->SetName("DVBF1jVsM4l_" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac)+ "_" + sample);
			histos_2D[i_cat][Settings::D_VH][i_ac]->SetName("DVHVsM4l_" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac)+ "_" + sample);
			histos_2D[i_cat][Settings::D_BKG_DEC][i_ac]->SetName("DBKGDECVsM4l" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac)+ "_" + sample);
			histos_2D[i_cat][Settings::D_DEC][i_ac]->SetName("DDECVsM4l" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac)+ "_" + sample);
			histos_2D[i_cat][Settings::D_BKG_VBF_DEC][i_ac]->SetName("DBKGVBFDECVsM4l" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac)+ "_" + sample);
			histos_2D[i_cat][Settings::D_VBF_DEC][i_ac]->SetName("DVBFDECVsM4l" + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac)+ "_" + sample);
			
			histos_2D[i_cat][Settings::D_VBF2j][i_ac]->Write();
			histos_2D[i_cat][Settings::D_VBF1j][i_ac]->Write();
			histos_2D[i_cat][Settings::D_VH][i_ac]->Write();
			histos_2D[i_cat][Settings::D_BKG_DEC][i_ac]->Write();
			histos_2D[i_cat][Settings::D_DEC][i_ac]->Write();
			histos_2D[i_cat][Settings::D_BKG_VBF_DEC][i_ac]->Write();
			histos_2D[i_cat][Settings::D_VBF_DEC][i_ac]->Write();
		}
		
	}
}

void Analyzer::WriteGraphs(TString sample)
{
	Functions *functions = new Functions();
	
	TGraphErrors *Djj_tgraph,*Dj_tgraph,*DVH_tgraph;
	
	histos_1D[Settings::M4l_DVBF2j]->Divide(histos_1D[Settings::M4l_2j_events]);
	histos_1D[Settings::M4l_DVBF1j]->Divide(histos_1D[Settings::M4l_1j_events]);
	histos_1D[Settings::M4l_DVH]->Divide(histos_1D[Settings::M4l_2j_events]);
	
	Djj_tgraph = functions->makeGraphFromTH1(p2j, histos_1D[Settings::M4l_DVBF2j] , sample + "_Djj_tgraph");
	Dj_tgraph  = functions->makeGraphFromTH1(p1j, histos_1D[Settings::M4l_DVBF1j] , sample + "_Dj_tgraph");
	DVH_tgraph = functions->makeGraphFromTH1(p2j, histos_1D[Settings::M4l_DVH]    , sample + "_DVH_tgraph");
	
	Djj_tgraph->Write();
	Dj_tgraph->Write();
	DVH_tgraph->Write();
	
	
}

void Analyzer::WriteSplines(TString sample)
{
	Functions *functions = new Functions();
	
	TGraphErrors *Djj_tgraph,*Dj_tgraph,*DVH_tgraph;
	
	histos_1D[Settings::M4l_DVBF2j]->Divide(histos_1D[Settings::M4l_2j_events]);
	histos_1D[Settings::M4l_DVBF1j]->Divide(histos_1D[Settings::M4l_1j_events]);
	histos_1D[Settings::M4l_DVH]->Divide(histos_1D[Settings::M4l_2j_events]);
	
	Djj_tgraph = functions->makeGraphFromTH1(p2j, histos_1D[Settings::M4l_DVBF2j] , sample + "_Djj_tgraph");
	Dj_tgraph  = functions->makeGraphFromTH1(p1j, histos_1D[Settings::M4l_DVBF1j] , sample + "_Dj_tgraph");
	DVH_tgraph = functions->makeGraphFromTH1(p2j, histos_1D[Settings::M4l_DVH]    , sample + "_DVH_tgraph");
	
	Djj_tgraph->Write();
	Dj_tgraph ->Write();
	DVH_tgraph->Write();
	
	TSpline3 *Djj_spline, *Dj_spline, *DVH_spline;
	
	Djj_spline = functions->convertGraphToSpline3(Djj_tgraph, 0, 0);
	Dj_spline  = functions->convertGraphToSpline3(Dj_tgraph, 0, 0);
	DVH_spline = functions->convertGraphToSpline3(DVH_tgraph, 0, 0);
	
	Djj_spline->Write();
	Dj_spline ->Write();
	DVH_spline->Write();
}

void Analyzer::RebinHistos()
{
	// Redefine M4l binning for WH and ZH
	Int_t   m4l_bins     = 18;
	Double_t m4l_slices[] = {105,140,150,160,170,180,190,220,250,300,400,500,600,700,800,900,1500,2500,3500};
	
	Int_t   m4l_bins2     = 10;
	Double_t m4l_slices2[] = {105,125,130,140,150,160,170,180,190,220,250};
	
	Int_t   m4l_bins3     = 13;
	Double_t m4l_slices3[] = {105,140,180,220,300,400,500,600,700,800,1500,2000,3000,4000};
	
	delete p2j, p1j, histos_1D[Settings::M4l_allevents],histos_1D[Settings::M4l_2j_events],histos_1D[Settings::M4l_1j_events], histos_1D[Settings::M4l_DVH], histos_1D[Settings::M4l_DVBF2j];
	
	p2j       = new TProfile("p2jet2","p2",m4l_bins2, m4l_slices2);
	p1j       = new TProfile("p1jet2","p2",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_allevents] = new TH1F("h2_v2", "h2",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_2j_events] = new TH1F("h23_v24", "h2",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_1j_events] = new TH1F("h23_v25", "h2",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_DVBF2j]    = new TH1F("DVBF2jVsM4l_v2", "DVBF2jVsM4l",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_DVBF1j]    = new TH1F("DVBF1jVsM4l_v2", "DVBF1jVsM4l",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_DVH]       = new TH1F("DVHVsM4l_v2", "DVHVsM4l",m4l_bins2, m4l_slices2);
}

void Analyzer::RebinHistosSplines()
{
	// Redefine M4l binning for WH and ZH
	//=======================================================
	// BINNING FOR SPLINES
	//=======================================================
	Int_t   m4l_bins     = 10;
	Double_t m4l_slices[] = {70,125,140,160,250,470,780,1200,1700,2160,3500};
	
	Int_t   m4l_binsqq     = 14;
	Double_t m4l_slicesqq[] = {70,90,96,140,175,190,200,210,220,235,250,270,300,340,3500};
	
	Int_t   m4l_bins2     = 6;
	Double_t m4l_slices2[] = {70,125,140,160,180,250,450};
	//=======================================================
	
	delete p2j,p1j, histos_1D[Settings::M4l_allevents],histos_1D[Settings::M4l_2j_events],histos_1D[Settings::M4l_1j_events],histos_1D[Settings::M4l_DVH], histos_1D[Settings::M4l_DVBF2j];
	
	p2j       = new TProfile("p2jet22","p2",m4l_bins2, m4l_slices2);
	p1j       = new TProfile("p1jet21","p2",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_allevents] = new TH1F("h2_v2", "h2",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_2j_events] = new TH1F("h23_v24", "h2",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_1j_events] = new TH1F("h23_v25", "h2",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_DVBF2j]    = new TH1F("DVBF2jVsM4l_v2", "DVBF2jVsM4l",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_DVBF1j]    = new TH1F("DVBF1jVsM4l_v2_v2", "DVBF1jVsM4l",m4l_bins2, m4l_slices2);
	histos_1D[Settings::M4l_DVH]       = new TH1F("DVHVsM4l", "DVHVsM4l",m4l_bins2, m4l_slices2);
}

void Analyzer::RebinHistosSplinesqq()
{
	// Redefine M4l binning for WH and ZH
	//=======================================================
	// BINNING FOR SPLINES
	//=======================================================
	Int_t   m4l_bins     = 10;
	Double_t m4l_slices[] = {70,125,140,160,250,470,780,1200,1700,2160,3500};
	
	Int_t   m4l_binsqq     = 14;
	Double_t m4l_slicesqq[] = {70,90,96,140,175,190,200,210,220,235,250,270,300,340,3500};
	
	Int_t   m4l_bins2     = 6;
	Double_t m4l_slices2[] = {70,125,140,160,180,250,450};
	//=======================================================
	
	delete p2j,p1j, histos_1D[Settings::M4l_allevents], histos_1D[Settings::M4l_2j_events],histos_1D[Settings::M4l_1j_events],histos_1D[Settings::M4l_DVH], histos_1D[Settings::M4l_DVBF2j];
	
	p2j       = new TProfile("p2jet2v2","p2",m4l_binsqq, m4l_slicesqq);
	p1j       = new TProfile("p1jet2v2","p2",m4l_binsqq, m4l_slicesqq);
	histos_1D[Settings::M4l_allevents] = new TH1F("h2_v3", "h2",m4l_binsqq, m4l_slicesqq);
	histos_1D[Settings::M4l_2j_events] = new TH1F("h23_ve24", "h2",m4l_binsqq, m4l_slicesqq);
	histos_1D[Settings::M4l_1j_events] = new TH1F("h23_ve25", "h2",m4l_binsqq, m4l_slicesqq);
	histos_1D[Settings::M4l_DVBF2j]    = new TH1F("DVBF2jVsM4l_v3", "DVBF2jVsM4l",m4l_binsqq, m4l_slicesqq);
	histos_1D[Settings::M4l_DVBF1j]    = new TH1F("DVBF1jVsM4l_v3", "DVBF1jVsM4l",m4l_binsqq, m4l_slicesqq);
	histos_1D[Settings::M4l_DVH]       = new TH1F("DVHVsM4l_v3", "DVHVsM4l",m4l_binsqq, m4l_slicesqq);
}

void Analyzer::LoadFakeRates()
{
	// Z+X SS factors
	// FIXME: recompute this for Run II, OS/SS ratio taken when computing fake rates in SS method
	_fs_ROS_SS.push_back(1.22);//4mu
	_fs_ROS_SS.push_back(0.97);//4e
	_fs_ROS_SS.push_back(1.30);//2e2mu
	_fs_ROS_SS.push_back(0.98);//2mu2e
	
	TString FR_file_name = "./FakeRate/FakeRate_SS_Moriond368.root";
	FR = new FakeRates(FR_file_name);
}

void Analyzer::LoadConstants()
{
	TString folder_name = "cConstants";
	TString folder2_name = "cConstants";
	
	
	VBF1j_file   = new TFile(folder_name + "/SmoothKDConstant_m4l_DjVBF_13TeV.root");
	VBF1j_spline = (TSpline3*)VBF1j_file->Get("sp_gr_varReco_Constant_Smooth");
	VBF2j_file = new TFile(folder_name + "/SmoothKDConstant_m4l_DjjVBF_13TeV.root");
	VBF2j_spline = (TSpline3*)VBF2j_file->Get("sp_gr_varReco_Constant_Smooth");
	WH_file = new TFile(folder_name + "/SmoothKDConstant_m4l_DjjWH_13TeV.root");
	WH_spline = (TSpline3*)WH_file->Get("sp_gr_varReco_Constant_Smooth");
	ZH_file = new TFile(folder_name + "/SmoothKDConstant_m4l_DjjZH_13TeV.root");
	ZH_spline = (TSpline3*)ZH_file->Get("sp_gr_varReco_Constant_Smooth");
	DBKG_file_4e = new TFile(folder_name + "/SmoothKDConstant_m4l_Dbkgkin_4e13TeV.root");
	DBKG_spline_4e = (TSpline3*)DBKG_file_4e->Get("sp_gr_varTrue_Constant_Smooth");
	DBKG_file_4mu = new TFile(folder_name + "/SmoothKDConstant_m4l_Dbkgkin_4mu13TeV.root");
	DBKG_spline_4mu = (TSpline3*)DBKG_file_4mu->Get("sp_gr_varTrue_Constant_Smooth");
	DBKG_file_2e2mu = new TFile(folder_name + "/SmoothKDConstant_m4l_Dbkgkin_2e2mu13TeV.root");
	DBKG_spline_2e2mu = (TSpline3*)DBKG_file_2e2mu->Get("sp_gr_varTrue_Constant_Smooth");
	
	g_Decay_g2_file   = new TFile(folder_name + "/gConstant_HZZ2e2mu_g2.root");
	g_Decay_g2_spline = (TSpline3*) g_Decay_g2_file->Get("sp_tgfinal_HZZ2e2mu_SM_over_tgfinal_HZZ2e2mu_g2");
	g_Decay_g4_file   = new TFile(folder_name + "/gConstant_HZZ2e2mu_g4.root");
	g_Decay_g4_spline = (TSpline3*) g_Decay_g4_file->Get("sp_tgfinal_HZZ2e2mu_SM_over_tgfinal_HZZ2e2mu_g4");
	g_Decay_L1_file   = new TFile(folder_name + "/gConstant_HZZ2e2mu_L1.root");
	g_Decay_L1_spline = (TSpline3*) g_Decay_L1_file->Get("sp_tgfinal_HZZ2e2mu_SM_over_tgfinal_HZZ2e2mu_L1");
	g_Decay_L1Zgs_file   = new TFile(folder_name + "/gConstant_HZZ2e2mu_L1Zgs.root");
	g_Decay_L1Zgs_spline = (TSpline3*) g_Decay_L1Zgs_file->Get("sp_tgfinal_HZZ2e2mu_SM_photoncut_over_tgfinal_HZZ2e2mu_L1Zgs");
	
	g_VBF_g2_file   = new TFile(folder_name + "/gConstant_VBF_g2.root");
	g_VBF_g2_spline = (TSpline3*) g_VBF_g2_file->Get("sp_tgfinal_VBF_SM_over_tgfinal_VBF_g2");
	g_VBF_g4_file   = new TFile(folder_name + "/gConstant_VBF_g4.root");
	g_VBF_g4_spline = (TSpline3*) g_VBF_g4_file->Get("sp_tgfinal_VBF_SM_over_tgfinal_VBF_g4");
	g_VBF_L1_file   = new TFile(folder_name + "/gConstant_VBF_L1.root");
	g_VBF_L1_spline = (TSpline3*) g_VBF_L1_file->Get("sp_tgfinal_VBF_SM_over_tgfinal_VBF_L1");
	g_VBF_L1Zgs_file   = new TFile(folder_name + "/gConstant_VBF_L1Zgs.root");
	g_VBF_L1Zgs_spline = (TSpline3*) g_VBF_L1Zgs_file->Get("sp_tgfinal_VBF_SM_photoncut_over_tgfinal_VBF_L1Zgs");
	
	g_WH_g2_file   = new TFile(folder_name + "/gConstant_WH_g2.root");
	g_WH_g2_spline = (TSpline3*) g_WH_g2_file->Get("sp_tgfinal_WH_SM_over_tgfinal_WH_g2");
	g_WH_g4_file   = new TFile(folder_name + "/gConstant_WH_g4.root");
	g_WH_g4_spline = (TSpline3*) g_WH_g4_file->Get("sp_tgfinal_WH_SM_over_tgfinal_WH_g4");
	g_WH_L1_file   = new TFile(folder_name + "/gConstant_WH_L1.root");
	g_WH_L1_spline = (TSpline3*) g_WH_L1_file->Get("sp_tgfinal_WH_SM_over_tgfinal_WH_L1");
	//	g_WH_L1Zgs_file   = new TFile(folder_name + "/gConstant_WH_L1Zgs.root");
	//	g_WH_L1Zgs_spline = (TSpline3*) g_WH_L1Zgs_file->Get("sp_tgfinal_WH_SM_photoncut_over_tgfinal_WH_L1Zgs");
	
	g_ZH_g2_file   = new TFile(folder_name + "/gConstant_ZH_g2.root");
	g_ZH_g2_spline = (TSpline3*) g_ZH_g2_file->Get("sp_tgfinal_ZH_SM_over_tgfinal_ZH_g2");
	g_ZH_g4_file   = new TFile(folder_name + "/gConstant_ZH_g4.root");
	g_ZH_g4_spline = (TSpline3*) g_ZH_g4_file->Get("sp_tgfinal_ZH_SM_over_tgfinal_ZH_g4");
	g_ZH_L1_file   = new TFile(folder_name + "/gConstant_ZH_L1.root");
	g_ZH_L1_spline = (TSpline3*) g_ZH_L1_file->Get("sp_tgfinal_ZH_SM_over_tgfinal_ZH_L1");
	g_ZH_L1Zgs_file   = new TFile(folder_name + "/gConstant_ZH_L1Zgs.root");
	g_ZH_L1Zgs_spline = (TSpline3*) g_ZH_L1Zgs_file->Get("sp_tgfinal_ZH_SM_photoncut_over_tgfinal_ZH_L1Zgs");
	
}


void Analyzer::Loop(bool only2jEvents)
{
	if (fChain == 0) return;
	
	Long64_t nentries = fChain->GetEntriesFast();
	
	hCounters = (TH1F*)inputfile->Get("ZZTree/Counters");
	gen_sum_weights = (Long64_t)hCounters->GetBinContent(40);
	
	Int_t _current_final_state;
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
		
		//=================================
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
		//_event_weight = (_k_factor * overallEventWeight) / gen_sum_weights; //removed xsec
		_event_weight = (_lumi * 1000 *_k_factor * _xsec * overallEventWeight) / gen_sum_weights;
		if ( input_file_name.Contains("Data"))
		{
			if( Z2Flav < 0) continue;
			if( Z1Flav == -169 && Z2Flav == 169 ) _current_final_state = 0;
			if( Z1Flav == -121 && Z2Flav == 121 ) _current_final_state = 1;
			if( Z1Flav == -121 && Z2Flav == 169 ) _current_final_state = 2;
			if( Z1Flav == -169 && Z2Flav == 121 ) _current_final_state = 3;
			

			_event_weight = _fs_ROS_SS.at(_current_final_state)*FR->GetFakeRate(LepPt->at(2),LepEta->at(2),LepLepId->at(2))*FR->GetFakeRate(LepPt->at(3),LepEta->at(3),LepLepId->at(3));
		}
		//cout << "weight=" << _event_weight << "   lumi="<< _lumi << "  xsec="<< _xsec<< "   k_factor=" << _k_factor<< "   overalEveW=" << overallEventWeight << endl;
		
		
		//=================================
		// cConstants and gConstants
		//=================================
		
		Float_t cConstant_VBF2j = VBF2j_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VBF2j, 0.5);
		Float_t cConstant_VBF1j = VBF1j_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VBF1j, 0.5);
		Float_t cConstant_ZH    = ZH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
		Float_t cConstant_WH    = WH_spline->Eval(ZZMass)*ShiftWPfactor(oldWP_VH, 0.5);
		
		Float_t cConstant_DBKG = GetDBKGcConstant(Z1Flav, Z2Flav, ZZMass);
		Float_t g_Decay_g2    = g_Decay_g2_spline->Eval(ZZMass);
		Float_t g_Decay_g4    = g_Decay_g4_spline->Eval(ZZMass);
		Float_t g_Decay_gL1   = g_Decay_L1_spline->Eval(ZZMass)*pow(10,-4);
		Float_t g_Decay_gL1Zs = g_Decay_L1Zgs_spline->Eval(ZZMass)*pow(10,-4);
		
		Float_t g_VBF_g2    = g_VBF_g2_spline->Eval(ZZMass);
		Float_t g_VBF_g4    = g_VBF_g4_spline->Eval(ZZMass);
		Float_t g_VBF_gL1   = g_VBF_L1_spline->Eval(ZZMass)*pow(10,-4);
		Float_t g_VBF_gL1Zs = g_VBF_L1Zgs_spline->Eval(ZZMass)*pow(10,-4);
		
		Float_t g_WH_g2    = g_WH_g2_spline->Eval(ZZMass);
		Float_t g_WH_g4    = g_WH_g4_spline->Eval(ZZMass);
		Float_t g_WH_gL1   = g_WH_L1_spline->Eval(ZZMass)*pow(10,-4);
		//		Float_t g_WH_gL1Zs = g_WH_L1Zgs_spline->Eval(ZZMass)*pow(10,-4);
		
		Float_t g_ZH_g2    = g_ZH_g2_spline->Eval(ZZMass);
		Float_t g_ZH_g4    = g_ZH_g4_spline->Eval(ZZMass);
		Float_t g_ZH_gL1   = g_ZH_L1_spline->Eval(ZZMass)*pow(10,-4);
		Float_t g_ZH_gL1Zs = g_ZH_L1Zgs_spline->Eval(ZZMass)*pow(10,-4);
		
		//=================================
		// CATEGORISATION DISCRIMINANTS
		//=================================
		
		if ( nCleanedJetsPt30>=2 && p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal != 0) DVBF2j_ME = 1./(1.+ cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal/p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal);
		else DVBF2j_ME = -1;
		
		D_0MH_VBF = (g_VBF_g4 * g_VBF_g4 * p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal) /( g_VBF_g4 * g_VBF_g4 * p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal + cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0PH_VBF = (g_VBF_g2 * g_VBF_g2 * p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal) /( g_VBF_g2 * g_VBF_g2 * p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal + cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0L1_VBF = (g_VBF_gL1 * g_VBF_gL1 * p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal) /( g_VBF_gL1 * g_VBF_gL1 * p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal + cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0L1Zgs_VBF = (g_VBF_gL1Zs * g_VBF_gL1Zs * p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal) /( g_VBF_gL1Zs * g_VBF_gL1Zs * p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal + cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		
		if (nCleanedJetsPt30>=1 && p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal != 0) DVBF1j_ME = 1./(1.+ cConstant_VBF1j*p_JQCD_SIG_ghg2_1_JHUGen_JECNominal/(p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal));
		else DVBF1j_ME = -1;
		
		
		if (nCleanedJetsPt30>=2 && p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*p_HadZH_mavjj_JECNominal != 0) DZH_ME = 1./(1.+ cConstant_ZH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal*p_HadZH_mavjj_true_JECNominal)/(p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*p_HadZH_mavjj_JECNominal));
		else DZH_ME = -1;
		
		if (nCleanedJetsPt30>=2 && p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*p_HadWH_mavjj_JECNominal != 0) DWH_ME = 1./(1.+ cConstant_WH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal*p_HadWH_mavjj_true_JECNominal)/(p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*p_HadWH_mavjj_JECNominal));
		else DWH_ME = -1;
		
		D_0MH_WH = (g_WH_g4 * g_WH_g4 * p_HadWH_SIG_ghw4_1_JHUGen_JECNominal) /( g_WH_g4 * g_WH_g4 * p_HadWH_SIG_ghw4_1_JHUGen_JECNominal + cConstant_WH*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0PH_WH = (g_WH_g2 * g_WH_g2 * p_HadWH_SIG_ghw2_1_JHUGen_JECNominal) /( g_WH_g2 * g_WH_g2 * p_HadWH_SIG_ghw2_1_JHUGen_JECNominal + cConstant_WH*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0L1_WH = (g_WH_gL1 * g_WH_gL1 * p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal) /( g_WH_gL1 * g_WH_gL1 * p_HadWH_SIG_ghw1prime2_1E4_JHUGen_JECNominal + cConstant_WH*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0L1Zgs_WH = 0;
		
		D_0MH_ZH = (g_ZH_g4 * g_ZH_g4 * p_HadZH_SIG_ghz4_1_JHUGen_JECNominal) /( g_ZH_g4 * g_ZH_g4 * p_HadZH_SIG_ghz4_1_JHUGen_JECNominal + cConstant_ZH*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0PH_ZH = (g_ZH_g2 * g_ZH_g2 * p_HadZH_SIG_ghz2_1_JHUGen_JECNominal) /( g_ZH_g2 * g_ZH_g2 * p_HadZH_SIG_ghz2_1_JHUGen_JECNominal + cConstant_ZH*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0L1_ZH = (g_ZH_gL1 * g_ZH_gL1 * p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal) /( g_ZH_gL1 * g_ZH_gL1 * p_HadZH_SIG_ghz1prime2_1E4_JHUGen_JECNominal + cConstant_ZH*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		D_0L1Zgs_ZH = (g_ZH_gL1Zs * g_ZH_gL1Zs * p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal) /( g_ZH_gL1Zs * g_ZH_gL1Zs * p_HadZH_SIG_ghza1prime2_1E4_JHUGen_JECNominal + cConstant_ZH*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal);
		
		DVH_ME     = TMath::Max( DZH_ME, DWH_ME );
		
		//=================================
		
		//=================================
		// PRODUCTION DISCRIMINANTS
		//=================================
		
		//Calculate kinematic discriminants
		D_BKG_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / ( p_GG_SIG_ghg2_1_ghz1_1_JHUGen + cConstant_DBKG * p_QQB_BKG_MCFM );
		D_BKG_VBF_DEC = p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal * p_GG_SIG_ghg2_1_ghz1_1_JHUGen / ( p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal * p_GG_SIG_ghg2_1_ghz1_1_JHUGen + cConstant_VBF2j * cConstant_DBKG * p_QQB_BKG_MCFM);
		
		// Untagged
		D_0MH_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / (p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_Decay_g4 * g_Decay_g4 * p_GG_SIG_ghg2_1_ghz4_1_JHUGen );
		D_0PH_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / (p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_Decay_g2 * g_Decay_g2 * p_GG_SIG_ghg2_1_ghz2_1_JHUGen );
		D_0L1_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / (p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_Decay_gL1 * g_Decay_gL1 * p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen);
		D_0L1Zgs_DEC = p_GG_SIG_ghg2_1_ghz1_1_JHUGen / (p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_Decay_gL1Zs * g_Decay_gL1Zs * p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen);
		
		// VBF2j-tagged
		D_0MH_VBF_DEC = p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1_1_JHUGen/( p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_VBF_g4 * g_VBF_g4 * g_Decay_g4 * g_Decay_g4 * p_JJVBF_SIG_ghv4_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz4_1_JHUGen );
		D_0PH_VBF_DEC = p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1_1_JHUGen/( p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_VBF_g2 * g_VBF_g2 * g_Decay_g2 * g_Decay_g2 * p_JJVBF_SIG_ghv2_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz2_1_JHUGen );
		D_0L1_VBF_DEC = p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1_1_JHUGen/( p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_VBF_gL1 * g_VBF_gL1 * g_Decay_gL1 * g_Decay_gL1 * p_JJVBF_SIG_ghv1prime2_1E4_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1prime2_1E4_JHUGen );
		D_0L1Zgs_VBF_DEC = p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1_1_JHUGen/( p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghz1_1_JHUGen + g_VBF_gL1Zs * g_VBF_gL1Zs * g_Decay_gL1Zs * g_Decay_gL1Zs * p_JJVBF_SIG_ghza1prime2_1E4_JHUGen_JECNominal*p_GG_SIG_ghg2_1_ghza1prime2_1E4_JHUGen );
		
		//		cout << "================================" << endl;
		//		cout << "NJets=" << nCleanedJetsPt30 << endl;
		//		cout << "DVBF2j_ME= " << DVBF2j_ME << endl;
		//		cout << "DVBF1j_ME= " << DVBF1j_ME << endl;
		//		cout << "DZH_ME= " << DZH_ME << endl;
		//		cout << "DWH_ME= " << DWH_ME << endl;
		//		cout << "D_BKG_DEC= " << D_BKG_DEC << endl;
		//		cout << "D_BKG_VBF_DEC= " << D_BKG_VBF_DEC << endl;
		//		cout << "D_0MH_DEC= " << D_0MH_DEC << endl;
		//		cout << "D_0PH_DEC= " << D_0PH_DEC << endl;
		//		cout << "D_0L1_DEC= " << D_0L1_DEC << endl;
		//		cout << "D_0L1Zgs_DEC= " << D_0L1Zgs_DEC << endl;
		//		cout << "D_0MH_VBF_DEC= " << D_0MH_VBF_DEC << endl;
		//		cout << "D_0PH_VBF_DEC= " << D_0PH_VBF_DEC << endl;
		//		cout << "D_0L1_VBF_DEC= " << D_0L1_VBF_DEC << endl;
		//		cout << "D_0L1Zgs_VBF_DEC= " << D_0L1Zgs_VBF_DEC << endl;
		//		cout << "================================" << endl;
		
		//=======================
		// 2D HISTOS
		//=======================
		
		//inclusive
		if (nCleanedJetsPt30 >= 2)
		{
			histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::SM]->Fill(ZZMass, DVBF2j_ME, _event_weight);
			histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::SM]->Fill(ZZMass,DVH_ME, _event_weight);
			
			histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa3]->Fill(ZZMass, D_0MH_VBF, _event_weight);
			histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::fa3]->Fill(ZZMass,TMath::Max(D_0MH_WH,D_0MH_ZH), _event_weight);
			
			histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa2]->Fill(ZZMass, D_0PH_VBF, _event_weight);
			histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::fa2]->Fill(ZZMass,TMath::Max(D_0PH_WH,D_0PH_ZH), _event_weight);
			
			histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fL1]->Fill(ZZMass, D_0L1_VBF, _event_weight);
			histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::fL1]->Fill(ZZMass,TMath::Max(D_0L1_WH,D_0L1_ZH), _event_weight);
			
			histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fL1Zgs]->Fill(ZZMass, D_0L1Zgs_VBF, _event_weight);
			histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::fL1Zgs]->Fill(ZZMass,TMath::Max(D_0L1Zgs_WH,D_0L1Zgs_ZH), _event_weight);

		}
		if (nCleanedJetsPt30 == 1)
		{
			histos_2D[Settings::on_inclusive][Settings::D_VBF1j][Settings::SM]->Fill(ZZMass, DVBF1j_ME, _event_weight);
		}
		
		//VBF2j-tagged fa3
		if ((DVBF2j_ME > 0.5 ||  D_0MH_VBF > 0.5))//nExtraLep==0 && (((nCleanedJetsPt30==2||nCleanedJetsPt30==3)&&nCleanedJetsPt30BTagged_bTagSF<=1)||(nCleanedJetsPt30>=4&&nCleanedJetsPt30BTagged_bTagSF==0)) &&
		{
			histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa3]->Fill(ZZMass,D_BKG_VBF_DEC,_event_weight);
			histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fa3]->Fill(ZZMass,D_0MH_VBF_DEC,_event_weight);
			
		}
		//Untagged fa3
		else
		{
			histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fa3]->Fill(ZZMass,D_BKG_DEC,_event_weight);
			histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fa3]->Fill(ZZMass,D_0MH_DEC,_event_weight);
		}
		
		//VBF2j-tagged fa2
		if ((DVBF2j_ME > 0.5 ||  D_0PH_VBF > 0.5))//nExtraLep==0 && (((nCleanedJetsPt30==2||nCleanedJetsPt30==3)&&nCleanedJetsPt30BTagged_bTagSF<=1)||(nCleanedJetsPt30>=4&&nCleanedJetsPt30BTagged_bTagSF==0)) &&
		{
			histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa2]->Fill(ZZMass,D_BKG_VBF_DEC,_event_weight);
			histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fa2]->Fill(ZZMass,D_0PH_VBF_DEC,_event_weight);
			
		}
		//Untagged fa2
		else
		{
			histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fa2]->Fill(ZZMass,D_BKG_DEC,_event_weight);
			histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fa2]->Fill(ZZMass,D_0PH_DEC,_event_weight);
		}
		
		//VBF2j-tagged fL1
		if ((DVBF2j_ME > 0.5 ||  D_0L1_VBF > 0.5))//nExtraLep==0 && (((nCleanedJetsPt30==2||nCleanedJetsPt30==3)&&nCleanedJetsPt30BTagged_bTagSF<=1)||(nCleanedJetsPt30>=4&&nCleanedJetsPt30BTagged_bTagSF==0)) &&
		{
			histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fL1]->Fill(ZZMass,D_BKG_VBF_DEC,_event_weight);
			histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fL1]->Fill(ZZMass,D_0L1_VBF_DEC,_event_weight);
			
		}
		//Untagged fL1
		else
		{
			histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fL1]->Fill(ZZMass,D_BKG_DEC,_event_weight);
			histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fL1]->Fill(ZZMass,D_0L1_DEC,_event_weight);
		}
		
		//VBF2j-tagged fL1Zgs
		if ((DVBF2j_ME > 0.5 ||  D_0L1Zgs_VBF > 0.5))//nExtraLep==0 && (((nCleanedJetsPt30==2||nCleanedJetsPt30==3)&&nCleanedJetsPt30BTagged_bTagSF<=1)||(nCleanedJetsPt30>=4&&nCleanedJetsPt30BTagged_bTagSF==0)) &&
		{
			histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fL1Zgs]->Fill(ZZMass,D_BKG_VBF_DEC,_event_weight);
			histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fL1Zgs]->Fill(ZZMass,D_0L1Zgs_VBF_DEC,_event_weight);
			
		}
		//Untagged fL1Zgs
		else
		{
			histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fL1Zgs]->Fill(ZZMass,D_BKG_DEC,_event_weight);
			histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fL1Zgs]->Fill(ZZMass,D_0L1Zgs_DEC,_event_weight);
		}
		
		
		
		
		//=======================
		// 1D HISTOS
		//=======================
		if ( only2jEvents && nCleanedJetsPt30 >= 2)
		{
			histos_1D[Settings::M4l_2j_events]->Fill(ZZMass, _event_weight);
			histos_1D[Settings::M4l_counter]->Fill(ZZMass);
			p2j->Fill(ZZMass,ZZMass,_event_weight);
		}
		
		else if (  !only2jEvents )
		{
			histos_1D[Settings::M4l_2j_events]->Fill(ZZMass, _event_weight);
			histos_1D[Settings::M4l_counter]->Fill(ZZMass);
			p2j->Fill(ZZMass,ZZMass,_event_weight);
		}
		
		if ( only2jEvents && nCleanedJetsPt30 >= 1)
		{
			histos_1D[Settings::M4l_1j_events]->Fill(ZZMass, _event_weight);
			p1j->Fill(ZZMass,ZZMass,_event_weight);
		}
		
		else if (  !only2jEvents )
		{
			histos_1D[Settings::M4l_1j_events]->Fill(ZZMass, _event_weight);
			p1j->Fill(ZZMass,ZZMass,_event_weight);
		}
		
		if( DVBF2j_ME > 0.5 && nCleanedJetsPt30 >= 2) histos_1D[Settings::M4l_DVBF2j]->Fill(ZZMass, _event_weight);
		if( DVBF1j_ME > 0.5 && nCleanedJetsPt30 == 1) histos_1D[Settings::M4l_DVBF1j]->Fill(ZZMass, _event_weight);
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
}


void Analyzer::LoopForEff(TString filename, Float_t lumi, bool shiftWP, bool only2jEvents , TH1F *hist_1D[])
{
	_lumi = lumi;
	input_file_name = filename;
	
	TTree *tree;
	inputfile = TFile::Open(filename);
	TDirectory * dir = (TDirectory*)inputfile->Get(filename);
	tree = (TTree*)inputfile->Get("ZZTree/candTree");
	
	Init(tree,filename);
	
	if (fChain == 0) return;
	
	Long64_t nentries = fChain->GetEntriesFast();
	
	hCounters = (TH1F*)inputfile->Get("ZZTree/Counters");
	gen_sum_weights = (Long64_t)hCounters->GetBinContent(40);
	
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
		Float_t cConstant_VBF2j, cConstant_VBF1j, cConstant_WH, cConstant_ZH, ZH_mavjj, WH_mavjj, ZH_mavjj_true, WH_mavjj_true;
		if(input_file_name.Contains("/data3/Higgs/"))
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
			WH_mavjj_true   = p_HadWH_mavjj_true_JECNominal;
			ZH_mavjj_true   = p_HadZH_mavjj_true_JECNominal;
		}
		
		else if(input_file_name.Contains("Moriond"))
		{
			cConstant_VBF2j = getDVBF2jetsConstant_shiftWP(ZZMass,false,0.5);
			cConstant_VBF1j = getDVBF1jetConstant_shiftWP(ZZMass,false,0.5);
			cConstant_ZH    = getDZHhConstant_shiftWP(ZZMass,false,0.5);
			cConstant_WH    = getDWHhConstant_shiftWP(ZZMass,false,0.5);
			WH_mavjj      = 1.;
			ZH_mavjj      = 1.;
			WH_mavjj_true = 1.;
			ZH_mavjj_true = 1.;
		}
		
		if (p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal > 0) DVBF2j_ME = 1./(1.+ cConstant_VBF2j*p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal/p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal);
		else DVBF2j_ME = -1;
		
		//		if (ientry == 10) break;
		//		cout << "p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal = " << p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal << endl;
		//		cout << "p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal = " << p_JJVBF_SIG_ghv1_1_JHUGen_JECNominal << endl;
		//		cout << "cConstant_VBF2j = " << cConstant_VBF2j << endl;
		//		cout << "DVBF2j_ME = " << DVBF2j_ME << endl;
		//		cout << "nCleanedJetsPt30 = " << nCleanedJetsPt30 << endl;
		//		cout << "event_weight = " << _event_weight << endl;
		//		cout << "ZZMass = " << ZZMass << endl;
		//		cout << "====================================================" << endl;
		
		if (p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal > 0) DVBF1j_ME = 1./(1.+ cConstant_VBF1j*p_JQCD_SIG_ghg2_1_JHUGen_JECNominal/(p_JVBF_SIG_ghv1_1_JHUGen_JECNominal*pAux_JVBF_SIG_ghv1_1_JHUGen_JECNominal));
		else DVBF1j_ME = -1;
		
		if (p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*ZH_mavjj > 0) DZH_ME = 1./(1.+ cConstant_ZH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal*ZH_mavjj_true)/(p_HadZH_SIG_ghz1_1_JHUGen_JECNominal*ZH_mavjj));
		else DZH_ME = -1;
		
		if (p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*WH_mavjj > 0) DWH_ME = 1./(1.+ cConstant_WH*(p_JJQCD_SIG_ghg2_1_JHUGen_JECNominal*WH_mavjj_true)/(p_HadWH_SIG_ghw1_1_JHUGen_JECNominal*WH_mavjj));
		else DWH_ME = -1;
		
		DVH_ME = TMath::Max( DZH_ME, DWH_ME );
		
		//=================================
		
		
		if (nCleanedJetsPt30 >= 2) hist_1D[Settings::M4l_DVBF2j]->Fill(DVBF2j_ME, _event_weight);
		else if (!only2jEvents) hist_1D[Settings::M4l_DVBF2j]->Fill(0., _event_weight);
		if (nCleanedJetsPt30 >= 2) hist_1D[Settings::M4l_DVH]->Fill(DVH_ME, _event_weight);
		else if (!only2jEvents) hist_1D[Settings::M4l_DVH]->Fill(0., _event_weight);
		if (nCleanedJetsPt30 == 1) hist_1D[Settings::M4l_DVBF1j]->Fill(DVBF1j_ME, _event_weight);
		else if (!only2jEvents) hist_1D[Settings::M4l_DVBF1j]->Fill(0., _event_weight);
		
		
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
		if ( abs(Z2Flav) == 121 )
			cConstant = DBKG_spline_4e->Eval(ZZMass); //4e final state
		else if ( abs(Z2Flav) == 169 )
			cConstant = DBKG_spline_2e2mu->Eval(ZZMass); // 2e2mu
		else
			cerr << "[ERROR] " << endl;
	}
	else if ( Z1Flav == -169 )
	{
		if ( abs(Z2Flav) == 121 )
			cConstant = DBKG_spline_2e2mu->Eval(ZZMass); //2mu2e
		else if ( abs(Z2Flav) == 169 )
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

