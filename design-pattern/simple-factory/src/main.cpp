#include <vector>

#include "Book.h"
#include "Reader.h"
#include "ReaderFactory.h"
using namespace std;

int main() {
  vector<Book*> books = { new Book("pdf"), new Book("mobi"), new Book("epub") };
  vector<Reader*> readers;
  for (auto book : books) {
    readers.push_back(ReaderFactory::getInstance().createReader(book));
  }

  for (auto reader : readers) {
    reader->display();
  }

  return 0;
}