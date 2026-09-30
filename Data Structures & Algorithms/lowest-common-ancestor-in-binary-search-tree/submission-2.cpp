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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *curr = root;
        while(curr)
        {
            // If both nodes are smaller, go left
            if(p->val < curr->val && q->val < curr->val)
            {
                curr = curr->left;
            }
            // If both nodes are larger, go right
            else if(p->val > curr->val && q->val > curr->val)
            {
                curr = curr->right;
            } 
            // If they split (or one equals curr), this is the LCA!
            else
            {
                return curr;
            }
        }
        return nullptr;
    }
};
