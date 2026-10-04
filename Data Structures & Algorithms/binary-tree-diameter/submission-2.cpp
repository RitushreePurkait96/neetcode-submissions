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


/*
The Core Concept: Tracking a Global Maximum
two things happening at every single node:

The Height (for the parent): A node needs to return its height (max(left, right) + 1) up to its parent so the parent can calculate its own height.

The Diameter (locally): As we compute the heights, the potential diameter passing through the current node is leftHeight + rightHeight.
Instead of doing these in separate passes, we can calculate the height recursively and update a global variable (maxDiameter) every time we visit a node. 

Whichever node has the largest leftHeight + rightHeight will win!
*/
class Solution {
private:
    int maxDiameter = 0; // Global tracker for the max diameter found anywhere

    int height(TreeNode* root) {
        if (!root) return 0;

        // 1. Get heights of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // 2. Update maxDiameter with the path passing through *this* node
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // 3. Return the height of this node to its parent
        return max(leftHeight, rightHeight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0; // Reset for safety
        height(root);    // Triggers the DFS traversal
        return maxDiameter;
    }
};