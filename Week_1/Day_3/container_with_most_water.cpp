#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
int maxArea(vector<int>& height) {
    int left = 0;                  // start pointer
    int right = height.size() - 1; // end pointer
    int max_area = 0;

    while (left < right) {
        // calculate area between two lines
        int area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, area);

        // move the smaller line inward
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_area;
}

int main() {
    // Example input
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    // Call the function
    int result = maxArea(height);

    // Print the result
    cout << "Maximum area: " << result;
    return 0;
}
