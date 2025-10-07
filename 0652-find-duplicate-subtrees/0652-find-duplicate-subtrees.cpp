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

string serialize(TreeNode* root,vector<TreeNode*> &nodes,unordered_map<string,int> &mpp){

    if(root==NULL){
        return "#";
    }

    string s=to_string(root->val)+","+serialize(root->left,nodes,mpp)+","+
    serialize(root->right,nodes,mpp);

    mpp[s]++;
     if (mpp[s] == 2) {
        nodes.push_back(root);
    }


    return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> nodes;
        unordered_map<string,int> mpp;
        serialize(root,nodes,mpp);

        return nodes;

      
        
    }
};