#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> a(n); // NSI: Next Smaller Index
        vector<int> b(n); // PSI: Previous Smaller Index
        stack<int> st1, st2;

        // Compute NSI (Next Smaller Index)
        for (int i = n - 1; i >= 0; i--) {
            while (!st1.empty() && arr[st1.top()] >= arr[i])
                st1.pop();
            a[i] = st1.empty() ? n : st1.top();
            st1.push(i);
        }

        // Compute PSI (Previous Smaller Index)
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && arr[st2.top()] > arr[i])
                st2.pop();
            b[i] = st2.empty() ? -1 : st2.top();
            st2.push(i);
        }

        // Contribution of each element as minimum
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int left = i - b[i];
            int right = a[i] - i;
            ans = (ans + 1LL * arr[i] * left % mod * right % mod) % mod;
        }

        return (int)ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of Subarray Minimums: " << sol.sumSubarrayMins(arr) << endl;
}
