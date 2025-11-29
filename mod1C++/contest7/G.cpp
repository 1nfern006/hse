#include <iostream>
#include <vector>
#include <string>

int main() {
    int m, n;
    std::cin >> m;
    std::vector<std::string> s(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> s[i];
    }

    std::cin >> n;
    std::vector<std::string> plate(n);
    std::vector<int> match(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> plate[i];
    }
    

    for (int i = 0; i < n; ++i) {     
        for (int j = 0; j < m; ++j) {
            bool flag = true;
            for (char c : s[j]) {
                if (plate[i].find(c) == std::string::npos) {
                    flag = false;
                    break;
                }
            }  
            if (flag) {
                ++match[i];
            }
        }
    }
    
    int maxi = match[0];
    for (int count : match) {
        maxi = std::max(maxi, count);
    }
    for (int i = 0; i < n; ++i) {
        if (match[i] == maxi) {
            std::cout << plate[i] << '\n';
        }
    }
    



    return 0;
}