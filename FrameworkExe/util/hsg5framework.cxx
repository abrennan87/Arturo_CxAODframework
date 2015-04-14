#include "xAODRootAccess/Init.h"
#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "SampleHandler/DiskListLocal.h"
#include "SampleHandler/DiskListXRD.h"
#include "EventLoop/Job.h"
#include "EventLoop/DirectDriver.h"
#include "EventLoopGrid/PrunDriver.h"

#include <iostream>
#include <fstream>
#include <TSystem.h> 
#include <stdlib.h> 

#include "CxAODMaker/AnalysisBase.h"
#include "CxAODTools/ConfigStore.h"
#include "TupleMaker/TupleMaker.h"

#include "AsgTools/StatusCode.h"
#include "EventLoop/StatusCode.h"
#include "PATInterfaces/CorrectionCode.h"
#include "PATInterfaces/SystematicCode.h"

int main(int argc, char* argv[]) {

  // steer file has to put here: FrameworkExe/data/framework-run.cfg
  // RootCore will copy it to $ROOTCOREBIN/data/FrameworkExe/framework-run.cfg
  // ConfigStore::createStore() will prepend "$ROOTCOREBIN/" to the path given
  std::string configPath = "data/FrameworkExe/framework-run.cfg";
  static ConfigStore* config = ConfigStore::createStore( configPath );
  if (!config) {
    Error("hsg5framework","Couldn't instantiate ConfigStore");
    return 0;
  }

  // enable failure on unchecked status codes
  bool enableFailure = false;
  config->getif<bool>("failUncheckedStatusCodes", enableFailure);
  if (enableFailure) {
    xAOD::TReturnCode::enableFailure();
    StatusCode::enableFailure();
    CP::CorrectionCode::enableFailure();
    CP::SystematicCode::enableFailure();
  }
  
  // output directory and file names (if not specified in steer file, default names are used)
  //  - output directory (submitDir)
  //  - output file name (sample_out) - in grid mode this is overridden below
  std::string submitDir  = "submitDir";
  std::string sample_out = "CxAOD"; 
  config->getif<std::string>("submitDir",submitDir);
  config->getif<std::string>("sample_out",sample_out);

  // check that output directory does not exist (otherwise EventLoop will crash)
  if (!gSystem->AccessPathName(submitDir.c_str())) {
    Error("hsg5framework","Output directory already exists, please change the value of submitDir in the configuration file");
    return 0;
  }

  // input sample name
  // - local running : the path to the directory required by SampleHandler
  // - grid running  : the path to a text file containing sample names (sample_in must contain the word "grid" to activate grid running) 
  std::string sample_in  = ""; 
  sample_in = config->get<std::string>("sample_in");
  // for grid running - contains sample names from text file
  std::vector<std::string> sample_name_in;

  // set up the job for xAOD access:
  xAOD::Init().ignore();
  
  // define if interactive or grid job, taken from 'grid' existing in name of submission text file
  // see https://twiki.cern.ch/twiki/bin/view/AtlasProtected/CxAODFramework#Grid_running
  bool grid = sample_in.find("grid") != std::string::npos;
  Info("hsg5framework","Run on grid = %s", grid ? "true" : "false");

  // instantiate SampleHandler
  SH::SampleHandler sampleHandler;

  // set input samples
  if (!grid) {
    std::string prefix = "/eos/";
    if ( sample_in.substr(0, prefix.size()).compare(prefix) == 0 ) {
      // read from eos                                                                                                                                                                                                                 
      SH::DiskListXRD list("eosatlas.cern.ch", sample_in, true);
      SH::scanDir(sampleHandler, list);
    }
    else {
      // read from local disk                                                                                                                                                                                                          
      SH::DiskListLocal list(sample_in);
      SH::scanSingleDir(sampleHandler, sample_out, list);
    }
  }
  else {
    // read input file
    std::ifstream infile;
    infile.open(sample_in);
    std::string line;
    while (!infile.eof()) {
      getline(infile, line);
      // don't run over commented lines
      if (line.find("#") != std::string::npos) continue;
      // add sample name to vector
      sample_name_in.push_back(line);
    }
    infile.close();
    // check if text file contains sample names
    if ( sample_name_in.size() == 0) {
      Info("hsg5framework","No samples specified in text file!");
      return 0;
    }
    // declare the jobs
    const int n_sample_name_in = static_cast<int>(sample_name_in.size()) - 1;
    for (int isam = 0; isam < n_sample_name_in; ++isam) {
      SH::scanDQ2 (sampleHandler, sample_name_in[isam]);
      //std::cout << "sample -> " << sample_name_in[isam] << std::endl;
    }
  }
  // Set the name of the input TTree. It's always "CollectionTree" for xAOD files.
  sampleHandler.setMetaString("nc_tree", "CollectionTree");
  //sampleHandler.setMetaString("nc_grid_filter", "AOD.01512594._000099.pool.root.1"); // use only 1 file to run on

  // print what we found:
  sampleHandler.print();

  // create an EventLoop job:
  EL::Job job;
  job.sampleHandler(sampleHandler);

  // limit number of events to maxEvents - set in config
  int eventMax = -1;
  config->getif<int>("maxEvents",eventMax);
  job.options()->setDouble (EL::Job::optMaxEvents, eventMax);
  // Set the xAOD access mode of the job:
  job.options()->setString( EL::Job::optXaodAccessMode, EL::Job::optXaodAccessMode_branch );

   // setup CxAODMaker
  AnalysisBase* algorithm = new AnalysisBase();
  algorithm->m_maxEvent = static_cast<int>(job.options()->getDouble(EL::Job::optMaxEvents));
  algorithm->setConfig(configPath);
  
  job.algsAdd(algorithm);

  // setup TupleMaker
  bool runTupleMaker = true;
  config->getif<bool>("runTupleMaker",runTupleMaker);
  if (runTupleMaker) {
    TupleMaker* tupleMaker = new TupleMaker();
    tupleMaker->configure(configPath);
    job.algsAdd(tupleMaker);
  }

  // run the job using the direct driver (local) or the prun driver (grid)
  if (!grid) {
    EL::DirectDriver driver;
    driver.submit(job, submitDir);
  }
  else {
    EL::PrunDriver driver;
    // determine aod_tag name
    std::string aod_tag = "CAOD";
    if (sample_name_in[0].find("CAOD") != std::string::npos) aod_tag = "FINAL"; // if we produce the final histos at this step, maybe useless
    // determine ana_tag name
    std::string ana_tag = "ana_tag"; // default value if it cannot be determined below
    bool ana_tag_flag = false;
    config->getif<bool>("autoDetermineSelection",ana_tag_flag);
    if (!ana_tag_flag) {
      std::string selectionName = "";
      config->getif<std::string>("selectionName",selectionName);
      if      (selectionName == "0lep") ana_tag = "HIGG5D1";
      else if (selectionName == "1lep") ana_tag = "HIGG5D2";
      else if (selectionName == "2lep") ana_tag = "HIGG2D4";
    }
    else {
      if      (sample_name_in[0].find("HIGG5D1") != std::string::npos) ana_tag = "HIGG5D1";
      else if (sample_name_in[0].find("HIGG5D2") != std::string::npos) ana_tag = "HIGG5D2";
      else if (sample_name_in[0].find("HIGG2D4") != std::string::npos) ana_tag = "HIGG2D4";
    }
    // form needed names
    std::string vtag = "vtag"; // default in case it is not specified in steer file
    config->getif<std::string>("vtag",vtag);
    std::ostringstream ostr_sample_out;
    ostr_sample_out << "user.%nickname%.%in:name[1]%.%in:name[2]%.%in:name[3]%." << aod_tag << "_" << ana_tag << "." << vtag;
    sample_out = ostr_sample_out.str();
    // options
    driver.options()->setString("nc_outputSampleName", sample_out); // output job name
    // 
    double nFilesPerJob = -1.;
    config->getif<double>("nFilesPerJob",nFilesPerJob);
    if (nFilesPerJob > 0) driver.options()->setDouble("nc_nFilesPerJob", nFilesPerJob);
    //
    double nGBPerJob = -1.;
    config->getif<double>("nGBPerJob",nGBPerJob);
    if (nGBPerJob > 0) {
      if (nGBPerJob == 1000.) driver.options()->setString("nc_nGBPerJob", "MAX");
      else driver.options()->setDouble("nc_nGBPerJob", nGBPerJob);
    }
    //
    std::string excludedSite = "none";
    config->getif<std::string>("excludedSite",excludedSite);
    if (excludedSite != "none") driver.options()->setString("nc_excludedSite", excludedSite);
    //
    bool submit = false;
    config->getif<bool>("submit",submit);
    if (!submit) {
      driver.options()->setDouble("nc_noSubmit", 1);
      driver.options()->setDouble("nc_showCmd", 1);
    }
    //driver.options()->setString("nc_mergeOutput", "true"); // can't do for CxAOD
    driver.options()->setString("nc_mergeOutput", "false"); // force to not merge
    // run
    //driver.submit(job, submitDir); // with monitoring
    driver.submitOnly(job, submitDir); // no monitoring
  }

  return 0;

}

