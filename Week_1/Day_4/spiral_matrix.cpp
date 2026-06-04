#include <bits/stdc++.h>
using namespace std;
/*time - O(N*M)
space - O(N*M)*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row_size = matrix.size();
    int col_size = matrix[0].size();

    int left = 0, top = 0, right = col_size - 1 , bottom = row_size - 1;
    vector<int> res;

    while (res.size() < row_size * col_size) {
        // on top from left to right
        for (int col = left; col <= right && res.size() < row_size * col_size; col++) {
            res.emplace_back(matrix[top][col]);
        }
        top++;
        // on right from top to bottom
        for (int row = top; row <= bottom && res.size() < row_size * col_size; row++) {
            res.emplace_back(matrix[row][right]);
        }
        right--;
        // on bottom from right to left
        for (int col = right; col >= left && res.size() < row_size * col_size; col--) {
            res.emplace_back(matrix[bottom][col]);
        }
        bottom--;
        // on left from bottom to top
        for (int row = bottom; row >= top && res.size() < row_size * col_size; row--) {
            res.emplace_back(matrix[row][left]);
        }
        left++;
    }
    return res;
}

int main() {
    // Example input
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the function
    vector<int> result = spiralOrder(matrix);

    // Print the result
    cout << "Spiral order: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
