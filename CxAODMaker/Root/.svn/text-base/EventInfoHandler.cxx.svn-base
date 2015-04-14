#include <iostream>

#include "EventLoop/StatusCode.h"
#include "xAODRootAccess/TEvent.h"
#include "xAODCore/AuxInfoBase.h"
#include "xAODCore/ShallowAuxInfo.h"
#include "xAODTracking/Vertex.h"
#include "CxAODMaker/EventInfoHandler.h"
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
#include "CxAODTools/ConfigStore.h"
#include "CxAODTools/ReturnCheck.h"

EventInfoHandler::EventInfoHandler(ConfigStore & config, xAOD::TEvent * event) :
  m_config(config),
  m_debug(false),
  m_msgLevel(MSG::WARNING),
  m_grl(""),
  m_event(event),
  m_eventInfoIn(nullptr),
  m_decorator(),
  m_grlSelectionTool(nullptr),
  m_pileupreweighting("PileupReweightingTool"),
  m_trigConfigTool(nullptr),
  m_trigDecTool(nullptr),
  m_isMC(-1),
  m_triggerStream(-1),
  m_indexPV(-1),
  m_is8TeV(false)
{

}
EventInfoHandler::~EventInfoHandler(){
  delete m_grlSelectionTool;
  delete m_trigConfigTool;
  delete m_trigDecTool;
}


EL::StatusCode EventInfoHandler::initialize() {

  //TODO: find better way - will MetaData become available?
  //check beam energy 
  //-------------------
  std::string sample_in = "";
  m_config.getif<std::string>("sample_in",sample_in);
  if(sample_in.find("13TeV") != std::string::npos){
    m_is8TeV = false;
    Info("EventInfoHandler::initialize()", "Running on 13 TeV sample.");
  }
  else if(sample_in.find("8TeV") != std::string::npos){
    m_is8TeV = true;
    Info("EventInfoHandler::initialize()", "Running on 8 TeV sample.");
  }
  else{
    Error("EventInfoHandler::initialize()", "Did not manage to find out beam energy! Exiting."); 
    return EL::StatusCode::FAILURE;
  }
    
  // GRL
  //-------
  m_config.getif<std::string>("grl",m_grl);

  // GRL selection tool
  //--------------------
  m_grlSelectionTool = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");
  // TODO retrieve message level from config
  m_grlSelectionTool->msg().setLevel( MSG::WARNING );
  std::vector<std::string> vecStringGRL;
  vecStringGRL.push_back(m_grl);
  
  TOOL_CHECK("EventInfoHandler::initialize()",m_grlSelectionTool->setProperty("GoodRunsListVec", vecStringGRL));
  // if true (default) will ignore result of GRL and will just pass all events
  TOOL_CHECK("EventInfoHandler::initialize()",m_grlSelectionTool->setProperty("PassThrough", false));
  TOOL_CHECK("EventInfoHandler::initialize()",m_grlSelectionTool->initialize());
     
  //pileup reweighting tool
  //---------------------------
  // pileup reweighting available only for 8TeV
  if (m_is8TeV) {
    // Inspired on Ref.[http://epweb2.ph.bham.ac.uk/user/head/AnalysisTop-2.0.24/ScaleFactorCalculator_8cxx_source.html]
    const std::string rc = std::string(getenv("ROOTCOREBIN"));
    //pileup weighting
    //this is stored in some web area: http://atlas.web.cern.ch:80/Atlas/GROUPS/DATABASE/GroupData/PileupReweighting/mc14v1_defaults.prw.root
    std::vector<std::string> prw {"PileupReweighting/mc14v1_defaults.prw.root" };
    //I had to provide a trigger to get the right int luminosity, but all (isolated and unisolated for e and mu)
    //triggers gave the same value - so let's just use the histogram from the EF e24vhi trigger
    std::vector<std::string> lc {rc + "/data/CxAODMaker/ilumicalc_histograms_EF_e24vhi_medium1_202660-205113.root"};
    TOOL_CHECK("EventInfoHandler::initialize()",m_pileupreweighting.setProperty("ConfigFiles", prw));
    TOOL_CHECK("EventInfoHandler::initialize()",m_pileupreweighting.setProperty("LumiCalcFiles", lc));
    TOOL_CHECK("EventInfoHandler::initialize()",m_pileupreweighting.initialize());
  }
  
  //trigger tool
  //----------------
  //get list of triggers from config
  m_triggerList.clear();
  m_config.getif< std::vector<std::string> >("triggerList", m_triggerList);
  if(!m_triggerList.size()) Warning("EventInfoHandler::initialize()","No trigger defined!");
  else{
    //xAODConfigTool
    m_trigConfigTool = new TrigConf::xAODConfigTool ("xAODConfigTool");
    m_trigConfigTool->msg().setLevel( m_msgLevel );
    TOOL_CHECK("EventInfoHandler::initialize()",m_trigConfigTool->initialize());
    ToolHandle<TrigConf::ITrigConfigTool> handle(m_trigConfigTool);
    TOOL_CHECK("EventInfoHandler::initialize()",handle->initialize());
    //TrigDecisionTool
    m_trigDecTool = new Trig::TrigDecisionTool("TrigDecisionTool");
    m_trigDecTool->msg().setLevel( m_msgLevel );
    TOOL_CHECK("EventInfoHandler::initialize()",m_trigDecTool->setProperty("ConfigTool",handle));
    TOOL_CHECK("EventInfoHandler::initialize()",m_trigDecTool->setProperty("TrigDecisionKey","xTrigDecision"));
    TOOL_CHECK("EventInfoHandler::initialize()",m_trigDecTool->setProperty("OutputLevel", m_msgLevel));
    TOOL_CHECK("EventInfoHandler::initialize()",m_trigDecTool->initialize());
  }
  return EL::StatusCode::SUCCESS;
}


EL::StatusCode EventInfoHandler::addVariations(const std::vector<TString> &variations)
{

  // here we filter the variations that affect the event info
  for (TString variation : variations) {
    // TODO: check for duplications? maybe use set...    
    if (variation.EqualTo("Nominal")) continue;
    if (variation.EqualTo("Original")) continue;
    // allow scale factors
    bool allow = false;
    allow |= variation.Contains("MUONSFSYS");
    allow |= variation.Contains("EL_EFF");
    if (!allow) continue;
    m_variations.push_back(variation);
  }

  return EL::StatusCode::SUCCESS;
}


EL::StatusCode EventInfoHandler::executeEvent() 
{

  // the output containers are not initialized when this function is called
  // (since the isMC flag is needed for that)
  
  //----------------------------
  // Event information
  //--------------------------- 

  // retrieve event info from TEvent
  //---------------------------------
  const xAOD::EventInfo * eventInfoIn = 0;
  if ( ! m_event->retrieve(eventInfoIn, "EventInfo").isSuccess() ) {
    Error("EventInfoHandler::executeEvent()", "Failed to retrieve event info collection. Exiting.");
    return EL::StatusCode::FAILURE;
  }
  std::pair< xAOD::EventInfo *, xAOD::ShallowAuxInfo *> sc_eventInfo = shallowCopyObject(*eventInfoIn);
  m_eventInfoIn = sc_eventInfo.first; 
  
  // check if MC or data
  //---------------------
  m_isMC = static_cast<int>(m_eventInfoIn->eventType(xAOD::EventInfo::IS_SIMULATION));
  if ( ! (m_isMC==0 || m_isMC==1) ) {
    Error("EventInfoHandler::executeEvent()", "Couldn't determine if the sample is MC!");
    return EL::StatusCode::FAILURE;
  }
  m_decorator.set(m_eventInfoIn, EventInfoIntProps::isMC, m_isMC);// use a custom decorator for isMC to avoid bit map
 
  //if MC
  //---------
  if ( m_isMC ) {
    
    //retrieve mc weight
    if (eventInfoIn->mcEventWeights().size() != 1) {
      Error("EventInfoHandler::executeEvent()", "Number of MC weights is not 1!");
      return EL::StatusCode::FAILURE;
    }
    m_decorator.set(m_eventInfoIn, EventInfoFloatProps::MCEventWeight, eventInfoIn->mcEventWeight(0));// use a custom decorator for mcEventWeight, since the original info is a vector

    //--------------------
    //pileup reweighting:  retrieve weight and decorate m_eventInfoIn
    //--------------------
    // pileup reweighting available only for 8TeV
    //  based upon Ref.[https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/ExtendedPileupReweighting#Example_in_Root_base_analysis]
    if ( m_is8TeV ) {     
      m_pileupreweighting.apply(eventInfoIn); // produces a decoration in Eventinfo (type is double)
      // this duplicates information in the EventInfo : PileupWeight && Pileupweight (can't have the same name for different types - float vs. double)
      m_decorator.set(m_eventInfoIn, EventInfoFloatProps::Pileupweight, static_cast<float>(m_eventInfoIn->auxdata< double >( "PileupWeight" )));
    }
    else {
      m_decorator.set(m_eventInfoIn, EventInfoFloatProps::Pileupweight, 1);
    }
  } else { 
    // if data
    //----------
    // set mcweight and  pileupweight to 1 to avoid problems downstream 
    m_decorator.set(m_eventInfoIn, EventInfoFloatProps::MCEventWeight, 1);  
    m_decorator.set(m_eventInfoIn, EventInfoFloatProps::Pileupweight, 1);   
    //TODO readout stream
    // for( const auto& st :  m_eventInfoIn->streamTags() ) {
    //   std:: string streamname = st.name();
    //   st.type();
    //   std::cout<<"EventInfoHandler Execute: Stream "<<streamname<<std::endl;
    // }

    //----------
    //GRL:         check if GRL is passed and decorate m_eventInfoIn
    //----------
    int passGRL = true;
    if (!m_grlSelectionTool->passRunLB(*eventInfoIn)) passGRL = false;
    m_decorator.set(m_eventInfoIn, EventInfoIntProps::passGRL, passGRL);

    //--------------
    //Event cleaning:  check if event is clean and decorate m_eventInfoIn
    //--------------
    int isCleanEvent = true;
    if ((eventInfoIn->errorState(xAOD::EventInfo::EventFlagSubDet::Tile) == xAOD::EventInfo::Error)
            || (eventInfoIn->errorState(xAOD::EventInfo::EventFlagSubDet::LAr) == xAOD::EventInfo::Error)
            || (eventInfoIn->isEventFlagBitSet(xAOD::EventInfo::Core, 18))) {
      isCleanEvent = false;
    }
    m_decorator.set(m_eventInfoIn, EventInfoIntProps::isCleanEvent, isCleanEvent);
  }

  //---------------
  //Trigger info:   retrieve information and decorate m_eventInfoIn      
  //---------------
  // Set TriggerStream information
  m_decorator.set(m_eventInfoIn, EventInfoIntProps::TriggerStream, m_triggerStream); 

  //get trigger decision of triggers defined in config
  for (std::string trigger : m_triggerList){
    bool triggerIsPassed = m_trigDecTool->isPassed(trigger);
    EventInfoIntProps trigDecDecorator;
    EL_CHECK("EventInfoHandler::executeEvent()",findTrigDecDecorator(trigger,trigDecDecorator));
    m_decorator.set(m_eventInfoIn, trigDecDecorator, (int)triggerIsPassed);
    if(m_debug) Info("EventInfoHandler::executeEvent()","Decision for trigger %s: %i",trigger.c_str(),(int) triggerIsPassed) ; 
  }
  if(m_debug && m_triggerList.size()){
    //print list of triggers in inpput file
    Info("EventInfoHandler::initialize()","list of triggers in input file :");
    auto chainGroup = m_trigDecTool->getChainGroup(".*");
    for(auto &trig : chainGroup->getListOfTriggers()){
      Info("EventInfoHandler::initialize()",trig.c_str());
    }
  }

  //--------------
  //Vertex info:   retrieve information and decorate m_eventInfoIn 
  //--------------

  // primary vertex
  const xAOD::Vertex * primVtx = 0;
  int nVtx3Trks = 0;
  // get the vertex container
  const xAOD::VertexContainer * primVtxCont = 0;
  if ( ! m_event->retrieve(primVtxCont, "PrimaryVertices").isSuccess() ) {
    Error("EventInfoHandler::executeEvent()", "Failed to retrieve primary vertices collection. Exiting.");
    return EL::StatusCode::FAILURE;
  } 

  // find the primary vertex and count the number of vertices with at least 2 tracks
  int indexPV = 0;
  for (const xAOD::Vertex * vtx : *primVtxCont) {
    //ask for type - no need to ask for at least two associated tracks anymore
    if ( vtx->vertexType() == xAOD::VxType::PriVtx ) {
      primVtx = vtx;
      m_indexPV = indexPV;
    }
    if ( vtx->nTrackParticles() > 2 ) ++nVtx3Trks;
    indexPV++;
  }

  // check if primary vertex is found
  float ZPV = -9999;
  if ( ! primVtx ) {
    Warning("EventInfoHandler::executeEvent()", "Couldn't find a primary vertex in this event!");
  } 
  else {
    ZPV = primVtx->z();
  }
  m_decorator.set(m_eventInfoIn, EventInfoIntProps::hasPV, primVtx != 0);
  m_decorator.set(m_eventInfoIn, EventInfoFloatProps::ZPV, ZPV);
  m_decorator.set(m_eventInfoIn, EventInfoIntProps::NVtx3Trks, nVtx3Trks);

  return EL::StatusCode::SUCCESS;
  
}


EL::StatusCode EventInfoHandler::setOutputContainer() {

  // create containers
  xAOD::EventInfo * eventInfoOutNominal = new xAOD::EventInfo();
  xAOD::AuxInfoBase * eventInfoOutNominalAux = new xAOD::AuxInfoBase();
  eventInfoOutNominal->setStore(eventInfoOutNominalAux);
  
  m_eventInfosOut["Nominal"] = eventInfoOutNominal;
  
  // record event info (yes, can be done before setting the actual values)
  if ( ! m_event->record(eventInfoOutNominal, "EventInfo___Nominal") ) {
    return EL::StatusCode::FAILURE;
  }
  if ( ! m_event->record(eventInfoOutNominalAux, "EventInfo___NominalAux.") ) {
    return EL::StatusCode::FAILURE;
  }

  // create a shallow copies e.g. for systematic variations of the event weights
  for (TString variation : m_variations) {
    std::pair< xAOD::EventInfo *, xAOD::ShallowAuxInfo *> eventInfoOutSC = shallowCopyObject(*eventInfoOutNominal);
    if ( ! m_event->record(eventInfoOutSC.first, ("EventInfo___" + variation).Data())) {
      return EL::StatusCode::FAILURE;
    }
    if ( ! m_event->record(eventInfoOutSC.second, ("EventInfo___" + variation + "Aux.").Data())) {
      return EL::StatusCode::FAILURE;
    }
    
    m_eventInfosOut[variation] = eventInfoOutSC.first;
  }
  return EL::StatusCode::SUCCESS;
}


void EventInfoHandler::setVariables(xAOD::EventInfo* eventInfoIn, xAOD::EventInfo* eventInfoOut) {

  eventInfoOut->setRunNumber(eventInfoIn->runNumber());
  eventInfoOut->setEventNumber(eventInfoIn->eventNumber());
  eventInfoOut->setAverageInteractionsPerCrossing(eventInfoIn->averageInteractionsPerCrossing());  // TODO remove?
  m_decorator.copy(eventInfoIn, eventInfoOut, EventInfoIntProps::isMC);
  for (std::string trigger : m_triggerList){
    EventInfoIntProps trigDecDecorator;
    if(findTrigDecDecorator(trigger,trigDecDecorator) == EL::StatusCode::SUCCESS){
      m_decorator.copy(eventInfoIn, eventInfoOut, trigDecDecorator);
    }
    else Error("EventInfoHandler::setVariables()","Can't copy decision for trigger %s to output, decorator is not defined!",trigger.c_str());
  }
  if ( m_isMC ) {
    eventInfoOut->setMCEventNumber(eventInfoIn->mcEventNumber());
    eventInfoOut->setMCChannelNumber(eventInfoIn->mcChannelNumber());
    m_decorator.copy(eventInfoIn, eventInfoOut, EventInfoFloatProps::MCEventWeight);
    m_decorator.copy(eventInfoIn, eventInfoOut, EventInfoFloatProps::Pileupweight);
  } else {
    m_decorator.copy(eventInfoIn, eventInfoOut, EventInfoIntProps::passGRL); // TODO remove?
    m_decorator.copy(eventInfoIn, eventInfoOut, EventInfoIntProps::isCleanEvent); // TODO remove?
  }
  m_decorator.copy(eventInfoIn, eventInfoOut, EventInfoFloatProps::ZPV);
  m_decorator.copy(eventInfoIn, eventInfoOut, EventInfoIntProps::NVtx3Trks);

}


EL::StatusCode EventInfoHandler::fillOutputContainer() 
{
  
  // this is currently nominal only

  if (!m_eventInfosOut.count("Nominal")) {
    Error("EventInfoHandler::fillOutputContainer()", "No Nominal output container defined!");
    return EL::StatusCode::FAILURE;
  }
  
  setVariables(m_eventInfoIn, m_eventInfosOut["Nominal"]);

  return EL::StatusCode::SUCCESS;

}

xAOD::EventInfo * EventInfoHandler::getOutEventInfoVariation(const TString &variation) {

  if (m_eventInfosOut.count(variation)) {
    return m_eventInfosOut[variation];
  }
  if (m_eventInfosOut.count("Nominal")) {
    return m_eventInfosOut["Nominal"];
  }
  return nullptr;
}

EL::StatusCode EventInfoHandler::clearEvent()
{
  
  delete m_eventInfoIn->getConstStore();
  delete m_eventInfoIn;
  m_eventInfoIn = 0;
  
  return EL::StatusCode::SUCCESS;

}


EL::StatusCode EventInfoHandler::findTrigDecDecorator(std::string triggerName, EventInfoIntProps& trigDecDecorator)
{
  if(triggerName == "HLT_xe100")                 trigDecDecorator = EventInfoIntProps::passHLT_xe100;
  else if(triggerName == "HLT_e28_tight_iloose") trigDecDecorator = EventInfoIntProps::passHLT_e28_tight_iloose;
  else if(triggerName == "HLT_e60_medium1")      trigDecDecorator = EventInfoIntProps::passHLT_e60_medium1;
  else if(triggerName == "HLT_2e17_loose1")      trigDecDecorator = EventInfoIntProps::passHLT_2e17_loose1;
  else if(triggerName == "HLT_mu26_imedium")     trigDecDecorator = EventInfoIntProps::passHLT_mu26_imedium;
  else if(triggerName == "HLT_mu50")             trigDecDecorator = EventInfoIntProps::passHLT_mu50;
  else if(triggerName == "HLT_2mu14")            trigDecDecorator = EventInfoIntProps::passHLT_2mu14;
  else{
    Error("EventInfoHandler::decorateTrigDec()","No decorator for trigger %s defined! Need to create one.", triggerName.c_str());
    return EL::StatusCode::FAILURE;
  }

  return EL::StatusCode::SUCCESS;
}
