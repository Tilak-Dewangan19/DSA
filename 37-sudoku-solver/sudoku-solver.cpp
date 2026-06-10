class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        
        // Check row and column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;
        }

        // Check 3 x 3 subgrid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == ch) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') {

                    for (char ch = '1'; ch <= '9'; ch++) {

                        if (isValid(board, i, j, ch)) {

                            board[i][j] = ch;

                            if (solve(board))
                                return true;

                            // Backtrack
                            board[i][j] = '.';
                        }
                    }

                    // No digit worked
                    return false;
                }
            }
        }

        // All cells are filled
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};