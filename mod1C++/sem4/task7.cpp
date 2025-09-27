#include <iostream>

int main() {
    int n;
    std::cin >> n;
    (n > 0) && ((n & (n-1)) == 0) ? std::cout << "YES" : std::cout << "NO";
    return 0;
}