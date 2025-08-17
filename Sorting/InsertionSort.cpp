#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int>& arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int j = i;
        while(j>=1 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
int main(){
    vector<int> arr = {5,4,3,2,1};
    int n = arr.size();
    // Insertion Sort
    insertionSort(arr);
    // print the sorted array
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
