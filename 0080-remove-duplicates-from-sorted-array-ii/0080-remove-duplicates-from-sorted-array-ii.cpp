class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); // If array is size 0, 1, or 2, return as is.

    int i = 2; // Slow pointer starts at index 2 since the first two elements are always allowed.

    for (int j = 2; j < nums.size(); j++) {
        if (nums[j] != nums[i - 2]) { // Check if the current element is different from nums[i-2]
            nums[i] = nums[j]; // Place valid element
            i++; // Move slow pointer
        }
    }

    return i; // New size of array with at most 2 duplicates
    }
};