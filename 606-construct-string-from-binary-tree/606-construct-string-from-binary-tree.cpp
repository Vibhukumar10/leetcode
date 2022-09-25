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
    void helper(string &s,TreeNode *root) {
        if(!root) {
            return;
        }
        
        s+=to_string(root->val);
        
        if(root->left) {
            s+="(";
            helper(s,root->left);
            s+=")";
        } else if(!root->left && root->right) {
            s+="()";
        }
        if(root->right) {
            s+="(";
            helper(s,root->right);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string s="";
        helper(s,root);
        return s;
    }
};