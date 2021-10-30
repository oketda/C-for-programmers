#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  /* print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b); */

  //a)
  cout << "a)" << endl;
  print("Original a = ", a);
  Fraction tmp_a = a-2;
  print("a - 2 = ", tmp_a);
  tmp_a = 3-a;
  print("3 - a = ", tmp_a);

  //b)
  // Siden operatøren er venstreassosiativ blir 5-3-fraction_1-7-fraction_2 løst som:
  //((((5-3)-fraction_1)-7)-fraction_2)
}

