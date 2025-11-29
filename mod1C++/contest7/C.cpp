#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::map<std::string, std::vector<int>> res;

    for (int i = 0; i < n; ++i) {
        int ns;
        std::cin >> ns;
        for (int j = 0; j < ns; ++j) {
            std::string name;
            int score;
            std::cin >> name >> score;
            if (res[name].size() < static_cast<size_t>(n)) {
                res[name].resize(n, 0);
            }
            res[name][i] = score;
        }
    }


    for (const auto& i : res) {
        std::cout << i.first;
        for (int score : i.second) {
            std::cout << "\t" << score;
        }
        std::cout << '\n';
    }

    return 0;
}

