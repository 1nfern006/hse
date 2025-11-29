#include <iostream>
#include <string>
#include <map>

int main() {
    std::map<char, int> all;
    std::string s;
    
    while (std::getline(std::cin, s)) {
        for (char c : s) {
            if (c != ' ' && c != '\n') {
                ++all[c];
            }
        }
    }
    
    int maxi = 0;
    for (const auto& p : all) {
        maxi = std::max(maxi, p.second);
    }
    

    for (int i = maxi; i > 0; --i) {
        for (const auto& p : all) {
            if (p.second >= i) {
                std::cout << '#';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    
    for (const auto& p : all) {
        std::cout << p.first;
    }
    
    return 0;
}