#include "Coffee.h"

// Even the destructor is declared as pure virtual, an implementation is still required.
// Otherwise, the error of unreferenced symbol is raised.
Coffee::~Coffee() {
}