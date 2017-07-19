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

using namespace std;

int main( int argc, char *argv[] )
{
   float lumi = 38.5;
   
   TFile *f = new TFile("EffVsCut.root", "recreate");
   
   
   TString folder_name_old = "/afs/cern.ch/work/t/tsculac/Moriond_2017/CMSSW_8_0_21/src/HZZ4l-plotter/Moriond_2017/";
   TString folder_name_new = "root://lxcms03//data3/Higgs/170623/";
   TString file_name       = "/ZZ4lAnalysis.root";
   
   float oldeff_Djj_VBF;
   float oldeff_Djj_ggH;
   float oldeff_DVH_ggH;
   float oldeff_DVH_WH;
   float oldeff_DVH_ZH;

   TString VBF125_old    = folder_name_old + "VBFH125" + file_name;
   TString gg125_old     = folder_name_old + "ggH125" + file_name;
   TString Wplus125_old  = folder_name_old + "WplusH125" + file_name;
   TString Wminus125_old = folder_name_old + "WminusH125" + file_name;
   TString Z125_old      = folder_name_old + "ZH125" + file_name;
   
   TH1F     *h_VBF2j_old = new TH1F("h_VBF2j_old", "h_VBF2j_old", 1000, 0, 1);
   TH1F     *h_VH_old    = new TH1F("h_VH_old", "      h_VH_old", 1000, 0, 1);
   
   
   Analyzer *_VBF125_old    = new Analyzer(VBF125_old, lumi);    _VBF125_old->LoopForEff(h_VBF2j_old,h_VH_old);
   h_VBF2j_old->SetName("DVBF2j_VBF_old");
   f->cd();
   h_VBF2j_old->Write();
   h_VH_old->SetName("DVH_VBF_old");
   h_VH_old->Write();
   oldeff_Djj_VBF=h_VBF2j_old->Integral(500,1000)/h_VBF2j_old->Integral();
   
   
   h_VBF2j_old->Reset();
   h_VH_old->Reset();
   Analyzer *_gg125_old     = new Analyzer(gg125_old, lumi);     _gg125_old->LoopForEff(h_VBF2j_old,h_VH_old);
   h_VBF2j_old->SetName("DVBF2j_ggH_old");
   f->cd();
   h_VBF2j_old->Write();
   h_VH_old->SetName("DVH_ggH_old");
   h_VH_old->Write();
   oldeff_Djj_ggH=h_VBF2j_old->Integral(500,1000)/h_VBF2j_old->Integral();
   oldeff_DVH_ggH=h_VH_old->Integral(500,1000)/h_VH_old->Integral();
   
   h_VBF2j_old->Reset();
   h_VH_old->Reset();
   Analyzer *_Wplus125_old  = new Analyzer(Wplus125_old, lumi);  _Wplus125_old->LoopForEff(h_VBF2j_old,h_VH_old);
   Analyzer *_Wminus125_old = new Analyzer(Wminus125_old, lumi); _Wminus125_old->LoopForEff(h_VBF2j_old,h_VH_old);
   h_VBF2j_old->SetName("DVBF2j_WH_old");
   f->cd();
   h_VBF2j_old->Write();
   h_VH_old->SetName("DVH_WH_old");
   h_VH_old->Write();
   oldeff_DVH_WH=h_VH_old->Integral(500,1000)/h_VH_old->Integral();
   
   
   h_VBF2j_old->Reset();
   h_VH_old->Reset();
   Analyzer *_Z125_old      = new Analyzer(Z125_old, lumi);      _Z125_old->LoopForEff(h_VBF2j_old,h_VH_old);
   h_VBF2j_old->SetName("DVBF2j_ZH_old");
   f->cd();
   h_VBF2j_old->Write();
   h_VH_old->SetName("DVH_ZH_old");
   h_VH_old->Write();
   oldeff_DVH_ZH=h_VH_old->Integral(500,1000)/h_VH_old->Integral();
   
//   cout << oldeff_Djj_VBF << endl;
//   cout << oldeff_Djj_ggH << endl;
//   cout << oldeff_DVH_ggH << endl;
//   cout << oldeff_DVH_WH  << endl;
//   cout << oldeff_DVH_ZH  << endl;
   
   
   TString VBF125_new    = folder_name_new + "VBFH125" + file_name;
   TString gg125_new     = folder_name_new + "ggH125" + file_name;
   TString Wplus125_new  = folder_name_new + "WplusH125" + file_name;
   TString Wminus125_new = folder_name_new + "WminusH125" + file_name;
   TString Z125_new      = folder_name_new + "ZH125" + file_name;
   
   TH1F     *h_VBF2j_new = new TH1F("h_VBF2j_new", "h_VBF2j_new", 1000, 0, 1);
   TH1F     *h_VH_new    = new TH1F("h_VH_new", "      h_VH_new", 1000, 0, 1);
   
   Analyzer *_VBF125_new    = new Analyzer(VBF125_new, lumi);    _VBF125_new->LoopForEff(h_VBF2j_new,h_VH_new);
   h_VBF2j_new->SetName("DVBF2j_VBF_new");
   f->cd();
   h_VBF2j_new->Write();
   h_VH_new->SetName("DVH_VBF_new");
   h_VH_new->Write();
   
   
   TCanvas *c1;
   TGraphErrors *gr_Djj_VBF,*gr_Djj_ggH,*gr_DVH_WH,*gr_DVH_ZH,*gr_DVH_ggH;
   c1 = new TCanvas("c1","c1",900,900);
   
   int nbins = 1000;
   Double_t x[nbins];
   Double_t y[nbins];
   Double_t y2[nbins];
   Double_t ex[nbins];
   Double_t ey[nbins];
   
   for( int i = 1; i <= nbins; i++)
   {
      x[i-1] = i/1000.;
      y[i-1] = h_VBF2j_new->Integral(i,1000)/h_VBF2j_new->Integral();
      ex[i-1] = 0;
      ey[i-1] = 0;
   }


   gr_Djj_VBF = new TGraphErrors(nbins,x,y,ex,ey);
   gr_Djj_VBF->SetTitle("TGraphErrors Example");
   gr_Djj_VBF->SetMarkerColor(kRed);
   gr_Djj_VBF->SetMarkerStyle(1);
   
   h_VBF2j_new->Reset();
   h_VH_new->Reset();
   Analyzer *_gg125_new     = new Analyzer(gg125_new, lumi);     _gg125_new->LoopForEff(h_VBF2j_new,h_VH_new);
   h_VBF2j_new->SetName("DVBF2j_ggH_new");
   f->cd();
   h_VBF2j_new->Write();
   h_VH_new->SetName("DVH_ggH_new");
   h_VH_new->Write();
   
   for( int i = 1; i <= nbins; i++)
   {
      x[i-1] = i/1000.;
      y[i-1] = h_VBF2j_new->Integral(i,1000)/h_VBF2j_new->Integral();
      y2[i-1] = h_VH_new->Integral(i,1000)/h_VH_new->Integral();
      ex[i-1] = 0;
      ey[i-1] = 0;
   }
   gr_Djj_ggH = new TGraphErrors(nbins,x,y,ex,ey);
   gr_Djj_ggH->SetTitle("TGraphErrors Example");
   gr_Djj_ggH->SetMarkerColor(kBlack);
   gr_Djj_ggH->SetMarkerStyle(1);
   
   gr_DVH_ggH = new TGraphErrors(nbins,x,y2,ex,ey);
   gr_DVH_ggH->SetTitle("TGraphErrors Example");
   gr_DVH_ggH->SetMarkerColor(kBlack);
   gr_DVH_ggH->SetMarkerStyle(1);
   
   
   h_VBF2j_new->Reset();
   h_VH_new->Reset();
   Analyzer *_Wplus125_new  = new Analyzer(Wplus125_new, lumi);  _Wplus125_new->LoopForEff(h_VBF2j_new,h_VH_new);
   Analyzer *_Wminus125_new = new Analyzer(Wminus125_new, lumi); _Wminus125_new->LoopForEff(h_VBF2j_new,h_VH_new);
   h_VBF2j_new->SetName("DVBF2j_WH_new");
   f->cd();
   h_VBF2j_new->Write();
   h_VH_new->SetName("DVH_WH_new");
   h_VH_new->Write();
   
   for( int i = 1; i <= nbins; i++)
   {
      x[i-1] = i/1000.;
      y[i-1] = h_VH_new->Integral(i,1000)/h_VH_new->Integral();
      ex[i-1] = 0;
      ey[i-1] = 0;
   }
   gr_DVH_WH = new TGraphErrors(nbins,x,y,ex,ey);
   gr_DVH_WH->SetTitle("TGraphErrors Example");
   gr_DVH_WH->SetMarkerColor(kBlue);
   gr_DVH_WH->SetMarkerStyle(1);
   
   
   h_VBF2j_new->Reset();
   h_VH_new->Reset();
   Analyzer *_Z125_new      = new Analyzer(Z125_new, lumi);      _Z125_new->LoopForEff(h_VBF2j_new,h_VH_new);
   h_VBF2j_new->SetName("DVBF2j_ZH_new");
   f->cd();
   h_VBF2j_new->Write();
   h_VH_new->SetName("DVH_ZH_new");
   h_VH_new->Write();
   
   for( int i = 1; i <= nbins; i++)
   {
      x[i-1] = i/1000.;
      y[i-1] = h_VH_new->Integral(i,1000)/h_VH_new->Integral();
      ex[i-1] = 0;
      ey[i-1] = 0;
   }
   gr_DVH_ZH = new TGraphErrors(nbins,x,y,ex,ey);
   gr_DVH_ZH->SetTitle("TGraphErrors Example");
   gr_DVH_ZH->SetMarkerColor(kYellow);
   gr_DVH_ZH->SetMarkerStyle(1);
   
   
   c1->cd();
   TMultiGraph *mg = new TMultiGraph();
   gr_Djj_VBF->SetTitle("VBF");
   mg->Add(gr_Djj_VBF);
   gr_Djj_ggH->SetTitle("ggH");
   mg->Add(gr_Djj_ggH);
   mg->Draw("apl");
   mg->GetXaxis()->SetTitle("Cut value");
   mg->GetYaxis()->SetTitle("D_{2jets}^{VBF}   eff");
   TLegend *leg = new TLegend(0.65, 0.75, 0.90, 0.90);
   leg->AddEntry(gr_Djj_VBF,"VBF","pl");
   leg->AddEntry(gr_Djj_ggH,"ggH","pl");
   leg->Draw();
   
   TLine *line1 = new TLine(0,oldeff_Djj_VBF,1,oldeff_Djj_VBF);
   line1->SetLineColor(kRed);
   line1->SetLineStyle(2);
   line1->Draw();
   TLine *line2 = new TLine(0,oldeff_Djj_ggH,1,oldeff_Djj_ggH);
   line2->SetLineColor(kBlack);
   line2->SetLineStyle(2);
   line2->Draw();
   c1->SaveAs("ControlPlots/DVBFVsCut.pdf");
   
   
   
   c1->Clear();
   c1->cd();
   TMultiGraph *mg2 = new TMultiGraph();
   gr_DVH_ZH->SetTitle("ZH");
   mg2->Add(gr_DVH_ZH);
   gr_DVH_WH->SetTitle("WH");
   mg2->Add(gr_DVH_WH);
   gr_DVH_ggH->SetTitle("ggH");
   mg2->Add(gr_DVH_ggH);
   mg2->Draw("apl");
   mg2->GetXaxis()->SetTitle("Cut value");
   mg2->GetYaxis()->SetTitle("D_{2jets}^{VH}   eff");
   TLegend *leg2 = new TLegend(0.65, 0.75, 0.90, 0.90);
   leg2->AddEntry(gr_DVH_ggH,"ggH","pl");
   leg2->AddEntry(gr_DVH_WH,"WH","pl");
   leg2->AddEntry(gr_DVH_ZH,"ZH","pl");
   leg2->Draw();
   
   TLine *line3 = new TLine(0,oldeff_DVH_ggH,1,oldeff_DVH_ggH);
   line3->SetLineColor(kBlack);
   line3->SetLineStyle(2);
   line3->Draw();
   TLine *line4 = new TLine(0,oldeff_DVH_WH,1,oldeff_DVH_WH);
   line4->SetLineColor(kBlue);
   line4->SetLineStyle(2);
   line4->Draw();
   TLine *line5 = new TLine(0,oldeff_DVH_ZH,1,oldeff_DVH_ZH);
   line5->SetLineColor(kYellow);
   line5->SetLineStyle(2);
   line5->Draw();
   c1->SaveAs("ControlPlots/DVHVsCut.pdf");

   
   
   f->Close();
   delete f;
   
}
