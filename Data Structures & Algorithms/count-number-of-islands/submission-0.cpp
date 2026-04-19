class Solution {
public:
    void solve(int x, int y, vector<vector<char>>& grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
            return;
        }
        if(grid[x][y] != '1') {
            return;
        }
        grid[x][y] = 'X';
        int nextx[4] = {0, 0, 1, -1};
        int nexty[4] = {1, -1, 0, 0};
        for(int i = 0; i < 4; i++) {
            solve(x+nextx[i], y+nexty[i], grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    solve(i, j, grid);
                }
            }
        }
        return ans;
    }
};
