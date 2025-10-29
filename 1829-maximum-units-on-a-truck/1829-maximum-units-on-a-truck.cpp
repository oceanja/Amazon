class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        int total=0;
        
        sort(boxTypes.begin(),boxTypes.end(), [](vector<int> &a,vector<int>&b){
            return a[1]>b[1];
        });

        for(auto &box:boxTypes){
            int noOfBoxes=box[0]; // 3
            int noOfUnitsPerBox=box[1]; // 1

            if(noOfBoxes<=truckSize){
                 total=total +(noOfBoxes*noOfUnitsPerBox); // 7
                 truckSize= truckSize-noOfBoxes;
                
            }
            else{
                total=total+((truckSize)*(noOfUnitsPerBox));
                break;
            }

             

        }

        return total;

        
    }
};