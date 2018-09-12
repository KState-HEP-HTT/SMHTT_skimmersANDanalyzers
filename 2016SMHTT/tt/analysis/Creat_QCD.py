if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allJES'], help="Which TES?")

    nbhist=1

    options = parser.parse_args()
    postfix=""

    fZTT=ROOT.TFile("files_nominal/ZTT.root","r")
    fZJ=ROOT.TFile("files_nominal/ZJ.root","r")
    fZL=ROOT.TFile("files_nominal/ZL.root","r")
    fTTT=ROOT.TFile("files_"+options.scale+"/TTT.root","r")
    fTTJ=ROOT.TFile("files_"+options.scale+"/TTJ.root","r")
    fVVT=ROOT.TFile("files_"+options.scale+"/VVT.root","r")
    fVVJ=ROOT.TFile("files_"+options.scale+"/VVJ.root","r")
    fW=ROOT.TFile("files_"+options.scale+"/WJets.root","r")
    fEWKZ=ROOT.TFile("files_"+options.scale+"/EWKZ.root","r")
    fData=ROOT.TFile("files_nominal/data.root","r")
    fout=ROOT.TFile("files_"+options.scale+"/QCD.root","recreate")

    postfixData=""
    hAIOS_0jet=fData.Get("AIOS_0jet/data_obs"+postfixData)
    hAIOS_0jet.Add(fZTT.Get("AIOS_0jet/ZTT"+postfix),-1)
    hAIOS_0jet.Add(fZJ.Get("AIOS_0jet/ZJ"+postfix),-1)
    hAIOS_0jet.Add(fZL.Get("AIOS_0jet/ZL"+postfix),-1)
    hAIOS_0jet.Add(fTTT.Get("AIOS_0jet/TTT"+postfix),-1)
    hAIOS_0jet.Add(fTTJ.Get("AIOS_0jet/TTJ"+postfix),-1)
    hAIOS_0jet.Add(fVVT.Get("AIOS_0jet/VVT"+postfix),-1)
    hAIOS_0jet.Add(fVVJ.Get("AIOS_0jet/VVJ"+postfix),-1)
    hAIOS_0jet.Add(fW.Get("AIOS_0jet/W"+postfix),-1)
    hAIOS_0jet.Add(fEWKZ.Get("AIOS_0jet/EWKZ"+postfix),-1)
    hAIOS_0jet.SetName("OSLooseIso"+postfix)
    for i in range(0,hAIOS_0jet.GetSize()-2):
        if hAIOS_0jet.GetBinContent(i)<0:
            hAIOS_0jet.SetBinError(i,max(0,hAIOS_0jet.GetBinError(i)+hAIOS_0jet.GetBinError(i)))
            hAIOS_0jet.SetBinContent(i,0)

    hAISS_0jet=fData.Get("AISS_0jet/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.
    hAISS_0jet.Add(fZTT.Get("AISS_0jet/ZTT"+postfix),-1)
    hAISS_0jet.Add(fZJ.Get("AISS_0jet/ZJ"+postfix),-1)
    hAISS_0jet.Add(fZL.Get("AISS_0jet/ZL"+postfix),-1)
    hAISS_0jet.Add(fTTT.Get("AISS_0jet/TTT"+postfix),-1)
    hAISS_0jet.Add(fTTJ.Get("AISS_0jet/TTJ"+postfix),-1)
    hAISS_0jet.Add(fVVT.Get("AISS_0jet/VVT"+postfix),-1)
    hAISS_0jet.Add(fVVJ.Get("AISS_0jet/VVJ"+postfix),-1)
    hAISS_0jet.Add(fW.Get("AISS_0jet/W"+postfix),-1)
    hAISS_0jet.Add(fEWKZ.Get("AISS_0jet/EWKZ"+postfix),-1)
    hAISS_0jet.SetName("SSLooseIso"+postfix)
    for i in range(0,hAISS_0jet.GetSize()-2):
        if hAISS_0jet.GetBinContent(i)<0:
            hAISS_0jet.SetBinError(i,max(0,hAISS_0jet.GetBinError(i)+hAISS_0jet.GetBinError(i)))
            hAISS_0jet.SetBinContent(i,0)

    hSS_0jet=fData.Get("ttSS_0jet/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.
    hSS_0jet.Add(fZTT.Get("ttSS_0jet/ZTT"+postfix),-1)
    hSS_0jet.Add(fZJ.Get("ttSS_0jet/ZJ"+postfix),-1)
    hSS_0jet.Add(fZL.Get("ttSS_0jet/ZL"+postfix),-1)
    hSS_0jet.Add(fTTT.Get("ttSS_0jet/TTT"+postfix),-1)
    hSS_0jet.Add(fTTJ.Get("ttSS_0jet/TTJ"+postfix),-1)
    hSS_0jet.Add(fVVT.Get("ttSS_0jet/VVT"+postfix),-1)
    hSS_0jet.Add(fVVJ.Get("ttSS_0jet/VVJ"+postfix),-1)
    hSS_0jet.Add(fW.Get("ttSS_0jet/W"+postfix),-1)
    hSS_0jet.Add(fEWKZ.Get("ttSS_0jet/EWKZ"+postfix),-1)
    hSS_0jet.SetName("SignalLike"+postfix)
    for i in range(0,hSS_0jet.GetSize()-2):
        if hSS_0jet.GetBinContent(i)<0:
            hSS_0jet.SetBinError(i,max(0,hSS_0jet.GetBinError(i)+hSS_0jet.GetBinError(i)))
            hSS_0jet.SetBinContent(i,0)

    # AN eq(14)
    hSF_0jet = hSS_0jet.Clone()
    hSF_0jet.Divide(hSS_0jet,hAISS_0jet,1,1,"B")
    hSF_0jet.SetName("ScaleFactor"+postfix)
    hQCD_0jet = hSF_0jet.Clone()
    hQCD_0jet.Multiply(hAIOS_0jet,hSF_0jet,1,1,"B")

    postfixData=""
    hAIOS_boosted=fData.Get("AIOS_boosted/data_obs"+postfixData)
    hAIOS_boosted.Add(fZTT.Get("AIOS_boosted/ZTT"+postfix),-1)
    hAIOS_boosted.Add(fZJ.Get("AIOS_boosted/ZJ"+postfix),-1)
    hAIOS_boosted.Add(fZL.Get("AIOS_boosted/ZL"+postfix),-1)
    hAIOS_boosted.Add(fTTT.Get("AIOS_boosted/TTT"+postfix),-1)
    hAIOS_boosted.Add(fTTJ.Get("AIOS_boosted/TTJ"+postfix),-1)
    hAIOS_boosted.Add(fVVT.Get("AIOS_boosted/VVT"+postfix),-1)
    hAIOS_boosted.Add(fVVJ.Get("AIOS_boosted/VVJ"+postfix),-1)
    hAIOS_boosted.Add(fW.Get("AIOS_boosted/W"+postfix),-1)
    hAIOS_boosted.Add(fEWKZ.Get("AIOS_boosted/EWKZ"+postfix),-1)
    hAIOS_boosted.SetName("OSLooseIso"+postfix)
    for i in range(0,hAIOS_boosted.GetSize()-2):
        if hAIOS_boosted.GetBinContent(i)<0:
            hAIOS_boosted.SetBinError(i,max(0,hAIOS_boosted.GetBinError(i)+hAIOS_boosted.GetBinError(i)))
            hAIOS_boosted.SetBinContent(i,0)

    hAISS_boosted=fData.Get("AISS_boosted/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.                                                   
    hAISS_boosted.Add(fZTT.Get("AISS_boosted/ZTT"+postfix),-1)
    hAISS_boosted.Add(fZJ.Get("AISS_boosted/ZJ"+postfix),-1)
    hAISS_boosted.Add(fZL.Get("AISS_boosted/ZL"+postfix),-1)
    hAISS_boosted.Add(fTTT.Get("AISS_boosted/TTT"+postfix),-1)
    hAISS_boosted.Add(fTTJ.Get("AISS_boosted/TTJ"+postfix),-1)
    hAISS_boosted.Add(fVVT.Get("AISS_boosted/VVT"+postfix),-1)
    hAISS_boosted.Add(fVVJ.Get("AISS_boosted/VVJ"+postfix),-1)
    hAISS_boosted.Add(fW.Get("AISS_boosted/W"+postfix),-1)
    hAISS_boosted.Add(fEWKZ.Get("AISS_boosted/EWKZ"+postfix),-1)
    hAISS_boosted.SetName("SSLooseIso"+postfix)
    for i in range(0,hAISS_boosted.GetSize()-2):
        if hAISS_boosted.GetBinContent(i)<0:
            hAISS_boosted.SetBinError(i,max(0,hAISS_boosted.GetBinError(i)+hAISS_boosted.GetBinError(i)))
            hAISS_boosted.SetBinContent(i,0)

    hSS_boosted=fData.Get("ttSS_boosted/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.                                                   
    hSS_boosted.Add(fZTT.Get("ttSS_boosted/ZTT"+postfix),-1)
    hSS_boosted.Add(fZJ.Get("ttSS_boosted/ZJ"+postfix),-1)
    hSS_boosted.Add(fZL.Get("ttSS_boosted/ZL"+postfix),-1)
    hSS_boosted.Add(fTTT.Get("ttSS_boosted/TTT"+postfix),-1)
    hSS_boosted.Add(fTTJ.Get("ttSS_boosted/TTJ"+postfix),-1)
    hSS_boosted.Add(fVVT.Get("ttSS_boosted/VVT"+postfix),-1)
    hSS_boosted.Add(fVVJ.Get("ttSS_boosted/VVJ"+postfix),-1)
    hSS_boosted.Add(fW.Get("ttSS_boosted/W"+postfix),-1)
    hSS_boosted.Add(fEWKZ.Get("ttSS_boosted/EWKZ"+postfix),-1)
    hSS_boosted.SetName("SignalLike"+postfix)
    for i in range(0,hSS_boosted.GetSize()-2):
        if hSS_boosted.GetBinContent(i)<0:
            hSS_boosted.SetBinError(i,max(0,hSS_boosted.GetBinError(i)+hSS_boosted.GetBinError(i)))
            hSS_boosted.SetBinContent(i,0)

    # AN eq(14)                                                                                                                              
    hSF_boosted = hSS_boosted.Clone()
    hSF_boosted.Divide(hSS_boosted,hAISS_boosted,1,1,"B")
    hSF_boosted.SetName("ScaleFactor"+postfix)
    hQCD_boosted = hSF_boosted.Clone()
    hQCD_boosted.Multiply(hAIOS_boosted,hSF_boosted,1,1,"B")


    hAIOS_vbf=fData.Get("AIOS_vbf/data_obs"+postfixData)
    hAIOS_vbf.Add(fZTT.Get("AIOS_vbf/ZTT"+postfix),-1)
    hAIOS_vbf.Add(fZJ.Get("AIOS_vbf/ZJ"+postfix),-1)
    hAIOS_vbf.Add(fZL.Get("AIOS_vbf/ZL"+postfix),-1)
    hAIOS_vbf.Add(fTTT.Get("AIOS_vbf/TTT"+postfix),-1)
    hAIOS_vbf.Add(fTTJ.Get("AIOS_vbf/TTJ"+postfix),-1)
    hAIOS_vbf.Add(fVVT.Get("AIOS_vbf/VVT"+postfix),-1)
    hAIOS_vbf.Add(fVVJ.Get("AIOS_vbf/VVJ"+postfix),-1)
    hAIOS_vbf.Add(fW.Get("AIOS_vbf/W"+postfix),-1)
    hAIOS_vbf.Add(fEWKZ.Get("AIOS_vbf/EWKZ"+postfix),-1)
    hAIOS_vbf.SetName("OSLooseIso"+postfix)
    for i in range(0,hAIOS_vbf.GetSize()-2):
        if hAIOS_vbf.GetBinContent(i)<0:
            hAIOS_vbf.SetBinError(i,max(0,hAIOS_vbf.GetBinError(i)+hAIOS_vbf.GetBinError(i)))
            hAIOS_vbf.SetBinContent(i,0)

    hAISS_vbf=fData.Get("AISS_vbf/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.                                                   
    hAISS_vbf.Add(fZTT.Get("AISS_vbf/ZTT"+postfix),-1)
    hAISS_vbf.Add(fZJ.Get("AISS_vbf/ZJ"+postfix),-1)
    hAISS_vbf.Add(fZL.Get("AISS_vbf/ZL"+postfix),-1)
    hAISS_vbf.Add(fTTT.Get("AISS_vbf/TTT"+postfix),-1)
    hAISS_vbf.Add(fTTJ.Get("AISS_vbf/TTJ"+postfix),-1)
    hAISS_vbf.Add(fVVT.Get("AISS_vbf/VVT"+postfix),-1)
    hAISS_vbf.Add(fVVJ.Get("AISS_vbf/VVJ"+postfix),-1)
    hAISS_vbf.Add(fW.Get("AISS_vbf/W"+postfix),-1)
    hAISS_vbf.Add(fEWKZ.Get("AISS_vbf/EWKZ"+postfix),-1)
    hAISS_vbf.SetName("SSLooseIso"+postfix)
    for i in range(0,hAISS_vbf.GetSize()-2):
        if hAISS_vbf.GetBinContent(i)<0:
            hAISS_vbf.SetBinError(i,max(0,hAISS_vbf.GetBinError(i)+hAISS_vbf.GetBinError(i)))
            hAISS_vbf.SetBinContent(i,0)

    hSS_vbf=fData.Get("ttSS_vbf/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.                                                   
    hSS_vbf.Add(fZTT.Get("ttSS_vbf/ZTT"+postfix),-1)
    hSS_vbf.Add(fZJ.Get("ttSS_vbf/ZJ"+postfix),-1)
    hSS_vbf.Add(fZL.Get("ttSS_vbf/ZL"+postfix),-1)
    hSS_vbf.Add(fTTT.Get("ttSS_vbf/TTT"+postfix),-1)
    hSS_vbf.Add(fTTJ.Get("ttSS_vbf/TTJ"+postfix),-1)
    hSS_vbf.Add(fVVT.Get("ttSS_vbf/VVT"+postfix),-1)
    hSS_vbf.Add(fVVJ.Get("ttSS_vbf/VVJ"+postfix),-1)
    hSS_vbf.Add(fW.Get("ttSS_vbf/W"+postfix),-1)
    hSS_vbf.Add(fEWKZ.Get("ttSS_vbf/EWKZ"+postfix),-1)
    hSS_vbf.SetName("SignalLike"+postfix)
    for i in range(0,hSS_vbf.GetSize()-2):
        if hSS_vbf.GetBinContent(i)<0:
            hSS_vbf.SetBinError(i,max(0,hSS_vbf.GetBinError(i)+hSS_vbf.GetBinError(i)))
            hSS_vbf.SetBinContent(i,0)

    # AN eq(14)                                                                                                                              
    hSF_vbf = hSS_vbf.Clone()
    hSF_vbf.Divide(hSS_vbf,hAISS_vbf,1,1,"B")
    hSF_vbf.SetName("ScaleFactor"+postfix)
    hQCD_vbf = hSF_vbf.Clone()
    hQCD_vbf.Multiply(hAIOS_vbf,hSF_vbf,1,1,"B")

    postfixData=""
    hAIOS_inclusive=fData.Get("AIOS_inclusive/data_obs"+postfixData)
    hAIOS_inclusive.Add(fZTT.Get("AIOS_inclusive/ZTT"+postfix),-1)
    hAIOS_inclusive.Add(fZJ.Get("AIOS_inclusive/ZJ"+postfix),-1)
    hAIOS_inclusive.Add(fZL.Get("AIOS_inclusive/ZL"+postfix),-1)
    hAIOS_inclusive.Add(fTTT.Get("AIOS_inclusive/TTT"+postfix),-1)
    hAIOS_inclusive.Add(fTTJ.Get("AIOS_inclusive/TTJ"+postfix),-1)
    hAIOS_inclusive.Add(fVVT.Get("AIOS_inclusive/VVT"+postfix),-1)
    hAIOS_inclusive.Add(fVVJ.Get("AIOS_inclusive/VVJ"+postfix),-1)
    hAIOS_inclusive.Add(fW.Get("AIOS_inclusive/W"+postfix),-1)
    hAIOS_inclusive.Add(fEWKZ.Get("AIOS_inclusive/EWKZ"+postfix),-1)
    hAIOS_inclusive.SetName("OSLooseIso"+postfix)
    for i in range(0,hAIOS_inclusive.GetSize()-2):
        if hAIOS_inclusive.GetBinContent(i)<0:
            hAIOS_inclusive.SetBinError(i,max(0,hAIOS_inclusive.GetBinError(i)+hAIOS_inclusive.GetBinError(i)))
            hAIOS_inclusive.SetBinContent(i,0)

    hAISS_inclusive=fData.Get("AISS_inclusive/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.                             
    hAISS_inclusive.Add(fZTT.Get("AISS_inclusive/ZTT"+postfix),-1)
    hAISS_inclusive.Add(fZJ.Get("AISS_inclusive/ZJ"+postfix),-1)
    hAISS_inclusive.Add(fZL.Get("AISS_inclusive/ZL"+postfix),-1)
    hAISS_inclusive.Add(fTTT.Get("AISS_inclusive/TTT"+postfix),-1)
    hAISS_inclusive.Add(fTTJ.Get("AISS_inclusive/TTJ"+postfix),-1)
    hAISS_inclusive.Add(fVVT.Get("AISS_inclusive/VVT"+postfix),-1)
    hAISS_inclusive.Add(fVVJ.Get("AISS_inclusive/VVJ"+postfix),-1)
    hAISS_inclusive.Add(fW.Get("AISS_inclusive/W"+postfix),-1)
    hAISS_inclusive.Add(fEWKZ.Get("AISS_inclusive/EWKZ"+postfix),-1)
    hAISS_inclusive.SetName("SSLooseIso"+postfix)
    for i in range(0,hAISS_inclusive.GetSize()-2):
        if hAISS_inclusive.GetBinContent(i)<0:
            hAISS_inclusive.SetBinError(i,max(0,hAISS_inclusive.GetBinError(i)+hAISS_inclusive.GetBinError(i)))
            hAISS_inclusive.SetBinContent(i,0)

    hSS_inclusive=fData.Get("ttSS_inclusive/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.                             
    hSS_inclusive.Add(fZTT.Get("ttSS_inclusive/ZTT"+postfix),-1)
    hSS_inclusive.Add(fZJ.Get("ttSS_inclusive/ZJ"+postfix),-1)
    hSS_inclusive.Add(fZL.Get("ttSS_inclusive/ZL"+postfix),-1)
    hSS_inclusive.Add(fTTT.Get("ttSS_inclusive/TTT"+postfix),-1)
    hSS_inclusive.Add(fTTJ.Get("ttSS_inclusive/TTJ"+postfix),-1)
    hSS_inclusive.Add(fVVT.Get("ttSS_inclusive/VVT"+postfix),-1)
    hSS_inclusive.Add(fVVJ.Get("ttSS_inclusive/VVJ"+postfix),-1)
    hSS_inclusive.Add(fW.Get("ttSS_inclusive/W"+postfix),-1)
    hSS_inclusive.Add(fEWKZ.Get("ttSS_inclusive/EWKZ"+postfix),-1)
    hSS_inclusive.SetName("SignalLike"+postfix)
    for i in range(0,hSS_inclusive.GetSize()-2):
        if hSS_inclusive.GetBinContent(i)<0:
            hSS_inclusive.SetBinError(i,max(0,hSS_inclusive.GetBinError(i)+hSS_inclusive.GetBinError(i)))
            hSS_inclusive.SetBinContent(i,0)

    # AN eq(14)                                                                                                        
    hSF_inclusive = hSS_inclusive.Clone()
    hSF_inclusive.Divide(hSS_inclusive,hAISS_inclusive,1,1,"B")
    hSF_inclusive.SetName("ScaleFactor"+postfix)
    hQCD_inclusive = hSF_inclusive.Clone()
    hQCD_inclusive.Multiply(hAIOS_inclusive,hSF_inclusive,1,1,"B")


    postfixData=""
    hAIOS_vh=fData.Get("AIOS_vh/data_obs"+postfixData)
    hAIOS_vh.Add(fZTT.Get("AIOS_vh/ZTT"+postfix),-1)
    hAIOS_vh.Add(fZJ.Get("AIOS_vh/ZJ"+postfix),-1)
    hAIOS_vh.Add(fZL.Get("AIOS_vh/ZL"+postfix),-1)
    hAIOS_vh.Add(fTTT.Get("AIOS_vh/TTT"+postfix),-1)
    hAIOS_vh.Add(fTTJ.Get("AIOS_vh/TTJ"+postfix),-1)
    hAIOS_vh.Add(fVVT.Get("AIOS_vh/VVT"+postfix),-1)
    hAIOS_vh.Add(fVVJ.Get("AIOS_vh/VVJ"+postfix),-1)
    hAIOS_vh.Add(fW.Get("AIOS_vh/W"+postfix),-1)
    hAIOS_vh.Add(fEWKZ.Get("AIOS_vh/EWKZ"+postfix),-1)
    hAIOS_vh.SetName("OSLooseIso"+postfix)
    for i in range(0,hAIOS_vh.GetSize()-2):
        if hAIOS_vh.GetBinContent(i)<0:
            hAIOS_vh.SetBinError(i,max(0,hAIOS_vh.GetBinError(i)+hAIOS_vh.GetBinError(i)))
            hAIOS_vh.SetBinContent(i,0)

    hAISS_vh=fData.Get("AISS_vh/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.                                                                    
    hAISS_vh.Add(fZTT.Get("AISS_vh/ZTT"+postfix),-1)
    hAISS_vh.Add(fZJ.Get("AISS_vh/ZJ"+postfix),-1)
    hAISS_vh.Add(fZL.Get("AISS_vh/ZL"+postfix),-1)
    hAISS_vh.Add(fTTT.Get("AISS_vh/TTT"+postfix),-1)
    hAISS_vh.Add(fTTJ.Get("AISS_vh/TTJ"+postfix),-1)
    hAISS_vh.Add(fVVT.Get("AISS_vh/VVT"+postfix),-1)
    hAISS_vh.Add(fVVJ.Get("AISS_vh/VVJ"+postfix),-1)
    hAISS_vh.Add(fW.Get("AISS_vh/W"+postfix),-1)
    hAISS_vh.Add(fEWKZ.Get("AISS_vh/EWKZ"+postfix),-1)
    hAISS_vh.SetName("SSLooseIso"+postfix)
    for i in range(0,hAISS_vh.GetSize()-2):
        if hAISS_vh.GetBinContent(i)<0:
            hAISS_vh.SetBinError(i,max(0,hAISS_vh.GetBinError(i)+hAISS_vh.GetBinError(i)))
            hAISS_vh.SetBinContent(i,0)
    hSS_vh=fData.Get("ttSS_vh/data_obs"+postfixData)
    # QCD contribution is estimated as data with all non-signal MC backgrounds subtracted.                                                                    
    hSS_vh.Add(fZTT.Get("ttSS_vh/ZTT"+postfix),-1)
    hSS_vh.Add(fZJ.Get("ttSS_vh/ZJ"+postfix),-1)
    hSS_vh.Add(fZL.Get("ttSS_vh/ZL"+postfix),-1)
    hSS_vh.Add(fTTT.Get("ttSS_vh/TTT"+postfix),-1)
    hSS_vh.Add(fTTJ.Get("ttSS_vh/TTJ"+postfix),-1)
    hSS_vh.Add(fVVT.Get("ttSS_vh/VVT"+postfix),-1)
    hSS_vh.Add(fVVJ.Get("ttSS_vh/VVJ"+postfix),-1)
    hSS_vh.Add(fW.Get("ttSS_vh/W"+postfix),-1)
    hSS_vh.Add(fEWKZ.Get("ttSS_vh/EWKZ"+postfix),-1)
    hSS_vh.SetName("SignalLike"+postfix)
    for i in range(0,hSS_vh.GetSize()-2):
        if hSS_vh.GetBinContent(i)<0:
            hSS_vh.SetBinError(i,max(0,hSS_vh.GetBinError(i)+hSS_vh.GetBinError(i)))
            hSS_vh.SetBinContent(i,0)

    # AN eq(14)                                                                                                                                               
    hSF_vh = hSS_vh.Clone()
    hSF_vh.Divide(hSS_vh,hAISS_vh,1,1,"B")
    hSF_vh.SetName("ScaleFactor"+postfix)
    hQCD_vh = hSF_vh.Clone()
    hQCD_vh.Multiply(hAIOS_vh,hSF_vh,1,1,"B")



    fout.cd()
    dirQCD_0jet=fout.mkdir("ttOS_0jet")
    dirQCD_0jet.cd()
    hQCD_0jet.SetName("QCD"+postfix)
    hQCD_0jet.Write()

# added by AM
    dirQCD_0jet=fout.mkdir("tt_0jet")
    dirQCD_0jet.cd()
    hQCD_0jet.SetName("QCD"+postfix)
    hQCD_0jet.Write()

    dirQCD_boosted=fout.mkdir("ttOS_boosted")
    dirQCD_boosted.cd()
    hQCD_boosted.SetName("QCD"+postfix)
    hQCD_boosted.Write()

# added by AM
    dirQCD_boosted=fout.mkdir("tt_boosted")
    dirQCD_boosted.cd()
    hQCD_boosted.SetName("QCD"+postfix)
    hQCD_boosted.Write()
    

    dirQCD_vbf=fout.mkdir("ttOS_vbf")
    dirQCD_vbf.cd()
    hQCD_vbf.SetName("QCD"+postfix)
    hQCD_vbf.Write()

# added by AM
    dirQCD_vbf=fout.mkdir("tt_vbf")
    dirQCD_vbf.cd()
    hQCD_vbf.SetName("QCD"+postfix)
    hQCD_vbf.Write()



    dirQCD_vh=fout.mkdir("ttOS_vh")
    dirQCD_vh.cd()
    hQCD_vh.SetName("QCD"+postfix)
    hQCD_vh.Write()

    dirQCD_inclusive=fout.mkdir("ttOS_inclusive")
    dirQCD_inclusive.cd()
    hQCD_inclusive.SetName("QCD"+postfix)
    hQCD_inclusive.Write()



    #hAIOS_0jet.Write()
    #hAISS_0jet.Write()
    #hSS_0jet.Write()
    #hSF_0jet_0jet.Write()






