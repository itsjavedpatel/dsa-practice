#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calculateHours(int mid, const vector<int>& piles, int h) {
        long long hours = 0;

        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / mid;

            if (piles[i] % mid != 0) {
                hours += 1;
            }

            if (hours > h) return hours;
        }

        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxElement = *max_element(piles.begin(), piles.end());

        if (n == h)
            return maxElement;

        int s = 1, e = maxElement;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            int findHours = calculateHours(mid, piles, h);

            if (findHours > h) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return s;
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    Solution obj;
    int ans = obj.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << ans << endl;

    return 0;
}