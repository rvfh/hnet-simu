#ifndef _OR_H
#define _OR_H

class Or : public Gate {
public:
  Or(Output& outputA, Output& outputB) : Gate(outputA, outputB) {}
  void update(const Output* output) {
    if (   ((_inputA != one) && (_inputA != zero))
        || ((_inputB != one) && (_inputB != zero))) {
      _output = error;
    } else
    if ((_inputA == one) || (_inputB == one)) {
      _output = one;
    } else
    {
      _output = zero;
    }
  }
};

#endif
