#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_map<char, int> hash;
    int left = 0, right = 0;
    int maxLen = 0;

    while (right < n) {
        char ch = s[right];

        // If character already exists in the map and is inside the window
        if (hash.find(ch) != hash.end()) {
            // Move the left pointer to avoid the duplicate
            left = max(hash[ch] + 1, left);
        }

        // Store/update the last index of the character
        hash[ch] = right;

        // Update the max length
        int len = right - left + 1;
        maxLen = max(maxLen, len);
        right++;
    }

    return maxLen;
}

int main() {
    string input = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " << lengthOfLongestSubstring(input) << endl;
    return 0;
}
