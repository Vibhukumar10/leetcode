/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode *root,vector<TreeNode*> &path,TreeNode *x) {
        if(!root) return false;
        
        path.push_back(root);
        
        if(root==x) return true;
        
        if(getPath(root->left,path,x) || getPath(root->right,path,x)) return true;
        
        path.pop_back();
        return false;      
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath,qPath;
        bool ok=getPath(root,pPath,p);
        bool nok=getPath(root,qPath,q);
        
        int i=0,j=0;
        TreeNode *res;
        while(i<pPath.size() && j<qPath.size() && pPath[i]==qPath[j])
        {
            res=pPath[i];
            i++;j++;
        }
        
        return res;
    }
};