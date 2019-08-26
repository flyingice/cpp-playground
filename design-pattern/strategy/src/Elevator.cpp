#include "Elevator.h"

std::string writeVector(const std::vector<bool>& v) {
  std::string res;
  for(auto e: v) {
    res += (e ? "1, " : "0, ");
  }
  return res;
}

Elevator::Elevator(int n) {
  status = IDLE;
  for (int i = 0; i < n; ++i) {
    upStops.push_back(false);
    downStops.push_back(false);
  }
}

void Elevator::insertButton(ElevatorButton eb) {
  buttons.push_back(eb);
}

void Elevator::handleExternalRequest(ExternalRequest r) {
  if (r.getDirection() == _UP) {
    upStops[r.getLevel() - 1] = true;
    if (noRequests(downStops)) {
      status = UP;
    }
  }
  else {
    downStops[r.getLevel() - 1] = true;
    if (noRequests(upStops)) {
      status = DOWN;
    }
  }
}

void Elevator::handleInternalRequest(InternalRequest r) {
  // check valid
  if (status == UP) {
    if (r.getLevel() >= currLevel + 1) {
      upStops[r.getLevel() - 1] = true;
    }
  }
  else if (status == DOWN) {
    if (r.getLevel() <= currLevel + 1) {
      downStops[r.getLevel() - 1] = true;
    }
  }
}

void Elevator::openGate() {
  if (status == UP) {
    for (int i = 0; i < upStops.size(); i++) {
      int checkLevel = (currLevel + i) % upStops.size();
      if (upStops[checkLevel]) {
        currLevel = checkLevel;
        upStops[checkLevel] = false;
        break;
      }
    }
  }
  else if (status == DOWN) {
    for (int i = 0; i < downStops.size(); i++) {
      int checkLevel = (currLevel + downStops.size() - i) % downStops.size();
      if (downStops[checkLevel]) {
        currLevel = checkLevel;
        downStops[checkLevel] = false;
        break;
      }
    }
  }
}

void Elevator::closeGate() {
  if (status == IDLE) {
    if (noRequests(downStops)) {
      status = UP;
      return;
    }
    if (noRequests(upStops)) {
      status = DOWN;
      return;
    }
  }
  else if (status == UP) {
    if (noRequests(upStops)) {
      if (noRequests(downStops)) {
        status = IDLE;
      }
      else
        status = DOWN;
    }
  }
  else {
    if (noRequests(downStops)) {
      if (noRequests(upStops)) {
        status = IDLE;
      }
      else
        status = UP;
    }
  }
}

bool Elevator::noRequests(std::vector<bool>& stops) const {
  for (int i = 0; i < stops.size(); i++) {
    if (stops[i]) {
      return false;
    }
  }
  return true;
}

std::string Elevator::elevatorStatusDescription() const {
  std::string status_;
  if (status == UP) {
    status_ = "UP";
  }
  else if (status == DOWN) {
    status_ = "DOWN";
  }
  else if (status == IDLE) {
    status_ = "IDLE";
  }
  std::string description =
      "Currently elevator status is : " + status_ + ".\nCurrent level is at: " + std::to_string(currLevel + 1)
      + ".\nup stop list looks like: " + writeVector(upStops)
      + ".\ndown stop list looks like:  " + writeVector(downStops) + ".\n*****************************************\n";
  return description;
}