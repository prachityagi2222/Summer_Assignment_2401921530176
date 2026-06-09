#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
int lengthOfLongestSubstring(string s) {
    unordered_set<char> st;
    int max_length = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
        while (st.count(s[right])) {
            st.erase(s[left]);
            left++;
        }
        st.insert(s[right]);
        max_length = max(max_length, right - left + 1);
    }
    return max_length;
}

int main() {
    // Example input
    string s = "abcabcbb";

    // Call the function
    int result = lengthOfLongestSubstring(s);

    // Print the result
    cout << "Length of longest substring without repeating characters: " << result;
    return 0;
}
