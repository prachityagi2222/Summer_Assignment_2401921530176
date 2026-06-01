#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    //using hashmaps
    for (int i = 0; i < nums.size(); i++){
        int required = target - nums[i];
        if (seen.find(required) != seen.end()) return {seen[required], i};
        seen[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {

    // Example input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call the function
    vector<int> result = twoSum(nums, target);

    // Print the result
    cout<<result[0]<<" "<<result[1];
    return 0;
}
