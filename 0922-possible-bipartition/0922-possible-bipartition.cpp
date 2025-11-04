class Solution {
public:

bool check(int node,vector<vector<int>> &adj,vector<int> &color){

   for(auto &neigh:adj[node]){

    if(color[neigh]==-1){
        color[neigh]=1-color[node];
        if(!check(neigh,adj,color)){
            return false;
        }
    }
    else{
        if(color[neigh]==color[node]){
            return false;
        }
    }

   }
   return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto &e:dislikes){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 1 -> 2 3 
        // 2-> 4

        vector<int> color(n+1,-1);

        for(int i=1;i<=n;i++){

            if(color[i]==-1){
                color[i]=0;
            }

            if(!check(i,adj,color)){
                return false;
            }
        
            
        }

        return true;
        
    }
};