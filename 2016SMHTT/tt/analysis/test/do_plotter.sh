 rm outputs_forPlots/*
 ####################
 ### Nominal runs ###
 ####################

 # 1. Data
 ./tt_templateMaker.exe outputs_nominal/data.root outputs_forPlots/data.root data_obs nominal

 # 2. Signals
 ./tt_templateMaker.exe outputs_nominal/VBF125.root outputs_forPlots/VBF125.root VBF125 nominal
 ./tt_templateMaker.exe outputs_nominal/ggH125.root outputs_forPlots/ggH125.root ggH125 nominal
 ./tt_templateMaker.exe outputs_nominal/WH125.root outputs_forPlots/WH125.root WH125 nominal
 ./tt_templateMaker.exe outputs_nominal/ZH125.root outputs_forPlots/ZH125.root ZH125 nominal

 # 3. DY
 ./tt_templateMaker.exe outputs_nominal/ZL.root outputs_forPlots/ZL.root ZL nominal
 ./tt_templateMaker.exe outputs_nominal/ZJ.root outputs_forPlots/ZJ.root ZJ nominal

 # 4. EWKZ
 ./tt_templateMaker.exe outputs_nominal/EWKZ.root outputs_forPlots/EWKZ.root EWKZ nominal

 # 5. TT
 ./tt_templateMaker.exe outputs_nominal/TTJ.root outputs_forPlots/TTJ.root TTJ nominal

 # 6. W
 ./tt_templateMaker.exe outputs_nominal/W.root outputs_forPlots/W.root W nominal

 # 7. VV
 ./tt_templateMaker.exe outputs_nominal/VVJ.root outputs_forPlots/VVJ.root VVJ nomianl

 # embedded
 ./tt_templateMaker.exe outputs_nominal/embedded.root outputs_forPlots/embedded.root embedded nominal

 python python/SignalCreator.py
 python python/QCDcreator.py

 # hadd all outputs
 hadd -f final_nominal.root outputs_forPlots/data.root outputs_forPlots/ZJ.root outputs_forPlots/ZL.root outputs_forPlots/TTJ.root outputs_forPlots/VVJ.root outputs_forPlots/W.root outputs_forPlots/EWKZ.root outputs_forPlots/VBF125.root outputs_forPlots/ggH125.root outputs_forPlots/WH125.root outputs_forPlots/ZH125.root outputs_forPlots/QCD.root outputs_forPlots/SMH.root outputs_forPlots/embedded.root

