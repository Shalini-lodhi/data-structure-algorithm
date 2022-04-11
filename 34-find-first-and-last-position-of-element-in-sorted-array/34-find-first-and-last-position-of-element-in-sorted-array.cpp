class Solution {
public:
    vector<int> searchRange(vector<int>& arr,int x )
{
    int n=arr.size();
    int low = lowfun(arr, n, x, 0);
    int high = lowfun(arr, n, x, 1);
    vector<int> ans;
    ans.push_back(low);
    ans.push_back(high);
    
    return ans;
}

int lowfun(vector<int>& arr, int n, int x, int p){
    
    int low = 0;
    int high = n-1;
    
    int res = -1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
         if(arr[mid] == x){
             res = mid;
             if(p==0)
               high = mid-1;
             else
               low = mid+1;
         }
         else if(arr[mid] > x)
            high = mid-1;
         else
            low = mid + 1;
    }
    
    return res;
    
}
};