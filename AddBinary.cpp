#include<iostream>
#include<algorithm>
using namespace std;
string addBinary(string& s1, string& s2) {
        // your code here
    int n = s1.length();
    int m = s2.length();
    int i = n-1;
    int j = m-1;
    string ans = "";
    int carry = 0;
    while(i>=0 || j>=0 || carry!=0){
        int x1 = (i>=0) ? s1[i]-'0' : 0;
        int x2 = (j>=0) ? s2[j]-'0' : 0;
        int sum = x1+x2+carry;
        carry = sum/2;
        sum = sum%2;
        ans += (sum+'0');
        i--;
        j--;
    }
    reverse(ans.begin(),ans.end());
    int cnt = 0; // leading zeros count;
    i = 0;
    while(i<ans.size() && ans[i]=='0') i++;
    ans = ans.substr(i);
    return ans;
}
int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    cout <<addBinary(s1,s2);
}