// C++
#include <iostream>
#include <fstream>
#include <string>

// ROOT
#include "TApplication.h"
#include "TMultiGraph.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TLine.h"


// My own files
#include "../include/Analyzer.h"
#include "../include/Functions.h"
#include "../include/Settings.h"

using namespace std;

int main( int argc, char *argv[] )
{
   float lumi = 38.5;
   int nbins = 10000;
   bool shiftWP = true;
	bool mergeInto_VH = true;
	bool only2jEvents = false;
	bool includeMCFM = false; //Slows down a lot
	bool useqqZZ_ext = false; //qqZZ does not have enough statistic

	Analyzer *analyzer = new Analyzer();
	TFile *f = new TFile("EffVsCut.root", "recreate");
   TH1F *histos_1D_old[Settings::num_of_1D_hist_names];
	
   
   TString folder_name_old = "./Moriond_2017/";
//   TString folder_name_new = "root://lxcms03//data3/Higgs/170623/";
	TString folder_name_new = "root://lxcms03//data3/Higgs/171005/";
   TString file_name       = "/ZZ4lAnalysis.root";
   
   float oldeff_Djj_VBF;
   float oldeff_Djj_ggH;
	float oldeff_Dj_VBF;
	float oldeff_Dj_ggH;
   float oldeff_DVH_ggH;
   float oldeff_DVH_WH;
   float oldeff_DVH_ZH;
   float oldeff_Djj_qqZZ;
	float oldeff_Dj_qqZZ;
   float oldeff_DVH_qqZZ;

   TString VBF125_old    = folder_name_old + "VBFH125" + file_name;
   TString gg125_old     = folder_name_old + "ggH125" + file_name;
   TString Wplus125_old  = folder_name_old + "WplusH125" + file_name;
   TString Wminus125_old = folder_name_old + "WminusH125" + file_name;
   TString Z125_old      = folder_name_old + "ZH125" + file_name;
   TString qqZZ_old      = folder_name_old + "ZZTo4l" + file_name;
	
	
	// Run over old VBF samples (Moriond 2017, /170222/ production)
   histos_1D_old[Settings::M4l_DVBF2j] = new TH1F("h_VBF2j_old", "h_VBF2j_old", nbins, 0, 1);
	histos_1D_old[Settings::M4l_DVBF1j] = new TH1F("h_VBF1j_old", "h_VBF1j_old", nbins, 0, 1);
   histos_1D_old[Settings::M4l_DVH]    = new TH1F("h_VH_old", "h_VH_old", nbins, 0, 1);


   analyzer->LoopForEff(VBF125_old, lumi,shiftWP,only2jEvents,histos_1D_old);
	f->cd();
   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_VBF_old");
   histos_1D_old[Settings::M4l_DVBF2j]->Write();
	histos_1D_old[Settings::M4l_DVBF1j]->SetName("DVBF1j_VBF_old");
	histos_1D_old[Settings::M4l_DVBF1j]->Write();
   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_VBF_old");
   histos_1D_old[Settings::M4l_DVH]->Write();
   oldeff_Djj_VBF=histos_1D_old[Settings::M4l_DVBF2j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF2j]->Integral();
	oldeff_Dj_VBF=histos_1D_old[Settings::M4l_DVBF1j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF1j]->Integral();


   // Run over old POWHEG ggH125 samples (Moriond 2017, /170222/ production)
   histos_1D_old[Settings::M4l_DVBF2j]->Reset();
	histos_1D_old[Settings::M4l_DVBF1j]->Reset();
   histos_1D_old[Settings::M4l_DVH]->Reset();
   analyzer->LoopForEff(gg125_old, lumi,shiftWP,only2jEvents,histos_1D_old);
	f->cd();
   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_ggH_old");
   histos_1D_old[Settings::M4l_DVBF2j]->Write();
	histos_1D_old[Settings::M4l_DVBF1j]->SetName("DVBF1j_ggH_old");
	histos_1D_old[Settings::M4l_DVBF1j]->Write();
   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_ggH_old");
   histos_1D_old[Settings::M4l_DVH]->Write();
   oldeff_Djj_ggH=histos_1D_old[Settings::M4l_DVBF2j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF2j]->Integral();
	oldeff_Dj_ggH=histos_1D_old[Settings::M4l_DVBF1j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF1j]->Integral();
   oldeff_DVH_ggH=histos_1D_old[Settings::M4l_DVH]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVH]->Integral();


	// Run over old VH samples (Moriond 2017, /170222/ production)
   histos_1D_old[Settings::M4l_DVBF2j]->Reset();
	histos_1D_old[Settings::M4l_DVBF1j]->Reset();
   histos_1D_old[Settings::M4l_DVH]->Reset();
   analyzer->LoopForEff(Wplus125_old, lumi,shiftWP,only2jEvents,histos_1D_old);
   analyzer->LoopForEff(Wminus125_old, lumi,shiftWP,only2jEvents,histos_1D_old);
	if (mergeInto_VH) {analyzer->LoopForEff(Z125_old, lumi,shiftWP,only2jEvents,histos_1D_old);}
   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_WH_old");
   f->cd();
   histos_1D_old[Settings::M4l_DVBF2j]->Write();
	histos_1D_old[Settings::M4l_DVBF1j]->SetName("DVBF1j_WH_old");
	histos_1D_old[Settings::M4l_DVBF1j]->Write();
   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_WH_old");
   histos_1D_old[Settings::M4l_DVH]->Write();
   oldeff_DVH_WH=histos_1D_old[Settings::M4l_DVH]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVH]->Integral();

   if (!mergeInto_VH)
	{
		histos_1D_old[Settings::M4l_DVBF2j]->Reset();
		histos_1D_old[Settings::M4l_DVBF1j]->Reset();
		histos_1D_old[Settings::M4l_DVH]->Reset();
		analyzer->LoopForEff(Z125_old, lumi,shiftWP,only2jEvents,histos_1D_old);
		histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_ZH_old");
		f->cd();
		histos_1D_old[Settings::M4l_DVBF2j]->Write();
		histos_1D_old[Settings::M4l_DVBF1j]->SetName("DVBF1j_ZH_old");
		histos_1D_old[Settings::M4l_DVBF1j]->Write();
		histos_1D_old[Settings::M4l_DVH]->SetName("DVH_ZH_old");
		histos_1D_old[Settings::M4l_DVH]->Write();
		oldeff_DVH_ZH=histos_1D_old[Settings::M4l_DVH]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVH]->Integral();
	}


	// Run over old qqZZ samples (Moriond 2017, /170222/ production)
   histos_1D_old[Settings::M4l_DVBF2j]->Reset();
	histos_1D_old[Settings::M4l_DVBF1j]->Reset();
   histos_1D_old[Settings::M4l_DVH]->Reset();
   analyzer->LoopForEff(qqZZ_old, lumi,shiftWP,only2jEvents,histos_1D_old);
   histos_1D_old[Settings::M4l_DVBF2j]->SetName("DVBF2j_qqZZ_old");
   f->cd();
   histos_1D_old[Settings::M4l_DVBF2j]->Write();
	histos_1D_old[Settings::M4l_DVBF1j]->SetName("DVBF1j_qqZZ_old");
	histos_1D_old[Settings::M4l_DVBF1j]->Write();
   histos_1D_old[Settings::M4l_DVH]->SetName("DVH_qqZZ_old");
   histos_1D_old[Settings::M4l_DVH]->Write();
   oldeff_DVH_qqZZ=histos_1D_old[Settings::M4l_DVH]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVH]->Integral();
   oldeff_Djj_qqZZ=histos_1D_old[Settings::M4l_DVBF2j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF2j]->Integral();
	oldeff_Dj_qqZZ=histos_1D_old[Settings::M4l_DVBF1j]->Integral(nbins/2,nbins)/histos_1D_old[Settings::M4l_DVBF1j]->Integral();

   cout << "======================================================================================" << endl;
   cout << "Old efficincy of DVBF2j in VBF sample = " << oldeff_Djj_VBF << endl;
   cout << "Old efficincy of DVBF2j in ggH sample = " << oldeff_Djj_ggH << endl;
	cout << "Old efficincy of DVBF2j in qqZZ sample = " << oldeff_Djj_qqZZ << endl << endl;
	cout << "Old efficincy of DVBF1j in VBF sample = " << oldeff_Dj_VBF << endl;
	cout << "Old efficincy of DVBF1j in ggH sample = " << oldeff_Dj_ggH << endl;
	cout << "Old efficincy of DVBF1j in qqZZ sample = " << oldeff_Dj_qqZZ << endl << endl;
	if (mergeInto_VH) cout << "Old efficincy of DVH in VH samples = " << oldeff_DVH_WH << endl;
	else
	{
		cout << "Old efficincy of DVH in WH sample = " << oldeff_DVH_WH << endl;
		cout << "Old efficincy of DVH in ZH sample = " << oldeff_DVH_ZH << endl;
	}
	cout << "Old efficincy of DVH in ggH sample = " << oldeff_DVH_ggH << endl;
   cout << "Old efficincy of DVH in qqZZ sample = " << oldeff_DVH_qqZZ << endl;
	cout << "======================================================================================" << endl;
	
	
   TString VBF125_new           = folder_name_new + "VBFH125" + file_name;
	TString VBFTo4e_MCFM_new     = folder_name_new + "VBFTo4eJJ_0PMH125_phantom128" + file_name;
	TString VBFTo4mu_MCFM_new    = folder_name_new + "VBFTo4muJJ_0PMH125_phantom128" + file_name;
	TString VBFTo2e2mu_MCFM_new  = folder_name_new + "VBFTo2e2muJJ_0PMH125_phantom128" + file_name;
   TString gg125_new            = folder_name_new + "ggH125" + file_name;
	TString gg125_MiNLO_new      = folder_name_new + "ggH125_minloHJJ" + file_name;
	TString gg125_NNLOPS_new     = folder_name_new + "ggH125_NNLOPS" + file_name;
	TString ggTo4e_MCFM_new      = folder_name_new + "ggTo4e_0PMH125_MCFM701" + file_name;
	TString ggTo4mu_MCFM_new     = folder_name_new + "ggTo4mu_0PMH125_MCFM701" + file_name;
	TString ggTo4tau_MCFM_new    = folder_name_new + "ggTo4tau_0PMH125_MCFM701" + file_name;
	TString ggTo2e2mu_MCFM_new   = folder_name_new + "ggTo2e2mu_0PMH125_MCFM701" + file_name;
	TString ggTo2e2tau_MCFM_new  = folder_name_new + "ggTo2e2tau_0PMH125_MCFM701" + file_name;
	TString ggTo2mu2tau_MCFM_new = folder_name_new + "ggTo2mu2tau_0PMH125_MCFM701" + file_name;
   TString Wplus125_new         = folder_name_new + "WplusH125" + file_name;
   TString Wminus125_new        = folder_name_new + "WminusH125" + file_name;
   TString Z125_new             = folder_name_new + "ZH125" + file_name;
   TString qqZZ_new             = folder_name_new + "ZZTo4l" + file_name;
	TString qqZZext_new          = folder_name_new + "ZZTo4lext" + file_name;
   
   TH1F *histos_1D_new[Settings::num_of_1D_hist_names];
	
	TGraphErrors *gr_Djj_VBF,*gr_Djj_ggH,*gr_Djj_ggH_MiNLO,*gr_Djj_ggH_NNLOPS,*gr_Djj_ggH_MCFM,*gr_Djj_qqZZ;
	TGraphErrors *gr_Dj_VBF,*gr_Dj_ggH,*gr_Dj_ggH_MiNLO,*gr_Dj_ggH_NNLOPS,*gr_Dj_ggH_MCFM,*gr_Dj_qqZZ;
	TGraphErrors *gr_DVH_WH,*gr_DVH_ZH,*gr_DVH_ggH,*gr_DVH_ggH_MiNLO,*gr_DVH_ggH_NNLOPS,*gr_DVH_ggH_MCFM,*gr_DVH_qqZZ;
	
	TCanvas *c1;

	c1 = new TCanvas("c1","c1",900,900);

	Double_t x[nbins];
	Double_t y[nbins];
	Double_t x2[nbins];
	Double_t x3[nbins];
	Double_t ex[nbins];
	Double_t ey[nbins];
	
	// Run over new VBF sample
   histos_1D_new[Settings::M4l_DVBF2j] = new TH1F("h_VBF2j_new", "h_VBF2j_new", nbins, 0, 1);
	histos_1D_new[Settings::M4l_DVBF1j] = new TH1F("h_VBF1j_new", "h_VBF1j_new", nbins, 0, 1);
   histos_1D_new[Settings::M4l_DVH]    = new TH1F("h_VH_new", "h_VH_new", nbins, 0, 1);

   analyzer->LoopForEff(VBF125_new, lumi,shiftWP,only2jEvents,histos_1D_new);
   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_VBF_new");
   f->cd();
   histos_1D_new[Settings::M4l_DVBF2j]->Write();
	histos_1D_new[Settings::M4l_DVBF1j]->SetName("DVBF1j_VBF_new");
	histos_1D_new[Settings::M4l_DVBF1j]->Write();
   histos_1D_new[Settings::M4l_DVH]->SetName("DVH_VBF_new");
   histos_1D_new[Settings::M4l_DVH]->Write();


   for( int i = 1; i <= nbins; i++)
   {
      y[i-1] = i/float(nbins);
      x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
		x2[i-1] = histos_1D_new[Settings::M4l_DVBF1j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF1j]->Integral();
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
	
	gr_Dj_VBF = new TGraphErrors(nbins,x2,y,ex,ey);
	gr_Dj_VBF->SetTitle("TGraphErrors Example");
	gr_Dj_VBF->SetName("gr_Dj_VBF");
	f->cd();
	gr_Dj_VBF->Write();
	gr_Dj_VBF->SetMarkerColor(kRed);
	gr_Dj_VBF->SetMarkerStyle(1);

   histos_1D_new[Settings::M4l_DVBF2j]->Reset();
	histos_1D_new[Settings::M4l_DVBF1j]->Reset();
   histos_1D_new[Settings::M4l_DVH]->Reset();


	// Run over new ggH POWHEG sample
   analyzer->LoopForEff(gg125_new, lumi,shiftWP,only2jEvents,histos_1D_new);
   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_ggH_new");
   f->cd();
   histos_1D_new[Settings::M4l_DVBF2j]->Write();
	histos_1D_new[Settings::M4l_DVBF1j]->SetName("DVBF1j_ggH_new");
	histos_1D_new[Settings::M4l_DVBF1j]->Write();
   histos_1D_new[Settings::M4l_DVH]->SetName("DVH_ggH_new");
   histos_1D_new[Settings::M4l_DVH]->Write();

   for( int i = 1; i <= nbins; i++)
   {
      y[i-1] = i/float(nbins);
      x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
		x2[i-1] = histos_1D_new[Settings::M4l_DVBF1j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF1j]->Integral();
      x3[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
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
	
	gr_Dj_ggH = new TGraphErrors(nbins,x2,y,ex,ey);
	gr_Dj_ggH->SetTitle("TGraphErrors Example");
	gr_Dj_ggH->SetName("gr_Dj_ggH");
	f->cd();
	gr_Dj_ggH->Write();
	gr_Dj_ggH->SetMarkerColor(kBlack);
	gr_Dj_ggH->SetMarkerStyle(1);

   gr_DVH_ggH = new TGraphErrors(nbins,x3,y,ex,ey);
   gr_DVH_ggH->SetTitle("TGraphErrors Example");
   gr_DVH_ggH->SetName("gr_DVH_ggH");
   f->cd();
   gr_DVH_ggH->Write();
   gr_DVH_ggH->SetMarkerColor(kBlack);
   gr_DVH_ggH->SetMarkerStyle(1);


   histos_1D_new[Settings::M4l_DVBF2j]->Reset();
	histos_1D_new[Settings::M4l_DVBF1j]->Reset();
   histos_1D_new[Settings::M4l_DVH]->Reset();

	// Run over new ggH NNLOPS sample
	analyzer->LoopForEff(gg125_NNLOPS_new, lumi,shiftWP,only2jEvents,histos_1D_new);
	histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_ggH_NNLOPS_new");
	f->cd();
	histos_1D_new[Settings::M4l_DVBF2j]->Write();
	histos_1D_new[Settings::M4l_DVBF1j]->SetName("DVBF1j_ggH_NNLOPS_new");
	histos_1D_new[Settings::M4l_DVBF1j]->Write();
	histos_1D_new[Settings::M4l_DVH]->SetName("DVH_ggH_NNLOPS_new");
	histos_1D_new[Settings::M4l_DVH]->Write();

	for( int i = 1; i <= nbins; i++)
	{
		y[i-1] = i/float(nbins);
		x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
		x2[i-1] = histos_1D_new[Settings::M4l_DVBF1j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF1j]->Integral();
		x3[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
		ex[i-1] = 0;
		ey[i-1] = 0;
	}
	gr_Djj_ggH_NNLOPS = new TGraphErrors(nbins,x,y,ex,ey);
	gr_Djj_ggH_NNLOPS->SetTitle("TGraphErrors Example");
	gr_Djj_ggH_NNLOPS->SetName("gr_Djj_ggH_NNLOPS");
	f->cd();
	gr_Djj_ggH_NNLOPS->Write();
	gr_Djj_ggH_NNLOPS->SetMarkerColor(kYellow + 3);
	gr_Djj_ggH_NNLOPS->SetMarkerStyle(1);
	
	gr_Dj_ggH_NNLOPS = new TGraphErrors(nbins,x2,y,ex,ey);
	gr_Dj_ggH_NNLOPS->SetTitle("TGraphErrors Example");
	gr_Dj_ggH_NNLOPS->SetName("gr_Dj_ggH_NNLOPS");
	f->cd();
	gr_Dj_ggH_NNLOPS->Write();
	gr_Dj_ggH_NNLOPS->SetMarkerColor(kYellow + 3);
	gr_Dj_ggH_NNLOPS->SetMarkerStyle(1);

	gr_DVH_ggH_NNLOPS = new TGraphErrors(nbins,x3,y,ex,ey);
	gr_DVH_ggH_NNLOPS->SetTitle("TGraphErrors Example");
	gr_DVH_ggH_NNLOPS->SetName("gr_DVH_ggH_NNLOPS");
	f->cd();
	gr_DVH_ggH_NNLOPS->Write();
	gr_DVH_ggH_NNLOPS->SetMarkerColor(kYellow + 3);
	gr_DVH_ggH_NNLOPS->SetMarkerStyle(1);


	histos_1D_new[Settings::M4l_DVBF2j]->Reset();
	histos_1D_new[Settings::M4l_DVBF1j]->Reset();
	histos_1D_new[Settings::M4l_DVH]->Reset();

	// Run over new ggH MiNLO sample
	analyzer->LoopForEff(gg125_MiNLO_new, lumi,shiftWP,only2jEvents,histos_1D_new);
	histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_ggH_MiNLO_new");
	f->cd();
	histos_1D_new[Settings::M4l_DVBF2j]->Write();
	histos_1D_new[Settings::M4l_DVBF1j]->SetName("DVBF1j_ggH_MiNLO_new");
	histos_1D_new[Settings::M4l_DVBF1j]->Write();
	histos_1D_new[Settings::M4l_DVH]->SetName("DVH_ggH_MiNLO_new");
	histos_1D_new[Settings::M4l_DVH]->Write();

	for( int i = 1; i <= nbins; i++)
	{
		y[i-1] = i/float(nbins);
		x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
		x2[i-1] = histos_1D_new[Settings::M4l_DVBF1j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF1j]->Integral();
		x3[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
		ex[i-1] = 0;
		ey[i-1] = 0;
	}
	gr_Djj_ggH_MiNLO = new TGraphErrors(nbins,x,y,ex,ey);
	gr_Djj_ggH_MiNLO->SetTitle("TGraphErrors Example");
	gr_Djj_ggH_MiNLO->SetName("gr_Djj_ggH_MiNLO");
	f->cd();
	gr_Djj_ggH_MiNLO->Write();
	gr_Djj_ggH_MiNLO->SetMarkerColor(kGray);
	gr_Djj_ggH_MiNLO->SetMarkerStyle(1);
	
	gr_Dj_ggH_MiNLO = new TGraphErrors(nbins,x2,y,ex,ey);
	gr_Dj_ggH_MiNLO->SetTitle("TGraphErrors Example");
	gr_Dj_ggH_MiNLO->SetName("gr_Dj_ggH_MiNLO");
	f->cd();
	gr_Dj_ggH_MiNLO->Write();
	gr_Dj_ggH_MiNLO->SetMarkerColor(kGray);
	gr_Dj_ggH_MiNLO->SetMarkerStyle(1);

	gr_DVH_ggH_MiNLO = new TGraphErrors(nbins,x3,y,ex,ey);
	gr_DVH_ggH_MiNLO->SetTitle("TGraphErrors Example");
	gr_DVH_ggH_MiNLO->SetName("gr_DVH_ggH_MiNLO");
	f->cd();
	gr_DVH_ggH_MiNLO->Write();
	gr_DVH_ggH_MiNLO->SetMarkerColor(kGray);
	gr_DVH_ggH_MiNLO->SetMarkerStyle(1);


	histos_1D_new[Settings::M4l_DVBF2j]->Reset();
	histos_1D_new[Settings::M4l_DVBF1j]->Reset();
	histos_1D_new[Settings::M4l_DVH]->Reset();
	
	// Run over new ggH MCFM sample
	if ( includeMCFM )
	{
		analyzer->LoopForEff(ggTo4e_MCFM_new, lumi,shiftWP,only2jEvents,histos_1D_new);
		analyzer->LoopForEff(ggTo4mu_MCFM_new, lumi,shiftWP,only2jEvents,histos_1D_new);
		analyzer->LoopForEff(ggTo2e2mu_MCFM_new, lumi,shiftWP,only2jEvents,histos_1D_new);
		analyzer->LoopForEff(ggTo2e2tau_MCFM_new, lumi,shiftWP,only2jEvents,histos_1D_new);
		analyzer->LoopForEff(ggTo2mu2tau_MCFM_new, lumi,shiftWP,only2jEvents,histos_1D_new);
		analyzer->LoopForEff(ggTo4tau_MCFM_new, lumi,shiftWP,only2jEvents,histos_1D_new);
		
		histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_ggH_MCFM_new");
		f->cd();
		histos_1D_new[Settings::M4l_DVBF2j]->Write();
		histos_1D_new[Settings::M4l_DVBF1j]->SetName("DVBF1j_ggH_MCFM_new");
		histos_1D_new[Settings::M4l_DVBF1j]->Write();
		histos_1D_new[Settings::M4l_DVH]->SetName("DVH_ggH_MCFM_new");
		histos_1D_new[Settings::M4l_DVH]->Write();
		
		for( int i = 1; i <= nbins; i++)
		{
			y[i-1] = i/float(nbins);
			x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
			x2[i-1] = histos_1D_new[Settings::M4l_DVBF1j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF1j]->Integral();
			x3[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
			ex[i-1] = 0;
			ey[i-1] = 0;
		}
		gr_Djj_ggH_MCFM = new TGraphErrors(nbins,x,y,ex,ey);
		gr_Djj_ggH_MCFM->SetTitle("TGraphErrors Example");
		gr_Djj_ggH_MCFM->SetName("gr_Djj_ggH_MCFM");
		f->cd();
		gr_Djj_ggH_MCFM->Write();
		gr_Djj_ggH_MCFM->SetMarkerColor(kGreen - 8);
		gr_Djj_ggH_MCFM->SetMarkerStyle(1);
		
		gr_Dj_ggH_MCFM = new TGraphErrors(nbins,x2,y,ex,ey);
		gr_Dj_ggH_MCFM->SetTitle("TGraphErrors Example");
		gr_Dj_ggH_MCFM->SetName("gr_Dj_ggH_MCFM");
		f->cd();
		gr_Dj_ggH_MCFM->Write();
		gr_Dj_ggH_MCFM->SetMarkerColor(kGreen - 8);
		gr_Dj_ggH_MCFM->SetMarkerStyle(1);
		
		gr_DVH_ggH_MCFM = new TGraphErrors(nbins,x3,y,ex,ey);
		gr_DVH_ggH_MCFM->SetTitle("TGraphErrors Example");
		gr_DVH_ggH_MCFM->SetName("gr_DVH_ggH_MCFM");
		f->cd();
		gr_DVH_ggH_MCFM->Write();
		gr_DVH_ggH_MCFM->SetMarkerColor(kGreen - 8);
		gr_DVH_ggH_MCFM->SetMarkerStyle(1);
		
		
		histos_1D_new[Settings::M4l_DVBF2j]->Reset();
		histos_1D_new[Settings::M4l_DVBF1j]->Reset();
		histos_1D_new[Settings::M4l_DVH]->Reset();
	}
   
	
	// Run over new VH samples
   analyzer->LoopForEff(Wplus125_new, lumi,shiftWP,only2jEvents,histos_1D_new);
   analyzer->LoopForEff(Wminus125_new, lumi,shiftWP,only2jEvents,histos_1D_new);
	if (mergeInto_VH) {analyzer->LoopForEff(Z125_new, lumi,shiftWP,only2jEvents,histos_1D_new);}
   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_WH_new");
   f->cd();
   histos_1D_new[Settings::M4l_DVBF2j]->Write();
	histos_1D_new[Settings::M4l_DVBF1j]->SetName("DVBF1j_WH_new");
	histos_1D_new[Settings::M4l_DVBF1j]->Write();
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
	histos_1D_new[Settings::M4l_DVBF1j]->Reset();
	histos_1D_new[Settings::M4l_DVH]->Reset();
	
	if(!mergeInto_VH)
	{
		analyzer->LoopForEff(Z125_new, lumi,shiftWP,only2jEvents,histos_1D_new);
		histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_ZH_new");
		f->cd();
		histos_1D_new[Settings::M4l_DVBF2j]->Write();
		histos_1D_new[Settings::M4l_DVBF1j]->SetName("DVBF1j_ZH_new");
		histos_1D_new[Settings::M4l_DVBF1j]->Write();
		histos_1D_new[Settings::M4l_DVH]->SetName("DVH_ZH_new");
		histos_1D_new[Settings::M4l_DVH]->Write();
		
		for( int i = 1; i <= nbins; i++)
		{
			y[i-1] = i/float(nbins);
			x[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
			ex[i-1] = 0;
			ey[i-1] = 0;
		}
		gr_DVH_ZH = new TGraphErrors(nbins,x,y,ex,ey);
		gr_DVH_ZH->SetTitle("TGraphErrors Example");
		gr_DVH_ZH->SetName("gr_DVH_ZH");
		f->cd();
		gr_DVH_ZH->Write();
		gr_DVH_ZH->SetMarkerColor(kYellow);
		gr_DVH_ZH->SetMarkerStyle(1);

	}
	
   
   histos_1D_new[Settings::M4l_DVBF2j]->Reset();
	histos_1D_new[Settings::M4l_DVBF1j]->Reset();
   histos_1D_new[Settings::M4l_DVH]->Reset();
   
	
	// Run over new qqZZ sample
   analyzer->LoopForEff(qqZZ_new, lumi,shiftWP,only2jEvents,histos_1D_new);
	if (useqqZZ_ext) { analyzer->LoopForEff(qqZZext_new, lumi,shiftWP,only2jEvents,histos_1D_new);}
   histos_1D_new[Settings::M4l_DVBF2j]->SetName("DVBF2j_qqZZ_new");
   f->cd();
   histos_1D_new[Settings::M4l_DVBF2j]->Write();
	histos_1D_new[Settings::M4l_DVBF1j]->SetName("DVBF1j_qqZZ_new");
	histos_1D_new[Settings::M4l_DVBF1j]->Write();
   histos_1D_new[Settings::M4l_DVH]->SetName("DVH_qqZZ_new");
   histos_1D_new[Settings::M4l_DVH]->Write();
   
   for( int i = 1; i <= nbins; i++)
   {
      y[i-1] = i/float(nbins);
      x[i-1] = histos_1D_new[Settings::M4l_DVBF2j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF2j]->Integral();
		x2[i-1] = histos_1D_new[Settings::M4l_DVBF1j]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVBF1j]->Integral();
      x3[i-1] = histos_1D_new[Settings::M4l_DVH]->Integral(i,nbins)/histos_1D_new[Settings::M4l_DVH]->Integral();
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
	
	gr_Dj_qqZZ = new TGraphErrors(nbins,x2,y,ex,ey);
	gr_Dj_qqZZ->SetTitle("TGraphErrors Example");
	gr_Dj_qqZZ->SetName("gr_Dj_qqZZ");
	f->cd();
	gr_Dj_qqZZ->Write();
	gr_Dj_qqZZ->SetMarkerColor(kGreen);
	gr_Dj_qqZZ->SetMarkerStyle(1);
   
   gr_DVH_qqZZ = new TGraphErrors(nbins,x3,y,ex,ey);
   gr_DVH_qqZZ->SetTitle("TGraphErrors Example");
   gr_DVH_qqZZ->SetName("gr_DVH_qqZZ");
   f->cd();
   gr_DVH_qqZZ->Write();
   gr_DVH_qqZZ->SetMarkerColor(kGreen);
   gr_DVH_qqZZ->SetMarkerStyle(1);
   
	
	// Draw everything on a multigraph for D_2jet
   c1->cd();
   TMultiGraph *mg = new TMultiGraph();
   gr_Djj_VBF->SetTitle("VBF");
   gr_Djj_VBF->SetLineColor(kRed);
   mg->Add(gr_Djj_VBF);
   gr_Djj_ggH->SetTitle("ggH POWHEG");
   mg->Add(gr_Djj_ggH);
	gr_Djj_ggH_MiNLO->SetTitle("ggH MiNLO");
	mg->Add(gr_Djj_ggH_MiNLO);
	gr_Djj_ggH_NNLOPS->SetTitle("ggH NNLOPS");
	mg->Add(gr_Djj_ggH_NNLOPS);
	if ( includeMCFM )gr_Djj_ggH_MCFM->SetTitle("ggH MCFM");
	if ( includeMCFM )gr_Djj_ggH_MCFM->SetLineStyle(4);
	if ( includeMCFM )mg->Add(gr_Djj_ggH_MCFM);
   gr_Djj_qqZZ->SetTitle("qqZZ");
   gr_Djj_qqZZ->SetLineColor(kGreen);
   mg->Add(gr_Djj_qqZZ);
   mg->Draw("apl");
   mg->SetMaximum(1.);
   mg->GetXaxis()->SetRangeUser(0., 0.8);
	if(only2jEvents) mg->GetXaxis()->SetRangeUser(0., 1.0);
   mg->GetYaxis()->SetTitle("Cut value");
   mg->GetXaxis()->SetTitle("D_{2jets}^{VBF}   eff");
   TLegend *leg = new TLegend(0.65, 0.75, 0.90, 0.90);
   leg->AddEntry(gr_Djj_VBF,"VBF","pl");
   leg->AddEntry(gr_Djj_ggH,"ggH POWHEG","pl");
	leg->AddEntry(gr_Djj_ggH_MiNLO,"ggH MiNLO","pl");
	leg->AddEntry(gr_Djj_ggH_NNLOPS,"ggH NNLOPS","pl");
	if ( includeMCFM )leg->AddEntry(gr_Djj_ggH_MCFM,"ggH MCFM","pl");
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
	if(only2jEvents)
	{
		c1->SaveAs("ControlPlots/DVBF2jetVsCut_2jEvents.pdf");
		c1->SaveAs("ControlPlots/DVBF2jetVsCut_2jEvents.png");
	}
	else
	{
		c1->SaveAs("ControlPlots/DVBF2jetVsCut_AllEvents.pdf");
		c1->SaveAs("ControlPlots/DVBF2jetVsCut_AllEvents.png");
	}

	
	// Draw everything on a multigraph for D_1jet
	c1->cd();
	TMultiGraph *mg2 = new TMultiGraph();
	gr_Dj_VBF->SetTitle("VBF");
	gr_Dj_VBF->SetLineColor(kRed);
	mg2->Add(gr_Dj_VBF);
	gr_Dj_ggH->SetTitle("ggH POWHEG");
	mg2->Add(gr_Dj_ggH);
	gr_Dj_ggH_MiNLO->SetTitle("ggH MiNLO");
	mg2->Add(gr_Dj_ggH_MiNLO);
	gr_Dj_ggH_NNLOPS->SetTitle("ggH NNLOPS");
	mg2->Add(gr_Dj_ggH_NNLOPS);
	if ( includeMCFM )gr_Dj_ggH_MCFM->SetTitle("ggH MCFM");
	if ( includeMCFM )gr_Dj_ggH_MCFM->SetLineStyle(4);
	if ( includeMCFM )mg2->Add(gr_Dj_ggH_MCFM);
	gr_Dj_qqZZ->SetTitle("qqZZ");
	gr_Dj_qqZZ->SetLineColor(kGreen);
	mg2->Add(gr_Dj_qqZZ);
	mg2->Draw("apl");
	mg2->SetMaximum(1.);
	mg2->GetXaxis()->SetRangeUser(0., 0.8);
	if(only2jEvents) mg2->GetXaxis()->SetRangeUser(0., 1.0);
	mg2->GetYaxis()->SetTitle("Cut value");
	mg2->GetXaxis()->SetTitle("D_{1jet}^{VBF}   eff");
	TLegend *leg2 = new TLegend(0.65, 0.75, 0.90, 0.90);
	leg2->AddEntry(gr_Dj_VBF,"VBF","pl");
	leg2->AddEntry(gr_Dj_ggH,"ggH POWHEG","pl");
	leg2->AddEntry(gr_Dj_ggH_MiNLO,"ggH MiNLO","pl");
	leg2->AddEntry(gr_Dj_ggH_NNLOPS,"ggH NNLOPS","pl");
	if ( includeMCFM )leg2->AddEntry(gr_Dj_ggH_MCFM,"ggH MCFM","pl");
	leg2->AddEntry(gr_Dj_qqZZ,"qqZZ","pl");
	leg2->Draw();
	
	TLine *line20 = new TLine(0,0.5,1,0.5);
	line20->SetLineColor(kBlack);
	line20->SetLineStyle(2);
	line20->Draw();
	TLine *line21 = new TLine(oldeff_Dj_VBF,0,oldeff_Dj_VBF,1);
	line21->SetLineColor(kRed);
	line21->SetLineStyle(2);
	line21->Draw();
	TLine *line22 = new TLine(oldeff_Dj_ggH,0,oldeff_Dj_ggH,1);
	line22->SetLineColor(kBlack);
	line22->SetLineStyle(2);
	line22->Draw();
	TLine *line22b = new TLine(oldeff_Dj_qqZZ,0,oldeff_Dj_qqZZ,1);
	line22b->SetLineColor(kGreen);
	line22b->SetLineStyle(2);
	line22b->Draw();
	if(only2jEvents)
	{
		c1->SaveAs("ControlPlots/DVBF1JetVsCut_2jEvents.pdf");
		c1->SaveAs("ControlPlots/DVBF1JetVsCut_2jEvents.png");
	}
	else
	{
		c1->SaveAs("ControlPlots/DVBF1JetVsCut_AllEvents.pdf");
		c1->SaveAs("ControlPlots/DVBF1JetVsCut_AllEvents.png");
	}

   
   
   // Draw everything on a multigraph for D_VH
   c1->Clear();
   c1->cd();
   TMultiGraph *mg3 = new TMultiGraph();
	if( !mergeInto_VH)
	{
		gr_DVH_ZH->SetTitle("ZH");
		gr_DVH_ZH->SetLineColor(kYellow);
		mg3->Add(gr_DVH_ZH);
	}
   gr_DVH_WH->SetTitle("WH");
   gr_DVH_WH->SetLineColor(kBlue);
   mg3->Add(gr_DVH_WH);
	gr_DVH_ggH->SetTitle("ggH POWHEG");
	mg3->Add(gr_DVH_ggH);
	gr_DVH_ggH_MiNLO->SetTitle("ggH MiNLO");
	mg3->Add(gr_DVH_ggH_MiNLO);
	gr_DVH_ggH_NNLOPS->SetTitle("ggH NNLOPS");
	mg3->Add(gr_DVH_ggH_NNLOPS);
	if ( includeMCFM )gr_DVH_ggH_MCFM->SetTitle("ggH MCFM");
	if ( includeMCFM )gr_DVH_ggH_MCFM->SetLineStyle(4);
	if ( includeMCFM )mg3->Add(gr_DVH_ggH_MCFM);
   gr_DVH_qqZZ->SetTitle("qqZZ");
   gr_DVH_qqZZ->SetLineColor(kGreen);
   mg3->Add(gr_DVH_qqZZ);
   mg3->Draw("apl");
   mg3->SetMaximum(1.);
   mg3->GetXaxis()->SetRangeUser(0., 0.6);
	if(only2jEvents) mg3->GetXaxis()->SetRangeUser(0., 1.0);
   mg3->GetYaxis()->SetTitle("Cut value");
   mg3->GetXaxis()->SetTitle("D_{2jets}^{VH}   eff");
   TLegend *leg3 = new TLegend(0.65, 0.75, 0.90, 0.90);
	leg3->AddEntry(gr_DVH_ggH,"ggH POWHEG","pl");
	leg3->AddEntry(gr_DVH_ggH_MiNLO,"ggH MiNLO","pl");
	leg3->AddEntry(gr_DVH_ggH_NNLOPS,"ggH NNLOPS","pl");
	if ( includeMCFM )leg3->AddEntry(gr_DVH_ggH_MCFM,"ggH MCFM","pl");
   if( mergeInto_VH) leg3->AddEntry(gr_DVH_WH,"VH","pl");
	else leg3->AddEntry(gr_DVH_WH,"WH","pl");
	if( !mergeInto_VH) leg3->AddEntry(gr_DVH_ZH,"ZH","pl");
   leg3->AddEntry(gr_DVH_qqZZ,"qqZZ","pl");
   leg3->Draw();
   
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
	if ( !mergeInto_VH)
	{
		TLine *line5 = new TLine(oldeff_DVH_ZH,0,oldeff_DVH_ZH,1);
		line5->SetLineColor(kYellow);
		line5->SetLineStyle(2);
		line5->Draw();
	}
	if(only2jEvents)
	{
		c1->SaveAs("ControlPlots/DVHVsCut_2jEvents.pdf");
		c1->SaveAs("ControlPlots/DVHVsCut_2jEvents.png");
	}
	else
	{
		c1->SaveAs("ControlPlots/DVHVsCut_AllEvents.pdf");
		c1->SaveAs("ControlPlots/DVHVsCut_AllEvents.png");
	}
	
	
   // Print out efficiencies and WPs
   cout << "======================================================================================" << endl;
   cout << "To match old efficiency of DVBF2j in VBF (" << oldeff_Djj_VBF << ") cut should be = " << gr_Djj_VBF->Eval(oldeff_Djj_VBF) << endl;
	cout << "To match old efficiency of DVBF2j in ggH (" << oldeff_Djj_ggH << ") cut should be = " << gr_Djj_ggH->Eval(oldeff_Djj_ggH) << endl << endl;
	
	cout << "To match old efficiency of DVBF1j in VBF (" << oldeff_Dj_VBF << ") cut should be = " << gr_Dj_VBF->Eval(oldeff_Dj_VBF) << endl;
	cout << "To match old efficiency of DVBF1j in ggH (" << oldeff_Dj_ggH << ") cut should be = " << gr_Dj_ggH->Eval(oldeff_Dj_ggH) << endl << endl;

   if(mergeInto_VH)cout << "To match old efficiency of DVH in VH (" << oldeff_DVH_WH << ") cut should be = " << gr_DVH_WH->Eval(oldeff_DVH_WH) << endl;
	else
	{
		cout << "To match old efficiency of DVH in WH (" << oldeff_DVH_WH << ") cut should be = " << gr_DVH_WH->Eval(oldeff_DVH_WH) << endl;
      cout << "To match old efficiency of DVH in ZH (" << oldeff_DVH_ZH << ") cut should be = " << gr_DVH_ZH->Eval(oldeff_DVH_ZH) << endl;
	}
	cout << "To match old efficiency of DVH in ggH (" << oldeff_DVH_ggH << ") cut should be = " << gr_DVH_ggH->Eval(oldeff_DVH_ggH) << endl;
   cout << "=======================================================================================" << endl;
   
//   cout << "======================================================================================" << endl;
//   cout << "Efficiency of DVBF2j in VBF = " << gr_Djj_VBF->Eval(0.5) << endl;
//	cout << "Efficiency of DVBF2j in ggH = " << gr_Djj_ggH->Eval(0.5) << endl;
//   cout << "Efficiency of DVBF2j in qqZZ = " << gr_Djj_qqZZ->Eval(0.5) << endl << endl;
//
//	if ( mergeInto_VH) cout << "Efficiency of DVH in ZH = " << gr_DVH_WH->Eval(0.5) << endl;
//	else
//	{
//		cout << "Efficiency of DVH in WH = " << gr_DVH_WH->Eval(0.5) << endl;
//		cout << "Efficiency of DVH in ZH = " << gr_DVH_ZH->Eval(0.5) << endl;
//	}
//	cout << "Efficiency of DVH in ggH = " << gr_DVH_ggH->Eval(0.5) << endl;
//   cout << "Efficiency of DVH in qqZZ = " << gr_DVH_qqZZ->Eval(0.5) << endl;
//   cout << "=======================================================================================" << endl;
	
   f->Close();
   delete f;
   
}
