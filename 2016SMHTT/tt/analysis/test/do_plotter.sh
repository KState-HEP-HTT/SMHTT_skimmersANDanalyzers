#!/bin/sh 

 rm outputs_forPlots/*
 ####################
 ### Nominal runs ###
 ####################

 # 1. Data
 ./tt_templateMaker.exe ${1}/data.root outputs_forPlots/data.root data_obs nominal

 # 2. Signals
 ./tt_templateMaker.exe ${1}/VBF125.root outputs_forPlots/VBF125.root VBF125 nominal
 ./tt_templateMaker.exe ${1}/ggH125.root outputs_forPlots/ggH125.root ggH125 nominal
 ./tt_templateMaker.exe ${1}/WH125.root outputs_forPlots/WH125.root WH125 nominal
 ./tt_templateMaker.exe ${1}/ZH125.root outputs_forPlots/ZH125.root ZH125 nominal

 # 3. DY
 ./tt_templateMaker.exe ${1}/ZL.root outputs_forPlots/ZL.root ZL nominal
 ./tt_templateMaker.exe ${1}/ZJ.root outputs_forPlots/ZJ.root ZJ nominal

 # 4. EWKZ
 ./tt_templateMaker.exe ${1}/EWKZ.root outputs_forPlots/EWKZ.root EWKZ nominal

 # 5. TT
 ./tt_templateMaker.exe ${1}/TTJ.root outputs_forPlots/TTT.root TTT nominal
 ./tt_templateMaker.exe ${1}/TTJ.root outputs_forPlots/TTJ.root TTJ nominal

 # 6. W
 ./tt_templateMaker.exe ${1}/W.root outputs_forPlots/W.root W nominal

 # 7. VV
 ./tt_templateMaker.exe ${1}/VVT.root outputs_forPlots/VVT.root VVT nomianl
 ./tt_templateMaker.exe ${1}/VVJ.root outputs_forPlots/VVJ.root VVJ nomianl

 # Embedded or MC (default(no 2nd input) is embedded)
 if [ -z ${2} ]; then
      ./tt_templateMaker.exe ${1}/embedded.root outputs_forPlots/embedded.root embedded nominal
      python python/SignalCreator.py
      python python/QCDcreator.py
      hadd -f final_nominal.root outputs_forPlots/data.root outputs_forPlots/ZJ.root outputs_forPlots/ZL.root outputs_forPlots/TTJ.root outputs_forPlots/VVJ.root outputs_forPlots/W.root outputs_forPlots/EWKZ.root outputs_forPlots/VBF125.root outputs_forPlots/ggH125.root outputs_forPlots/WH125.root outputs_forPlots/ZH125.root outputs_forPlots/QCD.root outputs_forPlots/SMH.root outputs_forPlots/embedded.root

 elif [ ${2} = "mc" ]; then
     ./tt_templateMaker.exe ${1}/ZTT.root outputs_forPlots/ZTT.root ZTT nominal
     python python/QCDcreator.py -z
     hadd -f final_nominal.root outputs_forPlots/data.root outputs_forPlots/ZTT.root outputs_forPlots/ZJ.root outputs_forPlots/ZL.root outputs_forPlots/TTT.root outputs_forPlots/TTJ.root outputs_forPlots/VVT.root outputs_forPlots/VVJ.root outputs_forPlots/W.root outputs_forPlots/EWKZ.root outputs_forPlots/VBF125.root outputs_forPlots/ggH125.root outputs_forPlots/WH125.root outputs_forPlots/ZH125.root outputs_forPlots/QCD.root 

 #else
 #    echo "Usage : source do_plotter.sh inputfolder (mc or empty for embedded)"
 #    exit
 fi
 
