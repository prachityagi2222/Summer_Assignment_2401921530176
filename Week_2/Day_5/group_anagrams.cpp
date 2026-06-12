#include <bits/stdc++.h>
using namespace std;
/*time - O(N * K log K)
space - O(N * K)*/
// N = number of strings, K = max length of a string
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end()); // sorted string as key
        mp[key].push_back(str);
    }

    vector<vector<string>> result;
    for (auto &entry : mp) {
        result.push_back(entry.second);
    }
    return result;
}

int main() {
    // Example input
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    // Call the function
    vector<vector<string>> result = groupAnagrams(strs);

    // Print the result
    cout << "Grouped anagrams:\n";
    for (auto &group : result) {
        for (auto &word : group) {
            cout << word << " ";
        }
        cout << "\n";
    }
    return 0;
}
