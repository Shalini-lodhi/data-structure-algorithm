class Solution {
public:
    bool isPerfectSquare(int num) {
    //edge conditions
        if(num < 0) return false;
        if(num == 1 || num ==0) return true;
      long left=1, right=num/2, mid;
        while(left<=right){
            mid=left+(right-left)/2;
            
            if(mid*mid==num) return true;
            else if(mid*mid >num) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
};