/*
 * ContactServiceImplTest.cpp
 *
 *  Created on: 6 Feb 2017
 *      Author: yyang
 */

#include "ContactServiceImplTest.h"

namespace contactbook {

using namespace ::testing;

TEST_F(ContactServiceImplTest, shouldReturnMatchingcontactWhengetById) {
  EXPECT_CALL(_mock, getById(1)).WillOnce(Return(ContactBuilder::JESSIE_JAMES));
  EXPECT_CALL(_mock, getById(2)).WillOnce(Return(ContactBuilder::JESSIE_KISSINGER));

  _impl.createContact(ContactBuilder::JESSIE_JAMES.getFirstName(), ContactBuilder::JESSIE_JAMES.getLastName());
  _impl.createContact(ContactBuilder::JESSIE_KISSINGER.getFirstName(), ContactBuilder::JESSIE_KISSINGER.getLastName());

  EXPECT_EQ(ContactBuilder::JESSIE_JAMES, _impl.getById(1));
  EXPECT_EQ(ContactBuilder::JESSIE_KISSINGER, _impl.getById(2));
}

}

