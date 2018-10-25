#!/bin/bash                                                                                                                                                    
rm plots/Quick/*

export input=""
for i in `ls files_nominal/*.root`; do
    export input="$iput $i"
    #echo $input                                                                                                                                               
    fileName="${input%.*}"
    fileName="${fileName##*/}"
    #echo $fileName                                                                                                                                 
    ./quickplot.exe $input plots/Quick/$fileName.root $fileName $1 $2 $3 $4
done

python python/QCDcreator.py -i plots/Quick/ -q
hadd -f final_nominal.root plots/Quick/*
python python/stackPlotter_dev.py
