class Solution {
public:
int n;
int t[1000001][3][3];
int helper(vector<int>& prices,int idx,int canBuy,int transactions){

    if(idx==n || transactions==2){
        return 0;
    }

    if(t[idx][canBuy][transactions]!=-1){
        return t[idx][canBuy][transactions];
    }

    if(canBuy){
        int buy=-prices[idx]+helper(prices,idx+1,0,transactions);
        int skip=helper(prices,idx+1,1,transactions);

        return t[idx][canBuy][transactions]=max(buy,skip);
    }
    else{
        int sell=prices[idx]+helper(prices,idx+1,1,transactions+1);
        int skip=helper(prices,idx+1,0,transactions);

        return t[idx][canBuy][transactions]=max(sell,skip);
    }

   

}
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(t,-1,sizeof(t));

        return helper(prices,0,1,0);

        
    }
};