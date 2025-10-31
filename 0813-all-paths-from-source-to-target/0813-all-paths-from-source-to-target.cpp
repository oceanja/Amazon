class Solution {
public:
int n;
void dfs(vector<vector<int>>& graph,vector<int> &path, vector<vector<int>> &result,vector<bool> vis,int node){
    vis[node]=true;
    path.push_back(node);

    if(node==n-1){
        result.push_back(path);
        return;
    }

    for(auto &neigh: graph[node]){
        if(!vis[neigh]){
            dfs(graph,path,result,vis,neigh);
        }
        path.pop_back();
    }

    
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         n=graph.size();
        vector<vector<int>> result;
        vector<int> path;

        vector<bool> vis(n);

        dfs(graph,path,result,vis,0);

        return result;
    }
};