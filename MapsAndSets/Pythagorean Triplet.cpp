#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool pythagoreanTriplet(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Square all elements
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * arr[i];
    }

    // Step 2: Store all squared values in a set
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    // Step 3: Check every pair for a^2 + b^2 = c^2
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (s.find(sum) != s.end()) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<int> arr = {3, 2, 4, 6, 5};

    if (pythagoreanTriplet(arr)) {
        cout << "Yes, a Pythagorean triplet exists in the array.\n";
    } else {
        cout << "No, there is no Pythagorean triplet in the array.\n";
    }

    return 0;
}
