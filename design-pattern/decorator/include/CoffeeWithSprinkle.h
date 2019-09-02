#ifndef COFFEE_WITH_SPRINKLE_H_
#define COFFEE_WITH_SPRINKLE_H_

#include <string>
#include "Coffee.h"
#include "CoffeeDecorator.h"

class CoffeeWithSprinkle : public CoffeeDecorator {
 public:
  CoffeeWithSprinkle(Coffee* iCoffee) : CoffeeDecorator(iCoffee) {
  }

  ~CoffeeWithSprinkle() = default;

  double getPrice() const {
    return CoffeeDecorator::getPrice() + 2.0;
  }

  std::string getIngredients() const {
    return CoffeeDecorator::getIngredients() + " with sprinkle";
  }
};

#endif