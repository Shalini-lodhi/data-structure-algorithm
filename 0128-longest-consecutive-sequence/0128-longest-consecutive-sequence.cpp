class UF{
    private:
    vector<int> parent;
    vector<int> size;
    public :
    UF(int n ){
        parent.resize(n);
        size.resize(n);
        for( int i = 0 ; i < n ; i++ ){
            parent[i] = i;
            size[i] = 1;
        }
    }
    void join(int x , int y ){
        int rootx = find(x);
        int rooty = find(y);
        if( rootx != rooty ){
            parent[rootx] = rooty;
            size[rooty] += size[rootx];
        }
        
    }

    int find( int x ){
        if( x == parent[x]){
            return x;
        }
        return find( parent[x] );
    }

    int getmaxsize(){
        int maxsize = 0;
        for( int a : size ){
            maxsize = max( maxsize, a );
        }
        return maxsize;
    }

};

class Solution {
public:
    
    
    
    int longestConsecutive(vector<int>& nums) {
        UF uf(nums.size());
        unordered_map<int,int> umap;
        
        
        for( int i = 0 ;i < nums.size() ; i++ ){
            if( umap.find(nums[i]) != umap.end() ){
                continue;
            }
            
            if( umap.find(nums[i]-1) != umap.end() ){
                uf.join(i,umap[nums[i]-1] );
            }
            if( umap.find(nums[i]+1) != umap.end() ){
                uf.join(i,umap[nums[i]+1] );
            }
            
            umap[nums[i]] = i;    
        }
        
        return uf.getmaxsize();
    }
};