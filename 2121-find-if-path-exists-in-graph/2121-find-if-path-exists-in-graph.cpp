class Solution {
public:

bool dfs(vector<vector<int>> &adj,int src,int destination,vector<bool> &vis){
    vis[src]=true;

    if(src==destination){
        return true;
    }

    for(auto &neigh:adj[src]){
        if(!vis[neigh] && dfs(adj,neigh,destination,vis)){
            return true;
        }
    }

    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj,source,destination,vis);


        
    }
};