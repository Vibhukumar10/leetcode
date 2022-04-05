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
    
    TreeNode *construct(vector<int> postorder,int l,int r) {
        if(l>r) {
            return NULL;
        }
        
        int rootVal=postorder[index--];
        TreeNode *root=new TreeNode(rootVal);
        
        root->right=construct(postorder,mp[rootVal]+1,r);
        root->left=construct(postorder,l,mp[rootVal]-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return NULL;
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]]=i;
        }
        
        index=postorder.size()-1;
        return construct(postorder,0,inorder.size()-1);
    }
};