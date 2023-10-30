class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0], b = edges[0][1];
        for(int i = 1; i < edges.size(); i++){
            if(edges[i][0] != a && edges[i][0] != b){
                return edges[i][1];
            }
            if(edges[i][1] != a && edges[i][1] != b){
                return edges[i][0];
            }
        }
        return -1;
    }
};