#ifndef Settings_h
#define Settings_h

using namespace std;

class Settings
{

public:
	
	Settings();
	~Settings();
   
   enum _final_state
	{
		fs4e = 0,
		fs4mu = 1,
		fs2e2mu = 2,
		fs2mu2e = 3,
		fs4l = 4,
		MAX_NUM_OF_FINAL_STATES
	};
   
   enum _category_OnShell
   {
      on_untagged = 0,
      on_VBF_2j_tagged = 1,
      on_VH_hadron_tagged = 2,
		on_inclusive = 3,
      MAX_NUM_OF_ONSHELL_CATEGORIES
   };
   
   enum _category_OffShell
   {
      off_untagged = 0,
      off_VBF_2j_tagged = 1,
		off_inclusive = 2,
      MAX_NUM_OF_OFFSHELL_CATEGORIES
   };
   
   enum _1D_hist_name
   {
      M4l_allevents  = 0,
		M4l_2j_events  = 1,
		M4l_1j_events  = 2,
      M4l_counter    = 3,
      M4l_DVBF2j     = 4,
		M4l_DVBF1j     = 5,
      M4l_DVH        = 6,
      MAX_NUM_OF_1D_HIST_NAMES
   };
   
   enum _2D_hist_name
   {
      D_VBF2j            = 0,
		D_VBF1j            = 1,
      D_VH               = 2,
      D_BKG_DEC          = 3,
      D_DEC              = 4,
		D_BKG_VBF_DEC      = 5,
		D_VBF_DEC          = 6,
      MAX_NUM_OF_2D_HIST_NAMES
   };
   
   enum _production_modes
   {
      ggH       = 0,
      VBF       = 1,
      WH        = 2,
      ZH        = 3,
      qqZZ      = 4,
		gg_0MH    = 5,
		gg_0PH    = 6,
		gg_0L1    = 7,
		gg_0L1Zs  = 8,
		VBF_0MH   = 9,
		VBF_0PH   = 10,
		VBF_0L1   = 11,
		VBF_0L1Zs = 12,
		MAX_NUM_OF_PRODUCTION_MODES
   };
	
	enum _AC
	{
		SM     = 0,
		fa3    = 1,
		fa2    = 2,
		fL1    = 3,
		fL1Zgs = 4,
		MAX_NUM_OF_ANOMALOUS_COUPLINGS
	};
   
   static const int num_of_production_modes    = MAX_NUM_OF_PRODUCTION_MODES;
   static const int num_of_final_states        = MAX_NUM_OF_FINAL_STATES;
   static const int num_of_categories_OnShell  = MAX_NUM_OF_ONSHELL_CATEGORIES;
   static const int num_of_categories_OffShell = MAX_NUM_OF_OFFSHELL_CATEGORIES;
   static const int num_of_1D_hist_names       = MAX_NUM_OF_1D_HIST_NAMES;
   static const int num_of_2D_hist_names       = MAX_NUM_OF_2D_HIST_NAMES;
	static const int num_of_anomalous_couplings = MAX_NUM_OF_ANOMALOUS_COUPLINGS;
   
   
   
   
   private:
      
};
#endif
