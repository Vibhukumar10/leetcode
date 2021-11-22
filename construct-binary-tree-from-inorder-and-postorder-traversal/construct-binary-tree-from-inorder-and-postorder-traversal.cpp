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
    int postIndex;
    unordered_map<int,int> inorderIndexMap;
    
    TreeNode *arrayToTree(vector<int> &postorder,int l,int r) {
        if(l>r) return NULL;
        
        int rootValue=postorder[postIndex--];
        TreeNode *root=new TreeNode(rootValue);
        
        root->right=arrayToTree(postorder,inorderIndexMap[rootValue]+1,r);
        root->left=arrayToTree(postorder,l,inorderIndexMap[rootValue]-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
            inorderIndexMap.insert({inorder[i],i});
        
        return arrayToTree(postorder,0,postorder.size()-1);
    }
};