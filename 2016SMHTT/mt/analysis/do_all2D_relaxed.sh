./Make.sh FinalSelection2D_relaxed.cc
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_8march/Data.root files_nominal/Data.root data_obs data_obs 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZTTall.root ZTT ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZLall.root ZL ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZJall.root ZJ ZJ 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZTT1.root ZTT ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZL1.root ZL ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZJ1.root ZJ ZJ 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZTT2.root ZTT ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZL2.root ZL ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZJ2.root ZJ ZJ 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZTT3.root ZTT ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZL3.root ZL ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZJ3.root ZJ ZJ 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZTT4.root ZTT ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZL4.root ZL ZL 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZJ4.root ZJ ZJ 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZNuNu.root files_nominal/EWKZNuNu.root EWKZNuNu EWKZ 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZLL.root files_nominal/EWKZLL.root EWKZLL EWKZ 0
hadd -f files_nominal/ZTT.root files_nominal/ZTTall.root files_nominal/ZTT1.root files_nominal/ZTT2.root files_nominal/ZTT3.root files_nominal/ZTT4.root files_nominal/EWKZLL.root files_nominal/EWKZNuNu.root
hadd -f files_nominal/ZL.root files_nominal/ZLall.root files_nominal/ZL1.root files_nominal/ZL2.root files_nominal/ZL3.root files_nominal/ZL4.root 
hadd -f files_nominal/ZJ.root files_nominal/ZJall.root files_nominal/ZJ1.root files_nominal/ZJ2.root files_nominal/ZJ3.root files_nominal/ZJ4.root 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_nominal/TTT.root TTT TTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_nominal/TTJ.root TTJ TTJ 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W.root files_nominal/Wincl.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W1.root files_nominal/W1.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W2.root files_nominal/W2.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W3.root files_nominal/W3.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W4.root files_nominal/W4.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWplus.root files_nominal/EWKWplus.root EWKWplus W 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWminus.root files_nominal/EWKWminus.root EWKWminus W 0
hadd -f files_nominal/Wunscaled.root files_nominal/W4.root files_nominal/W3.root files_nominal/W2.root files_nominal/W1.root files_nominal/Wincl.root files_nominal/EWKWminus.root files_nominal/EWKWplus.root

#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg125.root files_nominal/ggH125.root ggH125 ggH125 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF125.root files_nominal/VBF125.root VBF125 qqH125 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg120.root files_nominal/ggH120.root ggH120 ggH120 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF120.root files_nominal/VBF120.root VBF120 qqH120 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg110.root files_nominal/ggH110.root ggH110 ggH110 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF110.root files_nominal/VBF110.root VBF110 qqH110 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg140.root files_nominal/ggH140.root ggH140 ggH140 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF140.root files_nominal/VBF140.root VBF140 qqH140 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg130.root files_nominal/ggH130.root ggH130 ggH130 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF130.root files_nominal/VBF130.root VBF130 qqH130 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH120.root files_nominal/WplusH120.root WplusH120 WH120 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH120.root files_nominal/WminusH120.root WminusH120 WH120 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH120.root files_nominal/ZH120.root ZH120 ZH120 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH110.root files_nominal/WplusH110.root WplusH110 WH110 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH110.root files_nominal/WminusH110.root WminusH110 WH110 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH110.root files_nominal/ZH110.root ZH110 ZH110 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH140.root files_nominal/WplusH140.root WplusH140 WH140 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH140.root files_nominal/WminusH140.root WminusH140 WH140 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH140.root files_nominal/ZH140.root ZH140 ZH140 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH125.root files_nominal/WplusH125.root WplusH125 WH125 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH125.root files_nominal/WminusH125.root WminusH125 WH125 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH125.root files_nominal/ZH125.root ZH125 ZH125 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH130.root files_nominal/WplusH130.root WplusH130 WH130 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH130.root files_nominal/WminusH130.root WminusH130 WH130 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH130.root files_nominal/ZH130.root ZH130 ZH130 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/HWW_gg125.root files_nominal/ggH_WW125.root ggH_WW125 ggH_hww125 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/HWW_vbf125.root files_nominal/VBF_WW125.root VBF_WW125 qqH_hww125 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WW1L1Nu2Q.root files_nominal/WW1L1Nu2Q.root WW1L1Nu2Q VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/VV2L2Nu.root files_nominal/VV2L2Nu.root VV2L2Nu VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZLLLNu.root files_nominal/WZLLLNu.root WZLLLNu VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZZ2L2Q.root files_nominal/ZZ2L2Q.root ZZ2L2Q VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZZ4L.root files_nominal/ZZ4L.root ZZ4L VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ2L2Q.root files_nominal/WZ2L2Q.root WZ2L2Q VV 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ1L3Nu.root files_nominal/WZ1L3Nu.root WZ1L3Nu VV 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ1L1Nu2Q.root files_nominal/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_t_top.root files_nominal/ST_t_top.root ST_t_top VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_t_antitop.root files_nominal/ST_t_antitop.root ST_t_antitop VV 0
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_tW_top.root files_nominal/ST_tW_top.root ST_tW_top VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_tW_antitop.root files_nominal/ST_tW_antitop.root ST_tW_antitop VV 0 
hadd -f files_nominal/VV.root files_nominal/ST_t_top.root files_nominal/ST_t_antitop.root files_nominal/ST_tW_top.root files_nominal/ST_tW_antitop.root files_nominal/WW1L1Nu2Q.root files_nominal/ZZ2L2Q.root files_nominal/WZ2L2Q.root files_nominal/WZ1L3Nu.root files_nominal/WZ1L1Nu2Q.root files_nominal/VV2L2Nu.root files_nominal/WZLLLNu.root files_nominal/ZZ4L.root

################################
####### Zpt reweighting ########
################################

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/DYhighttall_zptup.root ZTT ZTT 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/DYhighllall_zptup.root ZL ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/DYhighjall_zptup.root ZJ ZJ 10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/DYhightt1_zptup.root ZTT ZTT 10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/DYhighll1_zptup.root ZL ZL 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/DYhighj1_zptup.root ZJ ZJ 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/DYhightt2_zptup.root ZTT ZTT 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/DYhighll2_zptup.root ZL ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/DYhighj2_zptup.root ZJ ZJ 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/DYhightt3_zptup.root ZTT ZTT 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/DYhighll3_zptup.root ZL ZL 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/DYhighj3_zptup.root ZJ ZJ 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/DYhightt4_zptup.root ZTT ZTT 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/DYhighll4_zptup.root ZL ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/DYhighj4_zptup.root ZJ ZJ 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZNuNu.root files_nominal/EWKZNuNu_zptup.root EWKZNuNu EWKZ 10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZLL.root files_nominal/EWKZLL_zptup.root EWKZLL EWKZ 10
hadd -f files_nominal/DYll_zptup.root files_nominal/DYhighllall_zptup.root files_nominal/DYhighll1_zptup.root files_nominal/DYhighll2_zptup.root files_nominal/DYhighll3_zptup.root files_nominal/DYhighll4_zptup.root files_nominal/EWKZLL_zptup.root files_nominal/EWKZNuNu_zptup.root
hadd -f files_nominal/DYj_zptup.root files_nominal/DYhighjall_zptup.root files_nominal/DYhighj1_zptup.root files_nominal/DYhighj2_zptup.root files_nominal/DYhighj3_zptup.root files_nominal/DYhighj4_zptup.root 
hadd -f files_nominal/DYtt_zptup.root files_nominal/DYhighttall_zptup.root files_nominal/DYhightt1_zptup.root files_nominal/DYhightt2_zptup.root files_nominal/DYhightt3_zptup.root files_nominal/DYhightt4_zptup.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/DYhighttall_zptdown.root ZTT ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/DYhighllall_zptdown.root ZL ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/DYhighjall_zptdown.root ZJ ZJ -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/DYhightt1_zptdown.root ZTT ZTT -10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/DYhighll1_zptdown.root ZL ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/DYhighj1_zptdown.root ZJ ZJ -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/DYhightt2_zptdown.root ZTT ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/DYhighll2_zptdown.root ZL ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/DYhighj2_zptdown.root ZJ ZJ -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/DYhightt3_zptdown.root ZTT ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/DYhighll3_zptdown.root ZL ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/DYhighj3_zptdown.root ZJ ZJ -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/DYhightt4_zptdown.root ZTT ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/DYhighll4_zptdown.root ZL ZL -10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/DYhighj4_zptdown.root ZJ ZJ -10 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZNuNu.root files_nominal/EWKZNuNu_zptdown.root EWKZNuNu EWKZ -10
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZLL.root files_nominal/EWKZLL_zptdown.root EWKZLL EWKZ -10
hadd -f files_nominal/DYll_zptdown.root files_nominal/DYhighllall_zptdown.root files_nominal/DYhighll1_zptdown.root files_nominal/DYhighll2_zptdown.root files_nominal/DYhighll3_zptdown.root files_nominal/DYhighll4_zptdown.root files_nominal/EWKZLL_zptdown.root files_nominal/EWKZNuNu_zptdown.root
hadd -f files_nominal/DYj_zptdown.root files_nominal/DYhighjall_zptdown.root files_nominal/DYhighj1_zptdown.root files_nominal/DYhighj2_zptdown.root files_nominal/DYhighj3_zptdown.root files_nominal/DYhighj4_zptdown.root
hadd -f files_nominal/DYtt_zptdown.root files_nominal/DYhighttall_zptdown.root files_nominal/DYhightt1_zptdown.root files_nominal/DYhightt2_zptdown.root files_nominal/DYhightt3_zptdown.root files_nominal/DYhightt4_zptdown.root

#############################
##### ttbar reweighting #####
#############################

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_nominal/TTT_shapeup.root TTT TTT 11 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_nominal/TTT_shapedown.root TTT TTT -11  
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_nominal/TTJ_shapeup.root TTJ TTJ 11 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_nominal/TTJ_shapedown.root TTJ TTJ -11 

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_nominal/TTJ_jfru.root TTJ TTJ 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_nominal/TTJ_jfrd.root TTJ TTJ -14

#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg125.root files_nominal/ggH125_shapeup.root ggH125 ggH125 12 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg125.root files_nominal/ggH125_shapedown.root ggH125 ggH125 -12 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg120.root files_nominal/ggH120_shapeup.root ggH120 ggH120 12 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg120.root files_nominal/ggH120_shapedown.root ggH120 ggH120 -12 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg130.root files_nominal/ggH130_shapeup.root ggH130 ggH130 12 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg130.root files_nominal/ggH130_shapedown.root ggH130 ggH130 -12 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg110.root files_nominal/ggH110_shapeup.root ggH110 ggH110 12
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg110.root files_nominal/ggH110_shapedown.root ggH110 ggH110 -12
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg140.root files_nominal/ggH140_shapeup.root ggH140 ggH140 12
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg140.root files_nominal/ggH140_shapedown.root ggH140 ggH140 -12
#
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg125.root files_nominal/ggH125_topshapeup.root ggH125 ggH125 22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg125.root files_nominal/ggH125_topshapedown.root ggH125 ggH125 -22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg120.root files_nominal/ggH120_topshapeup.root ggH120 ggH120 22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg120.root files_nominal/ggH120_topshapedown.root ggH120 ggH120 -22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg130.root files_nominal/ggH130_topshapeup.root ggH130 ggH130 22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg130.root files_nominal/ggH130_topshapedown.root ggH130 ggH130 -22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg110.root files_nominal/ggH110_topshapeup.root ggH110 ggH110 22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg110.root files_nominal/ggH110_topshapedown.root ggH110 ggH110 -22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg140.root files_nominal/ggH140_topshapeup.root ggH140 ggH140 22
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg140.root files_nominal/ggH140_topshapedown.root ggH140 ggH140 -22

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZTTall_zmmd.root ZTT ZTT -13
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZLall_zmmd.root ZL ZL -13  
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZJall_zmmd.root ZJ ZJ -13  
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZTT1_zmmd.root ZTT ZTT -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZL1_zmmd.root ZL ZL -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZJ1_zmmd.root ZJ ZJ -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZTT2_zmmd.root ZTT ZTT -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZL2_zmmd.root ZL ZL -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZJ2_zmmd.root ZJ ZJ -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZTT3_zmmd.root ZTT ZTT -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZL3_zmmd.root ZL ZL -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZJ3_zmmd.root ZJ ZJ -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZTT4_zmmd.root ZTT ZTT -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZL4_zmmd.root ZL ZL -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZJ4_zmmd.root ZJ ZJ -13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZNuNu.root files_nominal/EWKZNuNu_zmmd.root EWKZNuNu EWKZ -13
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZLL.root files_nominal/EWKZLL_zmmd.root EWKZLL EWKZ -13
hadd -f files_nominal/ZTT_zmmd.root files_nominal/ZTTall_zmmd.root files_nominal/ZTT1_zmmd.root files_nominal/ZTT2_zmmd.root files_nominal/ZTT3_zmmd.root files_nominal/ZTT4_zmmd.root files_nominal/EWKZNuNu_zmmd.root files_nominal/EWKZLL_zmmd.root
hadd -f files_nominal/ZL_zmmd.root files_nominal/ZLall_zmmd.root files_nominal/ZL1_zmmd.root files_nominal/ZL2_zmmd.root files_nominal/ZL3_zmmd.root files_nominal/ZL4_zmmd.root
hadd -f files_nominal/ZJ_zmmd.root files_nominal/ZJall_zmmd.root files_nominal/ZJ1_zmmd.root files_nominal/ZJ2_zmmd.root files_nominal/ZJ3_zmmd.root files_nominal/ZJ4_zmmd.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZTTall_zmmu.root ZTT ZTT 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZLall_zmmu.root ZL ZL 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZJall_zmmu.root ZJ ZJ 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZTT1_zmmu.root ZTT ZTT 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZL1_zmmu.root ZL ZL 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZJ1_zmmu.root ZJ ZJ 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZTT2_zmmu.root ZTT ZTT 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZL2_zmmu.root ZL ZL 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZJ2_zmmu.root ZJ ZJ 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZTT3_zmmu.root ZTT ZTT 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZL3_zmmu.root ZL ZL 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZJ3_zmmu.root ZJ ZJ 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZTT4_zmmu.root ZTT ZTT 13 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZL4_zmmu.root ZL ZL 13
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZJ4_zmmu.root ZJ ZJ 13
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZNuNu.root files_nominal/EWKZNuNu_zmmu.root EWKZNuNu EWKZ 13
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZLL.root files_nominal/EWKZLL_zmmu.root EWKZLL EWKZ 13
hadd -f files_nominal/ZTT_zmmu.root files_nominal/ZTTall_zmmu.root files_nominal/ZTT1_zmmu.root files_nominal/ZTT2_zmmu.root files_nominal/ZTT3_zmmu.root files_nominal/ZTT4_zmmu.root files_nominal/EWKZNuNu_zmmu.root files_nominal/EWKZLL_zmmu.root
hadd -f files_nominal/ZL_zmmu.root files_nominal/ZLall_zmmu.root files_nominal/ZL1_zmmu.root files_nominal/ZL2_zmmu.root files_nominal/ZL3_zmmu.root files_nominal/ZL4_zmmu.root
hadd -f files_nominal/ZJ_zmmu.root files_nominal/ZJall_zmmu.root files_nominal/ZJ1_zmmu.root files_nominal/ZJ2_zmmu.root files_nominal/ZJ3_zmmu.root files_nominal/ZJ4_zmmu.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZJall_jfru.root ZJ ZJ 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZJ1_jfru.root ZJ ZJ 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZJ2_jfru.root ZJ ZJ 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZJ3_jfru.root ZJ ZJ 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZJ4_jfru.root ZJ ZJ 14
hadd -f files_nominal/ZJ_jfru.root files_nominal/ZJall_jfru.root files_nominal/ZJ1_jfru.root files_nominal/ZJ2_jfru.root files_nominal/ZJ3_jfru.root files_nominal/ZJ4_jfru.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZJall_jfrd.root ZJ ZJ -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZJ1_jfrd.root ZJ ZJ -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZJ2_jfrd.root ZJ ZJ -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZJ3_jfrd.root ZJ ZJ -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZJ4_jfrd.root ZJ ZJ -14
hadd -f files_nominal/ZJ_jfrd.root files_nominal/ZJall_jfrd.root files_nominal/ZJ1_jfrd.root files_nominal/ZJ2_jfrd.root files_nominal/ZJ3_jfrd.root files_nominal/ZJ4_jfrd.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZLall_ZLu.root ZL ZL 17
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZL1_ZLu.root ZL ZL 17
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZL2_ZLu.root ZL ZL 17
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZL3_ZLu.root ZL ZL 17
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZL4_ZLu.root ZL ZL 17
hadd -f files_nominal/ZL_ZLshape.root files_nominal/ZLall_ZLu.root files_nominal/ZL1_ZLu.root files_nominal/ZL2_ZLu.root files_nominal/ZL3_ZLu.root files_nominal/ZL4_ZLu.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZLall_dm.root ZL ZL 18
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZL1_dm.root ZL ZL 18
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZL2_dm.root ZL ZL 18
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZL3_dm.root ZL ZL 18
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZL4_dm.root ZL ZL 18
hadd -f files_nominal/ZL_dm.root files_nominal/ZLall_dm.root files_nominal/ZL1_dm.root files_nominal/ZL2_dm.root files_nominal/ZL3_dm.root files_nominal/ZL4_dm.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZTTall_dm.root ZTT ZTT 16
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZTT1_dm.root ZTT ZTT 16
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZTT2_dm.root ZTT ZTT 16
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZTT3_dm.root ZTT ZTT 16
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZTT4_dm.root ZTT ZTT 16
hadd -f files_nominal/ZTT_dm.root files_nominal/ZTTall_dm.root files_nominal/ZTT1_dm.root files_nominal/ZTT2_dm.root files_nominal/ZTT3_dm.root files_nominal/ZTT4_dm.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W.root files_nominal/Wincl_dm.root W W 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W1.root files_nominal/W1_dm.root W W 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W2.root files_nominal/W2_dm.root W W 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W3.root files_nominal/W3_dm.root W W 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W4.root files_nominal/W4_dm.root W W 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWplus.root files_nominal/EWKWplus_dm.root EWKWplus W 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWminus.root files_nominal/EWKWminus_dm.root EWKWminus W 19
hadd -f files_nominal/Wunscaled_dm.root files_nominal/W4_dm.root files_nominal/W3_dm.root files_nominal/W2_dm.root files_nominal/W1_dm.root files_nominal/Wincl_dm.root files_nominal/EWKWminus_dm.root files_nominal/EWKWplus_dm.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_nominal/ZJall_dm.root ZJ ZJ 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_nominal/ZJ1_dm.root ZJ ZJ 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_nominal/ZJ2_dm.root ZJ ZJ 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_nominal/ZJ3_dm.root ZJ ZJ 19
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_nominal/ZJ4_dm.root ZJ ZJ 19
hadd -f files_nominal/ZJ_dm.root files_nominal/ZJall_dm.root files_nominal/ZJ1_dm.root files_nominal/ZJ2_dm.root files_nominal/ZJ3_dm.root files_nominal/ZJ4_dm.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W.root files_nominal/Wincl_jfru.root W W 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W1.root files_nominal/W1_jfru.root W W 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W2.root files_nominal/W2_jfru.root W W 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W3.root files_nominal/W3_jfru.root W W 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W4.root files_nominal/W4_jfru.root W W 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWplus.root files_nominal/EWKWplus_jfru.root EWKWplus W 14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWminus.root files_nominal/EWKWminus_jfru.root EWKWminus W 14
hadd -f files_nominal/Wunscaled_jfru.root files_nominal/W4_jfru.root files_nominal/W3_jfru.root files_nominal/W2_jfru.root files_nominal/W1_jfru.root files_nominal/Wincl_jfru.root files_nominal/EWKWminus_jfru.root files_nominal/EWKWplus_jfru.root

./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W.root files_nominal/Wincl_jfrd.root W W -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W1.root files_nominal/W1_jfrd.root W W -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W2.root files_nominal/W2_jfrd.root W W -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W3.root files_nominal/W3_jfrd.root W W -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W4.root files_nominal/W4_jfrd.root W W -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWplus.root files_nominal/EWKWplus_jfrd.root EWKWplus W -14
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWminus.root files_nominal/EWKWminus_jfrd.root EWKWminus W -14
hadd -f files_nominal/Wunscaled_jfrd.root files_nominal/W4_jfrd.root files_nominal/W3_jfrd.root files_nominal/W2_jfrd.root files_nominal/W1_jfrd.root files_nominal/Wincl_jfrd.root files_nominal/EWKWminus_jfrd.root files_nominal/EWKWplus_jfrd.root

###### Add systematic shapes #######
sh add_TES_2D.sh
sh addalljes.sh

python Scale_W_HighMT.py --scale nominal --anti iso
python Create_QCD_2Drelaxed.py --scale nominal 
python Scale_W_HighMT.py --scale wup --anti iso
python Create_QCD_2Drelaxed.py --scale wup
python Scale_W_HighMT.py --scale wdown --anti iso
python Create_QCD_2Drelaxed.py --scale wdown
python Scale_W_HighMT.py --scale qcdup --anti iso
python Create_QCD_2Drelaxed.py --scale qcdup
python Scale_W_HighMT.py --scale qcddown --anti iso
python Create_QCD_2Drelaxed.py --scale qcddown

python Normalize_W_shape.py
python Normalize_W_dm.py
python Normalize_ZJ_dm.py
python Normalize_ZTT_shape.py
python Normalize_QCD_shape.py

#hadd -f final_nominal.root files_nominal/W.root files_nominal/Data.root files_nominal/ZL.root files_nominal/ZJ.root files_nominal/ZTT.root files_nominal/TTT.root files_nominal/TTJ.root files_nominal/QCD.root files_nominal/VV.root files_nominal/ggH125.root files_nominal/VBF125.root files_nominal/WminusH125.root files_nominal/WplusH125.root files_nominal/ZH125.root files_nominal/DYtt_zptup.root files_nominal/DYll_zptup.root files_nominal/DYtt_zptdown.root files_nominal/DYll_zptdown.root files_nominal/W_qcdup.root files_nominal/W_qcddown.root files_nominal/W_wdown.root files_nominal/W_wup.root files_nominal/QCD_qcddown.root files_nominal/QCD_qcdup.root files_nominal/DYj_zptup.root files_nominal/DYj_zptdown.root files_nominal/TTJ_shapedown.root files_nominal/TTJ_shapeup.root files_nominal/TTT_shapedown.root files_nominal/TTT_shapeup.root files_nominal/ggH125_shapeup.root files_nominal/ggH125_shapedown.root files_nominal/ZL_zmmd.root files_nominal/ZJ_zmmd.root files_nominal/ZTT_zmmd.root files_nominal/ZL_zmmu.root files_nominal/ZJ_zmmu.root files_nominal/ZTT_zmmu.root files_nominal/ZJ_jfrd.root files_nominal/ZJ_jfru.root files_nominal/TTJ_jfrd.root files_nominal/TTJ_jfru.root files_nominal/W_jfrd.root files_nominal/W_jfru.root files_nominal/ggH120_shapeup.root files_nominal/ggH120_shapedown.root files_nominal/ggH130_shapeup.root files_nominal/ggH130_shapedown.root files_nominal/ZH130.root files_nominal/WplusH130.root files_nominal/ZH120.root files_nominal/WminusH130.root files_nominal/WplusH120.root files_nominal/WminusH120.root files_nominal/ggH120.root files_nominal/VBF120.root files_nominal/ggH130.root files_nominal/VBF130.root files_nominal/QCD_wdown_norm.root files_nominal/QCD_wup_norm.root files_nominal/ggH110.root files_nominal/VBF110.root files_nominal/WminusH110.root files_nominal/WplusH110.root files_nominal/ZH110.root files_nominal/ggH140.root files_nominal/VBF140.root files_nominal/WminusH140.root files_nominal/WplusH140.root files_nominal/ZH140.root files_nominal/ggH110_shapeup.root files_nominal/ggH110_shapedown.root files_nominal/ggH140_shapeup.root files_nominal/ggH140_shapedown.root files_nominal/ggH_WW125.root files_nominal/VBF_WW125.root files_nominal/ZTT_dm_norm.root files_nominal/ZL_ZLshape.root files_nominal/ZL_dm.root files_nominal/W_dm.root files_nominal/ZJ_dm_norm.root files_nominal/ggH125_topshapeup.root files_nominal/ggH125_topshapedown.root files_nominal/ggH110_topshapeup.root files_nominal/ggH110_topshapedown.root files_nominal/ggH140_topshapeup.root files_nominal/ggH140_topshapedown.root files_nominal/ggH120_topshapeup.root files_nominal/ggH120_topshapedown.root files_nominal/ggH130_topshapeup.root files_nominal/ggH130_topshapedown.root #files_nominal/ZL_ZLd.root files_nominal/ZL_ZLu.root

hadd -f final_nominal.root files_nominal/W.root files_nominal/Data.root files_nominal/ZL.root files_nominal/ZJ.root files_nominal/ZTT.root files_nominal/TTT.root files_nominal/TTJ.root files_nominal/QCD.root files_nominal/VV.root files_nominal/DYtt_zptup.root files_nominal/DYll_zptup.root files_nominal/DYtt_zptdown.root files_nominal/DYll_zptdown.root files_nominal/W_qcdup.root files_nominal/W_qcddown.root files_nominal/W_wdown.root files_nominal/W_wup.root files_nominal/QCD_qcddown.root files_nominal/QCD_qcdup.root files_nominal/DYj_zptup.root files_nominal/DYj_zptdown.root files_nominal/TTJ_shapedown.root files_nominal/TTJ_shapeup.root files_nominal/TTT_shapedown.root files_nominal/TTT_shapeup.root files_nominal/ZL_zmmd.root files_nominal/ZJ_zmmd.root files_nominal/ZTT_zmmd.root files_nominal/ZL_zmmu.root files_nominal/ZJ_zmmu.root files_nominal/ZTT_zmmu.root files_nominal/ZJ_jfrd.root files_nominal/ZJ_jfru.root files_nominal/TTJ_jfrd.root files_nominal/TTJ_jfru.root files_nominal/W_jfrd.root files_nominal/W_jfru.root files_nominal/QCD_wdown_norm.root files_nominal/QCD_wup_norm.root files_nominal/ggH_WW125.root files_nominal/VBF_WW125.root files_nominal/ZTT_dm_norm.root files_nominal/ZL_ZLshape.root files_nominal/ZL_dm.root files_nominal/W_dm.root files_nominal/ZJ_dm_norm.root 

#sh do_rivet_all.sh

hadd -f final_mutau_2D.root final_nominal.root final_up.root final_JESup.root allrivet.root
