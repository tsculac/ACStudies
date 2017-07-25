// My own files
#include "run.h"

using namespace std;

int main( int argc, char *argv[] )
{
   Float_t  lumi = 35.8;
   
   TH1F *histos_1D[Settings::num_of_1D_hist_names];
   TH2F *histos_2D[Settings::num_of_2D_hist_names];
   
   Int_t   m4l_bins     = 18;
   Double_t m4l_slices[] = {110,140,150,160,170,180,190,200,250,300,400,500,600,700,800,900,1000,2000,3000};
   
   Int_t   m4l_bins2     = 10;
   Double_t m4l_slices2[] = {110,125,130,140,150,160,170,180,190,200,250};
   
   Int_t   m4l_bins3     = 12;
   Double_t m4l_slices3[] = {110,140,180,220,300,400,500,600,700,800,1000,2000,3000};
   
//   //=======================================================
//   // FOR SPLINES
//   //=======================================================
//   Int_t   m4l_bins     = 9;
//   Double_t m4l_slices[] = {100,200,300,400,600,800,900,1000,2000,3500};
//   
//   Int_t m4l_bins_spec  = 8;
//   Double_t m4l_slices_spec[] = {150,270,400,600,800,900,1000,2000,3500};
//   
//   Int_t   m4l_bins2     = 4;
//   Double_t m4l_slices2[] = {110,130,160,190,250};
//   //=======================================================
   
   TProfile *p       = new TProfile("p","p",m4l_bins, m4l_slices);
   
   histos_1D[Settings::M4l_allevents] = new TH1F("h", "h", m4l_bins, m4l_slices);
   histos_1D[Settings::M4l_DVBF2j] = new TH1F("h_VBF2j", "h_VBF2j", m4l_bins, m4l_slices);
   histos_1D[Settings::M4l_DVH]    = new TH1F("h_VH", "h_VH", m4l_bins, m4l_slices);

   histos_2D[Settings::D_VBF2j]   = new TH2F("DVBF2jVsM4l",   "DVBF2jVsM4l", m4l_bins, m4l_slices, 100, 0., 1.);
   histos_2D[Settings::D_VH]      = new TH2F("DVHVsM4l",   "DVHVsM4l", m4l_bins, m4l_slices, 100, 0., 1.);
   histos_2D[Settings::D_BKG_DEC] = new TH2F("DBKGDECVsM4l",   "DBKGDECVsM4l", m4l_bins3, m4l_slices3, 100, 0., 1.);
//   histos_2D[Settings::D_BKG_DEC] = new TH2F("DBKGDECVsM4l",   "DBKGDECVsM4l", m4l_bins, m4l_slices, 100, 0., 1.);//for checks
   histos_2D[Settings::D_0M_DEC]  = new TH2F("D0MDECVsM4l",   "D0MDECVsM4l", m4l_bins3, m4l_slices3, 100, 0., 1.);
   histos_2D[Settings::D_0hP_DEC]  = new TH2F("D0PDECVsM4l",  "D0PDECVsM4l", m4l_bins3, m4l_slices3, 100, 0., 1.);
   histos_2D[Settings::D_L1_DEC]  = new TH2F("DL1DECVsM4l",   "DL1DECVsM4l", m4l_bins3, m4l_slices3, 100, 0., 1.);
   histos_2D[Settings::D_L1Zgs_DEC]  = new TH2F("DL1ZgsDECVsM4l","DL1ZgsDECVsM4l", m4l_bins3, m4l_slices3, 100, 0., 1.);
   
   TFile *fOutControlHistos = new TFile("DVsM4l.root", "recreate");
   
   TCanvas *c1,*c2, *c3;
   c1 = new TCanvas("c1","c1",900,700);
   c2 = new TCanvas("c2","c2",900,700);
   c3 = new TCanvas("c3","c3",900,700);
   
   //==================================================================
   //
   //    VBF SAMPLES
   //
   //==================================================================
   ResetHistos(p, histos_1D, histos_2D);
   DoVBFLoop(lumi, p, histos_1D, histos_2D);
   
   TGraphErrors *VBF_Djj_tgraph,*VBF_DVH_tgraph;
   
   histos_1D[Settings::M4l_DVBF2j]->Divide(histos_1D[Settings::M4l_allevents]);
   histos_1D[Settings::M4l_DVH]->Divide(histos_1D[Settings::M4l_allevents]);
   VBF_Djj_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVBF2j] , "VBF_Djj_tgraph");
   VBF_DVH_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVH]    , "VBF_DVH_tgraph");
   
   fOutControlHistos->cd();
   WriteHistos("VBF", histos_1D, histos_2D);
   //==================================================================
   //
   //    ggH SAMPLES
   //
   //==================================================================
   ResetHistos(p, histos_1D, histos_2D);
   DoggHLoop(lumi, p, histos_1D, histos_2D);
   
   TGraphErrors *ggH_Djj_tgraph,*ggH_DVH_tgraph;
   
   histos_1D[Settings::M4l_DVBF2j]->Divide(histos_1D[Settings::M4l_allevents]);
   histos_1D[Settings::M4l_DVH]->Divide(histos_1D[Settings::M4l_allevents]);
   ggH_Djj_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVBF2j] , "ggH_Djj_tgraph");
   ggH_DVH_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVH] , "ggH_DVH_tgraph");

   fOutControlHistos->cd();
   WriteHistos("ggH", histos_1D, histos_2D);
   //==================================================================
   //
   //    qqZZ BACKGROUND
   //
   //==================================================================
   ResetHistos(p, histos_1D, histos_2D);
   DoqqZZLoop(lumi, p, histos_1D, histos_2D);
   
   TGraphErrors *qqZZ_Djj_tgraph,*qqZZ_DVH_tgraph;
   
   histos_1D[Settings::M4l_DVBF2j]->Divide(histos_1D[Settings::M4l_allevents]);
   histos_1D[Settings::M4l_DVH]->Divide(histos_1D[Settings::M4l_allevents]);
   qqZZ_Djj_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVBF2j] , "qqZZ_Djj_tgraph");
   qqZZ_DVH_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVH] , "qqZZ_DVH_tgraph");
   
   fOutControlHistos->cd();
   WriteHistos("qqZZ", histos_1D, histos_2D);
   
   //==================================================================
   //
   //    BSM SIGNAL SAMPLES
   //
   //==================================================================
   
   // 0MH
   ResetHistos(p, histos_1D, histos_2D);
   Do0MHLoop(lumi, p, histos_1D, histos_2D);
   fOutControlHistos->cd();
   WriteHistos("0MH", histos_1D, histos_2D);

   // 0PH
   ResetHistos(p, histos_1D, histos_2D);
   Do0PHLoop(lumi, p, histos_1D, histos_2D);
   fOutControlHistos->cd();
   WriteHistos("0PH", histos_1D, histos_2D);
   
   // 0PL1
   ResetHistos(p, histos_1D, histos_2D);
   Do0PL1Loop(lumi, p, histos_1D, histos_2D);
   fOutControlHistos->cd();
   WriteHistos("0PL1", histos_1D, histos_2D);

   //==================================================================
   //
   //    WH SAMPLES
   //
   //==================================================================
   // Redefine M4l binning for WH and ZH
   delete p, histos_1D[Settings::M4l_allevents], histos_1D[Settings::M4l_DVH], histos_1D[Settings::M4l_DVBF2j];
   
   p       = new TProfile("p2","p2",m4l_bins2, m4l_slices2);
   histos_1D[Settings::M4l_allevents]       = new TH1F("h2", "h2",m4l_bins2, m4l_slices2);
   histos_1D[Settings::M4l_DVBF2j] = new TH1F("histos_2D[Settings::D_VBF2j]", "histos_2D[Settings::D_VBF2j]",m4l_bins2, m4l_slices2);
   histos_1D[Settings::M4l_DVH]    = new TH1F("histos_2D[Settings::D_VH]", "histos_2D[Settings::D_VH]",m4l_bins2, m4l_slices2);
   
   ResetHistos(p, histos_1D, histos_2D);
   DoWHLoop(lumi, p, histos_1D, histos_2D);
   
   TGraphErrors *WH_Djj_tgraph,*WH_DVH_tgraph;
   
   histos_1D[Settings::M4l_DVBF2j]->Divide(histos_1D[Settings::M4l_allevents]);
   histos_1D[Settings::M4l_DVH]->Divide(histos_1D[Settings::M4l_allevents]);
   WH_Djj_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVBF2j] , "WH_Djj_tgraph");
   WH_DVH_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVH] , "WH_DVH_tgraph");
   
   fOutControlHistos->cd();
   WriteHistos("WH", histos_1D, histos_2D);
   
   //==================================================================
   //
   //    ZH SAMPLES
   //
   //==================================================================
   ResetHistos(p, histos_1D, histos_2D);
   DoZHLoop(lumi, p, histos_1D, histos_2D);
   
   TGraphErrors *ZH_Djj_tgraph,*ZH_DVH_tgraph;
   
   histos_1D[Settings::M4l_DVBF2j]->Divide(histos_1D[Settings::M4l_allevents]);
   histos_1D[Settings::M4l_DVH]->Divide(histos_1D[Settings::M4l_allevents]);
   ZH_Djj_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVBF2j] , "ZH_Djj_tgraph");
   ZH_DVH_tgraph = functions->makeGraphFromTH1(p, histos_1D[Settings::M4l_DVH] , "ZH_DVH_tgraph");
   
   fOutControlHistos->cd();
   WriteHistos("ZH", histos_1D, histos_2D);
   
   //==================================================================
   
   fOutControlHistos->Close();
   delete fOutControlHistos;
   
   //==================================================================
   //
   //    WRITE SPLINES TO ROOT
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

void ResetHistos(TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   p->Reset();
   for (int i = 0; i < Settings::num_of_1D_hist_names ; i++) histos_1D[i]->Reset();
   for (int i = 0; i < Settings::num_of_2D_hist_names ; i++) histos_2D[i]->Reset();
}

void WriteHistos(TString sample, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   histos_1D[Settings::M4l_allevents]->SetName("M4l_" + sample);
   histos_1D[Settings::M4l_allevents]->Write();
   histos_2D[Settings::D_VBF2j]->SetName("DVBF2jVsM4l_" + sample);
   histos_2D[Settings::D_VBF2j]->Write();
   histos_2D[Settings::D_VH]->SetName("DVHVsM4l_" + sample);
   histos_2D[Settings::D_VH]->Write();
   histos_2D[Settings::D_BKG_DEC]->SetName("DBKGDECVsM4l_" + sample);
   histos_2D[Settings::D_BKG_DEC]->Write();
   histos_2D[Settings::D_0M_DEC]->SetName("D0MDECVsM4l_" + sample);
   histos_2D[Settings::D_0M_DEC]->Write();
   histos_2D[Settings::D_0hP_DEC]->SetName("D0PDECVsM4l_" + sample);
   histos_2D[Settings::D_0hP_DEC]->Write();
   histos_2D[Settings::D_L1_DEC]->SetName("DL1DECVsM4l_" + sample);
   histos_2D[Settings::D_L1_DEC]->Write();
   histos_2D[Settings::D_L1Zgs_DEC]->SetName("DL1ZgsDECVsM4l_" + sample);
   histos_2D[Settings::D_L1Zgs_DEC]->Write();
}

void DoVBFLoop(double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   Analyzer *_VBF115 = new Analyzer(VBF115, lumi); _VBF115->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF120 = new Analyzer(VBF120, lumi); _VBF120->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF124 = new Analyzer(VBF124, lumi); _VBF124->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF125 = new Analyzer(VBF125, lumi); _VBF125->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF126 = new Analyzer(VBF126, lumi); _VBF126->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF130 = new Analyzer(VBF130, lumi); _VBF130->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF135 = new Analyzer(VBF135, lumi); _VBF135->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF140 = new Analyzer(VBF140, lumi); _VBF140->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF145 = new Analyzer(VBF145, lumi); _VBF145->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF150 = new Analyzer(VBF150, lumi); _VBF150->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF155 = new Analyzer(VBF155, lumi); _VBF155->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF160 = new Analyzer(VBF160, lumi); _VBF160->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF170 = new Analyzer(VBF170, lumi); _VBF170->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF180 = new Analyzer(VBF180, lumi); _VBF180->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF200 = new Analyzer(VBF200, lumi); _VBF200->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF250 = new Analyzer(VBF250, lumi); _VBF250->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF300 = new Analyzer(VBF300, lumi); _VBF300->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF350 = new Analyzer(VBF350, lumi); _VBF350->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF400 = new Analyzer(VBF400, lumi); _VBF400->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF500 = new Analyzer(VBF500, lumi); _VBF500->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF600 = new Analyzer(VBF600, lumi); _VBF600->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF700 = new Analyzer(VBF700, lumi); _VBF700->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF800 = new Analyzer(VBF800, lumi); _VBF800->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF900 = new Analyzer(VBF900, lumi); _VBF900->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF1000 = new Analyzer(VBF1000, lumi); _VBF1000->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF1500 = new Analyzer(VBF1500, lumi); _VBF1500->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF2000 = new Analyzer(VBF2000, lumi); _VBF2000->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF2500 = new Analyzer(VBF2500, lumi); _VBF2500->Loop(p,histos_1D, histos_2D);
   Analyzer *_VBF3000 = new Analyzer(VBF3000, lumi); _VBF3000->Loop(p,histos_1D, histos_2D);

}

void DoggHLoop(double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   Analyzer *_gg115 = new Analyzer(gg115, lumi); _gg115->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg120 = new Analyzer(gg120, lumi); _gg120->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg124 = new Analyzer(gg124, lumi); _gg124->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg125 = new Analyzer(gg125, lumi); _gg125->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg126 = new Analyzer(gg126, lumi); _gg126->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg130 = new Analyzer(gg130, lumi); _gg130->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg135 = new Analyzer(gg135, lumi); _gg135->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg140 = new Analyzer(gg140, lumi); _gg140->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg145 = new Analyzer(gg145, lumi); _gg145->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg150 = new Analyzer(gg150, lumi); _gg150->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg155 = new Analyzer(gg155, lumi); _gg155->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg160 = new Analyzer(gg160, lumi); _gg160->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg170 = new Analyzer(gg170, lumi); _gg170->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg180 = new Analyzer(gg180, lumi); _gg180->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg200 = new Analyzer(gg200, lumi); _gg200->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg250 = new Analyzer(gg250, lumi); _gg250->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg300 = new Analyzer(gg300, lumi); _gg300->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg350 = new Analyzer(gg350, lumi); _gg350->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg400 = new Analyzer(gg400, lumi); _gg400->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg500 = new Analyzer(gg500, lumi); _gg500->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg600 = new Analyzer(gg600, lumi); _gg600->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg700 = new Analyzer(gg700, lumi); _gg700->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg800 = new Analyzer(gg800, lumi); _gg800->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg900 = new Analyzer(gg900, lumi); _gg900->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg1000 = new Analyzer(gg1000, lumi); _gg1000->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg1500 = new Analyzer(gg1500, lumi); _gg1500->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg2000 = new Analyzer(gg2000, lumi); _gg2000->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg2500 = new Analyzer(gg2500, lumi); _gg2500->Loop(p,histos_1D, histos_2D);
   Analyzer *_gg3000 = new Analyzer(gg3000, lumi); _gg3000->Loop(p,histos_1D, histos_2D);
}

void DoqqZZLoop(double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   Analyzer *_qqZZ = new Analyzer(qqZZ, lumi); _qqZZ->Loop(p,histos_1D, histos_2D);
   //Analyzer *_qqZZ = new Analyzer(qqZZext, lumi); _qqZZ->Loop(p,histos_1D, histos_2D);
}

void DoWHLoop(double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   Analyzer *_Wplus115 = new Analyzer(Wplus115, lumi); _Wplus115->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus120 = new Analyzer(Wplus120, lumi); _Wplus120->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus124 = new Analyzer(Wplus124, lumi); _Wplus124->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus125 = new Analyzer(Wplus125, lumi); _Wplus125->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus126 = new Analyzer(Wplus126, lumi); _Wplus126->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus130 = new Analyzer(Wplus130, lumi); _Wplus130->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus135 = new Analyzer(Wplus135, lumi); _Wplus135->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus140 = new Analyzer(Wplus140, lumi); _Wplus140->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus145 = new Analyzer(Wplus145, lumi); _Wplus145->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus150 = new Analyzer(Wplus150, lumi); _Wplus150->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus155 = new Analyzer(Wplus155, lumi); _Wplus155->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus160 = new Analyzer(Wplus160, lumi); _Wplus160->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus170 = new Analyzer(Wplus170, lumi); _Wplus170->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus175 = new Analyzer(Wplus175, lumi); _Wplus175->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus180 = new Analyzer(Wplus180, lumi); _Wplus180->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus190 = new Analyzer(Wplus190, lumi); _Wplus190->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus200 = new Analyzer(Wplus200, lumi); _Wplus200->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus210 = new Analyzer(Wplus210, lumi); _Wplus210->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wplus230 = new Analyzer(Wplus230, lumi); _Wplus230->Loop(p,histos_1D, histos_2D);
   
   Analyzer *_Wminus115 = new Analyzer(Wminus115, lumi); _Wminus115->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus120 = new Analyzer(Wminus120, lumi); _Wminus120->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus124 = new Analyzer(Wminus124, lumi); _Wminus124->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus125 = new Analyzer(Wminus125, lumi); _Wminus125->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus126 = new Analyzer(Wminus126, lumi); _Wminus126->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus130 = new Analyzer(Wminus130, lumi); _Wminus130->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus135 = new Analyzer(Wminus135, lumi); _Wminus135->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus140 = new Analyzer(Wminus140, lumi); _Wminus140->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus145 = new Analyzer(Wminus145, lumi); _Wminus145->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus150 = new Analyzer(Wminus150, lumi); _Wminus150->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus155 = new Analyzer(Wminus155, lumi); _Wminus155->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus160 = new Analyzer(Wminus160, lumi); _Wminus160->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus170 = new Analyzer(Wminus170, lumi); _Wminus170->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus175 = new Analyzer(Wminus175, lumi); _Wminus175->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus180 = new Analyzer(Wminus180, lumi); _Wminus180->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus190 = new Analyzer(Wminus190, lumi); _Wminus190->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus200 = new Analyzer(Wminus200, lumi); _Wminus200->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus210 = new Analyzer(Wminus210, lumi); _Wminus210->Loop(p,histos_1D, histos_2D);
   Analyzer *_Wminus230 = new Analyzer(Wminus230, lumi); _Wminus230->Loop(p,histos_1D, histos_2D);
}

void DoZHLoop(double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   Analyzer *_Z115 = new Analyzer(Z115, lumi); _Z115->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z120 = new Analyzer(Z120, lumi); _Z120->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z124 = new Analyzer(Z124, lumi); _Z124->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z125 = new Analyzer(Z125, lumi); _Z125->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z126 = new Analyzer(Z126, lumi); _Z126->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z130 = new Analyzer(Z130, lumi); _Z130->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z135 = new Analyzer(Z135, lumi); _Z135->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z140 = new Analyzer(Z140, lumi); _Z140->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z145 = new Analyzer(Z145, lumi); _Z145->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z150 = new Analyzer(Z150, lumi); _Z150->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z155 = new Analyzer(Z155, lumi); _Z155->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z160 = new Analyzer(Z160, lumi); _Z160->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z170 = new Analyzer(Z170, lumi); _Z170->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z175 = new Analyzer(Z175, lumi); _Z175->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z180 = new Analyzer(Z180, lumi); _Z180->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z190 = new Analyzer(Z190, lumi); _Z190->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z200 = new Analyzer(Z200, lumi); _Z200->Loop(p,histos_1D, histos_2D);
   //   Analyzer *_Z210 = new Analyzer(Z210, lumi); _Z210->Loop(p,histos_1D, histos_2D);
   Analyzer *_Z230 = new Analyzer(Z230, lumi); _Z230->Loop(p,histos_1D, histos_2D);
}

void Do0MHLoop(double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   Analyzer *_ggTo4e_0MH    = new Analyzer(ggTo4e_0MH, lumi);       _ggTo4e_0MH->Loop(p,histos_1D, histos_2D);
   Analyzer *_ggTo4mu_0MH   = new Analyzer(ggTo4mu_0MH, lumi);     _ggTo4mu_0MH->Loop(p,histos_1D, histos_2D);
   Analyzer *_ggTo2e2mu_0MH = new Analyzer(ggTo2e2mu_0MH, lumi); _ggTo2e2mu_0MH->Loop(p,histos_1D, histos_2D);
}

void Do0PHLoop(double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   Analyzer *_ggTo4e_0PH    = new Analyzer(ggTo4e_0PH, lumi);       _ggTo4e_0PH->Loop(p,histos_1D, histos_2D);
   Analyzer *_ggTo4mu_0PH   = new Analyzer(ggTo4mu_0PH, lumi);     _ggTo4mu_0PH->Loop(p,histos_1D, histos_2D);
   Analyzer *_ggTo2e2mu_0PH = new Analyzer(ggTo2e2mu_0PH, lumi); _ggTo2e2mu_0PH->Loop(p,histos_1D, histos_2D);
   
}

void Do0PL1Loop(double lumi, TProfile *p, TH1F *histos_1D[Settings::num_of_1D_hist_names], TH2F *histos_2D[Settings::num_of_2D_hist_names])
{
   Analyzer *_ggTo4e_0PL1    = new Analyzer(ggTo4e_0PL1, lumi);       _ggTo4e_0PL1->Loop(p,histos_1D, histos_2D);
   Analyzer *_ggTo4mu_0PL1   = new Analyzer(ggTo4mu_0PL1, lumi);     _ggTo4mu_0PL1->Loop(p,histos_1D, histos_2D);
   Analyzer *_ggTo2e2mu_0PL1 = new Analyzer(ggTo2e2mu_0PL1, lumi); _ggTo2e2mu_0PL1->Loop(p,histos_1D, histos_2D);

}
