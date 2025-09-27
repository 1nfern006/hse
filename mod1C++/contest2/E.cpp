#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    if ((a % 10 == a / 1000) && (a % 100 / 10 == a / 100 % 10)) {
        cout << 1;

    } else {
        cout << 2;
    }

    return 0;
    
}