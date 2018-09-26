#!/usr/bin/env python
import ROOT
import re
from array import array

def add_lumi():
    lowX=0.58
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.06)
    lumi.SetTextFont (   42 )
    lumi.AddText("2016, 20.1 fb^{-1} (13 TeV)")
    return lumi

def add_CMS():
    lowX=0.21
    lowY=0.70
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.08)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

def add_Preliminary():
    lowX=0.21
    lowY=0.63
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.06)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Preliminary")
    return lumi

def make_legend():
        output = ROOT.TLegend(0.65, 0.3, 0.92, 0.82, "", "brNDC")
        #output = ROOT.TLegend(0.2, 0.1, 0.47, 0.65, "", "brNDC")
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        output.SetFillStyle(0)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output

ROOT.gStyle.SetFrameLineWidth(3)
ROOT.gStyle.SetLineWidth(3)
ROOT.gStyle.SetOptStat(0)

c=ROOT.TCanvas("canvas","",0,0,600,600)
c.cd()

file=ROOT.TFile("final_mutau_cut.root","r")

adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)

categories=["mt_0jet_low","mt_0jet_high","mt_1jet_low","mt_1jet_high","mt_vbf_low","mt_vbf_high"] 
ncat=6

for i in range (0,ncat):
   Data=file.Get(categories[i]).Get("data_obs")
   QCD=file.Get(categories[i]).Get("QCD")
   W=file.Get(categories[i]).Get("W") 
   TT=file.Get(categories[i]).Get("TT")
   VV=file.Get(categories[i]).Get("VV")
   DYB=file.Get(categories[i]).Get("ZL")
   DYS=file.Get(categories[i]).Get("ZTT")
   qqH=file.Get(categories[i]).Get("qqH125")
   ggh=file.Get(categories[i]).Get("ggH125")

   Data.GetXaxis().SetTitle("")
   Data.GetXaxis().SetTitleSize(0)
   Data.GetXaxis().SetNdivisions(505)
   Data.GetYaxis().SetLabelFont(42)
   Data.GetYaxis().SetLabelOffset(0.01)
   Data.GetYaxis().SetLabelSize(0.06)
   Data.GetYaxis().SetTitleSize(0.075)
   Data.GetYaxis().SetTitleOffset(1.04)
   Data.SetTitle("")
   Data.GetYaxis().SetTitle("Events/bin")

   QCD.SetFillColor(ROOT.TColor.GetColor("#ffccff"))
   VV.SetFillColor(ROOT.TColor.GetColor("#12cadd"))
   W.SetFillColor(ROOT.TColor.GetColor("#de5a6a"))
   TT.SetFillColor(ROOT.TColor.GetColor("#9999cc"))
   DYB.SetFillColor(ROOT.TColor.GetColor("#4496c8"))
   DYS.SetFillColor(ROOT.TColor.GetColor("#ffcc66"))
   ggh.SetLineColor(ROOT.TColor.GetColor("#811aff"))
   qqH.SetLineColor(2)
   ggh.SetLineWidth(4)
   qqH.SetLineWidth(4)

   Data.SetMarkerStyle(20)
   Data.SetMarkerSize(1)
   QCD.SetLineColor(1)
   W.SetLineColor(1)
   TT.SetLineColor(1)
   DYS.SetLineColor(1)
   DYB.SetLineColor(1)
   VV.SetLineColor(1)
   Data.SetLineColor(1)
   Data.SetLineWidth(2)

   errorBand=file.Get(categories[i]).Get("QCD").Clone()
   errorBandVV=file.Get(categories[i]).Get("VV").Clone()
   errorBandTT=file.Get(categories[i]).Get("TT").Clone()
   errorBandW=file.Get(categories[i]).Get("W").Clone()
   errorBandDYB=file.Get(categories[i]).Get("ZL").Clone()
   errorBandDYS=file.Get(categories[i]).Get("ZTT").Clone()

   print errorBandVV.Integral(),errorBandTT.Integral(),errorBandW.Integral(),errorBandDYB.Integral(),errorBandDYS.Integral()
   print VV.Integral(),TT.Integral(),W.Integral()
   errorBand.Add(errorBandVV)
   errorBand.Add(errorBandTT)
   errorBand.Add(errorBandW)
   errorBand.Add(errorBandDYB)
   errorBand.Add(errorBandDYS)

   #errorBand.Add(VV)
   #errorBand.Add(W)
   #errorBand.Add(DYB)
   #errorBand.Add(DYS)
   #errorBand.Add(TT)

   stack=ROOT.THStack("stack","stack")
   stack.Add(QCD)
   stack.Add(W)
   stack.Add(VV)
   stack.Add(TT)
   stack.Add(DYB)
   stack.Add(DYS)

   errorBand.SetMarkerSize(0)
   errorBand.SetFillColor(new_idx)
   errorBand.SetFillStyle(3001)
   errorBand.SetLineWidth(1)

   pad1 = ROOT.TPad("pad1","pad1",0,0.35,1,1)
   pad1.Draw()
   pad1.cd()
   pad1.SetFillColor(0)
   pad1.SetBorderMode(0)
   pad1.SetBorderSize(10)
   pad1.SetTickx(1)
   pad1.SetTicky(1)
   pad1.SetLeftMargin(0.18)
   pad1.SetRightMargin(0.05)
   pad1.SetTopMargin(0.122)
   pad1.SetBottomMargin(0.026)
   pad1.SetFrameFillStyle(0)
   pad1.SetFrameLineStyle(0)
   pad1.SetFrameLineWidth(3)
   pad1.SetFrameBorderMode(0)
   pad1.SetFrameBorderSize(10)

   Data.GetXaxis().SetLabelSize(0)
   Data.SetMaximum(Data.GetMaximum()*1.35)
   for k in range(1,Data.GetSize()-1):
        s=qqH.GetBinContent(k)+ggh.GetBinContent(k)
        b=VV.GetBinContent(k)+DYS.GetBinContent(k)+DYB.GetBinContent(k)+W.GetBinContent(k)+QCD.GetBinContent(k)+TT.GetBinContent(k)+0.0000001
        if (b<0):
            b=0.000001
        if (10*s/((b+0.09*b*0.09*b)**0.5) > 0.5):
            Data.SetBinContent(k,-1)
            Data.SetBinError(k,-1)
   Data.SetMinimum(0)
   Data.Draw("e")
   stack.Draw("histsame")
   errorBand.Draw("e2same")
   qqH.Scale(1)
   ggh.Scale(1)
   qqH.Draw("histsame")
   ggh.Draw("histsame")
   Data.Draw("esame")

   legende=make_legend()
   legende.AddEntry(Data,"Observed","elp")
   legende.AddEntry(DYS,"Z#rightarrow#tau_{#mu}#tau_{h}","f")
   legende.AddEntry(DYB,"DY others","f")
   legende.AddEntry(TT,"t#bar{t}+jets","f")
   legende.AddEntry(VV,"Diboson","f")
   legende.AddEntry(W,"Electroweak","f")
   legende.AddEntry(QCD,"QCD multijet","f")
   legende.AddEntry(qqH,"qqH 125 (X1)","l")
   legende.AddEntry(ggh,"ggh 125 (X1)","l")
   legende.AddEntry(errorBand,"Uncertainty","f")
   legende.Draw()

   l1=add_lumi()
   l1.Draw("same")
   l2=add_CMS()
   l2.Draw("same")
   l3=add_Preliminary()
   l3.Draw("same")
 
   pad1.RedrawAxis()

   categ  = ROOT.TPaveText(0.21, 0.5+0.013, 0.43, 0.70+0.155, "NDC")
   categ.SetBorderSize(   0 )
   categ.SetFillStyle(    0 )
   categ.SetTextAlign(   12 )
   categ.SetTextSize ( 0.06 )
   categ.SetTextColor(    1 )
   categ.SetTextFont (   41 )
   if i==0 or i==1: 
    categ.AddText("0-jet")
   elif i==2 or i==3 :
    categ.AddText("1-jet")
   elif i==4 or i==5 :
    categ.AddText("2-jet")
   categ.Draw("same")

   c.cd()
   pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
   pad2.SetTopMargin(0.05);
   pad2.SetBottomMargin(0.35);
   pad2.SetLeftMargin(0.18);
   pad2.SetRightMargin(0.05);
   pad2.SetTickx(1)
   pad2.SetTicky(1)
   pad2.SetFrameLineWidth(3)
   pad2.SetGridx()
   pad2.SetGridy()
   pad2.Draw()
   pad2.cd()
   h1=Data.Clone()
   h1.SetMaximum(1.5)#FIXME(1.5)
   h1.SetMinimum(0.5)#FIXME(0.5)
   h1.SetMarkerStyle(20)
   h3=errorBand.Clone()
   hwoE=errorBand.Clone()
   for iii in range (1,hwoE.GetSize()-2):
     hwoE.SetBinError(iii,0)
   h3.Sumw2()
   h1.Sumw2()
   h1.SetStats(0)
   h1.Divide(hwoE)
   h3.Divide(hwoE)
   h1.GetXaxis().SetTitle("m_{#tau#tau} (GeV)")#(#vec{p_{T}(#mu)}+#vec{p_{T}(#tau)})/(p_{T}(#mu)+p_{T}(#tau))")
   #h1.GetXaxis().SetTitle("N_{charged}")
   h1.GetXaxis().SetLabelSize(0.08)
   h1.GetYaxis().SetLabelSize(0.08)
   h1.GetYaxis().SetTitle("Obs./Exp.")
   h1.GetXaxis().SetNdivisions(505)
   h1.GetYaxis().SetNdivisions(5)

   h1.GetXaxis().SetTitleSize(0.15)
   h1.GetYaxis().SetTitleSize(0.15)
   h1.GetYaxis().SetTitleOffset(0.56)
   h1.GetXaxis().SetTitleOffset(1.04)
   h1.GetXaxis().SetLabelSize(0.11)
   h1.GetYaxis().SetLabelSize(0.11)
   h1.GetXaxis().SetTitleFont(42)
   h1.GetYaxis().SetTitleFont(42)

   h1.Draw("ep")
   h3.Draw("e2same")

   c.cd()
   pad1.Draw()

   ROOT.gPad.RedrawAxis()

   c.Modified()
   c.SaveAs("mvis_"+categories[i]+".pdf")
   c.SaveAs("mvis_"+categories[i]+".png")


