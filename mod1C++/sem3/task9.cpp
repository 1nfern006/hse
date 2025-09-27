#include <iostream>


int main() {
    int a, b;

    std::cin >> a >> b;
    std::cout << "a = " << a << " b = " << b << '\n';
    a = a + b;
    b = a - b;
    a = (a + b) / 2;
    std::cout << "a = " << a << " b = " << b;
    return 0;
}