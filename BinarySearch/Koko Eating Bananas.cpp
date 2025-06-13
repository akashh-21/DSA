#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check(int speed, vector<int>& piles, int h) {
    long long hoursNeeded = 0;
    for (int pile : piles) {
        hoursNeeded += ceil((double)pile / speed);
    }
    return hoursNeeded <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int maxPile=-1;
    for(int i=0;i<n;i++)
    {
        maxPile=max(maxPile,piles[i]);
    }
    int low = 1, high = maxPile;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, piles, h)) {
            ans = mid;
            high = mid - 1;  // try to find a smaller speed
        } else {
            low = mid + 1;   // need to eat faster
        }
    }

    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum eating speed: " << minEatingSpeed(piles, h) << endl;
    return 0;
}
