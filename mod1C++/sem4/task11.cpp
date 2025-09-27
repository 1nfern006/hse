#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    a > b ? std::cout << a << '\n' : std::cout << b << '\n';
    return 0;
}