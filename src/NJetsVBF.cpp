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
#include "../include/Analyzer.h"

using namespace std;

int main( int argc, char *argv[] )
{
	Float_t lumi = 35.8;
	TString folder_name = "root://lxcms03//data3/Higgs/170623/";
	TString file_name   = "/ZZ4lAnalysis.root";
	
   TString VBF125           = folder_name + "VBFH125" + file_name;
	TString gg125            = folder_name + "ggH125" + file_name;
	TString gg125_MiNLO      = folder_name + "ggH125_minloHJJ" + file_name;
	TString gg125_NNLOPS     = folder_name + "ggH125_NNLOPS" + file_name;
	TString ggTo4e_MCFM      = folder_name + "ggTo4e_0PMH125_MCFM701" + file_name;
	TString ggTo4mu_MCFM     = folder_name + "ggTo4mu_0PMH125_MCFM701" + file_name;
	TString ggTo2e2mu_MCFM   = folder_name + "ggTo2e2mu_0PMH125_MCFM701" + file_name;
	TString ggTo4tau_MCFM    = folder_name + "ggTo4tau_0PMH125_MCFM701" + file_name;
	TString ggTo2e2tau_MCFM  = folder_name + "ggTo2e2tau_0PMH125_MCFM701" + file_name;
	TString ggTo2mu2tau_MCFM = folder_name + "ggTo2mu2tau_0PMH125_MCFM701" + file_name;
	
	TH1F *NJets_VBF = new TH1F("NJets_VBF","NJets_VBF",5,0,5);
	Analyzer *_VBF125 = new Analyzer(VBF125, lumi);
	_VBF125->LoopForNJets(NJets_VBF);
	
	TH1F *NJets_gg125 = new TH1F("NJets_gg125","NJets_gg125",5,0,5);
	Analyzer *_gg125 = new Analyzer(gg125, lumi);
	_gg125->LoopForNJets(NJets_gg125);
	
	TH1F *NJets_gg125_MiNLO = new TH1F("NJets_gg125_MiNLO","NJets_gg125_MiNLO",5,0,5);
	Analyzer *_gg125_MiNLO = new Analyzer(gg125_MiNLO, lumi);
	_gg125_MiNLO->LoopForNJets(NJets_gg125_MiNLO);
	
	TH1F *NJets_gg125_NNLOPS = new TH1F("NJets_gg125_NNLOPS","NJets_gg125_NNLOPS",5,0,5);
	Analyzer *_gg125_NNLOPS = new Analyzer(gg125_NNLOPS, lumi);
	_gg125_NNLOPS->LoopForNJets(NJets_gg125_NNLOPS);
	
	TH1F *NJets_gg125_MCFM = new TH1F("NJets_gg125_MCFM","NJets_gg125_MCFM",5,0,5);
	Analyzer *_ggTo4e_MCFM      = new Analyzer(ggTo4e_MCFM, lumi);
	Analyzer *_ggTo4mu_MCFM     = new Analyzer(ggTo4mu_MCFM, lumi);
	Analyzer *_ggTo2e2mu_MCFM   = new Analyzer(ggTo2e2mu_MCFM, lumi);
	Analyzer *_ggTo4tau_MCFM    = new Analyzer(ggTo4tau_MCFM, lumi);
	Analyzer *_ggTo2e2tau_MCFM  = new Analyzer(ggTo2e2tau_MCFM, lumi);
	Analyzer *_ggTo2mu2tau_MCFM = new Analyzer(ggTo2mu2tau_MCFM, lumi);
	_ggTo4e_MCFM     ->LoopForNJets(NJets_gg125_MCFM);
	_ggTo4mu_MCFM    ->LoopForNJets(NJets_gg125_MCFM);
	_ggTo2e2mu_MCFM  ->LoopForNJets(NJets_gg125_MCFM);
	_ggTo4tau_MCFM   ->LoopForNJets(NJets_gg125_MCFM);
	_ggTo2e2tau_MCFM ->LoopForNJets(NJets_gg125_MCFM);
	_ggTo2mu2tau_MCFM->LoopForNJets(NJets_gg125_MCFM);
	
	
	
	TCanvas *c1 = new TCanvas("c1","c1",900,900);
	gStyle->SetOptStat(0);
	c1->cd();
	NJets_VBF->SetTitle("VBF POWHEG");
	NJets_VBF->SetLineColor(kRed);
	NJets_VBF->SetMaximum(0.5);
	NJets_VBF->Draw("HIST");
	NJets_gg125->SetTitle("ggH POWHEG");
	NJets_gg125->SetLineColor(kBlack);
	NJets_gg125->Draw("HIST SAME");
	NJets_gg125_MiNLO->SetTitle("ggH MiNLO");
	NJets_gg125_MiNLO->SetLineColor(kGray);
	NJets_gg125_MiNLO->Draw("HIST SAME");
	NJets_gg125_NNLOPS->SetTitle("ggH NNLOPS");
	NJets_gg125_NNLOPS->SetLineColor(kYellow + 4);
	NJets_gg125_NNLOPS->Draw("HIST SAME");
	NJets_gg125_MCFM->SetTitle("ggH MCFM");
	NJets_gg125_MCFM->SetLineColor(kGreen - 4);
	NJets_gg125_MCFM->Draw("HIST SAME");
	c1->BuildLegend();
	c1->SaveAs("./ControlPlots/NJetsInVBF.pdf");
	
	
}
