#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void SelectSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int MinIdx = -1;
        int MinVal = INT_MAX;
        for(int j=i;j<n;j++){
            if(arr[i]<MinVal){
                MinVal = arr[j];
                MinIdx = j;
            }
        }
        swap(arr[i],arr[MinIdx]);
    }
}
int main(){
    vector<int> arr = {5,4,3,2,1};
    int n = arr.size();
    // Insertion Sort
    SelectSort(arr);
    // print the sorted array
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
