#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotateMethod2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(n,vector<int>(m));
    int idx1 = 0;
    int idx2 = m-1;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            ans[idx1][idx2] = matrix[i][j];
            idx1 += 1;
        }
        idx1 = 0;
        idx2 -= 1;
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            matrix[i][j] = ans[i][j];
        }
    }
}
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void printMatrix(vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    rotate(matrix);

    cout << "\nRotated Matrix (90 degrees clockwise):\n";
    printMatrix(matrix);

    return 0;
}
