#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
// N = length of nums
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        // remove indices out of current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // maintain decreasing order in deque
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // record max for window
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main() {
    // Example input
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    // Call the function
    vector<int> result = maxSlidingWindow(nums, k);

    // Print the result
    cout << "Sliding window maximums: ";
    for (int x : result) cout << x << " "; // Expected: 3 3 5 5 6 7
    return 0;
}
