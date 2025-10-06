#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    int arr[101][101];

    int num = 0;

    for (int s = 0; s <= ((n - 1) + (m - 1)); s++) {      
        for (int i = 0; i < n; i++) {
            int j = s - i;
        
            if (j >= 0 && j < m) {
                arr[i][j] = num;
                num++;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << '\n';
    }
    return 0;
}