#ifndef _CONTACTSERVICE_H_
#define _CONTACTSERVICE_H_

#include <vector>
#include <string>

#include "Contact.h"

namespace contactbook {

class ContactService {
public :
    virtual std::vector<Contact> searchBy(std::string searchString) = 0;

    virtual std::vector<Contact> listAllContacts() = 0;

    virtual Contact getById(int contactId) const = 0;

    virtual Contact createContact(std::string firstName, std::string lastName) = 0;// throws DuplicatedContactException;

};

} /* namespace contactbook */

#endif
