class Solution {
public:
int n;
int t[50001][3];
int helper(vector<int>& prices,int idx,int canBuy,int fee){
    if(idx==n){
        return 0;
    }

    if(t[idx][canBuy]!=-1){
        return t[idx][canBuy];
    }

    if(canBuy){
        int buy=-prices[idx]+helper(prices,idx+1,0,fee);
        int skip=helper(prices,idx+1,1,fee);
        return t[idx][canBuy]=max(buy,skip);
    }
    else{
        int sell=prices[idx]- fee +helper(prices,idx+1,1,fee);
        int skip=helper(prices,idx+1,0,fee);
        return t[idx][canBuy]=max(sell,skip);
    }
}
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return helper(prices,0,1,fee);
        
    }
};