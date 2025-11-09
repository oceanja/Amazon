class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
    if(size == 0)
        return 0;
        
    vector<vector<int>> dp(size, vector<int>(size, 0));
       
    for(int len = 1; len <= size; len++) {
        for(int i = 0; i <= size - len; i++) {
            int j = len + i - 1;
            for(int k = i; k <= j; k++) { 
                int leftValue  = (i == 0 ? 1 : nums[i-1]);
                int rightValue = (j == size-1 ? 1 : nums[j+1]);
                int before = (i == k ? 0 : dp[i][k-1]);
                int after  = (j == k ? 0 : dp[k+1][j]);
                    
                dp[i][j] = max(dp[i][j], 
                         leftValue * nums[k] * rightValue + before + after);
            }   
        }
    }    
    return dp[0][size-1];
    }
};