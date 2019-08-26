#ifndef REQUEST_H_
#define REQUEST_H_

class Request {
 public:
  Request(int l = 0) {
    level = l;
  }

  int getLevel() const {
    return level;
  }

 private:
  int level;
};

#endif