// My own files
#include "../include/run.h"

using namespace std;

/*
 Standalone script to produce M4l dependent splines for D_VH and D_jj in ggH, VBF, WH, ZH and qqZZ.
 Use M4lSlices script to help you define m4l bins.
*/
int main( int argc, char *argv[] )
{
   Float_t  lumi = 35.8;
	bool only2jEvents = true;
	
	TFile *fOutHistos = new TFile("Splines.root", "recreate");
	fOutHistos->cd();
	
	Analyzer *analyzer = new Analyzer(true);
	//==================================================================
	//
	//    VBF SAMPLES
	//
	//==================================================================
	DoVBFLoop(analyzer,lumi,only2jEvents);
	fOutHistos->cd();
	analyzer->WriteSplines("VBF");
	analyzer->ResetHistos();
	
	//==================================================================
	//
	//    ggH SAMPLES
	//
	//==================================================================
	DoggHLoop(analyzer,lumi,only2jEvents);
	fOutHistos->cd();
	analyzer->WriteSplines("ggH");
	analyzer->ResetHistos();
	//==================================================================
	//
	//    qqZZ BACKGROUND
	//
	//==================================================================
	analyzer->RebinHistosSplinesqq();
	
	DoqqZZLoop(analyzer,lumi,only2jEvents);
	fOutHistos->cd();
	analyzer->WriteSplines("qqZZ");
	analyzer->ResetHistos();
	
	//==================================================================
	//
	//    WH SAMPLES
	//
	//==================================================================
	analyzer->RebinHistosSplines();
	
	DoWHLoop(analyzer,lumi,only2jEvents);
	fOutHistos->cd();
	analyzer->WriteSplines("WH");
	analyzer->ResetHistos();
	
	//==================================================================
	//
	//    ZH SAMPLES
	//
	//==================================================================
	DoZHLoop(analyzer,lumi,only2jEvents);
	fOutHistos->cd();
	analyzer->WriteSplines("ZH");
	analyzer->ResetHistos();
	
   fOutHistos->Close();
   delete fOutHistos;

   
}


void DoVBFLoop(Analyzer *analyzer, float lumi, bool only2jEvents)
{
	analyzer->FillHistos(VBF115,lumi,only2jEvents);
	analyzer->FillHistos(VBF120,lumi,only2jEvents);
	analyzer->FillHistos(VBF124,lumi,only2jEvents);
	analyzer->FillHistos(VBF125,lumi,only2jEvents);
	analyzer->FillHistos(VBF126,lumi,only2jEvents);
	analyzer->FillHistos(VBF130,lumi,only2jEvents);
	analyzer->FillHistos(VBF135,lumi,only2jEvents);
	analyzer->FillHistos(VBF140,lumi,only2jEvents);
	analyzer->FillHistos(VBF145,lumi,only2jEvents);
	analyzer->FillHistos(VBF150,lumi,only2jEvents);
	analyzer->FillHistos(VBF155,lumi,only2jEvents);
	analyzer->FillHistos(VBF160,lumi,only2jEvents);
	analyzer->FillHistos(VBF170,lumi,only2jEvents);
	analyzer->FillHistos(VBF180,lumi,only2jEvents);
	analyzer->FillHistos(VBF200,lumi,only2jEvents);
	analyzer->FillHistos(VBF250,lumi,only2jEvents);
	analyzer->FillHistos(VBF300,lumi,only2jEvents);
	analyzer->FillHistos(VBF350,lumi,only2jEvents);
	analyzer->FillHistos(VBF400,lumi,only2jEvents);
	analyzer->FillHistos(VBF500,lumi,only2jEvents);
	analyzer->FillHistos(VBF600,lumi,only2jEvents);
	analyzer->FillHistos(VBF700,lumi,only2jEvents);
	analyzer->FillHistos(VBF800,lumi,only2jEvents);
	analyzer->FillHistos(VBF900,lumi,only2jEvents);
	analyzer->FillHistos(VBF1000,lumi,only2jEvents);
	analyzer->FillHistos(VBF1500,lumi,only2jEvents);
	analyzer->FillHistos(VBF2000,lumi,only2jEvents);
	analyzer->FillHistos(VBF2500,lumi,only2jEvents);
	analyzer->FillHistos(VBF3000,lumi,only2jEvents);
	
}

void DoggHLoop(Analyzer *analyzer, float lumi, bool only2jEvents)
{
	analyzer->FillHistos(gg115,lumi,only2jEvents);
	analyzer->FillHistos(gg120,lumi,only2jEvents);
	analyzer->FillHistos(gg124,lumi,only2jEvents);
	analyzer->FillHistos(gg125,lumi,only2jEvents);
	analyzer->FillHistos(gg126,lumi,only2jEvents);
	analyzer->FillHistos(gg130,lumi,only2jEvents);
	analyzer->FillHistos(gg135,lumi,only2jEvents);
	analyzer->FillHistos(gg140,lumi,only2jEvents);
	analyzer->FillHistos(gg145,lumi,only2jEvents);
	analyzer->FillHistos(gg150,lumi,only2jEvents);
	analyzer->FillHistos(gg155,lumi,only2jEvents);
	analyzer->FillHistos(gg160,lumi,only2jEvents);
	analyzer->FillHistos(gg170,lumi,only2jEvents);
	analyzer->FillHistos(gg180,lumi,only2jEvents);
	analyzer->FillHistos(gg200,lumi,only2jEvents);
	analyzer->FillHistos(gg250,lumi,only2jEvents);
	analyzer->FillHistos(gg300,lumi,only2jEvents);
	analyzer->FillHistos(gg350,lumi,only2jEvents);
	analyzer->FillHistos(gg400,lumi,only2jEvents);
	analyzer->FillHistos(gg500,lumi,only2jEvents);
	analyzer->FillHistos(gg600,lumi,only2jEvents);
	analyzer->FillHistos(gg700,lumi,only2jEvents);
	analyzer->FillHistos(gg800,lumi,only2jEvents);
	analyzer->FillHistos(gg900,lumi,only2jEvents);
	analyzer->FillHistos(gg1000,lumi,only2jEvents);
	analyzer->FillHistos(gg1500,lumi,only2jEvents);
	analyzer->FillHistos(gg2000,lumi,only2jEvents);
	analyzer->FillHistos(gg2500,lumi,only2jEvents);
	analyzer->FillHistos(gg3000,lumi,only2jEvents);
}

void DoqqZZLoop(Analyzer *analyzer, float lumi, bool only2jEvents)
{
	analyzer->FillHistos(qqZZ,lumi,only2jEvents);
	analyzer->FillHistos(qqZZext,lumi,only2jEvents);
}

void DoWHLoop(Analyzer *analyzer, float lumi, bool only2jEvents)
{
	analyzer->FillHistos(Wplus115,lumi,only2jEvents);
	analyzer->FillHistos(Wplus120,lumi,only2jEvents);
	analyzer->FillHistos(Wplus124,lumi,only2jEvents);
	analyzer->FillHistos(Wplus125,lumi,only2jEvents);
	analyzer->FillHistos(Wplus126,lumi,only2jEvents);
	analyzer->FillHistos(Wplus130,lumi,only2jEvents);
	analyzer->FillHistos(Wplus135,lumi,only2jEvents);
	analyzer->FillHistos(Wplus140,lumi,only2jEvents);
	analyzer->FillHistos(Wplus145,lumi,only2jEvents);
	analyzer->FillHistos(Wplus150,lumi,only2jEvents);
	analyzer->FillHistos(Wplus155,lumi,only2jEvents);
	analyzer->FillHistos(Wplus160,lumi,only2jEvents);
	analyzer->FillHistos(Wplus170,lumi,only2jEvents);
	analyzer->FillHistos(Wplus175,lumi,only2jEvents);
	analyzer->FillHistos(Wplus180,lumi,only2jEvents);
	analyzer->FillHistos(Wplus190,lumi,only2jEvents);
	analyzer->FillHistos(Wplus200,lumi,only2jEvents);
	analyzer->FillHistos(Wplus210,lumi,only2jEvents);
	analyzer->FillHistos(Wplus230,lumi,only2jEvents);
	
	analyzer->FillHistos(Wminus115,lumi,only2jEvents);
	analyzer->FillHistos(Wminus120,lumi,only2jEvents);
	analyzer->FillHistos(Wminus124,lumi,only2jEvents);
	analyzer->FillHistos(Wminus125,lumi,only2jEvents);
	analyzer->FillHistos(Wminus126,lumi,only2jEvents);
	analyzer->FillHistos(Wminus130,lumi,only2jEvents);
	analyzer->FillHistos(Wminus135,lumi,only2jEvents);
	analyzer->FillHistos(Wminus140,lumi,only2jEvents);
	analyzer->FillHistos(Wminus145,lumi,only2jEvents);
	analyzer->FillHistos(Wminus150,lumi,only2jEvents);
	analyzer->FillHistos(Wminus155,lumi,only2jEvents);
	analyzer->FillHistos(Wminus160,lumi,only2jEvents);
	analyzer->FillHistos(Wminus170,lumi,only2jEvents);
	analyzer->FillHistos(Wminus175,lumi,only2jEvents);
	analyzer->FillHistos(Wminus180,lumi,only2jEvents);
	analyzer->FillHistos(Wminus190,lumi,only2jEvents);
	analyzer->FillHistos(Wminus200,lumi,only2jEvents);
	analyzer->FillHistos(Wminus210,lumi,only2jEvents);
	analyzer->FillHistos(Wminus230,lumi,only2jEvents);
}

void DoZHLoop(Analyzer *analyzer, float lumi, bool only2jEvents)
{
	analyzer->FillHistos(Z115,lumi,only2jEvents);
	analyzer->FillHistos(Z120,lumi,only2jEvents);
	analyzer->FillHistos(Z124,lumi,only2jEvents);
	analyzer->FillHistos(Z125,lumi,only2jEvents);
	analyzer->FillHistos(Z126,lumi,only2jEvents);
	analyzer->FillHistos(Z130,lumi,only2jEvents);
	analyzer->FillHistos(Z135,lumi,only2jEvents);
	analyzer->FillHistos(Z140,lumi,only2jEvents);
	analyzer->FillHistos(Z145,lumi,only2jEvents);
	analyzer->FillHistos(Z150,lumi,only2jEvents);
	analyzer->FillHistos(Z155,lumi,only2jEvents);
	analyzer->FillHistos(Z160,lumi,only2jEvents);
	analyzer->FillHistos(Z170,lumi,only2jEvents);
	analyzer->FillHistos(Z175,lumi,only2jEvents);
	analyzer->FillHistos(Z180,lumi,only2jEvents);
	analyzer->FillHistos(Z190,lumi,only2jEvents);
	analyzer->FillHistos(Z200,lumi,only2jEvents);
	//	analyzer->FillHistos(Z210,lumi,only2jEvents);
	analyzer->FillHistos(Z230,lumi,only2jEvents);
}
