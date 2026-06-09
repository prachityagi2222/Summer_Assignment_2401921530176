#include <bits/stdc++.h>
using namespace std;
/*time - O(N + M)
space - O(1) ~ O(26) for lowercase letters*/
bool checkInclusion(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 > n2) return false;

    // counting frequency
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    for (char ch : s1) freq1[ch - 'a']++;

    // first window
    for (int i = 0; i < n1; i++) {
        freq2[s2[i] - 'a']++;
    }

    if (freq1 == freq2) return true;

    // sliding window
    for (int i = n1; i < n2; i++) {
        freq2[s2[i] - 'a']++;
        freq2[s2[i - n1] - 'a']--;
        if (freq1 == freq2) return true;
    }

    return false;
}

int main() {
    // Example input
    string s1 = "ab";
    string s2 = "eidbaooo";

    // Call the function
    bool result = checkInclusion(s1, s2);

    // Print the result
    cout << (result ? "Permutation exists in string" : "Permutation does not exist");
    return 0;
}
