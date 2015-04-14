#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdITupleMakerdIobjdITupleMakerCINT

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
#include "TupleMaker/TupleMaker.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TupleMaker(void *p = 0);
   static void *newArray_TupleMaker(Long_t size, void *p);
   static void delete_TupleMaker(void *p);
   static void deleteArray_TupleMaker(void *p);
   static void destruct_TupleMaker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TupleMaker*)
   {
      ::TupleMaker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TupleMaker >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TupleMaker", ::TupleMaker::Class_Version(), "TupleMaker/TupleMaker.h", 22,
                  typeid(::TupleMaker), DefineBehavior(ptr, ptr),
                  &::TupleMaker::Dictionary, isa_proxy, 4,
                  sizeof(::TupleMaker) );
      instance.SetNew(&new_TupleMaker);
      instance.SetNewArray(&newArray_TupleMaker);
      instance.SetDelete(&delete_TupleMaker);
      instance.SetDeleteArray(&deleteArray_TupleMaker);
      instance.SetDestructor(&destruct_TupleMaker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TupleMaker*)
   {
      return GenerateInitInstanceLocal((::TupleMaker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TupleMaker*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TupleMaker::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TupleMaker::Class_Name()
{
   return "TupleMaker";
}

//______________________________________________________________________________
const char *TupleMaker::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TupleMaker*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TupleMaker::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TupleMaker*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TupleMaker::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TupleMaker*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TupleMaker::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TupleMaker*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TupleMaker::Streamer(TBuffer &R__b)
{
   // Stream an object of class TupleMaker.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TupleMaker::Class(),this);
   } else {
      R__b.WriteClassBuffer(TupleMaker::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TupleMaker(void *p) {
      return  p ? new(p) ::TupleMaker : new ::TupleMaker;
   }
   static void *newArray_TupleMaker(Long_t nElements, void *p) {
      return p ? new(p) ::TupleMaker[nElements] : new ::TupleMaker[nElements];
   }
   // Wrapper around operator delete
   static void delete_TupleMaker(void *p) {
      delete ((::TupleMaker*)p);
   }
   static void deleteArray_TupleMaker(void *p) {
      delete [] ((::TupleMaker*)p);
   }
   static void destruct_TupleMaker(void *p) {
      typedef ::TupleMaker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TupleMaker

namespace ROOT {
   static TClass *vectorlEstringgR_Dictionary();
   static void vectorlEstringgR_TClassManip(TClass*);
   static void *new_vectorlEstringgR(void *p = 0);
   static void *newArray_vectorlEstringgR(Long_t size, void *p);
   static void delete_vectorlEstringgR(void *p);
   static void deleteArray_vectorlEstringgR(void *p);
   static void destruct_vectorlEstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<string>*)
   {
      vector<string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<string>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<string>", -2, "vector", 210,
                  typeid(vector<string>), DefineBehavior(ptr, ptr),
                  &vectorlEstringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<string>) );
      instance.SetNew(&new_vectorlEstringgR);
      instance.SetNewArray(&newArray_vectorlEstringgR);
      instance.SetDelete(&delete_vectorlEstringgR);
      instance.SetDeleteArray(&deleteArray_vectorlEstringgR);
      instance.SetDestructor(&destruct_vectorlEstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<string>*)0x0)->GetClass();
      vectorlEstringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEstringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<string> : new vector<string>;
   }
   static void *newArray_vectorlEstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<string>[nElements] : new vector<string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEstringgR(void *p) {
      delete ((vector<string>*)p);
   }
   static void deleteArray_vectorlEstringgR(void *p) {
      delete [] ((vector<string>*)p);
   }
   static void destruct_vectorlEstringgR(void *p) {
      typedef vector<string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<string>

namespace {
  void TriggerDictionaryInitialization_TupleMakerCINT_Impl() {
    static const char* headers[] = {
"TupleMaker/TupleMaker.h",
0
    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/TupleMaker/Root",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/TupleMaker",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/TupleMaker/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/TupleMaker/Root/LinkDef.h")))  TupleMaker;
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
  #define ROOTCORE_PACKAGE "TupleMaker"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "TupleMaker/TupleMaker.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"TupleMaker", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TupleMakerCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TupleMakerCINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TupleMakerCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TupleMakerCINT() {
  TriggerDictionaryInitialization_TupleMakerCINT_Impl();
}
