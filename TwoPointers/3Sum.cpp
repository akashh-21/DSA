#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = n - 1; i > 1; i--) {
        // Skip duplicate values for nums[i]
        if (i < n - 1 && nums[i] == nums[i + 1]) continue;

        int left = 0;
        int right = i - 1;
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                ans.push_back({nums[left], nums[right], nums[i]});

                // Skip duplicates for nums[left] and nums[right]
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10};

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets that sum to 0 are:\n";
    for (auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}
