#ifndef _RECEIVER_H
#define _RECEIVER_H

class Output;

class Receiver {
protected:
  unsigned int      _connections;
  unsigned int      _max_connections;
public:
  Receiver(int max_connections) :
      _connections(0), _max_connections(max_connections) {}
  virtual ~Receiver() {}
  virtual void update(const Output* output) {}
  int connect(Output& output);
  int disconnect(Output& output);
};

#endif
