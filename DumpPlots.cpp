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


// My own files
#include "Analyzer.h"
#include "Functions.h"

using namespace std;

int main( int argc, char *argv[] )
{
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
   mg->SetMaximum(1.09);
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
   c1->SaveAs("ControlPlots/DVBFJJ_comb.pdf");
   
   
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
   mg2->SetMaximum(0.59);
   mg2->Draw("apl");
   mg2->GetXaxis()->SetTitle("M_{4l} (GeV)");
   mg2->GetYaxis()->SetTitle("D_{2jets}^{VH}   eff");
   
   TLegend *leg2 = new TLegend(0.45, 0.65, 0.90, 0.90);
   leg2->AddEntry(VBF_DVH_tgraph,"VBF","pl");
   leg2->AddEntry(ggH_DVH_tgraph,"ggH","pl");
   leg2->AddEntry(WH_DVH_tgraph,"WH","pl");
   leg2->AddEntry(ZH_DVH_tgraph,"ZH","pl");
   leg2->AddEntry(qqZZ_DVH_tgraph,"qqZZ","pl");
   leg2->Draw();
   c1->SaveAs("ControlPlots/DVH_comb.pdf");
   
   
   tgraph_file->Close();
   
   TFile* th2f_file = TFile::Open("DVsM4l.root");
   TH2F *DVBF2jVsM4l_VBF,*DVHVsM4l_ZH,*DVHVsM4l_WH;
   DVBF2jVsM4l_VBF = (TH2F*)th2f_file->Get("DVBF2jVsM4l_VBF");
   DVHVsM4l_ZH     = (TH2F*)th2f_file->Get("DVHVsM4l_ZH");
   DVHVsM4l_WH     = (TH2F*)th2f_file->Get("DVHVsM4l_WH");
   
   Int_t   m4l_bins     = 18;
   Double_t m4l_slices[] = {110,120,130,140,150,160,170,180,190,200,250,300,400,500,600,700,800,900,1000};
   
   Int_t   m4l_bins2     = 10;
   Double_t m4l_slices2[] = {110,120,130,140,150,160,170,180,190,200,250};
   
   TH1D *h_temp;
   TH1 *frame;
   for ( int i = 0; i < m4l_bins ; i++ )
   {
      c1->Clear();
      frame = new TH1F(("a"+to_string(i)).c_str(),"",100,0,1);
      frame->SetMaximum(0.15);
      frame->Draw();
      h_temp = DVBF2jVsM4l_VBF->ProjectionY((to_string(i)).c_str(),i,i+1);
      frame->SetTitle((to_string(int(m4l_slices[i]))+" - "+to_string(int(m4l_slices[i+1]))).c_str());
      h_temp->DrawNormalized("HIST SAME");
      frame->GetXaxis()->SetTitle("D_{2jets}^{VBF}");
      gStyle->SetOptStat(0);
      if( i < 10 ) c1->SaveAs(("Animations/Djj_0"+to_string(i)+".gif").c_str());
      else c1->SaveAs(("Animations/Djj_"+to_string(i)+".gif").c_str());
      
   }
   
   for ( int i = 0; i < m4l_bins2 ; i++ )
   {
      c1->Clear();
      frame = new TH1F(("b"+to_string(i)).c_str(),"",100,0,1);
      frame->SetMaximum(0.06);
      frame->Draw();
      h_temp = DVHVsM4l_ZH->ProjectionY((to_string(i)).c_str(),i,i+1);
      frame->SetTitle((to_string(int(m4l_slices2[i]))+" - "+to_string(int(m4l_slices2[i+1]))).c_str());
      h_temp->DrawNormalized("HIST SAME");
      frame->GetXaxis()->SetTitle("D_{2jets}^{VH}");
      gStyle->SetOptStat(0);
      if( i < 10 ) c1->SaveAs(("Animations/DVH_ZH_0"+to_string(i)+".gif").c_str());
      else c1->SaveAs(("Animations/DVH_ZH_"+to_string(i)+".gif").c_str());
      
   }
   
   for ( int i = 0; i < m4l_bins2 ; i++ )
   {
      c1->Clear();
      frame = new TH1F(("c"+to_string(i)).c_str(),"",100,0,1);
      frame->SetMaximum(0.06);
      frame->Draw();
      h_temp = DVHVsM4l_WH->ProjectionY((to_string(i)).c_str(),i,i+1);
      frame->SetTitle((to_string(int(m4l_slices2[i]))+" - "+to_string(int(m4l_slices2[i+1]))).c_str());
      h_temp->DrawNormalized("HIST SAME");
      gStyle->SetOptStat(0);
      frame->GetXaxis()->SetTitle("D_{2jets}^{VH}");
      if ( i < 10) c1->SaveAs(("Animations/DVH_WH_0"+to_string(i)+".gif").c_str());
      else c1->SaveAs(("Animations/DVH_WH_"+to_string(i)+".gif").c_str());
      
   }
   
   
}
