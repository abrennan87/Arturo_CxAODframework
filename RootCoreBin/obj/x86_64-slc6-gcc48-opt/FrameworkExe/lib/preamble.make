RC_CXX       = g++
RC_LD        = g++
RC_CXXFLAGS  = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkExe/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkExe -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"FrameworkExe\" 
RC_DICTFLAGS = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkExe/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkExe -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"FrameworkExe\" 
RC_INCFLAGS  = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkExe/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkExe -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -DROOTCORE -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"FrameworkExe\"
RC_LIBFLAGS  = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic 
RC_BINFLAGS  = -L/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/lib -L/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/lib/x86_64-slc6-gcc48-opt -lTupleMaker -lTupleReader -lEventLoopGrid -lCxAODReader -lCxAODMaker -lxAODHelpers -lBosonTaggerXAOD -lxAODAnaHelpers -lJetSubStructureMomentTools -lJetRec -lJetSubStructureUtils -lJetEDM -lfastjetplugins -lsiscone_spherical -lsiscone -lfastjettools -lfastjet -lTrigDecisionTool -lTrigSteeringEvent -lTrigNavStructure -lTrigConfxAOD -lTrigConfHLTData -lTrigConfL1Data -lTrigConfBase -lPileupReweighting -lHist -lTauAnalysisTools -lMETUtilities -lboost_unit_test_framework -lInDetTrackSelectionTool -lElectronIsolationSelection -lElectronPhotonSelectorTools -lElectronEfficiencyCorrection -lXMLIO -lXMLParser -lTreePlayer -lTree -lxml2 -lElectronPhotonFourMomentumCorrection -lPhysics -lHist -legammaMVACalib -lTMVA -lHist -legammaLayerRecalibTool -lHist -lJetUncertainties -lHist -lJetResolution -lTreePlayer -lPhysics -lTree -lHist -lJetSelectorTools -lJetCalibTools -lMathCore -lCore -lPhysics -lTree -lxAODEventShape -lJetInterface -lMuonMomentumCorrections -lMuonSelectorTools -lMuonEfficiencyCorrections -lGoodRunsLists -lXMLIO -lXMLParser -lTreePlayer -lTree -lxml2 -lCxAODTools -lxAODMissingET -lxAODBTaggingEfficiency -lPathResolver -lboost_filesystem -lHist -lCalibrationDataInterface -lRIO -lHist -lMatrix -lPATCore -lPATInterfaces -lEventLoop -lProofPlayer -lProof -lHist -lTree -lSampleHandler -lPyROOT -lProof -lTree -lRootCoreUtils -lTree -lHist -lAssociationUtils -lxAODTau -lGenVector -lxAODJet -lGenVector -lxAODPFlow -lGenVector -lxAODBTagging -lxAODTrigger -lxAODMuon -lMuonIdHelpers -lxAODEgamma -lxAODPrimitives -lxAODTruth -lTruthUtils -lxAODCaloEvent -lCaloGeoHelpers -lxAODTracking -lxAODEventInfo -lxAODBase -lPhysics -lAsgTools -lxAODRootAccess -lTree -lxAODEventFormat -lxAODCore -lRIO -lAthContainers -lAthLinks -lCxxUtils -lboost_regex -lboost_system -lxAODRootAccessInterfaces -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic


all_FrameworkExe : dep_FrameworkExe package_FrameworkExe

package_FrameworkExe :  /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/bin/hsg5frameworkReadCxAOD /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/bin/hsg5framework postcompile_FrameworkExe

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/bin/% : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj/%.o | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/bin
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) -o $@ $< $(RC_BINFLAGS)

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj/%.o : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkExe/util/%.cxx | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj/hsg5frameworkReadCxAOD.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc FrameworkExe $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj/%.d : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkExe/util/%.cxx | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/bin : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

postcompile_FrameworkExe :  /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/bin/hsg5frameworkReadCxAOD /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/bin/hsg5framework
	$(SILENT)rc --internal postcompile_pkg FrameworkExe


dep_FrameworkExe : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj/hsg5frameworkReadCxAOD.d /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj/hsg5framework.d


-include  /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj/hsg5frameworkReadCxAOD.d /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkExe/obj/hsg5framework.d
