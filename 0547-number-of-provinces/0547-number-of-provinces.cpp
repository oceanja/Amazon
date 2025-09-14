class Solution {
public:

void dfs(vector<vector<int>> &adj,int u, vector<bool> &vis){
    vis[u]=true;

    for(auto &neigh:adj[u]){
        if(!vis[neigh]){
            dfs(adj,neigh,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
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
                dfs(adj,i,vis);
                cnt++;
            }
        }

        return cnt;


        
    }
};