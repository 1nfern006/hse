#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    int n;
    std::cin >> n;
    std::map<int, std::set<std::string>> all;

    for (int i = 0; i < n; ++i) {
        std::string word;
        int page;
        std::cin >> word >> page;
        all[page].insert(word);
    }
    
    for (const auto& i : all) {
        std::cout << i.first;
        const std::set<std::string>& words = i.second;
        
        for (const std::string& word : words) {
            std::cout << " " << word;
        }
        std::cout << '\n';
    }
    
    return 0;
}