#include <bits/stdc++.h>
using namespace std;
/*time - O(N)
space - O(1)*/
int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size(); // matrix is square
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += mat[i][i];           // main diagonal
        sum += mat[i][n - i - 1];   // secondary diagonal
    }

    // subtract the middle element if counted twice (odd size matrix)
    if (n % 2 != 0) {
        sum -= mat[n / 2][n / 2];
    }

    return sum;
}

int main() {
    // Example input
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Call the function
    int result = diagonalSum(mat);

    // Print the result
    cout << "Diagonal sum: " << result;
    return 0;
}
