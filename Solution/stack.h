#include <iostream>
#include "complex.h"

#ifndef STACK_H
#define STACK_H

const short DEFAULT_MAX_SIZE = 6;

class Stack{
public:
    // Kонструкторы: по умолчанию, параметризированный, копирования;
    Stack();             // Создаётся стек фиксированного размера (DEFAULT_MAX_SIZE)
    Stack(int sizeMaxNew);          // B качестве аргумента принимает максимальное количество элементов в стеке
    Stack(const Stack &stack);

    // Добавление и извлечение элементов
    void push(const Complex& number);
    Complex pop(); // Возвращает элемент и удаляет с вершины стека

    // Проверка на заполненость и количество элементов в стеке
    bool isEmpty() const;
    bool isFull() const;
    int size() const;

    // Вывод всех элементов в консоль
    void show() const;

    void change(int place, const Complex &new_number);

    // Перегрузка оператора вывода в консоль (<<)
    friend std::ostream& operator << (std::ostream& stream, const Stack &stack);

private:

    Complex *array;

    int sizeMax, sizeReal;
};

std::ostream& operator << (std::ostream& stream,const Stack &stack); // friend operator, (ostream + Stack)

#endif // STACK_H
