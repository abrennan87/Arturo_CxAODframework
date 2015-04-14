// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIJetCalibToolsdIobjdIJetCalibTools_Reflex

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
#include "/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/JetCalibTools/JetCalibTools/JetCalibToolsDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *JetCalibrationTool_Dictionary();
   static void JetCalibrationTool_TClassManip(TClass*);
   static void *new_JetCalibrationTool(void *p = 0);
   static void *newArray_JetCalibrationTool(Long_t size, void *p);
   static void delete_JetCalibrationTool(void *p);
   static void deleteArray_JetCalibrationTool(void *p);
   static void destruct_JetCalibrationTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JetCalibrationTool*)
   {
      ::JetCalibrationTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::JetCalibrationTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("JetCalibrationTool", "JetCalibTools/JetCalibrationTool.h", 35,
                  typeid(::JetCalibrationTool), DefineBehavior(ptr, ptr),
                  &JetCalibrationTool_Dictionary, isa_proxy, 0,
                  sizeof(::JetCalibrationTool) );
      instance.SetNew(&new_JetCalibrationTool);
      instance.SetNewArray(&newArray_JetCalibrationTool);
      instance.SetDelete(&delete_JetCalibrationTool);
      instance.SetDeleteArray(&deleteArray_JetCalibrationTool);
      instance.SetDestructor(&destruct_JetCalibrationTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JetCalibrationTool*)
   {
      return GenerateInitInstanceLocal((::JetCalibrationTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::JetCalibrationTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *JetCalibrationTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::JetCalibrationTool*)0x0)->GetClass();
      JetCalibrationTool_TClassManip(theClass);
   return theClass;
   }

   static void JetCalibrationTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_JetCalibrationTool(void *p) {
      return  p ? new(p) ::JetCalibrationTool : new ::JetCalibrationTool;
   }
   static void *newArray_JetCalibrationTool(Long_t nElements, void *p) {
      return p ? new(p) ::JetCalibrationTool[nElements] : new ::JetCalibrationTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_JetCalibrationTool(void *p) {
      delete ((::JetCalibrationTool*)p);
   }
   static void deleteArray_JetCalibrationTool(void *p) {
      delete [] ((::JetCalibrationTool*)p);
   }
   static void destruct_JetCalibrationTool(void *p) {
      typedef ::JetCalibrationTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JetCalibrationTool

namespace {
  void TriggerDictionaryInitialization_JetCalibTools_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/JetCalibTools/Root",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/JetCalibTools",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/JetCalibTools/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$JetCalibTools/JetCalibrationTool.h")))  JetCalibrationTool;
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
  #define ROOTCORE_PACKAGE "JetCalibTools"
#endif
#ifndef XAOD_STANDALONE
  #define XAOD_STANDALONE 1
#endif
#ifndef ASGTOOL_STANDALONE
  #define ASGTOOL_STANDALONE 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef JETCALIBTOOLS_JETCALIBTOOLSDICT_H
#define JETCALIBTOOLS_JETCALIBTOOLSDICT_H 1

// Reflex dictionary generation
// Following instructions on the CP tools twiki:
// https://twiki.cern.ch/twiki/bin/viewauth/AtlasComputing/DevelopingCPToolsForxAOD
// Special handling for Eigen vectorization

#if defined(__GCCXML__) and not defined(EIGEN_DONT_VECTORIZE)
#define EIGEN_DONT_VECTORIZE
#endif

#include "JetCalibTools/JetCalibrationTool.h"

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"JetCalibrationTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("JetCalibTools_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_JetCalibTools_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_JetCalibTools_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_JetCalibTools_Reflex() {
  TriggerDictionaryInitialization_JetCalibTools_Reflex_Impl();
}
