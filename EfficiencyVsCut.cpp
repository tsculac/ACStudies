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
   float lumi = 38.5;
   int nbins = 10000;
   bool shiftWP = true;
   
   TFile *f = new TFile("EffVsCut.root", "recreate");
   TH1F *histos_1D_old[Settings::num_of_1D_hist_names];
   
   
   TString folder_name_old = "/afs/cern.ch/work/t/tsculac/Moriond_2017/CMSSW_8_0_21/src/HZZ4l-plotter/Moriond_2017/";
   TString folder_name_new = "root://lxcms03//data3/Higgs/170623/";
   TString file_name       = "/ZZ4lAnalysis.root";
   
   float oldeff_Djj_VBF;
   float oldeff_Djj_ggH;
   float oldeff_DVH_ggH;
   float oldeff_DVH_WH;
   float oldeff_DVH_ZH;
   float oldeff_Djj_qqZZ;
   float oldeff_DVH_qqZZ;

   TString VBF125_old    = folder_name_old + "VBFH125" + file_name;
   TString gg125_old     = folder_name_old + "ggH125" + file_name;
   TString Wplus125_old  = folder_name_old + "WplusH125" + file_name;
   TString Wminus125_old = folder_name_old + "WminusH125" + file_name;
   TString Z125_old      = folder_name_old + "ZH125" + file_name;
   TString qqZZ_old      = folder_name_old + "ZZTo4l" + file_name;
   
   histos_1D_old[Settings::M4l_DVBF2j] = new TH1F("h_VBF2j_old", "h_VBF2j_old", nbins, 0, 1);
   histos_1D_old[Settings::M4l_DVH]    = new TH1F("h_VH_old", "h_VH_old", nbins, 0, 1);
   
   
   Analyzer *_VBF125_old    = new Analyzer(VBF125_old, lumi);    _VBF125_old->LoopForEff( shiftWP,histos_1D_old);
   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_VBF_old");
   f->cd();
   histos_1D_old[Settings::M4l_DVBF2j]->Write();
   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_VBF_old");
   histos_1D_old[Settings::M4l_DVH]->Write();
   oldeff_Djj_VBF=histos_1D_old[Settings::M4l_DVBF2j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF2j]->Integral();
   
   
   
   histos_1D_old[Settings::M4l_DVBF2j]->Reset();
   histos_1D_old[Settings::M4l_DVH]->Reset();
   Analyzer *_gg125_old     = new Analyzer(gg125_old, lumi);     _gg125_old->LoopForEff( shiftWP,histos_1D_old);
   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_ggH_old");
   f->cd();
   histos_1D_old[Settings::M4l_DVBF2j]->Write();
   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_ggH_old");
   histos_1D_old[Settings::M4l_DVH]->Write();
   oldeff_Djj_ggH=histos_1D_old[Settings::M4l_DVBF2j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF2j]->Integral();
   oldeff_DVH_ggH=histos_1D_old[Settings::M4l_DVH]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVH]->Integral();
   
   histos_1D_old[Settings::M4l_DVBF2j]->Reset();
   histos_1D_old[Settings::M4l_DVH]->Reset();
   Analyzer *_Wplus125_old  = new Analyzer(Wplus125_old, lumi);  _Wplus125_old->LoopForEff( shiftWP,histos_1D_old);
   Analyzer *_Wminus125_old = new Analyzer(Wminus125_old, lumi); _Wminus125_old->LoopForEff( shiftWP,histos_1D_old);
   Analyzer *_Z125_old      = new Analyzer(Z125_old, lumi);      _Z125_old->LoopForEff( shiftWP,histos_1D_old);
   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_WH_old");
   f->cd();
   histos_1D_old[Settings::M4l_DVBF2j]->Write();
   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_WH_old");
   histos_1D_old[Settings::M4l_DVH]->Write();
   oldeff_DVH_WH=histos_1D_old[Settings::M4l_DVH]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVH]->Integral();
   
   
//   histos_1D_old[Settings::M4l_DVBF2j]->Reset();
//   histos_1D_old[Settings::M4l_DVH]->Reset();
//   Analyzer *_Z125_old      = new Analyzer(Z125_old, lumi);      _Z125_old->LoopForEff( shiftWP,histos_1D_old);
//   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_ZH_old");
//   f->cd();
//   histos_1D_old[Settings::M4l_DVBF2j]->Write();
//   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_ZH_old");
//   histos_1D_old[Settings::M4l_DVH]->Write();
//   oldeff_DVH_ZH=histos_1D_old[Settings::M4l_DVH]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVH]->Integral();
   
   
   histos_1D_old[Settings::M4l_DVBF2j]->Reset();
   histos_1D_old[Settings::M4l_DVH]->Reset();
   Analyzer *_qqZZ_old      = new Analyzer(qqZZ_old, lumi);      _qqZZ_old->LoopForEff( shiftWP,histos_1D_old);
   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_qqZZ_old");
   f->cd();
   histos_1D_old[Settings::M4l_DVBF2j]->Write();
   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_qqZZ_old");
   histos_1D_old[Settings::M4l_DVH]->Write();
   oldeff_DVH_qqZZ=histos_1D_old[Settings::M4l_DVH]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVH]->Integral();
   oldeff_Djj_qqZZ=histos_1D_old[Settings::M4l_DVBF2j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF2j]->Integral();
   
   
   
//   cout << "Old efficincy of DVBF2j in VBF sample = " << oldeff_Djj_VBF << endl;
//   cout << "Old efficincy of DVBF2j in ggH sample = " << oldeff_Djj_ggH << endl;
//   cout << "Old efficincy of DVH in ggH sample = " << oldeff_DVH_ggH << endl;
//   cout << "Old efficincy of DVH in WH sample = " << oldeff_DVH_WH << endl;
//   cout << "Old efficincy of DVH in ZH sample = " << oldeff_DVH_ZH << endl;
//   cout << "Old efficincy of DVH in qqZZ sample = " << oldeff_DVH_qqZZ << endl;
//   cout << "Old efficincy of DVBF2j in qqZZ sample = " << oldeff_Djj_qqZZ << endl;
   
   TString VBF125_new    = folder_name_new + "VBFH125" + file_name;
   TString gg125_new     = folder_name_new + "ggH125" + file_name;
   TString Wplus125_new  = folder_name_new + "WplusH125" + file_name;
   TString Wminus125_new = folder_name_new + "WminusH125" + file_name;
   TString Z125_new      = folder_name_new + "ZH125" + file_name;
   TString qqZZ_new      = folder_name_new + "ZZTo4l" + file_name;
   
   TH1F *histos_1D_new[Settings::num_of_1D_hist_names];
   
   histos_1D_new[Settings::M4l_DVBF2j] = new TH1F("h_VBF2j_new", "h_VBF2j_new", nbins, 0, 1);
   histos_1D_new[Settings::M4l_DVH]    = new TH1F("h_VH_new", "h_VH_new", nbins, 0, 1);
   
   Analyzer *_VBF125_new    = new Analyzer(VBF125_new, lumi);    _VBF125_new->LoopForEff( shiftWP,histos_1D_new);
   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_VBF_new");
   f->cd();
   histos_1D_new[Settings::M4l_DVBF2j]->Write();
   histos_1D_new[Settings::M4l_DVH]->SetName("DVH_VBF_new");
   histos_1D_new[Settings::M4l_DVH]->Write();
   
   
   TCanvas *c1;
   TGraphErrors *gr_Djj_VBF,*gr_Djj_ggH,*gr_DVH_WH,*gr_DVH_ZH,*gr_DVH_ggH,*gr_Djj_qqZZ,*gr_DVH_qqZZ;
   c1 = new TCanvas("c1","c1",900,900);
   
   Double_t x[nbins];
   Double_t y[nbins];
   Double_t x2[nbins];
   Double_t ex[nbins];
   Double_t ey[nbins];
   
   for( int i = 1; i <= nbins; i++)
   {
      y[i-1] = i/float(nbins);
      x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
      ex[i-1] = 0;
      ey[i-1] = 0;
   }


   gr_Djj_VBF = new TGraphErrors(nbins,x,y,ex,ey);
   gr_Djj_VBF->SetTitle("TGraphErrors Example");
   gr_Djj_VBF->SetName("gr_Djj_VBF");
   f->cd();
   gr_Djj_VBF->Write();
   gr_Djj_VBF->SetMarkerColor(kRed);
   gr_Djj_VBF->SetMarkerStyle(1);
   
   histos_1D_new[Settings::M4l_DVBF2j]->Reset();
   histos_1D_new[Settings::M4l_DVH]->Reset();
   
   
   Analyzer *_gg125_new     = new Analyzer(gg125_new, lumi);     _gg125_new->LoopForEff( shiftWP,histos_1D_new);
   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_ggH_new");
   f->cd();
   histos_1D_new[Settings::M4l_DVBF2j]->Write();
   histos_1D_new[Settings::M4l_DVH]->SetName("DVH_ggH_new");
   histos_1D_new[Settings::M4l_DVH]->Write();
   
   for( int i = 1; i <= nbins; i++)
   {
      y[i-1] = i/float(nbins);
      x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
      x2[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
      ex[i-1] = 0;
      ey[i-1] = 0;
   }
   gr_Djj_ggH = new TGraphErrors(nbins,x,y,ex,ey);
   gr_Djj_ggH->SetTitle("TGraphErrors Example");
   gr_Djj_ggH->SetName("gr_Djj_ggH");
   f->cd();
   gr_Djj_ggH->Write();
   gr_Djj_ggH->SetMarkerColor(kBlack);
   gr_Djj_ggH->SetMarkerStyle(1);
   
   gr_DVH_ggH = new TGraphErrors(nbins,x2,y,ex,ey);
   gr_DVH_ggH->SetTitle("TGraphErrors Example");
   gr_DVH_ggH->SetName("gr_DVH_ggH");
   f->cd();
   gr_DVH_ggH->Write();
   gr_DVH_ggH->SetMarkerColor(kBlack);
   gr_DVH_ggH->SetMarkerStyle(1);
   
   
   histos_1D_new[Settings::M4l_DVBF2j]->Reset();
   histos_1D_new[Settings::M4l_DVH]->Reset();
   
   
   Analyzer *_Wplus125_new  = new Analyzer(Wplus125_new, lumi);  _Wplus125_new->LoopForEff( shiftWP,histos_1D_new);
   Analyzer *_Wminus125_new = new Analyzer(Wminus125_new, lumi); _Wminus125_new->LoopForEff( shiftWP,histos_1D_new);
   Analyzer *_Z125_new      = new Analyzer(Z125_new, lumi);      _Z125_new->LoopForEff( shiftWP,histos_1D_new);
   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_WH_new");
   f->cd();
   histos_1D_new[Settings::M4l_DVBF2j]->Write();
   histos_1D_new[Settings::M4l_DVH]->SetName("DVH_WH_new");
   histos_1D_new[Settings::M4l_DVH]->Write();
   
   for( int i = 1; i <= nbins; i++)
   {
      y[i-1] = i/float(nbins);
      x[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
      ex[i-1] = 0;
      ey[i-1] = 0;
   }
   gr_DVH_WH = new TGraphErrors(nbins,x,y,ex,ey);
   gr_DVH_WH->SetTitle("TGraphErrors Example");
   gr_DVH_WH->SetName("gr_DVH_WH");
   f->cd();
   gr_DVH_WH->Write();
   gr_DVH_WH->SetMarkerColor(kBlue);
   gr_DVH_WH->SetMarkerStyle(1);
   
   
   histos_1D_new[Settings::M4l_DVBF2j]->Reset();
   histos_1D_new[Settings::M4l_DVH]->Reset();
   
   
   Analyzer *_qqZZ_new     = new Analyzer(qqZZ_new, lumi);     _qqZZ_new->LoopForEff( shiftWP,histos_1D_new);
   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_qqZZ_new");
   f->cd();
   histos_1D_new[Settings::M4l_DVBF2j]->Write();
   histos_1D_new[Settings::M4l_DVH]->SetName("DVH_qqZZ_new");
   histos_1D_new[Settings::M4l_DVH]->Write();
   
   for( int i = 1; i <= nbins; i++)
   {
      y[i-1] = i/float(nbins);
      x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
      x2[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
      ex[i-1] = 0;
      ey[i-1] = 0;
   }
   gr_Djj_qqZZ = new TGraphErrors(nbins,x,y,ex,ey);
   gr_Djj_qqZZ->SetTitle("TGraphErrors Example");
   gr_Djj_qqZZ->SetName("gr_Djj_qqZZ");
   f->cd();
   gr_Djj_qqZZ->Write();
   gr_Djj_qqZZ->SetMarkerColor(kGreen);
   gr_Djj_qqZZ->SetMarkerStyle(1);
   
   gr_DVH_qqZZ = new TGraphErrors(nbins,x2,y,ex,ey);
   gr_DVH_qqZZ->SetTitle("TGraphErrors Example");
   gr_DVH_qqZZ->SetName("gr_DVH_qqZZ");
   f->cd();
   gr_DVH_qqZZ->Write();
   gr_DVH_qqZZ->SetMarkerColor(kGreen);
   gr_DVH_qqZZ->SetMarkerStyle(1);
   
   
   histos_1D_new[Settings::M4l_DVBF2j]->Reset();
   histos_1D_new[Settings::M4l_DVH]->Reset();
   
   
//   Analyzer *_Z125_new      = new Analyzer(Z125_new, lumi);      _Z125_new->LoopForEff( shiftWP,histos_1D_new);
//   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_ZH_new");
//   f->cd();
//   histos_1D_new[Settings::M4l_DVBF2j]->Write();
//   histos_1D_new[Settings::M4l_DVH]->SetName("DVH_ZH_new");
//   histos_1D_new[Settings::M4l_DVH]->Write();
//   
//   for( int i = 1; i <= nbins; i++)
//   {
//      y[i-1] = i/float(nbins);
//      x[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
//      ex[i-1] = 0;
//      ey[i-1] = 0;
//   }
//   gr_DVH_ZH = new TGraphErrors(nbins,x,y,ex,ey);
//   gr_DVH_ZH->SetTitle("TGraphErrors Example");
//   gr_DVH_ZH->SetName("gr_DVH_ZH");
//   f->cd();
//   gr_DVH_ZH->Write();
//   gr_DVH_ZH->SetMarkerColor(kYellow);
//   gr_DVH_ZH->SetMarkerStyle(1);
   
   
   c1->cd();
   TMultiGraph *mg = new TMultiGraph();
   gr_Djj_VBF->SetTitle("VBF");
   gr_Djj_VBF->SetLineColor(kRed);
   mg->Add(gr_Djj_VBF);
   gr_Djj_ggH->SetTitle("ggH");
   mg->Add(gr_Djj_ggH);
   gr_Djj_qqZZ->SetTitle("qqZZ");
   gr_Djj_qqZZ->SetLineColor(kGreen);
   mg->Add(gr_Djj_qqZZ);
   mg->Draw("apl");
   mg->SetMaximum(1.);
   mg->GetXaxis()->SetRangeUser(0., 0.8);
   mg->GetYaxis()->SetTitle("Cut value");
   mg->GetXaxis()->SetTitle("D_{2jets}^{VBF}   eff");
   TLegend *leg = new TLegend(0.65, 0.75, 0.90, 0.90);
   leg->AddEntry(gr_Djj_VBF,"VBF","pl");
   leg->AddEntry(gr_Djj_ggH,"ggH","pl");
   leg->AddEntry(gr_Djj_qqZZ,"qqZZ","pl");
   leg->Draw();
   
   TLine *line0 = new TLine(0,0.5,1,0.5);
   line0->SetLineColor(kBlack);
   line0->SetLineStyle(2);
   line0->Draw();
   TLine *line1 = new TLine(oldeff_Djj_VBF,0,oldeff_Djj_VBF,1);
   line1->SetLineColor(kRed);
   line1->SetLineStyle(2);
   line1->Draw();
   TLine *line2 = new TLine(oldeff_Djj_ggH,0,oldeff_Djj_ggH,1);
   line2->SetLineColor(kBlack);
   line2->SetLineStyle(2);
   line2->Draw();
   TLine *line2b = new TLine(oldeff_Djj_qqZZ,0,oldeff_Djj_qqZZ,1);
   line2b->SetLineColor(kGreen);
   line2b->SetLineStyle(2);
   line2b->Draw();
   c1->SaveAs("ControlPlots/DVBFVsCut.pdf");
   
   
   
   c1->Clear();
   c1->cd();
   TMultiGraph *mg2 = new TMultiGraph();
//   gr_DVH_ZH->SetTitle("ZH");
//   gr_DVH_ZH->SetLineColor(kYellow);
//   mg2->Add(gr_DVH_ZH);
   gr_DVH_WH->SetTitle("WH");
   gr_DVH_WH->SetLineColor(kBlue);
   mg2->Add(gr_DVH_WH);
   gr_DVH_ggH->SetTitle("ggH");
   mg2->Add(gr_DVH_ggH);
   gr_DVH_qqZZ->SetTitle("qqZZ");
   gr_DVH_qqZZ->SetLineColor(kGreen);
   mg2->Add(gr_DVH_qqZZ);
   mg2->Draw("apl");
   mg2->SetMaximum(1.);
   mg2->GetXaxis()->SetRangeUser(0., 0.8);
   mg2->GetYaxis()->SetTitle("Cut value");
   mg2->GetXaxis()->SetTitle("D_{2jets}^{VH}   eff");
   TLegend *leg2 = new TLegend(0.65, 0.75, 0.90, 0.90);
   leg2->AddEntry(gr_DVH_ggH,"ggH","pl");
   leg2->AddEntry(gr_DVH_WH,"VH","pl");
//   leg2->AddEntry(gr_DVH_ZH,"ZH","pl");
   leg2->AddEntry(gr_DVH_qqZZ,"qqZZ","pl");
   leg2->Draw();
   
   line0->Draw();
   TLine *line3 = new TLine(oldeff_DVH_ggH,0,oldeff_DVH_ggH,1);
   line3->SetLineColor(kBlack);
   line3->SetLineStyle(2);
   line3->Draw();
   TLine *line3b = new TLine(oldeff_DVH_qqZZ,0,oldeff_DVH_qqZZ,1);
   line3b->SetLineColor(kGreen);
   line3b->SetLineStyle(2);
   line3b->Draw();
   TLine *line4 = new TLine(oldeff_DVH_WH,0,oldeff_DVH_WH,1);
   line4->SetLineColor(kBlue);
   line4->SetLineStyle(2);
   line4->Draw();
//   TLine *line5 = new TLine(oldeff_DVH_ZH,0,oldeff_DVH_ZH,1);
//   line5->SetLineColor(kYellow);
//   line5->SetLineStyle(2);
//   line5->Draw();
   c1->SaveAs("ControlPlots/DVHVsCut.pdf");
   
   cout << "======================================================================================" << endl;
   cout << "To match old efficiency of DVBF2j in ggH (" << oldeff_Djj_ggH << ") cut should be = " << gr_Djj_ggH->Eval(oldeff_Djj_ggH) << endl;
   cout << "To match old efficiency of DVBF2j in VBF (" << oldeff_Djj_VBF << ") cut should be = " << gr_Djj_VBF->Eval(oldeff_Djj_VBF) << endl << endl;
   
   cout << "To match old efficiency of DVH in ggH (" << oldeff_DVH_ggH << ") cut should be = " << gr_DVH_ggH->Eval(oldeff_DVH_ggH) << endl;
   cout << "To match old efficiency of DVH in VH (" << oldeff_DVH_WH << ") cut should be = " << gr_DVH_WH->Eval(oldeff_DVH_WH) << endl;
//   cout << "To match old efficiency of DVH in ZH (" << oldeff_DVH_ZH << ") cut should be = " << gr_DVH_ZH->Eval(oldeff_DVH_ZH) << endl;
   cout << "=======================================================================================" << endl;
   
//   cout << "======================================================================================" << endl;
//   cout << "Efficiency of DVBF2j in ggH = " << gr_Djj_ggH->Eval(0.5) << endl;
//   cout << "Efficiency of DVBF2j in VBF = " << gr_Djj_VBF->Eval(0.5) << endl << endl;
//   cout << "Efficiency of DVBF2j in qqZZ = " << gr_Djj_qqZZ->Eval(0.5) << endl << endl;
//   
//   cout << "Efficiency of DVH in ggH = " << gr_DVH_ggH->Eval(0.5) << endl;
//   cout << "Efficiency of DVH in WH = " << gr_DVH_WH->Eval(0.5) << endl;
//   cout << "Efficiency of DVH in ZH = " << gr_DVH_ZH->Eval(0.5) << endl;
//   cout << "Efficiency of DVH in qqZZ = " << gr_DVH_qqZZ->Eval(0.5) << endl;
//   cout << "=======================================================================================" << endl;
   
   f->Close();
   delete f;
   
}
