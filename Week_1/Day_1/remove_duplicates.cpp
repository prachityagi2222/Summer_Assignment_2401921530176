#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
int removeDuplicates(vector<int>& nums) {
    int k = 0;
    int n = nums.size();
    if (n == 1) return k + 1;
    for (int i = 1; i < n; i++) {
        if (nums[k] == nums[i]) continue;
        k++;
        nums[k] = nums[i];
    }
    return k + 1;
}

int main() {

    // Example input
    vector<int> nums = {1, 1, 2, 2, 3};

    // Call the function
    int k = removeDuplicates(nums);

    // Print the result
    cout << "Unique elements count: " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
