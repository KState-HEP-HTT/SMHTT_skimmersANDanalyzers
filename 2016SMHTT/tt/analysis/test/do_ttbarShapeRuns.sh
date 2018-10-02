rm outputs_ttbarShape/*
#######################
### ttbarShape runs ###
#######################
./tt_analyzer.exe myntuples/Sep03_fixQ/TT.root outputs_ttbarShape/TTT_up.root TT TTT 11 ttbarShape_Up
./tt_analyzer.exe myntuples/Sep03_fixQ/TT.root outputs_ttbarShape/TTJ_up.root TT TTJ 11 ttbarShape_Up

./tt_analyzer.exe myntuples/Sep03_fixQ/TT.root outputs_ttbarShape/TTT_down.root TT TTT 11 ttbarShape_Down
./tt_analyzer.exe myntuples/Sep03_fixQ/TT.root outputs_ttbarShape/TTJ_down.root TT TTJ 11 ttbarShape_Down

# hadd
hadd -f final_ttbarShape.root outputs_ttbarShape/TTT_down.root outputs_ttbarShape/TTJ_down.root outputs_ttbarShape/TTT_up.root outputs_ttbarShape/TTJ_up.root