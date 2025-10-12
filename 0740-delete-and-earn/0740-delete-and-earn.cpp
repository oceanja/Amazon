class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> points(maxNum + 1, 0);


        for (int num : nums) {
            points[num] += num;
        }

        vector<int> dp(maxNum + 1, 0);
        dp[0] = 0;
        dp[1] = points[1];

        for (int i = 2; i <= maxNum; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + points[i]);
        }

        return dp[maxNum];
    }
};
