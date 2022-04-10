class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        long left=0, right=x/2, mid, ans;
        while(left<=right){
            mid=right+(left-right)/2;
            
            if(mid*mid == x) return mid;
            
            else if(mid*mid>x) right=mid-1;
            else{ left=mid+1; ans=mid;}
        }
        return ans;
    }
};