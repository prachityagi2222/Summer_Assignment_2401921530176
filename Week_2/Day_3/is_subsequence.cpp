#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
// N = length of t
bool isSubsequence(string s, string t) {
    int n1 = s.size();
    int n2 = t.size();
    int index = 0; // tracking s
    int i = 0;
    if (n1 == 0) return true;
    while (i < n2) {
        if (s[index] == t[i]) {
            index++;
            if (index == n1) {
                return true;
            }
        }
        i++;
    }
    return false;
}

int main() {
    // Example input
    string s = "abc";
    string t = "ahbgdc";

    // Call the function
    bool result = isSubsequence(s, t);

    // Print the result
    cout << (result ? "s is a subsequence of t" : "s is not a subsequence of t");
    return 0;
}
