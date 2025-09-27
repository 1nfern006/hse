#include <iostream>
#include <cmath>

int main() {
    double a, b;
    std::cin >> a >> b;

    double radius = sqrt(a*a + b*b);
    printf("%.2f\n", radius);
    
    return 0;
}