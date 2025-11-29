#include <iostream>
#include <string>
#include <set>
#include <vector>

int main() {
    std::vector<std::string> words;
    std::string s;
    while (std::cin >> s) {
        words.push_back(s);
    }

    std::set<char> res;
    for (size_t i = 0; i < words[0].length(); ++i) {
        char ltr = words[0][i];
        bool flag = true;
        for (size_t j = 1; j < words.size(); ++j) {
            if (words[j].find(ltr) == std::string::npos) {
                flag = false;
                break;
            }

        }
        if (flag) {
            res.insert(ltr);
        }
    }

    for (char i : res) {
        std::cout << i;
    }

    return 0;
}