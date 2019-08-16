#ifndef READER_EPUB_H_
#define READER_EPUB_H_

#include "Reader.h"

class ReaderEPub : public Reader {
 public:
  ReaderEPub() = default;
  virtual ~ReaderEPub() = default;

  virtual void display();
};

#endif