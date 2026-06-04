#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int left = 0, right = n - 1;
    int pos = n - 1; // fill result from the end

    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare) {
            result[pos] = leftSquare;
            left++;
        } else {
            result[pos] = rightSquare;
            right--;
        }
        pos--;
    }
    return result;
}

int main() {
    // Example input
    vector<int> nums = {-4, -1, 0, 3, 10};

    // Call the function
    vector<int> result = sortedSquares(nums);

    // Print the result
    cout << "Sorted squares: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
