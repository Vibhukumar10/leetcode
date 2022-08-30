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
    
    int xParent, yParent;
    void helper(TreeNode* root, int x, int y, int& depx, int& depy, int depth, TreeNode* parent)
    {
        if(root==NULL) return;
        if(root->val==x)
        {
            depx=depth;
            xParent=parent->val;
            return;
        }
        
        if(root->val==y)
        {
            depy=depth;
            yParent=parent->val;
            return;
        }
        
        else
        {
            helper(root->left, x, y, depx, depy, depth+1, root);
            helper(root->right, x, y, depx, depy, depth+1, root);
        }        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int depx = -1;
        int depy = -1;
        
        helper(root, x, y, depx, depy, 0, root);
        
        if(depx==depy && xParent!=yParent) return true;
        else return false;
        
    }
};