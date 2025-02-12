class Solution {
public:
    int ladderLength(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> validGenes(bank.begin(), bank.end());
        if (validGenes.find(endGene) == validGenes.end())
            return 0;

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        vector<char> choices = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                                'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                                's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        q.push({startGene, 1});
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
                current[i] = original;
            }
        }

        return 0;
    }
};