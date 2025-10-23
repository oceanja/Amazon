class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftSum(n);
        int ans=-1;

        leftSum[0]=nums[0];
        // 1 7 3 6 5 6
        // 1 8 11 17 22 28
        // 28 27 20 17 11 6     

        for(int i=1;i<n;i++){
            leftSum[i]=leftSum[i-1]+ nums[i];
        }

        vector<int> rightSum(n);

        rightSum[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i-- ){
            rightSum[i]=nums[i]+rightSum[i+1];
        }

        // 1 2 3
        // 1 3 6
        //  6 5 3

        for(int i=0;i<n;i++){

            if(leftSum[i]==rightSum[i]){
                ans=i;
                break;
            }

        }

        return ans;



        
    }
};