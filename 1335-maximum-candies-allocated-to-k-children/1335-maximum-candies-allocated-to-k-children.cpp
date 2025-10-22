class Solution {
public:

bool helper(vector<int>& candies,long long k, int noOfCandies){
    int n=candies.size();

    long long  children=0;

    for(int i=0;i<n;i++){
        children+=(candies[i]/noOfCandies);

        if(children>=k){
            return true;
        }
    }

    return false;

}
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int l=1;
        int r=*max_element(candies.begin(),candies.end());
        int ans=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(helper(candies,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else{

                r=mid-1;

            }
        }
        
    
        return ans;
        
        
    }
};