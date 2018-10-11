from subprocess import Popen
from sys import argv, exit, stdout, stderr

import ROOT
import numpy
from array import array

# So things don't look like crap.
ROOT.gROOT.SetStyle("Plain")
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(0)

####################################
canvas = ROOT.TCanvas("asdf", "adsf", 800, 800)

def get_histo(file, cate, histname=''):
    print '.... Finding ',histname,' histogram. If it is 2D, ProjectionX of it going to be used.'
    hist2d = file.Get("tt_"+cate+"/"+histname)
    if(hist2d.GetDimension()==2):
        hist = hist2d.ProjectionX()
    elif(hist2d.GetDimension()==1):
        hist = hist2d
    return hist

def get_eff(file,cate,histname=''):
    ''' Get the eff '''
    print '.... Getting efficiency of ', file.GetName(),' in ',cate,' category.'
    hist = get_histo(file,cate,histname)
    deno = hist.Integral()
    #print 'deno : ', deno
    eff = []
    for i in range(0,hist.GetNbinsX()):
        slice_yield=hist.Integral(hist.GetNbinsX()-i,hist.GetNbinsX())
        eff.append(slice_yield/deno)
    return eff

def produce_tgraph(fsignal,sig_histname,fztt,ztt_histname,cate,color,MarkerStyle=20):
    ''' Create a TGraph with one point(TGraph) '''
    print '.... Producing TGraph.'
    x_eff = numpy.array(get_eff(fsignal,cate,sig_histname),dtype=float)
    y_eff = numpy.array(get_eff(fztt,cate, ztt_histname),dtype=float)
    n = len(x_eff)
    print 'sig_eff : ', x_eff
    print 'bkf_eff : ', y_eff,'\n'
    tgraph = ROOT.TGraph(n,x_eff,y_eff)
    tgraph.SetMarkerStyle(MarkerStyle)
    tgraph.SetMarkerColor(color)
    tgraph.SetMarkerSize(0.5)
    return tgraph

def produce_pair(histoId, ntupleEff,ntupleFR,N,tgline):
    ''' Add a point to a roc curve (TGraph) '''
    id_Effi = get_ratio(histoId, ntupleEff)
    eff = numpy.array([id_Effi],dtype=float)
    id_FakeRate = get_ratio(histoId, ntupleFR)
    fr = numpy.array([id_FakeRate],dtype=float)
    tgline.SetPoint(N,eff,fr)

def produce_roc_curve1(f1, sig_histname, sig_title, bkg1_histname, bkg2_histname, bkg_title, title=''):#,label='roc'):
    frame = ROOT.TMultiGraph()
    frame.SetTitle(title+';'+sig_title+';'+bkg_title)
    cate = 'vbf'
    #Create TGraphs to add to the TMultiGraph
    tg1 = produce_tgraph(f1,sig_histname,f1,bkg1_histname,cate,ROOT.kBlue,20)
    tg2 = produce_tgraph(f1,sig_histname,f1,bkg2_histname,cate,ROOT.kRed,20)
    #Add the TGraphs to the TMultigraph 
    frame.Add(tg1)
    frame.Add(tg2)
    #Draw Axis,Line,Points
    frame.Draw("ALP")
    frame.GetXaxis().SetLimits(0.0,1.0);
    frame.GetHistogram().SetMinimum(0.0);
    frame.GetHistogram().SetMaximum(1.0);

    #Add Legend for the IDs
    legend = ROOT.TLegend(0.2, 0.7, 0.39, 0.8, "", "brNDC")
    legend.SetFillColor(ROOT.kWhite)
    legend.SetHeader("category","C")
    legend.SetBorderSize(0)
    legend.AddEntry(tg1,bkg1_histname,"pe")
    legend.AddEntry(tg2,bkg2_histname,"pe")
    legend.Draw()

    #Save with a specific file name
    saveas = 'plots/ROC/'+title+'_'+bkg1_histname+'.pdf'
    print saveas
    canvas.SaveAs(saveas)



def produce_roc_curve(f1, f2, sig_histname, sig_title, bkg_histname, bkg_title, type1, type2, title=''):#,label='roc'):
    frame = ROOT.TMultiGraph()
    frame.SetTitle(title+';'+sig_title+';'+bkg_title)
    cate = 'vbf'
    #Create a TGraph to draw a line behind the other points
    #tgline = 
    #produce_pair(histoId2, ntupleEff, ntupleFR, 1, tgline)
    #produce_pair(histoId3,ntupleEff, ntupleFR, 2, tgline)
    #Create TGraphs to add to the TMultiGraph
    tg1 = produce_tgraph(f1,sig_histname,f1,bkg_histname,cate,ROOT.kBlue,20)
    tg2 = produce_tgraph(f2,sig_histname,f2,bkg_histname,cate,ROOT.kRed,20)
    #tg3 = produce_tgraph(f3,sig_histname,f3,ztt_histname,cate,ROOT.kOrange,20)
    '''test = produce_tgraph(fsignal,"VBF125_MELA_VBF",fztt,"ZTT_MELA_VBF",ROOT.kBlack,20)
    c=ROOT.TCanvas("canvas","",0,0,600,600)
    c.cd()
    test.Draw()
    c.SaveAs('test.pdf') '''
    #tg2 = produce_tgraph(histoId2, ntupleEff, ntupleFR, ROOT.kRed-9, 1)
    #tg3 = produce_tgraph(histoId3, ntupleEff, ntupleFR, ROOT.kOrange-2, 1)
    #Add the TGraphs to the TMultigraph 
    #frame.Add(tgline)
    frame.Add(tg1)
    frame.Add(tg2)
    #frame.Add(tg3)
    #frame.Add(tg3)
    #Draw Axis,Line,Points
    frame.Draw("ALP")
    frame.GetXaxis().SetLimits(0.0,1.0);
    frame.GetHistogram().SetMinimum(0.0);
    frame.GetHistogram().SetMaximum(1.0);
    #frame.GetXaxis().SetLimits(0.,1.)
    #frame.GetYaxis().SetRangeUser(0.,1.)
    #Add Legend for the IDs
    legend = ROOT.TLegend(0.2, 0.7, 0.39, 0.8, "", "brNDC")
    legend.SetFillColor(ROOT.kWhite)
    #legend.SetHeader("category","C")
    legend.SetBorderSize(0)
    legend.AddEntry(tg1,type1,"pe")
    legend.AddEntry(tg2,type2,"pe")
    #legend.AddEntry(tg3,type3,"pe")
    #legend.AddEntry(tg3,legend3,"pe")
    legend.Draw()
    #Save with a specific file name
    saveas = 'plots/ROC/'+title+bkg_histname+'.pdf'
    canvas.SaveAs(saveas)
    print saveas,'----------------------------------------------------- \n\n\n'

def CMSstyle():
    ROOT.gROOT.SetStyle("Plain")
    cmsStyle = ROOT.TStyle("CMS","CMS approved plots style")
    cmsStyle.SetFrameBorderMode(0)
    cmsStyle.SetCanvasBorderMode(0)
    cmsStyle.SetPadBorderMode(0)
    cmsStyle.SetPadColor(0)
    cmsStyle.SetCanvasColor(0)
    cmsStyle.SetTitleColor(1)
    cmsStyle.SetStatColor(0)
    cmsStyle.SetFrameFillColor(0)

    # set the paper & margin sizes
    cmsStyle.SetPaperSize(20,26)
    cmsStyle.SetPadTopMargin(0.05)
    cmsStyle.SetPadRightMargin(0.05)
    cmsStyle.SetPadBottomMargin(0.15)
    cmsStyle.SetPadLeftMargin(0.15)
    
    # use large Times-Roman fonts
    cmsStyle.SetTextFont(132)
    cmsStyle.SetTextSize(0.08)
    cmsStyle.SetLabelFont(132,"x")
    cmsStyle.SetLabelFont(132,"y")
    cmsStyle.SetLabelFont(132,"z")
    cmsStyle.SetTitleFont(132,"x")
    cmsStyle.SetTitleFont(132,"y")
    cmsStyle.SetTitleFont(132,"z")
    
    cmsStyle.SetLabelSize(0.05,"x")
    cmsStyle.SetLabelSize(0.05,"y")
    cmsStyle.SetLabelSize(0.05,"z")
  
    cmsStyle.SetTitleSize(0.06,"x")
    cmsStyle.SetTitleSize(0.06,"y")
    cmsStyle.SetTitleSize(0.06,"z")

    # use bold lines and markers
    cmsStyle.SetMarkerStyle(8)
    cmsStyle.SetLineStyleString(2,"[12 12]") # postscript dashes

    # do not display any of the standard histogram decorations
    cmsStyle.SetOptTitle(1)
    cmsStyle.SetOptStat(1)
    cmsStyle.SetOptFit(1)

    # put tick marks on top and RHS of plots
    cmsStyle.SetPadTickX(1)
    #cmsStyle.ROOT.ePadTickY(1)
    ROOT.gROOT.SetStyle("CMS")
    ROOT.gROOT.ForceStyle()
    return 



def produce_ratio(file,var,cate,histname_sig='',histname_ztt=''):    
    CMSstyle()
    canvas2 = ROOT.TCanvas("","",0,0,600,650)
    #ROOT.gStyle.SetFrameBorderMode(0)
    #ROOT.gStyle.SetCanvasBorderMode(0)
    ROOT.gStyle.SetFrameLineWidth(2)
    ROOT.gStyle.SetOptTitle(0)
    #ROOT.gROOT.SetStyle("Plain")
    ROOT.gROOT.SetBatch(True)
    ROOT.gStyle.SetOptStat(0)
    ROOT.gStyle.SetPadTickX(1)
    ROOT.gStyle.SetPadTickY(1)
    canvas2.cd()
    pad1 = ROOT.TPad("","",0.05,0.3,1.0,0.99)
    pad1.Draw()
    pad2 = ROOT.TPad("","",0.05,0.0,1.0,0.405)
    pad2.Draw()
    pad2.SetTopMargin(0.00)
    pad2.SetBottomMargin(0.25)
    pad2.SetGridy()

    h_sig = get_histo(file,cate,histname_sig)
    h_ztt = get_histo(file,cate,histname_ztt)    
    h_sig.Scale(1./(h_sig.Integral()))
    h_ztt.Scale(1./(h_ztt.Integral()))
    
    pad1.cd()
    h_sig.GetXaxis().SetLabelSize(0)
    h_sig.GetYaxis().SetTitle("Normalized yields")
    h_sig.GetYaxis().SetTitleOffset(0.85)
    h_sig.GetYaxis().SetTitleFont(42)
    h_sig.GetYaxis().SetTitleSize(0.06)
    h_sig.SetLineColor(ROOT.kRed)
    h_sig.SetLineWidth(2)
    h_sig.SetMarkerStyle(8)
    h_sig.SetMaximum(max(h_sig.GetMaximum()*1.60, h_ztt.GetMaximum()*1.60))
    h_sig.SetMarkerSize(0.5)
    h_sig.Draw("HIST")
    h_ztt.SetLineColor(ROOT.kBlue)
    h_ztt.SetLineWidth(2)
    h_ztt.SetMarkerStyle(8)
    h_ztt.SetMarkerSize(0.5)
    h_ztt.Draw("HIST same")
    legend = ROOT.TLegend(0.2,0.7,0.45,0.87)
    legend.SetHeader(var,"C")
    #legend.SetHeader(var+":"+cate,"C")
    legend.AddEntry(h_sig,histname_sig,"l")
    #legend.AddEntry(h_sig,"Norm("+histname_sig+")","l")
    legend.AddEntry(h_ztt,histname_ztt,"l")
    legend.Draw()

    h_ratio = h_sig.Clone()
    h_ratio.Divide(h_sig,h_ztt,1,1,"B")
    h_ratio.SetLineWidth(1)
    h_ratio.SetLineColor(ROOT.kBlack)
    h_ratio.GetXaxis().SetLabelSize(0.09)
    #h_ratio.GetXaxis().SetTitle(var)
    h_ratio.GetXaxis().SetTitle(var)
    h_ratio.GetXaxis().SetTitleFont(42)
    h_ratio.GetXaxis().SetTitleSize(0.1)
    h_ratio.GetXaxis().SetTitleOffset(1.0)
    h_ratio.GetYaxis().SetLabelSize(0.07)
    h_ratio.GetYaxis().SetTitle('sig / '+histname_ztt)#histname_sig+'/'+histname_ztt)
    h_ratio.GetYaxis().CenterTitle()
    h_ratio.GetYaxis().SetTitleFont(42)
    h_ratio.GetYaxis().SetTitleSize(0.1)
    h_ratio.GetYaxis().SetTitleOffset(0.5)
    pad2.cd()
    h_ratio.Draw()

    #saveas = 'plots/ROC/'+var+'_'+cate+histname_ztt+'.pdf'
    saveas = 'plots/ROC/'+var+'_'+histname_ztt+'.pdf'
    print saveas  
    canvas2.SaveAs(saveas) 

