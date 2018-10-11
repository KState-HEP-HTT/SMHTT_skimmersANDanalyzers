#!/bin/sh
if [ ! $1 ] ; then
    echo "Please specify the code you want to compile by typing :"
    echo "./Make <Your-Code.C>"
    exit 1
fi
echo "================================================================"
#echo "====> Producing eventdict.cc and eventdict.h"
#rootcint -f eventdict.cc -c interface/myevent.h interface/LinkDef.h 
#echo "====> Compiling $1 linked with eventdict.cc"
filename=`echo $1 | awk -F"." '{print $1}'`
exefilename=../test/${filename}.exe
rm -f $exefilename

#g++ $1 -o $exefilename `root-config --cflags --glibs` -lRooFit -lRooFitCore -framework Python
#g++ $1 -o $exefilename `root-config --cflags --glibs` -lRooFit -lRooFitCore -std=c++14 -lpython2.6 `python2.6-config --includes`
#g++ $1 -o $exefilename `root-config --cflags --glibs` -lRooFit -lRooFitCore -std=c++14 -L/cvmfs/cms.cern.ch/slc6_amd64_gcc530/cms/cmssw/CMSSW_8_1_0/external/slc6_amd64_gcc530/lib -lpython2.7 `python2.7-config --includes`
g++ $1 -o $exefilename `root-config --cflags --glibs` -lRooFit -lRooFitCore -std=c++14 -lpython2.7 `python2.7-config --includes`

echo ""
if [ -e $exefilename ]; then 
    echo "====> Created exe file : "
    ls -lrt $exefilename
    echo "====> Done."
else
    echo "====> Did not create the exe file!"
fi
echo "================================================================"
	
