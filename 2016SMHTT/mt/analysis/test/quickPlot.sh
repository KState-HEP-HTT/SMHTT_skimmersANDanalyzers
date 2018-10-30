#!/bin/bash                                                                                                                                                    
rm plots/Quick/*.root

export input=""
for i in `ls $1/*.root`; do
    export input="$iput $i"
    #echo $input                                                                                                                                               
    fileName="${input%.*}"
    fileName="${fileName##*/}"
    #echo $fileName                                                                                                                                 
    ./quickplot.exe $input plots/Quick/$fileName.root $fileName $2 $3 $4 $5
done

python python/QCDcreator.py -i plots/Quick/ -q
hadd -f plots/Quick/templates/$5.root plots/Quick/*.root
#python python/stackPlotter_dev.py
