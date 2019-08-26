#ifndef ELEVATOR_H_
#define ELEVATOR_H_

#include <string>
#include <vector>
#include "Common.h"
#include "ElevatorButton.h"
#include "ExternalRequest.h"
#include "InternalRequest.h"

class Elevator {
 public:
  Elevator(int n);
  void insertButton(ElevatorButton eb);
  void handleExternalRequest(ExternalRequest r);
  void handleInternalRequest(InternalRequest r);
  void openGate();
  void closeGate();
  bool noRequests(std::vector<bool>& stops) const;
  std::string elevatorStatusDescription() const;

 private:
  std::vector<ElevatorButton> buttons;
  std::vector<bool> upStops;
  std::vector<bool> downStops;
  int currLevel;
  Status status;
};

#endif