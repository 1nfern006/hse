

#include <iostream>
int main() {
    volatile const int x = 0; // check without volatile
    std::cout << x << ' ' << &x << '\n';
    int b = 10;
    int* ptr = &(b) + 1;
    std::cout << x << ' ' << &x << '\n';
    std::cout << *ptr << ' ' << ptr << '\n';
}