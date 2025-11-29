#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdint>

struct Star {
    std::string name;
    uint64_t age;
};

std::string FindStar(const std::vector<Star>& stars) {
    std::map<std::string, uint64_t> uniques;

    for (const auto& star : stars) {

        uint64_t& max_age = uniques[star.name];
        
        if (star.age > max_age) {
            max_age = star.age;
        }
    }


    std::vector<uint64_t> ages;
    for (const auto& pair : uniques) {
        ages.push_back(pair.second);
    }


    std::sort(ages.begin(), ages.end());
    uint64_t median = ages[ages.size() / 2];

    for (const auto& pair : uniques) {
        if (pair.second == median) {
            return pair.first;
        }
    }
    return "";
}