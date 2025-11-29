#include <iostream>
#include <vector>
#include <string>


struct WordVec {
    std::string word;
    std::vector<int> vec;
};


int DotProduct(const std::vector<int>& u, const std::vector<int>& v) {
    int ans = 0;
    for (size_t i = 0; i < u.size(); ++i) {
        ans += u[i] * v[i];
    }
    return ans;
}

int main() {

    int m, n;
    std::cin >> m >> n;
        
    WordVec wv;
    wv.vec.resize(n);
    std::cin >> wv.word;
    for (int i = 0; i < n; ++i) {
        std::cin >> wv.vec[i];
    }


    std::vector<std::string> closestW;
    int closestP ; 


    WordVec cur;
    cur.vec.resize(n);

    for (int i = 1; i < m; ++i) {
        std::cin >> cur.word;
        for (int j = 0; j < n; ++j) {
            std::cin >> cur.vec[j];
        }

        int dotP = DotProduct(wv.vec, cur.vec);


        if (i == 1) {
            closestP = dotP;
            closestW.push_back(cur.word);
        } else {
            if (dotP > closestP) {
                closestP = dotP;
                closestW.clear();
                closestW.push_back(cur.word);
            } else if (dotP == closestP) {
                closestW.push_back(cur.word);
            }
        }
    }

    for (const auto& w : closestW) {
        std::cout << w << "\n";
    }

    return 0;
}