#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    // Example input
    vector<char> s = {'h','e','l','l','o'};

    // Call the function
    reverseString(s);

    // Print the result
    cout << "Reversed string: ";
    for (char ch : s) {
        cout << ch;
    }
    return 0;
}
