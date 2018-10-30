#!/bin/bash                                                                                                                                                    

#######################################################################################################
##                                                                                                   ##         
##  Usage: source quickplot.sh < input dir > < number of bins > < min > < max > < var > < channel >  ##
##    ex)  source quickPlot.sh FREEZE_TREES/mt_sync_NN 70 300 1000 mjj mt                            ##
##                                                                                                   ##         
#######################################################################################################

rm plots/Quick/*.root

export input=""
for i in `ls $1/*.root`; do
    export input="$iput $i"
    #echo $input                                                                                                                                               
    fileName="${input%.*}"
    fileName="${fileName##*/}"
    #echo $fileName                                                                                                                                 
    ./$6_quickplot.exe $input plots/Quick/$fileName.root $fileName $2 $3 $4 $5
done

python python/QCDcreator_$6.py -i plots/Quick/ -q
hadd -f plots/Quick/templates/$5.root plots/Quick/*.root
python python/stackPlotter_dev.py -i plots/Quick/templates/$5.root -v $5 -c $6

printf "\nCopy and paste the following to make ZTT MC plot.\n" 
echo python python/QCDcreator_$6.py -i plots/Quick/ -q -z
echo python python/stackPlotter_dev.py -i plots/Quick/templates/$5.root -v $5 -c $6 -z
echo
