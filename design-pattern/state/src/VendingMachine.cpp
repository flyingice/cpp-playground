#include "VendingMachine.h"
#include <iostream>
#include "State.h"
#include "StateIdle.h"
#include "StateItemSelected.h"
#include "StateMoneyInserted.h"

VendingMachine::VendingMachine()
    : stateIdle(new StateIdle(this)),
      stateItemSelected(new StateItemSelected(this)),
      stateMoneyInserted(new StateMoneyInserted(this)) {
  itemPrice["Coke"] = 100;
  itemPrice["Sprite"] = 200;
  itemPrice["Mirinda"] = 300;

  changeToStateIdle();
};

VendingMachine::~VendingMachine() {
  delete stateIdle;
  delete stateItemSelected;
  delete stateMoneyInserted;
};

void VendingMachine::setSelectedItem(const std::string& label) {
  currentItem = label;
}

std::string VendingMachine::getSelectedItem() const {
  return currentItem;
}

void VendingMachine::clearSelectedItem() {
  currentItem.clear();
}

void VendingMachine::addMoney(int amount) {
  currentMoney += amount;
}

int VendingMachine::getInsertedMoney() const {
  return currentMoney;
}

void VendingMachine::emptyMoney() {
  currentMoney = 0;
}

int VendingMachine::getSalePrice() const {
  if (!currentItem.empty()) {
    return itemPrice.at(currentItem);
  }

  return 0;
}

void VendingMachine::changeToStateIdle() {
  setCurrentState(stateIdle);
}

void VendingMachine::changeToStateItemSelected() {
  setCurrentState(stateItemSelected);
}

void VendingMachine::changeToStateMoneyInserted() {
  setCurrentState(stateMoneyInserted);
}

void VendingMachine::printState() const {
  std::cout << "Current selection is: " << currentItem << ", current inserted money: " << currentMoney
            << ", current state is : " << currentState->description() << std::endl;
}

void VendingMachine::selectItem(const std::string& selection) {
  currentState->selectItem(selection);
}

void VendingMachine::insertMoney(int amount) {
  currentState->insertMoney(amount);
}

void VendingMachine::executeTransaction() {
  currentState->executeTransaction();
}

int VendingMachine::cancelTransaction() {
  return currentState->cancelTransaction();
}

void VendingMachine::setCurrentState(State* iState) {
  currentState = iState;
}
