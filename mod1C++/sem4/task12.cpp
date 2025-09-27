#include <iostream>

int main() {
    int x, k;
    std::cin >> x >> k;
    x = (x ^ (1 << k));
    std::cout << x << '\n';
   return 0;
}