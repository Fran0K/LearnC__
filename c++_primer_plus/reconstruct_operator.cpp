//
// Created by Frank Lin on 27/4/2022.
//
#include <iostream>

using namespace std;

class complex{
public:
    complex();
    complex(double a, double b):real(a), imag(b){};
public:
    complex operator+(const complex &A) const;
private:
    double real;
    double imag;
};

complex complex::operator+(const complex &A) const {
    complex B;
    B.real = this->real + A.real;
    B.imag = this->imag + B.imag;
    return B;
}