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
    int index;
    unordered_map<int,int> mp;
    
    TreeNode *construct(vector<int> &preorder,int l,int r) {
        if(l>r) {
            return NULL;
        }
        
        int rootVal=preorder[index++];
        TreeNode *root=new TreeNode(rootVal);
        
        root->left=construct(preorder,l,mp[rootVal]-1);
        root->right=construct(preorder,mp[rootVal]+1,r);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index=0;
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]]=i;
        }
        
        return construct(preorder,0,preorder.size()-1);
    }
};