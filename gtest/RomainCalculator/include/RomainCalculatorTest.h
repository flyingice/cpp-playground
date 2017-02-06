/*
 * RomainCalculatorTest.h
 *
 *  Created on: 26 Jan 2017
 *      Author: yyang
 */

#ifndef TEST_INCLUDE_ROMAINCALCULATORTEST_H_
#define TEST_INCLUDE_ROMAINCALCULATORTEST_H_

#include "RomainCalculator.h"
#include "RomainConverterMock.h"

namespace tdd {

class RomainCalculatorTest: public ::testing::Test {

 public:
  RomainCalculatorTest();
  ~RomainCalculatorTest();

  RomainCalculator _calculator;
  RomainConverterMock _mock;
};

}


#endif /* TEST_INCLUDE_ROMAINCALCULATORTEST_H_ */
