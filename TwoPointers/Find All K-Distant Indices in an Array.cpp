#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> s;

        for(int i = 0; i < n; i++) {
            if(nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for(int j = start; j <= end; j++) {
                    s.insert(j);
                }
            }
        }

        return vector<int>(s.begin(), s.end());
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9, k = 1;
    vector<int> result = sol.findKDistantIndices(nums, key, k);

    cout << "K-Distant Indices: ";
    for(int idx : result) {
        cout << idx << " ";
    }
    cout << endl;
    return 0;
}
