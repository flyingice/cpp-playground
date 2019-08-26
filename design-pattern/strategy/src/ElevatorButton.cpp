#include "ElevatorButton.h"
#include "Elevator.h"
#include "InternalRequest.h"

void ElevatorButton::pressButton() {
  InternalRequest request = InternalRequest(level);
  elevator->handleInternalRequest(request);
}