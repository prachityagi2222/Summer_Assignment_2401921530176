#include <bits/stdc++.h>
using namespace std;
/*time - O(N * k)
space - O(N)*/
// N = length of string, k = max repeat count
string decode(const string &s, int &i) {
    string result = "";
    int num = 0;

    while (i < s.size()) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0'); // build number
            i++;
        }
        else if (ch == '[') {
            i++; // skip '['
            string inner = decode(s, i); // decode inside brackets
            for (int k = 0; k < num; k++) result += inner;
            num = 0; // reset
        }
        else if (ch == ']') {
            i++; // skip ']'
            return result; // return to caller
        }
        else {
            result += ch; // normal character
            i++;
        }
    }

    return result;
}

string decodeString(string s) {
    int i = 0;
    return decode(s, i);
}

int main() {
    // Example input
    string s = "3[a2[c]]";

    // Call the function
    string result = decodeString(s);

    // Print the result
    cout << "Decoded string: " << result;
    return 0;
}
