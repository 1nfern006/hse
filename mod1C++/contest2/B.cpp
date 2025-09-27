#include <iostream>
using namespace std;

int main() {
    int input;
    int p;
    cin >> input >> p;
    int a = (input >> p) % 2;
    cout << a;
    return 0;
    
}