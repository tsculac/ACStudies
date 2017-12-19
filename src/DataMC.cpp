// C++
#include <iostream>
#include <fstream>
#include <string>

// ROOT
#include "TApplication.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLine.h"
#include "TMultiGraph.h"
#include "THStack.h"
#include "TColor.h"
#include "TPaveText.h"


// My own files
#include "../include/Analyzer.h"
#include "../include/Functions.h"
#include "../include/Settings.h"

using namespace std;

void PlotAsStack(TString disc_name, TH2F *histos_2D[Settings::num_of_production_modes], TString xTitle,  TString folder="", int setup = 1)
{
	Int_t   m4l_bins1     = 18;
	Double_t m4l_slices1[] = {105,140,150,160,170,180,190,220,250,300,400,500,600,700,800,900,1000,2000,3000};
	
	Int_t   m4l_bins2     = 10;
	Double_t m4l_slices2[] = {105,120,130,140,150,160,170,180,190,220,250};
	
	Int_t   m4l_bins3     = 13;
	Double_t m4l_slices3[] = {105,140,180,220,300,400,500,600,700,800,1500,2000,3000,4000};
	
	Int_t m4l_bins = m4l_bins1;
	if(setup == 1) m4l_bins = m4l_bins1;
	if(setup == 2) m4l_bins = m4l_bins2;
	if(setup == 3) m4l_bins = m4l_bins3;
	
	Double_t m4l_slices[m4l_bins + 1];
	if(setup == 1) for(int i=0; i<= m4l_bins1; i++){ m4l_slices[i]=m4l_slices1[i];}
	if(setup == 2) for(int i=0; i<= m4l_bins2; i++){ m4l_slices[i]=m4l_slices2[i];}
	if(setup == 3) for(int i=0; i<= m4l_bins3; i++){ m4l_slices[i]=m4l_slices3[i];}
	
	Int_t n_plots;
	Int_t dn_mass[3];
	Int_t up_mass[3];
	if(setup == 1) { n_plots = 3; dn_mass[0]=0;dn_mass[1]=7;dn_mass[2]=10; up_mass[0]=1;up_mass[1]=10;up_mass[2]=18; }
	if(setup == 2) { n_plots = 1; dn_mass[0]=0; up_mass[0]=3;}
	if(setup == 3) { n_plots = 3; dn_mass[0]=0;dn_mass[1]=3;dn_mass[2]=5; up_mass[0]=1;up_mass[1]=5;up_mass[2]=13; }
	
	TH1D *ggH_SM, *VBF_SM, *VH_SM;
	TH1D *qqZZ, *ggZZ, *ZpX;
	
	TCanvas *c1;
	c1 = new TCanvas("c1_"+disc_name+folder,"c1_"+disc_name,900,900);
	
	for ( int i_plot = 0; i_plot < n_plots ; i_plot++ )
	{
		THStack *hs = new THStack("hs","");
		c1->cd();

		ggH_SM = (TH1D*)(histos_2D[Settings::ggH125]->ProjectionY((to_string(i_plot)).c_str(),dn_mass[i_plot],up_mass[i_plot],"D")->Clone());
		ggH_SM->SetFillColor(TColor::GetColor("#ffdcdc"));
		ggH_SM->SetLineColor(TColor::GetColor("#cc0000"));

		VBF_SM = (TH1D*)(histos_2D[Settings::VBFH125]->ProjectionY((to_string(i_plot)).c_str(),dn_mass[i_plot],up_mass[i_plot],"D")->Clone());
		VBF_SM->SetFillColor(TColor::GetColor("#ff9b9b"));
		VBF_SM->SetLineColor(TColor::GetColor("#cc0000"));
		
		VH_SM = (TH1D*)(histos_2D[Settings::WH125]->ProjectionY((to_string(i_plot)).c_str(),dn_mass[i_plot],up_mass[i_plot],"D")->Clone());
		//VH_SM->Add((TH1D*)(histos_2D[Settings::ZH125]->ProjectionY((to_string(i)).c_str(),dn_mass[i_plot],up_mass[i_plot],"D")->Clone()));
		VH_SM->SetFillColor(TColor::GetColor("#ff9b9b"));
		VH_SM->SetLineColor(TColor::GetColor("#cc0000"));
		
		qqZZ = (TH1D*)(histos_2D[Settings::qqZZ]->ProjectionY((to_string(i_plot)).c_str(),dn_mass[i_plot],up_mass[i_plot],"D")->Clone());
		qqZZ->SetFillColor(TColor::GetColor("#99ccff"));
		qqZZ->SetLineColor(TColor::GetColor("#000099"));
		
		ggZZ = (TH1D*)(histos_2D[Settings::ggZZ]->ProjectionY((to_string(i_plot)).c_str(),dn_mass[i_plot],up_mass[i_plot],"D")->Clone());
		ggZZ->SetFillColor(TColor::GetColor("#4b78ff"));
		ggZZ->SetLineColor(TColor::GetColor("#000099"));

		ZpX = (TH1D*)(histos_2D[Settings::ZpX]->ProjectionY((to_string(i_plot)).c_str(),dn_mass[i_plot],up_mass[i_plot],"D")->Clone());
		ZpX->SetFillColor(TColor::GetColor("#669966"));
		ZpX->SetLineColor(TColor::GetColor("#003300"));
		
		hs->Add(ZpX);
		hs->Add(ggZZ);
		hs->Add(qqZZ);
		hs->Add(VBF_SM);
		hs->Add(VH_SM);
		hs->Add(ggH_SM);

		hs->Draw("HIST");
		
		float data_max = qqZZ->GetBinContent(qqZZ->GetMaximumBin());
		//float data_max_error = histos_1D[plot_index][fs][cat][Settings::Data]->GetBinErrorUp(histos_1D[plot_index][fs][cat][Settings::Data]->GetMaximumBin());
		
		hs->SetMaximum((data_max)*5);


		
		hs->GetXaxis()->SetTitle(xTitle);
		hs->GetYaxis()->SetTitle("Events/0.01");
		
		TLegend *leg = new TLegend(0.1,0.5,0.5,0.9);
		leg->SetFillColor(0);
		leg->SetBorderSize(0);
		leg->SetFillStyle(0);
		leg->AddEntry( ggH_SM,"H(125), other","f");
		leg->AddEntry( VBF_SM,"H(125), VBF","f");
		leg->AddEntry( VH_SM, "H(125), VH","f");
		leg->AddEntry( qqZZ, "q#bar{q}#rightarrowZZ, Z#gamma*", "f" );
		leg->AddEntry( ggZZ, "gg#rightarrowZZ, Z#gamma*", "f" );
		leg->AddEntry( ZpX, "Z+X", "f" );
		leg->Draw();

		TPaveText *pav;
		pav = new TPaveText(.38, .88, .58, .95 ,"brNDC");
		pav->SetFillStyle(0);
		pav->SetBorderSize(0);
		pav->SetTextAlign(11);
		pav->SetTextSize(0.062);
		pav->SetTextFont(72);
		pav->AddText((to_string(int(m4l_slices[dn_mass[i_plot]]))+" - "+to_string(int(m4l_slices[up_mass[i_plot]]))+" GeV").c_str());
		pav->Draw();
		
		c1->SaveAs("DataMCPlots/" + folder + "/" + disc_name + "_"+to_string(i_plot)+".png");
		c1->SaveAs("DataMCPlots/" + folder + "/" + disc_name + "_"+to_string(i_plot)+".pdf");

		c1->Clear();
	}
	
}

int main( int argc, char *argv[] )
{
	TFile* th2f_file;
	th2f_file = TFile::Open("DVsM4l_AllEvents_lumi3586.root");
	
   Functions *functions = new Functions();
	
	vector<TString> _s_prod;
	vector<TString> _s_discr;
	vector<TString> _s_cat;
	vector<TString> _s_ac;
	
	_s_prod.push_back("ggH");
	_s_prod.push_back("VBF");
	_s_prod.push_back("WH");
	_s_prod.push_back("ZH");
	_s_prod.push_back("ggH125");
	_s_prod.push_back("VBF125");
	_s_prod.push_back("WH125");
	_s_prod.push_back("ZH125");
	_s_prod.push_back("qqZZ");
	_s_prod.push_back("ggZZ");
	_s_prod.push_back("ZpX");
	_s_prod.push_back("gg0MH");
	_s_prod.push_back("gg0PH");
	_s_prod.push_back("gg0PL1");
	_s_prod.push_back("gg0PL1Zgs");
	_s_prod.push_back("VBF0MH");
	_s_prod.push_back("VBF0PH");
	_s_prod.push_back("VBF0PL1");
	_s_prod.push_back("VBF0PL1Zgs");

	
	_s_cat.push_back("untag");
	_s_cat.push_back("VBFtag");
	_s_cat.push_back("VHtag");
	_s_cat.push_back("incl");
	
	_s_ac.push_back("SM");
	_s_ac.push_back("fa3");
	_s_ac.push_back("fa2");
	_s_ac.push_back("fL1");
	_s_ac.push_back("fL1Zgs");
	
	_s_discr.push_back("DVBF2jVsM4l_");
	_s_discr.push_back("DVBF1jVsM4l_");
	_s_discr.push_back("DVHVsM4l_");
	_s_discr.push_back("DBKGDECVsM4l");
	_s_discr.push_back("DDECVsM4l");
	_s_discr.push_back("DBKGVBFDECVsM4l");
	_s_discr.push_back("DVBFDECVsM4l");
	
	TString histo_name;
	
	TH2F *histos_2D[Settings::num_of_categories_OnShell][Settings::num_of_2D_hist_names][Settings::num_of_anomalous_couplings][Settings::num_of_production_modes];
	
	for (int i_cat = 0; i_cat < Settings::num_of_categories_OnShell; i_cat++)
	{
		for (int i_discr = 0; i_discr < Settings::num_of_2D_hist_names; i_discr++)
		{
			for (int i_ac = 0; i_ac < Settings::num_of_anomalous_couplings; i_ac++)
			{
				for (int i_prod = 0; i_prod < Settings::num_of_production_modes; i_prod++)
				{
					histo_name = _s_discr.at(i_discr) + _s_cat.at(i_cat) + "_" + _s_ac.at(i_ac) + "_" + _s_prod.at(i_prod);
					histos_2D[i_cat][i_discr][i_ac][i_prod] = (TH2F*)th2f_file->Get(histo_name);
				}
			}
		}
	}
	
	for (int i_cat = 0; i_cat < Settings::num_of_categories_OnShell; i_cat++)
	{
		for (int i_ac = 0; i_ac < Settings::num_of_anomalous_couplings; i_ac++)
		{
			for (int i_prod = 0; i_prod < Settings::num_of_production_modes; i_prod++)
			{
				if (i_prod == Settings::gg_0L1Zs || i_prod == Settings::VBF_0L1Zs ) continue;
				
				histos_2D[i_cat][Settings::D_VBF2j][i_ac][i_prod]->RebinY(10);
				histos_2D[i_cat][Settings::D_VBF1j][i_ac][i_prod]->RebinY(10);
				histos_2D[i_cat][Settings::D_VH][i_ac][i_prod]   ->RebinY(10);
				
				histos_2D[i_cat][Settings::D_BKG_DEC][i_ac][i_prod]    ->RebinY(10);
				histos_2D[i_cat][Settings::D_DEC][i_ac][i_prod]        ->RebinY(10);
				histos_2D[i_cat][Settings::D_BKG_VBF_DEC][i_ac][i_prod]->RebinY(10);
				histos_2D[i_cat][Settings::D_VBF_DEC][i_ac][i_prod]    ->RebinY(10);
			}
		}
	}

	//==================
	//SM discriminants
	//==================
	PlotAsStack("D_VBF2j", histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::SM], "D_{2jet}^{VBF}","SM", 1);
	PlotAsStack("D_VBF1j", histos_2D[Settings::on_inclusive][Settings::D_VBF1j][Settings::SM], "D_{1jet}^{VBF}","SM", 1);
	PlotAsStack("D_VH", histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::SM], "D_{2jet}^{VH}","SM", 2);
	
	//==================
	//fa3 discriminants
	//==================
	PlotAsStack("DVBF2jetBSM", histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa3], "D_{2jet}^{VBF,0-}","fa3", 3);
	PlotAsStack("DBKGDEC", histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fa3], "D_{bkg}^{dec}","fa3", 3);
	PlotAsStack("DDEC", histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fa3], "D_{0-}^{dec}","fa3", 3);
	PlotAsStack("DBKGVBFDEC", histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa3], "D_{bkg}^{VBF+dec}","fa3", 3);
	PlotAsStack("DVBFDEC", histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fa3], "D_{0-}^{VBF+dec}","fa3", 3);
	
	//==================
	//fa2 discriminants
	//==================
	PlotAsStack("DVBF2jetBSM", histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa2], "D_{2jet}^{VBF,0h+}","fa2", 3);
	PlotAsStack("DBKGDEC", histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fa2], "D_{bkg}^{dec}","fa2", 3);
	PlotAsStack("DDEC", histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fa2], "D_{0h+}^{dec}","fa2", 3);
	PlotAsStack("DBKGVBFDEC", histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa2], "D_{bkg}^{VBF+dec}","fa2", 3);
	PlotAsStack("DVBFDEC", histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fa2], "D_{0h+}^{VBF+dec}","fa2", 3);
	
	//==================
	//fL1 discriminants
	//==================
	PlotAsStack("DVBF2jetBSM", histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fL1], "D_{2jet}^{VBF,#Lambda_{1}}","fL1", 3);
	PlotAsStack("DBKGDEC", histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fL1], "D_{bkg}^{dec}","fL1", 3);
	PlotAsStack("DDEC", histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fL1], "D_{#Lambda_{1}}^{dec}","fL1", 3);
	PlotAsStack("DBKGVBFDEC", histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fL1], "D_{bkg}^{VBF+dec}","fL1", 3);
	PlotAsStack("DVBFDEC", histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fL1], "D_{#Lambda_{1}}^{VBF+dec}","fL1", 3);
	
	
}
