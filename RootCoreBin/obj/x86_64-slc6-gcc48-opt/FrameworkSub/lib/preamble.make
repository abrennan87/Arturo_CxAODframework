RC_CXX       = g++
RC_LD        = g++
RC_CXXFLAGS  = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkSub/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkSub -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DROOTCORE_PACKAGE=\"FrameworkSub\" 
RC_DICTFLAGS = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkSub/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkSub -O2 -Wall -fPIC -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -g -DROOTCORE -pthread -std=c++11 -Wno-deprecated-declarations -m64 -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -pipe -W -Wall -Wno-deprecated -pedantic -Wwrite-strings -Wpointer-arith -Woverloaded-virtual -Wno-long-long -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DROOTCORE_PACKAGE=\"FrameworkSub\" 
RC_INCFLAGS  = -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkSub/Root -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/FrameworkSub -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -I/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include -DROOTCORE -I/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include -DROOTCORE_RELEASE_SERIES=21 -DROOTCORE_TEST_FILE=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1\" -DROOTCORE_TEST_DATA=\"/afs/cern.ch/atlas/project/PAT/xAODs/r5591\" -DROOTCORE_PACKAGE=\"FrameworkSub\"
RC_LIBFLAGS  = -shared -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic 
RC_BINFLAGS  = -L/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/obj/x86_64-slc6-gcc48-opt/FrameworkSub/lib -L/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/lib/x86_64-slc6-gcc48-opt -m64 -L/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/lib -lCore -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -pthread -lm -ldl -rdynamic


all_FrameworkSub : dep_FrameworkSub package_FrameworkSub

package_FrameworkSub :  postcompile_FrameworkSub

postcompile_FrameworkSub : 
	$(SILENT)rc --internal postcompile_pkg FrameworkSub


dep_FrameworkSub :
