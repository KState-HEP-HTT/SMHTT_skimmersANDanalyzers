# Plotting distribution

## Instruction :
Checkout the repository and change branch for plot.
```
git clone git@github.com:KState-HEP-HTT/SMHTT_skimmersANDanalyzers.git
cd SMHTT_skimmersANDanalyzers
```

One need to copy input ntuples into this place.

```2016SMHTT/tt/analysis/test/myntuples/Sep03_fixQ/```

Ntuples are here : 

from the Wisconsin machine(@login.wisc.hep.edu) 
```/hdfs/store/user/doyeong/SMHTT_CONDOR/tautau/myskims/Sep03_fixQ/```

(The location of the lastest ntupels are always here: https://github.com/KState-HEP-HTT/infoSheet/wiki/TauTau-Information)

To compile analyzer,
```
cd 2016SMHTT/tt/analysis/src
./Make.sh tt_analyzer.cc
```

To run the analyzer and make the distribution plots,
```
cd ../test
source do_nominalRuns.sh
```

---
### How to make changes for R&D

I always keep uncommenting out everything such that one can reproduce 2016SMHTT official analysis. 
One need to modify ```tt_analyzer.cc``` for our R&D. 
I cpied lines from one of old commit which won't change as time goes, but one can find the same part(not the same line!!) from the current version of tt_analyzer.cc.

1. How to change binning? Search 'bins0[]' in the ```tt_analyzer.cc```. Something like this. 

https://github.com/KState-HEP-HTT/SMHTT_skimmersANDanalyzers/blob/cc73e960087c634f9420e65ae907f0305056fe7e/2016SMHTT/tt/analysis/src/tt_analyzer.cc#L291-L313

2. How to change variables? Search 'var_0jet'.

https://github.com/KState-HEP-HTT/SMHTT_skimmersANDanalyzers/blob/cc73e960087c634f9420e65ae907f0305056fe7e/2016SMHTT/tt/analysis/src/tt_analyzer.cc#L788-L792

3. How to change definition of category? Search 'is_VBF' 

There are 2016 analysis category and right below them one can find 'KSU study category'. Make sure that one set of them need to be commented out.

https://github.com/KState-HEP-HTT/SMHTT_skimmersANDanalyzers/blob/master/2016SMHTT/tt/analysis/src/tt_analyzer.cc#L716-L734



Where ingredients for each category are the following.

* 0jet 
  - binning : bins0[], bins1[] 
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




