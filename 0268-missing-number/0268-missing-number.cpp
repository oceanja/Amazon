class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        // 0 1 3 

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                return i;
            }
        }

        return n;
        
    }
};