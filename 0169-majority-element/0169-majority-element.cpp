class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num; // Assign new candidate
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};