class Solution {
public:
int gardenLastPoint;
map<pair<int,int>,int> mpp;

int solve(int i, int maxEnd, vector<pair<int,int>> &range){
    if(i>=range.size()){

        if(maxEnd>=gardenLastPoint){
            return 0;
        }
        else{
            return 1e9;
        }

    }

    if(range[i].first>maxEnd){
        return 1e9;
    }

    if(mpp.find({i,maxEnd})!=mpp.end()){
        return mpp[{i,maxEnd}];
    }

    int take=1+solve(i+1,max(maxEnd,range[i].second),range);
    int not_take=solve(i+1,maxEnd,range);

    return mpp[{i,maxEnd}]=min(take,not_take);
}
    int minTaps(int n, vector<int>& ranges) {
        gardenLastPoint=n;
        vector<pair<int,int>> range;

        for(int i=0;i<ranges.size();i++){
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);

            range.push_back({start,end});
        }

        sort(range.begin(),range.end());

        int result=solve(0,0,range);

        return result==1e9?-1:result;
        
    }
};