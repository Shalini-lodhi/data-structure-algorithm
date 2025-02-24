class DSU {
public:
    vector<int> parent;

    DSU() {
        parent.resize(26);
        for (int i = 0; i < 26; i++)
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
            if (rootX < rootY)
                parent[rootY] = rootX; // Always connect to smaller root
            else
                parent[rootX] = rootY;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu;

        // Step 1: Union all equivalent characters
        for (int i = 0; i < s1.size(); i++) {
            dsu.unite(s1[i] - 'a', s2[i] - 'a');
        }

        // Step 2: Convert baseStr using the smallest representative
        string result;
        for (char c : baseStr) {
            result += (char)('a' + dsu.find(c - 'a'));
        }
        return result;
    }
};