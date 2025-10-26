class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int n=arr.size();
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());

        // 1 2 3 4

        int minDiff=INT_MAX;

        for(int i=0;i<n-1;i++){
            int ndiff=abs(arr[i+1]-arr[i]);
            if(ndiff<minDiff){
                minDiff=ndiff;
                result.clear();
            }

            if(ndiff==minDiff){
                 result.push_back({arr[i],arr[i+1]});
            }
        }

        sort(result.begin(),result.end());

        return result;
    }
};