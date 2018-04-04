./Make.sh FinalSelection2D_relaxedFR.cc

./FinalSelection2D_relaxedFR.exe myntuples/data_B.root files_nominal/data_B.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/data_C.root files_nominal/data_C.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/data_D.root files_nominal/data_D.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/data_E.root files_nominal/data_E.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/data_F.root files_nominal/data_F.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/data_G.root files_nominal/data_G.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/data_H_v2.root files_nominal/data_H_v2.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/data_H_v3.root files_nominal/data_H_v3.root data_obs data_obs 0
hadd -f files_nominal/data.root files_nominal/data_B.root files_nominal/data_C.root files_nominal/data_D.root files_nominal/data_E.root files_nominal/data_F.root files_nominal/data_G.root files_nominal/data_H_v2.root files_nominal/data_H_v3.root

#./FinalSelection2D_relaxedFR.exe myntuples/ggH125.root files_nominal/SMH.root ggH125 SMH 0
./FinalSelection2D_relaxedFR.exe myntuples/VBF125.root files_nominal/VBF125.root VBF125 VBF125 0
./FinalSelection2D_relaxedFR.exe myntuples/ggH125.root files_nominal/ggH125.root ggH125 ggH125 0
python Creat_sig.py 

./FinalSelection2D_relaxedFR.exe myntuples/DYM50.root files_nominal/DY0.root DY DY 0
./FinalSelection2D_relaxedFR.exe myntuples/DY1.root files_nominal/DY1.root DY DY 0
./FinalSelection2D_relaxedFR.exe myntuples/DY2.root files_nominal/DY2.root DY DY 0
./FinalSelection2D_relaxedFR.exe myntuples/DY3.root files_nominal/DY3.root DY DY 0
./FinalSelection2D_relaxedFR.exe myntuples/DY4.root files_nominal/DY4.root DY DY 0
#./FinalSelection2D_relaxedFR.exe myntuples/DY10to50.root files_nominal/DY10to50.root DY DY 0
hadd -f files_nominal/DY.root files_nominal/DY0.root files_nominal/DY1.root files_nominal/DY2.root files_nominal/DY3.root files_nominal/DY4.root #files_nominal/DY10to50.root
./FinalSelection2D_relaxedFR.exe myntuples/TT.root files_nominal/TT.root TT TT 0
./FinalSelection2D_relaxedFR.exe myntuples/VV.root files_nominal/VV.root VV2L2Nu VV 0
./FinalSelection2D_relaxedFR.exe myntuples/WJets.root files_nominal/WJets.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W1Jets.root files_nominal/W1Jets.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W2Jets.root files_nominal/W2Jets.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W3Jets.root files_nominal/W3Jets.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W4Jets.root files_nominal/W4Jets.root W W 0
hadd -f files_nominal/W.root files_nominal/WJets.root files_nominal/W1Jets.root files_nominal/W2Jets.root files_nominal/W3Jets.root files_nominal/W4Jets.root

python Creat_QCD.py

hadd -f final_nominal.root files_nominal/SMH.root files_nominal/DY.root files_nominal/TT.root files_nominal/VV.root files_nominal/data.root files_nominal/W.root files_nominal/QCD.root

python plot_tt.py

