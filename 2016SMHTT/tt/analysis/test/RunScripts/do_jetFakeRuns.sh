rm outputs_jetFake/*
#######################
### jetFake runs    ###
### W, ZJ, TTJ, VVJ ###
#######################

# W
./tt_analyzer.exe myntuples/Aug30/W.root outputs_jetFake/W0_up.root W W 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/W1.root outputs_jetFake/W1_up.root W W 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/W2.root outputs_jetFake/W2_up.root W W 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/W3.root outputs_jetFake/W3_up.root W W 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/W4.root outputs_jetFake/W4_up.root W W 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_jetFake/EWKWMinus_up.root EWKWminus W 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_jetFake/EWKWPlus_up.root EWKWplus W 14 jetToTauFake_Up
hadd -f outputs_jetFake/W_up.root outputs_jetFake/W0_up.root outputs_jetFake/W1_up.root outputs_jetFake/W2_up.root outputs_jetFake/W3_up.root outputs_jetFake/W4_up.root outputs_jetFake/EWKWMinus_up.root outputs_jetFake/EWKWPlus_up.root 
# ZJ
./tt_analyzer.exe myntuples/Aug30/DY.root outputs_jetFake/ZJ0_up.root DY ZJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_jetFake/ZJ1_up.root DY ZJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_jetFake/ZJ2_up.root DY ZJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_jetFake/ZJ3_up.root DY ZJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_jetFake/ZJ4_up.root DY ZJ 14 jetToTauFake_Up
hadd -f outputs_jetFake/ZJ_up.root outputs_jetFake/ZJ0_up.root outputs_jetFake/ZJ1_up.root outputs_jetFake/ZJ2_up.root outputs_jetFake/ZJ3_up.root outputs_jetFake/ZJ4_up.root
# TTJ
./tt_analyzer.exe myntuples/Aug30/TT.root outputs_jetFake/TTJ_up.root TT TTJ 14 jetToTauFake_Up
# VVJ
./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_jetFake/WZ1l1nu2q_J_up.root WZ1L1Nu2Q VVJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_jetFake/WZ1l3nu_J_up.root WZ1L3Nu VVJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_jetFake/WZ3l1nu_J_up.root WZLLLNu VVJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_jetFake/WZ2l2q_J_up.root WZ2L2Q VVJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_jetFake/WW1l1nu2q_J_up.root WW1L1Nu2Q VVJ 14 jetToTauFake_Up 
./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_jetFake/ZZ4l_J_up.root ZZ4L VVJ 14 jetToTauFake_Up 
./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_jetFake/ZZ2l2q_J_up.root ZZ2L2Q VVJ 14 jetToTauFake_Up 
./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_jetFake/VV2l2nu_J_up.root VV2L2Nu VVJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_jetFake/Tbar-tW_J_up.root ST_tW_antitop VVJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_jetFake/T-tW_J_up.root ST_tW_top VVJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_jetFake/Tbar-tchan_J_up.root ST_t_antitop VVJ 14 jetToTauFake_Up
./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_jetFake/T-tchan_J_up.root ST_t_top VVJ 14 jetToTauFake_Up
hadd -f outputs_jetFake/VVJ_up.root outputs_jetFake/WZ1l1nu2q_J_up.root outputs_jetFake/WZ1l3nu_J_up.root outputs_jetFake/WZ1l1nu2q_J_up.root outputs_jetFake/WZ3l1nu_J_up.root outputs_jetFake/WZ2l2q_J_up.root outputs_jetFake/WW1l1nu2q_J_up.root outputs_jetFake/ZZ4l_J_up.root outputs_jetFake/ZZ2l2q_J_up.root outputs_jetFake/VV2l2nu_J_up.root outputs_jetFake/Tbar-tW_J_up.root outputs_jetFake/T-tW_J_up.root outputs_jetFake/Tbar-tchan_J_up.root outputs_jetFake/T-tchan_J_up.root 


# W
./tt_analyzer.exe myntuples/Aug30/W.root outputs_jetFake/W0_down.root W W -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/W1.root outputs_jetFake/W1_down.root W W -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/W2.root outputs_jetFake/W2_down.root W W -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/W3.root outputs_jetFake/W3_down.root W W -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/W4.root outputs_jetFake/W4_down.root W W -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/EWKWMinus.root outputs_jetFake/EWKWMinus_down.root EWKWminus W -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/EWKWPlus.root outputs_jetFake/EWKWPlus_down.root EWKWplus W -14 jetToTauFake_Down
hadd -f outputs_jetFake/W_down.root outputs_jetFake/W0_down.root outputs_jetFake/W1_down.root outputs_jetFake/W2_down.root outputs_jetFake/W3_down.root outputs_jetFake/W4_down.root outputs_jetFake/EWKWMinus_down.root outputs_jetFake/EWKWPlus_down.root 
# ZJ
./tt_analyzer.exe myntuples/Aug30/DY.root outputs_jetFake/ZJ0_down.root DY ZJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_jetFake/ZJ1_down.root DY ZJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_jetFake/ZJ2_down.root DY ZJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_jetFake/ZJ3_down.root DY ZJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_jetFake/ZJ4_down.root DY ZJ -14 jetToTauFake_Down
hadd -f outputs_jetFake/ZJ_down.root outputs_jetFake/ZJ0_down.root outputs_jetFake/ZJ1_down.root outputs_jetFake/ZJ2_down.root outputs_jetFake/ZJ3_down.root outputs_jetFake/ZJ4_down.root
# TTJ
./tt_analyzer.exe myntuples/Aug30/TT.root outputs_jetFake/TTJ_down.root TT TTJ -14 jetToTauFake_Down
# VVJ
./tt_analyzer.exe myntuples/Aug30/WZ1l1nu2q.root outputs_jetFake/WZ1l1nu2q_J_down.root WZ1L1Nu2Q VVJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/WZ1l3nu.root outputs_jetFake/WZ1l3nu_J_down.root WZ1L3Nu VVJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/WZ3l1nu.root outputs_jetFake/WZ3l1nu_J_down.root WZLLLNu VVJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/WZ2l2q.root outputs_jetFake/WZ2l2q_J_down.root WZ2L2Q VVJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/WW1l1nu2q.root outputs_jetFake/WW1l1nu2q_J_down.root WW1L1Nu2Q VVJ -14 jetToTauFake_Down 
./tt_analyzer.exe myntuples/Aug30/ZZ4l.root outputs_jetFake/ZZ4l_J_down.root ZZ4L VVJ -14 jetToTauFake_Down 
./tt_analyzer.exe myntuples/Aug30/ZZ2l2q.root outputs_jetFake/ZZ2l2q_J_down.root ZZ2L2Q VVJ -14 jetToTauFake_Down 
./tt_analyzer.exe myntuples/Aug30/VV2l2nu.root outputs_jetFake/VV2l2nu_J_down.root VV2L2Nu VVJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/Tbar-tW.root outputs_jetFake/Tbar-tW_J_down.root ST_tW_antitop VVJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/T-tW.root outputs_jetFake/T-tW_J_down.root ST_tW_top VVJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/Tbar-tchan.root outputs_jetFake/Tbar-tchan_J_down.root ST_t_antitop VVJ -14 jetToTauFake_Down
./tt_analyzer.exe myntuples/Aug30/T-tchan.root outputs_jetFake/T-tchan_J_down.root ST_t_top VVJ -14 jetToTauFake_Down
hadd -f outputs_jetFake/VVJ_down.root outputs_jetFake/WZ1l1nu2q_J_down.root outputs_jetFake/WZ1l3nu_J_down.root outputs_jetFake/WZ1l1nu2q_J_down.root outputs_jetFake/WZ3l1nu_J_down.root outputs_jetFake/WZ2l2q_J_down.root outputs_jetFake/WW1l1nu2q_J_down.root outputs_jetFake/ZZ4l_J_down.root outputs_jetFake/ZZ2l2q_J_down.root outputs_jetFake/VV2l2nu_J_down.root outputs_jetFake/Tbar-tW_J_down.root outputs_jetFake/T-tW_J_down.root outputs_jetFake/Tbar-tchan_J_down.root outputs_jetFake/T-tchan_J_down.root 




# hadd
hadd -f final_jetFake.root outputs_jetFake/W_down.root outputs_jetFake/ZJ_down.root outputs_jetFake/TTJ_down.root outputs_jetFake/VVJ_down.root outputs_jetFake/W_up.root outputs_jetFake/ZJ_up.root outputs_jetFake/TTJ_up.root outputs_jetFake/VVJ_up.root