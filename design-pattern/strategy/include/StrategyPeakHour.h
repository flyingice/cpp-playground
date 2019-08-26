#ifndef STRATEGY_PEAK_HOUR_H_
#define STRATEGY_PEAK_HOUR_H_

#include "ExternalRequest.h"
#include "Strategy.h"

#include <iostream>

class StrategyPeakHour : public Strategy {
 public:
  StrategyPeakHour() = default;
  virtual ~StrategyPeakHour() = default;

  void handleRequest(ExternalRequest request, std::vector<Elevator*> elevators) {
    std::cout << "scheduling elevators during peak hours..." << std::endl;
    elevators[0]->handleExternalRequest(request);
  }
};

#endif
