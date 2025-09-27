#include <iostream>
using namespace std;

int main() {
    char input;
    cin >> input;
    char a = 'a';   
    if (('A' <= input && input <= 'Z') || ('a' <= input && input <= 'z')) {
        cout << "correct";
    } else {
        cout << "incorrect";
    }
    return 0;
    
}