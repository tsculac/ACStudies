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
#include "Analyzer.h"
#include "Functions.h"
#include "Settings.h"

using namespace std;

/*
 Script to pring mass windows which contain nevents.
 It is usefull when defining m4l slices to produce splines.
 Needs DVsM4l.root file which is output of run.cpp!
*/

int main( int argc, char *argv[] )
{
   int nevents;
   
   TFile* histo_file = TFile::Open("DVsM4l.root");
   TH1F *M4L_histo_ggH, *M4L_histo_VBFH, *M4L_histo_WH, *M4L_histo_ZH, *M4L_histo_qqZZ;
   
   M4L_histo_ggH = (TH1F*) histo_file->Get("M4l_counter_ggH");
   M4L_histo_VBFH = (TH1F*) histo_file->Get("M4l_counter_VBF");
   M4L_histo_qqZZ = (TH1F*) histo_file->Get("M4l_counter_qqZZ");
   M4L_histo_WH = (TH1F*) histo_file->Get("M4l_counter_WH");
   M4L_histo_ZH = (TH1F*) histo_file->Get("M4l_counter_ZH");
   
   int dn_bin = 1;
   int up_bin = 1;
   nevents = 150000;
   
   cout << "===================================" << endl;
   cout << "M4L slices with " << nevents/1000 << "k events for ggH: " << endl;
   for ( int i=2 ; i <= M4L_histo_ggH->GetSize()-2 ; i++ )
   {
      if( M4L_histo_ggH->Integral(dn_bin, up_bin) >= nevents )
      {
         cout << 70 + dn_bin - 1 << ", " << 70 + up_bin -1 << endl;
         dn_bin = i;
         up_bin = i;
      }
      else up_bin = i;
   }
   cout << "===================================" << endl;
   
   
   dn_bin = 1;
   up_bin = 1;
   nevents = 150000;
   cout << "===================================" << endl;
   cout << "M4L slices with " << nevents/1000 << "k events for VBFH: " << endl;
   for ( int i=2 ; i <= M4L_histo_VBFH->GetSize()-2 ; i++ )
   {
      if( M4L_histo_VBFH->Integral(dn_bin, up_bin) >= nevents )
      {
         cout << 70 + dn_bin - 1 << ", " << 70 + up_bin -1 << endl;
         dn_bin = i;
         up_bin = i;
      }
      else up_bin = i;
   }
   cout << "===================================" << endl;
   
   dn_bin = 1;
   up_bin = 1;
   nevents = 150000;
   cout << "===================================" << endl;
   cout << "M4L slices with " << nevents/1000 << "k events for WH: " << endl;
   for ( int i=2 ; i <= M4L_histo_WH->GetSize()-2 ; i++ )
   {
      if( M4L_histo_WH->Integral(dn_bin, up_bin) >= nevents )
      {
         cout << 70 + dn_bin - 1 << ", " << 70 + up_bin -1 << endl;
         dn_bin = i;
         up_bin = i;
      }
      else up_bin = i;
   }
   cout << "===================================" << endl;
   
   dn_bin = 1;
   up_bin = 1;
   nevents = 150000;
   cout << "===================================" << endl;
   cout << "M4L slices with " << nevents/1000 << "k events for ZH: " << endl;
   for ( int i=2 ; i <= M4L_histo_ZH->GetSize()-2 ; i++ )
   {
      if( M4L_histo_ZH->Integral(dn_bin, up_bin) >= nevents )
      {
         cout << 70 + dn_bin - 1 << ", " << 70 + up_bin -1 << endl;
         dn_bin = i;
         up_bin = i;
      }
      else up_bin = i;
   }
   cout << "===================================" << endl;
   
   dn_bin = 1;
   up_bin = 1;
   nevents = 150000;
   cout << "===================================" << endl;
   cout << "M4L slices with " << nevents/1000 << "k events for qqZZ: " << endl;
   for ( int i=2 ; i <= M4L_histo_qqZZ->GetSize()-2 ; i++ )
   {
      if( M4L_histo_qqZZ->Integral(dn_bin, up_bin) >= nevents )
      {
         cout << 70 + dn_bin - 1 << ", " << 70 + up_bin -1 << endl;
         dn_bin = i;
         up_bin = i;
      }
      else up_bin = i;
   }
   cout << "===================================" << endl;
   
   
}
