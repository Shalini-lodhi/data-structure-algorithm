class Solution {
public:
    int binarySearch(vector<int>& nums, int sz, int req){
        int left =0, right=sz-1; int mid=0;
        while(left<=right){
            mid=left+(right-left)/2;
            
            if(nums[mid]==req) return mid;
            else if(nums[mid]>req) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
       int sz=nums.size(); 
        for(int i=0; i<sz-1; i++){
            int req=target-nums[i];
            if(binarySearch(nums, sz, req) !=-1){
                int x=i+1; 
                int y=binarySearch(nums, sz, req)+1;
                if(x==y){
                    y++;
                }
                return {x, y};
            }
        }
        return {-1, -1};
    }
};