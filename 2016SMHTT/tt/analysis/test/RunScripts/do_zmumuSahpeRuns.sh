 rm outputs_zmumuShape/*
 #######################
 ### zmumuShape runs ###
 #######################

 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_zmumuShape/ZTT0_up.root DY ZTT 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_zmumuShape/ZTT1_up.root DY ZTT 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_zmumuShape/ZTT2_up.root DY ZTT 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_zmumuShape/ZTT3_up.root DY ZTT 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_zmumuShape/ZTT4_up.root DY ZTT 13 zmumuShape_Up
 hadd -f outputs_zmumuShape/ZTT_up.root outputs_zmumuShape/ZTT0_up.root outputs_zmumuShape/ZTT1_up.root outputs_zmumuShape/ZTT2_up.root outputs_zmumuShape/ZTT3_up.root outputs_zmumuShape/ZTT4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_zmumuShape/ZL0_up.root DY ZL 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_zmumuShape/ZL1_up.root DY ZL 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_zmumuShape/ZL2_up.root DY ZL 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_zmumuShape/ZL3_up.root DY ZL 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_zmumuShape/ZL4_up.root DY  ZL 13 zmumuShape_Up
 hadd -f outputs_zmumuShape/ZL_up.root outputs_zmumuShape/ZL0_up.root outputs_zmumuShape/ZL1_up.root outputs_zmumuShape/ZL2_up.root outputs_zmumuShape/ZL3_up.root outputs_zmumuShape/ZL4_up.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_zmumuShape/ZJ0_up.root DY ZJ 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_zmumuShape/ZJ1_up.root DY ZJ 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_zmumuShape/ZJ2_up.root DY ZJ 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_zmumuShape/ZJ3_up.root DY ZJ 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_zmumuShape/ZJ4_up.root DY ZJ 13 zmumuShape_Up
 hadd -f outputs_zmumuShape/ZJ_up.root outputs_zmumuShape/ZJ0_up.root outputs_zmumuShape/ZJ1_up.root outputs_zmumuShape/ZJ2_up.root outputs_zmumuShape/ZJ3_up.root outputs_zmumuShape/ZJ4_up.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_zmumuShape/EWKZ2l_up.root EWKZLL EWKZ 13 zmumuShape_Up
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_zmumuShape/EWKZ2nu_up.root EWKZNuNu EWKZ 13 zmumuShape_Up
 hadd -f outputs_zmumuShape/EWKZ_up.root outputs_zmumuShape/EWKZ2l_up.root outputs_zmumuShape/EWKZ2nu_up.root


 # 3. DY
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_zmumuShape/ZTT0_down.root DY ZTT -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_zmumuShape/ZTT1_down.root DY ZTT -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_zmumuShape/ZTT2_down.root DY ZTT -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_zmumuShape/ZTT3_down.root DY ZTT -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_zmumuShape/ZTT4_down.root DY ZTT -13 zmumuShape_Down
 hadd -f outputs_zmumuShape/ZTT_down.root outputs_zmumuShape/ZTT0_down.root outputs_zmumuShape/ZTT1_down.root outputs_zmumuShape/ZTT2_down.root outputs_zmumuShape/ZTT3_down.root outputs_zmumuShape/ZTT4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_zmumuShape/ZL0_down.root DY ZL -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_zmumuShape/ZL1_down.root DY ZL -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_zmumuShape/ZL2_down.root DY ZL -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_zmumuShape/ZL3_down.root DY ZL -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_zmumuShape/ZL4_down.root DY  ZL -13 zmumuShape_Down
 hadd -f outputs_zmumuShape/ZL_down.root outputs_zmumuShape/ZL0_down.root outputs_zmumuShape/ZL1_down.root outputs_zmumuShape/ZL2_down.root outputs_zmumuShape/ZL3_down.root outputs_zmumuShape/ZL4_down.root
 ./tt_analyzer.exe myntuples/Aug30/DY.root outputs_zmumuShape/ZJ0_down.root DY ZJ -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY1.root outputs_zmumuShape/ZJ1_down.root DY ZJ -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY2.root outputs_zmumuShape/ZJ2_down.root DY ZJ -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY3.root outputs_zmumuShape/ZJ3_down.root DY ZJ -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/DY4.root outputs_zmumuShape/ZJ4_down.root DY ZJ -13 zmumuShape_Down
 hadd -f outputs_zmumuShape/ZJ_down.root outputs_zmumuShape/ZJ0_down.root outputs_zmumuShape/ZJ1_down.root outputs_zmumuShape/ZJ2_down.root outputs_zmumuShape/ZJ3_down.root outputs_zmumuShape/ZJ4_down.root
 # 4. EWKZ
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2l.root outputs_zmumuShape/EWKZ2l_down.root EWKZLL EWKZ -13 zmumuShape_Down
 ./tt_analyzer.exe myntuples/Aug30/EWKZ2nu.root outputs_zmumuShape/EWKZ2nu_down.root EWKZNuNu EWKZ -13 zmumuShape_Down
 hadd -f outputs_zmumuShape/EWKZ_down.root outputs_zmumuShape/EWKZ2l_down.root outputs_zmumuShape/EWKZ2nu_down.root


# hadd
hadd -f final_zmumuShape.root outputs_zmumuShape/ZTT_down.root outputs_zmumuShape/ZL_down.root outputs_zmumuShape/ZJ_down.root outputs_zmumuShape/EWKZ_down.root outputs_zmumuShape/ZTT_up.root outputs_zmumuShape/ZL_up.root outputs_zmumuShape/ZJ_up.root outputs_zmumuShape/EWKZ_up.root

