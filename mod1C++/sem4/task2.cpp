#include <iostream>

int x = 10;
int main() {
    int x, y;
    std::cin >> x >> y;
    y != 0 ? std::cout << x / y << '\n' : std::cout << "Error";
    
    return 0;
}