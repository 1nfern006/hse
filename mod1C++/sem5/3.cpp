#include <iostream>

int main() {
    std::string n;
    std::string s;
    std::cin >> n;
    std::cout << "Original: " << n << ", Reversed: ";
    for (int i = n.length() - 1; i >= 0; --i) {
        std::cout << n[i]; 
        s += n[i];
    }
    if (n == s) {
        std::cout << " - Palindrome!";
    }
    return 0;
}