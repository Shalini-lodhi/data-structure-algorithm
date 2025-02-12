class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> validGenes(bank.begin(), bank.end());
        if (validGenes.find(endGene) == validGenes.end())
            return -1;

        queue<pair<string, int>> q; // (current gene, mutation count)
        unordered_set<string> visited;
        vector<char> choices = {'A', 'C', 'G', 'T'};

        q.push({startGene, 0});
        visited.insert(startGene);

        while (!q.empty()) {
            auto [current, mutations] = q.front();
            q.pop();

            if (current == endGene)
                return mutations;

            for (int i = 0; i < current.size(); i++) {
                char original = current[i];

                for (char c : choices) {
                    if (c == original)
                        continue; // Skip same character

                    current[i] = c;
                    if (validGenes.find(current) != validGenes.end() &&
                        visited.find(current) == visited.end()) {
                        q.push({current, mutations + 1});
                        visited.insert(current);
                    }
                }
                current[i] = original; // Restore original character
            }
        }

        return -1; // No valid path found
    }
};