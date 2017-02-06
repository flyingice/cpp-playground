#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <string>

namespace contactbook {

class Contact {
    int _id;
    std::string _firstName;
    std::string _lastName;
 public:
    int getId() const;

    std::string getFirstName() const;

    std::string getLastName() const;

    bool operator== (const Contact& c) const;

    Contact(int id, std::string firstName, std::string lastName);

};

class ContactBuilder {

public :
    static const Contact JESSIE_JAMES;
    static const Contact JESSIE_KISSINGER;
    static const Contact AMY_KISSINGER;
    static const Contact AMY_JAMES;
    static const Contact UNKNOWN;

};

} /* namespace contactbook */

#endif 
