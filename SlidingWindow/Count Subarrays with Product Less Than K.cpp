#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0, p = 1, ans = 0;
    for (int j = 0; j < n; j++) {
        p *= nums[j];
        while (p >= k && i <= j) {
            p /= nums[i];
            i++;
        }
        ans += j - i + 1;
    }
    return ans;
}

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << "Number of subarrays with product less than " << k << ": " << numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}
