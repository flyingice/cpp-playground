/*
 * ContactServieImplTest.h
 *
 *  Created on: 6 Feb 2017
 *      Author: yyang
 */

#ifndef _CONTACTSERVIEIMPLTEST_H_
#define _CONTACTSERVIEIMPLTEST_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ContactServiceImpl.h"
#include "ContactDAOMock.h"

namespace contactbook {

class ContactServiceImplTest: public ::testing::Test {
 public:
  ContactServiceImplTest(): _impl(&_mock) {}
  ~ContactServiceImplTest() {}

  ContactDAOMock _mock;
  ContactServiceImpl _impl;
};

}

#endif
