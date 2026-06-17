#include <bits/stdc++.h>
using namespace std;

/*time - O(1) for all operations
space - O(N)*/
// N = number of elements pushed
class MinStack {
public:
    stack<int> st;     // normal stack
    stack<int> minSt;  // stack to track minimums

    MinStack() {}

    void push(int value) {
        st.push(value);
        if (minSt.empty()) {
            minSt.push(value);
        } else {
            minSt.push(min(value, minSt.top()));
        }
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {
    MinStack obj;

    // Example usage
    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    cout << "Current minimum: " << obj.getMin() << "\n"; // -3
    obj.pop();
    cout << "Top element: " << obj.top() << "\n";        // 0
    cout << "Current minimum: " << obj.getMin() << "\n"; // -2

    return 0;
}
