#include <bits/stdc++.h>
using namespace std;
/*time - O(N*M)
space - O(1)*/
// N = length of haystack, M = length of needle
int strStr(string haystack, string needle) {
    int n1 = haystack.size();
    int n2 = needle.size();
    if (n2 == 0) return 0;

    int index = 0;
    for (int i = 0; i < n1; i++) {
        if (haystack[i] == needle[index]) {
            index++;
            if (index == n2) {
                return i - n2 + 1; // correct starting position
            }
        } else {
            // reset index if mismatch
            i = i - index; // rewind to next start
            index = 0;
        }
    }
    return -1;
}

int main() {
    // Example input
    string haystack = "hello";
    string needle = "ll";

    // Call the function
    int result = strStr(haystack, needle);

    // Print the result
    if (result != -1) {
        cout << "Needle found at index: " << result;
    } else {
        cout << "Needle not found";
    }
    return 0;
}
