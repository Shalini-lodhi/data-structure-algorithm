class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26); // 26 lowercase English letters

        // Step 1: Process "==" equations first
        for (string eq : equations) {
            if (eq[1] == '=') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                dsu.unite(x, y);
            }
        }

        // Step 2: Process "!=" equations
        for (string eq : equations) {
            if (eq[1] == '!') {
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';
                if (dsu.find(x) == dsu.find(y))
                    return false; // Contradiction found
            }
        }

        return true;
    }
};