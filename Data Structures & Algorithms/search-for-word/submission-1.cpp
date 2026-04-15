class Solution {
public:
    bool solve(int row, int col, int pos, string& word, vector<vector<char>>& board, vector<vector<bool>> &vis) {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return false;
        }
        if(vis[row][col]) {
            return false;
        }
        if(board[row][col] != word[pos]) {
            return false;
        }
        if(pos == word.size()-1) {
            return true;
        }
        vis[row][col] = true;
        vector<int> x = {0, 0, 1, -1};
        vector<int> y = {1, -1, 0, 0};
        for(int i = 0; i < 4; i++) {
            if(solve(row+x[i], col+y[i], pos+1, word, board, vis)) {
                vis[row][col] = false;
                return true;
            }
        }
        vis[row][col] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(solve(i, j, 0, word, board, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
