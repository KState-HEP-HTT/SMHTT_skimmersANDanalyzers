
###################
### METunc runs ###
### All but QCD ###
###################


''' ClusteredMET '''
rm outputs_DM0/*
 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_DM0/VBF125_up.root VBF125 VBF125 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_DM0/ggH125_up.root ggH125 ggH125 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_DM0/WplusH125_up.root WplusH125 WH125 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_DM0/WminusH125_up.root WminusH125 WH125 0 DM0_UP
 hadd -f outputs_DM0/WH125_up.root outputs_DM0/WplusH125_up.root outputs_DM0/WminusH125_up.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_DM0/ZH125_up.root ZH125 ZH125 0 DM0_UP
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM0/ZTT0_up.root DY ZTT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM0/ZTT1_up.root DY ZTT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM0/ZTT2_up.root DY ZTT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM0/ZTT3_up.root DY ZTT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM0/ZTT4_up.root DY ZTT 0 DM0_UP
 hadd -f outputs_DM0/ZTT_up.root outputs_DM0/ZTT0_up.root outputs_DM0/ZTT1_up.root outputs_DM0/ZTT2_up.root outputs_DM0/ZTT3_up.root outputs_DM0/ZTT4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM0/ZL0_up.root DY ZL 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM0/ZL1_up.root DY ZL 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM0/ZL2_up.root DY ZL 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM0/ZL3_up.root DY ZL 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM0/ZL4_up.root DY  ZL 0 DM0_UP
 hadd -f outputs_DM0/ZL_up.root outputs_DM0/ZL0_up.root outputs_DM0/ZL1_up.root outputs_DM0/ZL2_up.root outputs_DM0/ZL3_up.root outputs_DM0/ZL4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM0/ZJ0_up.root DY ZJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM0/ZJ1_up.root DY ZJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM0/ZJ2_up.root DY ZJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM0/ZJ3_up.root DY ZJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM0/ZJ4_up.root DY ZJ 0 DM0_UP
 hadd -f outputs_DM0/ZJ_up.root outputs_DM0/ZJ0_up.root outputs_DM0/ZJ1_up.root outputs_DM0/ZJ2_up.root outputs_DM0/ZJ3_up.root outputs_DM0/ZJ4_up.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_DM0/EWKZ2l_up.root EWKZLL EWKZ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_DM0/EWKZ2nu_up.root EWKZNuNu EWKZ 0 DM0_UP
 hadd -f outputs_DM0/EWKZ_up.root outputs_DM0/EWKZ2l_up.root outputs_DM0/EWKZ2nu_up.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM0/TTT_up.root TT TTT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM0/TTJ_up.root TT TTJ 0 DM0_UP
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_DM0/W0_up.root W W 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_DM0/W1_up.root W W 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_DM0/W2_up.root W W 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_DM0/W3_up.root W W 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_DM0/W4_up.root W W 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_DM0/EWKWMinus_up.root EWKWminus W 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_DM0/EWKWPlus_up.root EWKWplus W 0 DM0_UP
 hadd -f outputs_DM0/W_up.root outputs_DM0/W0_up.root outputs_DM0/W1_up.root outputs_DM0/W2_up.root outputs_DM0/W3_up.root outputs_DM0/W4_up.root outputs_DM0/EWKWMinus_up.root outputs_DM0/EWKWPlus_up.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM0/WZ1l1nu2q_T_up.root WZ1L1Nu2Q VVT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM0/WZ1l3nu_T_up.root WZ1L3Nu VVT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM0/WZ3l1nu_T_up.root WZLLLNu VVT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM0/WZ2l2q_T_up.root WZ2L2Q VVT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM0/WW1l1nu2q_T_up.root WW1L1Nu2Q VVT 0 DM0_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM0/ZZ4l_T_up.root ZZ4L VVT 0 DM0_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM0/ZZ2l2q_T_up.root ZZ2L2Q VVT 0 DM0_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM0/VV2l2nu_T_up.root VV2L2Nu VVT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM0/Tbar-tW_T_up.root ST_tW_antitop VVT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM0/T-tW_T_up.root ST_tW_top VVT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM0/Tbar-tchan_T_up.root ST_t_antitop VVT 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM0/T-tchan_T_up.root ST_t_top VVT 0 DM0_UP
 hadd -f outputs_DM0/VVT_up.root outputs_DM0/WZ1l1nu2q_T_up.root outputs_DM0/WZ1l3nu_T_up.root outputs_DM0/WZ1l1nu2q_T_up.root outputs_DM0/WZ3l1nu_T_up.root outputs_DM0/WZ2l2q_T_up.root outputs_DM0/WW1l1nu2q_T_up.root outputs_DM0/ZZ4l_T_up.root outputs_DM0/ZZ2l2q_T_up.root outputs_DM0/VV2l2nu_T_up.root outputs_DM0/Tbar-tW_T_up.root outputs_DM0/T-tW_T_up.root outputs_DM0/Tbar-tchan_T_up.root outputs_DM0/T-tchan_T_up.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM0/WZ1l1nu2q_J_up.root WZ1L1Nu2Q VVJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM0/WZ1l3nu_J_up.root WZ1L3Nu VVJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM0/WZ3l1nu_J_up.root WZLLLNu VVJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM0/WZ2l2q_J_up.root WZ2L2Q VVJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM0/WW1l1nu2q_J_up.root WW1L1Nu2Q VVJ 0 DM0_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM0/ZZ4l_J_up.root ZZ4L VVJ 0 DM0_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM0/ZZ2l2q_J_up.root ZZ2L2Q VVJ 0 DM0_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM0/VV2l2nu_J_up.root VV2L2Nu VVJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM0/Tbar-tW_J_up.root ST_tW_antitop VVJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM0/T-tW_J_up.root ST_tW_top VVJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM0/Tbar-tchan_J_up.root ST_t_antitop VVJ 0 DM0_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM0/T-tchan_J_up.root ST_t_top VVJ 0 DM0_UP
 hadd -f outputs_DM0/VVJ_up.root outputs_DM0/WZ1l1nu2q_J_up.root outputs_DM0/WZ1l3nu_J_up.root outputs_DM0/WZ1l1nu2q_J_up.root outputs_DM0/WZ3l1nu_J_up.root outputs_DM0/WZ2l2q_J_up.root outputs_DM0/WW1l1nu2q_J_up.root outputs_DM0/ZZ4l_J_up.root outputs_DM0/ZZ2l2q_J_up.root outputs_DM0/VV2l2nu_J_up.root outputs_DM0/Tbar-tW_J_up.root outputs_DM0/T-tW_J_up.root outputs_DM0/Tbar-tchan_J_up.root outputs_DM0/T-tchan_J_up.root 



 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_DM0/VBF125_down.root VBF125 VBF125 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_DM0/ggH125_down.root ggH125 ggH125 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_DM0/WplusH125_down.root WplusH125 WH125 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_DM0/WminusH125_down.root WminusH125 WH125 0 DM0_DOWN
 hadd -f outputs_DM0/WH125_down.root outputs_DM0/WplusH125_down.root outputs_DM0/WminusH125_down.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_DM0/ZH125_down.root ZH125 ZH125 0 DM0_DOWN
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM0/ZTT0_down.root DY ZTT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM0/ZTT1_down.root DY ZTT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM0/ZTT2_down.root DY ZTT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM0/ZTT3_down.root DY ZTT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM0/ZTT4_down.root DY ZTT 0 DM0_DOWN
 hadd -f outputs_DM0/ZTT_down.root outputs_DM0/ZTT0_down.root outputs_DM0/ZTT1_down.root outputs_DM0/ZTT2_down.root outputs_DM0/ZTT3_down.root outputs_DM0/ZTT4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM0/ZL0_down.root DY ZL 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM0/ZL1_down.root DY ZL 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM0/ZL2_down.root DY ZL 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM0/ZL3_down.root DY ZL 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM0/ZL4_down.root DY  ZL 0 DM0_DOWN
 hadd -f outputs_DM0/ZL_down.root outputs_DM0/ZL0_down.root outputs_DM0/ZL1_down.root outputs_DM0/ZL2_down.root outputs_DM0/ZL3_down.root outputs_DM0/ZL4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM0/ZJ0_down.root DY ZJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM0/ZJ1_down.root DY ZJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM0/ZJ2_down.root DY ZJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM0/ZJ3_down.root DY ZJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM0/ZJ4_down.root DY ZJ 0 DM0_DOWN
 hadd -f outputs_DM0/ZJ_down.root outputs_DM0/ZJ0_down.root outputs_DM0/ZJ1_down.root outputs_DM0/ZJ2_down.root outputs_DM0/ZJ3_down.root outputs_DM0/ZJ4_down.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_DM0/EWKZ2l_down.root EWKZLL EWKZ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_DM0/EWKZ2nu_down.root EWKZNuNu EWKZ 0 DM0_DOWN
 hadd -f outputs_DM0/EWKZ_down.root outputs_DM0/EWKZ2l_down.root outputs_DM0/EWKZ2nu_down.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM0/TTT_down.root TT TTT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM0/TTJ_down.root TT TTJ 0 DM0_DOWN
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_DM0/W0_down.root W W 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_DM0/W1_down.root W W 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_DM0/W2_down.root W W 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_DM0/W3_down.root W W 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_DM0/W4_down.root W W 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_DM0/EWKWMinus_down.root EWKWminus W 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_DM0/EWKWPlus_down.root EWKWplus W 0 DM0_DOWN
 hadd -f outputs_DM0/W_down.root outputs_DM0/W0_down.root outputs_DM0/W1_down.root outputs_DM0/W2_down.root outputs_DM0/W3_down.root outputs_DM0/W4_down.root outputs_DM0/EWKWMinus_down.root outputs_DM0/EWKWPlus_down.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM0/WZ1l1nu2q_T_down.root WZ1L1Nu2Q VVT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM0/WZ1l3nu_T_down.root WZ1L3Nu VVT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM0/WZ3l1nu_T_down.root WZLLLNu VVT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM0/WZ2l2q_T_down.root WZ2L2Q VVT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM0/WW1l1nu2q_T_down.root WW1L1Nu2Q VVT 0 DM0_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM0/ZZ4l_T_down.root ZZ4L VVT 0 DM0_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM0/ZZ2l2q_T_down.root ZZ2L2Q VVT 0 DM0_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM0/VV2l2nu_T_down.root VV2L2Nu VVT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM0/Tbar-tW_T_down.root ST_tW_antitop VVT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM0/T-tW_T_down.root ST_tW_top VVT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM0/Tbar-tchan_T_down.root ST_t_antitop VVT 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM0/T-tchan_T_down.root ST_t_top VVT 0 DM0_DOWN
 hadd -f outputs_DM0/VVT_down.root outputs_DM0/WZ1l1nu2q_T_down.root outputs_DM0/WZ1l3nu_T_down.root outputs_DM0/WZ1l1nu2q_T_down.root outputs_DM0/WZ3l1nu_T_down.root outputs_DM0/WZ2l2q_T_down.root outputs_DM0/WW1l1nu2q_T_down.root outputs_DM0/ZZ4l_T_down.root outputs_DM0/ZZ2l2q_T_down.root outputs_DM0/VV2l2nu_T_down.root outputs_DM0/Tbar-tW_T_down.root outputs_DM0/T-tW_T_down.root outputs_DM0/Tbar-tchan_T_down.root outputs_DM0/T-tchan_T_down.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM0/WZ1l1nu2q_J_down.root WZ1L1Nu2Q VVJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM0/WZ1l3nu_J_down.root WZ1L3Nu VVJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM0/WZ3l1nu_J_down.root WZLLLNu VVJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM0/WZ2l2q_J_down.root WZ2L2Q VVJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM0/WW1l1nu2q_J_down.root WW1L1Nu2Q VVJ 0 DM0_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM0/ZZ4l_J_down.root ZZ4L VVJ 0 DM0_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM0/ZZ2l2q_J_down.root ZZ2L2Q VVJ 0 DM0_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM0/VV2l2nu_J_down.root VV2L2Nu VVJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM0/Tbar-tW_J_down.root ST_tW_antitop VVJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM0/T-tW_J_down.root ST_tW_top VVJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM0/Tbar-tchan_J_down.root ST_t_antitop VVJ 0 DM0_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM0/T-tchan_J_down.root ST_t_top VVJ 0 DM0_DOWN
 hadd -f outputs_DM0/VVJ_down.root outputs_DM0/WZ1l1nu2q_J_down.root outputs_DM0/WZ1l3nu_J_down.root outputs_DM0/WZ1l1nu2q_J_down.root outputs_DM0/WZ3l1nu_J_down.root outputs_DM0/WZ2l2q_J_down.root outputs_DM0/WW1l1nu2q_J_down.root outputs_DM0/ZZ4l_J_down.root outputs_DM0/ZZ2l2q_J_down.root outputs_DM0/VV2l2nu_J_down.root outputs_DM0/Tbar-tW_J_down.root outputs_DM0/T-tW_J_down.root outputs_DM0/Tbar-tchan_J_down.root outputs_DM0/T-tchan_J_down.root 

#hadd
 hadd -f final_DM0.root outputs_DM0/ZTT_down.root outputs_DM0/ZJ_down.root outputs_DM0/ZL_down.root outputs_DM0/TTT_down.root outputs_DM0/TTJ_down.root outputs_DM0/VVT_down.root outputs_DM0/VVJ_down.root outputs_DM0/W_down.root outputs_DM0/EWKZ_down.root outputs_DM0/VBF125_down.root outputs_DM0/ggH125_down.root outputs_DM0/WH125_down.root outputs_DM0/ZH125_down.root outputs_DM0/ZTT_up.root outputs_DM0/ZJ_up.root outputs_DM0/ZL_up.root outputs_DM0/TTT_up.root outputs_DM0/TTJ_up.root outputs_DM0/VVT_up.root outputs_DM0/VVJ_up.root outputs_DM0/W_up.root outputs_DM0/EWKZ_up.root outputs_DM0/VBF125_up.root outputs_DM0/ggH125_up.root outputs_DM0/WH125_up.root outputs_DM0/ZH125_up.root 



''' UnclusteredMET '''
rm outputs_DM1/*

 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_DM1/VBF125_up.root VBF125 VBF125 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_DM1/ggH125_up.root ggH125 ggH125 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_DM1/WplusH125_up.root WplusH125 WH125 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_DM1/WminusH125_up.root WminusH125 WH125 0 DM1_UP
 hadd -f outputs_DM1/WH125_up.root outputs_DM1/WplusH125_up.root outputs_DM1/WminusH125_up.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_DM1/ZH125_up.root ZH125 ZH125 0 DM1_UP
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM1/ZTT0_up.root DY ZTT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM1/ZTT1_up.root DY ZTT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM1/ZTT2_up.root DY ZTT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM1/ZTT3_up.root DY ZTT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM1/ZTT4_up.root DY ZTT 0 DM1_UP
 hadd -f outputs_DM1/ZTT_up.root outputs_DM1/ZTT0_up.root outputs_DM1/ZTT1_up.root outputs_DM1/ZTT2_up.root outputs_DM1/ZTT3_up.root outputs_DM1/ZTT4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM1/ZL0_up.root DY ZL 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM1/ZL1_up.root DY ZL 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM1/ZL2_up.root DY ZL 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM1/ZL3_up.root DY ZL 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM1/ZL4_up.root DY  ZL 0 DM1_UP
 hadd -f outputs_DM1/ZL_up.root outputs_DM1/ZL0_up.root outputs_DM1/ZL1_up.root outputs_DM1/ZL2_up.root outputs_DM1/ZL3_up.root outputs_DM1/ZL4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM1/ZJ0_up.root DY ZJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM1/ZJ1_up.root DY ZJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM1/ZJ2_up.root DY ZJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM1/ZJ3_up.root DY ZJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM1/ZJ4_up.root DY ZJ 0 DM1_UP
 hadd -f outputs_DM1/ZJ_up.root outputs_DM1/ZJ0_up.root outputs_DM1/ZJ1_up.root outputs_DM1/ZJ2_up.root outputs_DM1/ZJ3_up.root outputs_DM1/ZJ4_up.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_DM1/EWKZ2l_up.root EWKZLL EWKZ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_DM1/EWKZ2nu_up.root EWKZNuNu EWKZ 0 DM1_UP
 hadd -f outputs_DM1/EWKZ_up.root outputs_DM1/EWKZ2l_up.root outputs_DM1/EWKZ2nu_up.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM1/TTT_up.root TT TTT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM1/TTJ_up.root TT TTJ 0 DM1_UP
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_DM1/W0_up.root W W 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_DM1/W1_up.root W W 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_DM1/W2_up.root W W 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_DM1/W3_up.root W W 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_DM1/W4_up.root W W 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_DM1/EWKWMinus_up.root EWKWminus W 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_DM1/EWKWPlus_up.root EWKWplus W 0 DM1_UP
 hadd -f outputs_DM1/W_up.root outputs_DM1/W0_up.root outputs_DM1/W1_up.root outputs_DM1/W2_up.root outputs_DM1/W3_up.root outputs_DM1/W4_up.root outputs_DM1/EWKWMinus_up.root outputs_DM1/EWKWPlus_up.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM1/WZ1l1nu2q_T_up.root WZ1L1Nu2Q VVT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM1/WZ1l3nu_T_up.root WZ1L3Nu VVT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM1/WZ3l1nu_T_up.root WZLLLNu VVT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM1/WZ2l2q_T_up.root WZ2L2Q VVT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM1/WW1l1nu2q_T_up.root WW1L1Nu2Q VVT 0 DM1_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM1/ZZ4l_T_up.root ZZ4L VVT 0 DM1_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM1/ZZ2l2q_T_up.root ZZ2L2Q VVT 0 DM1_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM1/VV2l2nu_T_up.root VV2L2Nu VVT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM1/Tbar-tW_T_up.root ST_tW_antitop VVT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM1/T-tW_T_up.root ST_tW_top VVT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM1/Tbar-tchan_T_up.root ST_t_antitop VVT 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM1/T-tchan_T_up.root ST_t_top VVT 0 DM1_UP
 hadd -f outputs_DM1/VVT_up.root outputs_DM1/WZ1l1nu2q_T_up.root outputs_DM1/WZ1l3nu_T_up.root outputs_DM1/WZ1l1nu2q_T_up.root outputs_DM1/WZ3l1nu_T_up.root outputs_DM1/WZ2l2q_T_up.root outputs_DM1/WW1l1nu2q_T_up.root outputs_DM1/ZZ4l_T_up.root outputs_DM1/ZZ2l2q_T_up.root outputs_DM1/VV2l2nu_T_up.root outputs_DM1/Tbar-tW_T_up.root outputs_DM1/T-tW_T_up.root outputs_DM1/Tbar-tchan_T_up.root outputs_DM1/T-tchan_T_up.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM1/WZ1l1nu2q_J_up.root WZ1L1Nu2Q VVJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM1/WZ1l3nu_J_up.root WZ1L3Nu VVJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM1/WZ3l1nu_J_up.root WZLLLNu VVJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM1/WZ2l2q_J_up.root WZ2L2Q VVJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM1/WW1l1nu2q_J_up.root WW1L1Nu2Q VVJ 0 DM1_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM1/ZZ4l_J_up.root ZZ4L VVJ 0 DM1_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM1/ZZ2l2q_J_up.root ZZ2L2Q VVJ 0 DM1_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM1/VV2l2nu_J_up.root VV2L2Nu VVJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM1/Tbar-tW_J_up.root ST_tW_antitop VVJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM1/T-tW_J_up.root ST_tW_top VVJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM1/Tbar-tchan_J_up.root ST_t_antitop VVJ 0 DM1_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM1/T-tchan_J_up.root ST_t_top VVJ 0 DM1_UP
 hadd -f outputs_DM1/VVJ_up.root outputs_DM1/WZ1l1nu2q_J_up.root outputs_DM1/WZ1l3nu_J_up.root outputs_DM1/WZ1l1nu2q_J_up.root outputs_DM1/WZ3l1nu_J_up.root outputs_DM1/WZ2l2q_J_up.root outputs_DM1/WW1l1nu2q_J_up.root outputs_DM1/ZZ4l_J_up.root outputs_DM1/ZZ2l2q_J_up.root outputs_DM1/VV2l2nu_J_up.root outputs_DM1/Tbar-tW_J_up.root outputs_DM1/T-tW_J_up.root outputs_DM1/Tbar-tchan_J_up.root outputs_DM1/T-tchan_J_up.root 








 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_DM1/VBF125_down.root VBF125 VBF125 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_DM1/ggH125_down.root ggH125 ggH125 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_DM1/WplusH125_down.root WplusH125 WH125 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_DM1/WminusH125_down.root WminusH125 WH125 0 DM1_DOWN
 hadd -f outputs_DM1/WH125_down.root outputs_DM1/WplusH125_down.root outputs_DM1/WminusH125_down.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_DM1/ZH125_down.root ZH125 ZH125 0 DM1_DOWN
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM1/ZTT0_down.root DY ZTT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM1/ZTT1_down.root DY ZTT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM1/ZTT2_down.root DY ZTT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM1/ZTT3_down.root DY ZTT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM1/ZTT4_down.root DY ZTT 0 DM1_DOWN
 hadd -f outputs_DM1/ZTT_down.root outputs_DM1/ZTT0_down.root outputs_DM1/ZTT1_down.root outputs_DM1/ZTT2_down.root outputs_DM1/ZTT3_down.root outputs_DM1/ZTT4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM1/ZL0_down.root DY ZL 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM1/ZL1_down.root DY ZL 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM1/ZL2_down.root DY ZL 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM1/ZL3_down.root DY ZL 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM1/ZL4_down.root DY  ZL 0 DM1_DOWN
 hadd -f outputs_DM1/ZL_down.root outputs_DM1/ZL0_down.root outputs_DM1/ZL1_down.root outputs_DM1/ZL2_down.root outputs_DM1/ZL3_down.root outputs_DM1/ZL4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM1/ZJ0_down.root DY ZJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM1/ZJ1_down.root DY ZJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM1/ZJ2_down.root DY ZJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM1/ZJ3_down.root DY ZJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM1/ZJ4_down.root DY ZJ 0 DM1_DOWN
 hadd -f outputs_DM1/ZJ_down.root outputs_DM1/ZJ0_down.root outputs_DM1/ZJ1_down.root outputs_DM1/ZJ2_down.root outputs_DM1/ZJ3_down.root outputs_DM1/ZJ4_down.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_DM1/EWKZ2l_down.root EWKZLL EWKZ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_DM1/EWKZ2nu_down.root EWKZNuNu EWKZ 0 DM1_DOWN
 hadd -f outputs_DM1/EWKZ_down.root outputs_DM1/EWKZ2l_down.root outputs_DM1/EWKZ2nu_down.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM1/TTT_down.root TT TTT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM1/TTJ_down.root TT TTJ 0 DM1_DOWN
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_DM1/W0_down.root W W 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_DM1/W1_down.root W W 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_DM1/W2_down.root W W 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_DM1/W3_down.root W W 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_DM1/W4_down.root W W 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_DM1/EWKWMinus_down.root EWKWminus W 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_DM1/EWKWPlus_down.root EWKWplus W 0 DM1_DOWN
 hadd -f outputs_DM1/W_down.root outputs_DM1/W0_down.root outputs_DM1/W1_down.root outputs_DM1/W2_down.root outputs_DM1/W3_down.root outputs_DM1/W4_down.root outputs_DM1/EWKWMinus_down.root outputs_DM1/EWKWPlus_down.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM1/WZ1l1nu2q_T_down.root WZ1L1Nu2Q VVT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM1/WZ1l3nu_T_down.root WZ1L3Nu VVT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM1/WZ3l1nu_T_down.root WZLLLNu VVT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM1/WZ2l2q_T_down.root WZ2L2Q VVT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM1/WW1l1nu2q_T_down.root WW1L1Nu2Q VVT 0 DM1_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM1/ZZ4l_T_down.root ZZ4L VVT 0 DM1_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM1/ZZ2l2q_T_down.root ZZ2L2Q VVT 0 DM1_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM1/VV2l2nu_T_down.root VV2L2Nu VVT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM1/Tbar-tW_T_down.root ST_tW_antitop VVT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM1/T-tW_T_down.root ST_tW_top VVT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM1/Tbar-tchan_T_down.root ST_t_antitop VVT 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM1/T-tchan_T_down.root ST_t_top VVT 0 DM1_DOWN
 hadd -f outputs_DM1/VVT_down.root outputs_DM1/WZ1l1nu2q_T_down.root outputs_DM1/WZ1l3nu_T_down.root outputs_DM1/WZ1l1nu2q_T_down.root outputs_DM1/WZ3l1nu_T_down.root outputs_DM1/WZ2l2q_T_down.root outputs_DM1/WW1l1nu2q_T_down.root outputs_DM1/ZZ4l_T_down.root outputs_DM1/ZZ2l2q_T_down.root outputs_DM1/VV2l2nu_T_down.root outputs_DM1/Tbar-tW_T_down.root outputs_DM1/T-tW_T_down.root outputs_DM1/Tbar-tchan_T_down.root outputs_DM1/T-tchan_T_down.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM1/WZ1l1nu2q_J_down.root WZ1L1Nu2Q VVJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM1/WZ1l3nu_J_down.root WZ1L3Nu VVJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM1/WZ3l1nu_J_down.root WZLLLNu VVJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM1/WZ2l2q_J_down.root WZ2L2Q VVJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM1/WW1l1nu2q_J_down.root WW1L1Nu2Q VVJ 0 DM1_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM1/ZZ4l_J_down.root ZZ4L VVJ 0 DM1_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM1/ZZ2l2q_J_down.root ZZ2L2Q VVJ 0 DM1_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM1/VV2l2nu_J_down.root VV2L2Nu VVJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM1/Tbar-tW_J_down.root ST_tW_antitop VVJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM1/T-tW_J_down.root ST_tW_top VVJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM1/Tbar-tchan_J_down.root ST_t_antitop VVJ 0 DM1_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM1/T-tchan_J_down.root ST_t_top VVJ 0 DM1_DOWN
 hadd -f outputs_DM1/VVJ_down.root outputs_DM1/WZ1l1nu2q_J_down.root outputs_DM1/WZ1l3nu_J_down.root outputs_DM1/WZ1l1nu2q_J_down.root outputs_DM1/WZ3l1nu_J_down.root outputs_DM1/WZ2l2q_J_down.root outputs_DM1/WW1l1nu2q_J_down.root outputs_DM1/ZZ4l_J_down.root outputs_DM1/ZZ2l2q_J_down.root outputs_DM1/VV2l2nu_J_down.root outputs_DM1/Tbar-tW_J_down.root outputs_DM1/T-tW_J_down.root outputs_DM1/Tbar-tchan_J_down.root outputs_DM1/T-tchan_J_down.root 


 hadd -f final_DM1.root outputs_DM1/ZTT_down.root outputs_DM1/ZJ_down.root outputs_DM1/ZL_down.root outputs_DM1/TTT_down.root outputs_DM1/TTJ_down.root outputs_DM1/VVT_down.root outputs_DM1/VVJ_down.root outputs_DM1/W_down.root outputs_DM1/EWKZ_down.root outputs_DM1/VBF125_down.root outputs_DM1/ggH125_down.root outputs_DM1/WH125_down.root outputs_DM1/ZH125_down.root outputs_DM1/ZTT_up.root outputs_DM1/ZJ_up.root outputs_DM1/ZL_up.root outputs_DM1/TTT_up.root outputs_DM1/TTJ_up.root outputs_DM1/VVT_up.root outputs_DM1/VVJ_up.root outputs_DM1/W_up.root outputs_DM1/EWKZ_up.root outputs_DM1/VBF125_up.root outputs_DM1/ggH125_up.root outputs_DM1/WH125_up.root outputs_DM1/ZH125_up.root 

### DM10


''' UnclusteredMET '''
rm outputs_DM10/*

 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_DM10/VBF125_up.root VBF125 VBF125 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_DM10/ggH125_up.root ggH125 ggH125 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_DM10/WplusH125_up.root WplusH125 WH125 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_DM10/WminusH125_up.root WminusH125 WH125 0 DM10_UP
 hadd -f outputs_DM10/WH125_up.root outputs_DM10/WplusH125_up.root outputs_DM10/WminusH125_up.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_DM10/ZH125_up.root ZH125 ZH125 0 DM10_UP
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM10/ZTT0_up.root DY ZTT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM10/ZTT1_up.root DY ZTT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM10/ZTT2_up.root DY ZTT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM10/ZTT3_up.root DY ZTT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM10/ZTT4_up.root DY ZTT 0 DM10_UP
 hadd -f outputs_DM10/ZTT_up.root outputs_DM10/ZTT0_up.root outputs_DM10/ZTT1_up.root outputs_DM10/ZTT2_up.root outputs_DM10/ZTT3_up.root outputs_DM10/ZTT4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM10/ZL0_up.root DY ZL 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM10/ZL1_up.root DY ZL 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM10/ZL2_up.root DY ZL 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM10/ZL3_up.root DY ZL 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM10/ZL4_up.root DY  ZL 0 DM10_UP
 hadd -f outputs_DM10/ZL_up.root outputs_DM10/ZL0_up.root outputs_DM10/ZL1_up.root outputs_DM10/ZL2_up.root outputs_DM10/ZL3_up.root outputs_DM10/ZL4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM10/ZJ0_up.root DY ZJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM10/ZJ1_up.root DY ZJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM10/ZJ2_up.root DY ZJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM10/ZJ3_up.root DY ZJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM10/ZJ4_up.root DY ZJ 0 DM10_UP
 hadd -f outputs_DM10/ZJ_up.root outputs_DM10/ZJ0_up.root outputs_DM10/ZJ1_up.root outputs_DM10/ZJ2_up.root outputs_DM10/ZJ3_up.root outputs_DM10/ZJ4_up.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_DM10/EWKZ2l_up.root EWKZLL EWKZ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_DM10/EWKZ2nu_up.root EWKZNuNu EWKZ 0 DM10_UP
 hadd -f outputs_DM10/EWKZ_up.root outputs_DM10/EWKZ2l_up.root outputs_DM10/EWKZ2nu_up.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM10/TTT_up.root TT TTT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM10/TTJ_up.root TT TTJ 0 DM10_UP
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_DM10/W0_up.root W W 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_DM10/W1_up.root W W 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_DM10/W2_up.root W W 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_DM10/W3_up.root W W 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_DM10/W4_up.root W W 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_DM10/EWKWMinus_up.root EWKWminus W 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_DM10/EWKWPlus_up.root EWKWplus W 0 DM10_UP
 hadd -f outputs_DM10/W_up.root outputs_DM10/W0_up.root outputs_DM10/W1_up.root outputs_DM10/W2_up.root outputs_DM10/W3_up.root outputs_DM10/W4_up.root outputs_DM10/EWKWMinus_up.root outputs_DM10/EWKWPlus_up.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM10/WZ1l1nu2q_T_up.root WZ1L1Nu2Q VVT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM10/WZ1l3nu_T_up.root WZ1L3Nu VVT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM10/WZ3l1nu_T_up.root WZLLLNu VVT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM10/WZ2l2q_T_up.root WZ2L2Q VVT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM10/WW1l1nu2q_T_up.root WW1L1Nu2Q VVT 0 DM10_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM10/ZZ4l_T_up.root ZZ4L VVT 0 DM10_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM10/ZZ2l2q_T_up.root ZZ2L2Q VVT 0 DM10_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM10/VV2l2nu_T_up.root VV2L2Nu VVT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM10/Tbar-tW_T_up.root ST_tW_antitop VVT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM10/T-tW_T_up.root ST_tW_top VVT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM10/Tbar-tchan_T_up.root ST_t_antitop VVT 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM10/T-tchan_T_up.root ST_t_top VVT 0 DM10_UP
 hadd -f outputs_DM10/VVT_up.root outputs_DM10/WZ1l1nu2q_T_up.root outputs_DM10/WZ1l3nu_T_up.root outputs_DM10/WZ1l1nu2q_T_up.root outputs_DM10/WZ3l1nu_T_up.root outputs_DM10/WZ2l2q_T_up.root outputs_DM10/WW1l1nu2q_T_up.root outputs_DM10/ZZ4l_T_up.root outputs_DM10/ZZ2l2q_T_up.root outputs_DM10/VV2l2nu_T_up.root outputs_DM10/Tbar-tW_T_up.root outputs_DM10/T-tW_T_up.root outputs_DM10/Tbar-tchan_T_up.root outputs_DM10/T-tchan_T_up.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM10/WZ1l1nu2q_J_up.root WZ1L1Nu2Q VVJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM10/WZ1l3nu_J_up.root WZ1L3Nu VVJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM10/WZ3l1nu_J_up.root WZLLLNu VVJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM10/WZ2l2q_J_up.root WZ2L2Q VVJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM10/WW1l1nu2q_J_up.root WW1L1Nu2Q VVJ 0 DM10_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM10/ZZ4l_J_up.root ZZ4L VVJ 0 DM10_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM10/ZZ2l2q_J_up.root ZZ2L2Q VVJ 0 DM10_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM10/VV2l2nu_J_up.root VV2L2Nu VVJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM10/Tbar-tW_J_up.root ST_tW_antitop VVJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM10/T-tW_J_up.root ST_tW_top VVJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM10/Tbar-tchan_J_up.root ST_t_antitop VVJ 0 DM10_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM10/T-tchan_J_up.root ST_t_top VVJ 0 DM10_UP
 hadd -f outputs_DM10/VVJ_up.root outputs_DM10/WZ1l1nu2q_J_up.root outputs_DM10/WZ1l3nu_J_up.root outputs_DM10/WZ1l1nu2q_J_up.root outputs_DM10/WZ3l1nu_J_up.root outputs_DM10/WZ2l2q_J_up.root outputs_DM10/WW1l1nu2q_J_up.root outputs_DM10/ZZ4l_J_up.root outputs_DM10/ZZ2l2q_J_up.root outputs_DM10/VV2l2nu_J_up.root outputs_DM10/Tbar-tW_J_up.root outputs_DM10/T-tW_J_up.root outputs_DM10/Tbar-tchan_J_up.root outputs_DM10/T-tchan_J_up.root 








 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_DM10/VBF125_down.root VBF125 VBF125 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_DM10/ggH125_down.root ggH125 ggH125 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_DM10/WplusH125_down.root WplusH125 WH125 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_DM10/WminusH125_down.root WminusH125 WH125 0 DM10_DOWN
 hadd -f outputs_DM10/WH125_down.root outputs_DM10/WplusH125_down.root outputs_DM10/WminusH125_down.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_DM10/ZH125_down.root ZH125 ZH125 0 DM10_DOWN
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM10/ZTT0_down.root DY ZTT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM10/ZTT1_down.root DY ZTT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM10/ZTT2_down.root DY ZTT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM10/ZTT3_down.root DY ZTT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM10/ZTT4_down.root DY ZTT 0 DM10_DOWN
 hadd -f outputs_DM10/ZTT_down.root outputs_DM10/ZTT0_down.root outputs_DM10/ZTT1_down.root outputs_DM10/ZTT2_down.root outputs_DM10/ZTT3_down.root outputs_DM10/ZTT4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM10/ZL0_down.root DY ZL 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM10/ZL1_down.root DY ZL 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM10/ZL2_down.root DY ZL 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM10/ZL3_down.root DY ZL 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM10/ZL4_down.root DY  ZL 0 DM10_DOWN
 hadd -f outputs_DM10/ZL_down.root outputs_DM10/ZL0_down.root outputs_DM10/ZL1_down.root outputs_DM10/ZL2_down.root outputs_DM10/ZL3_down.root outputs_DM10/ZL4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_DM10/ZJ0_down.root DY ZJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_DM10/ZJ1_down.root DY ZJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_DM10/ZJ2_down.root DY ZJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_DM10/ZJ3_down.root DY ZJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_DM10/ZJ4_down.root DY ZJ 0 DM10_DOWN
 hadd -f outputs_DM10/ZJ_down.root outputs_DM10/ZJ0_down.root outputs_DM10/ZJ1_down.root outputs_DM10/ZJ2_down.root outputs_DM10/ZJ3_down.root outputs_DM10/ZJ4_down.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_DM10/EWKZ2l_down.root EWKZLL EWKZ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_DM10/EWKZ2nu_down.root EWKZNuNu EWKZ 0 DM10_DOWN
 hadd -f outputs_DM10/EWKZ_down.root outputs_DM10/EWKZ2l_down.root outputs_DM10/EWKZ2nu_down.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM10/TTT_down.root TT TTT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_DM10/TTJ_down.root TT TTJ 0 DM10_DOWN
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_DM10/W0_down.root W W 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_DM10/W1_down.root W W 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_DM10/W2_down.root W W 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_DM10/W3_down.root W W 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_DM10/W4_down.root W W 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_DM10/EWKWMinus_down.root EWKWminus W 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_DM10/EWKWPlus_down.root EWKWplus W 0 DM10_DOWN
 hadd -f outputs_DM10/W_down.root outputs_DM10/W0_down.root outputs_DM10/W1_down.root outputs_DM10/W2_down.root outputs_DM10/W3_down.root outputs_DM10/W4_down.root outputs_DM10/EWKWMinus_down.root outputs_DM10/EWKWPlus_down.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM10/WZ1l1nu2q_T_down.root WZ1L1Nu2Q VVT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM10/WZ1l3nu_T_down.root WZ1L3Nu VVT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM10/WZ3l1nu_T_down.root WZLLLNu VVT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM10/WZ2l2q_T_down.root WZ2L2Q VVT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM10/WW1l1nu2q_T_down.root WW1L1Nu2Q VVT 0 DM10_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM10/ZZ4l_T_down.root ZZ4L VVT 0 DM10_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM10/ZZ2l2q_T_down.root ZZ2L2Q VVT 0 DM10_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM10/VV2l2nu_T_down.root VV2L2Nu VVT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM10/Tbar-tW_T_down.root ST_tW_antitop VVT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM10/T-tW_T_down.root ST_tW_top VVT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM10/Tbar-tchan_T_down.root ST_t_antitop VVT 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM10/T-tchan_T_down.root ST_t_top VVT 0 DM10_DOWN
 hadd -f outputs_DM10/VVT_down.root outputs_DM10/WZ1l1nu2q_T_down.root outputs_DM10/WZ1l3nu_T_down.root outputs_DM10/WZ1l1nu2q_T_down.root outputs_DM10/WZ3l1nu_T_down.root outputs_DM10/WZ2l2q_T_down.root outputs_DM10/WW1l1nu2q_T_down.root outputs_DM10/ZZ4l_T_down.root outputs_DM10/ZZ2l2q_T_down.root outputs_DM10/VV2l2nu_T_down.root outputs_DM10/Tbar-tW_T_down.root outputs_DM10/T-tW_T_down.root outputs_DM10/Tbar-tchan_T_down.root outputs_DM10/T-tchan_T_down.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_DM10/WZ1l1nu2q_J_down.root WZ1L1Nu2Q VVJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_DM10/WZ1l3nu_J_down.root WZ1L3Nu VVJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_DM10/WZ3l1nu_J_down.root WZLLLNu VVJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_DM10/WZ2l2q_J_down.root WZ2L2Q VVJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_DM10/WW1l1nu2q_J_down.root WW1L1Nu2Q VVJ 0 DM10_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_DM10/ZZ4l_J_down.root ZZ4L VVJ 0 DM10_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_DM10/ZZ2l2q_J_down.root ZZ2L2Q VVJ 0 DM10_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_DM10/VV2l2nu_J_down.root VV2L2Nu VVJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_DM10/Tbar-tW_J_down.root ST_tW_antitop VVJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_DM10/T-tW_J_down.root ST_tW_top VVJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_DM10/Tbar-tchan_J_down.root ST_t_antitop VVJ 0 DM10_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_DM10/T-tchan_J_down.root ST_t_top VVJ 0 DM10_DOWN
 hadd -f outputs_DM10/VVJ_down.root outputs_DM10/WZ1l1nu2q_J_down.root outputs_DM10/WZ1l3nu_J_down.root outputs_DM10/WZ1l1nu2q_J_down.root outputs_DM10/WZ3l1nu_J_down.root outputs_DM10/WZ2l2q_J_down.root outputs_DM10/WW1l1nu2q_J_down.root outputs_DM10/ZZ4l_J_down.root outputs_DM10/ZZ2l2q_J_down.root outputs_DM10/VV2l2nu_J_down.root outputs_DM10/Tbar-tW_J_down.root outputs_DM10/T-tW_J_down.root outputs_DM10/Tbar-tchan_J_down.root outputs_DM10/T-tchan_J_down.root 

 hadd -f final_DM10.root outputs_DM10/ZTT_down.root outputs_DM10/ZJ_down.root outputs_DM10/ZL_down.root outputs_DM10/TTT_down.root outputs_DM10/TTJ_down.root outputs_DM10/VVT_down.root outputs_DM10/VVJ_down.root outputs_DM10/W_down.root outputs_DM10/EWKZ_down.root outputs_DM10/VBF125_down.root outputs_DM10/ggH125_down.root outputs_DM10/WH125_down.root outputs_DM10/ZH125_down.root outputs_DM10/ZTT_up.root outputs_DM10/ZJ_up.root outputs_DM10/ZL_up.root outputs_DM10/TTT_up.root outputs_DM10/TTJ_up.root outputs_DM10/VVT_up.root outputs_DM10/VVJ_up.root outputs_DM10/W_up.root outputs_DM10/EWKZ_up.root outputs_DM10/VBF125_up.root outputs_DM10/ggH125_up.root outputs_DM10/WH125_up.root outputs_DM10/ZH125_up.root 