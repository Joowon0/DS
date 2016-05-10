//
// Name : Joowon Byun
// Date : May 6th 2016
//
// Program for "Fundamentals of Data Structures" Chapter 2.3
// polynomial class using array
//

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <math.h>

class Polynomial;

class Term {
  friend Polynomial;
private:
  float coef;
  int exp;
};



class Polynomial {
private:
  Term *termArray; // an array (0s not included)
  int capacity;    // size of termArray
  int terms;       // num of filled data in termArray

  void NewTerm(const float, const int);
public:
  Polynomial(int);
  Polynomial Add(Polynomial);
  Polynomial Mul(Polynomial);
  float eval(float);
};

// add new one in the end of termArray
void Polynomial::NewTerm(const float theCoeff, const int theExp) {
  if (terms==capacity) {
    capacity *= 2;
    Term *temp = new Term[capacity];

    for (int i = 0; i < terms; i++)
      temp[i] = termArray[i];
    delete[] termArray;
    termArray = temp;
  }
  termArray[terms].coef=theCoeff;
  termArray[terms++].exp=theExp;
}

Polynomial::Polynomial(int d = 5) {
  capacity = d;
  termArray = new Term[capacity+1];
}

// return the result of Addition with b
Polynomial Polynomial::Add(Polynomial b) {
  Polynomial c;
  int aPos = 0, bPos = 0; // Position
  while((aPos < terms)&&(bPos<b.terms)) {
    if ((termArray)[aPos].exp==b.termArray[bPos].exp) {
      float t = termArray[aPos].coef + b.termArray[bPos].coef;
      if (t)
	c.NewTerm(t, termArray[aPos].exp);
      aPos++; bPos++;
    }
    else if ((termArray)[aPos].exp<b.termArray[bPos].exp) {
      c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
      bPos++;
    }
    else {
      c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
      aPos++;
    }

    // these makes polynomials not in order
    // need modifiaction
    for(; aPos<terms; aPos++)
      c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    for(; bPos<terms; bPos++)
      c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);

    return c;
  }
}
// return the result of Multiplication with b
Polynomial Polynomial::Mul(Polynomial b) {
}

float Polynomial::eval(float f) {
  int evalResult = 0;
  
  for(int i = 0; i < terms; i++)
    evalResult += termArray[i].coef * pow(f, termArray[i].exp);

  return evalResult;
}

#endif
