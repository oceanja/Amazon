class Solution {
public:
    int totalSum = 0;

    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int l = solve(root->left);
        int r = solve(root->right);


        totalSum += abs(l - r);

    
        return l + r + root->val;
    }

    int findTilt(TreeNode* root) {
        solve(root);
        return totalSum;
    }
};
