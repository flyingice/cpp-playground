#ifndef STATE_ITEM_SELECTED_H_
#define STATE_ITEM_SELECTED_H_

#include <iostream>
#include <string>
#include "State.h"
#include "VendingMachine.h"

class StateItemSelected : public State {
 public:
  StateItemSelected(VendingMachine* iVendingMachine) : State(iVendingMachine) {
  }

  ~StateItemSelected() {
  }

  void selectItem(const std::string& selection) {
    vendingMachine->setSelectedItem(selection);
    vendingMachine->changeToStateItemSelected();
  }

  void insertMoney(int value) {
    vendingMachine->addMoney(value);
    vendingMachine->changeToStateMoneyInserted();
  }

  void executeTransaction() {
    std::cout << "Please insert money" << std::endl;
  }

  int cancelTransaction() {
    std::cout << "You don't have inserted coins" << std::endl;
    return 0;
  }

  std::string description() const {
    return "item selected";
  }
};

#endif