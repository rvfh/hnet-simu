#include <list>

using namespace std;

#include "receiver.h"
#include "value.h"
#include "output.h"

int Receiver::connect(Output& output) {
  if (_connections >= _max_connections) {
    return -1;
  }
  output.enlist(this);
  _connections++;
  return 0;
}

int Receiver::disconnect(Output& output) {
  if (_connections == 0) {
    return -1;
  }
  if (output.delist(this) != 0) {
    return -1;
  }
  _connections--;
  return 0;
}
