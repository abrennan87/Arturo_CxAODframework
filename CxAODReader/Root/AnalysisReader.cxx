#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include "EventLoop/OutputStream.h"
#include <CxAODReader/AnalysisReader.h>

#include "xAODEventInfo/EventInfo.h"
#include "xAODBTagging/BTagging.h" 

#include "TLorentzVector.h"
#include "TSystem.h"
#include "TFile.h"
using namespace std;

#define length(array) (sizeof(array)/sizeof(*(array)))

// this is needed to distribute the algorithm to the workers
ClassImp(AnalysisReader)



AnalysisReader :: AnalysisReader () :
  m_eventInfoReader(nullptr),
  m_METReader(nullptr),
  m_electronReader(nullptr),
  m_photonReader(nullptr),
  m_muonReader(nullptr),
  m_tauReader(nullptr),
  m_jetReader(nullptr),
  m_analysisType(-1),
  m_eventCounter(0),
  m_isMC(false),
  m_weight(1.),
  m_sumOfWeights(1.),
  m_isSherpaVJets(0),
  m_isSherpaPt0WJets(0),
  m_isSherpaPt0ZJets(0),
  m_SherpaPt0WJetsCut(40000),
  m_SherpaPt0ZJetsCut(70000),
  m_isE(0),
  m_isMu(0),
  m_config(nullptr),
  m_configPath("data/FrameworkExe/framework-read.cfg"),
  m_debug(0),
  m_nominalOnly(0),
  m_autoDiscoverVariations(0),
  m_passThroughOR(0),
  m_isNotInFile(0),
  m_histSvc(nullptr),
  m_histNameSvc(nullptr)
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().

}



EL::StatusCode AnalysisReader :: setupJob (EL::Job& job)
{
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.
  job.useXAOD ();

  // let's initialize the algorithm to use the xAODRootAccess package
  xAOD::Init( "MyxAODAnalysis" ).ignore(); // call before opening first file

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode AnalysisReader :: histInitialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.

  if (m_histSvc) {
    // TODO why is histInitialize() called after fileExecute() ??
    Warning("histInitialize()", "Histograms already initialized! Skipping histInitialize()...");
    return EL::StatusCode::SUCCESS;
  }

  Info("histInitialize()", "Analysis type %i", m_analysisType ); 

  if (m_analysisType==VBF1ph)
    histInitialize_VBF1ph();
  else if (m_analysisType==monoWZH)
    histInitialize_monoWZH();

  // Try a histogram manager
  m_histSvc = new HistSvc();
  m_histNameSvc = new HistNameSvc();
  m_histSvc -> SetNameSvc(m_histNameSvc);
  
  // some histograms useful for all analyses
  // Truth pt
  m_hist_VPtTruth = new TH1F("VptTruth","V pt truth; V pt truth [GeV]; Events",100,0,1000);
  m_hist_VPtTruth->Sumw2();
  wk()->addOutput(m_hist_VPtTruth);
      
  // b-tagging flavour plots
  bTaggerHists(0); // 0 for booking histograms

  // a Tree with the luminosity
  m_histSvc -> BookFillTree("MetaData","luminosity",&m_luminosity,"m_luminosity");

  //pass worker to histogram manager
  m_histSvc->SetWorker(wk());  

  return EL::StatusCode::SUCCESS;

}

EL::StatusCode AnalysisReader :: bTaggerHists(int bookfill, const xAOD::Jet *jet)
{
  // bookfill 0/1 for booking/filling
  // fills histograms per jet and jet flavour for a list of b-taggers

  if(bookfill==0) {
    TString taggers[6]={"SV1_IP3D","MV1","MV2c00","MV2c10","MV2c20","MVb"};
    TString flavs[3]={" L"," C"," B"};
    
    for (auto &tagger : taggers) {
      TString hbasename(tagger);
      float xmin=-1.1; float xmax=1.1; 
      if (hbasename.Contains("SV1_IP3D")) {xmin=-30; xmax=80;}
      for (auto &flav : flavs) {
	TString hname(hbasename); 
	hname+=flav;
	m_hist_taggers[hname] = new TH1F(TString("Taggers/"+hname),TString(";"+hname+";Events"),110,xmin,xmax);
	m_hist_taggers[hname]->Sumw2();
	wk()->addOutput(m_hist_taggers[hname]);
      }
    }

  } else if (bookfill==1) {

    if (!jet) return EL::StatusCode::SUCCESS;
    
    int label(1000);
    jet->getAttribute<int>("TruthLabelID", label);
    //    std::cout << " label " << label << std::endl;
    float sv1_plus_IP3D=m_superDecorator.get(jet,JetFloatProps::SV1_IP3D);
    float mv1=m_superDecorator.get(jet,JetFloatProps::MV1);
    float mv2c00=m_superDecorator.get(jet,JetFloatProps::MV2c00);
    float mv2c10=m_superDecorator.get(jet,JetFloatProps::MV2c10);
    float mv2c20=m_superDecorator.get(jet,JetFloatProps::MV2c20);
    float mvb=m_superDecorator.get(jet,JetFloatProps::MVb);
    
    TString flav(" L");
    if (label==4) flav=" C";
    else if (label==5) flav=" B";
    m_hist_taggers["SV1_IP3D"+flav]->Fill(sv1_plus_IP3D,m_weight);
    m_hist_taggers["MV1"+flav]->Fill(mv1,m_weight);
    m_hist_taggers["MV2c00"+flav]->Fill(mv2c00,m_weight);
    m_hist_taggers["MV2c10"+flav]->Fill(mv2c10,m_weight);
    m_hist_taggers["MV2c20"+flav]->Fill(mv2c20,m_weight);
    m_hist_taggers["MVb"+flav]->Fill(mvb,m_weight);
    
  }

  return EL::StatusCode::SUCCESS;

}

EL::StatusCode AnalysisReader :: histInitialize_VBF1ph()
{

  // TODO
  //buffer = prefix+"pTPh"; nbins= 100.; min = 0.; max =500.;
  //buffer = prefix+"minDEtaBPh"; nbins = 100.; min = 0.; max = 5.;
  //buffer = prefix+"mBBPh"; nbins = 100.; min = 0.; max = 750.;
 
  // Cut flow hist
  static std::string cuts [8] = {"All", "GRL", "ZPV", "4Jet", "2SigJet", "1Ph", "Mbb", "Mjj"};

  m_hist_1ph_CutFlow = new TH1D("CutFlow", "CutFlow", 8, 0.5, 8.5);
  for(int iBin=0; iBin<8; ++iBin){
    m_hist_1ph_CutFlow->GetXaxis()->SetBinLabel(iBin+1,cuts[iBin].c_str());
  }
  wk()->addOutput(m_hist_1ph_CutFlow);
  // Cut flow hist no weight
  m_hist_1ph_CutFlow_noWght = new TH1D("CutFlow", "CutFlow", 8, 0.5, 8.5);
  for(int iBin=0; iBin<8; ++iBin){
    m_hist_1ph_CutFlow_noWght->GetXaxis()->SetBinLabel(iBin+1,cuts[iBin].c_str());
  }
  wk()->addOutput(m_hist_1ph_CutFlow_noWght);

  
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: histInitialize_monoWZH()			// this section added by AB (14/4/15), copied directly from old (2.0.22) CxAOD framework. TODO: work out how new code initialises histograms for eg 0lep.
{

  TH1::SetDefaultSumw2();
  TString buffer;
  int nbins;
  double min;
  double max;
  static std::string cuts [11] = {"All", "pre-selection", "met250", "met350", "one fatjet", "lep veto", "phot veto", "addjetveto", "metjetOL", "500met" ,"mJ"};
  // before any pre-selection
  buffer = "Before pre-selection fatjet Mass"; nbins = 100; min = 0; max = 1000 ;
  m_hist_mono_prepre_fatjetm = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_prepre_fatjetm);

  buffer = "Before pre-selection fatjet p_{T}"; nbins = 100; min = 0; max = 1000 ;
  m_hist_mono_prepre_fatjetpt = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_prepre_fatjetpt);

  //pre-selection
  buffer = "Pre-selection E_{T}^{miss}"; nbins = 60; min = 200.; max = 2000. ;
  m_hist_mono_pre_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_MET);

  buffer = "Pre-selection #Phi(MET)"; nbins = 16; min = -4.; max = 4. ;
  m_hist_mono_pre_METPhi = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_METPhi);

  buffer = "Pre-selection Fatjet Multiplicity"; nbins = 7; min = -0.5; max = 6.5 ;
  m_hist_mono_pre_Nfatjet = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_Nfatjet);

  buffer = "Pre-selection fatjet Mass"; nbins = 100; min = 0; max = 1000 ;
  m_hist_mono_pre_fatjetm = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_fatjetm);

  buffer = "Pre-selection fatjet p_{T}"; nbins = 100; min = 0; max = 1000 ;
  m_hist_mono_pre_fatjetpt = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_fatjetpt);

  buffer = "Pre-selection fatjet Eta"; nbins = 10; min = 0; max = 10 ;
  m_hist_mono_pre_fatjeteta = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_fatjeteta);

   buffer = "Pre-selection jet Mass"; nbins = 50; min = 0; max = 500 ;
  m_hist_mono_pre_jetm = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_jetm);

  buffer = "Pre-selection jet p_{T}"; nbins = 100; min = 0; max = 1000 ;
  m_hist_mono_pre_jetpt = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_jetpt);

    buffer = "Pre-selection jet Eta"; nbins = 10; min = 0; max = 5 ;
  m_hist_mono_pre_jeteta = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_pre_jeteta);


  //cutflow
  buffer = "Cutflow"; nbins = 11; min = 0.5; max = 11.5 ;
  m_hist_mono_cutflow = new TH1D(TString(buffer),TString(buffer),nbins, min, max);
  for(unsigned int i=0; i<11; i++) {
    m_hist_mono_cutflow->GetXaxis()->SetBinLabel(i+1,cuts[i].c_str());
  }
  wk()->addOutput(m_hist_mono_cutflow);

  buffer = "Cutflow_noweight"; nbins = 11; min = 0.5; max = 11.5 ;
  m_hist_mono_cutflow_noweight = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  for(unsigned int i=0; i<11; i++) {
    m_hist_mono_cutflow_noweight->GetXaxis()->SetBinLabel(i+1,cuts[i].c_str());
  }
  wk()->addOutput(m_hist_mono_cutflow_noweight);

  buffer = "MET250 cutflow MET"; nbins = 180; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_met250_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_met250_MET);

  buffer = "MET350 cutflow MET"; nbins = 180; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_met350_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_met350_MET);

  buffer = "fatjet cutflow MET"; nbins = 180; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_fjet_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_fjet_MET);

  buffer = "lepveto cutflow MET"; nbins = 180; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_lepveto_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_lepveto_MET);

  buffer = "photveto cutflow MET"; nbins = 180; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_photveto_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_photveto_MET);

  buffer = "jetveto cutflow MET"; nbins = 180; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_jetveto_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_jetveto_MET);

  buffer = "metjetOL cutflow MET"; nbins = 180; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_metjetOL_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_metjetOL_MET);

  buffer = "MET cutflow MET"; nbins = 180; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_met_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_met_MET);

  buffer = "m(fatjet) cutflow MET"; nbins = 60; min = 200.; max = 2000. ;
  m_hist_mono_cutflow_mj_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_mj_MET);

  buffer = "Signal Fatjet Multiplicity"; nbins = 7; min = -0.5; max = 6.5 ;
  m_hist_mono_cutflow_Nsigfjet = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_Nsigfjet);

  buffer = "#Delta R(fatjet ,addjet)"; nbins = 10; min = 0.; max = 3. ;
  m_hist_mono_cutflow_fjetaddjetDeltaR = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_cutflow_fjetaddjetDeltaR);

  //n-1 histogram

  buffer = "met250 n-1"; nbins = 60; min = 0.; max = 1800. ;
  m_hist_nminusone_met250 = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_met250);

  buffer = "met350 n-1"; nbins = 60; min = 0.; max = 1800. ;
  m_hist_nminusone_met350 = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_met350);

  buffer = "fatjet n-1 signal fatjet Multiplicity"; nbins = 6; min = -0.5; max = 5.5 ;
  m_hist_nminusone_fjet = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_fjet);

  buffer = "lepveto n-1 sig lepton Multiplicity"; nbins = 10; min = -0.5; max = 9.5 ;
  m_hist_nminusone_lepveto = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_lepveto);

  buffer = "photveto n-1 sig photon Multiplicity"; nbins = 10; min = -0.5; max = 9.5 ;
  m_hist_nminusone_photveto = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_photveto);

  buffer = "addjetveto n-1 sig addjet Multiplicity"; nbins = 10; min = -0.5; max = 9.5 ;
  m_hist_nminusone_jetveto = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_jetveto);

  buffer = "met-jet overlap n-1 (overlapping multiplicity)"; nbins = 7; min = -3.5; max = 3.5 ;
  m_hist_nminusone_metjetOL = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_metjetOL);

  buffer = "met500 n-1"; nbins = 60; min = 0.; max = 1800. ;
  m_hist_nminusone_met500 = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_met500);

  buffer = "mJ n-1"; nbins = 50; min = 0.; max = 200. ;
  m_hist_nminusone_mj = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_nminusone_mj);

  buffer = "Efficiency E_{T}^{miss}"; nbins = 60; min = 200.; max = 2000. ;
  m_hist_mono_eff_MET = new TH1F(TString(buffer),TString(buffer),nbins, min, max);
  wk()->addOutput(m_hist_mono_eff_MET);


  return EL::StatusCode::SUCCESS;
}


EL::StatusCode AnalysisReader :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed
  //std::cout << "fileExecute Input file is " << wk()->inputFile()->GetName() << std::endl;

  if (!m_histSvc) {
    // TODO why is histInitialize() called after fileExecute() ??
    Warning("fileExecute()", "Histograms not initialized! Calling histInitialize()...");
    histInitialize();
  }

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode AnalysisReader :: changeInput (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  
  // It seems PROOF-lite needs the file initialization here

  TFile* inputfile=wk()->inputFile();
  TString filename(inputfile->GetName());

  Info("changeInput()", "Processing file '%s'", filename.Data());

  m_sumOfWeights=1.0;
  TH1* metahist= (TH1*)inputfile->Get("MetaData_EventCount");
  if (metahist) {
    double nevents=metahist->GetBinContent(7);
    m_sumOfWeights=metahist->GetBinContent(8);
    std::cout << " Number of Events/Sum of weights on xAOD " << nevents << " " << m_sumOfWeights << std::endl;
  }

  m_isSherpaPt0WJets = (filename.Contains("Sherpa_CT10_W") && filename.Contains("Pt0") && m_comEnergy=="13TeV");
  m_isSherpaPt0ZJets = (filename.Contains("Sherpa_CT10_Z") && filename.Contains("Pt0") && m_comEnergy=="13TeV");

  // general Sherpa flag
  m_isSherpaVJets = (filename.Contains("Sherpa"));

  m_histNameSvc -> determineSample(filename.Data());

  //FIX for CxAOD_00-00-06
  if(filename.Contains("CxAOD_00-00-06")){
    Warning("fileExecute ()", "With CxAOD_00-00-06 it is not possible to run OR tool - set to pass through mode!");
    Warning("fileExecute ()", "With CxAOD_00-00-06 it is not possible to run photons or taus!");
    m_isNotInFile = true;
  }  

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode AnalysisReader :: initialize ()
{
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.
  
  
  EL_CHECK("initialize()",initializeEvent());
  EL_CHECK("initialize()",initializeReader());
  EL_CHECK("initialize()",initializeSelection());
  EL_CHECK("initialize()",initializeIsMC());
  EL_CHECK("initialize()",initializeXSections());
  EL_CHECK("initialize()",initializeSumOfWeights());
  EL_CHECK("initialize()",initializeVariations());
  
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: initializeEvent()
{
  Info("initializeEvent()", "Initialize event.");
  
  m_event = wk()->xaodEvent();

  Info("initialize()", "Number of events on first file = %lli", m_event->getEntries() ); // print long long int
  
  m_eventCounter = 0;

  // get configuration from steerfile
  //----------------------------------
  m_config = ConfigStore::createStore(m_configPath, false);
  if ( ! m_config ) {
    Error("initialize()","Couldn't create ConfigStore from file : %s",m_configPath.c_str());
    return EL::StatusCode::FAILURE;
  }
  m_config->getif< bool >("debug", m_debug);
  m_config->getif< bool >("nominalOnly", m_nominalOnly);
  m_config->getif< bool >("autoDiscoverVariations", m_autoDiscoverVariations);
  m_config->getif<bool>("passThroughOR", m_passThroughOR);
  if(m_passThroughOR) Warning("AnalysisReader :: AnalysisReader ()","Set OR to pass-through mode!");

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: initializeReader()
{
  Info("initializeReader()", "Initialize object reader.");

  // note: the names of the readers determine which collections are
  //       read, see also framework-read.cfg

  m_eventInfoReader = registerReader<xAOD::EventInfo>("eventInfo");
  m_METReader       = registerReader<xAOD::MissingETContainer>("MET");
  m_electronReader  = registerReader<xAOD::ElectronContainer>("electron");
  m_photonReader    = registerReader<xAOD::PhotonContainer>("photon");
  m_muonReader      = registerReader<xAOD::MuonContainer>("muon");
  m_tauReader       = registerReader<xAOD::TauJetContainer>("tau");
  m_jetReader       = registerReader<xAOD::JetContainer>("jet");
  m_fatJetReader    = registerReader<xAOD::JetContainer>("fatJet");
  m_truthParticleReader = registerReader<xAOD::TruthParticleContainer>("truthParticle");
 
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: initializeSelection()
{
  Info("initializeEvent()", "Initialize analysis '%i'.", m_analysisType);

  if (m_analysisType==e0Lep) 
    m_eventSelection = new VHbb0lepEvtSelection(); 
  else if (m_analysisType==e1Lep) 
    m_eventSelection = new VHbb1lepEvtSelection(); 
  else if (m_analysisType==e2Lep) 
    m_eventSelection = new VHbb2lepEvtSelection(); 
  else if (m_analysisType==VBF0ph)
    m_eventSelection = new VBFHbb0phEvtSelection();
  else if (m_analysisType==VBF1ph)
    m_eventSelection = new VBFHbb1phEvtSelection();
  else if (m_analysisType==monoWZH)
    m_eventSelection = new VHbb0lepEvtSelection();
  else {
    Error("initialize()", "Invalid analysis type %i", m_analysisType);
    return EL::StatusCode::FAILURE;
  }
  
  m_overlapRemoval = new OverlapRemoval(*m_config);
  m_overlapRemoval -> initialize();

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: initializeIsMC()
{
  Info("initializeReader()", "Initialize isMC.");
  // get nominal event info
  //-------------------------------------------------------------
  const xAOD::EventInfo* eventInfo = m_eventInfoReader->getObjects("Nominal");
  if(!eventInfo) return EL::StatusCode::FAILURE;

  // get MC flag - different info on data/MC files
  //-----------------------------------------------
  m_isMC=m_superDecorator.get(eventInfo, EventInfoIntProps::isMC);
  Info("initialize()", "isMC = %i", m_isMC );

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: initializeXSections()
{
  Info("initializeReader()", "Initialize cross sections.");

  if (m_isMC) {
    std::string xSectionFile = gSystem->Getenv("ROOTCOREBIN");
    if(m_comEnergy=="13TeV") 
      xSectionFile += "/data/FrameworkSub/XSections_13TeV.txt";
    else if (m_comEnergy=="8TeV") 
      xSectionFile += "/data/FrameworkSub/XSections_8TeV.txt";
    else {
      Error("initialize()", "Unknown COM energy. Exiting. %s",m_comEnergy.Data());
      return EL::StatusCode::FAILURE;
    }
    m_xSection = new XSectionProvider(xSectionFile);
  }

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: initializeSumOfWeights()
{
  Info("initializeReader()", "Initialize sum of weights.");

  if (m_isMC) {
    // which analysis
    std::string ana_read = "";
    if (m_analysisType==e0Lep) ana_read = "0lep";
    else if (m_analysisType==e1Lep) ana_read = "1lep";
    else if (m_analysisType==e2Lep) ana_read = "2lep";
    else if (m_analysisType==monoWZH) ana_read = "0lep";
    else {
      Warning("histInitialize()", "Invalid analysis type %i",m_analysisType);
      return EL::StatusCode::FAILURE;
    }
    //
    std::string sumOfWeightsFile = gSystem->Getenv("ROOTCOREBIN");
    sumOfWeightsFile += "/data/FrameworkSub/yields.";
    sumOfWeightsFile += ana_read;
    if(m_comEnergy=="13TeV") sumOfWeightsFile += ".13TeV.txt";
    else if (m_comEnergy=="8TeV") sumOfWeightsFile += ".8TeV.txt";
    else {
      Error("initialize()", "Unknown COM energy. Exiting. %s",m_comEnergy.Data());
      return EL::StatusCode::FAILURE;
    }
    m_sumOfWeights_fix = new sumOfWeightsProvider(sumOfWeightsFile);
  }

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: initializeVariations()
{
  Info("initializeReader()", "Initialize systematic variations.");

  m_variations.clear();
  m_variations.push_back("Nominal"); // Nominal is always present
  // if do syst variations
  if (!m_nominalOnly){
    TTree* collectionTree = dynamic_cast<TTree*>(wk()->inputFile()->Get("CollectionTree"));
    for (ObjectReaderBase* reader: m_objectReader) {
      reader->discoverVariations(collectionTree);
    }
    // get variations from config file
    if(!m_autoDiscoverVariations) {
      // Original (not calibrated)
      //m_variations.push_back("Original");
      std::vector<std::string> variations;
      m_config->getif< std::vector<std::string> >("variations", variations);
      if(!variations.size()) Warning("initialize()","No list of systematics specified in config file!");
      std::vector<std::string> pulls = {"1down", "1up"};
      for (std::string name : variations) {
	for (std::string pull : pulls) {
	  bool isAvailable = false;
	  std::string systName = name+"__" + pull;
	  //make sure the requested systematic is available in the input
	  for (ObjectReaderBase* reader : m_objectReader) {
	    for (std::string varName: reader->getVariations()){
	      if (varName.find(systName) != std::string::npos){
		isAvailable = true;
		break;
	      }
	    }
	  }
	  if(!isAvailable){
	    Warning("initialize()","Systematic variation %s not available in input! Skip it!", name.c_str());
	    continue;
	  }
	  else m_variations.push_back(systName.c_str());
	}
      }
    }
    else { 
      // get variations from collection tree
      for (ObjectReaderBase* reader : m_objectReader) {
	for (std::string varName: reader->getVariations()){
	  // ensure to use each systematic once
	  // would like to use set, but need to run Nominal first for OR (bug in EDM?)
	  bool found = false;
	  for (std::string varName1: m_variations) {
	    if (varName1 == varName){
	      found = true;
	      break;
	    }
	  }
	  if (!found) m_variations.push_back(varName);
	}
      }
    }
    //print variations to screen
    if(!m_autoDiscoverVariations) Info("initialize()", "Running variations sepcified in config file: ");
    else  Info("initialize()", "Running all variations found in CollectionTree: ");
    for (std::string varName: m_variations){
      std::cout << varName << std::endl;
    }
  }
  else{
    Info("initialize()", "Running NOMINAL only!");
    if(m_autoDiscoverVariations) Warning("initialize()", "Need to correct settings in config: both autoDiscoverVariations and nominalOnly are set to true!");
  }

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: execute ()
{
  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  // print every 10000 events
  if( (m_eventCounter % 10000) ==0 ) Info("execute()", "Event number = %i", m_eventCounter );
  m_eventCounter++;

  // determine if it is a Sherpa Pt0 sample, and remove events overlapping with slice (flag set for 13TeV only)
  float vpt_truth(-999);
  if (m_isSherpaVJets) {
    const xAOD::TruthParticleContainer* truthParts = m_truthParticleReader->getObjects("Nominal");
    if(!truthParts) return EL::StatusCode::FAILURE;

    const xAOD::TruthParticle* lep0(0);
    const xAOD::TruthParticle* lep1(0);
    for (unsigned int iPart(0) ; iPart < truthParts->size(); ++iPart) {
      const xAOD::TruthParticle* part = truthParts->at(iPart);
      // assume leptons are the only status 3 particles in SherpaV+jets
      if (part->status()==3) {
	if (!lep0) lep0=part;
	else lep1=part;
      }
    }  
    if (lep0 && lep1) {
      TLorentzVector V(lep0->p4());
      V+=lep1->p4();
      vpt_truth=V.Pt();
      //      if (m_isSherpaPt0VJets &&  vpt_truth > m_SherpaPt0VJetsCut)  return EL::StatusCode::SUCCESS;
      if (m_isSherpaPt0WJets  &&  vpt_truth > m_SherpaPt0WJetsCut)  return EL::StatusCode::SUCCESS;
      if (m_isSherpaPt0ZJets  &&  vpt_truth > m_SherpaPt0ZJetsCut)  return EL::StatusCode::SUCCESS;
    }
  }

  

  // reset event weight
  m_weight=1.0; 

  // reset lepton flavour, used for cutflows
  m_isE=false;
  m_isMu=false;

  // Query - reading the cross section every event.
  // This is because on the first event fileExecute and changeInput are called before initialize
  // so there is no event available to read datasetid
  if (m_isMC) {
    const xAOD::EventInfo* eventInfo = m_eventInfoReader->getObjects("Nominal");
    if(!eventInfo) return EL::StatusCode::FAILURE;

    int datasetid=eventInfo->mcChannelNumber();
    // fix m_sumOfWeights when production done on xAOD
    m_sumOfWeights = (m_sumOfWeights_fix) ? m_sumOfWeights_fix->getsumOfWeights(datasetid) : 1.0;
    //
    float sigmaEff = (m_xSection) ? m_xSection->getXSection(datasetid) : 1.0;
    //std::cout << "Cross section times eff. for dataset id " << datasetid << " = " << sigmaEff << std::endl;

    // we are normalising to MC lumi, sumOfWeights calculated per file.
    m_weight = (m_sumOfWeights) ? sigmaEff/m_sumOfWeights : 1.0;

    // multiply by MC generator weight 
    m_weight *= m_superDecorator.get(eventInfo,EventInfoFloatProps::MCEventWeight);

    // scale to desired luminosity
    m_weight *= (m_luminosity*1e3); //the MC is scaled to 1pb-1 but m_luminosity is in fb-1
  }
 
  // Sherpa Vpt  
  if (m_isSherpaVJets) m_hist_VPtTruth->Fill(vpt_truth/1000, m_weight);

  bool first = true;
  //loop on systematic variations - or at least run "Nominal"!
  //----------------------------------------------------------
  for (std::string varName : m_variations) {
    if(m_debug) Info("execute ()","Running variation %s", varName.c_str());
 
    m_histNameSvc -> reset();
    m_histNameSvc -> set_variation(varName);
     
    const xAOD::EventInfo* eventInfo = m_eventInfoReader->getObjects(varName);
    const xAOD::MissingETContainer* metCont = m_METReader->getObjects(varName);
    const xAOD::ElectronContainer* electrons = m_electronReader->getObjects(varName);
    //FIX for CxAOD_00-00-006
    const xAOD::PhotonContainer* photons = 0;
    if(!m_isNotInFile) photons = m_photonReader->getObjects(varName);
    const xAOD::MuonContainer* muons = m_muonReader->getObjects(varName);
    //FIX for CxAOD_00-00-006
    const xAOD::TauJetContainer* taus = 0;
    if(!m_isNotInFile) taus = m_tauReader->getObjects(varName);
  
    const xAOD::JetContainer* jets = m_jetReader->getObjects(varName);
    //const xAOD::JetContainer* fatjets = m_fatJetReader->getObjects(varName);
    
    const xAOD::MissingET * met = nullptr;
    if(metCont->size() > 0) met = metCont->at(0);
    
    //make sure that all collections could be properly retrieved
    //if(eventInfo || !metCont || !electrons || !photons || !muons || !taus || !jets || !fatjets) return EL::StatusCode::FAILURE;
    //if(!eventInfo || !metCont || !electrons || !photons || !muons || !taus || !jets) return EL::StatusCode::FAILURE;
     

    if (!m_isMC) {
      bool passGRL = m_superDecorator.get(eventInfo, EventInfoIntProps::passGRL);
      if (!passGRL) return EL::StatusCode::SUCCESS;
    }
 
    // lookout for events with no z-vertex
    float ZPV = m_superDecorator.get(eventInfo, EventInfoFloatProps::ZPV);
    if (ZPV<-9998) {
      std::cout << " Event without primary vertex " << ZPV << " " << eventInfo->runNumber() << " " << eventInfo->eventNumber() << std::endl;
      return EL::StatusCode::SUCCESS;
    }     


    if (first) {// bug in EDM: can decorate input only once currently
      
      if(!m_passThroughOR && !m_isNotInFile) m_overlapRemoval->removeOverlap(electrons, photons, muons, taus, jets);
      else OverlapPassThrough(electrons, photons, muons, taus, jets);

      first = false;
    }
    
    bool passSel = m_eventSelection->passSelection(eventInfo, met, electrons, photons, muons, taus, jets);
    
    // TODO want only pre-selection here?
    if (!passSel) continue;
    
    if (m_analysisType==e0Lep) 
      fill_0Lep();
    else if (m_analysisType==e1Lep) 
      fill_1Lep();
    else if (m_analysisType==e2Lep) 
      fill_2Lep(varName.c_str());
    else if (m_analysisType==VBF0ph)
      fill_VBF0ph();
    else if (m_analysisType==VBF1ph)
      fill_VBF1ph();
    else if (m_analysisType==monoWZH)
      fill_monoWZH();					
  } 
  
 
  return EL::StatusCode::SUCCESS;

}

EL::StatusCode AnalysisReader::fill_nJetHistos(std::vector<const xAOD::Jet*> jets, string jetType) {
  
  int nJet = jets.size();
  m_histSvc -> BookFillHist("N" + jetType + "Jets", 11, -0.5, 10.5, nJet, m_weight);

  for (const xAOD::Jet* jet: jets) {
    m_histSvc -> BookFillHist("Pt" + jetType + "Jets", 100,  0, 100, jet->pt()/1e3, m_weight);
    m_histSvc -> BookFillHist("Eta" + jetType + "Jets",100, -5,   5, jet->eta(),    m_weight);
    // TODO if(dirname=="Nominal") {
    // fill btagger histograms
    bTaggerHists(1, jet);
  } 
  
  return EL::StatusCode::SUCCESS;
}


EL::StatusCode AnalysisReader::fill_jetHistos(
        std::vector<const xAOD::Jet*> signalJets,
        std::vector<const xAOD::Jet*> forwardJets) {
  
  
  int nSignalJet = signalJets.size();
  int nForwardJet = forwardJets.size();
  int nJet = nSignalJet + nForwardJet;

  if (nSignalJet < 2) {
    Error("fill_jetHistos()", "Less than 2 jets provided!");
    return EL::StatusCode::FAILURE;
  }

  int jet0flav = m_superDecorator.get(signalJets.at(0), JetIntProps::truthLabel);
  int jet1flav = m_superDecorator.get(signalJets.at(1), JetIntProps::truthLabel);
  m_histNameSvc -> set_eventFlavour(jet0flav, jet1flav);
  m_histNameSvc -> set_nJet(nJet);
  
  TLorentzVector j1Vec = signalJets.at(0)->p4();
  TLorentzVector j2Vec = signalJets.at(1)->p4();
  TLorentzVector j3Vec;
  // TODO keep preferring signal jets or sort by pt?
  if      (nSignalJet  >= 3) j3Vec = signalJets.at(2)->p4();
  else if (nForwardJet >= 1) j3Vec = forwardJets.at(0)->p4();
  
  double bdt_dRBB   = j1Vec.DeltaR(j2Vec);
  double bdt_dPhiBB = j1Vec.DeltaPhi(j2Vec);
  double bdt_dEtaBB = fabs( j1Vec.Eta() - j2Vec.Eta() );
  double bdt_mBB    = (j1Vec+j2Vec).M();
  double bdt_pTB1   = j1Vec.Pt();
  double bdt_pTB2   = j2Vec.Pt();
  double bdt_pTJ3   = -1;
  double bdt_MBBJ   = -1;
  if (nJet >= 3) {
    bdt_pTJ3 = j3Vec.Pt();
    bdt_MBBJ = (j1Vec+j2Vec+j3Vec).M();
  }
  
  m_histSvc -> BookFillHist("dRBB",   100, 0,   5, bdt_dRBB,     m_weight);
  m_histSvc -> BookFillHist("dPhiBB", 100, 0,3.15, bdt_dPhiBB,   m_weight);
  m_histSvc -> BookFillHist("dEtaBB", 100, 0,   5, bdt_dEtaBB,   m_weight);
  m_histSvc -> BookFillHist("mBB",    100, 0, 500, bdt_mBB/1e3,  m_weight);
  m_histSvc -> BookFillHist("pTB1",   100, 0, 500, bdt_pTB1/1e3, m_weight);
  m_histSvc -> BookFillHist("pTB2",   100, 0, 500, bdt_pTB2/1e3, m_weight);
  if (nJet >= 3) {
    m_histSvc -> BookFillHist("pTJ3",   100, 0, 150, bdt_pTJ3/1e3, m_weight);
    m_histSvc -> BookFillHist("MBBJ",   100, 0, 750, bdt_MBBJ/1e3, m_weight);
  }

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: fill_0Lep()
{

  ResultVHbb0lep selectionResult = ((VHbb0lepEvtSelection*)m_eventSelection)->result();

  const xAOD::MissingET* met = selectionResult.met;
  std::vector<const xAOD::Jet*> signalJets = selectionResult.signalJets;
  std::vector<const xAOD::Jet*> forwardJets = selectionResult.forwardJets;

  // cut on nJet
  if (!(signalJets.size() + forwardJets.size() >= 2)) return EL::StatusCode::SUCCESS;

  fill_nJetHistos(signalJets, "Sig");
  fill_nJetHistos(forwardJets, "Fwd");

  // cut on nSignalJet
  if (!(signalJets.size() >= 2)) return EL::StatusCode::SUCCESS;

  // leading jet pt cut. sorting is be done by event selection
  if (signalJets.at(0)->pt()/1000. < 45.) return EL::StatusCode::SUCCESS;

  // and finally cut on MET
  if(met->met() < 120e3) return EL::StatusCode::SUCCESS;

  // LV
  TLorentzVector j1Vec = signalJets.at(0)->p4();
  TLorentzVector j2Vec = signalJets.at(1)->p4();
  TLorentzVector j3Vec;
  if (signalJets.size() >= 3) j3Vec = signalJets.at(2)->p4();
  TLorentzVector metVec;
  metVec.SetPxPyPzE(met->mpx(), met->mpy(), 0, met->met());

  // BDT input vars (for later should be jet corrected quantities)
  double bdt_dPhiVBB = fabs( metVec.DeltaPhi(j1Vec+j2Vec) );
  double bdt_MEff = j1Vec.Pt() + j2Vec.Pt() + metVec.Pt();
  double bdt_MEff3 = j1Vec.Pt() + j2Vec.Pt() + j3Vec.Pt() + metVec.Pt();
  double bdt_MET = metVec.Pt();

  // MVA selection (for later should be on jet uncorrected quantities)

  // dR cut -> leave for later
  //if (MET<200e3 && bdt_dRBB<0.7) return EL::StatusCode::SUCCESS;
  
  // mindPhi cut
  double mindPhi1 = fabs( j1Vec.DeltaPhi(metVec) );  
  double mindPhi2 = fabs( j2Vec.DeltaPhi(metVec) );       
  double mindPhi3 = 1000;
  if (signalJets.size() >= 3) mindPhi3 = fabs( j3Vec.DeltaPhi(metVec) );       
  double mindPhi = mindPhi1;
  if (mindPhi2<mindPhi) mindPhi = mindPhi2;
  if (mindPhi3<mindPhi) mindPhi = mindPhi3;

  if (mindPhi<1.5) return EL::StatusCode::SUCCESS;

  // dPhiMETMPT cut -> not possible yet

  // fill jet histos and set nJet, flavour for histo names
  fill_jetHistos(signalJets, forwardJets);

  m_histSvc -> BookFillHist("MET",     100, 0,  500, bdt_MET/1e3,     m_weight);
  m_histSvc -> BookFillHist("dPhiVBB", 100, 0, 3.15, bdt_dPhiVBB,     m_weight);
  m_histSvc -> BookFillHist("MEff"   , 100, 0, 1000, bdt_MEff/1e3,    m_weight);
  if (signalJets.size() >= 3) {
    m_histSvc -> BookFillHist("MEff3", 100, 0, 1000, bdt_MEff3/1e3,   m_weight);
  }

  return EL::StatusCode::SUCCESS;
} 

EL::StatusCode AnalysisReader :: fill_1Lep()
{

  // TODO add new fat jet selection
  //make mass plot fo fat jets before any selection
  /*
  m_hist_1lep_fatJetPt = new TH1F("FatJetPt","Pt of leading Fat Jet",100,200,600);
  m_hist_1lep_fatJetm = new TH1F("FatJetm","Mass of leading Fat Jet",100,0,400);
  int isFatEvent = false;
  std::vector<const xAOD::Jet*> fatsigJets;
  for (unsigned int iJet(0) ; iJet < fatjets->size(); ++iJet) {
    const xAOD::Jet * fatjet = fatjets->at(iJet);
    m_superDecorator.get(fatjet, FatJetIntProps::isFatJet, isFatEvent);
      if(isFatEvent){
          m_hist_1lep_fatJetPt->Fill(fatjet->pt()/1000, m_weight);
          m_hist_1lep_fatJetm->Fill(fatjet->m()/1000, m_weight);
      }else{
       //   std::cout << "not a fatjet" << std::endl;
      }

  }
  */

  ResultVHbb1lep selectionResult = ((VHbb1lepEvtSelection*)m_eventSelection)->result();

  //do final event selection
  const xAOD::Electron* electron = selectionResult.el;
  const xAOD::Muon* muon = selectionResult.mu;
  const xAOD::MissingET* met = selectionResult.met;
  std::vector<const xAOD::Jet*> signalJets = selectionResult.signalJets;
  std::vector<const xAOD::Jet*> forwardJets = selectionResult.forwardJets;

  // cut on nJet
  if (!(signalJets.size() + forwardJets.size() >= 2)) return EL::StatusCode::SUCCESS;

  fill_nJetHistos(signalJets, "Sig");
  fill_nJetHistos(forwardJets, "Fwd");

  // cut on nSignalJet
  if (!(signalJets.size() >= 2)) return EL::StatusCode::SUCCESS;

  // leading jet pt cut. sorting is be done by event selection
  if (signalJets.at(0)->pt()/1000. < 45.) return EL::StatusCode::SUCCESS;

  TLorentzVector lepVec;
  if (muon) {
    lepVec = muon->p4();
  } else if (electron) {
    lepVec = electron->p4();
  } else {
    Error("fill_1Lep()", "Missing lepton!");
    return EL::StatusCode::FAILURE;
  }
 
  TLorentzVector metVec;
  metVec.SetPtEtaPhiM(met->met(), 0, met->phi(), 0);

  TLorentzVector lepVecT;
  lepVecT.SetPtEtaPhiM(lepVec.Pt(), 0, lepVec.Phi(), 0);

  TLorentzVector WVecT = lepVecT + metVec;
  
  double bdt_MET = met->met();
  double bdt_mTW = WVecT.M();
  double bdt_pTV = WVecT.Mag();
  double bdt_pTL = lepVec.Pt();
  
  // fill jet histos and set nJet, flavour for histo names
  fill_jetHistos(signalJets, forwardJets);

  m_histSvc -> BookFillHist("MET",   100, 0, 500, bdt_MET/1e3, m_weight);
  m_histSvc -> BookFillHist("mTW",   100, 0, 500, bdt_mTW/1e3, m_weight);
  m_histSvc -> BookFillHist("pTV",   100, 0, 500, bdt_pTV/1e3, m_weight);
  m_histSvc -> BookFillHist("pTL",   100, 0, 500, bdt_pTL/1e3, m_weight);

  return EL::StatusCode::SUCCESS;
} 

EL::StatusCode AnalysisReader :: fill_2Lep(TString sysname)
{
  std::string dirname(sysname);

  ResultVHbb2lep selectionResult = ((VHbb2lepEvtSelection*)m_eventSelection)->result();
  
  const xAOD::Electron* el1 = selectionResult.el1;
  const xAOD::Electron* el2 = selectionResult.el2;
  const xAOD::Muon* mu1 = selectionResult.mu1;
  const xAOD::Muon* mu2 = selectionResult.mu2;
  const xAOD::MissingET* met = selectionResult.met;
  std::vector<const xAOD::Jet*> signalJets = selectionResult.signalJets;
  std::vector<const xAOD::Jet*> forwardJets = selectionResult.forwardJets;

  CutFlowHist("CutFlow/"+dirname+"/", "All", m_weight);

  // no e-mu for the moment
  m_isMu=(mu1&&mu2);
  m_isE=(el1&&el2);
  if (!m_isMu&&!m_isE) return EL::StatusCode::SUCCESS;
  CutFlowHist("CutFlow/"+dirname+"/", "2Lep", m_weight);

  // cut on nJet
  if (!(signalJets.size() + forwardJets.size() >= 2)) return EL::StatusCode::SUCCESS;
  CutFlowHist("CutFlow/"+dirname+"/", "2Jet", m_weight);

  fill_nJetHistos(signalJets, "Sig");
  fill_nJetHistos(forwardJets, "Fwd");

  // cut on nSignalJet
  if (!(signalJets.size() >= 2)) return EL::StatusCode::SUCCESS;
  CutFlowHist("CutFlow/"+dirname+"/", "2SigJet", m_weight);

  // leading jet pt cut. sorting is be done by event selection
  if (signalJets.at(0)->pt()/1000. < 45.) return EL::StatusCode::SUCCESS;
  CutFlowHist("CutFlow/"+dirname+"/", "Pt45", m_weight);

  TLorentzVector l1Vec;
  TLorentzVector l2Vec;
  if (m_isMu) {
    l1Vec = mu1->p4();
    l2Vec = mu2->p4();
  } else {
    l1Vec = el1->p4();
    l2Vec = el2->p4();
  }
  TLorentzVector ZVec = l1Vec + l2Vec;

  // cut on mLL
  if (!(ZVec.M()/1000. >= 71. && ZVec.M()/1000. < 121.)) return EL::StatusCode::SUCCESS;
  CutFlowHist("CutFlow/"+dirname+"/", "Mll", m_weight);
  
  // cut on MET
  if (!(met->met()/1000. < 60.)) return EL::StatusCode::SUCCESS;
  CutFlowHist("CutFlow/"+dirname+"/", "MET", m_weight);

  // fill jet histos and set nJet, flavour for histo names
  fill_jetHistos(signalJets, forwardJets);

  m_histSvc -> BookFillHist("MET", 100,  0, 100, met->met()/1000., m_weight);
  m_histSvc -> BookFillHist("mLL",  60, 60, 120, ZVec.M()/1000,    m_weight);
  m_histSvc -> BookFillHist("pTV", 100,  0, 500, ZVec.Pt()/1000,   m_weight);
  if (m_isMu) {
    m_histSvc -> BookFillHist("Mmumu",    60, 60, 120, ZVec.M()/1000,  m_weight);
    m_histSvc -> BookFillHist("pTZmumu", 100,  0, 500, ZVec.Pt()/1000, m_weight);
  }
  else {
    m_histSvc -> BookFillHist("Mee",    60, 60, 120, ZVec.M()/1000,  m_weight);
    m_histSvc -> BookFillHist("pTZee", 100,  0, 500, ZVec.Pt()/1000, m_weight);
  }

  // TODO primary vertex after cuts
  //m_histSvc -> BookFillHist("ZPV",100,-200,200,ZPV,m_weight);

  return EL::StatusCode::SUCCESS;
}


EL::StatusCode AnalysisReader :: fill_VBF0ph()
{
  return EL::StatusCode::SUCCESS;
}


EL::StatusCode AnalysisReader :: fill_VBF1ph()
{
  ResultVBFHbb1ph selectionResult = ((VBFHbb1phEvtSelection*)m_eventSelection)->result();

  //const xAOD::Photon* ph = onePhResult.ph;
  std::vector<const xAOD::Jet*> selJets = selectionResult.jets;

  int njets=selJets.size();
  if(njets<4) return EL::StatusCode::SUCCESS;


  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: fill_monoWZH()
{

  ResultVHbb0lep selectionResult = ((VHbb0lepEvtSelection*)m_eventSelection)->result();

  const xAOD::MissingET* met = selectionResult.met;
  std::vector<const xAOD::Jet*> jets = selectionResult.signalJets;
  std::vector<const xAOD::FatJet*> fatjets = selectionResult.fatJets;
 
  cout << "jets->size(): " << jets.size() << endl;

//  std::vector<const xAOD::Jet*> forwardJets = selectionResult.forwardJets;

  // cut on nJet
//  if (!(signalJets.size() + forwardJets.size() >= 2)) return EL::StatusCode::SUCCESS;

 // fill_nJetHistos(signalJets, "Sig");
//  fill_nJetHistos(forwardJets, "Fwd");

  // cut on nSignalJet
//  if (!(signalJets.size() >= 2)) return EL::StatusCode::SUCCESS;

  bool debug = false;
  if(debug) std::cout<< "Filling" <<std::endl;

  //----------------------------
  // Overlap Removal
  //--------------------------- 
  // Do here for Nominal, systematics
  //m_overlapRemoval->removeOverlap(elecs, phots, muons, jets);

  //------------------------
  //Event Selection
  //-------------------------

  //make mass plot fo fat jets before any selection
  //bool isFatEvent = false;
  //std::vector<const xAOD::Jet*> fatsigJets;
  // for (unsigned int iJet(0) ; iJet < fatjets->size(); ++iJet) {
   // const xAOD::Jet * fatjet = fatjets->at(iJet);
      // if(m_superDecorator.get(fatjet,FatJetIntProps::isFatJet)){
          // isFatEvent = true;
                  //Need to add new hists
          //m_hist_1lep_fatJetPt->Fill(fatjet->pt()/1000, m_weight);
          //m_hist_1lep_fatJetm->Fill(fatjet->m()/1000, m_weight);
      // }else{
         //std::cout << "not a fatjet" << std::endl;
      // }

  // }
  //Need to def new selection
//  bool passmonoWZH=m_zerolepSel->passSelection(eventInfo,
//                                            met,
//                                            elecs,
//                                                                                        phots,
//                                            muons,
//                                            jets);

  //  if(debug)  std::cout << " Passed 0 lepton "  << pass0lep << std::endl;
  //Following code need to be check
  //ResultVHbb0lep zerolepResult=m_zerolepSel->result();

  //if (zerolepResult.pass != pass0lep)
  //  std::cout << " 0 lep ERROR "  << pass0lep << " " << zerolepResult.pass << std::endl;

  // select events
//  if (!passmonoWZH) return EL::StatusCode::SUCCESS;

//  std::vector<const xAOD::Jet*> selJets=zerolepResult.jets;


  //pre-selection 
  //could be implement in CxAODMaker  
  bool pass_presele = true;
  if(METNominal->size() == 0) pass_presele = false;
  //0 electron
  //if(elecs->size() > 0) pass_presele = false;                         // not applied in the pre-selection (though shouldn't be present in xAOD anyway)
  if(elecs->size() > 0) cout << "Found an electron!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  //0 muons
  //if(muons->size() > 0) pass_presele = false;
  if(muons->size() > 0) cout << "Found a muon!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
  //MET > 200GeV
  if((met->met()/1000.) < 200 ) pass_presele = false;
  //a least one fatjet 
  if(fatjets->size() < 1) pass_presele = false;
  if(debug) std::cout << "Done pre_selection" << std::endl;
  //Event selection
  bool pass_met250 = false;
  bool pass_met350 = false;
  bool pass_fatjet = false;
  bool pass_lepveto = false;
  bool pass_photveto = false;
  bool pass_jetveto = false;
  bool pass_metcut = false;
  bool pass_jetmass = false;
  bool pass_jetOL = false;

  m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("All"), m_weight);
  m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("All"));

  // want to look at fat jet variables before pre-selection here, for comparison with Arturo's CxAODs with jet substructure
  int nfatjet_pre = fatjets->size();
  for(int i(0); i < nfatjet_pre ;i++){
        m_hist_mono_prepre_fatjetm->Fill(fatjets->at(i)->m()/1000., m_weight);
        m_hist_mono_prepre_fatjetpt->Fill(fatjets->at(i)->pt()/1000., m_weight);
  }

//  int nfatjet_Cam_pre = fatjets_Cam->size();
//  for(int j(0); j < nfatjet_Cam_pre; j++){
//        m_hist_mono_prepre_fatjetm_Cam->Fill(fatjets_Cam->at(j)->m()/1000., m_weight);
//        m_hist_mono_prepre_fatjetpt_Cam->Fill(fatjets_Cam->at(j)->pt()/1000., m_weight);
//  } 

if(pass_presele)
{
  // MET cut at 250 GeV
  if (met->met()/1000. > 250.) pass_met250 = true;

  // MET cut at 350 GeV
  if (met->met()/1000. > 350.) pass_met350 = true;

  //fat jet Pt > 250GeV |eta| < 1.2
  int nfatjet = fatjets->size();
  std::vector<const xAOD::Jet*> fatsigJets;
  if(debug) std::cout << "Done fatjet cut start" << std::endl;
  for(int i(0); i < nfatjet ;i++){
          if(fatjets->at(i)->pt() < 250000.) continue;
          if(fabs(fatjets->at(i)->eta()) > 1.2) continue;
          fatsigJets.push_back(fatjets->at(i));
  }
  //if (pass_met350) cout << "Num of sig fat jets: " << fatsigJets.size() << endl;
  if(fatsigJets.size() > 0) pass_fatjet = true;

  // find leading fat jet
  float max_pt = 0.;
  int lead_i;
  TLorentzVector lead_fjet;             // define the leading fat jet
  if(fatsigJets.size() > 0){
          for (int i(0); i< fatsigJets.size(); i++){
                  if (fatsigJets.at(i)->pt() > max_pt){
                           max_pt = fatsigJets.at(i)->pt();
                           lead_i = i;
                  }
          }
          lead_fjet.SetPtEtaPhiM(fatsigJets.at(lead_i)->pt(), fatsigJets.at(lead_i)->eta(), fatsigJets.at(lead_i)->phi(), fatsigJets.at(lead_i)->m());
  }
  if(debug) std::cout << "Done fatjet cut" << std::endl;

  // lepton veto
  std::vector<const xAOD::Electron*> sigEls;
  std::vector<const xAOD::Muon*> sigMus;
  std::vector<const xAOD::Photon*> sigPhots;
  int n_el = elecs->size();
  int n_mu = muons->size();
  int n_ph = phots->size();
  //cout << "n_el: " << n_el << endl;
  //cout << "n_mu: " << n_mu << endl;
  //cout << "n_ph: " << n_ph << endl;
  for (int i(0); i < n_el; i++){
    if (elecs->at(i)->pt() < 10000.) continue;
    if (fabs(elecs->at(i)->eta()) > 2.47) continue;
    sigEls.push_back(elecs->at(i));
  }
  for (int i(0); i < n_mu; i++){
    if (muons->at(i)->pt() < 10000.) continue;
    if (fabs(muons->at(i)->eta()) > 2.5) continue;
    sigMus.push_back(muons->at(i));
  }
  for (int i(0); i < n_ph; i++){
    if (phots->at(i)->pt() < 10000.) continue;
    if (fabs(phots->at(i)->eta()) > 2.37) continue;
    sigPhots.push_back(phots->at(i));
  }
  //cout << "n_sigEl: " << sigEls.size() << endl;
  //cout << "n_sigMu: " << sigMus.size() << endl;
  //cout << "n_sigPh: " << sigPhots.size() << endl;
  if (sigEls.size() == 0 && sigMus.size() == 0) pass_lepveto = true;
  if (sigPhots.size() == 0) pass_photveto = true;

  //if (pass_met350 && pass_lepveto) cout << "Num of sig fat jets at jet veto: " << fatsigJets.size() << endl;

  //Additional jet veto
  std::vector<const xAOD::Jet*> sigJets;
  int njets=selJets.size();
  for(int i(0);i < njets;i++){                                                  // loop over antiKt jets
          if(selJets.at(i)->pt() < 40000.) continue;
          if(fabs(selJets.at(i)->eta()) > 4.5) continue;
          TLorentzVector addjet;
          addjet.SetPtEtaPhiM(selJets.at(i)->pt(), selJets.at(i)->eta(), selJets.at(i)->phi(), selJets.at(i)->m());
          float deltaR = 20.;                                                   // set to some arbitray large number. Then if no fat jet, deltaR is not recalculated, and this jet should pass. 
          if (fatsigJets.size() > 0) deltaR = lead_fjet.DeltaR(addjet);
          if (deltaR < 0.9) continue;                                           // ie overlaps with lead fat jet, remove this antiKt jet
          sigJets.push_back(selJets.at(i));
  }
  if (sigJets.size() < 2) pass_jetveto = true;
  if(debug) std::cout << "Done jetveto cut" << std::endl;

  int num_close_jets = 0;
  TLorentzVector metVec;
  metVec.SetPxPyPzE(met->mpx()/1000., met->mpy()/1000., 0, met->met()/1000.);
  for(int i(0); i<sigJets.size(); i++){
        TLorentzVector seljet;
        seljet.SetPtEtaPhiM(sigJets.at(i)->pt(), sigJets.at(i)->eta(), sigJets.at(i)->phi(), sigJets.at(i)->m());
        double met_phi = met->phi();
        float delPhi = fabs(seljet.DeltaPhi(metVec));
        //cout << "delPhi is " << delPhi << endl;
        if (delPhi <= 0.4) num_close_jets++;
  }
  if (num_close_jets == 0) pass_jetOL = true;


  //MET > 500 GeV
  if((met->met()/1000.) > 500 ) pass_metcut = true;

  // 50 < mJ < 120 GeV
  float lead_mass = 0.;
  if(fatsigJets.size() > 0){
          lead_mass = fatsigJets.at(lead_i)->m();
          if (lead_mass > 50000. && lead_mass < 120000.) pass_jetmass = true;
  }

  if(debug) std::cout << "Done selection" << std::endl;

  //fill cutflow hist 

  //m_hist_mono_pre_MET->Fill(met->met()/1000., m_weight);
  m_hist_mono_pre_MET->Fill(met->met()/1000.);
  m_hist_mono_pre_Nfatjet->Fill(nfatjet);
  for(int i(0); i < nfatjet ;i++){
        m_hist_mono_pre_fatjetm->Fill(fatjets->at(i)->m()/1000., m_weight);
        m_hist_mono_pre_fatjetpt->Fill(fatjets->at(i)->pt()/1000., m_weight);
        m_hist_mono_pre_fatjeteta->Fill(fatjets->at(i)->eta()/1000., m_weight);
  }
  for(int i(0); i < njets ;i++){
        m_hist_mono_pre_jetm->Fill(selJets.at(i)->m()/1000., m_weight);
        m_hist_mono_pre_jetpt->Fill(selJets.at(i)->pt()/1000., m_weight);
        m_hist_mono_pre_jeteta->Fill(selJets.at(i)->eta()/1000., m_weight);
  }
  m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("pre-selection"), m_weight);
  m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("pre-selection"));
  m_hist_mono_cutflow_Nsigfjet->Fill(fatsigJets.size());

  if(pass_met250)
  {
        //m_hist_mono_cutflow_met250_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_met250_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("met250"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("met250"));
  }
  if(pass_met250 && pass_met350)
  {
        //m_hist_mono_cutflow_met350_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_met350_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("met350"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("met350"));
  }
  if(pass_met250 && pass_met350 && pass_fatjet)
  {
        //m_hist_mono_cutflow_fjet_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_fjet_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("one fatjet"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("one fatjet"));
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto)
  {
        //m_hist_mono_cutflow_lepveto_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_lepveto_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("lep veto"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("lep veto"));
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto)
  {
        //m_hist_mono_cutflow_photveto_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_photveto_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("phot veto"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("phot veto"));
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto)
  {
        //m_hist_mono_cutflow_jetveto_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_jetveto_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("addjetveto"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("addjetveto"));
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto && pass_jetOL)
  {
        //m_hist_mono_cutflow_metjetOL_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_metjetOL_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("metjetOL"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("metjetOL"));
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto && pass_jetOL && pass_metcut)
  {
        //m_hist_mono_cutflow_met_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_met_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("500met"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("500met"));
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto && pass_jetOL && pass_metcut && pass_jetmass)
  {
        //m_hist_mono_cutflow_mj_MET->Fill(met->met()/1000., m_weight);
        m_hist_mono_cutflow_mj_MET->Fill(met->met()/1000.);
        m_hist_mono_cutflow->Fill(m_hist_mono_cutflow->GetXaxis()->FindBin("mJ"), m_weight);
        m_hist_mono_cutflow_noweight->Fill(m_hist_mono_cutflow_noweight->GetXaxis()->FindBin("mJ"));
  }
  if(debug) std::cout << "Done fill_hist" << std::endl;

  //fill n-1 histogram                                                                                          
  if(pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto && pass_jetOL && pass_metcut && pass_jetmass)
  {
        m_hist_nminusone_met250->Fill(met->met()/1000., m_weight);
  }
  if(pass_met250 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto && pass_jetOL && pass_metcut && pass_jetmass)
  {
        m_hist_nminusone_met350->Fill(met->met()/1000., m_weight);
  }
  if(pass_met250 && pass_met350 && pass_lepveto && pass_photveto && pass_jetveto && pass_jetOL && pass_metcut && pass_jetmass)
  {
        m_hist_nminusone_fjet->Fill(fatsigJets.size(), m_weight);
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_photveto && pass_jetveto && pass_jetOL && pass_metcut && pass_jetmass)
  {
        m_hist_nminusone_lepveto->Fill((sigEls.size()+sigMus.size()), m_weight);
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_jetveto && pass_jetOL && pass_metcut && pass_jetmass)
  {
        m_hist_nminusone_photveto->Fill(sigPhots.size(), m_weight);
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetOL && pass_metcut && pass_jetmass)
  {
        m_hist_nminusone_jetveto->Fill(sigJets.size(), m_weight);
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto && pass_metcut && pass_jetmass)
  {
        m_hist_nminusone_metjetOL->Fill(num_close_jets, m_weight);                                                                                      // This should be improved to show the overlap between all jets and MET
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto && pass_jetOL && pass_jetmass)
  {
        m_hist_nminusone_met500->Fill(met->met()/1000., m_weight);
  }
  if(pass_met250 && pass_met350 && pass_fatjet && pass_lepveto && pass_photveto && pass_jetveto && pass_jetOL && pass_metcut)
  {
        m_hist_nminusone_mj->Fill(lead_mass/1000., m_weight);
  }
}


  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode AnalysisReader :: finalize ()
{
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events.
  
  Info("finalize()", "Processed %i Events", m_eventCounter );



  return EL::StatusCode::SUCCESS;
}



EL::StatusCode AnalysisReader :: histFinalize ()
{
  // This method is the mirror image of histInitialize(), meaning it
  // gets called after the last event has been processed on the worker
  // node and allows you to finish up any objects you created in
  // histInitialize() before they are written to disk.  This is
  // actually fairly rare, since this happens separately for each
  // worker node.  Most of the time you want to do your
  // post-processing on the submission node after all your histogram
  // outputs have been merged.  This is different from finalize() in
  // that it gets called on all worker nodes regardless of whether
  // they processed input events.

  
  m_histSvc->Write();  

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisReader ::CutFlowHist(std::string dir, std::string label, double weight) {

  static std::string cuts [18] = {"All", "2Lep", "2Jet", "2SigJet", "Pt45", "Mll", "MET", "DRmin", "DRjj",  "Bin0", "Bin1","Bin2","Bin3","Bin4","MjjUncor","Mjj"};

  m_histSvc->BookFillCutHist(dir+"Cuts", length(cuts), cuts, label, weight);
  m_histSvc->BookFillCutHist(dir+"CutsNoWeight", length(cuts), cuts, label, 1.);
  
  if (m_isMu) {
    m_histSvc->BookFillCutHist(dir+"CutsElec", length(cuts), cuts, label, weight);
    m_histSvc->BookFillCutHist(dir+"CutsElecNoWeight", length(cuts), cuts, label, 1.);
  } else if (m_isE) {
    m_histSvc->BookFillCutHist(dir+"CutsMuon", length(cuts), cuts, label, weight);
    m_histSvc->BookFillCutHist(dir+"CutsMuonNoWeight", length(cuts), cuts, label, 1.);
  }

  return EL::StatusCode::SUCCESS;

}

EL::StatusCode AnalysisReader :: OverlapPassThrough(const xAOD::ElectronContainer* electrons, 
						    const xAOD::PhotonContainer* photons,	
						    const xAOD::MuonContainer* muons,		
						    const xAOD::TauJetContainer* taus,		
						    const xAOD::JetContainer* jets)  {
  if (electrons) {
    for (const xAOD::Electron* elec : *electrons) {
      m_superDecorator.set(elec, ElecIntProps::passOR, true);
    }        
  }                                                                                        

  if (photons) {
    for (const xAOD::Photon* photon : *photons) {
      m_superDecorator.set(photon, PhotIntProps::passOR, true);
    }
  } 

  if (muons) {
    for (const xAOD::Muon* muon : *muons) {                                                          
      m_superDecorator.set(muon, MuonIntProps::passOR, true);     
    }
  }
  if (taus) {
    for (const xAOD::TauJet* tau : *taus) {
      m_superDecorator.set(tau, TauIntProps::passOR, true);
    }
  }

  if (jets) {
    for (const xAOD::Jet* jet : *jets) {
      m_superDecorator.set(jet, JetIntProps::passOR, true);
    }
  }                                                                                                  

  return EL::StatusCode::SUCCESS;

}          
