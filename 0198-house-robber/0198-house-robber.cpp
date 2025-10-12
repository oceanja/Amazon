class Solution {
public:
int n;
int t[101];
int solve(vector<int>& nums,int idx){

    if(idx>=n){
        return 0;
    }

    if(t[idx]!=-1){
        return t[idx];
    }

    

    int take=nums[idx]+solve(nums,idx+2);
    int not_take=solve(nums,idx+1);

    return t[idx]=max(take,not_take);

}
    int rob(vector<int>& nums) {
         n=nums.size();
         memset(t,-1,sizeof(t));
        return solve(nums,0);
        
    }
};