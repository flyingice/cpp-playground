#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

/* 
 * Note that CTRL+D on Unix/Linux is a signal to shell indicating 
 * the end of input. There is no so-called EOF character at all.
 * CTRL+D at the end of a line will flush the buffer only, as the Enter.
 * Only the CTRL+D at the beginning is recoginized as the signal indicating
 * the end of input.
 */
void getValidInteger(istream& is, ostream& os) {
  int n;
  // input stream is not valid as long as at least one of the eof/fail/bad flags is on
  while(os << "Please enter an integer: " << endl && !(is >> n) && !is.eof()) {
    if(is.fail()) {
      // set iostate to istream::goodbit 
      // setstate() turns on/off a certain bit flag while the clear() overwrites the bit flag with the parameter value 
      is.clear();
      // ignore the data in the buffer
      is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if(is.bad()) { // unrecoverable error
      return;
    }
  }

  os << n << endl;
}

void bufferControl() {
  cout << "flushes the buffer without adding any data\n" << flush;
  cout << "inserts a null and then flushes the buffer\n" << ends;
  cout << "inserts a new line, then flushes the buffer" << endl;
  cout << unitbuf << "flushes at every output operation\n" << nounitbuf;
}

ifstream& openFile(ifstream& in, const string& fileName) {
  in.close(); // in case it is already open. However, close() will not clear the error status itself
  in.clear(); // clear any existing errors
  in.open(fileName);
  return in;
}

void readFromStringStreamUsingGet(const string& str) {
  istringstream is(str);

  char c;
  while(is.get(c)) {
    cout << c;
  }
  cout << endl;
}

void readFromStringStreamUsingGetLine(const string& str) {
  istringstream is(str);

  string line;
  // getline(stream, string, delimeter='\n')
  while(getline(is, line)) {
    cout << line << endl;
  }
}

int main() {
  return 0;
}
