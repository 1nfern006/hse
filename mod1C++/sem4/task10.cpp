#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int step = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            step++;
            n = n / 2;
        } else {
            step++;
            n = 3 * n + 1;
        }
    }
    std::cout << step << '\n';
   return 0;
}