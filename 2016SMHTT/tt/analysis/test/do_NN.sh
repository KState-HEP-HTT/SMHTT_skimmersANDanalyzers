 rm outputs_NN/*
 ####################
 ### Nominal runs ###
 ####################

 # 1. Data
 ./tt_analyzer_NN.exe myntuples/NNout/data_NN.root outputs_NN/data.root data_obs data_obs nominal

 # 3. DY
 ./tt_analyzer_NN.exe myntuples/NNout/ZTT_NN.root outputs_NN/ZTT.root data_obs ZTT nominal
 ./tt_analyzer_NN.exe myntuples/NNout/ZJ_NN.root outputs_NN/ZJ.root data_obs ZJ nominal
 ./tt_analyzer_NN.exe myntuples/NNout/ZL_NN.root outputs_NN/ZL.root data_obs ZL nominal

 # 4. EWKZ
 ./tt_analyzer_NN.exe myntuples/NNout/EWKZ_NN.root outputs_NN/EWKZ.root data_obs EWKZ nominal

 # 5. TT
 ./tt_analyzer_NN.exe myntuples/NNout/TTT_NN.root outputs_NN/TTT.root data_obs TTT nominal
 ./tt_analyzer_NN.exe myntuples/NNout/TTJ_NN.root outputs_NN/TTJ.root data_obs TTJ nominal
 # 6. W
 ./tt_analyzer_NN.exe myntuples/NNout/W_NN.root outputs_NN/W.root data_obs W nominal
 # 7. VV
 ./tt_analyzer_NN.exe myntuples/NNout/VVT_NN.root outputs_NN/VVT.root data_obs VVT nominal
 ./tt_analyzer_NN.exe myntuples/NNout/VVJ_NN.root outputs_NN/VVJ.root data_obs VVJ nominal

 ./tt_analyzer_NN.exe myntuples/NNout/VBF125_NN.root outputs_NN/VBF125.root data_obs VBF125 nominal


 python python/QCDcreator.py

 # hadd all outputs
 hadd -f final_nominal_NN.root outputs_NN/data.root outputs_NN/ZTT.root outputs_NN/ZJ.root outputs_NN/ZL.root outputs_NN/TTT.root outputs_NN/TTJ.root outputs_NN/VVT.root outputs_NN/VVJ.root outputs_NN/W.root outputs_NN/EWKZ.root outputs_NN/VBF125.root outputs_NN/QCD.root 

