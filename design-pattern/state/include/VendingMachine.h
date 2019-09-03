#ifndef VENDING_MACHINE_H_
#define VENDING_MACHINE_H_

#include <string>
#include <unordered_map>

class State;

class VendingMachine {
 public:
  VendingMachine();
  ~VendingMachine();

  void setSelectedItem(const std::string& label);
  std::string getSelectedItem() const;
  void clearSelectedItem();
  void addMoney(int amount);
  int getInsertedMoney() const;
  void emptyMoney();
  int getSalePrice() const;

  void changeToStateIdle();
  void changeToStateItemSelected();
  void changeToStateMoneyInserted();
  void printState() const;

  void selectItem(const std::string& selection);
  void insertMoney(int amount);
  void executeTransaction();
  int cancelTransaction();

 private:
  void setCurrentState(State* state);

  std::unordered_map<std::string, int> itemPrice;
  std::string currentItem;
  int currentMoney;
  State* currentState;
  State* stateIdle;
  State* stateItemSelected;
  State* stateMoneyInserted;
};

#endif