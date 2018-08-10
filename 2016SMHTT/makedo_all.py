import os
import sys

channel = raw_input("Please, type channel. (tt, et, mt) : ")
if (channel=="tt") :
    ch = "TT"
elif (channel=="mt") :
    ch = "MT"
elif (channel=="et") :
    ch = "ET"
print 'channel : ',ch
    

directory_n = raw_input("Please, type the path of output files. ( /scratch/doyeong/testfiles_tt_July12) :") # Bookmark 1
numMax = input("Please, type the number of iteration. -1 for full skim. : ") # the number of iteration
sys.stdout = open('skimScript_'+ch+'.sh','wt')
directory_MC = "/hdfs/store/user/ndev/LFV_feb18_mc/"
directory_Data = "/hdfs/store/user/ndev/LFV_reminiaod_feb18/"
directory_Signal = "/hdfs/store/user/truggles/SMHTT_signals_may30/"
sample_MC = {    
    "DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext1-v2/" : "DYJets_",
    "DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext2-v1/" : "DYJets_",
    "DY1JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "DYJets1_",
    "DY2JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "DYJets2_",
    "DY3JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "DYJets3_",
    "DY4JetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "DYJets4_",
    "WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "WJets_",
    "WJetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext2-v1/" : "WJets_",
    "W1JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "WJets1_" ,
    "W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "WJets2_",
    "W2JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext1-v1/" : "WJets2_",
    "W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "WJets3_",
    "W3JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext1-v1/" : "WJets3_",
    "W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6-v1/" : "WJets4_",
    "W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext1-v1/" : "WJets4_",
    "W4JetsToLNu_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_v6_ext2-v1/" : "WJets4_",
    "TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_v6-v1/" : "TT_",
    "VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/" : "VV2l2nu_",
    "VVTo2L2Nu_13TeV_amcatnloFXFX_madspin_pythia8_v6_ext1-v1/" : "VV2l2nu_",
    "ST_t-channel_antitop_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1_v6-v1/" : "Tbar-tchan_",
    "ST_t-channel_top_4f_inclusiveDecays_13TeV-powhegV2-madspin-pythia8_TuneCUETP8M1_v6-v1/" : "T-tchan_",
    "ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_v6_ext1-v1/" : "Tbar-tW_",
    "ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_v6_ext1-v1/" : "T-tW_",
    "WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/" : "WW1l1nu2q_",
    "ZZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/" : "ZZ2l2q_",
    "ZZTo4L_13TeV-amcatnloFXFX-pythia8_v6_ext1-v1/" : "ZZ4l_",
    
    "EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6-v1/" : "EWKWMinus_",
    "EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6_ext1-v1/" : "EWKWMinus_",
    "EWKWMinus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6_ext2-v1/" : "EWKWMinus_",
    "EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6-v1/" : "EWKWPlus_",
    "EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6_ext1-v1/" : "EWKWPlus_",
    "EWKWPlus2Jets_WToLNu_M-50_13TeV-madgraph-pythia8_v6_ext2-v1/" : "EWKWPlus_",
    "EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8_v6-v1/" : "EWKZ2l_",
    "EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8_v6_ext1-v1/" : "EWKZ2l_",
    "EWKZ2Jets_ZToLL_M-50_13TeV-madgraph-pythia8_v6_ext2-v1/" : "EWKZ2l_",
    "EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8_v6-v1/" : "EWKZ2nu_",
    "EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8_v6_ext1-v1/" : "EWKZ2nu_",
    "EWKZ2Jets_ZToNuNu_13TeV-madgraph-pythia8_v6_ext2-v1/" : "EWKZ2nu_",
    
    "WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_v6_ext1-v1/" : "WGLNu_",
    "WGToLNuG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_v6_ext2-v1/" : "WGLNu_",
    "WGstarToLNuEE_012Jets_13TeV-madgraph_v6-v1/" : "WGstarEE_",
    "WGstarToLNuMuMu_012Jets_13TeV-madgraph_v6-v1/" : "WGstarMuMu_",
    "WWW_4F_TuneCUETP8M1_13TeV-amcatnlo-pythia8_v6-v1/" :"WWW_",
    "WZJToLLLNu_TuneCUETP8M1_13TeV-amcnlo-pythia8_v6-v1/" : "WZ3l1nu_",
    "WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_v6-v3/" : "WZ1l1nu2q_",
    "WZTo1L3Nu_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/" : "WZ1l3nu_",
    "WZTo2L2Q_13TeV_amcatnloFXFX_madspin_pythia8_v6-v1/" : "WZ2l2q_"
    }
sample_Signal = {"GluGluHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/" : "ggHtoTauTau125_",
                 "GluGluHToWWTo2L2Nu_M125_13TeV_powheg_pythia8_v6-v1/" : "ggH_WW125_",
                 "VBFHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/" : "VBFHtoTauTau125_", #VBFHToTauTau_M125_13TeV_powheg_pythia8_v6-v2 also exist. 
                 "VBFHToWWTo2L2Nu_M125_13TeV_powheg_pythia8_v6-v1/" : "VBF_WW125_",
                 "WplusHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/" : "WPlusHTauTau125_",
                 "WminusHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/" : "WMinusHTauTau125_",
                 "ZHToTauTau_M125_13TeV_powheg_pythia8_v6-v1/" : "ZHTauTau125_"
                 }
sample_Data = {
               "data_SingleMuon_Run2016B_v1/" : "data"+ch+"-B_",
               "data_SingleMuon_Run2016B_v2/" : "data"+ch+"-B_",
               "data_SingleMuon_Run2016C/" : "data"+ch+"-C_",
               "data_SingleMuon_Run2016D/" : "data"+ch+"-D_",
               "data_SingleMuon_Run2016E/" : "data"+ch+"-E_",
               "data_SingleMuon_Run2016F/" : "data"+ch+"-F_",
               "data_SingleMuon_Run2016G/" : "data"+ch+"-G_",
               "data_SingleMuon_Run2016H_v2/" : "data"+ch+"-H_",
               "data_SingleMuon_Run2016H_v3/" : "data"+ch+"-H_"
               }
outputDic = {}

print("./Make.sh skim_"+channel+".cc\n") # Bookmark 2
print("mkdir "+directory_n)
print("mkdir "+directory_n+"/Recoil0_TES1_WJ0")
print("mkdir "+directory_n+"/Recoil2_TES1_WJ0")
print("mkdir "+directory_n+"/Recoil2_TES1_WJ1")
print("mkdir "+directory_n+"/Recoil0_TES0_WJ0")

dicSamples = {directory_Signal : sample_Signal, directory_MC : sample_MC, directory_Data : sample_Data}
recoil = 0

for directory, samples in dicSamples.items():#.keys():
    type = 'mc'
    if directory is directory_Data:
        type = 'data'

    for sample in samples:
        # This categorization form here : https://github.com/maravin/SubmitSVFit/blob/CMSSW_9_4_4_classic_svFit_v0/tools/controlledMerge.py
        # Cecile's run script for mt : https://github.com/cecilecaillol/SMHTT2016/blob/master/mt/Analyze/do_all.sh
        if ((('GluGlu') in str(sample)) or (('DY') in str(sample)) or (('VBF') in str(sample)) ):
            dir = 'Recoil2_TES1_WJ0/'
            recoil = 2
        elif 'WJets' in str(samples[sample]):
            #print str(samples[sample])
            dir = 'Recoil2_TES1_WJ1/'
            recoil = 2
        elif directory is directory_Data:
            dir = 'Recoil0_TES0_WJ0/'
            recoil = 0
        else :
            dir = 'Recoil0_TES1_WJ0/'
            recoil = 0

        test_directory = directory+sample
        output = samples[sample]
        i = 0
        if output in outputDic.keys() :
            i = outputDic[output]+1

        for child in os.listdir(test_directory):
            test_path = os.path.join(test_directory, child)
            print ('./skim_'+channel+'.exe '+type+' '+directory_n+'/'+dir+output+str(i)+'.root'+' '+test_directory+child+' '+str(recoil)) # Bookmark 3
            # when multiple ver exist
            if os.listdir(test_directory)[-1] == child :
                outputDic[output]=i
            i=i+1
            
            # Maximum number of iteration
            if (numMax!=-1 and i%numMax == 0):
                outputDic[output]=i-1
                break



