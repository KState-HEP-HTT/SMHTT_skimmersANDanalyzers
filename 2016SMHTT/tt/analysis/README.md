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
### How to change observable
One need to modify ```tt_analyzer.cc``` to make other observable distributions. 

1. Set what you want to plots in this line.

https://github.com/dykim1/HTT/blob/feature-plot/2016SMHTT/tt/analysis/src/tt_analyzer.cc#L761

2. Choose the proper binning from here.

https://github.com/dykim1/HTT/blob/feature-plot/2016SMHTT/tt/analysis/src/tt_analyzer.cc#L223-L225

Where 0, 1, and 2 means 0jet, 1jet and 2 or more jets category. One can modify binning of each category independently. 

3. If you would like to change the definiton of category, modifiy these lines.

https://github.com/dykim1/HTT/blob/feature-plot/2016SMHTT/tt/analysis/src/tt_analyzer.cc#L738-L739

https://github.com/dykim1/HTT/blob/feature-plot/2016SMHTT/tt/analysis/src/tt_analyzer.cc#L735

