/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


***********************************************APPROACH**************************************
Okay, it’s a BST, so left subtree < root < right subtree.
If I’m standing at some root, I can compare both targets p and q to root->val:
If both p and q are smaller than root, then their LCA must be somewhere in the left subtree. So I should go left.
If both are greater than root, their LCA must be in the right subtree. So I should go right.
Otherwise, I’ve found a split point: one side is ≤ root and the other is ≥ root (or one equals the root). 
That means this root is the LCA—it’s the first node where their paths diverge.

This “split point” idea naturally handles cases like p->val == root->val or q->val == root->val—then the root itself is the ancestor. 
It also avoids worrying about which of p or q is larger—comparison to root is all that matters at each step.”

 Why it’s correct

“In a BST, any node smaller than root can’t be in the right subtree, and any node greater than root can’t be in the left subtree.
So as long as both targets sit strictly on the same side, the LCA can’t be at the current root; it must be deeper on that side.
The first time they are not on the same side, I’m exactly at their lowest common ancestor.”

⏱ Time &  Space (and how I evaluate them)

Time: O(H) where H is the tree height. I only move down one path (left or right) until 
I hit the split point—so I visit at most one node per level.

Space: O(H) with recursion (call stack equals height).
If I do it iteratively, it becomes O(1) extra space.

How I evaluated it:
I counted how many nodes I can possibly visit—at most one per level, 
 never backtracking—so proportional to the height. 
The stack depth matches the longest chain I might follow.



CODE:
    
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return nullptr;
        }

        int value=root->val;

        if(value > p->val && value > q->val ){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if( value < p->val && value < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }

        else{
            return root;
        }
        
    }
};
