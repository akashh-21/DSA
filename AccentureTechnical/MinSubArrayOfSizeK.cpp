#include<iostream>
#include<vector>
using namespace std;
void minSubarraySum( vector<int>& arr,int k){
    int n = arr.size();
    if(k<=0 || k>n){
        cout<<"NULL";
        return;
    }
    
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    int startIdx = -1;
    int endIdx = -1;
    int i = 1;
    int j = k;
    while(j<n){
        int s = sum - arr[i-1] + arr[j];
        if(s<sum){
            sum = s;
            startIdx = i;
            endIdx = j;
        }
    }
    for(int i=startIdx;i<=endIdx;i++) cout<<arr[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    minSubarraySum(arr,k);
    return 0;
} 
