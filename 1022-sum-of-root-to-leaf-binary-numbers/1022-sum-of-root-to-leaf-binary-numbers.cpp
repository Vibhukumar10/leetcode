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
    int sumRootToLeaf(TreeNode* root) {
        int res=0, currNumber=0;
        if(!root) return 0;
        
        stack<pair<TreeNode*,int>> st;
        st.push({root,0});
        
        while(!st.empty())
        {
            pair<TreeNode*,int> p=st.top();
            TreeNode* temp=p.first;
            currNumber=p.second;
            
            st.pop();
            
            
            currNumber=(currNumber<<1)|temp->val;
            
            if(!temp->right && !temp->left)
            {
                res+=currNumber;
                currNumber=currNumber>>1;
            }
            
            if(temp->right) st.push({temp->right,currNumber});
            if(temp->left) st.push({temp->left,currNumber});
        }
        
        return res;
    }
};