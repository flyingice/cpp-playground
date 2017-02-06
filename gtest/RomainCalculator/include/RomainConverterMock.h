/*
 * RomainConverterMock.h
 *
 *  Created on: 26 Jan 2017
 *      Author: yyang
 */

#ifndef TEST_INCLUDE_ROMAINCONVERTERMOCK_H_
#define TEST_INCLUDE_ROMAINCONVERTERMOCK_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "RomainConverter.h"

namespace tdd {

class RomainConverterMock: public RomainConverter {
 public:
  MOCK_CONST_METHOD1(intToString, string(int));
  MOCK_CONST_METHOD1(stringToInt, int(const string&));
 private:
};

}



#endif /* TEST_INCLUDE_ROMAINCONVERTERMOCK_H_ */
