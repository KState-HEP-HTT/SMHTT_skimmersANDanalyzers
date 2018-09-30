
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

file_current = ROOT.TFile("final_nominal.root")
#file_vbfMELA2jets = ROOT.TFile("final_nominal_normMELAvbf_2jets.root") 
#file_vbfMELA2016 = ROOT.TFile("final_nominal_normMELAvbf_vbf2016.root")
#file_mjj2jets = ROOT.TFile("final_nominal_mjj_2jets.root")
#file_mjj2016 = ROOT.TFile("final_nominal_mjj_vbf2016.root")
'''
####### Produce ROC curve #######
plotRocCurve_def.produce_roc_curve( 
    file_mjj,file_ggh,       # input root files
    'ggH125','ggH125_eff',   # 'histogramName' in rootfile, 'legend Title' on the plot (x-axis)
    'ZJ','ZJ_eff',         # 'histogramName' in rootfile, 'legend Title' on the plot (y-axis)
    'mjj','MELA',            # category (legend name)
    'ROC(normMELAggH)',      # output file name is 'ROC(normMELAggH).pdf'
    )

plotRocCurve_def.produce_roc_curve( 
    file_mjj2jets,file_vbfMELA2jets,       # input root files
    'VBF125','VBF125_eff',   # 'histogramName' in rootfile, 'legend Title' on the plot (x-axis)
    'QCD','QCD_eff',         # 'histogramName' in rootfile, 'legend Title' on the plot (y-axis)
    'mjj','MELA',            # category (legend name)
    'ROC(2orMoreJets)',      # output file name is 'ROC(normMELAvbf).pdf'
    )
'''
plotRocCurve_def.produce_roc_curve1( 
    file_current,       # input root files
    'ggH125','ggH125_eff',   # 'histogramName' in rootfile, 'legend Title' on the plot (x-axis)
    'EWKZ','ZTT','bkg125_eff',         # 'histogramName' in rootfile, 'legend Title' on the plot (y-axis)
    'ROC(normMELAggh)',      # output file name is 'ROC(normMELAvbf).pdf'
    )


'''


####### Produce MELA obs with ratio #######
plotRocCurve_def.produce_ratio(
    file_vbf,
    'normMELAvbf','vbf',     # 'legend title', 'category' in root file
    'VBF125','ZTT',          # 'signal histo name', 'ztt histo name'
    )
plotRocCurve_def.produce_ratio(
    file_ggh,
    'normMELAggh','vbf',     # 'legend title', 'category' in root file
    'ggH125','ZTT',          # 'signal histo name', 'ztt histo name'
    )
plotRocCurve_def.produce_ratio(
    file_vbfbyggh,
    'normMELAvbf_ggH','vbf',
    'ggH125','VBF125',
    )
plotRocCurve_def.produce_ratio(
    file_gghbyvbf,
    'normMELAggH_vbf','vbf',
    'ggH125','VBF125',
    )

plotRocCurve_def.produce_ratio(
    file_current,
    'normMELvbf','vbf',
    'VBF125','ZTT',
    )


plotRocCurve_def.produce_ratio(
    file_current,
    'normMELAggH_w200','vbf',
    'ggH125','QCD',
    )
'''
