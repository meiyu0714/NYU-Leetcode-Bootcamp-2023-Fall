class Solution {
    int m, n;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0 , 1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int x, int y){
        grid[x][y] = '0';
        for(int i = 0; i < 4; i ++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1'){
                dfs(grid, nx, ny);
            }
        }
    }
};