class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        // fruits[i]-> quantity of ith type of fruit
        // baskets[j]-> capacity of jth basket

        // each fruit type must be plced in the leftmost basket w capacity >= quantity of fruit
        // each basket-> one fruit only
        // fruit type cannot be placed in any basket , unplaced

        // f-> 4 2 5 
        // b-> 3 5 4

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(baskets[j]>=fruits[i] && baskets[j]!=-1){
                    baskets[j]= -1 ;// mark it as used
                    break;
                }
            }
        }

        for(int i=0;i<n;i++){

            if(baskets[i]!=-1){
                ans++;
            }

        }

        return ans;




        
    }
};