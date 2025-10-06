#include <iostream>


void swap(int** a, int n, int r, int s) {
    int dop;
    for (int i = 0; i < n; ++i) {
        dop = a[i][r];
        a[i][r] = a[i][s];
        a[i][s] = dop;
    }
    
} 

int main() {
    int n, m, r, s;
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
    std::cin >> r >> s;
    
    swap(a, n, r, s);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << '\n';
    }
    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}