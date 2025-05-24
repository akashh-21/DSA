#include <iostream>
#include <string>
using namespace std;

int sumSubstrings(string &s) {
    int sum = s[0] - '0';
    int tsum = s[0] - '0';
    for (int i = 1; i < s.length(); i++) {
        tsum = (i + 1) * (s[i] - '0') + tsum * 10;
        sum += tsum;
    }
    return sum;
}

int main() {
    string s;
    cout << "Enter a numeric string: ";
    cin >> s;

    int result = sumSubstrings(s);
    cout << "Sum of all numeric substrings is: " << result << endl;

    return 0;
}
