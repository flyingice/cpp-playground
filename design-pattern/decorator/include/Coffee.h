#ifndef COFFEE_H_
#define COFFEE_H_

#include <string>

class Coffee {
 public:
  Coffee() = default;
  virtual ~Coffee() = 0;

  virtual double getPrice() const = 0;
  virtual std::string getIngredients() const = 0;
};

#endif