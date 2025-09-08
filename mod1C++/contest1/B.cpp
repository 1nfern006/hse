#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    int r = n % 2;
    cout << n + 2 - r;
    return 0;
}