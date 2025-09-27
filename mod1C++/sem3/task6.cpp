#include <iostream>


int main() {
    int a;
    std::cin >> a;
    std::cout << a % 10 + a % 100 / 10 + a / 1000 + a / 100 % 10 << '\n';

}