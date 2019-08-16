#ifndef READER_FACTORY_H_
#define READER_FACTORY_H_

class Book;
class Reader;

class ReaderFactory {
 public:
  static ReaderFactory& getInstance();
  Reader* createReader(const Book* iBook);

 private:
  ReaderFactory() = default;
  virtual ~ReaderFactory() = default;

  ReaderFactory(const ReaderFactory&);
  ReaderFactory& operator=(const ReaderFactory&);
};

#endif