#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <string>

// a basic Complex number class

class Complex;

bool operator==(const Complex, const Complex);
bool operator!=(const Complex, const Complex);

Complex add(Complex, Complex);
Complex subtract(Complex, Complex);
Complex multiply(Complex, Complex);
Complex divide(Complex, Complex);

class Complex{
public:

  double real, imag;

  Complex(const double r=0, const double i=0);

  Complex& operator+=(const Complex);
  Complex& operator-=(const Complex);
  Complex& operator*=(const Complex);
  Complex& operator/=(const Complex);

  double realPart() const;
  double imagPart() const;

  void setReal(const double);
  void setImag(const double);

  double norm();
  Complex conj();

  std::string toString() const{
    return std::to_string(real) + " + " + std::to_string(imag) + "i";
  }

private:


};

#endif
