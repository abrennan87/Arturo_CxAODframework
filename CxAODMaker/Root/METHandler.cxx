#include "iostream"


#include "CxAODMaker/METHandler.h"
#include "METUtilities/METRebuilder.h"
// declare static members
//MuonDecorator MuonHandler::m_decorator;



METHandler::METHandler(ConfigStore *config, xAOD::TEvent *event, int isMC) :
  m_event(event),
  m_isMC(isMC)
{
  //TODO: move this in a initialize() method
  debug=false;
  //debug=true;

  // set container name
  m_config = config; //This is usually defined in ObjectHandler so I add here by hand
  m_containerName = m_config->get<std::string>("METContainer"); //This is usually defined in ObjectHandler so I add here by hand


  //// initialize the MET utilities tool
  m_metutil = new met::METRebuilder("METRebuilderTool");

  // TODO retrive message level from config
  m_metutil->msg().setLevel( MSG::WARNING );

  // Nominal settings 
  m_contSysName="Nominal";


  //// Closure test without calibrated objects
  //m_contSysName="Original";
  //std::string m_softTermType="Reference";
  //m_metutil->setProperty( "SoftTermType", m_softTermType);

  /// Settings equivalent to "Reference":
  //std::string SoftTerm = "SoftClus";
  //bool DoJetJVFCut = false;
  //std::string SoftJetScale = "JetConstitScaleMomentum";
  //double CalibJetPtCut = 0.;


  //Turning on CST MET because TST not possible without new Derivations
  std::string m_softTermType="ClusterSoftTerm";
  if(!m_metutil->setProperty( "SoftTermType", m_softTermType).isSuccess()){
    std::cerr << "Cannot set soft term type for METRebuilder" << std::endl; // or substitute your favourite messaging macro - OR implement an initialize/set tools etc function that returns a status code to AnalysisBase. ;-)
    std::cerr << "Exiting... " << std::endl;
  }
  


  if( m_metutil->initialize()  != StatusCode::SUCCESS){
    std::cerr << "Cannot intialize METRebuilder" << std::endl; // or substitute your favourite messaging macro - OR implement an initialize function that returns a status code to AnalysisBase. ;-)
    std::cerr << "Exiting... " << std::endl;
    exit(-1);
  }




//  // TODO: move to AnalysisBase
//  // get recommended systematic uncertainties from registry and add them to list
//  //----------------------------------------------------------------------------
//  const CP::SystematicRegistry& registry = CP::SystematicRegistry::getInstance();
//  // SystematicSet = set storing SystematicVariation(s)
//  const CP::SystematicSet& recommendedSystematics = registry.recommendedSystematics();
//
//  // this is the nominal set, no systematic -> empty!
//  m_sysList.push_back(CP::SystematicSet());
//  // loop on recommended systematic and add them to list if tool is affected
//  for (const CP::SystematicVariation sysVar : recommendedSystematics) {
//    std::cout << "sysVar.name() " << sysVar.name() << std::endl;
//    std::cout << "MonCalibrationAndSmearingTool is affected? "
//            << m_muonCalibrationAndSmearingTool->isAffectedBySystematic(sysVar)
//            << std::endl;
//    // check if tool is affected by systematic, if yes add it to list
//    if (m_muonCalibrationAndSmearingTool->isAffectedBySystematic(sysVar)) {
//      // CP tools take sets in order to be able to apply several systematic variations at once,
//      // but most of the times they just store one systematic variation
//      m_sysList.push_back(CP::SystematicSet());
//      m_sysList.back().insert(sysVar);
//    }
//  }

}

METHandler::~METHandler() {
  ////delete tool:
  //if (m_metutil) {
  //  delete m_metutil;
  //  m_metutil = nullptr;
  //}
}


EL::StatusCode METHandler::setMET(std::map<TString, xAOD::ElectronContainer*>* elec,
				  std::map<TString, xAOD::PhotonContainer*>* gamma,
				  std::map<TString, xAOD::TauJetContainer*>* taujet,
				  std::map<TString, xAOD::MuonContainer*>* muon,
				  std::map<TString, xAOD::JetContainer*>* jet){



  if(debug)std::cout << "SETTING MET" << std::endl;

  m_eleTerm      = "RefEle";
  m_gammaTerm    = "RefGamma";
  m_tauTerm      = "RefTau";
  m_jetTerm      = "RefJet";
  m_muonTerm     = "Muons";
  m_softTerm     = "SoftClus";
  m_inputMap     = "METMap_RefFinal";
  m_inputMETCont = "MET_RefFinal";
  m_outMETTerm   = "Final";

  m_inputMETTrackCont = "MET_Track";

  const xAOD::MissingETContainer* inputMETContainer = nullptr;
  TOOL_CHECK("METHandler::setMET()",m_event->retrieve( inputMETContainer, m_inputMETCont ));

  xAOD::MissingETContainer::const_iterator met_it = inputMETContainer->find("Final");

  if (met_it == inputMETContainer->end()) {
    Error("METHandler::setMET()", "No RefFinal inside MET container. Exiting.");
    return EL::StatusCode::FAILURE;
  }

  const xAOD::MissingETComponentMap* metMap = nullptr;
  TOOL_CHECK("METHandler::setMET()",m_event->retrieve(metMap, m_inputMap));


  //                                                                                                                                             
  // MET Track                                                                                                                                   
  //                                                                                                                                             
  const xAOD::MissingETContainer* inputMETTrackContainer = nullptr;
  if( m_event->retrieve( inputMETTrackContainer, m_inputMETTrackCont ).isFailure() ) {
    Error("METHandler::setMET()", "Failed to retrieve MET_Track container. Exiting.");
    return EL::StatusCode::FAILURE;
  }

  xAOD::MissingETContainer::const_iterator mettrack_it = inputMETTrackContainer->find("Track");

  if (mettrack_it == inputMETTrackContainer->end()) {
    Error("METHandler::setMET()", "No RefFinal inside MET_Track container. Exiting.");
    return EL::StatusCode::FAILURE;
  }



  //// Truth MET
  if(m_isMC){

    const xAOD::MissingETContainer* TruthMETContainer = nullptr;
    TOOL_CHECK("METHandler::setMET()",m_event->retrieve( TruthMETContainer, "MET_Truth" ));
 
    xAOD::MissingETContainer::const_iterator truthMET_it = TruthMETContainer->find("NonInt");
    if (truthMET_it == TruthMETContainer->end()) {
      std::cerr << "No NonInt inside MET_Truth container" << std::endl;
    }
    
    m_TruthMETContainer=(xAOD::MissingETContainer*)TruthMETContainer;
    
    if(debug){
      std::cout << "Truth MET - NonInt:" << std::endl;
      std::cout << " Missing Et (x,y) " << "NonInt: (" << (*truthMET_it)->mpx() << "," <<  (*truthMET_it)->mpy() << ")" << std::endl;
    }
  }
  
  
  
  if(debug){
    std::cout << "Original (Non-Rebuilt) MET:" << std::endl;
    printMET(inputMETContainer); 
    const xAOD::MissingETComponent* component = xAOD::MissingETComposition::getComponent(metMap,m_jetTerm);
    const xAOD::IParticleContainer* testCollection = dynamic_cast<const xAOD::IParticleContainer*>(component->objects().front()->container());
    std::cout << "Njets MET:      " << testCollection->size() << std::endl;
    int counter=0;
    double sumpx=0.;
    double sumpy=0.;
    for (xAOD::IParticle * j : *testCollection) {
      std::cout << "pt["<<counter<<"] " << j->pt() << " px: " << j->p4().Px() << " py: " << j->p4().Py() <<  std::endl;
      counter++;
      sumpx+=j->p4().Px();
      sumpy+=j->p4().Py();
    }
    std::cout << "sum px: " << sumpx << "sum py: " << sumpy << std::endl;
  }

  
  bool doRebuild = false;
  m_config->getif<bool>("applyMETrebuilding", doRebuild);
  
  if(!doRebuild){

    m_METContainer=(xAOD::MissingETContainer*)inputMETContainer;

  }else{
    //--------------------
    // Rebuilding MET
    // Create the new container and its auxiliary store.
    m_METContainer = new xAOD::MissingETContainer();
    xAOD::MissingETAuxContainer* METContainerAux = new xAOD::MissingETAuxContainer();
    m_METContainer->setStore( METContainerAux ); //< Connect the two


    const xAOD::MissingET* oldSoft = xAOD::MissingETComposition::getMissingET(metMap,m_softTerm);
    bool doTracks = MissingETBase::Source::isTrackTerm(oldSoft->source());

    bool m_doEle = true;
    bool m_doGamma = false;
    bool m_doTau = false;
    bool m_doMuon = true;


    if(m_doEle){
      TOOL_CHECK("METHandler::setMET()",m_metutil->rebuildMET(m_eleTerm, &(*m_METContainer), (*elec)[m_contSysName], metMap, doTracks));
    }
    else{
      TOOL_CHECK("METHandler::setMET()",m_metutil->copyMET(m_eleTerm, &(*m_METContainer), metMap));
    }
    
    if(m_doGamma){
      TOOL_CHECK("METHandler::setMET()",m_metutil->rebuildMET(m_gammaTerm, &(*m_METContainer),  (*gamma)[m_contSysName], metMap, doTracks));
    }
    else{
      TOOL_CHECK("METHandler::setMET()",m_metutil->copyMET(m_gammaTerm, &(*m_METContainer), metMap));
    }
    
    if(m_doTau){
      TOOL_CHECK("METHandler::setMET()",m_metutil->rebuildMET(m_tauTerm, &(*m_METContainer),  (*taujet)[m_contSysName], metMap, doTracks));
    }
    else{
      TOOL_CHECK("METHandler::setMET()",m_metutil->copyMET(m_tauTerm, &(*m_METContainer), metMap));
    }

    if(m_doMuon){
      TOOL_CHECK("METHandler::setMET()",m_metutil->rebuildMET(m_muonTerm, &(*m_METContainer),  (*muon)[m_contSysName], metMap, doTracks));
    }
    else{
      TOOL_CHECK("METHandler::setMET()",m_metutil->copyMET(m_muonTerm, &(*m_METContainer), metMap));
    }
  
    TOOL_CHECK("METHandler::setMET()",m_metutil->rebuildJetMET(m_jetTerm, m_softTerm, &(*m_METContainer), (*jet)[m_contSysName], metMap, doTracks));
    TOOL_CHECK("METHandler::setMET()",m_metutil->buildMETSum(m_outMETTerm, &(*m_METContainer)));

    if(debug)std::cout << "Done rebuilding MET." << std::endl;

    double rebuilt_mpx = (*m_METContainer)[m_outMETTerm]->mpx();
    double rebuilt_mpy = (*m_METContainer)[m_outMETTerm]->mpy();

    if(debug)std::cout << "Rebuilt MET: Missing Et (x,y): (" << rebuilt_mpx << "," <<  rebuilt_mpy << ")" << std::endl;
  }
  

  //                                                                                                                                             
  // Re-build MET_Track                                                                                                                          
  //                                                                                                                                             
  bool doMETTrkRebuild = false;
  // m_config->getif<bool>("applyMETTrackrebuilding", doMETTrkRebuild);                                                                          

  if(!doMETTrkRebuild){

    m_METTrackContainer=(xAOD::MissingETContainer*)inputMETTrackContainer;

  }


  return EL::StatusCode::SUCCESS;
}



void METHandler::printMET(const xAOD::MissingETContainer* METCont) {
   
  std::cout << " Missing Et (x,y) " << m_outMETTerm << ": (" << (*METCont)[m_outMETTerm]->mpx() << "," <<  (*METCont)[m_outMETTerm]->mpy() << ")" << std::endl;
  std::cout << "      " << m_eleTerm << ": (" << (*METCont)[m_eleTerm]->mpx() << "," <<  (*METCont)[m_eleTerm]->mpy() << ")" << std::endl;
  std::cout << "      " << m_muonTerm << ": (" << (*METCont)[m_muonTerm]->mpx() << "," <<  (*METCont)[m_muonTerm]->mpy() << ")" << std::endl;
  std::cout << "      " << m_jetTerm << ": (" << (*METCont)[m_jetTerm]->mpx() << "," <<  (*METCont)[m_jetTerm]->mpy() << ")" << std::endl;
  std::cout << "      " << m_gammaTerm << ": (" << (*METCont)[m_gammaTerm]->mpx() << "," <<  (*METCont)[m_gammaTerm]->mpy() << ")" << std::endl;
  std::cout << "      " << m_tauTerm << ": (" << (*METCont)[m_tauTerm]->mpx() << "," <<  (*METCont)[m_tauTerm]->mpy() << ")" << std::endl;
  std::cout << "      " << m_softTerm << ": (" << (*METCont)[m_softTerm]->mpx() << "," <<  (*METCont)[m_softTerm]->mpy() << ")" << std::endl;

}



xAOD::MissingET* METHandler::getMET() {
  xAOD::MissingETContainer::const_iterator met_it = m_METContainer->find("Final");
  if(met_it == m_METContainer->end()) {
    return nullptr;
  }
  return *met_it;
}


xAOD::MissingET* METHandler::getMETTrack() {
  xAOD::MissingETContainer::const_iterator mettrack_it = m_METTrackContainer->find("Track");
  if(mettrack_it == m_METTrackContainer->end()) {
    return nullptr;
  }
  return *mettrack_it;
}


EL::StatusCode METHandler::fillOutputContainer() {
  //return fillOutputContainerCheck(&checkPassSel);
  //TODO ADD MORE SOPHISTICATED OUTPUT FILLING HERE

  xAOD::MissingETContainer* METNominal = new xAOD::MissingETContainer();
  xAOD::MissingETAuxContainer* METNominalAux = new xAOD::MissingETAuxContainer();
  METNominal->setStore( METNominalAux ); //< Connect the two

  xAOD::MissingETContainer::const_iterator met_it = m_METContainer->find("Final");

  xAOD::MissingET * met = new xAOD::MissingET();
  met->makePrivateStore( **met_it );
  METNominal->push_back( met );


  if (!m_event->record(METNominal, m_containerName + "___Nominal")) {
    return EL::StatusCode::FAILURE;
  }
  if (!m_event->record(METNominalAux, m_containerName + "___NominalAux.")) {
    return EL::StatusCode::FAILURE;
  }




  //
  // Output MET_Track
  //
  xAOD::MissingETContainer* MET_Track_Nominal = new xAOD::MissingETContainer();
  xAOD::MissingETAuxContainer* MET_Track_NominalAux = new xAOD::MissingETAuxContainer();
  MET_Track_Nominal->setStore( MET_Track_NominalAux ); //< Connect the two                                                                       

  xAOD::MissingETContainer::const_iterator mettrk_it = m_METTrackContainer->find("Track");

  xAOD::MissingET * trackMet = new xAOD::MissingET();
  trackMet->makePrivateStore( **mettrk_it );
  MET_Track_Nominal->push_back( trackMet );

  if (!m_event->record(MET_Track_Nominal, "MET_Track___Nominal")) {
    return EL::StatusCode::FAILURE;
  }
  if (!m_event->record(MET_Track_NominalAux, "MET_Track___NominalAux.")) {
    return EL::StatusCode::FAILURE;
  }


  
  if(m_isMC){
    //// Truth MET
    xAOD::MissingETContainer* TruthMETNominal = new xAOD::MissingETContainer();
    xAOD::MissingETAuxContainer* TruthMETNominalAux = new xAOD::MissingETAuxContainer();
    TruthMETNominal->setStore( TruthMETNominalAux ); //< Connect the two
    
    xAOD::MissingETContainer::const_iterator truthMet_it = m_TruthMETContainer->find("NonInt");
    
    xAOD::MissingET * truthMet = new xAOD::MissingET();
    truthMet->makePrivateStore( **truthMet_it );
    TruthMETNominal->push_back( truthMet );
    
    
    if (!m_event->record(TruthMETNominal, "MET_Truth___Nominal")) {
      return EL::StatusCode::FAILURE;
    }
    if (!m_event->record(TruthMETNominalAux, "MET_Truth___NominalAux.")) {
      return EL::StatusCode::FAILURE;
    }
  }
    


  return EL::StatusCode::SUCCESS;
}

EL::StatusCode METHandler::clearEvent() {

  bool doRebuild = false;
  m_config->getif<bool>("applyMETrebuilding", doRebuild);
  if(doRebuild){
    delete m_METContainer->getConstStore();
    m_METContainer->setConstStore(nullptr);
    delete m_METContainer;
    m_METContainer = nullptr;
  }

  return EL::StatusCode::SUCCESS;
}

