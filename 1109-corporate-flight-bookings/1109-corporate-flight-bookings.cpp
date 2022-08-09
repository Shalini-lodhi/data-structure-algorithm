class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
         vector<int> res(n);
        
        for(auto v : bookings)
        {
            int first = v[0];
            
            int last = v[1];
            
            int reserve = v[2];
            
            res[first - 1] += reserve;
            
            if(last < n)
            {
                res[last] -= reserve;
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            res[i] += res[i - 1];
        }
        
        return res;
    }
};