#include <iostream>
#include <cstddef>
#include <concepts>


template<class T>

T swapValues(const T* ) {
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