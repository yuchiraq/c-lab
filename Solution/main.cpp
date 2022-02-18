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
    int key;
    int size = initStack();
    if(!size){
        std::cout << "Проверка стека отменена" << std::endl;
        return;
    }
    Complex complex_new;
    Stack *stack = new Stack(size);
    while(true){
        std::cout << "Количество элементов в стеке: " << stack->size() << std::endl;
        std::cout << "1 - Ввести новое значение для числа в стеке" << std::endl;
        std::cout << "2 - Удаление нескольких чисел с вершины стека" << std::endl;
        std::cout << "3 - Вывод стека" << std::endl;
        std::cout << "0 - Выход" << std::endl;
        std::cin >> key;
        switch (key) {
        case 1:
            std::cout << "Введите номер для добавления или замены (для добавления количество элементов + 1) >> ";
            std::cin >> key;
            std::cout << "Введите новое комплекное число >> ";
            std::cin >> complex_new;
            stack->change(--key, complex_new);
            break;
        case 2:
            std::cout << "Сколько элементов с вершины удалить >> ";
            std::cin >> key;
            for(int i = 0; i < key; i++){
                try {
                    std::cout << "Удалён элемент: " << stack->pop() << std::endl;
                }  catch (char const *e) {
                    std::cout << e << std::endl;
                }

            }
            break;
        case 3:
            stack->show();

            break;
        case 0:
            return;
            break;
        default:
            std::cout << "Проверьте правильность выбора пункта меню!" << std::endl;
        }
    }
}

int main(){
    std::cout << "Реализовать класс, представляющий комплексное число:" << std::endl;
    Complex a(2, 5), b(2, 5);
    demo(a, b);
    menuStack();
    return 0;
}
