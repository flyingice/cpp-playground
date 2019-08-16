#include "Book.h"

Book::Book(const std::string& iFormat) : format(iFormat) {
}

std::string Book::getFormat() const {
  return format;
}