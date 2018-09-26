./Make.sh FinalSelection.cc
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/Data.root files_nominal/Data.root data_obs data_obs 0
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_nominal/ZTT.root ZTT ZTT 0
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_nominal/ZL.root ZL ZL 0
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_nominal/ZLL.root ZLL ZLL 0
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_nominal/ZJ.root ZJ ZJ 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_nominal/ZTTall.root ZTT ZTT 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_nominal/ZLall.root ZL ZL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_nominal/ZLLall.root ZLL ZLL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_nominal/ZJall.root ZJ ZJ 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_nominal/ZTT1.root ZTT ZTT 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_nominal/ZL1.root ZL ZL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_nominal/ZLL1.root ZLL ZLL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_nominal/ZJ1.root ZJ ZJ 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_nominal/ZTT2.root ZTT ZTT 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_nominal/ZL2.root ZL ZL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_nominal/ZLL2.root ZLL ZLL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_nominal/ZJ2.root ZJ ZJ 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_nominal/ZTT3.root ZTT ZTT 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_nominal/ZL3.root ZL ZL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_nominal/ZLL3.root ZLL ZLL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_nominal/ZJ3.root ZJ ZJ 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_nominal/ZTT4.root ZTT ZTT 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_nominal/ZL4.root ZL ZL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_nominal/ZLL4.root ZLL ZLL 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_nominal/ZJ4.root ZJ ZJ 0
hadd -f files_nominal/ZTT.root files_nominal/ZTTall.root files_nominal/ZTT1.root files_nominal/ZTT2.root files_nominal/ZTT3.root files_nominal/ZTT4.root
hadd -f files_nominal/ZLL.root files_nominal/ZLLall.root files_nominal/ZLL1.root files_nominal/ZLL2.root files_nominal/ZLL3.root files_nominal/ZLL4.root
hadd -f files_nominal/ZL.root files_nominal/ZLall.root files_nominal/ZL1.root files_nominal/ZL2.root files_nominal/ZL3.root files_nominal/ZL4.root
hadd -f files_nominal/ZJ.root files_nominal/ZJall.root files_nominal/ZJ1.root files_nominal/ZJ2.root files_nominal/ZJ3.root files_nominal/ZJ4.root
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/TT.root files_nominal/TT.root TT TT 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W.root files_nominal/Wincl.root W W 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W1.root files_nominal/W1.root W W 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W2.root files_nominal/W2.root W W 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W3.root files_nominal/W3.root W W 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W4.root files_nominal/W4.root W W 0
hadd -f files_nominal/Wunscaled.root files_nominal/W4.root files_nominal/W3.root files_nominal/W2.root files_nominal/W1.root files_nominal/Wincl.root
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg125.root files_nominal/ggH125.root ggH125 ggH125 0 
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF125.root files_nominal/VBF125.root VBF125 qqH125 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg120.root files_nominal/ggH120.root ggH120 ggH120 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF120.root files_nominal/VBF120.root VBF120 qqH120 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg130.root files_nominal/ggH130.root ggH130 ggH130 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF130.root files_nominal/VBF130.root VBF130 qqH130 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/WW.root files_nominal/WW.root WW VV 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/WZ.root files_nominal/WZ.root WZ VV 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ZZ.root files_nominal/ZZ.root ZZ VV 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_t_top.root files_nominal/ST_t_top.root ST_t_top VV 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_t_antitop.root files_nominal/ST_t_antitop.root ST_t_antitop VV 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_tW_top.root files_nominal/ST_tW_top.root ST_tW_top VV 0
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_tW_antitop.root files_nominal/ST_tW_antitop.root ST_tW_antitop VV 0
hadd -f files_nominal/VV.root files_nominal/WW.root files_nominal/WZ.root files_nominal/ZZ.root files_nominal/ST_t_top.root files_nominal/ST_tW_top.root files_nominal/ST_t_antitop.root files_nominal/ST_tW_antitop.root

#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_up/ZTT.root ZTT ZTT 1
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_up/ZL.root ZL ZL 1
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_up/ZJ.root ZJ ZJ 1
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_up/ZLL.root ZLL ZLL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_up/ZTTall.root ZTT ZTT 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_up/ZLall.root ZL ZL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_up/ZJall.root ZJ ZJ 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_up/ZLLall.root ZLL ZLL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_up/ZTT1.root ZTT ZTT 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_up/ZL1.root ZL ZL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_up/ZJ1.root ZJ ZJ 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_up/ZLL1.root ZLL ZLL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_up/ZTT2.root ZTT ZTT 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_up/ZL2.root ZL ZL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_up/ZJ2.root ZJ ZJ 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_up/ZLL2.root ZLL ZLL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_up/ZTT3.root ZTT ZTT 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_up/ZL3.root ZL ZL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_up/ZJ3.root ZJ ZJ 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_up/ZLL3.root ZLL ZLL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_up/ZTT4.root ZTT ZTT 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_up/ZL4.root ZL ZL 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_up/ZJ4.root ZJ ZJ 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_up/ZLL4.root ZLL ZLL 1
hadd -f files_up/ZTT.root files_up/ZTTall.root files_up/ZTT1.root files_up/ZTT2.root files_up/ZTT3.root files_up/ZTT4.root
hadd -f files_up/ZJ.root files_up/ZJall.root files_up/ZJ1.root files_up/ZJ2.root files_up/ZJ3.root files_up/ZJ4.root
hadd -f files_up/ZL.root files_up/ZLall.root files_up/ZL1.root files_up/ZL2.root files_up/ZL3.root files_up/ZL4.root
hadd -f files_up/ZLL.root files_up/ZLLall.root files_up/ZLL1.root files_up/ZLL2.root files_up/ZLL3.root files_up/ZLL4.root
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/TT.root files_up/TT.root TT TT 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W.root files_up/Wincl.root W W 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W1.root files_up/W1.root W W 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W2.root files_up/W2.root W W 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W3.root files_up/W3.root W W 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W4.root files_up/W4.root W W 1
hadd -f files_up/Wunscaled.root files_up/W4.root files_up/W3.root files_up/W2.root files_up/W1.root files_up/Wincl.root
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg125.root files_up/ggH125.root ggH125 ggH125 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF125.root files_up/VBF125.root VBF125 qqH125 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg125.root files_up/ggH120.root ggH120 ggH120 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF125.root files_up/VBF120.root VBF120 qqH120 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg125.root files_up/ggH130.root ggH130 ggH130 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF125.root files_up/VBF130.root VBF130 qqH130 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/WW.root files_up/WW.root WW VV 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/WZ.root files_up/WZ.root WZ VV 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ZZ.root files_up/ZZ.root ZZ VV 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_t_top.root files_up/ST_t_top.root ST_t_top VV 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_t_antitop.root files_up/ST_t_antitop.root ST_t_antitop VV 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_tW_top.root files_up/ST_tW_top.root ST_tW_top VV 1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_tW_antitop.root files_up/ST_tW_antitop.root ST_tW_antitop VV 1
hadd -f files_up/VV.root files_up/WW.root files_up/WZ.root files_up/ZZ.root files_up/ST_t_top.root files_up/ST_tW_top.root files_up/ST_t_antitop.root files_up/ST_tW_antitop.root

#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_down/ZTT.root ZTT ZTT -1
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_down/ZL.root ZL ZL -1
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_down/ZJ.root ZJ ZJ -1
#./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_down/ZLL.root ZLL ZLL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_down/ZTTall.root ZTT ZTT -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_down/ZLall.root ZL ZL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_down/ZJall.root ZJ ZJ -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY.root files_down/ZLLall.root ZLL ZLL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_down/ZTT1.root ZTT ZTT -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_down/ZL1.root ZL ZL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_down/ZJ1.root ZJ ZJ -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY1.root files_down/ZLL1.root ZLL ZLL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_down/ZTT2.root ZTT ZTT -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_down/ZL2.root ZL ZL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_down/ZJ2.root ZJ ZJ -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY2.root files_down/ZLL2.root ZLL ZLL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_down/ZTT3.root ZTT ZTT -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_down/ZL3.root ZL ZL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_down/ZJ3.root ZJ ZJ -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY3.root files_down/ZLL3.root ZLL ZLL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_down/ZTT4.root ZTT ZTT -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_down/ZL4.root ZL ZL -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_down/ZJ4.root ZJ ZJ -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/DY4.root files_down/ZLL4.root ZLL ZLL -1
hadd -f files_down/ZTT.root files_down/ZTTall.root files_down/ZTT1.root files_down/ZTT2.root files_down/ZTT3.root files_down/ZTT4.root
hadd -f files_down/ZLL.root files_down/ZLLall.root files_down/ZLL1.root files_down/ZLL2.root files_down/ZLL3.root files_down/ZLL4.root
hadd -f files_down/ZL.root files_down/ZLall.root files_down/ZL1.root files_down/ZL2.root files_down/ZL3.root files_down/ZL4.root
hadd -f files_down/ZJ.root files_down/ZJall.root files_down/ZJ1.root files_down/ZJ2.root files_down/ZJ3.root files_down/ZJ4.root
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/TT.root files_down/TT.root TT TT -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W.root files_down/Wincl.root W W -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W1.root files_down/W1.root W W -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W2.root files_down/W2.root W W -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W3.root files_down/W3.root W W -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/W4.root files_down/W4.root W W -1
hadd -f files_down/Wunscaled.root files_down/W4.root files_down/W3.root files_down/W2.root files_down/W1.root files_down/Wincl.root
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg125.root files_down/ggH125.root ggH125 ggH125 -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF125.root files_down/VBF125.root VBF125 qqH125 -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg125.root files_down/ggH120.root ggH120 ggH120 -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF125.root files_down/VBF120.root VBF120 qqH120 -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_gg125.root files_down/ggH130.root ggH130 ggH130 -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/SMH_VBF125.root files_down/VBF130.root VBF130 qqH130 -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/WW.root files_down/WW.root WW VV -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/WZ.root files_down/WZ.root WZ VV -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ZZ.root files_down/ZZ.root ZZ VV -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_t_top.root files_down/ST_t_top.root ST_t_top VV -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_t_antitop.root files_down/ST_t_antitop.root ST_t_antitop VV -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_tW_top.root files_down/ST_tW_top.root ST_tW_top VV -1
./FinalSelection.exe /data/ccaillol/ntuples_mutau_sep16_sv_2/ST_tW_antitop.root files_down/ST_tW_antitop.root ST_tW_antitop VV -1
hadd -f files_down/VV.root files_down/WW.root files_down/WZ.root files_down/ZZ.root files_down/ST_t_top.root files_down/ST_tW_top.root files_down/ST_t_antitop.root files_down/ST_tW_antitop.root 

python Scale_W.py --scale nominal --anti iso
python Scale_W.py --scale up --anti iso
python Scale_W.py --scale down --anti iso
python Create_QCD.py --scale nominal 
python Create_QCD.py --scale down
python Create_QCD.py --scale up

hadd -f final_nominal.root files_nominal/W.root files_nominal/Data.root files_nominal/ZTT.root files_nominal/ZLL.root files_nominal/ZJ.root files_nominal/ZL.root files_nominal/TT.root files_nominal/QCD.root files_nominal/VV.root files_nominal/ggH120.root files_nominal/VBF120.root files_nominal/ggH125.root files_nominal/VBF125.root files_nominal/ggH130.root files_nominal/VBF130.root
hadd -f final_down.root files_down/W.root files_down/ZTT.root files_down/ZL.root files_down/ZJ.root files_down/ZLL.root files_down/TT.root files_down/QCD.root files_down/VV.root files_up/ggH120.root files_up/VBF120.root files_up/ggH125.root files_up/VBF125.root files_up/ggH130.root files_up/VBF130.root
hadd -f final_up.root files_up/W.root files_up/ZTT.root files_up/ZLL.root files_up/ZJ.root files_up/ZL.root files_up/TT.root files_up/QCD.root files_up/VV.root files_down/ggH120.root files_down/VBF120.root files_down/ggH125.root files_down/VBF125.root files_down/ggH130.root files_down/VBF130.root
hadd -f final_mutau_cut.root final_nominal.root final_up.root final_down.root

