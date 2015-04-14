#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdICxAODReaderdIobjdICxAODReaderCINT

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
#include "CxAODReader/AnalysisReader.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_AnalysisReader(void *p = 0);
   static void *newArray_AnalysisReader(Long_t size, void *p);
   static void delete_AnalysisReader(void *p);
   static void deleteArray_AnalysisReader(void *p);
   static void destruct_AnalysisReader(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AnalysisReader*)
   {
      ::AnalysisReader *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::AnalysisReader >(0);
      static ::ROOT::TGenericClassInfo 
         instance("AnalysisReader", ::AnalysisReader::Class_Version(), "CxAODReader/AnalysisReader.h", 37,
                  typeid(::AnalysisReader), DefineBehavior(ptr, ptr),
                  &::AnalysisReader::Dictionary, isa_proxy, 4,
                  sizeof(::AnalysisReader) );
      instance.SetNew(&new_AnalysisReader);
      instance.SetNewArray(&newArray_AnalysisReader);
      instance.SetDelete(&delete_AnalysisReader);
      instance.SetDeleteArray(&deleteArray_AnalysisReader);
      instance.SetDestructor(&destruct_AnalysisReader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AnalysisReader*)
   {
      return GenerateInitInstanceLocal((::AnalysisReader*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::AnalysisReader*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr AnalysisReader::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *AnalysisReader::Class_Name()
{
   return "AnalysisReader";
}

//______________________________________________________________________________
const char *AnalysisReader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AnalysisReader*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AnalysisReader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AnalysisReader*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *AnalysisReader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AnalysisReader*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *AnalysisReader::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AnalysisReader*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void AnalysisReader::Streamer(TBuffer &R__b)
{
   // Stream an object of class AnalysisReader.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(AnalysisReader::Class(),this);
   } else {
      R__b.WriteClassBuffer(AnalysisReader::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_AnalysisReader(void *p) {
      return  p ? new(p) ::AnalysisReader : new ::AnalysisReader;
   }
   static void *newArray_AnalysisReader(Long_t nElements, void *p) {
      return p ? new(p) ::AnalysisReader[nElements] : new ::AnalysisReader[nElements];
   }
   // Wrapper around operator delete
   static void delete_AnalysisReader(void *p) {
      delete ((::AnalysisReader*)p);
   }
   static void deleteArray_AnalysisReader(void *p) {
      delete [] ((::AnalysisReader*)p);
   }
   static void destruct_AnalysisReader(void *p) {
      typedef ::AnalysisReader current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AnalysisReader

namespace {
  void TriggerDictionaryInitialization_CxAODReaderCINT_Impl() {
    static const char* headers[] = {
"CxAODReader/AnalysisReader.h",
0
    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/CxAODReader/Root",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/CxAODReader",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/CxAODReader/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/CxAODReader/Root/LinkDef.h")))  AnalysisReader;
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
  #define ROOTCORE_PACKAGE "CxAODReader"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "CxAODReader/AnalysisReader.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"AnalysisReader", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CxAODReaderCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CxAODReaderCINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CxAODReaderCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CxAODReaderCINT() {
  TriggerDictionaryInitialization_CxAODReaderCINT_Impl();
}
