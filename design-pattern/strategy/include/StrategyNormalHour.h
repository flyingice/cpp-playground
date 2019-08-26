#ifndef STRATEGY_NORMAL_HOUR_H_
#define STRATEGY_NORMAL_HOUR_H_

#include "Elevator.h"
#include "ExternalRequest.h"
#include "Strategy.h"

#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>

class StrategyNormalHour : public Strategy {
 public:
  StrategyNormalHour() {
    std::srand(std::time(nullptr));
  }
  virtual ~StrategyNormalHour() = default;

  void handleRequest(ExternalRequest request, std::vector<Elevator*> elevators) {
    std::cout << "scheduling elevators during normal hours..." << std::endl;
    elevators[std::rand() % elevators.size()]->handleExternalRequest(request);
  }
};

#endif
