class Solution {
public:
    int sum = 0;

    void f(TreeNode* root, string &num) {
        if (!root) return;

        num += to_string(root->val);

        if (!root->left && !root->right) {
            sum += stoi(num, 0, 2);
            num.pop_back();  
            return;
        }

        f(root->left, num);
        f(root->right, num);

        num.pop_back();  // backtrack before returning to parent
    }

    int sumRootToLeaf(TreeNode* root) {
        string num = "";
        f(root, num);
        return sum;
    }
};
