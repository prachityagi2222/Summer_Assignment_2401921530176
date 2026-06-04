#include <bits/stdc++.h>
using namespace std;
/*time - O(N*M)
space - O(N*M)*/
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int n = mat.size();
    int m = mat[0].size();

    if (r * c != n * m) return mat;

    // storing elements
    vector<int> elements;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            elements.push_back(mat[i][j]);
        }
    }

    // make new matrix
    vector<vector<int>> new_matrix(r, vector<int>(c, 0));
    auto itr = elements.begin();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            new_matrix[i][j] = *itr;
            ++itr;
        }
    }

    return new_matrix;
}

int main() {
    // Example input
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    };
    int r = 1, c = 4;

    // Call the function
    vector<vector<int>> result = matrixReshape(mat, r, c);

    // Print the result
    cout << "Reshaped matrix:" << endl;
    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
