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

./FinalSelection2D_relaxedFR.exe myntuples/DY_ext1.root files_nominal/ZTT_ext1.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/DY_ext2.root files_nominal/ZTT_ext2.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/DY1.root files_nominal/ZTT1.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/DY2.root files_nominal/ZTT2.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/DY3.root files_nominal/ZTT3.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/DY4.root files_nominal/ZTT4.root ZTT ZTT 0
hadd -f files_nominal/ZTT.root files_nominal/ZTT_ext1.root files_nominal/ZTT_ext2.root files_nominal/ZTT1.root files_nominal/ZTT2.root files_nominal/ZTT3.root files_nominal/ZTT4.root 

./FinalSelection2D_relaxedFR.exe myntuples/DY_ext1.root files_nominal/ZL_ext1.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/DY_ext2.root files_nominal/ZL_ext2.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/DY1.root files_nominal/ZL1.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/DY2.root files_nominal/ZL2.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/DY3.root files_nominal/ZL3.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/DY4.root files_nominal/ZL4.root ZL ZL 0
hadd -f files_nominal/ZL.root files_nominal/ZL_ext1.root files_nominal/ZL_ext2.root files_nominal/ZL1.root files_nominal/ZL2.root files_nominal/ZL3.root files_nominal/ZL4.root 

./FinalSelection2D_relaxedFR.exe myntuples/DY_ext1.root files_nominal/ZJ_ext1.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/DY_ext2.root files_nominal/ZJ_ext2.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/DY1.root files_nominal/ZJ1.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/DY2.root files_nominal/ZJ2.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/DY3.root files_nominal/ZJ3.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/DY4.root files_nominal/ZJ4.root ZJ ZJ 0
hadd -f files_nominal/ZJ.root files_nominal/ZJ_ext1.root files_nominal/ZJ_ext2.root files_nominal/ZJ1.root files_nominal/ZJ2.root files_nominal/ZJ3.root files_nominal/ZJ4.root 

./FinalSelection2D_relaxedFR.exe myntuples/TT.root files_nominal/TT.root TT TT 0
./FinalSelection2D_relaxedFR.exe myntuples/VV.root files_nominal/VV.root VV2L2Nu VV 0

./FinalSelection2D_relaxedFR.exe myntuples/W.root files_nominal/W.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W_ext2.root files_nominal/W_ext2.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W1.root files_nominal/W1.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W2.root files_nominal/W2.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W2_ext1.root files_nominal/W2_ext1.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W3.root files_nominal/W3.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W3_ext1.root files_nominal/W3_ext1.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W4.root files_nominal/W4.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W4_ext1.root files_nominal/W4_ext1.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/W4_ext2.root files_nominal/W4_ext2.root W W 0
hadd -f files_nominal/WJets.root files_nominal/W.root files_nominal/W_ext2.root files_nominal/W1.root files_nominal/W2.root files_nominal/W2_ext1.root files_nominal/W3.root files_nominal/W3_ext1.root files_nominal/W4.root files_nominal/W4_ext1.root files_nominal/W4_ext2.root

python Creat_QCD.py

hadd -f final_nominal.root files_nominal/SMH.root files_nominal/ZTT.root files_nominal/ZJ.root files_nominal/ZL.root files_nominal/TT.root files_nominal/VV.root files_nominal/data.root files_nominal/WJets.root files_nominal/QCD.root

python plot_tt.py

