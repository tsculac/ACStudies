#define Functions_cxx
#include "Functions.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TMath.h"

Functions::Functions()
{

}

Functions::~Functions() {}


TGraphErrors* Functions::makeGraphFromTH1(TProfile *hx, TH1* hy, TString name){
   if (hx->GetNbinsX()!=hy->GetNbinsX()){
      cerr << "Number of bins for x coordinate != those for y" << endl;
      assert(0);
   }
   unsigned int nbins = hx->GetNbinsX();
   double* xexyey[4];
   for (unsigned int ix=0; ix<4; ix++) xexyey[ix] = new double[nbins];
   for (unsigned int bin=0; bin<nbins; bin++){
      xexyey[0][bin] = hx->GetBinContent(bin+1);
      xexyey[1][bin] = hx->GetBinError(bin+1);
      
      //cout << "Bin " << bin << " x-center: " << xexyey[0][bin] << " +- " << xexyey[1][bin] << endl;
      xexyey[2][bin] = hy->GetBinContent(bin+1);
      xexyey[3][bin] = hy->GetBinError(bin+1);
   }
   TGraphErrors* tg = new TGraphErrors(nbins, xexyey[0], xexyey[2], xexyey[1], xexyey[3]);
   tg->SetName(name);
   for (unsigned int ix=0; ix<4; ix++) delete[] xexyey[ix];
   return tg;
}

TSpline3* Functions::convertGraphToSpline3(TGraph* tg, double* dfirst=0, double* dlast=0){
   unsigned int nbins = tg->GetN();
   double* xy[2]={
      tg->GetX(),
      tg->GetY()
   };
   TSpline3* spline = new TSpline3("spline", tg, "b2e2", 0, 0);
   spline->SetName(Form("%s_spline", tg->GetName()));
   if (dfirst!=0) *dfirst = spline->Derivative(xy[0][0]);
   if (dlast!=0) *dlast = spline->Derivative(xy[0][nbins-1]);
   return spline;
}

/* SPECIFIC COMMENT: Convert a TGraph to a TSpline3 */
TSpline3* Functions::convertGraphToSpline3_FaithfulSlopes(TGraph* tg, double* dfirst=0, double* dlast=0){
   unsigned int nbins = tg->GetN();
   double* xy[2]={
      tg->GetX(),
      tg->GetY()
   };
   double derivative_first = (xy[1][1]-xy[1][0])/(xy[0][1]-xy[0][0]);
   double derivative_last = (xy[1][nbins-1]-xy[1][nbins-2])/(xy[0][nbins-1]-xy[0][nbins-2]);
   TSpline3* spline = new TSpline3("spline", tg, "b1e1", derivative_first, derivative_last);
   spline->SetName(Form("%s_spline", tg->GetName()));
   if (dfirst!=0) *dfirst = spline->Derivative(xy[0][0]);
   if (dlast!=0) *dlast = spline->Derivative(xy[0][nbins-1]);
   return spline;
}

void Functions::ConditionalNormalisation(TH2F* h){
   
   for(int ix=0; ix<=h->GetNbinsX()+1; ix++)
   {
      double integral = h->Integral(ix,ix,0, h->GetNbinsY()+1);
      
      if(integral!=0.)
      {
         for(int iy=0;iy<=h->GetNbinsY()+1;iy++) h->SetBinContent(ix,iy,h->GetBinContent(ix,iy)/integral);
      }
   }
}





