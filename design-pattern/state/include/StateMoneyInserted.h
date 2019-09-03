#ifndef STATE_MONEY_INSERTED_H_
#define STATE_MONEY_INSERTED_H_

#include <iostream>
#include <string>
#include "State.h"
#include "VendingMachine.h"

class StateMoneyInserted : public State {
 public:
  StateMoneyInserted(VendingMachine* iVendingMachine) : State(iVendingMachine) {
  }

  ~StateMoneyInserted() {
  }

  void selectItem(const std::string& selection) {
    std::cout << "Please cancel the transaction first" << std::endl;
  }

  void insertMoney(int value) {
    vendingMachine->addMoney(value);
    vendingMachine->changeToStateMoneyInserted();
  }

  void executeTransaction() {
    if (vendingMachine->getInsertedMoney() >= vendingMachine->getSalePrice()) {
      vendingMachine->changeToStateIdle();
      vendingMachine->emptyMoney();
      vendingMachine->clearSelectedItem();
    }
    else {
      std::cout << "Please insert more money" << std::endl;
    }
  }

  int cancelTransaction() {
    int res = vendingMachine->getInsertedMoney();
    vendingMachine->emptyMoney();
    vendingMachine->changeToStateIdle();
    return res;
  }

  std::string description() const {
    return "money inserted";
  }
};

#endif