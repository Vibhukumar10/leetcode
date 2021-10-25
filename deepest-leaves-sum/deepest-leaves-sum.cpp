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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        
        q.push(root);
        
        while(!q.empty())
        {
            v.clear();
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode *temp=q.front();
                v.push_back(temp->val);
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);                
            }
        }
        
        int res=0;
        for(int x:v)
            res+=x;
        return res;
    }
};