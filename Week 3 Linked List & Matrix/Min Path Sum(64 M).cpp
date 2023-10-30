class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int outcome[n][m];

        outcome[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            outcome[0][i] = grid[0][i] + outcome[0][i-1];
        }//第一行的数值
        for(int i = 1; i < n; i++){
            outcome[i][0] = grid[i][0] + outcome[i-1][0];
        }//第一列的数值
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                outcome[i][j] = min(outcome[i-1][j], outcome[i][j-1]) + grid[i][j];
            }
        }
        return outcome[n-1][m-1];
    }
};