#include <iostream>
using namespace std;



int main() {
    int v, t;
    int l = 109;
    cin >> v >> t;
    int s = v * t;
    int ost = s % l;
    cout << (ost >= 0 ? ost : (l + ost));
    return 0;
}