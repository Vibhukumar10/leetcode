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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> v;
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp=q.front();
                v.push_back(temp->val);
                q.pop();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(v);
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};