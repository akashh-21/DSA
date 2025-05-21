#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m, false);   // Marks for rows that should be zero
    vector<int> colmn(n, false); // Marks for columns that should be zero

    // Step 1: Traverse and mark rows and columns where 0 is found
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                row[i] = true;
                colmn[j] = true;
            }
        }
    }

    // Step 2: Set rows to zero where marked
    for(int i = 0; i < m; i++) {
        if(row[i]) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Set columns to zero where marked
    for(int j = 0; j < n; j++) {
        if(colmn[j]) {
            for(int i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    setZeroes(matrix);

    cout << "Modified matrix:\n";
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
