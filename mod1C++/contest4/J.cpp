#include <iostream>

int main() {
    int n, m, w;
    std::cin >> n >> m >> w;
    int arr[33][33];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < w; ++i) {
    int r, c;
    std::cin >> r >> c;
    r--; 
    c--;
    arr[r][c] = 13;


    for (int r1 = -1; r1 <= 1; ++r1) { 
        for (int c1 = -1; c1 <= 1; ++c1) { 
            if (r1 == 0 && c1 == 0) {
                continue;
            }

            int row = r + r1;
            int col = c + c1;

            if (row >= 0 && row < n && col >= 0 && col < m) {   
                if (arr[row][col] < 13) {
                    arr[row][col] += 1;
                }
            }
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] >= 13){
                std::cout << "*" << " ";
            } else {
                std::cout << arr[i][j] << " ";
            }
            
        }
        std::cout << '\n';
    }
    return 0;
}