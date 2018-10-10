
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
file_NN = ROOT.TFile("final_nominal_NN.root")

####### Produce ROC curve #######
plotRocCurve_def.produce_roc_curve( 
    file_current,file_NN,       # input root files
    'VBF125','VBF125_eff',   # 'histogramName' in rootfile, 'legend Title' on the plot (x-axis)
    'ZTT','ZTT_eff',         # 'histogramName' in rootfile, 'legend Title' on the plot (y-axis)
    'normMELAvbf','NNdisc',            # category (legend name)
    'ROC(tt_ZTT)',      # output file name is 'ROC(normMELAggH).pdf'
    )

bkgtmp = 'QCD'
plotRocCurve_def.produce_roc_curve1( 
    file_NN,       # input root files
    'VBF125','VBF125_eff',   # 'histogramName' in rootfile, 'legend Title' on the plot (x-axis)
    'ZTT',bkgtmp,'bkg_eff',         # 'histogramName' in rootfile, 'legend Title' on the plot (y-axis)
    'ROC(NNdisc)',      # output file name is 'ROC(normMELAvbf).pdf'
    )


'''
####### Produce MELA distributions with ratio #######
plotRocCurve_def.produce_ratio(
    file_vbf,
    'normMELAvbf','vbf',     # 'legend title', 'category' in root file
    'VBF125','ZTT',          # 'signal histo name', 'ztt histo name'
    )
'''
plotRocCurve_def.produce_ratio(
    file_NN,
    'NNdisc','vbf',
    'VBF125','ZTT',
    )

