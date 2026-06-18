#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
// N = number of days
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st; // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top();
            st.pop();
            ans[idx] = i - idx; // days until warmer temperature
        }
        st.push(i);
    }
    return ans;
}

int main() {
    // Example input
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    // Call the function
    vector<int> result = dailyTemperatures(temperatures);

    // Print the result
    cout << "Days until warmer temperature: ";
    for (int x : result) cout << x << " ";
    return 0;
}
