/* Problem Description :
The Binary number system only uses two digits, 0 and 1 and number system can be called binary string. You are required to implement the following function:

int OperationsBinaryString(char* str);

The function accepts a string str as its argument. The string str consists of binary digits eparated with an alphabet as follows:

– A denotes AND operation
– B denotes OR operation
– C denotes XOR Operation
You are required to calculate the result of the string str, scanning the string to right taking one opearation at a time, and return the same.

Note:

No order of priorities of operations is required
Length of str is odd
If str is NULL or None (in case of Python), return -1  */
#include<iostream>
#include<vector>
using namespace std;
int OperationsBinaryString(string& s){
    int n = s.length();
    if(n==0) return -1;
    int res = s[0]-'0';
    for(int i=1;i<n;i++){
        if(isalpha(s[i])){
            if(s[i]=='A') res &= (s[i+1]-'0');
            else if(s[i]=='B') res |= (s[i+1]-'0');
            else res ^= (s[i+1]-'0');
        }
    }
    return res;
}
int main()
{
    string s;
    cin>>s;
    cout<<OperationsBinaryString(s);
    return 0;
} 
