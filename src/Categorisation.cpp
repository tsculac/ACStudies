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
#include "THStack.h"


// My own files
#include "../include/Analyzer.h"
#include "../include/Functions.h"
#include "../include/Settings.h"

using namespace std;

int main( int argc, char *argv[] )
{
   TH1F *histo = new TH1F("histo","histo",3,0,3);
   Float_t lumi = 1.;
   
   TString folder_name = "root://lxcms03//data3/Higgs/170623/";
   TString file_name   = "/ZZ4lAnalysis.root";
   
   TFile *fOutHistos = new TFile("CategoryPurities.root", "recreate");
   
   histo->Reset();
   TString VBF125 = folder_name + "VBFH125" + file_name;
   Analyzer *_VBF125 = new Analyzer(VBF125, lumi); _VBF125->LoopForCat(false,histo);
   histo->SetName("oldArbitration_VBF");
   fOutHistos->cd();
   histo->Write();
   
   histo->Reset();
   _VBF125->LoopForCat(true,histo);
   histo->SetName("newArbitration_VBF");
   fOutHistos->cd();
   histo->Write();
   
   histo->Reset();
   TString ggH125 = folder_name + "ggH125" + file_name;
   Analyzer *_ggH125 = new Analyzer(ggH125, lumi); _ggH125->LoopForCat(false,histo);
   histo->SetName("oldArbitration_ggH");
   fOutHistos->cd();
   histo->Write();
   
   histo->Reset();
   _ggH125->LoopForCat(true,histo);
   histo->SetName("newArbitration_ggH");
   fOutHistos->cd();
   histo->Write();
   
   histo->Reset();
   TString WplusH125  = folder_name + "WplusH125" + file_name;
   TString WminusH125 = folder_name + "WminusH125" + file_name;
   Analyzer *_WplusH125  = new Analyzer(WplusH125, lumi); _WplusH125->LoopForCat(false,histo);
   Analyzer *_WminusH125 = new Analyzer(WminusH125, lumi); _WminusH125->LoopForCat(false,histo);
   histo->SetName("oldArbitration_WH");
   fOutHistos->cd();
   histo->Write();
   
   histo->Reset();
   _WplusH125->LoopForCat(true,histo);
   _WminusH125->LoopForCat(true,histo);
   histo->SetName("newArbitration_WH");
   fOutHistos->cd();
   histo->Write();
   
   histo->Reset();
   TString ZH125  = folder_name + "ZH125" + file_name;
   Analyzer *_ZH125 = new Analyzer(ZH125, lumi); _ZH125->LoopForCat(false,histo);
   histo->SetName("oldArbitration_ZH");
   fOutHistos->cd();
   histo->Write();
   
   histo->Reset();
   _ZH125->LoopForCat(true,histo);
   histo->SetName("newArbitration_ZH");
   fOutHistos->cd();
   histo->Write();
   
   fOutHistos->Close();
   delete fOutHistos;
   
   TFile* histo_file = TFile::Open("CategoryPurities.root");
   THStack *oldS = new THStack("old","");
   THStack *newS = new THStack("new","");
   TH1F *old_VBF,*old_ggH,*old_WH,*old_ZH,*new_VBF,*new_ggH,*new_WH,*new_ZH;
   
   old_VBF = (TH1F*)histo_file->Get("oldArbitration_VBF");
   new_VBF = (TH1F*)histo_file->Get("newArbitration_VBF");
   old_ggH = (TH1F*)histo_file->Get("oldArbitration_ggH");
   new_ggH = (TH1F*)histo_file->Get("newArbitration_ggH");
   old_WH  = (TH1F*)histo_file->Get("oldArbitration_WH");
   new_WH  = (TH1F*)histo_file->Get("newArbitration_WH");
   old_ZH  = (TH1F*)histo_file->Get("oldArbitration_ZH");
   new_ZH  = (TH1F*)histo_file->Get("newArbitration_ZH");
   
   old_VBF->SetFillColor(kRed);
   new_VBF->SetFillColor(kRed);
   old_ggH->SetFillColor(kBlack);
   new_ggH->SetFillColor(kBlack);
   old_WH ->SetFillColor(kBlue);
   new_WH ->SetFillColor(kBlue);
   old_ZH ->SetFillColor(kYellow);
   new_ZH ->SetFillColor(kYellow);
   
   oldS->Add(old_ggH);
   oldS->Add(old_VBF);
   oldS->Add(old_ZH);
   oldS->Add(old_WH);
   
   cout << "================================================" << endl;
   cout << "Old categorisation purities" << endl;
   cout <<fixed<<setprecision(3)<< "              VBF     WH      ZH     ggH " <<endl;
   cout <<fixed<<setprecision(3) <<"VBF2j-tag.: "<< old_VBF->GetBinContent(1) << "   " << old_WH->GetBinContent(1) << "   " << old_ZH->GetBinContent(1)<< "   " << old_ggH->GetBinContent(1)<< endl;
   cout <<fixed<<setprecision(3)<< "Untagged.:  "<< old_VBF->GetBinContent(2) << "   " << old_WH->GetBinContent(2) << "   " << old_ZH->GetBinContent(2)<< "   " << old_ggH->GetBinContent(2)<< endl;
   cout <<fixed<<setprecision(3)<< "VH-tag.:    "<< old_VBF->GetBinContent(3) << "   " << old_WH->GetBinContent(3) << "   " << old_ZH->GetBinContent(3)<< "   " << old_ggH->GetBinContent(3)<< endl;
   cout << "================================================" << endl;
   cout << "New categorisation purities" << endl;
   cout <<fixed<<setprecision(3)<< "              VBF     WH      ZH     ggH " <<endl;
   cout <<fixed<<setprecision(3) <<"VBF2j-tag.: "<< new_VBF->GetBinContent(1) << "   " << new_WH->GetBinContent(1) << "   " << new_ZH->GetBinContent(1)<< "   " << new_ggH->GetBinContent(1)<< endl;
   cout <<fixed<<setprecision(3)<< "Untagged.:  "<< new_VBF->GetBinContent(2) << "   " << new_WH->GetBinContent(2) << "   " << new_ZH->GetBinContent(2)<< "   " << new_ggH->GetBinContent(2)<< endl;
   cout <<fixed<<setprecision(3)<< "VH-tag.:    "<< new_VBF->GetBinContent(3) << "   " << new_WH->GetBinContent(3) << "   " << new_ZH->GetBinContent(3)<< "   " << new_ggH->GetBinContent(3)<< endl;
   cout << "================================================" << endl;
   
   newS->Add(new_ggH);
   newS->Add(new_VBF);
   newS->Add(new_ZH);
   newS->Add(new_WH);
   
   TCanvas *c1 = new TCanvas("c1","c1",900,900);
   c1->cd();
   oldS->Draw("HIST");
   c1->SaveAs("ControlPlots/CategoryPurity_old.pdf");
   c1->Clear();
   newS->Draw("HIST");
   c1->SaveAs("ControlPlots/CategoryPurity_new.pdf");
}

