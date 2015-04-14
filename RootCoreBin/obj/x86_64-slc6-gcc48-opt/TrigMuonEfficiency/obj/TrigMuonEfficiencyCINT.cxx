#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdITrigMuonEfficiencydIobjdITrigMuonEfficiencyCINT

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
#include "TrigMuonEfficiency/MuonHypothesis.h"
#include "TrigMuonEfficiency/LeptonTriggerSF.h"
#include "TrigMuonEfficiency/HSG3TrigLeptonSFTool.h"
#include "TrigMuonEfficiency/MuonTriggerMatching.h"
#include "TrigMuonEfficiency/TriggerNavigationVariables.h"
#include "TrigMuonEfficiency/ElectronTriggerMatching.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *MuonHypothesis_Dictionary();
   static void MuonHypothesis_TClassManip(TClass*);
   static void *new_MuonHypothesis(void *p = 0);
   static void *newArray_MuonHypothesis(Long_t size, void *p);
   static void delete_MuonHypothesis(void *p);
   static void deleteArray_MuonHypothesis(void *p);
   static void destruct_MuonHypothesis(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MuonHypothesis*)
   {
      ::MuonHypothesis *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MuonHypothesis),0);
      static ::ROOT::TGenericClassInfo 
         instance("MuonHypothesis", "TrigMuonEfficiency/MuonHypothesis.h", 15,
                  typeid(::MuonHypothesis), DefineBehavior(ptr, ptr),
                  &MuonHypothesis_Dictionary, isa_proxy, 4,
                  sizeof(::MuonHypothesis) );
      instance.SetNew(&new_MuonHypothesis);
      instance.SetNewArray(&newArray_MuonHypothesis);
      instance.SetDelete(&delete_MuonHypothesis);
      instance.SetDeleteArray(&deleteArray_MuonHypothesis);
      instance.SetDestructor(&destruct_MuonHypothesis);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MuonHypothesis*)
   {
      return GenerateInitInstanceLocal((::MuonHypothesis*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MuonHypothesis*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MuonHypothesis_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MuonHypothesis*)0x0)->GetClass();
      MuonHypothesis_TClassManip(theClass);
   return theClass;
   }

   static void MuonHypothesis_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *LeptonTriggerSF_Dictionary();
   static void LeptonTriggerSF_TClassManip(TClass*);
   static void *new_LeptonTriggerSF(void *p = 0);
   static void *newArray_LeptonTriggerSF(Long_t size, void *p);
   static void delete_LeptonTriggerSF(void *p);
   static void deleteArray_LeptonTriggerSF(void *p);
   static void destruct_LeptonTriggerSF(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::LeptonTriggerSF*)
   {
      ::LeptonTriggerSF *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::LeptonTriggerSF),0);
      static ::ROOT::TGenericClassInfo 
         instance("LeptonTriggerSF", "TrigMuonEfficiency/LeptonTriggerSF.h", 174,
                  typeid(::LeptonTriggerSF), DefineBehavior(ptr, ptr),
                  &LeptonTriggerSF_Dictionary, isa_proxy, 4,
                  sizeof(::LeptonTriggerSF) );
      instance.SetNew(&new_LeptonTriggerSF);
      instance.SetNewArray(&newArray_LeptonTriggerSF);
      instance.SetDelete(&delete_LeptonTriggerSF);
      instance.SetDeleteArray(&deleteArray_LeptonTriggerSF);
      instance.SetDestructor(&destruct_LeptonTriggerSF);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::LeptonTriggerSF*)
   {
      return GenerateInitInstanceLocal((::LeptonTriggerSF*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::LeptonTriggerSF*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *LeptonTriggerSF_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::LeptonTriggerSF*)0x0)->GetClass();
      LeptonTriggerSF_TClassManip(theClass);
   return theClass;
   }

   static void LeptonTriggerSF_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HSG3TrigLeptonSFTool_Dictionary();
   static void HSG3TrigLeptonSFTool_TClassManip(TClass*);
   static void delete_HSG3TrigLeptonSFTool(void *p);
   static void deleteArray_HSG3TrigLeptonSFTool(void *p);
   static void destruct_HSG3TrigLeptonSFTool(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HSG3TrigLeptonSFTool*)
   {
      ::HSG3TrigLeptonSFTool *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HSG3TrigLeptonSFTool),0);
      static ::ROOT::TGenericClassInfo 
         instance("HSG3TrigLeptonSFTool", "TrigMuonEfficiency/HSG3TrigLeptonSFTool.h", 25,
                  typeid(::HSG3TrigLeptonSFTool), DefineBehavior(ptr, ptr),
                  &HSG3TrigLeptonSFTool_Dictionary, isa_proxy, 4,
                  sizeof(::HSG3TrigLeptonSFTool) );
      instance.SetDelete(&delete_HSG3TrigLeptonSFTool);
      instance.SetDeleteArray(&deleteArray_HSG3TrigLeptonSFTool);
      instance.SetDestructor(&destruct_HSG3TrigLeptonSFTool);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HSG3TrigLeptonSFTool*)
   {
      return GenerateInitInstanceLocal((::HSG3TrigLeptonSFTool*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::HSG3TrigLeptonSFTool*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HSG3TrigLeptonSFTool_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HSG3TrigLeptonSFTool*)0x0)->GetClass();
      HSG3TrigLeptonSFTool_TClassManip(theClass);
   return theClass;
   }

   static void HSG3TrigLeptonSFTool_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MuonTriggerMatching_Dictionary();
   static void MuonTriggerMatching_TClassManip(TClass*);
   static void delete_MuonTriggerMatching(void *p);
   static void deleteArray_MuonTriggerMatching(void *p);
   static void destruct_MuonTriggerMatching(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MuonTriggerMatching*)
   {
      ::MuonTriggerMatching *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MuonTriggerMatching),0);
      static ::ROOT::TGenericClassInfo 
         instance("MuonTriggerMatching", "TrigMuonEfficiency/MuonTriggerMatching.h", 22,
                  typeid(::MuonTriggerMatching), DefineBehavior(ptr, ptr),
                  &MuonTriggerMatching_Dictionary, isa_proxy, 4,
                  sizeof(::MuonTriggerMatching) );
      instance.SetDelete(&delete_MuonTriggerMatching);
      instance.SetDeleteArray(&deleteArray_MuonTriggerMatching);
      instance.SetDestructor(&destruct_MuonTriggerMatching);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MuonTriggerMatching*)
   {
      return GenerateInitInstanceLocal((::MuonTriggerMatching*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MuonTriggerMatching*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MuonTriggerMatching_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MuonTriggerMatching*)0x0)->GetClass();
      MuonTriggerMatching_TClassManip(theClass);
   return theClass;
   }

   static void MuonTriggerMatching_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ElectronTriggerMatching_Dictionary();
   static void ElectronTriggerMatching_TClassManip(TClass*);
   static void delete_ElectronTriggerMatching(void *p);
   static void deleteArray_ElectronTriggerMatching(void *p);
   static void destruct_ElectronTriggerMatching(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElectronTriggerMatching*)
   {
      ::ElectronTriggerMatching *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ElectronTriggerMatching),0);
      static ::ROOT::TGenericClassInfo 
         instance("ElectronTriggerMatching", "TrigMuonEfficiency/ElectronTriggerMatching.h", 22,
                  typeid(::ElectronTriggerMatching), DefineBehavior(ptr, ptr),
                  &ElectronTriggerMatching_Dictionary, isa_proxy, 4,
                  sizeof(::ElectronTriggerMatching) );
      instance.SetDelete(&delete_ElectronTriggerMatching);
      instance.SetDeleteArray(&deleteArray_ElectronTriggerMatching);
      instance.SetDestructor(&destruct_ElectronTriggerMatching);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElectronTriggerMatching*)
   {
      return GenerateInitInstanceLocal((::ElectronTriggerMatching*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElectronTriggerMatching*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ElectronTriggerMatching_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ElectronTriggerMatching*)0x0)->GetClass();
      ElectronTriggerMatching_TClassManip(theClass);
   return theClass;
   }

   static void ElectronTriggerMatching_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TriggerNavigationVariables_Dictionary();
   static void TriggerNavigationVariables_TClassManip(TClass*);
   static void *new_TriggerNavigationVariables(void *p = 0);
   static void *newArray_TriggerNavigationVariables(Long_t size, void *p);
   static void delete_TriggerNavigationVariables(void *p);
   static void deleteArray_TriggerNavigationVariables(void *p);
   static void destruct_TriggerNavigationVariables(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TriggerNavigationVariables*)
   {
      ::TriggerNavigationVariables *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TriggerNavigationVariables),0);
      static ::ROOT::TGenericClassInfo 
         instance("TriggerNavigationVariables", "TrigMuonEfficiency/TriggerNavigationVariables.h", 10,
                  typeid(::TriggerNavigationVariables), DefineBehavior(ptr, ptr),
                  &TriggerNavigationVariables_Dictionary, isa_proxy, 4,
                  sizeof(::TriggerNavigationVariables) );
      instance.SetNew(&new_TriggerNavigationVariables);
      instance.SetNewArray(&newArray_TriggerNavigationVariables);
      instance.SetDelete(&delete_TriggerNavigationVariables);
      instance.SetDeleteArray(&deleteArray_TriggerNavigationVariables);
      instance.SetDestructor(&destruct_TriggerNavigationVariables);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TriggerNavigationVariables*)
   {
      return GenerateInitInstanceLocal((::TriggerNavigationVariables*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TriggerNavigationVariables*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TriggerNavigationVariables_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TriggerNavigationVariables*)0x0)->GetClass();
      TriggerNavigationVariables_TClassManip(theClass);
   return theClass;
   }

   static void TriggerNavigationVariables_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_MuonHypothesis(void *p) {
      return  p ? new(p) ::MuonHypothesis : new ::MuonHypothesis;
   }
   static void *newArray_MuonHypothesis(Long_t nElements, void *p) {
      return p ? new(p) ::MuonHypothesis[nElements] : new ::MuonHypothesis[nElements];
   }
   // Wrapper around operator delete
   static void delete_MuonHypothesis(void *p) {
      delete ((::MuonHypothesis*)p);
   }
   static void deleteArray_MuonHypothesis(void *p) {
      delete [] ((::MuonHypothesis*)p);
   }
   static void destruct_MuonHypothesis(void *p) {
      typedef ::MuonHypothesis current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MuonHypothesis

namespace ROOT {
   // Wrappers around operator new
   static void *new_LeptonTriggerSF(void *p) {
      return  p ? new(p) ::LeptonTriggerSF : new ::LeptonTriggerSF;
   }
   static void *newArray_LeptonTriggerSF(Long_t nElements, void *p) {
      return p ? new(p) ::LeptonTriggerSF[nElements] : new ::LeptonTriggerSF[nElements];
   }
   // Wrapper around operator delete
   static void delete_LeptonTriggerSF(void *p) {
      delete ((::LeptonTriggerSF*)p);
   }
   static void deleteArray_LeptonTriggerSF(void *p) {
      delete [] ((::LeptonTriggerSF*)p);
   }
   static void destruct_LeptonTriggerSF(void *p) {
      typedef ::LeptonTriggerSF current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::LeptonTriggerSF

namespace ROOT {
   // Wrapper around operator delete
   static void delete_HSG3TrigLeptonSFTool(void *p) {
      delete ((::HSG3TrigLeptonSFTool*)p);
   }
   static void deleteArray_HSG3TrigLeptonSFTool(void *p) {
      delete [] ((::HSG3TrigLeptonSFTool*)p);
   }
   static void destruct_HSG3TrigLeptonSFTool(void *p) {
      typedef ::HSG3TrigLeptonSFTool current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HSG3TrigLeptonSFTool

namespace ROOT {
   // Wrapper around operator delete
   static void delete_MuonTriggerMatching(void *p) {
      delete ((::MuonTriggerMatching*)p);
   }
   static void deleteArray_MuonTriggerMatching(void *p) {
      delete [] ((::MuonTriggerMatching*)p);
   }
   static void destruct_MuonTriggerMatching(void *p) {
      typedef ::MuonTriggerMatching current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MuonTriggerMatching

namespace ROOT {
   // Wrapper around operator delete
   static void delete_ElectronTriggerMatching(void *p) {
      delete ((::ElectronTriggerMatching*)p);
   }
   static void deleteArray_ElectronTriggerMatching(void *p) {
      delete [] ((::ElectronTriggerMatching*)p);
   }
   static void destruct_ElectronTriggerMatching(void *p) {
      typedef ::ElectronTriggerMatching current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElectronTriggerMatching

namespace ROOT {
   // Wrappers around operator new
   static void *new_TriggerNavigationVariables(void *p) {
      return  p ? new(p) ::TriggerNavigationVariables : new ::TriggerNavigationVariables;
   }
   static void *newArray_TriggerNavigationVariables(Long_t nElements, void *p) {
      return p ? new(p) ::TriggerNavigationVariables[nElements] : new ::TriggerNavigationVariables[nElements];
   }
   // Wrapper around operator delete
   static void delete_TriggerNavigationVariables(void *p) {
      delete ((::TriggerNavigationVariables*)p);
   }
   static void deleteArray_TriggerNavigationVariables(void *p) {
      delete [] ((::TriggerNavigationVariables*)p);
   }
   static void destruct_TriggerNavigationVariables(void *p) {
      typedef ::TriggerNavigationVariables current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TriggerNavigationVariables

namespace ROOT {
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary();
   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEintgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<int> >*)
   {
      vector<vector<int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<int> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<int> >", -2, "vector", 210,
                  typeid(vector<vector<int> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<int> >) );
      instance.SetNew(&new_vectorlEvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<int> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<int> >*)0x0)->GetClass();
      vectorlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<int> > : new vector<vector<int> >;
   }
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<int> >[nElements] : new vector<vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEintgRsPgR(void *p) {
      delete ((vector<vector<int> >*)p);
   }
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p) {
      delete [] ((vector<vector<int> >*)p);
   }
   static void destruct_vectorlEvectorlEintgRsPgR(void *p) {
      typedef vector<vector<int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<int> >

namespace ROOT {
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 210,
                  typeid(vector<vector<float> >), DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<float> >*)0x0)->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete ((vector<vector<float> >*)p);
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] ((vector<vector<float> >*)p);
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

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

namespace ROOT {
   static TClass *vectorlEshortgR_Dictionary();
   static void vectorlEshortgR_TClassManip(TClass*);
   static void *new_vectorlEshortgR(void *p = 0);
   static void *newArray_vectorlEshortgR(Long_t size, void *p);
   static void delete_vectorlEshortgR(void *p);
   static void deleteArray_vectorlEshortgR(void *p);
   static void destruct_vectorlEshortgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<short>*)
   {
      vector<short> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<short>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<short>", -2, "vector", 210,
                  typeid(vector<short>), DefineBehavior(ptr, ptr),
                  &vectorlEshortgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<short>) );
      instance.SetNew(&new_vectorlEshortgR);
      instance.SetNewArray(&newArray_vectorlEshortgR);
      instance.SetDelete(&delete_vectorlEshortgR);
      instance.SetDeleteArray(&deleteArray_vectorlEshortgR);
      instance.SetDestructor(&destruct_vectorlEshortgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<short> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<short>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEshortgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<short>*)0x0)->GetClass();
      vectorlEshortgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEshortgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEshortgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<short> : new vector<short>;
   }
   static void *newArray_vectorlEshortgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<short>[nElements] : new vector<short>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEshortgR(void *p) {
      delete ((vector<short>*)p);
   }
   static void deleteArray_vectorlEshortgR(void *p) {
      delete [] ((vector<short>*)p);
   }
   static void destruct_vectorlEshortgR(void *p) {
      typedef vector<short> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<short>

namespace ROOT {
   static TClass *vectorlEmaplEstringcOTH2mUgRsPgR_Dictionary();
   static void vectorlEmaplEstringcOTH2mUgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEmaplEstringcOTH2mUgRsPgR(void *p = 0);
   static void *newArray_vectorlEmaplEstringcOTH2mUgRsPgR(Long_t size, void *p);
   static void delete_vectorlEmaplEstringcOTH2mUgRsPgR(void *p);
   static void deleteArray_vectorlEmaplEstringcOTH2mUgRsPgR(void *p);
   static void destruct_vectorlEmaplEstringcOTH2mUgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<map<string,TH2*> >*)
   {
      vector<map<string,TH2*> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<map<string,TH2*> >),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<map<string,TH2*> >", -2, "vector", 210,
                  typeid(vector<map<string,TH2*> >), DefineBehavior(ptr, ptr),
                  &vectorlEmaplEstringcOTH2mUgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<map<string,TH2*> >) );
      instance.SetNew(&new_vectorlEmaplEstringcOTH2mUgRsPgR);
      instance.SetNewArray(&newArray_vectorlEmaplEstringcOTH2mUgRsPgR);
      instance.SetDelete(&delete_vectorlEmaplEstringcOTH2mUgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEmaplEstringcOTH2mUgRsPgR);
      instance.SetDestructor(&destruct_vectorlEmaplEstringcOTH2mUgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<map<string,TH2*> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<map<string,TH2*> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEmaplEstringcOTH2mUgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<map<string,TH2*> >*)0x0)->GetClass();
      vectorlEmaplEstringcOTH2mUgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEmaplEstringcOTH2mUgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEmaplEstringcOTH2mUgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<map<string,TH2*> > : new vector<map<string,TH2*> >;
   }
   static void *newArray_vectorlEmaplEstringcOTH2mUgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<map<string,TH2*> >[nElements] : new vector<map<string,TH2*> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEmaplEstringcOTH2mUgRsPgR(void *p) {
      delete ((vector<map<string,TH2*> >*)p);
   }
   static void deleteArray_vectorlEmaplEstringcOTH2mUgRsPgR(void *p) {
      delete [] ((vector<map<string,TH2*> >*)p);
   }
   static void destruct_vectorlEmaplEstringcOTH2mUgRsPgR(void *p) {
      typedef vector<map<string,TH2*> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<map<string,TH2*> >

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 210,
                  typeid(vector<int>), DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = 0);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 210,
                  typeid(vector<float>), DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)0x0)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   static TClass *maplEstringcOTH2mUgR_Dictionary();
   static void maplEstringcOTH2mUgR_TClassManip(TClass*);
   static void *new_maplEstringcOTH2mUgR(void *p = 0);
   static void *newArray_maplEstringcOTH2mUgR(Long_t size, void *p);
   static void delete_maplEstringcOTH2mUgR(void *p);
   static void deleteArray_maplEstringcOTH2mUgR(void *p);
   static void destruct_maplEstringcOTH2mUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,TH2*>*)
   {
      map<string,TH2*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,TH2*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,TH2*>", -2, "map", 96,
                  typeid(map<string,TH2*>), DefineBehavior(ptr, ptr),
                  &maplEstringcOTH2mUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,TH2*>) );
      instance.SetNew(&new_maplEstringcOTH2mUgR);
      instance.SetNewArray(&newArray_maplEstringcOTH2mUgR);
      instance.SetDelete(&delete_maplEstringcOTH2mUgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOTH2mUgR);
      instance.SetDestructor(&destruct_maplEstringcOTH2mUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,TH2*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,TH2*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOTH2mUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,TH2*>*)0x0)->GetClass();
      maplEstringcOTH2mUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOTH2mUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOTH2mUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,TH2*> : new map<string,TH2*>;
   }
   static void *newArray_maplEstringcOTH2mUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,TH2*>[nElements] : new map<string,TH2*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOTH2mUgR(void *p) {
      delete ((map<string,TH2*>*)p);
   }
   static void deleteArray_maplEstringcOTH2mUgR(void *p) {
      delete [] ((map<string,TH2*>*)p);
   }
   static void destruct_maplEstringcOTH2mUgR(void *p) {
      typedef map<string,TH2*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,TH2*>

namespace ROOT {
   static TClass *maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR_Dictionary();
   static void maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR_TClassManip(TClass*);
   static void *new_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(void *p = 0);
   static void *newArray_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(Long_t size, void *p);
   static void delete_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(void *p);
   static void deleteArray_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(void *p);
   static void destruct_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,MuonTriggerMatching::DimuonChainInfo>*)
   {
      map<string,MuonTriggerMatching::DimuonChainInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,MuonTriggerMatching::DimuonChainInfo>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,MuonTriggerMatching::DimuonChainInfo>", -2, "map", 96,
                  typeid(map<string,MuonTriggerMatching::DimuonChainInfo>), DefineBehavior(ptr, ptr),
                  &maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,MuonTriggerMatching::DimuonChainInfo>) );
      instance.SetNew(&new_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR);
      instance.SetNewArray(&newArray_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR);
      instance.SetDelete(&delete_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR);
      instance.SetDestructor(&destruct_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,MuonTriggerMatching::DimuonChainInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,MuonTriggerMatching::DimuonChainInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,MuonTriggerMatching::DimuonChainInfo>*)0x0)->GetClass();
      maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,MuonTriggerMatching::DimuonChainInfo> : new map<string,MuonTriggerMatching::DimuonChainInfo>;
   }
   static void *newArray_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,MuonTriggerMatching::DimuonChainInfo>[nElements] : new map<string,MuonTriggerMatching::DimuonChainInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(void *p) {
      delete ((map<string,MuonTriggerMatching::DimuonChainInfo>*)p);
   }
   static void deleteArray_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(void *p) {
      delete [] ((map<string,MuonTriggerMatching::DimuonChainInfo>*)p);
   }
   static void destruct_maplEstringcOMuonTriggerMatchingcLcLDimuonChainInfogR(void *p) {
      typedef map<string,MuonTriggerMatching::DimuonChainInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,MuonTriggerMatching::DimuonChainInfo>

namespace ROOT {
   static TClass *maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR_Dictionary();
   static void maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR_TClassManip(TClass*);
   static void *new_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(void *p = 0);
   static void *newArray_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(Long_t size, void *p);
   static void delete_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(void *p);
   static void deleteArray_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(void *p);
   static void destruct_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,ElectronTriggerMatching::DielectronChainInfo>*)
   {
      map<string,ElectronTriggerMatching::DielectronChainInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,ElectronTriggerMatching::DielectronChainInfo>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<string,ElectronTriggerMatching::DielectronChainInfo>", -2, "map", 96,
                  typeid(map<string,ElectronTriggerMatching::DielectronChainInfo>), DefineBehavior(ptr, ptr),
                  &maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,ElectronTriggerMatching::DielectronChainInfo>) );
      instance.SetNew(&new_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR);
      instance.SetNewArray(&newArray_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR);
      instance.SetDelete(&delete_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR);
      instance.SetDestructor(&destruct_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,ElectronTriggerMatching::DielectronChainInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,ElectronTriggerMatching::DielectronChainInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,ElectronTriggerMatching::DielectronChainInfo>*)0x0)->GetClass();
      maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,ElectronTriggerMatching::DielectronChainInfo> : new map<string,ElectronTriggerMatching::DielectronChainInfo>;
   }
   static void *newArray_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,ElectronTriggerMatching::DielectronChainInfo>[nElements] : new map<string,ElectronTriggerMatching::DielectronChainInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(void *p) {
      delete ((map<string,ElectronTriggerMatching::DielectronChainInfo>*)p);
   }
   static void deleteArray_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(void *p) {
      delete [] ((map<string,ElectronTriggerMatching::DielectronChainInfo>*)p);
   }
   static void destruct_maplEstringcOElectronTriggerMatchingcLcLDielectronChainInfogR(void *p) {
      typedef map<string,ElectronTriggerMatching::DielectronChainInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,ElectronTriggerMatching::DielectronChainInfo>

namespace ROOT {
   static TClass *maplEintcOstringgR_Dictionary();
   static void maplEintcOstringgR_TClassManip(TClass*);
   static void *new_maplEintcOstringgR(void *p = 0);
   static void *newArray_maplEintcOstringgR(Long_t size, void *p);
   static void delete_maplEintcOstringgR(void *p);
   static void deleteArray_maplEintcOstringgR(void *p);
   static void destruct_maplEintcOstringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,string>*)
   {
      map<int,string> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,string>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<int,string>", -2, "map", 96,
                  typeid(map<int,string>), DefineBehavior(ptr, ptr),
                  &maplEintcOstringgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,string>) );
      instance.SetNew(&new_maplEintcOstringgR);
      instance.SetNewArray(&newArray_maplEintcOstringgR);
      instance.SetDelete(&delete_maplEintcOstringgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOstringgR);
      instance.SetDestructor(&destruct_maplEintcOstringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,string> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<int,string>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOstringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,string>*)0x0)->GetClass();
      maplEintcOstringgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOstringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOstringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,string> : new map<int,string>;
   }
   static void *newArray_maplEintcOstringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,string>[nElements] : new map<int,string>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOstringgR(void *p) {
      delete ((map<int,string>*)p);
   }
   static void deleteArray_maplEintcOstringgR(void *p) {
      delete [] ((map<int,string>*)p);
   }
   static void destruct_maplEintcOstringgR(void *p) {
      typedef map<int,string> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,string>

namespace ROOT {
   static TClass *maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR_Dictionary();
   static void maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR_TClassManip(TClass*);
   static void *new_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(void *p = 0);
   static void *newArray_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(Long_t size, void *p);
   static void delete_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(void *p);
   static void deleteArray_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(void *p);
   static void destruct_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,Root::TElectronEfficiencyCorrectionTool*>*)
   {
      map<int,Root::TElectronEfficiencyCorrectionTool*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,Root::TElectronEfficiencyCorrectionTool*>),0);
      static ::ROOT::TGenericClassInfo 
         instance("map<int,Root::TElectronEfficiencyCorrectionTool*>", -2, "map", 96,
                  typeid(map<int,Root::TElectronEfficiencyCorrectionTool*>), DefineBehavior(ptr, ptr),
                  &maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,Root::TElectronEfficiencyCorrectionTool*>) );
      instance.SetNew(&new_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR);
      instance.SetNewArray(&newArray_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR);
      instance.SetDelete(&delete_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR);
      instance.SetDeleteArray(&deleteArray_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR);
      instance.SetDestructor(&destruct_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,Root::TElectronEfficiencyCorrectionTool*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<int,Root::TElectronEfficiencyCorrectionTool*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,Root::TElectronEfficiencyCorrectionTool*>*)0x0)->GetClass();
      maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,Root::TElectronEfficiencyCorrectionTool*> : new map<int,Root::TElectronEfficiencyCorrectionTool*>;
   }
   static void *newArray_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,Root::TElectronEfficiencyCorrectionTool*>[nElements] : new map<int,Root::TElectronEfficiencyCorrectionTool*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(void *p) {
      delete ((map<int,Root::TElectronEfficiencyCorrectionTool*>*)p);
   }
   static void deleteArray_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(void *p) {
      delete [] ((map<int,Root::TElectronEfficiencyCorrectionTool*>*)p);
   }
   static void destruct_maplEintcORootcLcLTElectronEfficiencyCorrectionToolmUgR(void *p) {
      typedef map<int,Root::TElectronEfficiencyCorrectionTool*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,Root::TElectronEfficiencyCorrectionTool*>

namespace {
  void TriggerDictionaryInitialization_TrigMuonEfficiencyCINT_Impl() {
    static const char* headers[] = {
"TrigMuonEfficiency/MuonHypothesis.h",
"TrigMuonEfficiency/LeptonTriggerSF.h",
"TrigMuonEfficiency/HSG3TrigLeptonSFTool.h",
"TrigMuonEfficiency/MuonTriggerMatching.h",
"TrigMuonEfficiency/TriggerNavigationVariables.h",
"TrigMuonEfficiency/ElectronTriggerMatching.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency/Root",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency/Root/LinkDef.h")))  MuonHypothesis;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency/Root/LinkDef.h")))  LeptonTriggerSF;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency/Root/LinkDef.h")))  HSG3TrigLeptonSFTool;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency/Root/LinkDef.h")))  MuonTriggerMatching;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency/Root/LinkDef.h")))  ElectronTriggerMatching;
class __attribute__((annotate("$clingAutoload$/cvmfs/atlas.cern.ch/repo/sw/ASG/AnalysisBase/2.1.29/TrigMuonEfficiency/Root/LinkDef.h")))  TriggerNavigationVariables;
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
  #define ROOTCORE_PACKAGE "TrigMuonEfficiency"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "TrigMuonEfficiency/MuonHypothesis.h"
#include "TrigMuonEfficiency/LeptonTriggerSF.h"
#include "TrigMuonEfficiency/HSG3TrigLeptonSFTool.h"
#include "TrigMuonEfficiency/MuonTriggerMatching.h"
#include "TrigMuonEfficiency/TriggerNavigationVariables.h"
#include "TrigMuonEfficiency/ElectronTriggerMatching.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"ElectronTriggerMatching", payloadCode, "@",
"HSG3TrigLeptonSFTool", payloadCode, "@",
"LeptonTriggerSF", payloadCode, "@",
"MuonHypothesis", payloadCode, "@",
"MuonTriggerMatching", payloadCode, "@",
"TriggerNavigationVariables", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TrigMuonEfficiencyCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TrigMuonEfficiencyCINT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TrigMuonEfficiencyCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TrigMuonEfficiencyCINT() {
  TriggerDictionaryInitialization_TrigMuonEfficiencyCINT_Impl();
}
