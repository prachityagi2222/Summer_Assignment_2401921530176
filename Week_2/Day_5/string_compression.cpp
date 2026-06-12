#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
// N = length of chars
int compress(vector<char>& chars) {
    int n = chars.size();
    int write = 0; // position to write next character
    int i = 0;     // read pointer
    
    while (i < n) {
        char current = chars[i];
        int count = 0;
        
        // Count consecutive repeating characters
        while (i < n && chars[i] == current) {
            i++;
            count++;
        }
        
        // Write the character
        chars[write++] = current;
        
        // If count > 1, write the digits of count
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[write++] = c;
            }
        }
    }
    
    return write; // new length of the compressed array
}

int main() {
    // Example input
    vector<char> chars = {'a','a','b','b','c','c','c'};

    // Call the function
    int newLength = compress(chars);

    // Print the result
    cout << "Compressed length: " << newLength << "\n";
    cout << "Compressed chars: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    return 0;
}
