#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int* p = &n;
    int count = 0;

    std::cout << "Number " << *p << " has ";
    *p = abs(*p);
    while (*p != 0) {
        count += 1;
        *p /= 10;
    }
    std::cout << count << " digits";
    return 0;
}