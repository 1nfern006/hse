#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>


int main() {
    std::string s;
    std::getline(std::cin, s);
    
    std::stack<char> st;
    std::unordered_map<char, char> seq = {{')', '('}, {']', '['}, {'}', '{'}};
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty() || st.top() != seq[c]) {
                std::cout << "no" << '\n';
                return 0;
            }
            st.pop();
        }
    }
    
    if (!st.empty()) {
        std::cout << "no";
    } else {
        std::cout << "yes ";
    }
    
    return 0;
}