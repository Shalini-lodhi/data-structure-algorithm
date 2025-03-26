class Solution {
public:
    bool canDistribute(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int c : candies) {
            count += (c / mid);
            if (count >= k)
                return true; // Stop early if we already reached k
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies =
            accumulate(candies.begin(), candies.end(), 0LL);
        if (total_candies < k)
            return 0; // Not enough candies to give at least one to each child

        int low = 1, high = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canDistribute(candies, k, mid)) {
                ans = mid;     // Store the valid mid value
                low = mid + 1; // Try for larger candies per child
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};