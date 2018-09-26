./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_allTES/ZTTall.root ZTT ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_allTES/ZLall.root ZL ZL 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY.root files_allTES/ZJall.root ZJ ZJ 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_allTES/ZTT1.root ZTT ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_allTES/ZL1.root ZL ZL 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY1.root files_allTES/ZJ1.root ZJ ZJ 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_allTES/ZTT2.root ZTT ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_allTES/ZL2.root ZL ZL 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY2.root files_allTES/ZJ2.root ZJ ZJ 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_allTES/ZTT3.root ZTT ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_allTES/ZL3.root ZL ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY3.root files_allTES/ZJ3.root ZJ ZJ 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_allTES/ZTT4.root ZTT ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_allTES/ZL4.root ZL ZL 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/DY4.root files_allTES/ZJ4.root ZJ ZJ 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZNuNu.root files_allTES/EWKZNuNu.root EWKZNuNu EWKZ 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKZLL.root files_allTES/EWKZLL.root EWKZLL EWKZ 1
hadd -f files_allTES/ZTT.root files_allTES/ZTTall.root files_allTES/ZTT1.root files_allTES/ZTT2.root files_allTES/ZTT3.root files_allTES/ZTT4.root files_allTES/EWKZLL.root files_allTES/EWKZNuNu.root
hadd -f files_allTES/ZJ.root files_allTES/ZJall.root files_allTES/ZJ1.root files_allTES/ZJ2.root files_allTES/ZJ3.root files_allTES/ZJ4.root
hadd -f files_allTES/ZL.root files_allTES/ZLall.root files_allTES/ZL1.root files_allTES/ZL2.root files_allTES/ZL3.root files_allTES/ZL4.root
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_allTES/TTJ.root TTJ TTJ 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/TT.root files_allTES/TTT.root TTT TTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W.root files_allTES/Wincl.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W1.root files_allTES/W1.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W2.root files_allTES/W2.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W3.root files_allTES/W3.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/W4.root files_allTES/W4.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWminus.root files_allTES/EWKWminus.root EWKWminus W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/EWKWplus.root files_allTES/EWKWplus.root EWKWplus W 1
hadd -f files_allTES/Wunscaled.root files_allTES/W4.root files_allTES/W3.root files_allTES/W2.root files_allTES/W1.root files_allTES/Wincl.root files_allTES/EWKWminus.root files_allTES/EWKWplus.root
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg125.root files_allTES/ggH125.root ggH125 ggH125 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF125.root files_allTES/VBF125.root VBF125 qqH125 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg120.root files_allTES/ggH120.root ggH120 ggH120 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF120.root files_allTES/VBF120.root VBF120 qqH120 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg130.root files_allTES/ggH130.root ggH130 ggH130 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF130.root files_allTES/VBF130.root VBF130 qqH130 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg110.root files_allTES/ggH110.root ggH110 ggH110 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF110.root files_allTES/VBF110.root VBF110 qqH110 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_gg140.root files_allTES/ggH140.root ggH140 ggH140 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/SMH_VBF140.root files_allTES/VBF140.root VBF140 qqH140 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH120.root files_allTES/WplusH120.root WplusH120 WH120 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH120.root files_allTES/WminusH120.root WminusH120 WH120 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH120.root files_allTES/ZH120.root ZH120 ZH120 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH125.root files_allTES/WplusH125.root WplusH125 WH125 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH125.root files_allTES/WminusH125.root WminusH125 WH125 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH125.root files_allTES/ZH125.root ZH125 ZH125 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH130.root files_allTES/WplusH130.root WplusH130 WH130 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH130.root files_allTES/WminusH130.root WminusH130 WH130 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH130.root files_allTES/ZH130.root ZH130 ZH130 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH110.root files_allTES/WplusH110.root WplusH110 WH110 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH110.root files_allTES/WminusH110.root WminusH110 WH110 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH110.root files_allTES/ZH110.root ZH110 ZH110 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WplusH140.root files_allTES/WplusH140.root WplusH140 WH140 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WminusH140.root files_allTES/WminusH140.root WminusH140 WH140 1
#./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZH140.root files_allTES/ZH140.root ZH140 ZH140 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/HWW_gg125.root files_allTES/ggH_WW125.root ggH_WW125 ggH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/HWW_vbf125.root files_allTES/VBF_WW125.root VBF_WW125 qqH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WW1L1Nu2Q.root files_allTES/WW1L1Nu2Q.root WW1L1Nu2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/VV2L2Nu.root files_allTES/VV2L2Nu.root VV2L2Nu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZLLLNu.root files_allTES/WZLLLNu.root WZLLLNu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZZ2L2Q.root files_allTES/ZZ2L2Q.root ZZ2L2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ZZ4L.root files_allTES/ZZ4L.root ZZ4L VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ2L2Q.root files_allTES/WZ2L2Q.root WZ2L2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ1L3Nu.root files_allTES/WZ1L3Nu.root WZ1L3Nu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/WZ1L1Nu2Q.root files_allTES/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_t_top.root files_allTES/ST_t_top.root ST_t_top VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_t_antitop.root files_allTES/ST_t_antitop.root ST_t_antitop VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_tW_top.root files_allTES/ST_tW_top.root ST_tW_top VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/smhmt_20march/ST_tW_antitop.root files_allTES/ST_tW_antitop.root ST_tW_antitop VV 1
hadd -f files_allTES/VV.root files_allTES/ST_t_top.root files_allTES/ST_t_antitop.root files_allTES/ST_tW_top.root files_allTES/ST_tW_antitop.root files_allTES/WW1L1Nu2Q.root files_allTES/ZZ2L2Q.root files_allTES/WZ2L2Q.root files_allTES/WZ1L3Nu.root files_allTES/WZ1L1Nu2Q.root files_allTES/VV2L2Nu.root files_allTES/WZLLLNu.root files_allTES/ZZ4L.root

python Scale_W_HighMT.py --scale allTES --anti iso
python Create_QCD_2Drelaxed.py --scale allTES
#hadd -f final_up.root files_allTES/W.root files_allTES/ZJ.root files_allTES/ZL.root files_allTES/ZTT.root files_allTES/TTT.root files_allTES/TTJ.root files_allTES/QCD.root files_allTES/VV.root files_allTES/ggH125.root files_allTES/VBF125.root files_allTES/WminusH125.root files_allTES/WplusH125.root files_allTES/ZH125.root files_allTES/ggH120.root files_allTES/VBF120.root files_allTES/ggH130.root files_allTES/VBF130.root files_allTES/WminusH120.root files_allTES/WminusH130.root files_allTES/WplusH120.root files_allTES/WplusH130.root files_allTES/ZH120.root files_allTES/ZH130.root files_allTES/ggH_WW125.root files_allTES/VBF_WW125.root files_allTES/ggH110.root files_allTES/VBF110.root files_allTES/WminusH110.root files_allTES/WplusH110.root files_allTES/ZH110.root files_allTES/ggH140.root files_allTES/VBF140.root files_allTES/WminusH140.root files_allTES/WplusH140.root files_allTES/ZH140.root
hadd -f final_up.root files_allTES/W.root files_allTES/ZJ.root files_allTES/ZL.root files_allTES/ZTT.root files_allTES/TTT.root files_allTES/TTJ.root files_allTES/QCD.root files_allTES/VV.root files_allTES/ggH_WW125.root files_allTES/VBF_WW125.root 
