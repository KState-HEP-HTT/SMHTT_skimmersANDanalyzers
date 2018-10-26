#!/bin/sh 

 rm output/mt/*
 ####################
 ### Nominal runs ###
 ####################
if [ -z ${1} ]; then
    input_dir='FREEZE_TREES/cat_vbf_mjj300_njets2_taupt40'
else
    input_dir=${1}
fi

echo $input_dir

 # 1. Data
 ./mt_templateMaker.exe $input_dir/Data.root output/mt/data.root data_obs nominal

 # 2. Signals
 ./mt_templateMaker.exe $input_dir/VBF125.root output/mt/VBF125.root VBF125 nominal
 ./mt_templateMaker.exe $input_dir/ggH125.root output/mt/ggH125.root ggH125 nominal
 ./mt_templateMaker.exe $input_dir/WH125.root output/mt/WH125.root WH125 nominal
 ./mt_templateMaker.exe $input_dir/ZH125.root output/mt/ZH125.root ZH125 nominal

 # 3. DY
 ./mt_templateMaker.exe $input_dir/ZL.root output/mt/ZL.root ZL nominal
 ./mt_templateMaker.exe $input_dir/ZJ.root output/mt/ZJ.root ZJ nominal

 # 4. EWKZ
 ./mt_templateMaker.exe $input_dir/EWKZ.root output/mt/EWKZ.root EWKZ nominal

 # 5. TT
 ./mt_templateMaker.exe $input_dir/TTT.root output/mt/TTT.root TTT nominal
 ./mt_templateMaker.exe $input_dir/TTJ.root output/mt/TTJ.root TTJ nominal

 # 6. W
 ./mt_templateMaker.exe $input_dir/W.root output/mt/W.root W nominal

 # 7. VV
 ./mt_templateMaker.exe $input_dir/VV.root output/mt/VV.root VV nomianl

 # Embedded or MC (default(no 2nd input) is embedded)
 if [ -z ${2} ]; then
      ./mt_templateMaker.exe $input_dir/embedded.root output/mt/embedded.root embedded nominal
      python python/SignalCreator.py
      python python/QCDcreator_mt.py 
      hadd -f final_nominal.root output/mt/data.root output/mt/ZJ.root output/mt/ZL.root output/mt/TTT.root output/mt/TTJ.root output/mt/VV.root output/mt/W.root output/mt/EWKZ.root output/mt/VBF125.root output/mt/ggH125.root output/mt/WH125.root output/mt/ZH125.root output/mt/QCD.root output/mt/embedded.root

 elif [ ${2} = "mc" ]; then
     ./mt_templateMaker.exe $input_dir/ZTT.root output/mt/ZTT.root ZTT nominal
     python python/QCDcreator_mt.py -z
     hadd -f final_nominal.root output/mt/data.root output/mt/ZTT.root output/mt/ZJ.root output/mt/ZL.root output/mt/TTT.root output/mt/TTJ.root output/mt/VV.root output/mt/W.root output/mt/EWKZ.root output/mt/VBF125.root output/mt/ggH125.root output/mt/WH125.root output/mt/ZH125.root output/mt/QCD.root 

 #else
 #    echo "Usage : source do_plotter.sh inputfolder (mc or empty for embedded)"
 #    exit
 fi
 
