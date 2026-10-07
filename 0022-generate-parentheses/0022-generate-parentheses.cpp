class Solution {
public:
    vector<string> ans;
    string temp;

    void helper(int o, int c, int n) {
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (o < n) {
            temp.push_back('(');
            helper(o + 1, c, n);
            temp.pop_back();   // backtrack
        }

        if (c < o) {
            temp.push_back(')');
            helper(o, c + 1, n);
            temp.pop_back();   // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        helper(0, 0, n);
        return ans;
    }
};