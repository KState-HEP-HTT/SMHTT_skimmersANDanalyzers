float w_jetMultiplicity (int numGenJets) {
  float weight=25.446;
  if (numGenJets==1) weight=6.8176;
  else if (numGenJets==2) weight=2.1038;
  else if (numGenJets==3) weight=0.6889;
  else if (numGenJets==4) weight=0.6900;
  
  return weight
}

float dy_jetMultiplicity (int numGenJets) {

}
