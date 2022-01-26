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
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(!root)
            return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        
        vector<int> res;
        int i1=0,i2=0;
        while(i1<v1.size() && i2<v2.size())
        {
            if(v1[i1]<=v2[i2])
            {
                res.push_back(v1[i1]);
                i1++;
            }
            else
            {
                res.push_back(v2[i2]);
                i2++;
            }
        }
        
        while(i1<v1.size())
        {
            res.push_back(v1[i1]);
            i1++;
        }
        while(i2<v2.size())
        {
            res.push_back(v2[i2]);
            i2++;
        }
        
        return res;
    }
};