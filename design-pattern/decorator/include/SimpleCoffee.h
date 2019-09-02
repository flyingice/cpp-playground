#ifndef SIMPLE_COFFEE_H_
#define SIMPLE_COFFEE_H_

#include <string>
#include "Coffee.h"

class SimpleCoffee : public Coffee {
 public:
  SimpleCoffee() = default;
  ~SimpleCoffee() = default;

  double getPrice() const {
    return 3.0;
  }

  std::string getIngredients() const {
    return "Coffee";
  }
};

#endif