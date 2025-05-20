#include <iostream>
#include <vector>
using namespace std;

// Standalone function (no class)
bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> diffArray(n + 1, 0);

    // Step 1: Build the difference array
    for (int i = 0; i < queries.size(); i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        diffArray[left] += 1;
        if (right + 1 < n)
            diffArray[right + 1] -= 1;
    }

    // Step 2: Apply difference and check if all elements are zero or less
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += diffArray[i];
        if (sum < nums[i])
            return false;
    }

    return true;
}

int main() {
    // Example input
    vector<int> nums = {2, 1, 1};
    vector<vector<int>> queries = {{0, 1}, {1, 2}};

    bool result = isZeroArray(nums, queries);

    if (result)
        cout << "All elements are zero or less after queries.\n";
    else
        cout << "Some elements are still greater than zero.\n";

    return 0;
}
