class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0; // Edge case for empty array

        int i = 0; // Slow pointer for unique elements

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j]; // Move unique element forward
            }
        }

        return i + 1; // Unique element count
    }
};