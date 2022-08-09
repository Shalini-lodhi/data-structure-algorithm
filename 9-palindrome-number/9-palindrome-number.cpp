class Solution {
public:
    int reverse(int x) {
         long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
    bool isPalindrome(int x) {
        if(x <0 ) return false;
        //step 1: reverse the number
            int y = reverse(x);
        //step 2: check reverse number and orginal number
            if(y != x) return false;
        //step 3: if rev. number == original number 
            return true;        
    }
};