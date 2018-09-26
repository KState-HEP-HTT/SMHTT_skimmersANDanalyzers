./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_JESup/ZTTall.root ZTT ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_JESup/ZLall.root ZL ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_JESup/ZJall.root ZJ ZJ 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_JESup/ZTT1.root ZTT ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_JESup/ZL1.root ZL ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_JESup/ZJ1.root ZJ ZJ 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_JESup/ZTT2.root ZTT ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_JESup/ZL2.root ZL ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_JESup/ZJ2.root ZJ ZJ 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_JESup/ZTT3.root ZTT ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_JESup/ZL3.root ZL ZL 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_JESup/ZJ3.root ZJ ZJ 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_JESup/ZTT4.root ZTT ZTT 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_JESup/ZL4.root ZL ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_JESup/ZJ4.root ZJ ZJ 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZNuNu.root files_JESup/EWKZNuNu.root EWKZNuNu EWKZ 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZLL.root files_JESup/EWKZLL.root EWKZLL EWKZ 100
hadd -f files_JESup/ZTT.root files_JESup/ZTTall.root files_JESup/ZTT1.root files_JESup/ZTT2.root files_JESup/ZTT3.root files_JESup/ZTT4.root files_JESup/EWKZLL.root files_JESup/EWKZNuNu.root
hadd -f files_JESup/ZJ.root files_JESup/ZJall.root files_JESup/ZJ1.root files_JESup/ZJ2.root files_JESup/ZJ3.root files_JESup/ZJ4.root
hadd -f files_JESup/ZL.root files_JESup/ZLall.root files_JESup/ZL1.root files_JESup/ZL2.root files_JESup/ZL3.root files_JESup/ZL4.root
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_JESup/TTJ.root TTJ TTJ 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_JESup/TTT.root TTT TTT 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W.root files_JESup/Wincl.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W1.root files_JESup/W1.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W2.root files_JESup/W2.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W3.root files_JESup/W3.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W4.root files_JESup/W4.root W W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWminus.root files_JESup/EWKWminus.root EWKWminus W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWplus.root files_JESup/EWKWplus.root EWKWplus W 100
hadd -f files_JESup/Wunscaled.root files_JESup/W4.root files_JESup/W3.root files_JESup/W2.root files_JESup/W1.root files_JESup/Wincl.root files_JESup/EWKWminus.root files_JESup/EWKWplus.root 
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg125.root files_JESup/ggH125.root ggH125 ggH125 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF125.root files_JESup/VBF125.root VBF125 qqH125 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg120.root files_JESup/ggH120.root ggH120 ggH120 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF120.root files_JESup/VBF120.root VBF120 qqH120 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg130.root files_JESup/ggH130.root ggH130 ggH130 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF130.root files_JESup/VBF130.root VBF130 qqH130 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg110.root files_JESup/ggH110.root ggH110 ggH110 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF110.root files_JESup/VBF110.root VBF110 qqH110 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg140.root files_JESup/ggH140.root ggH140 ggH140 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF140.root files_JESup/VBF140.root VBF140 qqH140 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH120.root files_JESup/WplusH120.root WplusH120 WH120 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH120.root files_JESup/WminusH120.root WminusH120 WH120 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH120.root files_JESup/ZH120.root ZH120 ZH120 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH125.root files_JESup/WplusH125.root WplusH125 WH125 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH125.root files_JESup/WminusH125.root WminusH125 WH125 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH125.root files_JESup/ZH125.root ZH125 ZH125 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH130.root files_JESup/WplusH130.root WplusH130 WH130 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH130.root files_JESup/WminusH130.root WminusH130 WH130 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH130.root files_JESup/ZH130.root ZH130 ZH130 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH140.root files_JESup/WplusH140.root WplusH140 WH140 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH140.root files_JESup/WminusH140.root WminusH140 WH140 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH140.root files_JESup/ZH140.root ZH140 ZH140 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH110.root files_JESup/WplusH110.root WplusH110 WH110 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH110.root files_JESup/WminusH110.root WminusH110 WH110 100
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH110.root files_JESup/ZH110.root ZH110 ZH110 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/HWW_gg125.root files_JESup/ggH_WW125.root ggH_WW125 ggH_hww125 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/HWW_vbf125.root files_JESup/VBF_WW125.root VBF_WW125 qqH_hww125 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WW1L1Nu2Q.root files_JESup/WW1L1Nu2Q.root WW1L1Nu2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/VV2L2Nu.root files_JESup/VV2L2Nu.root VV2L2Nu VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZLLLNu.root files_JESup/WZLLLNu.root WZLLLNu VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZZ2L2Q.root files_JESup/ZZ2L2Q.root ZZ2L2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZZ4L.root files_JESup/ZZ4L.root ZZ4L VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ2L2Q.root files_JESup/WZ2L2Q.root WZ2L2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ1L3Nu.root files_JESup/WZ1L3Nu.root WZ1L3Nu VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ1L1Nu2Q.root files_JESup/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_t_top.root files_JESup/ST_t_top.root ST_t_top VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_t_antitop.root files_JESup/ST_t_antitop.root ST_t_antitop VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_tW_top.root files_JESup/ST_tW_top.root ST_tW_top VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_tW_antitop.root files_JESup/ST_tW_antitop.root ST_tW_antitop VV 100
hadd -f files_JESup/VV.root files_JESup/ST_t_top.root files_JESup/ST_t_antitop.root files_JESup/ST_tW_top.root files_JESup/ST_tW_antitop.root files_JESup/WW1L1Nu2Q.root files_JESup/ZZ2L2Q.root files_JESup/WZ2L2Q.root files_JESup/WZ1L3Nu.root files_JESup/WZ1L1Nu2Q.root files_JESup/VV2L2Nu.root files_JESup/WZLLLNu.root files_JESup/ZZ4L.root

python Scale_W_HighMT.py --scale allJES --anti iso
python Create_QCD_2Drelaxed.py --scale allJES
#hadd -f final_JESup.root files_JESup/W.root files_JESup/ZJ.root files_JESup/ZL.root files_JESup/ZTT.root files_JESup/TTJ.root files_JESup/TTT.root files_JESup/QCD.root files_JESup/VV.root files_JESup/ggH125.root files_JESup/VBF125.root files_JESup/WminusH125.root files_JESup/WplusH125.root files_JESup/ZH125.root files_JESup/ggH120.root files_JESup/VBF120.root files_JESup/ggH130.root files_JESup/VBF130.root files_JESup/WminusH120.root  files_JESup/WminusH130.root files_JESup/WplusH120.root files_JESup/WplusH130.root files_JESup/ZH120.root files_JESup/ZH130.root files_JESup/ggH_WW125.root files_JESup/VBF_WW125.root files_JESup/ggH110.root files_JESup/VBF110.root files_JESup/WminusH110.root files_JESup/WplusH110.root files_JESup/ZH110.root files_JESup/ggH140.root files_JESup/VBF140.root files_JESup/WminusH140.root files_JESup/WplusH140.root files_JESup/ZH140.root
hadd -f final_JESup.root files_JESup/W.root files_JESup/ZJ.root files_JESup/ZL.root files_JESup/ZTT.root files_JESup/TTJ.root files_JESup/TTT.root files_JESup/QCD.root files_JESup/VV.root files_JESup/ggH_WW125.root files_JESup/VBF_WW125.root
