class Solution {
public:
int t[30001][3];
    int helper(vector<int>& prices, int i, int canBuy) {
        int n = prices.size();
        if (i == n) return 0; 

        if(t[i][canBuy]!=-1){
            return t[i][canBuy];
        }

        if (canBuy) {
  
            int buy = -prices[i] + helper(prices, i + 1, 0);
            int skip = helper(prices, i + 1, 1);
            return t[i][canBuy]=max(buy, skip);
        } else {
            int sell = prices[i] + helper(prices, i + 1, 1);  
            int skip = helper(prices, i + 1, 0);
            return t[i][canBuy]=max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t));
        return helper(prices, 0, 1); 
    }
};
