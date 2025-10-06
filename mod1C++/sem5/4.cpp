#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* p = &n;

    for (int i = 1; i <= 10; ++i) {
        std::cout << *p << " x " << i << " = " << *p * i << '\n'; 
    }
    return 0;
}
