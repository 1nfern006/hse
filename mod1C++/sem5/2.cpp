#include <iostream>
#include <string>

int main() {

    std::string n;
    std::cin >> n;
    if (n[0] == "-"[0]) {
        std::cout << "-";
    }
    for (int i = n.length(); i >= 0; --i) {
        if (n[i] == "-"[0]) {
            continue;
        } else {
            std::cout << n[i];
        }
    } 
    return 0;
}