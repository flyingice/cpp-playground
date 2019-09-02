#ifndef COFFEE_DECORATOR_H_
#define COFFEE_DECORATOR_H_

#include <string>
#include "Coffee.h"

class CoffeeDecorator : public Coffee {
 public:
  CoffeeDecorator(Coffee* iCoffee) : coffee(iCoffee) {
  }

  virtual ~CoffeeDecorator() = 0;

  virtual double getPrice() const;

  virtual std::string getIngredients() const;

 protected:
  Coffee* const coffee;  // to whom the decorator (accessory) is added
};

#endif