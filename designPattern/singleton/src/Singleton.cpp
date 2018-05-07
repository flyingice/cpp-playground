#include "Singleton.h"
#include <stdexcept>

bool Singleton::_isDestroyed = false;

Singleton& Singleton::GetInstance() {
  // Meyers' singleton
  // the local static variable initialization is thread-safe since C++11
  static Singleton instance;

  if(_isDestroyed) OnDeadReference();
  return instance;
}

void Singleton::OnDeadReference() {
  throw std::runtime_error("dead reference detected");
}
