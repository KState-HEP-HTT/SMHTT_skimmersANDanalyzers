if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--input', help="Which TES?")
    parser.add_argument('--output', help="Which TES?")
    parser.add_argument('--hist', help="Which TES?")
    parser.add_argument('--postfixP', help="Which TES?")
    parser.add_argument('--postfixF', help="Which TES?")
    parser.add_argument('--factor', help="Which TES?")
    options = parser.parse_args()

    fin=ROOT.TFile(options.input,"r")
    fout=ROOT.TFile(options.output,"recreate")
    histdownP=fin.Get("passOS/"+options.hist)
    histdownP.Scale(1.0-float(options.factor))
    histdownP.SetName(options.hist+options.postfixP+"Down")
    dirP=fout.mkdir("passOS")
    dirP.cd()
    histdownP.Write()
    histdownF=fin.Get("failOS/"+options.hist)
    histdownF.Scale(1.0-float(options.factor))
    histdownF.SetName(options.hist+options.postfixF+"Down")
    dirF=fout.mkdir("failOS")
    dirF.cd()
    histdownF.Write()

    histupP=fin.Get("passOS/"+options.hist)
    histupP.Scale(1.0+float(options.factor))
    histupP.SetName(options.hist+options.postfixP+"Up")
    dirP.cd()
    histupP.Write()
    histupF=fin.Get("failOS/"+options.hist)
    histupF.Scale(1.0+float(options.factor))
    histupF.SetName(options.hist+options.postfixF+"Up")
    dirF.cd()
    histupF.Write()


