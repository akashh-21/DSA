#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    vector<int> arr(n1+n2);
    int i=n1-1,j=n2-1,k=n1+n2-1;
    while(i>=0 && j>=0)
    {
        if(nums1[i]>=nums2[j])
        {
            arr[k] = nums1[i];
            k--;
            i--;
        }
        else{
            arr[k] = nums2[j];
            k--;
            j--;
        }
    }
    while(j>=0)
    {
        arr[k] = nums2[j];
        k--;
        j--;
    }
    while(i>=0)
    {
        arr[k] = nums1[i];
        k--;
        i--;
    }
    int n = arr.size();
    if(arr.size()%2==0)
    {
        double x = arr[n/2]+arr[(n/2)-1];
        x = x/2;
        return x;
    }
    else{
        double x = double(arr[arr.size()/2]);
        return x;
    }
}

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median of two sorted arrays is: " << median << endl;

    return 0;
}
