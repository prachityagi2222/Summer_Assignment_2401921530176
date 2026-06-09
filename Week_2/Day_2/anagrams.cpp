#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1) ~ O(26) for lowercase letters*/
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int n1 = s.size();
    int n2 = p.size();
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    if (n2 > n1) return result;

    // freq of p
    for (char ch : p) freq2[ch - 'a']++;

    // freq of first window
    for (int i = 0; i < n2; i++) freq1[s[i] - 'a']++;
    if (freq1 == freq2) result.push_back(0);

    // sliding window
    for (int i = n2; i < n1; i++) {
        freq1[s[i] - 'a']++;
        freq1[s[i - n2] - 'a']--;
        if (freq1 == freq2) result.push_back(i - n2 + 1);
    }

    return result;
}

int main() {
    // Example input
    string s = "cbaebabacd";
    string p = "abc";

    // Call the function
    vector<int> result = findAnagrams(s, p);

    // Print the result
    cout << "Anagram starting indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    return 0;
}
