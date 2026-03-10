class Solution {
public:
    bool f(int ind, int t, vector<int>& nums,
           vector<vector<int>>& dp) {
        if (t == 0)
            return true;
        if (ind == 0)
            return nums[0] == t;
        if(dp[ind][t]!= -1) return dp[ind][t];
        bool notTake = f(ind - 1, t, nums, dp);

        bool take = false;
        if (nums[ind] <= t) {
            take = f(ind - 1, t - nums[ind], nums,dp);
        }

        return dp[ind][t]= take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
       

        for (auto& it : nums) {
            totalSum += it;
        }

        if (totalSum % 2)
            return false;

        int t = totalSum / 2;
         vector<vector<int>> dp(n, vector<int>(t+ 1, -1));
        return f(n - 1, t, nums,dp);
    }
};