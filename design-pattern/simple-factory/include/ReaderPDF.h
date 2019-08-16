#ifndef READER_PDF_H_
#define READER_PDF_H_

#include "Reader.h"

class ReaderPDF : public Reader {
 public:
  ReaderPDF() = default;
  virtual ~ReaderPDF() = default;

  virtual void display();
};

#endif