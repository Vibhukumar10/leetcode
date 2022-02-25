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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        
        TreeNode *root=new TreeNode(0);
        if(root1) root->val+=root1->val;
        if(root2) root->val+=root2->val;
        
        if(!root1 && root2) root->left = mergeTrees(NULL,root2->left);
        else if(!root2 && root1) root->left = mergeTrees(root1->left,NULL);
        else root->left = mergeTrees(root1->left,root2->left);
        
        if(!root1 && root2) root->right = mergeTrees(NULL,root2->right);
        else if(!root2 && root1) root->right = mergeTrees(root1->right,NULL);
        else root->right = mergeTrees(root1->right,root2->right);
        
        return root;
    }
};