import math
import ROOT
from scipy.stats import norm

data = {
    "mc_genuine_TightIso_dm10": {
        "alpha": 1.686527964047553,
        "m_{0}": 39.82716689014602,
        "sigma": 5.046934778494286,
        "norm": 0.9709884820866538,
        "n": 119.86933951486884
        },
    "mc_genuine_TightIso_dm1": {
        "alpha": 4.661955903316635,
        "m_{0}": 36.33798366748843,
        "sigma": 4.5521495089687765,
        "norm": 0.9999999970681116,
        "n": 1.6079296195874044
        },
    "mc_genuine_TightIso_dm0": {
        "alpha": 4.862445750387961,
        "m_{0}": 38.083905839292164,
        "sigma": 6.202388502948717,
        "norm": 0.9321292524169671,
        "n": 3.397804647368993
        },
    "data_genuine_TightIso_dm10": {
        "alpha": 2.153157818960823,
        "m_{0}": 40.57070442578432,
        "sigma": 5.245672570732005,
        "norm": 0.9999999969400835,
        "n": 12.26252955476852
        },
    "data_genuine_TightIso_dm1": {
        "alpha": 5.631705386364713,
        "m_{0}": 36.70311525314159,
        "sigma": 4.703474934239983,
        "norm": 0.999999997352303,
        "n": 1.6444215737140877
        },
    "data_genuine_TightIso_dm0": {
        "alpha": 7.283491259365051,
        "m_{0}": 38.822860380950296,
        "sigma": 7.168040439424631,
        "norm": 0.9907280391995551,
        "n": 2.3082298644327626
        }
    }

def compute_SF(x):#x, decayMode):
    if (x[0]==-1.0) :
        return -1.0
    eff_data = crystalballEfficiency(x[0],data['data_genuine_TightIso_dm'+str(x[1])].values())
    eff_mc = crystalballEfficiency(x[0],data['mc_genuine_TightIso_dm'+str(x[1])].values())
    eff_SF = eff_data/eff_mc
    #print 'eff_data = ',eff_data, ', eff_mc = ', eff_mc, ', eff_SF = ',eff_SF
    return eff_SF

def crystalballEfficiency(x, par):
    x     = x
    alpha = par[0]
    m0    = par[1]
    sigma = par[2]
    norm  = par[3]
    n     = par[4]
    return _crystalballEfficiency( x, m0, sigma, alpha, n, norm )

def _crystalballEfficiency(m, m0, sigma, alpha, n, norm):
  
    sqrtPiOver2 = math.sqrt(ROOT.TMath.PiOver2())
    sqrt2       = math.sqrt(2.)
    sig         = abs(sigma)
    t           = (m - m0)/sig * alpha / abs(alpha)
    absAlpha    = abs(alpha/sig)
    a           = ROOT.TMath.Power(n/absAlpha, n) * ROOT.TMath.Exp(-0.5 * absAlpha * absAlpha)
    b           = absAlpha - n/absAlpha
    arg         = absAlpha / sqrt2;
  
    if   arg >  5.: ApproxErf =  1.
    elif arg < -5.: ApproxErf = -1.
    else          : ApproxErf = ROOT.TMath.Erf(arg)
  
    leftArea    = (1. + ApproxErf) * sqrtPiOver2
    rightArea   = ( a * 1./ROOT.TMath.Power(absAlpha-b, n-1) ) / (n - 1)
    area        = leftArea + rightArea
  
    if t <= absAlpha:
        arg = t / sqrt2
        if   arg >  5.: ApproxErf =  1.
        elif arg < -5.: ApproxErf = -1.
        else          : ApproxErf = ROOT.TMath.Erf(arg)
        return norm * (1 + ApproxErf) * sqrtPiOver2 / area
  
    else:
        return norm * (leftArea + a * (1/ROOT.TMath.Power(t-b,n-1) - \
                                       1/ROOT.TMath.Power(absAlpha - b,n-1)) / (1 - n)) / area
  
