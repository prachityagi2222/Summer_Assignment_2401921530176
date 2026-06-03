#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
void moveZeroes(vector<int>& nums) {
    int i = 0; // pointer for non-zero position
    int n = nums.size();
    for (int j = 0; j < n; j++) {
        if (nums[j] != 0) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
}

int main() {
    // Example input
    vector<int> nums = {0, 1, 0, 3, 12};

    // Call the function
    moveZeroes(nums);

    // Print the result
    cout << "Array after moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}
