#include <iostream>
#include <algorithm>
using namespace std;

// Count how many numbers in the multiplication table are <= val
int count(int val, int m, int n) {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        cnt += min(val / i, n);
    }
    return cnt;
}

// Main function to find the k-th smallest number
int kthSmallest(int m, int n, int k) {
    int lo = 1, hi = m * n;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (count(mid, m, n) < k) {
            lo = mid + 1; // move right
        } else {
            hi = mid - 1; // move left
        }
    }
    return lo;
}

int main() {
    int m = 3, n = 3, k = 5;
    cout << "The " << k << "-th smallest number is: " << kthSmallest(m, n, k) << endl;
    return 0;
}
