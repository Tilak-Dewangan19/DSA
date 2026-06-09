class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int> &dp){
        if(ind < 0) return 0;
        if(ind == 0) return nums[ind];
        if(dp[ind]!= -1)return dp[ind];
        int pick = nums[ind] + solve(ind-2, nums, dp);
        int notpick = 0 + solve(ind-1, nums, dp);

        return dp[ind] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
         int n = nums.size(); 
         if( n== 1) return nums[0];
         vector<int>temp1(nums.begin(), nums.end()-1);
         vector<int>temp2(nums.begin()+1, nums.end());

        vector<int> dp1(temp1.size(), -1);
        vector<int>dp2(temp2.size(), -1);
       
       return max( solve(temp1.size()-1, temp1, dp1), solve(temp2.size()-1, temp2, dp2));
       
    }
};