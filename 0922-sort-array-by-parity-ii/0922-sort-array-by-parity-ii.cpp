class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();

        vector<int> odd;
        vector<int> even;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]); // 4 2
            }
            else{
                odd.push_back(nums[i]); // 5 7 
            }
        }

        int e=0;
        int o=0;

        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=even[e++];
            }
            else{
                nums[i]=odd[o++];
            }
        }

        return nums;


    }
};