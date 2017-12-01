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


// My own files
#include "../include/Analyzer.h"
#include "../include/Functions.h"
#include "../include/Settings.h"

using namespace std;

void DoEfficiencyVsM4lPlots(bool only2jEvents = false)
{
	TFile* tgraph_file;
	if(only2jEvents) tgraph_file = TFile::Open("EffVsM4l_2jEvents.root");
	else tgraph_file = TFile::Open("EffVsM4l_AllEvents_testing.root");
	
	TGraphErrors *VBF_Djj_tgraph, *ggH_Djj_tgraph, *WH_Djj_tgraph, *ZH_Djj_tgraph, *qqZZ_Djj_tgraph;
	TGraphErrors *VBF_DVH_tgraph,*ggH_DVH_tgraph,*WH_DVH_tgraph,*ZH_DVH_tgraph,*qqZZ_DVH_tgraph;
	TGraphErrors *VBF_Dj_tgraph, *ggH_Dj_tgraph, *WH_Dj_tgraph, *ZH_Dj_tgraph, *qqZZ_Dj_tgraph;
	
	VBF_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("VBF_Djj_tgraph");
	ggH_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("ggH_Djj_tgraph");
	WH_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("WH_Djj_tgraph");
	ZH_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("ZH_Djj_tgraph");
	qqZZ_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("qqZZ_Djj_tgraph");
	
	VBF_Dj_tgraph = (TGraphErrors*)tgraph_file->Get("VBF_Dj_tgraph");
	ggH_Dj_tgraph = (TGraphErrors*)tgraph_file->Get("ggH_Dj_tgraph");
	WH_Dj_tgraph = (TGraphErrors*)tgraph_file->Get("WH_Dj_tgraph");
	ZH_Dj_tgraph = (TGraphErrors*)tgraph_file->Get("ZH_Dj_tgraph");
	qqZZ_Dj_tgraph = (TGraphErrors*)tgraph_file->Get("qqZZ_Dj_tgraph");
	
	VBF_DVH_tgraph = (TGraphErrors*)tgraph_file->Get("VBF_DVH_tgraph");
	ggH_DVH_tgraph = (TGraphErrors*)tgraph_file->Get("ggH_DVH_tgraph");
	WH_DVH_tgraph = (TGraphErrors*)tgraph_file->Get("WH_DVH_tgraph");
	ZH_DVH_tgraph = (TGraphErrors*)tgraph_file->Get("ZH_DVH_tgraph");
	qqZZ_DVH_tgraph = (TGraphErrors*)tgraph_file->Get("qqZZ_DVH_tgraph");
	
	
	
	//==================================================================
	//
	//    DVBF2j_ME
	//======================
	TCanvas *c1;
	c1 = new TCanvas("c11","c11",900,900);
	c1->Clear();
	c1->cd();
	TMultiGraph *mg = new TMultiGraph();
	VBF_Djj_tgraph->SetTitle("VBF");
	VBF_Djj_tgraph->SetLineColor(kRed);
	VBF_Djj_tgraph->SetMarkerStyle(20);
	VBF_Djj_tgraph->SetMarkerColor(kRed);
	mg->Add(VBF_Djj_tgraph);
	
	ggH_Djj_tgraph->SetTitle("ggH");
	ggH_Djj_tgraph->SetLineColor(kBlack);
	ggH_Djj_tgraph->SetMarkerStyle(20);
	ggH_Djj_tgraph->SetMarkerColor(kBlack);
	mg->Add(ggH_Djj_tgraph);
	
	WH_Djj_tgraph->SetTitle("WH");
	WH_Djj_tgraph->SetLineColor(kBlue);
	WH_Djj_tgraph->SetMarkerStyle(20);
	WH_Djj_tgraph->SetMarkerColor(kBlue);
	mg->Add(WH_Djj_tgraph);
	
	ZH_Djj_tgraph->SetTitle("ZH");
	ZH_Djj_tgraph->SetLineColor(kYellow);
	ZH_Djj_tgraph->SetMarkerStyle(20);
	ZH_Djj_tgraph->SetMarkerColor(kYellow);
	mg->Add(ZH_Djj_tgraph);
	
	qqZZ_Djj_tgraph->SetTitle("qqZZ");
	qqZZ_Djj_tgraph->SetLineColor(kGreen);
	qqZZ_Djj_tgraph->SetMarkerStyle(20);
	qqZZ_Djj_tgraph->SetMarkerColor(kGreen);
	mg->Add(qqZZ_Djj_tgraph);
	mg->SetMinimum(0.);
	mg->SetMaximum(1.39);
	mg->Draw("apl");
	mg->GetXaxis()->SetTitle("M_{4l} (GeV)");
	mg->GetYaxis()->SetTitle("D_{2jets}^{VBF}  eff");
	
	TLegend *leg1 = new TLegend(0.45, 0.65, 0.90, 0.90);
	leg1->AddEntry(VBF_Djj_tgraph,"VBF","pl");
	leg1->AddEntry(ggH_Djj_tgraph,"ggH","pl");
	leg1->AddEntry(WH_Djj_tgraph,"WH","pl");
	leg1->AddEntry(ZH_Djj_tgraph,"ZH","pl");
	leg1->AddEntry(qqZZ_Djj_tgraph,"qqZZ","pl");
	leg1->Draw();
	if(only2jEvents)
	{
		c1->SaveAs("ControlPlots/DVBFJJ_comb_2jEvents.pdf");
		c1->SaveAs("ControlPlots/DVBFJJ_comb_2jEvents.png");
	}
	else
	{
		c1->SaveAs("ControlPlots/DVBFJJ_comb.pdf");
		c1->SaveAs("ControlPlots/DVBFJJ_comb.png");
	}
	
	//======================
	//
	//    DVH_ME
	//======================
	c1->Clear();
	c1->cd();
	TMultiGraph *mg2 = new TMultiGraph();
	VBF_DVH_tgraph->SetTitle("VBF");
	VBF_DVH_tgraph->SetLineColor(kRed);
	VBF_DVH_tgraph->SetMarkerStyle(20);
	VBF_DVH_tgraph->SetMarkerColor(kRed);
	mg2->Add(VBF_DVH_tgraph);
	
	ggH_DVH_tgraph->SetTitle("ggH");
	ggH_DVH_tgraph->SetLineColor(kBlack);
	ggH_DVH_tgraph->SetMarkerStyle(20);
	ggH_DVH_tgraph->SetMarkerColor(kBlack);
	mg2->Add(ggH_DVH_tgraph);
	
	WH_DVH_tgraph->SetTitle("WH");
	WH_DVH_tgraph->SetLineColor(kBlue);
	WH_DVH_tgraph->SetMarkerStyle(20);
	WH_DVH_tgraph->SetMarkerColor(kBlue);
	mg2->Add(WH_DVH_tgraph);
	
	ZH_DVH_tgraph->SetTitle("ZH");
	ZH_DVH_tgraph->SetLineColor(kYellow);
	ZH_DVH_tgraph->SetMarkerStyle(20);
	ZH_DVH_tgraph->SetMarkerColor(kYellow);
	mg2->Add(ZH_DVH_tgraph);
	
	qqZZ_DVH_tgraph->SetTitle("qqZZ");
	qqZZ_DVH_tgraph->SetLineColor(kGreen);
	qqZZ_DVH_tgraph->SetMarkerStyle(20);
	qqZZ_DVH_tgraph->SetMarkerColor(kGreen);
	mg2->Add(qqZZ_DVH_tgraph);
	
	mg2->SetMinimum(0.);
	mg2->SetMaximum(1.19);
	mg2->Draw("apl");
	mg2->GetXaxis()->SetLimits(70.,300.);
	mg2->GetXaxis()->SetTitle("M_{4l} (GeV)");
	mg2->GetYaxis()->SetTitle("D_{2jets}^{VH}   eff");
	
	TLegend *leg2 = new TLegend(0.45, 0.65, 0.90, 0.90);
	leg2->AddEntry(VBF_DVH_tgraph,"VBF","pl");
	leg2->AddEntry(ggH_DVH_tgraph,"ggH","pl");
	leg2->AddEntry(WH_DVH_tgraph,"WH","pl");
	leg2->AddEntry(ZH_DVH_tgraph,"ZH","pl");
	leg2->AddEntry(qqZZ_DVH_tgraph,"qqZZ","pl");
	leg2->Draw();
	if(only2jEvents)
	{
		c1->SaveAs("ControlPlots/DVH_comb_2jEvents.pdf");
		c1->SaveAs("ControlPlots/DVH_comb_2jEvents.png");
	}
	else
	{
		c1->SaveAs("ControlPlots/DVH_comb.pdf");
		c1->SaveAs("ControlPlots/DVH_comb.png");
	}
	
	//==================================================================
	//
	//    DVBF1j_ME
	//======================
	TCanvas *c3;
	c3 = new TCanvas("c3","c3",900,900);
	c3->Clear();
	c3->cd();
	TMultiGraph *mg3 = new TMultiGraph();
	VBF_Dj_tgraph->SetTitle("VBF");
	VBF_Dj_tgraph->SetLineColor(kRed);
	VBF_Dj_tgraph->SetMarkerStyle(20);
	VBF_Dj_tgraph->SetMarkerColor(kRed);
	mg3->Add(VBF_Dj_tgraph);
	
	ggH_Dj_tgraph->SetTitle("ggH");
	ggH_Dj_tgraph->SetLineColor(kBlack);
	ggH_Dj_tgraph->SetMarkerStyle(20);
	ggH_Dj_tgraph->SetMarkerColor(kBlack);
	mg3->Add(ggH_Dj_tgraph);
	
	WH_Dj_tgraph->SetTitle("WH");
	WH_Dj_tgraph->SetLineColor(kBlue);
	WH_Dj_tgraph->SetMarkerStyle(20);
	WH_Dj_tgraph->SetMarkerColor(kBlue);
	mg3->Add(WH_Dj_tgraph);
	
	ZH_Dj_tgraph->SetTitle("ZH");
	ZH_Dj_tgraph->SetLineColor(kYellow);
	ZH_Dj_tgraph->SetMarkerStyle(20);
	ZH_Dj_tgraph->SetMarkerColor(kYellow);
	mg3->Add(ZH_Dj_tgraph);
	
	qqZZ_Dj_tgraph->SetTitle("qqZZ");
	qqZZ_Dj_tgraph->SetLineColor(kGreen);
	qqZZ_Dj_tgraph->SetMarkerStyle(20);
	qqZZ_Dj_tgraph->SetMarkerColor(kGreen);
	mg3->Add(qqZZ_Dj_tgraph);
	mg3->SetMinimum(0.);
	mg3->SetMaximum(1.39);
	mg3->Draw("apl");
	mg3->GetXaxis()->SetTitle("M_{4l} (GeV)");
	mg3->GetYaxis()->SetTitle("D_{1jet}^{VBF}  eff");
	
	TLegend *leg3 = new TLegend(0.45, 0.65, 0.90, 0.90);
	leg3->AddEntry(VBF_Dj_tgraph,"VBF","pl");
	leg3->AddEntry(ggH_Dj_tgraph,"ggH","pl");
	leg3->AddEntry(WH_Dj_tgraph,"WH","pl");
	leg3->AddEntry(ZH_Dj_tgraph,"ZH","pl");
	leg3->AddEntry(qqZZ_Dj_tgraph,"qqZZ","pl");
	leg3->Draw();
	if(only2jEvents)
	{
		c3->SaveAs("ControlPlots/DVBFJ_comb_1jEvents.pdf");
		c3->SaveAs("ControlPlots/DVBFJ_comb_1jEvents.png");
	}
	else
	{
		c3->SaveAs("ControlPlots/DVBFJ_comb.pdf");
		c3->SaveAs("ControlPlots/DVBFJ_comb.png");
	}
	
	
	tgraph_file->Close();
	
}

void PlotInM4lSlices_1SIG1BKG(TString disc_name,
										TH2F *signal, TString sig_name, int col1, int style1,
										TH2F *bkg1, TString bkg1_name, int col2,  int style2,
										TString xTitle,  TString folder="", float max = 0.15, int setup = 1)
{
	Int_t   m4l_bins1     = 18;
	Double_t m4l_slices1[] = {110,140,150,160,170,180,190,200,250,300,400,500,600,700,800,900,1000,2000,3000};
	
	Int_t   m4l_bins2     = 10;
	Double_t m4l_slices2[] = {110,120,130,140,150,160,170,180,190,200,250};
	
	Int_t   m4l_bins3     = 13;
	Double_t m4l_slices3[] = {110,140,180,220,300,400,500,600,700,800,1500,2000,3000,4000};
	
	Int_t m4l_bins = m4l_bins1;
	if(setup == 1) m4l_bins = m4l_bins1;
	if(setup == 2) m4l_bins = m4l_bins2;
	if(setup == 3) m4l_bins = m4l_bins3;
	
	Double_t m4l_slices[m4l_bins + 1];
	if(setup == 1) for(int i=0; i<= m4l_bins1; i++){ m4l_slices[i]=m4l_slices1[i];}
	if(setup == 2) for(int i=0; i<= m4l_bins2; i++){ m4l_slices[i]=m4l_slices2[i];}
	if(setup == 3) for(int i=0; i<= m4l_bins3; i++){ m4l_slices[i]=m4l_slices3[i];}
	
	TH1D *sig_temp,*bkg1_temp;
	TH1 *frame;
	TLine *tmp_line = new TLine(1,1,1,1);//hack for TLegend
	TLine *tmp_line1 = new TLine(1,1,1,1);//hack for TLegend
	
	TCanvas *c1;
	c1 = new TCanvas("c1_"+disc_name+folder,"c1_"+disc_name,900,900);
	
	for ( int i = 0; i < m4l_bins ; i++ )
	{
		c1->Clear();
		frame = new TH1F("a_"+disc_name+"_"+to_string(i),"",100,0,1);
		frame->SetMaximum(max);
		frame->Draw();
		sig_temp = signal->ProjectionY((to_string(i)).c_str(),i,i+1);
		frame->SetTitle((to_string(int(m4l_slices[i]))+" - "+to_string(int(m4l_slices[i+1]))).c_str());
		sig_temp->SetLineColor(col1);
		sig_temp->SetLineStyle(style1);
		sig_temp->DrawNormalized("HIST SAME");
		bkg1_temp = bkg1->ProjectionY((to_string(i)).c_str(),i,i+1);
		bkg1_temp->SetLineColor(col2);
		bkg1_temp->SetLineStyle(style2);
		bkg1_temp->DrawNormalized("HIST SAME");
		
		frame->GetXaxis()->SetTitle(xTitle);
		frame->GetYaxis()->SetTitle("a.u.");
		gStyle->SetOptStat(0);
		
		TLegend *leg = new TLegend(0.65, 0.75, 0.90, 0.90);
		tmp_line->SetLineColor(col1);
		tmp_line->SetLineStyle(style1);
		leg->AddEntry(tmp_line,sig_name,"l");
		tmp_line1->SetLineColor(col2);
		tmp_line1->SetLineStyle(style2);
		leg->AddEntry(tmp_line1,bkg1_name,"l");
		leg->Draw();
		
		if( i < 10 ) c1->SaveAs("Animations/" + folder + "/" + disc_name + "_0"+to_string(i)+".png");
		else c1->SaveAs("Animations/" + folder + "/" + disc_name + "_"+to_string(i)+".png");
	}
	
}


void PlotInM4lSlices_2SIG1BKG(TString disc_name,
										TH2F *signal1, TString sig1_name, int col11, int style11,
										TH2F *signal2, TString sig2_name, int col12, int style12,
										TH2F *bkg1, TString bkg1_name, int col2,  int style2,
										TString xTitle,  TString folder="", float max = 0.15, int setup = 1)
{
	Int_t   m4l_bins1     = 18;
	Double_t m4l_slices1[] = {110,140,150,160,170,180,190,200,250,300,400,500,600,700,800,900,1000,2000,3000};
	
	Int_t   m4l_bins2     = 10;
	Double_t m4l_slices2[] = {110,120,130,140,150,160,170,180,190,200,250};
	
	Int_t   m4l_bins3     = 13;
	Double_t m4l_slices3[] = {110,140,180,220,300,400,500,600,700,800,1500,2000,3000,4000};
	
	Int_t m4l_bins = m4l_bins1;
	if(setup == 1) m4l_bins = m4l_bins1;
	if(setup == 2) m4l_bins = m4l_bins2;
	if(setup == 3) m4l_bins = m4l_bins3;
	
	Double_t m4l_slices[m4l_bins + 1];
	if(setup == 1) for(int i=0; i<= m4l_bins1; i++){ m4l_slices[i]=m4l_slices1[i];}
	if(setup == 2) for(int i=0; i<= m4l_bins2; i++){ m4l_slices[i]=m4l_slices2[i];}
	if(setup == 3) for(int i=0; i<= m4l_bins3; i++){ m4l_slices[i]=m4l_slices3[i];}
	
	TH1D *sig1_temp,*sig2_temp,*bkg1_temp;
	TH1 *frame;
	TLine *tmp_lines1 = new TLine(1,1,1,1);//hack for TLegend
	TLine *tmp_lines2 = new TLine(1,1,1,1);//hack for TLegend
	TLine *tmp_line1 = new TLine(1,1,1,1);//hack for TLegend
	
	TCanvas *c1;
	c1 = new TCanvas("c1_"+disc_name+folder,"c1_"+disc_name,900,900);
	
	for ( int i = 0; i < m4l_bins ; i++ )
	{
		c1->Clear();
		frame = new TH1F("a_"+disc_name+"_"+to_string(i),"",100,0,1);
		frame->SetMaximum(max);
		frame->Draw();
		sig1_temp = signal1->ProjectionY((to_string(i)).c_str(),i,i+1);
		frame->SetTitle((to_string(int(m4l_slices[i]))+" - "+to_string(int(m4l_slices[i+1]))).c_str());
		sig1_temp->SetLineColor(col11);
		sig1_temp->SetLineStyle(style11);
		sig1_temp->DrawNormalized("HIST SAME");
		
		sig2_temp = signal2->ProjectionY((to_string(i)).c_str(),i,i+1);
		frame->SetTitle((to_string(int(m4l_slices[i]))+" - "+to_string(int(m4l_slices[i+1]))).c_str());
		sig2_temp->SetLineColor(col12);
		sig2_temp->SetLineStyle(style12);
		sig2_temp->DrawNormalized("HIST SAME");
		
		bkg1_temp = bkg1->ProjectionY((to_string(i)).c_str(),i,i+1);
		bkg1_temp->SetLineColor(col2);
		bkg1_temp->SetLineStyle(style2);
		bkg1_temp->DrawNormalized("HIST SAME");
		
		frame->GetXaxis()->SetTitle(xTitle);
		frame->GetYaxis()->SetTitle("a.u.");
		gStyle->SetOptStat(0);
		
		TLegend *leg = new TLegend(0.65, 0.75, 0.90, 0.90);
		tmp_lines1->SetLineColor(col11);
		tmp_lines1->SetLineStyle(style11);
		leg->AddEntry(tmp_lines1,sig1_name,"l");
		tmp_lines2->SetLineColor(col12);
		tmp_lines2->SetLineStyle(style12);
		leg->AddEntry(tmp_lines2,sig2_name,"l");
		tmp_line1->SetLineColor(col2);
		tmp_line1->SetLineStyle(style2);
		leg->AddEntry(tmp_line1,bkg1_name,"l");
		leg->Draw();
		
		if( i < 10 ) c1->SaveAs("Animations/" + folder + "/" + disc_name + "_0"+to_string(i)+".png");
		else c1->SaveAs("Animations/" + folder + "/" + disc_name + "_"+to_string(i)+".png");
	}
	
}

void PlotInM4lSlices_1SIG2BKG(TString disc_name,
										TH2F *signal1, TString sig1_name, int col11, int style11,
										TH2F *bkg2, TString bkg2_name, int col22,  int style22,
										TH2F *bkg1, TString bkg1_name, int col21,  int style21,
										TString xTitle,  TString folder="", float max = 0.15, int setup = 1)
{
	Int_t   m4l_bins1     = 18;
	Double_t m4l_slices1[] = {110,140,150,160,170,180,190,200,250,300,400,500,600,700,800,900,1000,2000,3000};
	
	Int_t   m4l_bins2     = 10;
	Double_t m4l_slices2[] = {110,120,130,140,150,160,170,180,190,200,250};
	
	Int_t   m4l_bins3     = 13;
	Double_t m4l_slices3[] = {110,140,180,220,300,400,500,600,700,800,1500,2000,3000,4000};
	
	Int_t m4l_bins = m4l_bins1;
	if(setup == 1) m4l_bins = m4l_bins1;
	if(setup == 2) m4l_bins = m4l_bins2;
	if(setup == 3) m4l_bins = m4l_bins3;
	
	Double_t m4l_slices[m4l_bins + 1];
	if(setup == 1) for(int i=0; i<= m4l_bins1; i++){ m4l_slices[i]=m4l_slices1[i];}
	if(setup == 2) for(int i=0; i<= m4l_bins2; i++){ m4l_slices[i]=m4l_slices2[i];}
	if(setup == 3) for(int i=0; i<= m4l_bins3; i++){ m4l_slices[i]=m4l_slices3[i];}
	
	TH1D *sig1_temp,*bkg2_temp,*bkg1_temp;
	TH1 *frame;
	TLine *tmp_lines1 = new TLine(1,1,1,1);//hack for TLegend
	TLine *tmp_lines2 = new TLine(1,1,1,1);//hack for TLegend
	TLine *tmp_line1 = new TLine(1,1,1,1);//hack for TLegend
	
	TCanvas *c1;
	c1 = new TCanvas("c1_"+disc_name+folder,"c1_"+disc_name,900,900);
	
	for ( int i = 0; i < m4l_bins ; i++ )
	{
		c1->Clear();
		frame = new TH1F("a_"+disc_name+"_"+to_string(i),"",100,0,1);
		frame->SetMaximum(max);
		frame->Draw();
		sig1_temp = signal1->ProjectionY((to_string(i)).c_str(),i,i+1);
		frame->SetTitle((to_string(int(m4l_slices[i]))+" - "+to_string(int(m4l_slices[i+1]))).c_str());
		sig1_temp->SetLineColor(col11);
		sig1_temp->SetLineStyle(style11);
		sig1_temp->DrawNormalized("HIST SAME");
		
		bkg2_temp = bkg2->ProjectionY((to_string(i)).c_str(),i,i+1);
		bkg2_temp->SetLineColor(col22);
		bkg2_temp->SetLineStyle(style22);
		bkg2_temp->DrawNormalized("HIST SAME");
		
		bkg1_temp = bkg1->ProjectionY((to_string(i)).c_str(),i,i+1);
		bkg1_temp->SetLineColor(col21);
		bkg1_temp->SetLineStyle(style21);
		bkg1_temp->DrawNormalized("HIST SAME");
		
		frame->GetXaxis()->SetTitle(xTitle);
		frame->GetYaxis()->SetTitle("a.u.");
		gStyle->SetOptStat(0);
		
		TLegend *leg = new TLegend(0.65, 0.75, 0.90, 0.90);
		tmp_lines1->SetLineColor(col11);
		tmp_lines1->SetLineStyle(style11);
		leg->AddEntry(tmp_lines1,sig1_name,"l");
		tmp_lines2->SetLineColor(col22);
		tmp_lines2->SetLineStyle(style22);
		leg->AddEntry(tmp_lines2,bkg2_name,"l");
		tmp_line1->SetLineColor(col21);
		tmp_line1->SetLineStyle(style21);
		leg->AddEntry(tmp_line1,bkg1_name,"l");
		leg->Draw();
		
		if( i < 10 ) c1->SaveAs("Animations/" + folder + "/" + disc_name + "_0"+to_string(i)+".png");
		else c1->SaveAs("Animations/" + folder + "/" + disc_name + "_"+to_string(i)+".png");
	}
	
}

int main( int argc, char *argv[] )
{
	
	bool only2jEvents = false;
	bool plotVBF2j = false;
	bool plotVBF1j = false;
	bool plotVH = false;
	bool plotDBKG = true;
	bool plotD0M = true;
	bool plotD0P = true;
	bool plotDL1 = true;
	bool plotDL1Zgs = false;
	
	DoEfficiencyVsM4lPlots(only2jEvents);

   
	TFile* th2f_file;
	if(only2jEvents) th2f_file = TFile::Open("DVsM4l_2jEvents.root");
	else th2f_file = TFile::Open("DVsM4l_AllEvents.root");
	
   Functions *functions = new Functions();
	
	vector<TString> _s_prod;
	vector<TString> _s_discr;
	vector<TString> _s_cat;
	vector<TString> _s_ac;
	
	_s_prod.push_back("ggH");
	_s_prod.push_back("VBF");
	_s_prod.push_back("WH");
	_s_prod.push_back("ZH");
	_s_prod.push_back("qqZZ");
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
				
				histos_2D[i_cat][Settings::D_VBF2j][i_ac][i_prod]->RebinY(2);
				histos_2D[i_cat][Settings::D_VBF1j][i_ac][i_prod]->RebinY(2);
				histos_2D[i_cat][Settings::D_VH][i_ac][i_prod]   ->RebinY(2);
				
				histos_2D[i_cat][Settings::D_BKG_DEC][i_ac][i_prod]    ->RebinY(5);
				histos_2D[i_cat][Settings::D_DEC][i_ac][i_prod]        ->RebinY(5);
				histos_2D[i_cat][Settings::D_BKG_VBF_DEC][i_ac][i_prod]->RebinY(5);
				histos_2D[i_cat][Settings::D_VBF_DEC][i_ac][i_prod]    ->RebinY(5);
			}
		}
	}

	//==================
	//SM discriminants
	//==================

	PlotInM4lSlices_1SIG1BKG("DVBF2jetSM",
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::SM][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::SM][Settings::ggH],"ggH",kBlack,1,
									 "D_{2jet}^{VBF}",
									 "SM", 0.15, 1);
	
	PlotInM4lSlices_1SIG1BKG("DVBF1jetSM",
									 histos_2D[Settings::on_inclusive][Settings::D_VBF1j][Settings::SM][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_inclusive][Settings::D_VBF1j][Settings::SM][Settings::ggH],"ggH",kBlack,1,
									 "D_{1jet}^{VBF}",
									 "SM", 0.20, 1);
	
	PlotInM4lSlices_2SIG1BKG("DVH2jetSM",
									 histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::SM][Settings::ZH],"ZH",kOrange,1,
									 histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::SM][Settings::WH],"WH",kBlue,1,
									 histos_2D[Settings::on_inclusive][Settings::D_VH][Settings::SM][Settings::ggH],"ggH",kBlack,1,
									 "D_{2jet}^{VH}",
									 "SM", 0.20, 2);

	
	//==================
	//fa3 discriminants
	//==================
	
	PlotInM4lSlices_2SIG1BKG("DVBF2jetBSM",
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa3][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa3][Settings::VBF_0MH],"VBF f_{a3}=1",kRed,2,
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa3][Settings::ggH],"ggH",kBlack,1,
									 "D_{2jet}^{VBF,0-}",
									 "fa3", 0.15, 3);
	
	PlotInM4lSlices_1SIG1BKG("DBKGDEC",
									 histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fa3][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fa3][Settings::qqZZ],"qqZZ",kGreen,1,
									 "D_{bkg}^{dec}",
									 "fa3", 0.20, 3);

	PlotInM4lSlices_1SIG1BKG("DDEC",
									 histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fa3][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fa3][Settings::gg_0MH],"ggH f_{a3}=1",kBlack,2,
									 "D_{0-}^{dec}",
									 "fa3", 0.16, 3);

	PlotInM4lSlices_1SIG2BKG("DBKGVBFDEC",
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa3][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa3][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa3][Settings::qqZZ],"qqZZ",kGreen,1,
									 "D_{bkg}^{VBF+dec}",
									 "fa3", 0.25, 3);
	
	PlotInM4lSlices_1SIG1BKG("DVBFDEC",
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fa3][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fa3][Settings::VBF_0MH],"VBF f_{a3}=1",kRed,2,
									 "D_{0-}^{VBF+dec}",
									 "fa3", 0.25, 3);

	//==================
	//fa2 discriminants
	//==================

	PlotInM4lSlices_2SIG1BKG("DVBF2jetBSM",
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa2][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa2][Settings::VBF_0PH],"VBF f_{a2}=1",kRed,2,
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fa2][Settings::ggH],"ggH",kBlack,1,
									 "D_{2jet}^{VBF,0h+}",
									 "fa2", 0.15, 3);

	PlotInM4lSlices_1SIG1BKG("DBKGDEC",
									 histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fa2][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fa2][Settings::qqZZ],"qqZZ",kGreen,1,
									 "D_{bkg}^{dec}",
									 "fa2", 0.20, 3);

	PlotInM4lSlices_1SIG1BKG("DDEC",
									 histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fa2][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fa2][Settings::gg_0PH],"ggH f_{a2}=1",kBlack,2,
									 "D_{0h+}^{dec}",
									 "fa2", 0.20, 3);

	PlotInM4lSlices_1SIG2BKG("DBKGVBFDEC",
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa2][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa2][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fa2][Settings::qqZZ],"qqZZ",kGreen,1,
									 "D_{bkg}^{VBF+dec}",
									 "fa2", 0.25, 3);

	PlotInM4lSlices_1SIG1BKG("DVBFDEC",
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fa2][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fa2][Settings::VBF_0PH],"VBF f_{a2}=1",kRed,2,
									 "D_{0hp}^{VBF+dec}",
									 "fa2", 0.25, 3);
	
	//==================
	//fL1 discriminants
	//==================
	
	PlotInM4lSlices_2SIG1BKG("DVBF2jetBSM",
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fL1][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fL1][Settings::VBF_0L1],"VBF f_{#Lambda_{1}}=1",kRed,2,
									 histos_2D[Settings::on_inclusive][Settings::D_VBF2j][Settings::fL1][Settings::ggH],"ggH",kBlack,1,
									 "D_{2jet}^{VBF,#Lambda_{1}}",
									 "fL1", 0.15, 3);
	
	PlotInM4lSlices_1SIG1BKG("DBKGDEC",
									 histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fL1][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_untagged][Settings::D_BKG_DEC][Settings::fL1][Settings::qqZZ],"qqZZ",kGreen,1,
									 "D_{bkg}^{dec}",
									 "fL1", 0.20, 3);
	
	PlotInM4lSlices_1SIG1BKG("DDEC",
									 histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fL1][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_untagged][Settings::D_DEC][Settings::fL1][Settings::gg_0L1],"ggH f_{#Lambda_{1}}=1",kBlack,2,
									 "D_{#Lambda_{1}}^{dec}",
									 "fL1", 0.25, 3);
	
	PlotInM4lSlices_1SIG2BKG("DBKGVBFDEC",
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fL1][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fL1][Settings::ggH],"ggH",kBlack,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_BKG_VBF_DEC][Settings::fL1][Settings::qqZZ],"qqZZ",kGreen,1,
									 "D_{bkg}^{VBF+dec}",
									 "fL1", 0.25, 3);
	
	PlotInM4lSlices_1SIG1BKG("DVBFDEC",
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fL1][Settings::VBF],"VBF",kRed,1,
									 histos_2D[Settings::on_VBF_2j_tagged][Settings::D_VBF_DEC][Settings::fL1][Settings::VBF_0L1],"VBF f_{#Lambda_{1}}=1",kRed,2,
									 "D_{#Lambda_{1}}^{VBF+dec}",
									 "fL1", 0.25, 3);
}
