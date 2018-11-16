#include "example.h"
#include <iostream>
#include <cassert>

using namespace std;


bool operator==(const Complex a, const Complex b){
  return (a.realPart() == b.realPart() && a.imagPart() == b.imagPart());
}

bool operator!=(const Complex a, const Complex b){
  return !(a == b);
}

Complex add(Complex a, Complex b){
  return a += b;
}

Complex subtract(Complex a, Complex b){
  return a -= b;
}

Complex multiply(Complex a, Complex b){
  return a *= b;
}

Complex divide(Complex a, Complex b){
  return a /= b;
}


Complex::Complex(const double r, const double i): real(r), imag(i) {}

Complex& Complex::operator+=(const Complex x){
  real += x.real;
  imag += x.imag;

  return *this;
}

Complex& Complex::operator-=(const Complex x){
  real -= x.real;
  imag -= x.imag;

  return *this;
}

Complex& Complex::operator*=(const Complex x){
  double a=real, b=imag, c=x.real, d=x.imag;
  real = a*c - b*d;
  imag = b*c + a*d;

  return *this;
}

Complex& Complex::operator/=(const Complex x){
  assert(x.real || x.imag);
  double a=real, b=x.real, c=imag, d=x.imag;
  real = (a*c + b*d)/(c*c + d*d);
  imag = (b*c - a*d)/(c*c + d*d);

  return *this;
}

double Complex::realPart()const{
  return real;
}

double Complex::imagPart()const{
  return imag;
}

void Complex::setReal(const double r){
  real = r;
}

void Complex::setImag(const double i){
  imag = i;
}

double Complex::norm(){
  return (real*real + imag*imag);
}

Complex Complex::conj(){
  return Complex(real, -imag);
}
