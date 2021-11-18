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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        unordered_map<int,int> map;
        queue<TreeNode*> q;
        q.push(root);
        int maxi=INT_MIN;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *temp=q.front();
                q.pop();
                
                map[temp->val]++;
                if(map[temp->val]>maxi)
                    maxi=map[temp->val];
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        for(auto it:map)
        {
            if(it.second==maxi)
                res.push_back(it.first);
        }
        return res;        
    }
};