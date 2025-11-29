#include <iostream>
#include <string>
#include <set>

int main() {
    std::string s;
    std::getline(std::cin, s);
    
    std::set<int> seen;
    std::string ns = "";
    
    for (char c : s) {
        if (c == ' ') {
            if (!ns.empty()) {
                int n = std::stoi(ns);
                if (seen.find(n) != seen.end()) {
                    std::cout << "YES" << '\n';
                } else {
                    std::cout << "NO" << '\n';
                    seen.insert(n);
                }
                ns = "";
            }
        } else {
            ns += c;
        }
    }
    
    if (!ns.empty()) {
        int n = std::stoi(ns);
        if (seen.find(n) != seen.end()) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
            seen.insert(n);
        }
    }
    
    return 0;
}