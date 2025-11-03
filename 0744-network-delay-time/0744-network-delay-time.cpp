class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &e:times){
            int u=e[0];
            int v=e[1];
            int time=e[2];

            adj[u].push_back({v,time});
        }

        vector<int> minTime(n+1,INT_MAX);
        minTime[k]=0;
       

         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
         pq.push({0,k});

         while(!pq.empty()){
            pair<int,int> p=pq.top();
            int node=p.second;
            int dist=p.first;
            pq.pop();

            for(auto &neigh:adj[node]){
                int adjNode=neigh.first;
                int wt=neigh.second;

                if(minTime[adjNode]>wt+dist){
                    minTime[adjNode]=wt+dist;
                    pq.push({minTime[adjNode],adjNode});
                }
            }

         }

         int miniTime=0;

         for(int i=1;i<=n;i++){
            if(minTime[i]==INT_MAX){
                return -1;
            }

            miniTime=max(miniTime,minTime[i]);
         }

         return miniTime;




        
    }
};