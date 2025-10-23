#include <iostream>
#include <vector>
#include <string>


int DotProduct(std::vector<int>& u, std::vector<int>& v) {
    int ans = 0;
    for (size_t i = 0; i < u.size(); ++i) {
        ans += u[i] * v[i];
    }
    return ans;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::string word1;
    std::vector<int> vect1(n);
    std::cin >> word1;
    for (int i = 0; i < n; ++i) {
        std::cin >> vect1[i];
    }
    
    std::string word;
    std::vector<int> vect(n);
    std::vector<std::string> closestW;
    int closestP;
    int dotP;
    for (int i = 1; i < m; ++i) {
        std::cin >> word;
        for (int j = 0; j < n; ++j) {
            std::cin >> vect[j];
        }
        dotP = DotProduct(vect1, vect);
        if (i == 1) {
            closestP = dotP;
            closestW.push_back(word);
        } else {
            if (dotP > closestP) {
                closestP = dotP;
                closestW.clear();
                closestW.push_back(word);
            } else if (dotP == closestP) {
                closestW.push_back(word);
            }
        }
    }
    for (size_t i = 0; i < closestW.size(); ++i) {
        std::cout << closestW[i] << '\n';
    }
    return 0;
}