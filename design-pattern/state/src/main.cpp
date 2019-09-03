#include "VendingMachine.h"

int main() {
  VendingMachine vendingMachine;

  vendingMachine.selectItem("Coke");
  vendingMachine.printState();
  vendingMachine.insertMoney(50);
  vendingMachine.printState();
  vendingMachine.executeTransaction();
  vendingMachine.printState();

  return 0;
}