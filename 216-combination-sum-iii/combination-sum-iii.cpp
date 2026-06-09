class Solution {
    private:
    void solve(int start, int k, int target, vector<vector<int>>& ans, vector<int>ds){
        if(target == 0 && ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if(target < 0 || ds.size() > k){
            return;
        }
        for(int i = start; i<=9; i++){
            ds.push_back(i);
            solve(i+1,k, target-i, ans, ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(1, k,n, ans,ds);
        return ans;
    }
};