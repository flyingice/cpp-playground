#ifndef BOOK_H_
#define BOOK_H_

#include <string>

class Book {
 public:
  explicit Book(const std::string& iFormat);
  virtual ~Book() = default;

  std::string getFormat() const;

 private:
  std::string format;
};

#endif