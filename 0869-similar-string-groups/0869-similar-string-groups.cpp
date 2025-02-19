class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
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
            if (size[rootX] < size[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};
class Solution {
public:
    bool areSimilar(const string& a, const string& b) {
        int diffCount = 0;
        vector<int> diffPos;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diffCount++;
                diffPos.push_back(i);
            }
            if (diffCount > 2)
                return false; // More than 2 differences
        }

        return (diffCount == 2 && a[diffPos[0]] == b[diffPos[1]] &&
                a[diffPos[1]] == b[diffPos[0]]) ||
               (diffCount == 0);
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU dsu(n);

        // Connect similar words using DSU
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (areSimilar(strs[i], strs[j])) {
                    dsu.unite(i, j);
                }
            }
        }

        // Count unique groups (connected components)
        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i)
                groups++;
        }

        return groups;
    }
};