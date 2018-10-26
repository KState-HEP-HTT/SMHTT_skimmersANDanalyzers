#!/usr/bin/env python
import ROOT
import re
from array import array
from optparse import OptionParser
import sys

inputfile = sys.argv[1]
channel = sys.argv[2]

parser = OptionParser()
parser.add_option('--svn', '-s', action='store_true',
                  default=False, dest='is_SVN',
                  help='input is SVN datacard'
                  )
parser.add_option('--ztt', '-z', action='store_true',
                  default=False, dest='is_zttMC',
                  help='run on embedded or MC ZTT'
                  )
(options, args) = parser.parse_args()

islog=1
'''
def add_lumi():
    lowX=0.7
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.08)
    lumi.SetTextFont (   42 )
    lumi.AddText("2016, 20.1 fb^{-1} (13 TeV)")
    return lumi

def add_CMS():
    lowX=0.11
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.1)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

def add_Preliminary():
    lowX=0.18
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.08)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Preliminary")
    return lumi

def make_legend():
	if islog:
	   output = ROOT.TLegend(0.12, 0.05, 0.92, 0.25, "", "brNDC")
           output.SetNColumns(5)
	else:
           output = ROOT.TLegend(0.55, 0.3, 0.92, 0.75, "", "brNDC")
	   output.SetNColumns(2)
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        #output.SetFillStyle(0)
        output.SetFillColor(0)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output

ROOT.gStyle.SetFrameLineWidth(3)
ROOT.gStyle.SetLineWidth(3)
ROOT.gStyle.SetOptStat(0)

c=ROOT.TCanvas("canvas","",0,0,1800,600)
c.cd()
'''
file=ROOT.TFile(inputfile,"r")
file1D=ROOT.TFile("htt_"+channel+".inputs-sm-13TeV-2D.root","recreate")
categories=[channel+"_0jet",channel+"_boosted",channel+"_vbf"] # input dir names
processes=["data_obs","ZTT","W","QCD","ZL","ZJ","TTT","TTJ","VV","EWKZ","ggH125","VBF125","WH125","ZH125"] # input histos
processes_plot_bkg=["ZTT","W","QCD","ZL","ZJ","TTT","TTJ","VV","EWKZ"] # bkg processes for plot
if options.is_SVN:
    del categories[:]
    del processes[:]
    categories=["htt_"+channel+"_1_13TeV","htt_"+channel+"_2_13TeV","htt_"+channel+"_3_13TeV"]
    processes=["data_obs","ZTT","W","QCD","ZL","ZJ","TTT","TTJ","VV","EWKZ","ggH_htt125","qqH_htt125","WH_htt125","ZH_htt125"] # input histos    

if channel == 'tt':
    print "this is tt channel"    
    processes.remove("VV")
    processes.insert(8,"VVT")
    processes.insert(9,"VVJ")
    processes_plot_bkg.remove("VV")
    processes_plot_bkg.insert(8,"VVT")
    processes_plot_bkg.insert(9,"VVJ")
cat=[channel+"_0jet",channel+"_boosted",channel+"_vbf"] # outout dir names

systematics=[] # systematics
'''
systematics=[ # systematics
    "_CMS_htt_dyShape_13TeV",
    "_CMS_htt_jetToTauFake_13TeV",
    "_CMS_htt_ttbarShape_13TeV",
    "_CMS_scale_t_13TeV",
    "_CMS_scale_t_1prong_13TeV",
    "_CMS_scale_t_1prong1pizero_13TeV",
    "_CMS_scale_t_3prong_13TeV",
    "_CMS_scale_met_unclustered_13TeV",
    "_CMS_scale_met_clustered_13TeV",
    "_CMS_scale_j_13TeV",
    "_CMS_htt_zmumuShape_VBF_13TeV"
    ]
'''


processes_plot_signal=["ggH125","VBF125",] # signal processes for plot
ncat=3
adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)
for i in range (0,ncat): # loop over categories
    mydir=file1D.mkdir(cat[i])

    print "=================>>>  category: ", categories[i]
    for i_histo in processes: # loop over input histos (processes)
        print " histo: ", i_histo
        histo2D=file.Get(categories[i]).Get(i_histo)
        nx=histo2D.GetXaxis().GetNbins()
        ny=histo2D.GetYaxis().GetNbins()
        histo=ROOT.TH1F("histo",histo2D.GetName(),nx*ny,0,nx*ny)
        histo.SetName(histo2D.GetName())    
        if options.is_SVN:
            if histo2D.GetName()=="ggH_htt125":
                histo.SetName("ggH125")
            if histo2D.GetName()=="qqH_htt125":
                histo.SetName("VBF125")
            if histo2D.GetName()=="WH_htt125":
                histo.SetName("WH125")
            if histo2D.GetName()=="ZH_htt125":
                histo.SetName("ZH125")

        l=0
        for j in range(1,nx+1):
            for k in range(1,ny+1):
	        l=l+1
                n = histo2D.GetBin(j,k);
                histo.SetBinContent(l,histo2D.GetBinContent(n))
                histo.SetBinError(l,histo2D.GetBinError(n))
        mydir.cd()
        histo.Write()

        for systematic in systematics : # loop over available systematics
            if file.Get(categories[i]).Get(i_histo+systematic+"Down") != None:
                print i_histo+systematic+"Down/Up"
                histo2D_d=file.Get(categories[i]).Get(i_histo+systematic+"Down") #
                histo2D_u=file.Get(categories[i]).Get(i_histo+systematic+"Up") #
                histo_d=ROOT.TH1F("histo_d",histo2D_d.GetName(),nx*ny,0,nx*ny) #
                histo_u=ROOT.TH1F("histo_u",histo2D_u.GetName(),nx*ny,0,nx*ny) #
                histo_d.SetName(histo2D_d.GetName()) #
                histo_u.SetName(histo2D_u.GetName()) #
                l=0
                for j in range(1,nx+1):
                    for k in range(1,ny+1):
                        l=l+1
                        n = histo2D.GetBin(j,k);
                        histo_u.SetBinContent(l,histo2D_u.GetBinContent(n)) #
                        histo_u.SetBinError(l,histo2D_u.GetBinError(n)) #
                        histo_d.SetBinContent(l,histo2D_d.GetBinContent(n)) #
                        histo_d.SetBinError(l,histo2D_d.GetBinError(n)) #
                histo_u.Write() #
                histo_d.Write() #           
            #else :
            #    print i_histo+systematic+"Down/Up fail"

# now make nice unrolled plots:
