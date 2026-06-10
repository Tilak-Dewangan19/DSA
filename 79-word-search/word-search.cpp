class Solution {
public:
    bool solve(int i, int j, int ind, vector<vector<char>>& board, string& word){
        if(ind == word.size())return true;
         int n = board.size();
        int m = board[0].size();

        if(i<0 || i>=n || j <0 || j>=m || board[i][j]!= word[ind]) return false;
        char ch = board[i][j];
        board[i][j] = '#';

        bool found = solve(i+1, j, ind+1, board, word) || solve(i-1, j, ind+1, board, word) || solve(i, j+1, ind+1, board, word) || solve(i, j-1, ind+1, board, word);
        board[i][j]= ch;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(solve(i,j,0,board,word)) return true;
            }
        }
        return false;
        
        
    }
};