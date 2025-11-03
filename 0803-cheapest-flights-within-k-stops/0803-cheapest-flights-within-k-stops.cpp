class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>result(n,INT_MAX);

        result[src]=0;

        for(int cnt=1;cnt<=k+1;cnt++){
            vector<int> temp=result;
            for(auto &edge:flights){
                int u=edge[0];
                int v=edge[1];
                int price=edge[2];

                if(result[u]!=INT_MAX && result[u]+price<temp[v]){
                    temp[v]=result[u]+price;
                   
                }
            }

            result=temp;


        }

       return (result[dst] == INT_MAX) ? -1 : result[dst];

        // 0 1   2   3
        // 0 100 200 700


    }
};