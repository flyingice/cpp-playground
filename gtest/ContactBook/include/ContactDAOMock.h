/*
 * ContactDAOMock.h
 *
 *  Created on: 6 Feb 2017
 *      Author: yyang
 */

#ifndef _CONTACTDAOMOCK_H_
#define _CONTACTDAOMOCK_H_

#include <gmock/gmock.h>

#include "ContactDAO.h"

namespace contactbook {

using namespace ::testing;

class ContactDAOMock : public ContactDAO {

public:
  ContactDAOMock() {}
  ~ContactDAOMock() {}

  MOCK_METHOD0(findAll, std::vector<Contact>());
  MOCK_METHOD1(getById, Contact(int));
  MOCK_METHOD1(getByMatchingString, std::vector<Contact>(std::string));
  MOCK_METHOD1(createContact, void(Contact));
  MOCK_METHOD0(nextID, int());
};

}

#endif
