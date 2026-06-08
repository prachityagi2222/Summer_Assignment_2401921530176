#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1) ~ O(26) for lowercase letters*/
int firstUniqChar(string s) {
    // store frequency 
    unordered_map<char, int> freq;
    for (char &ch : s) {
        freq[ch]++;
    }

    // now iterate and find out the first non-repeating index
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) return i;
    }
    return -1;
}

int main() {
    // Example input
    string s = "leetcode";

    // Call the function
    int result = firstUniqChar(s);

    // Print the result
    if (result != -1) {
        cout << "First unique character index: " << result;
    } else {
        cout << "No unique character found";
    }
    return 0;
}
