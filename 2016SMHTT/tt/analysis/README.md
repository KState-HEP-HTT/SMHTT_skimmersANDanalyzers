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
./Make.sh tt_templateMaker.cc
```

To run the analyzer and make the distribution plots,

1. Embedded sample,

```
cd ../test
source do_plotter.sh
python python/stackPlotter_dev.py
```
2. MC samples,

```
cd ../test
source do_plotterMC.sh 
python python/stackPlotter_dev.py -z
```

---
### How to make changes for R&D
One mainly need to change three things. 1) binning, 2) variables, and 3) category. 
Where ingredients for each category are the following.

* 0jet 
  - binning : bins0[]
  - variable : var_0jet
  - category : is_0jet 

* boosted
  - binning : bins1X[], bins1Y[]
  - variable : var_boostedX, var_boostedY
  - category : is_boosted

* 0jet 
  - binning : bins2X[], bins2Y[]
  - variable : var_vbfX, var_vbfY
  - category : is_VBF




