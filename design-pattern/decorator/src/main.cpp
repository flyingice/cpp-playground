#include <iostream>
#include <string>
#include "Coffee.h"
#include "CoffeeWithMilk.h"
#include "CoffeeWithSprinkle.h"
#include "SimpleCoffee.h"

void print(const Coffee* coffee) {
  std::cout << "coffee price: " << coffee->getPrice() << " euros, ingredients: " << coffee->getIngredients()
            << std::endl;
}

int main() {
  SimpleCoffee* coffee = new SimpleCoffee();
  print(coffee);

  CoffeeWithMilk* coffeeWithMilk = new CoffeeWithMilk(coffee);
  print(coffeeWithMilk);

  CoffeeWithSprinkle* coffeeWithSprinkle = new CoffeeWithSprinkle(coffee);
  print(coffeeWithSprinkle);

  return 0;
}