# Higgs to tau, tau 2016 skimming and analysis codes

## Instruction :
### 1. Skimming
---
To compile the code:
``` ./Make.sh skim_tt.cc```

The syntax to run over FSA ntuples is: 
``` ./skim_tt.exe mc (or data) out.root in.root ```


### 2. Comparision
---
To cmpare ntuples:
```python compare.py ntuple1.root ntuple2.root ... -t ntuple1, ntuple2, ntuple3, ... ```

For instance, 
```python compare.py FSA_mt.root VIE_mt.root IC_mt.root KIE_mt.root -t FSA,VIE,IC,KIT```

Official 2017-sync repository is https://github.com/CMS-HTT/2017-sync.
All code in Comparision directory are from the official repository.