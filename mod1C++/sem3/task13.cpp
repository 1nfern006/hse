#include <iostream>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    double p = (a + b + c) / 2;

    printf("%.2f\n", p * (p - a) * (p - b) * (p - c));
    
    return 0;
}