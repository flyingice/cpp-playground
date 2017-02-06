/*
 * RomainCalculatorTest.cpp
 *
 *  Created on: 26 Jan 2017
 *      Author: yyang
 */

#include "RomainCalculatorTest.h"

using namespace ::testing;

namespace tdd {

RomainCalculatorTest::RomainCalculatorTest(): _calculator(&_mock) {}

RomainCalculatorTest::~RomainCalculatorTest() {}

TEST_F(RomainCalculatorTest, returnIIIWhenIAddII) {
  EXPECT_CALL(_mock, stringToInt("I")).WillOnce(Return(1));
  EXPECT_CALL(_mock, stringToInt("II")).WillOnce(Return(2));
  EXPECT_CALL(_mock, intToString(3)).WillOnce(Return("III"));

  ASSERT_EQ("III", _calculator.add("I", "II"));
}

TEST_F(RomainCalculatorTest, returnIXWhenVIIIAddI) {
//  EXPECT_CALL(_mock, stringToInt(_))
//      .WillOnce(Return(8))
//      .WillOnce(Return(1));
  EXPECT_CALL(_mock, stringToInt(_)).WillOnce(Return(8));
  EXPECT_CALL(_mock, stringToInt(_)).WillOnce(Return(1)).RetiresOnSaturation();

  EXPECT_CALL(_mock, intToString(9)).WillOnce(Return("IX"));

  ASSERT_EQ("IX", _calculator.add("VIII", "I"));
}

}
