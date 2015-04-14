// Dear emacs, this is -*-c++-*-
#ifndef CxAODMaker_ObjectHandlerBase_H
#define CxAODMaker_ObjectHandlerBase_H

#include <vector>
#include <TString.h>

// infrastucture includes
#include "EventLoop/StatusCode.h"
#include "PATInterfaces/SystematicRegistry.h"


class ObjectHandlerBase {

public:

  /**
   * @brief Destructor.
   */
  virtual ~ObjectHandlerBase() {;}

  /**
   * @brief Retrieve physics objects from event.
   * @return Status code.
   */
  virtual EL::StatusCode setObjects() = 0;

  /**
   * @brief Calibration/selection/... tools are initialized.
   * @return Status code.
   */
  virtual EL::StatusCode initializeTools() = 0;
  
  /**
   * @brief Get the name of this handler.
   * @return The name.
   */
  virtual const std::string& name() const = 0;

  /**
   * @brief Add systematic variations.
   * @return Status code.
   */
  virtual EL::StatusCode addCPVariations(const std::vector<TString> &variations) = 0;

  /**
   * @brief Get all variations that affect this handler.
   * @return The list of all systematics
   * 
   * This includes "Nominal" if requested and "Original" if available .
   */
  virtual std::vector<TString> getAllVariations(bool includeNominal = true) = 0;

  /**
   * @brief Print all CP variations.
   * 
   * Print all variations to be run on in this handler and those available
   * in the registered ISystematicTools.
   */
  virtual void printAllVariations() = 0;

  /**
   * @brief Calibrate physics objects.
   * @return Status code.
   */
  virtual EL::StatusCode calibrate() = 0;

  /**
   * @brief Run selection on physics objects.
   * @return Status code.
   */
  virtual EL::StatusCode select() = 0;

  /**
   * @brief Copy selected physics objects to output container.
   * @return Status code.
   */
  virtual EL::StatusCode fillOutputContainer() = 0;

  /**
   * @brief Delete any owned objects created during the event.
   * @return Status code.
   */
  virtual EL::StatusCode clearEvent() = 0;

  /**
   * @brief count size of physics objects.
   * @return Status code.
   *
   * count the size of the input/output containers
   */
  virtual void countObjects() = 0;

  /**
   * @brief print the counted physics objects.
   * @return Status code.
   *
   * print the total size of the input/output containers
   */
  virtual void printObjectCounts() = 0;

};

#endif
