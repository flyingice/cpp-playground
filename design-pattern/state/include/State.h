#ifndef STATE_H_
#define STATE_H_

#include <string>

class VendingMachine;

class State {
 public:
  State(VendingMachine* iVendingMachine);
  virtual ~State() = 0;

  virtual void selectItem(const std::string& selection) = 0;
  virtual void insertMoney(int value) = 0;
  virtual void executeTransaction() = 0;
  virtual int cancelTransaction() = 0;

  virtual std::string description() const = 0;

 protected:
  VendingMachine* vendingMachine;
};

#endif