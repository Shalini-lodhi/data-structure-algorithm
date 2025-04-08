class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> count;
        unordered_set<char> seen;
        stack<char> st;

        // Count frequency of each character
        for (char c : s) {
            count[c]++;
        }

        for (char c : s) {
            count[c]--; // one occurrence processed

            // If character is already in the result stack, skip it
            if (seen.count(c))
                continue;

            // Remove characters from the stack if:
            // 1. The current char is smaller (lexicographically)
            // 2. The char at the top appears later again
            while (!st.empty() && c < st.top() && count[st.top()] > 0) {
                seen.erase(st.top());
                st.pop();
            }

            st.push(c);
            seen.insert(c);
        }

        // Build the result from the stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Reverse the result since we built it using a stack
        reverse(result.begin(), result.end());

        return result;
    }
};