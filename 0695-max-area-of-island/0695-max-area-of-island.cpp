class Solution {
public:
int n;
int m;
int  dfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>> &vis){
    vis[row][col]=true;
    int area=1;

    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    for(int i=0;i<4;i++){
        int nrow=row+dx[i];
        int ncol=col+dy[i];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
            area+=dfs(nrow,ncol,grid,vis);
        }
    }

    return area; 
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxArea=0;
        

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int area =dfs(i,j,grid,vis);
                    maxArea=max(maxArea,area);
                }
            }
        }

        return maxArea;
        
        
    }
};