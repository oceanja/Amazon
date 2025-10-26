class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size(); // row
        int n=grid[0].size(); // col
        int ops=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                if (grid[j+1][i] <= grid[j][i]) {
             int needed = grid[j][i]+1-grid[j+1][i];
             ops += needed;
             grid[j+1][i] = grid[j][i] + 1; 
}

            }
        }

        return ops;
        
    }
};