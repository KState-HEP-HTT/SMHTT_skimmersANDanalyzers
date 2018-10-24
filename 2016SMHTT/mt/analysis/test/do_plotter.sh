#!/bin/sh 

 rm outputs_forPlots/*
 ####################
 ### Nominal runs ###
 ####################

 # 1. Data
 ./mt_templateMaker.exe ${1}/Data.root outputs_forPlots/data.root data_obs nominal

 # 2. Signals
 ./mt_templateMaker.exe ${1}/VBF125.root outputs_forPlots/VBF125.root VBF125 nominal
 ./mt_templateMaker.exe ${1}/ggH125.root outputs_forPlots/ggH125.root ggH125 nominal
 ./mt_templateMaker.exe ${1}/WH125.root outputs_forPlots/WH125.root WH125 nominal
 ./mt_templateMaker.exe ${1}/ZH125.root outputs_forPlots/ZH125.root ZH125 nominal

 # 3. DY
 ./mt_templateMaker.exe ${1}/ZL.root outputs_forPlots/ZL.root ZL nominal
 ./mt_templateMaker.exe ${1}/ZJ.root outputs_forPlots/ZJ.root ZJ nominal

 # 4. EWKZ
 ./mt_templateMaker.exe ${1}/EWKZ.root outputs_forPlots/EWKZ.root EWKZ nominal

 # 5. TT
 ./mt_templateMaker.exe ${1}/TTT.root outputs_forPlots/TTT.root TTT nominal
 ./mt_templateMaker.exe ${1}/TTJ.root outputs_forPlots/TTJ.root TTJ nominal

 # 6. W
 ./mt_templateMaker.exe ${1}/W.root outputs_forPlots/W.root W nominal

 # 7. VV
 ./mt_templateMaker.exe ${1}/VV.root outputs_forPlots/VV.root VV nomianl

 # Embedded or MC (default(no 2nd input) is embedded)
 if [ -z ${2} ]; then
      ./mt_templateMaker.exe ${1}/embedded.root outputs_forPlots/embedded.root embedded nominal
      python python/SignalCreator.py
      python python/QCDcreator.py
      hadd -f final_nominal.root outputs_forPlots/data.root outputs_forPlots/ZJ.root outputs_forPlots/ZL.root outputs_forPlots/TTT.root outputs_forPlots/TTJ.root outputs_forPlots/VV.root outputs_forPlots/W.root outputs_forPlots/EWKZ.root outputs_forPlots/VBF125.root outputs_forPlots/ggH125.root outputs_forPlots/WH125.root outputs_forPlots/ZH125.root outputs_forPlots/QCD.root outputs_forPlots/embedded.root

 elif [ ${2} = "mc" ]; then
     ./mt_templateMaker.exe ${1}/ZTT.root outputs_forPlots/ZTT.root ZTT nominal
     python python/QCDcreator.py -z
     hadd -f final_nominal.root outputs_forPlots/data.root outputs_forPlots/ZTT.root outputs_forPlots/ZJ.root outputs_forPlots/ZL.root outputs_forPlots/TTT.root outputs_forPlots/TTJ.root outputs_forPlots/VV.root outputs_forPlots/W.root outputs_forPlots/EWKZ.root outputs_forPlots/VBF125.root outputs_forPlots/ggH125.root outputs_forPlots/WH125.root outputs_forPlots/ZH125.root outputs_forPlots/QCD.root 

 #else
 #    echo "Usage : source do_plotter.sh inputfolder (mc or empty for embedded)"
 #    exit
 fi
 
