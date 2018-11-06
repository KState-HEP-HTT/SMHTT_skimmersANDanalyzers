import os
if __name__ == "__main__":

    #place="/hdfs/store/user/ndev/LFV_reminiaod_feb18/"
    #sample=["data_SingleMuon_Run2016B_v1/","data_SingleMuon_Run2016B_v2/","data_SingleMuon_Run2016C/","data_SingleMuon_Run2016D/","data_SingleMuon_Run2016E/","data_SingleMuon_Run2016F/","data_SingleMuon_Run2016G/","data_SingleMuon_Run2016H_v1/","data_SingleMuon_Run2016H_v2/","data_SingleMuon_Run2016H_v3/"]
    #name=["DataB1","DataB2","DataC","DataD","DataE","DataF","DataG","DataH1","DataH2","DataH3"]
    #recoil=["0","0","0","0","0","0","0","0","0","0"]

    #place="/hdfs/store/user/truggles/aHTT_signals_july11_v3/"
    #place="/hdfs/store/user/truggles/aHTT_signals_aug16/"
    #name=["VBFHiggs0L1f05ph0","VBFHiggs0L1","VBFHiggs0Mf05ph0","VBFHiggs0M","VBFHiggs0PHf05ph0","VBFHiggs0PH","VBFHiggs0PM","WHiggs0L1f05ph0","WHiggs0L1","WHiggs0Mf05ph0","WHiggs0M","WHiggs0PHf05ph0","WHiggs0PH","WHiggs0PM","ZHiggs0L1f05ph0","ZHiggs0L1","ZHiggs0Mf05ph0","ZHiggs0M","ZHiggs0PHf05ph0","ZHiggs0PH","ZHiggs0PM"]
    #sample=["VBFHiggs0L1f05ph0_M-125_13TeV-JHUGenV6_v6-v1/","VBFHiggs0L1_M-125_13TeV-JHUGenV6_v6-v1/","VBFHiggs0Mf05ph0_M-125_13TeV-JHUGenV6_v6-v1/","VBFHiggs0M_M-125_13TeV-JHUGenV6_v6-v1/","VBFHiggs0PHf05ph0_M-125_13TeV-JHUGenV6_v6-v1/","VBFHiggs0PH_M-125_13TeV-JHUGenV6_v6-v1/","VBFHiggs0PM_M-125_13TeV-JHUGenV6_v6-v1/","WHiggs0L1fWH05ph0_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","WHiggs0L1_Undecayed_M-125_13TeV-JHUgenV6_v6-v1/","WHiggs0MfWH05ph0_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","WHiggs0M_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","WHiggs0PHfWH05ph0_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","WHiggs0PH_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","WHiggs0PM_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","ZHiggs0L1fZH05ph0_Undecayed_M-125_13TeV-JHUgenV6_v6-v1/","ZHiggs0L1_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","ZHiggs0MfZH05ph0_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","ZHiggs0M_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","ZHiggs0PHfZH05ph0_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","ZHiggs0PH_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/","ZHiggs0PM_Undecayed_M-125_13TeV-JHUgenV6_v6-v2/"]
    #recoil=["Z","Z","Z","Z","Z","Z","Z","0","0","0","0","0","0","0","0","0","0","0","0","0","0"]

    #place = "/hdfs/store/user/truggles/aHTT_signals_ggH_nov11/"
    #name=["GGH2Jets_maxmix","GGH2Jets_sm","GGH2Jets_pseudoscalar"]
    #sample=["GluGluH2JetsToTauTau_M125_13TeV_CPmixing_maxmix_JHU_v6-v1/","GluGluH2JetsToTauTau_M125_13TeV_CPmixing_sm_JHU_v6-v1/","GluGluH2JetsToTauTau_M125_13TeV_CPmixing_pseudoscalar_JHU_v6-v1/"]
    #recoil=["Z","Z","Z"]

    place = "/hdfs/store/user/truggles/aHTT_signals_oct29_v1/"
    name= ["VBF_pseudoscalar","VBF_scalar"]
    sample = ["PS/","S/"]
    recoil = ["0","0"]

    #place="/hdfs/store/user/ndev/LFV_feb18_mc/"
    #sample=["DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext1-v2/","DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext2-v1/","DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext2-v1/","W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext1-v1/","W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext1-v1/","W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext1-v1/","W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext2-v1/","WW_TuneCUETP8M1_13TeV-pythia8_v6-v1/","WZ_TuneCUETP8M1_13TeV-pythia8_v6-v1/","ZZ_TuneCUETP8M1_13TeV-pythia8_v6-v1/","TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_v6-v1/","ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_v6_ext1-v1/","ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_v6_ext1-v1/","ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1_v6-v1/","ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1_v6-v1/","DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","DY1JetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","DY2JetsToLL_M-10to50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/","WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/","WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_v6-v3/","WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/","VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/","VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8_v6_ext1-v1/","WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/","ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/","WZJToLLLNu_TuneCUETP8M1_13TeV-amcnlo-pythia8_v6-v1/","ZZTo4L_13TeV-amcatnloFXFX-pythia8_v6_ext1-v1/","GluGluHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/","VBFHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/","GluGluHToWWTo2L2Nu_M125_13TeV_powheg_pythia8_v6-v1/","VBFHToWWTo2L2Nu_M125_13TeV_powheg_pythia8_v6-v1/","WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_v6_ext1-v1/","WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_v6_ext2-v1/","WGstarToLNuEE_012Jets_13TeV-madgraph_v6-v1/","WGstarToLNuMuMu_012Jets_13TeV-madgraph_v6-v1/","WplusHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/","WminusHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/","ZHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/","EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6-v1/","EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6_ext1-v1/","EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6_ext2-v1/","EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6-v1/","EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6_ext1-v1/","EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6_ext2-v1/","EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8_v6-v1/","EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8_v6_ext1-v1/","EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8_v6_ext2-v1/","GluGluHToTauTau_M110_13TeV_powheg_pythia8_v6-v1/","VBFHToTauTau_M110_13TeV_powheg_pythia8_v6-v1/","WplusHToTauTau_M110_13TeV_powheg_pythia8_v6-v1/","WminusHToTauTau_M110_13TeV_powheg_pythia8_v6-v1/","ZHToTauTau_M110_13TeV_powheg_pythia8_v6-v1/","GluGluHToTauTau_M120_13TeV_powheg_pythia8_v6_ext1-v1/","VBFHToTauTau_M120_13TeV_powheg_pythia8_v6_ext1-v1/","WplusHToTauTau_M120_13TeV_powheg_pythia8_v6-v1/","WminusHToTauTau_M120_13TeV_powheg_pythia8_v6-v1/","ZHToTauTau_M120_13TeV_powheg_pythia8_v6-v1/","GluGluHToTauTau_M130_13TeV_powheg_pythia8_v6_ext1-v1/","VBFHToTauTau_M130_13TeV_powheg_pythia8_v6_ext1-v1/","WplusHToTauTau_M130_13TeV_powheg_pythia8_v6-v1/","WminusHToTauTau_M130_13TeV_powheg_pythia8_v6-v1/","ZHToTauTau_M130_13TeV_powheg_pythia8_v6-v1/","GluGluHToTauTau_M140_13TeV_powheg_pythia8_v6-v1/","VBFHToTauTau_M140_13TeV_powheg_pythia8_v6-v1/","WplusHToTauTau_M140_13TeV_powheg_pythia8_v6-v1/","WminusHToTauTau_M140_13TeV_powheg_pythia8_v6-v1/","ZHToTauTau_M140_13TeV_powheg_pythia8_v6-v1/","EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8_v6-v1/","EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8_v6_ext1-v1/","EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8_v6_ext2-v1/","ttHJetToTT_M125_13TeV_amcatnloFXFX_madspin_pythia8_v6_ext4-v1/"]

    #name=["DY","DY_v2","DY1","DY2","DY3","DY4","W","W_v2","W1","W2","W2_v2","W3","W3_v2","W4","W4_v2","W4_v3","WW","WZ","ZZ","TT","ST_tW_top","ST_tW_antitop","ST_t_top","ST_t_antitop","DYlow","DY1low","DY2low","WZ1L3Nu","WZ1L1Nu2Q","WZ2L2Q","VV2L2Nu","VV2L2Nu_v2","WW1L1Nu2Q","ZZ2L2Q","WZJLLLNu","ZZ4L","ggH125","VBF125","gghww125","vbfhww125","WGToLNuG_v1","WGToLNuG_v2","WGstarToLNuEE","WGstarToLNuMuMu","Wplus125","Wminus125","ZH125","EWKWminus_v1","EWKWminus_v2","EWKWminus_v3","EWKWplus_v1","EWKWplus_v2","EWKWplus_v3","EWKZ_v1","EWKZ_v2","EWKZ_v3","ggH110","VBF110","Wplus110","Wminus110","ZH110","ggH120","VBF120","Wplus120","Wminus120","ZH120","ggH130","VBF130","Wplus130","Wminus130","ZH130","ggH140","VBF140","Wplus140","Wminus140","ZH140","EWKZNuNu_v1","EWKZNuNu_v2","EWKZNuNu_v3","ttHToTauTau125"]
    #recoil=["Z","Z","Z","Z","Z","Z","W","W","W","W","W","W","W","W","W","W","0","0","0","0","0","0","0","0","Z","Z","Z","0","0","0","0","0","0","0","0","0","Z","Z","Z","Z","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","Z","Z","0","0","0","Z","Z","0","0","0","Z","Z","0","0","0","Z","Z","0","0","0","0","0","0","0"]
    
    datadir="/nfs_scratch/caillol/smhmt_anomalous_4sep/"
    all_File = open("do_submit.sh" , 'w')
    line=""
    print len(name)
    for j in range(0,len(name)):
       print name[j],sample[j],recoil[j]
       submit_File = open("Submit_"+name[j]+".sh" , 'w')
       line+="mkdir -p "+datadir+"Out_"+name[j]+"\n"
       line+="sh Submit_"+name[j]+".sh" +"\n"
       f=os.popen("ls -t " + place+sample[j] + "/make* | sort")
       #f=os.popen("ls -t " + place+sample[j])
       command1=""
       ligne=0
       for i in f.readlines():
	   command1=command1+"./skim_mt.exe mc "+datadir+"Out_"+name[j]+"/"+name[j]+str(ligne)+".root " + i[0:-1] + " " + recoil[j] +" \n"
	   #command1=command1+"./skim_mt.exe mc "+datadir+"Out_"+sample[j]+"/"+i[0:-1] +" /hdfs/store/user/truggles/httJuly12melaSig/"+ i[0:-1] + " " + recoil[j] +" \n"
           ligne=ligne+1
       submit_File.write(command1)
       submit_File.close()
    all_File.write(line)
    all_File.close()

