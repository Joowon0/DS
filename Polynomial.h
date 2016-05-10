//
// Name : Joowon Byun
// Date : May 6th 2016
//
// Program for "Fundamentals of Data Structures" Chapter 2.3
// polynomial class using array
//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <math.h>

class Polynomial {
private:
  float *coef;
  int degree;    // num of filled data in coef

  void Resize(int);
public:
  Polynomial(int);
  Polynomial(float*, int);
  Polynomial Add(const Polynomial);
  Polynomial Mul(const Polynomial);
  float eval(const float);
  void print();
};

void Polynomial::Resize(int newsize) {
  float *temp = new float[newsize];

  for (int i = 0; i < newsize; i++)
    temp[i] = coef[i];
  delete[] coef;
  coef = temp;
  degree = newsize;
}

Polynomial::Polynomial(int len = 5) {
  degree = len;
  coef = new float[degree + 1];
}

Polynomial::Polynomial(float* coefIn, int len = 5) {
  degree = len;
  coef = new float[degree+1];
  for (int i = 0; i < degree; i++)
    coef[i] = coefIn[i];
}

// return the result of Addition with b
Polynomial Polynomial::Add(const Polynomial b) {
  int size = degree;
  if (degree < b.degree)
    size = b.degree;
  Polynomial c(degree);

  // insert a
  for (int i = 0; i< degree; i++)
    c.coef[i] = coef[i];

  // add b
  for (int i = 0; i < b.degree; i++)
    c.coef[i] += b.coef[i];
  
  return c;
}

// return the result of Multiplication with b
Polynomial Polynomial::Mul(const Polynomial b) {
  int size = degree + b.degree - 1;
  Polynomial c(size);
  
  for (int i = 0; i < degree; i++) {
    for (int j = 0; j < b.degree; j++)
      c.coef[i+j] += coef[i] * b.coef[j];
  }

  return c;
}

// result if a number is substitued
float Polynomial::eval(const float f) {
  float evalResult = 0;

  for (int i = 0; i < degree; i++)
    evalResult += coef[i] * pow(f, i);

  return evalResult;
}

void Polynomial::print() {
  std:: cout << coef[degree-1];
  for(int i = degree-2; i >= 0; i--)
    std::cout << "x^" << i+1 << " + " << coef[i] ;
  std::cout << std::endl;
}

#endif
