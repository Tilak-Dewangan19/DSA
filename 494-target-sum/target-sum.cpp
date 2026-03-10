class Solution {
public:
    int findWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if(nums[0] == 0) 
            dp[0][0] = 2;
        else 
            dp[0][0] = 1;

        if(nums[0] != 0 && nums[0] <= target)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int T = 0; T <= target; T++) {
                int notPick = dp[i - 1][T];
                int pick = 0;

                if (nums[i] <= T)
                    pick = dp[i - 1][T - nums[i]];

                dp[i][T] = pick + notPick;
            }
        }

        return dp[n - 1][target];
    }

    int countP(int n, int d, vector<int>& arr) {
        int totSum = 0;
        for (auto &it : arr)
            totSum += it;

        if (totSum - d < 0 || (totSum - d) % 2)
            return 0;

        return findWays(arr, (totSum - d) / 2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countP(nums.size(), target, nums);
    }
};