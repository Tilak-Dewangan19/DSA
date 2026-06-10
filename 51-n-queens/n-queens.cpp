class Solution {
public:
    bool isValid(int r, int c, vector<string>& board, int n){
        int dr =r;
        int dc = c;

        while(r >= 0 && c>=0){
            if(board[r][c] == 'Q') return false;
            c--;
            r--;
        }

        c = dc;
        r= dr;
        while(c>=0){
            if(board[r][c] == 'Q') return false;
            c--;
        }

        c= dc;
        r=dr;
        while(r < n && c>=0){
            if(board[r][c] == 'Q') return false;
            c--;
            r++;
        }
    return true;
    }
    void solve(int col, int n, vector<vector<string>>& ans, vector<string>& board){
        if(col == n) {ans.push_back(board);
        return;
        }

        for(int row = 0; row< n; row++){
            if(isValid(row, col, board, n)){
                board[row][col]= 'Q';
                solve(col+1, n, ans, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');

        for(int i = 0; i<n; i++){
            board[i] = s;
        }
        solve(0,n,ans, board);
        return ans;
        
    }
};