class Solution {
public:
    int search(vector<int>& arr,int k){
        int n=arr.size();
        int start=0, end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==k)return mid;
            else if(arr[mid]>k) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
};