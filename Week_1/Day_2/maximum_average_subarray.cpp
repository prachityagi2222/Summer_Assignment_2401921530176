#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double sum = 0;

    // Initial window sum
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    double max_sum = sum;

    // Sliding window
    for (int i = k; i < n; i++) {
        sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, sum);
    }

    return max_sum / k;
}

int main() {

    // Example input
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    // Call the function
    double result = findMaxAverage(nums, k);

    // Print the result
    cout << fixed << setprecision(5) << result;
    return 0;
}
