class Solution {
public:
    int solve(int x, int y, vector<vector<int>>& grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
            return 0;
        }
        if(grid[x][y] != 1) {
            return 0;
        }
        grid[x][y] = -1;
        int nextx[4] = {0, 0, 1, -1};
        int nexty[4] = {1, -1, 0, 0};
        int area = 1;
        for(int i = 0; i < 4; i++) {
            area += solve(x+nextx[i], y+nexty[i], grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    ans = max(ans, solve(i, j, grid));
                }
            }
        }
        return ans;
    }
};
