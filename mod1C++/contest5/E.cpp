#include <iostream>


void maximum(int** a, int n, int m) {
    int maxV = a[0][0];
    int maxX = 0;
    int maxY = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > maxV) {
                maxV = a[i][j];
                maxX = i;
                maxY = j;
            }
        }
    }
    std::cout << maxX << " " << maxY << '\n';
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
    maximum(a, n, m);

    for(int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}