#include <iostream>
using namespace std;

int main() {
    int a, n;
    cin >> a >> n;
    int bits = 1 << n;  
    int ans = a & (bits - 1);
    cout << ans;
    return 0;
    
}