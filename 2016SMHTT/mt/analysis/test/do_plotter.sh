rm outputs_template/*

# Data
./mt_templateMaker.exe files_nominal/Data.root outputs_template/Data.root data_obs nominal

# DY
./mt_templateMaker.exe files_nominal/ZTT.root outputs_template/ZTT.root ZTT nominal
./mt_templateMaker.exe files_nominal/ZL.root outputs_template/ZL.root ZL nominal
./mt_templateMaker.exe files_nominal/ZJ.root outputs_template/ZJ.root ZJ nominal

#EWKZ
./mt_templateMaker.exe files_nominal/EWKZ.root outputs_template/EWKZ.root EWKZ nominal

# TT
./mt_templateMaker.exe files_nominal/TTT.root outputs_template/TTT.root TTT nominal
./mt_templateMaker.exe files_nominal/TTJ.root outputs_template/TTJ.root TTJ nominal

# WJets
./mt_templateMaker.exe files_nominal/W.root outputs_template/W.root W nominal

# VV
./mt_templateMaker.exe files_nominal/VV.root outputs_template/VV.root VV nominal

# signal
./mt_templateMaker.exe files_nominal/VBF125.root outputs_template/VBF125.root VBF125 nominal
./mt_templateMaker.exe files_nominal/ggH125.root outputs_template/ggH125.root ggH125 nominal
./mt_templateMaker.exe files_nominal/WH125.root outputs_template/WH125.root WH125 nominal
./mt_templateMaker.exe files_nominal/ZH125.root outputs_template/ZH125.root ZH125 nominal

#python python/Scale_W_HighMT.py --scale nominal --anti iso  
#python python/Create_QCD_2Drelaxed.py --scale nominal
python python/QCDcreator.py -i outputs_template


hadd -f final_nominal.root outputs_template/data.root outputs_template/ZTT.root outputs_template/ZL.root outputs_template/ZJ.root outputs_template/TTT.root outputs_template/TTJ.root outputs_template/W.root outputs_template/VV.root outputs_template/VBF125.root outputs_template/ggH125.root outputs_template/WH125.root outputs_template/ZH125.root outputs_template/QCD.root

