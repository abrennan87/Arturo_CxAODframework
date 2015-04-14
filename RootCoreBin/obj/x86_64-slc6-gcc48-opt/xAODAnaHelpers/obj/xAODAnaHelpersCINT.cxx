#ifdef __llvm__
#pragma GCC diagnostic ignored "-Wunused-private-field"
#endif
// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIadIabrennandItestareadICxAODTestFrameworkdIRootCoreBindIobjdIx86_64mIslc6mIgcc48mIoptdIxAODAnaHelpersdIobjdIxAODAnaHelpersCINT

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
#include "xAODAnaHelpers/ContainerRecording.h"
#include "xAODAnaHelpers/BasicEventSelection.h"
#include "xAODAnaHelpers/BJetSelector.h"
#include "xAODAnaHelpers/ElectronSelector.h"
#include "xAODAnaHelpers/JetSelector.h"
#include "xAODAnaHelpers/TrackSelector.h"
#include "xAODAnaHelpers/MuonSelector.h"
#include "xAODAnaHelpers/ElectronCalibrator.h"
#include "xAODAnaHelpers/JetCalibrator.h"
#include "xAODAnaHelpers/MuonCalibrator.h"
#include "xAODAnaHelpers/ElectronEfficiencyCorrector.h"
#include "xAODAnaHelpers/JetHistsAlgo.h"
#include "xAODAnaHelpers/TrackHistsAlgo.h"
#include "xAODAnaHelpers/JERShifter.h"
#include "xAODAnaHelpers/OverlapRemover.h"
#include "xAODAnaHelpers/Writer.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_BasicEventSelection(void *p = 0);
   static void *newArray_BasicEventSelection(Long_t size, void *p);
   static void delete_BasicEventSelection(void *p);
   static void deleteArray_BasicEventSelection(void *p);
   static void destruct_BasicEventSelection(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BasicEventSelection*)
   {
      ::BasicEventSelection *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::BasicEventSelection >(0);
      static ::ROOT::TGenericClassInfo 
         instance("BasicEventSelection", ::BasicEventSelection::Class_Version(), "xAODAnaHelpers/BasicEventSelection.h", 25,
                  typeid(::BasicEventSelection), DefineBehavior(ptr, ptr),
                  &::BasicEventSelection::Dictionary, isa_proxy, 4,
                  sizeof(::BasicEventSelection) );
      instance.SetNew(&new_BasicEventSelection);
      instance.SetNewArray(&newArray_BasicEventSelection);
      instance.SetDelete(&delete_BasicEventSelection);
      instance.SetDeleteArray(&deleteArray_BasicEventSelection);
      instance.SetDestructor(&destruct_BasicEventSelection);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BasicEventSelection*)
   {
      return GenerateInitInstanceLocal((::BasicEventSelection*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::BasicEventSelection*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_BJetSelector(void *p = 0);
   static void *newArray_BJetSelector(Long_t size, void *p);
   static void delete_BJetSelector(void *p);
   static void deleteArray_BJetSelector(void *p);
   static void destruct_BJetSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BJetSelector*)
   {
      ::BJetSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::BJetSelector >(0);
      static ::ROOT::TGenericClassInfo 
         instance("BJetSelector", ::BJetSelector::Class_Version(), "xAODAnaHelpers/BJetSelector.h", 21,
                  typeid(::BJetSelector), DefineBehavior(ptr, ptr),
                  &::BJetSelector::Dictionary, isa_proxy, 4,
                  sizeof(::BJetSelector) );
      instance.SetNew(&new_BJetSelector);
      instance.SetNewArray(&newArray_BJetSelector);
      instance.SetDelete(&delete_BJetSelector);
      instance.SetDeleteArray(&deleteArray_BJetSelector);
      instance.SetDestructor(&destruct_BJetSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BJetSelector*)
   {
      return GenerateInitInstanceLocal((::BJetSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::BJetSelector*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ElectronSelector(void *p = 0);
   static void *newArray_ElectronSelector(Long_t size, void *p);
   static void delete_ElectronSelector(void *p);
   static void deleteArray_ElectronSelector(void *p);
   static void destruct_ElectronSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElectronSelector*)
   {
      ::ElectronSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ElectronSelector >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ElectronSelector", ::ElectronSelector::Class_Version(), "xAODAnaHelpers/ElectronSelector.h", 29,
                  typeid(::ElectronSelector), DefineBehavior(ptr, ptr),
                  &::ElectronSelector::Dictionary, isa_proxy, 4,
                  sizeof(::ElectronSelector) );
      instance.SetNew(&new_ElectronSelector);
      instance.SetNewArray(&newArray_ElectronSelector);
      instance.SetDelete(&delete_ElectronSelector);
      instance.SetDeleteArray(&deleteArray_ElectronSelector);
      instance.SetDestructor(&destruct_ElectronSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElectronSelector*)
   {
      return GenerateInitInstanceLocal((::ElectronSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElectronSelector*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_JetSelector(void *p = 0);
   static void *newArray_JetSelector(Long_t size, void *p);
   static void delete_JetSelector(void *p);
   static void deleteArray_JetSelector(void *p);
   static void destruct_JetSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JetSelector*)
   {
      ::JetSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JetSelector >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JetSelector", ::JetSelector::Class_Version(), "xAODAnaHelpers/JetSelector.h", 21,
                  typeid(::JetSelector), DefineBehavior(ptr, ptr),
                  &::JetSelector::Dictionary, isa_proxy, 4,
                  sizeof(::JetSelector) );
      instance.SetNew(&new_JetSelector);
      instance.SetNewArray(&newArray_JetSelector);
      instance.SetDelete(&delete_JetSelector);
      instance.SetDeleteArray(&deleteArray_JetSelector);
      instance.SetDestructor(&destruct_JetSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JetSelector*)
   {
      return GenerateInitInstanceLocal((::JetSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::JetSelector*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TrackSelector(void *p = 0);
   static void *newArray_TrackSelector(Long_t size, void *p);
   static void delete_TrackSelector(void *p);
   static void deleteArray_TrackSelector(void *p);
   static void destruct_TrackSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrackSelector*)
   {
      ::TrackSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TrackSelector >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TrackSelector", ::TrackSelector::Class_Version(), "xAODAnaHelpers/TrackSelector.h", 27,
                  typeid(::TrackSelector), DefineBehavior(ptr, ptr),
                  &::TrackSelector::Dictionary, isa_proxy, 4,
                  sizeof(::TrackSelector) );
      instance.SetNew(&new_TrackSelector);
      instance.SetNewArray(&newArray_TrackSelector);
      instance.SetDelete(&delete_TrackSelector);
      instance.SetDeleteArray(&deleteArray_TrackSelector);
      instance.SetDestructor(&destruct_TrackSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrackSelector*)
   {
      return GenerateInitInstanceLocal((::TrackSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TrackSelector*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MuonSelector(void *p = 0);
   static void *newArray_MuonSelector(Long_t size, void *p);
   static void delete_MuonSelector(void *p);
   static void deleteArray_MuonSelector(void *p);
   static void destruct_MuonSelector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MuonSelector*)
   {
      ::MuonSelector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MuonSelector >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MuonSelector", ::MuonSelector::Class_Version(), "xAODAnaHelpers/MuonSelector.h", 27,
                  typeid(::MuonSelector), DefineBehavior(ptr, ptr),
                  &::MuonSelector::Dictionary, isa_proxy, 4,
                  sizeof(::MuonSelector) );
      instance.SetNew(&new_MuonSelector);
      instance.SetNewArray(&newArray_MuonSelector);
      instance.SetDelete(&delete_MuonSelector);
      instance.SetDeleteArray(&deleteArray_MuonSelector);
      instance.SetDestructor(&destruct_MuonSelector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MuonSelector*)
   {
      return GenerateInitInstanceLocal((::MuonSelector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MuonSelector*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ElectronCalibrator(void *p = 0);
   static void *newArray_ElectronCalibrator(Long_t size, void *p);
   static void delete_ElectronCalibrator(void *p);
   static void deleteArray_ElectronCalibrator(void *p);
   static void destruct_ElectronCalibrator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElectronCalibrator*)
   {
      ::ElectronCalibrator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ElectronCalibrator >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ElectronCalibrator", ::ElectronCalibrator::Class_Version(), "xAODAnaHelpers/ElectronCalibrator.h", 23,
                  typeid(::ElectronCalibrator), DefineBehavior(ptr, ptr),
                  &::ElectronCalibrator::Dictionary, isa_proxy, 4,
                  sizeof(::ElectronCalibrator) );
      instance.SetNew(&new_ElectronCalibrator);
      instance.SetNewArray(&newArray_ElectronCalibrator);
      instance.SetDelete(&delete_ElectronCalibrator);
      instance.SetDeleteArray(&deleteArray_ElectronCalibrator);
      instance.SetDestructor(&destruct_ElectronCalibrator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElectronCalibrator*)
   {
      return GenerateInitInstanceLocal((::ElectronCalibrator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElectronCalibrator*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_JetCalibrator(void *p = 0);
   static void *newArray_JetCalibrator(Long_t size, void *p);
   static void delete_JetCalibrator(void *p);
   static void deleteArray_JetCalibrator(void *p);
   static void destruct_JetCalibrator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JetCalibrator*)
   {
      ::JetCalibrator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JetCalibrator >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JetCalibrator", ::JetCalibrator::Class_Version(), "xAODAnaHelpers/JetCalibrator.h", 21,
                  typeid(::JetCalibrator), DefineBehavior(ptr, ptr),
                  &::JetCalibrator::Dictionary, isa_proxy, 4,
                  sizeof(::JetCalibrator) );
      instance.SetNew(&new_JetCalibrator);
      instance.SetNewArray(&newArray_JetCalibrator);
      instance.SetDelete(&delete_JetCalibrator);
      instance.SetDeleteArray(&deleteArray_JetCalibrator);
      instance.SetDestructor(&destruct_JetCalibrator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JetCalibrator*)
   {
      return GenerateInitInstanceLocal((::JetCalibrator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::JetCalibrator*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MuonCalibrator(void *p = 0);
   static void *newArray_MuonCalibrator(Long_t size, void *p);
   static void delete_MuonCalibrator(void *p);
   static void deleteArray_MuonCalibrator(void *p);
   static void destruct_MuonCalibrator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MuonCalibrator*)
   {
      ::MuonCalibrator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MuonCalibrator >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MuonCalibrator", ::MuonCalibrator::Class_Version(), "xAODAnaHelpers/MuonCalibrator.h", 18,
                  typeid(::MuonCalibrator), DefineBehavior(ptr, ptr),
                  &::MuonCalibrator::Dictionary, isa_proxy, 4,
                  sizeof(::MuonCalibrator) );
      instance.SetNew(&new_MuonCalibrator);
      instance.SetNewArray(&newArray_MuonCalibrator);
      instance.SetDelete(&delete_MuonCalibrator);
      instance.SetDeleteArray(&deleteArray_MuonCalibrator);
      instance.SetDestructor(&destruct_MuonCalibrator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MuonCalibrator*)
   {
      return GenerateInitInstanceLocal((::MuonCalibrator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MuonCalibrator*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ElectronEfficiencyCorrector(void *p = 0);
   static void *newArray_ElectronEfficiencyCorrector(Long_t size, void *p);
   static void delete_ElectronEfficiencyCorrector(void *p);
   static void deleteArray_ElectronEfficiencyCorrector(void *p);
   static void destruct_ElectronEfficiencyCorrector(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ElectronEfficiencyCorrector*)
   {
      ::ElectronEfficiencyCorrector *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ElectronEfficiencyCorrector >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ElectronEfficiencyCorrector", ::ElectronEfficiencyCorrector::Class_Version(), "xAODAnaHelpers/ElectronEfficiencyCorrector.h", 20,
                  typeid(::ElectronEfficiencyCorrector), DefineBehavior(ptr, ptr),
                  &::ElectronEfficiencyCorrector::Dictionary, isa_proxy, 4,
                  sizeof(::ElectronEfficiencyCorrector) );
      instance.SetNew(&new_ElectronEfficiencyCorrector);
      instance.SetNewArray(&newArray_ElectronEfficiencyCorrector);
      instance.SetDelete(&delete_ElectronEfficiencyCorrector);
      instance.SetDeleteArray(&deleteArray_ElectronEfficiencyCorrector);
      instance.SetDestructor(&destruct_ElectronEfficiencyCorrector);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ElectronEfficiencyCorrector*)
   {
      return GenerateInitInstanceLocal((::ElectronEfficiencyCorrector*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ElectronEfficiencyCorrector*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_JetHistsAlgo(void *p = 0);
   static void *newArray_JetHistsAlgo(Long_t size, void *p);
   static void delete_JetHistsAlgo(void *p);
   static void deleteArray_JetHistsAlgo(void *p);
   static void destruct_JetHistsAlgo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JetHistsAlgo*)
   {
      ::JetHistsAlgo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JetHistsAlgo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JetHistsAlgo", ::JetHistsAlgo::Class_Version(), "xAODAnaHelpers/JetHistsAlgo.h", 12,
                  typeid(::JetHistsAlgo), DefineBehavior(ptr, ptr),
                  &::JetHistsAlgo::Dictionary, isa_proxy, 4,
                  sizeof(::JetHistsAlgo) );
      instance.SetNew(&new_JetHistsAlgo);
      instance.SetNewArray(&newArray_JetHistsAlgo);
      instance.SetDelete(&delete_JetHistsAlgo);
      instance.SetDeleteArray(&deleteArray_JetHistsAlgo);
      instance.SetDestructor(&destruct_JetHistsAlgo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JetHistsAlgo*)
   {
      return GenerateInitInstanceLocal((::JetHistsAlgo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::JetHistsAlgo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TrackHistsAlgo(void *p = 0);
   static void *newArray_TrackHistsAlgo(Long_t size, void *p);
   static void delete_TrackHistsAlgo(void *p);
   static void deleteArray_TrackHistsAlgo(void *p);
   static void destruct_TrackHistsAlgo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TrackHistsAlgo*)
   {
      ::TrackHistsAlgo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TrackHistsAlgo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TrackHistsAlgo", ::TrackHistsAlgo::Class_Version(), "xAODAnaHelpers/TrackHistsAlgo.h", 12,
                  typeid(::TrackHistsAlgo), DefineBehavior(ptr, ptr),
                  &::TrackHistsAlgo::Dictionary, isa_proxy, 4,
                  sizeof(::TrackHistsAlgo) );
      instance.SetNew(&new_TrackHistsAlgo);
      instance.SetNewArray(&newArray_TrackHistsAlgo);
      instance.SetDelete(&delete_TrackHistsAlgo);
      instance.SetDeleteArray(&deleteArray_TrackHistsAlgo);
      instance.SetDestructor(&destruct_TrackHistsAlgo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TrackHistsAlgo*)
   {
      return GenerateInitInstanceLocal((::TrackHistsAlgo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TrackHistsAlgo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_JERShifter(void *p = 0);
   static void *newArray_JERShifter(Long_t size, void *p);
   static void delete_JERShifter(void *p);
   static void deleteArray_JERShifter(void *p);
   static void destruct_JERShifter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::JERShifter*)
   {
      ::JERShifter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::JERShifter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("JERShifter", ::JERShifter::Class_Version(), "xAODAnaHelpers/JERShifter.h", 15,
                  typeid(::JERShifter), DefineBehavior(ptr, ptr),
                  &::JERShifter::Dictionary, isa_proxy, 4,
                  sizeof(::JERShifter) );
      instance.SetNew(&new_JERShifter);
      instance.SetNewArray(&newArray_JERShifter);
      instance.SetDelete(&delete_JERShifter);
      instance.SetDeleteArray(&deleteArray_JERShifter);
      instance.SetDestructor(&destruct_JERShifter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::JERShifter*)
   {
      return GenerateInitInstanceLocal((::JERShifter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::JERShifter*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_OverlapRemover(void *p = 0);
   static void *newArray_OverlapRemover(Long_t size, void *p);
   static void delete_OverlapRemover(void *p);
   static void deleteArray_OverlapRemover(void *p);
   static void destruct_OverlapRemover(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::OverlapRemover*)
   {
      ::OverlapRemover *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::OverlapRemover >(0);
      static ::ROOT::TGenericClassInfo 
         instance("OverlapRemover", ::OverlapRemover::Class_Version(), "xAODAnaHelpers/OverlapRemover.h", 25,
                  typeid(::OverlapRemover), DefineBehavior(ptr, ptr),
                  &::OverlapRemover::Dictionary, isa_proxy, 4,
                  sizeof(::OverlapRemover) );
      instance.SetNew(&new_OverlapRemover);
      instance.SetNewArray(&newArray_OverlapRemover);
      instance.SetDelete(&delete_OverlapRemover);
      instance.SetDeleteArray(&deleteArray_OverlapRemover);
      instance.SetDestructor(&destruct_OverlapRemover);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::OverlapRemover*)
   {
      return GenerateInitInstanceLocal((::OverlapRemover*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::OverlapRemover*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Writer(void *p = 0);
   static void *newArray_Writer(Long_t size, void *p);
   static void delete_Writer(void *p);
   static void deleteArray_Writer(void *p);
   static void destruct_Writer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Writer*)
   {
      ::Writer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Writer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Writer", ::Writer::Class_Version(), "xAODAnaHelpers/Writer.h", 12,
                  typeid(::Writer), DefineBehavior(ptr, ptr),
                  &::Writer::Dictionary, isa_proxy, 4,
                  sizeof(::Writer) );
      instance.SetNew(&new_Writer);
      instance.SetNewArray(&newArray_Writer);
      instance.SetDelete(&delete_Writer);
      instance.SetDeleteArray(&deleteArray_Writer);
      instance.SetDestructor(&destruct_Writer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Writer*)
   {
      return GenerateInitInstanceLocal((::Writer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Writer*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_ContainerRecording(void *p = 0);
   static void *newArray_ContainerRecording(Long_t size, void *p);
   static void delete_ContainerRecording(void *p);
   static void deleteArray_ContainerRecording(void *p);
   static void destruct_ContainerRecording(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ContainerRecording*)
   {
      ::ContainerRecording *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ContainerRecording >(0);
      static ::ROOT::TGenericClassInfo 
         instance("ContainerRecording", ::ContainerRecording::Class_Version(), "xAODAnaHelpers/ContainerRecording.h", 10,
                  typeid(::ContainerRecording), DefineBehavior(ptr, ptr),
                  &::ContainerRecording::Dictionary, isa_proxy, 4,
                  sizeof(::ContainerRecording) );
      instance.SetNew(&new_ContainerRecording);
      instance.SetNewArray(&newArray_ContainerRecording);
      instance.SetDelete(&delete_ContainerRecording);
      instance.SetDeleteArray(&deleteArray_ContainerRecording);
      instance.SetDestructor(&destruct_ContainerRecording);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ContainerRecording*)
   {
      return GenerateInitInstanceLocal((::ContainerRecording*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::ContainerRecording*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr BasicEventSelection::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BasicEventSelection::Class_Name()
{
   return "BasicEventSelection";
}

//______________________________________________________________________________
const char *BasicEventSelection::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BasicEventSelection*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BasicEventSelection::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BasicEventSelection*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BasicEventSelection::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BasicEventSelection*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BasicEventSelection::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BasicEventSelection*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr BJetSelector::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *BJetSelector::Class_Name()
{
   return "BJetSelector";
}

//______________________________________________________________________________
const char *BJetSelector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BJetSelector*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int BJetSelector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::BJetSelector*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BJetSelector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BJetSelector*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BJetSelector::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::BJetSelector*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ElectronSelector::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ElectronSelector::Class_Name()
{
   return "ElectronSelector";
}

//______________________________________________________________________________
const char *ElectronSelector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ElectronSelector*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ElectronSelector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ElectronSelector*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ElectronSelector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ElectronSelector*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ElectronSelector::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ElectronSelector*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr JetSelector::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *JetSelector::Class_Name()
{
   return "JetSelector";
}

//______________________________________________________________________________
const char *JetSelector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JetSelector*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int JetSelector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JetSelector*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetSelector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JetSelector*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetSelector::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JetSelector*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TrackSelector::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TrackSelector::Class_Name()
{
   return "TrackSelector";
}

//______________________________________________________________________________
const char *TrackSelector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackSelector*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TrackSelector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackSelector*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TrackSelector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackSelector*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TrackSelector::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackSelector*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MuonSelector::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MuonSelector::Class_Name()
{
   return "MuonSelector";
}

//______________________________________________________________________________
const char *MuonSelector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MuonSelector*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MuonSelector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MuonSelector*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MuonSelector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MuonSelector*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MuonSelector::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MuonSelector*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ElectronCalibrator::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ElectronCalibrator::Class_Name()
{
   return "ElectronCalibrator";
}

//______________________________________________________________________________
const char *ElectronCalibrator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ElectronCalibrator*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ElectronCalibrator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ElectronCalibrator*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ElectronCalibrator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ElectronCalibrator*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ElectronCalibrator::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ElectronCalibrator*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr JetCalibrator::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *JetCalibrator::Class_Name()
{
   return "JetCalibrator";
}

//______________________________________________________________________________
const char *JetCalibrator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JetCalibrator*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int JetCalibrator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JetCalibrator*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetCalibrator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JetCalibrator*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetCalibrator::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JetCalibrator*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MuonCalibrator::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MuonCalibrator::Class_Name()
{
   return "MuonCalibrator";
}

//______________________________________________________________________________
const char *MuonCalibrator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MuonCalibrator*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MuonCalibrator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MuonCalibrator*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MuonCalibrator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MuonCalibrator*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MuonCalibrator::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MuonCalibrator*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ElectronEfficiencyCorrector::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ElectronEfficiencyCorrector::Class_Name()
{
   return "ElectronEfficiencyCorrector";
}

//______________________________________________________________________________
const char *ElectronEfficiencyCorrector::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ElectronEfficiencyCorrector*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ElectronEfficiencyCorrector::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ElectronEfficiencyCorrector*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ElectronEfficiencyCorrector::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ElectronEfficiencyCorrector*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ElectronEfficiencyCorrector::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ElectronEfficiencyCorrector*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr JetHistsAlgo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *JetHistsAlgo::Class_Name()
{
   return "JetHistsAlgo";
}

//______________________________________________________________________________
const char *JetHistsAlgo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JetHistsAlgo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int JetHistsAlgo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JetHistsAlgo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetHistsAlgo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JetHistsAlgo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetHistsAlgo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JetHistsAlgo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TrackHistsAlgo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TrackHistsAlgo::Class_Name()
{
   return "TrackHistsAlgo";
}

//______________________________________________________________________________
const char *TrackHistsAlgo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackHistsAlgo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TrackHistsAlgo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TrackHistsAlgo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TrackHistsAlgo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackHistsAlgo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TrackHistsAlgo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TrackHistsAlgo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr JERShifter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *JERShifter::Class_Name()
{
   return "JERShifter";
}

//______________________________________________________________________________
const char *JERShifter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JERShifter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int JERShifter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::JERShifter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JERShifter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JERShifter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JERShifter::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::JERShifter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr OverlapRemover::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *OverlapRemover::Class_Name()
{
   return "OverlapRemover";
}

//______________________________________________________________________________
const char *OverlapRemover::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::OverlapRemover*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int OverlapRemover::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::OverlapRemover*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *OverlapRemover::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::OverlapRemover*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *OverlapRemover::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::OverlapRemover*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Writer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Writer::Class_Name()
{
   return "Writer";
}

//______________________________________________________________________________
const char *Writer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Writer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Writer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Writer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Writer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Writer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Writer::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Writer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr ContainerRecording::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *ContainerRecording::Class_Name()
{
   return "ContainerRecording";
}

//______________________________________________________________________________
const char *ContainerRecording::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ContainerRecording*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int ContainerRecording::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ContainerRecording*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ContainerRecording::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ContainerRecording*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ContainerRecording::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ContainerRecording*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void BasicEventSelection::Streamer(TBuffer &R__b)
{
   // Stream an object of class BasicEventSelection.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(BasicEventSelection::Class(),this);
   } else {
      R__b.WriteClassBuffer(BasicEventSelection::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_BasicEventSelection(void *p) {
      return  p ? new(p) ::BasicEventSelection : new ::BasicEventSelection;
   }
   static void *newArray_BasicEventSelection(Long_t nElements, void *p) {
      return p ? new(p) ::BasicEventSelection[nElements] : new ::BasicEventSelection[nElements];
   }
   // Wrapper around operator delete
   static void delete_BasicEventSelection(void *p) {
      delete ((::BasicEventSelection*)p);
   }
   static void deleteArray_BasicEventSelection(void *p) {
      delete [] ((::BasicEventSelection*)p);
   }
   static void destruct_BasicEventSelection(void *p) {
      typedef ::BasicEventSelection current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BasicEventSelection

//______________________________________________________________________________
void BJetSelector::Streamer(TBuffer &R__b)
{
   // Stream an object of class BJetSelector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(BJetSelector::Class(),this);
   } else {
      R__b.WriteClassBuffer(BJetSelector::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_BJetSelector(void *p) {
      return  p ? new(p) ::BJetSelector : new ::BJetSelector;
   }
   static void *newArray_BJetSelector(Long_t nElements, void *p) {
      return p ? new(p) ::BJetSelector[nElements] : new ::BJetSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_BJetSelector(void *p) {
      delete ((::BJetSelector*)p);
   }
   static void deleteArray_BJetSelector(void *p) {
      delete [] ((::BJetSelector*)p);
   }
   static void destruct_BJetSelector(void *p) {
      typedef ::BJetSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BJetSelector

//______________________________________________________________________________
void ElectronSelector::Streamer(TBuffer &R__b)
{
   // Stream an object of class ElectronSelector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ElectronSelector::Class(),this);
   } else {
      R__b.WriteClassBuffer(ElectronSelector::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElectronSelector(void *p) {
      return  p ? new(p) ::ElectronSelector : new ::ElectronSelector;
   }
   static void *newArray_ElectronSelector(Long_t nElements, void *p) {
      return p ? new(p) ::ElectronSelector[nElements] : new ::ElectronSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElectronSelector(void *p) {
      delete ((::ElectronSelector*)p);
   }
   static void deleteArray_ElectronSelector(void *p) {
      delete [] ((::ElectronSelector*)p);
   }
   static void destruct_ElectronSelector(void *p) {
      typedef ::ElectronSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElectronSelector

//______________________________________________________________________________
void JetSelector::Streamer(TBuffer &R__b)
{
   // Stream an object of class JetSelector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JetSelector::Class(),this);
   } else {
      R__b.WriteClassBuffer(JetSelector::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_JetSelector(void *p) {
      return  p ? new(p) ::JetSelector : new ::JetSelector;
   }
   static void *newArray_JetSelector(Long_t nElements, void *p) {
      return p ? new(p) ::JetSelector[nElements] : new ::JetSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_JetSelector(void *p) {
      delete ((::JetSelector*)p);
   }
   static void deleteArray_JetSelector(void *p) {
      delete [] ((::JetSelector*)p);
   }
   static void destruct_JetSelector(void *p) {
      typedef ::JetSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JetSelector

//______________________________________________________________________________
void TrackSelector::Streamer(TBuffer &R__b)
{
   // Stream an object of class TrackSelector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TrackSelector::Class(),this);
   } else {
      R__b.WriteClassBuffer(TrackSelector::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrackSelector(void *p) {
      return  p ? new(p) ::TrackSelector : new ::TrackSelector;
   }
   static void *newArray_TrackSelector(Long_t nElements, void *p) {
      return p ? new(p) ::TrackSelector[nElements] : new ::TrackSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrackSelector(void *p) {
      delete ((::TrackSelector*)p);
   }
   static void deleteArray_TrackSelector(void *p) {
      delete [] ((::TrackSelector*)p);
   }
   static void destruct_TrackSelector(void *p) {
      typedef ::TrackSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TrackSelector

//______________________________________________________________________________
void MuonSelector::Streamer(TBuffer &R__b)
{
   // Stream an object of class MuonSelector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MuonSelector::Class(),this);
   } else {
      R__b.WriteClassBuffer(MuonSelector::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MuonSelector(void *p) {
      return  p ? new(p) ::MuonSelector : new ::MuonSelector;
   }
   static void *newArray_MuonSelector(Long_t nElements, void *p) {
      return p ? new(p) ::MuonSelector[nElements] : new ::MuonSelector[nElements];
   }
   // Wrapper around operator delete
   static void delete_MuonSelector(void *p) {
      delete ((::MuonSelector*)p);
   }
   static void deleteArray_MuonSelector(void *p) {
      delete [] ((::MuonSelector*)p);
   }
   static void destruct_MuonSelector(void *p) {
      typedef ::MuonSelector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MuonSelector

//______________________________________________________________________________
void ElectronCalibrator::Streamer(TBuffer &R__b)
{
   // Stream an object of class ElectronCalibrator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ElectronCalibrator::Class(),this);
   } else {
      R__b.WriteClassBuffer(ElectronCalibrator::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElectronCalibrator(void *p) {
      return  p ? new(p) ::ElectronCalibrator : new ::ElectronCalibrator;
   }
   static void *newArray_ElectronCalibrator(Long_t nElements, void *p) {
      return p ? new(p) ::ElectronCalibrator[nElements] : new ::ElectronCalibrator[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElectronCalibrator(void *p) {
      delete ((::ElectronCalibrator*)p);
   }
   static void deleteArray_ElectronCalibrator(void *p) {
      delete [] ((::ElectronCalibrator*)p);
   }
   static void destruct_ElectronCalibrator(void *p) {
      typedef ::ElectronCalibrator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElectronCalibrator

//______________________________________________________________________________
void JetCalibrator::Streamer(TBuffer &R__b)
{
   // Stream an object of class JetCalibrator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JetCalibrator::Class(),this);
   } else {
      R__b.WriteClassBuffer(JetCalibrator::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_JetCalibrator(void *p) {
      return  p ? new(p) ::JetCalibrator : new ::JetCalibrator;
   }
   static void *newArray_JetCalibrator(Long_t nElements, void *p) {
      return p ? new(p) ::JetCalibrator[nElements] : new ::JetCalibrator[nElements];
   }
   // Wrapper around operator delete
   static void delete_JetCalibrator(void *p) {
      delete ((::JetCalibrator*)p);
   }
   static void deleteArray_JetCalibrator(void *p) {
      delete [] ((::JetCalibrator*)p);
   }
   static void destruct_JetCalibrator(void *p) {
      typedef ::JetCalibrator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JetCalibrator

//______________________________________________________________________________
void MuonCalibrator::Streamer(TBuffer &R__b)
{
   // Stream an object of class MuonCalibrator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MuonCalibrator::Class(),this);
   } else {
      R__b.WriteClassBuffer(MuonCalibrator::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MuonCalibrator(void *p) {
      return  p ? new(p) ::MuonCalibrator : new ::MuonCalibrator;
   }
   static void *newArray_MuonCalibrator(Long_t nElements, void *p) {
      return p ? new(p) ::MuonCalibrator[nElements] : new ::MuonCalibrator[nElements];
   }
   // Wrapper around operator delete
   static void delete_MuonCalibrator(void *p) {
      delete ((::MuonCalibrator*)p);
   }
   static void deleteArray_MuonCalibrator(void *p) {
      delete [] ((::MuonCalibrator*)p);
   }
   static void destruct_MuonCalibrator(void *p) {
      typedef ::MuonCalibrator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MuonCalibrator

//______________________________________________________________________________
void ElectronEfficiencyCorrector::Streamer(TBuffer &R__b)
{
   // Stream an object of class ElectronEfficiencyCorrector.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ElectronEfficiencyCorrector::Class(),this);
   } else {
      R__b.WriteClassBuffer(ElectronEfficiencyCorrector::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ElectronEfficiencyCorrector(void *p) {
      return  p ? new(p) ::ElectronEfficiencyCorrector : new ::ElectronEfficiencyCorrector;
   }
   static void *newArray_ElectronEfficiencyCorrector(Long_t nElements, void *p) {
      return p ? new(p) ::ElectronEfficiencyCorrector[nElements] : new ::ElectronEfficiencyCorrector[nElements];
   }
   // Wrapper around operator delete
   static void delete_ElectronEfficiencyCorrector(void *p) {
      delete ((::ElectronEfficiencyCorrector*)p);
   }
   static void deleteArray_ElectronEfficiencyCorrector(void *p) {
      delete [] ((::ElectronEfficiencyCorrector*)p);
   }
   static void destruct_ElectronEfficiencyCorrector(void *p) {
      typedef ::ElectronEfficiencyCorrector current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ElectronEfficiencyCorrector

//______________________________________________________________________________
void JetHistsAlgo::Streamer(TBuffer &R__b)
{
   // Stream an object of class JetHistsAlgo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JetHistsAlgo::Class(),this);
   } else {
      R__b.WriteClassBuffer(JetHistsAlgo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_JetHistsAlgo(void *p) {
      return  p ? new(p) ::JetHistsAlgo : new ::JetHistsAlgo;
   }
   static void *newArray_JetHistsAlgo(Long_t nElements, void *p) {
      return p ? new(p) ::JetHistsAlgo[nElements] : new ::JetHistsAlgo[nElements];
   }
   // Wrapper around operator delete
   static void delete_JetHistsAlgo(void *p) {
      delete ((::JetHistsAlgo*)p);
   }
   static void deleteArray_JetHistsAlgo(void *p) {
      delete [] ((::JetHistsAlgo*)p);
   }
   static void destruct_JetHistsAlgo(void *p) {
      typedef ::JetHistsAlgo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JetHistsAlgo

//______________________________________________________________________________
void TrackHistsAlgo::Streamer(TBuffer &R__b)
{
   // Stream an object of class TrackHistsAlgo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TrackHistsAlgo::Class(),this);
   } else {
      R__b.WriteClassBuffer(TrackHistsAlgo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TrackHistsAlgo(void *p) {
      return  p ? new(p) ::TrackHistsAlgo : new ::TrackHistsAlgo;
   }
   static void *newArray_TrackHistsAlgo(Long_t nElements, void *p) {
      return p ? new(p) ::TrackHistsAlgo[nElements] : new ::TrackHistsAlgo[nElements];
   }
   // Wrapper around operator delete
   static void delete_TrackHistsAlgo(void *p) {
      delete ((::TrackHistsAlgo*)p);
   }
   static void deleteArray_TrackHistsAlgo(void *p) {
      delete [] ((::TrackHistsAlgo*)p);
   }
   static void destruct_TrackHistsAlgo(void *p) {
      typedef ::TrackHistsAlgo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TrackHistsAlgo

//______________________________________________________________________________
void JERShifter::Streamer(TBuffer &R__b)
{
   // Stream an object of class JERShifter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(JERShifter::Class(),this);
   } else {
      R__b.WriteClassBuffer(JERShifter::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_JERShifter(void *p) {
      return  p ? new(p) ::JERShifter : new ::JERShifter;
   }
   static void *newArray_JERShifter(Long_t nElements, void *p) {
      return p ? new(p) ::JERShifter[nElements] : new ::JERShifter[nElements];
   }
   // Wrapper around operator delete
   static void delete_JERShifter(void *p) {
      delete ((::JERShifter*)p);
   }
   static void deleteArray_JERShifter(void *p) {
      delete [] ((::JERShifter*)p);
   }
   static void destruct_JERShifter(void *p) {
      typedef ::JERShifter current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::JERShifter

//______________________________________________________________________________
void OverlapRemover::Streamer(TBuffer &R__b)
{
   // Stream an object of class OverlapRemover.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(OverlapRemover::Class(),this);
   } else {
      R__b.WriteClassBuffer(OverlapRemover::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_OverlapRemover(void *p) {
      return  p ? new(p) ::OverlapRemover : new ::OverlapRemover;
   }
   static void *newArray_OverlapRemover(Long_t nElements, void *p) {
      return p ? new(p) ::OverlapRemover[nElements] : new ::OverlapRemover[nElements];
   }
   // Wrapper around operator delete
   static void delete_OverlapRemover(void *p) {
      delete ((::OverlapRemover*)p);
   }
   static void deleteArray_OverlapRemover(void *p) {
      delete [] ((::OverlapRemover*)p);
   }
   static void destruct_OverlapRemover(void *p) {
      typedef ::OverlapRemover current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::OverlapRemover

//______________________________________________________________________________
void Writer::Streamer(TBuffer &R__b)
{
   // Stream an object of class Writer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Writer::Class(),this);
   } else {
      R__b.WriteClassBuffer(Writer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Writer(void *p) {
      return  p ? new(p) ::Writer : new ::Writer;
   }
   static void *newArray_Writer(Long_t nElements, void *p) {
      return p ? new(p) ::Writer[nElements] : new ::Writer[nElements];
   }
   // Wrapper around operator delete
   static void delete_Writer(void *p) {
      delete ((::Writer*)p);
   }
   static void deleteArray_Writer(void *p) {
      delete [] ((::Writer*)p);
   }
   static void destruct_Writer(void *p) {
      typedef ::Writer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Writer

//______________________________________________________________________________
void ContainerRecording::Streamer(TBuffer &R__b)
{
   // Stream an object of class ContainerRecording.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ContainerRecording::Class(),this);
   } else {
      R__b.WriteClassBuffer(ContainerRecording::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ContainerRecording(void *p) {
      return  p ? new(p) ::ContainerRecording : new ::ContainerRecording;
   }
   static void *newArray_ContainerRecording(Long_t nElements, void *p) {
      return p ? new(p) ::ContainerRecording[nElements] : new ::ContainerRecording[nElements];
   }
   // Wrapper around operator delete
   static void delete_ContainerRecording(void *p) {
      delete ((::ContainerRecording*)p);
   }
   static void deleteArray_ContainerRecording(void *p) {
      delete [] ((::ContainerRecording*)p);
   }
   static void destruct_ContainerRecording(void *p) {
      typedef ::ContainerRecording current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ContainerRecording

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
   static TClass *vectorlETStringgR_Dictionary();
   static void vectorlETStringgR_TClassManip(TClass*);
   static void *new_vectorlETStringgR(void *p = 0);
   static void *newArray_vectorlETStringgR(Long_t size, void *p);
   static void delete_vectorlETStringgR(void *p);
   static void deleteArray_vectorlETStringgR(void *p);
   static void destruct_vectorlETStringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TString>*)
   {
      vector<TString> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TString>),0);
      static ::ROOT::TGenericClassInfo 
         instance("vector<TString>", -2, "vector", 210,
                  typeid(vector<TString>), DefineBehavior(ptr, ptr),
                  &vectorlETStringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TString>) );
      instance.SetNew(&new_vectorlETStringgR);
      instance.SetNewArray(&newArray_vectorlETStringgR);
      instance.SetDelete(&delete_vectorlETStringgR);
      instance.SetDeleteArray(&deleteArray_vectorlETStringgR);
      instance.SetDestructor(&destruct_vectorlETStringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TString> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<TString>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETStringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TString>*)0x0)->GetClass();
      vectorlETStringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETStringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETStringgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TString> : new vector<TString>;
   }
   static void *newArray_vectorlETStringgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<TString>[nElements] : new vector<TString>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETStringgR(void *p) {
      delete ((vector<TString>*)p);
   }
   static void deleteArray_vectorlETStringgR(void *p) {
      delete [] ((vector<TString>*)p);
   }
   static void destruct_vectorlETStringgR(void *p) {
      typedef vector<TString> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TString>

namespace {
  void TriggerDictionaryInitialization_xAODAnaHelpersCINT_Impl() {
    static const char* headers[] = {
"xAODAnaHelpers/ContainerRecording.h",
"xAODAnaHelpers/BasicEventSelection.h",
"xAODAnaHelpers/BJetSelector.h",
"xAODAnaHelpers/ElectronSelector.h",
"xAODAnaHelpers/JetSelector.h",
"xAODAnaHelpers/TrackSelector.h",
"xAODAnaHelpers/MuonSelector.h",
"xAODAnaHelpers/ElectronCalibrator.h",
"xAODAnaHelpers/JetCalibrator.h",
"xAODAnaHelpers/MuonCalibrator.h",
"xAODAnaHelpers/ElectronEfficiencyCorrector.h",
"xAODAnaHelpers/JetHistsAlgo.h",
"xAODAnaHelpers/TrackHistsAlgo.h",
"xAODAnaHelpers/JERShifter.h",
"xAODAnaHelpers/OverlapRemover.h",
"xAODAnaHelpers/Writer.h",
0
    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/RootCoreBin/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.02.05-x86_64-slc6-gcc48-opt/include",
"/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/cmt/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  BasicEventSelection;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  BJetSelector;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  ElectronSelector;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  JetSelector;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  TrackSelector;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  MuonSelector;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  ElectronCalibrator;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  JetCalibrator;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  MuonCalibrator;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  ElectronEfficiencyCorrector;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  JetHistsAlgo;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  TrackHistsAlgo;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  JERShifter;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  OverlapRemover;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  Writer;
class __attribute__((annotate("$clingAutoload$/afs/cern.ch/user/a/abrennan/testarea/CxAODTestFramework/xAODAnaHelpers/Root/LinkDef.h")))  ContainerRecording;
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
  #define ROOTCORE_PACKAGE "xAODAnaHelpers"
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "xAODAnaHelpers/ContainerRecording.h"
#include "xAODAnaHelpers/BasicEventSelection.h"
#include "xAODAnaHelpers/BJetSelector.h"
#include "xAODAnaHelpers/ElectronSelector.h"
#include "xAODAnaHelpers/JetSelector.h"
#include "xAODAnaHelpers/TrackSelector.h"
#include "xAODAnaHelpers/MuonSelector.h"
#include "xAODAnaHelpers/ElectronCalibrator.h"
#include "xAODAnaHelpers/JetCalibrator.h"
#include "xAODAnaHelpers/MuonCalibrator.h"
#include "xAODAnaHelpers/ElectronEfficiencyCorrector.h"
#include "xAODAnaHelpers/JetHistsAlgo.h"
#include "xAODAnaHelpers/TrackHistsAlgo.h"
#include "xAODAnaHelpers/JERShifter.h"
#include "xAODAnaHelpers/OverlapRemover.h"
#include "xAODAnaHelpers/Writer.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"BJetSelector", payloadCode, "@",
"BasicEventSelection", payloadCode, "@",
"ContainerRecording", payloadCode, "@",
"ElectronCalibrator", payloadCode, "@",
"ElectronEfficiencyCorrector", payloadCode, "@",
"ElectronSelector", payloadCode, "@",
"JERShifter", payloadCode, "@",
"JetCalibrator", payloadCode, "@",
"JetHistsAlgo", payloadCode, "@",
"JetSelector", payloadCode, "@",
"MuonCalibrator", payloadCode, "@",
"MuonSelector", payloadCode, "@",
"OverlapRemover", payloadCode, "@",
"TrackHistsAlgo", payloadCode, "@",
"TrackSelector", payloadCode, "@",
"Writer", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("xAODAnaHelpersCINT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_xAODAnaHelpersCINT_Impl, {{"namespace DataVector_detail { template <typename B1, typename B2, typename B3> class VirtBases; }", 1},{"template <typename T> class DataVectorBase;", 1},{"template <typename T, typename BASE> class DataVector;", 1},{"namespace DataVector_detail { template <typename T> class DVLEltBaseInit; }", 1}}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_xAODAnaHelpersCINT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_xAODAnaHelpersCINT() {
  TriggerDictionaryInitialization_xAODAnaHelpersCINT_Impl();
}
