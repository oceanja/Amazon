Step 1 – Understanding the problem
“The problem is asking me to return a binary tree’s level order traversal, but in a zigzag fashion:
the first level left to right, the next right to left, then left to right again, and so on. 
So it’s basically a level order traversal with alternating directions.”

Step 2 – First intuition
“My first thought was to do a simple BFS, level by level. BFS already processes nodes level by level, 
which fits perfectly here. But the extra twist is that the order of elements alternates at each level.”

Step 3 – Handling the zigzag pattern
“To manage this, I can use a queue to do normal BFS. At each level, I know exactly how many nodes I
will process (the current queue size). I create a vector of that size, and when I place values into it:

If the direction is left-to-right, I fill it in natural order (idx = i).

If the direction is right-to-left, I fill it in reverse (idx = size-1-i).

This way, I don’t have to reverse the vector later — I directly place elements in the correct order.”

Step 4 – Direction toggle
“After finishing one level, I simply toggle a boolean flag leftToRight so the next level is traversed in the opposite order.”

Step 5 – Complexity

Time complexity: Every node is processed once, and each edge is looked at once, so it’s O(N) where N is the number of nodes.

Space complexity: We use a queue that at most holds one level of nodes (O(N) in worst case for the last level),
plus a level vector of size O(width of tree). So space is O(N) overall.


***********************************CODE**********************************

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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }

        bool leftToRight=true;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> level(n);
            int i=0;
            while(n--){
            TreeNode* node=q.front();
            q.pop();

            int idx= leftToRight?i:level.size()-1-i;
            level[idx]=node->val;

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }

            i++;

       }
            
            leftToRight=!leftToRight;
            result.push_back(level);
        }

        return result;
        
    }
};
