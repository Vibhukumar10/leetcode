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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        bool flag=true;
        
        while(!dq.empty()) 
        {
            int sz=dq.size();
            vector<int> add;
            for(int i=0;i<sz;i++)
            {
                if(flag)
                {
                    TreeNode *temp=dq.front();
                    dq.pop_front();
                    
                    add.push_back(temp->val);
                    if(temp->left) dq.push_back(temp->left);
                    if(temp->right) dq.push_back(temp->right);
                }
                else
                {
                    TreeNode *temp=dq.back();
                    dq.pop_back();
                    
                    add.push_back(temp->val);
                    if(temp->right) dq.push_front(temp->right);
                    if(temp->left) dq.push_front(temp->left);
                }
            }
            // if(!flag) reverse(add.begin(),add.end());
            res.push_back(add);
            flag=!flag;
        }
        return res;
    }
};