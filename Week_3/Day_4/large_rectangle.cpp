#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
// N = number of bars
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st; // stores indices
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n ? 0 : heights[i]);
        while (!st.empty() && currHeight < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    // Example input
    vector<int> heights = {2,1,5,6,2,3};

    // Call the function
    int result = largestRectangleArea(heights);

    // Print the result
    cout << "Largest rectangle area: " << result; // Expected: 10
    return 0;
}
