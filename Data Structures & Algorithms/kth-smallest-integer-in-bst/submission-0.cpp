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
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inorder(root, k, result);
        return result;
    }

private:
    void inorder(TreeNode* root, int& k, int& result) {
        // Base case: if node is null or we already found our answer, return early
        if (!root || k == 0) return;
        
        // 1. Traverse left subtree
        inorder(root->left, k, result);
        
        // 2. Process current root node
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        
        // 3. Traverse right subtree
        inorder(root->right, k, result);
    }
};
