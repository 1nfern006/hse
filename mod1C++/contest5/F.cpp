#include <iostream>


void transposed(int** a, int n, int m) {
    int** trA = new int*[m];
    for (int i = 0; i < m ; ++ i) {
        trA[i] = new int[n];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            trA[i][j] = a[j][i];
            std::cout << trA[i][j] << " ";
        }
        std::cout << '\n';
    }

    for(int i = 0; i < m; ++i) {
        delete[] trA[i];
    }
    delete[] trA;
} 

int main() {
    int n, m;
    std::cin >> n >> m;
    int** a = new int*[n];
    for (int i = 0; i < n ; ++ i) {
        a[i] = new int[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
        }
    }
    transposed(a, n, m);

    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}