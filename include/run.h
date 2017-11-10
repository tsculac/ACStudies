#ifndef run_h
#define run_h

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
#include "Settings.h"

void ResetHistos(TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void WriteHistos(TString sample, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void DoVBFLoop(bool doOnly2jEvents, double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void DoggHLoop(bool doOnly2jEvents, double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void DoqqZZLoop(bool doOnly2jEvents, double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void DoWHLoop(bool doOnly2jEvents, double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void DoZHLoop(bool doOnly2jEvents, double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void Do0MHLoop(bool doOnly2jEvents, double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void Do0PHLoop(bool doOnly2jEvents, double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);
void Do0PL1Loop(bool doOnly2jEvents, double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names]);

Functions *functions = new Functions();

TString folder_name = "root://lxcms03//data3/Higgs/171005/";
//TString folder_name = "root://lxcms03//data3/Higgs/170623/";
//TString folder_name = "root://lxcms03//data3/Higgs/170222/";
TString file_name   = "/ZZ4lAnalysis.root";

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

//==================================================================
//
//    ggH SAMPLES
//
//==================================================================

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
TString ggTo4e_MCFM     = folder_name + "ggTo4e_0PMH125_MCFM701" + file_name;
TString ggTo4mu_MCFM    = folder_name + "ggTo4mu_0PMH125_MCFM701" + file_name;
TString ggTo2e2mu_MCFM  = folder_name + "ggTo2e2mu_0PMH125_MCFM701" + file_name;

//==================================================================
//
//    qqZZ BACKGROUND
//
//==================================================================

TString qqZZ = folder_name + "ZZTo4l" + file_name;
TString qqZZext = folder_name + "ZZTo4lext" + file_name;

//==================================================================
//
//    WH SAMPLES
//
//==================================================================

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

//==================================================================
//
//    ZH SAMPLES
//
//==================================================================

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
TString Z210 = folder_name + "ZH210" + file_name;
TString Z230 = folder_name + "ZH230" + file_name;

//==================================================================
//
//    BSM SIGNAL SAMPLES
//
//==================================================================

TString ggTo4e_0MH     = folder_name + "ggTo4e_0MH125_MCFM701" + file_name;
TString ggTo4mu_0MH    = folder_name + "ggTo4mu_0MH125_MCFM701" + file_name;
TString ggTo2e2mu_0MH  = folder_name + "ggTo2e2mu_0MH125_MCFM701" + file_name;

TString ggTo4e_0PH     = folder_name + "ggTo4e_0PHH125_MCFM701" + file_name;
TString ggTo4mu_0PH    = folder_name + "ggTo4mu_0PHH125_MCFM701" + file_name;
TString ggTo2e2mu_0PH  = folder_name + "ggTo2e2mu_0PHH125_MCFM701" + file_name;

TString ggTo4e_0PL1     = folder_name + "ggTo4e_0PL1H125_MCFM701" + file_name;
TString ggTo4mu_0PL1    = folder_name + "ggTo4mu_0PL1H125_MCFM701" + file_name;
TString ggTo2e2mu_0PL1  = folder_name + "ggTo2e2mu_0PL1H125_MCFM701" + file_name;



#endif
