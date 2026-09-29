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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        // If the main tree runs out of nodes, subRoot cannot be found
        if (!root) return false;
        
        // If the trees match starting from the current root node, return true
        if (isSameTree(root, subRoot)) return true;
        
        // Otherwise, check the left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    // Helper function from the previous problem
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};