#ifndef _OUTPUT_H
#define _OUTPUT_H

class Output {
  Value              _value;
  list<Receiver*>       _basics;
public:
  Output(Value value = high_z) : _value(value) {}
  virtual ~Output() {}
  Value operator=(Value value) {
    if (value != _value) {
      _value = value;
      for (list<Receiver*>::const_iterator i = _basics.begin();
          i != _basics.end(); i++) {
        (*i)->update(this);
      }
    }
    return _value;
  }
  virtual Value value() const { return _value; }
  // Do not use these two methods directly
  virtual void enlist(Receiver* basic) {
    _basics.push_back(basic);
    basic->update(this);
  }
  virtual int delist(const Receiver* basic) {
    bool found = false;
    for (list<Receiver*>::iterator i = _basics.begin();
        i != _basics.end(); i++) {
      if (*i == basic) {
        _basics.erase(i);
        found = true;
        break;
      }
    }
    return found ? 0 : -1;
  }
};

class OutputOne : public Output {
public:
  Value value() const { return one; }
};

class OutputZero : public Output {
public:
  Value value() const { return zero; }
};

#endif
