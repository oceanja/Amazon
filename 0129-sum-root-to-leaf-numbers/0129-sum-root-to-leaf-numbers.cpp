/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


** Brute solution approach : So the problem is asking me to calculate the sum of all numbers formed from root-to-leaf paths in a binary tree.

My first intuition was very direct: if I can somehow collect all the paths from root to each leaf, then I can easily convert
each path into a number and add them up.
To implement this, I decided to use a helper function that recursively builds every root-to-leaf path.
I keep a temporary vector to track the current path, and whenever I reach a leaf node, I push that path into a list of paths.
Once I have all these paths, I process each one: I iterate through its digits and convert it into a number by
multiplying the current number by 10 and adding the next digit. 

Finally, I sum up all these numbers and return the result.
This approach is very intuitive because it mirrors how we would do it manually: 
first write down all the numbers, then sum them. But it’s also brute force, because I’m storing all paths explicitly.”

Time Complexity Analysis:
“To analyze complexity, I break it into two steps:
Generating all paths: In the worst case, the tree can be skewed, so we can have up to O(N)
nodes per path and O(N) such paths → O(N²) work to just build/store them.

Converting paths to numbers: For each path, I iterate through its length (up to O(N)), 
and do this for all paths, so again it could go to O(N²).

Adding both, the time complexity is O(N²) in the worst case.”

or space complexity: , apart from recursion stack (O(H), where H is tree height), I’m storing all root-to-leaf paths. 
In the worst case (skewed tree), this is O(N²) extra space because each path could be length N, and there could be N leaves.

So total space complexity is O(N²) in the worst case.”

But clearly, storing all paths explicitly is not efficient. 
Once I’m confident the brute force is correct, I’d like to refine it further — 
for example, by avoiding storing paths at all and instead carrying the running number during traversal. 
That would bring down both time and space complexities.”



** BRUTE FORCE CODE**:
class Solution {
public:

int findSumOfNumber(vector<vector<int>> &paths){

    int sum=0;

    for(vector<int> path:paths){
        int num = 0;
        for (int d : path) {
            num = num * 10 + d;  
        }
        sum+=num;
    }

    return sum;
}

vector<vector<int>> findNodetoLeafPaths(TreeNode* root, vector<int> &temp){

    vector<vector<int>> result;
    if(root==NULL) return result;  

    temp.push_back(root->val);      

    if(root->left==NULL && root->right==NULL){
        result.push_back(temp);
    } else {
        auto left  = findNodetoLeafPaths(root->left,temp);
        auto right = findNodetoLeafPaths(root->right,temp);
        result.insert(result.end(), left.begin(), left.end());   
        result.insert(result.end(), right.begin(), right.end()); 
    }

    temp.pop_back(); 
    return result;   
}

int sumNumbers(TreeNode* root) {

    // brute
    if(root==NULL ){
        return 0;
    }
    vector<int> temp;
    vector<vector<int>> paths= findNodetoLeafPaths(root,temp);
    int totalSum=findSumOfNumber(paths);   
    return totalSum;
}
};

**************------------OPTIMIZED APPROACH********************----------------

** OPTIMAL APPROACH: So after I wrote the brute force, I started thinking — do I really need to actually store all those paths?
If you think about it, when I’m moving down the tree, I’m basically just extending a number digit by digit. 
    For example, if I’ve built 49 so far, and the next node is 5, I don’t need the whole path [4, 9, 5] — 
    I can just do 49 * 10 + 5 = 495.
That gave me the idea to carry a running integer along the recursion. 
    Each time I go deeper, I multiply by 10 and add the current digit.
    And whenever I hit a leaf, that running number is already the full number I want, so I just return it.

Then I just take the sum of whatever comes from the left and right subtrees. 
    That way, I’m directly calculating the final answer in one traversal, without keeping extra vectors or paths in memory.”
    
Now for complexity — here I’m visiting every node only once, and at each step I’m just doing O(1) work 
(a multiply and an add). So the total time is O(N).

For space, since I’m not storing paths anymore, 
the only extra space is the recursion stack, which is equal to the height of the tree. 
So best case for a balanced tree it’s O(log N), worst case for a skewed tree it’s O(N).”

** CODE:
class Solution {
public:

int solve(TreeNode* root,int curr){

     if(!root){
            return 0;
        }

    curr=(curr*10)+root->val;

    if(root->left==NULL && root->right==NULL){
        return curr;
    }
    int l=solve(root->left,curr);
    int r=solve(root->right,curr);

    return l+r;
}
    int sumNumbers(TreeNode* root) {

        return solve(root,0);
    
        
    }
};


