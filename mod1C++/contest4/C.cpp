#include <iostream>

int main() {
    int z, n;
    std::cin >> z >> n;
    int* p1 = &z;
    int* p2 = &n;
    *p1 += *p2;
    std::cout << *(p2 - 1) << '\n';
    return 0;
}