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

int findSumOfNumber(vector<vector<int>> &paths){

    int sum=0;

    for(vector<int> path:paths){
        int num = 0;
        for (int d : path) {
            num = num * 10 + d;  
        }
        sum+=num;
    }

    return sum;
}

vector<vector<int>> findNodetoLeafPaths(TreeNode* root, vector<int> &temp){

    vector<vector<int>> result;
    if(root==NULL) return result;  

    temp.push_back(root->val);      

    if(root->left==NULL && root->right==NULL){
        result.push_back(temp);
    } else {
        auto left  = findNodetoLeafPaths(root->left,temp);
        auto right = findNodetoLeafPaths(root->right,temp);
        result.insert(result.end(), left.begin(), left.end());   
        result.insert(result.end(), right.begin(), right.end()); 
    }

    temp.pop_back(); 
    return result;   
}

int sumNumbers(TreeNode* root) {

    // brute
    if(root==NULL ){
        return 0;
    }
    vector<int> temp;
    vector<vector<int>> paths= findNodetoLeafPaths(root,temp);
    int totalSum=findSumOfNumber(paths);   
    return totalSum;
}
};
