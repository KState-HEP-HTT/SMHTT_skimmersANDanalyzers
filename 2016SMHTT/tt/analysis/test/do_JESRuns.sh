
###################
### METunc runs ###
### All but QCD ###
###################


#''' ClusteredMET '''
rm outputs_JES/*
 # 2. Signals
 ./tt_analyzer.exe myntuples/Sep03_v2/VBF125.root outputs_JES/VBF125_up.root VBF125 VBF125 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/ggH125.root outputs_JES/ggH125_up.root ggH125 ggH125 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WplusH125.root outputs_JES/WplusH125_up.root WplusH125 WH125 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WminusH125.root outputs_JES/WminusH125_up.root WminusH125 WH125 0 JESUp
 hadd -f outputs_JES/WH125_up.root outputs_JES/WplusH125_up.root outputs_JES/WminusH125_up.root
 ./tt_analyzer.exe myntuples/Sep03_v2/ZH125.root outputs_JES/ZH125_up.root ZH125 ZH125 0 JESUp
 # 3. DY
 ./tt_analyzer.exe myntuples/Sep03_v2/DY.root outputs_JES/ZTT0_up.root DY ZTT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY1.root outputs_JES/ZTT1_up.root DY ZTT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY2.root outputs_JES/ZTT2_up.root DY ZTT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY3.root outputs_JES/ZTT3_up.root DY ZTT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY4.root outputs_JES/ZTT4_up.root DY ZTT 0 JESUp
 hadd -f outputs_JES/ZTT_up.root outputs_JES/ZTT0_up.root outputs_JES/ZTT1_up.root outputs_JES/ZTT2_up.root outputs_JES/ZTT3_up.root outputs_JES/ZTT4_up.root
 ./tt_analyzer.exe myntuples/Sep03_v2/DY.root outputs_JES/ZL0_up.root DY ZL 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY1.root outputs_JES/ZL1_up.root DY ZL 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY2.root outputs_JES/ZL2_up.root DY ZL 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY3.root outputs_JES/ZL3_up.root DY ZL 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY4.root outputs_JES/ZL4_up.root DY  ZL 0 JESUp
 hadd -f outputs_JES/ZL_up.root outputs_JES/ZL0_up.root outputs_JES/ZL1_up.root outputs_JES/ZL2_up.root outputs_JES/ZL3_up.root outputs_JES/ZL4_up.root
 ./tt_analyzer.exe myntuples/Sep03_v2/DY.root outputs_JES/ZJ0_up.root DY ZJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY1.root outputs_JES/ZJ1_up.root DY ZJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY2.root outputs_JES/ZJ2_up.root DY ZJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY3.root outputs_JES/ZJ3_up.root DY ZJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/DY4.root outputs_JES/ZJ4_up.root DY ZJ 0 JESUp
 hadd -f outputs_JES/ZJ_up.root outputs_JES/ZJ0_up.root outputs_JES/ZJ1_up.root outputs_JES/ZJ2_up.root outputs_JES/ZJ3_up.root outputs_JES/ZJ4_up.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Sep03_v2/EWKZ2l.root outputs_JES/EWKZ2l_up.root EWKZLL EWKZ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/EWKZ2nu.root outputs_JES/EWKZ2nu_up.root EWKZNuNu EWKZ 0 JESUp
 hadd -f outputs_JES/EWKZ_up.root outputs_JES/EWKZ2l_up.root outputs_JES/EWKZ2nu_up.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Sep03_v2/TT.root outputs_JES/TTT_up.root TT TTT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/TT.root outputs_JES/TTJ_up.root TT TTJ 0 JESUp
 # 6. W
 ./tt_analyzer.exe myntuples/Sep03_v2/W.root outputs_JES/W0_up.root W W 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/W1.root outputs_JES/W1_up.root W W 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/W2.root outputs_JES/W2_up.root W W 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/W3.root outputs_JES/W3_up.root W W 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/W4.root outputs_JES/W4_up.root W W 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/EWKWMinus.root outputs_JES/EWKWMinus_up.root EWKWminus W 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/EWKWPlus.root outputs_JES/EWKWPlus_up.root EWKWplus W 0 JESUp
 hadd -f outputs_JES/W_up.root outputs_JES/W0_up.root outputs_JES/W1_up.root outputs_JES/W2_up.root outputs_JES/W3_up.root outputs_JES/W4_up.root outputs_JES/EWKWMinus_up.root outputs_JES/EWKWPlus_up.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ1l1nu2q.root outputs_JES/WZ1l1nu2q_T_up.root WZ1L1Nu2Q VVT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ1l3nu.root outputs_JES/WZ1l3nu_T_up.root WZ1L3Nu VVT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ3l1nu.root outputs_JES/WZ3l1nu_T_up.root WZLLLNu VVT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ2l2q.root outputs_JES/WZ2l2q_T_up.root WZ2L2Q VVT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WW1l1nu2q.root outputs_JES/WW1l1nu2q_T_up.root WW1L1Nu2Q VVT 0 JESUp 
 ./tt_analyzer.exe myntuples/Sep03_v2/ZZ4l.root outputs_JES/ZZ4l_T_up.root ZZ4L VVT 0 JESUp 
 ./tt_analyzer.exe myntuples/Sep03_v2/ZZ2l2q.root outputs_JES/ZZ2l2q_T_up.root ZZ2L2Q VVT 0 JESUp 
 ./tt_analyzer.exe myntuples/Sep03_v2/VV2l2nu.root outputs_JES/VV2l2nu_T_up.root VV2L2Nu VVT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/Tbar-tW.root outputs_JES/Tbar-tW_T_up.root ST_tW_antitop VVT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/T-tW.root outputs_JES/T-tW_T_up.root ST_tW_top VVT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/Tbar-tchan.root outputs_JES/Tbar-tchan_T_up.root ST_t_antitop VVT 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/T-tchan.root outputs_JES/T-tchan_T_up.root ST_t_top VVT 0 JESUp
 hadd -f outputs_JES/VVT_up.root outputs_JES/WZ1l1nu2q_T_up.root outputs_JES/WZ1l3nu_T_up.root outputs_JES/WZ1l1nu2q_T_up.root outputs_JES/WZ3l1nu_T_up.root outputs_JES/WZ2l2q_T_up.root outputs_JES/WW1l1nu2q_T_up.root outputs_JES/ZZ4l_T_up.root outputs_JES/ZZ2l2q_T_up.root outputs_JES/VV2l2nu_T_up.root outputs_JES/Tbar-tW_T_up.root outputs_JES/T-tW_T_up.root outputs_JES/Tbar-tchan_T_up.root outputs_JES/T-tchan_T_up.root 
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ1l1nu2q.root outputs_JES/WZ1l1nu2q_J_up.root WZ1L1Nu2Q VVJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ1l3nu.root outputs_JES/WZ1l3nu_J_up.root WZ1L3Nu VVJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ3l1nu.root outputs_JES/WZ3l1nu_J_up.root WZLLLNu VVJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ2l2q.root outputs_JES/WZ2l2q_J_up.root WZ2L2Q VVJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/WW1l1nu2q.root outputs_JES/WW1l1nu2q_J_up.root WW1L1Nu2Q VVJ 0 JESUp 
 ./tt_analyzer.exe myntuples/Sep03_v2/ZZ4l.root outputs_JES/ZZ4l_J_up.root ZZ4L VVJ 0 JESUp 
 ./tt_analyzer.exe myntuples/Sep03_v2/ZZ2l2q.root outputs_JES/ZZ2l2q_J_up.root ZZ2L2Q VVJ 0 JESUp 
 ./tt_analyzer.exe myntuples/Sep03_v2/VV2l2nu.root outputs_JES/VV2l2nu_J_up.root VV2L2Nu VVJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/Tbar-tW.root outputs_JES/Tbar-tW_J_up.root ST_tW_antitop VVJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/T-tW.root outputs_JES/T-tW_J_up.root ST_tW_top VVJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/Tbar-tchan.root outputs_JES/Tbar-tchan_J_up.root ST_t_antitop VVJ 0 JESUp
 ./tt_analyzer.exe myntuples/Sep03_v2/T-tchan.root outputs_JES/T-tchan_J_up.root ST_t_top VVJ 0 JESUp
 hadd -f outputs_JES/VVJ_up.root outputs_JES/WZ1l1nu2q_J_up.root outputs_JES/WZ1l3nu_J_up.root outputs_JES/WZ1l1nu2q_J_up.root outputs_JES/WZ3l1nu_J_up.root outputs_JES/WZ2l2q_J_up.root outputs_JES/WW1l1nu2q_J_up.root outputs_JES/ZZ4l_J_up.root outputs_JES/ZZ2l2q_J_up.root outputs_JES/VV2l2nu_J_up.root outputs_JES/Tbar-tW_J_up.root outputs_JES/T-tW_J_up.root outputs_JES/Tbar-tchan_J_up.root outputs_JES/T-tchan_J_up.root 



 # 2. Signals
 ./tt_analyzer.exe myntuples/Sep03_v2/VBF125.root outputs_JES/VBF125_down.root VBF125 VBF125 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/ggH125.root outputs_JES/ggH125_down.root ggH125 ggH125 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WplusH125.root outputs_JES/WplusH125_down.root WplusH125 WH125 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WminusH125.root outputs_JES/WminusH125_down.root WminusH125 WH125 0 JESDown
 hadd -f outputs_JES/WH125_down.root outputs_JES/WplusH125_down.root outputs_JES/WminusH125_down.root
 ./tt_analyzer.exe myntuples/Sep03_v2/ZH125.root outputs_JES/ZH125_down.root ZH125 ZH125 0 JESDown
 # 3. DY
 ./tt_analyzer.exe myntuples/Sep03_v2/DY.root outputs_JES/ZTT0_down.root DY ZTT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY1.root outputs_JES/ZTT1_down.root DY ZTT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY2.root outputs_JES/ZTT2_down.root DY ZTT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY3.root outputs_JES/ZTT3_down.root DY ZTT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY4.root outputs_JES/ZTT4_down.root DY ZTT 0 JESDown
 hadd -f outputs_JES/ZTT_down.root outputs_JES/ZTT0_down.root outputs_JES/ZTT1_down.root outputs_JES/ZTT2_down.root outputs_JES/ZTT3_down.root outputs_JES/ZTT4_down.root
 ./tt_analyzer.exe myntuples/Sep03_v2/DY.root outputs_JES/ZL0_down.root DY ZL 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY1.root outputs_JES/ZL1_down.root DY ZL 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY2.root outputs_JES/ZL2_down.root DY ZL 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY3.root outputs_JES/ZL3_down.root DY ZL 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY4.root outputs_JES/ZL4_down.root DY  ZL 0 JESDown
 hadd -f outputs_JES/ZL_down.root outputs_JES/ZL0_down.root outputs_JES/ZL1_down.root outputs_JES/ZL2_down.root outputs_JES/ZL3_down.root outputs_JES/ZL4_down.root
 ./tt_analyzer.exe myntuples/Sep03_v2/DY.root outputs_JES/ZJ0_down.root DY ZJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY1.root outputs_JES/ZJ1_down.root DY ZJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY2.root outputs_JES/ZJ2_down.root DY ZJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY3.root outputs_JES/ZJ3_down.root DY ZJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/DY4.root outputs_JES/ZJ4_down.root DY ZJ 0 JESDown
 hadd -f outputs_JES/ZJ_down.root outputs_JES/ZJ0_down.root outputs_JES/ZJ1_down.root outputs_JES/ZJ2_down.root outputs_JES/ZJ3_down.root outputs_JES/ZJ4_down.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Sep03_v2/EWKZ2l.root outputs_JES/EWKZ2l_down.root EWKZLL EWKZ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/EWKZ2nu.root outputs_JES/EWKZ2nu_down.root EWKZNuNu EWKZ 0 JESDown
 hadd -f outputs_JES/EWKZ_down.root outputs_JES/EWKZ2l_down.root outputs_JES/EWKZ2nu_down.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Sep03_v2/TT.root outputs_JES/TTT_down.root TT TTT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/TT.root outputs_JES/TTJ_down.root TT TTJ 0 JESDown
 # 6. W
 ./tt_analyzer.exe myntuples/Sep03_v2/W.root outputs_JES/W0_down.root W W 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/W1.root outputs_JES/W1_down.root W W 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/W2.root outputs_JES/W2_down.root W W 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/W3.root outputs_JES/W3_down.root W W 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/W4.root outputs_JES/W4_down.root W W 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/EWKWMinus.root outputs_JES/EWKWMinus_down.root EWKWminus W 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/EWKWPlus.root outputs_JES/EWKWPlus_down.root EWKWplus W 0 JESDown
 hadd -f outputs_JES/W_down.root outputs_JES/W0_down.root outputs_JES/W1_down.root outputs_JES/W2_down.root outputs_JES/W3_down.root outputs_JES/W4_down.root outputs_JES/EWKWMinus_down.root outputs_JES/EWKWPlus_down.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ1l1nu2q.root outputs_JES/WZ1l1nu2q_T_down.root WZ1L1Nu2Q VVT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ1l3nu.root outputs_JES/WZ1l3nu_T_down.root WZ1L3Nu VVT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ3l1nu.root outputs_JES/WZ3l1nu_T_down.root WZLLLNu VVT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ2l2q.root outputs_JES/WZ2l2q_T_down.root WZ2L2Q VVT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WW1l1nu2q.root outputs_JES/WW1l1nu2q_T_down.root WW1L1Nu2Q VVT 0 JESDown 
 ./tt_analyzer.exe myntuples/Sep03_v2/ZZ4l.root outputs_JES/ZZ4l_T_down.root ZZ4L VVT 0 JESDown 
 ./tt_analyzer.exe myntuples/Sep03_v2/ZZ2l2q.root outputs_JES/ZZ2l2q_T_down.root ZZ2L2Q VVT 0 JESDown 
 ./tt_analyzer.exe myntuples/Sep03_v2/VV2l2nu.root outputs_JES/VV2l2nu_T_down.root VV2L2Nu VVT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/Tbar-tW.root outputs_JES/Tbar-tW_T_down.root ST_tW_antitop VVT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/T-tW.root outputs_JES/T-tW_T_down.root ST_tW_top VVT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/Tbar-tchan.root outputs_JES/Tbar-tchan_T_down.root ST_t_antitop VVT 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/T-tchan.root outputs_JES/T-tchan_T_down.root ST_t_top VVT 0 JESDown
 hadd -f outputs_JES/VVT_down.root outputs_JES/WZ1l1nu2q_T_down.root outputs_JES/WZ1l3nu_T_down.root outputs_JES/WZ1l1nu2q_T_down.root outputs_JES/WZ3l1nu_T_down.root outputs_JES/WZ2l2q_T_down.root outputs_JES/WW1l1nu2q_T_down.root outputs_JES/ZZ4l_T_down.root outputs_JES/ZZ2l2q_T_down.root outputs_JES/VV2l2nu_T_down.root outputs_JES/Tbar-tW_T_down.root outputs_JES/T-tW_T_down.root outputs_JES/Tbar-tchan_T_down.root outputs_JES/T-tchan_T_down.root 
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ1l1nu2q.root outputs_JES/WZ1l1nu2q_J_down.root WZ1L1Nu2Q VVJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ1l3nu.root outputs_JES/WZ1l3nu_J_down.root WZ1L3Nu VVJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ3l1nu.root outputs_JES/WZ3l1nu_J_down.root WZLLLNu VVJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WZ2l2q.root outputs_JES/WZ2l2q_J_down.root WZ2L2Q VVJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/WW1l1nu2q.root outputs_JES/WW1l1nu2q_J_down.root WW1L1Nu2Q VVJ 0 JESDown 
 ./tt_analyzer.exe myntuples/Sep03_v2/ZZ4l.root outputs_JES/ZZ4l_J_down.root ZZ4L VVJ 0 JESDown 
 ./tt_analyzer.exe myntuples/Sep03_v2/ZZ2l2q.root outputs_JES/ZZ2l2q_J_down.root ZZ2L2Q VVJ 0 JESDown 
 ./tt_analyzer.exe myntuples/Sep03_v2/VV2l2nu.root outputs_JES/VV2l2nu_J_down.root VV2L2Nu VVJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/Tbar-tW.root outputs_JES/Tbar-tW_J_down.root ST_tW_antitop VVJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/T-tW.root outputs_JES/T-tW_J_down.root ST_tW_top VVJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/Tbar-tchan.root outputs_JES/Tbar-tchan_J_down.root ST_t_antitop VVJ 0 JESDown
 ./tt_analyzer.exe myntuples/Sep03_v2/T-tchan.root outputs_JES/T-tchan_J_down.root ST_t_top VVJ 0 JESDown
 hadd -f outputs_JES/VVJ_down.root outputs_JES/WZ1l1nu2q_J_down.root outputs_JES/WZ1l3nu_J_down.root outputs_JES/WZ1l1nu2q_J_down.root outputs_JES/WZ3l1nu_J_down.root outputs_JES/WZ2l2q_J_down.root outputs_JES/WW1l1nu2q_J_down.root outputs_JES/ZZ4l_J_down.root outputs_JES/ZZ2l2q_J_down.root outputs_JES/VV2l2nu_J_down.root outputs_JES/Tbar-tW_J_down.root outputs_JES/T-tW_J_down.root outputs_JES/Tbar-tchan_J_down.root outputs_JES/T-tchan_J_down.root 

 hadd -f final_JES.root outputs_JES/ZTT_down.root outputs_JES/ZJ_down.root outputs_JES/ZL_down.root outputs_JES/TTT_down.root outputs_JES/TTJ_down.root outputs_JES/VVT_down.root outputs_JES/VVJ_down.root outputs_JES/W_down.root outputs_JES/EWKZ_down.root outputs_JES/VBF125_down.root outputs_JES/ggH125_down.root outputs_JES/WH125_down.root outputs_JES/ZH125_down.root outputs_JES/ZTT_up.root outputs_JES/ZJ_up.root outputs_JES/ZL_up.root outputs_JES/TTT_up.root outputs_JES/TTJ_up.root outputs_JES/VVT_up.root outputs_JES/VVJ_up.root outputs_JES/W_up.root outputs_JES/EWKZ_up.root outputs_JES/VBF125_up.root outputs_JES/ggH125_up.root outputs_JES/WH125_up.root outputs_JES/ZH125_up.root 

