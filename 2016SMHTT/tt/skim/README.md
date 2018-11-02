# Higgs to tau, tau 2016 skimming and analysis codes

## Instruction :
### 1. Skimming
---
To compile the code:
``` ./Make.sh skim_tt.cc```

The syntax to run over FSA ntuples is: 

``` 
./skim_tt.exe <mc/data/embedded> <output> <input> <recoil> <17/16>
./skim_tt.exe data test.root /hdfs/store/user/tmitchel/submit_DATA_tau/data_Tau_Run2017B-17Nov2017/make_ntuples_cfg-90E1AB1D-C4DA-E711-9E42-0242AC130002.root 0 17
```

#### Legacy 

To make the list of commands to run over all samples:
```python makedo_all_tt.py > skimming.sh ```

makedo_all_tt.py prints commands for skimming all tt-channel samples. 


Then, ```source skimming.sh ```

