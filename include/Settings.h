#ifndef Settings_h
#define Settings_h

using namespace std;

class Settings
{

public:
	
	Settings();
	~Settings();
   
   enum _final_state { fs4e = 0, fs4mu = 1, fs2e2mu = 2, fs2mu2e = 3, fs4l = 4, MAX_NUM_OF_FINAL_STATES };
   
   enum _category_OnShell
   {
      on_untagged = 0,
      on_VBF_2j_tagged = 1,
      on_VH_hadron_tagged = 2,
      MAX_NUM_OF_ONSHELL_CATEGORIES
   };
   
   enum _category_OffShell
   {
      off_untagged = 0,
      off_VBF_2j_tagged = 1,
      MAX_NUM_OF_OFFSHELL_CATEGORIES
   };
   
   enum _1D_hist_name
   {
      M4l_allevents     = 0,
      M4l_counter = 1,
      M4l_DVBF2j = 2,
      M4l_DVH    = 3,
		M4l_DVBF1j = 4,
      MAX_NUM_OF_1D_HIST_NAMES
   };
   
   enum _2D_hist_name
   {
      D_VBF2j = 0,
      D_VH = 1,
      D_BKG_DEC = 2,
      D_0M_DEC = 3,
      D_0hP_DEC = 4,
      D_L1_DEC = 5,
      D_L1Zgs_DEC = 6,
      MAX_NUM_OF_2D_HIST_NAMES
   };
   
   enum _production_modes
   {
      ggH = 0,
      VBF = 1,
      WH = 2,
      ZH = 3,
      ttH = 4, MAX_NUM_OF_PRODUCTION_MODES
   };
   
   
   static const int num_of_production_modes    = MAX_NUM_OF_PRODUCTION_MODES;
   static const int num_of_final_states        = MAX_NUM_OF_FINAL_STATES;
   static const int num_of_categories_OnShell  = MAX_NUM_OF_ONSHELL_CATEGORIES;
   static const int num_of_categories_OffShell = MAX_NUM_OF_OFFSHELL_CATEGORIES;
   static const int num_of_1D_hist_names       = MAX_NUM_OF_1D_HIST_NAMES;
   static const int num_of_2D_hist_names       = MAX_NUM_OF_2D_HIST_NAMES;
   
   
   
   
   private:
      
};
#endif
