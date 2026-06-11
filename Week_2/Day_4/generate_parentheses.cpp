#include <bits/stdc++.h>
using namespace std;
/*time - O(4^N / sqrt(N))
space - O(N)*/
// Catalan number complexity
void backtrack(vector<string>& result, string current, int open, int close, int n) {
    if (current.size() == 2 * n) {
        result.push_back(current);
        return;
    }
    if (open < n) {
        backtrack(result, current + "(", open + 1, close, n);
    }
    if (close < open) {
        backtrack(result, current + ")", open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(result, "", 0, 0, n);
    return result;
}

int main() {
    // Example input
    int n = 3;

    // Call the function
    vector<string> result = generateParenthesis(n);

    // Print the result
    cout << "Generated parentheses combinations:\n";
    for (string &s : result) {
        cout << s << "\n";
    }
    return 0;
}
