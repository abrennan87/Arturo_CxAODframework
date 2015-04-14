#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIxAODHelpersdIobjdIxAODHelpersCINT

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
#include "xAODHelpers/WTaggedHistsAlgo.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_WTaggedHistsAlgo(void *p = 0);
   static void *newArray_WTaggedHistsAlgo(Long_t size, void *p);
   static void delete_WTaggedHistsAlgo(void *p);
   static void deleteArray_WTaggedHistsAlgo(void *p);
   static void destruct_WTaggedHistsAlgo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::WTaggedHistsAlgo*)
   {
      ::WTaggedHistsAlgo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::WTaggedHistsAlgo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("WTaggedHistsAlgo", ::WTaggedHistsAlgo::Class_Version(), "xAODHelpers/WTaggedHistsAlgo.h", 18,
                  typeid(::WTaggedHistsAlgo), DefineBehavior(ptr, ptr),
                  &::WTaggedHistsAlgo::Dictionary, isa_proxy, 4,
                  sizeof(::WTaggedHistsAlgo) );
      instance.SetNew(&new_WTaggedHistsAlgo);
      instance.SetNewArray(&newArray_WTaggedHistsAlgo);
      instance.SetDelete(&delete_WTaggedHistsAlgo);
      instance.SetDeleteArray(&deleteArray_WTaggedHistsAlgo);
      instance.SetDestructor(&destruct_WTaggedHistsAlgo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::WTaggedHistsAlgo*)
   {
      return GenerateInitInstanceLocal((::WTaggedHistsAlgo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::WTaggedHistsAlgo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr WTaggedHistsAlgo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *WTaggedHistsAlgo::Class_Name()
{
   return "WTaggedHistsAlgo";
}

//______________________________________________________________________________
const char *WTaggedHistsAlgo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WTaggedHistsAlgo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int WTaggedHistsAlgo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::WTaggedHistsAlgo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *WTaggedHistsAlgo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WTaggedHistsAlgo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *WTaggedHistsAlgo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::WTaggedHistsAlgo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void WTaggedHistsAlgo::Streamer(TBuffer &R__b)
{
   // Stream an object of class WTaggedHistsAlgo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(WTaggedHistsAlgo::Class(),this);
   } else {
      R__b.WriteClassBuffer(WTaggedHistsAlgo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_WTaggedHistsAlgo(void *p) {
      return  p ? new(p) ::WTaggedHistsAlgo : new ::WTaggedHistsAlgo;
   }
   static void *newArray_WTaggedHistsAlgo(Long_t nElements, void *p) {
      return p ? new(p) ::WTaggedHistsAlgo[nElements] : new ::WTaggedHistsAlgo[nElements];
   }
   // Wrapper around operator delete
   static void delete_WTaggedHistsAlgo(void *p) {
      delete ((::WTaggedHistsAlgo*)p);
   }
   static void deleteArray_WTaggedHistsAlgo(void *p) {
      delete [] ((::WTaggedHistsAlgo*)p);
   }
   static void destruct_WTaggedHistsAlgo(void *p) {
      typedef ::WTaggedHistsAlgo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::WTaggedHistsAlgo

namespace {
  void TriggerDictionaryInitialization_xAODHelpersCINT_Impl() {
    static const char* headers[] = {
"xAODHelpers/WTaggedHistsAlgo.h",
0
    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODHelpers/Root",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODHelpers",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODHelpers/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODHelpers/Root/LinkDef.h")))  WTaggedHistsAlgo;
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
  #define ROOTCORE_PACKAGE "xAODHelpers"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "xAODHelpers/WTaggedHistsAlgo.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"WTaggedHistsAlgo", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("xAODHelpersCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_xAODHelpersCINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T, typename BASE> class DataVector;", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_xAODHelpersCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_xAODHelpersCINT() {
  TriggerDictionaryInitialization_xAODHelpersCINT_Impl();
}
