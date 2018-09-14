import ROOT
import os
import sys
from ROOT import TH1F

#fin = ROOT.TFile("files_nominal/VBF125.root","")
finKSU = ROOT.TFile("final_nominal.root","")
finOFF = ROOT.TFile("../htt_input.root","")
fout = ROOT.TFile("testUnroll.root","recreate")
dic_cat = {'tt_0jet':'htt_tt_1_13TeV', 'tt_boosted':'htt_tt_2_13TeV', 'tt_vbf':'htt_tt_3_13TeV'}
dic_sig = {'VBF125':'qqH_htt125', 'WH125':'WH_htt125','ggH125':'ggH_htt125','ZH125':'ZH_htt125'}
dic_bkg = ['data_obs', 'ZTT', 'ZJ', 'ZL', 'TTT', 'TTJ', 'VVT', 'VVJ', 'W', 'EWKZ','QCD']
#dic_sig = {'VBF125':'qqH125', 'WH125':'WH125','ggH125':'ggH125','ZH125':'ZH125'}
c=ROOT.TCanvas("canvas","",0,0,600,600)


for key in finKSU.GetListOfKeys():
    tdirName = key.GetName()
    if tdirName in dic_cat.keys():
        #print tdirName
        print '#################################################  ', tdirName, '  #################################################\n'
        for histK in finKSU.Get(tdirName).GetListOfKeys():
            histName = histK.GetName()
            hist = finKSU.Get(tdirName).Get(histName)
            histDim = hist.GetDimension()
            nbinX = hist.GetNbinsX()

            # open histogram in official datacard
            finOFF.cd()
            if ((histName not in dic_bkg) and (histName not in dic_sig.keys())):
                continue
            if histName in dic_sig.keys():
                #print 'histName, dic_sig[histName]:',histName, dic_sig[histName]
                h_off=finOFF.Get(dic_cat[tdirName]).Get(dic_sig[histName])
            else:
                h_off=finOFF.Get(dic_cat[tdirName]).Get(histName)

            # for 1D
            if histDim==1:
                h_ur=finKSU.Get(tdirName).Get(histName)
                fout.cd()
                h_ur.SetLineStyle(1)
                h_ur.SetLineColor(2)
                h_ur.Write()
                h_off.Write()
                c.cd()                
                h_off.Draw()
                h_ur.Draw('same')
                c.SaveAs('unrollPlots/'+tdirName+'_'+histName+'.pdf')
                print histName
                print "official datacard yield is ", h_off.Integral()
                print "KSU datacard yield is ", h_ur.Integral(), '\n'

            # for 2D
            if histDim==2:                
                h_ur=TH1F(tdirName+'_'+histName,"",48,0,48)                 
                nbinY = hist.GetNbinsY()
                #print histName
                for ibin in range(nbinX):
                    for jbin in range(nbinY):         
                        binNo=jbin+ibin*nbinY
                        cont = hist.GetBinContent(ibin+1,jbin+1)
                        h_ur.SetBinContent(binNo+1,cont)  
                        #print "\nbin No : ", binNo+1
                        #print "x,y : (", ibin+1,", " ,jbin+1 ,"), value : " , cont

                fout.cd()
                h_ur.SetLineColor(2)
                h_ur.Write()
                h_off.Write()
                c.cd()                
                h_off.Draw()
                h_ur.Draw('same')
                c.SaveAs('unrollPlots/'+tdirName+'_'+histName+'.pdf')
                print histName
                print "official datacard yield is ", h_off.Integral()
                print "KSU datacard yield is ", h_ur.Integral(),'\n'


'''
# loop over all TDirectory
for key in finKSU.GetListOfKeys():
    tdirName = key.GetName()
    # get hist name
    for histK in finKSU.Get(tdirName).GetListOfKeys():
        histName = histK.GetName()
        hist = finKSU.Get(tdirName).Get(histName)
        histDim = hist.GetDimension()
        nbinX = hist.GetNbinsX()        

        if histDim==2 :#and tdirName=='ttOS_boosted':
            h_ur=TH1F(tdirName+histName,"",48,0,48)
            nbinY = hist.GetNbinsY()
            for ibin in range(nbinX):
                for jbin in range(nbinY):
                    print " "
                    binNo=jbin+ibin*nbinY
                    print "bin No : ", binNo
                    cont = hist.GetBinContent(ibin+1,jbin+1)
                    print "x,y : (", ibin+1,", " ,jbin+1 ,"), value : " , cont
                    h_ur.SetBinContent(binNo+1,cont)

            fout.cd()
            h_ur.Write()

'''
