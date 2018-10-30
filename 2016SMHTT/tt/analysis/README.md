# 2016 Higgs to Tau-Tau Analysis Code

## Instruction of quick plotter :
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


One need to recompile the code to change VBF category definition.

https://github.com/KState-HEP-HTT/SMHTT_skimmersANDanalyzers/blob/b140f715b4dbf47959b2f15eabdaf23c0efda54d/2016SMHTT/tt/analysis/src/mt_quickplot.cc#L134

Abailable branches are here and one can added whatever.

https://github.com/KState-HEP-HTT/SMHTT_skimmersANDanalyzers/blob/master/2016SMHTT/tt/analysis/test/python/stackPlotter_dev.py#L37-L60

