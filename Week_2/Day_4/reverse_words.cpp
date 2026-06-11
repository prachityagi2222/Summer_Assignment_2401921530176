#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
string reverseWords(string s) {
    int n = s.length();
    string result = "";
    string word = "";

    // traversing each character till white space
    for (char &ch : s) {
        if (ch == ' ') {
            // reverse the word formed till now and add to the string
            reverse(word.begin(), word.end());
            result += word + " ";
            word = "";
        } else {
            word += ch;
        }
    }

    // handle last word
    reverse(word.begin(), word.end());
    result += word;

    return result;
}

int main() {
    // Example input
    string s = "Let's take LeetCode contest";

    // Call the function
    string result = reverseWords(s);

    // Print the result
    cout << "Reversed words string: " << result;
    return 0;
}
