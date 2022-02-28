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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        long long int res=0,startIndex=0;
        
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                pair<TreeNode*,int> p=q.front();
                q.pop();
                TreeNode *temp=p.first;
                long long int index=p.second;
                
                if(i==0) startIndex=index;
                if(i==sz-1) res=max(res,index-startIndex+1);
                
                if(temp->left) q.push({temp->left,index*2+1});
                if(temp->right) q.push({temp->right,index*2+2});
            }
        }
        return res;
    }
};