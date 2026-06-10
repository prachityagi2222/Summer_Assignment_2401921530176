#include <bits/stdc++.h>
using namespace std;
/*time - O(N^2)
space - O(1)*/
bool repeatedSubstringPattern(string s) {
    int n = s.size();

    // try all possible substring lengths up to n/2
    for (int len = 1; len <= n / 2; len++) {
        if (n % len != 0) continue; // must divide evenly

        bool ok = true;
        // check if repeating substring of length len forms the whole string
        for (int i = len; i < n; i++) {
            if (s[i] != s[i % len]) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    // Example input
    string s = "abab";

    // Call the function
    bool result = repeatedSubstringPattern(s);

    // Print the result
    cout << (result ? "String can be formed by repeating a substring"
                    : "String cannot be formed by repeating a substring");
    return 0;
}
