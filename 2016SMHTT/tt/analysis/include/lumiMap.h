#include <map>

static std::map<std::string, double> xs {
  {"data_obs", 1.0},
  {"ggH125", 48.58*0.0627},  
  {"VBF125", 3.782*0.0627},
  {"WplusH125", 0.840*0.0627},
  {"WminusH125", 0.5328*0.0627},
  {"ZH125", 0.8839*0.0627},
  {"DY", 5765.4},
  {"TT", 831.76},
  {"W", 61526.7},
  {"EWKZLL", 3.987},
  {"EWKZNuNu", 10.01},
  {"EWKWminus", 20.25},
  {"EWKWplus", 25.62},
  {"WZ1L1Nu2Q", 10.71},
  {"WZ1L3Nu", 3.05},
  {"WZJets", 5.26},
  {"WZLLLNu", 4.708},
  {"WZ2L2Q", 5.595},
  {"WW1L1Nu2Q", 49.997},
  {"ZZ4L", 1.212},
  {"ZZ2L2Q", 3.22},
  {"VV2L2Nu", 11.95},
  {"ST_tW_antitop",35.6},
  {"ST_tW_top", 35.6},
  {"ST_t_antitop", 26.23},
  {"ST_t_top", 44.07},
  {"QCD", 720648000*0.00042}
};

float lumiWeight(std::string sample, float ngen) {
  float weight=1.0; 
  float luminosity=35870.0;
  weight=luminosity*xs[sample]/ngen;
  if (xs.find(sample) == xs.end())     
    return 0;
  else
    return weight;

} 
