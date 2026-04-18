class Solution {
public:
    void solve(int row, int n, vector<string>& board, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!col[i] && !diag1[row+i] && !diag2[row-i+n-1]) {
                col[i] = true;
                diag1[row+i] = true;
                diag2[row-i+n-1] = true;
                board[row][i] = 'Q';
                solve(row+1, n, board, col, diag1, diag2, ans);
                col[i] = false;
                diag1[row+i] = false;
                diag2[row-i+n-1] = false;
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false), diag1(2*n-1, false), diag2(2*n-1, false);
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, col, diag1, diag2, ans);
        return ans;
    }
};
