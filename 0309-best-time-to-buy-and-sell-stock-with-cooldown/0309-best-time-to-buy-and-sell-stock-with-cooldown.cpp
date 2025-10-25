class Solution {
public:
int n;
int t[5001][3];
int helper(vector<int>& prices,int idx,int canBuy){
    if(idx>=n){
        return 0;
    }
    if(t[idx][canBuy]!=-1){
        return t[idx][canBuy];
    }

    if(canBuy){
        int buy= -prices[idx]+helper(prices,idx+1,0);
        int skip=helper(prices,idx+1,1);
        return t[idx][canBuy]=max(buy,skip);
    }
    else{
        int sell=prices[idx]+helper(prices,idx+2,1);
        int skip=helper(prices,idx+1,0);
        return t[idx][canBuy]=max(sell,skip);
    }
}
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return helper(prices,0,1);
        
    }
};