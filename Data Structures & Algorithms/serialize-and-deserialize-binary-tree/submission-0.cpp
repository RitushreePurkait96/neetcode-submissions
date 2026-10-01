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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string str = "";
        serializeHelper(root, str);
        return str;
    }
           
    void serializeHelper(TreeNode *root, string& str)
    {
        if(!root)
        {
            str.append("null,");
            return;
        }
        
        str.append(to_string(root->val) + ",");
        serializeHelper(root->left, str);
        serializeHelper(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        stringstream datastr(data);
        return deserializeHelper(datastr);
    }
    TreeNode* deserializeHelper(stringstream& datastr)
    {
        string item;
        if(!getline(datastr, item, ','))
            return nullptr;
        
        if(item == "null")
            return nullptr;

        TreeNode *newNode = new TreeNode(stoi(item));
        newNode->left = deserializeHelper(datastr);
        newNode->right = deserializeHelper(datastr);
        return newNode;
    }
};
