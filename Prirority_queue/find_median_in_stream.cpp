#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution{
    public:
        vector<double> getMedian(vector<int>& arr){
            // always left values of median is less than the median and right values of median is greater than the median
            // so we can use two heaps to solve this problem
            // one is max heap to store the left values of median
            // another is min heap to store the right values of median
            // the max heap will store the first half of the array and the min heap will store the second half
            // the max heap will store the values which are less than the median and the min heap will store the values which are greater than the median
            priority_queue<int> left;
            priority_queue<int, vector<int>, greater<int>> right;
            vector<double> ans;
            for(int val : arr){
                // if the left heap is empty or the value is less than the top of the left heap
                // because the left values to the median is always less than the median and right values to the median is always greater than the median
                if(left.size()==0 || val<=left.top()) left.push(val);
                else right.push(val);
                
                // if the size of the left heap is greater than the size of the right heap by more than 1 
                // we need to move the top of the left heap to the right heap
                // because the left values to the median is always less than the median and right values to the median is always greater than the median
                // so we need to move the top of the left heap to the right heap to make the size of the left heap and the right heap equal 
                // or the size of the right heap is greater than the size of the left heap by 1 
                // because the left values to the median is always less than the median and right values to the median is always greater than the median
                // so we need to move the top of the left heap to the right heap to make the size of the left heap and the right heap equal 
                if(left.size()>right.size()+1){
                    right.push(left.top());
                    left.pop();
                }
                else if(right.size()>left.size()){
                    left.push(right.top());
                    right.pop();
                }
                
                // if the size of the left heap and the right heap is equal then the median is the average of the top of the left heap and the top of the right heap
                // else if the size of the left heap is greater than the size of the right heap then the median is the top of the left heap 
                // else if the size of the right heap is greater than the size of the left heap the median is the top of the right heap 
                if(left.size()==right.size()) ans.push_back((double)(left.top()+right.top())/2);
                else {
                    if(left.size()>right.size()) ans.push_back((double)left.top());
                    else ans.push_back((double)right.top());
                }
            }
            return ans;
        }
};
int main(){
    Solution s;
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    // output 5.0, 10.0, 5.0, 4.0, 3.0, 4.0
    vector<double> ans = s.getMedian(arr);
    for(int val:ans) cout<<val<<" ";
    return 0;
}