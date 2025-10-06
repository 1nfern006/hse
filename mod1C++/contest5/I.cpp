#include <iostream>


void Sort(int* begin, int* end) {
    int num = end - begin;
    int dop;
    for (int i = 0; i < num - 1; ++i) {
        for (int* n = begin; n < end - i - 1; ++n) {
            if (*n > *(n + 1)) {
                dop = *n;
                *n = *(n + 1);
                *(n + 1) = dop;
            }
        }
    }
} 

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    Sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}