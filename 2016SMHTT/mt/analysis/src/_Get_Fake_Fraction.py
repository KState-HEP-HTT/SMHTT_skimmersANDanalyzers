#abdollah.mohammadi@cern.ch
#This script is to get the fake fraction.
#The same code can be used for both mutau, and tautau channels




import os
import ROOT
from ROOT import *
from array import array



inputFile= TFile('Input_Files_For_Fake_Fraction.root','r')

categories=['0jet','boosted','vbf']

outFile= TFile('FakeFraction_mutau_3D.root','RECREATE')


########
# Note: for the time being we have not splitted VV, sp we assume all VV is real. We have to spl
########
data=['data_obs']
ttj=['TTJ']
wj=['W','VV','ZJ']
real=['ZTT','TTT','EWKZ','ZL']



for cat in categories:
    inputDir='AI%s_FF'%cat
    
    hist_data=inputFile.Get('%s/%s'%(inputDir,'data_obs'))
    
    #TTJ fraction
    print '%s/%s'%(inputDir,ttj[0])
    hist_ttj=inputFile.Get('%s/%s'%(inputDir,'TTJ'))
    
    # W fraction
    hist_wj=inputFile.Get('%s/%s'%(inputDir,'W'))
    hist_wj.Add(inputFile.Get('%s/%s'%(inputDir,'ZJ')))
    
    # real
    hist_real=inputFile.Get('%s/%s'%(inputDir,'ZTT'))
    hist_real.Add(inputFile.Get('%s/%s'%(inputDir,'TTT')))
    hist_real.Add(inputFile.Get('%s/%s'%(inputDir,'EWKZ')))
    hist_real.Add(inputFile.Get('%s/%s'%(inputDir,'ZL')))
    hist_real.Add(inputFile.Get('%s/%s'%(inputDir,'VV')))
    
    
    hist_QCD=hist_data.Clone()
    hist_QCD.Add(hist_ttj,-1)
    hist_QCD.Add(hist_wj,-1)
    hist_QCD.Add(hist_real,-1)
    
    
    ## print the fake fraction for all bins
    print   'QCD FakeFrac=',  hist_QCD.Integral()/hist_data.Integral()
    print   'W FakeFrac=',  hist_wj.Integral()/hist_data.Integral()
    print   'TTJ FakeFrac=',  hist_ttj.Integral()/hist_data.Integral()
    print   'Real FakeFrac=',  hist_real.Integral()/hist_data.Integral()
    
    
    tDirectory= outFile.mkdir(cat)
    tDirectory.cd()
    
    
    #### Binning for x axis
    bins = hist_data.GetXaxis().GetXbins()
    binlist = []
    binlist = [bins[b] for b in xrange(len(bins))]
    Binning = array("d",binlist)
    print  "x binning", Binning

    #### Binning for y axis
    binsY = hist_data.GetYaxis().GetXbins()
    binlistY = []
    binlistY = [binsY[b] for b in xrange(len(binsY))]
    BinningY = array("d",binlistY)
    print  "y binning", BinningY

    #### Binning for z axis
    binlistZ=[0,1,2,3,4]
    BinningZ= array("d",binlistZ)
    
    
    OutHis = TH3F('3DHisto','3DHisto',len(binlist)-1, Binning,len(binlistY)-1, BinningY,len(binlistZ)-1, BinningZ)
    
    
    for xbin in range(hist_data.GetNbinsX()):
        for ybin in range(hist_data.GetNbinsY()):
        
            if hist_data.GetBinContent(xbin+1,ybin+1) == 0 : continue  # skip the binns of they are empty
            
            
            binZ_qcd=1
            OutHis.SetBinContent(xbin+1,ybin+1,binZ_qcd, hist_QCD.GetBinContent(xbin+1,ybin+1)/hist_data.GetBinContent(xbin+1,ybin+1) )

            binZ_w=2
            OutHis.SetBinContent(xbin+1,ybin+1,binZ_w, hist_wj.GetBinContent(xbin+1,ybin+1)/hist_data.GetBinContent(xbin+1,ybin+1) )
        
            binZ_tt=3
            OutHis.SetBinContent(xbin+1,ybin+1,binZ_tt, hist_ttj.GetBinContent(xbin+1,ybin+1)/hist_data.GetBinContent(xbin+1,ybin+1) )
        
            binZ_real=4
            OutHis.SetBinContent(xbin+1,ybin+1,binZ_real, hist_real.GetBinContent(xbin+1,ybin+1)/hist_data.GetBinContent(xbin+1,ybin+1) )
    
    tDirectory.WriteObject(OutHis,cat)

outFile.Close()
    

