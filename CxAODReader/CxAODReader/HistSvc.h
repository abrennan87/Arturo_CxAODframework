#ifndef HistSvc_h
#define HistSvc_h

#include <TH1.h>
#include <TFile.h>
#include <TTree.h>

#include "EventLoop/Worker.h"

#include "CxAODReader/HistNameSvc.h"

#include <map>
using std::map;
#include <string>
using std::string;
#include <string>
using std::vector;
#include <unordered_map>
using std::unordered_map;

class Worker;

class HistSvc {

public:

  HistSvc();
  ~HistSvc();

  TH1* BookHist(const string& name, int nbinsx, float xlow, float xup);
  TH1* BookHist(const string& name, int nbinsx, float* xbins);
  TH1* BookHist(const string& name, int nbinsx, float xlow, float xup, int nbinsy, float ylow, float yup);
  TH1* BookHist(const string& name, int nbinsx, float* xbins, int nbinsy, float* ybins);

  void BookFillHist(const string& name, int nbinsx, float xlow, float xup, float value, float weight=1);
  void BookFillHist(const string& name, int nbinsx, float* xbins, float value, float weight=1);
  void BookFillHist(const string& name, int nbinsx, float xlow, float xup, int nbinsy, float ylow, float yup, float xvalue, float yvalue, float weight=1);
  void BookFillHist(const string& name, int nbinsx, float* xbins, int nbinsy, float* ybins, float xvalue,  float yvalue, float weight=1);


  TTree* BookTree(const string& name, const string& branchName, void* address, const std::string& leaves);
  TTree* BookTree(const string& name, const string& branchName, double* address);

  void BookFillTree(const string& name, const string& branchName, void* address, const std::string& leaves);
  void BookFillTree(const string& name, const string& branchName, double* address);

  TH1* BookCutHist(const string& name, int nbinsx, string cuts[]);
  void BookFillCutHist(const string& name, int nbinsx, string cuts[], string label, float weight);

  void Write(TFile* file);
  void Write();

  void Reset();
  TH1* FindHistInMap(const string& name);

  void SetWorker(EL::Worker* wk) {m_wk=wk;}
  void SetNameSvc(HistNameSvc* nameSvc) {m_nameSvc = nameSvc;}


private:

  unordered_map<string, TH1*> m_hists ;  

  typedef unordered_map<string, TTree*> treestore_t;  
  treestore_t* m_trees;

  HistNameSvc* m_nameSvc;
  EL::Worker* m_wk;
  
  string histName(const string name);
  string dirName(const string name);

};

#endif
