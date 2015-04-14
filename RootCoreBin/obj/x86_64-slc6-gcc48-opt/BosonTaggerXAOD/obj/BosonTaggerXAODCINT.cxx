#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIBosonTaggerXAODdIobjdIBosonTaggerXAODCINT

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
#include "BosonTaggerXAOD/WTagger.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_WTagger(void *p = 0);
   static void *newArray_WTagger(Long_t size, void *p);
   static void delete_WTagger(void *p);
   static void deleteArray_WTagger(void *p);
   static void destruct_WTagger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WTagger*)
   {
      ::WTagger *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WTagger >(0);
      static ::ROOT::TGenericClassInfo 
         instance("WTagger", ::WTagger::Class_Version(), "BosonTaggerXAOD/WTagger.h", 20,
                  typeid(::WTagger), DefineBehavior(ptr, ptr),
                  &::WTagger::Dictionary, isa_proxy, 4,
                  sizeof(::WTagger) );
      instance.SetNew(&new_WTagger);
      instance.SetNewArray(&newArray_WTagger);
      instance.SetDelete(&delete_WTagger);
      instance.SetDeleteArray(&deleteArray_WTagger);
      instance.SetDestructor(&destruct_WTagger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WTagger*)
   {
      return GenerateInitInstanceLocal((::WTagger*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::WTagger*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr WTagger::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *WTagger::Class_Name()
{
   return "WTagger";
}

//______________________________________________________________________________
const char *WTagger::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WTagger*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int WTagger::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WTagger*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WTagger::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WTagger*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WTagger::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WTagger*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void WTagger::Streamer(TBuffer &R__b)
{
   // Stream an object of class WTagger.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WTagger::Class(),this);
   } else {
      R__b.WriteClassBuffer(WTagger::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WTagger(void *p) {
      return  p ? new(p) ::WTagger : new ::WTagger;
   }
   static void *newArray_WTagger(Long_t nElements, void *p) {
      return p ? new(p) ::WTagger[nElements] : new ::WTagger[nElements];
   }
   // Wrapper around operator delete
   static void delete_WTagger(void *p) {
      delete ((::WTagger*)p);
   }
   static void deleteArray_WTagger(void *p) {
      delete [] ((::WTagger*)p);
   }
   static void destruct_WTagger(void *p) {
      typedef ::WTagger current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::WTagger

namespace {
  void TriggerDictionaryInitialization_BosonTaggerXAODCINT_Impl() {
    static const char* headers[] = {
"BosonTaggerXAOD/WTagger.h",
0
    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/BosonTaggerXAOD/Root/LinkDef.h")))  WTagger;
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
  #define ROOTCORE_PACKAGE "BosonTaggerXAOD"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "BosonTaggerXAOD/WTagger.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"WTagger", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("BosonTaggerXAODCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_BosonTaggerXAODCINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_BosonTaggerXAODCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_BosonTaggerXAODCINT() {
  TriggerDictionaryInitialization_BosonTaggerXAODCINT_Impl();
}
