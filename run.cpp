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


// My own files
#include "Analyzer.h"
#include "Functions.h"

using namespace std;

int main( int argc, char *argv[] )
{
   Float_t  lumi = 35.8;
   
   Int_t   m4l_bins     = 18;
   Double_t m4l_slices[] = {110,120,130,140,150,160,170,180,190,200,250,300,400,500,600,700,800,900,1000};
   
   Int_t   m4l_bins2     = 10;
   Double_t m4l_slices2[] = {110,120,130,140,150,160,170,180,190,200,250};
   
   TProfile *p       = new TProfile("p","p",m4l_bins, m4l_slices);
   TH1F     *h       = new TH1F("h", "h", m4l_bins, m4l_slices);
   TH1F     *h_VBF2j = new TH1F("h_VBF2j", "h_VBF2j", m4l_bins, m4l_slices);
   TH1F     *h_VH    = new TH1F("h_VH", "      h_VH", m4l_bins, m4l_slices);

   TH2F     *h2_VBF2j = new TH2F("h2_VBF2j", "h2_VBF2j", m4l_bins, m4l_slices, 100, 0., 1.);
   TH2F     *h2_VH    = new TH2F("h2_VH",       "h2_VH", m4l_bins, m4l_slices, 100, 0., 1.);
   
   TString folder_name = "root://lxcms03//data3/Higgs/170623/";
   TString file_name   = "/ZZ4lAnalysis.root";
   
   TFile *fOutControlHistos = new TFile("DVsM4l.root", "recreate");
   
   //==================================================================
   //
   //    VBF SAMPLES
   //
   //==================================================================

   TString VBF115 = folder_name + "VBFH115" + file_name;
   TString VBF120 = folder_name + "VBFH120" + file_name;
   TString VBF124 = folder_name + "VBFH124" + file_name;
   TString VBF125 = folder_name + "VBFH125" + file_name;
   TString VBF126 = folder_name + "VBFH126" + file_name;
   TString VBF130 = folder_name + "VBFH130" + file_name;
   TString VBF135 = folder_name + "VBFH135" + file_name;
   TString VBF140 = folder_name + "VBFH140" + file_name;
   TString VBF145 = folder_name + "VBFH145" + file_name;
   TString VBF150 = folder_name + "VBFH150" + file_name;
   TString VBF155 = folder_name + "VBFH155" + file_name;
   TString VBF160 = folder_name + "VBFH160" + file_name;
   TString VBF170 = folder_name + "VBFH170" + file_name;
   TString VBF180 = folder_name + "VBFH180" + file_name;
   TString VBF200 = folder_name + "VBFH200" + file_name;
   TString VBF250 = folder_name + "VBFH250" + file_name;
   TString VBF300 = folder_name + "VBFH300" + file_name;
   TString VBF350 = folder_name + "VBFH350" + file_name;
   TString VBF400 = folder_name + "VBFH400" + file_name;
   TString VBF500 = folder_name + "VBFH500" + file_name;
   TString VBF600 = folder_name + "VBFH600" + file_name;
   TString VBF700 = folder_name + "VBFH700" + file_name;
   TString VBF800 = folder_name + "VBFH800" + file_name;
   TString VBF900 = folder_name + "VBFH900" + file_name;
   TString VBF1000 = folder_name + "VBFH1000" + file_name;
   TString VBF1500 = folder_name + "VBFH1500" + file_name;
   TString VBF2000 = folder_name + "VBFH2000" + file_name;
   TString VBF2500 = folder_name + "VBFH2500" + file_name;
   TString VBF3000 = folder_name + "VBFH3000" + file_name;
   
   
   Analyzer *_VBF115 = new Analyzer(VBF115, lumi); _VBF115->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF120 = new Analyzer(VBF120, lumi); _VBF120->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF124 = new Analyzer(VBF124, lumi); _VBF124->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF125 = new Analyzer(VBF125, lumi); _VBF125->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF126 = new Analyzer(VBF126, lumi); _VBF126->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF130 = new Analyzer(VBF130, lumi); _VBF130->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF135 = new Analyzer(VBF135, lumi); _VBF135->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF140 = new Analyzer(VBF140, lumi); _VBF140->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF145 = new Analyzer(VBF145, lumi); _VBF145->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF150 = new Analyzer(VBF150, lumi); _VBF150->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF155 = new Analyzer(VBF155, lumi); _VBF155->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF160 = new Analyzer(VBF160, lumi); _VBF160->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF170 = new Analyzer(VBF170, lumi); _VBF170->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF180 = new Analyzer(VBF180, lumi); _VBF180->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF200 = new Analyzer(VBF200, lumi); _VBF200->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF250 = new Analyzer(VBF250, lumi); _VBF250->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF300 = new Analyzer(VBF300, lumi); _VBF300->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF350 = new Analyzer(VBF350, lumi); _VBF350->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF400 = new Analyzer(VBF400, lumi); _VBF400->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF500 = new Analyzer(VBF500, lumi); _VBF500->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF600 = new Analyzer(VBF600, lumi); _VBF600->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF700 = new Analyzer(VBF700, lumi); _VBF700->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF800 = new Analyzer(VBF800, lumi); _VBF800->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF900 = new Analyzer(VBF900, lumi); _VBF900->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_VBF1000 = new Analyzer(VBF1000, lumi); _VBF1000->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
//   Analyzer *_VBF1500 = new Analyzer(VBF1500, lumi); _VBF1500->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH); wrong xsec
//   Analyzer *_VBF2000 = new Analyzer(VBF2000, lumi); _VBF2000->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
//   Analyzer *_VBF2500 = new Analyzer(VBF2500, lumi); _VBF2500->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
//   Analyzer *_VBF3000 = new Analyzer(VBF3000, lumi); _VBF3000->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   
   
   TCanvas *c1,*c2, *c3;
   c1 = new TCanvas("c1","c1",900,700);
   c2 = new TCanvas("c2","c2",900,700);
   c3 = new TCanvas("c3","c3",900,700);
   
   c1->Divide(2,2);
   c1->cd(1);
   p->Draw();
   c1->cd(2);
   h->Draw();
   c1->cd(3);
   h_VBF2j->Draw();
   c1->cd(4);
   h_VH->Draw();
   c1->SaveAs("ControlPlots/test_VBF.pdf");
   
   TGraphErrors *VBF_Djj_tgraph,*VBF_DVH_tgraph;
   Functions *functions = new Functions();
   h_VBF2j->Divide(h);
   h_VH->Divide(h);
   
   VBF_Djj_tgraph = functions->makeGraphFromTH1(p, h_VBF2j , "VBF_Djj_tgraph");
   VBF_DVH_tgraph = functions->makeGraphFromTH1(p, h_VH    , "VBF_DVH_tgraph");
   c2->cd();
   VBF_Djj_tgraph->Draw();
   c2->SaveAs("ControlPlots/eff_DVBF2j_VBF.pdf");
   c3->cd();
   VBF_DVH_tgraph->Draw();
   c3->SaveAs("ControlPlots/eff_DVH_VBF.pdf");
   
   fOutControlHistos->cd();
   h->SetName("M4l_VBF");
   h->Write();
   h2_VBF2j->SetName("DVBF2jVsM4l_VBF");
   h2_VBF2j->Write();
   h2_VH->SetName("DVHVsM4l_VBF");
   h2_VH->Write();
   
   
   
   
   //==================================================================
   //
   //    ggH SAMPLES
   //
   //==================================================================
   
   
   p->Reset();
   h->Reset();
   h_VBF2j->Reset();
   h_VH->Reset();
   h2_VBF2j->Reset();
   h2_VH->Reset();
   
   TString gg115 = folder_name + "ggH115" + file_name;
   TString gg120 = folder_name + "ggH120" + file_name;
   TString gg124 = folder_name + "ggH124" + file_name;
   TString gg125 = folder_name + "ggH125" + file_name;
   TString gg126 = folder_name + "ggH126" + file_name;
   TString gg130 = folder_name + "ggH130" + file_name;
   TString gg135 = folder_name + "ggH135" + file_name;
   TString gg140 = folder_name + "ggH140" + file_name;
   TString gg145 = folder_name + "ggH145" + file_name;
   TString gg150 = folder_name + "ggH150" + file_name;
   TString gg155 = folder_name + "ggH155" + file_name;
   TString gg160 = folder_name + "ggH160" + file_name;
   TString gg170 = folder_name + "ggH170" + file_name;
   TString gg180 = folder_name + "ggH180" + file_name;
   TString gg200 = folder_name + "ggH200" + file_name;
   TString gg250 = folder_name + "ggH250" + file_name;
   TString gg300 = folder_name + "ggH300" + file_name;
   TString gg350 = folder_name + "ggH350" + file_name;
   TString gg400 = folder_name + "ggH400" + file_name;
   TString gg500 = folder_name + "ggH500" + file_name;
   TString gg600 = folder_name + "ggH600" + file_name;
   TString gg700 = folder_name + "ggH700" + file_name;
   TString gg800 = folder_name + "ggH800" + file_name;
   TString gg900 = folder_name + "ggH900" + file_name;
   TString gg1000 = folder_name + "ggH1000" + file_name;
   TString gg1500 = folder_name + "ggH1500" + file_name;
   TString gg2000 = folder_name + "ggH2000" + file_name;
   TString gg2500 = folder_name + "ggH2500" + file_name;
   TString gg3000 = folder_name + "ggH3000" + file_name;
   
   
   Analyzer *_gg115 = new Analyzer(gg115, lumi); _gg115->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg120 = new Analyzer(gg120, lumi); _gg120->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg124 = new Analyzer(gg124, lumi); _gg124->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg125 = new Analyzer(gg125, lumi); _gg125->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg126 = new Analyzer(gg126, lumi); _gg126->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg130 = new Analyzer(gg130, lumi); _gg130->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg135 = new Analyzer(gg135, lumi); _gg135->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg140 = new Analyzer(gg140, lumi); _gg140->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg145 = new Analyzer(gg145, lumi); _gg145->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg150 = new Analyzer(gg150, lumi); _gg150->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg155 = new Analyzer(gg155, lumi); _gg155->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg160 = new Analyzer(gg160, lumi); _gg160->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg170 = new Analyzer(gg170, lumi); _gg170->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg180 = new Analyzer(gg180, lumi); _gg180->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg200 = new Analyzer(gg200, lumi); _gg200->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg250 = new Analyzer(gg250, lumi); _gg250->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg300 = new Analyzer(gg300, lumi); _gg300->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg350 = new Analyzer(gg350, lumi); _gg350->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg400 = new Analyzer(gg400, lumi); _gg400->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg500 = new Analyzer(gg500, lumi); _gg500->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg600 = new Analyzer(gg600, lumi); _gg600->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg700 = new Analyzer(gg700, lumi); _gg700->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg800 = new Analyzer(gg800, lumi); _gg800->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg900 = new Analyzer(gg900, lumi); _gg900->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_gg1000 = new Analyzer(gg1000, lumi); _gg1000->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
//   Analyzer *_gg1500 = new Analyzer(gg1500, lumi); _gg1500->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH); wrong xsec
//   Analyzer *_gg2000 = new Analyzer(gg2000, lumi); _gg2000->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
//   Analyzer *_gg2500 = new Analyzer(gg2500, lumi); _gg2500->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
//   Analyzer *_gg3000 = new Analyzer(gg3000, lumi); _gg3000->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   
   c1->cd(1);
   p->Draw();
   c1->cd(2);
   h->Draw();
   c1->cd(3);
   h_VBF2j->Draw();
   c1->cd(4);
   h_VH->Draw();
   c1->SaveAs("ControlPlots/test_ggH.pdf");
   
   TGraphErrors *ggH_Djj_tgraph,*ggH_DVH_tgraph;
   h_VBF2j->Divide(h);
   h_VH->Divide(h);
   
   ggH_Djj_tgraph = functions->makeGraphFromTH1(p, h_VBF2j , "ggH_Djj_tgraph");
   ggH_DVH_tgraph = functions->makeGraphFromTH1(p, h_VH , "ggH_DVH_tgraph");
   c2->Clear();
   c2->cd();
   ggH_Djj_tgraph->Draw();
   c2->SaveAs("ControlPlots/eff_DVBF2j_ggH.pdf");
   c3->Clear();
   c3->cd();
   ggH_DVH_tgraph->Draw();
   c3->SaveAs("ControlPlots/eff_DVH_ggH.pdf");

   fOutControlHistos->cd();
   h->SetName("M4l_ggH");
   h->Write();
   h2_VBF2j->SetName("DVBF2jVsM4l_ggH");
   h2_VBF2j->Write();
   h2_VH->SetName("DVHVsM4l_ggH");
   h2_VH->Write();
   
   //==================================================================
   //
   //    qqZZ BACKGROUND
   //
   //==================================================================
   
   p->Reset();
   h->Reset();
   h_VBF2j->Reset();
   h_VH->Reset();
   h2_VBF2j->Reset();
   h2_VH->Reset();
   
   TString qqZZ = folder_name + "ZZTo4l" + file_name;
   
   Analyzer *_qqZZ = new Analyzer(qqZZ, lumi); _qqZZ->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   
   
   c1->cd(1);
   p->Draw();
   c1->cd(2);
   h->Draw();
   c1->cd(3);
   h_VBF2j->Draw();
   c1->cd(4);
   h_VH->Draw();
   c1->SaveAs("ControlPlots/test_qqZZ.pdf");
   
   TGraphErrors *qqZZ_Djj_tgraph,*qqZZ_DVH_tgraph;
   h_VBF2j->Divide(h);
   h_VH->Divide(h);
   qqZZ_Djj_tgraph = functions->makeGraphFromTH1(p, h_VBF2j , "qqZZ_Djj_tgraph");
   qqZZ_DVH_tgraph = functions->makeGraphFromTH1(p, h_VH , "qqZZ_DVH_tgraph");
   c2->Clear();
   c2->cd();
   qqZZ_Djj_tgraph->Draw();
   c2->SaveAs("ControlPlots/eff_DVBF2j_qqZZ.pdf");
   
   c3->Clear();
   c3->cd();
   qqZZ_DVH_tgraph->Draw();
   c3->SaveAs("ControlPlots/eff_DVH_qqZZ.pdf");
   
   fOutControlHistos->cd();
   h->SetName("M4l_qqZZ");
   h->Write();
   h2_VBF2j->SetName("DVBF2jVsM4l_qqZZ");
   h2_VBF2j->Write();
   h2_VH->SetName("DVHVsM4l_qqZZ");
   h2_VH->Write();
   
   //==================================================================
   //
   //    WH SAMPLES
   //
   //==================================================================
   delete p, h, h_VH, h_VBF2j;
   
   p       = new TProfile("p2","p2",m4l_bins2, m4l_slices2);
   h       = new TH1F("h2", "h2",m4l_bins2, m4l_slices2);
   h_VBF2j = new TH1F("h2_VBF2j", "h2_VBF2j",m4l_bins2, m4l_slices2);
   h_VH    = new TH1F("h2_VH", "h2_VH",m4l_bins2, m4l_slices2);
   
   h2_VBF2j->Reset();
   h2_VH->Reset();
   
   TString Wplus115 = folder_name + "WplusH115" + file_name;
   TString Wplus120 = folder_name + "WplusH120" + file_name;
   TString Wplus124 = folder_name + "WplusH124" + file_name;
   TString Wplus125 = folder_name + "WplusH125" + file_name;
   TString Wplus126 = folder_name + "WplusH126" + file_name;
   TString Wplus130 = folder_name + "WplusH130" + file_name;
   TString Wplus135 = folder_name + "WplusH135" + file_name;
   TString Wplus140 = folder_name + "WplusH140" + file_name;
   TString Wplus145 = folder_name + "WplusH145" + file_name;
   TString Wplus150 = folder_name + "WplusH150" + file_name;
   TString Wplus155 = folder_name + "WplusH155" + file_name;
   TString Wplus160 = folder_name + "WplusH160" + file_name;
   TString Wplus170 = folder_name + "WplusH170" + file_name;
   TString Wplus175 = folder_name + "WplusH175" + file_name;
   TString Wplus180 = folder_name + "WplusH180" + file_name;
   TString Wplus190 = folder_name + "WplusH190" + file_name;
   TString Wplus200 = folder_name + "WplusH200" + file_name;
   TString Wplus210 = folder_name + "WplusH210" + file_name;
   TString Wplus230 = folder_name + "WplusH230" + file_name;
   
   TString Wminus115 = folder_name + "WminusH115" + file_name;
   TString Wminus120 = folder_name + "WminusH120" + file_name;
   TString Wminus124 = folder_name + "WminusH124" + file_name;
   TString Wminus125 = folder_name + "WminusH125" + file_name;
   TString Wminus126 = folder_name + "WminusH126" + file_name;
   TString Wminus130 = folder_name + "WminusH130" + file_name;
   TString Wminus135 = folder_name + "WminusH135" + file_name;
   TString Wminus140 = folder_name + "WminusH140" + file_name;
   TString Wminus145 = folder_name + "WminusH145" + file_name;
   TString Wminus150 = folder_name + "WminusH150" + file_name;
   TString Wminus155 = folder_name + "WminusH155" + file_name;
   TString Wminus160 = folder_name + "WminusH160" + file_name;
   TString Wminus170 = folder_name + "WminusH170" + file_name;
   TString Wminus175 = folder_name + "WminusH175" + file_name;
   TString Wminus180 = folder_name + "WminusH180" + file_name;
   TString Wminus190 = folder_name + "WminusH190" + file_name;
   TString Wminus200 = folder_name + "WminusH200" + file_name;
   TString Wminus210 = folder_name + "WminusH210" + file_name;
   TString Wminus230 = folder_name + "WminusH230" + file_name;
   
   Analyzer *_Wplus115 = new Analyzer(Wplus115, lumi); _Wplus115->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus120 = new Analyzer(Wplus120, lumi); _Wplus120->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus124 = new Analyzer(Wplus124, lumi); _Wplus124->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus125 = new Analyzer(Wplus125, lumi); _Wplus125->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus126 = new Analyzer(Wplus126, lumi); _Wplus126->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus130 = new Analyzer(Wplus130, lumi); _Wplus130->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus135 = new Analyzer(Wplus135, lumi); _Wplus135->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus140 = new Analyzer(Wplus140, lumi); _Wplus140->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus145 = new Analyzer(Wplus145, lumi); _Wplus145->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus150 = new Analyzer(Wplus150, lumi); _Wplus150->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus155 = new Analyzer(Wplus155, lumi); _Wplus155->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus160 = new Analyzer(Wplus160, lumi); _Wplus160->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus170 = new Analyzer(Wplus170, lumi); _Wplus170->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus175 = new Analyzer(Wplus175, lumi); _Wplus175->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus180 = new Analyzer(Wplus180, lumi); _Wplus180->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus190 = new Analyzer(Wplus190, lumi); _Wplus190->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus200 = new Analyzer(Wplus200, lumi); _Wplus200->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus210 = new Analyzer(Wplus210, lumi); _Wplus210->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wplus230 = new Analyzer(Wplus230, lumi); _Wplus230->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   
   Analyzer *_Wminus115 = new Analyzer(Wminus115, lumi); _Wminus115->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus120 = new Analyzer(Wminus120, lumi); _Wminus120->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus124 = new Analyzer(Wminus124, lumi); _Wminus124->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus125 = new Analyzer(Wminus125, lumi); _Wminus125->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus126 = new Analyzer(Wminus126, lumi); _Wminus126->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus130 = new Analyzer(Wminus130, lumi); _Wminus130->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus135 = new Analyzer(Wminus135, lumi); _Wminus135->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus140 = new Analyzer(Wminus140, lumi); _Wminus140->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus145 = new Analyzer(Wminus145, lumi); _Wminus145->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus150 = new Analyzer(Wminus150, lumi); _Wminus150->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus155 = new Analyzer(Wminus155, lumi); _Wminus155->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus160 = new Analyzer(Wminus160, lumi); _Wminus160->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus170 = new Analyzer(Wminus170, lumi); _Wminus170->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus175 = new Analyzer(Wminus175, lumi); _Wminus175->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus180 = new Analyzer(Wminus180, lumi); _Wminus180->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus190 = new Analyzer(Wminus190, lumi); _Wminus190->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus200 = new Analyzer(Wminus200, lumi); _Wminus200->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus210 = new Analyzer(Wminus210, lumi); _Wminus210->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Wminus230 = new Analyzer(Wminus230, lumi); _Wminus230->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);

   c1->cd(1);
   p->Draw();
   c1->cd(2);
   h->Draw();
   c1->cd(3);
   h_VBF2j->Draw();
   c1->cd(4);
   h_VH->Draw();
   c1->SaveAs("ControlPlots/test_WH.pdf");
   
   TGraphErrors *WH_Djj_tgraph,*WH_DVH_tgraph;
   h_VBF2j->Divide(h);
   h_VH->Divide(h);
   
   WH_Djj_tgraph = functions->makeGraphFromTH1(p, h_VBF2j , "WH_Djj_tgraph");
   WH_DVH_tgraph = functions->makeGraphFromTH1(p, h_VH , "WH_DVH_tgraph");
   c2->Clear();
   c2->cd();
   WH_Djj_tgraph->Draw();
   c2->SaveAs("ControlPlots/eff_DVBF2j_WH.pdf");
   
   c3->Clear();
   c3->cd();
   WH_DVH_tgraph->Draw();
   c3->SaveAs("ControlPlots/eff_DVH_WH.pdf");
   
   fOutControlHistos->cd();
   h->SetName("M4l_WH");
   h->Write();
   h2_VBF2j->SetName("DVBF2jVsM4l_WH");
   h2_VBF2j->Write();
   h2_VH->SetName("DVHVsM4l_WH");
   h2_VH->Write();
   
   //==================================================================
   //
   //    ZH SAMPLES
   //
   //==================================================================
   
   p->Reset();
   h->Reset();
   h_VBF2j->Reset();
   h_VH->Reset();
   h2_VBF2j->Reset();
   h2_VH->Reset();
   
   TString Z115 = folder_name + "ZH115" + file_name;
   TString Z120 = folder_name + "ZH120" + file_name;
   TString Z124 = folder_name + "ZH124" + file_name;
   TString Z125 = folder_name + "ZH125" + file_name;
   TString Z126 = folder_name + "ZH126" + file_name;
   TString Z130 = folder_name + "ZH130" + file_name;
   TString Z135 = folder_name + "ZH135" + file_name;
   TString Z140 = folder_name + "ZH140" + file_name;
   TString Z145 = folder_name + "ZH145" + file_name;
   TString Z150 = folder_name + "ZH150" + file_name;
   TString Z155 = folder_name + "ZH155" + file_name;
   TString Z160 = folder_name + "ZH160" + file_name;
   TString Z170 = folder_name + "ZH170" + file_name;
   TString Z175 = folder_name + "ZH175" + file_name;
   TString Z180 = folder_name + "ZH180" + file_name;
   TString Z190 = folder_name + "ZH190" + file_name;
   TString Z200 = folder_name + "ZH200" + file_name;
//   TString Z210 = folder_name + "ZH210" + file_name;
   TString Z230 = folder_name + "ZH230" + file_name;
   
   
   Analyzer *_Z115 = new Analyzer(Z115, lumi); _Z115->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z120 = new Analyzer(Z120, lumi); _Z120->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z124 = new Analyzer(Z124, lumi); _Z124->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z125 = new Analyzer(Z125, lumi); _Z125->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z126 = new Analyzer(Z126, lumi); _Z126->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z130 = new Analyzer(Z130, lumi); _Z130->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z135 = new Analyzer(Z135, lumi); _Z135->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z140 = new Analyzer(Z140, lumi); _Z140->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z145 = new Analyzer(Z145, lumi); _Z145->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z150 = new Analyzer(Z150, lumi); _Z150->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z155 = new Analyzer(Z155, lumi); _Z155->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z160 = new Analyzer(Z160, lumi); _Z160->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z170 = new Analyzer(Z170, lumi); _Z170->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z175 = new Analyzer(Z175, lumi); _Z175->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z180 = new Analyzer(Z180, lumi); _Z180->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z190 = new Analyzer(Z190, lumi); _Z190->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z200 = new Analyzer(Z200, lumi); _Z200->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
//   Analyzer *_Z210 = new Analyzer(Z210, lumi); _Z210->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   Analyzer *_Z230 = new Analyzer(Z230, lumi); _Z230->Loop(p,h,h_VBF2j,h_VH,h2_VBF2j,h2_VH);
   
   
   c1->cd(1);
   p->Draw();
   c1->cd(2);
   h->Draw();
   c1->cd(3);
   h_VBF2j->Draw();
   c1->cd(4);
   h_VH->Draw();
   c1->SaveAs("ControlPlots/test_ZH.pdf");
   
   TGraphErrors *ZH_Djj_tgraph,*ZH_DVH_tgraph;
   h_VBF2j->Divide(h);
   h_VH->Divide(h);
   
   ZH_Djj_tgraph = functions->makeGraphFromTH1(p, h_VBF2j , "ZH_Djj_tgraph");
   ZH_DVH_tgraph = functions->makeGraphFromTH1(p, h_VH , "ZH_DVH_tgraph");
   c2->Clear();
   c2->cd();
   ZH_Djj_tgraph->Draw();
   c2->SaveAs("ControlPlots/eff_DVBF2j_ZH.pdf");
  
   c3->Clear();
   c3->cd();
   ZH_DVH_tgraph->Draw();
   c3->SaveAs("ControlPlots/eff_DVH_ZH.pdf");
   
   fOutControlHistos->cd();
   h->SetName("M4l_ZH");
   h->Write();
   h2_VBF2j->SetName("DVBF2jVsM4l_ZH");
   h2_VBF2j->Write();
   h2_VH->SetName("DVHVsM4l_ZH");
   h2_VH->Write();
   
   fOutControlHistos->Close();
   delete fOutControlHistos;

   //==================================================================
   //
   //    WRITE TO ROOT
   //
   //==================================================================
   TFile *fOutHistos = new TFile("EffVsM4l.root", "recreate");
   fOutHistos->cd();
   
   VBF_Djj_tgraph ->Write();
   VBF_DVH_tgraph ->Write();
   ggH_Djj_tgraph ->Write();
   ggH_DVH_tgraph ->Write();
   WH_Djj_tgraph  ->Write();
   WH_DVH_tgraph  ->Write();
   ZH_Djj_tgraph  ->Write();
   ZH_DVH_tgraph  ->Write();
   qqZZ_Djj_tgraph->Write();
   qqZZ_DVH_tgraph->Write();
   
   TSpline3 *VBF_Djj_spline, *VBF_DVH_spline, *ggH_Djj_spline, *ggH_DVH_spline, *WH_Djj_spline, *WH_DVH_spline, *ZH_Djj_spline, *ZH_DVH_spline, *qqZZ_Djj_spline, *qqZZ_DVH_spline;
   
   VBF_Djj_spline = functions->convertGraphToSpline3(VBF_Djj_tgraph, 0, 0);
   VBF_DVH_spline = functions->convertGraphToSpline3(VBF_DVH_tgraph, 0, 0);
   ggH_Djj_spline = functions->convertGraphToSpline3(ggH_Djj_tgraph, 0, 0);
   ggH_DVH_spline = functions->convertGraphToSpline3(ggH_DVH_tgraph, 0, 0);
   WH_Djj_spline  = functions->convertGraphToSpline3(WH_Djj_tgraph, 0, 0);
   WH_DVH_spline  = functions->convertGraphToSpline3(WH_DVH_tgraph, 0, 0);
   ZH_Djj_spline  = functions->convertGraphToSpline3(ZH_Djj_tgraph, 0, 0);
   ZH_DVH_spline  = functions->convertGraphToSpline3(ZH_DVH_tgraph, 0, 0);
   qqZZ_Djj_spline= functions->convertGraphToSpline3(qqZZ_Djj_tgraph, 0, 0);
   qqZZ_DVH_spline= functions->convertGraphToSpline3(qqZZ_DVH_tgraph, 0, 0);
   
   VBF_Djj_spline ->Write();
   VBF_DVH_spline ->Write();
   ggH_Djj_spline ->Write();
   ggH_DVH_spline ->Write();
   WH_Djj_spline  ->Write();
   WH_DVH_spline  ->Write();
   ZH_Djj_spline  ->Write();
   ZH_DVH_spline  ->Write();
   qqZZ_Djj_spline->Write();
   qqZZ_DVH_spline->Write();
   
   fOutHistos->Close();
   delete fOutHistos;

   
}


