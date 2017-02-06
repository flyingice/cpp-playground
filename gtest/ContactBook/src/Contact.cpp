#include "Contact.h"

namespace contactbook {

const Contact ContactBuilder::JESSIE_JAMES(1, "Jessie", "James");
const Contact ContactBuilder::JESSIE_KISSINGER(2, "Jessie", "Kissinger");
const Contact ContactBuilder::AMY_KISSINGER(3, "Amy", "Kissinger");
const Contact ContactBuilder::AMY_JAMES(4, "Amy", "James");
const Contact ContactBuilder::UNKNOWN(-1, "Unknown", "Buddy");

int Contact::getId() const {
    return _id;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

bool Contact::operator== (const Contact& c) const {
    return _id == c._id;
}

Contact::Contact(int id, std::string firstName, std::string lastName) {
    _id = id;
    _firstName = firstName;
    _lastName = lastName;
}

} /* namespace contactbook */
