#ifndef COFFEE_WITH_MILK_H_
#define COFFEE_WITH_MILK_H_

#include <string>
#include "Coffee.h"
#include "CoffeeDecorator.h"

class CoffeeWithMilk : public CoffeeDecorator {
 public:
  CoffeeWithMilk(Coffee* iCoffee) : CoffeeDecorator(iCoffee) {
  }

  ~CoffeeWithMilk() = default;

  double getPrice() const {
    return CoffeeDecorator::getPrice() + 1.0;
  }

  std::string getIngredients() const {
    return CoffeeDecorator::getIngredients() + " with milk";
  }
};

#endif