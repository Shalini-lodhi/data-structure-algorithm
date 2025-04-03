/*
piles[n] = {}, h
piles = [3, 6, 7, 11], h = 8
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = (left + right) / 2;
            int hours_needed = 0;

            for (int pile : piles) {
                hours_needed += ceil((double)pile / mid); // Compute total hours
            }

            if (hours_needed > h) {
                left = mid + 1; // Increase speed
            } else {
                right = mid; // Try smaller speed
            }
        }
        return left;
    }
};