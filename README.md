# Higgs to tau, tau 2016 skimming and analysis codes

## Instruction :
### 1. Skimming
---
To compile the code:
``` ./Make.sh skim_tt.cc```

The syntax to run over FSA ntuples is: 
``` ./skim_tt.exe mc (or data) out.root in.root ```

To make the list of commands to run over all samples:
```python makedo_all_tt.py > skimming.sh ```

makedo_all_tt.py prints commands for skimming all tt-channel samples. 


Then, ```source skimming.sh ```




### 2. Analysis
---

To compile the code:
``` ./Make.sh FinalSelection2D_relaxedFR.cc```

To run it over skimmed FSA ntuples:

```./FinalSelection2D_relaxedFR.exe input.root output.root sampletype sampletype recoil```

For example, 

```./FinalSelection2D_relaxedFR.exe myntuples/Jun27/data_B.root files_nominal/data_B.root data_obs data_obs 0```


``` ./FinalSelection2D_relaxedFR.exe myntuples/Jun27/VBF125.root files_nominal/VBF125.root VBF125  VBF125 0```

From Wisconsin machine one can simply execute to compile and run.
```source onerun.sh```

One can adjust binning and variable in this code changing ‘bins0[]’ and ‘var’ respectively.
