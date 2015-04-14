#include "EventLoop/Job.h"
#include "EventLoop/StatusCode.h"
#include "EventLoop/Worker.h"
#include "EventLoop/OutputStream.h"

#include "CxAODMaker/AnalysisBase.h"

#include "CxAODMaker/MuonHandler.h"
#include "CxAODMaker/TauHandler.h"
#include "CxAODMaker/JetHandler.h"
#include "CxAODMaker/ElectronHandler.h"
#include "CxAODMaker/PhotonHandler.h"
#include "CxAODMaker/FatJetHandler.h"
#include "CxAODMaker/TrackJetHandler.h"
#include "CxAODMaker/UngroomedJetHandler.h"
#include "CxAODMaker/GroomedJetHandler.h"
#include "CxAODMaker/TrimmedJetHandler.h"
#include "CxAODMaker/METHandler.h"
#include "CxAODMaker/TruthParticleHandler.h"
#include "CxAODMaker/EventInfoHandler.h"
#include "CxAODMaker/EventSelector.h"

#include "CxAODTools/VHbb0lepEvtSelection.h"
#include "CxAODTools/VHbb1lepEvtSelection.h"
#include "CxAODTools/VHbb2lepEvtSelection.h"
#include "CxAODTools/VBFHbb0phEvtSelection.h"
#include "CxAODTools/VBFHbb1phEvtSelection.h"
#include "CxAODTools/HHbbtautauSemiLepSelection.h"

#include "TFile.h"
#include "TTree.h"
#include "TTreeFormula.h"

// this is needed to distribute the algorithm to the workers
ClassImp(AnalysisBase)

AnalysisBase::AnalysisBase() :
m_jetHandler(nullptr),
  m_fatjetHandler(nullptr),
  m_trackjetHandler(nullptr),
  m_ungroomedjetHandler(nullptr),
  m_groomedjetHandler(nullptr),
  m_trimmedjetHandler(nullptr),
  m_muonHandler(nullptr),
  m_electronHandler(nullptr),
  m_photonHandler(nullptr),
  m_tauHandler(nullptr),
  m_eventInfoHandler(nullptr),
  m_METHandler(nullptr),
  m_selector(nullptr),
  m_config(nullptr),
  m_configPath("none"),
  m_debug(false),
  m_xJets(false),
  m_event(nullptr),
  m_maxEvent(-999), 
  m_eventCounter(0),
  m_eventWeightCounter(0),
  m_histEventCount(0)
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().
}

EL::StatusCode AnalysisBase::setupJob(EL::Job& job) {
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.
  job.useXAOD();

  // let's initialize the algorithm to use the xAODRootAccess package
  xAOD::Init("AnalysisBase").ignore(); // call before opening first file

  // tell EventLoop about our output xAOD:
  EL::OutputStream out("outputLabel");
  job.outputAdd (out);

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::histInitialize() {
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.
  
  if (m_histEventCount) {
    // TODO why is histInitialize() called after fileExecute() ??
    Warning("histInitialize()", "Histograms already initialized! Skipping histInitialize()...");
    return EL::StatusCode::SUCCESS;
  }

  // event counts from meta data
  m_histEventCount = new TH1D("MetaData_EventCount", "MetaData_EventCount", 8, 0.5, 8.5);
  m_histEventCount -> GetXaxis() -> SetBinLabel(1, "nEvents initial");
  m_histEventCount -> GetXaxis() -> SetBinLabel(2, "nEvents selected in");
  m_histEventCount -> GetXaxis() -> SetBinLabel(3, "nEvents selected out");
  m_histEventCount -> GetXaxis() -> SetBinLabel(4, "sumOfWeights initial");
  m_histEventCount -> GetXaxis() -> SetBinLabel(5, "sumOfWeights selected in");
  m_histEventCount -> GetXaxis() -> SetBinLabel(6, "sumOfWeights selected out");
  m_histEventCount -> GetXaxis() -> SetBinLabel(7, "nEvents in this job");
  m_histEventCount -> GetXaxis() -> SetBinLabel(8, "sumOfWeights in this job");
  wk() -> addOutput(m_histEventCount);

  Info("histInitialize()", "Histograms initialized.");

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::fileExecute() {
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed

  if (!m_histEventCount) {
    // TODO why is histInitialize() called after fileExecute() ??
    Warning("fileExecute()", "Histograms not initialized! Calling histInitialize()...");
    histInitialize();
  }
  
  TString fileName = wk()->inputFile()->GetName();
  Info("fileExecute()", "Processing file '" + fileName + "'");

  //----------------------------
  // Meta data
  //--------------------------- 

  // get the MetaData tree once a new file is opened, with
  TTree *MetaData = dynamic_cast<TTree*>(wk()->inputFile()->Get("MetaData"));
  if (!MetaData) {
    // TODO: report Error and return FAILURE?
    Warning("fileExecute()", "MetaData not found!");
    return EL::StatusCode::SUCCESS;
  }
  MetaData->LoadTree(0);

  // extract the information from the EventBookkeepers branch (only on derivations)
  // TODO: move the GetBranch piece of code more upstream and set an "isDerivation"
  // flag there, to be used later?
  if (!MetaData->GetBranch("StreamAOD")) {
    TTreeFormula tfNevents("tf", "EventBookkeepers.m_nAcceptedEvents", MetaData);
    TTreeFormula tfSumW("tf", "EventBookkeepers.m_nWeightedAcceptedEvents", MetaData);
    tfNevents.UpdateFormulaLeaves();
    tfSumW.UpdateFormulaLeaves();
    if (tfNevents.GetNdata() < 2 || tfSumW.GetNdata() < 2) {
      Warning("fileExecute()", "Could not read sum of weights from MetaData!");
    }
    else{
      // read meta data
      Info("fileExecute()", "Meta data from this file:");
      Info("fileExecute()", "Initial  events         = %f", tfNevents.EvalInstance(1));
      Info("fileExecute()", "Selected events         = %f", tfNevents.EvalInstance(0));
      Info("fileExecute()", "Initial  sum of weights = %f", tfSumW.EvalInstance(1));
      Info("fileExecute()", "Selected sum of weights = %f", tfSumW.EvalInstance(0));
      m_histEventCount -> Fill(1, tfNevents.EvalInstance(1)); // nEvents initial
      m_histEventCount -> Fill(2, tfNevents.EvalInstance(0)); // nEvents selected in
      m_histEventCount -> Fill(4, tfSumW.EvalInstance(1)); // sumOfWeights initial
      m_histEventCount -> Fill(5, tfSumW.EvalInstance(0)); // sumOfWeights selected in
    }
  }

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::changeInput(bool firstFile) {
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::initialize() {
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.

  Info("AnalysisBase::initialize()", "Initialize.");
  
  // modular initialization for easier derivation

  EL_CHECK("initialize()",initializeEvent()     );
  EL_CHECK("initialize()",initializeVariations());
  EL_CHECK("initialize()",initializeHandlers()  );

  bool isMC = m_eventInfoHandler->get_isMC();

  EL_CHECK("initialize()",initializeSelector() );
  EL_CHECK("initialize()",initializeTools(isMC));
  EL_CHECK("initialize()",initializeSelection());
  
  bool printVariations;
  m_config->getif<bool>("printKnownVariations", printVariations);
  if (printVariations) printKnownVariations();

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::initializeEvent() {
  Info("AnalysisBase::initializeEvent()", "Initialize event.");

  // get TEvent
  m_event = wk()->xaodEvent();
  
  // get configuration from steerfile
  m_config = ConfigStore::createStore(m_configPath,false);
  if ( ! m_config ) {
    Error("initialize()","Couldn't create ConfigStore from file : %s",m_configPath.c_str());
    return EL::StatusCode::FAILURE;
  }

  // flag for debug output
  m_config->getif<bool>("debug",m_debug);

  // flag for included extra Jetsin the output
  m_config->getif<bool>("addTrimmedJetContainer",m_xJets);

  // sample name
  TString sampleName = wk()->metaData()->getString("sample_name");
  Info("initialize()", "Sample name = %s", sampleName.Data());
  // as a check, let's see the number of events in our xAOD (long long int)
  Info("initialize()", "Number of events in file   = %lli", m_event->getEntries());
  if(m_maxEvent < 0) m_maxEvent = m_event->getEntries() ;
  Info("initialize()", "Number of events to run on = %li", m_maxEvent);


  // count number of events
  m_eventCounter = 0;
  m_eventWeightCounter = 0;

  // output xAOD
  TFile * file = wk()->getOutputFile ("outputLabel");
  if(!m_event->writeTo(file).isSuccess()){
    Error("initialize()", "Failed to write event to output file!");
    return EL::StatusCode::FAILURE;
  }

  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::initializeVariations() {
  Info("AnalysisBase::initializeVariations()", "Initialize variations.");

  m_variations.clear();
  // Nominal is always present
  m_variations.push_back("Nominal");
  // Original (not calibrated)
  bool storeOrig;
  m_config->getif<bool>("storeOriginal", storeOrig);
  if (storeOrig) {
    m_variations.push_back("Original");
  }
  // variations
  std::vector<std::string> variations;
  m_config->getif< std::vector<std::string> >("variations", variations);
  std::vector<std::string> pulls = {"1down", "1up"};
  for (std::string name : variations) {
    for (std::string pull : pulls) {
      m_variations.push_back((name + "__" + pull).c_str());
    }
  }
  std::vector<std::string> weightVariations;
  m_config->getif< std::vector<std::string> >("weightVariations", weightVariations);
  // Add weight variations to variations vector
  for (std::string name : weightVariations) {
    for (std::string pull : pulls) {
      m_variations.push_back((name + "__" + pull).c_str());
    }
  }
  
  // TODO add symmetric variations


  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::initializeHandlers() {
  Info("AnalysisBase::initializeHandlers()", "Initialize handlers.");

  // initialize EventInfoHandler and read info of first event
  
  m_eventInfoHandler = new EventInfoHandler(*m_config, m_event);
  EL_CHECK("initializeHandlers()",m_eventInfoHandler->initialize());
  EL_CHECK("initializeHandlers()",m_eventInfoHandler->executeEvent());

  bool isMC = m_eventInfoHandler->get_isMC();
  Info("initialize()", "First event is MC          = %i ", isMC);

  // note: the names of the handlers determine which collections are
  //       read, see also framework-run.cfg
  
  // register TruthParticleHandler before all others to make truthParticles for e.g. matching available
  TruthParticleHandler* truthHandler = nullptr;
  if (isMC) {
    truthHandler = registerHandler<TruthParticleHandler>("truthParticle");
  }

  // these have global pointer to be used e.g. in event selection
  m_muonHandler         = registerHandler<MuonHandler>("muon");
  m_tauHandler          = registerHandler<TauHandler>("tau");
  m_electronHandler     = registerHandler<ElectronHandler>("electron");
  m_photonHandler       = registerHandler<PhotonHandler>("photon");
  m_jetHandler          = registerHandler<JetHandler>("jet");
  m_fatjetHandler       = registerHandler<FatJetHandler>("fatJet");
  m_trackjetHandler     = registerHandler<TrackJetHandler>("trackJet");
  m_ungroomedjetHandler = registerHandler<UngroomedJetHandler>("ungroomedJet");
  m_groomedjetHandler   = registerHandler<GroomedJetHandler>("groomedJet");

  
  // these are spectators: they are calibrated and written to output,
  //                       but are not used in the event selection
   
  registerHandler<JetHandler>("jetSpectator");
   
  // alternative: manual handler initialization (e.g. with different constructor)
  //  std::string containerName;
  //  std::string name = "muon";
  //  m_config->getif<std::string>(name + "Container", containerName);
  //  if ( ! containerName.empty() ) {
  //    m_muonHandler = new MuonHandler(name, *m_config, m_event, *m_eventInfoHandler);
  //    m_objectHandler.push_back( m_muonHandler );
  //  }
  
  // initialize METHandler (not a ObjectHandler)
  m_METHandler = new METHandler(m_config, m_event, isMC);
  
  // initialize TrimmedJetHandler (not a ObjectHandler)
  if (m_xJets) {
    m_trimmedjetHandler = new TrimmedJetHandler(m_config, m_event, isMC);
  }
  
  // for tau truth matching
  if (m_tauHandler) {
    m_tauHandler->setTruthHandler(truthHandler); 
  }
  

  // Set trigger stream info if data
  // need to catch embedding once the time has come
  bool m_isEmbedding=false; 
  if( !isMC && !m_isEmbedding ){
    TString sampleName = wk()->metaData()->getString("sample_name");
    if(sampleName.Contains("Egamma")) m_eventInfoHandler->set_TriggerStream(1);
    if(sampleName.Contains("Muons")) m_eventInfoHandler->set_TriggerStream(2);
    if(sampleName.Contains("Jet")) m_eventInfoHandler->set_TriggerStream(3);
  }
    
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::initializeSelector() {
  Info("AnalysisBase::initializeSelector()", "Initialize selector.");

  // initialize EventSelector
  m_selector = new EventSelector(*m_config);
  
  m_selector->setJets(m_jetHandler);
  m_selector->setFatJets(m_fatjetHandler);
  m_selector->setTrackJets(m_trackjetHandler);
  m_selector->setUngroomedJets(m_ungroomedjetHandler);
  m_selector->setGroomedJets(m_groomedjetHandler);
  if (m_xJets)
    m_selector->setTrimmedJets(m_trimmedjetHandler);
  m_selector->setMuons(m_muonHandler);
  m_selector->setTaus(m_tauHandler);
  m_selector->setElectrons(m_electronHandler);
  m_selector->setPhotons(m_photonHandler);
  m_selector->setMET(m_METHandler);
  m_selector->setEventInfo(m_eventInfoHandler);
  
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::initializeTools(bool isMC) {
  Info("AnalysisBase::initializeTools", "Initialize CP tools and systematics.");
  
  //---------------------------
  // initialize tools and set systematics
  //---------------------------
  
  if (isMC) {
    m_eventInfoHandler->addVariations(m_variations);
  }
  
  for (ObjectHandlerBase * handler : m_objectHandler) {
    EL_CHECK("initializeTools()",handler->initializeTools());
    if (isMC) {
      EL_CHECK("initializeTools()",handler->addCPVariations(m_variations));
    }
  }
  
  return EL::StatusCode::SUCCESS;
}

EL::StatusCode AnalysisBase::initializeSelection() {
  Info("AnalysisBase::initializeSelection()", "Initialize selection.");
  
  // determine selection name
  
  std::string selectionName = "";
  bool autoDetermineSelection;
  m_config->getif<bool>("autoDetermineSelection", autoDetermineSelection);
  if (!autoDetermineSelection) {
    m_config->getif<std::string>("selectionName", selectionName);
  } else {
    TString sampleName = wk()->metaData()->getString("sample_name");
    if      (sampleName.Contains("HIGG5D1")) selectionName = "0lep";
    else if (sampleName.Contains("HIGG5D2")) selectionName = "1lep";
    else if (sampleName.Contains("HIGG2D4")) selectionName = "2lep";
    else if (sampleName.Contains("SDKJFHDSKJ")) selectionName = "vbf"; // todo : get actual disk name, if available
    else if (sampleName.Contains("JHSJKDHFJK")) selectionName = "vbfa"; // todo : get actual disk name, if available
    else {
      Error("initialize()", "Could not auto determine selection!");
      return EL::StatusCode::FAILURE;
    }
  }

  // initialize event selection

  bool applySelection = false;
  m_config->getif<bool>("applyEventSelection", applySelection);
  if (applySelection) {
    Info("initialize()", "Applying selection: %s", selectionName.c_str());
    if      (selectionName == "0lep") m_selector->setSelection(new VHbb0lepEvtSelection());
    else if (selectionName == "1lep") m_selector->setSelection(new VHbb1lepEvtSelection());
    else if (selectionName == "2lep") m_selector->setSelection(new VHbb2lepEvtSelection());
    else if (selectionName == "vbf" ) m_selector->setSelection(new VBFHbb0phEvtSelection());
    else if (selectionName == "vbfa") m_selector->setSelection(new VBFHbb1phEvtSelection());
    else if (selectionName == "bbtt") m_selector->setSelection(new HHbbtautauSemiLepSelection());
    else {
      Error("initialize()", "Unknown selection requested!");
      return EL::StatusCode::FAILURE;
    }
  }

  // initialize overlap removal (possibly analysis specific)

  OverlapRemoval* overlapRemoval = new OverlapRemoval(*m_config);
  EL_CHECK("initializeSelection()",overlapRemoval->initialize());
  m_selector -> setOverlapRemoval(overlapRemoval);
  
  // TODO make METHandler to cope with non-existing containers and
  //      move this check into event selection
  if ( !m_muonHandler || !m_electronHandler || !m_jetHandler) {
    Error("initialize()", "Not all collections for MET rebuilding are defined!");
    return EL::StatusCode::FAILURE;
  }

  return EL::StatusCode::SUCCESS;
}


EL::StatusCode AnalysisBase::execute() {
  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  // print every 100 events, so we know where we are:
  if ( (m_eventCounter % 100) == 0 ) {
    Info("execute()", "Event number = %li", m_eventCounter);
  }
  ++m_eventCounter;

  //----------------------------
  // Event information
  //--------------------------- 
  bool isMC = m_eventInfoHandler->get_isMC();

  // first event was executed in initialize()
  if (m_eventCounter > 1) {
    m_eventInfoHandler->executeEvent();
  }

  if(isMC){
    // sum the weights of this job
    m_eventWeightCounter += m_eventInfoHandler->get_MCEventWeight();
  }

  // initialize event info output container for writing variations
  EL_CHECK("execute()",m_eventInfoHandler->setOutputContainer());

  //---------------------------
  //perform object calibrations
  //---------------------------
  for (ObjectHandlerBase * handler : m_objectHandler) {
    EL_CHECK("execute()",handler->setObjects());
    EL_CHECK("execute()",handler->calibrate());
  }


  //------------------------
  //perform MET calculation (needs to be done before object selection)
  //------------------------
  EL_CHECK("execute()",m_METHandler->setMET(m_electronHandler->getInParticles(),
					    m_photonHandler->getInParticles(),
					    m_tauHandler->getInParticles(),
					    m_muonHandler->getInParticles(),
					    m_jetHandler->getInParticles()));

  
  //---------------------------
  //perform Jet trimming (needs to be done before object selection)
  //---------------------------
  if (m_xJets) {
    if (m_trimmedjetHandler->getTrimmedJets() !=  EL::StatusCode::SUCCESS ) {
      Error("execute()","Failed to do Trimming to Fat-Jets!");
      return EL::StatusCode::FAILURE;
    }
  }
  
  
  //---------------------------
  //perform object selections
  //---------------------------
  for (ObjectHandlerBase * handler : m_objectHandler) {
    EL_CHECK("execute()",handler->select());
  }

  //------------------------
  // do event selection
  //------------------------

  bool eventPassed = false;
  EL_CHECK("execute()",m_selector->performSelection(eventPassed));
  
  //----------------------
  // fill output container
  //----------------------

  if (eventPassed) {
    m_eventInfoHandler->fillOutputContainer();
    // objects
    bool printCounts;
    m_config->getif<bool>("printObjectCounts", printCounts);
    for (ObjectHandlerBase * handler : m_objectHandler) {
      EL_CHECK("execute()",handler->fillOutputContainer());
      if (printCounts) {
        // count the size of the arrays
	handler->countObjects();
      }
    }
    // MET
    EL_CHECK("execute()",m_METHandler->fillOutputContainer());
    
    // Trimming Jets
    if (m_xJets) EL_CHECK("execute()",m_trimmedjetHandler->fillOutputContainer());
    
  }
  
  

  //-------------------------
  // clean memory allocations
  //-------------------------
  for (ObjectHandlerBase * handler : m_objectHandler) {
    EL_CHECK("execute()",handler->clearEvent());
  }
  EL_CHECK("execute()",m_METHandler->clearEvent());
  
  if (m_xJets) EL_CHECK("execute()",m_trimmedjetHandler->clearEvent());
  
  
  // skip all further execute() and postExecute() if !eventPassed
  if (!eventPassed) {
    // event info is cleared here or in postExecute()
    m_eventInfoHandler->clearEvent();
    wk()->skipEvent();
  }
  
  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode AnalysisBase::postExecute() {
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.
  
  
  //--------------------------
  //save the event in the xAOD
  //--------------------------
  if(m_event->fill() < 0){
    Error("execute()", "Failed writing event to output file!");
  };
  m_histEventCount -> Fill(3); // nEvents selected out

  bool isMC = m_eventInfoHandler->get_isMC();
  if (isMC)  
    m_histEventCount -> Fill(6, m_eventInfoHandler->get_MCEventWeight()); // sumOfWeights selected out

  EL_CHECK("postExecute()",m_eventInfoHandler->clearEvent());

  return EL::StatusCode::SUCCESS;
}


EL::StatusCode AnalysisBase::finalize() {
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events

  Info("AnalysisBase::finalize()", "Finalize.");
  
  // finalize and close our output xAOD file ( and write MetaData tree)
  TFile * file = wk()->getOutputFile("outputLabel");
  TOOL_CHECK("finalize()",m_event->finishWritingTo( file ));
  
  // print object counters
  bool printCounts;
  m_config->getif<bool>("printObjectCounts", printCounts);
  if (printCounts) {
    Info("finalize()", "Printing number of selected objects:");
    for (ObjectHandlerBase * handler : m_objectHandler) {
      // print the size of the arrays
      handler->printObjectCounts();
    }
  }

  // delete handlers
  delete m_eventInfoHandler;
  for (ObjectHandlerBase * handler : m_objectHandler) {
    delete handler;
    handler = 0;
  }

  Info("finalize()", "Number of events:");
  Info("finalize()", "  in input file (meta data) = %li", (long) m_histEventCount -> GetBinContent(2));
  Info("finalize()", "  limit (config)            = %li", m_maxEvent);
  Info("finalize()", "  processed                 = %li", m_eventCounter);
  Info("finalize()", "  written to output         = %li", (long) m_histEventCount -> GetBinContent(3));

  return EL::StatusCode::SUCCESS;

}


EL::StatusCode AnalysisBase::histFinalize() {
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

  Info("AnalysisBase::finalize()", "Finalize histograms.");
  
  // write meta-data histograms to CxAOD file directly, 
  TFile * file = wk()->getOutputFile("outputLabel");
  if (file && m_histEventCount) {
    m_histEventCount -> Fill(7, m_eventCounter); // events in this job
    m_histEventCount -> Fill(8, m_eventWeightCounter); // sumOfWeights in this job
    file->cd();
    m_histEventCount->Write();
  }

  return EL::StatusCode::SUCCESS;
}

void AnalysisBase::printKnownVariations() {
  Info("printKnownVariations()", "Printing all systematic variations to be run in this job:");
  for (TString variation: m_variations) {
    std::cout << variation.Data() << std::endl;
  }
  for (ObjectHandlerBase * handler : m_objectHandler) {
    handler -> printAllVariations();
  }
}
