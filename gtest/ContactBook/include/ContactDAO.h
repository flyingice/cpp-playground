#ifndef _CONTACTDAO_H_
#define _CONTACTDAO_H_

#include <string>
#include <vector>

#include "Contact.h"

namespace contactbook {

class ContactDAO {
public :
    virtual ~ContactDAO() {}

    virtual std::vector<Contact> findAll() = 0;

    virtual Contact getById(int id) = 0;

    virtual std::vector<Contact> getByMatchingString(std::string string) = 0;

    virtual void createContact(Contact contact) = 0;

    virtual int nextID() = 0;
};

} /* namespace contactbook */

#endif
