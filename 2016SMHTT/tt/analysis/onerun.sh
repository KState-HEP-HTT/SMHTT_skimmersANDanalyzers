./Make.sh FinalSelection2D_relaxedFR.cc

./FinalSelection2D_relaxedFR.exe myntuples/April15/data_B.root files_nominal/data_B.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/data_C.root files_nominal/data_C.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/data_D.root files_nominal/data_D.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/data_E.root files_nominal/data_E.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/data_F.root files_nominal/data_F.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/data_G.root files_nominal/data_G.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/data_H_v2.root files_nominal/data_H_v2.root data_obs data_obs 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/data_H_v3.root files_nominal/data_H_v3.root data_obs data_obs 0
hadd -f files_nominal/data.root files_nominal/data_B.root files_nominal/data_C.root files_nominal/data_D.root files_nominal/data_E.root files_nominal/data_F.root files_nominal/data_G.root files_nominal/data_H_v2.root files_nominal/data_H_v3.root

#./FinalSelection2D_relaxedFR.exe myntuples/April15/ggH125.root files_nominal/SMH.root ggH125 SMH 0
./FinalSelection2D_relaxedFR.exe myntuples/April22_svfit/VBF125.root files_nominal/VBF125.root VBF125 VBF125 0
./FinalSelection2D_relaxedFR.exe myntuples/April22_svfit/ggH125.root files_nominal/ggH125.root ggH125 ggH125 0
./FinalSelection2D_relaxedFR.exe myntuples/April22_svfit/WplusH125.root files_nominal/WplusH125.root WplusH125 WplusH125 0
./FinalSelection2D_relaxedFR.exe myntuples/April22_svfit/WminusH125.root files_nominal/WminusH125.root WminusH125 WminusH125 0
./FinalSelection2D_relaxedFR.exe myntuples/April22_svfit/ZH125.root files_nominal/ZH125.root ZH125 ZH125 0

#./FinalSelection2D_relaxedFR.exe myntuples/April15/VBF125.root files_nominal/VBF125.root VBF125 VBF125 0
#./FinalSelection2D_relaxedFR.exe myntuples/April15/ggH125.root files_nominal/ggH125.root ggH125 ggH125 0
#./FinalSelection2D_relaxedFR.exe myntuples/April15/WplusH125.root files_nominal/WplusH125.root WplusH125 WplusH125 0
#./FinalSelection2D_relaxedFR.exe myntuples/April15/WminusH125.root files_nominal/WminusH125.root WminusH125 WminusH125 0
#./FinalSelection2D_relaxedFR.exe myntuples/April15/ZH125.root files_nominal/ZH125.root ZH125 ZH125 0
python Creat_WH.py
python Creat_sig.py 


./FinalSelection2D_relaxedFR.exe myntuples/April15/DY_ext1.root files_nominal/ZTT_ext1.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY_ext2.root files_nominal/ZTT_ext2.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY1.root files_nominal/ZTT1.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY2.root files_nominal/ZTT2.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY3.root files_nominal/ZTT3.root ZTT ZTT 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY4.root files_nominal/ZTT4.root ZTT ZTT 0
hadd -f files_nominal/ZTT.root files_nominal/ZTT_ext1.root files_nominal/ZTT_ext2.root files_nominal/ZTT1.root files_nominal/ZTT2.root files_nominal/ZTT3.root files_nominal/ZTT4.root 

./FinalSelection2D_relaxedFR.exe myntuples/April15/DY_ext1.root files_nominal/ZL_ext1.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY_ext2.root files_nominal/ZL_ext2.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY1.root files_nominal/ZL1.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY2.root files_nominal/ZL2.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY3.root files_nominal/ZL3.root ZL ZL 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY4.root files_nominal/ZL4.root ZL ZL 0
hadd -f files_nominal/ZL.root files_nominal/ZL_ext1.root files_nominal/ZL_ext2.root files_nominal/ZL1.root files_nominal/ZL2.root files_nominal/ZL3.root files_nominal/ZL4.root 

./FinalSelection2D_relaxedFR.exe myntuples/April15/DY_ext1.root files_nominal/ZJ_ext1.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY_ext2.root files_nominal/ZJ_ext2.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY1.root files_nominal/ZJ1.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY2.root files_nominal/ZJ2.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY3.root files_nominal/ZJ3.root ZJ ZJ 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/DY4.root files_nominal/ZJ4.root ZJ ZJ 0
hadd -f files_nominal/ZJ.root files_nominal/ZJ_ext1.root files_nominal/ZJ_ext2.root files_nominal/ZJ1.root files_nominal/ZJ2.root files_nominal/ZJ3.root files_nominal/ZJ4.root 

./FinalSelection2D_relaxedFR.exe myntuples/April15/TT.root files_nominal/TT.root TT TT 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/VV.root files_nominal/VV.root VV2L2Nu VV 0

./FinalSelection2D_relaxedFR.exe myntuples/April15/W.root files_nominal/W.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W_ext2.root files_nominal/W_ext2.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W1.root files_nominal/W1.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W2.root files_nominal/W2.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W2_ext1.root files_nominal/W2_ext1.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W3.root files_nominal/W3.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W3_ext1.root files_nominal/W3_ext1.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W4.root files_nominal/W4.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W4_ext1.root files_nominal/W4_ext1.root W W 0
./FinalSelection2D_relaxedFR.exe myntuples/April15/W4_ext2.root files_nominal/W4_ext2.root W W 0
hadd -f files_nominal/WJets.root files_nominal/W.root files_nominal/W_ext2.root files_nominal/W1.root files_nominal/W2.root files_nominal/W2_ext1.root files_nominal/W3.root files_nominal/W3_ext1.root files_nominal/W4.root files_nominal/W4_ext1.root files_nominal/W4_ext2.root

python Creat_QCD.py

hadd -f final_nominal.root files_nominal/SMH.root files_nominal/ZTT.root files_nominal/ZJ.root files_nominal/ZL.root files_nominal/TT.root files_nominal/VV.root files_nominal/data.root files_nominal/WJets.root files_nominal/QCD.root files_nominal/VBF125.root files_nominal/ggH125.root files_nominal/WH125.root files_nominal/ZH125.root

python plot_tt_category.py

