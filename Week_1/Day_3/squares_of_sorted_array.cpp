#include <bits/stdc++.h>
using namespace std;
/*time - O(N log N)
space - O(N)*/
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result;
    for (int num : nums) {
        result.push_back(num * num); // square each number
    }
    sort(result.begin(), result.end()); // sort the squared values
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
