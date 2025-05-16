#include<iostream>
#include<vector>
using namespace std;
int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    int mn = prices[0];
    int mx = prices[0];
    int ans = 0;
    int i = 0;
    while(i<n-1){
        while(i<n-1 && prices[i]>=prices[i+1]) i++;
        mn = prices[i];
        while(i<n-1 && prices[i]<=prices[i+1]) i++;
        mx = prices[i];
        ans = ans+ (mx-mn);
    }
    return ans;
}
int main(){
    vector<int> arr = {100, 180, 260, 310, 40, 535, 695};
    cout<<maximumProfit(arr);
    return 0;
}

