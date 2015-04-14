#ifndef CxAODTools_SuperDecorator_H
#define CxAODTools_SuperDecorator_H

#include "CxAODTools/ElectronDecorator.h"
#include "xAODEgamma/Electron.h"

#include "CxAODTools/MuonDecorator.h"
#include "xAODMuon/Muon.h"
#include "CxAODTools/TauDecorator.h"
#include "xAODTau/TauJet.h"
#include "CxAODTools/JetDecorator.h"
#include "CxAODTools/FatJetDecorator.h"
#include "xAODJet/Jet.h"

#include "CxAODTools/EventInfoDecorator.h"
#include "xAODEventInfo/EventInfo.h"

#include "CxAODTools/PhotonDecorator.h"
#include "xAODEgamma/Photon.h"

#include "CxAODTools/TruthDecorator.h"
#include "xAODTruth/TruthParticle.h"
class SuperDecorator {

  private:
    ElectronDecorator m_eldec;
    MuonDecorator m_mudec;
    TauDecorator m_taudec;
    JetDecorator m_jetdec;
    FatJetDecorator m_fatdec;
    EventInfoDecorator m_evtdec;
    PhotonDecorator m_phdec;
    TruthDecorator m_truthdec;

  public:

    SuperDecorator() = default;
    ~SuperDecorator() = default;

    /// @name Electron decorators operations
    /// @{

    char get(const xAOD::Electron* el, ElecCharProps p) { return m_eldec.get(el, p); }
    int get(const xAOD::Electron* el, ElecIntProps p) { return m_eldec.get(el, p); }
    float get(const xAOD::Electron* el, ElecFloatProps p) { return m_eldec.get(el, p); }

    bool get(const xAOD::Electron* el, ElecCharProps p, char& value) { return m_eldec.get(el, p, value); }
    bool get(const xAOD::Electron* el, ElecIntProps p, int& value) { return m_eldec.get(el, p, value); }
    bool get(const xAOD::Electron* el, ElecFloatProps p, float& value) { return m_eldec.get(el, p, value); }

    bool exists(const xAOD::Electron* el, ElecCharProps p) { return m_eldec.exists(el, p); }
    bool exists(const xAOD::Electron* el, ElecIntProps p) { return m_eldec.exists(el, p); }
    bool exists(const xAOD::Electron* el, ElecFloatProps p) { return m_eldec.exists(el, p); }

    void set(xAOD::Electron* el, ElecCharProps p, char v) { return m_eldec.set(el, p, v); }
    void set(xAOD::Electron* el, ElecIntProps p, int v) { return m_eldec.set(el, p, v); }
    void set(xAOD::Electron* el, ElecFloatProps p, float v) { return m_eldec.set(el, p, v); }

    void set(const xAOD::Electron* el, ElecCharProps p, char v) { return m_eldec.set(el, p, v); }
    void set(const xAOD::Electron* el, ElecIntProps p, int v) { return m_eldec.set(el, p, v); }
    void set(const xAOD::Electron* el, ElecFloatProps p, float v) { return m_eldec.set(el, p, v); }

    /// @}

    /// @name Muon decorators operations
    /// @{

    char get(const xAOD::Muon* mu, MuonCharProps p) { return m_mudec.get(mu, p); }
    int get(const xAOD::Muon* mu, MuonIntProps p) { return m_mudec.get(mu, p); }
    float get(const xAOD::Muon* mu, MuonFloatProps p) { return m_mudec.get(mu, p); }

    bool get(const xAOD::Muon* mu, MuonCharProps p, char& value) { return m_mudec.get(mu, p, value); }
    bool get(const xAOD::Muon* mu, MuonIntProps p, int& value) { return m_mudec.get(mu, p, value); }
    bool get(const xAOD::Muon* mu, MuonFloatProps p, float& value) { return m_mudec.get(mu, p, value); }

    bool exists(const xAOD::Muon* mu, MuonCharProps p) { return m_mudec.exists(mu, p); }
    bool exists(const xAOD::Muon* mu, MuonIntProps p) { return m_mudec.exists(mu, p); }
    bool exists(const xAOD::Muon* mu, MuonFloatProps p) { return m_mudec.exists(mu, p); }

    void set(xAOD::Muon* mu, MuonCharProps p, char v) { return m_mudec.set(mu, p, v); }
    void set(xAOD::Muon* mu, MuonIntProps p, int v) { return m_mudec.set(mu, p, v); }
    void set(xAOD::Muon* mu, MuonFloatProps p, float v) { return m_mudec.set(mu, p, v); }

    void set(const xAOD::Muon* mu, MuonCharProps p, char v) { return m_mudec.set(mu, p, v); }
    void set(const xAOD::Muon* mu, MuonIntProps p, int v) { return m_mudec.set(mu, p, v); }
    void set(const xAOD::Muon* mu, MuonFloatProps p, float v) { return m_mudec.set(mu, p, v); }

    /// @}

    /// @name Tau decorators operations
    /// @{

    char get(const xAOD::TauJet* mu, TauCharProps p) { return m_taudec.get(mu, p); }
    int get(const xAOD::TauJet* mu, TauIntProps p) { return m_taudec.get(mu, p); }
    float get(const xAOD::TauJet* mu, TauFloatProps p) { return m_taudec.get(mu, p); }

    bool get(const xAOD::TauJet* mu, TauCharProps p, char& value) { return m_taudec.get(mu, p, value); }
    bool get(const xAOD::TauJet* mu, TauIntProps p, int& value) { return m_taudec.get(mu, p, value); }
    bool get(const xAOD::TauJet* mu, TauFloatProps p, float& value) { return m_taudec.get(mu, p, value); }

    bool exists(const xAOD::TauJet* mu, TauCharProps p) { return m_taudec.exists(mu, p); }
    bool exists(const xAOD::TauJet* mu, TauIntProps p) { return m_taudec.exists(mu, p); }
    bool exists(const xAOD::TauJet* mu, TauFloatProps p) { return m_taudec.exists(mu, p); }

    void set(xAOD::TauJet* mu, TauCharProps p, char v) { return m_taudec.set(mu, p, v); }
    void set(xAOD::TauJet* mu, TauIntProps p, int v) { return m_taudec.set(mu, p, v); }
    void set(xAOD::TauJet* mu, TauFloatProps p, float v) { return m_taudec.set(mu, p, v); }

    void set(const xAOD::TauJet* mu, TauCharProps p, char v) { return m_taudec.set(mu, p, v); }
    void set(const xAOD::TauJet* mu, TauIntProps p, int v) { return m_taudec.set(mu, p, v); }
    void set(const xAOD::TauJet* mu, TauFloatProps p, float v) { return m_taudec.set(mu, p, v); }

    /// @}

    /// @name Jet decorators operations
    /// @{

    char get(const xAOD::Jet* jet, JetCharProps p) { return m_jetdec.get(jet, p); }
    int get(const xAOD::Jet* jet, JetIntProps p) { return m_jetdec.get(jet, p); }
    float get(const xAOD::Jet* jet, JetFloatProps p) { return m_jetdec.get(jet, p); }

    bool get(const xAOD::Jet* jet, JetCharProps p, char& value) { return m_jetdec.get(jet, p, value); }
    bool get(const xAOD::Jet* jet, JetIntProps p, int& value) { return m_jetdec.get(jet, p, value); }
    bool get(const xAOD::Jet* jet, JetFloatProps p, float& value) { return m_jetdec.get(jet, p, value); }

    bool exists(const xAOD::Jet* jet, JetCharProps p) { return m_jetdec.exists(jet, p); }
    bool exists(const xAOD::Jet* jet, JetIntProps p) { return m_jetdec.exists(jet, p); }
    bool exists(const xAOD::Jet* jet, JetFloatProps p) { return m_jetdec.exists(jet, p); }

    void set(xAOD::Jet* jet, JetCharProps p, char v) { return m_jetdec.set(jet, p, v); }
    void set(xAOD::Jet* jet, JetIntProps p, int v) { return m_jetdec.set(jet, p, v); }
    void set(xAOD::Jet* jet, JetFloatProps p, float v) { return m_jetdec.set(jet, p, v); }

    void set(const xAOD::Jet* jet, JetCharProps p, char v) { return m_jetdec.set(jet, p, v); }
    void set(const xAOD::Jet* jet, JetIntProps p, int v) { return m_jetdec.set(jet, p, v); }
    void set(const xAOD::Jet* jet, JetFloatProps p, float v) { return m_jetdec.set(jet, p, v); }

    /// @}

    /// @name Fat jet decorators operations
    /// @{

    char get(const xAOD::Jet* fatjet, FatJetCharProps p) { return m_fatdec.get(fatjet, p); }
    int get(const xAOD::Jet* fatjet, FatJetIntProps p) { return m_fatdec.get(fatjet, p); }
    float get(const xAOD::Jet* fatjet, FatJetFloatProps p) { return m_fatdec.get(fatjet, p); }

    bool get(const xAOD::Jet* fatjet, FatJetCharProps p, char& value) { return m_fatdec.get(fatjet, p, value); }
    bool get(const xAOD::Jet* fatjet, FatJetIntProps p, int& value) { return m_fatdec.get(fatjet, p, value); }
    bool get(const xAOD::Jet* fatjet, FatJetFloatProps p, float& value) { return m_fatdec.get(fatjet, p, value); }

    bool exists(const xAOD::Jet* fatjet, FatJetCharProps p) { return m_fatdec.exists(fatjet, p); }
    bool exists(const xAOD::Jet* fatjet, FatJetIntProps p) { return m_fatdec.exists(fatjet, p); }
    bool exists(const xAOD::Jet* fatjet, FatJetFloatProps p) { return m_fatdec.exists(fatjet, p); }

    void set(xAOD::Jet* fatjet, FatJetCharProps p, char v) { return m_fatdec.set(fatjet, p, v); }
    void set(xAOD::Jet* fatjet, FatJetIntProps p, int v) { return m_fatdec.set(fatjet, p, v); }
    void set(xAOD::Jet* fatjet, FatJetFloatProps p, float v) { return m_fatdec.set(fatjet, p, v); }

    void set(const xAOD::Jet* fatjet, FatJetCharProps p, char v) { return m_fatdec.set(fatjet, p, v); }
    void set(const xAOD::Jet* fatjet, FatJetIntProps p, int v) { return m_fatdec.set(fatjet, p, v); }
    void set(const xAOD::Jet* fatjet, FatJetFloatProps p, float v) { return m_fatdec.set(fatjet, p, v); }

    /// @}    

    /// @name Event Info decorators operations
    /// @{

    char get(const xAOD::EventInfo* evt, EventInfoCharProps p) { return m_evtdec.get(evt, p); }
    int get(const xAOD::EventInfo* evt, EventInfoIntProps p) { return m_evtdec.get(evt, p); }
    float get(const xAOD::EventInfo* evt, EventInfoFloatProps p) { return m_evtdec.get(evt, p); }

    bool get(const xAOD::EventInfo* evt, EventInfoCharProps p, char& value) { return m_evtdec.get(evt, p, value); }
    bool get(const xAOD::EventInfo* evt, EventInfoIntProps p, int& value) { return m_evtdec.get(evt, p, value); }
    bool get(const xAOD::EventInfo* evt, EventInfoFloatProps p, float& value) { return m_evtdec.get(evt, p, value); }

    bool exists(const xAOD::EventInfo* evt, EventInfoCharProps p) { return m_evtdec.exists(evt, p); }
    bool exists(const xAOD::EventInfo* evt, EventInfoIntProps p) { return m_evtdec.exists(evt, p); }
    bool exists(const xAOD::EventInfo* evt, EventInfoFloatProps p) { return m_evtdec.exists(evt, p); }

    void set(xAOD::EventInfo* evt, EventInfoCharProps p, char v) { return m_evtdec.set(evt, p, v); }
    void set(xAOD::EventInfo* evt, EventInfoIntProps p, int v) { return m_evtdec.set(evt, p, v); }
    void set(xAOD::EventInfo* evt, EventInfoFloatProps p, float v) { return m_evtdec.set(evt, p, v); }

    void set(const xAOD::EventInfo* evt, EventInfoCharProps p, char v) { return m_evtdec.set(evt, p, v); }
    void set(const xAOD::EventInfo* evt, EventInfoIntProps p, int v) { return m_evtdec.set(evt, p, v); }
    void set(const xAOD::EventInfo* evt, EventInfoFloatProps p, float v) { return m_evtdec.set(evt, p, v); }

    /// @}


    /// @name Photon decorators operations
    /// @{

    char get(const xAOD::Photon* ph, PhotCharProps p) { return m_phdec.get(ph, p); }
    int get(const xAOD::Photon* ph, PhotIntProps p) { return m_phdec.get(ph, p); }
    float get(const xAOD::Photon* ph, PhotFloatProps p) { return m_phdec.get(ph, p); }

    bool get(const xAOD::Photon* ph, PhotCharProps p, char& value) { return m_phdec.get(ph, p, value); }
    bool get(const xAOD::Photon* ph, PhotIntProps p, int& value) { return m_phdec.get(ph, p, value); }
    bool get(const xAOD::Photon* ph, PhotFloatProps p, float& value) { return m_phdec.get(ph, p, value); }

    bool exists(const xAOD::Photon* ph, PhotCharProps p) { return m_phdec.exists(ph, p); }
    bool exists(const xAOD::Photon* ph, PhotIntProps p) { return m_phdec.exists(ph, p); }
    bool exists(const xAOD::Photon* ph, PhotFloatProps p) { return m_phdec.exists(ph, p); }

    void set(xAOD::Photon* ph, PhotCharProps p, char v) { return m_phdec.set(ph, p, v); }
    void set(xAOD::Photon* ph, PhotIntProps p, int v) { return m_phdec.set(ph, p, v); }
    void set(xAOD::Photon* ph, PhotFloatProps p, float v) { return m_phdec.set(ph, p, v); }

    void set(const xAOD::Photon* ph, PhotCharProps p, char v) { return m_phdec.set(ph, p, v); }
    void set(const xAOD::Photon* ph, PhotIntProps p, int v) { return m_phdec.set(ph, p, v); }
    void set(const xAOD::Photon* ph, PhotFloatProps p, float v) { return m_phdec.set(ph, p, v); }

    /// @}

    /// @name Truth decorators operations
    /// @{

    char get(const xAOD::TruthParticle* ph, TruthCharProps p) { return m_truthdec.get(ph, p); }
    int get(const xAOD::TruthParticle* ph, TruthIntProps p) { return m_truthdec.get(ph, p); }
    float get(const xAOD::TruthParticle* ph, TruthFloatProps p) { return m_truthdec.get(ph, p); }

    bool get(const xAOD::TruthParticle* ph, TruthCharProps p, char& value) { return m_truthdec.get(ph, p, value); }
    bool get(const xAOD::TruthParticle* ph, TruthIntProps p, int& value) { return m_truthdec.get(ph, p, value); }
    bool get(const xAOD::TruthParticle* ph, TruthFloatProps p, float& value) { return m_truthdec.get(ph, p, value); }

    bool exists(const xAOD::TruthParticle* ph, TruthCharProps p) { return m_truthdec.exists(ph, p); }
    bool exists(const xAOD::TruthParticle* ph, TruthIntProps p) { return m_truthdec.exists(ph, p); }
    bool exists(const xAOD::TruthParticle* ph, TruthFloatProps p) { return m_truthdec.exists(ph, p); }

    void set(xAOD::TruthParticle* ph, TruthCharProps p, char v) { return m_truthdec.set(ph, p, v); }
    void set(xAOD::TruthParticle* ph, TruthIntProps p, int v) { return m_truthdec.set(ph, p, v); }
    void set(xAOD::TruthParticle* ph, TruthFloatProps p, float v) { return m_truthdec.set(ph, p, v); }

    void set(const xAOD::TruthParticle* ph, TruthCharProps p, char v) { return m_truthdec.set(ph, p, v); }
    void set(const xAOD::TruthParticle* ph, TruthIntProps p, int v) { return m_truthdec.set(ph, p, v); }
    void set(const xAOD::TruthParticle* ph, TruthFloatProps p, float v) { return m_truthdec.set(ph, p, v); }

    /// @}

};

#endif
