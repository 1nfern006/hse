#include <iostream>
#include <string>
#include <set>

int main() {
    std::set<std::string> all;
    std::string s;
    while (std::getline(std::cin, s)) {
        if (s.empty()) continue;
        all.insert("/");
        
        size_t pos = 0;
        while (pos < s.length()) {
            size_t np = s.find('/', pos + 1);
            if (np == std::string::npos) {
                if (pos > 0 && s.back() == '/') {
                    all.insert(s);
                }
                break;
            }

            std::string dir = s.substr(0, np + 1);
            all.insert(dir);
            pos = np;
        }

    }

    for (const auto& dir : all) {
        std::cout << dir << '\n';
    }
    return 0;
}
