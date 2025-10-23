#include <iostream>
#include <thread>
#include <chrono>

int main() {
    const char symbols[] = {'-', '\\', '|', '/'};
    int num = 4;

    std::cout << "Loading: ";

    for (int i = 0; i < 50; ++i) {
        std::cout << symbols[i % num] << "\r" << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Loading: " << std::flush;

    }

    std::cout << "Done!" << '\n';
    return 0;
}