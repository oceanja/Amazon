class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        long long  score=0;

        vector<bool> marked(n,false);
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

         for(int i=0;i<n;i++){
            pq.push({nums[i],i});
         }

         while(!pq.empty()){
            auto P=pq.top();
            int val=P.first;
            int idx=P.second;
            pq.pop();

            if(!marked[idx]){

            score+=P.first;
            marked[idx]=true;
            if(idx-1>=0) marked[idx-1]=true;
            if(idx+1<n) marked[idx+1]=true;

            }

         }

         return score;



        
    }
};