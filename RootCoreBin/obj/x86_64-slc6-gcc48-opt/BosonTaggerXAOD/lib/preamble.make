RC_CXX       = g++
RC_LD        = g++
RC_CXXFLAGS  = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"BosonTaggerXAOD\" 
RC_DICTFLAGS = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"BosonTaggerXAOD\" 
RC_INCFLAGS  = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -DROOTCORE -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DXAOD_STANDALONE -DXAOD_ANALYSIS -DASGTOOL_STANDALONE -DROOTCORE_PACKAGE=\"BosonTaggerXAOD\"
RC_LIBFLAGS  = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic 
RC_BINFLAGS  = -L/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/lib -L/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/lib/x86_64-slc6-gcc48-opt -lBosonTaggerXAOD -lAsgTools -lxAODEventInfo -lxAODJet -lGenVector -lxAODPFlow -lGenVector -lxAODCaloEvent -lCaloGeoHelpers -lxAODBTagging -lxAODTracking -lxAODTrigger -lxAODBase -lPhysics -lEventLoop -lProofPlayer -lProof -lHist -lTree -lxAODRootAccess -lTree -lxAODEventFormat -lxAODCore -lRIO -lAthContainers -lAthLinks -lxAODRootAccessInterfaces -lCxxUtils -lboost_regex -lboost_system -lSampleHandler -lPyROOT -lProof -lTree -lRootCoreUtils -lTree -lHist -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic


all_BosonTaggerXAOD : dep_BosonTaggerXAOD package_BosonTaggerXAOD

package_BosonTaggerXAOD :  /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/lib/libBosonTaggerXAOD.so /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/bin/test_taggerExample postcompile_BosonTaggerXAOD

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/lib/libBosonTaggerXAOD.so :  /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/WTagger.o /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.o | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/lib
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/WTagger.o /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.o $(RC_LIBFLAGS) -L/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/lib/x86_64-slc6-gcc48-opt -o $@

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/%.o : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root/%.cxx | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/WTagger.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc BosonTaggerXAOD $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/%.d : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root/%.cxx | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.o : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root/LinkDef.h /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.headers | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc BosonTaggerXAOD $@
	$(SILENT)rc --internal rootcint $(ROOTSYS)/bin/rootcint $(RC_INCFLAGS) /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root/LinkDef.h /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.cxx /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.headers /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/lib BosonTaggerXAOD
	$(SILENT)$(RC_CXX) $(RC_DICTFLAGS) $(INCLUDES) -c /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.cxx -o $@

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.headers : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root/LinkDef.h | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -D__CINT__ -D__MAKECINT__ -D__CLING__ -Wno-unknown-pragmas -- $@ $< 

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.d : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root/LinkDef.h | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/lib : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/bin/% : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/%.o | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/lib/libBosonTaggerXAOD.so /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/bin
	$(SILENT)echo Linking `basename $@`
	$(SILENT)$(RC_LD) -o $@ $< $(RC_BINFLAGS)

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/%.o : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/util/%.cxx | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/test_taggerExample.d
	$(SILENT)echo Compiling `basename $@`
	$(SILENT)rc --internal check_dep_cc BosonTaggerXAOD $@
	$(SILENT)$(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES) -c $< -o $@

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/%.d : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/util/%.cxx | /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj
	$(SILENT)echo Making dependency for `basename $<`
	$(SILENT)rc --internal make_dep $(RC_CXX) $(RC_CXXFLAGS) $(INCLUDES)  -- $@ $< 

/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/bin : 
	$(SILENT)echo Making directory $@
	$(SILENT)mkdir -p $@

postcompile_BosonTaggerXAOD :  /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/lib/libBosonTaggerXAOD.so /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/bin/test_taggerExample
	$(SILENT)rc --internal postcompile_pkg BosonTaggerXAOD


dep_BosonTaggerXAOD : /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/WTagger.d /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.headers /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.d /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/test_taggerExample.d


-include  /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/WTagger.d /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.headers /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/BosonTaggerXAODCINT.d /afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/BosonTaggerXAOD/obj/test_taggerExample.d
