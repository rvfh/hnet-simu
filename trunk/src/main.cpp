#include <iostream>
#include <list>

using namespace std;

#include "value.h"
#include "receiver.h"
#include "output.h"
#include "input.h"
#include "gate.h"
#include "and.h"
#include "or.h"

class TestInput : public Input {
public:
  void update(const Output* output) {
    Input::update(output);
    cout << " -> Input updated to " << value() << endl;
  }
};

int main(void) {
  cout << endl << "Test Input constructor" << endl;
  TestInput r;
  cout << "Input default value = " << r.value() << endl;

  cout << endl << "Test OutputOne" << endl;
  OutputOne oo;
  cout << "OutputOne value = " << oo.value() << endl;
  if (r.connect(oo)) cerr << "! input connect failed" << endl;
  cout << "Input value= " << r.value() << endl;

  cout << endl << "Test OutputZero" << endl;
  OutputZero oz;
  cout << "OutputZero value = " << oz.value() << endl;
  if (r.disconnect(oo)) cerr << "! input disconnect failed" << endl;
  if (r.connect(oz)) cerr << "! input connect failed" << endl;
  cout << "Input value= " << r.value() << endl;

  cout << endl << "Test Output" << endl;
  Output o0;
  cout << "Output value = " << o0.value() << endl;
  if (r.disconnect(oz)) cerr << "! input disconnect failed" << endl;
  if (r.connect(o0)) cerr << "! input connect failed" << endl;
  cout << "Input value= " << r.value() << endl;
  o0 = one;
  cout << "Output value = " << o0.value() << endl;
  cout << "Input value= " << r.value() << endl;
  o0 = zero;
  cout << "Output value = " << o0.value() << endl;
  cout << "Input value= " << r.value() << endl;
  o0 = high_z;
  cout << "Output value = " << o0.value() << endl;
  cout << "Input value= " << r.value() << endl;
  o0 = error;
  cout << "Output value = " << o0.value() << endl;
  cout << "Input value= " << r.value() << endl;

  cout << endl << "Test And gate" << endl;
  Output o1;
  And a(o0, o1);
  if (r.disconnect(o0)) cerr << "! input disconnect failed" << endl;
  if (r.connect(a.output())) cerr << "! input connect failed" << endl;
  o0 = error;
  o1 = high_z;
  cout << "Output 0 value = " << o0.value() << endl;
  cout << "Output 1 value = " << o1.value() << endl;
  cout << "And value = " << a.value() << endl;
  cout << "Input value = " << r.value() << endl;

  o0 = one;
  cout << "Output 0 value = " << o0.value() << endl;
  cout << "Output 1 value = " << o1.value() << endl;
  cout << "And value = " << a.value() << endl;
  cout << "Input value = " << r.value() << endl;

  o1 = zero;
  cout << "Output 0 value = " << o0.value() << endl;
  cout << "Output 1 value = " << o1.value() << endl;
  cout << "And value = " << a.value() << endl;
  cout << "Input value = " << r.value() << endl;

  o1 = one;
  cout << "Output 0 value = " << o0.value() << endl;
  cout << "Output 1 value = " << o1.value() << endl;
  cout << "And value = " << a.value() << endl;
  cout << "Input value = " << r.value() << endl;

  cout << endl << "Test And gate" << endl;
  Or o(o0, o1);
  if (r.disconnect(a.output())) cerr << "! input disconnect failed" << endl;
  if (r.connect(o.output())) cerr << "! input connect failed" << endl;
  o0 = error;
  o1 = high_z;
  cout << "Output 0 value = " << o0.value() << endl;
  cout << "Output 1 value = " << o1.value() << endl;
  cout << "And value = " << o.value() << endl;
  cout << "Input value = " << r.value() << endl;

  o0 = one;
  cout << "Output 0 value = " << o0.value() << endl;
  cout << "Output 1 value = " << o1.value() << endl;
  cout << "And value = " << o.value() << endl;
  cout << "Input value = " << r.value() << endl;

  o1 = zero;
  cout << "Output 0 value = " << o0.value() << endl;
  cout << "Output 1 value = " << o1.value() << endl;
  cout << "And value = " << o.value() << endl;
  cout << "Input value = " << r.value() << endl;

  o0 = zero;
  cout << "Output 0 value = " << o0.value() << endl;
  cout << "Output 1 value = " << o1.value() << endl;
  cout << "And value = " << o.value() << endl;
  cout << "Input value = " << r.value() << endl;
#if 0
#endif

  return 0;
}
