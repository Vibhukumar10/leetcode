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
    int levelOrder(TreeNode *root)
    {
        int smallest=-1,secondSmallest=-1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                if(temp->val==root->val)
                    smallest=temp->val;
                else
                {
                    if(secondSmallest==-1 && temp->val > smallest)
                        secondSmallest=temp->val;
                    else
                    {
                        secondSmallest=min(secondSmallest,temp->val);
                    }
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        
        return secondSmallest;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        return levelOrder(root);
    }
};