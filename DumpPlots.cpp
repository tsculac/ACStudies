// C++
#include <iostream>
#include <fstream>
#include <string>

// ROOT
#include "TApplication.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLine.h"


// My own files
#include "Analyzer.h"
#include "Functions.h"
#include "Settings.h"

using namespace std;

int main( int argc, char *argv[] )
{	
	bool plotDBKGcheck = false;
	bool plotVBF2j = true;
	bool plotVH = true;
	bool plotDBKG = true;
	bool plotD0M = true;
	bool plotD0P = true;
	bool plotDL1 = true;
	bool plotDL1Zgs = false;
	
	
   TFile* tgraph_file = TFile::Open("EffVsM4l.root");
   
   TGraphErrors *VBF_Djj_tgraph,*VBF_DVH_tgraph, *ggH_Djj_tgraph,*ggH_DVH_tgraph, *WH_Djj_tgraph,*WH_DVH_tgraph, *ZH_Djj_tgraph,*ZH_DVH_tgraph, *qqZZ_Djj_tgraph,*qqZZ_DVH_tgraph;
   
   VBF_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("VBF_Djj_tgraph");
   ggH_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("ggH_Djj_tgraph");
   WH_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("WH_Djj_tgraph");
   ZH_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("ZH_Djj_tgraph");
   qqZZ_Djj_tgraph = (TGraphErrors*)tgraph_file->Get("qqZZ_Djj_tgraph");
   
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
   c1 = new TCanvas("c1","c1",900,900);
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
   c1->SaveAs("ControlPlots/DVBFJJ_comb_2jEvents.pdf");
   c1->SaveAs("ControlPlots/DVBFJJ_comb_2jEvents.png");
   
   
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
   c1->SaveAs("ControlPlots/DVH_comb_2jEvents.pdf");
   c1->SaveAs("ControlPlots/DVH_comb_2jEvents.png");
   
   
   tgraph_file->Close();
   
   TFile* th2f_file = TFile::Open("DVsM4l.root");
   Functions *functions = new Functions();
   TH2F *DVBF2jVsM4l_VBF,*DVBF2jVsM4l_ggH,*DVHVsM4l_ZH,*DVHVsM4l_WH,*DVHVsM4l_ggH,*DBKGDEC_ggH,*DBKGDEC_qqZZ,*D0MDECVsM4l_0MH,*D0MDECVsM4l_ggH,*D0PDECVsM4l_0PH,*D0PDECVsM4l_ggH,*DL1DECVsM4l_0PL1,*DL1DECVsM4l_ggH,*DL1ZgsDECVsM4l_0PL1,*DL1ZgsDECVsM4l_ggH;
   
   DVBF2jVsM4l_VBF     = (TH2F*)th2f_file->Get("DVBF2jVsM4l_VBF");
   DVBF2jVsM4l_ggH     = (TH2F*)th2f_file->Get("DVBF2jVsM4l_ggH");
   DVHVsM4l_ZH         = (TH2F*)th2f_file->Get("DVHVsM4l_ZH");
   DVHVsM4l_WH         = (TH2F*)th2f_file->Get("DVHVsM4l_WH");
   DVHVsM4l_ggH        = (TH2F*)th2f_file->Get("DVHVsM4l_ggH");
   DBKGDEC_ggH         = (TH2F*)th2f_file->Get("DBKGDECVsM4l_ggH");
   DBKGDEC_qqZZ        = (TH2F*)th2f_file->Get("DBKGDECVsM4l_qqZZ");
   D0MDECVsM4l_0MH     = (TH2F*)th2f_file->Get("D0MDECVsM4l_0MH");
   D0MDECVsM4l_ggH     = (TH2F*)th2f_file->Get("D0MDECVsM4l_ggH");
   D0PDECVsM4l_0PH     = (TH2F*)th2f_file->Get("D0PDECVsM4l_0PH");
   D0PDECVsM4l_ggH     = (TH2F*)th2f_file->Get("D0PDECVsM4l_ggH");
	DL1DECVsM4l_0PL1    = (TH2F*)th2f_file->Get("DL1DECVsM4l_0PL1");
   DL1ZgsDECVsM4l_0PL1 = (TH2F*)th2f_file->Get("DL1ZgsDECVsM4l_0PL1");
   DL1DECVsM4l_ggH     = (TH2F*)th2f_file->Get("DL1DECVsM4l_ggH");
   DL1ZgsDECVsM4l_ggH  = (TH2F*)th2f_file->Get("DL1ZgsDECVsM4l_ggH");
   
   if(plotDBKG || plotDBKGcheck) DBKGDEC_ggH->RebinY(5);
   if(plotDBKG || plotDBKGcheck) DBKGDEC_qqZZ->RebinY(5);
   if(plotD0M) D0MDECVsM4l_0MH->RebinY(5);
   if(plotD0M) D0MDECVsM4l_ggH->RebinY(5);
   if(plotD0P) D0PDECVsM4l_0PH->RebinY(5);
   if(plotD0P) D0PDECVsM4l_ggH->RebinY(5);
   if(plotDL1) DL1DECVsM4l_0PL1->RebinY(5);
   if(plotDL1) DL1DECVsM4l_ggH->RebinY(5);
   if(plotDL1Zgs) DL1ZgsDECVsM4l_0PL1->RebinY(5);
   if(plotDL1Zgs) DL1ZgsDECVsM4l_ggH->RebinY(5);
   
   
   functions->ConditionalNormalisation(DBKGDEC_ggH);
   functions->ConditionalNormalisation(DBKGDEC_qqZZ);
   c1->Clear();
   c1->cd();
   DBKGDEC_ggH->Draw("COLZ");
   c1->SaveAs("ControlPlots/DBKGDEC_ggH.pdf");
   c1->Clear();
   c1->cd();
   DBKGDEC_qqZZ->Draw("COLZ");
   c1->SaveAs("ControlPlots/DBKGDEC_qqZZ.pdf");
   
   TH1D *h_os_ggH, *h_os_qqZZ;
   h_os_ggH  = DBKGDEC_ggH->ProjectionY("DBKGDEC_ggH",0,3);
   h_os_qqZZ = DBKGDEC_qqZZ->ProjectionY("DBKGDEC_qqZZ",0,3);
   c1->Clear();
   c1->cd();
   h_os_ggH->Draw("HIST");
   h_os_qqZZ->Draw("HIST SAME");
   c1->SaveAs("ControlPlots/DBKGDEC_SIGvsBKG.pdf");
   
   
   Int_t   m4l_bins_check     = 23;
   Double_t m4l_slices_check[] = {80,90,100,110,120,130,140,150,160,170,180,190,200,250,300,400,500,600,700,800,900,1000,2000,3000};
   
   Int_t   m4l_bins     = 18;
   Double_t m4l_slices[] = {110,140,150,160,170,180,190,200,250,300,400,500,600,700,800,900,1000,2000,3000};
   
   Int_t   m4l_bins2     = 10;
   Double_t m4l_slices2[] = {110,120,130,140,150,160,170,180,190,200,250};
   
   Int_t   m4l_bins3     = 13;
   Double_t m4l_slices3[] = {110,140,180,220,300,400,500,600,700,800,1500,2000,3000,4000};
   
   TH1D *h_temp,*b_temp;
   TH1 *frame;
	TLine *tmp_line = new TLine(1,1,1,1);//hack for TLegend
   
   if(plotDBKGcheck)
   {
      for ( int i = 0; i < m4l_bins_check ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("h"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.30);
         frame->Draw();
         h_temp = DBKGDEC_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices_check[i]))+" - "+to_string(int(m4l_slices_check[i+1]))).c_str());
         h_temp->SetLineColor(kBlack);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = DBKGDEC_qqZZ->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kGreen);
         b_temp->SetLineStyle(1);
         b_temp->DrawNormalized("HIST SAME");
         
         frame->GetXaxis()->SetTitle("D_{bkg}^{dec}");
			frame->GetYaxis()->SetTitle("a.u.");
         gStyle->SetOptStat(0);
         
         TLegend *legD = new TLegend(0.65, 0.75, 0.90, 0.90);
         legD->AddEntry(h_temp,"ggH","l");
         legD->AddEntry(b_temp,"qqZZ","l");
         legD->Draw();
         
         if( i < 10 ) c1->SaveAs(("Animations/check_DBKG_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/check_DBKG_"+to_string(i)+".png").c_str());
         
      }//for checks
   }
   
   if(plotVBF2j)
   {
      for ( int i = 0; i < m4l_bins ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("a"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.15);
         frame->Draw();
         h_temp = DVBF2jVsM4l_VBF->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices[i]))+" - "+to_string(int(m4l_slices[i+1]))).c_str());
         h_temp->SetLineColor(kRed);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = DVBF2jVsM4l_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kBlack);
         b_temp->DrawNormalized("HIST SAME");
         
         frame->GetXaxis()->SetTitle("D_{2jets}^{VBF}");
			frame->GetYaxis()->SetTitle("a.u.");
         gStyle->SetOptStat(0);
			
			TLegend *legVBF = new TLegend(0.65, 0.75, 0.90, 0.90);
			tmp_line->SetLineColor(kRed);
			tmp_line->SetLineStyle(1);
			legVBF->AddEntry(tmp_line,"VBF","l");//I have no idea why this works?
			legVBF->AddEntry(b_temp,"ggH","l");
			legVBF->Draw();
			
         if( i < 10 ) c1->SaveAs(("Animations/Djj_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/Djj_"+to_string(i)+".png").c_str());
         
      }
   }

   
   if(plotVH)
   {
      for ( int i = 0; i < m4l_bins2 ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("b"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.12);
         frame->Draw();
         h_temp = DVHVsM4l_ZH->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices2[i]))+" - "+to_string(int(m4l_slices2[i+1]))).c_str());
         h_temp->SetLineColor(kYellow);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = DVHVsM4l_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kBlack);
         b_temp->DrawNormalized("HIST SAME");
         
         frame->GetXaxis()->SetTitle("D_{2jets}^{VH}");
			frame->GetYaxis()->SetTitle("a.u.");
         gStyle->SetOptStat(0);
			
			TLegend *legZH = new TLegend(0.65, 0.75, 0.90, 0.90);
			tmp_line->SetLineColor(kYellow);
			tmp_line->SetLineStyle(1);
			legZH->AddEntry(tmp_line,"ZH","l");//I have no idea why this works?
			legZH->AddEntry(b_temp,"ggH","l");
			legZH->Draw();
			
         if( i < 10 ) c1->SaveAs(("Animations/DVH_ZH_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/DVH_ZH_"+to_string(i)+".png").c_str());
         
      }
   }

   
   if(plotVH)
   {
      for ( int i = 0; i < m4l_bins2 ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("c"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.12);
         frame->Draw();
         h_temp = DVHVsM4l_WH->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices2[i]))+" - "+to_string(int(m4l_slices2[i+1]))).c_str());
         h_temp->SetLineColor(kBlue);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = DVHVsM4l_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kBlack);
         b_temp->DrawNormalized("HIST SAME");
         
         gStyle->SetOptStat(0);
         frame->GetXaxis()->SetTitle("D_{2jets}^{VH}");
			frame->GetYaxis()->SetTitle("a.u.");
			
			TLegend *legWH = new TLegend(0.65, 0.75, 0.90, 0.90);
			tmp_line->SetLineColor(kBlue);
			tmp_line->SetLineStyle(1);
			legWH->AddEntry(tmp_line,"WH","l");//I have no idea why this works?
			legWH->AddEntry(b_temp,"ggH","l");
			legWH->Draw();
			
         if ( i < 10) c1->SaveAs(("Animations/DVH_WH_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/DVH_WH_"+to_string(i)+".png").c_str());
         
      }
   }

   if(plotDBKG)
   {
      for ( int i = 0; i < m4l_bins3 ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("h"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.30);
         frame->Draw();
         h_temp = DBKGDEC_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices3[i]))+" - "+to_string(int(m4l_slices3[i+1]))).c_str());
         h_temp->SetLineColor(kBlack);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = DBKGDEC_qqZZ->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kGreen);
         b_temp->SetLineStyle(1);
         b_temp->DrawNormalized("HIST SAME");
         
         frame->GetXaxis()->SetTitle("D_{bkg}^{dec}");
			frame->GetYaxis()->SetTitle("a.u.");
         gStyle->SetOptStat(0);
         
         TLegend *legD = new TLegend(0.65, 0.75, 0.90, 0.90);
         legD->AddEntry("h_temp","ggH","l");//I have no idea why this works?
         legD->AddEntry(b_temp,"qqZZ","l");
         legD->Draw();
         
         if( i < 10 ) c1->SaveAs(("Animations/DBKG_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/DBKG_"+to_string(i)+".png").c_str());
         
      }
      
   }
   
   if (plotD0M)
   {
      for ( int i = 0; i < m4l_bins3 ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("d"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.15);
         frame->Draw();
         h_temp = D0MDECVsM4l_0MH->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices3[i]))+" - "+to_string(int(m4l_slices3[i+1]))).c_str());
         h_temp->SetLineColor(kBlack);
         h_temp->SetLineStyle(2);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = D0MDECVsM4l_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kBlack);
         b_temp->SetLineStyle(1);
         b_temp->DrawNormalized("HIST SAME");
         
         frame->GetXaxis()->SetTitle("D_{0-}^{dec}");
			frame->GetYaxis()->SetTitle("a.u.");
         gStyle->SetOptStat(0);
         TLegend *leg0M = new TLegend(0.65, 0.75, 0.90, 0.90);
			tmp_line->SetLineColor(kBlack);
			tmp_line->SetLineStyle(2);
			leg0M->AddEntry(tmp_line,"f_{a3} = 1","l");
			leg0M->AddEntry(b_temp,"SM ggH","l");
         leg0M->Draw();
         if( i < 10 ) c1->SaveAs(("Animations/D0M_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/D0M_"+to_string(i)+".png").c_str());
         
      }

   }
   
   if(plotD0P)
   {
      for ( int i = 0; i < m4l_bins3 ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("e"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.26);
         frame->Draw();
         h_temp = D0PDECVsM4l_0PH->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices3[i]))+" - "+to_string(int(m4l_slices3[i+1]))).c_str());
         h_temp->SetLineColor(kBlack);
         h_temp->SetLineStyle(2);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = D0PDECVsM4l_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kBlack);
         b_temp->SetLineStyle(1);
         b_temp->DrawNormalized("HIST SAME");
         
         frame->GetXaxis()->SetTitle("D_{0h+}^{dec}");
			frame->GetYaxis()->SetTitle("a.u.");
         gStyle->SetOptStat(0);
         TLegend *leg0P = new TLegend(0.65, 0.75, 0.90, 0.90);
			tmp_line->SetLineColor(kBlack);
			tmp_line->SetLineStyle(2);
         leg0P->AddEntry(b_temp,"SM ggH","l");
         leg0P->AddEntry(tmp_line,"f_{a2} = 1","l");
         leg0P->Draw();
         if( i < 10 ) c1->SaveAs(("Animations/D0P_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/D0P_"+to_string(i)+".png").c_str());
         
      }
   }

   if(plotDL1)
   {
      for ( int i = 0; i < m4l_bins3 ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("f"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.66);
         frame->Draw();
         h_temp = DL1DECVsM4l_0PL1->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices3[i]))+" - "+to_string(int(m4l_slices3[i+1]))).c_str());
         h_temp->SetLineColor(kBlack);
         h_temp->SetLineStyle(2);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = DL1DECVsM4l_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kBlack);
         b_temp->SetLineStyle(1);
         b_temp->DrawNormalized("HIST SAME");
         
         frame->GetXaxis()->SetTitle("D_{#Lambda1}^{dec}");
			frame->GetYaxis()->SetTitle("a.u.");
         gStyle->SetOptStat(0);
         TLegend *leg0P = new TLegend(0.65, 0.75, 0.90, 0.90);
			tmp_line->SetLineColor(kBlack);
			tmp_line->SetLineStyle(2);
         leg0P->AddEntry(b_temp,"SM ggH","l");
         leg0P->AddEntry(tmp_line,"f_{#Lambda 1} = 1","l");
         leg0P->Draw();
         if( i < 10 ) c1->SaveAs(("Animations/DL1_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/DL1_"+to_string(i)+".png").c_str());
         
      }
   }

   if(plotDL1Zgs)
   {
      for ( int i = 0; i < m4l_bins3 ; i++ )
      {
         c1->Clear();
         frame = new TH1F(("g"+to_string(i)).c_str(),"",100,0,1);
         frame->SetMaximum(0.56);
         frame->Draw();
         h_temp = DL1ZgsDECVsM4l_0PL1->ProjectionY((to_string(i)).c_str(),i,i+1);
         frame->SetTitle((to_string(int(m4l_slices3[i]))+" - "+to_string(int(m4l_slices3[i+1]))).c_str());
         h_temp->SetLineColor(kBlack);
         h_temp->SetLineStyle(2);
         h_temp->DrawNormalized("HIST SAME");
         
         b_temp = DL1ZgsDECVsM4l_ggH->ProjectionY((to_string(i)).c_str(),i,i+1);
         b_temp->SetLineColor(kBlack);
         b_temp->SetLineStyle(1);
         b_temp->DrawNormalized("HIST SAME");
         
         frame->GetXaxis()->SetTitle("D_{#Lambda1}^{Z #gamma^{*},dec}");
			frame->GetYaxis()->SetTitle("a.u.");
         gStyle->SetOptStat(0);
         TLegend *leg0P = new TLegend(0.65, 0.75, 0.90, 0.90);
			tmp_line->SetLineColor(kBlack);
			tmp_line->SetLineStyle(2);
         leg0P->AddEntry(b_temp,"SM ggH","l");
         leg0P->AddEntry(tmp_line,"f_{#Lambda1} = 1","l");
         leg0P->Draw();
         if( i < 10 ) c1->SaveAs(("Animations/DL1Zgs_0"+to_string(i)+".png").c_str());
         else c1->SaveAs(("Animations/DL1Zgs_"+to_string(i)+".png").c_str());
         
      }
   }

}
