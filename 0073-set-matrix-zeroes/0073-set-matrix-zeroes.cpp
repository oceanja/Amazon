class Solution {
public:

void set(int row,int col,vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();

    for(int i=0;i<n;i++){
        grid[row][i]=0;
    }

    for(int j=0;j<m;j++){
        grid[j][col]=0;
    }

}
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> grid=matrix;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    set(i,j,grid);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=grid[i][j];
            }
        }
    }
};