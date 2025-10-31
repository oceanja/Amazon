class Solution {
public:

void dfs(int node,vector<bool> &vis,vector<vector<int>> &adj){
    vis[node]=true;

    for(auto &neigh:adj[node]){
        if(!vis[neigh]){
            dfs(neigh,vis,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        // 1 1 0
        // 1 1 0
        // 0 0 1

        int n=isConnected.size();
        vector<vector<int>> adj(n);
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }


        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cnt++;
            }
        }

        return cnt;


    }
};