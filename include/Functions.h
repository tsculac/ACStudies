#ifndef Functions_h
#define Functions_h

#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TProfile.h"
#include "TGraph.h"
#include "TSpline.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <iostream>
#include "assert.h"

using namespace std;

class Functions {
public :
   Functions();
   virtual ~Functions();
   virtual TGraphErrors* makeGraphFromTH1(TProfile *hx, TH1* hy, TString name);
   virtual TSpline3* convertGraphToSpline3(TGraph* tg, double* dfirst, double* dlast);
   virtual TSpline3* convertGraphToSpline3_FaithfulSlopes(TGraph* tg, double* dfirst, double* dlast);
   virtual void ConditionalNormalisation(TH2F* h);

};

#endif
