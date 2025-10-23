#include <iostream>
#include <cstddef>
#include <concepts>
#include <type_traits>


template<class T>
requires(std::integral<T> || std::floating_point<T>)
T findMax(const T* a, std::size_t length) {
    T maxe = a[0];
    for (std::size_t i = 0; i < length; ++i) {
        if (a[i] > maxe) {
            maxe = a[i];
        }

    }
    return maxe;
}

int main() {

    const int a[5] = {1, 3, 2, 4, 8};
    std::cout << findMax<int>(a, 5);

    return 0;
}