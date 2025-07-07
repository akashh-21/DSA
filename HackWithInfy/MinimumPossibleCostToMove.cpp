#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {2,3,5,7,11};
    int n = arr.size();
    int i=0;
    int cnt = 0;
    while(i<n-1){
        bool flag = false;
        int j = n-1;
        while(i<j){
            if(arr[i]!=arr[j] && arr[j]%arr[i]==0) {
                flag = true;
                break;
            }
            j--;
        }
        if(flag){
            cnt+= arr[i];
            arr[j] += 1;
            i = j;
        }
        else {
            cnt++;
            i++;
        }
    }
    cout<<cnt;
    
    return 0;
}