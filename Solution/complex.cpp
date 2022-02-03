#include "complex.h"
#include <cmath>
#include <iostream>

Complex::Complex(){
    a = 0;
    b = 0;
}

Complex::Complex(double a_new, double b_new){
    a = a_new;
    b = b_new;
}

Complex::Complex(const Complex &complex){
    a = complex.a;
    b = complex.b;
}

Complex Complex::operator + (const Complex &second){
    Complex temp = *this;
    temp.a += second.a;
    temp.b += second.b;
    return temp;
}

Complex Complex::operator - (const Complex &second){
    Complex temp = *this;
    temp.a -= second.a;
    temp.b -= second.b;
    return temp;
}

Complex Complex::operator * (const Complex &second){                               //помню что this не обязательно, но в данных случаях как-то проще воспринимать
    Complex temp = *this;
    temp.a = this->a * second.a - this->b * second.b;
    temp.b = this->b * second.a + this->a * second.b;
    return temp;
}

Complex Complex::operator / (const Complex &second){
    Complex temp = *this;
    temp.a = (this->a * second.a + this->b * second.b) / (pow(second.a, 2) + pow(second.b, 2));
    temp.b = (this->b * second.a - this->a * second.b) / (pow(second.a, 2) + pow(second.b, 2));
    return temp;
}

Complex& Complex::operator =(const Complex &second){
    a = second.a;
    b = second.b;
    return *this;
}

bool Complex::operator ==(const Complex &second){
    return this->a == second.a && this->b == second.b;
}

std::ostream& operator << (std::ostream &stream, const Complex &complex){
    //if(complex.b > 0){
        stream << complex.a << complex.b;
    /*}else if(complex.b < 0){
        stream << complex.a << complex.b << 'i';
    }else{
        stream << complex.a;
    }*/
    return stream;
}
