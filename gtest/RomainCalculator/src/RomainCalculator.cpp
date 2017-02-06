#include "RomainCalculator.h"

namespace tdd {

RomainCalculator::RomainCalculator(RomainConverter* rc) : _converter(rc) {}

RomainCalculator::~RomainCalculator() {}

string RomainCalculator::add(const string& left, const string& right) const {
  int leftValue = _converter->stringToInt(left);
  int rightValue = _converter->stringToInt(right);

  return _converter->intToString(leftValue + rightValue);
}

string RomainCalculator::substract(const string& left, const string& right) const {
  return "";
}

}
