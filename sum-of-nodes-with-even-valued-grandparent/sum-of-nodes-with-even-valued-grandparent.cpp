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
    int sumEvenGrandparent(TreeNode* root) {
        int res=0;
        if(!root || (!root->left && !root->right))
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->val%2==0)
                {
                    if(temp->left)
                    {
                        if(temp->left->left)
                            res+=temp->left->left->val;
                        if(temp->left->right)
                            res+=temp->left->right->val;
                    }
                    if(temp->right)
                    {
                        if(temp->right->left)
                            res+=temp->right->left->val;
                        if(temp->right->right)
                            res+=temp->right->right->val;
                    }
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return res;
    }
};