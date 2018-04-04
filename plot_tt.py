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
    lumi.AddText("2016, 35.9 fb^{-1} (13 TeV)")
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
        output = ROOT.TLegend(0.70, 0.40, 0.92, 0.84, "", "brNDC")
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

file=ROOT.TFile("final_nominal.root","r")

adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)

categories=["ttOS"]#,"ttSS"]#,"AIOS","AISS"] 
ncat = 1


for i in range (0,ncat):
   Data=file.Get(categories[i]).Get("data_obs")
   VV=file.Get(categories[i]).Get("VV")
   #ZZ=file.Get(categories[i]).Get("ZZ")
   #WZ=file.Get(categories[i]).Get("WZ")
   DY=file.Get(categories[i]).Get("DY")
   TT=file.Get(categories[i]).Get("TT")
   QCD=file.Get(categories[i]).Get("QCD")
   SMH=file.Get(categories[i]).Get("SMH")
   W=file.Get(categories[i]).Get("W")
   SMH.Scale(5)
   #ZH=file.Get(categories[i]).Get("ZH125")

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

   VV.SetFillColor(ROOT.TColor.GetColor("#11e7ae"))
   #WZ.SetFillColor(ROOT.TColor.GetColor("#efe7ae"))
   #ZZ.SetFillColor(ROOT.TColor.GetColor("#11e7ae"))
   QCD.SetFillColor(ROOT.TColor.GetColor("#a278aa"))
   DY.SetFillColor(ROOT.TColor.GetColor("#4567f1"))
   TT.SetFillColor(ROOT.TColor.GetColor("#g14d16"))
   W.SetFillColor(ROOT.TColor.GetColor("#efe7ae"))

   SMH.SetLineWidth(4)

   Data.SetMarkerStyle(20)
   Data.SetLineColor(1)
   Data.SetMarkerSize(1)
   QCD.SetLineColor(1)
   VV.SetLineColor(1)
   #WZ.SetLineColor(1)
   #ZZ.SetLineColor(1)
   DY.SetLineColor(1)
   TT.SetLineColor(1)
   W.SetLineColor(1)

   #errorBand=file.Get(categories[i]).Get("VV").Clone()
   errorBand=file.Get(categories[i]).Get("DY").Clone()
   #errorBand.Add(ZZ)
   errorBand.Add(VV)
   #errorBand.Add(DY)
   errorBand.Add(TT)
   errorBand.Add(W)
   errorBand.Add(QCD)

   stack=ROOT.THStack("stack","stack")
   stack.Add(QCD)
   stack.Add(TT)
   stack.Add(VV)
   stack.Add(W)
   #stack.Add(WZ)
   #stack.Add(ZZ)
   stack.Add(DY)

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
   Data.SetMaximum(32000)#max(Data.GetMaximum()*1.35,stack.GetMaximum()*1.35)) #32000
   for k in range(1,Data.GetSize()-1):
        s=SMH.GetBinContent(k)
        data1=Data.GetBinContent(k)
        #b=VV.GetBinContent(k)+Fake.GetBinContent(k)
        #b=ZZ.GetBinContent(k)+Fake.GetBinContent(k)+WZ.GetBinContent(k)
        #if (b<0):
        #    b=0.000001
        #if (s/(0.00001+0.2*s+b)**0.5 > 0.8):
        #    Data.SetBinContent(k,-1)
        #    Data.SetBinError(k,-1)
   Data.SetMinimum(0)
   Data.SetMaximum(1.3*Data.GetMaximum()) #1.3
   Data.Draw("e")
   stack.Draw("histsame")
   errorBand.Draw("e2same")
   SMH.Draw("histsame")
   Data.Draw("esame")

   legende=make_legend()
   legende.AddEntry(Data,"Observed","elp")
   legende.AddEntry(TT,"TT","f")
   legende.AddEntry(W,"W","f")
   #legende.AddEntry(WZ,"WZ","f")
   #legende.AddEntry(ZZ,"ZZ","f")
   legende.AddEntry(VV,"VV","f")
   legende.AddEntry(DY,"DY","f")
   legende.AddEntry(QCD,"QCD","f")
   legende.AddEntry(SMH,"SMH (x5)","l")
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
   categ.SetTextFont (   42 )
   if i+1==1:       
     categ.AddText("OS")
   elif i+1==2:       
     categ.AddText("SS")
   categ.Draw()

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
   h1.SetMinimum(0.1)#FIXME(0.5)
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
   h1.GetXaxis().SetTitle("Higgs p_{T} [GeV]")#1:well matched, 3:sub is not from H, 4:leading is not from W")#("p_{T,vis} (GeV)")#("p_{T}(#mu_{2}) (GeV)")
   #("m_{vis} (GeV)")#(#vec{p_{T}}(#tau_{1})+#vec{p_{T}}(#tau_{2}))/(p_{T}(#tau_{1})+p_{T}(#tau_{2}))")#("m_{vis} (GeV)")#(#vec{p_{T}(#mu)}+#vec{p_{T}(#tau)})/(p_{T}(#mu)+p_{T}(#tau))")
   #if (i+1==1 or i+1==2 or i+1==7 or i+1==8):
   #	h1.GetXaxis().SetTitle("Electron p_{T} (GeV)")
   #if (i+1==4 or i+1==10):
   #     h1.GetXaxis().SetTitle("Muon p_{T} (GeV)")
   #if (i+1==6 or i+1==12 or i+1==3 or i+1==5 or i+1==9 or i+1==11):
   #     h1.GetXaxis().SetTitle("Tau p_{T} (GeV)")
   h1.GetXaxis().SetLabelSize(0.08)
   h1.GetYaxis().SetLabelSize(0.08)
   h1.GetYaxis().SetTitle("Obs./Exp.")
   h1.GetXaxis().SetNdivisions(505)
   h1.GetYaxis().SetNdivisions(5)

   h1.GetXaxis().SetTitleSize(0.15)
   h1.GetYaxis().SetTitleSize(0.15)#(0.15)
   h1.GetYaxis().SetTitleOffset(0.56)
   h1.GetXaxis().SetTitleOffset(1.04)
   h1.GetXaxis().SetLabelSize(0.11)
   h1.GetYaxis().SetLabelSize(0.11)
   h1.GetXaxis().SetTitleFont(42)
   h1.GetYaxis().SetTitleFont(42)

   h1.Draw("e0p")
   h3.Draw("e2same")

   print "integral : ", h3.Integral(9,10)

   c.cd()
   pad1.Draw()

   ROOT.gPad.RedrawAxis()

   c.Modified()
   c.SaveAs("htt_"+categories[i]+".pdf")
   #c.SaveAs("wh_mmt_"+categories[i]+".png")


