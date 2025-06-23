#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to add two large numbers represented as strings
    string addString(string n1, string n2) {
        int i = n1.size() - 1;
        int j = n2.size() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int d1 = (i >= 0) ? (n1[i] - '0') : 0;
            int d2 = (j >= 0) ? (n2[j] - '0') : 0;
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans += (sum + '0');
            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    // Function to compute the minimum sum formed by adding two numbers
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string n1 = "", n2 = "";

        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) n1 += (arr[i] + '0');
            else n2 += (arr[i] + '0');
        }

        return addString(n1, n2);
    }
};

// Sample usage
int main() {
    Solution sol;
    vector<int> digits = {6, 8, 4, 5, 2, 3};
    cout << "Minimum Sum: " << sol.minSum(digits) << endl;
    return 0;
}
