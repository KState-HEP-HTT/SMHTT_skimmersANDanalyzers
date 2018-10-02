
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
'''
####### Produce ROC curve #######
plotRocCurve_def.produce_roc_curve( 
    file_mjj,file_ggh,       # input root files
    'ggH125','ggH125_eff',   # 'histogramName' in rootfile, 'legend Title' on the plot (x-axis)
    'ZJ','ZJ_eff',         # 'histogramName' in rootfile, 'legend Title' on the plot (y-axis)
    'mjj','MELA',            # category (legend name)
    'ROC(normMELAggH)',      # output file name is 'ROC(normMELAggH).pdf'
    )
'''
bkgtmp = 'EWKZ'
plotRocCurve_def.produce_roc_curve1( 
    file_current,       # input root files
    'ggH125','ggH125_eff',   # 'histogramName' in rootfile, 'legend Title' on the plot (x-axis)
    bkgtmp,'ZTT','bkg125_eff',         # 'histogramName' in rootfile, 'legend Title' on the plot (y-axis)
    'ROC(normMELAggh)',      # output file name is 'ROC(normMELAvbf).pdf'
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
    file_current,
    'normMELAggH','vbf',
    'ggH125',bkgtmp,
    )

