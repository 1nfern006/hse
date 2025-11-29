#include <iostream>
#include <string>

int main() {
    std::string alfs;
    int n;
    std::cin >> alfs >> n;

    std::string word;
    for (int i = 0; i < n; ++i) {
        std::cin >> word;
        bool flag = true;
        for (int j = 0; j < word.length(); ++j) {
            if (alfs.find(word[j]) == std::string::npos) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << word << '\n';
        }
    }

    return 0;
}