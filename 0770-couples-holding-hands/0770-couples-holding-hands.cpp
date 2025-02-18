#include <iostream>
#include <vector>

using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false; // Already connected
        if (rank[xr] > rank[yr]) swap(xr, yr);
        parent[xr] = yr; // Union
        if (rank[xr] == rank[yr]) rank[yr]++;
        return true;
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2; // Number of couples
        DSU dsu(n);
        int swaps = 0;
        
        // Process couples
        for (int i = 0; i < row.size(); i += 2) {
            int a = row[i] / 2, b = row[i+1] / 2; // Get couple ID
            if (dsu.unite(a, b)) swaps++;
        }
        
        return swaps;
    }
};
