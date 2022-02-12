#include "complex.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

Complex::Complex(){
    real = 0;
    imaginary = 0;
}

Complex::Complex(double a_new, double b_new){
    real = a_new;
    imaginary = b_new;
}

Complex::Complex(const Complex &complex){
    real = complex.real;
    imaginary = complex.imaginary;
}

double Complex::getReal(){
    return real;
}

double Complex::getImaginary(){
    return imaginary;
}

Complex Complex::operator + (const Complex &second){
    Complex temp = *this;
    temp.real += second.real;
    temp.imaginary += second.imaginary;
    return temp;
}

Complex Complex::operator - (const Complex &second){
    Complex temp = *this;
    temp.real -= second.real;
    temp.imaginary -= second.imaginary;
    return temp;
}

Complex Complex::operator * (const Complex &second){                               //помню что this не обязательно, но в данных случаях как-то проще воспринимать
    Complex temp = *this;
    temp.real = this->real * second.real - this->imaginary * second.imaginary;
    temp.imaginary = this->imaginary * second.real + this->real * second.imaginary;
    return temp;
}

Complex Complex::operator / (const Complex &second){
    Complex temp = *this;
    temp.real = (this->real * second.real + this->imaginary * second.imaginary) / (pow(second.real, 2) + pow(second.imaginary, 2));
    temp.imaginary = (this->imaginary * second.real - this->real * second.imaginary) / (pow(second.real, 2) + pow(second.imaginary, 2));
    return temp;
}

Complex& Complex::operator =(const Complex &second){
    real = second.real;
    imaginary = second.imaginary;
    return *this;
}

bool Complex::operator ==(const Complex &second){
    return this->real == second.real && this->imaginary == second.imaginary;
}

bool Complex::operator!=(const Complex &second){
    return this->real != second.real || this->imaginary != second.imaginary;
}

std::ostream& operator << (std::ostream &stream, const Complex &complex){
    if(complex.imaginary > 0){
        stream << complex.real << '+' << complex.imaginary << 'i';
    }else if(complex.imaginary < 0){
        stream << complex.real << complex.imaginary << 'i';
    }else{
        stream << complex.real;
    }
    return stream;
}

std::istream& operator >> (std::istream &stream, Complex &complex){
    stream >> complex.real;
    stream >> complex.imaginary;
    return stream;
}
