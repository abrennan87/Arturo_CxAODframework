#include "CxAODReader/HistNameSvc.h"

#include "TString.h"
// TODO random include to get Error() and Info(). Where is it coming from?
#include "AthContainers/AuxElement.h"

HistNameSvc::HistNameSvc() {
  reset(true);
  m_name.reserve(300);
}

void HistNameSvc::reset(bool resetSample) {
  if (resetSample) {
    set_sample("None");
  }
  set_eventFlavour(-1, -1);
  set_nTag(-1);
  set_nJet(-1);
  set_pTV(-1);
  set_variation("Nominal");
}

std::string HistNameSvc::getFullHistName(const std::string& variable) {
  
  // TODO cache sub strings for speed up

  m_name.clear();

  if (!m_isNominal) {
    m_name += "Sys";
    m_name += m_variation;
    m_name += "/";
  }
  
  m_name += m_sample;
  
  if (m_useEventFlav) {
    appendEventFlavour(m_name);
  }
  
  // TODO use __ or ___ after sample?
          
  if (m_nTag < 0) m_name += "_pretag";
  else if (m_nTag == 0) m_name += "_0tag";
  else if (m_nTag == 1) m_name += "_1tag";
  else if (m_nTag == 2) m_name += "_2tag";
  else m_name += "_3ptag";
  
  if (m_nJet < 0) m_name += "xjet";
  else if (m_nJet == 0) m_name += "0jet";
  else if (m_nJet == 1) m_name += "1jet";
  else if (m_nJet == 2) m_name += "2jet";
  else if (m_nJet == 3) m_name += "3jet";
  else m_name += "4pjet";

  // TODO different implementation for MVA...
  
  if (m_pTV < 0) m_name += "_vpt0_";
  else if (m_pTV < 90e3) m_name += "_vpt0_90_";
  else if (m_pTV < 120e3) m_name += "_vpt90_120_";
  else if (m_pTV < 160e3) m_name += "_vpt120_160_";
  else if (m_pTV < 200e3) m_name += "_vpt160_200_";
  else m_name += "_vpt200_";
  
  m_name += variable;
  
  if (!m_isNominal) {
    m_name += "_Sys";
    m_name += m_variation;
  }

  return m_name;
}

std::string HistNameSvc::getEventFlavour(){
  std::string buff;
  appendEventFlavour(buff);
  return buff;
}

void HistNameSvc::appendEventFlavour(std::string& buff){

  if (m_jet0flav < 0 || m_jet1flav < 0) return;

  if       (m_jet0flav == 5 && m_jet1flav == 5)  buff += "bb";
  else if ((m_jet0flav == 5 || m_jet1flav == 5)
        && (m_jet0flav == 4 || m_jet1flav == 4)) buff += "bc";
  else if  (m_jet0flav == 5 || m_jet1flav == 5)  buff += "bl";
  else if  (m_jet0flav == 4 && m_jet1flav == 4)  buff += "cc";
  else if  (m_jet0flav == 4 || m_jet1flav == 4)  buff += "cl";
  else buff += "l";
}

std::string HistNameSvc::determineSample(const std::string& fileName) {
  
  // TODO could be nicer with std::map<std::string> fileToSample;
  
  TString name(fileName.c_str());
  std::string sampleName = "";
  if      (name.Contains("Sherpa_CT10_W")) sampleName = "W";
  else if (name.Contains("Sherpa_CT10_Z")) sampleName = "Z";
  else if (name.Contains("ttbar")) sampleName = "ttbar";
  else if (name.Contains("st_schan")) sampleName = "stops";
  else if (name.Contains("singletop_tchan")) sampleName = "stopt";
  else if (name.Contains("st_Wtchan")) sampleName = "stopWt";
  // TODO other mass points
  else if (name.Contains("_WH125_lnubb")) sampleName = "WlvH125";
  else if (name.Contains("_ZH125_nunubb")) sampleName = "qqZvvH125";
  else if (name.Contains("_ZH125_llbb")) sampleName = "qqZllH125";
  // TODO other samples ggZH, diboson, ...
  else if (name.Contains("data")) sampleName = "data";
  else {
    // TODO what is needed for Error() 
    Error("HistNameSvc::determineSample()",
            ("Unable to determine sample from file '" + fileName + "'.").c_str());
    exit(EXIT_FAILURE);
  }
  Info("HistNameSvc::determineSample()",
          ("Set sample to '" + sampleName + "'.").c_str());
  set_sample(sampleName);
  return sampleName;
}

void HistNameSvc::set_sample(const std::string& sample) {
  m_sample = sample;
  m_useEventFlav = (m_sample == "W" || m_sample == "Z");
}

void HistNameSvc::set_variation(const std::string& variation) {
  m_variation = variation;
  m_isNominal = (variation == "Nominal");
}
