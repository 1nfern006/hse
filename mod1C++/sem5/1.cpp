#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* p = &n;
    int n1 = 1;
    int n2 = 1;
    int s = 0;
    for (int i = 1; i <= *p; ++i) {
        if (i == 1) {
            std::cout << 0 << " ";
        } else if (i == 2 || i == 3) {
            std::cout << 1 << " ";
        } else {
            s = n1 + n2;
            std::cout << s << " ";
            n1 = n2;
            n2 = s;

        }
    }
    return 0;
}