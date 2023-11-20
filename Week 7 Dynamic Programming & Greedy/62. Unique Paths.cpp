class Solution {
public:
    int uniquePaths(int m, int n) {
        int path[m][n];

        //最上行和最左列都是0
        for(int i = 0; i < m; i++){
            path[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            path[0][i] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                path[i][j] = path[i][j-1] + path[i-1][j];
            }
        }
        return path[m-1][n-1];
    }
};