#include <iostream>
#include <sstream>
using namespace std;

class BufferedWrite {
 public:
  BufferedWrite(ostringstream& oss, int iCapacity) : os(oss), capacity(iCapacity), next(0), buffer(new char[capacity]) {
  }

  virtual ~BufferedWrite() {
  }

  void write(const string& iContent);
  void flush();

 protected:
  bool isBufferFull() const {
    return next >= capacity;
  }

 private:
  ostringstream& os;
  size_t capacity;
  size_t next;
  char* buffer;
};

void BufferedWrite::write(const string& iContent) {
  for (size_t i = 0; i < iContent.size(); i++) {
    if (isBufferFull()) flush();
    buffer[next++] = iContent[i];
  }
}

void BufferedWrite::flush() {
  for (size_t i = 0; i < next; i++) {
    os << buffer[i];
  }

  next = 0;
}

int main() {
  ostringstream os;
  BufferedWrite aBufferedWrite(os, 5);
  aBufferedWrite.write("Hello, World!");
  aBufferedWrite.flush();
  cout << os.str() << endl;

  return 0;
}