#ifndef ELEVATORSYSTEM_H_
#define ELEVATORSYSTEM_H_

#include <vector>
#include "ExternalRequest.h"

class Elevator;
class Strategy;

class ElevatorSystem {
 public:
  ElevatorSystem(int n, int m);  // n elevators serving m floors
  void handleRequest(ExternalRequest request);
  void setStrategy(Strategy* s);

 private:
  std::vector<Elevator*> elevators;
  Strategy* strategy;
};

#endif