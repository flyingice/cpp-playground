#ifndef INTERNAL_REQUEST_H_
#define INTERNAL_REQUEST_H_

class InternalRequest : public Request {
 public:
  InternalRequest(int l = 0) : Request(l) {
  }
};

#endif