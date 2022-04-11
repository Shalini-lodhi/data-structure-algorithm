class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int nonCircularSum = maxSubArray(A);
        int totalSum = 0;
        for(int i=0;i<A.size();i++){
            totalSum += A[i];
            A[i] = -A[i];
        }
              
        int circularSum = totalSum + maxSubArray(A);
        if(circularSum == 0)
            return nonCircularSum;
        return max(circularSum,nonCircularSum);
    }
    
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), sum=INT_MIN, temp=0;        
        for(int i=0;i<n;i++)
        {
            temp=max(nums[i],nums[i]+temp);
            sum=max(sum,temp);
        }
        return sum;
    }
};