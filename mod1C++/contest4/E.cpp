#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    int* p1 = &a;
    int* p2 = &b;
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
    std::cout << a << " " << b << '\n';
    return 0;
}