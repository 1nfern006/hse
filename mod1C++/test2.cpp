#include <iostream>
#include <vector>


bool isPositive(int x) {
    if (x > 0) {
        return true;
    }
    return false;
}


bool isEven(int x) {
    if (x % 2 == 0) {
        return true;
    }
    return false;
}


std::vector<int> filterArray(
    const std::vector<int>& arr,
    bool (*filter)(int),
    int& resultSize
) {
    std::vector<int> res;
    for (int temp: arr) {
        if (filter arr)) {
            ++resultSize;
            res.push_back(res[i]);
        }
    }
    return res;
}

int main() {
    int n;
    int num1 = 0, num2 = 0;
    std::cin >> n;
    std::vector<int> vect(n);
    std::vector<int> a1 = filterArray(vect, isPositive, num1);
    for (int temp: arr) {
        std::cout << arr << " ";
    }
    std::vector<int> a2 = filterArray(vect, isEven, num2);
    for (int temp: arr) {
        std::cout << arr << " ";
    }
    return 0;
}