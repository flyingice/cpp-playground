#include "Common.h"
#include "ElevatorSystem.h"
#include "ExternalRequest.h"
#include "StrategyNormalHour.h"
#include "StrategyPeakHour.h"

int main() {
  ElevatorSystem system(2, 10);

  system.setStrategy(new StrategyNormalHour());
  system.handleRequest(ExternalRequest(3, _UP));

  system.setStrategy(new StrategyPeakHour());
  system.handleRequest(ExternalRequest(5, _DOWN));

  return 0;
}