class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
         int i=0,j=grid[0].size()-1;
        int count = 0,size=grid.size();
        
        while(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()) 
        {
            if(grid[i][j]==target)
            {
                return true;
            }
            else if(grid[i][j]>target)
            {
                j--; 
            }
            else
            {
            	i++; 
            }
            
        }
        return false;
    }
};