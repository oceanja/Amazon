class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        // 3 5 7
        // 4 6 7
        // 5 7 7
        // 6 8 7
        // 7 8 8
        // 8 8 8
        int mini=*min_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++ ){
            ans+=(nums[i]-mini);
        }

        return ans;








    }
};