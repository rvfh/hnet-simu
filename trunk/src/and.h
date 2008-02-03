#ifndef _AND_H
#define _AND_H

class And : public Gate {
public:
  And(Output& outputA, Output& outputB) : Gate(outputA, outputB) {}
  void update(const Output* output) {
    if (   ((_inputA != one) && (_inputA != zero))
        || ((_inputB != one) && (_inputB != zero))) {
      _output = error;
    } else
    if ((_inputA == one) && (_inputB == one)) {
      _output = one;
    } else
    {
      _output = zero;
    }
  }
};

#endif
