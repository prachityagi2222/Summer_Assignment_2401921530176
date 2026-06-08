#include <bits/stdc++.h>
using namespace std;
/*time - O(N + M)
space - O(1) ~ O(26) for lowercase letters*/
bool canConstruct(string ransomNote, string magazine) {
    // storing frequencies for magazine
    vector<int> freq(26, 0);

    for (char ch : magazine) {
        freq[ch - 'a']++;
    }

    // check ransomNote characters
    for (char ch : ransomNote) {
        if (freq[ch - 'a'] == 0) return false;
        freq[ch - 'a']--;
    }

    return true;
}

int main() {
    // Example input
    string ransomNote = "aa";
    string magazine = "aab";

    // Call the function
    bool result = canConstruct(ransomNote, magazine);

    // Print the result
    cout << (result ? "Can construct ransom note" : "Cannot construct ransom note");
    return 0;
}
