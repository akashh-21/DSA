#include<iostream>
#include<vector>
using namespace std;
int maxSubarraySum(vector<int> &arr) {
    int maxvalue = arr[0];
    int currmax = arr[0];
    for(int i=1;i<arr.size();i++){
        currmax = max(arr[i],currmax+arr[i]);
        maxvalue = max(maxvalue,currmax);
    }
    return maxvalue;
}
int main(){
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout<<maxSubarraySum(arr);
    return 0;
}

