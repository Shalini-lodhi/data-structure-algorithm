class Solution {
public:

    bool canDivide(vector<int>& nums, int mid, int maxOp){
        int op = 0;
        for(auto& num : nums){
            if(num > mid){
                op += (num - 1) / mid; 
            }
        }
        return op <= maxOp;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low < high){
            int mid = (low + high)/2;
            if(canDivide(nums, mid, maxOperations)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};