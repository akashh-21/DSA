#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        bool flag = true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                flag = false;
            }
        }
        if(flag==true) break;
    }
}
int main(){
    vector<int> arr = {5,4,3,2,1};
    int n = arr.size();
    // bubble Sort
    bubbleSort(arr);
    // print the sorted array
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
