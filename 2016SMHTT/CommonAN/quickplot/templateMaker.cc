// system includes
#include <dirent.h>
#include <map>
#include <string>
#include <sys/types.h>
#include <iostream>

// ROOT includes
#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"

// user includes
#include "CLParser.h"

using namespace std;
// class to hold the histograms until I'm ready to write them
class histHolder {
public:
  histHolder(std::vector<float>, std::string);
  void writeHistos();
  void initVectors(std::string);

  TH1F *qcd_0jet_OS, *qcd_boosted_OS, *qcd_vbf_OS, 
       *qcd_0jet_SS, *qcd_boosted_SS, *qcd_vbf_SS, 
       *qcd_0jet   , *qcd_boosted   , *qcd_vbf   ;
  TFile *fout;
  std::vector<float> bins;
  std::map<std::string, std::vector<TH1F *>> hists;
};

void read_directory(const std::string &name, std::vector<std::string> &v);
void fillQCD(TH1F*, std::string, double, double);

int main(int argc, char *argv[]) {
  // get CLI arguments
  CLParser parser(argc, argv);
  std::string sample = parser.Option("-s");
  std::string dir = parser.Option("-d");
  std::string tvar = parser.Option("-t");
  std::vector<std::string> sbins = parser.MultiOption("-b", 3);

  // get the provided histogram binning
  std::vector<float> bins;
  std::cout << sbins.size() << std::endl;
  for (auto sbin : sbins) {
    std::cout << sbin << std::endl;
    bins.push_back(std::strtof(sbin.c_str(),0));
  }

  // get input file directory
  if (dir.empty()) {
    std::cerr << "You must give an input directory" << std::endl;
    return -1;
  }

  std::cout << "So far it is good 1 " << std::endl;
  // initialize histogram holder 
  auto hists = new histHolder(bins, tvar);

  std::cout << "So far it is good 2 " << std::endl;
  // read all files from input directory
  std::vector<std::string> files;
  read_directory(dir, files);
  std::cout << "So far it is good 3 " << std::endl;

  for (auto ifile : files) {
    auto fin = new TFile((dir+"/"+ifile).c_str(), "read");
    auto tree = (TTree*)fin->Get("mutau_tree");
    std::string name = ifile.substr(0, ifile.find(".")).c_str();

    std::cout << "Reading " << (dir+"/"+ifile).c_str() << std::endl;
    
    hists->initVectors(name);
    // I hate doing it like this, but when I move the SetBranchAddres I see unexpected behavior
    Float_t cat_inclusive, cat_0jet, cat_boosted, cat_vbf;
    Float_t mq, tq, hpt, var, weight, mjj, mt, t1_pt;
    Int_t njets, nbjets;
    Bool_t is_signal, is_qcd;
    Float_t Dbkg_VBF;
    tree->SetBranchAddress("Dbkg_VBF", &Dbkg_VBF);
    tree->SetBranchAddress("mt", &mt);
    tree->SetBranchAddress("njets", &njets);
    tree->SetBranchAddress("nbtag", &nbjets);
    tree->SetBranchAddress("mu_charge", &mq);
    tree->SetBranchAddress("t1_charge", &tq);
    tree->SetBranchAddress("t1_pt",&t1_pt);
    //tree->SetBranchAddress("higgs_pT", &hpt);
    tree->SetBranchAddress("mjj", &mjj);
    if ( strncmp(tvar.c_str(), "mjj", 3) != 0 ) 
      tree->SetBranchAddress(tvar.c_str(), &var);
    tree->SetBranchAddress("evtwt", &weight);
    tree->SetBranchAddress("cat_inclusive", &cat_inclusive);
    tree->SetBranchAddress("cat_vbf", &cat_vbf);
    tree->SetBranchAddress("cat_boosted", &cat_boosted);
    tree->SetBranchAddress("cat_0jet", &cat_0jet);
    tree->SetBranchAddress("is_qcd", &is_qcd);
    tree->SetBranchAddress("is_signal", &is_signal);

    for (auto i = 0; i < tree->GetEntries(); i++) {
      tree->GetEntry(i);

      
      if ( strncmp(tvar.c_str(), "mjj", 3) == 0 ) 
	var = mjj;

      Bool_t vbf_criteria = mjj>0 && njets>=2 && is_signal==1 && mt<50 && t1_pt>40  && nbjets==0;
      //Bool_t vbf_criteria = cat_inclusive>0 && njets >= 2 && mjj > 300.0 && mt < 50;
      
      if (mq + tq == 0) {
        // output histograms for the template
        if (cat_0jet > 0) {
          hists->hists.at("mt_0jet").back()->Fill(var, weight);
        }
        if (cat_boosted > 0) {
          hists->hists.at("mt_boosted").back()->Fill(var, weight);
        }
	if (vbf_criteria && is_signal ) {
          hists->hists.at("mt_vbf").back()->Fill(var, weight);
        }
      } else {
        // get QCD shape from SS loose iso region
        if (cat_0jet > 0 && is_qcd) {
          fillQCD(hists->qcd_0jet, name, var, weight);
        }
        if (cat_boosted > 0 && is_qcd) {
          fillQCD(hists->qcd_boosted, name, var, weight);
        }
        if (vbf_criteria  &&  is_qcd ) {
          fillQCD(hists->qcd_vbf, name, var, weight);
        }

        // get SS in signal region for loose region normalization
        if (cat_0jet > 0  && is_signal ) {
          fillQCD(hists->qcd_0jet_SS, name, var, weight);
        }
        if (cat_boosted > 0  && is_signal ) {
          fillQCD(hists->qcd_boosted_SS, name, var, weight);
        }
        if (vbf_criteria  && is_signal ) {
          fillQCD(hists->qcd_vbf_SS, name, var, weight);
        }
      }
    }
  }
  // write the output histograms
  hists->writeHistos();
}

// read all *.root files in the given directory and put them in the provided vector
void read_directory(const std::string &name, std::vector<std::string> &v) {
  DIR *dirp = opendir(name.c_str());
  struct dirent *dp;
  while ((dp = readdir(dirp)) != 0) {
    if (static_cast<std::string>(dp->d_name).find("root") != std::string::npos) {
      std::cout << dp->d_name << std::endl;
      v.push_back(dp->d_name);
    }
  }
  closedir(dirp);
}

// Fill histogram with positive weight for Data and negative weight for BKG. Equivalent to 
// doing data-bkg
void fillQCD(TH1F* hist, std::string name, double var, double weight) {
  if (name.find("Data") != std::string::npos) {
    hist->Fill(var, weight);
  } else if (name == "ZTT" || name == "ZL" || name == "ZJ" || name == "TTT" || name == "TTJ" || name == "W" || name == "VV" || name == "EWKZ") {
    hist->Fill(var, -1*weight);
  }
}

// histHolder contructor to create the output file, the qcd histograms with the correct binning
// and the map from categories to vectors of TH1F*'s. Each TH1F* in the vector corresponds to 
// one file that is being put into that categories directory in the output tempalte
histHolder::histHolder(std::vector<float> Bins, std::string tvar) :
  hists {
    {"mt_0jet", std::vector<TH1F *>()},
    {"mt_boosted", std::vector<TH1F *>()},
    {"mt_vbf", std::vector<TH1F *>()},
  }, 
  fout( new TFile(("Templates/template_"+tvar+".root").c_str(), "recreate") ),
  bins( Bins )
{
  for (auto it = hists.begin(); it != hists.end(); it++) {
    fout->cd();
    fout->mkdir((it->first).c_str());
    fout->cd();
  }

  qcd_0jet_OS = new TH1F("qcd_0jet_OS", "qcd_0jet_OS", bins.at(0), bins.at(1), bins.at(2));
  qcd_boosted_OS = new TH1F("qcd_boosted_OS", "qcd_boosted_OS", bins.at(0), bins.at(1), bins.at(2));
  qcd_vbf_OS = new TH1F("qcd_vbf_OS", "qcd_vbf_OS", bins.at(0), bins.at(1), bins.at(2));
  qcd_0jet_SS = new TH1F("qcd_0jet_SS", "qcd_0jet_SS", bins.at(0), bins.at(1), bins.at(2));
  qcd_boosted_SS = new TH1F("qcd_boosted_SS", "qcd_boosted_SS", bins.at(0), bins.at(1), bins.at(2));
  qcd_vbf_SS = new TH1F("qcd_vbf_SS", "qcd_vbf_SS", bins.at(0), bins.at(1), bins.at(2));
  qcd_0jet = new TH1F("qcd_0jet", "qcd_SS", bins.at(0), bins.at(1), bins.at(2));
  qcd_boosted = new TH1F("qcd_boosted", "qcd_SS", bins.at(0), bins.at(1), bins.at(2));
  qcd_vbf = new TH1F("qcd_vbf", "qcd_SS", bins.at(0), bins.at(1), bins.at(2));
}

// change to the correct output directory then create a new TH1F that will be filled for the current input file
void histHolder::initVectors(std::string name) {
  for (auto key : hists) {
    fout->cd(key.first.c_str());
    hists.at(key.first.c_str()).push_back(new TH1F(name.c_str(), name.c_str(), bins.at(0), bins.at(1), bins.at(2)));
  }
}

// write output histograms including the QCD histograms after scaling by OS/SS ratio
void histHolder::writeHistos() {
  for (auto cat : hists) {
    fout->cd(cat.first.c_str());
    for (auto hist : cat.second) {
      hist->Write();
    }
  }

  fout->cd("mt_0jet");
  qcd_0jet->SetName("QCD");
  qcd_0jet->Scale(1.0 * qcd_0jet_SS->Integral() / qcd_0jet->Integral());
  for (auto i = 0; i < qcd_0jet->GetNbinsX(); i++) {
    if (qcd_0jet->GetBinContent(i) < 0) {
      qcd_0jet->SetBinContent(i, 0);
    }
  }
  qcd_0jet->Write();

  fout->cd("mt_boosted");
  qcd_boosted->SetName("QCD");
  qcd_boosted->Scale(1.28 * qcd_boosted_SS->Integral() / qcd_boosted->Integral());
  for (auto i = 0; i < qcd_boosted->GetNbinsX(); i++) {
    if (qcd_boosted->GetBinContent(i) < 0) {
      qcd_boosted->SetBinContent(i, 0);
    }
  }
  qcd_boosted->Write();

  fout->cd("mt_vbf");
  qcd_vbf->SetName("QCD");
  qcd_vbf->Scale(1.0 * qcd_vbf_SS->Integral() / qcd_vbf->Integral());
  for (auto i = 0; i < qcd_vbf->GetNbinsX(); i++) {
    if (qcd_vbf->GetBinContent(i) < 0) {
      qcd_vbf->SetBinContent(i, 0);
    }
  }
  qcd_vbf->Write();
}
