#include <iostream>


void reverseP(int* a, int n) {
    int* newA = new int[n];
    for (int i = 0; i < n; ++i) {
        newA[a[i] - 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << newA[i] << " ";
    }
    delete[] newA;
}

int main() {
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        int s;
        std::cin >> s;
        a[i] = s;
    }
    reverseP(a, n);
    delete[] a;
    return 0;
}