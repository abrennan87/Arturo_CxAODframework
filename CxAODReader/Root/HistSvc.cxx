#include "CxAODReader/HistSvc.h"
#include <stdexcept> 
#include <TROOT.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TH2F.h>

#include <utility>
using std::pair;
#include <sstream>
#include <iostream>
#include <string>

HistSvc::HistSvc() :
  m_nameSvc(nullptr),
  m_wk(0)
{
  TH1::AddDirectory(false);
  gROOT->SetBatch(true);

  m_trees = new unordered_map<string, TTree*>;
}

HistSvc::~HistSvc() {
  //  if (m_hists) {delete m_hists; m_hists = 0;}
}

void HistSvc::Reset() {
  // Clear all hists from store, freeing up memory
  for (auto entry : m_hists) {
    if (entry.second) delete entry.second;
  }
  m_hists.clear();

  if (m_trees) {    
    treestore_t::const_iterator treeItr(m_trees->begin());
    treestore_t::const_iterator treeEnd(m_trees->end());
    
    for ( ; treeItr != treeEnd; ++treeItr) {
      if (treeItr->second) delete treeItr->second;    
    }
    
    m_trees->clear();
    delete m_trees; 
    m_trees = 0;
  }

  m_trees = new unordered_map<string, TTree*>;

}


TH1* HistSvc::FindHistInMap(const string& fullname){
  TH1* hist = nullptr;
  try {
    hist=m_hists.at(fullname);
  } catch (const std::out_of_range& oor) {
    return nullptr;
  }
  return hist;
}

TH1* HistSvc::BookHist(const string& name, int nbinsx, float xlow, float xup) {

  string fullname = name;
  if (m_nameSvc) {
    fullname = m_nameSvc -> getFullHistName(name);
  }

  TH1* hist=FindHistInMap(fullname);
  if(hist == 0) {
    string hname = histName(fullname);    
    hist = new TH1F(hname.c_str(), hname.c_str(), nbinsx, xlow, xup);
    hist->Sumw2();
    m_hists[fullname]=hist;
  }
  return hist;
}


void HistSvc::BookFillHist(const string& name, int nbinsx, float xlow, float xup, float value, float weight) {
  BookHist(name, nbinsx, xlow, xup) -> Fill(value, weight);
}

TH1* HistSvc::BookHist(const string& name, int nbinsx, float* xbins) {

  string fullname = name;
  if (m_nameSvc) {
    fullname = m_nameSvc -> getFullHistName(name);
  }

  TH1* hist=FindHistInMap(fullname);
  if(hist == 0) {    
    string hname = histName(fullname);    
    hist = new TH1F(hname.c_str(), hname.c_str(), nbinsx, xbins);
    hist->Sumw2();
    m_hists[fullname]=hist;
  }
  return hist;
}

void HistSvc::BookFillHist(const string& name, int nbinsx, float* xbins, float value, float weight) {
  BookHist(name, nbinsx, xbins)->Fill(value, weight);
}
  
TH1* HistSvc::BookHist(const string& name, int nbinsx, float xlow, float xup, int nbinsy, float ylow, float yup) {
  
  string fullname = name;
  if (m_nameSvc) {
    fullname = m_nameSvc -> getFullHistName(name);
  }

  TH1* hist=FindHistInMap(fullname);
  if(hist == 0) {    
    string hname = histName(fullname);
    hist = new TH2F(hname.c_str(), hname.c_str(), nbinsx, xlow, xup, nbinsy, ylow, yup);
    hist->Sumw2();
    m_hists[fullname]=hist;
  }

  return hist;
}

void HistSvc::BookFillHist(const string& name, int nbinsx, float xlow, float xup, int nbinsy, float ylow, float yup, float xvalue, float yvalue, float weight) {
  static_cast<TH2F*>(BookHist(name, nbinsx, xlow, xup, nbinsy, ylow, yup)) -> Fill(xvalue, yvalue, weight);
}
 
TH1* HistSvc::BookHist(const string& name, int nbinsx, float* xbins, int nbinsy, float* ybins) {

  string fullname = name;
  if (m_nameSvc) {
    fullname = m_nameSvc -> getFullHistName(name);
  }

  TH1* hist=FindHistInMap(fullname);
  if(hist == 0) {    
    string hname = histName(fullname);
    hist = new TH2F(hname.c_str(), hname.c_str(), nbinsx, xbins, nbinsy, ybins);
    hist->Sumw2();
    m_hists[fullname]=hist;
  }

  return hist;
}

void HistSvc::BookFillHist(const string& name, int nbinsx, float* xbins, int nbinsy, float* ybins, float xvalue, float yvalue, float weight) {
  static_cast<TH2F*>(BookHist(name, nbinsx, xbins, nbinsy, ybins)) -> Fill(xvalue, yvalue, weight);
}

TTree* HistSvc::BookTree(const string& name, const string& branchName, void* address, const std::string& leaves) {
  TTree* tree;
  string fullname = name;
  string tname = histName(name);
  treestore_t::const_iterator treeItr = m_trees->find(fullname);
  if (treeItr == m_trees->end()) {
    tree = new TTree(tname.c_str(), tname.c_str());
    tree->SetDirectory(0); 
    tree->Branch(branchName.c_str(), address, leaves.c_str());
    (*m_trees)[fullname] = tree;
  } else {
    tree = (*m_trees)[fullname];
  }
  
  return tree;
}

void HistSvc::BookFillTree(const string& name, const string& branchName, void* address, const std::string& leaves) {
  BookTree(name, branchName, address, leaves)->Fill();
}

TTree* HistSvc::BookTree(const string& name, const string& branchName, double* address) {
  TTree* tree;
  string fullname = name;
  string tname = histName(name);
  treestore_t::const_iterator treeItr = m_trees->find(fullname);
  if (treeItr == m_trees->end()) {
    tree = new TTree(tname.c_str(), tname.c_str());
    tree->SetDirectory(0); 

    char* names = const_cast<char*>(branchName.c_str());
    char* pch = strtok (names,":");
    int i(0);
    
    while (pch) {
      tree->Branch(pch, address+i++);
      pch = strtok(0, ":");      
    }

    (*m_trees)[fullname] = tree;
  } else {
    tree = (*m_trees)[fullname];
  }
  
  return tree;
}

void HistSvc::BookFillTree(const string& name, const string& branchName, double* address) {
  BookTree(name, branchName, address)->Fill();
}

TH1* HistSvc::BookCutHist(const string& name, int nbinsx, string cuts[]) {
   
  string fullname = name;
  
  // no automatic names for cut flow hists currently
  //if (m_nameSvc) {
  //  fullname = m_nameSvc -> getFullHistName(name);
  //}
  
  TH1* hist=FindHistInMap(fullname);
  
  if(hist==0) {
    string hname = histName(name);
    hist = new TH1D(hname.c_str(), hname.c_str(), nbinsx, -0.5, nbinsx-0.5);
    hist->Sumw2();
    m_hists[fullname]=hist;
    for(int i=0; i<nbinsx; i++) {
      hist->GetXaxis()->SetBinLabel(i+1,cuts[i].c_str());
    }
  }
  
  return hist;
}


void HistSvc::BookFillCutHist(const string& name, int nbinsx, string cuts[], string label, float weight) {

  TH1* hist = BookCutHist(name, nbinsx, cuts);
  int ibin = hist->GetXaxis()->FindBin(label.c_str());
  hist->Fill(ibin-1, weight);
}

void HistSvc::Write() {

  // EventLoop: add the histograms to the TList output objects of the Worker
  for (auto entry : m_hists) {
    TH1* hist = entry.second;
    hist->SetName(entry.first.c_str());
    m_wk->addOutput(hist);
  }

  // EventLoop: add the trees to the TList output objects of the Worker
  //for (auto entry : m_trees) {
  for ( auto entry = m_trees->begin(); entry != m_trees->end(); ++entry ) {
    TTree* tree = entry->second;
    tree->SetName(entry->first.c_str());
    m_wk->addOutput(tree);
  }
  
  // EventLoop seems to take care of deleting histograms
}

string HistSvc::histName(const string name) {
  std::string::size_type idelim = name.find_last_of("/");
  if (idelim == std::string::npos) return name;
  return name.substr(idelim+1);
}

string HistSvc::dirName(const string name) {
  std::string::size_type idelim = name.find_last_of("/");
  if (idelim == std::string::npos) return string("");
  return name.substr(0, idelim);
}

