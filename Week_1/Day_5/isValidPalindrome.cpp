#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(N)*/
bool isPalindrome(string s) {
    // converting the word into proper string
    string str;
    for (char ch : s) {
        if (ch >= 'A' && ch <= 'Z') {
            // is uppercase
            ch = ch + 32;
            str += ch;
        }
        else if (ch >= 'a' && ch <= 'z') {
            str += ch;
        }
        else if (ch >= '0' && ch <= '9') {
            str += ch;
        }
    }

    // checking for valid palindrome
    auto left = str.begin();
    auto right = str.end() - 1;

    while (left < right) {
        if (*left != *right) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    // Example input
    string s = "A man, a plan, a canal: Panama";

    // Call the function
    bool result = isPalindrome(s);

    // Print the result
    cout << (result ? "Valid Palindrome" : "Not a Palindrome");
    return 0;
}
