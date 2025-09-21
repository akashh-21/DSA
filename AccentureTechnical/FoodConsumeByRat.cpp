// Problem Description :
// The function accepts two positive integers ‘r’ and ‘unit’ and a positive integer array ‘arr’ of size ‘n’ as its argument ‘r’ represents the number of rats present in an area, ‘unit’ is the amount of food each rat consumes and each ith element of array ‘arr’ represents the amount of food present in ‘i+1’ house number, where 0 <= i

// Note:

// Return -1 if the array is null
// Return 0 if the total amount of food from all houses is not sufficient for all the rats.
// Computed values lie within the integer range.

// Example:

// Input:
    // r: 7
    // unit: 2
    // n: 8
    // arr: 2 8 3 5 7 4 1 2
// Output:  4
#include<iostream>
#include<vector>
using namespace std;
int totalAmountOfFood(vector<int>& arr,int r,int units){
    if(arr.size()==0) return -1;
    int totalAmount = r*units; // Total amount of food required for all rats = r * unit
    int amount = 0;
    for(int val:arr){
        amount +=val;
        if(amount>=totalAmount) return amount;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i]; //  ith element of array ‘arr’ represents the amount of food present in ‘i+1’ 
    int r; //  ‘r’ represents the number of rats present in an area
    cin>>r;
    int units;
    cin>>units; //  ‘unit’ is the amount of food each rat consumes
    cout<<totalAmountOfFood(arr,r,units);
    return 0;
}