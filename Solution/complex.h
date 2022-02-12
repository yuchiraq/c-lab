#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    // Kонструкторы: по умолчанию, параметризированный, копирования;
    Complex();
    Complex(double a_new, double b_new);
    Complex(const Complex &complex);

    double getReal();

    double getImaginary();

    // Aрифметические oперации (+, -, *, /, =) и операции сравнения (==, !=);
    Complex operator +(const Complex &second);              // operator +(Complex + Complex);
    Complex operator -(const Complex &second);              // operator -(Complex - Complex);
    Complex operator *(const Complex &second);
    Complex operator /(const Complex &second);
    Complex& operator =(const Complex &second);

    bool operator ==(const Complex &second);
    bool operator !=(const Complex &second);

    // Oперации ввода вывода (<<, >>);
    friend std::ostream& operator << (std::ostream& stream,const  Complex &complex); // friend operator, (ostream + Complex)
    friend std::istream& operator >> (std::istream& stream, Complex &complex); // friend operator, (istream + Complex)
private:
    static const int i = -1;
    double real;
    double imaginary;
};

// Oперации ввода вывода (<<, >>);
std::ostream& operator << (std::ostream& stream,const  Complex &complex); // friend operator, (ostream + Complex)
std::istream& operator >> (std::ostream& stream, Complex &complex); // friend operator, (istream + Complex)

#endif // COMPLEX_H
