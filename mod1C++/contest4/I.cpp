#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int arr[101][101];


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) == (n - 1)) {
                arr[i][j] = 1;
            } else if ((i + j) < (n - 1)) {
                arr[i][j] = 0;
            } else {
                arr[i][j] = 2;
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << '\n';
    }
    return 0;
}