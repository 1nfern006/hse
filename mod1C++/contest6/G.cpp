
#include <vector>
#include <algorithm>

void delete_zeroes(std::vector<int>& numbers) {
    auto last = std::remove(numbers.begin(), numbers.end(), 0);
    numbers.erase(last, numbers.end());
}