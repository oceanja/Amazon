class Solution {
public:
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int m;
int n;

void dfs(int row,int col,vector<vector<bool>> &vis,vector<vector<char>>& grid){

vis[row][col]=true;

for(int i=0;i<4;i++){
    int nrow=row+dx[i];
    int ncol=col+dy[i];

    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n
    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
    dfs(nrow, ncol, vis, grid);
}

}

}
    int numIslands(vector<vector<char>>& grid) {
         m=grid.size();
         n=grid[0].size();

       vector<vector<bool>> vis(m, vector<bool>(n, false));

        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,vis,grid);
                    
                }
            }
        }

        return cnt;
        
    }
};