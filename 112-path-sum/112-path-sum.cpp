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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*,int>> st;
        if(!root) return false;
        
        st.push({root,root->val});
        while(!st.empty())
        {
            pair<TreeNode*,int> p=st.top();
            st.pop();
            TreeNode *temp=p.first;
            int sum=p.second;
            
            if(!(temp->left) && !(temp->right) && targetSum==sum)
                return true;
            
            if(temp->right) st.push({temp->right,sum+temp->right->val});
            if(temp->left) st.push({temp->left,sum+temp->left->val});
        }
        return false;        
    }
};