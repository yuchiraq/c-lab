#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
    // Kонструкторы: по умолчанию, параметризированный, копирования;
    Complex();
    Complex(double a_new, double b_new);
    Complex(const Complex &complex);

    // Aрифметические oперации (+, -, *, /, =) и операции сравнения (==, !=);
    Complex operator +(const Complex &complex);              // operator +(Complex + Complex);
    Complex operator -(const Complex &complex);              // operator -(Complex - Complex);
    Complex operator *(const Complex &complex);
    Complex operator /(const Complex &complex);
    Complex& operator =(const Complex &complex);

    bool operator ==(const Complex &complex);
    bool operator !=(const Complex &complex);

    // Oперации ввода вывода (<<, >>);
    std::ostream& operator << (std::ostream& stream,const  Complex &complex); // friend operator, (ostream + Complex)
    std::istream& operator >> (std::ostream& stream, Complex &complex); // friend operator, (istream + Complex)

//private:
    static const int i = -1;
    double a;
    double b;
};

#endif // COMPLEX_H
