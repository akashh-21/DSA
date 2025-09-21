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
using namespace std;
bool PasswordChecker(string& s){
    int n = s.length();
    if(n<4) return false;
    if(isdigit(s[0])) return false;
    bool digit = false , caps = false;
    for(int i=1;i<n;i++){
        if(isdigit(s[i])){
            digit = true;
        }
        else if(isalpha(s[i])){
            if(isupper(s[i])) caps = true;
        }
        else if(s[i]==' ' || s[i]=='/'){
            return false;
        }
    }
    return (digit && caps);
}
int main()
{
    string s;
    getline(cin,s);
    cout<<PasswordChecker(s);
    return 0;
} 
