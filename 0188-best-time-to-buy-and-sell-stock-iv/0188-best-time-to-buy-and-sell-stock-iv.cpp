class Solution {
public:
int n;
int t[1001][3][101];
int solve(vector<int>& prices,int idx,int canBuy,int k,int transactions){
    if(idx==n || transactions==k){
        return 0;
    }

    if(t[idx][canBuy][transactions]!=-1){
        return t[idx][canBuy][transactions];
    }

    if(canBuy){
        int buy=-prices[idx]+solve(prices,idx+1,0,k,transactions);
        int skip=solve(prices,idx+1,1,k,transactions);
        return t[idx][canBuy][transactions]=max(buy,skip);
    }
    else{
        int sell=prices[idx]+solve(prices,idx+1,1,k,transactions+1);
        int skip=solve(prices,idx+1,0,k,transactions);
        return t[idx][canBuy][transactions]=max(sell,skip);
    }
}
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));
        return solve(prices,0,1,k,0);
        
        
    }
};