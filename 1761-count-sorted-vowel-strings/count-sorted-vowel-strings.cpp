class Solution {
public:
    int solve(int n, int idx, vector<vector<int>>& dp){
        if(n == 0) return 1;
        if(dp[n][idx] != -1){
            return dp[n][idx];
        }
        int ans = 0;
        for(int i =idx; i< 5; i++){
            ans+= solve(n-1, i, dp);
        }
        return dp[n][idx] = ans;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(n+1, vector<int>(5,-1));
      return  solve(n, 0, dp);
        
    }
};