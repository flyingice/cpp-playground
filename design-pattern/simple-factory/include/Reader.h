#ifndef READER_H_
#define READER_H_

class Reader {
 public:
  Reader() = default;
  virtual ~Reader() = default;

  virtual void display() = 0;
};

#endif