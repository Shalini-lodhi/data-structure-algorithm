#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class DSU {
public:
    unordered_map<int, int> parent, size;

    int find(int x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};

class Solution {
public:
    // Function to get prime factors of a number
    vector<int> getPrimeFactors(int num) {
        vector<int> factors;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                factors.push_back(i);
                while (num % i == 0) num /= i;
            }
        }
        if (num > 1) factors.push_back(num);
        return factors;
    }

    int largestComponentSize(vector<int>& nums) {
        DSU dsu;
        unordered_map<int, int> primeToNode;

        // Step 1: Connect numbers through their prime factors
        for (int num : nums) {
            vector<int> factors = getPrimeFactors(num);
            for (int prime : factors) {
                if (primeToNode.count(prime)) {
                    dsu.unite(num, primeToNode[prime]);
                }
                primeToNode[prime] = num;
            }
        }

        // Step 2: Count component sizes
        unordered_map<int, int> componentSize;
        int maxSize = 0;

        for (int num : nums) {
            int root = dsu.find(num);
            componentSize[root]++;
            maxSize = max(maxSize, componentSize[root]);
        }

        return maxSize;
    }
};