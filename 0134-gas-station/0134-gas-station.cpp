******************************* BRUTE***************************************
Brute force approach:
“My first idea was straightforward brute force: since we need to find a valid starting station, 
I thought why not just try every station as the starting point? So I loop over each index i, 
assume it’s the start, and simulate the journey around the circle. At each step, I keep track
of how much gas is left in the tank — add the gas at the current station, subtract the cost to move to the next, 
and continue. If at any point the fuel becomes negative, I know this start fails. If I manage 
to return back to the starting point without running out of gas, then that index is the answer. 
The approach is conceptually simple, but the problem is efficiency: for each of the N stations I may
simulate up to N steps, so the worst-case time complexity is O(N²). The space is constant, since I only 
store a few variables for simulation. While this approach works for small inputs, it becomes too slow for 
large arrays, so I knew I needed to optimize further.”

CODE:
    
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
     int n=gas.size();
     
     for(int i=0;i<n;i++){
         if(gas[i]<cost[i]){
             continue;
         }
         
         int j=(i+1)%n;
         
         int costForMovingToNextStation=cost[i];
         int gasEarnAtNextStation=gas[j];
         
         int currGas=gas[i]-costForMovingToNextStation+gasEarnAtNextStation;
         
         while(j!=i){
             if(currGas<cost[j]){
                 break;
             }
             
             int costForMovingFromThisStationj=cost[j];
             j=(j+1)%n;
             
             int gasEarnAtNextStation=gas[j];
             
             currGas=currGas-costForMovingFromThisStationj+gasEarnAtNextStation;
         }
         
         if(j==i){
             return i;
         }
     }
     
     return -1;
        
    }
};

********************************************OPTIMAL*****************************************************************
To improve, I tried to reason more globally. First, I noticed that if the total amount of gas available across 
all stations is less than the total cost required to complete the circle, then it’s impossible to succeed 
no matter where I start, so that check can immediately return -1. Now, suppose the totals are valid. 
I maintain a running balance as I simulate from a candidate starting station: balance += gas[i] - cost[i]. 
If this balance ever goes negative at station k, that means I cannot reach station k+1 from my current start. 
More importantly, it also means that no station between my start and k could be a valid start either,
because they would have accumulated even less gas by the time they reached k.
So instead of trying them, I can safely reset the candidate start to k+1 and reset my balance to 0,
then continue. By the time I finish one full pass, the last candidate start index I set is guaranteed to be the
solution. This greedy observation reduces the problem to a single O(N) pass, and since I only use 
a few variables (balance, result, and totals), the space remains O(1). So compared to the 
brute force O(N²), this greedy reset trick brings it down to O(N), which is efficient even for large inputs.”


CODE:

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();

        int totalSum=accumulate(gas.begin(),gas.end(),0);
        int costSum=accumulate(cost.begin(),cost.end(),0);

        if(totalSum<costSum){
            return -1;
        }

        int result=0;
        int total=0;

        for(int i=0;i<n;i++){

            total=total+gas[i]-cost[i];

            if(total<0){
                result=i+1;
                total=0;
            }

        }

        return result;
        
    }
};
