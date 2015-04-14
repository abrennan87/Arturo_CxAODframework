#ifndef HistNameSvc_h
#define HistNameSvc_h

#include <string>

class HistNameSvc {

private:
  
  // buffer for the full output name
  std::string m_name;
  
  std::string m_sample;
  bool m_useEventFlav;
  int m_jet0flav;
  int m_jet1flav;
  int m_nTag;
  int m_nJet;
  float m_pTV; // MeV
  std::string m_variation;
  bool m_isNominal;

  void appendEventFlavour(std::string& buff);
  
public:
  
  HistNameSvc();
  ~HistNameSvc() {};
  
  void reset(bool resetSample = false);

  std::string getFullHistName(const std::string& variable);
  std::string getEventFlavour();
  std::string determineSample(const std::string& fileName);
  
  void set_sample(const std::string& sample);
  void set_eventFlavour(int jet0flav, int jet1flav) { m_jet0flav = jet0flav; m_jet1flav = jet1flav; }
  void set_nTag(int nTag) { m_nTag = nTag; }
  void set_nJet(int nJet) { m_nJet = nJet; }
  void set_pTV(float pTV) { m_pTV = pTV; }
  void set_variation(const std::string& variation);
  
};

#endif
