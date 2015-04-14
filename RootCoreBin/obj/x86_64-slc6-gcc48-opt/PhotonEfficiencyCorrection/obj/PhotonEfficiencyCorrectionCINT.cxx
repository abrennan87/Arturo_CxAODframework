#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIPhotonEfficiencyCorrectiondIobjdIPhotonEfficiencyCorrectionCINT

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "PhotonEfficiencyCorrection/TPhotonEfficiencyCorrectionTool.h"

// Header files passed via #pragma extra_include

namespace Root {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *Root_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("Root", 0 /*version*/, "PATCore/TResult.h", 22,
                     ::ROOT::DefineBehavior((void*)0,(void*)0),
                     &Root_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *Root_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *RootcLcLTPhotonEfficiencyCorrectionTool_Dictionary();
   static void RootcLcLTPhotonEfficiencyCorrectionTool_TClassManip(TClass*);
   static void *new_RootcLcLTPhotonEfficiencyCorrectionTool(void *p = 0);
   static void *newArray_RootcLcLTPhotonEfficiencyCorrectionTool(Long_t size, void *p);
   static void delete_RootcLcLTPhotonEfficiencyCorrectionTool(void *p);
   static void deleteArray_RootcLcLTPhotonEfficiencyCorrectionTool(void *p);
   static void destruct_RootcLcLTPhotonEfficiencyCorrectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Root::TPhotonEfficiencyCorrectionTool*)
   {
      ::Root::TPhotonEfficiencyCorrectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Root::TPhotonEfficiencyCorrectionTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("Root::TPhotonEfficiencyCorrectionTool", "PhotonEfficiencyCorrection/TPhotonEfficiencyCorrectionTool.h", 39,
                  typeid(::Root::TPhotonEfficiencyCorrectionTool), DefineBehavior(ptr, ptr),
                  &RootcLcLTPhotonEfficiencyCorrectionTool_Dictionary, isa_proxy, 4,
                  sizeof(::Root::TPhotonEfficiencyCorrectionTool) );
      instance.SetNew(&new_RootcLcLTPhotonEfficiencyCorrectionTool);
      instance.SetNewArray(&newArray_RootcLcLTPhotonEfficiencyCorrectionTool);
      instance.SetDelete(&delete_RootcLcLTPhotonEfficiencyCorrectionTool);
      instance.SetDeleteArray(&deleteArray_RootcLcLTPhotonEfficiencyCorrectionTool);
      instance.SetDestructor(&destruct_RootcLcLTPhotonEfficiencyCorrectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Root::TPhotonEfficiencyCorrectionTool*)
   {
      return GenerateInitInstanceLocal((::Root::TPhotonEfficiencyCorrectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Root::TPhotonEfficiencyCorrectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RootcLcLTPhotonEfficiencyCorrectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Root::TPhotonEfficiencyCorrectionTool*)0x0)->GetClass();
      RootcLcLTPhotonEfficiencyCorrectionTool_TClassManip(theClass);
   return theClass;
   }

   static void RootcLcLTPhotonEfficiencyCorrectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_RootcLcLTPhotonEfficiencyCorrectionTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Root::TPhotonEfficiencyCorrectionTool : new ::Root::TPhotonEfficiencyCorrectionTool;
   }
   static void *newArray_RootcLcLTPhotonEfficiencyCorrectionTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Root::TPhotonEfficiencyCorrectionTool[nElements] : new ::Root::TPhotonEfficiencyCorrectionTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_RootcLcLTPhotonEfficiencyCorrectionTool(void *p) {
      delete ((::Root::TPhotonEfficiencyCorrectionTool*)p);
   }
   static void deleteArray_RootcLcLTPhotonEfficiencyCorrectionTool(void *p) {
      delete [] ((::Root::TPhotonEfficiencyCorrectionTool*)p);
   }
   static void destruct_RootcLcLTPhotonEfficiencyCorrectionTool(void *p) {
      typedef ::Root::TPhotonEfficiencyCorrectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Root::TPhotonEfficiencyCorrectionTool

namespace {
  void TriggerDictionaryInitialization_PhotonEfficiencyCorrectionCINT_Impl() {
    static const char* headers[] = {
"PhotonEfficiencyCorrection/TPhotonEfficiencyCorrectionTool.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/PhotonEfficiencyCorrection/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/PhotonEfficiencyCorrection",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/usr/include/libxml2",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/PhotonEfficiencyCorrection/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace Root{class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/PhotonEfficiencyCorrection/Root/LinkDef.h")))  TPhotonEfficiencyCorrectionTool;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef ROOTCORE
  #define ROOTCORE 1
#endif
#ifndef ROOTCORE_RELEASE_SERIES
  #define ROOTCORE_RELEASE_SERIES 21
#endif
#ifndef ROOTCORE_TEST_FILE
  #define ROOTCORE_TEST_FILE "/afs/cern.ch/atlas/project/PAT/xAODs/r5591/mc14_8TeV.117050.PowhegPythia_P2011C_ttbar.recon.AOD.e1727_s1933_s1911_r5591/AOD.01494882._111853.pool.root.1"
#endif
#ifndef ROOTCORE_TEST_DATA
  #define ROOTCORE_TEST_DATA "/afs/cern.ch/atlas/project/PAT/xAODs/r5591"
#endif
#ifndef XAOD_STANDALONE
  #define XAOD_STANDALONE 1
#endif
#ifndef XAOD_ANALYSIS
  #define XAOD_ANALYSIS 1
#endif
#ifndef ASGTOOL_STANDALONE
  #define ASGTOOL_STANDALONE 1
#endif
#ifndef ROOTCORE_PACKAGE
  #define ROOTCORE_PACKAGE "PhotonEfficiencyCorrection"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "PhotonEfficiencyCorrection/TPhotonEfficiencyCorrectionTool.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Root::TPhotonEfficiencyCorrectionTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("PhotonEfficiencyCorrectionCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_PhotonEfficiencyCorrectionCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_PhotonEfficiencyCorrectionCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_PhotonEfficiencyCorrectionCINT() {
  TriggerDictionaryInitialization_PhotonEfficiencyCorrectionCINT_Impl();
}
