 rm outputs_NN/*
 ####################
 ### Nominal runs ###
 ####################

 # 1. Data
 ./et_analyzer_NN.exe myntuples/NNout/Data_NN.root outputs_NN/data.root data_obs data_obs nominal

 # 3. DY
 ./et_analyzer_NN.exe myntuples/NNout/ZTT_NN.root outputs_NN/ZTT.root data_obs ZTT nominal
 ./et_analyzer_NN.exe myntuples/NNout/ZJ_NN.root outputs_NN/ZJ.root data_obs ZJ nominal
 ./et_analyzer_NN.exe myntuples/NNout/ZL_NN.root outputs_NN/ZL.root data_obs ZL nominal

 # 4. EWKZ
 ./et_analyzer_NN.exe myntuples/NNout/EWKZ_NN.root outputs_NN/EWKZ.root data_obs EWKZ nominal

 # 5. TT
 ./et_analyzer_NN.exe myntuples/NNout/TTT_NN.root outputs_NN/TTT.root data_obs TTT nominal
 ./et_analyzer_NN.exe myntuples/NNout/TTJ_NN.root outputs_NN/TTJ.root data_obs TTJ nominal
 # 6. W
 ./et_analyzer_NN.exe myntuples/NNout/W_NN.root outputs_NN/W.root data_obs W nominal
 # 7. VV
 ./et_analyzer_NN.exe myntuples/NNout/VV_NN.root outputs_NN/VV.root data_obs VV nominal


 ./et_analyzer_NN.exe myntuples/NNout/VBF125_NN.root outputs_NN/VBF125.root data_obs VBF125 nominal


 #python python/QCDcreator.py

 # hadd all outputs
 hadd -f final_nominal_NN.root outputs_NN/data.root outputs_NN/ZTT.root outputs_NN/ZJ.root outputs_NN/ZL.root outputs_NN/TTT.root outputs_NN/TTJ.root outputs_NN/VV.root outputs_NN/W.root outputs_NN/EWKZ.root outputs_NN/VBF125.root 

 python python/plotRocCurve.py

#outputs_NN/QCD.root 

