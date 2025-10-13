class Solution {
public:
int n;
int t[10001];

int solve(vector<int>& cost,int idx){

if(idx>=n){
    return 0;
}

if(t[idx]!=-1){
    return t[idx];
}

int take_1_jump= cost[idx]+solve(cost,idx+1);
int take_2_jump=cost[idx]+solve(cost,idx+2);

return t[idx]=min(take_1_jump,take_2_jump);

}
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memset(t,-1,sizeof(t));
        int start_from_idx_0=solve(cost,0);
        memset(t,-1,sizeof(t));
        int start_from_idx_1=solve(cost,1);

        return min(start_from_idx_0,start_from_idx_1);


        
    }
};