/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


“So the problem is: I’m given a binary tree, a target node, and an integer k. 
I need to return all the nodes that are exactly k edges away from the target.
My first instinct was: if it were only about going downwards from the target, 
then it’s easy — I could just do a DFS from the target’s left and right children, count steps, and stop when I hit k.
But the tricky part is that distance doesn’t just mean going down. A node k away could also be above
the target or in another branch entirely. And in a tree, I don’t naturally have pointers to the parent — 
I only have left and right. That’s a problem.
So then I thought: how do I move both up and down? If I had a
way to quickly go to the parent of a node, then the tree would basically 
become an undirected graph. That’s when the idea of a parent map came in: during a DFS, 
I can store parent[child] = node. After that, I’ll be able to go left, right, or parent from any node.
Once I turn it into an undirected graph, the problem becomes a lot cleaner:
it’s basically “find all nodes at distance k from a starting node in a graph.” And the standard way
to do that is BFS, because BFS explores level by level. Each level of BFS corresponds to +1 distance.

So my plan became:
Do a DFS to build the parent map.
Start BFS from the target node, keep track of visited nodes to avoid cycles, and expand to left, right, and parent.
When I finish exactly k BFS levels, whatever’s in the queue are the nodes at distance k.
That’s the intuition I built: convert the tree into an undirected graph with parent pointers,
then use BFS to collect all nodes at distance k.”

    
Time Complexity

Building the parent map touches each node once → O(N).

BFS also visits each node once → O(N).

Each edge/neighbor (left, right, parent) is checked a constant number of times.

Total time = O(N).

How I evaluated it: I asked: “How many times can any node be processed?” Once in DFS, once in BFS → linear in number of nodes.

📦 Space Complexity

Parent map stores up to N-1 entries → O(N).

BFS queue and visited set → up to O(N) in the worst case.

DFS recursion stack → O(H), where H is tree height.

Total space = O(N).

How I evaluated it: counted extra data structures (parent map + queue + visited), all linear; recursion adds at most height.


    
****************************************************************CODE************************************************************************
class Solution {
public:

unordered_map<TreeNode* ,TreeNode* > parent;

void inorder(TreeNode* root){
    if(root==NULL){
        return ;
    }

    if(root->left){
        parent[root->left]=root;
        inorder(root->left);
    }

    if(root->right){
        parent[root->right]=root;
        inorder(root->right);
    }

}

void solve(TreeNode* root, TreeNode* target, int k, vector<int> &result){
    if(root==NULL){
        return;
    }

    queue<TreeNode*>q;
    q.push(target);

    unordered_set<int> vis;
    vis.insert(target->val);

    while(!q.empty()){
        int n=q.size();

        if(k==0){
            break;
        }

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

        k--;
    }


    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        result.push_back(node->val);
    }

}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;

        inorder(root);

        solve(root,target,k,result);

        return result;
        
    }
};
