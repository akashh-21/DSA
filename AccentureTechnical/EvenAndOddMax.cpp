/*
You are required to implement the following Function 

def LargeSmallSum(arr)

The function accepts an integers arr of size ’length’ as its arguments you are required to return the sum of second largest  element from the even positions and second smallest from the odd position of given ‘arr’

Assumption:

All array elements are unique
Treat the 0th position as even
NOTE

Return 0 if array is empty
Return 0, if array length is 3 or less than 3
Example

Input

arr:3 2 1 7 5 4

Output

7
Explanation

Second largest among even position elements(1 3 5) is 3
Second smallest among odd position element is 4
Thus output is 3+4 = 7

*/
/* Problem Description :
You are given a function.
int CheckPassword(char str[], int n);
The function accepts string str of size n as an argument. Implement the function which returns 1 if given string str is valid password else 0.
str is a valid password if it satisfies the below conditions.

– At least 4 characters
– At least one numeric digit
– At Least one Capital Letter
– Must not have space or slash (/)
– Starting character must not be a number
Assumption:
Input string will not be empty.

Example:

Input 1:
aA1_67
Input 2:
a987 abC012

Output 1:
1
Output 2:
0 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LargeSmallSum(vector<int>& arr){
    int n = arr.size();
    if(n<=3) return 0;
    vector<int> even,odd;
    for(int i=0;i<n;i++){
        if(i%2==0) even.push_back(arr[i]);
        else odd.push_back(arr[i]);
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    return even[even.size()-2] + odd[1];
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<LargeSmallSum(arr);
    return 0;
} 
