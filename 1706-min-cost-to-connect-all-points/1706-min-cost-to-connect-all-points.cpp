class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);

       for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                  int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                  adj[i].push_back({j, dist});
                  adj[j].push_back({i, dist}); 
    }
}

        vector<bool> vis(n,false);
        vector<int> parent(n,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int sum=0;

        pq.push({0,0});

        while(!pq.empty()){
            pair<int,int> p=pq.top();
            int wt=p.first;
            int node=p.second;
            pq.pop();

            if(!vis[node]){
                vis[node]=true;
                sum+=wt;
                for(auto &neigh:adj[node]){
                    int adjNode=neigh.first;
                    int d=neigh.second;
                    if(!vis[adjNode]){
                        pq.push({d,adjNode});
                    }
                }
            }
        }

        return sum;




        
    }
};