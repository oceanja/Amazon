class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp; // cumSum,idx

        int csum=0;
        int maxLen=0;

        mpp[0]=-1;


      for(int i=0;i<n;i++){
        csum+=(nums[i]==1)?1:-1;

        if(mpp.find(csum)!=mpp.end()){
            int len=i-mpp[csum];
            maxLen=max(len,maxLen);
        }
        else{
            mpp[csum]=i;
        }

      }

      return maxLen;

    }
};