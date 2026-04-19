class Solution {
public:
    void solve(int x, int y, vector<vector<char>>& grid) {
        stack<pair<int, int>> st;
        st.push({x, y});
        grid[x][y] = 'X';
        int nextx[4] = {0, 0, 1, -1};
        int nexty[4] = {1, -1, 0, 0};
        while(!st.empty()) {
            auto [i, j] = st.top();
            st.pop();
            for(int k = 0; k < 4; k++) {
                int newx = i+nextx[k];
                int newy = j+nexty[k];
                if(newx >= 0 && newy >= 0 && newx < grid.size() && newy < grid[0].size() && grid[newx][newy] == '1') {
                    grid[newx][newy] = 'X';
                    st.push({newx, newy});
                }
            }
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
