 rm outputs_nominal/*
 ####################
 ### Nominal runs ###
 ####################

 # 1. Data
 ./tt_analyzer.exe myntuples/Sep03_fixQ/data_B.root outputs_nominal/data_B.root data_obs data_obs nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/data_C.root outputs_nominal/data_C.root data_obs data_obs nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/data_D.root outputs_nominal/data_D.root data_obs data_obs nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/data_E.root outputs_nominal/data_E.root data_obs data_obs nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/data_F.root outputs_nominal/data_F.root data_obs data_obs nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/data_G.root outputs_nominal/data_G.root data_obs data_obs nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/data_H.root outputs_nominal/data_H.root data_obs data_obs nominal
 hadd -f outputs_nominal/data.root outputs_nominal/data_*.root
 # 2. Signals
 ./tt_analyzer.exe myntuples/Sep03_fixQ/VBF125.root outputs_nominal/VBF125.root VBF125 VBF125 nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/ggH125.root outputs_nominal/ggH125.root ggH125 ggH125 nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/WplusH125.root outputs_nominal/WplusH125.root WplusH125 WH125 nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/WminusH125.root outputs_nominal/WminusH125.root WminusH125 WH125 nominal
 hadd -f outputs_nominal/WH125.root outputs_nominal/WplusH125.root outputs_nominal/WminusH125.root
 ./tt_analyzer.exe myntuples/Sep03_fixQ/ZH125.root outputs_nominal/ZH125.root ZH125 ZH125 nominal
 # 3. DY
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY.root outputs_nominal/ZL0.root DY ZL nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY1.root outputs_nominal/ZL1.root DY ZL nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY2.root outputs_nominal/ZL2.root DY ZL nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY3.root outputs_nominal/ZL3.root DY ZL nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY4.root outputs_nominal/ZL4.root DY  ZL nominal
 hadd -f outputs_nominal/ZL.root outputs_nominal/ZL0.root outputs_nominal/ZL1.root outputs_nominal/ZL2.root outputs_nominal/ZL3.root outputs_nominal/ZL4.root
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY.root outputs_nominal/ZJ0.root DY ZJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY1.root outputs_nominal/ZJ1.root DY ZJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY2.root outputs_nominal/ZJ2.root DY ZJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY3.root outputs_nominal/ZJ3.root DY ZJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/DY4.root outputs_nominal/ZJ4.root DY ZJ nominal
 hadd -f outputs_nominal/ZJ.root outputs_nominal/ZJ0.root outputs_nominal/ZJ1.root outputs_nominal/ZJ2.root outputs_nominal/ZJ3.root outputs_nominal/ZJ4.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Sep03_fixQ/EWKZ2l.root outputs_nominal/EWKZ2l.root EWKZLL EWKZ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/EWKZ2nu.root outputs_nominal/EWKZ2nu.root EWKZNuNu EWKZ nominal
 hadd -f outputs_nominal/EWKZ.root outputs_nominal/EWKZ2l.root outputs_nominal/EWKZ2nu.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Sep03_fixQ/TT.root outputs_nominal/TTJ.root TT TTJ nominal
 # 6. W
 ./tt_analyzer.exe myntuples/Sep03_fixQ/W.root outputs_nominal/W0.root W W nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/W1.root outputs_nominal/W1.root W W nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/W2.root outputs_nominal/W2.root W W nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/W3.root outputs_nominal/W3.root W W nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/W4.root outputs_nominal/W4.root W W nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/EWKWMinus.root outputs_nominal/EWKWMinus.root EWKWminus W nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/EWKWPlus.root outputs_nominal/EWKWPlus.root EWKWplus W nominal
 hadd -f outputs_nominal/W.root outputs_nominal/W0.root outputs_nominal/W1.root outputs_nominal/W2.root outputs_nominal/W3.root outputs_nominal/W4.root outputs_nominal/EWKWMinus.root outputs_nominal/EWKWPlus.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Sep03_fixQ/WZ1l1nu2q.root outputs_nominal/WZ1l1nu2q_J.root WZ1L1Nu2Q VVJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/WZ1l3nu.root outputs_nominal/WZ1l3nu_J.root WZ1L3Nu VVJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/WZ3l1nu.root outputs_nominal/WZ3l1nu_J.root WZLLLNu VVJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/WZ2l2q.root outputs_nominal/WZ2l2q_J.root WZ2L2Q VVJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/WW1l1nu2q.root outputs_nominal/WW1l1nu2q_J.root WW1L1Nu2Q VVJ nominal 
 ./tt_analyzer.exe myntuples/Sep03_fixQ/ZZ4l.root outputs_nominal/ZZ4l_J.root ZZ4L VVJ nominal 
 ./tt_analyzer.exe myntuples/Sep03_fixQ/ZZ2l2q.root outputs_nominal/ZZ2l2q_J.root ZZ2L2Q VVJ nominal 
 ./tt_analyzer.exe myntuples/Sep03_fixQ/VV2l2nu.root outputs_nominal/VV2l2nu_J.root VV2L2Nu VVJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/Tbar-tW.root outputs_nominal/Tbar-tW_J.root ST_tW_antitop VVJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/T-tW.root outputs_nominal/T-tW_J.root ST_tW_top VVJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/Tbar-tchan.root outputs_nominal/Tbar-tchan_J.root ST_t_antitop VVJ nominal
 ./tt_analyzer.exe myntuples/Sep03_fixQ/T-tchan.root outputs_nominal/T-tchan_J.root ST_t_top VVJ nominal
 hadd -f outputs_nominal/VVJ.root outputs_nominal/WZ1l1nu2q_J.root outputs_nominal/WZ1l3nu_J.root outputs_nominal/WZ1l1nu2q_J.root outputs_nominal/WZ3l1nu_J.root outputs_nominal/WZ2l2q_J.root outputs_nominal/WW1l1nu2q_J.root outputs_nominal/ZZ4l_J.root outputs_nominal/ZZ2l2q_J.root outputs_nominal/VV2l2nu_J.root outputs_nominal/Tbar-tW_J.root outputs_nominal/T-tW_J.root outputs_nominal/Tbar-tchan_J.root outputs_nominal/T-tchan_J.root 

 # embedded
 ./tt_analyzer.exe myntuples/Oct14_Embedded/embedded.root outputs_nominal/embedded.root embedded embedded nominal

 python python/SignalCreator.py
 python python/QCDcreator.py

 # hadd all outputs
 hadd -f final_nominal.root outputs_nominal/data.root outputs_nominal/ZJ.root outputs_nominal/ZL.root outputs_nominal/TTJ.root outputs_nominal/VVJ.root outputs_nominal/W.root outputs_nominal/EWKZ.root outputs_nominal/VBF125.root outputs_nominal/ggH125.root outputs_nominal/WH125.root outputs_nominal/ZH125.root outputs_nominal/QCD.root outputs_nominal/SMH.root outputs_nominal/embedded.root

