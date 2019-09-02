#include "CoffeeDecorator.h"

CoffeeDecorator::~CoffeeDecorator(){};

double CoffeeDecorator::getPrice() const {
  return coffee->getPrice();
}

std::string CoffeeDecorator::getIngredients() const {
  return coffee->getIngredients();
}