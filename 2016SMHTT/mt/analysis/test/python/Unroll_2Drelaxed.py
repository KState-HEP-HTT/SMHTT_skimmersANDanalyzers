#!/usr/bin/env python
import ROOT
import re
from array import array

islog=1

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

file=ROOT.TFile("final_mutau_2D.root","r")
file1D=ROOT.TFile("final_mutau_1D.root","recreate")

adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)

categories=["mt_0jet","mt_1jet","mt_vbf"] 
cat=["mt_0jet","mt_1jet","mt_vbf"]
ncat=3

for i in range (0,ncat):
   Data2D=file.Get(categories[i]).Get("data_obs")
   QCD2D=file.Get(categories[i]).Get("QCD")
   W2D=file.Get(categories[i]).Get("W") 
   TT2D=file.Get(categories[i]).Get("TT")
   VV2D=file.Get(categories[i]).Get("VV")
   DYB2D=file.Get(categories[i]).Get("ZLL")
   DYS2D=file.Get(categories[i]).Get("ZTT")
   qqH2D=file.Get(categories[i]).Get("qqH125")
   ggh2D=file.Get(categories[i]).Get("ggH125")
   qqH1302D=file.Get(categories[i]).Get("qqH130")
   ggh1302D=file.Get(categories[i]).Get("ggH130")
   qqH1202D=file.Get(categories[i]).Get("qqH120")
   ggh1202D=file.Get(categories[i]).Get("ggH120")

   QCD2D_d=file.Get(categories[i]).Get("QCD_TESDown")
   W2D_d=file.Get(categories[i]).Get("W_TESDown")
   TT2D_d=file.Get(categories[i]).Get("TT_TESDown")
   VV2D_d=file.Get(categories[i]).Get("VV_TESDown")
   DYB2D_d=file.Get(categories[i]).Get("ZLL_TESDown")
   DYS2D_d=file.Get(categories[i]).Get("ZTT_TESDown")
   qqH2D_d=file.Get(categories[i]).Get("qqH125_TESDown")
   ggh2D_d=file.Get(categories[i]).Get("ggH125_TESDown")
   qqH1302D_d=file.Get(categories[i]).Get("qqH130_TESDown")
   ggh1302D_d=file.Get(categories[i]).Get("ggH130_TESDown")
   qqH1202D_d=file.Get(categories[i]).Get("qqH120_TESDown")
   ggh1202D_d=file.Get(categories[i]).Get("ggH120_TESDown")

   QCD2D_u=file.Get(categories[i]).Get("QCD_TESUp")
   W2D_u=file.Get(categories[i]).Get("W_TESUp")
   TT2D_u=file.Get(categories[i]).Get("TT_TESUp")
   VV2D_u=file.Get(categories[i]).Get("VV_TESUp")
   DYB2D_u=file.Get(categories[i]).Get("ZLL_TESUp")
   DYS2D_u=file.Get(categories[i]).Get("ZTT_TESUp")
   qqH2D_u=file.Get(categories[i]).Get("qqH125_TESUp")
   ggh2D_u=file.Get(categories[i]).Get("ggH125_TESUp")
   qqH1302D_u=file.Get(categories[i]).Get("qqH130_TESUp")
   ggh1302D_u=file.Get(categories[i]).Get("ggH130_TESUp")
   qqH1202D_u=file.Get(categories[i]).Get("qqH120_TESUp")
   ggh1202D_u=file.Get(categories[i]).Get("ggH120_TESUp")

   nx=Data2D.GetXaxis().GetNbins()
   ny=Data2D.GetYaxis().GetNbins()

   Data=ROOT.TH1F("data_obs","data_obs",nx*ny,0,nx*ny)
   QCD=ROOT.TH1F("QCD","QCD",nx*ny,0,nx*ny)
   W=ROOT.TH1F("W","W",nx*ny,0,nx*ny)
   TT=ROOT.TH1F("TT","TT",nx*ny,0,nx*ny)
   VV=ROOT.TH1F("VV","VV",nx*ny,0,nx*ny)
   DYB=ROOT.TH1F("ZLL","ZLL",nx*ny,0,nx*ny)
   DYS=ROOT.TH1F("ZTT","ZTT",nx*ny,0,nx*ny)
   qqH=ROOT.TH1F("qqH125","qqH125",nx*ny,0,nx*ny)
   ggh=ROOT.TH1F("ggH125","ggH125",nx*ny,0,nx*ny)
   qqH120=ROOT.TH1F("qqH120","qqH120",nx*ny,0,nx*ny)
   ggh120=ROOT.TH1F("ggH120","ggH120",nx*ny,0,nx*ny)
   qqH130=ROOT.TH1F("qqH130","qqH130",nx*ny,0,nx*ny)
   ggh130=ROOT.TH1F("ggH130","ggH130",nx*ny,0,nx*ny)

   QCD_u=ROOT.TH1F("QCD_TESUp","QCD_TESUp",nx*ny,0,nx*ny)
   W_u=ROOT.TH1F("W_TESUp","W_TESUp",nx*ny,0,nx*ny)
   TT_u=ROOT.TH1F("TT_TESUp","TT_TESUp",nx*ny,0,nx*ny)
   VV_u=ROOT.TH1F("VV_TESUp","VV_TESUp",nx*ny,0,nx*ny)
   DYB_u=ROOT.TH1F("ZLL_TESUp","ZLL_TESUp",nx*ny,0,nx*ny)
   DYS_u=ROOT.TH1F("ZTT_TESUp","ZTT_TESUp",nx*ny,0,nx*ny)
   qqH_u=ROOT.TH1F("qqH125_TESUp","qqH125_TESUp",nx*ny,0,nx*ny)
   ggh_u=ROOT.TH1F("ggH125_TESUp","ggH125_TESUp",nx*ny,0,nx*ny)
   qqH120_u=ROOT.TH1F("qqH120_TESUp","qqH120_TESUp",nx*ny,0,nx*ny)
   ggh120_u=ROOT.TH1F("ggH120_TESUp","ggH120_TESUp",nx*ny,0,nx*ny)
   qqH130_u=ROOT.TH1F("qqH130_TESUp","qqH130_TESUp",nx*ny,0,nx*ny)
   ggh130_u=ROOT.TH1F("ggH130_TESUp","ggH130_TESUp",nx*ny,0,nx*ny)

   QCD_d=ROOT.TH1F("QCD_TESDown","QCD_TESDown",nx*ny,0,nx*ny)
   W_d=ROOT.TH1F("W_TESDown","W_TESDown",nx*ny,0,nx*ny)
   TT_d=ROOT.TH1F("TT_TESDown","TT_TESDown",nx*ny,0,nx*ny)
   VV_d=ROOT.TH1F("VV_TESDown","VV_TESDown",nx*ny,0,nx*ny)
   DYB_d=ROOT.TH1F("ZLL_TESDown","ZLL_TESDown",nx*ny,0,nx*ny)
   DYS_d=ROOT.TH1F("ZTT_TESDown","ZTT_TESDown",nx*ny,0,nx*ny)
   qqH_d=ROOT.TH1F("qqH125_TESDown","qqH125_TESDown",nx*ny,0,nx*ny)
   ggh_d=ROOT.TH1F("ggH125_TESDown","ggH125_TESDown",nx*ny,0,nx*ny)
   qqH120_d=ROOT.TH1F("qqH120_TESDown","qqH120_TESDown",nx*ny,0,nx*ny)
   ggh120_d=ROOT.TH1F("ggH120_TESDown","ggH120_TESDown",nx*ny,0,nx*ny)
   qqH130_d=ROOT.TH1F("qqH130_TESDown","qqH130_TESDown",nx*ny,0,nx*ny)
   ggh130_d=ROOT.TH1F("ggH130_TESDown","ggH130_TESDown",nx*ny,0,nx*ny)

   l=0
   for j in range(1,nx+1):
     for k in range(1,ny+1):
	l=l+1
        n = Data2D.GetBin(j,k);
	Data.SetBinContent(l,Data2D.GetBinContent(n))
        QCD.SetBinContent(l,QCD2D.GetBinContent(n))
        W.SetBinContent(l,W2D.GetBinContent(n))
        TT.SetBinContent(l,TT2D.GetBinContent(n))
        VV.SetBinContent(l,VV2D.GetBinContent(n))
        DYB.SetBinContent(l,DYB2D.GetBinContent(n))
        DYS.SetBinContent(l,DYS2D.GetBinContent(n))
        qqH.SetBinContent(l,qqH2D.GetBinContent(n))
        ggh.SetBinContent(l,ggh2D.GetBinContent(n))
        qqH120.SetBinContent(l,qqH1202D.GetBinContent(n))
        ggh120.SetBinContent(l,ggh1202D.GetBinContent(n))
        qqH130.SetBinContent(l,qqH1302D.GetBinContent(n))
        ggh130.SetBinContent(l,ggh1302D.GetBinContent(n))
        Data.SetBinError(l,Data2D.GetBinError(n))
        QCD.SetBinError(l,QCD2D.GetBinError(n))
        W.SetBinError(l,W2D.GetBinError(n))
        TT.SetBinError(l,TT2D.GetBinError(n))
        VV.SetBinError(l,VV2D.GetBinError(n))
        DYB.SetBinError(l,DYB2D.GetBinError(n))
        DYS.SetBinError(l,DYS2D.GetBinError(n))
        qqH.SetBinError(l,qqH2D.GetBinError(n))
        ggh.SetBinError(l,ggh2D.GetBinError(n))
        qqH120.SetBinError(l,qqH1202D.GetBinError(n))
        ggh120.SetBinError(l,ggh1202D.GetBinError(n))
        qqH130.SetBinError(l,qqH1302D.GetBinError(n))
        ggh130.SetBinError(l,ggh1302D.GetBinError(n))

        QCD_d.SetBinContent(l,QCD2D_d.GetBinContent(n))
        W_d.SetBinContent(l,W2D_d.GetBinContent(n))
        TT_d.SetBinContent(l,TT2D_d.GetBinContent(n))
        VV_d.SetBinContent(l,VV2D_d.GetBinContent(n))
        DYB_d.SetBinContent(l,DYB2D_d.GetBinContent(n))
        DYS_d.SetBinContent(l,DYS2D_d.GetBinContent(n))
        qqH_d.SetBinContent(l,qqH2D_d.GetBinContent(n))
        ggh_d.SetBinContent(l,ggh2D_d.GetBinContent(n))
        qqH120_d.SetBinContent(l,qqH1202D_d.GetBinContent(n))
        ggh120_d.SetBinContent(l,ggh1202D_d.GetBinContent(n))
        qqH130_d.SetBinContent(l,qqH1302D_d.GetBinContent(n))
        ggh130_d.SetBinContent(l,ggh1302D_d.GetBinContent(n))
        QCD_d.SetBinError(l,QCD2D_d.GetBinError(n))
        W_d.SetBinError(l,W2D_d.GetBinError(n))
        TT_d.SetBinError(l,TT2D_d.GetBinError(n))
        VV_d.SetBinError(l,VV2D_d.GetBinError(n))
        DYB_d.SetBinError(l,DYB2D_d.GetBinError(n))
        DYS_d.SetBinError(l,DYS2D_d.GetBinError(n))
        qqH_d.SetBinError(l,qqH2D_d.GetBinError(n))
        ggh_d.SetBinError(l,ggh2D_d.GetBinError(n))
        qqH120_d.SetBinError(l,qqH1202D_d.GetBinError(n))
        ggh120_d.SetBinError(l,ggh1202D_d.GetBinError(n))
        qqH130_d.SetBinError(l,qqH1302D_d.GetBinError(n))
        ggh130_d.SetBinError(l,ggh1302D_d.GetBinError(n))

        QCD_u.SetBinContent(l,QCD2D_u.GetBinContent(n))
        W_u.SetBinContent(l,W2D_u.GetBinContent(n))
        TT_u.SetBinContent(l,TT2D_u.GetBinContent(n))
        VV_u.SetBinContent(l,VV2D_u.GetBinContent(n))
        DYB_u.SetBinContent(l,DYB2D_u.GetBinContent(n))
        DYS_u.SetBinContent(l,DYS2D_u.GetBinContent(n))
        qqH_u.SetBinContent(l,qqH2D_u.GetBinContent(n))
        ggh_u.SetBinContent(l,ggh2D_u.GetBinContent(n))
        qqH120_u.SetBinContent(l,qqH1202D_u.GetBinContent(n))
        ggh120_u.SetBinContent(l,ggh1202D_u.GetBinContent(n))
        qqH130_u.SetBinContent(l,qqH1302D_u.GetBinContent(n))
        ggh130_u.SetBinContent(l,ggh1302D_u.GetBinContent(n))
        QCD_u.SetBinError(l,QCD2D_u.GetBinError(n))
        W_u.SetBinError(l,W2D_u.GetBinError(n))
        TT_u.SetBinError(l,TT2D_u.GetBinError(n))
        VV_u.SetBinError(l,VV2D_u.GetBinError(n))
        DYB_u.SetBinError(l,DYB2D_u.GetBinError(n))
        DYS_u.SetBinError(l,DYS2D_u.GetBinError(n))
        qqH_u.SetBinError(l,qqH2D_u.GetBinError(n))
        ggh_u.SetBinError(l,ggh2D_u.GetBinError(n))
        qqH120_u.SetBinError(l,qqH1202D_u.GetBinError(n))
        ggh120_u.SetBinError(l,ggh1202D_u.GetBinError(n))
        qqH130_u.SetBinError(l,qqH1302D_u.GetBinError(n))
        ggh130_u.SetBinError(l,ggh1302D_u.GetBinError(n))

   mydir=file1D.mkdir(cat[i])
   mydir.cd()
   Data.Write()
   QCD.Write()
   DYB.Write()
   DYS.Write()
   W.Write()
   VV.Write()
   TT.Write()
   ggh.Write()
   qqH.Write()
   ggh120.Write()
   qqH120.Write()
   ggh130.Write()
   qqH130.Write()
   QCD_u.Write()
   DYB_u.Write()
   DYS_u.Write()
   W_u.Write()
   VV_u.Write()
   TT_u.Write()
   ggh_u.Write()
   qqH_u.Write()
   ggh120_u.Write()
   qqH120_u.Write()
   ggh130_u.Write()
   qqH130_u.Write()
   QCD_d.Write()
   DYB_d.Write()
   DYS_d.Write()
   W_d.Write()
   VV_d.Write()
   TT_d.Write()
   ggh_d.Write()
   qqH_d.Write()
   ggh120_d.Write()
   qqH120_d.Write()
   ggh130_d.Write()
   qqH130_d.Write()



   Data.GetXaxis().SetTitle("")
   Data.GetXaxis().SetTitleSize(0)
   Data.GetXaxis().SetNdivisions(505)
   Data.GetYaxis().SetLabelFont(42)
   Data.GetYaxis().SetLabelOffset(0.01)
   Data.GetYaxis().SetLabelSize(0.06)
   Data.GetYaxis().SetTitleSize(0.075)
   Data.GetYaxis().SetTitleOffset(0.56)
   Data.SetTitle("")
   Data.GetYaxis().SetTitle("Events/bin")

   QCD.SetFillColor(ROOT.TColor.GetColor("#ffccff"))
   VV.SetFillColor(ROOT.TColor.GetColor("#12cadd"))
   W.SetFillColor(ROOT.TColor.GetColor("#de5a6a"))
   TT.SetFillColor(ROOT.TColor.GetColor("#9999cc"))
   DYB.SetFillColor(ROOT.TColor.GetColor("#4496c8"))
   DYS.SetFillColor(ROOT.TColor.GetColor("#ffcc66"))
   ggh.SetLineColor(ROOT.TColor.GetColor("#5911ff"))
   qqH.SetLineColor(ROOT.TColor.GetColor("#4faf4e"))
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

   errorBand=QCD.Clone()
   errorBand.Add(VV)
   errorBand.Add(TT)
   errorBand.Add(W)
   errorBand.Add(DYB)
   errorBand.Add(DYS)

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
   pad1.SetLeftMargin(0.10)
   pad1.SetRightMargin(0.05)
   pad1.SetTopMargin(0.122)
   pad1.SetBottomMargin(0.026)
   pad1.SetFrameFillStyle(0)
   pad1.SetFrameLineStyle(0)
   pad1.SetFrameLineWidth(3)
   pad1.SetFrameBorderMode(0)
   pad1.SetFrameBorderSize(10)
   if islog:
     pad1.SetLogy()

   Data.GetXaxis().SetLabelSize(0)
   Data.SetMaximum(Data.GetMaximum()*1.35)
   Data.SetMinimum(0.0)
   if islog:
      Data.SetMaximum(Data.GetMaximum()*5.35)
      Data.SetMinimum(0.01)
   for k in range(1,Data.GetSize()-1):
        s=qqH.GetBinContent(k)+ggh.GetBinContent(k)
        b=VV.GetBinContent(k)+DYS.GetBinContent(k)+DYB.GetBinContent(k)+W.GetBinContent(k)+QCD.GetBinContent(k)+TT.GetBinContent(k)+0.0000001
        if (b<0):
            b=0.000001
        #if (s/((b+0.09*b*0.09*b)**0.5) > 0.5):
	if (s/((s+b)**0.5) > 0.2):
            Data.SetBinContent(k,100000000)
            Data.SetBinError(k,100000000)
   Data.Draw("e")
   stack.Draw("histsame")
   errorBand.Draw("e2same")
   qqH.Scale(100)
   ggh.Scale(100)
   qqH.Draw("histsame")
   ggh.Draw("histsame")
   Data.Draw("esame")


   pthbins=[0,60,100,140,180,220]
   mjjbins=[300,600,900,1200,1700]
   tauptbins=[30,35,40,45,50,55]
   line=[]
   label=[]
   for z in range(1,nx):
      line.append(ROOT.TLine(z*ny,0,z*ny,Data.GetMaximum()))
      line[z-1].SetLineStyle(3)
      line[z-1].Draw("same")
   for z in range(1,nx+1):
      posx=0.11+0.85*(z-1)/nx
      label.append(ROOT.TPaveText(posx, 0.73, posx+0.15, 0.73+0.155, "NDC"))
      if i==0:
         label[z-1].AddText("p_{T}(#tau_{h}) > "+str(tauptbins[z-1])+" GeV")
      if i==1:
         label[z-1].AddText("p_{T}(H) > "+str(pthbins[z-1])+" GeV")
      if i==2:
         label[z-1].AddText("m_{jj} > "+str(mjjbins[z-1])+" GeV")
      label[z-1].SetBorderSize(   0 )
      label[z-1].SetFillStyle(    0 )
      label[z-1].SetTextAlign(   12 )
      label[z-1].SetTextSize ( 0.06 )
      label[z-1].SetTextColor(    1 )
      label[z-1].SetTextFont (   42 )
      label[z-1].Draw("same")

   legende=make_legend()
   legende.AddEntry(Data,"Observed","elp")
   legende.AddEntry(DYS,"Z#rightarrow#tau_{#mu}#tau_{h}","f")
   legende.AddEntry(DYB,"DY others","f")
   legende.AddEntry(TT,"t#bar{t}+jets","f")
   legende.AddEntry(VV,"Diboson","f")
   legende.AddEntry(W,"Electroweak","f")
   legende.AddEntry(QCD,"QCD multijet","f")
   legende.AddEntry(qqH,"qqH 125 (X100)","l")
   legende.AddEntry(ggh,"ggh 125 (X100)","l")
   legende.AddEntry(errorBand,"Stat. uncertainty","f")
   legende.Draw()

   l1=add_lumi()
   l1.Draw("same")
   l2=add_CMS()
   l2.Draw("same")
   l3=add_Preliminary()
   l3.Draw("same")
 
   pad1.RedrawAxis()

   categ  = ROOT.TPaveText(0.45, 0.865, 0.60, 0.865+0.155, "NDC")
   categ.SetBorderSize(   0 )
   categ.SetFillStyle(    0 )
   categ.SetTextAlign(   12 )
   categ.SetTextSize ( 0.08 )
   categ.SetTextColor(    1 )
   categ.SetTextFont (   42 )
   if i==0: 
    categ.AddText("#mu#tau_{h}, no jet")
   elif i==1:
    categ.AddText("#mu#tau_{h}, boosted")
   elif i==2:
    categ.AddText("#mu#tau_{h}, VBF")
   categ.Draw("same")

   c.cd()
   pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
   pad2.SetTopMargin(0.05);
   pad2.SetBottomMargin(0.35);
   pad2.SetLeftMargin(0.10);
   pad2.SetRightMargin(0.05);
   pad2.SetTickx(1)
   pad2.SetTicky(1)
   pad2.SetFrameLineWidth(3)
   #pad2.SetGridx()
   pad2.SetGridy()
   pad2.Draw()
   pad2.cd()
   h1=Data.Clone()
   h1.SetMaximum(1.6)#FIXME(1.5)
   h1.SetMinimum(0.4)#FIXME(0.5)
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
   h1.GetXaxis().SetTitle("2D bin number")#(#vec{p_{T}(#mu)}+#vec{p_{T}(#tau)})/(p_{T}(#mu)+p_{T}(#tau))")
   #h1.GetXaxis().SetTitle("N_{charged}")
   h1.GetXaxis().SetLabelSize(0.08)
   h1.GetYaxis().SetLabelSize(0.08)
   h1.GetYaxis().SetTitle("Obs./Exp.")
   h1.GetXaxis().SetNdivisions(505)
   h1.GetYaxis().SetNdivisions(5)

   h1.GetXaxis().SetTitleSize(0.15)
   h1.GetYaxis().SetTitleSize(0.15)
   h1.GetYaxis().SetTitleOffset(0.26)
   h1.GetXaxis().SetTitleOffset(1.04)
   h1.GetXaxis().SetLabelSize(0.11)
   h1.GetYaxis().SetLabelSize(0.11)
   h1.GetXaxis().SetTitleFont(42)
   h1.GetYaxis().SetTitleFont(42)

   h1.Draw("ep")
   h3.Draw("e2same")

   line2=[]
   for z in range(1,nx):
      line2.append(ROOT.TLine(z*ny,0.4,z*ny,1.6))
      line2[z-1].SetLineStyle(3)
      line2[z-1].Draw("same")

   c.cd()
   pad1.Draw()

   ROOT.gPad.RedrawAxis()

   c.Modified()
   if islog:
     c.SaveAs("unroll_log_"+categories[i]+".pdf")
     c.SaveAs("unroll_log_"+categories[i]+".png")
   else: 
     c.SaveAs("unroll_"+categories[i]+".pdf")
     c.SaveAs("unroll_"+categories[i]+".png")


