convert -delay 10 -loop 0 Animations/SM/DVBF1jetSM_*.png Animations/SM/DVBF_1jet_SM.gif
convert -delay 10 -loop 0 Animations/SM/DVBF2jetSM_*.png Animations/SM/DVBF_2jet_SM.gif
convert -delay 10 -loop 0 Animations/SM/DVH2jetSM_*.png Animations/SM/DVH_2jet_SM.gif

convert -delay 10 -loop 0 Animations/fa3/DVBF2jetBSM_*.png Animations/fa3/DVBF_2jet_BSM.gif
convert -delay 10 -loop 0 Animations/fa3/DBKGDEC_*.png Animations/fa3/D_BKG_DEC.gif
convert -delay 10 -loop 0 Animations/fa3/DBKGVBFDEC_*.png Animations/fa3/D_BKG_VBF_DEC.gif
convert -delay 10 -loop 0 Animations/fa3/DDEC_*.png Animations/fa3/D_DEC.gif
convert -delay 10 -loop 0 Animations/fa3/DVBFDEC_*.png Animations/fa3/D_VBF_DEC.gif

convert -delay 10 -loop 0 Animations/fa2/DVBF2jetBSM_*.png Animations/fa2/DVBF_2jet_BSM.gif
convert -delay 10 -loop 0 Animations/fa2/DBKGDEC_*.png Animations/fa2/D_BKG_DEC.gif
convert -delay 10 -loop 0 Animations/fa2/DBKGVBFDEC_*.png Animations/fa2/D_BKG_VBF_DEC.gif
convert -delay 10 -loop 0 Animations/fa2/DDEC_*.png Animations/fa2/D_DEC.gif
convert -delay 10 -loop 0 Animations/fa2/DVBFDEC_*.png Animations/fa2/D_VBF_DEC.gif

convert -delay 10 -loop 0 Animations/fL1/DVBF2jetBSM_*.png Animations/fL1/DVBF_2jet_BSM.gif
convert -delay 10 -loop 0 Animations/fL1/DBKGDEC_*.png Animations/fL1/D_BKG_DEC.gif
convert -delay 10 -loop 0 Animations/fL1/DBKGVBFDEC_*.png Animations/fL1/D_BKG_VBF_DEC.gif
convert -delay 10 -loop 0 Animations/fL1/DDEC_*.png Animations/fL1/D_DEC.gif
convert -delay 10 -loop 0 Animations/fL1/DVBFDEC_*.png Animations/fL1/D_VBF_DEC.gif

mv Animations/SM/* ~/www/AnomalousCouplings/Plots_NewProduciton/Animations/SM/
mv Animations/fa3/* ~/www/AnomalousCouplings/Plots_NewProduciton/Animations/fa3/
mv Animations/fa2/* ~/www/AnomalousCouplings/Plots_NewProduciton/Animations/fa2/
mv Animations/fL1/* ~/www/AnomalousCouplings/Plots_NewProduciton/Animations/fL1/
