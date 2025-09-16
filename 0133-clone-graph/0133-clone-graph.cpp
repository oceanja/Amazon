The goal is to create a deep copy of a graph where each node may have multiple neighbors.
The key difficulty is that graphs can have cycles (a node pointing back to an earlier one). 
If we naïvely recurse, we’d get stuck in an infinite loop.

The trick:

Maintain a map from original node → cloned node.

While traversing, if we see a node we’ve already cloned, reuse the clone instead of making a new one.

This ensures each node is cloned exactly once, and all connections (edges) are preserved.

2. Data Structures & Algorithm Choice

unordered_map<Node*, Node*> mpp

Key: pointer to an original node

Value: pointer to its cloned version

Prevents infinite recursion and ensures re-use of clones.

DFS traversal (recursive):

Visit each node, create a clone, then recursively clone its neighbors.

Trade-offs

DFS works fine; BFS (using a queue) is also valid.

DFS recursion depth can be a problem in very large graphs (risk of stack overflow), but acceptable for interview-scale.

3. Step-by-Step Walkthrough

Suppose we have this small graph:

1 -- 2
|    |
4 -- 3

Call: cloneGraph(node1)

mpp.clear() resets map.

Create clone of node1 (clone_node with val=1).

Map: {1 → 1'}

Now DFS:

DFS(node1, clone1):

Look at neighbors of 1 → [2, 4]

Neighbor 2:

Not in map → create clone2.

Map: {1→1', 2→2'}

Add edge: clone1.neighbors.push_back(clone2)

DFS(node2, clone2)

DFS(node2, clone2):

Neighbors of 2 → [1, 3]

Neighbor 1: already cloned → just add clone1 to clone2.neighbors.

Neighbor 3: not cloned yet → create clone3.

Map: {1→1', 2→2', 3→3'}

Add edge: clone2.neighbors.push_back(clone3)

DFS(node3, clone3)

DFS(node3, clone3):

Neighbors → [2, 4]

Neighbor 2: already cloned → add clone2.

Neighbor 4: not cloned yet → create clone4.

Map: {1→1', 2→2', 3→3', 4→4'}

Add edge: clone3.neighbors.push_back(clone4)

DFS(node4, clone4)

DFS(node4, clone4):

Neighbors → [1, 3]

Both already cloned → just add references to clone1 and clone3.

At the end:

We’ve built a fully connected copy of the graph with all edges preserved.

Return pointer to clone of starting node (clone1).

4. Complexity Analysis

Let V = number of nodes, E = number of edges.

Time:

Each node cloned once, each edge explored once.

O(V + E).

Space:

Map stores O(V).

Recursion stack O(V) in the worst case (deep graph).

5. Potential Improvements / Edge Cases

Edge cases:

node == NULL → return NULL (already handled).

Single node with no neighbors → returns a clone correctly.

Cyclic graphs (like a self-loop) handled safely by the map.

Improvement:

Could implement BFS (iterative with queue) to avoid recursion depth.

Use unordered_map<int, Node*> if node values are unique and IDs, but safer to use pointer-to-pointer mapping as in this code.

Clarity:

DFS could be simplified to return the cloned node directly (instead of passing clone_node around).

✅ Summary (what to say in interview):
This solution does a DFS traversal, cloning each node and mapping it to its copy. 
When visiting neighbors, if a neighbor hasn’t been cloned yet, we create it and recurse. 
If it has, we just attach the existing clone. 
This way, every node is cloned once, and cycles don’t cause infinite recursion. The algorithm runs in O(V+E) time with O(V) space.


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map< Node*, Node*> mpp;

void DFS(Node* node,Node* clone_node){
    for(Node* n: node->neighbors){
        if(mpp.find(n)==mpp.end()){
            Node* clone=new Node(n->val);
            mpp[n]=clone;
            clone_node->neighbors.push_back(clone);
            DFS(n,clone);
        }
        else{
            clone_node->neighbors.push_back(mpp[n]);
        }
    }
}
    Node* cloneGraph(Node* node) {

        if(node==NULL){
            return NULL;
        }

        mpp.clear();

        Node* clone_node= new Node(node->val);
        mpp[node]=clone_node;

        DFS(node,clone_node);

        return clone_node;        
    }
};
