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
    int sumNumbers(TreeNode* root) {
        int res=0;
        if(!root) return res;
        
        stack<pair<TreeNode*,int>> st;
        st.push({root,root->val});
        while(!st.empty())
        {
            pair<TreeNode*,int> p=st.top();
            st.pop();
            TreeNode *temp=p.first;
            int num=p.second;
            
            if(!temp->left && !temp->right)
                res+=num;
            
            if(temp->right) st.push({temp->right,num*10+temp->right->val});
            if(temp->left) st.push({temp->left,num*10+temp->left->val});   
        }
        
        return res;
    }
};