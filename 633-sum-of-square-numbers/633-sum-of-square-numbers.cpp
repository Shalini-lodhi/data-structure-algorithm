class Solution {
public:
    bool binary_search(long long int x)
    {
        long long int low = 0;
        long long int high = x;
        while(low<high)
        {
            long long int mid = (low+high)/2;
            if(mid*mid == x)
            {
                return true;
            }
            if(mid*mid > x)
            {
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        if(c == 1 || c == 2 | c == 0)
        {
            return true;
        }
      
        for(long long int a = 0;a*a<=c;a++)
        {
            if(binary_search(c-(a*a)))
            {
                return true;
            }
        }
        return false;
    }
};