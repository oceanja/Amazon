Step 1 – First greedy thought
“At first, I was thinking maybe I can just try greedily. Since the problem is asking for the largest outlier, 
 my first instinct was: why not just remove the largest number and see if the condition holds? 
If it doesn’t, then maybe try the next largest, and so on.”

Step 2 – Why greedy fails
“But then I realized that doesn’t actually work. The condition for being an 
outlier is very specific: after removing x, the sum of the remaining numbers must equal 2 * s 
for some element s. That condition depends on the relationship between all the numbers, not 
just the size of the candidate. So just looking at the largest first won’t necessarily find the correct answer.”

Step 3 – Refined idea using sums
“So I stepped back and looked at the formula.
If totalSum is the sum of all numbers, and I remove some number x, then the sum of the rest is totalSum - x.

For x to be an outlier, I need:
totalSum - x = 2 * s for some s in the array.
That means s = (totalSum - x) / 2.

Now the problem becomes much cleaner: for each candidate x, I just need to check if (totalSum - x) 
is even, and whether (totalSum - x)/2 exists in the array.”

Step 4 – Efficient check
“To make this check fast, I built a frequency map of all numbers. 
For each candidate x, I temporarily decrement its count (so I don’t accidentally reuse the same element), 
compute (totalSum - x)/2, and see if that number exists in the map. If yes, then x is an outlier. 
And I keep track of the maximum outlier I’ve seen.”

Step 5 – Complexity

Building the map: O(N).

Looping over all candidates: O(N).

Each lookup in the map: O(1).
So total time is O(N), and space is O(N) for the frequency map.



class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long totalSum = 0;
        unordered_map<int, int> mpp;

        for (int num : nums) {
            totalSum += num;
            mpp[num] += 1;
        }

        int maxOutlier = INT_MIN;
        for (int num : nums) {
            long long requiredSum = totalSum - num;
            if (requiredSum % 2 != 0) continue;

            long long potentialSum = requiredSum / 2;
            mpp[num] -= 1;
            int sumElement = potentialSum;
            int count = mpp.count(sumElement) ? mpp[sumElement] : 0;
            if (count > 0) maxOutlier = max(maxOutlier, num);
            mpp[num] += 1;
        }

        return maxOutlier;
    }
}; 
