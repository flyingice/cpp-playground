#ifndef _ROMAIN_CONVERTER_H_
#define _ROMAIN_CONVERTER_H_

#include <string>

namespace tdd {

using std::string;

class RomainConverter {
 public:
  RomainConverter() {};
  ~RomainConverter() {};

  virtual int stringToInt(const string&) const = 0;
  virtual string intToString(int) const = 0;

 private:

};

}

#endif
