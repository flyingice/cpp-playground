#ifndef _ROMAIN_CALCULATOR_
#define _ROMAIN_CALCULATOR_

#include "RomainConverter.h"
#include <string>

using std::string;

namespace tdd {

class RomainCalculator {
public:
  RomainCalculator(RomainConverter* rc);
  ~RomainCalculator();

  string add(const string& left, const string& right) const ;
  string substract(const string& left, const string& right) const;

private:
  RomainConverter* _converter;
};

}

#endif
