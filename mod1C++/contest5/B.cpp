#include <iostream>
#include <string>

bool palindrome(std::string s) {
    int len = s.length();
    std::string news = "";
    for (int i = 0; i < len; ++i) {
        if (s[i] == " "[0]) {
            continue;
        }
        news += s[i];
    }
    len = news.length();
    for (int i = 0; i < len / 2; ++i) {
        if (news[i] != news[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    if (palindrome(s)) {
        std::cout << "yes" << '\n';
    } else {
        std::cout << "no" << '\n';
    }
    return 0;
}