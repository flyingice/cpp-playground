#include <iostream>
#include <string>
using namespace std;

class BufferedWrite {
 public:
  BufferedWrite(ostream& ioStream, int iSize)
      : stream(ioStream), size(iSize + 1), next(0), sentinel(iSize), buffer(new char[size]), cnt(0) {
  }

  virtual ~BufferedWrite() {
    flush();  // important: flush the remaining elements in the buffer
    delete[] buffer;

    cout << endl << "flushed " << cnt << " times" << endl;
  }

  void write(const string& iStr) {
    for (size_t i = 0; i < iStr.size(); i++) {
      if (isFull()) {
        flush();
      }

      buffer[next] = iStr[i];
      next = (next + 1) % size;
    }
  }

  void flush() {
    cnt++;
    while (!isEmpty()) {
      sentinel = (sentinel + 1) % size;
      stream << buffer[sentinel];
    }
  }

 protected:
  bool isFull() const {
    return next == sentinel;
  }

  bool isEmpty() const {
    return (sentinel + 1) % size == next;
  }

 private:
  ostream& stream;
  size_t size;
  size_t next, sentinel;
  char* buffer;

  int cnt;  // debug only: count of flush() method call
};

int main() {
  BufferedWrite aBufferedWrite(cout, 5);
  aBufferedWrite.write("Hello, World!");

  return 0;
}