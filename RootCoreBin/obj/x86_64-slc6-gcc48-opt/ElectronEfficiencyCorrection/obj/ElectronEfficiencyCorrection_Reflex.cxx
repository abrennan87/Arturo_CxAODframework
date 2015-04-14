// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIElectronEfficiencyCorrectiondIobjdIElectronEfficiencyCorrection_Reflex

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
#include "/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/ElectronEfficiencyCorrection/ElectronEfficiencyCorrection/ElectronEfficiencyCorrectionDict.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *AsgElectronEfficiencyCorrectionTool_Dictionary();
   static void AsgElectronEfficiencyCorrectionTool_TClassManip(TClass*);
   static void delete_AsgElectronEfficiencyCorrectionTool(void *p);
   static void deleteArray_AsgElectronEfficiencyCorrectionTool(void *p);
   static void destruct_AsgElectronEfficiencyCorrectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AsgElectronEfficiencyCorrectionTool*)
   {
      ::AsgElectronEfficiencyCorrectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::AsgElectronEfficiencyCorrectionTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("AsgElectronEfficiencyCorrectionTool", "ElectronEfficiencyCorrection/AsgElectronEfficiencyCorrectionTool.h", 34,
                  typeid(::AsgElectronEfficiencyCorrectionTool), DefineBehavior(ptr, ptr),
                  &AsgElectronEfficiencyCorrectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::AsgElectronEfficiencyCorrectionTool) );
      instance.SetDelete(&delete_AsgElectronEfficiencyCorrectionTool);
      instance.SetDeleteArray(&deleteArray_AsgElectronEfficiencyCorrectionTool);
      instance.SetDestructor(&destruct_AsgElectronEfficiencyCorrectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AsgElectronEfficiencyCorrectionTool*)
   {
      return GenerateInitInstanceLocal((::AsgElectronEfficiencyCorrectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::AsgElectronEfficiencyCorrectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *AsgElectronEfficiencyCorrectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::AsgElectronEfficiencyCorrectionTool*)0x0)->GetClass();
      AsgElectronEfficiencyCorrectionTool_TClassManip(theClass);
   return theClass;
   }

   static void AsgElectronEfficiencyCorrectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RootcLcLTElectronEfficiencyCorrectionTool_Dictionary();
   static void RootcLcLTElectronEfficiencyCorrectionTool_TClassManip(TClass*);
   static void *new_RootcLcLTElectronEfficiencyCorrectionTool(void *p = 0);
   static void *newArray_RootcLcLTElectronEfficiencyCorrectionTool(Long_t size, void *p);
   static void delete_RootcLcLTElectronEfficiencyCorrectionTool(void *p);
   static void deleteArray_RootcLcLTElectronEfficiencyCorrectionTool(void *p);
   static void destruct_RootcLcLTElectronEfficiencyCorrectionTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Root::TElectronEfficiencyCorrectionTool*)
   {
      ::Root::TElectronEfficiencyCorrectionTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Root::TElectronEfficiencyCorrectionTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("Root::TElectronEfficiencyCorrectionTool", "ElectronEfficiencyCorrection/TElectronEfficiencyCorrectionTool.h", 47,
                  typeid(::Root::TElectronEfficiencyCorrectionTool), DefineBehavior(ptr, ptr),
                  &RootcLcLTElectronEfficiencyCorrectionTool_Dictionary, isa_proxy, 0,
                  sizeof(::Root::TElectronEfficiencyCorrectionTool) );
      instance.SetNew(&new_RootcLcLTElectronEfficiencyCorrectionTool);
      instance.SetNewArray(&newArray_RootcLcLTElectronEfficiencyCorrectionTool);
      instance.SetDelete(&delete_RootcLcLTElectronEfficiencyCorrectionTool);
      instance.SetDeleteArray(&deleteArray_RootcLcLTElectronEfficiencyCorrectionTool);
      instance.SetDestructor(&destruct_RootcLcLTElectronEfficiencyCorrectionTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Root::TElectronEfficiencyCorrectionTool*)
   {
      return GenerateInitInstanceLocal((::Root::TElectronEfficiencyCorrectionTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Root::TElectronEfficiencyCorrectionTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RootcLcLTElectronEfficiencyCorrectionTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Root::TElectronEfficiencyCorrectionTool*)0x0)->GetClass();
      RootcLcLTElectronEfficiencyCorrectionTool_TClassManip(theClass);
   return theClass;
   }

   static void RootcLcLTElectronEfficiencyCorrectionTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrapper around operator delete
   static void delete_AsgElectronEfficiencyCorrectionTool(void *p) {
      delete ((::AsgElectronEfficiencyCorrectionTool*)p);
   }
   static void deleteArray_AsgElectronEfficiencyCorrectionTool(void *p) {
      delete [] ((::AsgElectronEfficiencyCorrectionTool*)p);
   }
   static void destruct_AsgElectronEfficiencyCorrectionTool(void *p) {
      typedef ::AsgElectronEfficiencyCorrectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AsgElectronEfficiencyCorrectionTool

namespace ROOT {
   // Wrappers around operator new
   static void *new_RootcLcLTElectronEfficiencyCorrectionTool(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Root::TElectronEfficiencyCorrectionTool : new ::Root::TElectronEfficiencyCorrectionTool;
   }
   static void *newArray_RootcLcLTElectronEfficiencyCorrectionTool(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::Root::TElectronEfficiencyCorrectionTool[nElements] : new ::Root::TElectronEfficiencyCorrectionTool[nElements];
   }
   // Wrapper around operator delete
   static void delete_RootcLcLTElectronEfficiencyCorrectionTool(void *p) {
      delete ((::Root::TElectronEfficiencyCorrectionTool*)p);
   }
   static void deleteArray_RootcLcLTElectronEfficiencyCorrectionTool(void *p) {
      delete [] ((::Root::TElectronEfficiencyCorrectionTool*)p);
   }
   static void destruct_RootcLcLTElectronEfficiencyCorrectionTool(void *p) {
      typedef ::Root::TElectronEfficiencyCorrectionTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Root::TElectronEfficiencyCorrectionTool

namespace {
  void TriggerDictionaryInitialization_ElectronEfficiencyCorrection_Reflex_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/ElectronEfficiencyCorrection/Root",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/ElectronEfficiencyCorrection",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/usr/include/libxml2",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/ElectronEfficiencyCorrection/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$ElectronEfficiencyCorrection/AsgElectronEfficiencyCorrectionTool.h")))  AsgElectronEfficiencyCorrectionTool;
namespace Root{class __attribute__((annotate("$clingAutoload$ElectronEfficiencyCorrection/AsgElectronEfficiencyCorrectionTool.h")))  TElectronEfficiencyCorrectionTool;}
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
  #define ROOTCORE_PACKAGE "ElectronEfficiencyCorrection"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Dear emacs, this is -*-c++-*-

#ifndef __ELECTRONEFFICIENCYCORRECTIONDICT__
#define __ELECTRONEFFICIENCYCORRECTIONDICT__


#include "ElectronEfficiencyCorrection/AsgElectronEfficiencyCorrectionTool.h"
#include "ElectronEfficiencyCorrection/TElectronEfficiencyCorrectionTool.h"

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"AsgElectronEfficiencyCorrectionTool", payloadCode, "@",
"Root::TElectronEfficiencyCorrectionTool", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ElectronEfficiencyCorrection_Reflex",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ElectronEfficiencyCorrection_Reflex_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ElectronEfficiencyCorrection_Reflex_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ElectronEfficiencyCorrection_Reflex() {
  TriggerDictionaryInitialization_ElectronEfficiencyCorrection_Reflex_Impl();
}
