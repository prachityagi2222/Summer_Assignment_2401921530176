#include <bits/stdc++.h>
using namespace std;
/*time - O(1) amortized for push/pop/peek/empty
space - O(N)*/
// N = number of elements
class MyQueue {
public:
    stack<int> stIn;   // input stack
    stack<int> stOut;  // output stack

    MyQueue() {}

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        peek(); // ensure stOut has the front
        int val = stOut.top();
        stOut.pop();
        return val;
    }

    int peek() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

int main() {
    MyQueue q;

    // Example usage
    q.push(1);
    q.push(2);
    cout << "Peek: " << q.peek() << "\n"; // 1
    cout << "Pop: " << q.pop() << "\n";   // 1
    cout << "Empty? " << (q.empty() ? "Yes" : "No") << "\n"; // No

    return 0;
}
