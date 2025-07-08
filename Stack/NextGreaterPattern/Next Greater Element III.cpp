#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int pivot = -1;

        // Step 1: Find the first decreasing element from the right
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot is found, it's already the largest permutation
        if (pivot == -1) return -1;

        // Step 2: Reverse the suffix (right part)
        reverse(s.begin() + pivot + 1, s.end());

        // Step 3: Find the next greater digit in suffix to swap with pivot
        for (int i = pivot + 1; i < s.length(); i++) {
            if (s[i] > s[pivot]) {
                swap(s[i], s[pivot]);
                break;
            }
        }

        // Step 4: Convert back to number, check if it's within int range
        long long result = stoll(s);
        return (result > INT_MAX) ? -1 : (int)result;
    }
};

int main() {
    Solution sol;
    int n = 12443322;
    int res = sol.nextGreaterElement(n);
    cout << "Next greater permutation: " << res << endl;
}
