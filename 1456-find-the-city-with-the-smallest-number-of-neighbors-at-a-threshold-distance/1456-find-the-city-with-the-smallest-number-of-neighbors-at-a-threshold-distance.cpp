class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

       for(auto &e:edges){
        int u=e[0];
        int v=e[1];
        int d=e[2];
        dist[u][v]=d;
        dist[v][u]=d;
       }

        for (int i = 0; i < n; i++) 
            dist[i][i] = 0;
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int cityNo=-1;
        int minCount = INT_MAX;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j &&dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }

            if(minCount>=cnt){
                minCount=cnt;
                cityNo=i;
            }
        }

        return cityNo;
        
    }
};