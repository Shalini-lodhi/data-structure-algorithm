#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i; // Initially, each node is its own parent
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x), rootY = find(y);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToID;
        unordered_map<string, string> emailToName;
        int id = 0;

        // Step 1: Assign a unique ID to each email and store the name
        for (auto &account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                string email = account[i];
                if (emailToID.find(email) == emailToID.end()) {
                    emailToID[email] = id++; // Assign a unique ID
                    emailToName[email] = name;
                }
            }
        }

        // Step 2: Initialize Union-Find for all unique emails
        UnionFind uf(id);

        // Step 3: Union emails within the same account
        for (auto &account : accounts) {
            int firstEmailID = emailToID[account[1]];
            for (int i = 2; i < account.size(); i++) {
                uf.unionSet(firstEmailID, emailToID[account[i]]);
            }
        }

        // Step 4: Group emails by root parent
        unordered_map<int, vector<string>> groupedEmails;
        for (auto &[email, index] : emailToID) {
            int root = uf.find(index);
            groupedEmails[root].push_back(email);
        }

        // Step 5: Construct the result
        vector<vector<string>> mergedAccounts;
        for (auto &[root, emails] : groupedEmails) {
            sort(emails.begin(), emails.end()); // Sort emails lexicographically
            string name = emailToName[emails[0]]; // Get the name from any email
            emails.insert(emails.begin(), name); // Insert name at the beginning
            mergedAccounts.push_back(emails);
        }

        return mergedAccounts;
    }
};
