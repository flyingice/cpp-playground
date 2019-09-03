#ifndef STATE_IDLE_H_
#define STATE_IDLE_H_

#include <iostream>
#include <string>
#include "State.h"
#include "VendingMachine.h"

class StateIdle : public State {
 public:
  StateIdle(VendingMachine* iVendingMachine) : State(iVendingMachine) {
  }

  ~StateIdle() {
  }

  void selectItem(const std::string& selection) {
    vendingMachine->setSelectedItem(selection);
    vendingMachine->changeToStateItemSelected();
  }

  void insertMoney(int value) {
    std::cout << "Please select item" << std::endl;
  }

  void executeTransaction() {
    std::cout << "Please select item" << std::endl;
  }

  int cancelTransaction() {
    std::cout << "You don't have inserted coins" << std::endl;
    return 0;
  }

  std::string description() const {
    return "idle";
  }
};

#endif