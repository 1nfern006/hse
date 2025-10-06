#include <iostream>
#include <string>

std::string plus1(std::string n) {
    int len = n.length();
    int dop = 1;
    std::string newN = "";
    for (int i = len - 1; i >= 0; --i) {
        int num = n[i] - '0' + dop;
        newN = std::to_string(num % 10) + newN;
        dop = num / 10;     
    }

    if (dop > 0) {
        newN = "1" + newN;
    }

    return newN;
} 

int main() {
    std::string n;
    std::cin >> n;
    std::cout << plus1(n) << '\n';
    return 0;
}