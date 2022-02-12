#include "complex.h"
#include "stack.h"

Stack::Stack(){
    sizeMax = DEFAULT_MAX_SIZE;
    array = new Complex[sizeMax]();
}

Stack::Stack(int sizeMaxNew){
    sizeMax = sizeMaxNew;
    array = new Complex[sizeMax]();
}

Stack::Stack(const Stack &stack){
    if(stack.isEmpty()){
        std::cout << "Error, stack is empty!!!" << std::endl;
        return;
    }
    sizeMax = stack.size();
    array = new Complex[sizeMax]();
    for(int i = 0; i < sizeMax; i++){
        this->array[i] = stack.array[i];
    }
}

void Stack::push(const Complex &number){
    if(this->isFull()){
        std::cout << "Error, stack is full" << std::endl;
        return;
    }
    array[sizeReal] = number;
    sizeReal++;
}

Complex Stack::pop(){
    sizeReal--;
    return array[sizeReal];
}

bool Stack::isEmpty() const{
    if(!sizeReal){
        return true;
    }else{
        return false;
    }
}

bool Stack::isFull() const{
    if(sizeReal == sizeMax){
        return true;
    }else{
        return false;
    }
}

int Stack::size() const{
    return sizeReal;
}

void Stack::show() const{
    std::cout << this;
}

void Stack::change(int place, const double &realNew, const double &imaginaryNew){
    if(place > sizeReal){
        std::cout << "Error, out of stack";
        return;
    }
    array[--place] = Complex(realNew, imaginaryNew);
}

std::ostream& operator << (std::ostream& stream, const Stack &stack){
    for(int i = 0; i < stack.sizeReal; i++){
        stream << i << ") " << stack.array[i] << std::endl;
    }
    return stream;
}
