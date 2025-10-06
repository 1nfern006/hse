#include <iostream>
#include <string>

bool valid(std::string pwd) {
    int cls1 = 0;
    int cls2 = 0;
    int cls3 = 0;
    int cls4 = 0;
    int len = pwd.length();

    if (len < 8 || len > 14) {
            return false;
    }
    

    for (int i = 0; i < len; ++i) {
        if (int(pwd[i]) < 33 || int(pwd[i]) > 127) {
            return false;
        }
        if (pwd[i] >= 'A' && pwd[i] <= 'Z') {
            cls1 = 1;
        } else if (pwd[i] >= 'a' && pwd[i] <= 'z') {
            cls2 = 1;
        } else if (pwd[i] >= '0' && pwd[i] <= '9') {
            cls3 = 1;
        } else {
            cls4 = 1;
        }
    }

    if ((cls1 + cls2 + cls3 + cls4) >= 3) {
        return true;
    }

    return false;
}

int main() {
    std::string pwd;
    std::cin >> pwd;
    if (valid(pwd)) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }
    return 0;
}