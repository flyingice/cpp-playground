#include "ElevatorSystem.h"
#include "Elevator.h"
#include "Strategy.h"

ElevatorSystem::ElevatorSystem(int n, int m) {
  for (int i = 0; i < n; i++) {
    elevators.push_back(new Elevator(m));
  }
}

void ElevatorSystem::handleRequest(ExternalRequest request) {
  strategy->handleRequest(request, elevators);
}

void ElevatorSystem::setStrategy(Strategy* s) {
  strategy = s;
}