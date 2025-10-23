class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> expected(heights.begin(),heights.end());

        sort(expected.begin(),expected.end());
        int ans=0;

        for(int i=0;i<n;i++){
            if(heights[i]!=expected[i]){
                ans++;
            }

        }

        return ans;


    }
};