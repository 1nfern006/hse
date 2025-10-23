#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

int main() {
    int r = 10, m = 15, delay = 100;
    int** a = new int*[r];
    for (int i = 0; i < r ; ++ i) {
        a[i] = new int[m];
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = rand() % 10;
            std::cout << a[i][j] << " ";
        }
        std::cout << '\n';
    }

    for (int n = 0; n < 10; ++n) {
        std::cout << "\033[" << r << "A"; 
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = rand() % 10;
                std::cout << a[i][j] << " ";
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << '\n';
        }

    }
    


    return 0;
}