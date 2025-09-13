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



“So the problem is asking if two nodes in a binary tree are cousins.
I know cousins means they have the same depth but different parents.
So my goal becomes: I need two pieces of information — depth of each node and parent of each node.

At first I thought maybe I could get both depth and parent just with one BFS. 
That’s possible, but it felt a bit messy to track parent pointers directly during BFS. So I broke it down:

For parents, I can just do a DFS. Every time I go to a child (left or right), 
I store parent[child->val] = root->val. That way I can easily look up the parent of any node later.

For depths, BFS is very natural because it processes nodes level by level. 
If I start from the root with depth 0, when I pop a node I know exactly what level it’s on. 
So I can run a BFS, and when I see the target value, I just return its depth.

Once I have both of those pieces:

If the two nodes are at the same depth and their parent values are different, then they’re cousins.

Otherwise, they’re not.

⏱ Time and  Space

Both traversals are linear. The DFS to build the parent map visits every node once, O(N). 
The BFS I run to get depths is also O(N). Space-wise, I’m storing the parent map and the BFS queue, both O(N).


********************************CODE*************************************************************
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
