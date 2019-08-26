#ifndef EXTERNAL_REQUEST_H_
#define EXTERNAL_REQUEST_H_

#include "Common.h"
#include "Request.h"

class ExternalRequest : public Request {
 public:
  ExternalRequest() {
  }

  ExternalRequest(int l, Direction d) : Request(l) {
    this->direction = d;
  }

  Direction getDirection() {
    return direction;
  }

 private:
  Direction direction;
};

#endif