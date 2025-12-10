class Solution {
public:
    int m,n;
    long long MARK = (long long)INT_MIN - 1;   // safe marker outside int range

    void setRowCol(int row,int col,vector<vector<long long>>& mat){

        for(int i=0;i<n;i++){
            mat[row][i] = (mat[row][i] != 0 ? MARK : 0);
        }

        for(int j=0;j<m;j++){
            mat[j][col] = (mat[j][col] != 0 ? MARK : 0);
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<long long>> mat(m, vector<long long>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = matrix[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    setRowCol(i,j,mat);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == MARK){
                    mat[i][j] = 0;
                }
            }
        }

        // copy back to original matrix
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = (int)mat[i][j];
            }
        }
    }
};
