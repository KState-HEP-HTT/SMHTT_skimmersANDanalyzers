///////////////////////////////////////////////////////////////
//                                                           //
//  Maps for histograms                                      //
//  : changing observable require changing bins together.    //
//    On top of that, make analyzer as clean as possible.    //
//                                                           // 
///////////////////////////////////////////////////////////////
#include <iostream>
#include <string>

class histo_1D {
 public:
  std::vector<TH1F> h_1d;
  std::ostringstream HISTO1D;
  int binNum(std::string);
  ~histo_1D () {};
};


///////////////////////////////////////
//  Official 2016 analysis binnings  //
///////////////////////////////////////
// Binning for 0jet
float bins0[] = {0,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};  
// Binning for 1jet cat, x-axis: HpT
float bins11[] = {0,100,170,300,10000};
// Binning for 1jet cat, y-axis: M_sv
float bins12[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};
// Binning for 2jet cat, x-axis: Mjj
float bins21[] = {0,300,500,800,10000};
// Binning for 2jet cat, y-axis: Msv
float bins22[] = {0,40,60,70,80,90,100,110,120,130,150,200,250};

int binNum(std::string cate) {
  int binnum;
  if (cate=="0jet") binnum = sizeof(bins0)/sizeof(Float_t) - 1;
  
  return binnum;
}


