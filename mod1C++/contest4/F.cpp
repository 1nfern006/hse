#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    int x = 0;
    int y = n;
    while (x < y) {
        for (int i = x; i < y; i++) {
            for (int j = x; j < y; j++) {
                if (i == x || i == (y - 1) || j == (y - 1) || (j == x && i != (x + 1))) {
                    arr[i][j] = 1;
                } 
            }
        }
        if (x > 0) {
            arr[x][x-1] = 1;
        }

        x += 2;
        y -= 2;

    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }
    
    
    return 0;
}
