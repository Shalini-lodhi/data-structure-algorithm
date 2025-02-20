#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class DSU {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    int find(int x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;

        // Step 1: Union all stones that share the same row or column
        for (auto& stone : stones) {
            int row = stone[0];      
            int col = stone[1] + 10001;  // Shift column index to avoid collision
            dsu.unite(row, col);
        }

        // Step 2: Count unique components
        unordered_map<int, int> uniqueRoots;
        for (auto& stone : stones) {
            uniqueRoots[dsu.find(stone[0])]++;
        }

        // Step 3: Compute the maximum removable stones
        return stones.size() - uniqueRoots.size();
    }
};