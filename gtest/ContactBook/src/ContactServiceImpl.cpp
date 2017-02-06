/*
 * ContactServiceImpl.cpp
 *
 *  Created on: 6 Feb 2017
 *      Author: yyang
 */


#include "ContactServiceImpl.h"
#include "Contact.h"
#include "ContactDAO.h"

namespace contactbook {

ContactServiceImpl::ContactServiceImpl(ContactDAO* p): _book(p) {
}

ContactServiceImpl::~ContactServiceImpl() {
}

Contact ContactServiceImpl::createContact(std::string firstName, std::string lastName) {
  Contact contact(_book->nextID(), firstName, lastName);
  _book->createContact(contact);

  return contact;
}

std::vector<Contact> ContactServiceImpl::searchBy(std::string searchString) {
  return _book->getByMatchingString(searchString);
}


std::vector<Contact> ContactServiceImpl::listAllContacts() {
  return _book->findAll();
}

Contact ContactServiceImpl::getById(int contactId) const {
  return _book->getById(contactId);
}

}

