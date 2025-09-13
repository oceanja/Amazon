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

unordered_map<int,int> parent;

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }

    if(root->left){
        parent[root->left->val]=root->val;
        inorder(root->left);
    }

     if(root->right){
        parent[root->right->val]=root->val;
        inorder(root->right);
    }
}

int  bfs(TreeNode* root, int target){
    if(root==NULL) return -1;

    queue<pair<TreeNode*,int>> q;   
    q.push({root,0});


    while(!q.empty()){

         auto [valNode, level] =q.front();
         q.pop();

         if(valNode->val==target){
            return level;
         }

         if(valNode->left){
            q.push({valNode->left,level+1});
         }
         if(valNode->right){
            q.push({valNode->right,level+1});
         }

        
    }

     return -1;

}
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL){
            return false;
        }

        inorder(root);

        if((bfs(root,x)==bfs(root,y)) && parent[x]!=parent[y]){
            return true;
        }

        return false;
        
    }
};