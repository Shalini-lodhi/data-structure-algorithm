class Solution {
public:
    /*
    env = [
        [5,4],
        [6,4],
        [6,7],
        [2,3]
        ]
    -> sorting
    env = [
        [2,3],
        [5,4],
        [6,7],
        [6,4]
    ]
    -> Extract the height
    heights = [3,4,7,4]
    -> LIS = 3
    */
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty())
            return 0;

        // Step 1: Sort envelopes
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
             });

        // Step 2: Extract heights
        vector<int> heights;
        for (auto& e : envelopes) {
            heights.push_back(e[1]);
        }

        // Step 3: Find Longest Increasing Subsequence (LIS) in heights using
        // Binary Search
        vector<int> dp;
        for (int h : heights) {
            auto it = lower_bound(dp.begin(), dp.end(), h);
            if (it == dp.end()) {
                dp.push_back(h);
            } else {
                *it = h; // Replace element to maintain smallest increasing
                         // subsequence
            }
        }

        return dp.size();
    }
};