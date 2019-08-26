#ifndef STRATEGY_H_
#define STRATEGY_H_

class Elevator;
class ExternalRequest;

#include <vector>

class Strategy {
 public:
  Strategy() = default;
  virtual ~Strategy() = default;

  virtual void handleRequest(ExternalRequest request, std::vector<Elevator*> elevators) = 0;
};

#endif