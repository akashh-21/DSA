#include<iostream>
#include<vector>
using namespace std;
int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    int buyStocks = prices[0];
    int profit = 0;
    for(int sellStocks:prices){
        if(sellStocks<buyStocks) buyStocks = sellStocks;
        profit = max(profit,sellStocks-buyStocks);
    }
    return profit;
}
int main(){
    vector<int> arr = {100, 180, 260, 310, 40, 535, 695};
    cout<<maximumProfit(arr);
    return 0;
}

