#include<iostream>
#include<vector>
using namespace std;
void sortColors(vector<int>& nums) {
    int noOfZeros = 0;
    int noOfOnes = 0;
    int noOfTwos = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0) noOfZeros++;
        else if(nums[i]==1) noOfOnes++;
        else noOfTwos++;
    }
    for(int i=0;i<nums.size();i++){
        if(i<noOfZeros) nums[i] = 0;
        else if(i<noOfOnes+noOfZeros) nums[i] = 1;
        else nums[i] = 2;
    }
}
int main(){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
