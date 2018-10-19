rm files_nominal/*

# Data
./mt_analyzer.exe myntuple/Sep10_fixQ/data_B.root files_nominal/data_B.root data_obs data_obs 0
./mt_analyzer.exe myntuple/Sep10_fixQ/data_C.root files_nominal/data_C.root data_obs data_obs 0
./mt_analyzer.exe myntuple/Sep10_fixQ/data_D.root files_nominal/data_D.root data_obs data_obs 0
./mt_analyzer.exe myntuple/Sep10_fixQ/data_E.root files_nominal/data_E.root data_obs data_obs 0
./mt_analyzer.exe myntuple/Sep10_fixQ/data_F.root files_nominal/data_F.root data_obs data_obs 0
./mt_analyzer.exe myntuple/Sep10_fixQ/data_G.root files_nominal/data_G.root data_obs data_obs 0
./mt_analyzer.exe myntuple/Sep10_fixQ/data_H.root files_nominal/data_H.root data_obs data_obs 0
hadd -f files_nominal/Data.root files_nominal/data*.root

# DY
./mt_analyzer.exe myntuple/Sep10_fixQ/DY.root files_nominal/ZTTall.root ZTT ZTT 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY1.root files_nominal/ZTT1.root ZTT ZTT 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY2.root files_nominal/ZTT2.root ZTT ZTT 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY3.root files_nominal/ZTT3.root ZTT ZTT 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY4.root files_nominal/ZTT4.root ZTT ZTT 0
hadd -f files_nominal/ZTT.root files_nominal/ZTT*.root 
./mt_analyzer.exe myntuple/Sep10_fixQ/DY.root files_nominal/ZLall.root ZL ZL 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY1.root files_nominal/ZL1.root ZL ZL 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY2.root files_nominal/ZL2.root ZL ZL 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY3.root files_nominal/ZL3.root ZL ZL 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY4.root files_nominal/ZL4.root ZL ZL 0
hadd -f files_nominal/ZL.root files_nominal/ZL*.root
./mt_analyzer.exe myntuple/Sep10_fixQ/DY.root files_nominal/ZJall.root ZJ ZJ 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY1.root files_nominal/ZJ1.root ZJ ZJ 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY2.root files_nominal/ZJ2.root ZJ ZJ 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY3.root files_nominal/ZJ3.root ZJ ZJ 0
./mt_analyzer.exe myntuple/Sep10_fixQ/DY4.root files_nominal/ZJ4.root ZJ ZJ 0
hadd -f files_nominal/ZJ.root files_nominal/ZJ*.root

#EWKZ
./mt_analyzer.exe myntuple/Sep10_fixQ/EWKZ2l.root files_nominal/EWKZLL.root EWKZLL EWKZ 0
./mt_analyzer.exe myntuple/Sep10_fixQ/EWKZ2nu.root files_nominal/EWKZNuNu.root EWKZNuNu EWKZ 0
hadd -f files_nominal/EWKZ.root files_nominal/EWKZ*.root

# TT
./mt_analyzer.exe myntuple/Sep10_fixQ/TT.root files_nominal/TTT.root TTT TTT 0
./mt_analyzer.exe myntuple/Sep10_fixQ/TT.root files_nominal/TTJ.root TTJ TTJ 0

# WJets
./mt_analyzer.exe myntuple/Sep10_fixQ/W.root files_nominal/Wincl.root W W 0
./mt_analyzer.exe myntuple/Sep10_fixQ/W1.root files_nominal/W1.root W W 0
./mt_analyzer.exe myntuple/Sep10_fixQ/W2.root files_nominal/W2.root W W 0
./mt_analyzer.exe myntuple/Sep10_fixQ/W3.root files_nominal/W3.root W W 0
./mt_analyzer.exe myntuple/Sep10_fixQ/W4.root files_nominal/W4.root W W 0
./mt_analyzer.exe myntuple/Sep10_fixQ/EWKWMinus.root files_nominal/EWKWminus.root EWKWminus W 0
./mt_analyzer.exe myntuple/Sep10_fixQ/EWKWPlus.root files_nominal/EWKWplus.root EWKWplus W 0
hadd -f files_nominal/W.root files_nominal/W4.root files_nominal/W3.root files_nominal/W2.root files_nominal/W1.root files_nominal/Wincl.root files_nominal/EWKWminus.root files_nominal/EWKWplus.root

./mt_analyzer.exe myntuple/Sep10_fixQ/WW1l1nu2q.root files_nominal/WW1L1Nu2Q.root WW1L1Nu2Q VV 0 
./mt_analyzer.exe myntuple/Sep10_fixQ/VV2l2nu.root files_nominal/VV2L2Nu.root VV2L2Nu VV 0 
./mt_analyzer.exe myntuple/Sep10_fixQ/WZ3l1nu.root files_nominal/WZLLLNu.root WZLLLNu VV 0 
./mt_analyzer.exe myntuple/Sep10_fixQ/ZZ2l2q.root files_nominal/ZZ2L2Q.root ZZ2L2Q VV 0 
./mt_analyzer.exe myntuple/Sep10_fixQ/ZZ4l.root files_nominal/ZZ4L.root ZZ4L VV 0 
./mt_analyzer.exe myntuple/Sep10_fixQ/WZ2l2q.root files_nominal/WZ2L2Q.root WZ2L2Q VV 0
./mt_analyzer.exe myntuple/Sep10_fixQ/WZ1l3nu.root files_nominal/WZ1L3Nu.root WZ1L3Nu VV 0
./mt_analyzer.exe myntuple/Sep10_fixQ/WZ1l1nu2q.root files_nominal/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 0
./mt_analyzer.exe myntuple/Sep10_fixQ/T-tchan.root files_nominal/ST_t_top.root ST_t_top VV 0 
./mt_analyzer.exe myntuple/Sep10_fixQ/Tbar-tchan.root files_nominal/ST_t_antitop.root ST_t_antitop VV 0
./mt_analyzer.exe myntuple/Sep10_fixQ/T-tW.root files_nominal/ST_tW_top.root ST_tW_top VV 0 
./mt_analyzer.exe myntuple/Sep10_fixQ/Tbar-tW.root files_nominal/ST_tW_antitop.root ST_tW_antitop VV 0 
hadd -f files_nominal/VV.root files_nominal/ST_t_top.root files_nominal/ST_t_antitop.root files_nominal/ST_tW_top.root files_nominal/ST_tW_antitop.root files_nominal/WW1L1Nu2Q.root files_nominal/ZZ2L2Q.root files_nominal/WZ2L2Q.root files_nominal/WZ1L3Nu.root files_nominal/WZ1L1Nu2Q.root files_nominal/VV2L2Nu.root files_nominal/WZLLLNu.root files_nominal/ZZ4L.root

# signal
./mt_analyzer.exe myntuple/Sep10_fixQ/VBF125.root files_nominal/VBF125.root VBF125 VBF125 0
./mt_analyzer.exe myntuple/Sep10_fixQ/ggH125_ok.root files_nominal/ggH125.root ggH125 ggH125 0
./mt_analyzer.exe myntuple/Sep10_fixQ/WminusH125.root files_nominal/WminusH125.root WminusH125 WH125 0
./mt_analyzer.exe myntuple/Sep10_fixQ/WplusH125.root files_nominal/WplusH125.root WplusH125 WH125 0
hadd -f files_nominal/WH125.root files_nominal/WplusH125.root files_nominal/WminusH125.root
./mt_analyzer.exe myntuple/Sep10_fixQ/ZH125.root files_nominal/ZH125.root ZH125 ZH125 0

#python python/Scale_W_HighMT.py --scale nominal --anti iso  
python python/Create_QCD_2Drelaxed.py --scale nominal

hadd -f final_nominal.root files_nominal/Data.root files_nominal/ZTT.root files_nominal/ZL.root files_nominal/ZJ.root files_nominal/EWKZ.root files_nominal/TTT.root files_nominal/TTJ.root files_nominal/W.root files_nominal/VV.root files_nominal/VBF125.root files_nominal/ggH125.root files_nominal/WH125.root files_nominal/ZH125.root files_nominal/QCD.root

