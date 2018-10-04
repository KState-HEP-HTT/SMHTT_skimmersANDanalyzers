if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down'], help="Which TES?")
    parser.add_argument('--anti', default="iso", choices=['iso', 'anti'], help="Which TES?")
    options = parser.parse_args()

    anti=""
    if (options.anti=="anti"):
        anti="anti_"

    postfix=""
    if (options.scale=="up"):
        postfix="_TESUp"
    if (options.scale=="down"):
        postfix="_TESDown"

    fDYB=ROOT.TFile("files_"+options.scale+"/ZTT.root","r")
    fDYS=ROOT.TFile("files_"+options.scale+"/ZL.root","r")
    fDYJ=ROOT.TFile("files_"+options.scale+"/ZJ.root","r")
    fW=ROOT.TFile("files_"+options.scale+"/Wunscaled.root","r")
    fTTT=ROOT.TFile("files_"+options.scale+"/TTT.root","r")
    fTTJ=ROOT.TFile("files_"+options.scale+"/TTJ.root","r")
    fVV=ROOT.TFile("files_"+options.scale+"/VV.root","r")
    fData=ROOT.TFile("files_nominal/Data.root","r")
    fsf=ROOT.TFile("SFW.root","recreate")

    QCDSS=fData.Get("n70SS").Clone()
    print "1"
    QCDSS.Add(fDYB.Get("n70SS"),-1)
    print "2"
    QCDSS.Add(fDYS.Get("n70SS"),-1)
    print "3"
    QCDSS.Add(fDYJ.Get("n70SS"),-1)
    print "4"
    QCDSS.Add(fTTJ.Get("n70SS"),-1)
    print "5"
    QCDSS.Add(fTTT.Get("n70SS"),-1)
    print "6"
    QCDSS.Add(fW.Get("n70SS"),-1)
    print "7"

    WOS=fData.Get("n70").Clone()
    print "8"
    WOS.Add(fDYB.Get("n70"),-1)
    print "9"
    WOS.Add(fDYS.Get("n70"),-1)
    print "10"
    WOS.Add(fDYJ.Get("n70"),-1)
    print "11"
    WOS.Add(fTTJ.Get("n70"),-1)
    print "12"
    WOS.Add(fTTT.Get("n70"),-1)
    print "13"
    WOS.Add(QCDSS,-1)
    print "14"

    SF=WOS.Clone()
    SF.Divide(fW.Get("n70"))

    fsf.cd()
    SF.Write()
    fsf.Close()
