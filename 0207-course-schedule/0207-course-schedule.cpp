class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;

            for(auto &neigh:adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }

        if(count==numCourses){
            return true;
        }

        return false;

        
    }
};