#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> arr(n1 + n2);
    int i = n1 - 1, j = n2 - 1, k = n1 + n2 - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            arr[k--] = nums1[i--];
        } else {
            arr[k--] = nums2[j--];
        }
    }
    while (j >= 0) {
        arr[k--] = nums2[j--];
    }
    while (i >= 0) {
        arr[k--] = nums1[i--];
    }

    int n = arr.size();
    if (n % 2 == 0) {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    } else {
        return double(arr[n / 2]);
    }
}

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median of two sorted arrays is: " << median << endl;

    return 0;
}
