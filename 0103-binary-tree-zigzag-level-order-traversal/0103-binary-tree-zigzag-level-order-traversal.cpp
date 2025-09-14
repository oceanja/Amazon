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