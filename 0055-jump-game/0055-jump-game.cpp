So the problem is: given an array where each element tells me the maximum jump length from that index,
I need to check if I can reach the last index starting from the first one.

My first thought was: this looks like a recursive exploration problem. From any index,
I can jump 1 step, 2 steps, … up to nums[idx]. If from any of those jumps I can eventually reach the end, then the answer is true.

So I started with a recursive function solve(idx) that tries all jumps from that position. 
The base case is simple: if I’m already at the last index, return true.

But then I realized recursion alone will re-explore the same subproblems many times. 
For example, if multiple paths lead to the same index, I’d keep recomputing from that index. 
That’s exponential. So the natural improvement is to add memoization.

I keep a DP array t[idx] initialized to -1. When I compute the result for an index, 
I store it. Next time I revisit that index, I just return the stored value. This way each index is solved only once.

So the recursion with memoization checks:
Base: if idx == n-1, return true.
If already computed, return from memo.
Otherwise, try all jumps from 1 to nums[idx], and if any leads to the end, mark it true.
If none works, mark it false.

Time and  Space Complexity

Time: Each index is solved once, and for each index I may try up to nums[idx] jumps. 
In the worst case that’s O(N²), but memoization ensures no recomputation.

Space: O(N) for the memo array + O(N) recursion stack in the worst case.


*********************** CODE -TOP DOWN*****************************************************

class Solution {
public:

int t[10001];

bool solve(vector<int>& nums,int n,int idx){
    if(idx==n-1){
        return true;
    }

    if(t[idx]!=-1){
        return t[idx];
    }

    for(int i=1;i<=nums[idx];i++){
        if(solve(nums,n,idx+i)==true){
            return t[idx]=true;
        }
    }

    return t[idx]=false;
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));

        return solve(nums,n,0);
        
    }
};

*************************** BOTTOM UP**************************************
The problem is: we need to check if we can jump from the first index to the last. 
Each number tells me the maximum jump length from that position.
Earlier I thought about recursion + memoization, where from each index I try all possible jumps. 
But that has overhead and can go up to O(N²). So I thought: can I flip this and build it bottom-up?
mtlb pahle we will check ki har i k liye piche koi aisa j hai kya jisko j +nums[j] krke i tk pohoch skte hi ya nhi so if t[j]== true dega and 
j+nums[j] i ya usse aage pohchega tb t[i] true mark ho jaayega .
I defined a DP array t[i] which means: is index i reachable from the start?
I know t[0] = true, because I’m already at the start.
Then, for each index i from 1 to n-1, I check: is there some previous index j such 
that j is reachable (t[j] = true) and from j I can jump to i (j + nums[j] >= i)?

If yes, then t[i] = true.

At the end, I just return whether t[n-1] is true.

So instead of exploring recursively, I’m iteratively marking reachable positions and building up to the last index.

Time and Space Complexity

Time complexity: For every index i, in the worst case I may check all previous j. That’s O(N²).

Space complexity: O(N) for the DP array.

(I evaluated this by noting: two nested loops, outer loop runs N, inner can run up to N, so O(N²). DP array is linear in size.)
**************************************** CODE=BOTTOM UP****************************************************************************
    
class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> t(n, false);
        //t[i] = True means, you can reach index i
        
        t[0] = true; //Already at starting index
        
        for(int i = 1; i<n; i++) {
            for(int j = i-1; j>=0; j--) {
                if(j + nums[j] >= i && t[j]) { //here t[j] == true means you should be able to reach j also, 
                                               //then only you can plan to jump(j+nums[i])  from this jth index
                    t[i] = true;
                    break;
                }
            }
        }
        
        
        return t[n-1];

    }
};

********************************** MOST OPTIMAL**************************************    

The problem is: can I reach the last index given that each number tells me the maximum jump length?

I started with recursion + memoization: from each index, try all possible jumps. 
That works but can go up to O(N²). Then I thought of bottom-up DP, where I check reachability of each index. 
That’s cleaner, but still O(N²).

Then I realized: I don’t actually need to check all previous indices for each position.
What really matters is the farthest point I can reach at any moment.

So my greedy idea is:

Keep a variable maxReachable which tracks the farthest index I can jump to so far.

Iterate through the array. At index i, if i is greater than maxReachable, it means I can’t even reach this index → return false immediately.

Otherwise, update maxReachable = max(maxReachable, i + nums[i]).

If I finish the loop without failing, that means every index up to n-1 was reachable → return true.

This way, instead of checking all paths, I just maintain the maximum reach at every step.”

Time and  Space Complexity

Time Complexity: O(N), because I only scan the array once.

Space Complexity: O(1), just a couple of variables.

(I evaluated by noting there are no nested loops, only one pass, and only constant extra variables.)



    
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n            = nums.size();
        
        for(int i = 0; i<n; i++) {
            if(i > maxReachable) {
                return false;
            }
            maxReachable = max(maxReachable, nums[i]+i);
        }
        
        return true;
    }
};
