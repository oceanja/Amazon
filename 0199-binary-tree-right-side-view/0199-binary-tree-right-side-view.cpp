*** Approach: 
So the problem is to return the right side view of a binary tree — basically, 
the set of nodes that would be visible if you stood to the right of the tree and looked in.
My first attempt was to just follow the right child, and if it didn’t exist, then go left. 
But then I realized that only gives me the right spine of the tree, not necessarily the
visible nodes per level.

For example, if a left child exists at a deeper level and no right child is there, 
that left node should still be visible.
So the key insight is: I actually want the first node I encounter at each level when exploring
from the right side first.
To implement that, I pass a level parameter in my DFS. 
Each time I go down a level, I check: if this is the first time I’ve reached this 
level (level == result.size()), I add that node’s value. Since I always recurse into the 
right child before the left, the first node I see at each level is exactly the rightmost one.
This way I cover all nodes, but I only record one per level, and it ends up being the right side view.”

Time & Space Complexity

Time: O(N) because I visit each node once.

Space: O(H) for recursion stack, where H is the height of the tree. In the worst case (skewed tree), H = N.

How I evaluated it: I asked myself: do I visit any node more than once? No → O(N).
Do I store anything more than one result per level? No, just a single array of size = depth of tree.
Stack usage grows linearly with depth → O(H).

    
class Solution {
public:

void giveRightSideView(TreeNode* root, vector<int> &result, int level){
    if(root==NULL){
        return;
    }


    if(level == result.size()){
        result.push_back(root->val);
    }


    giveRightSideView(root->right, result, level+1);
    giveRightSideView(root->left, result, level+1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    giveRightSideView(root, result, 0);   
    return result;
}
};
