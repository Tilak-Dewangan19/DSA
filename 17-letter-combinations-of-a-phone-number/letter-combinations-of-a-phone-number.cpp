class Solution {
    private:
    void solve(int ind, string &digits, string &ds,
               vector<string> &ans, vector<string> &mapping) {

        // One complete combination formed
        if (ind == digits.size()) {
            ans.push_back(ds);
            return;
        }

        string letters = mapping[digits[ind] - '0'];

        for (char ch : letters) {
            ds.push_back(ch);

            solve(ind + 1, digits, ds, ans, mapping);

            ds.pop_back();
        }
               }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        vector<string> ans;
       string ds;

       solve(0,digits,ds,ans,mapping);
        return ans;
    }
};