class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>&triangle, vector<vector<int>>&dp, int n){
    //     if(i == n-1) return triangle[n-1][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int d = triangle[i][j]+ solve(i+1,j,triangle, dp, n);
    //     int dg = triangle[i][j] + solve(i+1, j+1, triangle,dp, n);
    //     return dp[i][j] = min(d,dg);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>>dp(n, vector<int>(n, -1));
        // return solve(0, 0, triangle, dp,n);
        

        vector<vector<int>> dp(n, vector<int>(n, 0));

    
        for(int j = 0; j < n; j++)
            dp[n-1][j] = triangle[n-1][j];

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[i][j] = triangle[i][j] +
                           min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};
        
