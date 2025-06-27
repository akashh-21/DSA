#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        for (char ch : t) m[ch]--;

        int i = 0; // Left pointer
        int start = 0; // Start index of the answer
        int ans = INT_MAX; // Minimum length of window
        int cnt = 0; // Count of characters from t matched in window

        for (int j = 0; j < s.length(); j++) {
            char ch = s[j];
            m[ch]++;

            if (m[ch] <= 0) cnt++;

            while (cnt == t.length()) {
                if (ans > j - i + 1) {
                    ans = j - i + 1;
                    start = i;
                }

                char c = s[i];
                m[c]--;

                if (m[c] < 0) cnt--;

                i++;
            }
        }

        if (ans == INT_MAX) return "";
        return s.substr(start, ans);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "Minimum window: " << sol.minWindow(s, t) << endl;
    return 0;
}
