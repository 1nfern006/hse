#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a > b && b > c) || (c > b && a < b)) {
        cout << b;
    } else if ((a > c && c > b) || (b > c && a < c)) {
        cout << c;
    } else {
        cout << a;
    }
    return 0;
    
}