#!/usr/bin/env python
import ROOT
from ROOT import *
import re
from array import array

islog=1
unrollSV=1

#file=ROOT.TFile("FFfinal_mutau_2D.root","r")
#file1=ROOT.TFile("FF_final_mutau_1D.root","recreate")
file=ROOT.TFile("final_mutau_2D.root","r")
file1=ROOT.TFile("final_mutau_1D.root","recreate")


file.cd()
dirList = gDirectory.GetListOfKeys()
for k1 in dirList:
      if k1.GetName()=="mt_wjets_0jet_cr" or k1.GetName()=="mt_wjets_boosted_cr" or k1.GetName()=="mt_wjets_vbf_cr" or k1.GetName()=="mt_antiiso_0jet_cr" or k1.GetName()=="mt_antiiso_boosted_cr" or k1.GetName()=="mt_antiiso_vbf_cr":
         h1 = k1.ReadObj()
         file1.mkdir(h1.GetName())
         h1.cd()
         dirList2 = gDirectory.GetListOfKeys()
         for k2 in dirList2:
            h2 = k2.ReadObj()
            h3=h2.Clone()
            file1.cd(h1.GetName())
            h3.SetName(k2.GetName())
            h3.Write()
	 
      if k1.GetName()=="mt_0jet" or k1.GetName()=="mt_boosted" or k1.GetName()=="mt_vbf":
         h1 = k1.ReadObj()
         file1.mkdir(h1.GetName())
         h1.cd()
         dirList2 = gDirectory.GetListOfKeys()
         for k2 in dirList2:
            h2 = k2.ReadObj()
            h3=h2.Clone()
            nn=h3.GetSize()
            nx=h3.GetXaxis().GetNbins()
   	    ny=h3.GetYaxis().GetNbins()
   	    h1d=ROOT.TH1F("h1d","h1d",nx*ny,0,nx*ny)
            dir1=nx
            dir2=ny
	    l=0
            for j in range(1,dir1+1):
      		for k in range(1,dir2+1):
        	   l=l+1
        	   n = h3.GetBin(j,k);
        	   h1d.SetBinContent(l,h3.GetBinContent(n))
        	   h1d.SetBinError(l,h3.GetBinError(n))
            file1.cd(h1.GetName())
            h1d.SetName(k2.GetName())
	    h1d.Write()

