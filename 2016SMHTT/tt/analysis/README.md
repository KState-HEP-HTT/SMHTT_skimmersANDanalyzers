# 2016 Higgs to Tau-Tau Analysis Code

## Instruction :
One can run this analyzer from local machine as well as Wisconsin machine. 

Checkout the repository.
```
git clone git@github.com:KState-HEP-HTT/SMHTT_skimmersANDanalyzers.git
```

To compile,
```
cd SMHTT_skimmersANDanalyzers/2016SMHTT/tt/analysis/src
./Make.sh tt_quickplot.cc 
./Make.sh mt_quickplot.cc 
```

To run the analyzer and make the distribution plots,

```
cd ../test
source quickPlot.sh FREEZE_TREES/tt_sync_NN 20 0 1 MELA tt
```

This will give you the plots with embedded sample + two lines that enable you to make the same plots usint MC ZTT.


