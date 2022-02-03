#include <iostream>
#include "complex.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Complex a(2.56, -6), b(2, 5);
    std::cout << "1 - " << a << std::endl << "2 - " << b << std::endl;
    std::cout << a + b << std::endl;
    return 0;
}
