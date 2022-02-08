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
    void preorder(TreeNode *root,vector<string> &v)
    {
        if(!root)
            return;
        stack<pair<TreeNode*,string>> st;
        st.push({root,to_string(root->val)});
        
        while(!st.empty())
        {
            pair<TreeNode*,string> p=st.top();
            st.pop();
            TreeNode *temp=p.first;
            string s=p.second;
            if(!temp->left && !temp->right)
                v.push_back(s);
            
            if(temp->right) st.push({temp->right,s+"->"+to_string(temp->right->val)});
            if(temp->left) st.push({temp->left,s+"->"+to_string(temp->left->val)});
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        //preorder traversal
        vector<string> v;
        preorder(root,v);
        return v;
    }
};