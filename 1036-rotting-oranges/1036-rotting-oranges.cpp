class Solution {
public:
 
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int minutes=0;
        int cnt=0;

       queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 || grid[i][j]==2){
                    cnt++;
                }
            }
        }
        if(cnt==0){
            return 0;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int num=q.size();
            while(num--){
                pair<int,int> p=q.front();
                int row=p.first;
                int col=p.second;
                q.pop();
                int dx[4]={0,1,0,-1};
                int dy[4]={1,0,-1,0};

                for(int i=0;i<4;i++){
                    int nrow=row+dx[i];
                    int ncol=col+dy[i];

                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                        q.push({nrow,ncol});

                        grid[nrow][ncol]=2;
                    }
                }

            }

            minutes++;
           
        }

        int cnt2=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    cnt2++;
                }
            }
        }

        return (cnt==cnt2)?(minutes-1):-1;


        
    }
};