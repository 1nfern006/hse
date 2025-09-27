#include <iostream>
#include "operations.h"

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << plus(a, b) << "\n";   
    std::cout << minus(a, b) << "\n";   
    std::cout << multiply(a, b) << "\n";   
    std::cout << divide(a, b) << "\n";   
    return 0;
}