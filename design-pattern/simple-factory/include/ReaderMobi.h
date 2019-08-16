#ifndef READER_MOBI_H_
#define READER_MOBI_H_

#include "Reader.h"

class ReaderMobi : public Reader {
 public:
  ReaderMobi() = default;
  virtual ~ReaderMobi() = default;

  virtual void display();
};

#endif