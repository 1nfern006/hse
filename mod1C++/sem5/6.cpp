#include <iostream>

int main() {
    std::string n;
    int sum = 0;
    std::cin >> n;
    std::cout << "Sum of digits in " << n << ": ";
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] != "-"[0]) {
            sum += n[i] - '0';
            std::cout << n[i];
            if (i != n.length() - 1) {
                std::cout << "+";
            }
        }

    }
    std::cout << " = " << sum;
    return 0;
}