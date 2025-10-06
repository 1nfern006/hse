#include <iostream>

int main() {
    float y, yn;
    std::cin >> y >> yn;
    float* p = &y;
    *p = yn;
    std::cout << y << '\n';
    return 0;
}