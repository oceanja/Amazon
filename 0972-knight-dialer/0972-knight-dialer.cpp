class Solution {
public:
const int M=1e9+7;
int t[5001][10];
vector<vector<int>>adj={
    {4,6}, // 0
    {6,8}, // 1
    {7,9}, // 2
    {4,8}, //3
    {3,9,0}, // 4
    {}, // 5
    {1,7,0}, // 6
    {2,6}, //7
    {1,3}, //8
    {2,4} // 9
};

int solve(int n,int digit){
    if(n==0){
        return 1;
    }

    if(t[n][digit]!=-1){
        return t[n][digit];
    }

    int ans=0;

    for(int &cell:adj[digit]){
        ans=(ans+(solve(n-1,cell)))%M;

    }

    return t[n][digit]=ans;



}
    int knightDialer(int n) {
        int total=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<=9;i++){
            total=(total+solve(n-1,i))%M;
        }

        return total;

       
    }
};