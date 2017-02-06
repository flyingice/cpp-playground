#ifndef _CONTACTSERVICEIMPL_H_
#define _CONTACTSERVICEIMPL_H_

#include "ContactService.h"

namespace contactbook {

class ContactDAO;

class ContactServiceImpl: public ContactService {

public :
  ContactServiceImpl(ContactDAO* p);
  ~ContactServiceImpl();

    virtual std::vector<Contact> searchBy(std::string searchString);
    virtual std::vector<Contact> listAllContacts();
    virtual Contact getById(int contactId) const;
    virtual Contact createContact(std::string firstName, std::string lastName); // throws DuplicatedContactException;

private:
    ContactDAO* _book;
};

}

#endif
