class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        
        unordered_map<int,int> mpp;
        int i=0;
        int j=0;
        int maxFruits=INT_MIN;
        // 1 2 3 2 2 4 4 4
        while(j<n){
            mpp[fruits[j]]++;

            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }

            maxFruits=max(maxFruits,j-i+1);
            j++;


        }
        return maxFruits;



        
    }
};