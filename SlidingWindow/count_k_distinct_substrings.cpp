
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Helper function to count substrings with at most k distinct characters
int count(string &s, int k) {
    int n = s.length();
    int distinctCount = 0, ans = 0;
    int i = 0;
    vector<int> freq(26, 0);  // Only lowercase letters

    for (int j = 0; j < n; j++) {
        freq[s[j] - 'a']++;
        if (freq[s[j] - 'a'] == 1)
            distinctCount++;

        while (distinctCount > k) {
            freq[s[i] - 'a']--;
            if (freq[s[i] - 'a'] == 0)
                distinctCount--;
            i++;
        }

        ans += (j - i + 1);
    }

    return ans;
}

// Main function to count substrings with exactly k distinct characters
int countSubstr(string& s, int k) {
    return count(s, k) - count(s, k - 1);
}

int main() {
    string s = "pqpqs";
    int k = 2;
    cout << "Substrings with exactly " << k << " distinct characters: " << countSubstr(s, k) << endl;
    return 0;
}
