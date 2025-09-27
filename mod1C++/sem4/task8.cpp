#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int count = 0;
    while (n != 0) {
        n &= (n-1);
        count++;
    }
    std::cout << count << '\n';
    return 0;
}