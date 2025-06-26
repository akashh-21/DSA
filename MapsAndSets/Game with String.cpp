#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int check(unordered_map<char,int>& m){
        int cnt = 0;
        for(auto x : m){
            int pow = x.second;
            cnt += (pow * pow);
        }
        return cnt;
    }

    int minValue(string &s, int k) {
        unordered_map<char, int> m;
        for(char ch : s) m[ch]++;
        
        while(k--){
            int mx = INT_MIN;
            char ch;
            for(auto x : m){
                if(x.second > mx){
                    mx = x.second;
                    ch = x.first;
                }
            }
            m[ch]--;
        }
        return check(m);
    }
};

int main() {
    Solution sol;
    string s = "abbccc";  // Example string
    int k = 2;            // Number of characters to remove
    int result = sol.minValue(s, k);
    cout << "Minimum value after removing " << k << " characters: " << result << endl;
    return 0;
}
