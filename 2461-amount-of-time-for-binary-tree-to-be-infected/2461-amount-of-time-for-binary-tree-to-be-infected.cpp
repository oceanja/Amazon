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



**********************BFS APPROACH**********************
The problem is: we have a binary tree, and an infection starts at some node given by its value. 
Every minute, the infection spreads to parent and children. I need to figure out how many minutes it takes until the entire tree is infected.
My first thought was — this is really like a graph spread problem. 
If I think of the tree as an undirected graph, each minute the infection spreads to neighbors. 
That’s exactly how a BFS works: level by level expansion corresponds to minutes.
But there’s a catch: in a normal tree I can only go to left and right.
I can’t go upwards to the parent. And infection does spread upwards, so I need that parent connection as well.
That gave me the idea of building a parent map first. I run a DFS on the tree and store parent[child] = root. 
That way, later on, I can move in three directions: left, right, and parent. Now the tree really behaves like an undirected graph.
The next issue is: the problem gives me the start node as an integer value, not as a TreeNode*. 
So before BFS, I need to locate the actual starting node in the tree. I do that with a simple DFS search (getStart).
Once I have the starting node, I can begin BFS:
I put the starting node in the queue and mark it visited.
Each round of BFS represents one minute.
For every node at this level, I push its left, right, and parent into the queue if they’re not visited yet.
After processing a whole level, I increment the minute counter.
When the queue is empty, the infection has spread everywhere. 
The total minutes is minutes - 1 because the last increment happens after the infection is already done.”

⏱ Time & Space Complexity

Time complexity:

Building the parent map is O(N) (visit each node once).

BFS is also O(N) (each node enters the queue once).

Total → O(N).
(Evaluated by checking how many times each node is processed: once in DFS, once in BFS.)

Space complexity:

Parent map stores O(N).

Visited set stores up to O(N).

BFS queue also O(N).

Recursion for parent map up to tree height H.

Total → O(N).

*************CODE*********************************
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
