High-Level Overview

The first thing I’d do is frame the problem: we want all unique quadruplets (a,b,c,d) such that a + b + c + d = target.
I’ll walk through three levels:

Brute force (O(n⁴)): try every 4-tuple, dedupe.

Better with hashing (O(n³)): fix two numbers, reduce to a Two-Sum using a hash set; handle duplicates carefully.

Optimal (O(n³)): sort and use two pointers for the inner pair, with systematic duplicate skipping (the code you shared).

Data Structures & Algorithm Choice

Brute: just arrays/loops; maybe a set<vector<int>> to avoid duplicates.

Hash-based better:

Fix two indices (i, j), then scan the rest with an unordered_set to detect the complement to reach target - (nums[i] + nums[j]).

Optionally a set<vector<int>> to dedupe sorted quadruplets.

Optimal (sorted + two pointers):

Sorting enables monotonic movement of k and l based on the current sum, and easy duplicate skipping with adjacent comparisons.

Use long long for intermediate sums to avoid overflow.


Brute, Better, Optimal — how I’d pitch them quickly

Brute (O(n⁴))

// For illustration (not full code):
set<vector<int>> uniq;
sort(nums.begin(), nums.end());
for (int a=0; a<n; a++)
 for (int b=a+1; b<n; b++)
  for (int c=b+1; c<n; c++)
   for (int d=c+1; d<n; d++)
     if ((long long)nums[a]+nums[b]+nums[c]+nums[d] == target)
       uniq.insert({nums[a],nums[b],nums[c],nums[d]});
return vector<vector<int>>(uniq.begin(), uniq.end());

Better with HashSet (O(n³))

// Fix i, j; solve 2-sum on the tail using a set
set<vector<int>> uniq;
sort(nums.begin(), nums.end());
for (int i=0; i<n; ++i) {
  for (int j=i+1; j<n; ++j) {
    long long need = (long long)target - nums[i] - nums[j];
    unordered_set<int> seen;
    for (int k=j+1; k<n; ++k) {
      int x = nums[k];
      if (seen.count((int)(need - x))) {
        vector<int> q = {nums[i], nums[j], (int)(need - x), x};
        sort(q.begin(), q.end());
        uniq.insert(q);
      }
      seen.insert(x);
    }
  }
}
return {uniq.begin(), uniq.end()};

*****************************************************
4Sum — Optimized Two-Pointer Approach (Interview Script)
1) High-Level Overview

The first thing I’d do is frame the plan in one line: sort the array, fix two numbers, and then find the remaining pair with two pointers.
Sorting gives me order. With order, I can move a left pointer right to increase the sum and a right pointer left to decrease it. 
This lets me find all pairs that complete the four-number sum in linear time per (i, j)
choice—while cleanly skipping duplicates so each quadruplet appears exactly once.

2) Data Structures & Algorithm Choice

Data structures: just the input vector (in-place sort) and a result vector of quadruplets. No extra hash maps needed.

Algorithms used:

Sorting the array.

Nested loops to pick the first two numbers i and j.

Two-pointer sweep (k from left, l from right) on the remaining subarray to find pairs summing to target - nums[i] - nums[j].

Why this combo?
Sorting turns the “find a pair with a target sum” subproblem into a monotonic search: 
if the current sum is too small, move k++ to get bigger; if it’s too large, move l-- to get smaller. 
That makes the inner search O(n) instead of O(n²), bringing the total to O(n³).

3) Step-by-Step Walkthrough (with a tiny example)

Let’s use nums = [1, 0, -1, 0, -2, 2], target = 0.
Step 1 — Sort: [-2, -1, 0, 0, 1, 2].

I’ll talk through the control flow exactly like I’d code it:

Outer loop (i): iterate i from 0 … n-1.

Duplicate guard for i: if i > 0 and nums[i] == nums[i-1], skip—because any quadruplet starting with 
this value was already generated when i-1 was used.

Second loop (j): iterate j from i+1 … n-1.

Duplicate guard for j: if j > i+1 and nums[j] == nums[j-1], skip—same reasoning as i.

Two pointers (k, l): set k = j+1, l = n-1.

While k < l:

Compute sum = nums[i] + nums[j] + nums[k] + nums[l] (use long long to avoid overflow).

If sum == target: we’ve found one quadruplet.

Push {nums[i], nums[j], nums[k], nums[l]} into the answer.

Move both pointers: k++, l--.

Skip duplicates on the move:

while k < l and nums[k] == nums[k-1], k++

while k < l and nums[l] == nums[l+1], l--
This ensures we never repeat the same quadruplet.

Else if sum < target: we need a larger sum → k++ (move left pointer right).

Else (sum > target): we need a smaller sum → l-- (move right pointer left).

Let me trace one path so it’s intuitive:

Pick i = -2, j = -1. We want the inner pair to sum to +3.

k = 0 (value 0), l = 5 (value 2): pair sum = 2 → too small → k++.

Try (k=2 -> 0, l=5 -> 2): still 2 → k++.

(k=3 -> 0, l=5 -> 2): still 2 → k++.

(k=4 -> 1, l=5 -> 2): now 3 → perfect → record [-2, -1, 1, 2].

Move both pointers: k=5, l=4 → stop (k >= l).

Next, i = -2, j = 0 (first 0): need inner sum = 2. Two-pointer finds [-2, 0, 0, 2].

Next, i = -1, j = 0: need inner sum = 1. Two-pointer finds [-1, 0, 0, 1].

Duplicate guards ensure we don’t emit the same quadruplet twice.

Key intuition I emphasize:

Sorting lets me navigate the remaining pair deterministically.
If I’m too light, I push left pointer right to add weight; 
if I’m too heavy, I trim from the right. Duplicate skipping is 
just “if the next number is identical to the one I just used at that level,
skip it”—first for i, then j, and after recording a hit for k and l.

4) Complexity Analysis

Sorting: O(n log n).

Nested loops + two pointers:

i runs O(n), j runs O(n) for each i → O(n²) outer work.

For each (i, j), the two-pointer sweep is O(n) (each of k and l moves at most n steps total).

Total O(n³) time. Sorting is dominated by the O(n³).

Space: O(1) extra (ignoring output). We sort in place and use constant overhead.



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;

                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];

                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }

                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }

        return ans;
        
    }
};
