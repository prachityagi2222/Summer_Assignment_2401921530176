#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
int maxSubArray(vector<int>& nums) {
    int max_sum = nums[0];
    int curr_sum = nums[0];
    int n = nums.size();
    
    for (int i = 1; i < n; i++) {
        curr_sum = max(nums[i], curr_sum + nums[i]);
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}

int main() {

    // Example input
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Call the function
    int result = maxSubArray(nums);

    // Print the result
    cout << "Maximum Subarray Sum: " << result;
    return 0;
}
