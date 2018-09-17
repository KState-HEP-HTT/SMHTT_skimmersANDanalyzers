
from subprocess import Popen 
from sys import argv, exit, stdout, stderr    

import ROOT
import numpy 
from array import array   

import plotRocCurve_def 

# So things don't look like crap.    
ROOT.gROOT.SetStyle("Plain")
ROOT.gROOT.SetBatch(True)   
ROOT.gStyle.SetOptStat(0)  

######## Load Files ######### 
#fsignal = ROOT.TFile("files_nominal/ggH125.root") 
#fztt = ROOT.TFile("files_nominal/ZTT.root") 
file1 = ROOT.TFile("final_nominal_mjj.root")
file2 = ROOT.TFile("final_nominal_MELA.root")


####### Produce ROC curve #######
'''
plotRocCurve_def.produce_roc_curve( 
    file1,file2,file3, # input root files
    'VBF125','VBF125_eff', # 'histogramName', ' legend Title' 
    'ZTT','ZTT_eff', # 'histogramName', ' legend Title'
    'mjj','MELA','NN',  # type
    'ROC',
    )

plotRocCurve_def.produce_roc_curve( 
    file,file2, # input root files
    'VBF125_Dbkg_VBF','VBF125_eff', # 'histogramName', ' legend Title' 
    'ZTT_Dbkg_VBF','ZTT_eff', # 'histogramName', ' legend Title'
    'vbf','vbf',  # category
    'ROC(Norm_Dbkg_VBF)',
    )
'''
plotRocCurve_def.produce_roc_curve( 
    file1,file2, # input root files
    'ggH125','ggH125_eff', # 'histogramName', ' legend Title' 
    'ZTT','ZTT_eff', # 'histogramName', ' legend Title'
    'mjj','MELA',  # category
    'ROC',
    )

####### Produce MELA obs with ratio #######

plotRocCurve_def.produce_ratio(
    file3,
    'NN_disc','vbf', # 'variable', 'category'
    'VBF125','ZTT', # 'signal histo name', 'ztt histo name'
    )
'''
plotRocCurve_def.produce_ratio(
    file,
    'Dbkg_VBF','2jets', # 'variable', 'category'
    'VBF125_Dbkg_VBF','ZTT_Dbkg_VBF', # 'signal histo name', 'ztt histo name'
    )

plotRocCurve_def.produce_ratio(
    file,
    'Dbkg_ggH','vbf', # 'variable', 'category'
    'ggH125_Dbkg_ggH','ZTT_Dbkg_ggH', # 'signal histo name', 'ztt histo name'
    )
plotRocCurve_def.produce_ratio(
    file,
    'Dbkg_ggH','2jets', # 'variable', 'category'
    'ggH125_Dbkg_ggH','ZTT_Dbkg_ggH', # 'signal histo name', 'ztt histo name'
    )
'''



