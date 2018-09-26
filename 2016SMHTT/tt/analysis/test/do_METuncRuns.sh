
###################
### METunc runs ###
### All but QCD ###
###################


''' ClusteredMET '''
rm outputs_ClusteredMet/*
 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_ClusteredMet/VBF125_up.root VBF125 VBF125 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_ClusteredMet/ggH125_up.root ggH125 ggH125 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_ClusteredMet/WplusH125_up.root WplusH125 WH125 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_ClusteredMet/WminusH125_up.root WminusH125 WH125 0 ClusteredMet_UP
 hadd -f outputs_ClusteredMet/WH125_up.root outputs_ClusteredMet/WplusH125_up.root outputs_ClusteredMet/WminusH125_up.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_ClusteredMet/ZH125_up.root ZH125 ZH125 0 ClusteredMet_UP
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_ClusteredMet/ZTT0_up.root DY ZTT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_ClusteredMet/ZTT1_up.root DY ZTT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_ClusteredMet/ZTT2_up.root DY ZTT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_ClusteredMet/ZTT3_up.root DY ZTT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_ClusteredMet/ZTT4_up.root DY ZTT 0 ClusteredMet_UP
 hadd -f outputs_ClusteredMet/ZTT_up.root outputs_ClusteredMet/ZTT0_up.root outputs_ClusteredMet/ZTT1_up.root outputs_ClusteredMet/ZTT2_up.root outputs_ClusteredMet/ZTT3_up.root outputs_ClusteredMet/ZTT4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_ClusteredMet/ZL0_up.root DY ZL 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_ClusteredMet/ZL1_up.root DY ZL 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_ClusteredMet/ZL2_up.root DY ZL 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_ClusteredMet/ZL3_up.root DY ZL 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_ClusteredMet/ZL4_up.root DY  ZL 0 ClusteredMet_UP
 hadd -f outputs_ClusteredMet/ZL_up.root outputs_ClusteredMet/ZL0_up.root outputs_ClusteredMet/ZL1_up.root outputs_ClusteredMet/ZL2_up.root outputs_ClusteredMet/ZL3_up.root outputs_ClusteredMet/ZL4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_ClusteredMet/ZJ0_up.root DY ZJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_ClusteredMet/ZJ1_up.root DY ZJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_ClusteredMet/ZJ2_up.root DY ZJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_ClusteredMet/ZJ3_up.root DY ZJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_ClusteredMet/ZJ4_up.root DY ZJ 0 ClusteredMet_UP
 hadd -f outputs_ClusteredMet/ZJ_up.root outputs_ClusteredMet/ZJ0_up.root outputs_ClusteredMet/ZJ1_up.root outputs_ClusteredMet/ZJ2_up.root outputs_ClusteredMet/ZJ3_up.root outputs_ClusteredMet/ZJ4_up.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_ClusteredMet/EWKZ2l_up.root EWKZLL EWKZ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_ClusteredMet/EWKZ2nu_up.root EWKZNuNu EWKZ 0 ClusteredMet_UP
 hadd -f outputs_ClusteredMet/EWKZ_up.root outputs_ClusteredMet/EWKZ2l_up.root outputs_ClusteredMet/EWKZ2nu_up.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_ClusteredMet/TTT_up.root TT TTT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_ClusteredMet/TTJ_up.root TT TTJ 0 ClusteredMet_UP
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_ClusteredMet/W0_up.root W W 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_ClusteredMet/W1_up.root W W 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_ClusteredMet/W2_up.root W W 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_ClusteredMet/W3_up.root W W 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_ClusteredMet/W4_up.root W W 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_ClusteredMet/EWKWMinus_up.root EWKWminus W 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_ClusteredMet/EWKWPlus_up.root EWKWplus W 0 ClusteredMet_UP
 hadd -f outputs_ClusteredMet/W_up.root outputs_ClusteredMet/W0_up.root outputs_ClusteredMet/W1_up.root outputs_ClusteredMet/W2_up.root outputs_ClusteredMet/W3_up.root outputs_ClusteredMet/W4_up.root outputs_ClusteredMet/EWKWMinus_up.root outputs_ClusteredMet/EWKWPlus_up.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_ClusteredMet/WZ1l1nu2q_T_up.root WZ1L1Nu2Q VVT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_ClusteredMet/WZ1l3nu_T_up.root WZ1L3Nu VVT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_ClusteredMet/WZ3l1nu_T_up.root WZLLLNu VVT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_ClusteredMet/WZ2l2q_T_up.root WZ2L2Q VVT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_ClusteredMet/WW1l1nu2q_T_up.root WW1L1Nu2Q VVT 0 ClusteredMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_ClusteredMet/ZZ4l_T_up.root ZZ4L VVT 0 ClusteredMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_ClusteredMet/ZZ2l2q_T_up.root ZZ2L2Q VVT 0 ClusteredMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_ClusteredMet/VV2l2nu_T_up.root VV2L2Nu VVT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_ClusteredMet/Tbar-tW_T_up.root ST_tW_antitop VVT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_ClusteredMet/T-tW_T_up.root ST_tW_top VVT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_ClusteredMet/Tbar-tchan_T_up.root ST_t_antitop VVT 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_ClusteredMet/T-tchan_T_up.root ST_t_top VVT 0 ClusteredMet_UP
 hadd -f outputs_ClusteredMet/VVT_up.root outputs_ClusteredMet/WZ1l1nu2q_T_up.root outputs_ClusteredMet/WZ1l3nu_T_up.root outputs_ClusteredMet/WZ1l1nu2q_T_up.root outputs_ClusteredMet/WZ3l1nu_T_up.root outputs_ClusteredMet/WZ2l2q_T_up.root outputs_ClusteredMet/WW1l1nu2q_T_up.root outputs_ClusteredMet/ZZ4l_T_up.root outputs_ClusteredMet/ZZ2l2q_T_up.root outputs_ClusteredMet/VV2l2nu_T_up.root outputs_ClusteredMet/Tbar-tW_T_up.root outputs_ClusteredMet/T-tW_T_up.root outputs_ClusteredMet/Tbar-tchan_T_up.root outputs_ClusteredMet/T-tchan_T_up.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_ClusteredMet/WZ1l1nu2q_J_up.root WZ1L1Nu2Q VVJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_ClusteredMet/WZ1l3nu_J_up.root WZ1L3Nu VVJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_ClusteredMet/WZ3l1nu_J_up.root WZLLLNu VVJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_ClusteredMet/WZ2l2q_J_up.root WZ2L2Q VVJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_ClusteredMet/WW1l1nu2q_J_up.root WW1L1Nu2Q VVJ 0 ClusteredMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_ClusteredMet/ZZ4l_J_up.root ZZ4L VVJ 0 ClusteredMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_ClusteredMet/ZZ2l2q_J_up.root ZZ2L2Q VVJ 0 ClusteredMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_ClusteredMet/VV2l2nu_J_up.root VV2L2Nu VVJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_ClusteredMet/Tbar-tW_J_up.root ST_tW_antitop VVJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_ClusteredMet/T-tW_J_up.root ST_tW_top VVJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_ClusteredMet/Tbar-tchan_J_up.root ST_t_antitop VVJ 0 ClusteredMet_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_ClusteredMet/T-tchan_J_up.root ST_t_top VVJ 0 ClusteredMet_UP
 hadd -f outputs_ClusteredMet/VVJ_up.root outputs_ClusteredMet/WZ1l1nu2q_J_up.root outputs_ClusteredMet/WZ1l3nu_J_up.root outputs_ClusteredMet/WZ1l1nu2q_J_up.root outputs_ClusteredMet/WZ3l1nu_J_up.root outputs_ClusteredMet/WZ2l2q_J_up.root outputs_ClusteredMet/WW1l1nu2q_J_up.root outputs_ClusteredMet/ZZ4l_J_up.root outputs_ClusteredMet/ZZ2l2q_J_up.root outputs_ClusteredMet/VV2l2nu_J_up.root outputs_ClusteredMet/Tbar-tW_J_up.root outputs_ClusteredMet/T-tW_J_up.root outputs_ClusteredMet/Tbar-tchan_J_up.root outputs_ClusteredMet/T-tchan_J_up.root 



 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_ClusteredMet/VBF125_down.root VBF125 VBF125 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_ClusteredMet/ggH125_down.root ggH125 ggH125 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_ClusteredMet/WplusH125_down.root WplusH125 WH125 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_ClusteredMet/WminusH125_down.root WminusH125 WH125 0 ClusteredMet_DOWN
 hadd -f outputs_ClusteredMet/WH125_down.root outputs_ClusteredMet/WplusH125_down.root outputs_ClusteredMet/WminusH125_down.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_ClusteredMet/ZH125_down.root ZH125 ZH125 0 ClusteredMet_DOWN
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_ClusteredMet/ZTT0_down.root DY ZTT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_ClusteredMet/ZTT1_down.root DY ZTT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_ClusteredMet/ZTT2_down.root DY ZTT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_ClusteredMet/ZTT3_down.root DY ZTT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_ClusteredMet/ZTT4_down.root DY ZTT 0 ClusteredMet_DOWN
 hadd -f outputs_ClusteredMet/ZTT_down.root outputs_ClusteredMet/ZTT0_down.root outputs_ClusteredMet/ZTT1_down.root outputs_ClusteredMet/ZTT2_down.root outputs_ClusteredMet/ZTT3_down.root outputs_ClusteredMet/ZTT4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_ClusteredMet/ZL0_down.root DY ZL 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_ClusteredMet/ZL1_down.root DY ZL 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_ClusteredMet/ZL2_down.root DY ZL 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_ClusteredMet/ZL3_down.root DY ZL 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_ClusteredMet/ZL4_down.root DY  ZL 0 ClusteredMet_DOWN
 hadd -f outputs_ClusteredMet/ZL_down.root outputs_ClusteredMet/ZL0_down.root outputs_ClusteredMet/ZL1_down.root outputs_ClusteredMet/ZL2_down.root outputs_ClusteredMet/ZL3_down.root outputs_ClusteredMet/ZL4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_ClusteredMet/ZJ0_down.root DY ZJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_ClusteredMet/ZJ1_down.root DY ZJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_ClusteredMet/ZJ2_down.root DY ZJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_ClusteredMet/ZJ3_down.root DY ZJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_ClusteredMet/ZJ4_down.root DY ZJ 0 ClusteredMet_DOWN
 hadd -f outputs_ClusteredMet/ZJ_down.root outputs_ClusteredMet/ZJ0_down.root outputs_ClusteredMet/ZJ1_down.root outputs_ClusteredMet/ZJ2_down.root outputs_ClusteredMet/ZJ3_down.root outputs_ClusteredMet/ZJ4_down.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_ClusteredMet/EWKZ2l_down.root EWKZLL EWKZ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_ClusteredMet/EWKZ2nu_down.root EWKZNuNu EWKZ 0 ClusteredMet_DOWN
 hadd -f outputs_ClusteredMet/EWKZ_down.root outputs_ClusteredMet/EWKZ2l_down.root outputs_ClusteredMet/EWKZ2nu_down.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_ClusteredMet/TTT_down.root TT TTT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_ClusteredMet/TTJ_down.root TT TTJ 0 ClusteredMet_DOWN
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_ClusteredMet/W0_down.root W W 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_ClusteredMet/W1_down.root W W 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_ClusteredMet/W2_down.root W W 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_ClusteredMet/W3_down.root W W 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_ClusteredMet/W4_down.root W W 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_ClusteredMet/EWKWMinus_down.root EWKWminus W 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_ClusteredMet/EWKWPlus_down.root EWKWplus W 0 ClusteredMet_DOWN
 hadd -f outputs_ClusteredMet/W_down.root outputs_ClusteredMet/W0_down.root outputs_ClusteredMet/W1_down.root outputs_ClusteredMet/W2_down.root outputs_ClusteredMet/W3_down.root outputs_ClusteredMet/W4_down.root outputs_ClusteredMet/EWKWMinus_down.root outputs_ClusteredMet/EWKWPlus_down.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_ClusteredMet/WZ1l1nu2q_T_down.root WZ1L1Nu2Q VVT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_ClusteredMet/WZ1l3nu_T_down.root WZ1L3Nu VVT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_ClusteredMet/WZ3l1nu_T_down.root WZLLLNu VVT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_ClusteredMet/WZ2l2q_T_down.root WZ2L2Q VVT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_ClusteredMet/WW1l1nu2q_T_down.root WW1L1Nu2Q VVT 0 ClusteredMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_ClusteredMet/ZZ4l_T_down.root ZZ4L VVT 0 ClusteredMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_ClusteredMet/ZZ2l2q_T_down.root ZZ2L2Q VVT 0 ClusteredMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_ClusteredMet/VV2l2nu_T_down.root VV2L2Nu VVT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_ClusteredMet/Tbar-tW_T_down.root ST_tW_antitop VVT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_ClusteredMet/T-tW_T_down.root ST_tW_top VVT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_ClusteredMet/Tbar-tchan_T_down.root ST_t_antitop VVT 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_ClusteredMet/T-tchan_T_down.root ST_t_top VVT 0 ClusteredMet_DOWN
 hadd -f outputs_ClusteredMet/VVT_down.root outputs_ClusteredMet/WZ1l1nu2q_T_down.root outputs_ClusteredMet/WZ1l3nu_T_down.root outputs_ClusteredMet/WZ1l1nu2q_T_down.root outputs_ClusteredMet/WZ3l1nu_T_down.root outputs_ClusteredMet/WZ2l2q_T_down.root outputs_ClusteredMet/WW1l1nu2q_T_down.root outputs_ClusteredMet/ZZ4l_T_down.root outputs_ClusteredMet/ZZ2l2q_T_down.root outputs_ClusteredMet/VV2l2nu_T_down.root outputs_ClusteredMet/Tbar-tW_T_down.root outputs_ClusteredMet/T-tW_T_down.root outputs_ClusteredMet/Tbar-tchan_T_down.root outputs_ClusteredMet/T-tchan_T_down.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_ClusteredMet/WZ1l1nu2q_J_down.root WZ1L1Nu2Q VVJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_ClusteredMet/WZ1l3nu_J_down.root WZ1L3Nu VVJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_ClusteredMet/WZ3l1nu_J_down.root WZLLLNu VVJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_ClusteredMet/WZ2l2q_J_down.root WZ2L2Q VVJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_ClusteredMet/WW1l1nu2q_J_down.root WW1L1Nu2Q VVJ 0 ClusteredMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_ClusteredMet/ZZ4l_J_down.root ZZ4L VVJ 0 ClusteredMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_ClusteredMet/ZZ2l2q_J_down.root ZZ2L2Q VVJ 0 ClusteredMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_ClusteredMet/VV2l2nu_J_down.root VV2L2Nu VVJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_ClusteredMet/Tbar-tW_J_down.root ST_tW_antitop VVJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_ClusteredMet/T-tW_J_down.root ST_tW_top VVJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_ClusteredMet/Tbar-tchan_J_down.root ST_t_antitop VVJ 0 ClusteredMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_ClusteredMet/T-tchan_J_down.root ST_t_top VVJ 0 ClusteredMet_DOWN
 hadd -f outputs_ClusteredMet/VVJ_down.root outputs_ClusteredMet/WZ1l1nu2q_J_down.root outputs_ClusteredMet/WZ1l3nu_J_down.root outputs_ClusteredMet/WZ1l1nu2q_J_down.root outputs_ClusteredMet/WZ3l1nu_J_down.root outputs_ClusteredMet/WZ2l2q_J_down.root outputs_ClusteredMet/WW1l1nu2q_J_down.root outputs_ClusteredMet/ZZ4l_J_down.root outputs_ClusteredMet/ZZ2l2q_J_down.root outputs_ClusteredMet/VV2l2nu_J_down.root outputs_ClusteredMet/Tbar-tW_J_down.root outputs_ClusteredMet/T-tW_J_down.root outputs_ClusteredMet/Tbar-tchan_J_down.root outputs_ClusteredMet/T-tchan_J_down.root 

 hadd -f final_ClusteredMet.root outputs_ClusteredMet/ZTT_down.root outputs_ClusteredMet/ZJ_down.root outputs_ClusteredMet/ZL_down.root outputs_ClusteredMet/TTT_down.root outputs_ClusteredMet/TTJ_down.root outputs_ClusteredMet/VVT_down.root outputs_ClusteredMet/VVJ_down.root outputs_ClusteredMet/W_down.root outputs_ClusteredMet/EWKZ_down.root outputs_ClusteredMet/VBF125_down.root outputs_ClusteredMet/ggH125_down.root outputs_ClusteredMet/WH125_down.root outputs_ClusteredMet/ZH125_down.root outputs_ClusteredMet/ZTT_up.root outputs_ClusteredMet/ZJ_up.root outputs_ClusteredMet/ZL_up.root outputs_ClusteredMet/TTT_up.root outputs_ClusteredMet/TTJ_up.root outputs_ClusteredMet/VVT_up.root outputs_ClusteredMet/VVJ_up.root outputs_ClusteredMet/W_up.root outputs_ClusteredMet/EWKZ_up.root outputs_ClusteredMet/VBF125_up.root outputs_ClusteredMet/ggH125_up.root outputs_ClusteredMet/WH125_up.root outputs_ClusteredMet/ZH125_up.root 


''' UnclusteredMET '''
rm outputs_UncMet/*

 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_UncMet/VBF125_up.root VBF125 VBF125 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_UncMet/ggH125_up.root ggH125 ggH125 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_UncMet/WplusH125_up.root WplusH125 WH125 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_UncMet/WminusH125_up.root WminusH125 WH125 0 UncMet_UP
 hadd -f outputs_UncMet/WH125_up.root outputs_UncMet/WplusH125_up.root outputs_UncMet/WminusH125_up.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_UncMet/ZH125_up.root ZH125 ZH125 0 UncMet_UP
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_UncMet/ZTT0_up.root DY ZTT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_UncMet/ZTT1_up.root DY ZTT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_UncMet/ZTT2_up.root DY ZTT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_UncMet/ZTT3_up.root DY ZTT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_UncMet/ZTT4_up.root DY ZTT 0 UncMet_UP
 hadd -f outputs_UncMet/ZTT_up.root outputs_UncMet/ZTT0_up.root outputs_UncMet/ZTT1_up.root outputs_UncMet/ZTT2_up.root outputs_UncMet/ZTT3_up.root outputs_UncMet/ZTT4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_UncMet/ZL0_up.root DY ZL 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_UncMet/ZL1_up.root DY ZL 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_UncMet/ZL2_up.root DY ZL 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_UncMet/ZL3_up.root DY ZL 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_UncMet/ZL4_up.root DY  ZL 0 UncMet_UP
 hadd -f outputs_UncMet/ZL_up.root outputs_UncMet/ZL0_up.root outputs_UncMet/ZL1_up.root outputs_UncMet/ZL2_up.root outputs_UncMet/ZL3_up.root outputs_UncMet/ZL4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_UncMet/ZJ0_up.root DY ZJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_UncMet/ZJ1_up.root DY ZJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_UncMet/ZJ2_up.root DY ZJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_UncMet/ZJ3_up.root DY ZJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_UncMet/ZJ4_up.root DY ZJ 0 UncMet_UP
 hadd -f outputs_UncMet/ZJ_up.root outputs_UncMet/ZJ0_up.root outputs_UncMet/ZJ1_up.root outputs_UncMet/ZJ2_up.root outputs_UncMet/ZJ3_up.root outputs_UncMet/ZJ4_up.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_UncMet/EWKZ2l_up.root EWKZLL EWKZ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_UncMet/EWKZ2nu_up.root EWKZNuNu EWKZ 0 UncMet_UP
 hadd -f outputs_UncMet/EWKZ_up.root outputs_UncMet/EWKZ2l_up.root outputs_UncMet/EWKZ2nu_up.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_UncMet/TTT_up.root TT TTT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_UncMet/TTJ_up.root TT TTJ 0 UncMet_UP
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_UncMet/W0_up.root W W 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_UncMet/W1_up.root W W 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_UncMet/W2_up.root W W 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_UncMet/W3_up.root W W 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_UncMet/W4_up.root W W 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_UncMet/EWKWMinus_up.root EWKWminus W 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_UncMet/EWKWPlus_up.root EWKWplus W 0 UncMet_UP
 hadd -f outputs_UncMet/W_up.root outputs_UncMet/W0_up.root outputs_UncMet/W1_up.root outputs_UncMet/W2_up.root outputs_UncMet/W3_up.root outputs_UncMet/W4_up.root outputs_UncMet/EWKWMinus_up.root outputs_UncMet/EWKWPlus_up.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_UncMet/WZ1l1nu2q_T_up.root WZ1L1Nu2Q VVT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_UncMet/WZ1l3nu_T_up.root WZ1L3Nu VVT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_UncMet/WZ3l1nu_T_up.root WZLLLNu VVT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_UncMet/WZ2l2q_T_up.root WZ2L2Q VVT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_UncMet/WW1l1nu2q_T_up.root WW1L1Nu2Q VVT 0 UncMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_UncMet/ZZ4l_T_up.root ZZ4L VVT 0 UncMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_UncMet/ZZ2l2q_T_up.root ZZ2L2Q VVT 0 UncMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_UncMet/VV2l2nu_T_up.root VV2L2Nu VVT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_UncMet/Tbar-tW_T_up.root ST_tW_antitop VVT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_UncMet/T-tW_T_up.root ST_tW_top VVT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_UncMet/Tbar-tchan_T_up.root ST_t_antitop VVT 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_UncMet/T-tchan_T_up.root ST_t_top VVT 0 UncMet_UP
 hadd -f outputs_UncMet/VVT_up.root outputs_UncMet/WZ1l1nu2q_T_up.root outputs_UncMet/WZ1l3nu_T_up.root outputs_UncMet/WZ1l1nu2q_T_up.root outputs_UncMet/WZ3l1nu_T_up.root outputs_UncMet/WZ2l2q_T_up.root outputs_UncMet/WW1l1nu2q_T_up.root outputs_UncMet/ZZ4l_T_up.root outputs_UncMet/ZZ2l2q_T_up.root outputs_UncMet/VV2l2nu_T_up.root outputs_UncMet/Tbar-tW_T_up.root outputs_UncMet/T-tW_T_up.root outputs_UncMet/Tbar-tchan_T_up.root outputs_UncMet/T-tchan_T_up.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_UncMet/WZ1l1nu2q_J_up.root WZ1L1Nu2Q VVJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_UncMet/WZ1l3nu_J_up.root WZ1L3Nu VVJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_UncMet/WZ3l1nu_J_up.root WZLLLNu VVJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_UncMet/WZ2l2q_J_up.root WZ2L2Q VVJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_UncMet/WW1l1nu2q_J_up.root WW1L1Nu2Q VVJ 0 UncMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_UncMet/ZZ4l_J_up.root ZZ4L VVJ 0 UncMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_UncMet/ZZ2l2q_J_up.root ZZ2L2Q VVJ 0 UncMet_UP 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_UncMet/VV2l2nu_J_up.root VV2L2Nu VVJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_UncMet/Tbar-tW_J_up.root ST_tW_antitop VVJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_UncMet/T-tW_J_up.root ST_tW_top VVJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_UncMet/Tbar-tchan_J_up.root ST_t_antitop VVJ 0 UncMet_UP
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_UncMet/T-tchan_J_up.root ST_t_top VVJ 0 UncMet_UP
 hadd -f outputs_UncMet/VVJ_up.root outputs_UncMet/WZ1l1nu2q_J_up.root outputs_UncMet/WZ1l3nu_J_up.root outputs_UncMet/WZ1l1nu2q_J_up.root outputs_UncMet/WZ3l1nu_J_up.root outputs_UncMet/WZ2l2q_J_up.root outputs_UncMet/WW1l1nu2q_J_up.root outputs_UncMet/ZZ4l_J_up.root outputs_UncMet/ZZ2l2q_J_up.root outputs_UncMet/VV2l2nu_J_up.root outputs_UncMet/Tbar-tW_J_up.root outputs_UncMet/T-tW_J_up.root outputs_UncMet/Tbar-tchan_J_up.root outputs_UncMet/T-tchan_J_up.root 








 # 2. Signals
 ./tt_analyzer.exe myntuples/Aug30/VBF125.root outputs_UncMet/VBF125_down.root VBF125 VBF125 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/ggH125.root outputs_UncMet/ggH125_down.root ggH125 ggH125 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WplusH125.root outputs_UncMet/WplusH125_down.root WplusH125 WH125 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WminusH125.root outputs_UncMet/WminusH125_down.root WminusH125 WH125 0 UncMet_DOWN
 hadd -f outputs_UncMet/WH125_down.root outputs_UncMet/WplusH125_down.root outputs_UncMet/WminusH125_down.root
 ./tt_analyzer.exe myntuples/Aug30/ZH125.root outputs_UncMet/ZH125_down.root ZH125 ZH125 0 UncMet_DOWN
 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_UncMet/ZTT0_down.root DY ZTT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_UncMet/ZTT1_down.root DY ZTT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_UncMet/ZTT2_down.root DY ZTT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_UncMet/ZTT3_down.root DY ZTT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_UncMet/ZTT4_down.root DY ZTT 0 UncMet_DOWN
 hadd -f outputs_UncMet/ZTT_down.root outputs_UncMet/ZTT0_down.root outputs_UncMet/ZTT1_down.root outputs_UncMet/ZTT2_down.root outputs_UncMet/ZTT3_down.root outputs_UncMet/ZTT4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_UncMet/ZL0_down.root DY ZL 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_UncMet/ZL1_down.root DY ZL 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_UncMet/ZL2_down.root DY ZL 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_UncMet/ZL3_down.root DY ZL 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_UncMet/ZL4_down.root DY  ZL 0 UncMet_DOWN
 hadd -f outputs_UncMet/ZL_down.root outputs_UncMet/ZL0_down.root outputs_UncMet/ZL1_down.root outputs_UncMet/ZL2_down.root outputs_UncMet/ZL3_down.root outputs_UncMet/ZL4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_UncMet/ZJ0_down.root DY ZJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_UncMet/ZJ1_down.root DY ZJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_UncMet/ZJ2_down.root DY ZJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_UncMet/ZJ3_down.root DY ZJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_UncMet/ZJ4_down.root DY ZJ 0 UncMet_DOWN
 hadd -f outputs_UncMet/ZJ_down.root outputs_UncMet/ZJ0_down.root outputs_UncMet/ZJ1_down.root outputs_UncMet/ZJ2_down.root outputs_UncMet/ZJ3_down.root outputs_UncMet/ZJ4_down.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_UncMet/EWKZ2l_down.root EWKZLL EWKZ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_UncMet/EWKZ2nu_down.root EWKZNuNu EWKZ 0 UncMet_DOWN
 hadd -f outputs_UncMet/EWKZ_down.root outputs_UncMet/EWKZ2l_down.root outputs_UncMet/EWKZ2nu_down.root
 # 5. TT
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_UncMet/TTT_down.root TT TTT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/TT.root outputs_UncMet/TTJ_down.root TT TTJ 0 UncMet_DOWN
 # 6. W
 ./tt_analyzer.exe myntuples/Aug30/W.root outputs_UncMet/W0_down.root W W 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W1.root outputs_UncMet/W1_down.root W W 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W2.root outputs_UncMet/W2_down.root W W 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W3.root outputs_UncMet/W3_down.root W W 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/W4.root outputs_UncMet/W4_down.root W W 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_UncMet/EWKWMinus_down.root EWKWminus W 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_UncMet/EWKWPlus_down.root EWKWplus W 0 UncMet_DOWN
 hadd -f outputs_UncMet/W_down.root outputs_UncMet/W0_down.root outputs_UncMet/W1_down.root outputs_UncMet/W2_down.root outputs_UncMet/W3_down.root outputs_UncMet/W4_down.root outputs_UncMet/EWKWMinus_down.root outputs_UncMet/EWKWPlus_down.root 
 # 7. VV
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_UncMet/WZ1l1nu2q_T_down.root WZ1L1Nu2Q VVT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_UncMet/WZ1l3nu_T_down.root WZ1L3Nu VVT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_UncMet/WZ3l1nu_T_down.root WZLLLNu VVT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_UncMet/WZ2l2q_T_down.root WZ2L2Q VVT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_UncMet/WW1l1nu2q_T_down.root WW1L1Nu2Q VVT 0 UncMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_UncMet/ZZ4l_T_down.root ZZ4L VVT 0 UncMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_UncMet/ZZ2l2q_T_down.root ZZ2L2Q VVT 0 UncMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_UncMet/VV2l2nu_T_down.root VV2L2Nu VVT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_UncMet/Tbar-tW_T_down.root ST_tW_antitop VVT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_UncMet/T-tW_T_down.root ST_tW_top VVT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_UncMet/Tbar-tchan_T_down.root ST_t_antitop VVT 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_UncMet/T-tchan_T_down.root ST_t_top VVT 0 UncMet_DOWN
 hadd -f outputs_UncMet/VVT_down.root outputs_UncMet/WZ1l1nu2q_T_down.root outputs_UncMet/WZ1l3nu_T_down.root outputs_UncMet/WZ1l1nu2q_T_down.root outputs_UncMet/WZ3l1nu_T_down.root outputs_UncMet/WZ2l2q_T_down.root outputs_UncMet/WW1l1nu2q_T_down.root outputs_UncMet/ZZ4l_T_down.root outputs_UncMet/ZZ2l2q_T_down.root outputs_UncMet/VV2l2nu_T_down.root outputs_UncMet/Tbar-tW_T_down.root outputs_UncMet/T-tW_T_down.root outputs_UncMet/Tbar-tchan_T_down.root outputs_UncMet/T-tchan_T_down.root 
 ./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_UncMet/WZ1l1nu2q_J_down.root WZ1L1Nu2Q VVJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_UncMet/WZ1l3nu_J_down.root WZ1L3Nu VVJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_UncMet/WZ3l1nu_J_down.root WZLLLNu VVJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_UncMet/WZ2l2q_J_down.root WZ2L2Q VVJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_UncMet/WW1l1nu2q_J_down.root WW1L1Nu2Q VVJ 0 UncMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_UncMet/ZZ4l_J_down.root ZZ4L VVJ 0 UncMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_UncMet/ZZ2l2q_J_down.root ZZ2L2Q VVJ 0 UncMet_DOWN 
 ./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_UncMet/VV2l2nu_J_down.root VV2L2Nu VVJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_UncMet/Tbar-tW_J_down.root ST_tW_antitop VVJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_UncMet/T-tW_J_down.root ST_tW_top VVJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_UncMet/Tbar-tchan_J_down.root ST_t_antitop VVJ 0 UncMet_DOWN
 ./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_UncMet/T-tchan_J_down.root ST_t_top VVJ 0 UncMet_DOWN
 hadd -f outputs_UncMet/VVJ_down.root outputs_UncMet/WZ1l1nu2q_J_down.root outputs_UncMet/WZ1l3nu_J_down.root outputs_UncMet/WZ1l1nu2q_J_down.root outputs_UncMet/WZ3l1nu_J_down.root outputs_UncMet/WZ2l2q_J_down.root outputs_UncMet/WW1l1nu2q_J_down.root outputs_UncMet/ZZ4l_J_down.root outputs_UncMet/ZZ2l2q_J_down.root outputs_UncMet/VV2l2nu_J_down.root outputs_UncMet/Tbar-tW_J_down.root outputs_UncMet/T-tW_J_down.root outputs_UncMet/Tbar-tchan_J_down.root outputs_UncMet/T-tchan_J_down.root 

 hadd -f final_UncMet.root outputs_UncMet/ZTT_down.root outputs_UncMet/ZJ_down.root outputs_UncMet/ZL_down.root outputs_UncMet/TTT_down.root outputs_UncMet/TTJ_down.root outputs_UncMet/VVT_down.root outputs_UncMet/VVJ_down.root outputs_UncMet/W_down.root outputs_UncMet/EWKZ_down.root outputs_UncMet/VBF125_down.root outputs_UncMet/ggH125_down.root outputs_UncMet/WH125_down.root outputs_UncMet/ZH125_down.root outputs_UncMet/ZTT_up.root outputs_UncMet/ZJ_up.root outputs_UncMet/ZL_up.root outputs_UncMet/TTT_up.root outputs_UncMet/TTJ_up.root outputs_UncMet/VVT_up.root outputs_UncMet/VVJ_up.root outputs_UncMet/W_up.root outputs_UncMet/EWKZ_up.root outputs_UncMet/VBF125_up.root outputs_UncMet/ggH125_up.root outputs_UncMet/WH125_up.root outputs_UncMet/ZH125_up.root 