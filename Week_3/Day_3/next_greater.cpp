#include <bits/stdc++.h>
using namespace std;
/*time - O(N + M)
space - O(N)*/
// N = length of nums2, M = length of nums1
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater; // element -> next greater element
    stack<int> st;

    // Process nums2 from left to right
    for (int num : nums2) {
        while (!st.empty() && st.top() < num) {
            nextGreater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    // Elements left in stack have no greater element to their right
    while (!st.empty()) {
        nextGreater[st.top()] = -1;
        st.pop();
    }

    // Build answer for nums1 using the map
    vector<int> ans;
    for (int num : nums1) {
        ans.push_back(nextGreater[num]);
    }
    return ans;
}

int main() {
    // Example input
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    // Call the function
    vector<int> result = nextGreaterElement(nums1, nums2);

    // Print the result
    cout << "Next greater elements: ";
    for (int x : result) cout << x << " ";
    return 0;
}
