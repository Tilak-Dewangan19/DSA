class Solution {
public:
    int solve(int idx, int g1, int g2, vector<int>& nums, vector<vector<vector<int>>>& dp){
        long long MOD = 1e9 + 7;
        if(idx == nums.size()){
            return (g1 != 0 && g1 == g2);
        }
        if(dp[idx][g1][g2] != -1) return dp[idx][g1][g2];

        long long ans = 0;

        ans+= solve(idx+1,g1, g2, nums, dp);

        int newG1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans+= solve(idx+1, newG1, g2, nums, dp);

        int newG2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans+= solve(idx+1, g1, newG2, nums, dp);

        return dp[idx][g1][g2] = ans % MOD ;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(mx+1, vector<int>(mx+1, -1)));
        return solve(0, 0, 0, nums, dp);
        
    }
};