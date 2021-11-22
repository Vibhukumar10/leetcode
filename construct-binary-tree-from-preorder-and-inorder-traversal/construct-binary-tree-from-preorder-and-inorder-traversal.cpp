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
    int preIndex;
    map<int,int> inorderIndexMap;
    
    TreeNode *arrayToTree(vector<int> &preorder,int l,int r) {
        if(l>r) return NULL;
        
        int rootValue=preorder[preIndex++];
        TreeNode *root=new TreeNode(rootValue);
        
        root->left=arrayToTree(preorder,l,inorderIndexMap[rootValue]-1);
        root->right=arrayToTree(preorder,inorderIndexMap[rootValue]+1,r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preIndex=0;
        for(int i=0;i<inorder.size();i++)
            inorderIndexMap.insert({inorder[i],i});
        
        return arrayToTree(preorder,0,preorder.size()-1);
    }
};