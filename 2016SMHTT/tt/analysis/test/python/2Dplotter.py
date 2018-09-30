#!/usr/bin/env python
import ROOT
import re
from array import array
import math
import plotRocCurve_def

channel = "#tau_{h}#tau_{h}"
varX = "normMELAggh"
varY = "M_{#tau#tau}"
plottitle = varX+" VS "+varY

file=ROOT.TFile("final_nominal.root","r")
cate={"tt_boosted":"boosted","tt_vbf":"vbf"}
samples = ["ZTT","QCD","ZL","ZJ","TTT","TTJ","W","VVT","VVJ","ggH125","VBF125","WH125","ZH125"]

ROOT.gStyle.SetFrameLineWidth(1)
ROOT.gStyle.SetLineWidth(1)
ROOT.gStyle.SetOptStat(0)

def add_title():
    title = ROOT.TPaveText(0.42, 0.88, 0.60, 0.98, "NDC")
    title.SetBorderSize(   0 )
    title.SetFillStyle(    0 )
    title.SetTextAlign(   12 )
    title.SetTextSize ( 0.06 )
    title.SetTextColor(    1 )
    title.SetTextFont (   42 )
    title.AddText(plottitle)
    return title

for cats in file.GetListOfKeys():
    cat = cats.GetName()
    if cat in cate.keys():
        for histos in file.Get(cat).GetListOfKeys():
            histoN = histos.GetName()
            histo = file.Get(cat).Get(histoN)
            histo.SetTitle(channel)
            histo.SetTitleFont(42)
            histo.SetTitleOffset(10)
            histo.GetXaxis().SetTitle(varX)
            histo.GetYaxis().SetTitle(varY)
            histo.GetXaxis().SetTitleOffset(1.0)
            histo.GetYaxis().SetTitleOffset(0.9)
            canvas = ROOT.TCanvas(cat+"_"+histoN,"",0,0,400,600)
            canvas.SetBottomMargin(0.15)
            canvas.SetTopMargin(0.12)
            canvas.SetBorderMode(0)
            canvas.SetBorderSize(10)    
            canvas.cd()
            histo.Draw("COLZ")
            title = add_title()
            title.Draw("same")
            canvas.SaveAs("plots/2D"+cat+"_"+histoN+".pdf")

