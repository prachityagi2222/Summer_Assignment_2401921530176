#include <bits/stdc++.h>
using namespace std;
/*time - O(N) worst case per ping
space - O(N)*/
// N = number of pings stored
class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        // remove all requests older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

int main() {
    RecentCounter obj;

    // Example usage
    cout << obj.ping(1) << "\n";     // 1
    cout << obj.ping(100) << "\n";   // 2
    cout << obj.ping(3001) << "\n";  // 3
    cout << obj.ping(3002) << "\n";  // 3

    return 0;
}
    