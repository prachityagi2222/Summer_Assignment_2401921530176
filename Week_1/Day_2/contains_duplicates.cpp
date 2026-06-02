#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numbers;
    for (int num : nums) {
        if (numbers.find(num) != numbers.end()) return true;
        numbers.insert(num);
    }
    return false;
}

int main() {

    // Example input
    vector<int> nums = {1, 2, 3, 1};

    // Call the function
    bool result = containsDuplicate(nums);

    // Print the result
    cout << (result ? "Contains Duplicate" : "No Duplicate");
    return 0;
}
