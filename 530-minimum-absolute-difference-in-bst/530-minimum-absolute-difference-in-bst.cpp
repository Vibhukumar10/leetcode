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
    int curr;
    bool leftmost=true;
    void inorder(TreeNode *root, int &res)
    {
        if(!root)
            return;
        
        inorder(root->left,res);
        if(leftmost)
        {
            curr=root->val;
            leftmost=false;
        }
        else
        {
            res=min(res,abs(curr-root->val));
            curr=root->val;
        }
        inorder(root->right,res);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int res=INT_MAX;
        inorder(root, res);
        return res;
    }
};