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
    if(this->isEmpty()){
        throw "Error, stack is empty!!!";
    }
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
    //std::cout << this;
    std::cout << std::endl;
    for(int i = 0; i < this->sizeReal; i++){
        std::cout << i + 1 << ") " << this->array[i] << std::endl;
    }
    std::cout << std::endl;
}

void Stack::change(int place, const Complex &new_number){
    if(place > sizeReal){
        std::cout << "Error, out of stack" << std::endl;
        return;
    }else if (place == sizeReal) {
        push(new_number);
        return;
    }
    array[--place] = Complex(new_number);
}

std::ostream& operator << (std::ostream& stream, const Stack &stack){
    stream << std::endl;
    for(int i = 0; i < stack.sizeReal; i++){
        stream << i + 1 << ") " << stack.array[i] << std::endl;
    }
    return stream;
}
