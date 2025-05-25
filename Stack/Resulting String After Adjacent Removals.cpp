#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string resultingString(string s) {
    int n = s.length();
    stack<char> st;
    int i = 1;

    st.push(s[0]);

    while (i < n) {
        char top = st.empty() ? '\0' : st.top();
        char curr = s[i];

        // If characters are consecutive (like 'a' & 'b', or 'z' & 'a'), remove the top
        if (!st.empty() &&
            ((top == 'a' && curr == 'z') || (top == 'z' && curr == 'a') || abs(top - curr) == 1)) {
            st.pop();
        } else {
            st.push(curr);
        }
        i++;
    }

    // If stack is empty, return empty string
    if (st.empty()) return "";

    // Reconstruct the final string
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "abczd";
    cout << "Final resulting string: " << resultingString(s) << endl;
    return 0;
}
