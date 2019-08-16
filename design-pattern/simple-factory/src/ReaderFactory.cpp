#include "ReaderFactory.h"
#include "Book.h"
#include "ReaderEPub.h"
#include "ReaderMobi.h"
#include "ReaderPDF.h"

ReaderFactory& ReaderFactory::getInstance() {
  static ReaderFactory instance;
  return instance;
}

Reader* ReaderFactory::createReader(const Book* iBook) {
  Reader* reader = nullptr;
  if (iBook->getFormat() == "pdf") {
    reader = new ReaderPDF();
  }
  else if (iBook->getFormat() == "mobi") {
    reader = new ReaderMobi();
  }
  else if (iBook->getFormat() == "epub") {
    reader = new ReaderEPub();
  }

  return reader;
}
