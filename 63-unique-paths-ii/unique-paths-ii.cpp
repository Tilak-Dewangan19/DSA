class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>&grid, vector<vector<int>>&dp){
        if(i >= m || j >=n) return 0;
        if(grid[i][j] == 1) return 0;
         
        if( i == m-1 && j == n-1){
            return 1;
        }
        
 
      
        if(dp[i][j]!= -1) return dp[i][j];
        return dp[i][j] = (solve(i+1, j, m, n, grid,dp) + solve(i, j+1, m, n, grid, dp));
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1)return 0;
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(0,0,m,n,grid,dp);
        
    }
};