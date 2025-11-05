class Solution {
public:
int result=1;
int t[10001];

int fun(int num){
    if(num==0){
        return 0;
    }

    if(t[num]!=-1){
        return t[num];
    }

    int ans=INT_MAX;

    for(int i=1;(i*i)<=num;i++){
        int sq=i*i;
        ans=min(1+fun(num-sq),ans);
    }

    return t[num]=ans;

}
    int numSquares(int n) {
        memset(t,-1,sizeof(t));
       return fun(n);
    }
};