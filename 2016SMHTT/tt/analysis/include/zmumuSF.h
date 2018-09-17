// Z mumu SF
// https://github.com/truggles/Z_to_TauTau_13TeV/blob/SM-HTT-2016/analysis2IsoJetsAndDups.py#L1193-L1211
// https://github.com/truggles/Z_to_TauTau_13TeV/blob/SM-HTT-2016/analysisPlots.py#L293-L312

float zmumuSF_boosted (float pt_sv, std::string shape) {
  float zmumusf = 1.00;
  if (pt_sv<=100) zmumusf = 0.973;
  else if (pt_sv<=170) zmumusf = 0.959;
  else if (pt_sv<=300) zmumusf = 0.934;
  else zmumusf = 0.993;

  if (shape!="zmumuShape_Up" && shape!="zmumuShape_Down") // nominal
    return zmumusf;

  zmumusf-=1.0;
  if (shape=="zmumuShape_Up") // up 
    zmumusf=((1.0+2*zmumusf)/(1.0+zmumusf));
  else if (shape=="zmumuShape_Down") // down  
    zmumusf=(1.0/(1.0+zmumusf));
    
  return zmumusf;
}

float zmumuSF_vbf (float mjj, std::string shape) {
  float zmumusf = 1.00;
  if (mjj<=300) zmumusf = (0.010/2.0)+1.0;
  else if (mjj<=500) zmumusf = (0.064/2.0)+1.0;
  else if (mjj<=800) zmumusf = (0.088/2.0)+1.0;
  else zmumusf = (0.003/2.0)+1.0;
 
  if (shape!="zmumuShape_Up" && shape!="zmumuShape_Down") // nominal
    return zmumusf;


  zmumusf-=1.0;
  if (shape=="zmumuShape_Up") // up 
    zmumusf=((1.0+2*zmumusf)/(1.0+zmumusf));
  else if (shape=="zmumuShape_Down") // down  
    zmumusf=(1.0/(1.0+zmumusf));
    
  return zmumusf;
}
