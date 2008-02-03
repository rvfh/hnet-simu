#ifndef _GATE_H
#define _GATE_H

class Gate : public Receiver {
protected:
  Input             _inputA;
  Input             _inputB;
  Output            _output;
public:
  Gate(Output& outputA, Output& outputB) : Receiver(2) {
    // Update inputs
    _inputA.connect(outputA);
    _inputB.connect(outputB);
    // Update self
    connect(outputA);
    connect(outputB);
  }
  Output& output() { return _output; }
  Value value() const { return _output.value(); }
};

#endif
