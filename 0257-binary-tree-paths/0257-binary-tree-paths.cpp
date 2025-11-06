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

void f(TreeNode* root,string temp,vector<string> &paths){
    if(root==NULL){
        return;
    }

    temp= temp + to_string(root->val);

    if(root->left==NULL && root->right==NULL){
        paths.push_back(temp);
      
        return;
    }

    temp+="->";
    f(root->left,temp,paths);
    f(root->right,temp,paths);

 


}
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp="";
        vector<string> paths;

        f(root,temp,paths);

        return paths;
        
    }
};