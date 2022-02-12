#include <iostream>
#include "complex.h"
#include "stack.h"

std::string status(bool status){
    if(status){
        return "true";
    }else{
        return "false";
    }
}

void demo(Complex &a, Complex &b){
    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
    std::cout << "a == b - " << status(a == b) << std::endl;
    std::cout << "a != b - " << status(a != b) << std::endl;
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    std::cout << a << " / " << b << " = " << a / b << std::endl;
}

int initStack(){
    int size;
    std::cout << "Введите количество элементов стека(0 - отмена) >> ";
    std::cin >> size;
    return size;
}

void menuStack(){
    int size = initStack();
    if(!size){
        std::cout << "Проверка стека отменена";
        return;
    }
    Stack *stack = new Stack(size), *stackAlternate;
    while(true){
        std::cout << "1 - Ввести новое значение для числа в стеке" << std::endl;
    }
}

int main(){
    std::cout << "Реализовать класс, представляющий комплексное число:" << std::endl;
    Complex a(2, 5), b(2, 5);
    demo(a, b);
    menuStack();
    return 0;
}
