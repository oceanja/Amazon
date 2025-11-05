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
int sum=0;

void f(TreeNode* root,string num){

    if(!root){
        return;
    }

    num+=to_string(root->val);

    if(root->left==NULL && root->right==NULL){
        sum=sum+stoi(num,0,2);
        return ;
    }


    if(root->left){
        f(root->left,num);
    }

    if(root->right){
        f(root->right,num);
    }

}
    int sumRootToLeaf(TreeNode* root) {
        f(root,"");
        return sum;
        
    }
};