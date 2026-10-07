class Solution {
public:
    vector<string> ans;
    string temp;

    void helper(int idx, int cost, int prev, int n, int k) {

        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        // Put 0
        temp.push_back('0');
        helper(idx + 1, cost, 0, n, k);
        temp.pop_back();

        // Put 1
        if (prev == 0 && cost + idx <= k) {
            temp.push_back('1');
            helper(idx + 1, cost + idx, 1, n, k);
            temp.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        helper(0,0,0, n, k);
        return ans;
    }
};