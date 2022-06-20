class Solution {
public:
    bool isValid(string s) {
        string result = "";
        
        for (auto &ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                result += ch;
            }
            else {
                // If result is empty and "ch" is a closing bracket return false.
                if (result.size() == 0) {
                    return false;
                }
                else if (ch == '}' && result.back() == '{') {
                    result.pop_back();
                }
                else if (ch == ')' && result.back() == '(') {
                    result.pop_back();
                }
                else if (ch == ']' && result.back() == '[') {
                    result.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        return result.size() == 0;
    }
};