/******************************************************************************
 * Copyright (c) 2017 Philipp Schubert.
 * All rights reserved. This program and the accompanying materials are made
 * available under the terms of LICENSE.txt.
 *
 * Contributors:
 *     Philipp Schubert and others
 *****************************************************************************/

/*
 * ICFG.h
 *
 *  Created on: 17.08.2016
 *      Author: pdschbrt
 */

#ifndef ANALYSIS_IFDS_IDE_ICFG_H_
#define ANALYSIS_IFDS_IDE_ICFG_H_

#include <iostream>
#include <json.hpp>
#include <map>
#include <phasar/Config/ContainerConfiguration.h>
#include <phasar/PhasarLLVM/ControlFlow/CFG.h>
#include <set>
#include <string>
#include <vector>
using json = nlohmann::json;

namespace psr {

enum class CallGraphAnalysisType { CHA, RTA, DTA, VTA, OTF };

extern const std::map<std::string, CallGraphAnalysisType>
    StringToCallGraphAnalysisType;

extern const std::map<CallGraphAnalysisType, std::string>
    CallGraphAnalysisTypeToString;

std::ostream &operator<<(std::ostream &os, const CallGraphAnalysisType &CGA);

template <typename N, typename M> class ICFG : public CFG<N, M> {
public:
  virtual ~ICFG() = default;

  virtual bool isCallStmt(N stmt) = 0;

  virtual M getMethod(const std::string &fun) = 0;

  virtual std::set<N> allNonCallStartNodes() = 0;

  virtual std::set<M> getCalleesOfCallAt(N stmt) = 0;

  virtual std::set<N> getCallersOf(M fun) = 0;

  virtual std::set<N> getCallsFromWithin(M fun) = 0;

  virtual std::set<N> getStartPointsOf(M fun) = 0;

  virtual std::set<N> getExitPointsOf(M fun) = 0;

  virtual std::set<N> getReturnSitesOfCallAt(N stmt) = 0;

  virtual json getAsJson() = 0;
};

} // namespace psr

#endif /* ANALYSIS_ICFG_HH_ */
