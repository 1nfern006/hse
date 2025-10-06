#include <iostream>
#include <string>

std::string extractDigits(std::string s) {
    std::string newS = "";
    int len = s.length();
    for (int i = 0; i < len; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            newS += s[i];
        }
    } 
    return newS;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << extractDigits(s);
    return 0;
}