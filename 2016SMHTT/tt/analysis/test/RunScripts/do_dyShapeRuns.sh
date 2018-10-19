rm outputs_dyShape/*
####################
### dyShape runs ###
####################

 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_dyShape/ZTT0_up.root DY ZTT 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_dyShape/ZTT1_up.root DY ZTT 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_dyShape/ZTT2_up.root DY ZTT 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_dyShape/ZTT3_up.root DY ZTT 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_dyShape/ZTT4_up.root DY ZTT 10 dyShape_Up
 hadd -f outputs_dyShape/ZTT_up.root outputs_dyShape/ZTT0_up.root outputs_dyShape/ZTT1_up.root outputs_dyShape/ZTT2_up.root outputs_dyShape/ZTT3_up.root outputs_dyShape/ZTT4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_dyShape/ZL0_up.root DY ZL 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_dyShape/ZL1_up.root DY ZL 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_dyShape/ZL2_up.root DY ZL 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_dyShape/ZL3_up.root DY ZL 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_dyShape/ZL4_up.root DY  ZL 10 dyShape_Up
 hadd -f outputs_dyShape/ZL_up.root outputs_dyShape/ZL0_up.root outputs_dyShape/ZL1_up.root outputs_dyShape/ZL2_up.root outputs_dyShape/ZL3_up.root outputs_dyShape/ZL4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_dyShape/ZJ0_up.root DY ZJ 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_dyShape/ZJ1_up.root DY ZJ 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_dyShape/ZJ2_up.root DY ZJ 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_dyShape/ZJ3_up.root DY ZJ 10 dyShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_dyShape/ZJ4_up.root DY ZJ 10 dyShape_Up
 hadd -f outputs_dyShape/ZJ_up.root outputs_dyShape/ZJ0_up.root outputs_dyShape/ZJ1_up.root outputs_dyShape/ZJ2_up.root outputs_dyShape/ZJ3_up.root outputs_dyShape/ZJ4_up.root
 # 4. EWKZ
 #./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_dyShape/EWKZ2l_up.root EWKZLL EWKZ 10 dyShape_Up
 #./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_dyShape/EWKZ2nu_up.root EWKZNuNu EWKZ 10 dyShape_Up
 #hadd -f outputs_dyShape/EWKZ_up.root outputs_dyShape/EWKZ2l_up.root outputs_dyShape/EWKZ2nu_up.root


 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_dyShape/ZTT0_down.root DY ZTT -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_dyShape/ZTT1_down.root DY ZTT -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_dyShape/ZTT2_down.root DY ZTT -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_dyShape/ZTT3_down.root DY ZTT -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_dyShape/ZTT4_down.root DY ZTT -10 dyShape_Down
 hadd -f outputs_dyShape/ZTT_down.root outputs_dyShape/ZTT0_down.root outputs_dyShape/ZTT1_down.root outputs_dyShape/ZTT2_down.root outputs_dyShape/ZTT3_down.root outputs_dyShape/ZTT4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_dyShape/ZL0_down.root DY ZL -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_dyShape/ZL1_down.root DY ZL -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_dyShape/ZL2_down.root DY ZL -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_dyShape/ZL3_down.root DY ZL -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_dyShape/ZL4_down.root DY  ZL -10 dyShape_Down
 hadd -f outputs_dyShape/ZL_down.root outputs_dyShape/ZL0_down.root outputs_dyShape/ZL1_down.root outputs_dyShape/ZL2_down.root outputs_dyShape/ZL3_down.root outputs_dyShape/ZL4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_dyShape/ZJ0_down.root DY ZJ -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_dyShape/ZJ1_down.root DY ZJ -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_dyShape/ZJ2_down.root DY ZJ -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_dyShape/ZJ3_down.root DY ZJ -10 dyShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_dyShape/ZJ4_down.root DY ZJ -10 dyShape_Down
 hadd -f outputs_dyShape/ZJ_down.root outputs_dyShape/ZJ0_down.root outputs_dyShape/ZJ1_down.root outputs_dyShape/ZJ2_down.root outputs_dyShape/ZJ3_down.root outputs_dyShape/ZJ4_down.root
 # 4. EWKZ
 #./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_dyShape/EWKZ2l_down.root EWKZLL EWKZ -10 dyShape_Down
 #./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_dyShape/EWKZ2nu_down.root EWKZNuNu EWKZ -10 dyShape_Down
 #hadd -f outputs_dyShape/EWKZ_down.root outputs_dyShape/EWKZ2l_down.root outputs_dyShape/EWKZ2nu_down.root


# hadd
hadd -f final_dyShape.root outputs_dyShape/ZTT_down.root outputs_dyShape/ZL_down.root outputs_dyShape/ZJ_down.root outputs_dyShape/ZTT_up.root outputs_dyShape/ZL_up.root outputs_dyShape/ZJ_up.root 




