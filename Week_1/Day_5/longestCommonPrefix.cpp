#include <bits/stdc++.h>
using namespace std;
/*time - O(N log N + M)
space - O(1)*/
// N = number of strings, M = length of shortest string
string longestCommonPrefix(vector<string>& strs) {
    // sort the strings
    sort(strs.begin(), strs.end());

    // compare the first and the last strings
    string first = strs[0];
    string last = strs[strs.size() - 1];
    int i = 0;

    while (i < first.size() && i < last.size() && first[i] == last[i]) {
        i++;
    }

    return first.substr(0, i);
}

int main() {
    // Example input
    vector<string> strs = {"flower","flow","flight"};

    // Call the function
    string result = longestCommonPrefix(strs);

    // Print the result
    cout << "Longest common prefix: " << result;
    return 0;
}
