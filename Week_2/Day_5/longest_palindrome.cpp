#include <bits/stdc++.h>
using namespace std;
/*time - O(N^2)
space - O(1)*/
// N = length of string
string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0, maxLen = 1;

    // Helper function to expand around center
    auto expand = [&](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Length is (right - left - 1), start is (left + 1)
        int len = right - left - 1;
        if (len > maxLen) {
            maxLen = len;
            start = left + 1;
        }
    };

    for (int i = 0; i < s.length(); i++) {
        expand(i, i);     // Odd length palindrome
        expand(i, i + 1); // Even length palindrome
    }

    return s.substr(start, maxLen);
}

int main() {
    // Example input
    string s = "babad";

    // Call the