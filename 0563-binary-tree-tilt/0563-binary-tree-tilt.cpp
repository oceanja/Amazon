
“The problem asks me to find the tilt of a binary tree. 
The tilt of a node is defined as the absolute difference between the sum of its left subtree 
and the sum of its right subtree, and the total tilt of the tree is the sum of tilts across all nodes.
My first thought was: if I want the tilt of every node, 
I need to know the sum of values in its left subtree and the sum of values in its right subtree. 
So the natural idea is to use recursion: at each node, I ask the left child for its total sum, and the right child for its total sum.

Once I have those two numbers, I can compute the tilt at the current node as abs(leftSum - rightSum) and add it to a global answer.

But the key detail is: besides updating the tilt, I also need to return something back to the parent. 
If I just return tilt, the parent won’t know the subtree sums it needs. 
So what I actually return from the recursive function is the total sum of the subtree rooted at
this node: leftSum + rightSum + node->val. This way, each parent can correctly compute its own tilt.

So the flow is:

Recurse left → get left subtree sum.

Recurse right → get right subtree sum.

Add abs(leftSum - rightSum) to a global tilt counter.

Return the total sum of this subtree to the parent.

This guarantees that every node’s tilt is counted exactly once, and every parent gets the sums it needs.”

⏱ Time and  Space Complexity

Time Complexity: O(N). Every node is visited exactly once, and we do O(1) work at each node (addition and absolute difference).

Space Complexity: O(H), where H is the height of the tree, due to recursion stack.
Worst case (skewed tree) it’s O(N), best case (balanced tree) it’s O(log N).






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
