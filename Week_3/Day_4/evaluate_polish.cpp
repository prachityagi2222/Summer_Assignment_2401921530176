#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
// N = number of tokens
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (string &token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b); // integer division
        } else {
            st.push(stoi(token)); // convert string to int
        }
    }
    return st.top();
}

int main() {
    // Example input: ["2","1","+","3","*"]
    vector<string> tokens = {"2","1","+","3","*"};

    // Call the function
    int result = evalRPN(tokens);

    // Print the result
    cout << "Evaluated RPN result: " << result; // (2+1)*3 = 9
    return 0;
}
