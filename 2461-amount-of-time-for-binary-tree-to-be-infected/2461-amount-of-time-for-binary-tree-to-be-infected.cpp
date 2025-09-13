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
unordered_map<TreeNode*,TreeNode*> parent;

void parentFilling(TreeNode* root){
    if(root==NULL){
        return ;
    }

    if(root->left){
        parent[root->left]=root;
        parentFilling(root->left);
    }

    if(root->right){
        parent[root->right]=root;
        parentFilling(root->right);
    }
}

TreeNode* getStart(TreeNode* root, int start) {       
    if(root==NULL) return NULL;
    if(root->val == start) return root;
    TreeNode* l = getStart(root->left, start);
    if(l) return l;
    return getStart(root->right, start);
}
    int amountOfTime(TreeNode* root, int start) {
        // q->[ |   ] min=4;

        parentFilling(root);

        TreeNode* startNode=getStart(root,start);

        queue<TreeNode*> q;
        q.push(startNode);

         unordered_set<int> vis;
         vis.insert(startNode->val);

        int minutes=0;

        while(!q.empty()){
            int n=q.size();

            while(n--){
                TreeNode* curr=q.front();
                q.pop();

                if(curr->left && !vis.count(curr->left->val)){
                    q.push(curr->left);
                    vis.insert(curr->left->val);
                }

                if(curr->right && !vis.count(curr->right->val)){
                    q.push(curr->right);
                    vis.insert(curr->right->val);
                }

                if(parent.count(curr) && !vis.count(parent[curr]->val)){
                    q.push(parent[curr]);
                    vis.insert(parent[curr]->val);
                }
            }

            minutes++;
        }


        return minutes-1;




    }   

};