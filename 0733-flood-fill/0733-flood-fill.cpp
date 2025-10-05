class Solution {
public:

int delrow[4]={0,-1,0,1};
int delcol[4]={1,0,-1,0};

void dfs(vector<vector<int>>& image,vector<vector<int>> &ans,int r,int c,int color,int iniColor){
    int m=image.size();
    int n=image[0].size();

    ans[r][c]=color; 

    for(int i=0;i<4;i++){
        int nrow=r+delrow[i];
        int ncol=c+delcol[i];

       
        if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && ans[nrow][ncol]==iniColor){
            dfs(image,ans,nrow,ncol,color,iniColor);
        }
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        int iniColor=image[sr][sc];
        if (iniColor == color) {
            return image;
        }

        vector<vector<int>> ans=image; 
        dfs(image,ans,sr,sc,color,iniColor);

        return ans;
    }
};