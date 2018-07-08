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
To run the code, simply execute
```source onerun.sh```

Analysis code is FinalSelection2D_relaxedFR.cc.
One can adjust binning and variable in this code changing ‘bins0[]’ and ‘var’ respectively.
