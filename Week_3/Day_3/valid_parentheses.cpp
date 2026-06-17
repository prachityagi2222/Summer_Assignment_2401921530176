#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
// N = length of string
bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            if ((ch == ')' && st.top() == '(') ||
                (ch == '}' && st.top() == '{') ||
                (ch == ']' && st.top() == '[')) {
                st.pop();
            } else return false;
        }
    }
    return st.empty();
}

int main() {
    // Example input
    string s = "{[()]}";

    // Call the function
    bool result = isValid(s);

    // Print the result
    cout << (result ? "Valid parentheses" : "Invalid parentheses");
    return 0;
}
