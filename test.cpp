#include "Polynomial.h"
//#include "Polynomial2.h"
#include <iostream>

using namespace std;

int main() {
  float coefA[5] = { 1, 1, 1, 1, 1};
  float coefB[5] = { 1, 2, 3, 4, 5};
  Polynomial a(coefA), b(coefB), c, d;

  cout << "a(x)     : ";
  a.print();
  cout << "b(x)     : ";
  b.print();

  cout << "a(x)+b(x): ";
  c = a.Add(b);
  c.print();

  cout << "a(x)*b(x): ";
  d = a.Mul(b);
  d.print();

  cout << "a(3)     : " << a.eval(3) << endl;
  cout << "b(1)     : " << b.eval(1) << endl;
  
  return 0;
}
