class Solution {
    private:
    void dfs(int sr, int sc, vector<vector<int>>&ans, vector<vector<int>>&image, int drow[], int dcol[], int inicolor, int color){
        ans[sr][sc] = color;
        int  n = image.size();
        int m = image[0].size();
        for(int i =0; i<4; i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
                if(nrow>=0 && nrow < n && ncol>=0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != color)  {
                    dfs(nrow,ncol,ans,image,drow,dcol,inicolor,color);
                }          }
        }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        vector<vector<int>> ans = image;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        dfs(sr,sc,ans,image,drow, dcol,inicolor, color); 
        return ans;
    }
};