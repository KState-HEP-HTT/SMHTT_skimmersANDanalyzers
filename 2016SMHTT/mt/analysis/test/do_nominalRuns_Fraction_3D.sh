rm files_nominal_FF_fraction_3D/*

# Data
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/data_B.root files_nominal_FF_fraction_3D/data_B.root data_obs data_obs 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/data_C.root files_nominal_FF_fraction_3D/data_C.root data_obs data_obs 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/data_D.root files_nominal_FF_fraction_3D/data_D.root data_obs data_obs 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/data_E.root files_nominal_FF_fraction_3D/data_E.root data_obs data_obs 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/data_F.root files_nominal_FF_fraction_3D/data_F.root data_obs data_obs 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/data_G.root files_nominal_FF_fraction_3D/data_G.root data_obs data_obs 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/data_H.root files_nominal_FF_fraction_3D/data_H.root data_obs data_obs 0
hadd -f files_nominal_FF_fraction_3D/Data.root files_nominal_FF_fraction_3D/data*.root

# DY
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY.root files_nominal_FF_fraction_3D/ZTTall.root ZTT ZTT 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY1.root files_nominal_FF_fraction_3D/ZTT1.root ZTT ZTT 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY2.root files_nominal_FF_fraction_3D/ZTT2.root ZTT ZTT 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY3.root files_nominal_FF_fraction_3D/ZTT3.root ZTT ZTT 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY4.root files_nominal_FF_fraction_3D/ZTT4.root ZTT ZTT 0
#EWKZ
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/EWKZ2l.root files_nominal_FF_fraction_3D/EWKZLL.root EWKZLL EWKZ 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/EWKZ2nu.root files_nominal_FF_fraction_3D/EWKZNuNu.root EWKZNuNu EWKZ 0
hadd -f files_nominal_FF_fraction_3D/ZTT.root files_nominal_FF_fraction_3D/ZTT*.root files_nominal_FF_fraction_3D/EWKZLL.root files_nominal_FF_fraction_3D/EWKZNuNu.root
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY.root files_nominal_FF_fraction_3D/ZLall.root ZL ZL 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY1.root files_nominal_FF_fraction_3D/ZL1.root ZL ZL 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY2.root files_nominal_FF_fraction_3D/ZL2.root ZL ZL 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY3.root files_nominal_FF_fraction_3D/ZL3.root ZL ZL 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY4.root files_nominal_FF_fraction_3D/ZL4.root ZL ZL 0
hadd -f files_nominal_FF_fraction_3D/ZL.root files_nominal_FF_fraction_3D/ZL*.root
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY.root files_nominal_FF_fraction_3D/ZJall.root ZJ ZJ 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY1.root files_nominal_FF_fraction_3D/ZJ1.root ZJ ZJ 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY2.root files_nominal_FF_fraction_3D/ZJ2.root ZJ ZJ 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY3.root files_nominal_FF_fraction_3D/ZJ3.root ZJ ZJ 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/DY4.root files_nominal_FF_fraction_3D/ZJ4.root ZJ ZJ 0
hadd -f files_nominal_FF_fraction_3D/ZJ.root files_nominal_FF_fraction_3D/ZJ*.root

# TT
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/TT.root files_nominal_FF_fraction_3D/TTT.root TTT TTT 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/TT.root files_nominal_FF_fraction_3D/TTJ.root TTJ TTJ 0

# WJets
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/W.root files_nominal_FF_fraction_3D/Wincl.root W W 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/W1.root files_nominal_FF_fraction_3D/W1.root W W 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/W2.root files_nominal_FF_fraction_3D/W2.root W W 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/W3.root files_nominal_FF_fraction_3D/W3.root W W 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/W4.root files_nominal_FF_fraction_3D/W4.root W W 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/EWKWMinus.root files_nominal_FF_fraction_3D/EWKWminus.root EWKWminus W 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/EWKWPlus.root files_nominal_FF_fraction_3D/EWKWplus.root EWKWplus W 0
hadd -f files_nominal_FF_fraction_3D/W.root files_nominal_FF_fraction_3D/W4.root files_nominal_FF_fraction_3D/W3.root files_nominal_FF_fraction_3D/W2.root files_nominal_FF_fraction_3D/W1.root files_nominal_FF_fraction_3D/Wincl.root files_nominal_FF_fraction_3D/EWKWminus.root files_nominal_FF_fraction_3D/EWKWplus.root

./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/WW1l1nu2q.root files_nominal_FF_fraction_3D/WW1L1Nu2Q.root WW1L1Nu2Q VV 0 
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/VV2l2nu.root files_nominal_FF_fraction_3D/VV2L2Nu.root VV2L2Nu VV 0 
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/WZ3l1nu.root files_nominal_FF_fraction_3D/WZLLLNu.root WZLLLNu VV 0 
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/ZZ2l2q.root files_nominal_FF_fraction_3D/ZZ2L2Q.root ZZ2L2Q VV 0 
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/ZZ4l.root files_nominal_FF_fraction_3D/ZZ4L.root ZZ4L VV 0 
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/WZ2l2q.root files_nominal_FF_fraction_3D/WZ2L2Q.root WZ2L2Q VV 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/WZ1l3nu.root files_nominal_FF_fraction_3D/WZ1L3Nu.root WZ1L3Nu VV 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/WZ1l1nu2q.root files_nominal_FF_fraction_3D/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/T-tchan.root files_nominal_FF_fraction_3D/ST_t_top.root ST_t_top VV 0 
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/Tbar-tchan.root files_nominal_FF_fraction_3D/ST_t_antitop.root ST_t_antitop VV 0
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/T-tW.root files_nominal_FF_fraction_3D/ST_tW_top.root ST_tW_top VV 0 
./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/Tbar-tW.root files_nominal_FF_fraction_3D/ST_tW_antitop.root ST_tW_antitop VV 0 
hadd -f files_nominal_FF_fraction_3D/VV.root files_nominal_FF_fraction_3D/ST_t_top.root files_nominal_FF_fraction_3D/ST_t_antitop.root files_nominal_FF_fraction_3D/ST_tW_top.root files_nominal_FF_fraction_3D/ST_tW_antitop.root files_nominal_FF_fraction_3D/WW1L1Nu2Q.root files_nominal_FF_fraction_3D/ZZ2L2Q.root files_nominal_FF_fraction_3D/WZ2L2Q.root files_nominal_FF_fraction_3D/WZ1L3Nu.root files_nominal_FF_fraction_3D/WZ1L1Nu2Q.root files_nominal_FF_fraction_3D/VV2L2Nu.root files_nominal_FF_fraction_3D/WZLLLNu.root files_nominal_FF_fraction_3D/ZZ4L.root

# signal
#./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/VBF125.root files_nominal_FF_fraction_3D/VBF125.root VBF125 VBF125 0
#./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/ggH125_ok.root files_nominal_FF_fraction_3D/ggH125.root ggH125 ggH125 0
#./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/WminusH125.root files_nominal_FF_fraction_3D/WminusH125.root WminusH125 WH125 0
#./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/WplusH125.root files_nominal_FF_fraction_3D/WplusH125.root WplusH125 WH125 0
#hadd -f files_nominal_FF_fraction_3D/WH125.root files_nominal_FF_fraction_3D/WplusH125.root files_nominal_FF_fraction_3D/WminusH125.root
#./mt_analyzer_FF_3D_new.exe /hdfs/store/user/doyeong/SMHTT_CONDOR/mutau/myskims/Sep10_fixQ/ZH125.root files_nominal_FF_fraction_3D/ZH125.root ZH125 ZH125 0

#python python/Scale_W_HighMT.py --scale nominal --anti iso  
#python python/Create_QCD_2Drelaxed.py --scale nominal

hadd -f final_nominal_2D.root files_nominal_FF_fraction_3D/Data.root files_nominal_FF_fraction_3D/ZTT.root files_nominal_FF_fraction_3D/ZL.root files_nominal_FF_fraction_3D/ZJ.root files_nominal_FF_fraction_3D/TTT.root files_nominal_FF_fraction_3D/TTJ.root files_nominal_FF_fraction_3D/W.root files_nominal_FF_fraction_3D/VV.root

