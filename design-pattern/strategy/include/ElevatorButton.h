#ifndef ELEVATOR_BUTTON_H_
#define ELEVATOR_BUTTON_H_

class Elevator;

class ElevatorButton {
 public:
  ElevatorButton(int level, Elevator* e) {
    this->level = level;
    this->elevator = e;
  }

  void pressButton();

 private:
  int level;
  Elevator* elevator;
};

#endif