class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();

        vector<int> lessThanPivot;
        vector<int> moreThanPivot;
        vector<int> equalPivot;
        int l=0;
        int m=0;
        int p=0;

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                lessThanPivot.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                moreThanPivot.push_back(nums[i]);
            }
            else{
                equalPivot.push_back(nums[i]);
            }
        }

        int idx=0;

        for(int i=0;i<lessThanPivot.size();i++){
            nums[idx]=lessThanPivot[l];
            idx++;
            l++;
        }

        for(int i=0;i<equalPivot.size();i++){
            nums[idx]=equalPivot[p];
            idx++;
            p++;
        }

         for(int i=0;i<moreThanPivot.size();i++){
            nums[idx]=moreThanPivot[m];
            idx++;
            m++;
        }

        return nums;
        
    }
};