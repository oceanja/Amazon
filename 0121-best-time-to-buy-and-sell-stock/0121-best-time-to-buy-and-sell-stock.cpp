class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int mini=INT_MAX;
        int maxiProfit=0;

        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            maxiProfit=max(maxiProfit,prices[i]-mini);

        }

        return maxiProfit;
        
    }
};