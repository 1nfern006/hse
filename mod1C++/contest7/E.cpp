#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;
    std::vector<int> all(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> all[i];
    }
    
    std::multiset<int> window;
    for (int i = 0; i < k; ++i) {
        window.insert(all[i]);
    }
    std::cout << *window.begin() << '\n';
    
    for (int i = k; i < n; ++i) {
        window.erase(window.find(all[i - k]));
        window.insert(all[i]);
        std::cout << *window.begin() << '\n';
    }

    
    return 0;
}