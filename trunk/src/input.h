#ifndef _INPUT_H
#define _INPUT_H

class Input : public Receiver {
  Value             _value;
public:
  Input() : Receiver(1), _value(error) {}
  virtual ~Input() {}
  Value value() const { return _value; }
  virtual Value operator=(Value value) {
    _value = value;
    return _value;
  }
  bool operator==(const Value& value) const {
    return _value == value;
  }
  bool operator!=(const Value& value) const {
    return _value != value;
  }
  virtual void update(const Output* output) {
    _value = output->value();
  }
};

#endif
