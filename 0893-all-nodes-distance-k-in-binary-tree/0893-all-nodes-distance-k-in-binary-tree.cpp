/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode* ,TreeNode*> mpp;


void fillParent(TreeNode* root){
    if(root==NULL){
        return;
    }

    if(root->left){
        mpp[root->left]=root;
        fillParent(root->left);
    }

    if(root->right){
        mpp[root->right]=root;
         fillParent(root->right);
    }
}
void f(TreeNode* root, TreeNode* target, int k,vector<int> &result){

    queue<pair<TreeNode*, int>> q;
    unordered_set<TreeNode*> vis;
    q.push({target, 0});
    vis.insert(target);

    while(!q.empty()){
            TreeNode* node=q.front().first;
            int dist=q.front().second;
            q.pop();
                if(dist==k){
                    result.push_back(node->val);
                }
                else{

                    if(node->left && !vis.count(node->left)){
                    q.push({node->left,dist+1});
                    vis.insert(node->left);
                    }

                    if(node->right && !vis.count(node->right)){
                        q.push({node->right,dist+1});
                        vis.insert(node->right);
                    }

                    if(mpp.count(node) && !vis.count(mpp[node])){
                        q.push({mpp[node],dist+1});
                        vis.insert(mpp[node]);
                    }

                }  
        }
}



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        fillParent(root);
        f(root,target,k,result);
        return result;
    }
};