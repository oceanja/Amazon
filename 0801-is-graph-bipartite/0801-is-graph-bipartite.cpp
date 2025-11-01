class Solution {
public:

bool f(vector<vector<int>>& graph,vector<int> &colour,int node,int currColor){

    colour[node]=currColor;

    for(auto &neigh:graph[node]){
        if(colour[neigh]==-1){
            if(!f(graph,colour,neigh,1-currColor)){
                return false;
            }
        }
        else{
            if(colour[neigh]==currColor){
                return false;
            }
        }
    }

    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false);

        vector<int> colour(n,-1);

        for(int i=0;i<n;i++){
            if(colour[i]==-1){
                if(f(graph,colour,i,0)==false){
                return false;
            }

            }
            
        }

        return true;
    }
};