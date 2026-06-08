#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1) ~ O(26) for lowercase letters*/
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> freq;
    for (int i = 0; i < s.size(); i++) {
        char ch1 = s[i];
        char ch2 = t[i];
        freq[ch1] += 1;
        freq[ch2] -= 1;
    }

    // checking the frequencies
    for (auto [ch, f] : freq) {
        if (f != 0) return false;
    }
    return true;
}

int main() {
    // Example input
    string s = "anagram";
    string t = "nagaram";

    // Call the function
    bool result = isAnagram(s, t);

    // Print the result
    cout << (result ? "Valid Anagram" : "Not an Anagram");
    return 0;
}
