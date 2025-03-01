class Solution {
public:
    /*
    nums = [
        0 | -2
        1 | 1
        2 | -3
        3 | 4
        4 | -1
        5 | 2
        6 | 1
        7 | -5
        8 | 4
    ]
    */
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], currentSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentSum =
                max(nums[i],
                    currentSum + nums[i]); // Max of current element and sum
                                           // including the current element
            maxSum = max(maxSum,
                         currentSum); // Update maxSum if currentSum is greater
        }

        return maxSum;
    }
};